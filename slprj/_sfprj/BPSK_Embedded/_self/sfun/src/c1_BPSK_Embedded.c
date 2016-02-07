/* Include files */

#include <stddef.h>
#include "blas.h"
#include "BPSK_Embedded_sfun.h"
#include "c1_BPSK_Embedded.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BPSK_Embedded_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[13] = { "n", "m", "EbN0_lin",
  "noise_var", "Noise", "p", "i", "j", "nargin", "nargout", "Signal", "EbNo",
  "y" };

/* Function Declarations */
static void initialize_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void initialize_params_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct *
  chartInstance);
static void enable_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void disable_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_BPSK_Embedded
  (SFc1_BPSK_EmbeddedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_BPSK_Embedded
  (SFc1_BPSK_EmbeddedInstanceStruct *chartInstance);
static void set_sim_state_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void sf_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance);
static void c1_chartstep_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void initSimStructsc1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void registerMessagesc1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  const mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[1000]);
static void c1_b_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[57]);
static real_T c1_power(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b);
static void c1_eml_scalar_eg(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance);
static void c1_eml_error(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance);
static real_T c1_sqrt(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                      c1_x);
static void c1_b_eml_error(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance);
static void c1_randn(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                     c1_r[1000]);
static void c1_eml_rand_mcg16807(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_e_state, uint32_T *c1_f_state, real_T *c1_r);
static void c1_genrandu(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_s, uint32_T *c1_e_state, real_T *c1_r);
static void c1_eml_rand_shr3cong(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_e_state[2], uint32_T c1_f_state[2], real_T *c1_r);
static real_T c1_abs(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                     c1_x);
static void c1_eml_rand_mt19937ar(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[625]);
static void c1_twister_state_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625]);
static void c1_b_eml_rand_mt19937ar(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[625], uint32_T c1_f_state[625], real_T
  *c1_r);
static void c1_assert_valid_state(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);
static void c1_genrand_uint32_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], uint32_T c1_b_mt[625], uint32_T c1_u[2]);
static void c1_b_genrandu(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_mt[625], uint32_T c1_b_mt[625], real_T *c1_r);
static void c1_c_eml_error(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint32_T c1_e_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_c_method, const char_T *c1_identifier);
static uint32_T c1_f_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint32_T c1_g_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_c_method, const char_T *c1_identifier);
static uint32_T c1_h_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint32_T c1_i_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier);
static uint32_T c1_j_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_k_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier,
  uint32_T c1_y[625]);
static void c1_l_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[625]);
static void c1_m_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier,
  uint32_T c1_y[2]);
static void c1_n_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[2]);
static void c1_o_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier,
  uint32_T c1_y[2]);
static void c1_p_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[2]);
static uint8_T c1_q_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BPSK_Embedded, const char_T
  *c1_identifier);
static uint8_T c1_r_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sqrt(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                      *c1_x);
static real_T c1_b_eml_rand_mcg16807(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T *c1_e_state);
static real_T c1_b_eml_rand_shr3cong(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[2]);
static void c1_b_twister_state_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed);
static real_T c1_c_eml_rand_mt19937ar(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[625]);
static void c1_b_genrand_uint32_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], uint32_T c1_u[2]);
static real_T c1_c_genrandu(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_mt[625]);
static void init_dsm_address_info(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_method_not_empty = FALSE;
  chartInstance->c1_state_not_empty = FALSE;
  chartInstance->c1_b_method_not_empty = FALSE;
  chartInstance->c1_b_state_not_empty = FALSE;
  chartInstance->c1_c_state_not_empty = FALSE;
  chartInstance->c1_d_state_not_empty = FALSE;
  chartInstance->c1_is_active_c1_BPSK_Embedded = 0U;
}

static void initialize_params_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct *
  chartInstance)
{
}

