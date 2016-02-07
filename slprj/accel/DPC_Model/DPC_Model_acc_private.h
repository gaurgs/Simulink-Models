#include "__cf_DPC_Model.h"
#ifndef RTW_HEADER_DPC_Model_acc_private_h_
#define RTW_HEADER_DPC_Model_acc_private_h_
#include "rtwtypes.h"
#ifndef RTW_COMMON_DEFINES_
#define RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif
#endif
#endif
extern void RandSrcInitState_U_64 ( const uint32_T seed [ ] , real_T state [
] , int32_T nChans ) ; extern void RandSrc_U_D ( real_T y [ ] , const real_T
minVec [ ] , int32_T minLen , const real_T maxVec [ ] , int32_T maxLen ,
real_T state [ ] , int32_T nChans , int32_T nSamps ) ;
#endif
