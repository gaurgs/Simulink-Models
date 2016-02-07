/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DPC_Model_sfun.h"
#include "c1_DPC_Model.h"
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
static const char * c1_debug_family_names[5] = { "nargin", "nargout",
  "rx_signal", "l", "y" };

/* Function Declarations */
static void initialize_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void initialize_params_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance);
static void enable_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void disable_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance);
static void set_sim_state_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void sf_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void c1_chartstep_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance);
static void initSimStructsc1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance);
static void registerMessagesc1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_y, const char_T *c1_identifier, creal_T c1_b_y[40]);
static void c1_b_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, creal_T c1_y[40]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[134]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[134]);
static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[134]);
static void c1_invNxN(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T c1_x
                      [16], creal_T c1_y[16]);
static void c1_realmin(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void c1_eps(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void c1_eml_matlab_zgetrf(SFc1_DPC_ModelInstanceStruct *chartInstance,
  creal_T c1_A[16], creal_T c1_b_A[16], int32_T c1_ipiv[4], int32_T *c1_info);
static void c1_check_forloop_overflow_error(SFc1_DPC_ModelInstanceStruct
  *chartInstance, boolean_T c1_overflow);
static creal_T c1_eml_div(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T
  c1_x, creal_T c1_y);
static void c1_eml_xgeru(SFc1_DPC_ModelInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0, int32_T c1_iy0, creal_T
  c1_A[16], int32_T c1_ia0, creal_T c1_b_A[16]);
static void c1_eml_xtrsm(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T
  c1_A[16], creal_T c1_B[16], creal_T c1_b_B[16]);
static real_T c1_norm(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T c1_x
                      [16]);
static void c1_eml_warning(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void c1_b_eml_warning(SFc1_DPC_ModelInstanceStruct *chartInstance, char_T
  c1_varargin_2[14]);
static void c1_eml_scalar_eg(SFc1_DPC_ModelInstanceStruct *chartInstance);
static void c1_d_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_sprintf, const char_T *c1_identifier, char_T c1_y[14]);
static void c1_e_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, char_T c1_y[14]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_DPC_Model, const char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_eml_matlab_zgetrf(SFc1_DPC_ModelInstanceStruct *chartInstance,
  creal_T c1_A[16], int32_T c1_ipiv[4], int32_T *c1_info);
static void c1_b_eml_xgeru(SFc1_DPC_ModelInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0, int32_T c1_iy0, creal_T
  c1_A[16], int32_T c1_ia0);
static void c1_b_eml_xtrsm(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T
  c1_A[16], creal_T c1_B[16]);
static void init_dsm_address_info(SFc1_DPC_ModelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_DPC_Model = 0U;
}

static void initialize_params_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void enable_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
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
  creal_T (*c1_d_y)[40];
  c1_d_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 40; c1_i0++) {
    c1_u[c1_i0] = (*c1_d_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 4, 10),
                FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_DPC_Model;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  creal_T c1_dcv0[40];
  int32_T c1_i1;
  creal_T (*c1_y)[40];
  c1_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                      c1_dcv0);
  for (c1_i1 = 0; c1_i1 < 40; c1_i1++) {
    (*c1_y)[c1_i1] = c1_dcv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_DPC_Model = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "is_active_c1_DPC_Model");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_DPC_Model(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
}

static void sf_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_DPC_Model(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DPC_ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  creal_T c1_rx_signal[40];
  int32_T c1_i3;
  creal_T c1_l[16];
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  creal_T c1_y[40];
  int32_T c1_i4;
  creal_T c1_u[16];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i5;
  creal_T c1_x[16];
  int32_T c1_i6;
  creal_T c1_b_x[16];
  creal_T c1_c_y[16];
  int32_T c1_i7;
  creal_T c1_c_x[16];
  real_T c1_n1x;
  int32_T c1_i8;
  creal_T c1_d_y[16];
  real_T c1_n1xinv;
  real_T c1_a;
  real_T c1_b;
  real_T c1_e_y;
  real_T c1_rc;
  real_T c1_d_x;
  boolean_T c1_b_b;
  real_T c1_e_x;
  int32_T c1_i9;
  static char_T c1_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c1_b_u[8];
  const mxArray *c1_f_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_i_y = NULL;
  char_T c1_str[14];
  int32_T c1_i10;
  char_T c1_b_str[14];
  int32_T c1_i11;
  creal_T c1_c_b[40];
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  creal_T c1_C[40];
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  creal_T c1_j_y;
  int32_T c1_i23;
  creal_T (*c1_k_y)[40];
  creal_T (*c1_b_l)[16];
  creal_T (*c1_b_rx_signal)[40];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_b_l = (creal_T (*)[16])ssGetInputPortSignal(chartInstance->S, 1);
  c1_k_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_rx_signal = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 40; c1_i2++) {
    c1_rx_signal[c1_i2] = (*c1_b_rx_signal)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 16; c1_i3++) {
    c1_l[c1_i3] = (*c1_b_l)[c1_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_rx_signal, 2U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_l, 3U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  sf_mex_printf("%s =\\n", "l");
  for (c1_i4 = 0; c1_i4 < 16; c1_i4++) {
    c1_u[c1_i4] = c1_l[c1_i4];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c1_b_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i5 = 0; c1_i5 < 16; c1_i5++) {
    c1_x[c1_i5] = c1_l[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 16; c1_i6++) {
    c1_b_x[c1_i6] = c1_x[c1_i6];
  }

  c1_invNxN(chartInstance, c1_b_x, c1_c_y);
  for (c1_i7 = 0; c1_i7 < 16; c1_i7++) {
    c1_c_x[c1_i7] = c1_x[c1_i7];
  }

  c1_n1x = c1_norm(chartInstance, c1_c_x);
  for (c1_i8 = 0; c1_i8 < 16; c1_i8++) {
    c1_d_y[c1_i8] = c1_c_y[c1_i8];
  }

  c1_n1xinv = c1_norm(chartInstance, c1_d_y);
  c1_a = c1_n1x;
  c1_b = c1_n1xinv;
  c1_e_y = c1_a * c1_b;
  c1_rc = 1.0 / c1_e_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c1_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c1_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c1_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c1_d_x = c1_rc;
    c1_b_b = muDoubleScalarIsNaN(c1_d_x);
    guard3 = FALSE;
    if (c1_b_b) {
      guard3 = TRUE;
    } else {
      c1_eps(chartInstance);
      if (c1_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c1_e_x = c1_rc;
      for (c1_i9 = 0; c1_i9 < 8; c1_i9++) {
        c1_b_u[c1_i9] = c1_cv0[c1_i9];
      }

      c1_f_y = NULL;
      sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c1_c_u = 14.0;
      c1_g_y = NULL;
      sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_d_u = 6.0;
      c1_h_y = NULL;
      sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_e_u = c1_e_x;
      c1_i_y = NULL;
      sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c1_f_y, 14, c1_g_y, 14,
        c1_h_y), 14, c1_i_y), "sprintf", c1_str);
      for (c1_i10 = 0; c1_i10 < 14; c1_i10++) {
        c1_b_str[c1_i10] = c1_str[c1_i10];
      }

      c1_b_eml_warning(chartInstance, c1_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c1_eml_warning(chartInstance);
  }

  for (c1_i11 = 0; c1_i11 < 40; c1_i11++) {
    c1_c_b[c1_i11] = c1_rx_signal[c1_i11];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i12 = 0; c1_i12 < 40; c1_i12++) {
    c1_y[c1_i12].re = 0.0;
    c1_y[c1_i12].im = 0.0;
  }

  for (c1_i13 = 0; c1_i13 < 40; c1_i13++) {
    c1_y[c1_i13].re = 0.0;
    c1_y[c1_i13].im = 0.0;
  }

  for (c1_i14 = 0; c1_i14 < 40; c1_i14++) {
    c1_C[c1_i14] = c1_y[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 40; c1_i15++) {
    c1_y[c1_i15] = c1_C[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 40; c1_i16++) {
    c1_C[c1_i16] = c1_y[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 40; c1_i17++) {
    c1_y[c1_i17] = c1_C[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 4; c1_i18++) {
    c1_i19 = 0;
    for (c1_i20 = 0; c1_i20 < 10; c1_i20++) {
      c1_y[c1_i19 + c1_i18].re = 0.0;
      c1_y[c1_i19 + c1_i18].im = 0.0;
      c1_i21 = 0;
      for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
        c1_j_y.re = c1_c_y[c1_i21 + c1_i18].re * c1_c_b[c1_i22 + c1_i19].re -
          c1_c_y[c1_i21 + c1_i18].im * c1_c_b[c1_i22 + c1_i19].im;
        c1_j_y.im = c1_c_y[c1_i21 + c1_i18].re * c1_c_b[c1_i22 + c1_i19].im +
          c1_c_y[c1_i21 + c1_i18].im * c1_c_b[c1_i22 + c1_i19].re;
        c1_y[c1_i19 + c1_i18].re += c1_j_y.re;
        c1_y[c1_i19 + c1_i18].im += c1_j_y.im;
        c1_i21 += 4;
      }

      c1_i19 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i23 = 0; c1_i23 < 40; c1_i23++) {
    (*c1_k_y)[c1_i23] = c1_y[c1_i23];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_DPC_Model(SFc1_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  creal_T c1_b_inData[40];
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  creal_T c1_u[40];
  const mxArray *c1_y = NULL;
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i24 = 0;
  for (c1_i25 = 0; c1_i25 < 10; c1_i25++) {
    for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
      c1_b_inData[c1_i26 + c1_i24] = (*(creal_T (*)[40])c1_inData)[c1_i26 +
        c1_i24];
    }

    c1_i24 += 4;
  }

  c1_i27 = 0;
  for (c1_i28 = 0; c1_i28 < 10; c1_i28++) {
    for (c1_i29 = 0; c1_i29 < 4; c1_i29++) {
      c1_u[c1_i29 + c1_i27] = c1_b_inData[c1_i29 + c1_i27];
    }

    c1_i27 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_y, const char_T *c1_identifier, creal_T c1_b_y[40])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
}

static void c1_b_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, creal_T c1_y[40])
{
  creal_T c1_dcv1[40];
  int32_T c1_i30;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dcv1, 1, 0, 1U, 1, 0U, 2, 4,
                10);
  for (c1_i30 = 0; c1_i30 < 40; c1_i30++) {
    c1_y[c1_i30] = c1_dcv1[c1_i30];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  creal_T c1_b_y[40];
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  c1_i31 = 0;
  for (c1_i32 = 0; c1_i32 < 10; c1_i32++) {
    for (c1_i33 = 0; c1_i33 < 4; c1_i33++) {
      (*(creal_T (*)[40])c1_outData)[c1_i33 + c1_i31] = c1_b_y[c1_i33 + c1_i31];
    }

    c1_i31 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  creal_T c1_b_inData[16];
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  creal_T c1_u[16];
  const mxArray *c1_y = NULL;
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i34 = 0;
  for (c1_i35 = 0; c1_i35 < 4; c1_i35++) {
    for (c1_i36 = 0; c1_i36 < 4; c1_i36++) {
      c1_b_inData[c1_i36 + c1_i34] = (*(creal_T (*)[16])c1_inData)[c1_i36 +
        c1_i34];
    }

    c1_i34 += 4;
  }

  c1_i37 = 0;
  for (c1_i38 = 0; c1_i38 < 4; c1_i38++) {
    for (c1_i39 = 0; c1_i39 < 4; c1_i39++) {
      c1_u[c1_i39 + c1_i37] = c1_b_inData[c1_i39 + c1_i37];
    }

    c1_i37 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
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
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_DPC_Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[134];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i40;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  c1_c_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 134), FALSE);
  for (c1_i40 = 0; c1_i40 < 134; c1_i40++) {
    c1_r0 = &c1_info[c1_i40];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i40);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[134])
{
  c1_info[0].context = "";
  c1_info[0].name = "inv";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c1_info[0].fileTimeLo = 1305305400U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[1].name = "eml_index_class";
  c1_info[1].dominantType = "";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[1].fileTimeLo = 1323154378U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[2].name = "eml_xgetrf";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[2].fileTimeLo = 1286806206U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[3].name = "eml_lapack_xgetrf";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[3].fileTimeLo = 1286806210U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[4].name = "eml_matlab_zgetrf";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[4].fileTimeLo = 1302676394U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[5].name = "realmin";
  c1_info[5].dominantType = "char";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[5].fileTimeLo = 1307638642U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[6].name = "eml_realmin";
  c1_info[6].dominantType = "char";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[6].fileTimeLo = 1307638644U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[7].name = "eml_float_model";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[7].fileTimeLo = 1326711796U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[8].name = "eps";
  c1_info[8].dominantType = "char";
  c1_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[8].fileTimeLo = 1326711796U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[9].name = "eml_is_float_class";
  c1_info[9].dominantType = "char";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[9].fileTimeLo = 1286806182U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[10].name = "eml_eps";
  c1_info[10].dominantType = "char";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[10].fileTimeLo = 1326711796U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[11].name = "eml_float_model";
  c1_info[11].dominantType = "char";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[11].fileTimeLo = 1326711796U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[12].name = "min";
  c1_info[12].dominantType = "coder.internal.indexInt";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[12].fileTimeLo = 1311242718U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[13].name = "eml_min_or_max";
  c1_info[13].dominantType = "char";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[13].fileTimeLo = 1334058890U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[14].name = "eml_scalar_eg";
  c1_info[14].dominantType = "coder.internal.indexInt";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[14].fileTimeLo = 1286806196U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[15].name = "eml_scalexp_alloc";
  c1_info[15].dominantType = "coder.internal.indexInt";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[15].fileTimeLo = 1352408660U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[16].name = "eml_index_class";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[16].fileTimeLo = 1323154378U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[17].name = "eml_scalar_eg";
  c1_info[17].dominantType = "coder.internal.indexInt";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[17].fileTimeLo = 1286806196U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[18].name = "colon";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[18].fileTimeLo = 1348179328U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[19].name = "colon";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[19].fileTimeLo = 1348179328U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[20].name = "floor";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[20].fileTimeLo = 1343817780U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[21].name = "eml_scalar_floor";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[21].fileTimeLo = 1286806126U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[22].name = "intmin";
  c1_info[22].dominantType = "char";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[22].fileTimeLo = 1311242718U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[23].name = "intmax";
  c1_info[23].dominantType = "char";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[23].fileTimeLo = 1311242716U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[24].name = "intmin";
  c1_info[24].dominantType = "char";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[24].fileTimeLo = 1311242718U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[25].name = "intmax";
  c1_info[25].dominantType = "char";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[25].fileTimeLo = 1311242716U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[26].name = "eml_isa_uint";
  c1_info[26].dominantType = "coder.internal.indexInt";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[26].fileTimeLo = 1286806184U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[27].name = "eml_unsigned_class";
  c1_info[27].dominantType = "char";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[27].fileTimeLo = 1323154380U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[28].name = "eml_index_class";
  c1_info[28].dominantType = "";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[28].fileTimeLo = 1323154378U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[29].name = "eml_index_class";
  c1_info[29].dominantType = "";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[29].fileTimeLo = 1323154378U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[30].name = "intmax";
  c1_info[30].dominantType = "char";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[30].fileTimeLo = 1311242716U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[31].name = "eml_isa_uint";
  c1_info[31].dominantType = "coder.internal.indexInt";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[31].fileTimeLo = 1286806184U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[32].name = "eml_index_plus";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[32].fileTimeLo = 1286806178U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[33].name = "eml_index_class";
  c1_info[33].dominantType = "";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[33].fileTimeLo = 1323154378U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c1_info[34].name = "eml_int_forloop_overflow_check";
  c1_info[34].dominantType = "";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[34].fileTimeLo = 1346497740U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[35].name = "intmax";
  c1_info[35].dominantType = "char";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[35].fileTimeLo = 1311242716U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[36].name = "eml_index_class";
  c1_info[36].dominantType = "";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[36].fileTimeLo = 1323154378U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[37].name = "eml_index_plus";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[37].fileTimeLo = 1286806178U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[38].name = "eml_int_forloop_overflow_check";
  c1_info[38].dominantType = "";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[38].fileTimeLo = 1346497740U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[39].name = "eml_index_minus";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[39].fileTimeLo = 1286806178U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[40].name = "eml_index_class";
  c1_info[40].dominantType = "";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[40].fileTimeLo = 1323154378U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[41].name = "eml_index_minus";
  c1_info[41].dominantType = "coder.internal.indexInt";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[41].fileTimeLo = 1286806178U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[42].name = "eml_index_times";
  c1_info[42].dominantType = "coder.internal.indexInt";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[42].fileTimeLo = 1286806180U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[43].name = "eml_index_class";
  c1_info[43].dominantType = "";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[43].fileTimeLo = 1323154378U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[44].name = "eml_index_plus";
  c1_info[44].dominantType = "coder.internal.indexInt";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[44].fileTimeLo = 1286806178U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[45].name = "eml_ixamax";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[45].fileTimeLo = 1299060570U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[46].name = "eml_blas_inline";
  c1_info[46].dominantType = "";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[46].fileTimeLo = 1299060568U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c1_info[47].name = "length";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[47].fileTimeLo = 1303133606U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c1_info[48].name = "eml_index_class";
  c1_info[48].dominantType = "";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[48].fileTimeLo = 1323154378U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[49].name = "eml_index_class";
  c1_info[49].dominantType = "";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[49].fileTimeLo = 1323154378U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[50].name = "eml_refblas_ixamax";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[50].fileTimeLo = 1299060570U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[51].name = "eml_index_class";
  c1_info[51].dominantType = "";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[51].fileTimeLo = 1323154378U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[52].name = "eml_xcabs1";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[52].fileTimeLo = 1286806106U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[53].name = "abs";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[53].fileTimeLo = 1343817766U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[54].name = "eml_scalar_abs";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[54].fileTimeLo = 1286806112U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[55].name = "eml_int_forloop_overflow_check";
  c1_info[55].dominantType = "";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[55].fileTimeLo = 1346497740U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[56].name = "eml_index_plus";
  c1_info[56].dominantType = "coder.internal.indexInt";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[56].fileTimeLo = 1286806178U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[57].name = "eml_xswap";
  c1_info[57].dominantType = "double";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[57].fileTimeLo = 1299060578U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[58].name = "eml_blas_inline";
  c1_info[58].dominantType = "";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[58].fileTimeLo = 1299060568U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[59].name = "eml_index_class";
  c1_info[59].dominantType = "";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[59].fileTimeLo = 1323154378U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[60].name = "eml_refblas_xswap";
  c1_info[60].dominantType = "double";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[60].fileTimeLo = 1299060586U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[61].name = "eml_index_class";
  c1_info[61].dominantType = "";
  c1_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[61].fileTimeLo = 1323154378U;
  c1_info[61].fileTimeHi = 0U;
  c1_info[61].mFileTimeLo = 0U;
  c1_info[61].mFileTimeHi = 0U;
  c1_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[62].name = "abs";
  c1_info[62].dominantType = "coder.internal.indexInt";
  c1_info[62].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[62].fileTimeLo = 1343817766U;
  c1_info[62].fileTimeHi = 0U;
  c1_info[62].mFileTimeLo = 0U;
  c1_info[62].mFileTimeHi = 0U;
  c1_info[63].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[63].name = "eml_scalar_abs";
  c1_info[63].dominantType = "coder.internal.indexInt";
  c1_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[63].fileTimeLo = 1286806112U;
  c1_info[63].fileTimeHi = 0U;
  c1_info[63].mFileTimeLo = 0U;
  c1_info[63].mFileTimeHi = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[134])
{
  c1_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[64].name = "eml_int_forloop_overflow_check";
  c1_info[64].dominantType = "";
  c1_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[64].fileTimeLo = 1346497740U;
  c1_info[64].fileTimeHi = 0U;
  c1_info[64].mFileTimeLo = 0U;
  c1_info[64].mFileTimeHi = 0U;
  c1_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[65].name = "eml_index_plus";
  c1_info[65].dominantType = "coder.internal.indexInt";
  c1_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[65].fileTimeLo = 1286806178U;
  c1_info[65].fileTimeHi = 0U;
  c1_info[65].mFileTimeLo = 0U;
  c1_info[65].mFileTimeHi = 0U;
  c1_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[66].name = "eml_div";
  c1_info[66].dominantType = "double";
  c1_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[66].fileTimeLo = 1313335210U;
  c1_info[66].fileTimeHi = 0U;
  c1_info[66].mFileTimeLo = 0U;
  c1_info[66].mFileTimeHi = 0U;
  c1_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c1_info[67].name = "eml_scalar_eg";
  c1_info[67].dominantType = "double";
  c1_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[67].fileTimeLo = 1286806196U;
  c1_info[67].fileTimeHi = 0U;
  c1_info[67].mFileTimeLo = 0U;
  c1_info[67].mFileTimeHi = 0U;
  c1_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c1_info[68].name = "eml_scalexp_alloc";
  c1_info[68].dominantType = "double";
  c1_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[68].fileTimeLo = 1352408660U;
  c1_info[68].fileTimeHi = 0U;
  c1_info[68].mFileTimeLo = 0U;
  c1_info[68].mFileTimeHi = 0U;
  c1_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c1_info[69].name = "abs";
  c1_info[69].dominantType = "double";
  c1_info[69].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[69].fileTimeLo = 1343817766U;
  c1_info[69].fileTimeHi = 0U;
  c1_info[69].mFileTimeLo = 0U;
  c1_info[69].mFileTimeHi = 0U;
  c1_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c1_info[70].name = "mtimes";
  c1_info[70].dominantType = "double";
  c1_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[70].fileTimeLo = 1289503492U;
  c1_info[70].fileTimeHi = 0U;
  c1_info[70].mFileTimeLo = 0U;
  c1_info[70].mFileTimeHi = 0U;
  c1_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[71].name = "eml_xgeru";
  c1_info[71].dominantType = "double";
  c1_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[71].fileTimeLo = 1299060574U;
  c1_info[71].fileTimeHi = 0U;
  c1_info[71].mFileTimeLo = 0U;
  c1_info[71].mFileTimeHi = 0U;
  c1_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[72].name = "eml_blas_inline";
  c1_info[72].dominantType = "";
  c1_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[72].fileTimeLo = 1299060568U;
  c1_info[72].fileTimeHi = 0U;
  c1_info[72].mFileTimeLo = 0U;
  c1_info[72].mFileTimeHi = 0U;
  c1_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgeru.m!below_threshold";
  c1_info[73].name = "intmax";
  c1_info[73].dominantType = "char";
  c1_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[73].fileTimeLo = 1311242716U;
  c1_info[73].fileTimeHi = 0U;
  c1_info[73].mFileTimeLo = 0U;
  c1_info[73].mFileTimeHi = 0U;
  c1_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgeru.m!below_threshold";
  c1_info[74].name = "min";
  c1_info[74].dominantType = "double";
  c1_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[74].fileTimeLo = 1311242718U;
  c1_info[74].fileTimeHi = 0U;
  c1_info[74].mFileTimeLo = 0U;
  c1_info[74].mFileTimeHi = 0U;
  c1_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[75].name = "eml_scalar_eg";
  c1_info[75].dominantType = "double";
  c1_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[75].fileTimeLo = 1286806196U;
  c1_info[75].fileTimeHi = 0U;
  c1_info[75].mFileTimeLo = 0U;
  c1_info[75].mFileTimeHi = 0U;
  c1_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[76].name = "eml_scalexp_alloc";
  c1_info[76].dominantType = "double";
  c1_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[76].fileTimeLo = 1352408660U;
  c1_info[76].fileTimeHi = 0U;
  c1_info[76].mFileTimeLo = 0U;
  c1_info[76].mFileTimeHi = 0U;
  c1_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[77].name = "eml_scalar_eg";
  c1_info[77].dominantType = "double";
  c1_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[77].fileTimeLo = 1286806196U;
  c1_info[77].fileTimeHi = 0U;
  c1_info[77].mFileTimeLo = 0U;
  c1_info[77].mFileTimeHi = 0U;
  c1_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgeru.m!below_threshold";
  c1_info[78].name = "mtimes";
  c1_info[78].dominantType = "double";
  c1_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[78].fileTimeLo = 1289503492U;
  c1_info[78].fileTimeHi = 0U;
  c1_info[78].mFileTimeLo = 0U;
  c1_info[78].mFileTimeHi = 0U;
  c1_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgeru.m";
  c1_info[79].name = "eml_index_class";
  c1_info[79].dominantType = "";
  c1_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[79].fileTimeLo = 1323154378U;
  c1_info[79].fileTimeHi = 0U;
  c1_info[79].mFileTimeLo = 0U;
  c1_info[79].mFileTimeHi = 0U;
  c1_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgeru.m";
  c1_info[80].name = "eml_scalar_eg";
  c1_info[80].dominantType = "double";
  c1_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[80].fileTimeLo = 1286806196U;
  c1_info[80].fileTimeHi = 0U;
  c1_info[80].mFileTimeLo = 0U;
  c1_info[80].mFileTimeHi = 0U;
  c1_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgeru.m";
  c1_info[81].name = "eml_refblas_xgeru";
  c1_info[81].dominantType = "double";
  c1_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgeru.m";
  c1_info[81].fileTimeLo = 1299060576U;
  c1_info[81].fileTimeHi = 0U;
  c1_info[81].mFileTimeLo = 0U;
  c1_info[81].mFileTimeHi = 0U;
  c1_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgeru.m";
  c1_info[82].name = "eml_refblas_xgerx";
  c1_info[82].dominantType = "char";
  c1_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[82].fileTimeLo = 1299060578U;
  c1_info[82].fileTimeHi = 0U;
  c1_info[82].mFileTimeLo = 0U;
  c1_info[82].mFileTimeHi = 0U;
  c1_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[83].name = "eml_index_class";
  c1_info[83].dominantType = "";
  c1_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[83].fileTimeLo = 1323154378U;
  c1_info[83].fileTimeHi = 0U;
  c1_info[83].mFileTimeLo = 0U;
  c1_info[83].mFileTimeHi = 0U;
  c1_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[84].name = "abs";
  c1_info[84].dominantType = "coder.internal.indexInt";
  c1_info[84].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[84].fileTimeLo = 1343817766U;
  c1_info[84].fileTimeHi = 0U;
  c1_info[84].mFileTimeLo = 0U;
  c1_info[84].mFileTimeHi = 0U;
  c1_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[85].name = "eml_index_minus";
  c1_info[85].dominantType = "double";
  c1_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[85].fileTimeLo = 1286806178U;
  c1_info[85].fileTimeHi = 0U;
  c1_info[85].mFileTimeLo = 0U;
  c1_info[85].mFileTimeHi = 0U;
  c1_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[86].name = "eml_int_forloop_overflow_check";
  c1_info[86].dominantType = "";
  c1_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[86].fileTimeLo = 1346497740U;
  c1_info[86].fileTimeHi = 0U;
  c1_info[86].mFileTimeLo = 0U;
  c1_info[86].mFileTimeHi = 0U;
  c1_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[87].name = "eml_index_plus";
  c1_info[87].dominantType = "double";
  c1_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[87].fileTimeLo = 1286806178U;
  c1_info[87].fileTimeHi = 0U;
  c1_info[87].mFileTimeLo = 0U;
  c1_info[87].mFileTimeHi = 0U;
  c1_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[88].name = "eml_index_plus";
  c1_info[88].dominantType = "coder.internal.indexInt";
  c1_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[88].fileTimeLo = 1286806178U;
  c1_info[88].fileTimeHi = 0U;
  c1_info[88].mFileTimeLo = 0U;
  c1_info[88].mFileTimeHi = 0U;
  c1_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[89].name = "eml_ipiv2perm";
  c1_info[89].dominantType = "coder.internal.indexInt";
  c1_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c1_info[89].fileTimeLo = 1286806182U;
  c1_info[89].fileTimeHi = 0U;
  c1_info[89].mFileTimeLo = 0U;
  c1_info[89].mFileTimeHi = 0U;
  c1_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c1_info[90].name = "colon";
  c1_info[90].dominantType = "double";
  c1_info[90].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[90].fileTimeLo = 1348179328U;
  c1_info[90].fileTimeHi = 0U;
  c1_info[90].mFileTimeLo = 0U;
  c1_info[90].mFileTimeHi = 0U;
  c1_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c1_info[91].name = "eml_index_class";
  c1_info[91].dominantType = "";
  c1_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[91].fileTimeLo = 1323154378U;
  c1_info[91].fileTimeHi = 0U;
  c1_info[91].mFileTimeLo = 0U;
  c1_info[91].mFileTimeHi = 0U;
  c1_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c1_info[92].name = "coder.internal.indexIntRelop";
  c1_info[92].dominantType = "";
  c1_info[92].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c1_info[92].fileTimeLo = 1326712122U;
  c1_info[92].fileTimeHi = 0U;
  c1_info[92].mFileTimeLo = 0U;
  c1_info[92].mFileTimeHi = 0U;
  c1_info[93].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c1_info[93].name = "eml_float_model";
  c1_info[93].dominantType = "char";
  c1_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[93].fileTimeLo = 1326711796U;
  c1_info[93].fileTimeHi = 0U;
  c1_info[93].mFileTimeLo = 0U;
  c1_info[93].mFileTimeHi = 0U;
  c1_info[94].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c1_info[94].name = "intmin";
  c1_info[94].dominantType = "char";
  c1_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[94].fileTimeLo = 1311242718U;
  c1_info[94].fileTimeHi = 0U;
  c1_info[94].mFileTimeLo = 0U;
  c1_info[94].mFileTimeHi = 0U;
  c1_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[95].name = "eml_int_forloop_overflow_check";
  c1_info[95].dominantType = "";
  c1_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[95].fileTimeLo = 1346497740U;
  c1_info[95].fileTimeHi = 0U;
  c1_info[95].mFileTimeLo = 0U;
  c1_info[95].mFileTimeHi = 0U;
  c1_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[96].name = "eml_index_plus";
  c1_info[96].dominantType = "double";
  c1_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[96].fileTimeLo = 1286806178U;
  c1_info[96].fileTimeHi = 0U;
  c1_info[96].mFileTimeLo = 0U;
  c1_info[96].mFileTimeHi = 0U;
  c1_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[97].name = "mtimes";
  c1_info[97].dominantType = "double";
  c1_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[97].fileTimeLo = 1289503492U;
  c1_info[97].fileTimeHi = 0U;
  c1_info[97].mFileTimeLo = 0U;
  c1_info[97].mFileTimeHi = 0U;
  c1_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[98].name = "eml_scalar_eg";
  c1_info[98].dominantType = "double";
  c1_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[98].fileTimeLo = 1286806196U;
  c1_info[98].fileTimeHi = 0U;
  c1_info[98].mFileTimeLo = 0U;
  c1_info[98].mFileTimeHi = 0U;
  c1_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c1_info[99].name = "eml_xtrsm";
  c1_info[99].dominantType = "char";
  c1_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[99].fileTimeLo = 1299060578U;
  c1_info[99].fileTimeHi = 0U;
  c1_info[99].mFileTimeLo = 0U;
  c1_info[99].mFileTimeHi = 0U;
  c1_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[100].name = "eml_blas_inline";
  c1_info[100].dominantType = "";
  c1_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[100].fileTimeLo = 1299060568U;
  c1_info[100].fileTimeHi = 0U;
  c1_info[100].mFileTimeLo = 0U;
  c1_info[100].mFileTimeHi = 0U;
  c1_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c1_info[101].name = "mtimes";
  c1_info[101].dominantType = "double";
  c1_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[101].fileTimeLo = 1289503492U;
  c1_info[101].fileTimeHi = 0U;
  c1_info[101].mFileTimeLo = 0U;
  c1_info[101].mFileTimeHi = 0U;
  c1_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[102].name = "eml_index_class";
  c1_info[102].dominantType = "";
  c1_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[102].fileTimeLo = 1323154378U;
  c1_info[102].fileTimeHi = 0U;
  c1_info[102].mFileTimeLo = 0U;
  c1_info[102].mFileTimeHi = 0U;
  c1_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[103].name = "eml_scalar_eg";
  c1_info[103].dominantType = "double";
  c1_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[103].fileTimeLo = 1286806196U;
  c1_info[103].fileTimeHi = 0U;
  c1_info[103].mFileTimeLo = 0U;
  c1_info[103].mFileTimeHi = 0U;
  c1_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[104].name = "eml_refblas_xtrsm";
  c1_info[104].dominantType = "char";
  c1_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[104].fileTimeLo = 1299060586U;
  c1_info[104].fileTimeHi = 0U;
  c1_info[104].mFileTimeLo = 0U;
  c1_info[104].mFileTimeHi = 0U;
  c1_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[105].name = "eml_scalar_eg";
  c1_info[105].dominantType = "double";
  c1_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[105].fileTimeLo = 1286806196U;
  c1_info[105].fileTimeHi = 0U;
  c1_info[105].mFileTimeLo = 0U;
  c1_info[105].mFileTimeHi = 0U;
  c1_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[106].name = "eml_index_minus";
  c1_info[106].dominantType = "double";
  c1_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[106].fileTimeLo = 1286806178U;
  c1_info[106].fileTimeHi = 0U;
  c1_info[106].mFileTimeLo = 0U;
  c1_info[106].mFileTimeHi = 0U;
  c1_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[107].name = "eml_index_class";
  c1_info[107].dominantType = "";
  c1_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[107].fileTimeLo = 1323154378U;
  c1_info[107].fileTimeHi = 0U;
  c1_info[107].mFileTimeLo = 0U;
  c1_info[107].mFileTimeHi = 0U;
  c1_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[108].name = "eml_int_forloop_overflow_check";
  c1_info[108].dominantType = "";
  c1_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[108].fileTimeLo = 1346497740U;
  c1_info[108].fileTimeHi = 0U;
  c1_info[108].mFileTimeLo = 0U;
  c1_info[108].mFileTimeHi = 0U;
  c1_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[109].name = "eml_index_times";
  c1_info[109].dominantType = "coder.internal.indexInt";
  c1_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[109].fileTimeLo = 1286806180U;
  c1_info[109].fileTimeHi = 0U;
  c1_info[109].mFileTimeLo = 0U;
  c1_info[109].mFileTimeHi = 0U;
  c1_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[110].name = "eml_index_plus";
  c1_info[110].dominantType = "coder.internal.indexInt";
  c1_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[110].fileTimeLo = 1286806178U;
  c1_info[110].fileTimeHi = 0U;
  c1_info[110].mFileTimeLo = 0U;
  c1_info[110].mFileTimeHi = 0U;
  c1_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[111].name = "intmin";
  c1_info[111].dominantType = "char";
  c1_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[111].fileTimeLo = 1311242718U;
  c1_info[111].fileTimeHi = 0U;
  c1_info[111].mFileTimeLo = 0U;
  c1_info[111].mFileTimeHi = 0U;
  c1_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[112].name = "eml_div";
  c1_info[112].dominantType = "double";
  c1_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[112].fileTimeLo = 1313335210U;
  c1_info[112].fileTimeHi = 0U;
  c1_info[112].mFileTimeLo = 0U;
  c1_info[112].mFileTimeHi = 0U;
  c1_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[113].name = "norm";
  c1_info[113].dominantType = "double";
  c1_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[113].fileTimeLo = 1336509494U;
  c1_info[113].fileTimeHi = 0U;
  c1_info[113].mFileTimeLo = 0U;
  c1_info[113].mFileTimeHi = 0U;
  c1_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[114].name = "abs";
  c1_info[114].dominantType = "double";
  c1_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[114].fileTimeLo = 1343817766U;
  c1_info[114].fileTimeHi = 0U;
  c1_info[114].mFileTimeLo = 0U;
  c1_info[114].mFileTimeHi = 0U;
  c1_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[115].name = "eml_dlapy2";
  c1_info[115].dominantType = "double";
  c1_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c1_info[115].fileTimeLo = 1350398054U;
  c1_info[115].fileTimeHi = 0U;
  c1_info[115].mFileTimeLo = 0U;
  c1_info[115].mFileTimeHi = 0U;
  c1_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[116].name = "isnan";
  c1_info[116].dominantType = "double";
  c1_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[116].fileTimeLo = 1286806160U;
  c1_info[116].fileTimeHi = 0U;
  c1_info[116].mFileTimeLo = 0U;
  c1_info[116].mFileTimeHi = 0U;
  c1_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[117].name = "eml_guarded_nan";
  c1_info[117].dominantType = "char";
  c1_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[117].fileTimeLo = 1286806176U;
  c1_info[117].fileTimeHi = 0U;
  c1_info[117].mFileTimeLo = 0U;
  c1_info[117].mFileTimeHi = 0U;
  c1_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[118].name = "eml_is_float_class";
  c1_info[118].dominantType = "char";
  c1_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[118].fileTimeLo = 1286806182U;
  c1_info[118].fileTimeHi = 0U;
  c1_info[118].mFileTimeLo = 0U;
  c1_info[118].mFileTimeHi = 0U;
  c1_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[119].name = "mtimes";
  c1_info[119].dominantType = "double";
  c1_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[119].fileTimeLo = 1289503492U;
  c1_info[119].fileTimeHi = 0U;
  c1_info[119].mFileTimeLo = 0U;
  c1_info[119].mFileTimeHi = 0U;
  c1_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[120].name = "eml_warning";
  c1_info[120].dominantType = "char";
  c1_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[120].fileTimeLo = 1286806202U;
  c1_info[120].fileTimeHi = 0U;
  c1_info[120].mFileTimeLo = 0U;
  c1_info[120].mFileTimeHi = 0U;
  c1_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[121].name = "isnan";
  c1_info[121].dominantType = "double";
  c1_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[121].fileTimeLo = 1286806160U;
  c1_info[121].fileTimeHi = 0U;
  c1_info[121].mFileTimeLo = 0U;
  c1_info[121].mFileTimeHi = 0U;
  c1_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[122].name = "eps";
  c1_info[122].dominantType = "char";
  c1_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[122].fileTimeLo = 1326711796U;
  c1_info[122].fileTimeHi = 0U;
  c1_info[122].mFileTimeLo = 0U;
  c1_info[122].mFileTimeHi = 0U;
  c1_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[123].name = "eml_flt2str";
  c1_info[123].dominantType = "double";
  c1_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[123].fileTimeLo = 1309438596U;
  c1_info[123].fileTimeHi = 0U;
  c1_info[123].mFileTimeLo = 0U;
  c1_info[123].mFileTimeHi = 0U;
  c1_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[124].name = "char";
  c1_info[124].dominantType = "double";
  c1_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c1_info[124].fileTimeLo = 1319717368U;
  c1_info[124].fileTimeHi = 0U;
  c1_info[124].mFileTimeLo = 0U;
  c1_info[124].mFileTimeHi = 0U;
  c1_info[125].context = "";
  c1_info[125].name = "mtimes";
  c1_info[125].dominantType = "double";
  c1_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[125].fileTimeLo = 1289503492U;
  c1_info[125].fileTimeHi = 0U;
  c1_info[125].mFileTimeLo = 0U;
  c1_info[125].mFileTimeHi = 0U;
  c1_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[126].name = "eml_index_class";
  c1_info[126].dominantType = "";
  c1_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[126].fileTimeLo = 1323154378U;
  c1_info[126].fileTimeHi = 0U;
  c1_info[126].mFileTimeLo = 0U;
  c1_info[126].mFileTimeHi = 0U;
  c1_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[127].name = "eml_scalar_eg";
  c1_info[127].dominantType = "double";
  c1_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[127].fileTimeLo = 1286806196U;
  c1_info[127].fileTimeHi = 0U;
  c1_info[127].mFileTimeLo = 0U;
  c1_info[127].mFileTimeHi = 0U;
}

static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[134])
{
  c1_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[128].name = "eml_xgemm";
  c1_info[128].dominantType = "char";
  c1_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[128].fileTimeLo = 1299060572U;
  c1_info[128].fileTimeHi = 0U;
  c1_info[128].mFileTimeLo = 0U;
  c1_info[128].mFileTimeHi = 0U;
  c1_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[129].name = "eml_blas_inline";
  c1_info[129].dominantType = "";
  c1_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[129].fileTimeLo = 1299060568U;
  c1_info[129].fileTimeHi = 0U;
  c1_info[129].mFileTimeLo = 0U;
  c1_info[129].mFileTimeHi = 0U;
  c1_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[130].name = "mtimes";
  c1_info[130].dominantType = "double";
  c1_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[130].fileTimeLo = 1289503492U;
  c1_info[130].fileTimeHi = 0U;
  c1_info[130].mFileTimeLo = 0U;
  c1_info[130].mFileTimeHi = 0U;
  c1_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[131].name = "eml_index_class";
  c1_info[131].dominantType = "";
  c1_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[131].fileTimeLo = 1323154378U;
  c1_info[131].fileTimeHi = 0U;
  c1_info[131].mFileTimeLo = 0U;
  c1_info[131].mFileTimeHi = 0U;
  c1_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[132].name = "eml_scalar_eg";
  c1_info[132].dominantType = "double";
  c1_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[132].fileTimeLo = 1286806196U;
  c1_info[132].fileTimeHi = 0U;
  c1_info[132].mFileTimeLo = 0U;
  c1_info[132].mFileTimeHi = 0U;
  c1_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[133].name = "eml_refblas_xgemm";
  c1_info[133].dominantType = "char";
  c1_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[133].fileTimeLo = 1299060574U;
  c1_info[133].fileTimeHi = 0U;
  c1_info[133].mFileTimeLo = 0U;
  c1_info[133].mFileTimeHi = 0U;
}

static void c1_invNxN(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T c1_x
                      [16], creal_T c1_y[16])
{
  int32_T c1_i41;
  static creal_T c1_dc0 = { 0.0, 0.0 };

  int32_T c1_info;
  int32_T c1_ipiv[4];
  int32_T c1_i42;
  int32_T c1_p[4];
  int32_T c1_k;
  real_T c1_b_k;
  int32_T c1_ipk;
  int32_T c1_a;
  real_T c1_b;
  int32_T c1_b_a;
  real_T c1_b_b;
  int32_T c1_idx;
  real_T c1_flt;
  boolean_T c1_b_p;
  int32_T c1_pipk;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_c;
  static creal_T c1_dc1 = { 1.0, 0.0 };

  int32_T c1_e_k;
  boolean_T c1_overflow;
  int32_T c1_j;
  int32_T c1_b_j;
  boolean_T c1_b_y;
  int32_T c1_c_a;
  int32_T c1_i43;
  boolean_T c1_b_overflow;
  int32_T c1_i;
  int32_T c1_b_i;
  creal_T c1_d_a;
  creal_T c1_c_b;
  creal_T c1_e_a;
  int32_T c1_i44;
  creal_T c1_b_x[16];
  for (c1_i41 = 0; c1_i41 < 16; c1_i41++) {
    c1_y[c1_i41] = c1_dc0;
  }

  c1_b_eml_matlab_zgetrf(chartInstance, c1_x, c1_ipiv, &c1_info);
  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    c1_p[c1_i42] = 1 + c1_i42;
  }

  for (c1_k = 0; c1_k < 3; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_ipk = c1_ipiv[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 4, 1, 0) - 1];
    c1_a = c1_ipk;
    c1_b = c1_b_k;
    c1_b_a = c1_a;
    c1_b_b = c1_b;
    c1_idx = c1_b_a;
    c1_flt = c1_b_b;
    c1_b_p = ((real_T)c1_idx > c1_flt);
    if (c1_b_p) {
      c1_pipk = c1_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c1_ipk), 1, 4, 1, 0) - 1];
      c1_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_ipk), 1, 4, 1, 0) - 1] = c1_p[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
        1, 4, 1, 0) - 1];
      c1_p[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_b_k), 1, 4, 1, 0) - 1] = c1_pipk;
    }
  }

  for (c1_c_k = 1; c1_c_k < 5; c1_c_k++) {
    c1_d_k = c1_c_k;
    c1_c = c1_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_d_k), 1, 4, 1, 0) - 1];
    c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_d_k), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_c), 1, 4, 2, 0) - 1) <<
           2)) - 1] = c1_dc1;
    c1_e_k = c1_d_k;
    c1_overflow = FALSE;
    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_overflow);
    }

    for (c1_j = c1_e_k; c1_j < 5; c1_j++) {
      c1_b_j = c1_j;
      c1_b_y = ((c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)) - 1].re !=
                 c1_dc0.re) || (c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) +
                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)) - 1].im != c1_dc0.im));
      if (c1_b_y) {
        c1_c_a = c1_b_j;
        c1_i43 = c1_c_a;
        c1_b_overflow = FALSE;
        if (c1_b_overflow) {
          c1_check_forloop_overflow_error(chartInstance, c1_b_overflow);
        }

        for (c1_i = c1_i43 + 1; c1_i < 5; c1_i++) {
          c1_b_i = c1_i;
          c1_d_a = c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)) - 1];
          c1_c_b = c1_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
          c1_e_a = c1_d_a;
          c1_d_a.re = c1_e_a.re * c1_c_b.re - c1_e_a.im * c1_c_b.im;
          c1_d_a.im = c1_e_a.re * c1_c_b.im + c1_e_a.im * c1_c_b.re;
          c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c1_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                   "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_c), 1, 4, 2, 0)
                  - 1) << 2)) - 1].re = c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) +
            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)) - 1].re - c1_d_a.re;
          c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c1_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                   "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_c), 1, 4, 2, 0)
                  - 1) << 2)) - 1].im = c1_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) +
            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_c), 1, 4, 2, 0) - 1) << 2)) - 1].im - c1_d_a.im;
        }
      }
    }
  }

  for (c1_i44 = 0; c1_i44 < 16; c1_i44++) {
    c1_b_x[c1_i44] = c1_x[c1_i44];
  }

  c1_b_eml_xtrsm(chartInstance, c1_b_x, c1_y);
}

