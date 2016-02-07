/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ZFBD_sfun.h"
#include "c1_ZFBD.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ZFBD_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[10] = { "m", "n", "a1", "a2", "nargin",
  "nargout", "data", "w2", "w1", "Tx_Data" };

/* Function Declarations */
static void initialize_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void initialize_params_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void enable_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void disable_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ZFBD(SFc1_ZFBDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_ZFBD(SFc1_ZFBDInstanceStruct
  *chartInstance);
static void set_sim_state_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance, const
  mxArray *c1_st);
static void finalize_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void sf_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void c1_chartstep_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void initSimStructsc1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void registerMessagesc1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance, const
  mxArray *c1_Tx_Data, const char_T *c1_identifier, creal_T c1_y[40]);
static void c1_b_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, creal_T c1_y[40]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_eml_scalar_eg(SFc1_ZFBDInstanceStruct *chartInstance);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_ZFBD, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_ZFBDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_ZFBD = 0U;
}

static void initialize_params_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
}

static void enable_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_ZFBD(SFc1_ZFBDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_ZFBD(SFc1_ZFBDInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  creal_T c1_u[40];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  creal_T (*c1_Tx_Data)[40];
  c1_Tx_Data = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 40; c1_i0++) {
    c1_u[c1_i0] = (*c1_Tx_Data)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 4, 10),
                FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_ZFBD;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance, const
  mxArray *c1_st)
{
  const mxArray *c1_u;
  creal_T c1_dcv0[40];
  int32_T c1_i1;
  creal_T (*c1_Tx_Data)[40];
  c1_Tx_Data = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "Tx_Data", c1_dcv0);
  for (c1_i1 = 0; c1_i1 < 40; c1_i1++) {
    (*c1_Tx_Data)[c1_i1] = c1_dcv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_ZFBD = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "is_active_c1_ZFBD");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_ZFBD(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
}

