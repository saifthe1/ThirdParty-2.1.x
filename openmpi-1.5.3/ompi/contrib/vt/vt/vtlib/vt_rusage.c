/**
 * VampirTrace
 * http://www.tu-dresden.de/zih/vampirtrace
 *
 * Copyright (c) 2005-2010, ZIH, TU Dresden, Federal Republic of Germany
 *
 * Copyright (c) 1998-2005, Forschungszentrum Juelich, Juelich Supercomputing
 *                          Centre, Federal Republic of Germany
 *
 * See the file COPYING in the package base directory for details
 **/

#include "config.h"

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "vt_env.h"
#include "vt_error.h"
#include "vt_inttypes.h"
#include "vt_pform.h"
#include "vt_rusage.h"
#include "vt_trc.h"

#include "otf.h"

/* define this macro to write only changed counter values */
#undef RU_WRITE_ONLY_CHANGED_VALS

/* maximum number of resource usage counters */
#define RU_CNTR_MAXNUM 16

/* resource usage counter indices */
typedef enum {
  RU_UTIME, RU_STIME, RU_MAXRSS, RU_IXRSS,
  RU_IDRSS, RU_ISRSS, RU_MINFLT, RU_MAJFLT,
  RU_NSWAP, RU_INBLOCK, RU_OUBLOCK, RU_MSGSND,
  RU_MSGRCV, RU_NSIGNALS, RU_NVCSW, RU_NIVCSW
} ru_cntr_t;

/* data structure of resource usage counter specification */
struct ru_cntr
{
  const ru_cntr_t idx;
  const char*     name;
  const char*     unit;
  const uint32_t  prop;
};

/* vector of resource usage counter specifications */
static struct ru_cntr ru_cntrv[RU_CNTR_MAXNUM] = {
  { RU_UTIME,    "ru_utime",    "us", OTF_COUNTER_TYPE_ACC },
  { RU_STIME,    "ru_stime",    "us", OTF_COUNTER_TYPE_ACC },
  { RU_MAXRSS,   "ru_maxrss",   "kBytes",
    OTF_COUNTER_TYPE_ABS|OTF_COUNTER_SCOPE_NEXT },
  { RU_IXRSS,    "ru_ixrss",    "kBytes", OTF_COUNTER_TYPE_ACC }, 
  { RU_IDRSS,    "ru_idrss",    "kBytes", OTF_COUNTER_TYPE_ACC },
  { RU_ISRSS,    "ru_isrss",    "kBytes", OTF_COUNTER_TYPE_ACC },
  { RU_MINFLT,   "ru_minflt",   "#", OTF_COUNTER_TYPE_ACC },
  { RU_MAJFLT,   "ru_majflt",   "#", OTF_COUNTER_TYPE_ACC },
  { RU_NSWAP,    "ru_nswap",    "#", OTF_COUNTER_TYPE_ACC },
  { RU_INBLOCK,  "ru_inblock",  "#", OTF_COUNTER_TYPE_ACC },
  { RU_OUBLOCK,  "ru_oublock",  "#", OTF_COUNTER_TYPE_ACC },
  { RU_MSGSND,   "ru_msgsnd",   "#", OTF_COUNTER_TYPE_ACC },
  { RU_MSGRCV,   "ru_msgrcv",   "#", OTF_COUNTER_TYPE_ACC },
  { RU_NSIGNALS, "ru_nsignals", "#", OTF_COUNTER_TYPE_ACC },
  { RU_NVCSW,    "ru_nvcsw",    "#", OTF_COUNTER_TYPE_ACC },
  { RU_NIVCSW,   "ru_nivcsw",   "#", OTF_COUNTER_TYPE_ACC }
};
		
/* vector of active resource usage counters */ 
static struct ru_cntr* ru_active_cntrv[RU_CNTR_MAXNUM];
/* number of active resource usage counters */
static uint32_t ru_active_cntrn = 0;

struct vt_rusage
{
  struct rusage ru;
};

/* vector of counter ids */
uint32_t* vt_rusage_cidv = NULL;

/* read interval */
uint64_t vt_rusage_intv = 0;

uint32_t vt_rusage_open()
{
  char* env;
  char* var;
  char* token;
  uint32_t intv = (uint32_t)vt_env_rusage_intv();
  uint32_t i;

  /* read environment variable "VT_RUSAGE" */
  if ( ( env = vt_env_rusage() ) == NULL )
    return 0;

  var = strdup(env);
  vt_cntl_msg(2, "VT_RUSAGE=%s", var);

  /* convert VT_RUSAGE's letters to lower case */
  token = var;
  while ( *token ) { *token = tolower(*token); token++; }

  if ( strcmp(var, "all") == 0 )
  {
    /* add all rusage counters */
    for ( i = 0; i < RU_CNTR_MAXNUM; i++ )
      ru_active_cntrv[ru_active_cntrn++] = &(ru_cntrv[i]);
  }
  else
  {
    int idx;

    /* read rusage counter from specification string */
    token = strtok(var, ":");
    while ( token )
    {
      idx = -1;

      if ( ru_active_cntrn == RU_CNTR_MAXNUM )
      {
	vt_error_msg("Number of resource usage counters exceeds maximum of %d",
		     RU_CNTR_MAXNUM);
      }
      /* search counter name in vector of counter specifications */
      for ( i = 0; i < RU_CNTR_MAXNUM; i++ )
	if( strcmp(ru_cntrv[i].name, token) == 0) idx = (int)ru_cntrv[i].idx;

      /* if found, add the address of this counter specification to vector
	 of active counters; otherwise abort */
      if ( idx != -1 )
	ru_active_cntrv[ru_active_cntrn++] = &(ru_cntrv[idx]);
      else
	vt_error_msg("Unknown resource usage counter %s", token);

      token = strtok(NULL, ":");
    }
  }

  /* set rusage read interval */
  if ( intv > 0 )
    vt_rusage_intv = (vt_pform_clockres() * (uint64_t)intv) / 1000;

  free(var);

  return ru_active_cntrn;
}