static void enable_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_BPSK_Embedded
  (SFc1_BPSK_EmbeddedInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_BPSK_Embedded
  (SFc1_BPSK_EmbeddedInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[1000];
  const mxArray *c1_b_y = NULL;
  uint32_T c1_hoistedGlobal;
  uint32_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint32_T c1_b_hoistedGlobal;
  uint32_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint32_T c1_c_hoistedGlobal;
  uint32_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_i1;
  uint32_T c1_e_u[625];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i2;
  uint32_T c1_f_u[2];
  const mxArray *c1_g_y = NULL;
  int32_T c1_i3;
  uint32_T c1_g_u[2];
  const mxArray *c1_h_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T (*c1_j_y)[1000];
  c1_j_y = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(8), FALSE);
  for (c1_i0 = 0; c1_i0 < 1000; c1_i0++) {
    c1_u[c1_i0] = (*c1_j_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 1000), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_b_method;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  if (!chartInstance->c1_b_method_not_empty) {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 7, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_b_hoistedGlobal = chartInstance->c1_method;
  c1_c_u = c1_b_hoistedGlobal;
  c1_d_y = NULL;
  if (!chartInstance->c1_method_not_empty) {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 7, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_c_hoistedGlobal = chartInstance->c1_b_state;
  c1_d_u = c1_c_hoistedGlobal;
  c1_e_y = NULL;
  if (!chartInstance->c1_b_state_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 7, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  for (c1_i1 = 0; c1_i1 < 625; c1_i1++) {
    c1_e_u[c1_i1] = chartInstance->c1_d_state[c1_i1];
  }

  c1_f_y = NULL;
  if (!chartInstance->c1_d_state_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_e_u, 7, 0U, 1U, 0U, 1, 625),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_f_u[c1_i2] = chartInstance->c1_c_state[c1_i2];
  }

  c1_g_y = NULL;
  if (!chartInstance->c1_c_state_not_empty) {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_f_u, 7, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 5, c1_g_y);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_g_u[c1_i3] = chartInstance->c1_state[c1_i3];
  }

  c1_h_y = NULL;
  if (!chartInstance->c1_state_not_empty) {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_g_u, 7, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_BPSK_Embedded;
  c1_h_u = c1_d_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[1000];
  int32_T c1_i4;
  uint32_T c1_uv0[625];
  int32_T c1_i5;
  uint32_T c1_uv1[2];
  int32_T c1_i6;
  uint32_T c1_uv2[2];
  int32_T c1_i7;
  real_T (*c1_y)[1000];
  c1_y = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                      c1_dv0);
  for (c1_i4 = 0; c1_i4 < 1000; c1_i4++) {
    (*c1_y)[c1_i4] = c1_dv0[c1_i4];
  }

  chartInstance->c1_b_method = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "method");
  chartInstance->c1_method = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "method");
  chartInstance->c1_b_state = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "state");
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
                        "state", c1_uv0);
  for (c1_i5 = 0; c1_i5 < 625; c1_i5++) {
    chartInstance->c1_d_state[c1_i5] = c1_uv0[c1_i5];
  }

  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "state", c1_uv1);
  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    chartInstance->c1_c_state[c1_i6] = c1_uv1[c1_i6];
  }

  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
                        "state", c1_uv2);
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    chartInstance->c1_state[c1_i7] = c1_uv2[c1_i7];
  }

  chartInstance->c1_is_active_c1_BPSK_Embedded = c1_q_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
     "is_active_c1_BPSK_Embedded");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_BPSK_Embedded(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
{
}

static void sf_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance)
{
  int32_T c1_i8;
  int32_T c1_i9;
  real_T *c1_EbNo;
  real_T (*c1_y)[1000];
  real_T (*c1_Signal)[1000];
  c1_EbNo = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_y = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_Signal = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i8 = 0; c1_i8 < 1000; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((*c1_Signal)[c1_i8], 0U);
  }

  for (c1_i9 = 0; c1_i9 < 1000; c1_i9++) {
    _SFD_DATA_RANGE_CHECK((*c1_y)[c1_i9], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_EbNo, 2U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_BPSK_Embedded(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_BPSK_EmbeddedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  int32_T c1_i10;
  real_T c1_Signal[1000];
  real_T c1_EbNo;
  uint32_T c1_debug_family_var_map[13];
  real_T c1_n;
  real_T c1_m;
  real_T c1_EbN0_lin;
  real_T c1_noise_var;
  real_T c1_Noise[1000];
  real_T c1_p[1000];
  real_T c1_i;
  real_T c1_j;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_y[1000];
  int32_T c1_i11;
  real_T c1_b;
  real_T c1_b_y;
  real_T c1_B;
  real_T c1_c_y;
  real_T c1_d_y;
  real_T c1_a;
  real_T c1_b_b[1000];
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_b_i;
  int32_T c1_i14;
  int32_T c1_i15;
  real_T *c1_b_EbNo;
  real_T (*c1_e_y)[1000];
  real_T (*c1_b_Signal)[1000];
  c1_b_EbNo = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_e_y = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Signal = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_EbNo;
  for (c1_i10 = 0; c1_i10 < 1000; c1_i10++) {
    c1_Signal[c1_i10] = (*c1_b_Signal)[c1_i10];
  }

  c1_EbNo = c1_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_n, 0U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m, 1U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_EbN0_lin, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_noise_var, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Noise, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_p, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_j, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 9U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Signal, 10U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_EbNo, 11U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_n = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_m = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  for (c1_i11 = 0; c1_i11 < 1000; c1_i11++) {
    c1_y[c1_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_b = c1_EbNo;
  c1_b_y = 0.1 * c1_b;
  c1_EbN0_lin = c1_power(chartInstance, 10.0, c1_b_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_B = c1_EbN0_lin;
  c1_c_y = c1_B;
  c1_d_y = c1_c_y;
  c1_noise_var = 0.5 / c1_d_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_a = c1_noise_var;
  c1_b_sqrt(chartInstance, &c1_a);
  c1_randn(chartInstance, c1_b_b);
  for (c1_i12 = 0; c1_i12 < 1000; c1_i12++) {
    c1_Noise[c1_i12] = c1_a * c1_b_b[c1_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  for (c1_i13 = 0; c1_i13 < 1000; c1_i13++) {
    c1_p[c1_i13] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_i = 1.0;
  c1_b_i = 0;
  while (c1_b_i < 1000) {
    c1_i = 1.0 + (real_T)c1_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    c1_j = 1.0;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
    c1_p[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("p", (int32_T)
      _SFD_INTEGER_CHECK("i", c1_i), 1, 1000, 1, 0) - 1] = c1_Signal[(int32_T)
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Signal", (int32_T)_SFD_INTEGER_CHECK(
      "i", c1_i), 1, 1000, 1, 0) - 1] + c1_Noise[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("Noise", (int32_T)_SFD_INTEGER_CHECK("i", c1_i),
      1, 1000, 1, 0) - 1];
    CV_EML_FOR(0, 1, 1, 0);
    c1_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  for (c1_i14 = 0; c1_i14 < 1000; c1_i14++) {
    c1_y[c1_i14] = c1_p[c1_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i15 = 0; c1_i15 < 1000; c1_i15++) {
    (*c1_e_y)[c1_i15] = c1_y[c1_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_BPSK_Embedded(SFc1_BPSK_EmbeddedInstanceStruct
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
  int32_T c1_i16;
  real_T c1_b_inData[1000];
  int32_T c1_i17;
  real_T c1_u[1000];
  const mxArray *c1_y = NULL;
  SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
  chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i16 = 0; c1_i16 < 1000; c1_i16++) {
    c1_b_inData[c1_i16] = (*(real_T (*)[1000])c1_inData)[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 1000; c1_i17++) {
    c1_u[c1_i17] = c1_b_inData[c1_i17];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 1000), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  const mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[1000])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
}

static void c1_b_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000])
{
  real_T c1_dv1[1000];
  int32_T c1_i18;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 1000);
  for (c1_i18 = 0; c1_i18 < 1000; c1_i18++) {
    c1_y[c1_i18] = c1_dv1[c1_i18];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[1000];
  int32_T c1_i19;
  SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
  chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i19 = 0; c1_i19 < 1000; c1_i19++) {
    (*(real_T (*)[1000])c1_outData)[c1_i19] = c1_b_y[c1_i19];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
  chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
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
  SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
  chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_BPSK_Embedded_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[57];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i20;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 57), FALSE);
  for (c1_i20 = 0; c1_i20 < 57; c1_i20++) {
    c1_r0 = &c1_info[c1_i20];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i20);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[57])
{
  c1_info[0].context = "";
  c1_info[0].name = "mtimes";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[0].fileTimeLo = 1289503492U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "power";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[1].fileTimeLo = 1348179330U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[2].name = "eml_scalar_eg";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[2].fileTimeLo = 1286806196U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[3].name = "eml_scalexp_alloc";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[3].fileTimeLo = 1352408660U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[4].name = "floor";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[4].fileTimeLo = 1343817780U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[5].name = "eml_scalar_floor";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[5].fileTimeLo = 1286806126U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[6].name = "eml_error";
  c1_info[6].dominantType = "char";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[6].fileTimeLo = 1343817758U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[7].name = "eml_scalar_eg";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[7].fileTimeLo = 1286806196U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "";
  c1_info[8].name = "mrdivide";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[8].fileTimeLo = 1357935348U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 1319717366U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[9].name = "rdivide";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[9].fileTimeLo = 1346497788U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[10].name = "eml_scalexp_compatible";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[10].fileTimeLo = 1286806196U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[11].name = "eml_div";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[11].fileTimeLo = 1313335210U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "";
  c1_info[12].name = "sqrt";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[12].fileTimeLo = 1343817786U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[13].name = "eml_error";
  c1_info[13].dominantType = "char";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[13].fileTimeLo = 1343817758U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[14].name = "eml_scalar_sqrt";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[14].fileTimeLo = 1286806138U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context = "";
  c1_info[15].name = "randn";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randn.m";
  c1_info[15].fileTimeLo = 1313335224U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randn.m";
  c1_info[16].name = "eml_is_rand_extrinsic";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m";
  c1_info[16].fileTimeLo = 1334058890U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randn.m";
  c1_info[17].name = "eml_randn";
  c1_info[17].dominantType = "char";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_randn.m";
  c1_info[17].fileTimeLo = 1313335222U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_randn.m";
  c1_info[18].name = "eml_rand_str2id";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m";
  c1_info[18].fileTimeLo = 1313335222U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_randn.m";
  c1_info[19].name = "eml_rand_shr3cong";
  c1_info[19].dominantType = "char";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c1_info[19].fileTimeLo = 1313335220U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_randn.m";
  c1_info[20].name = "eml_tolower";
  c1_info[20].dominantType = "char";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_tolower.m";
  c1_info[20].fileTimeLo = 1286806200U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_randn.m";
  c1_info[21].name = "eml_rand";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[21].fileTimeLo = 1313335220U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[22].name = "eml_rand_str2id";
  c1_info[22].dominantType = "char";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m";
  c1_info[22].fileTimeLo = 1313335222U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[23].name = "eml_rand_mcg16807_stateful";
  c1_info[23].dominantType = "char";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c1_info[23].fileTimeLo = 1313335220U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c1_info[24].name = "eml_rand_mcg16807";
  c1_info[24].dominantType = "char";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c1_info[24].fileTimeLo = 1313335220U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c1_info[25].name = "eml_rand_mcg16807";
  c1_info[25].dominantType = "uint32";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c1_info[25].fileTimeLo = 1313335220U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m!genrandu";
  c1_info[26].name = "mtimes";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[26].fileTimeLo = 1289503492U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m!genrandn";
  c1_info[27].name = "mtimes";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[27].fileTimeLo = 1289503492U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[28].name = "eml_rand_shr3cong_stateful";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c1_info[28].fileTimeLo = 1313335222U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c1_info[29].name = "eml_rand_shr3cong";
  c1_info[29].dominantType = "char";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c1_info[29].fileTimeLo = 1313335220U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c1_info[30].name = "eml_rand_shr3cong";
  c1_info[30].dominantType = "uint32";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c1_info[30].fileTimeLo = 1313335220U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandn";
  c1_info[31].name = "mtimes";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[31].fileTimeLo = 1289503492U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandn";
  c1_info[32].name = "abs";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[32].fileTimeLo = 1343817766U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[33].name = "eml_scalar_abs";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[33].fileTimeLo = 1286806112U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandn";
  c1_info[34].name = "mrdivide";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[34].fileTimeLo = 1357935348U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 1319717366U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandn";
  c1_info[35].name = "exp";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c1_info[35].fileTimeLo = 1343817780U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c1_info[36].name = "eml_scalar_exp";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c1_info[36].fileTimeLo = 1301315864U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[37].name = "eml_rand_mt19937ar_stateful";
  c1_info[37].dominantType = "char";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c1_info[37].fileTimeLo = 1313335220U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c1_info[38].name = "eml_rand_mt19937ar";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c1_info[38].fileTimeLo = 1313335220U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c1_info[39].name = "eml_rand_mt19937ar";
  c1_info[39].dominantType = "uint32";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c1_info[39].fileTimeLo = 1313335220U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c1_info[40].name = "isequal";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[40].fileTimeLo = 1286806158U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[41].name = "eml_isequal_core";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[41].fileTimeLo = 1286806186U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c1_info[42].name = "isnan";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[42].fileTimeLo = 1286806160U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!mtziggurat";
  c1_info[43].name = "mtimes";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[43].fileTimeLo = 1289503492U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!mtziggurat";
  c1_info[44].name = "mrdivide";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[44].fileTimeLo = 1357935348U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 1319717366U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!mtziggurat";
  c1_info[45].name = "abs";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[45].fileTimeLo = 1343817766U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c1_info[46].name = "eps";
  c1_info[46].dominantType = "";
  c1_info[46].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[46].fileTimeLo = 1326711796U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[47].name = "eml_eps";
  c1_info[47].dominantType = "char";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[47].fileTimeLo = 1326711796U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[48].name = "eml_float_model";
  c1_info[48].dominantType = "char";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[48].fileTimeLo = 1326711796U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c1_info[49].name = "mtimes";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[49].fileTimeLo = 1289503492U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c1_info[50].name = "eml_index_class";
  c1_info[50].dominantType = "";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[50].fileTimeLo = 1323154378U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c1_info[51].name = "eml_index_plus";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[51].fileTimeLo = 1286806178U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[52].name = "eml_index_class";
  c1_info[52].dominantType = "";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[52].fileTimeLo = 1323154378U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c1_info[53].name = "eml_error";
  c1_info[53].dominantType = "char";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[53].fileTimeLo = 1343817758U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!mtziggurat";
  c1_info[54].name = "exp";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c1_info[54].fileTimeLo = 1343817780U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_randn.m";
  c1_info[55].name = "eml_rand_mcg16807";
  c1_info[55].dominantType = "uint32";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c1_info[55].fileTimeLo = 1313335220U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_randn.m";
  c1_info[56].name = "eml_rand_shr3cong";
  c1_info[56].dominantType = "uint32";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c1_info[56].fileTimeLo = 1313335220U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
}

static real_T c1_power(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b)
{
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_ak;
  real_T c1_bk;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_ar;
  real_T c1_br;
  c1_b_a = c1_a;
  c1_b_b = c1_b;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_b_a;
  c1_bk = c1_b_b;
  if (c1_ak < 0.0) {
    c1_x = c1_bk;
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarFloor(c1_b_x);
    if (c1_b_x != c1_bk) {
      c1_eml_error(chartInstance);
    }
  }

  c1_c_a = c1_ak;
  c1_c_b = c1_bk;
  c1_eml_scalar_eg(chartInstance);
  c1_ar = c1_c_a;
  c1_br = c1_c_b;
  return muDoubleScalarPower(c1_ar, c1_br);
}

static void c1_eml_scalar_eg(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance)
{
}

static void c1_eml_error(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance)
{
  int32_T c1_i21;
  static char_T c1_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[31];
  const mxArray *c1_y = NULL;
  for (c1_i21 = 0; c1_i21 < 31; c1_i21++) {
    c1_u[c1_i21] = c1_cv0[c1_i21];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 31), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static real_T c1_sqrt(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_b_eml_error(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance)
{
  int32_T c1_i22;
  static char_T c1_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i23;
  static char_T c1_cv2[4] = { 's', 'q', 'r', 't' };

  char_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  for (c1_i22 = 0; c1_i22 < 30; c1_i22++) {
    c1_u[c1_i22] = c1_cv1[c1_i22];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
    c1_b_u[c1_i23] = c1_cv2[c1_i23];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static void c1_randn(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                     c1_r[1000])
{
  int32_T c1_i24;
  static uint32_T c1_uv3[2] = { 362436069U, 0U };

  int32_T c1_k;
  real_T c1_b_k;
  uint32_T c1_e_state;
  real_T c1_d1;
  int32_T c1_i25;
  int32_T c1_c_k;
  real_T c1_d_k;
  real_T c1_d2;
  uint32_T c1_uv4[625];
  int32_T c1_i26;
  int32_T c1_e_k;
  real_T c1_f_k;
  real_T c1_d3;
  uint32_T c1_hoistedGlobal;
  int32_T c1_g_k;
  real_T c1_h_k;
  uint32_T c1_u0;
  real_T c1_d4;
  int32_T c1_i_k;
  real_T c1_d5;
  if (!chartInstance->c1_method_not_empty) {
    chartInstance->c1_method = 0U;
    chartInstance->c1_method_not_empty = TRUE;
    for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
      chartInstance->c1_state[c1_i24] = c1_uv3[c1_i24];
    }

    if ((real_T)chartInstance->c1_state[1] == 0.0) {
      chartInstance->c1_state[1] = 521288629U;
    }

    chartInstance->c1_state_not_empty = TRUE;
  }

  if (chartInstance->c1_method == 0U) {
    if (!chartInstance->c1_b_method_not_empty) {
      chartInstance->c1_b_method = 7U;
      chartInstance->c1_b_method_not_empty = TRUE;
    }

    if (chartInstance->c1_b_method == 4U) {
      if (!chartInstance->c1_b_state_not_empty) {
        chartInstance->c1_b_state = 1144108930U;
        chartInstance->c1_b_state_not_empty = TRUE;
      }

      for (c1_k = 0; c1_k < 1000; c1_k++) {
        c1_b_k = 1.0 + (real_T)c1_k;
        c1_e_state = chartInstance->c1_b_state;
        c1_d1 = c1_b_eml_rand_mcg16807(chartInstance, &c1_e_state);
        chartInstance->c1_b_state = c1_e_state;
        c1_r[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_b_k), 1, 1000, 1, 0) - 1] = c1_d1;
      }
    } else if (chartInstance->c1_b_method == 5U) {
      if (!chartInstance->c1_c_state_not_empty) {
        for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
          chartInstance->c1_c_state[c1_i25] = 362436069U + 158852560U *
            (uint32_T)c1_i25;
        }

        chartInstance->c1_c_state_not_empty = TRUE;
      }

      for (c1_c_k = 0; c1_c_k < 1000; c1_c_k++) {
        c1_d_k = 1.0 + (real_T)c1_c_k;
        c1_d2 = c1_b_eml_rand_shr3cong(chartInstance, chartInstance->c1_c_state);
        c1_r[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_d_k), 1, 1000, 1, 0) - 1] = c1_d2;
      }
    } else {
      if (!chartInstance->c1_d_state_not_empty) {
        c1_eml_rand_mt19937ar(chartInstance, c1_uv4);
        for (c1_i26 = 0; c1_i26 < 625; c1_i26++) {
          chartInstance->c1_d_state[c1_i26] = c1_uv4[c1_i26];
        }

        chartInstance->c1_d_state_not_empty = TRUE;
      }

      for (c1_e_k = 0; c1_e_k < 1000; c1_e_k++) {
        c1_f_k = 1.0 + (real_T)c1_e_k;
        c1_d3 = c1_c_eml_rand_mt19937ar(chartInstance, chartInstance->c1_d_state);
        c1_r[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_f_k), 1, 1000, 1, 0) - 1] = c1_d3;
      }
    }
  } else {
    c1_hoistedGlobal = chartInstance->c1_method;
    if (c1_hoistedGlobal == 4U) {
      for (c1_g_k = 0; c1_g_k < 1000; c1_g_k++) {
        c1_h_k = 1.0 + (real_T)c1_g_k;
        c1_u0 = chartInstance->c1_state[0];
        c1_d4 = c1_b_eml_rand_mcg16807(chartInstance, &c1_u0);
        chartInstance->c1_state[0] = c1_u0;
        c1_r[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_h_k), 1, 1000, 1, 0) - 1] = c1_d4;
      }
    } else {
      for (c1_i_k = 0; c1_i_k < 1000; c1_i_k++) {
        c1_h_k = 1.0 + (real_T)c1_i_k;
        c1_d5 = c1_b_eml_rand_shr3cong(chartInstance, chartInstance->c1_state);
        c1_r[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_h_k), 1, 1000, 1, 0) - 1] = c1_d5;
      }
    }
  }
}

