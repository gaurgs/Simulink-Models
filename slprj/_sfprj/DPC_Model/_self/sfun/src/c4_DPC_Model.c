/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DPC_Model_sfun.h"
#include "c4_DPC_Model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DPC_Model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[16] = { "NT", "sigma2", "sigma", "a1",
  "a2", "t1", "d1", "d2", "n", "x", "z", "nargin", "nargout", "txdata1", "snrdB",
  "rx_signal" };

/* Function Declarations */
static void initialize_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance);
static void initialize_params_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance);
static void enable_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance);
static void disable_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance);
static void set_sim_state_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance);
static void sf_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance);
static void initSimStructsc4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance);
static void registerMessagesc4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[16]);
static void c4_eml_scalar_eg(SFc4_DPC_ModelInstanceStruct *chartInstance);
static void c4_eml_error(SFc4_DPC_ModelInstanceStruct *chartInstance);
static void c4_b_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_mtimes, const char_T *c4_identifier, creal_T c4_y[40]);
static void c4_c_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, creal_T c4_y[40]);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_DPC_Model, const char_T *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_DPC_ModelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_DPC_Model = 0U;
}

static void initialize_params_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void enable_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  creal_T c4_u[40];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  creal_T (*c4_rx_signal)[40];
  c4_rx_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 40; c4_i0++) {
    c4_u[c4_i0] = (*c4_rx_signal)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 1U, 1U, 0U, 2, 4, 10),
                FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_DPC_Model;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  creal_T c4_dcv0[40];
  int32_T c4_i1;
  creal_T (*c4_rx_signal)[40];
  c4_rx_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                        "rx_signal", c4_dcv0);
  for (c4_i1 = 0; c4_i1 < 40; c4_i1++) {
    (*c4_rx_signal)[c4_i1] = c4_dcv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_DPC_Model = c4_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 1)), "is_active_c4_DPC_Model");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_DPC_Model(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance)
{
}

