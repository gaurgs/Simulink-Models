/*
 * Energy.h
 *
 * Code generation for model "Energy".
 *
 * Model version              : 1.63
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Feb 13 00:08:08 2015
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Energy_h_
#define RTW_HEADER_Energy_h_
#ifndef Energy_COMMON_INCLUDES_
# define Energy_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* Energy_COMMON_INCLUDES_ */

#include "Energy_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T b_y[1000];
} B_Energy_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  creal_T In1[1000];                   /* '<Root>/In1' */
} ExtU_Energy_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
} ExtY_Energy_T;

/* Parameters (auto storage) */
struct P_Energy_T_ {
  real_T SNR_Value;                    /* Expression: -10
                                        * Referenced by: '<S1>/SNR'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Energy_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Energy_T Energy_P;

/* Block signals (auto storage) */
extern B_Energy_T Energy_B;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Energy_T Energy_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Energy_T Energy_Y;

/* Model entry point functions */
extern void Energy_initialize(void);
extern void Energy_step(void);
extern void Energy_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Energy_T *const Energy_M;

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
 * hilite_system('SDR_c/Energy Detection')    - opens subsystem SDR_c/Energy Detection
 * hilite_system('SDR_c/Energy Detection/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SDR_c'
 * '<S1>'   : 'SDR_c/Energy Detection'
 * '<S2>'   : 'SDR_c/Energy Detection/Energy'
 */
#endif                                 /* RTW_HEADER_Energy_h_ */
