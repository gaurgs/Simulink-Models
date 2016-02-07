/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ZFBD_sfun.h"
#include "c2_ZFBD.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ZFBD_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[32] = { "m", "n", "a1", "a2", "b1",
  "b2", "c1", "c2", "d1", "d2", "x", "z", "H1", "p", "q", "H2", "U1", "S1", "V1",
  "U2", "S2", "V2", "nargin", "nargout", "Data", "Nr", "Nt", "l3", "l4", "y",
  "l1", "l2" };

/* Function Declarations */
static void initialize_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void initialize_params_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void enable_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void disable_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_ZFBD(SFc2_ZFBDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_ZFBD(SFc2_ZFBDInstanceStruct
  *chartInstance);
static void set_sim_state_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_st);
static void finalize_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void sf_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void initSimStructsc2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void registerMessagesc2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_y, const char_T *c2_identifier, creal_T c2_b_y[40]);
static void c2_b_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[40]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_e_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_V1, const char_T *c2_identifier, creal_T c2_y[16]);
static void c2_f_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[16]);
static void c2_g_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_H1, const char_T *c2_identifier, creal_T c2_y[8]);
static void c2_h_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[8]);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ZFBD, const char_T *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_ZFBDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_ZFBD = 0U;
}

static void initialize_params_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
}

static void enable_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_ZFBD(SFc2_ZFBDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_ZFBD(SFc2_ZFBDInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  creal_T c2_u[16];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  creal_T c2_b_u[16];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  creal_T c2_c_u[8];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i3;
  creal_T c2_d_u[8];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i4;
  creal_T c2_e_u[40];
  const mxArray *c2_f_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  creal_T (*c2_h_y)[40];
  creal_T (*c2_l4)[8];
  creal_T (*c2_l3)[8];
  creal_T (*c2_l2)[16];
  creal_T (*c2_l1)[16];
  c2_l2 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_l1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_h_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_l4 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_l3 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(6), FALSE);
  for (c2_i0 = 0; c2_i0 < 16; c2_i0++) {
    c2_u[c2_i0] = (*c2_l1)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 1U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 16; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_l2)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 1U, 1U, 0U, 2, 4, 4),
                FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 8; c2_i2++) {
    c2_c_u[c2_i2] = (*c2_l3)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 1U, 1U, 0U, 2, 2, 4),
                FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i3 = 0; c2_i3 < 8; c2_i3++) {
    c2_d_u[c2_i3] = (*c2_l4)[c2_i3];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 0, 1U, 1U, 0U, 2, 2, 4),
                FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  for (c2_i4 = 0; c2_i4 < 40; c2_i4++) {
    c2_e_u[c2_i4] = (*c2_h_y)[c2_i4];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 0, 1U, 1U, 0U, 2, 4, 10),
                FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_ZFBD;
  c2_f_u = c2_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_st)
{
  const mxArray *c2_u;
  creal_T c2_dcv0[16];
  int32_T c2_i5;
  creal_T c2_dcv1[16];
  int32_T c2_i6;
  creal_T c2_dcv2[8];
  int32_T c2_i7;
  creal_T c2_dcv3[8];
  int32_T c2_i8;
  creal_T c2_dcv4[40];
  int32_T c2_i9;
  creal_T (*c2_l1)[16];
  creal_T (*c2_l2)[16];
  creal_T (*c2_l3)[8];
  creal_T (*c2_l4)[8];
  creal_T (*c2_y)[40];
  c2_l2 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_l1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_l4 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_l3 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "l1",
                        c2_dcv0);
  for (c2_i5 = 0; c2_i5 < 16; c2_i5++) {
    (*c2_l1)[c2_i5] = c2_dcv0[c2_i5];
  }

  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "l2",
                        c2_dcv1);
  for (c2_i6 = 0; c2_i6 < 16; c2_i6++) {
    (*c2_l2)[c2_i6] = c2_dcv1[c2_i6];
  }

  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)), "l3",
                        c2_dcv2);
  for (c2_i7 = 0; c2_i7 < 8; c2_i7++) {
    (*c2_l3)[c2_i7] = c2_dcv2[c2_i7];
  }

  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)), "l4",
                        c2_dcv3);
  for (c2_i8 = 0; c2_i8 < 8; c2_i8++) {
    (*c2_l4)[c2_i8] = c2_dcv3[c2_i8];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)), "y",
                      c2_dcv4);
  for (c2_i9 = 0; c2_i9 < 40; c2_i9++) {
    (*c2_y)[c2_i9] = c2_dcv4[c2_i9];
  }

  chartInstance->c2_is_active_c2_ZFBD = c2_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 5)), "is_active_c2_ZFBD");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ZFBD(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
}