static void c1_eml_rand_mcg16807(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_e_state, uint32_T *c1_f_state, real_T *c1_r)
{
  *c1_f_state = c1_e_state;
  *c1_r = c1_b_eml_rand_mcg16807(chartInstance, c1_f_state);
}

static void c1_genrandu(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_s, uint32_T *c1_e_state, real_T *c1_r)
{
  uint32_T c1_u1;
  uint32_T c1_hi;
  uint32_T c1_lo;
  uint32_T c1_test1;
  uint32_T c1_test2;
  real_T c1_a;
  c1_u1 = 127773U;
  if (c1_u1 == 0) {
    c1_hi = MAX_uint32_T;
  } else {
    c1_hi = c1_s / c1_u1;
  }

  c1_lo = c1_s - c1_hi * 127773U;
  c1_test1 = 16807U * c1_lo;
  c1_test2 = 2836U * c1_hi;
  if (c1_test1 < c1_test2) {
    *c1_e_state = (c1_test1 - c1_test2) + 2147483647U;
  } else {
    *c1_e_state = c1_test1 - c1_test2;
  }

  c1_a = (real_T)*c1_e_state;
  *c1_r = c1_a * 4.6566128752457969E-10;
}

static void c1_eml_rand_shr3cong(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_e_state[2], uint32_T c1_f_state[2], real_T *c1_r)
{
  int32_T c1_i27;
  for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
    c1_f_state[c1_i27] = c1_e_state[c1_i27];
  }

  *c1_r = c1_b_eml_rand_shr3cong(chartInstance, c1_f_state);
}