static void sf_c4_DPC_Model(SFc4_DPC_ModelInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  int32_T c4_i2;
  creal_T c4_txdata1[40];
  real_T c4_snrdB;
  uint32_T c4_debug_family_var_map[16];
  real_T c4_NT;
  real_T c4_sigma2;
  real_T c4_sigma;
  real_T c4_a1[40];
  real_T c4_a2[40];
  creal_T c4_t1[40];
  real_T c4_d1[40];
  real_T c4_d2[40];
  creal_T c4_n[40];
  const mxArray *c4_x = NULL;
  const mxArray *c4_z = NULL;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  creal_T c4_rx_signal[40];
  real_T c4_A;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_y;
  real_T c4_b;
  real_T c4_b_b;
  real_T c4_c_b;
  real_T c4_bk;
  real_T c4_d_b;
  real_T c4_br;
  real_T c4_c;
  real_T c4_e_b;
  real_T c4_d_x;
  real_T c4_e_x;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  creal_T c4_dcv1[40];
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  real_T *c4_b_snrdB;
  creal_T (*c4_b_rx_signal)[40];
  creal_T (*c4_b_txdata1)[40];
  c4_b_snrdB = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_rx_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_txdata1 = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_b_snrdB, 2U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_snrdB;
  for (c4_i2 = 0; c4_i2 < 40; c4_i2++) {
    c4_txdata1[c4_i2] = (*c4_b_txdata1)[c4_i2];
  }

  c4_snrdB = c4_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_NT, 0U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_sigma2, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_sigma, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_a1, 3U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_a2, 4U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_t1, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_d1, 6U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_d2, 7U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_n, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_x, 9U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_z, 10U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 11U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 12U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_txdata1, 13U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_snrdB, 14U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_rx_signal, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 2);
  c4_NT = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_A = -c4_snrdB;
  c4_b_x = c4_A;
  c4_c_x = c4_b_x;
  c4_y = c4_c_x / 10.0;
  c4_b = c4_y;
  c4_b_b = c4_b;
  c4_c_b = c4_b_b;
  c4_eml_scalar_eg(chartInstance);
  c4_bk = c4_c_b;
  c4_d_b = c4_bk;
  c4_eml_scalar_eg(chartInstance);
  c4_br = c4_d_b;
  c4_c = muDoubleScalarPower(10.0, c4_br);
  c4_e_b = c4_c;
  c4_sigma2 = 2.0 * c4_e_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_d_x = c4_sigma2;
  c4_sigma = c4_d_x;
  if (c4_sigma < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_e_x = c4_sigma;
  c4_sigma = c4_e_x;
  c4_sigma = muDoubleScalarSqrt(c4_sigma);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i3 = 0; c4_i3 < 40; c4_i3++) {
    c4_a1[c4_i3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  for (c4_i4 = 0; c4_i4 < 40; c4_i4++) {
    c4_a2[c4_i4] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  for (c4_i5 = 0; c4_i5 < 40; c4_i5++) {
    c4_t1[c4_i5].re = 0.0;
    c4_t1[c4_i5].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i6 = 0; c4_i6 < 40; c4_i6++) {
    c4_d1[c4_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i7 = 0; c4_i7 < 40; c4_i7++) {
    c4_d2[c4_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  for (c4_i8 = 0; c4_i8 < 40; c4_i8++) {
    c4_n[c4_i8].re = 0.0;
    c4_n[c4_i8].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_u = 4.0;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_b_u = 10.0;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_x, sf_mex_call_debug("randn", 1U, 2U, 14, c4_b_y, 14, c4_c_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_c_u = 4.0;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_d_u = 10.0;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_z, sf_mex_call_debug("randn", 1U, 2U, 14, c4_d_y, 14, c4_e_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  c4_e_u = c4_sigma;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_call_debug("mtimes", 1U, 2U, 14,
    c4_f_y, 14, sf_mex_call_debug("complex", 1U, 2U, 14, sf_mex_dup(c4_x), 14,
    sf_mex_dup(c4_z))), "mtimes", c4_dcv1);
  for (c4_i9 = 0; c4_i9 < 40; c4_i9++) {
    c4_n[c4_i9] = c4_dcv1[c4_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  for (c4_i10 = 0; c4_i10 < 40; c4_i10++) {
    c4_rx_signal[c4_i10].re = c4_txdata1[c4_i10].re + c4_n[c4_i10].re;
    c4_rx_signal[c4_i10].im = c4_txdata1[c4_i10].im + c4_n[c4_i10].im;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c4_x);
  sf_mex_destroy(&c4_z);
  for (c4_i11 = 0; c4_i11 < 40; c4_i11++) {
    (*c4_b_rx_signal)[c4_i11] = c4_rx_signal[c4_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DPC_ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc4_DPC_Model(SFc4_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  creal_T c4_b_inData[40];
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  creal_T c4_u[40];
  const mxArray *c4_y = NULL;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i12 = 0;
  for (c4_i13 = 0; c4_i13 < 10; c4_i13++) {
    for (c4_i14 = 0; c4_i14 < 4; c4_i14++) {
      c4_b_inData[c4_i14 + c4_i12] = (*(creal_T (*)[40])c4_inData)[c4_i14 +
        c4_i12];
    }

    c4_i12 += 4;
  }

  c4_i15 = 0;
  for (c4_i16 = 0; c4_i16 < 10; c4_i16++) {
    for (c4_i17 = 0; c4_i17 < 4; c4_i17++) {
      c4_u[c4_i17 + c4_i15] = c4_b_inData[c4_i17 + c4_i15];
    }

    c4_i15 += 4;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 1U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_mtimes;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  creal_T c4_y[40];
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_mtimes = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_mtimes), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_mtimes);
  c4_i18 = 0;
  for (c4_i19 = 0; c4_i19 < 10; c4_i19++) {
    for (c4_i20 = 0; c4_i20 < 4; c4_i20++) {
      (*(creal_T (*)[40])c4_outData)[c4_i20 + c4_i18] = c4_y[c4_i20 + c4_i18];
    }

    c4_i18 += 4;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  const mxArray *c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = sf_mex_dup(*(const mxArray **)c4_inData);
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), FALSE);
  sf_mex_destroy(&c4_u);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  real_T c4_b_inData[40];
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  real_T c4_u[40];
  const mxArray *c4_y = NULL;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i21 = 0;
  for (c4_i22 = 0; c4_i22 < 10; c4_i22++) {
    for (c4_i23 = 0; c4_i23 < 4; c4_i23++) {
      c4_b_inData[c4_i23 + c4_i21] = (*(real_T (*)[40])c4_inData)[c4_i23 +
        c4_i21];
    }

    c4_i21 += 4;
  }

  c4_i24 = 0;
  for (c4_i25 = 0; c4_i25 < 10; c4_i25++) {
    for (c4_i26 = 0; c4_i26 < 4; c4_i26++) {
      c4_u[c4_i26 + c4_i24] = c4_b_inData[c4_i26 + c4_i24];
    }

    c4_i24 += 4;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_DPC_Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[16];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i27;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16), FALSE);
  for (c4_i27 = 0; c4_i27 < 16; c4_i27++) {
    c4_r0 = &c4_info[c4_i27];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i27);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i27);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i27);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i27);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i27);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i27);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i27);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i27);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[16])
{
  c4_info[0].context = "";
  c4_info[0].name = "mtimes";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[0].fileTimeLo = 1289503492U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 0U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context = "";
  c4_info[1].name = "mrdivide";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[1].fileTimeLo = 1357935348U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 1319717366U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[2].name = "rdivide";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[2].fileTimeLo = 1346497788U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[3].name = "eml_scalexp_compatible";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c4_info[3].fileTimeLo = 1286806196U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[4].name = "eml_div";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[4].fileTimeLo = 1313335210U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context = "";
  c4_info[5].name = "mpower";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[5].fileTimeLo = 1286806242U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[6].name = "power";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[6].fileTimeLo = 1348179330U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c4_info[7].name = "eml_scalar_eg";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[7].fileTimeLo = 1286806196U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c4_info[8].name = "eml_scalexp_alloc";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[8].fileTimeLo = 1352408660U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c4_info[9].name = "floor";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c4_info[9].fileTimeLo = 1343817780U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 0U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c4_info[10].name = "eml_scalar_floor";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c4_info[10].fileTimeLo = 1286806126U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c4_info[11].name = "eml_error";
  c4_info[11].dominantType = "char";
  c4_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[11].fileTimeLo = 1343817758U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c4_info[12].name = "eml_scalar_eg";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[12].fileTimeLo = 1286806196U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
  c4_info[13].context = "";
  c4_info[13].name = "sqrt";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[13].fileTimeLo = 1343817786U;
  c4_info[13].fileTimeHi = 0U;
  c4_info[13].mFileTimeLo = 0U;
  c4_info[13].mFileTimeHi = 0U;
  c4_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[14].name = "eml_error";
  c4_info[14].dominantType = "char";
  c4_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[14].fileTimeLo = 1343817758U;
  c4_info[14].fileTimeHi = 0U;
  c4_info[14].mFileTimeLo = 0U;
  c4_info[14].mFileTimeHi = 0U;
  c4_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[15].name = "eml_scalar_sqrt";
  c4_info[15].dominantType = "double";
  c4_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c4_info[15].fileTimeLo = 1286806138U;
  c4_info[15].fileTimeHi = 0U;
  c4_info[15].mFileTimeLo = 0U;
  c4_info[15].mFileTimeHi = 0U;
}

static void c4_eml_scalar_eg(SFc4_DPC_ModelInstanceStruct *chartInstance)
{
}

static void c4_eml_error(SFc4_DPC_ModelInstanceStruct *chartInstance)
{
  int32_T c4_i28;
  static char_T c4_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c4_u[30];
  const mxArray *c4_y = NULL;
  int32_T c4_i29;
  static char_T c4_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c4_b_u[4];
  const mxArray *c4_b_y = NULL;
  for (c4_i28 = 0; c4_i28 < 30; c4_i28++) {
    c4_u[c4_i28] = c4_cv0[c4_i28];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c4_i29 = 0; c4_i29 < 4; c4_i29++) {
    c4_b_u[c4_i29] = c4_cv1[c4_i29];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c4_y, 14, c4_b_y));
}

static void c4_b_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_mtimes, const char_T *c4_identifier, creal_T c4_y[40])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_mtimes), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_mtimes);
}