static void sf_c2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  int32_T c2_i10;
  creal_T c2_Data[40];
  real_T c2_Nr;
  real_T c2_Nt;
  uint32_T c2_debug_family_var_map[32];
  real_T c2_m;
  real_T c2_n;
  real_T c2_a1[16];
  real_T c2_a2[16];
  real_T c2_b1[16];
  real_T c2_b2[16];
  real_T c2_c1[8];
  real_T c2_c2[8];
  real_T c2_d1[8];
  real_T c2_d2[8];
  const mxArray *c2_x = NULL;
  const mxArray *c2_z = NULL;
  const mxArray *c2_H1 = NULL;
  const mxArray *c2_p = NULL;
  const mxArray *c2_q = NULL;
  const mxArray *c2_H2 = NULL;
  const mxArray *c2_U1 = NULL;
  const mxArray *c2_S1 = NULL;
  const mxArray *c2_V1 = NULL;
  const mxArray *c2_U2 = NULL;
  const mxArray *c2_S2 = NULL;
  const mxArray *c2_V2 = NULL;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 5.0;
  creal_T c2_l3[8];
  creal_T c2_l4[8];
  creal_T c2_y[40];
  creal_T c2_l1[16];
  creal_T c2_l2[16];
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  const mxArray *c2_b_V1 = NULL;
  const mxArray *c2_b_S1 = NULL;
  const mxArray *c2_b_U1 = NULL;
  const mxArray *c2_b_V2 = NULL;
  const mxArray *c2_b_S2 = NULL;
  const mxArray *c2_b_U2 = NULL;
  creal_T c2_dcv5[16];
  int32_T c2_i23;
  creal_T c2_dcv6[16];
  int32_T c2_i24;
  creal_T c2_dcv7[8];
  int32_T c2_i25;
  creal_T c2_dcv8[8];
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  real_T *c2_b_Nt;
  real_T *c2_b_Nr;
  creal_T (*c2_b_l3)[8];
  creal_T (*c2_b_l4)[8];
  creal_T (*c2_l_y)[40];
  creal_T (*c2_b_l1)[16];
  creal_T (*c2_b_l2)[16];
  creal_T (*c2_b_Data)[40];
  c2_b_l2 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_b_Nt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Nr = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_l1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_Data = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
  c2_l_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_l4 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_l3 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_Nr, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Nt, 6U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_Nr;
  c2_b_hoistedGlobal = *c2_b_Nt;
  for (c2_i10 = 0; c2_i10 < 40; c2_i10++) {
    c2_Data[c2_i10] = (*c2_b_Data)[c2_i10];
  }

  c2_Nr = c2_hoistedGlobal;
  c2_Nt = c2_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 32U, 32U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_m, 0U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_n, 1U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_a1, 2U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_a2, 3U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b1, 4U, c2_g_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b2, 5U, c2_g_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_c1, 6U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_c2, 7U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_d1, 8U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_d2, 9U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_x, 10U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_z, 11U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_H1, 12U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_p, 13U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_q, 14U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_H2, 15U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_U1, 16U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_S1, 17U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_V1, 18U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_U2, 19U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_S2, 20U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_V2, 21U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 22U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 23U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Data, 24U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Nr, 25U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Nt, 26U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_l3, 27U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_l4, 28U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y, 29U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_l1, 30U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_l2, 31U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_m = 4.0;
  c2_n = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  for (c2_i11 = 0; c2_i11 < 16; c2_i11++) {
    c2_a1[c2_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  for (c2_i12 = 0; c2_i12 < 16; c2_i12++) {
    c2_a2[c2_i12] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  for (c2_i13 = 0; c2_i13 < 16; c2_i13++) {
    c2_l1[c2_i13].re = 0.0;
    c2_l1[c2_i13].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  for (c2_i14 = 0; c2_i14 < 16; c2_i14++) {
    c2_b1[c2_i14] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  for (c2_i15 = 0; c2_i15 < 16; c2_i15++) {
    c2_b2[c2_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  for (c2_i16 = 0; c2_i16 < 16; c2_i16++) {
    c2_l2[c2_i16].re = 0.0;
    c2_l2[c2_i16].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  for (c2_i17 = 0; c2_i17 < 8; c2_i17++) {
    c2_c1[c2_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  for (c2_i18 = 0; c2_i18 < 8; c2_i18++) {
    c2_c2[c2_i18] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  for (c2_i19 = 0; c2_i19 < 8; c2_i19++) {
    c2_l3[c2_i19].re = 0.0;
    c2_l3[c2_i19].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  for (c2_i20 = 0; c2_i20 < 8; c2_i20++) {
    c2_d1[c2_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  for (c2_i21 = 0; c2_i21 < 8; c2_i21++) {
    c2_d2[c2_i21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  for (c2_i22 = 0; c2_i22 < 8; c2_i22++) {
    c2_l4[c2_i22].re = 0.0;
    c2_l4[c2_i22].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_u = c2_Nr;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_b_u = c2_Nt;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_x, sf_mex_call_debug("randn", 1U, 2U, 14, c2_b_y, 14, c2_c_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_c_u = c2_Nr;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_d_u = c2_Nt;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_z, sf_mex_call_debug("randn", 1U, 2U, 14, c2_d_y, 14, c2_e_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_e_u = 1.4142135623730951;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_H1, sf_mex_call_debug("rdivide", 1U, 2U, 14,
    sf_mex_call_debug("complex", 1U, 2U, 14, sf_mex_dup(c2_x), 14, sf_mex_dup
                      (c2_z)), 14, c2_f_y), FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_f_u = c2_Nr;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_g_u = c2_Nt;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_p, sf_mex_call_debug("randn", 1U, 2U, 14, c2_g_y, 14, c2_h_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_h_u = c2_Nr;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_i_u = c2_Nt;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_q, sf_mex_call_debug("randn", 1U, 2U, 14, c2_i_y, 14, c2_j_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_j_u = 1.4142135623730951;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_H2, sf_mex_call_debug("rdivide", 1U, 2U, 14,
    sf_mex_call_debug("complex", 1U, 2U, 14, sf_mex_dup(c2_p), 14, sf_mex_dup
                      (c2_q)), 14, c2_k_y), FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  sf_mex_printf("%s =\\n", "H1");
  sf_mex_call_debug("disp", 0U, 1U, 14, sf_mex_dup(c2_H1));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  sf_mex_printf("%s =\\n", "H2");
  sf_mex_call_debug("disp", 0U, 1U, 14, sf_mex_dup(c2_H2));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  sf_mex_call_debug("svd", 3U, 1U, 14, sf_mex_dup(c2_H1), &c2_b_U1, &c2_b_S1,
                    &c2_b_V1);
  sf_mex_assign(&c2_U1, sf_mex_dup(c2_b_U1), FALSE);
  sf_mex_assign(&c2_S1, sf_mex_dup(c2_b_S1), FALSE);
  sf_mex_assign(&c2_V1, sf_mex_dup(c2_b_V1), FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  sf_mex_call_debug("svd", 3U, 1U, 14, sf_mex_dup(c2_H2), &c2_b_U2, &c2_b_S2,
                    &c2_b_V2);
  sf_mex_assign(&c2_U2, sf_mex_dup(c2_b_U2), FALSE);
  sf_mex_assign(&c2_S2, sf_mex_dup(c2_b_S2), FALSE);
  sf_mex_assign(&c2_V2, sf_mex_dup(c2_b_V2), FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  sf_mex_printf("%s =\\n", "V1");
  sf_mex_call_debug("disp", 0U, 1U, 14, sf_mex_dup(c2_V1));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  sf_mex_printf("%s =\\n", "V2");
  sf_mex_call_debug("disp", 0U, 1U, 14, sf_mex_dup(c2_V2));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_V1), "V1", c2_dcv5);
  for (c2_i23 = 0; c2_i23 < 16; c2_i23++) {
    c2_l1[c2_i23] = c2_dcv5[c2_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_V2), "V2", c2_dcv6);
  for (c2_i24 = 0; c2_i24 < 16; c2_i24++) {
    c2_l2[c2_i24] = c2_dcv6[c2_i24];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_H1), "H1", c2_dcv7);
  for (c2_i25 = 0; c2_i25 < 8; c2_i25++) {
    c2_l3[c2_i25] = c2_dcv7[c2_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_H2), "H2", c2_dcv8);
  for (c2_i26 = 0; c2_i26 < 8; c2_i26++) {
    c2_l4[c2_i26] = c2_dcv8[c2_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  for (c2_i27 = 0; c2_i27 < 40; c2_i27++) {
    c2_y[c2_i27] = c2_Data[c2_i27];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -53);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c2_x);
  sf_mex_destroy(&c2_z);
  sf_mex_destroy(&c2_H1);
  sf_mex_destroy(&c2_p);
  sf_mex_destroy(&c2_q);
  sf_mex_destroy(&c2_H2);
  sf_mex_destroy(&c2_U1);
  sf_mex_destroy(&c2_S1);
  sf_mex_destroy(&c2_V1);
  sf_mex_destroy(&c2_U2);
  sf_mex_destroy(&c2_S2);
  sf_mex_destroy(&c2_V2);
  sf_mex_destroy(&c2_b_U1);
  sf_mex_destroy(&c2_b_S1);
  sf_mex_destroy(&c2_b_V1);
  sf_mex_destroy(&c2_b_U2);
  sf_mex_destroy(&c2_b_S2);
  sf_mex_destroy(&c2_b_V2);
  for (c2_i28 = 0; c2_i28 < 8; c2_i28++) {
    (*c2_b_l3)[c2_i28] = c2_l3[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 8; c2_i29++) {
    (*c2_b_l4)[c2_i29] = c2_l4[c2_i29];
  }

  for (c2_i30 = 0; c2_i30 < 40; c2_i30++) {
    (*c2_l_y)[c2_i30] = c2_y[c2_i30];
  }

  for (c2_i31 = 0; c2_i31 < 16; c2_i31++) {
    (*c2_b_l1)[c2_i31] = c2_l1[c2_i31];
  }

  for (c2_i32 = 0; c2_i32 < 16; c2_i32++) {
    (*c2_b_l2)[c2_i32] = c2_l2[c2_i32];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ZFBDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_ZFBD(SFc2_ZFBDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  creal_T c2_b_inData[16];
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  creal_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i33 = 0;
  for (c2_i34 = 0; c2_i34 < 4; c2_i34++) {
    for (c2_i35 = 0; c2_i35 < 4; c2_i35++) {
      c2_b_inData[c2_i35 + c2_i33] = (*(creal_T (*)[16])c2_inData)[c2_i35 +
        c2_i33];
    }

    c2_i33 += 4;
  }

  c2_i36 = 0;
  for (c2_i37 = 0; c2_i37 < 4; c2_i37++) {
    for (c2_i38 = 0; c2_i38 < 4; c2_i38++) {
      c2_u[c2_i38 + c2_i36] = c2_b_inData[c2_i38 + c2_i36];
    }

    c2_i36 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 1U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_V1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  creal_T c2_y[16];
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_V1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_V1), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_V1);
  c2_i39 = 0;
  for (c2_i40 = 0; c2_i40 < 4; c2_i40++) {
    for (c2_i41 = 0; c2_i41 < 4; c2_i41++) {
      (*(creal_T (*)[16])c2_outData)[c2_i41 + c2_i39] = c2_y[c2_i41 + c2_i39];
    }

    c2_i39 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  creal_T c2_b_inData[40];
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  creal_T c2_u[40];
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i42 = 0;
  for (c2_i43 = 0; c2_i43 < 10; c2_i43++) {
    for (c2_i44 = 0; c2_i44 < 4; c2_i44++) {
      c2_b_inData[c2_i44 + c2_i42] = (*(creal_T (*)[40])c2_inData)[c2_i44 +
        c2_i42];
    }

    c2_i42 += 4;
  }

  c2_i45 = 0;
  for (c2_i46 = 0; c2_i46 < 10; c2_i46++) {
    for (c2_i47 = 0; c2_i47 < 4; c2_i47++) {
      c2_u[c2_i47 + c2_i45] = c2_b_inData[c2_i47 + c2_i45];
    }

    c2_i45 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 1U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_y, const char_T *c2_identifier, creal_T c2_b_y[40])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[40])
{
  creal_T c2_dcv9[40];
  int32_T c2_i48;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dcv9, 1, 0, 1U, 1, 0U, 2, 4,
                10);
  for (c2_i48 = 0; c2_i48 < 40; c2_i48++) {
    c2_y[c2_i48] = c2_dcv9[c2_i48];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  creal_T c2_b_y[40];
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  c2_i49 = 0;
  for (c2_i50 = 0; c2_i50 < 10; c2_i50++) {
    for (c2_i51 = 0; c2_i51 < 4; c2_i51++) {
      (*(creal_T (*)[40])c2_outData)[c2_i51 + c2_i49] = c2_b_y[c2_i51 + c2_i49];
    }

    c2_i49 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  creal_T c2_b_inData[8];
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  creal_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i52 = 0;
  for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
    for (c2_i54 = 0; c2_i54 < 2; c2_i54++) {
      c2_b_inData[c2_i54 + c2_i52] = (*(creal_T (*)[8])c2_inData)[c2_i54 +
        c2_i52];
    }

    c2_i52 += 2;
  }

  c2_i55 = 0;
  for (c2_i56 = 0; c2_i56 < 4; c2_i56++) {
    for (c2_i57 = 0; c2_i57 < 2; c2_i57++) {
      c2_u[c2_i57 + c2_i55] = c2_b_inData[c2_i57 + c2_i55];
    }

    c2_i55 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 1U, 1U, 0U, 2, 2, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_H1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  creal_T c2_y[8];
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_H1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_H1), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_H1);
  c2_i58 = 0;
  for (c2_i59 = 0; c2_i59 < 4; c2_i59++) {
    for (c2_i60 = 0; c2_i60 < 2; c2_i60++) {
      (*(creal_T (*)[8])c2_outData)[c2_i60 + c2_i58] = c2_y[c2_i60 + c2_i58];
    }

    c2_i58 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  const mxArray *c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = sf_mex_dup(*(const mxArray **)c2_inData);
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  real_T c2_b_inData[8];
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  real_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i61 = 0;
  for (c2_i62 = 0; c2_i62 < 4; c2_i62++) {
    for (c2_i63 = 0; c2_i63 < 2; c2_i63++) {
      c2_b_inData[c2_i63 + c2_i61] = (*(real_T (*)[8])c2_inData)[c2_i63 + c2_i61];
    }

    c2_i61 += 2;
  }

  c2_i64 = 0;
  for (c2_i65 = 0; c2_i65 < 4; c2_i65++) {
    for (c2_i66 = 0; c2_i66 < 2; c2_i66++) {
      c2_u[c2_i66 + c2_i64] = c2_b_inData[c2_i66 + c2_i64];
    }

    c2_i64 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  real_T c2_b_inData[16];
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i67 = 0;
  for (c2_i68 = 0; c2_i68 < 4; c2_i68++) {
    for (c2_i69 = 0; c2_i69 < 4; c2_i69++) {
      c2_b_inData[c2_i69 + c2_i67] = (*(real_T (*)[16])c2_inData)[c2_i69 +
        c2_i67];
    }

    c2_i67 += 4;
  }

  c2_i70 = 0;
  for (c2_i71 = 0; c2_i71 < 4; c2_i71++) {
    for (c2_i72 = 0; c2_i72 < 4; c2_i72++) {
      c2_u[c2_i72 + c2_i70] = c2_b_inData[c2_i72 + c2_i70];
    }

    c2_i70 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16])
{
  real_T c2_dv0[16];
  int32_T c2_i73;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv0, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i73 = 0; c2_i73 < 16; c2_i73++) {
    c2_y[c2_i73] = c2_dv0[c2_i73];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_b2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b2), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b2);
  c2_i74 = 0;
  for (c2_i75 = 0; c2_i75 < 4; c2_i75++) {
    for (c2_i76 = 0; c2_i76 < 4; c2_i76++) {
      (*(real_T (*)[16])c2_outData)[c2_i76 + c2_i74] = c2_y[c2_i76 + c2_i74];
    }

    c2_i74 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_ZFBD_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[5];
  c2_ResolvedFunctionInfo (*c2_b_info)[5];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i77;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[5])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "sqrt";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c2_b_info)[0].fileTimeLo = 1343817786U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c2_b_info)[1].name = "eml_error";
  (*c2_b_info)[1].dominantType = "char";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c2_b_info)[1].fileTimeLo = 1343817758U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c2_b_info)[2].name = "eml_scalar_sqrt";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  (*c2_b_info)[2].fileTimeLo = 1286806138U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "rdivide";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[3].fileTimeLo = 1346497788U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "svd";
  (*c2_b_info)[4].dominantType = "mxArray";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  (*c2_b_info)[4].fileTimeLo = 1286806232U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c2_i77 = 0; c2_i77 < 5; c2_i77++) {
    c2_r0 = &c2_info[c2_i77];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i77);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i77);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i77);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i77);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i77);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i77);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i77);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i77);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_e_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_V1, const char_T *c2_identifier, creal_T c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_V1), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_V1);
}

static void c2_f_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[16])
{
  creal_T c2_dcv10[16];
  int32_T c2_i78;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dcv10, 1, 0, 1U, 1, 0U, 2, 4,
                4);
  for (c2_i78 = 0; c2_i78 < 16; c2_i78++) {
    c2_y[c2_i78] = c2_dcv10[c2_i78];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_H1, const char_T *c2_identifier, creal_T c2_y[8])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_H1), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_H1);
}

static void c2_h_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[8])
{
  creal_T c2_dcv11[8];
  int32_T c2_i79;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dcv11, 1, 0, 1U, 1, 0U, 2, 2,
                4);
  for (c2_i79 = 0; c2_i79 < 8; c2_i79++) {
    c2_y[c2_i79] = c2_dcv11[c2_i79];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i80;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i80, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i80;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ZFBD, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_is_active_c2_ZFBD),
    &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_ZFBD);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_ZFBDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_ZFBDInstanceStruct *chartInstance)
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

void sf_c2_ZFBD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3344710271U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3851829970U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3805733050U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(80600834U);
}