static real_T c1_abs(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                     c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  return muDoubleScalarAbs(c1_b_x);
}

static void c1_eml_rand_mt19937ar(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[625])
{
  real_T c1_d6;
  int32_T c1_i28;
  c1_d6 = 5489.0;
  for (c1_i28 = 0; c1_i28 < 625; c1_i28++) {
    c1_e_state[c1_i28] = 0U;
  }

  c1_b_twister_state_vector(chartInstance, c1_e_state, c1_d6);
}

static void c1_twister_state_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625])
{
  int32_T c1_i29;
  for (c1_i29 = 0; c1_i29 < 625; c1_i29++) {
    c1_b_mt[c1_i29] = c1_mt[c1_i29];
  }

  c1_b_twister_state_vector(chartInstance, c1_b_mt, c1_seed);
}

static void c1_b_eml_rand_mt19937ar(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[625], uint32_T c1_f_state[625], real_T
  *c1_r)
{
  int32_T c1_i30;
  for (c1_i30 = 0; c1_i30 < 625; c1_i30++) {
    c1_f_state[c1_i30] = c1_e_state[c1_i30];
  }

  *c1_r = c1_c_eml_rand_mt19937ar(chartInstance, c1_f_state);
}

static void c1_assert_valid_state(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
{
}

static void c1_genrand_uint32_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], uint32_T c1_b_mt[625], uint32_T c1_u[2])
{
  int32_T c1_i31;
  for (c1_i31 = 0; c1_i31 < 625; c1_i31++) {
    c1_b_mt[c1_i31] = c1_mt[c1_i31];
  }

  c1_b_genrand_uint32_vector(chartInstance, c1_b_mt, c1_u);
}

static void c1_b_genrandu(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_mt[625], uint32_T c1_b_mt[625], real_T *c1_r)
{
  int32_T c1_i32;
  for (c1_i32 = 0; c1_i32 < 625; c1_i32++) {
    c1_b_mt[c1_i32] = c1_mt[c1_i32];
  }

  *c1_r = c1_c_genrandu(chartInstance, c1_b_mt);
}

static void c1_c_eml_error(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance)
{
  int32_T c1_i33;
  static char_T c1_cv3[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c1_u[37];
  const mxArray *c1_y = NULL;
  for (c1_i33 = 0; c1_i33 < 37; c1_i33++) {
    c1_u[c1_i33] = c1_cv3[c1_i33];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 37), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
  chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i34;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i34, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i34;
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
  SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
  chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *)chartInstanceVoid;
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

static uint32_T c1_e_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_c_method, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_c_method),
    &c1_thisId);
  sf_mex_destroy(&c1_c_method);
  return c1_y;
}

static uint32_T c1_f_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u2;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_b_method_not_empty = FALSE;
  } else {
    chartInstance->c1_b_method_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u2, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u2;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint32_T c1_g_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_c_method, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_c_method),
    &c1_thisId);
  sf_mex_destroy(&c1_c_method);
  return c1_y;
}

static uint32_T c1_h_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u3;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_method_not_empty = FALSE;
  } else {
    chartInstance->c1_method_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u3, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u3;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint32_T c1_i_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e_state), &c1_thisId);
  sf_mex_destroy(&c1_e_state);
  return c1_y;
}

static uint32_T c1_j_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u4;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_b_state_not_empty = FALSE;
  } else {
    chartInstance->c1_b_state_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u4, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u4;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_k_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier,
  uint32_T c1_y[625])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_e_state);
}

static void c1_l_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[625])
{
  uint32_T c1_uv5[625];
  int32_T c1_i35;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_d_state_not_empty = FALSE;
  } else {
    chartInstance->c1_d_state_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv5, 1, 7, 0U, 1, 0U, 1, 625);
    for (c1_i35 = 0; c1_i35 < 625; c1_i35++) {
      c1_y[c1_i35] = c1_uv5[c1_i35];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_m_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier,
  uint32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_e_state);
}

static void c1_n_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[2])
{
  uint32_T c1_uv6[2];
  int32_T c1_i36;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_c_state_not_empty = FALSE;
  } else {
    chartInstance->c1_c_state_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv6, 1, 7, 0U, 1, 0U, 1, 2);
    for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
      c1_y[c1_i36] = c1_uv6[c1_i36];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_o_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_e_state, const char_T *c1_identifier,
  uint32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_e_state);
}

static void c1_p_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[2])
{
  uint32_T c1_uv7[2];
  int32_T c1_i37;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_state_not_empty = FALSE;
  } else {
    chartInstance->c1_state_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv7, 1, 7, 0U, 1, 0U, 1, 2);
    for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
      c1_y[c1_i37] = c1_uv7[c1_i37];
    }
  }

  sf_mex_destroy(&c1_u);
}

static uint8_T c1_q_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BPSK_Embedded, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_BPSK_Embedded), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_BPSK_Embedded);
  return c1_y;
}