static void c1_realmin(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
}

static void c1_eps(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
}

static void c1_eml_matlab_zgetrf(SFc1_DPC_ModelInstanceStruct *chartInstance,
  creal_T c1_A[16], creal_T c1_b_A[16], int32_T c1_ipiv[4], int32_T *c1_info)
{
  int32_T c1_i45;
  for (c1_i45 = 0; c1_i45 < 16; c1_i45++) {
    c1_b_A[c1_i45] = c1_A[c1_i45];
  }

  c1_b_eml_matlab_zgetrf(chartInstance, c1_b_A, c1_ipiv, c1_info);
}

static void c1_check_forloop_overflow_error(SFc1_DPC_ModelInstanceStruct
  *chartInstance, boolean_T c1_overflow)
{
  int32_T c1_i46;
  static char_T c1_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i47;
  static char_T c1_cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c1_b_u[23];
  const mxArray *c1_b_y = NULL;
  if (!c1_overflow) {
  } else {
    for (c1_i46 = 0; c1_i46 < 34; c1_i46++) {
      c1_u[c1_i46] = c1_cv1[c1_i46];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c1_i47 = 0; c1_i47 < 23; c1_i47++) {
      c1_b_u[c1_i47] = c1_cv2[c1_i47];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c1_y, 14, c1_b_y));
  }
}