static void sf_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_ZFBD(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ZFBDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  creal_T c1_data[40];
  int32_T c1_i3;
  creal_T c1_w2[8];
  int32_T c1_i4;
  creal_T c1_w1[8];
  uint32_T c1_debug_family_var_map[10];
  real_T c1_m;
  real_T c1_n;
  real_T c1_a1[40];
  real_T c1_a2[40];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  creal_T c1_Tx_Data[40];
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  creal_T c1_a[8];
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  creal_T c1_b[20];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  creal_T c1_y[40];
  int32_T c1_i17;
  int32_T c1_i18;
  creal_T c1_b_a;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  creal_T c1_b_y[40];
  int32_T c1_i28;
  int32_T c1_i29;
  creal_T c1_c_a;
  int32_T c1_i30;
  int32_T c1_i31;
  creal_T (*c1_b_Tx_Data)[40];
  creal_T (*c1_b_w1)[8];
  creal_T (*c1_b_w2)[8];
  creal_T (*c1_b_data)[40];
  c1_b_w1 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Tx_Data = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_w2 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_data = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 40; c1_i2++) {
    c1_data[c1_i2] = (*c1_b_data)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 8; c1_i3++) {
    c1_w2[c1_i3] = (*c1_b_w2)[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 8; c1_i4++) {
    c1_w1[c1_i4] = (*c1_b_w1)[c1_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_a1, 2U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_a2, 3U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 4U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 5U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_data, 6U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_w2, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_w1, 8U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Tx_Data, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_m = 4.0;
  c1_n = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i5 = 0; c1_i5 < 40; c1_i5++) {
    c1_a1[c1_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  for (c1_i6 = 0; c1_i6 < 40; c1_i6++) {
    c1_a2[c1_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  for (c1_i7 = 0; c1_i7 < 40; c1_i7++) {
    c1_Tx_Data[c1_i7].re = 0.0;
    c1_Tx_Data[c1_i7].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i8 = 0; c1_i8 < 8; c1_i8++) {
    c1_a[c1_i8] = c1_w1[c1_i8];
  }

  c1_i9 = 0;
  c1_i10 = 0;
  for (c1_i11 = 0; c1_i11 < 10; c1_i11++) {
    for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
      c1_b[c1_i12 + c1_i9] = c1_data[c1_i12 + c1_i10];
    }

    c1_i9 += 2;
    c1_i10 += 4;
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
    c1_i14 = 0;
    c1_i15 = 0;
    for (c1_i16 = 0; c1_i16 < 10; c1_i16++) {
      c1_y[c1_i14 + c1_i13].re = 0.0;
      c1_y[c1_i14 + c1_i13].im = 0.0;
      c1_i17 = 0;
      for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
        c1_b_a.re = c1_a[c1_i17 + c1_i13].re * c1_b[c1_i18 + c1_i15].re -
          c1_a[c1_i17 + c1_i13].im * c1_b[c1_i18 + c1_i15].im;
        c1_b_a.im = c1_a[c1_i17 + c1_i13].re * c1_b[c1_i18 + c1_i15].im +
          c1_a[c1_i17 + c1_i13].im * c1_b[c1_i18 + c1_i15].re;
        c1_y[c1_i14 + c1_i13].re += c1_b_a.re;
        c1_y[c1_i14 + c1_i13].im += c1_b_a.im;
        c1_i17 += 4;
      }

      c1_i14 += 4;
      c1_i15 += 2;
    }
  }

  for (c1_i19 = 0; c1_i19 < 8; c1_i19++) {
    c1_a[c1_i19] = c1_w2[c1_i19];
  }

  c1_i20 = 0;
  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 10; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
      c1_b[c1_i23 + c1_i20] = c1_data[(c1_i23 + c1_i21) + 2];
    }

    c1_i20 += 2;
    c1_i21 += 4;
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
    c1_i25 = 0;
    c1_i26 = 0;
    for (c1_i27 = 0; c1_i27 < 10; c1_i27++) {
      c1_b_y[c1_i25 + c1_i24].re = 0.0;
      c1_b_y[c1_i25 + c1_i24].im = 0.0;
      c1_i28 = 0;
      for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
        c1_c_a.re = c1_a[c1_i28 + c1_i24].re * c1_b[c1_i29 + c1_i26].re -
          c1_a[c1_i28 + c1_i24].im * c1_b[c1_i29 + c1_i26].im;
        c1_c_a.im = c1_a[c1_i28 + c1_i24].re * c1_b[c1_i29 + c1_i26].im +
          c1_a[c1_i28 + c1_i24].im * c1_b[c1_i29 + c1_i26].re;
        c1_b_y[c1_i25 + c1_i24].re += c1_c_a.re;
        c1_b_y[c1_i25 + c1_i24].im += c1_c_a.im;
        c1_i28 += 4;
      }

      c1_i25 += 4;
      c1_i26 += 2;
    }
  }

  for (c1_i30 = 0; c1_i30 < 40; c1_i30++) {
    c1_Tx_Data[c1_i30].re = c1_y[c1_i30].re + c1_b_y[c1_i30].re;
    c1_Tx_Data[c1_i30].im = c1_y[c1_i30].im + c1_b_y[c1_i30].im;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i31 = 0; c1_i31 < 40; c1_i31++) {
    (*c1_b_Tx_Data)[c1_i31] = c1_Tx_Data[c1_i31];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_ZFBD(SFc1_ZFBDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  creal_T c1_b_inData[40];
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  creal_T c1_u[40];
  const mxArray *c1_y = NULL;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i32 = 0;
  for (c1_i33 = 0; c1_i33 < 10; c1_i33++) {
    for (c1_i34 = 0; c1_i34 < 4; c1_i34++) {
      c1_b_inData[c1_i34 + c1_i32] = (*(creal_T (*)[40])c1_inData)[c1_i34 +
        c1_i32];
    }

    c1_i32 += 4;
  }

  c1_i35 = 0;
  for (c1_i36 = 0; c1_i36 < 10; c1_i36++) {
    for (c1_i37 = 0; c1_i37 < 4; c1_i37++) {
      c1_u[c1_i37 + c1_i35] = c1_b_inData[c1_i37 + c1_i35];
    }

    c1_i35 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance, const
  mxArray *c1_Tx_Data, const char_T *c1_identifier, creal_T c1_y[40])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Tx_Data), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Tx_Data);
}