static void c4_c_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, creal_T c4_y[40])
{
  creal_T c4_dcv2[40];
  int32_T c4_i30;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dcv2, 1, 0, 1U, 1, 0U, 2, 4,
                10);
  for (c4_i30 = 0; c4_i30 < 40; c4_i30++) {
    c4_y[c4_i30] = c4_dcv2[c4_i30];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i31;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i31, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i31;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_DPC_Model, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_DPC_Model), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_DPC_Model);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_DPC_ModelInstanceStruct *chartInstance)
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

void sf_c4_DPC_Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3851405200U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2437627678U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1109254032U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1694530488U);
}

mxArray *sf_c4_DPC_Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QYODx525VAXVhxpURf21AB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c4_DPC_Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_DPC_Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"rx_signal\",},{M[8],M[0],T\"is_active_c4_DPC_Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_DPC_Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_DPC_ModelInstanceStruct *chartInstance;
    chartInstance = (SFc4_DPC_ModelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DPC_ModelMachineNumber_,
           4,
           1,
           1,
           3,
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
          init_script_number_translation(_DPC_ModelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DPC_ModelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DPC_ModelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"txdata1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"rx_signal");
          _SFD_SET_DATA_PROPS(2,1,1,0,"snrdB");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,417);
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
            1.0,0,1,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_snrdB;
          creal_T (*c4_txdata1)[40];
          creal_T (*c4_rx_signal)[40];
          c4_snrdB = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_rx_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S,
            1);
          c4_txdata1 = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_txdata1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_rx_signal);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_snrdB);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DPC_ModelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Aw8V1LkSXjxnjiwHuAZhzF";
}

