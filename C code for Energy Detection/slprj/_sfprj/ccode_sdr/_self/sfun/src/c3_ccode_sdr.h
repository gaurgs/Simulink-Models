#ifndef __c3_ccode_sdr_h__
#define __c3_ccode_sdr_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc3_ccode_sdrInstanceStruct
#define typedef_SFc3_ccode_sdrInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_ccode_sdr;
} SFc3_ccode_sdrInstanceStruct;

#endif                                 /*typedef_SFc3_ccode_sdrInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_ccode_sdr_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_ccode_sdr_get_check_sum(mxArray *plhs[]);
extern void c3_ccode_sdr_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