static creal_T c1_eml_div(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T
  c1_x, creal_T c1_y)
{
  creal_T c1_z;
  real_T c1_ar;
  real_T c1_ai;
  real_T c1_br;
  real_T c1_bi;
  real_T c1_brm;
  real_T c1_bim;
  real_T c1_s;
  real_T c1_d;
  real_T c1_nr;
  real_T c1_ni;
  real_T c1_sgnbr;
  real_T c1_sgnbi;
  c1_ar = c1_x.re;
  c1_ai = c1_x.im;
  c1_br = c1_y.re;
  c1_bi = c1_y.im;
  if (c1_bi == 0.0) {
    if (c1_ai == 0.0) {
      c1_z.re = c1_ar / c1_br;
      c1_z.im = 0.0;
    } else if (c1_ar == 0.0) {
      c1_z.re = 0.0;
      c1_z.im = c1_ai / c1_br;
    } else {
      c1_z.re = c1_ar / c1_br;
      c1_z.im = c1_ai / c1_br;
    }
  } else if (c1_br == 0.0) {
    if (c1_ar == 0.0) {
      c1_z.re = c1_ai / c1_bi;
      c1_z.im = 0.0;
    } else if (c1_ai == 0.0) {
      c1_z.re = 0.0;
      c1_z.im = -(c1_ar / c1_bi);
    } else {
      c1_z.re = c1_ai / c1_bi;
      c1_z.im = -(c1_ar / c1_bi);
    }
  } else {
    c1_brm = muDoubleScalarAbs(c1_br);
    c1_bim = muDoubleScalarAbs(c1_bi);
    if (c1_brm > c1_bim) {
      c1_s = c1_bi / c1_br;
      c1_d = c1_br + c1_s * c1_bi;
      c1_nr = c1_ar + c1_s * c1_ai;
      c1_ni = c1_ai - c1_s * c1_ar;
      c1_z.re = c1_nr / c1_d;
      c1_z.im = c1_ni / c1_d;
    } else if (c1_bim == c1_brm) {
      if (c1_br > 0.0) {
        c1_sgnbr = 0.5;
      } else {
        c1_sgnbr = -0.5;
      }

      if (c1_bi > 0.0) {
        c1_sgnbi = 0.5;
      } else {
        c1_sgnbi = -0.5;
      }

      c1_nr = c1_ar * c1_sgnbr + c1_ai * c1_sgnbi;
      c1_ni = c1_ai * c1_sgnbr - c1_ar * c1_sgnbi;
      c1_z.re = c1_nr / c1_brm;
      c1_z.im = c1_ni / c1_brm;
    } else {
      c1_s = c1_br / c1_bi;
      c1_d = c1_bi + c1_s * c1_br;
      c1_nr = c1_s * c1_ar + c1_ai;
      c1_ni = c1_s * c1_ai - c1_ar;
      c1_z.re = c1_nr / c1_d;
      c1_z.im = c1_ni / c1_d;
    }
  }

  return c1_z;
}