static uint8_T c1_r_emlrt_marshallIn(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u5;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u5, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u5;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sqrt(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance, real_T
                      *c1_x)
{
  if (*c1_x < 0.0) {
    c1_b_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarSqrt(*c1_x);
}

static real_T c1_b_eml_rand_mcg16807(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T *c1_e_state)
{
  uint32_T c1_f_state;
  uint32_T c1_g_state;
  real_T c1_b_r;
  uint32_T c1_h_state;
  real_T c1_c_r;
  real_T c1_t;
  uint32_T c1_i_state;
  real_T c1_b_t;
  real_T c1_b;
  real_T c1_y;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_a;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_b_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_c_a;
  real_T c1_f_b;
  c1_f_state = *c1_e_state;
  c1_g_state = c1_f_state;
  do {
    c1_genrandu(chartInstance, c1_g_state, &c1_h_state, &c1_b_r);
    c1_g_state = c1_h_state;
    c1_c_r = c1_b_r;
    c1_genrandu(chartInstance, c1_g_state, &c1_i_state, &c1_t);
    c1_g_state = c1_i_state;
    c1_b_t = c1_t;
    c1_b = c1_c_r;
    c1_y = 2.0 * c1_b;
    c1_c_r = c1_y - 1.0;
    c1_b_b = c1_b_t;
    c1_b_y = 2.0 * c1_b_b;
    c1_b_t = c1_b_y - 1.0;
    c1_a = c1_b_t;
    c1_c_b = c1_b_t;
    c1_c_y = c1_a * c1_c_b;
    c1_b_a = c1_c_r;
    c1_d_b = c1_c_r;
    c1_d_y = c1_b_a * c1_d_b;
    c1_b_t = c1_c_y + c1_d_y;
  } while (!(c1_b_t <= 1.0));

  c1_e_b = muDoubleScalarLog(c1_b_t);
  c1_e_y = -2.0 * c1_e_b;
  c1_c_a = c1_c_r;
  c1_f_b = muDoubleScalarSqrt(c1_e_y / c1_b_t);
  c1_c_r = c1_c_a * c1_f_b;
  *c1_e_state = c1_g_state;
  return c1_c_r;
}

static real_T c1_b_eml_rand_shr3cong(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[2])
{
  uint32_T c1_icng;
  uint32_T c1_jsr;
  uint32_T c1_b_icng;
  uint32_T c1_b_jsr;
  uint32_T c1_c_jsr;
  uint32_T c1_c_icng;
  uint32_T c1_ui;
  uint32_T c1_b_ui;
  uint32_T c1_j;
  uint32_T c1_jp1;
  int32_T c1_i;
  real_T c1_a;
  real_T c1_y;
  real_T c1_b_a;
  static real_T c1_dv2[65] = { 0.340945, 0.4573146, 0.5397793, 0.6062427,
    0.6631691, 0.7136975, 0.7596125, 0.8020356, 0.8417227, 0.8792102, 0.9148948,
    0.9490791, 0.9820005, 1.0138492, 1.044781, 1.0749254, 1.1043917, 1.1332738,
    1.161653, 1.189601, 1.2171815, 1.2444516, 1.2714635, 1.298265, 1.3249008,
    1.3514125, 1.3778399, 1.4042211, 1.4305929, 1.4569915, 1.4834527, 1.5100122,
    1.5367061, 1.5635712, 1.5906454, 1.617968, 1.6455802, 1.6735255, 1.7018503,
    1.7306045, 1.7598422, 1.7896223, 1.8200099, 1.851077, 1.8829044, 1.9155831,
    1.9492166, 1.9839239, 2.0198431, 2.0571356, 2.095993, 2.136645, 2.1793713,
    2.2245175, 2.2725186, 2.3239338, 2.3795008, 2.4402218, 2.5075117, 2.5834658,
    2.6713916, 2.7769942, 2.7769942, 2.7769942, 2.7769942 };

  real_T c1_b;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_c_r;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_c_y;
  real_T c1_A;
  real_T c1_B;
  real_T c1_e_x;
  real_T c1_d_y;
  real_T c1_f_x;
  real_T c1_e_y;
  real_T c1_g_x;
  uint32_T c1_d_icng;
  uint32_T c1_d_jsr;
  uint32_T c1_e_jsr;
  uint32_T c1_e_icng;
  uint32_T c1_c_ui;
  real_T c1_c_a;
  real_T c1_f_y;
  real_T c1_g_y;
  real_T c1_s;
  real_T c1_b_b;
  real_T c1_h_y;
  real_T c1_c_b;
  real_T c1_i_y;
  real_T c1_d_b;
  real_T c1_j_y;
  real_T c1_e_b;
  real_T c1_k_y;
  real_T c1_d_a;
  real_T c1_f_b;
  real_T c1_l_y;
  real_T c1_g_b;
  real_T c1_m_y;
  real_T c1_h_b;
  real_T c1_n_y;
  real_T c1_e_a;
  real_T c1_i_b;
  real_T c1_o_y;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_f_a;
  real_T c1_p_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_j_x;
  real_T c1_q_y;
  real_T c1_k_x;
  real_T c1_r_y;
  real_T c1_s_y;
  real_T c1_j_b;
  real_T c1_t_y;
  real_T c1_g_a;
  real_T c1_k_b;
  real_T c1_u_y;
  uint32_T c1_f_icng;
  uint32_T c1_f_jsr;
  uint32_T c1_g_jsr;
  uint32_T c1_g_icng;
  uint32_T c1_d_ui;
  real_T c1_h_a;
  real_T c1_v_y;
  real_T c1_c_A;
  real_T c1_l_x;
  real_T c1_m_x;
  uint32_T c1_h_icng;
  uint32_T c1_h_jsr;
  uint32_T c1_i_jsr;
  uint32_T c1_i_icng;
  uint32_T c1_e_ui;
  real_T c1_i_a;
  real_T c1_w_y;
  real_T c1_l_b;
  real_T c1_x_y;
  real_T c1_j_a;
  real_T c1_m_b;
  real_T c1_y_y;
  c1_icng = c1_e_state[0];
  c1_jsr = c1_e_state[1];
  c1_b_icng = c1_icng;
  c1_b_jsr = c1_jsr;
  c1_c_jsr = c1_b_jsr;
  c1_c_icng = c1_b_icng;
  c1_c_icng = 69069U * c1_c_icng + 1234567U;
  c1_c_jsr ^= c1_c_jsr << 13U;
  c1_c_jsr ^= c1_c_jsr >> 17U;
  c1_c_jsr ^= c1_c_jsr << 5U;
  c1_ui = c1_c_icng + c1_c_jsr;
  c1_icng = c1_c_icng;
  c1_jsr = c1_c_jsr;
  c1_b_ui = c1_ui;
  c1_j = (c1_b_ui & 63U) + 1U;
  c1_j;
  c1_jp1 = c1_j + 1U;
  c1_i = (int32_T)c1_b_ui;
  c1_a = (real_T)c1_i;
  c1_y = c1_a * 4.6566128730773926E-10;
  c1_b_a = c1_y;
  c1_b = c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_jp1), 1, 65, 1, 0) - 1];
  c1_b_r = c1_b_a * c1_b;
  c1_x = c1_b_r;
  c1_b_x = c1_x;
  c1_b_y = muDoubleScalarAbs(c1_b_x);
  if (c1_b_y <= c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
       (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_j), 1, 65, 1, 0) - 1])
  {
    c1_c_r = c1_b_r;
  } else {
    c1_c_x = c1_b_r;
    c1_d_x = c1_c_x;
    c1_c_y = muDoubleScalarAbs(c1_d_x);
    c1_A = c1_c_y - c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_j), 1, 65, 1, 0) - 1];
    c1_B = c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_jp1), 1, 65, 1, 0) - 1] -
      c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_j), 1, 65, 1, 0) - 1];
    c1_e_x = c1_A;
    c1_d_y = c1_B;
    c1_f_x = c1_e_x;
    c1_e_y = c1_d_y;
    c1_g_x = c1_f_x / c1_e_y;
    c1_d_icng = c1_icng;
    c1_d_jsr = c1_jsr;
    c1_e_jsr = c1_d_jsr;
    c1_e_icng = c1_d_icng;
    c1_e_icng = 69069U * c1_e_icng + 1234567U;
    c1_e_jsr ^= c1_e_jsr << 13U;
    c1_e_jsr ^= c1_e_jsr >> 17U;
    c1_e_jsr ^= c1_e_jsr << 5U;
    c1_c_ui = c1_e_icng + c1_e_jsr;
    c1_icng = c1_e_icng;
    c1_jsr = c1_e_jsr;
    c1_b_ui = c1_c_ui;
    c1_i = (int32_T)c1_b_ui;
    c1_c_a = (real_T)c1_i;
    c1_f_y = c1_c_a * 2.328306436538696E-10;
    c1_g_y = 0.5 + c1_f_y;
    c1_s = c1_g_x + c1_g_y;
    if (c1_s > 1.301198) {
      if (c1_b_r < 0.0) {
        c1_b_b = c1_g_x;
        c1_h_y = 0.4878992 * c1_b_b;
        c1_c_r = c1_h_y - 0.4878992;
      } else {
        c1_c_b = c1_g_x;
        c1_i_y = 0.4878992 * c1_c_b;
        c1_c_r = 0.4878992 - c1_i_y;
      }
    } else if (c1_s <= 0.9689279) {
      c1_c_r = c1_b_r;
    } else {
      c1_d_b = c1_g_x;
      c1_j_y = 0.4878992 * c1_d_b;
      c1_g_x = 0.4878992 - c1_j_y;
      c1_e_b = c1_g_x;
      c1_k_y = -0.5 * c1_e_b;
      c1_d_a = c1_k_y;
      c1_f_b = c1_g_x;
      c1_l_y = c1_d_a * c1_f_b;
      c1_g_b = muDoubleScalarExp(c1_l_y);
      c1_m_y = 12.37586 * c1_g_b;
      if (c1_g_y > 12.67706 - c1_m_y) {
        if (c1_b_r < 0.0) {
          c1_c_r = -c1_g_x;
        } else {
          c1_c_r = c1_g_x;
        }
      } else {
        c1_h_b = c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_jp1), 1, 65, 1, 0)
          - 1];
        c1_n_y = -0.5 * c1_h_b;
        c1_e_a = c1_n_y;
        c1_i_b = c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_jp1), 1, 65, 1, 0)
          - 1];
        c1_o_y = c1_e_a * c1_i_b;
        c1_h_x = c1_o_y;
        c1_i_x = c1_h_x;
        c1_i_x = muDoubleScalarExp(c1_i_x);
        c1_f_a = c1_g_y;
        c1_p_y = c1_f_a * 0.01958303;
        c1_b_A = c1_p_y;
        c1_b_B = c1_dv2[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_jp1), 1, 65, 1, 0)
          - 1];
        c1_j_x = c1_b_A;
        c1_q_y = c1_b_B;
        c1_k_x = c1_j_x;
        c1_r_y = c1_q_y;
        c1_s_y = c1_k_x / c1_r_y;
        c1_j_b = c1_b_r;
        c1_t_y = -0.5 * c1_j_b;
        c1_g_a = c1_t_y;
        c1_k_b = c1_b_r;
        c1_u_y = c1_g_a * c1_k_b;
        if (c1_i_x + c1_s_y <= muDoubleScalarExp(c1_u_y)) {
          c1_c_r = c1_b_r;
        } else {
          do {
            c1_f_icng = c1_icng;
            c1_f_jsr = c1_jsr;
            c1_g_jsr = c1_f_jsr;
            c1_g_icng = c1_f_icng;
            c1_g_icng = 69069U * c1_g_icng + 1234567U;
            c1_g_jsr ^= c1_g_jsr << 13U;
            c1_g_jsr ^= c1_g_jsr >> 17U;
            c1_g_jsr ^= c1_g_jsr << 5U;
            c1_d_ui = c1_g_icng + c1_g_jsr;
            c1_icng = c1_g_icng;
            c1_jsr = c1_g_jsr;
            c1_b_ui = c1_d_ui;
            c1_i = (int32_T)c1_b_ui;
            c1_h_a = (real_T)c1_i;
            c1_v_y = c1_h_a * 2.328306436538696E-10;
            c1_c_A = muDoubleScalarLog(0.5 + c1_v_y);
            c1_l_x = c1_c_A;
            c1_m_x = c1_l_x;
            c1_g_x = c1_m_x / 2.776994;
            c1_h_icng = c1_icng;
            c1_h_jsr = c1_jsr;
            c1_i_jsr = c1_h_jsr;
            c1_i_icng = c1_h_icng;
            c1_i_icng = 69069U * c1_i_icng + 1234567U;
            c1_i_jsr ^= c1_i_jsr << 13U;
            c1_i_jsr ^= c1_i_jsr >> 17U;
            c1_i_jsr ^= c1_i_jsr << 5U;
            c1_e_ui = c1_i_icng + c1_i_jsr;
            c1_icng = c1_i_icng;
            c1_jsr = c1_i_jsr;
            c1_b_ui = c1_e_ui;
            c1_i = (int32_T)c1_b_ui;
            c1_i_a = (real_T)c1_i;
            c1_w_y = c1_i_a * 2.328306436538696E-10;
            c1_l_b = muDoubleScalarLog(0.5 + c1_w_y);
            c1_x_y = -2.0 * c1_l_b;
            c1_j_a = c1_g_x;
            c1_m_b = c1_g_x;
            c1_y_y = c1_j_a * c1_m_b;
          } while (!(c1_x_y > c1_y_y));

          if (c1_b_r < 0.0) {
            c1_c_r = c1_g_x - 2.776994;
          } else {
            c1_c_r = 2.776994 - c1_g_x;
          }
        }
      }
    }
  }

  c1_e_state[0] = c1_icng;
  c1_e_state[1] = c1_jsr;
  return c1_c_r;
}