static void sf_opaque_initialize_c4_DPC_Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*)
    chartInstanceVar);
  initialize_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_DPC_Model(void *chartInstanceVar)
{
  enable_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_DPC_Model(void *chartInstanceVar)
{
  disable_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_DPC_Model(void *chartInstanceVar)
{
  sf_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_DPC_Model(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_DPC_Model();/* state var info */
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

extern void sf_internal_set_sim_state_c4_DPC_Model(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_DPC_Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_DPC_Model(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_DPC_Model(S);
}

static void sf_opaque_set_sim_state_c4_DPC_Model(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_DPC_Model(S, st);
}

static void sf_opaque_terminate_c4_DPC_Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DPC_Model_optimization_info();
    }

    finalize_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_DPC_Model((SFc4_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_DPC_Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_DPC_Model((SFc4_DPC_ModelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DPC_Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2492654307U));
  ssSetChecksum1(S,(148067526U));
  ssSetChecksum2(S,(365551428U));
  ssSetChecksum3(S,(3038207743U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_DPC_Model(SimStruct *S)
{
  SFc4_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_DPC_ModelInstanceStruct *)utMalloc(sizeof
    (SFc4_DPC_ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_DPC_ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_DPC_Model;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_DPC_Model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_DPC_Model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_DPC_Model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_DPC_Model;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_DPC_Model;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_DPC_Model;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_DPC_Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_DPC_Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_DPC_Model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_DPC_Model;
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

void c4_DPC_Model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_DPC_Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_DPC_Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_DPC_Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_DPC_Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