static void c1_eml_xgeru(SFc1_DPC_ModelInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0, int32_T c1_iy0, creal_T
  c1_A[16], int32_T c1_ia0, creal_T c1_b_A[16])
{
  int32_T c1_i48;
  for (c1_i48 = 0; c1_i48 < 16; c1_i48++) {
    c1_b_A[c1_i48] = c1_A[c1_i48];
  }

  c1_b_eml_xgeru(chartInstance, c1_m, c1_n, c1_alpha1, c1_ix0, c1_iy0, c1_b_A,
                 c1_ia0);
}

static void c1_eml_xtrsm(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T
  c1_A[16], creal_T c1_B[16], creal_T c1_b_B[16])
{
  int32_T c1_i49;
  int32_T c1_i50;
  creal_T c1_b_A[16];
  for (c1_i49 = 0; c1_i49 < 16; c1_i49++) {
    c1_b_B[c1_i49] = c1_B[c1_i49];
  }

  for (c1_i50 = 0; c1_i50 < 16; c1_i50++) {
    c1_b_A[c1_i50] = c1_A[c1_i50];
  }

  c1_b_eml_xtrsm(chartInstance, c1_b_A, c1_b_B);
}

static real_T c1_norm(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T c1_x
                      [16])
{
  real_T c1_y;
  int32_T c1_j;
  real_T c1_b_j;
  real_T c1_s;
  int32_T c1_i;
  real_T c1_b_i;
  creal_T c1_b_x;
  real_T c1_x1;
  real_T c1_x2;
  real_T c1_a;
  real_T c1_b;
  real_T c1_b_y;
  real_T c1_c_x;
  boolean_T c1_b_b;
  boolean_T exitg1;
  c1_y = 0.0;
  c1_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c1_j < 4)) {
    c1_b_j = 1.0 + (real_T)c1_j;
    c1_s = 0.0;
    for (c1_i = 0; c1_i < 4; c1_i++) {
      c1_b_i = 1.0 + (real_T)c1_i;
      c1_b_x = c1_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_b_i), 1, 4, 1, 0) + (((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_j),
        1, 4, 2, 0) - 1) << 2)) - 1];
      c1_x1 = c1_b_x.re;
      c1_x2 = c1_b_x.im;
      c1_a = c1_x1;
      c1_b = c1_x2;
      c1_b_y = muDoubleScalarHypot(c1_a, c1_b);
      c1_s += c1_b_y;
    }

    c1_c_x = c1_s;
    c1_b_b = muDoubleScalarIsNaN(c1_c_x);
    if (c1_b_b) {
      c1_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c1_s > c1_y) {
        c1_y = c1_s;
      }

      c1_j++;
    }
  }

  return c1_y;
}