static void c1_b_twister_state_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed)
{
  real_T c1_d7;
  uint32_T c1_u6;
  uint32_T c1_r;
  int32_T c1_mti;
  real_T c1_b_mti;
  real_T c1_d8;
  uint32_T c1_u7;
  c1_d7 = c1_seed;
  if (c1_d7 < 4.294967296E+9) {
    if (c1_d7 >= 0.0) {
      c1_u6 = (uint32_T)c1_d7;
    } else {
      c1_u6 = 0U;
    }
  } else if (c1_d7 >= 4.294967296E+9) {
    c1_u6 = MAX_uint32_T;
  } else {
    c1_u6 = 0U;
  }

  c1_r = c1_u6;
  c1_mt[0] = c1_r;
  for (c1_mti = 0; c1_mti < 623; c1_mti++) {
    c1_b_mti = 2.0 + (real_T)c1_mti;
    c1_d8 = muDoubleScalarRound(c1_b_mti - 1.0);
    if (c1_d8 < 4.294967296E+9) {
      if (c1_d8 >= 0.0) {
        c1_u7 = (uint32_T)c1_d8;
      } else {
        c1_u7 = 0U;
      }
    } else if (c1_d8 >= 4.294967296E+9) {
      c1_u7 = MAX_uint32_T;
    } else {
      c1_u7 = 0U;
    }

    c1_r = (c1_r ^ c1_r >> 30U) * 1812433253U + c1_u7;
    c1_mt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_mti), 1, 625, 1, 0) - 1] = c1_r;
  }

  c1_mt[624] = 624U;
}

