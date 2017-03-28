#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef ENCLAVE_STD_ALT
// printf
#include "glue.h"
// for ocall_log_FATAL etc
#include "Enclave_t.h"
#else
#include "loguru.hpp"
#endif


#ifndef ENC_LOG_H
#define ENC_LOG_H

#ifdef    __cplusplus
extern "C" {
#endif

#ifdef ENCLAVE_STD_ALT
// macros for use in the enclave
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG(level,fmt,arg... ) \
do { \
  char __log_buf[BUFSIZ] = {'\0'};\
  snprintf(__log_buf, BUFSIZ, "[%s:%d] " fmt, __FILENAME__, __LINE__, ##arg);\
  ocall_log_##level(__log_buf);\
} while(0)
#else
#define LOG(level,fmt,arg... ) \
do { \
  LOG_F(level,fmt,##arg ); \
} while(0)
#endif

#define LOG_LEVEL_TRACE 3
#define LOG_LEVEL_DEBUG 2
#define LOG_LEVEL_LOG 1

#define LL_TRACE( fmt, arg... )     LOG(3, fmt, ##arg )
#define LL_DEBUG( fmt, arg... )     LOG(2, fmt, ##arg )
#define LL_LOG( fmt, arg... )       LOG(1, fmt, ##arg )
#define LL_INFO( fmt, arg... )      LOG(INFO,    fmt, ##arg )
#define LL_WARNING( fmt, arg... )   LOG(WARNING, fmt, ##arg )
#define LL_ERROR( fmt, arg... )     LOG(ERROR, fmt, ##arg )
#define LL_CRITICAL( fmt, arg... )  LOG(ERROR, fmt, ##arg )

#ifdef __cplusplus
}
#endif

#endif