static void c1_eml_warning(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
  int32_T c1_i51;
  static char_T c1_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c1_u[27];
  const mxArray *c1_y = NULL;
  for (c1_i51 = 0; c1_i51 < 27; c1_i51++) {
    c1_u[c1_i51] = c1_varargin_1[c1_i51];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c1_y));
}

static void c1_b_eml_warning(SFc1_DPC_ModelInstanceStruct *chartInstance, char_T
  c1_varargin_2[14])
{
  int32_T c1_i52;
  static char_T c1_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c1_u[33];
  const mxArray *c1_y = NULL;
  int32_T c1_i53;
  char_T c1_b_u[14];
  const mxArray *c1_b_y = NULL;
  for (c1_i52 = 0; c1_i52 < 33; c1_i52++) {
    c1_u[c1_i52] = c1_varargin_1[c1_i52];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c1_i53 = 0; c1_i53 < 14; c1_i53++) {
    c1_b_u[c1_i53] = c1_varargin_2[c1_i53];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c1_y, 14, c1_b_y));
}

static void c1_eml_scalar_eg(SFc1_DPC_ModelInstanceStruct *chartInstance)
{
}

static void c1_d_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_sprintf, const char_T *c1_identifier, char_T c1_y[14])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sprintf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_sprintf);
}