static real_T c1_c_eml_rand_mt19937ar(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_e_state[625])
{
  uint32_T c1_u32[2];
  uint32_T c1_i;
  uint32_T c1_ip1;
  real_T c1_a;
  real_T c1_y;
  real_T c1_b_a;
  real_T c1_b_y;
  real_T c1_u;
  real_T c1_c_a;
  static real_T c1_dv3[257] = { 0.0, 0.215241895984875, 0.286174591792068,
    0.335737519214422, 0.375121332878378, 0.408389134611989, 0.43751840220787,
    0.46363433679088, 0.487443966139235, 0.50942332960209, 0.529909720661557,
    0.549151702327164, 0.567338257053817, 0.584616766106378, 0.601104617755991,
    0.61689699000775, 0.63207223638606, 0.646695714894993, 0.660822574244419,
    0.674499822837293, 0.687767892795788, 0.700661841106814, 0.713212285190975,
    0.725446140909999, 0.737387211434295, 0.749056662017815, 0.760473406430107,
    0.771654424224568, 0.782615023307232, 0.793369058840623, 0.80392911698997,
    0.814306670135215, 0.824512208752291, 0.834555354086381, 0.844444954909153,
    0.854189171008163, 0.863795545553308, 0.87327106808886, 0.882622229585165,
    0.891855070732941, 0.900975224461221, 0.909987953496718, 0.91889818364959,
    0.927710533401999, 0.936429340286575, 0.945058684468165, 0.953602409881086,
    0.96206414322304, 0.970447311064224, 0.978755155294224, 0.986990747099062,
    0.99515699963509, 1.00325667954467, 1.01129241744, 1.01926671746548,
    1.02718196603564, 1.03504043983344, 1.04284431314415, 1.05059566459093,
    1.05829648333067, 1.06594867476212, 1.07355406579244, 1.0811144097034,
    1.08863139065398, 1.09610662785202, 1.10354167942464, 1.11093804601357,
    1.11829717411934, 1.12562045921553, 1.13290924865253, 1.14016484436815,
    1.14738850542085, 1.15458145035993, 1.16174485944561, 1.16887987673083,
    1.17598761201545, 1.18306914268269, 1.19012551542669, 1.19715774787944,
    1.20416683014438, 1.2111537262437, 1.21811937548548, 1.22506469375653,
    1.23199057474614, 1.23889789110569, 1.24578749554863, 1.2526602218949,
    1.25951688606371, 1.26635828701823, 1.27318520766536, 1.27999841571382,
    1.28679866449324, 1.29358669373695, 1.30036323033084, 1.30712898903073,
    1.31388467315022, 1.32063097522106, 1.32736857762793, 1.33409815321936,
    1.3408203658964, 1.34753587118059, 1.35424531676263, 1.36094934303328,
    1.36764858359748, 1.37434366577317, 1.38103521107586, 1.38772383568998,
    1.39441015092814, 1.40109476367925, 1.4077782768464, 1.41446128977547,
    1.42114439867531, 1.42782819703026, 1.43451327600589, 1.44120022484872,
    1.44788963128058, 1.45458208188841, 1.46127816251028, 1.46797845861808,
    1.47468355569786, 1.48139403962819, 1.48811049705745, 1.49483351578049,
    1.50156368511546, 1.50830159628131, 1.51504784277671, 1.521803020761,
    1.52856772943771, 1.53534257144151, 1.542128153229, 1.54892508547417,
    1.55573398346918, 1.56255546753104, 1.56939016341512, 1.57623870273591,
    1.58310172339603, 1.58997987002419, 1.59687379442279, 1.60378415602609,
    1.61071162236983, 1.61765686957301, 1.62462058283303, 1.63160345693487,
    1.63860619677555, 1.64562951790478, 1.65267414708306, 1.65974082285818,
    1.66683029616166, 1.67394333092612, 1.68108070472517, 1.68824320943719,
    1.69543165193456, 1.70264685479992, 1.7098896570713, 1.71716091501782,
    1.72446150294804, 1.73179231405296, 1.73915426128591, 1.74654827828172,
    1.75397532031767, 1.76143636531891, 1.76893241491127, 1.77646449552452,
    1.78403365954944, 1.79164098655216, 1.79928758454972, 1.80697459135082,
    1.81470317596628, 1.82247454009388, 1.83028991968276, 1.83815058658281,
    1.84605785028518, 1.8540130597602, 1.86201760539967, 1.87007292107127,
    1.878180486293, 1.88634182853678, 1.8945585256707, 1.90283220855043,
    1.91116456377125, 1.91955733659319, 1.92801233405266, 1.93653142827569,
    1.94511656000868, 1.95376974238465, 1.96249306494436, 1.97128869793366,
    1.98015889690048, 1.98910600761744, 1.99813247135842, 2.00724083056053,
    2.0164337349062, 2.02571394786385, 2.03508435372962, 2.04454796521753,
    2.05410793165065, 2.06376754781173, 2.07353026351874, 2.0833996939983,
    2.09337963113879, 2.10347405571488, 2.11368715068665, 2.12402331568952,
    2.13448718284602, 2.14508363404789, 2.15581781987674, 2.16669518035431,
    2.17772146774029, 2.18890277162636, 2.20024554661128, 2.21175664288416,
    2.22344334009251, 2.23531338492992, 2.24737503294739, 2.25963709517379,
    2.27210899022838, 2.28480080272449, 2.29772334890286, 2.31088825060137,
    2.32430801887113, 2.33799614879653, 2.35196722737914, 2.36623705671729,
    2.38082279517208, 2.39574311978193, 2.41101841390112, 2.42667098493715,
    2.44272531820036, 2.4592083743347, 2.47614993967052, 2.49358304127105,
    2.51154444162669, 2.53007523215985, 2.54922155032478, 2.56903545268184,
    2.58957598670829, 2.61091051848882, 2.63311639363158, 2.65628303757674,
    2.68051464328574, 2.70593365612306, 2.73268535904401, 2.76094400527999,
    2.79092117400193, 2.82287739682644, 2.85713873087322, 2.89412105361341,
    2.93436686720889, 2.97860327988184, 3.02783779176959, 3.08352613200214,
    3.147889289518, 3.2245750520478, 3.32024473383983, 3.44927829856143,
    3.65415288536101, 3.91075795952492 };

  real_T c1_b;
  real_T c1_b_r;
  real_T c1_b_u;
  real_T c1_d_a;
  static real_T c1_dv4[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  real_T c1_b_b;
  real_T c1_c_y;
  real_T c1_c_b;
  real_T c1_d_y;
  real_T c1_e_a;
  real_T c1_d_b;
  real_T c1_e_y;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_u;
  real_T c1_f_a;
  real_T c1_c_x;
  real_T c1_d_u;
  real_T c1_e_b;
  real_T c1_f_y;
  real_T c1_g_a;
  real_T c1_f_b;
  real_T c1_g_y;
  int32_T exitg1;
  c1_assert_valid_state(chartInstance);
  do {
    exitg1 = 0;
    c1_b_genrand_uint32_vector(chartInstance, c1_e_state, c1_u32);
    c1_i = (c1_u32[1] >> 24U) + 1U;
    c1_ip1 = c1_i + 1U;
    c1_a = (real_T)(c1_u32[0] >> 3U);
    c1_y = c1_a * 1.6777216E+7;
    c1_b_a = c1_y + (real_T)(c1_u32[1] & 16777215U);
    c1_b_y = c1_b_a * 2.2204460492503131E-16;
    c1_u = c1_b_y - 1.0;
    c1_c_a = c1_u;
    c1_b = c1_dv3[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ip1), 1, 257, 1, 0) - 1];
    c1_b_r = c1_c_a * c1_b;
    if (c1_abs(chartInstance, c1_b_r) <= c1_dv3[(int32_T)(uint32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)(uint32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_i), 1, 257, 1, 0) - 1]) {
      exitg1 = 1;
    } else if ((real_T)c1_i < 256.0) {
      c1_b_u = c1_c_genrandu(chartInstance, c1_e_state);
      c1_u = c1_b_u;
      c1_d_a = c1_u;
      c1_b_b = c1_dv4[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_i), 1, 257, 1, 0) -
        1] - c1_dv4[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ip1), 1, 257, 1, 0) - 1];
      c1_c_y = c1_d_a * c1_b_b;
      c1_c_b = c1_b_r;
      c1_d_y = -0.5 * c1_c_b;
      c1_e_a = c1_d_y;
      c1_d_b = c1_b_r;
      c1_e_y = c1_e_a * c1_d_b;
      c1_x = c1_e_y;
      c1_b_x = c1_x;
      c1_b_x = muDoubleScalarExp(c1_b_x);
      if (c1_dv4[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ip1), 1, 257, 1, 0) - 1]
          + c1_c_y < c1_b_x) {
        exitg1 = 1;
      }
    } else {
      do {
        c1_c_u = c1_c_genrandu(chartInstance, c1_e_state);
        c1_u = c1_c_u;
        c1_f_a = muDoubleScalarLog(c1_u);
        c1_c_x = c1_f_a * 0.273661237329758;
        c1_d_u = c1_c_genrandu(chartInstance, c1_e_state);
        c1_u = c1_d_u;
        c1_e_b = muDoubleScalarLog(c1_u);
        c1_f_y = -2.0 * c1_e_b;
        c1_g_a = c1_c_x;
        c1_f_b = c1_c_x;
        c1_g_y = c1_g_a * c1_f_b;
      } while (!(c1_f_y > c1_g_y));

      if (c1_b_r < 0.0) {
        c1_b_r = c1_c_x - 3.65415288536101;
      } else {
        c1_b_r = 3.65415288536101 - c1_c_x;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c1_b_r;
}

static void c1_b_genrand_uint32_vector(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance, uint32_T c1_mt[625], uint32_T c1_u[2])
{
  int32_T c1_i38;
  int32_T c1_j;
  real_T c1_b_j;
  uint32_T c1_mti;
  int32_T c1_kk;
  real_T c1_b_kk;
  uint32_T c1_y;
  uint32_T c1_b_y;
  uint32_T c1_c_y;
  int32_T c1_c_kk;
  uint32_T c1_d_y;
  uint32_T c1_e_y;
  uint32_T c1_f_y;
  uint32_T c1_g_y;
  for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
    c1_u[c1_i38] = 0U;
  }

  for (c1_j = 0; c1_j < 2; c1_j++) {
    c1_b_j = 1.0 + (real_T)c1_j;
    c1_mti = c1_mt[624] + 1U;
    if ((real_T)c1_mti >= 625.0) {
      for (c1_kk = 0; c1_kk < 227; c1_kk++) {
        c1_b_kk = 1.0 + (real_T)c1_kk;
        c1_y = (c1_mt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                 _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] &
                2147483648U) | (c1_mt[(int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c1_b_kk + 1.0), 1, 625, 1, 0) - 1] & 2147483647U);
        c1_b_y = c1_y;
        c1_c_y = c1_b_y;
        if ((real_T)(c1_c_y & 1U) == 0.0) {
          c1_c_y >>= 1U;
        } else {
          c1_c_y = c1_c_y >> 1U ^ 2567483615U;
        }

        c1_mt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] = c1_mt[(int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c1_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c1_c_y;
      }

      for (c1_c_kk = 0; c1_c_kk < 396; c1_c_kk++) {
        c1_b_kk = 228.0 + (real_T)c1_c_kk;
        c1_y = (c1_mt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                 _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] &
                2147483648U) | (c1_mt[(int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c1_b_kk + 1.0), 1, 625, 1, 0) - 1] & 2147483647U);
        c1_d_y = c1_y;
        c1_e_y = c1_d_y;
        if ((real_T)(c1_e_y & 1U) == 0.0) {
          c1_e_y >>= 1U;
        } else {
          c1_e_y = c1_e_y >> 1U ^ 2567483615U;
        }

        c1_mt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] = c1_mt[(int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (c1_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^ c1_e_y;
      }

      c1_y = (c1_mt[623] & 2147483648U) | (c1_mt[0] & 2147483647U);
      c1_f_y = c1_y;
      c1_g_y = c1_f_y;
      if ((real_T)(c1_g_y & 1U) == 0.0) {
        c1_g_y >>= 1U;
      } else {
        c1_g_y = c1_g_y >> 1U ^ 2567483615U;
      }

      c1_mt[623] = c1_mt[396] ^ c1_g_y;
      c1_mti = 1U;
    }

    c1_y = c1_mt[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_mti), 1, 625, 1, 0) - 1];
    c1_mt[624] = c1_mti;
    c1_y ^= c1_y >> 11U;
    c1_y ^= c1_y << 7U & 2636928640U;
    c1_y ^= c1_y << 15U & 4022730752U;
    c1_y ^= c1_y >> 18U;
    c1_u[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_j), 1, 2, 1, 0) - 1] = c1_y;
  }
}

