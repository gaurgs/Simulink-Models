/*
 * Energy_sf.h
 *
 * Code generation for model "Energy_sf".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Mar 18 01:21:15 2015
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Energy_sf_h_
#define RTW_HEADER_Energy_sf_h_
#ifndef Energy_sf_COMMON_INCLUDES_
# define Energy_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#define S_FUNCTION_NAME                Energy_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* Energy_sf_COMMON_INCLUDES_ */

#include "Energy_sf_types.h"

/* External inputs (root inport signals with auto storage) */
typedef struct {
  creal_T *Rxsignal[1000];             /* '<Root>/Rxsignal' */
} ExternalUPtrs_Energy_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *energy;                      /* '<Root>/energy' */
  real_T *nvariance;                   /* '<Root>/nvariance' */
  real_T *samples;                     /* '<Root>/samples' */
} ExtY_Energy_T;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ccode_sdr/Energy Detection Block ')    - opens subsystem ccode_sdr/Energy Detection Block
 * hilite_system('ccode_sdr/Energy Detection Block /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ccode_sdr'
 * '<S1>'   : 'ccode_sdr/Energy Detection Block '
 * '<S2>'   : 'ccode_sdr/Energy Detection Block /Energy'
 */
#endif                                 /* RTW_HEADER_Energy_sf_h_ */