static void c1_e_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, char_T c1_y[14])
{
  char_T c1_cv3[14];
  int32_T c1_i54;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv3, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c1_i54 = 0; c1_i54 < 14; c1_i54++) {
    c1_y[c1_i54] = c1_cv3[c1_i54];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
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
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_DPC_Model, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_DPC_Model), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_DPC_Model);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_eml_matlab_zgetrf(SFc1_DPC_ModelInstanceStruct *chartInstance,
  creal_T c1_A[16], int32_T c1_ipiv[4], int32_T *c1_info)
{
  int32_T c1_i56;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_jm1;
  int32_T c1_b;
  int32_T c1_mmj;
  int32_T c1_b_a;
  int32_T c1_c;
  int32_T c1_b_b;
  int32_T c1_jj;
  int32_T c1_c_a;
  int32_T c1_jp1j;
  int32_T c1_d_a;
  int32_T c1_b_c;
  int32_T c1_n;
  int32_T c1_ix0;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  int32_T c1_idxmax;
  int32_T c1_ix;
  creal_T c1_temp;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_y;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_y;
  real_T c1_smax;
  int32_T c1_d_n;
  int32_T c1_c_b;
  int32_T c1_d_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_e_a;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_d_y;
  real_T c1_s;
  int32_T c1_f_a;
  int32_T c1_jpiv_offset;
  int32_T c1_g_a;
  int32_T c1_e_b;
  int32_T c1_jpiv;
  static creal_T c1_dc2 = { 0.0, 0.0 };

  boolean_T c1_b_A;
  int32_T c1_h_a;
  int32_T c1_f_b;
  int32_T c1_c_c;
  int32_T c1_g_b;
  int32_T c1_jrow;
  int32_T c1_i_a;
  int32_T c1_h_b;
  int32_T c1_jprow;
  int32_T c1_d_ix0;
  int32_T c1_iy0;
  int32_T c1_e_ix0;
  int32_T c1_b_iy0;
  int32_T c1_f_ix0;
  int32_T c1_c_iy0;
  int32_T c1_b_ix;
  int32_T c1_iy;
  int32_T c1_c_k;
  int32_T c1_j_a;
  int32_T c1_k_a;
  int32_T c1_b_jp1j;
  int32_T c1_l_a;
  int32_T c1_d_c;
  int32_T c1_m_a;
  int32_T c1_i_b;
  int32_T c1_i57;
  int32_T c1_n_a;
  int32_T c1_j_b;
  int32_T c1_o_a;
  int32_T c1_k_b;
  boolean_T c1_b_overflow;
  int32_T c1_i;
  int32_T c1_b_i;
  creal_T c1_c_A;
  creal_T c1_d_A;
  int32_T c1_l_b;
  int32_T c1_e_c;
  int32_T c1_p_a;
  int32_T c1_f_c;
  int32_T c1_q_a;
  int32_T c1_g_c;
  real_T c1_d1;
  boolean_T c1_e_A;
  c1_realmin(chartInstance);
  c1_eps(chartInstance);
  for (c1_i56 = 0; c1_i56 < 4; c1_i56++) {
    c1_ipiv[c1_i56] = 1 + c1_i56;
  }

  *c1_info = 0;
  for (c1_j = 1; c1_j < 4; c1_j++) {
    c1_b_j = c1_j;
    c1_a = c1_b_j - 1;
    c1_jm1 = c1_a;
    c1_b = c1_b_j;
    c1_mmj = 4 - c1_b;
    c1_b_a = c1_jm1;
    c1_c = c1_b_a * 5;
    c1_b_b = c1_c + 1;
    c1_jj = c1_b_b;
    c1_c_a = c1_jj + 1;
    c1_jp1j = c1_c_a;
    c1_d_a = c1_mmj;
    c1_b_c = c1_d_a;
    c1_n = c1_b_c + 1;
    c1_ix0 = c1_jj;
    c1_b_n = c1_n;
    c1_b_ix0 = c1_ix0;
    c1_c_n = c1_b_n;
    c1_c_ix0 = c1_b_ix0;
    if (c1_c_n < 1) {
      c1_idxmax = 0;
    } else {
      c1_idxmax = 1;
      if (c1_c_n > 1) {
        c1_ix = c1_c_ix0;
        c1_temp = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1];
        c1_x = c1_temp.re;
        c1_b_x = c1_x;
        c1_y = muDoubleScalarAbs(c1_b_x);
        c1_c_x = c1_temp.im;
        c1_d_x = c1_c_x;
        c1_b_y = muDoubleScalarAbs(c1_d_x);
        c1_smax = c1_y + c1_b_y;
        c1_d_n = c1_c_n;
        c1_c_b = c1_d_n;
        c1_d_b = c1_c_b;
        if (2 > c1_d_b) {
          c1_overflow = FALSE;
        } else {
          c1_overflow = (c1_d_b > 2147483646);
        }

        if (c1_overflow) {
          c1_check_forloop_overflow_error(chartInstance, c1_overflow);
        }

        for (c1_k = 2; c1_k <= c1_d_n; c1_k++) {
          c1_b_k = c1_k;
          c1_e_a = c1_ix + 1;
          c1_ix = c1_e_a;
          c1_temp = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1];
          c1_e_x = c1_temp.re;
          c1_f_x = c1_e_x;
          c1_c_y = muDoubleScalarAbs(c1_f_x);
          c1_g_x = c1_temp.im;
          c1_h_x = c1_g_x;
          c1_d_y = muDoubleScalarAbs(c1_h_x);
          c1_s = c1_c_y + c1_d_y;
          if (c1_s > c1_smax) {
            c1_idxmax = c1_b_k;
            c1_smax = c1_s;
          }
        }
      }
    }

    c1_f_a = c1_idxmax - 1;
    c1_jpiv_offset = c1_f_a;
    c1_g_a = c1_jj;
    c1_e_b = c1_jpiv_offset;
    c1_jpiv = c1_g_a + c1_e_b;
    c1_b_A = ((c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_jpiv), 1, 16, 1, 0) - 1].re != c1_dc2.re) ||
              (c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_jpiv), 1, 16, 1, 0) - 1].im != c1_dc2.im));
    if (c1_b_A) {
      if (c1_jpiv_offset != 0) {
        c1_h_a = c1_b_j;
        c1_f_b = c1_jpiv_offset;
        c1_c_c = c1_h_a + c1_f_b;
        c1_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 4, 1, 0) - 1] = c1_c_c;
        c1_g_b = c1_jm1 + 1;
        c1_jrow = c1_g_b;
        c1_i_a = c1_jrow;
        c1_h_b = c1_jpiv_offset;
        c1_jprow = c1_i_a + c1_h_b;
        c1_d_ix0 = c1_jrow;
        c1_iy0 = c1_jprow;
        c1_e_ix0 = c1_d_ix0;
        c1_b_iy0 = c1_iy0;
        c1_f_ix0 = c1_e_ix0;
        c1_c_iy0 = c1_b_iy0;
        c1_b_ix = c1_f_ix0;
        c1_iy = c1_c_iy0;
        for (c1_c_k = 1; c1_c_k < 5; c1_c_k++) {
          c1_temp = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 16, 1, 0) - 1];
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ix), 1, 16, 1, 0) - 1] =
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_iy), 1, 16, 1, 0) - 1];
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_iy), 1, 16, 1, 0) - 1] = c1_temp;
          c1_j_a = c1_b_ix + 4;
          c1_b_ix = c1_j_a;
          c1_k_a = c1_iy + 4;
          c1_iy = c1_k_a;
        }
      }

      c1_b_jp1j = c1_jp1j;
      c1_l_a = c1_mmj;
      c1_d_c = c1_l_a;
      c1_m_a = c1_jp1j;
      c1_i_b = c1_d_c - 1;
      c1_i57 = c1_m_a + c1_i_b;
      c1_n_a = c1_b_jp1j;
      c1_j_b = c1_i57;
      c1_o_a = c1_n_a;
      c1_k_b = c1_j_b;
      if (c1_o_a > c1_k_b) {
        c1_b_overflow = FALSE;
      } else {
        c1_b_overflow = (c1_k_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_check_forloop_overflow_error(chartInstance, c1_b_overflow);
      }

      for (c1_i = c1_b_jp1j; c1_i <= c1_i57; c1_i++) {
        c1_b_i = c1_i;
        c1_c_A = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 16, 1, 0) - 1];
        c1_d_A = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_jj), 1, 16, 1, 0) - 1];
        c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_i), 1, 16, 1, 0) - 1] = c1_eml_div(chartInstance, c1_c_A,
          c1_d_A);
      }
    } else {
      *c1_info = c1_b_j;
    }

    c1_l_b = c1_b_j;
    c1_e_c = 4 - c1_l_b;
    c1_p_a = c1_jj;
    c1_f_c = c1_p_a;
    c1_q_a = c1_jj;
    c1_g_c = c1_q_a;
    c1_d1 = -1.0;
    c1_b_eml_xgeru(chartInstance, c1_mmj, c1_e_c, c1_d1, c1_jp1j, c1_f_c + 4,
                   c1_A, c1_g_c + 5);
  }

  if (*c1_info == 0) {
    c1_e_A = ((c1_A[15].re != c1_dc2.re) || (c1_A[15].im != c1_dc2.im));
    if (!c1_e_A) {
      *c1_info = 4;
    }
  }
}

