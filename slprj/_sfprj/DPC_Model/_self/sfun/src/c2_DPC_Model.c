/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DPC_Model_sfun.h"
#include "c2_DPC_Model.h"
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
static const char * c2_debug_family_names[28] = { "e", "d", "x", "z", "H1", "a1",
  "a2", "Q_temp", "b1", "b2", "R_temp", "c1", "c2", "L", "d1", "d2", "Q", "e1",
  "e2", "m", "nargin", "nargout", "xp", "Nuser", "Nt", "h1", "y", "l" };

/* Function Declarations */
static void initialize_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void initialize_params_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance);
static void enable_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void disable_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance);
static void set_sim_state_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void sf_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void c2_chartstep_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance);
static void initSimStructsc2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance);
static void registerMessagesc2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier, creal_T c2_b_y[40]);
static void c2_b_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[40]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[34]);
static void c2_eml_scalar_eg(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void c2_b_eml_scalar_eg(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void c2_eml_xgemm(SFc2_DPC_ModelInstanceStruct *chartInstance, int32_T
  c2_k, creal_T c2_A_data[3], int32_T c2_A_sizes[2], creal_T c2_B_data[30],
  int32_T c2_B_sizes[2], int32_T c2_ldb, creal_T c2_C[10]);
static void c2_c_eml_scalar_eg(SFc2_DPC_ModelInstanceStruct *chartInstance);
static void c2_d_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_Q_temp, const char_T *c2_identifier, creal_T c2_y[16]);
static void c2_e_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[16]);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_DPC_Model, const char_T *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_DPC_ModelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_DPC_Model = 0U;
}

static void initialize_params_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void enable_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
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
  creal_T c2_c_u[40];
  const mxArray *c2_d_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  creal_T (*c2_f_y)[40];
  creal_T (*c2_l)[16];
  creal_T (*c2_h1)[16];
  c2_l = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_f_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_h1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4), FALSE);
  for (c2_i0 = 0; c2_i0 < 16; c2_i0++) {
    c2_u[c2_i0] = (*c2_h1)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 1U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 16; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_l)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 1U, 1U, 0U, 2, 4, 4),
                FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 40; c2_i2++) {
    c2_c_u[c2_i2] = (*c2_f_y)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 1U, 1U, 0U, 2, 4, 10),
                FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_DPC_Model;
  c2_d_u = c2_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  creal_T c2_dcv0[16];
  int32_T c2_i3;
  creal_T c2_dcv1[16];
  int32_T c2_i4;
  creal_T c2_dcv2[40];
  int32_T c2_i5;
  creal_T (*c2_h1)[16];
  creal_T (*c2_l)[16];
  creal_T (*c2_y)[40];
  c2_l = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_h1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "h1",
                        c2_dcv0);
  for (c2_i3 = 0; c2_i3 < 16; c2_i3++) {
    (*c2_h1)[c2_i3] = c2_dcv0[c2_i3];
  }

  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "l",
                        c2_dcv1);
  for (c2_i4 = 0; c2_i4 < 16; c2_i4++) {
    (*c2_l)[c2_i4] = c2_dcv1[c2_i4];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)), "y",
                      c2_dcv2);
  for (c2_i5 = 0; c2_i5 < 40; c2_i5++) {
    (*c2_y)[c2_i5] = c2_dcv2[c2_i5];
  }

  chartInstance->c2_is_active_c2_DPC_Model = c2_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "is_active_c2_DPC_Model");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_DPC_Model(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
}