static void c1_b_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, creal_T c1_y[40])
{
  creal_T c1_dcv1[40];
  int32_T c1_i38;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dcv1, 1, 0, 1U, 1, 0U, 2, 4,
                10);
  for (c1_i38 = 0; c1_i38 < 40; c1_i38++) {
    c1_y[c1_i38] = c1_dcv1[c1_i38];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Tx_Data;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  creal_T c1_y[40];
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_Tx_Data = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Tx_Data), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Tx_Data);
  c1_i39 = 0;
  for (c1_i40 = 0; c1_i40 < 10; c1_i40++) {
    for (c1_i41 = 0; c1_i41 < 4; c1_i41++) {
      (*(creal_T (*)[40])c1_outData)[c1_i41 + c1_i39] = c1_y[c1_i41 + c1_i39];
    }

    c1_i39 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  creal_T c1_b_inData[8];
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  creal_T c1_u[8];
  const mxArray *c1_y = NULL;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i42 = 0;
  for (c1_i43 = 0; c1_i43 < 2; c1_i43++) {
    for (c1_i44 = 0; c1_i44 < 4; c1_i44++) {
      c1_b_inData[c1_i44 + c1_i42] = (*(creal_T (*)[8])c1_inData)[c1_i44 +
        c1_i42];
    }

    c1_i42 += 4;
  }

  c1_i45 = 0;
  for (c1_i46 = 0; c1_i46 < 2; c1_i46++) {
    for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
      c1_u[c1_i47 + c1_i45] = c1_b_inData[c1_i47 + c1_i45];
    }

    c1_i45 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 4, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  real_T c1_b_inData[40];
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  real_T c1_u[40];
  const mxArray *c1_y = NULL;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i48 = 0;
  for (c1_i49 = 0; c1_i49 < 10; c1_i49++) {
    for (c1_i50 = 0; c1_i50 < 4; c1_i50++) {
      c1_b_inData[c1_i50 + c1_i48] = (*(real_T (*)[40])c1_inData)[c1_i50 +
        c1_i48];
    }

    c1_i48 += 4;
  }

  c1_i51 = 0;
  for (c1_i52 = 0; c1_i52 < 10; c1_i52++) {
    for (c1_i53 = 0; c1_i53 < 4; c1_i53++) {
      c1_u[c1_i53 + c1_i51] = c1_b_inData[c1_i53 + c1_i51];
    }

    c1_i51 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_ZFBD_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[9];
  c1_ResolvedFunctionInfo (*c1_b_info)[9];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i54;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[9])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 1289503492U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[1].name = "eml_index_class";
  (*c1_b_info)[1].dominantType = "";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[1].fileTimeLo = 1323154378U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[2].name = "eml_scalar_eg";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[2].fileTimeLo = 1286806196U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[3].name = "eml_xgemm";
  (*c1_b_info)[3].dominantType = "char";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c1_b_info)[3].fileTimeLo = 1299060572U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c1_b_info)[4].name = "eml_blas_inline";
  (*c1_b_info)[4].dominantType = "";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c1_b_info)[4].fileTimeLo = 1299060568U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c1_b_info)[5].name = "mtimes";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[5].fileTimeLo = 1289503492U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[6].name = "eml_index_class";
  (*c1_b_info)[6].dominantType = "";
  (*c1_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[6].fileTimeLo = 1323154378U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[7].name = "eml_scalar_eg";
  (*c1_b_info)[7].dominantType = "double";
  (*c1_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[7].fileTimeLo = 1286806196U;
  (*c1_b_info)[7].fileTimeHi = 0U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  (*c1_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[8].name = "eml_refblas_xgemm";
  (*c1_b_info)[8].dominantType = "char";
  (*c1_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c1_b_info)[8].fileTimeLo = 1299060574U;
  (*c1_b_info)[8].fileTimeHi = 0U;
  (*c1_b_info)[8].mFileTimeLo = 0U;
  (*c1_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c1_i54 = 0; c1_i54 < 9; c1_i54++) {
    c1_r0 = &c1_info[c1_i54];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i54);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i54);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i54);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i54);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i54);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i54);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i54);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i54);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_eml_scalar_eg(SFc1_ZFBDInstanceStruct *chartInstance)
{
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i55;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i55, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i55;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_ZFBD, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_is_active_c1_ZFBD),
    &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_ZFBD);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_ZFBDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_ZFBDInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_ZFBD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(576156990U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(240235758U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1495390353U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3427682525U);
}

