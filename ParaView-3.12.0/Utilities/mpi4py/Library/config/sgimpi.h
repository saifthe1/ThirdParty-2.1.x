#ifndef PyMPI_CONFIG_SGIMPI_H
#define PyMPI_CONFIG_SGIMPI_H

#define PyMPI_MISSING_MPI_ROOT 1
#define PyMPI_MISSING_MPI_WCHAR 1
#define PyMPI_MISSING_MPI_SIGNED_CHAR 1
#define PyMPI_MISSING_MPI_UNSIGNED_LONG_LONG 1
#define PyMPI_MISSING_MPI_TYPE_CREATE_INDEXED_BLOCK 1
#define PyMPI_MISSING_MPI_TYPECLASS_INTEGER 1
#define PyMPI_MISSING_MPI_TYPECLASS_REAL 1
#define PyMPI_MISSING_MPI_TYPECLASS_COMPLEX 1
#define PyMPI_MISSING_MPI_TYPE_MATCH_SIZE 1
#define PyMPI_MISSING_MPI_PACK_EXTERNAL 1
#define PyMPI_MISSING_MPI_UNPACK_EXTERNAL 1
#define PyMPI_MISSING_MPI_PACK_EXTERNAL_SIZE 1
#define PyMPI_MISSING_MPI_REPLACE 1
#define PyMPI_MISSING_MPI_COMM_ERRHANDLER_FN 1
#define PyMPI_MISSING_MPI_COMM_CREATE_ERRHANDLER 1
#define PyMPI_MISSING_MPI_COMM_GET_ERRHANDLER 1
#define PyMPI_MISSING_MPI_COMM_SET_ERRHANDLER 1
#define PyMPI_MISSING_MPI_COMM_CALL_ERRHANDLER 1
#define PyMPI_MISSING_MPI_LASTUSEDCODE 1
#define PyMPI_MISSING_MPI_ALLTOALLW 1
#define PyMPI_MISSING_MPI_EXSCAN 1
#define PyMPI_MISSING_MPI_COMM_JOIN 1
/*#define PyMPI_MISSING_MPI_ARGV_NULL 1*/
/*#define PyMPI_MISSING_MPI_ARGVS_NULL 1*/
/*#define PyMPI_MISSING_MPI_ERRCODES_IGNORE 1*/
#define PyMPI_MISSING_MPI_WIN_ERRHANDLER_FN 1
#define PyMPI_MISSING_MPI_WIN_CREATE_ERRHANDLER 1
#define PyMPI_MISSING_MPI_WIN_CALL_ERRHANDLER 1
#define PyMPI_MISSING_MPI_FILE_ERRHANDLER_FN 1
#define PyMPI_MISSING_MPI_FILE_CREATE_ERRHANDLER 1
#define PyMPI_MISSING_MPI_FILE_CALL_ERRHANDLER 1
#define PyMPI_MISSING_MPI_DATAREP_CONVERSION_FUNCTION 1
#define PyMPI_MISSING_MPI_DATAREP_EXTENT_FUNCTION 1
#define PyMPI_MISSING_MPI_REGISTER_DATAREP 1
#define PyMPI_MISSING_MPI_ADD_ERROR_CLASS 1
#define PyMPI_MISSING_MPI_ADD_ERROR_CODE 1
#define PyMPI_MISSING_MPI_ADD_ERROR_STRING 1
#define PyMPI_MISSING_MPI_F_STATUS_IGNORE 1
#define PyMPI_MISSING_MPI_F_STATUSES_IGNORE 1
#define PyMPI_MISSING_MPI_STATUS_C2F 1
#define PyMPI_MISSING_MPI_STATUS_F2C 1
#define PyMPI_MISSING_MPI_ERRHANDLER_C2F 1
#define PyMPI_MISSING_MPI_ERRHANDLER_F2C 1

#if defined(_ABIN32) && _ABIN32
#define PyMPI_MISSING_MPI_WIN_NULL 1
#define PyMPI_MISSING_MPI_WIN_FREE 1
#define PyMPI_MISSING_MPI_WIN_CREATE 1
#define PyMPI_MISSING_MPI_WIN_GET_GROUP 1
#define PyMPI_MISSING_MPI_GET 1
#define PyMPI_MISSING_MPI_PUT 1
#define PyMPI_MISSING_MPI_ACCUMULATE 1
#define PyMPI_MISSING_MPI_MODE_NOCHECK 1
#define PyMPI_MISSING_MPI_MODE_NOSTORE 1
#define PyMPI_MISSING_MPI_MODE_NOPUT 1
#define PyMPI_MISSING_MPI_MODE_NOPRECEDE 1
#define PyMPI_MISSING_MPI_MODE_NOSUCCEED 1
#define PyMPI_MISSING_MPI_WIN_FENCE 1
#define PyMPI_MISSING_MPI_WIN_POST 1
#define PyMPI_MISSING_MPI_WIN_START 1
#define PyMPI_MISSING_MPI_WIN_COMPLETE 1
#define PyMPI_MISSING_MPI_WIN_LOCK 1
#define PyMPI_MISSING_MPI_WIN_UNLOCK 1
#define PyMPI_MISSING_MPI_WIN_WAIT 1
#define PyMPI_MISSING_MPI_WIN_TEST 1
#define PyMPI_MISSING_MPI_WIN_C2F 1
#define PyMPI_MISSING_MPI_WIN_F2C 1
#endif /* !_ABIN32 */

#endif /* !PyMPI_CONFIG_SGIMPI_H */