static void sf_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
  real_T *c2_Nuser;
  real_T *c2_Nt;
  c2_Nt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_Nuser = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_Nuser, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_Nt, 4U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_DPC_Model(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DPC_ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  int32_T c2_i6;
  creal_T c2_xp[40];
  real_T c2_Nuser;
  real_T c2_Nt;
  uint32_T c2_debug_family_var_map[28];
  real_T c2_e;
  real_T c2_d;
  const mxArray *c2_x = NULL;
  const mxArray *c2_z = NULL;
  const mxArray *c2_H1 = NULL;
  real_T c2_a1[16];
  real_T c2_a2[16];
  creal_T c2_Q_temp[16];
  real_T c2_b1[16];
  real_T c2_b2[16];
  creal_T c2_R_temp[16];
  real_T c2_c1[16];
  real_T c2_c2[16];
  creal_T c2_L[16];
  real_T c2_d1[16];
  real_T c2_d2[16];
  creal_T c2_Q[16];
  real_T c2_e1[40];
  real_T c2_e2[40];
  real_T c2_m;
  creal_T c2_b_x[40];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 3.0;
  creal_T c2_h1[16];
  creal_T c2_y[40];
  creal_T c2_l[16];
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
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
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
  int32_T c2_i23;
  const mxArray *c2_b_R_temp = NULL;
  const mxArray *c2_b_Q_temp = NULL;
  creal_T c2_dcv3[16];
  int32_T c2_i24;
  creal_T c2_dcv4[16];
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_b_m;
  real_T c2_d0;
  int32_T c2_i35;
  real_T c2_b_d1;
  int32_T c2_i36;
  int32_T c2_c_m;
  int32_T c2_A_sizes[2];
  int32_T c2_loop_ub;
  int32_T c2_i37;
  creal_T c2_A_data[3];
  creal_T c2_B;
  int32_T c2_A;
  int32_T c2_b_A;
  int32_T c2_c_A;
  int32_T c2_d_A;
  int32_T c2_b_loop_ub;
  int32_T c2_i38;
  creal_T c2_b_A_data;
  real_T c2_ar;
  real_T c2_ai;
  real_T c2_br;
  real_T c2_bi;
  real_T c2_brm;
  real_T c2_bim;
  real_T c2_s;
  real_T c2_b_d;
  real_T c2_nr;
  real_T c2_ni;
  real_T c2_sgnbr;
  real_T c2_sgnbi;
  int32_T c2_b_sizes[2];
  int32_T c2_i39;
  int32_T c2_c_loop_ub;
  int32_T c2_i40;
  creal_T c2_b_data[30];
  boolean_T c2_innerDimOk;
  boolean_T c2_b0;
  int32_T c2_i41;
  static char_T c2_cv0[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D', 'y',
    'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p', 'a',
    'n', 's', 'i', 'o', 'n' };

  char_T c2_f_u[45];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i42;
  static char_T c2_cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  char_T c2_g_u[21];
  const mxArray *c2_h_y = NULL;
  int32_T c2_i43;
  creal_T c2_i_y[10];
  int32_T c2_d_loop_ub;
  int32_T c2_i44;
  creal_T c2_c_A_data;
  int32_T c2_k;
  int32_T c2_b_A_sizes[2];
  int32_T c2_e_A;
  int32_T c2_f_A;
  int32_T c2_e_loop_ub;
  int32_T c2_i45;
  creal_T c2_d_A_data[3];
  int32_T c2_b_b_sizes[2];
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_f_loop_ub;
  int32_T c2_i46;
  creal_T c2_b_b_data[30];
  int32_T c2_d_m;
  int32_T c2_e_m;
  int32_T c2_i47;
  creal_T c2_c_x[10];
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  creal_T c2_a[16];
  int32_T c2_i53;
  creal_T c2_c_b[40];
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  creal_T c2_C[40];
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  creal_T c2_b_a;
  creal_T c2_dcv5[16];
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  real_T *c2_b_Nuser;
  real_T *c2_b_Nt;
  creal_T (*c2_b_h1)[16];
  creal_T (*c2_j_y)[40];
  creal_T (*c2_b_l)[16];
  creal_T (*c2_b_xp)[40];
  boolean_T guard1 = FALSE;
  c2_b_l = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_Nt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Nuser = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_j_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_xp = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_h1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_Nuser;
  c2_b_hoistedGlobal = *c2_b_Nt;
  for (c2_i6 = 0; c2_i6 < 40; c2_i6++) {
    c2_xp[c2_i6] = (*c2_b_xp)[c2_i6];
  }

  c2_Nuser = c2_hoistedGlobal;
  c2_Nt = c2_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 28U, 29U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_x, MAX_uint32_T, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_z, 3U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_H1, 4U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_a1, 5U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_a2, 6U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Q_temp, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b1, 8U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b2, 9U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R_temp, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_c1, 11U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_c2, 12U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_L, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_d1, 14U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_d2, 15U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Q, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_e1, 17U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_e2, 18U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_m, 19U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_x, MAX_uint32_T, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 20U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 21U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_xp, 22U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Nuser, 23U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Nt, 24U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_h1, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y, 26U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_l, 27U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_e = 4.0;
  c2_d = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_u = c2_Nuser;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_b_u = c2_Nt;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_x, sf_mex_call_debug("randn", 1U, 2U, 14, c2_b_y, 14, c2_c_y),
                FALSE);
  _SFD_SYMBOL_SWITCH(2U, 2U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_c_u = c2_Nuser;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_d_u = c2_Nt;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_z, sf_mex_call_debug("randn", 1U, 2U, 14, c2_d_y, 14, c2_e_y),
                FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_e_u = 1.4142135623730951;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_H1, sf_mex_call_debug("rdivide", 1U, 2U, 14,
    sf_mex_call_debug("complex", 1U, 2U, 14, sf_mex_dup(c2_x), 14, sf_mex_dup
                      (c2_z)), 14, c2_f_y), FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i7 = 0; c2_i7 < 16; c2_i7++) {
    c2_a1[c2_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i8 = 0; c2_i8 < 16; c2_i8++) {
    c2_a2[c2_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  for (c2_i9 = 0; c2_i9 < 16; c2_i9++) {
    c2_Q_temp[c2_i9].re = 0.0;
    c2_Q_temp[c2_i9].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  for (c2_i10 = 0; c2_i10 < 16; c2_i10++) {
    c2_b1[c2_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  for (c2_i11 = 0; c2_i11 < 16; c2_i11++) {
    c2_b2[c2_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  for (c2_i12 = 0; c2_i12 < 16; c2_i12++) {
    c2_R_temp[c2_i12].re = 0.0;
    c2_R_temp[c2_i12].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  for (c2_i13 = 0; c2_i13 < 16; c2_i13++) {
    c2_c1[c2_i13] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  for (c2_i14 = 0; c2_i14 < 16; c2_i14++) {
    c2_c2[c2_i14] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  for (c2_i15 = 0; c2_i15 < 16; c2_i15++) {
    c2_L[c2_i15].re = 0.0;
    c2_L[c2_i15].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  for (c2_i16 = 0; c2_i16 < 16; c2_i16++) {
    c2_d1[c2_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  for (c2_i17 = 0; c2_i17 < 16; c2_i17++) {
    c2_d2[c2_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  for (c2_i18 = 0; c2_i18 < 16; c2_i18++) {
    c2_Q[c2_i18].re = 0.0;
    c2_Q[c2_i18].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  for (c2_i19 = 0; c2_i19 < 40; c2_i19++) {
    c2_e1[c2_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  for (c2_i20 = 0; c2_i20 < 40; c2_i20++) {
    c2_e2[c2_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  for (c2_i21 = 0; c2_i21 < 40; c2_i21++) {
    c2_b_x[c2_i21].re = 0.0;
    c2_b_x[c2_i21].im = 0.0;
  }

  _SFD_SYMBOL_SWITCH(2U, 20U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  for (c2_i22 = 0; c2_i22 < 16; c2_i22++) {
    c2_h1[c2_i22].re = 0.0;
    c2_h1[c2_i22].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  for (c2_i23 = 0; c2_i23 < 16; c2_i23++) {
    c2_l[c2_i23].re = 0.0;
    c2_l[c2_i23].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  sf_mex_call_debug("qr", 2U, 1U, 14, sf_mex_call_debug("transpose", 1U, 1U, 14,
    sf_mex_dup(c2_H1)), &c2_b_Q_temp, &c2_b_R_temp);
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Q_temp), "Q_temp",
                        c2_dcv3);
  for (c2_i24 = 0; c2_i24 < 16; c2_i24++) {
    c2_Q_temp[c2_i24] = c2_dcv3[c2_i24];
  }

  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_R_temp), "R_temp",
                        c2_dcv4);
  for (c2_i25 = 0; c2_i25 < 16; c2_i25++) {
    c2_R_temp[c2_i25] = c2_dcv4[c2_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_i26 = 0;
  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    c2_i28 = 0;
    for (c2_i29 = 0; c2_i29 < 4; c2_i29++) {
      c2_L[c2_i29 + c2_i26].re = c2_R_temp[c2_i28 + c2_i27].re;
      c2_L[c2_i29 + c2_i26].im = -c2_R_temp[c2_i28 + c2_i27].im;
      c2_i28 += 4;
    }

    c2_i26 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
    c2_i32 = 0;
    for (c2_i33 = 0; c2_i33 < 4; c2_i33++) {
      c2_Q[c2_i33 + c2_i30].re = c2_Q_temp[c2_i32 + c2_i31].re;
      c2_Q[c2_i33 + c2_i30].im = -c2_Q_temp[c2_i32 + c2_i31].im;
      c2_i32 += 4;
    }

    c2_i30 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  for (c2_i34 = 0; c2_i34 < 40; c2_i34++) {
    c2_b_x[c2_i34] = c2_xp[c2_i34];
  }

  _SFD_SYMBOL_SWITCH(2U, 20U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_m = 2.0;
  c2_b_m = 0;
  while (c2_b_m < 3) {
    c2_m = 2.0 + (real_T)c2_b_m;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
    c2_d0 = c2_m - 1.0;
    c2_i35 = (int32_T)c2_d0;
    c2_b_d1 = c2_m - 1.0;
    c2_i36 = (int32_T)c2_b_d1;
    c2_c_m = (int32_T)c2_m - 1;
    c2_A_sizes[0] = 1;
    c2_A_sizes[1] = c2_i35;
    c2_loop_ub = c2_i35 - 1;
    for (c2_i37 = 0; c2_i37 <= c2_loop_ub; c2_i37++) {
      c2_A_data[c2_A_sizes[0] * c2_i37] = c2_L[c2_c_m + (c2_i37 << 2)];
    }

    c2_B = c2_L[((int32_T)c2_m + (((int32_T)c2_m - 1) << 2)) - 1];
    c2_A_sizes[0] = 1;
    c2_A_sizes[1];
    c2_A = c2_A_sizes[0];
    c2_b_A = c2_A_sizes[1];
    c2_c_A = c2_A_sizes[0];
    c2_d_A = c2_A_sizes[1];
    c2_b_loop_ub = c2_c_A * c2_d_A - 1;
    for (c2_i38 = 0; c2_i38 <= c2_b_loop_ub; c2_i38++) {
      c2_b_A_data = c2_A_data[c2_i38];
      c2_ar = c2_b_A_data.re;
      c2_ai = c2_b_A_data.im;
      c2_br = c2_B.re;
      c2_bi = c2_B.im;
      if (c2_bi == 0.0) {
        if (c2_ai == 0.0) {
          c2_A_data[c2_i38].re = c2_ar / c2_br;
          c2_A_data[c2_i38].im = 0.0;
        } else if (c2_ar == 0.0) {
          c2_A_data[c2_i38].re = 0.0;
          c2_A_data[c2_i38].im = c2_ai / c2_br;
        } else {
          c2_A_data[c2_i38].re = c2_ar / c2_br;
          c2_A_data[c2_i38].im = c2_ai / c2_br;
        }
      } else if (c2_br == 0.0) {
        if (c2_ar == 0.0) {
          c2_A_data[c2_i38].re = c2_ai / c2_bi;
          c2_A_data[c2_i38].im = 0.0;
        } else if (c2_ai == 0.0) {
          c2_A_data[c2_i38].re = 0.0;
          c2_A_data[c2_i38].im = -(c2_ar / c2_bi);
        } else {
          c2_A_data[c2_i38].re = c2_ai / c2_bi;
          c2_A_data[c2_i38].im = -(c2_ar / c2_bi);
        }
      } else {
        c2_brm = muDoubleScalarAbs(c2_br);
        c2_bim = muDoubleScalarAbs(c2_bi);
        if (c2_brm > c2_bim) {
          c2_s = c2_bi / c2_br;
          c2_b_d = c2_br + c2_s * c2_bi;
          c2_nr = c2_ar + c2_s * c2_ai;
          c2_ni = c2_ai - c2_s * c2_ar;
          c2_A_data[c2_i38].re = c2_nr / c2_b_d;
          c2_A_data[c2_i38].im = c2_ni / c2_b_d;
        } else if (c2_bim == c2_brm) {
          if (c2_br > 0.0) {
            c2_sgnbr = 0.5;
          } else {
            c2_sgnbr = -0.5;
          }

          if (c2_bi > 0.0) {
            c2_sgnbi = 0.5;
          } else {
            c2_sgnbi = -0.5;
          }

          c2_nr = c2_ar * c2_sgnbr + c2_ai * c2_sgnbi;
          c2_ni = c2_ai * c2_sgnbr - c2_ar * c2_sgnbi;
          c2_A_data[c2_i38].re = c2_nr / c2_brm;
          c2_A_data[c2_i38].im = c2_ni / c2_brm;
        } else {
          c2_s = c2_br / c2_bi;
          c2_b_d = c2_bi + c2_s * c2_br;
          c2_nr = c2_s * c2_ar + c2_ai;
          c2_ni = c2_s * c2_ai - c2_ar;
          c2_A_data[c2_i38].re = c2_nr / c2_b_d;
          c2_A_data[c2_i38].im = c2_ni / c2_b_d;
        }
      }
    }

    c2_b_sizes[0] = c2_i36;
    c2_b_sizes[1] = 10;
    for (c2_i39 = 0; c2_i39 < 10; c2_i39++) {
      c2_c_loop_ub = c2_i36 - 1;
      for (c2_i40 = 0; c2_i40 <= c2_c_loop_ub; c2_i40++) {
        c2_b_data[c2_i40 + c2_b_sizes[0] * c2_i39] = c2_b_x[c2_i40 + (c2_i39 <<
          2)];
      }
    }

    c2_innerDimOk = ((real_T)c2_A_sizes[1] == (real_T)c2_b_sizes[0]);
    if (!c2_innerDimOk) {
      c2_b0 = (c2_A_sizes[1] == 1);
      if (c2_b0) {
        for (c2_i41 = 0; c2_i41 < 45; c2_i41++) {
          c2_f_u[c2_i41] = c2_cv0[c2_i41];
        }

        c2_g_y = NULL;
        sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 10, 0U, 1U, 0U, 2, 1,
          45), FALSE);
        sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U,
          1U, 14, c2_g_y));
      } else {
        for (c2_i42 = 0; c2_i42 < 21; c2_i42++) {
          c2_g_u[c2_i42] = c2_cv1[c2_i42];
        }

        c2_h_y = NULL;
        sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_g_u, 10, 0U, 1U, 0U, 2, 1,
          21), FALSE);
        sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U,
          1U, 14, c2_h_y));
      }
    }

    guard1 = FALSE;
    if ((real_T)c2_A_sizes[1] == 1.0) {
      guard1 = TRUE;
    } else if ((real_T)c2_b_sizes[0] == 1.0) {
      guard1 = TRUE;
    } else {
      c2_k = (int32_T)(real_T)c2_A_sizes[1];
      c2_eml_scalar_eg(chartInstance);
      c2_eml_scalar_eg(chartInstance);
      c2_b_A_sizes[0] = 1;
      c2_b_A_sizes[1] = c2_A_sizes[1];
      c2_e_A = c2_b_A_sizes[0];
      c2_f_A = c2_b_A_sizes[1];
      c2_e_loop_ub = c2_A_sizes[0] * c2_A_sizes[1] - 1;
      for (c2_i45 = 0; c2_i45 <= c2_e_loop_ub; c2_i45++) {
        c2_d_A_data[c2_i45] = c2_A_data[c2_i45];
      }

      c2_b_b_sizes[0] = c2_b_sizes[0];
      c2_b_b_sizes[1] = 10;
      c2_b = c2_b_b_sizes[0];
      c2_b_b = c2_b_b_sizes[1];
      c2_f_loop_ub = c2_b_sizes[0] * c2_b_sizes[1] - 1;
      for (c2_i46 = 0; c2_i46 <= c2_f_loop_ub; c2_i46++) {
        c2_b_b_data[c2_i46] = c2_b_data[c2_i46];
      }

      c2_eml_xgemm(chartInstance, c2_k, c2_d_A_data, c2_b_A_sizes, c2_b_b_data,
                   c2_b_b_sizes, c2_k, c2_i_y);
    }

    if (guard1 == TRUE) {
      for (c2_i43 = 0; c2_i43 < 10; c2_i43++) {
        c2_i_y[c2_i43].re = 0.0;
        c2_i_y[c2_i43].im = 0.0;
        c2_d_loop_ub = c2_A_sizes[1] - 1;
        for (c2_i44 = 0; c2_i44 <= c2_d_loop_ub; c2_i44++) {
          c2_c_A_data.re = c2_A_data[c2_A_sizes[0] * c2_i44].re *
            c2_b_data[c2_i44 + c2_b_sizes[0] * c2_i43].re -
            c2_A_data[c2_A_sizes[0] * c2_i44].im * c2_b_data[c2_i44 +
            c2_b_sizes[0] * c2_i43].im;
          c2_c_A_data.im = c2_A_data[c2_A_sizes[0] * c2_i44].re *
            c2_b_data[c2_i44 + c2_b_sizes[0] * c2_i43].im +
            c2_A_data[c2_A_sizes[0] * c2_i44].im * c2_b_data[c2_i44 +
            c2_b_sizes[0] * c2_i43].re;
          c2_i_y[c2_i43].re += c2_c_A_data.re;
          c2_i_y[c2_i43].im += c2_c_A_data.im;
        }
      }
    }

    c2_d_m = (int32_T)c2_m - 1;
    c2_e_m = (int32_T)c2_m - 1;
    for (c2_i47 = 0; c2_i47 < 10; c2_i47++) {
      c2_c_x[c2_i47].re = c2_b_x[c2_e_m + (c2_i47 << 2)].re - c2_i_y[c2_i47].re;
      c2_c_x[c2_i47].im = c2_b_x[c2_e_m + (c2_i47 << 2)].im - c2_i_y[c2_i47].im;
    }

    for (c2_i48 = 0; c2_i48 < 10; c2_i48++) {
      c2_b_x[c2_d_m + (c2_i48 << 2)] = c2_c_x[c2_i48];
    }

    _SFD_SYMBOL_SWITCH(2U, 20U);
    c2_b_m++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_i49 = 0;
  for (c2_i50 = 0; c2_i50 < 4; c2_i50++) {
    c2_i51 = 0;
    for (c2_i52 = 0; c2_i52 < 4; c2_i52++) {
      c2_a[c2_i52 + c2_i49].re = c2_Q[c2_i51 + c2_i50].re;
      c2_a[c2_i52 + c2_i49].im = -c2_Q[c2_i51 + c2_i50].im;
      c2_i51 += 4;
    }

    c2_i49 += 4;
  }

  for (c2_i53 = 0; c2_i53 < 40; c2_i53++) {
    c2_c_b[c2_i53] = c2_b_x[c2_i53];
  }

  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i54 = 0; c2_i54 < 40; c2_i54++) {
    c2_y[c2_i54].re = 0.0;
    c2_y[c2_i54].im = 0.0;
  }

  for (c2_i55 = 0; c2_i55 < 40; c2_i55++) {
    c2_y[c2_i55].re = 0.0;
    c2_y[c2_i55].im = 0.0;
  }

  for (c2_i56 = 0; c2_i56 < 40; c2_i56++) {
    c2_C[c2_i56] = c2_y[c2_i56];
  }

  for (c2_i57 = 0; c2_i57 < 40; c2_i57++) {
    c2_y[c2_i57] = c2_C[c2_i57];
  }

  for (c2_i58 = 0; c2_i58 < 40; c2_i58++) {
    c2_C[c2_i58] = c2_y[c2_i58];
  }

  for (c2_i59 = 0; c2_i59 < 40; c2_i59++) {
    c2_y[c2_i59] = c2_C[c2_i59];
  }

  for (c2_i60 = 0; c2_i60 < 4; c2_i60++) {
    c2_i61 = 0;
    for (c2_i62 = 0; c2_i62 < 10; c2_i62++) {
      c2_y[c2_i61 + c2_i60].re = 0.0;
      c2_y[c2_i61 + c2_i60].im = 0.0;
      c2_i63 = 0;
      for (c2_i64 = 0; c2_i64 < 4; c2_i64++) {
        c2_b_a.re = c2_a[c2_i63 + c2_i60].re * c2_c_b[c2_i64 + c2_i61].re -
          c2_a[c2_i63 + c2_i60].im * c2_c_b[c2_i64 + c2_i61].im;
        c2_b_a.im = c2_a[c2_i63 + c2_i60].re * c2_c_b[c2_i64 + c2_i61].im +
          c2_a[c2_i63 + c2_i60].im * c2_c_b[c2_i64 + c2_i61].re;
        c2_y[c2_i61 + c2_i60].re += c2_b_a.re;
        c2_y[c2_i61 + c2_i60].im += c2_b_a.im;
        c2_i63 += 4;
      }

      c2_i61 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_H1), "H1", c2_dcv5);
  for (c2_i65 = 0; c2_i65 < 16; c2_i65++) {
    c2_h1[c2_i65] = c2_dcv5[c2_i65];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
  for (c2_i66 = 0; c2_i66 < 16; c2_i66++) {
    c2_l[c2_i66] = c2_L[c2_i66];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -41);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c2_x);
  sf_mex_destroy(&c2_z);
  sf_mex_destroy(&c2_H1);
  sf_mex_destroy(&c2_b_Q_temp);
  sf_mex_destroy(&c2_b_R_temp);
  for (c2_i67 = 0; c2_i67 < 16; c2_i67++) {
    (*c2_b_h1)[c2_i67] = c2_h1[c2_i67];
  }

  for (c2_i68 = 0; c2_i68 < 40; c2_i68++) {
    (*c2_j_y)[c2_i68] = c2_y[c2_i68];
  }

  for (c2_i69 = 0; c2_i69 < 16; c2_i69++) {
    (*c2_b_l)[c2_i69] = c2_l[c2_i69];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_DPC_Model(SFc2_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  creal_T c2_b_inData[16];
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  creal_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i70 = 0;
  for (c2_i71 = 0; c2_i71 < 4; c2_i71++) {
    for (c2_i72 = 0; c2_i72 < 4; c2_i72++) {
      c2_b_inData[c2_i72 + c2_i70] = (*(creal_T (*)[16])c2_inData)[c2_i72 +
        c2_i70];
    }

    c2_i70 += 4;
  }

  c2_i73 = 0;
  for (c2_i74 = 0; c2_i74 < 4; c2_i74++) {
    for (c2_i75 = 0; c2_i75 < 4; c2_i75++) {
      c2_u[c2_i75 + c2_i73] = c2_b_inData[c2_i75 + c2_i73];
    }

    c2_i73 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 1U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Q_temp;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  creal_T c2_y[16];
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_Q_temp = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Q_temp), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Q_temp);
  c2_i76 = 0;
  for (c2_i77 = 0; c2_i77 < 4; c2_i77++) {
    for (c2_i78 = 0; c2_i78 < 4; c2_i78++) {
      (*(creal_T (*)[16])c2_outData)[c2_i78 + c2_i76] = c2_y[c2_i78 + c2_i76];
    }

    c2_i76 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  creal_T c2_b_inData[40];
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  creal_T c2_u[40];
  const mxArray *c2_y = NULL;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i79 = 0;
  for (c2_i80 = 0; c2_i80 < 10; c2_i80++) {
    for (c2_i81 = 0; c2_i81 < 4; c2_i81++) {
      c2_b_inData[c2_i81 + c2_i79] = (*(creal_T (*)[40])c2_inData)[c2_i81 +
        c2_i79];
    }

    c2_i79 += 4;
  }

  c2_i82 = 0;
  for (c2_i83 = 0; c2_i83 < 10; c2_i83++) {
    for (c2_i84 = 0; c2_i84 < 4; c2_i84++) {
      c2_u[c2_i84 + c2_i82] = c2_b_inData[c2_i84 + c2_i82];
    }

    c2_i82 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 1U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier, creal_T c2_b_y[40])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[40])
{
  creal_T c2_dcv6[40];
  int32_T c2_i85;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dcv6, 1, 0, 1U, 1, 0U, 2, 4,
                10);
  for (c2_i85 = 0; c2_i85 < 40; c2_i85++) {
    c2_y[c2_i85] = c2_dcv6[c2_i85];
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
  int32_T c2_i86;
  int32_T c2_i87;
  int32_T c2_i88;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  c2_i86 = 0;
  for (c2_i87 = 0; c2_i87 < 10; c2_i87++) {
    for (c2_i88 = 0; c2_i88 < 4; c2_i88++) {
      (*(creal_T (*)[40])c2_outData)[c2_i88 + c2_i86] = c2_b_y[c2_i88 + c2_i86];
    }

    c2_i86 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  real_T c2_b_inData[40];
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  real_T c2_u[40];
  const mxArray *c2_y = NULL;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i89 = 0;
  for (c2_i90 = 0; c2_i90 < 10; c2_i90++) {
    for (c2_i91 = 0; c2_i91 < 4; c2_i91++) {
      c2_b_inData[c2_i91 + c2_i89] = (*(real_T (*)[40])c2_inData)[c2_i91 +
        c2_i89];
    }

    c2_i89 += 4;
  }

  c2_i92 = 0;
  for (c2_i93 = 0; c2_i93 < 10; c2_i93++) {
    for (c2_i94 = 0; c2_i94 < 4; c2_i94++) {
      c2_u[c2_i94 + c2_i92] = c2_b_inData[c2_i94 + c2_i92];
    }

    c2_i92 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  real_T c2_b_inData[16];
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i100;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i95 = 0;
  for (c2_i96 = 0; c2_i96 < 4; c2_i96++) {
    for (c2_i97 = 0; c2_i97 < 4; c2_i97++) {
      c2_b_inData[c2_i97 + c2_i95] = (*(real_T (*)[16])c2_inData)[c2_i97 +
        c2_i95];
    }

    c2_i95 += 4;
  }

  c2_i98 = 0;
  for (c2_i99 = 0; c2_i99 < 4; c2_i99++) {
    for (c2_i100 = 0; c2_i100 < 4; c2_i100++) {
      c2_u[c2_i100 + c2_i98] = c2_b_inData[c2_i100 + c2_i98];
    }

    c2_i98 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  const mxArray *c2_u;
  const mxArray *c2_y = NULL;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = sf_mex_dup(*(const mxArray **)c2_inData);
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_DPC_Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[34];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i101;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 34), FALSE);
  for (c2_i101 = 0; c2_i101 < 34; c2_i101++) {
    c2_r0 = &c2_info[c2_i101];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i101);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i101);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i101);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i101);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i101);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i101);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i101);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i101);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[34])
{
  c2_info[0].context = "";
  c2_info[0].name = "sqrt";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[0].fileTimeLo = 1343817786U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[1].name = "eml_error";
  c2_info[1].dominantType = "char";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[1].fileTimeLo = 1343817758U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[2].name = "eml_scalar_sqrt";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[2].fileTimeLo = 1286806138U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "rdivide";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[3].fileTimeLo = 1346497788U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "qr";
  c2_info[4].dominantType = "mxArray";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/qr.m";
  c2_info[4].fileTimeLo = 1302676396U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "mrdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].fileTimeLo = 1357935348U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 1319717366U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileTimeLo = 1346497788U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "eml_scalexp_compatible";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[7].fileTimeLo = 1286806196U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].name = "eml_div";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[8].fileTimeLo = 1313335210U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[9].name = "eml_scalar_eg";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[9].fileTimeLo = 1286806196U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[10].name = "eml_scalexp_alloc";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[10].fileTimeLo = 1352408660U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[11].name = "abs";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[11].fileTimeLo = 1343817766U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[12].name = "eml_scalar_abs";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[12].fileTimeLo = 1286806112U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[13].name = "mtimes";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].fileTimeLo = 1289503492U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "mtimes";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[14].fileTimeLo = 1289503492U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].name = "eml_index_class";
  c2_info[15].dominantType = "";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[15].fileTimeLo = 1323154378U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[16].name = "eml_scalar_eg";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[16].fileTimeLo = 1286806196U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[17].name = "eml_xgemm";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[17].fileTimeLo = 1299060572U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[18].name = "eml_blas_inline";
  c2_info[18].dominantType = "";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[18].fileTimeLo = 1299060568U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[19].name = "eml_index_class";
  c2_info[19].dominantType = "";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[19].fileTimeLo = 1323154378U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[20].name = "eml_scalar_eg";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[20].fileTimeLo = 1286806196U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[21].name = "eml_refblas_xgemm";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[21].fileTimeLo = 1299060574U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[22].name = "eml_index_minus";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[22].fileTimeLo = 1286806178U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[23].name = "eml_index_class";
  c2_info[23].dominantType = "";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[23].fileTimeLo = 1323154378U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[24].name = "eml_index_class";
  c2_info[24].dominantType = "";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[24].fileTimeLo = 1323154378U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[25].name = "eml_scalar_eg";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[25].fileTimeLo = 1286806196U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[26].name = "eml_index_times";
  c2_info[26].dominantType = "coder.internal.indexInt";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[26].fileTimeLo = 1286806180U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[27].name = "eml_index_class";
  c2_info[27].dominantType = "";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[27].fileTimeLo = 1323154378U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[28].name = "eml_index_plus";
  c2_info[28].dominantType = "coder.internal.indexInt";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[28].fileTimeLo = 1286806178U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[29].name = "eml_index_class";
  c2_info[29].dominantType = "";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[29].fileTimeLo = 1323154378U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[30].name = "eml_int_forloop_overflow_check";
  c2_info[30].dominantType = "";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[30].fileTimeLo = 1346497740U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[31].name = "intmax";
  c2_info[31].dominantType = "char";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[31].fileTimeLo = 1311242716U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[32].name = "eml_index_plus";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[32].fileTimeLo = 1286806178U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[33].name = "mtimes";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[33].fileTimeLo = 1289503492U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
}

static void c2_b_eml_scalar_eg(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
}

static void c2_eml_xgemm(SFc2_DPC_ModelInstanceStruct *chartInstance, int32_T
  c2_k, creal_T c2_A_data[3], int32_T c2_A_sizes[2], creal_T c2_B_data[30],
  int32_T c2_B_sizes[2], int32_T c2_ldb, creal_T c2_C[10])
{
  int32_T c2_b_k;
  int32_T c2_b_ldb;
  int32_T c2_i102;
  int32_T c2_c_k;
  int32_T c2_c_ldb;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  int32_T c2_var;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  int32_T c2_b_var;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  static creal_T c2_alpha1 = { 1.0, 0.0 };

  double * c2_alpha1_t;
  double * c2_Aia0_t;
  double * c2_Bib0_t;
  static creal_T c2_beta1 = { 0.0, 0.0 };

  double * c2_beta1_t;
  double * c2_Cic0_t;
  c2_b_k = c2_k;
  c2_b_ldb = c2_ldb;
  for (c2_i102 = 0; c2_i102 < 10; c2_i102++) {
    c2_C[c2_i102].re = 0.0;
    c2_C[c2_i102].im = 0.0;
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_c_k = c2_b_k;
  c2_c_ldb = c2_b_ldb;
  c2_TRANSB = 'N';
  c2_TRANSA = 'N';
  c2_m_t = (ptrdiff_t)(1);
  c2_n_t = (ptrdiff_t)(10);
  c2_var = c2_c_k;
  c2_k_t = (ptrdiff_t)(c2_var);
  c2_lda_t = (ptrdiff_t)(1);
  c2_b_var = c2_c_ldb;
  c2_ldb_t = (ptrdiff_t)(c2_b_var);
  c2_ldc_t = (ptrdiff_t)(1);
  c2_alpha1_t = (double *)(&c2_alpha1);
  c2_Aia0_t = (double *)(&c2_A_data[0]);
  c2_Bib0_t = (double *)(&c2_B_data[0]);
  c2_beta1_t = (double *)(&c2_beta1);
  c2_Cic0_t = (double *)(&c2_C[0]);
  zgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, c2_alpha1_t,
        c2_Aia0_t, &c2_lda_t, c2_Bib0_t, &c2_ldb_t, c2_beta1_t, c2_Cic0_t,
        &c2_ldc_t);
}

static void c2_c_eml_scalar_eg(SFc2_DPC_ModelInstanceStruct *chartInstance)
{
}

static void c2_d_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_Q_temp, const char_T *c2_identifier, creal_T c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Q_temp), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Q_temp);
}

static void c2_e_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, creal_T c2_y[16])
{
  creal_T c2_dcv7[16];
  int32_T c2_i103;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dcv7, 1, 0, 1U, 1, 0U, 2, 4, 4);
  for (c2_i103 = 0; c2_i103 < 16; c2_i103++) {
    c2_y[c2_i103] = c2_dcv7[c2_i103];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i104;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i104, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i104;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_DPC_Model, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_DPC_Model), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_DPC_Model);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_DPC_ModelInstanceStruct *chartInstance)
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

void sf_c2_DPC_Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4209668460U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3538755615U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3449245820U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1350622922U);
}

mxArray *sf_c2_DPC_Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("R9zHw3RlV7CfcXvejLMrqF");
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
      pr[1] = (double)(10);
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
      pr[1] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_DPC_Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_DPC_Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[8],T\"h1\",},{M[1],M[10],T\"l\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_DPC_Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_DPC_Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_DPC_ModelInstanceStruct *chartInstance;
    chartInstance = (SFc2_DPC_ModelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DPC_ModelMachineNumber_,
           2,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"h1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"xp");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Nuser");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Nt");
          _SFD_SET_DATA_PROPS(5,2,0,1,"l");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,837);
        _SFD_CV_INIT_EML_FOR(0,1,0,717,727,812);
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
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_Nuser;
          real_T *c2_Nt;
          creal_T (*c2_h1)[16];
          creal_T (*c2_xp)[40];
          creal_T (*c2_y)[40];
          creal_T (*c2_l)[16];
          c2_l = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_Nt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_Nuser = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_xp = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 0);
          c2_h1 = (creal_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_h1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_xp);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_Nuser);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_Nt);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_l);
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
  return "utx4Kt6RXbOHPS3SVQ4fTF";
}