mxArray *sf_c1_ZFBD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("gTl7j3rRMh3Om0rBfx4nc");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(10);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(2);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(10);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_ZFBD_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_ZFBD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Tx_Data\",},{M[8],M[0],T\"is_active_c1_ZFBD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ZFBD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ZFBDInstanceStruct *chartInstance;
    chartInstance = (SFc1_ZFBDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ZFBDMachineNumber_,
           1,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ZFBDMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ZFBDMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ZFBDMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"data");
          _SFD_SET_DATA_PROPS(1,1,1,0,"w2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Tx_Data");
          _SFD_SET_DATA_PROPS(3,1,1,0,"w1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,198);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          creal_T (*c1_data)[40];
          creal_T (*c1_w2)[8];
          creal_T (*c1_Tx_Data)[40];
          creal_T (*c1_w1)[8];
          c1_w1 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 2);
          c1_Tx_Data = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S,
            1);
          c1_w2 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
          c1_data = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_data);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_w2);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_Tx_Data);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_w1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ZFBDMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "XBHSQqyteizHJQ9cqrGinF";
}

static void sf_opaque_initialize_c1_ZFBD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ZFBDInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c1_ZFBD((SFc1_ZFBDInstanceStruct*) chartInstanceVar);
  initialize_c1_ZFBD((SFc1_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ZFBD(void *chartInstanceVar)
{
  enable_c1_ZFBD((SFc1_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_ZFBD(void *chartInstanceVar)
{
  disable_c1_ZFBD((SFc1_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_ZFBD(void *chartInstanceVar)
{
  sf_c1_ZFBD((SFc1_ZFBDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_ZFBD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ZFBD((SFc1_ZFBDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ZFBD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_ZFBD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ZFBD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ZFBD((SFc1_ZFBDInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_ZFBD(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ZFBD(S);
}

static void sf_opaque_set_sim_state_c1_ZFBD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_ZFBD(S, st);
}

static void sf_opaque_terminate_c1_ZFBD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ZFBDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ZFBD_optimization_info();
    }

    finalize_c1_ZFBD((SFc1_ZFBDInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_ZFBD((SFc1_ZFBDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ZFBD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_ZFBD((SFc1_ZFBDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ZFBD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2366601119U));
  ssSetChecksum1(S,(3868017853U));
  ssSetChecksum2(S,(1343039299U));
  ssSetChecksum3(S,(2942815779U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_ZFBD(SimStruct *S)
{
  SFc1_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc1_ZFBDInstanceStruct *)utMalloc(sizeof
    (SFc1_ZFBDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ZFBDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_ZFBD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_ZFBD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_ZFBD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_ZFBD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_ZFBD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_ZFBD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_ZFBD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_ZFBD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ZFBD;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ZFBD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_ZFBD;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_ZFBD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ZFBD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ZFBD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ZFBD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ZFBD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