static real_T c1_c_genrandu(SFc1_BPSK_EmbeddedInstanceStruct *chartInstance,
  uint32_T c1_mt[625])
{
  real_T c1_r;
  uint32_T c1_u[2];
  real_T c1_a;
  real_T c1_y;
  real_T c1_b;
  boolean_T c1_b0;
  boolean_T c1_isvalid;
  int32_T c1_k;
  int32_T c1_b_a;
  real_T c1_d9;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  boolean_T exitg2;

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    exitg1 = 0;
    c1_b_genrand_uint32_vector(chartInstance, c1_mt, c1_u);
    c1_u[0] >>= 5U;
    c1_u[1] >>= 6U;
    c1_a = (real_T)c1_u[0];
    c1_y = c1_a * 6.7108864E+7;
    c1_b = c1_y + (real_T)c1_u[1];
    c1_r = 1.1102230246251565E-16 * c1_b;
    if (c1_r == 0.0) {
      guard1 = FALSE;
      if ((real_T)c1_mt[624] >= 1.0) {
        if ((real_T)c1_mt[624] < 625.0) {
          c1_b0 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c1_b0 = FALSE;
      }

      c1_isvalid = c1_b0;
      if (c1_isvalid) {
        c1_isvalid = FALSE;
        c1_k = 1;
        exitg2 = FALSE;
        while ((exitg2 == FALSE) && (c1_k < 625)) {
          if ((real_T)c1_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c1_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c1_b_a = c1_k + 1;
            c1_k = c1_b_a;
          } else {
            c1_isvalid = TRUE;
            exitg2 = TRUE;
          }
        }
      }

      if (!c1_isvalid) {
        c1_c_eml_error(chartInstance);
        c1_d9 = 5489.0;
        c1_b_twister_state_vector(chartInstance, c1_mt, c1_d9);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c1_r;
}

static void init_dsm_address_info(SFc1_BPSK_EmbeddedInstanceStruct
  *chartInstance)
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

void sf_c1_BPSK_Embedded_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(869110829U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2000250427U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(286790237U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3043863866U);
}

mxArray *sf_c1_BPSK_Embedded_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mUbDTzmrzScsUhxgJ0Kcf");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

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
      pr[0] = (double)(1000);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_BPSK_Embedded_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_BPSK_Embedded(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"E:/my_software/toolbox/eml/lib/matlab/randfun/eml_rand.m\"}}},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[638 644],M[1],T\"E:/my_software/toolbox/eml/lib/matlab/randfun/eml_randn.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"E:/my_software/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"E:/my_software/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"E:/my_software/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[645 650],M[1],T\"E:/my_software/toolbox/eml/lib/matlab/randfun/eml_randn.m\"}}},{M[8],M[0],T\"is_active_c1_BPSK_Embedded\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_BPSK_Embedded_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
    chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _BPSK_EmbeddedMachineNumber_,
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
          init_script_number_translation(_BPSK_EmbeddedMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_BPSK_EmbeddedMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _BPSK_EmbeddedMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Signal");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"EbNo");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,314);
        _SFD_CV_INIT_EML_FOR(0,1,0,218,228,308);
        _SFD_CV_INIT_EML_FOR(0,1,1,236,246,300);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 1000;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 1000;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_EbNo;
          real_T (*c1_Signal)[1000];
          real_T (*c1_y)[1000];
          c1_EbNo = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_y = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Signal = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_Signal);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_EbNo);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _BPSK_EmbeddedMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "36u2a68vB92szA9rmEZ9KD";
}

static void sf_opaque_initialize_c1_BPSK_Embedded(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_BPSK_EmbeddedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*)
    chartInstanceVar);
  initialize_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_BPSK_Embedded(void *chartInstanceVar)
{
  enable_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_BPSK_Embedded(void *chartInstanceVar)
{
  disable_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_BPSK_Embedded(void *chartInstanceVar)
{
  sf_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_BPSK_Embedded(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_BPSK_Embedded
    ((SFc1_BPSK_EmbeddedInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_BPSK_Embedded();/* state var info */
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

extern void sf_internal_set_sim_state_c1_BPSK_Embedded(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_BPSK_Embedded();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_BPSK_Embedded(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_BPSK_Embedded(S);
}

static void sf_opaque_set_sim_state_c1_BPSK_Embedded(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_BPSK_Embedded(S, st);
}

static void sf_opaque_terminate_c1_BPSK_Embedded(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_BPSK_EmbeddedInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_BPSK_Embedded_optimization_info();
    }

    finalize_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_BPSK_Embedded(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_BPSK_Embedded((SFc1_BPSK_EmbeddedInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_BPSK_Embedded(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BPSK_Embedded_optimization_info();
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
  ssSetChecksum0(S,(830409700U));
  ssSetChecksum1(S,(1968588682U));
  ssSetChecksum2(S,(3460781749U));
  ssSetChecksum3(S,(3284878969U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_BPSK_Embedded(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_BPSK_Embedded(SimStruct *S)
{
  SFc1_BPSK_EmbeddedInstanceStruct *chartInstance;
  chartInstance = (SFc1_BPSK_EmbeddedInstanceStruct *)utMalloc(sizeof
    (SFc1_BPSK_EmbeddedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_BPSK_EmbeddedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_BPSK_Embedded;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_BPSK_Embedded;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_BPSK_Embedded;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_BPSK_Embedded;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_BPSK_Embedded;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_BPSK_Embedded;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_BPSK_Embedded;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_BPSK_Embedded;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_BPSK_Embedded;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_BPSK_Embedded;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_BPSK_Embedded;
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

void c1_BPSK_Embedded_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_BPSK_Embedded(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_BPSK_Embedded(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_BPSK_Embedded(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_BPSK_Embedded_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