mxArray *sf_c2_ZFBD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hcvzIcisy8lsmNUsQ2SWKE");
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(4);
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
      pr[0] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(10);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_ZFBD_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_ZFBD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"l1\",},{M[1],M[8],T\"l2\",},{M[1],M[10],T\"l3\",},{M[1],M[11],T\"l4\",},{M[1],M[9],T\"y\",},{M[8],M[0],T\"is_active_c2_ZFBD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ZFBD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ZFBDInstanceStruct *chartInstance;
    chartInstance = (SFc2_ZFBDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ZFBDMachineNumber_,
           2,
           1,
           1,
           8,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"l3");
          _SFD_SET_DATA_PROPS(1,2,0,1,"l4");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Data");
          _SFD_SET_DATA_PROPS(4,2,0,1,"l1");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Nr");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Nt");
          _SFD_SET_DATA_PROPS(7,2,0,1,"l2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1035);
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
          dimVector[0]= 2;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_Nr;
          real_T *c2_Nt;
          creal_T (*c2_l3)[8];
          creal_T (*c2_l4)[8];
          creal_T (*c2_y)[40];
          creal_T (*c2_Data)[40];
          creal_T (*c2_l1)[16];
          creal_T (*c2_l2)[16];
          c2_l2 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
          c2_Nt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_Nr = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_l1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 4);
          c2_Data = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
          c2_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_l4 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_l3 = (creal_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_l3);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_l4);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_y);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_Data);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_l1);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_Nr);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_Nt);
          _SFD_SET_DATA_VALUE_PTR(7U, *c2_l2);
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
  return "2bwo7BOpVaIg61wjA7sDtD";
}

