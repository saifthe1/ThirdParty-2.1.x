/* Copyright 2004,2007,2008 ENSEIRB, INRIA & CNRS
**
** This file is part of the Scotch software package for static mapping,
** graph partitioning and sparse matrix ordering.
**
** This software is governed by the CeCILL-C license under French law
** and abiding by the rules of distribution of free software. You can
** use, modify and/or redistribute the software under the terms of the
** CeCILL-C license as circulated by CEA, CNRS and INRIA at the following
** URL: "http://www.cecill.info".
** 
** As a counterpart to the access to the source code and rights to copy,
** modify and redistribute granted by the license, users are provided
** only with a limited warranty and the software's author, the holder of
** the economic rights, and the successive licensors have only limited
** liability.
** 
** In this respect, the user's attention is drawn to the risks associated
** with loading, using, modifying and/or developing or reproducing the
** software by the user in light of its specific status of free software,
** that may mean that it is complicated to manipulate, and that also
** therefore means that it is reserved for developers and experienced
** professionals having in-depth computer knowledge. Users are therefore
** encouraged to load and test the software's suitability as regards
** their requirements in conditions enabling the security of their
** systems and/or data to be ensured and, more generally, to use and
** operate it in the same conditions as regards security.
** 
** The fact that you are presently reading this means that you have had
** knowledge of the CeCILL-C license and that you accept its terms.
*/
/************************************************************/
/**                                                        **/
/**   NAME       : gmk_msh.h                               **/
/**                                                        **/
/**   AUTHOR     : Francois PELLEGRINI                     **/
/**                                                        **/
/**   FUNCTION   : Part of a mesh-to-graph converter.      **/
/**                This module contains the data declara-  **/
/**                tions for the main module.              **/
/**                                                        **/
/**   DATES      : # Version 4.0  : from : 21 jan 2004     **/
/**                                 to   : 21 jan 2004     **/
/**                                                        **/
/************************************************************/

/*
**  The defines
*/

/*+ File name aliases. +*/

#define C_FILENBR                   2            /* Number of files in list                */
#define C_FILEARGNBR                2            /* Number of files which can be arguments */

#define C_filenamemshinp            C_fileTab[0].name /* External graph input file name  */
#define C_filenamegrfout            C_fileTab[1].name /* Source graph output file name   */

#define C_filepntrmshinp            C_fileTab[0].pntr /* External graph input file  */
#define C_filepntrgrfout            C_fileTab[1].pntr /* Source graph output file   */

/*
**  The type and structure definitions.
*/

/*+ This structure defines the method array element. +*/

typedef struct C_Format_ {
  char                      code;                /* Format type code */
  int                    (* func) ();            /* Function to call */
} C_Format;
