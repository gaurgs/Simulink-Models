/*
 * Energy.c
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
#include "Energy.h"
#include "Energy_private.h"

/* Block signals (auto storage) */
B_Energy_T Energy_B;

/* External inputs (root inport signals with auto storage) */
ExtU_Energy_T Energy_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Energy_T Energy_Y;

/* Real-time model */
RT_MODEL_Energy_T Energy_M_;
RT_MODEL_Energy_T *const Energy_M = &Energy_M_;
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  real_T b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Model step function */
void Energy_step(void)
{
  real_T energy;
  int32_T k;

  /* MATLAB Function: '<S1>/Energy' incorporates:
   *  Inport: '<Root>/In1'
   */
  /* MATLAB Function 'Energy Detection/Energy': '<S2>:1' */
  /* energy=double(zeros(1,1)); */
  /* '<S2>:1:4' */
  for (k = 0; k < 1000; k++) {
    energy = rt_hypotd_snf(Energy_U.In1[k].re, Energy_U.In1[k].im);
    Energy_B.b_y[k] = energy * energy;
  }

  energy = Energy_B.b_y[0];
  for (k = 0; k < 999; k++) {
    energy += Energy_B.b_y[k + 1];
  }

  /* Outport: '<Root>/Out1' incorporates:
   *  MATLAB Function: '<S1>/Energy'
   */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /*  noise variance */
  /* '<S2>:1:7' */
  /* '<S2>:1:8' */
  Energy_Y.Out1 = energy;

  /* Outport: '<Root>/Out2' incorporates:
   *  Constant: '<S1>/SNR'
   *  MATLAB Function: '<S1>/Energy'
   */
  Energy_Y.Out2 = 1.0 / rt_powd_snf(10.0, Energy_P.SNR_Value / 20.0);

  /* Outport: '<Root>/Out3' incorporates:
   *  MATLAB Function: '<S1>/Energy'
   */
  Energy_Y.Out3 = 1000.0;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Energy_M->rtwLogInfo, (&Energy_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [10.0s, 0.0s] */
    if ((rtmGetTFinal(Energy_M)!=-1) &&
        !((rtmGetTFinal(Energy_M)-Energy_M->Timing.taskTime0) >
          Energy_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Energy_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Energy_M->Timing.clockTick0)) {
    ++Energy_M->Timing.clockTickH0;
  }

  Energy_M->Timing.taskTime0 = Energy_M->Timing.clockTick0 *
    Energy_M->Timing.stepSize0 + Energy_M->Timing.clockTickH0 *
    Energy_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Energy_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Energy_M, 0,
                sizeof(RT_MODEL_Energy_T));
  rtmSetTFinal(Energy_M, 10000.0);
  Energy_M->Timing.stepSize0 = 10.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Energy_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Energy_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Energy_M->rtwLogInfo, (NULL));
    rtliSetLogT(Energy_M->rtwLogInfo, "tout");
    rtliSetLogX(Energy_M->rtwLogInfo, "");
    rtliSetLogXFinal(Energy_M->rtwLogInfo, "");
    rtliSetSigLog(Energy_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Energy_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Energy_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Energy_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Energy_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Energy_Y.Out1,
        &Energy_Y.Out2,
        &Energy_Y.Out3
      };

      rtliSetLogYSignalPtrs(Energy_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "y",
        "nvar",
        "N" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Energy/Out1",
        "Energy/Out2",
        "Energy/Out3" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          3,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Energy_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }

    rtliSetLogY(Energy_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  (void) memset(Energy_U.In1, 0,
                2000U*sizeof(real_T));

  /* external outputs */
  (void) memset((void *)&Energy_Y, 0,
                sizeof(ExtY_Energy_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Energy_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Energy_M), Energy_M->Timing.stepSize0, (&rtmGetErrorStatus(Energy_M)));
}

/* Model terminate function */
void Energy_terminate(void)
{
  /* (no terminate code required) */
}