static void c1_b_eml_xgeru(SFc1_DPC_ModelInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0, int32_T c1_iy0, creal_T
  c1_A[16], int32_T c1_ia0)
{
  int32_T c1_b_m;
  int32_T c1_b_n;
  real_T c1_b_alpha1;
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_b_ia0;
  int32_T c1_c_m;
  int32_T c1_c_n;
  static creal_T c1_dc3 = { 0.0, 0.0 };

  creal_T c1_c_alpha1;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_c_ia0;
  int32_T c1_d_m;
  int32_T c1_d_n;
  int32_T c1_d_ix0;
  int32_T c1_d_iy0;
  int32_T c1_d_ia0;
  boolean_T c1_d_alpha1;
  int32_T c1_ixstart;
  int32_T c1_a;
  int32_T c1_jA;
  int32_T c1_jy;
  int32_T c1_e_n;
  int32_T c1_b;
  int32_T c1_b_b;
  boolean_T c1_overflow;
  int32_T c1_j;
  creal_T c1_yjy;
  boolean_T c1_b_yjy;
  creal_T c1_c_yjy;
  int32_T c1_ix;
  int32_T c1_c_b;
  int32_T c1_i58;
  int32_T c1_b_a;
  int32_T c1_d_b;
  int32_T c1_i59;
  int32_T c1_c_a;
  int32_T c1_e_b;
  int32_T c1_d_a;
  int32_T c1_f_b;
  boolean_T c1_b_overflow;
  int32_T c1_ijA;
  int32_T c1_b_ijA;
  creal_T c1_b_A;
  int32_T c1_e_a;
  int32_T c1_f_a;
  int32_T c1_g_a;
  c1_b_m = c1_m;
  c1_b_n = c1_n;
  c1_b_alpha1 = c1_alpha1;
  c1_b_ix0 = c1_ix0;
  c1_b_iy0 = c1_iy0;
  c1_b_ia0 = c1_ia0;
  c1_c_m = c1_b_m;
  c1_c_n = c1_b_n;
  c1_c_alpha1.re = c1_b_alpha1 + c1_dc3.re;
  c1_c_alpha1.im = c1_dc3.im;
  c1_c_ix0 = c1_b_ix0;
  c1_c_iy0 = c1_b_iy0;
  c1_c_ia0 = c1_b_ia0;
  c1_d_m = c1_c_m;
  c1_d_n = c1_c_n;
  c1_d_ix0 = c1_c_ix0;
  c1_d_iy0 = c1_c_iy0;
  c1_d_ia0 = c1_c_ia0;
  c1_d_alpha1 = ((c1_c_alpha1.re == c1_dc3.re) && (c1_c_alpha1.im == c1_dc3.im));
  if (c1_d_alpha1) {
  } else {
    c1_ixstart = c1_d_ix0;
    c1_a = c1_d_ia0 - 1;
    c1_jA = c1_a;
    c1_jy = c1_d_iy0;
    c1_e_n = c1_d_n;
    c1_b = c1_e_n;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = FALSE;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_overflow);
    }

    for (c1_j = 1; c1_j <= c1_e_n; c1_j++) {
      c1_yjy = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c1_jy), 1, 16, 1, 0) - 1];
      c1_b_yjy = ((c1_yjy.re != c1_dc3.re) || (c1_yjy.im != c1_dc3.im));
      if (c1_b_yjy) {
        c1_c_yjy = c1_yjy;
        c1_yjy.re = c1_c_yjy.re * c1_c_alpha1.re - c1_c_yjy.im * c1_c_alpha1.im;
        c1_yjy.im = c1_c_yjy.re * c1_c_alpha1.im + c1_c_yjy.im * c1_c_alpha1.re;
        c1_ix = c1_ixstart;
        c1_c_b = c1_jA + 1;
        c1_i58 = c1_c_b;
        c1_b_a = c1_d_m;
        c1_d_b = c1_jA;
        c1_i59 = c1_b_a + c1_d_b;
        c1_c_a = c1_i58;
        c1_e_b = c1_i59;
        c1_d_a = c1_c_a;
        c1_f_b = c1_e_b;
        if (c1_d_a > c1_f_b) {
          c1_b_overflow = FALSE;
        } else {
          c1_b_overflow = (c1_f_b > 2147483646);
        }

        if (c1_b_overflow) {
          c1_check_forloop_overflow_error(chartInstance, c1_b_overflow);
        }

        for (c1_ijA = c1_i58; c1_ijA <= c1_i59; c1_ijA++) {
          c1_b_ijA = c1_ijA;
          c1_b_A.re = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1].re *
            c1_yjy.re - c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1].im *
            c1_yjy.im;
          c1_b_A.im = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1].re *
            c1_yjy.im + c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1].im *
            c1_yjy.re;
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ijA), 1, 16, 1, 0) - 1].re =
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ijA), 1, 16, 1, 0) - 1].re + c1_b_A.re;
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ijA), 1, 16, 1, 0) - 1].im =
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ijA), 1, 16, 1, 0) - 1].im + c1_b_A.im;
          c1_e_a = c1_ix + 1;
          c1_ix = c1_e_a;
        }
      }

      c1_f_a = c1_jy + 4;
      c1_jy = c1_f_a;
      c1_g_a = c1_jA + 4;
      c1_jA = c1_g_a;
    }
  }
}