static void sf_opaque_initialize_c2_ZFBD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ZFBDInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_ZFBD((SFc2_ZFBDInstanceStruct*) chartInstanceVar);
  initialize_c2_ZFBD((SFc2_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ZFBD(void *chartInstanceVar)
{
  enable_c2_ZFBD((SFc2_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ZFBD(void *chartInstanceVar)
{
  disable_c2_ZFBD((SFc2_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ZFBD(void *chartInstanceVar)
{
  sf_c2_ZFBD((SFc2_ZFBDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_ZFBD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_ZFBD((SFc2_ZFBDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ZFBD();/* state var info */
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

extern void sf_internal_set_sim_state_c2_ZFBD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ZFBD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_ZFBD((SFc2_ZFBDInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_ZFBD(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_ZFBD(S);
}

static void sf_opaque_set_sim_state_c2_ZFBD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_ZFBD(S, st);
}

static void sf_opaque_terminate_c2_ZFBD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ZFBDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ZFBD_optimization_info();
    }

    finalize_c2_ZFBD((SFc2_ZFBDInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_ZFBD((SFc2_ZFBDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ZFBD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ZFBD((SFc2_ZFBDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ZFBD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2951532202U));
  ssSetChecksum1(S,(4068722979U));
  ssSetChecksum2(S,(1238661417U));
  ssSetChecksum3(S,(2709894707U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ZFBD(SimStruct *S)
{
  SFc2_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc2_ZFBDInstanceStruct *)utMalloc(sizeof
    (SFc2_ZFBDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_ZFBDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_ZFBD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_ZFBD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_ZFBD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ZFBD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ZFBD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_ZFBD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_ZFBD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_ZFBD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ZFBD;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ZFBD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_ZFBD;
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

void c2_ZFBD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ZFBD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ZFBD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ZFBD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ZFBD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