void vt_rusage_close()
{
  uint32_t i;

  /* reset vector of active counters */
  for ( i = 0; i < RU_CNTR_MAXNUM; i++ )
    ru_active_cntrv[i] = NULL; 
  ru_active_cntrn = 0;

  free(vt_rusage_cidv);
}

struct vt_rusage* vt_rusage_create()
{
  struct vt_rusage* rusage;

  rusage = (struct vt_rusage*)malloc(sizeof(struct vt_rusage));
  if ( rusage == NULL )
    vt_error();

  return rusage;
}

void vt_rusage_free(struct vt_rusage* rusage)
{
  if( rusage == NULL )
    return;

  free(rusage);
}

void vt_rusage_init()
{
  uint32_t gid;
  uint32_t i;

  /* allocate vector of counter ids */
  vt_rusage_cidv = (uint32_t*)calloc(ru_active_cntrn, sizeof(uint32_t));
  if ( vt_rusage_cidv == NULL )
    vt_error();

  /* write counter group name definition */
  gid = vt_def_counter_group("Resources");

  /* write counter definition for active counters */
  for ( i = 0; i < ru_active_cntrn; i++ )
  {
    vt_rusage_cidv[i] =
      vt_def_counter(ru_active_cntrv[i]->name,
		     ru_active_cntrv[i]->prop,
		     gid,
		     ru_active_cntrv[i]->unit);
  }
}

void vt_rusage_read(struct vt_rusage* rusage, uint64_t* values, uint32_t* changed)
{
  uint32_t i;
  uint64_t new_value = 0;
  
  /* get resource usage */
  if ( getrusage(RUSAGE_SELF, &(rusage->ru)) == -1 )
    vt_error_msg("getrusage: %s", strerror(errno));

#ifdef RU_WRITE_ONLY_CHANGED_VALS
  *changed = 0;            /* set all bits to 0 (unchanged value) */
#else /* RU_WRITE_ONLY_CHANGED_VALS */
  *changed = (uint32_t)-1; /* set all bits to 1 (changed value) */
#endif /* RU_WRITE_ONLY_CHANGED_VALS */
  for ( i = 0; i < ru_active_cntrn; i++ )
  {
    switch(ru_active_cntrv[i]->idx)
    {
      case RU_UTIME:
      {
	new_value = ((uint64_t)rusage->ru.ru_utime.tv_sec * 1e6 +
		     (uint64_t)rusage->ru.ru_utime.tv_usec);
	break;
      }
      case RU_STIME:
      {
	new_value = ((uint64_t)rusage->ru.ru_stime.tv_sec * 1e6 +
		     (uint64_t)rusage->ru.ru_stime.tv_usec);
	break;
      }
      case RU_MAXRSS:
      {
	new_value = (uint64_t)rusage->ru.ru_maxrss;
	break;
      }
      case RU_IXRSS:
      {
	new_value = (uint64_t)rusage->ru.ru_ixrss;
	break;
      }
      case RU_IDRSS:
      {
	new_value = (uint64_t)rusage->ru.ru_idrss;
	break;
      }
      case RU_ISRSS:
      {
	new_value = (uint64_t)rusage->ru.ru_isrss;
	break;
      }
      case RU_MINFLT:
      {
	new_value = (uint64_t)rusage->ru.ru_minflt;
	break;
      }
      case RU_MAJFLT:
      {
	new_value = (uint64_t)rusage->ru.ru_majflt;
	break;
      }
      case RU_NSWAP:
      {
	new_value = (uint64_t)rusage->ru.ru_nswap;
	break;
      }
      case RU_INBLOCK:
      {
	new_value = (uint64_t)rusage->ru.ru_inblock;
	break;
      }
      case RU_OUBLOCK:
      {
	new_value = (uint64_t)rusage->ru.ru_oublock;
	break;
      }
      case RU_MSGSND:
      {
	new_value = (uint64_t)rusage->ru.ru_msgsnd;
	break;
      }
      case RU_MSGRCV:
      {
	new_value = (uint64_t)rusage->ru.ru_msgrcv;
	break;
      }
      case RU_NSIGNALS:
      {
	new_value = (uint64_t)rusage->ru.ru_nsignals;
	break;
      }
      case RU_NVCSW:
      {
	new_value = (uint64_t)rusage->ru.ru_nvcsw;
	break;
      }
      case RU_NIVCSW:
      {
	new_value = (uint64_t)rusage->ru.ru_nivcsw;
	break;
      }
    }

#ifdef RU_WRITE_ONLY_CHANGED_VALS
    if ( new_value != values[i] )
    {
       values[i] = new_value; /* write new value to vector */
      *changed |= (1<<i);     /* set bit for this counter to 1
				 (changed value) */
    }
#else /* RU_WRITE_ONLY_CHANGED_VALS */
    values[i] = new_value;
#endif /* RU_WRITE_ONLY_CHANGED_VALS */
  }
}

uint32_t vt_rusage_num()
{
  return ru_active_cntrn;
}