static void c1_b_eml_xtrsm(SFc1_DPC_ModelInstanceStruct *chartInstance, creal_T
  c1_A[16], creal_T c1_B[16])
{
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_b;
  int32_T c1_jBcol;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_b_a;
  int32_T c1_c_c;
  int32_T c1_c_b;
  int32_T c1_d_c;
  int32_T c1_d_b;
  int32_T c1_kAcol;
  int32_T c1_c_a;
  int32_T c1_e_b;
  int32_T c1_e_c;
  static creal_T c1_dc4 = { 0.0, 0.0 };

  boolean_T c1_b_B;
  int32_T c1_d_a;
  int32_T c1_f_b;
  int32_T c1_f_c;
  int32_T c1_e_a;
  int32_T c1_g_b;
  int32_T c1_g_c;
  int32_T c1_f_a;
  int32_T c1_h_b;
  int32_T c1_h_c;
  creal_T c1_c_B;
  creal_T c1_b_A;
  int32_T c1_g_a;
  int32_T c1_i60;
  int32_T c1_i_b;
  int32_T c1_j_b;
  boolean_T c1_overflow;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_h_a;
  int32_T c1_k_b;
  int32_T c1_i_c;
  int32_T c1_i_a;
  int32_T c1_l_b;
  int32_T c1_j_c;
  int32_T c1_j_a;
  int32_T c1_m_b;
  int32_T c1_k_c;
  int32_T c1_k_a;
  int32_T c1_n_b;
  int32_T c1_l_c;
  creal_T c1_d_B;
  for (c1_j = 1; c1_j < 5; c1_j++) {
    c1_b_j = c1_j;
    c1_a = c1_b_j;
    c1_c = c1_a;
    c1_b = c1_c - 1;
    c1_b_c = c1_b << 2;
    c1_b_b = c1_b_c;
    c1_jBcol = c1_b_b;
    for (c1_k = 4; c1_k > 0; c1_k--) {
      c1_b_k = c1_k;
      c1_b_a = c1_b_k;
      c1_c_c = c1_b_a;
      c1_c_b = c1_c_c - 1;
      c1_d_c = c1_c_b << 2;
      c1_d_b = c1_d_c;
      c1_kAcol = c1_d_b;
      c1_c_a = c1_b_k;
      c1_e_b = c1_jBcol;
      c1_e_c = c1_c_a + c1_e_b;
      c1_b_B = ((c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c1_e_c), 1, 16, 1, 0) - 1].re
                 != c1_dc4.re) || (c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c1_e_c), 1, 16, 1, 0) - 1].im
                 != c1_dc4.im));
      if (c1_b_B) {
        c1_d_a = c1_b_k;
        c1_f_b = c1_jBcol;
        c1_f_c = c1_d_a + c1_f_b;
        c1_e_a = c1_b_k;
        c1_g_b = c1_jBcol;
        c1_g_c = c1_e_a + c1_g_b;
        c1_f_a = c1_b_k;
        c1_h_b = c1_kAcol;
        c1_h_c = c1_f_a + c1_h_b;
        c1_c_B = c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_g_c), 1, 16, 1, 0) - 1];
        c1_b_A = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_h_c), 1, 16, 1, 0) - 1];
        c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_f_c), 1, 16, 1, 0) - 1] = c1_eml_div(chartInstance, c1_c_B,
          c1_b_A);
        c1_g_a = c1_b_k - 1;
        c1_i60 = c1_g_a;
        c1_i_b = c1_i60;
        c1_j_b = c1_i_b;
        if (1 > c1_j_b) {
          c1_overflow = FALSE;
        } else {
          c1_overflow = (c1_j_b > 2147483646);
        }

        if (c1_overflow) {
          c1_check_forloop_overflow_error(chartInstance, c1_overflow);
        }

        for (c1_i = 1; c1_i <= c1_i60; c1_i++) {
          c1_b_i = c1_i;
          c1_h_a = c1_b_i;
          c1_k_b = c1_jBcol;
          c1_i_c = c1_h_a + c1_k_b;
          c1_i_a = c1_b_i;
          c1_l_b = c1_jBcol;
          c1_j_c = c1_i_a + c1_l_b;
          c1_j_a = c1_b_k;
          c1_m_b = c1_jBcol;
          c1_k_c = c1_j_a + c1_m_b;
          c1_k_a = c1_b_i;
          c1_n_b = c1_kAcol;
          c1_l_c = c1_k_a + c1_n_b;
          c1_d_B.re = c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_k_c), 1, 16, 1, 0) - 1].re *
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_l_c), 1, 16, 1, 0) - 1].re -
            c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_k_c), 1, 16, 1, 0) - 1].im *
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_l_c), 1, 16, 1, 0) - 1].im;
          c1_d_B.im = c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_k_c), 1, 16, 1, 0) - 1].re *
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_l_c), 1, 16, 1, 0) - 1].im +
            c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_k_c), 1, 16, 1, 0) - 1].im *
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_l_c), 1, 16, 1, 0) - 1].re;
          c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_i_c), 1, 16, 1, 0) - 1].re =
            c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_j_c), 1, 16, 1, 0) - 1].re - c1_d_B.re;
          c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_i_c), 1, 16, 1, 0) - 1].im =
            c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_j_c), 1, 16, 1, 0) - 1].im - c1_d_B.im;
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc1_DPC_ModelInstanceStruct *chartInstance)
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

void sf_c1_DPC_Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3920406619U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4281301198U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3925377439U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(507889959U);
}

mxArray *sf_c1_DPC_Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("op2XNLHpO6BltoYPuniAYB");
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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

mxArray *sf_c1_DPC_Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_DPC_Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_DPC_Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DPC_Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DPC_ModelInstanceStruct *chartInstance;
    chartInstance = (SFc1_DPC_ModelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DPC_ModelMachineNumber_,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"rx_signal");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"l");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,57);
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
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          creal_T (*c1_rx_signal)[40];
          creal_T (*c1_y)[40];
          creal_T (*c1_l)[16];
          c1_l = (creal_T (*)[16])ssGetInputPortSignal(chartInstance->S, 1);
          c1_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_rx_signal = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_rx_signal);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_l);
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
  return "zlhNiMI53hymmiCDFlRV3F";
}

static void sf_opaque_initialize_c1_DPC_Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*)
    chartInstanceVar);
  initialize_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_DPC_Model(void *chartInstanceVar)
{
  enable_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_DPC_Model(void *chartInstanceVar)
{
  disable_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_DPC_Model(void *chartInstanceVar)
{
  sf_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_DPC_Model(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DPC_Model();/* state var info */
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

extern void sf_internal_set_sim_state_c1_DPC_Model(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DPC_Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_DPC_Model(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_DPC_Model(S);
}

static void sf_opaque_set_sim_state_c1_DPC_Model(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_DPC_Model(S, st);
}

static void sf_opaque_terminate_c1_DPC_Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DPC_Model_optimization_info();
    }

    finalize_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_DPC_Model((SFc1_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DPC_Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DPC_Model((SFc1_DPC_ModelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DPC_Model_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
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
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3827482106U));
  ssSetChecksum1(S,(202079001U));
  ssSetChecksum2(S,(2050043190U));
  ssSetChecksum3(S,(2982199428U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_DPC_Model(SimStruct *S)
{
  SFc1_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_DPC_ModelInstanceStruct *)utMalloc(sizeof
    (SFc1_DPC_ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_DPC_ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_DPC_Model;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_DPC_Model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_DPC_Model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_DPC_Model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_DPC_Model;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_DPC_Model;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_DPC_Model;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_DPC_Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DPC_Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DPC_Model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_DPC_Model;
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

void c1_DPC_Model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DPC_Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DPC_Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DPC_Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DPC_Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