static void sf_opaque_initialize_c2_DPC_Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*)
    chartInstanceVar);
  initialize_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_DPC_Model(void *chartInstanceVar)
{
  enable_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_DPC_Model(void *chartInstanceVar)
{
  disable_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_DPC_Model(void *chartInstanceVar)
{
  sf_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_DPC_Model(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_DPC_Model();/* state var info */
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

extern void sf_internal_set_sim_state_c2_DPC_Model(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_DPC_Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_DPC_Model(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_DPC_Model(S);
}

static void sf_opaque_set_sim_state_c2_DPC_Model(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_DPC_Model(S, st);
}

static void sf_opaque_terminate_c2_DPC_Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DPC_Model_optimization_info();
    }

    finalize_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_DPC_Model((SFc2_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_DPC_Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_DPC_Model((SFc2_DPC_ModelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DPC_Model_optimization_info();
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
        infoStruct,2,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
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
  ssSetChecksum0(S,(3207166344U));
  ssSetChecksum1(S,(3430911890U));
  ssSetChecksum2(S,(2849597146U));
  ssSetChecksum3(S,(1875687012U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_DPC_Model(SimStruct *S)
{
  SFc2_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc2_DPC_ModelInstanceStruct *)utMalloc(sizeof
    (SFc2_DPC_ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_DPC_ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_DPC_Model;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_DPC_Model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_DPC_Model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_DPC_Model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_DPC_Model;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_DPC_Model;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_DPC_Model;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_DPC_Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_DPC_Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_DPC_Model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_DPC_Model;
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

void c2_DPC_Model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_DPC_Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_DPC_Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_DPC_Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_DPC_Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
