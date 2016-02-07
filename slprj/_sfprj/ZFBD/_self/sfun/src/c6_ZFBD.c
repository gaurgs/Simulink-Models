/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ZFBD_sfun.h"
#include "c6_ZFBD.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ZFBD_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[14] = { "a1", "a2", "w2_h2", "b1",
  "b2", "EQ2", "c1", "c2", "nargin", "nargout", "rx2", "h2", "w2", "yr2" };

/* Function Declarations */
static void initialize_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void initialize_params_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void enable_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void disable_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_ZFBD(SFc6_ZFBDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_ZFBD(SFc6_ZFBDInstanceStruct
  *chartInstance);
static void set_sim_state_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_st);
static void finalize_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void sf_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void c6_chartstep_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void initSimStructsc6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void registerMessagesc6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_yr2, const char_T *c6_identifier, creal_T c6_y[20]);
static void c6_b_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, creal_T c6_y[20]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, creal_T c6_y[4]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[37]);
static void c6_eml_scalar_eg(SFc6_ZFBDInstanceStruct *chartInstance);
static void c6_b_eml_scalar_eg(SFc6_ZFBDInstanceStruct *chartInstance);
static void c6_inv(SFc6_ZFBDInstanceStruct *chartInstance, creal_T c6_x[4],
                   creal_T c6_y[4]);
static void c6_inv2x2(SFc6_ZFBDInstanceStruct *chartInstance, creal_T c6_x[4],
                      creal_T c6_y[4]);
static real_T c6_norm(SFc6_ZFBDInstanceStruct *chartInstance, creal_T c6_x[4]);
static void c6_eml_warning(SFc6_ZFBDInstanceStruct *chartInstance);
static void c6_b_eml_warning(SFc6_ZFBDInstanceStruct *chartInstance, char_T
  c6_varargin_2[14]);
static void c6_c_eml_scalar_eg(SFc6_ZFBDInstanceStruct *chartInstance);
static void c6_e_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_sprintf, const char_T *c6_identifier, char_T c6_y[14]);
static void c6_f_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, char_T c6_y[14]);
static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_g_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_h_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_ZFBD, const char_T *c6_identifier);
static uint8_T c6_i_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_ZFBDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_ZFBD = 0U;
}

static void initialize_params_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
}

static void enable_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_ZFBD(SFc6_ZFBDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_ZFBD(SFc6_ZFBDInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  creal_T c6_u[20];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  creal_T (*c6_yr2)[20];
  c6_yr2 = (creal_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2), FALSE);
  for (c6_i0 = 0; c6_i0 < 20; c6_i0++) {
    c6_u[c6_i0] = (*c6_yr2)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 1U, 1U, 0U, 2, 2, 10),
                FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_ZFBD;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_st)
{
  const mxArray *c6_u;
  creal_T c6_dcv0[20];
  int32_T c6_i1;
  creal_T (*c6_yr2)[20];
  c6_yr2 = (creal_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "yr2",
                      c6_dcv0);
  for (c6_i1 = 0; c6_i1 < 20; c6_i1++) {
    (*c6_yr2)[c6_i1] = c6_dcv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_ZFBD = c6_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 1)), "is_active_c6_ZFBD");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_ZFBD(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
}

static void sf_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_ZFBD(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ZFBDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  creal_T c6_rx2[20];
  int32_T c6_i3;
  creal_T c6_h2[8];
  int32_T c6_i4;
  creal_T c6_w2[8];
  uint32_T c6_debug_family_var_map[14];
  real_T c6_a1[4];
  real_T c6_a2[4];
  creal_T c6_w2_h2[4];
  real_T c6_b1[4];
  real_T c6_b2[4];
  creal_T c6_EQ2[4];
  real_T c6_c1[20];
  real_T c6_c2[20];
  real_T c6_nargin = 3.0;
  real_T c6_nargout = 1.0;
  creal_T c6_yr2[20];
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  creal_T c6_a[8];
  int32_T c6_i15;
  creal_T c6_b[8];
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  creal_T c6_C[4];
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  creal_T c6_b_a;
  int32_T c6_i28;
  creal_T c6_c_a[4];
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  creal_T c6_b_b[4];
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  creal_T c6_d_a;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  int32_T c6_i41;
  int32_T c6_i42;
  creal_T c6_b_C[4];
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  int32_T c6_i47;
  int32_T c6_i48;
  int32_T c6_i49;
  int32_T c6_i50;
  int32_T c6_i51;
  int32_T c6_i52;
  int32_T c6_i53;
  creal_T c6_e_a;
  int32_T c6_i54;
  int32_T c6_i55;
  creal_T c6_c_b[20];
  int32_T c6_i56;
  int32_T c6_i57;
  int32_T c6_i58;
  creal_T c6_c_C[20];
  int32_T c6_i59;
  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  int32_T c6_i63;
  int32_T c6_i64;
  int32_T c6_i65;
  int32_T c6_i66;
  creal_T c6_f_a;
  int32_T c6_i67;
  creal_T (*c6_b_yr2)[20];
  creal_T (*c6_b_w2)[8];
  creal_T (*c6_b_h2)[8];
  creal_T (*c6_b_rx2)[20];
  c6_b_w2 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_h2 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_yr2 = (creal_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_rx2 = (creal_T (*)[20])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 20; c6_i2++) {
    c6_rx2[c6_i2] = (*c6_b_rx2)[c6_i2];
  }

  for (c6_i3 = 0; c6_i3 < 8; c6_i3++) {
    c6_h2[c6_i3] = (*c6_b_h2)[c6_i3];
  }

  for (c6_i4 = 0; c6_i4 < 8; c6_i4++) {
    c6_w2[c6_i4] = (*c6_b_w2)[c6_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_a1, 0U, c6_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_a2, 1U, c6_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_w2_h2, 2U, c6_f_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b1, 3U, c6_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b2, 4U, c6_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_EQ2, 5U, c6_f_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_c1, 6U, c6_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_c2, 7U, c6_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 8U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 9U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_rx2, 10U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_h2, 11U, c6_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_w2, 12U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_yr2, 13U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  for (c6_i5 = 0; c6_i5 < 4; c6_i5++) {
    c6_a1[c6_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  for (c6_i6 = 0; c6_i6 < 4; c6_i6++) {
    c6_a2[c6_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  for (c6_i7 = 0; c6_i7 < 4; c6_i7++) {
    c6_w2_h2[c6_i7].re = 0.0;
    c6_w2_h2[c6_i7].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  for (c6_i8 = 0; c6_i8 < 4; c6_i8++) {
    c6_b1[c6_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  for (c6_i9 = 0; c6_i9 < 4; c6_i9++) {
    c6_b2[c6_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i10 = 0; c6_i10 < 4; c6_i10++) {
    c6_EQ2[c6_i10].re = 0.0;
    c6_EQ2[c6_i10].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i11 = 0; c6_i11 < 20; c6_i11++) {
    c6_c1[c6_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  for (c6_i12 = 0; c6_i12 < 20; c6_i12++) {
    c6_c2[c6_i12] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  for (c6_i13 = 0; c6_i13 < 20; c6_i13++) {
    c6_yr2[c6_i13].re = 0.0;
    c6_yr2[c6_i13].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
  for (c6_i14 = 0; c6_i14 < 8; c6_i14++) {
    c6_a[c6_i14] = c6_h2[c6_i14];
  }

  for (c6_i15 = 0; c6_i15 < 8; c6_i15++) {
    c6_b[c6_i15] = c6_w2[c6_i15];
  }

  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i16 = 0; c6_i16 < 4; c6_i16++) {
    c6_w2_h2[c6_i16].re = 0.0;
    c6_w2_h2[c6_i16].im = 0.0;
  }

  for (c6_i17 = 0; c6_i17 < 4; c6_i17++) {
    c6_w2_h2[c6_i17].re = 0.0;
    c6_w2_h2[c6_i17].im = 0.0;
  }

  for (c6_i18 = 0; c6_i18 < 4; c6_i18++) {
    c6_C[c6_i18] = c6_w2_h2[c6_i18];
  }

  for (c6_i19 = 0; c6_i19 < 4; c6_i19++) {
    c6_w2_h2[c6_i19] = c6_C[c6_i19];
  }

  for (c6_i20 = 0; c6_i20 < 4; c6_i20++) {
    c6_C[c6_i20] = c6_w2_h2[c6_i20];
  }

  for (c6_i21 = 0; c6_i21 < 4; c6_i21++) {
    c6_w2_h2[c6_i21] = c6_C[c6_i21];
  }

  for (c6_i22 = 0; c6_i22 < 2; c6_i22++) {
    c6_i23 = 0;
    c6_i24 = 0;
    for (c6_i25 = 0; c6_i25 < 2; c6_i25++) {
      c6_w2_h2[c6_i23 + c6_i22].re = 0.0;
      c6_w2_h2[c6_i23 + c6_i22].im = 0.0;
      c6_i26 = 0;
      for (c6_i27 = 0; c6_i27 < 4; c6_i27++) {
        c6_b_a.re = c6_a[c6_i26 + c6_i22].re * c6_b[c6_i27 + c6_i24].re -
          c6_a[c6_i26 + c6_i22].im * c6_b[c6_i27 + c6_i24].im;
        c6_b_a.im = c6_a[c6_i26 + c6_i22].re * c6_b[c6_i27 + c6_i24].im +
          c6_a[c6_i26 + c6_i22].im * c6_b[c6_i27 + c6_i24].re;
        c6_w2_h2[c6_i23 + c6_i22].re += c6_b_a.re;
        c6_w2_h2[c6_i23 + c6_i22].im += c6_b_a.im;
        c6_i26 += 2;
      }

      c6_i23 += 2;
      c6_i24 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
  for (c6_i28 = 0; c6_i28 < 4; c6_i28++) {
    c6_c_a[c6_i28] = c6_w2_h2[c6_i28];
  }

  c6_i29 = 0;
  for (c6_i30 = 0; c6_i30 < 2; c6_i30++) {
    c6_i31 = 0;
    for (c6_i32 = 0; c6_i32 < 2; c6_i32++) {
      c6_b_b[c6_i32 + c6_i29].re = c6_w2_h2[c6_i31 + c6_i30].re;
      c6_b_b[c6_i32 + c6_i29].im = -c6_w2_h2[c6_i31 + c6_i30].im;
      c6_i31 += 2;
    }

    c6_i29 += 2;
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i33 = 0; c6_i33 < 2; c6_i33++) {
    c6_i34 = 0;
    for (c6_i35 = 0; c6_i35 < 2; c6_i35++) {
      c6_C[c6_i34 + c6_i33].re = 0.0;
      c6_C[c6_i34 + c6_i33].im = 0.0;
      c6_i36 = 0;
      for (c6_i37 = 0; c6_i37 < 2; c6_i37++) {
        c6_d_a.re = c6_c_a[c6_i36 + c6_i33].re * c6_b_b[c6_i37 + c6_i34].re -
          c6_c_a[c6_i36 + c6_i33].im * c6_b_b[c6_i37 + c6_i34].im;
        c6_d_a.im = c6_c_a[c6_i36 + c6_i33].re * c6_b_b[c6_i37 + c6_i34].im +
          c6_c_a[c6_i36 + c6_i33].im * c6_b_b[c6_i37 + c6_i34].re;
        c6_C[c6_i34 + c6_i33].re += c6_d_a.re;
        c6_C[c6_i34 + c6_i33].im += c6_d_a.im;
        c6_i36 += 2;
      }

      c6_i34 += 2;
    }
  }

  c6_i38 = 0;
  for (c6_i39 = 0; c6_i39 < 2; c6_i39++) {
    c6_i40 = 0;
    for (c6_i41 = 0; c6_i41 < 2; c6_i41++) {
      c6_c_a[c6_i41 + c6_i38].re = c6_w2_h2[c6_i40 + c6_i39].re;
      c6_c_a[c6_i41 + c6_i38].im = -c6_w2_h2[c6_i40 + c6_i39].im;
      c6_i40 += 2;
    }

    c6_i38 += 2;
  }

  for (c6_i42 = 0; c6_i42 < 4; c6_i42++) {
    c6_b_C[c6_i42] = c6_C[c6_i42];
  }

  c6_inv(chartInstance, c6_b_C, c6_b_b);
  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i43 = 0; c6_i43 < 4; c6_i43++) {
    c6_EQ2[c6_i43].re = 0.0;
    c6_EQ2[c6_i43].im = 0.0;
  }

  for (c6_i44 = 0; c6_i44 < 4; c6_i44++) {
    c6_EQ2[c6_i44].re = 0.0;
    c6_EQ2[c6_i44].im = 0.0;
  }

  for (c6_i45 = 0; c6_i45 < 4; c6_i45++) {
    c6_C[c6_i45] = c6_EQ2[c6_i45];
  }

  for (c6_i46 = 0; c6_i46 < 4; c6_i46++) {
    c6_EQ2[c6_i46] = c6_C[c6_i46];
  }

  for (c6_i47 = 0; c6_i47 < 4; c6_i47++) {
    c6_C[c6_i47] = c6_EQ2[c6_i47];
  }

  for (c6_i48 = 0; c6_i48 < 4; c6_i48++) {
    c6_EQ2[c6_i48] = c6_C[c6_i48];
  }

  for (c6_i49 = 0; c6_i49 < 2; c6_i49++) {
    c6_i50 = 0;
    for (c6_i51 = 0; c6_i51 < 2; c6_i51++) {
      c6_EQ2[c6_i50 + c6_i49].re = 0.0;
      c6_EQ2[c6_i50 + c6_i49].im = 0.0;
      c6_i52 = 0;
      for (c6_i53 = 0; c6_i53 < 2; c6_i53++) {
        c6_e_a.re = c6_c_a[c6_i52 + c6_i49].re * c6_b_b[c6_i53 + c6_i50].re -
          c6_c_a[c6_i52 + c6_i49].im * c6_b_b[c6_i53 + c6_i50].im;
        c6_e_a.im = c6_c_a[c6_i52 + c6_i49].re * c6_b_b[c6_i53 + c6_i50].im +
          c6_c_a[c6_i52 + c6_i49].im * c6_b_b[c6_i53 + c6_i50].re;
        c6_EQ2[c6_i50 + c6_i49].re += c6_e_a.re;
        c6_EQ2[c6_i50 + c6_i49].im += c6_e_a.im;
        c6_i52 += 2;
      }

      c6_i50 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 17);
  for (c6_i54 = 0; c6_i54 < 4; c6_i54++) {
    c6_c_a[c6_i54] = c6_EQ2[c6_i54];
  }

  for (c6_i55 = 0; c6_i55 < 20; c6_i55++) {
    c6_c_b[c6_i55] = c6_rx2[c6_i55];
  }

  c6_c_eml_scalar_eg(chartInstance);
  c6_c_eml_scalar_eg(chartInstance);
  for (c6_i56 = 0; c6_i56 < 20; c6_i56++) {
    c6_yr2[c6_i56].re = 0.0;
    c6_yr2[c6_i56].im = 0.0;
  }

  for (c6_i57 = 0; c6_i57 < 20; c6_i57++) {
    c6_yr2[c6_i57].re = 0.0;
    c6_yr2[c6_i57].im = 0.0;
  }

  for (c6_i58 = 0; c6_i58 < 20; c6_i58++) {
    c6_c_C[c6_i58] = c6_yr2[c6_i58];
  }

  for (c6_i59 = 0; c6_i59 < 20; c6_i59++) {
    c6_yr2[c6_i59] = c6_c_C[c6_i59];
  }

  for (c6_i60 = 0; c6_i60 < 20; c6_i60++) {
    c6_c_C[c6_i60] = c6_yr2[c6_i60];
  }

  for (c6_i61 = 0; c6_i61 < 20; c6_i61++) {
    c6_yr2[c6_i61] = c6_c_C[c6_i61];
  }

  for (c6_i62 = 0; c6_i62 < 2; c6_i62++) {
    c6_i63 = 0;
    for (c6_i64 = 0; c6_i64 < 10; c6_i64++) {
      c6_yr2[c6_i63 + c6_i62].re = 0.0;
      c6_yr2[c6_i63 + c6_i62].im = 0.0;
      c6_i65 = 0;
      for (c6_i66 = 0; c6_i66 < 2; c6_i66++) {
        c6_f_a.re = c6_c_a[c6_i65 + c6_i62].re * c6_c_b[c6_i66 + c6_i63].re -
          c6_c_a[c6_i65 + c6_i62].im * c6_c_b[c6_i66 + c6_i63].im;
        c6_f_a.im = c6_c_a[c6_i65 + c6_i62].re * c6_c_b[c6_i66 + c6_i63].im +
          c6_c_a[c6_i65 + c6_i62].im * c6_c_b[c6_i66 + c6_i63].re;
        c6_yr2[c6_i63 + c6_i62].re += c6_f_a.re;
        c6_yr2[c6_i63 + c6_i62].im += c6_f_a.im;
        c6_i65 += 2;
      }

      c6_i63 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i67 = 0; c6_i67 < 20; c6_i67++) {
    (*c6_b_yr2)[c6_i67] = c6_yr2[c6_i67];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
}

static void registerMessagesc6_ZFBD(SFc6_ZFBDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i68;
  int32_T c6_i69;
  int32_T c6_i70;
  creal_T c6_b_inData[20];
  int32_T c6_i71;
  int32_T c6_i72;
  int32_T c6_i73;
  creal_T c6_u[20];
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i68 = 0;
  for (c6_i69 = 0; c6_i69 < 10; c6_i69++) {
    for (c6_i70 = 0; c6_i70 < 2; c6_i70++) {
      c6_b_inData[c6_i70 + c6_i68] = (*(creal_T (*)[20])c6_inData)[c6_i70 +
        c6_i68];
    }

    c6_i68 += 2;
  }

  c6_i71 = 0;
  for (c6_i72 = 0; c6_i72 < 10; c6_i72++) {
    for (c6_i73 = 0; c6_i73 < 2; c6_i73++) {
      c6_u[c6_i73 + c6_i71] = c6_b_inData[c6_i73 + c6_i71];
    }

    c6_i71 += 2;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 1U, 1U, 0U, 2, 2, 10), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_yr2, const char_T *c6_identifier, creal_T c6_y[20])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_yr2), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_yr2);
}

static void c6_b_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, creal_T c6_y[20])
{
  creal_T c6_dcv1[20];
  int32_T c6_i74;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dcv1, 1, 0, 1U, 1, 0U, 2, 2,
                10);
  for (c6_i74 = 0; c6_i74 < 20; c6_i74++) {
    c6_y[c6_i74] = c6_dcv1[c6_i74];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_yr2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  creal_T c6_y[20];
  int32_T c6_i75;
  int32_T c6_i76;
  int32_T c6_i77;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_yr2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_yr2), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_yr2);
  c6_i75 = 0;
  for (c6_i76 = 0; c6_i76 < 10; c6_i76++) {
    for (c6_i77 = 0; c6_i77 < 2; c6_i77++) {
      (*(creal_T (*)[20])c6_outData)[c6_i77 + c6_i75] = c6_y[c6_i77 + c6_i75];
    }

    c6_i75 += 2;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i78;
  int32_T c6_i79;
  int32_T c6_i80;
  creal_T c6_b_inData[8];
  int32_T c6_i81;
  int32_T c6_i82;
  int32_T c6_i83;
  creal_T c6_u[8];
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i78 = 0;
  for (c6_i79 = 0; c6_i79 < 2; c6_i79++) {
    for (c6_i80 = 0; c6_i80 < 4; c6_i80++) {
      c6_b_inData[c6_i80 + c6_i78] = (*(creal_T (*)[8])c6_inData)[c6_i80 +
        c6_i78];
    }

    c6_i78 += 4;
  }

  c6_i81 = 0;
  for (c6_i82 = 0; c6_i82 < 2; c6_i82++) {
    for (c6_i83 = 0; c6_i83 < 4; c6_i83++) {
      c6_u[c6_i83 + c6_i81] = c6_b_inData[c6_i83 + c6_i81];
    }

    c6_i81 += 4;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 1U, 1U, 0U, 2, 4, 2), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i84;
  int32_T c6_i85;
  int32_T c6_i86;
  creal_T c6_b_inData[8];
  int32_T c6_i87;
  int32_T c6_i88;
  int32_T c6_i89;
  creal_T c6_u[8];
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i84 = 0;
  for (c6_i85 = 0; c6_i85 < 4; c6_i85++) {
    for (c6_i86 = 0; c6_i86 < 2; c6_i86++) {
      c6_b_inData[c6_i86 + c6_i84] = (*(creal_T (*)[8])c6_inData)[c6_i86 +
        c6_i84];
    }

    c6_i84 += 2;
  }

  c6_i87 = 0;
  for (c6_i88 = 0; c6_i88 < 4; c6_i88++) {
    for (c6_i89 = 0; c6_i89 < 2; c6_i89++) {
      c6_u[c6_i89 + c6_i87] = c6_b_inData[c6_i89 + c6_i87];
    }

    c6_i87 += 2;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 1U, 1U, 0U, 2, 2, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i90;
  int32_T c6_i91;
  int32_T c6_i92;
  real_T c6_b_inData[20];
  int32_T c6_i93;
  int32_T c6_i94;
  int32_T c6_i95;
  real_T c6_u[20];
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i90 = 0;
  for (c6_i91 = 0; c6_i91 < 10; c6_i91++) {
    for (c6_i92 = 0; c6_i92 < 2; c6_i92++) {
      c6_b_inData[c6_i92 + c6_i90] = (*(real_T (*)[20])c6_inData)[c6_i92 +
        c6_i90];
    }

    c6_i90 += 2;
  }

  c6_i93 = 0;
  for (c6_i94 = 0; c6_i94 < 10; c6_i94++) {
    for (c6_i95 = 0; c6_i95 < 2; c6_i95++) {
      c6_u[c6_i95 + c6_i93] = c6_b_inData[c6_i95 + c6_i93];
    }

    c6_i93 += 2;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 2, 10), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i96;
  int32_T c6_i97;
  int32_T c6_i98;
  creal_T c6_b_inData[4];
  int32_T c6_i99;
  int32_T c6_i100;
  int32_T c6_i101;
  creal_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i96 = 0;
  for (c6_i97 = 0; c6_i97 < 2; c6_i97++) {
    for (c6_i98 = 0; c6_i98 < 2; c6_i98++) {
      c6_b_inData[c6_i98 + c6_i96] = (*(creal_T (*)[4])c6_inData)[c6_i98 +
        c6_i96];
    }

    c6_i96 += 2;
  }

  c6_i99 = 0;
  for (c6_i100 = 0; c6_i100 < 2; c6_i100++) {
    for (c6_i101 = 0; c6_i101 < 2; c6_i101++) {
      c6_u[c6_i101 + c6_i99] = c6_b_inData[c6_i101 + c6_i99];
    }

    c6_i99 += 2;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 1U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, creal_T c6_y[4])
{
  creal_T c6_dcv2[4];
  int32_T c6_i102;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dcv2, 1, 0, 1U, 1, 0U, 2, 2, 2);
  for (c6_i102 = 0; c6_i102 < 4; c6_i102++) {
    c6_y[c6_i102] = c6_dcv2[c6_i102];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_EQ2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  creal_T c6_y[4];
  int32_T c6_i103;
  int32_T c6_i104;
  int32_T c6_i105;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_EQ2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_EQ2), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_EQ2);
  c6_i103 = 0;
  for (c6_i104 = 0; c6_i104 < 2; c6_i104++) {
    for (c6_i105 = 0; c6_i105 < 2; c6_i105++) {
      (*(creal_T (*)[4])c6_outData)[c6_i105 + c6_i103] = c6_y[c6_i105 + c6_i103];
    }

    c6_i103 += 2;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i106;
  int32_T c6_i107;
  int32_T c6_i108;
  real_T c6_b_inData[4];
  int32_T c6_i109;
  int32_T c6_i110;
  int32_T c6_i111;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i106 = 0;
  for (c6_i107 = 0; c6_i107 < 2; c6_i107++) {
    for (c6_i108 = 0; c6_i108 < 2; c6_i108++) {
      c6_b_inData[c6_i108 + c6_i106] = (*(real_T (*)[4])c6_inData)[c6_i108 +
        c6_i106];
    }

    c6_i106 += 2;
  }

  c6_i109 = 0;
  for (c6_i110 = 0; c6_i110 < 2; c6_i110++) {
    for (c6_i111 = 0; c6_i111 < 2; c6_i111++) {
      c6_u[c6_i111 + c6_i109] = c6_b_inData[c6_i111 + c6_i109];
    }

    c6_i109 += 2;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

const mxArray *sf_c6_ZFBD_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[37];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i112;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 37), FALSE);
  for (c6_i112 = 0; c6_i112 < 37; c6_i112++) {
    c6_r0 = &c6_info[c6_i112];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i112);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i112);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i112);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i112);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i112);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i112);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i112);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i112);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[37])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileTimeLo = 1289503492U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[1].name = "eml_index_class";
  c6_info[1].dominantType = "";
  c6_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[1].fileTimeLo = 1323154378U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[2].name = "eml_scalar_eg";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[2].fileTimeLo = 1286806196U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[3].name = "eml_xgemm";
  c6_info[3].dominantType = "char";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[3].fileTimeLo = 1299060572U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[4].name = "eml_blas_inline";
  c6_info[4].dominantType = "";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[4].fileTimeLo = 1299060568U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c6_info[5].name = "mtimes";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[5].fileTimeLo = 1289503492U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[6].name = "eml_index_class";
  c6_info[6].dominantType = "";
  c6_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[6].fileTimeLo = 1323154378U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[7].name = "eml_scalar_eg";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[7].fileTimeLo = 1286806196U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[8].name = "eml_refblas_xgemm";
  c6_info[8].dominantType = "char";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[8].fileTimeLo = 1299060574U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context = "";
  c6_info[9].name = "inv";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c6_info[9].fileTimeLo = 1305305400U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c6_info[10].name = "eml_xcabs1";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c6_info[10].fileTimeLo = 1286806106U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c6_info[11].name = "abs";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[11].fileTimeLo = 1343817766U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[12].name = "eml_scalar_abs";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[12].fileTimeLo = 1286806112U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c6_info[13].name = "mrdivide";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[13].fileTimeLo = 1357935348U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 1319717366U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[14].name = "rdivide";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[14].fileTimeLo = 1346497788U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[15].name = "eml_scalexp_compatible";
  c6_info[15].dominantType = "double";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c6_info[15].fileTimeLo = 1286806196U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[16].name = "eml_div";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[16].fileTimeLo = 1313335210U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c6_info[17].name = "eml_scalar_eg";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[17].fileTimeLo = 1286806196U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c6_info[18].name = "eml_scalexp_alloc";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[18].fileTimeLo = 1352408660U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c6_info[19].name = "abs";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[19].fileTimeLo = 1343817766U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c6_info[20].name = "mtimes";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[20].fileTimeLo = 1289503492U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c6_info[21].name = "mtimes";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[21].fileTimeLo = 1289503492U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c6_info[22].name = "norm";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c6_info[22].fileTimeLo = 1336509494U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 0U;
  c6_info[22].mFileTimeHi = 0U;
  c6_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c6_info[23].name = "abs";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[23].fileTimeLo = 1343817766U;
  c6_info[23].fileTimeHi = 0U;
  c6_info[23].mFileTimeLo = 0U;
  c6_info[23].mFileTimeHi = 0U;
  c6_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[24].name = "eml_dlapy2";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c6_info[24].fileTimeLo = 1350398054U;
  c6_info[24].fileTimeHi = 0U;
  c6_info[24].mFileTimeLo = 0U;
  c6_info[24].mFileTimeHi = 0U;
  c6_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c6_info[25].name = "isnan";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[25].fileTimeLo = 1286806160U;
  c6_info[25].fileTimeHi = 0U;
  c6_info[25].mFileTimeLo = 0U;
  c6_info[25].mFileTimeHi = 0U;
  c6_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c6_info[26].name = "eml_guarded_nan";
  c6_info[26].dominantType = "char";
  c6_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c6_info[26].fileTimeLo = 1286806176U;
  c6_info[26].fileTimeHi = 0U;
  c6_info[26].mFileTimeLo = 0U;
  c6_info[26].mFileTimeHi = 0U;
  c6_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c6_info[27].name = "eml_is_float_class";
  c6_info[27].dominantType = "char";
  c6_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c6_info[27].fileTimeLo = 1286806182U;
  c6_info[27].fileTimeHi = 0U;
  c6_info[27].mFileTimeLo = 0U;
  c6_info[27].mFileTimeHi = 0U;
  c6_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c6_info[28].name = "mtimes";
  c6_info[28].dominantType = "double";
  c6_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[28].fileTimeLo = 1289503492U;
  c6_info[28].fileTimeHi = 0U;
  c6_info[28].mFileTimeLo = 0U;
  c6_info[28].mFileTimeHi = 0U;
  c6_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c6_info[29].name = "eml_warning";
  c6_info[29].dominantType = "char";
  c6_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c6_info[29].fileTimeLo = 1286806202U;
  c6_info[29].fileTimeHi = 0U;
  c6_info[29].mFileTimeLo = 0U;
  c6_info[29].mFileTimeHi = 0U;
  c6_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c6_info[30].name = "isnan";
  c6_info[30].dominantType = "double";
  c6_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[30].fileTimeLo = 1286806160U;
  c6_info[30].fileTimeHi = 0U;
  c6_info[30].mFileTimeLo = 0U;
  c6_info[30].mFileTimeHi = 0U;
  c6_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c6_info[31].name = "eps";
  c6_info[31].dominantType = "char";
  c6_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[31].fileTimeLo = 1326711796U;
  c6_info[31].fileTimeHi = 0U;
  c6_info[31].mFileTimeLo = 0U;
  c6_info[31].mFileTimeHi = 0U;
  c6_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[32].name = "eml_is_float_class";
  c6_info[32].dominantType = "char";
  c6_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c6_info[32].fileTimeLo = 1286806182U;
  c6_info[32].fileTimeHi = 0U;
  c6_info[32].mFileTimeLo = 0U;
  c6_info[32].mFileTimeHi = 0U;
  c6_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[33].name = "eml_eps";
  c6_info[33].dominantType = "char";
  c6_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c6_info[33].fileTimeLo = 1326711796U;
  c6_info[33].fileTimeHi = 0U;
  c6_info[33].mFileTimeLo = 0U;
  c6_info[33].mFileTimeHi = 0U;
  c6_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c6_info[34].name = "eml_float_model";
  c6_info[34].dominantType = "char";
  c6_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[34].fileTimeLo = 1326711796U;
  c6_info[34].fileTimeHi = 0U;
  c6_info[34].mFileTimeLo = 0U;
  c6_info[34].mFileTimeHi = 0U;
  c6_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c6_info[35].name = "eml_flt2str";
  c6_info[35].dominantType = "double";
  c6_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c6_info[35].fileTimeLo = 1309438596U;
  c6_info[35].fileTimeHi = 0U;
  c6_info[35].mFileTimeLo = 0U;
  c6_info[35].mFileTimeHi = 0U;
  c6_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c6_info[36].name = "char";
  c6_info[36].dominantType = "double";
  c6_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c6_info[36].fileTimeLo = 1319717368U;
  c6_info[36].fileTimeHi = 0U;
  c6_info[36].mFileTimeLo = 0U;
  c6_info[36].mFileTimeHi = 0U;
}

static void c6_eml_scalar_eg(SFc6_ZFBDInstanceStruct *chartInstance)
{
}

static void c6_b_eml_scalar_eg(SFc6_ZFBDInstanceStruct *chartInstance)
{
}

static void c6_inv(SFc6_ZFBDInstanceStruct *chartInstance, creal_T c6_x[4],
                   creal_T c6_y[4])
{
  int32_T c6_i113;
  creal_T c6_b_x[4];
  int32_T c6_i114;
  creal_T c6_c_x[4];
  real_T c6_n1x;
  int32_T c6_i115;
  creal_T c6_b_y[4];
  real_T c6_n1xinv;
  real_T c6_a;
  real_T c6_b;
  real_T c6_c_y;
  real_T c6_rc;
  real_T c6_d_x;
  boolean_T c6_b_b;
  real_T c6_e_x;
  int32_T c6_i116;
  static char_T c6_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c6_u[8];
  const mxArray *c6_d_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_e_y = NULL;
  real_T c6_c_u;
  const mxArray *c6_f_y = NULL;
  real_T c6_d_u;
  const mxArray *c6_g_y = NULL;
  char_T c6_str[14];
  int32_T c6_i117;
  char_T c6_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  for (c6_i113 = 0; c6_i113 < 4; c6_i113++) {
    c6_b_x[c6_i113] = c6_x[c6_i113];
  }

  c6_inv2x2(chartInstance, c6_b_x, c6_y);
  for (c6_i114 = 0; c6_i114 < 4; c6_i114++) {
    c6_c_x[c6_i114] = c6_x[c6_i114];
  }

  c6_n1x = c6_norm(chartInstance, c6_c_x);
  for (c6_i115 = 0; c6_i115 < 4; c6_i115++) {
    c6_b_y[c6_i115] = c6_y[c6_i115];
  }

  c6_n1xinv = c6_norm(chartInstance, c6_b_y);
  c6_a = c6_n1x;
  c6_b = c6_n1xinv;
  c6_c_y = c6_a * c6_b;
  c6_rc = 1.0 / c6_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c6_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c6_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c6_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c6_d_x = c6_rc;
    c6_b_b = muDoubleScalarIsNaN(c6_d_x);
    guard3 = FALSE;
    if (c6_b_b) {
      guard3 = TRUE;
    } else {
      if (c6_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c6_e_x = c6_rc;
      for (c6_i116 = 0; c6_i116 < 8; c6_i116++) {
        c6_u[c6_i116] = c6_cv0[c6_i116];
      }

      c6_d_y = NULL;
      sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c6_b_u = 14.0;
      c6_e_y = NULL;
      sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c6_c_u = 6.0;
      c6_f_y = NULL;
      sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c6_d_u = c6_e_x;
      c6_g_y = NULL;
      sf_mex_assign(&c6_g_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c6_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c6_d_y, 14, c6_e_y, 14,
        c6_f_y), 14, c6_g_y), "sprintf", c6_str);
      for (c6_i117 = 0; c6_i117 < 14; c6_i117++) {
        c6_b_str[c6_i117] = c6_str[c6_i117];
      }

      c6_b_eml_warning(chartInstance, c6_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c6_eml_warning(chartInstance);
  }
}

static void c6_inv2x2(SFc6_ZFBDInstanceStruct *chartInstance, creal_T c6_x[4],
                      creal_T c6_y[4])
{
  creal_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_b_y;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_c_y;
  real_T c6_d;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_d_y;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_e_y;
  real_T c6_b_d;
  creal_T c6_B;
  real_T c6_ar;
  real_T c6_ai;
  real_T c6_br;
  real_T c6_bi;
  creal_T c6_r;
  real_T c6_brm;
  real_T c6_bim;
  real_T c6_s;
  real_T c6_c_d;
  real_T c6_nr;
  real_T c6_ni;
  real_T c6_sgnbr;
  real_T c6_sgnbi;
  creal_T c6_k_x;
  static creal_T c6_dc0 = { 1.0, 0.0 };

  real_T c6_b_ar;
  real_T c6_b_ai;
  real_T c6_b_br;
  real_T c6_b_bi;
  creal_T c6_t;
  real_T c6_b_brm;
  real_T c6_b_bim;
  real_T c6_b_s;
  real_T c6_d_d;
  real_T c6_b_nr;
  real_T c6_b_ni;
  real_T c6_b_sgnbr;
  real_T c6_b_sgnbi;
  creal_T c6_l_x;
  real_T c6_c_ar;
  real_T c6_c_ai;
  real_T c6_c_br;
  real_T c6_c_bi;
  real_T c6_c_brm;
  real_T c6_c_bim;
  real_T c6_c_s;
  real_T c6_e_d;
  real_T c6_c_nr;
  real_T c6_c_ni;
  real_T c6_c_sgnbr;
  real_T c6_c_sgnbi;
  creal_T c6_m_x;
  creal_T c6_n_x;
  real_T c6_d_ar;
  real_T c6_d_ai;
  real_T c6_d_br;
  real_T c6_d_bi;
  real_T c6_d_brm;
  real_T c6_d_bim;
  real_T c6_d_s;
  real_T c6_f_d;
  real_T c6_d_nr;
  real_T c6_d_ni;
  real_T c6_d_sgnbr;
  real_T c6_d_sgnbi;
  creal_T c6_o_x;
  real_T c6_e_ar;
  real_T c6_e_ai;
  real_T c6_e_br;
  real_T c6_e_bi;
  real_T c6_e_brm;
  real_T c6_e_bim;
  real_T c6_e_s;
  real_T c6_g_d;
  real_T c6_e_nr;
  real_T c6_e_ni;
  real_T c6_e_sgnbr;
  real_T c6_e_sgnbi;
  creal_T c6_p_x;
  real_T c6_f_ar;
  real_T c6_f_ai;
  real_T c6_f_br;
  real_T c6_f_bi;
  real_T c6_f_brm;
  real_T c6_f_bim;
  real_T c6_f_s;
  real_T c6_h_d;
  real_T c6_f_nr;
  real_T c6_f_ni;
  real_T c6_f_sgnbr;
  real_T c6_f_sgnbi;
  creal_T c6_q_x;
  real_T c6_g_ar;
  real_T c6_g_ai;
  real_T c6_g_br;
  real_T c6_g_bi;
  real_T c6_g_brm;
  real_T c6_g_bim;
  real_T c6_g_s;
  real_T c6_i_d;
  real_T c6_g_nr;
  real_T c6_g_ni;
  real_T c6_g_sgnbr;
  real_T c6_g_sgnbi;
  creal_T c6_r_x;
  creal_T c6_s_x;
  creal_T c6_t_x;
  real_T c6_h_ar;
  real_T c6_h_ai;
  real_T c6_h_br;
  real_T c6_h_bi;
  real_T c6_h_brm;
  real_T c6_h_bim;
  real_T c6_h_s;
  real_T c6_j_d;
  real_T c6_h_nr;
  real_T c6_h_ni;
  real_T c6_h_sgnbr;
  real_T c6_h_sgnbi;
  creal_T c6_u_x;
  c6_b_x = c6_x[1];
  c6_c_x = c6_b_x.re;
  c6_d_x = c6_c_x;
  c6_b_y = muDoubleScalarAbs(c6_d_x);
  c6_e_x = c6_b_x.im;
  c6_f_x = c6_e_x;
  c6_c_y = muDoubleScalarAbs(c6_f_x);
  c6_d = c6_b_y + c6_c_y;
  c6_b_x = c6_x[0];
  c6_g_x = c6_b_x.re;
  c6_h_x = c6_g_x;
  c6_d_y = muDoubleScalarAbs(c6_h_x);
  c6_i_x = c6_b_x.im;
  c6_j_x = c6_i_x;
  c6_e_y = muDoubleScalarAbs(c6_j_x);
  c6_b_d = c6_d_y + c6_e_y;
  if (c6_d > c6_b_d) {
    c6_b_x = c6_x[0];
    c6_B = c6_x[1];
    c6_ar = c6_b_x.re;
    c6_ai = c6_b_x.im;
    c6_br = c6_B.re;
    c6_bi = c6_B.im;
    if (c6_bi == 0.0) {
      if (c6_ai == 0.0) {
        c6_r.re = c6_ar / c6_br;
        c6_r.im = 0.0;
      } else if (c6_ar == 0.0) {
        c6_r.re = 0.0;
        c6_r.im = c6_ai / c6_br;
      } else {
        c6_r.re = c6_ar / c6_br;
        c6_r.im = c6_ai / c6_br;
      }
    } else if (c6_br == 0.0) {
      if (c6_ar == 0.0) {
        c6_r.re = c6_ai / c6_bi;
        c6_r.im = 0.0;
      } else if (c6_ai == 0.0) {
        c6_r.re = 0.0;
        c6_r.im = -(c6_ar / c6_bi);
      } else {
        c6_r.re = c6_ai / c6_bi;
        c6_r.im = -(c6_ar / c6_bi);
      }
    } else {
      c6_brm = muDoubleScalarAbs(c6_br);
      c6_bim = muDoubleScalarAbs(c6_bi);
      if (c6_brm > c6_bim) {
        c6_s = c6_bi / c6_br;
        c6_c_d = c6_br + c6_s * c6_bi;
        c6_nr = c6_ar + c6_s * c6_ai;
        c6_ni = c6_ai - c6_s * c6_ar;
        c6_r.re = c6_nr / c6_c_d;
        c6_r.im = c6_ni / c6_c_d;
      } else if (c6_bim == c6_brm) {
        if (c6_br > 0.0) {
          c6_sgnbr = 0.5;
        } else {
          c6_sgnbr = -0.5;
        }

        if (c6_bi > 0.0) {
          c6_sgnbi = 0.5;
        } else {
          c6_sgnbi = -0.5;
        }

        c6_nr = c6_ar * c6_sgnbr + c6_ai * c6_sgnbi;
        c6_ni = c6_ai * c6_sgnbr - c6_ar * c6_sgnbi;
        c6_r.re = c6_nr / c6_brm;
        c6_r.im = c6_ni / c6_brm;
      } else {
        c6_s = c6_br / c6_bi;
        c6_c_d = c6_bi + c6_s * c6_br;
        c6_nr = c6_s * c6_ar + c6_ai;
        c6_ni = c6_s * c6_ai - c6_ar;
        c6_r.re = c6_nr / c6_c_d;
        c6_r.im = c6_ni / c6_c_d;
      }
    }

    c6_b_x = c6_x[3];
    c6_k_x = c6_b_x;
    c6_b_x.re = c6_r.re * c6_k_x.re - c6_r.im * c6_k_x.im;
    c6_b_x.im = c6_r.re * c6_k_x.im + c6_r.im * c6_k_x.re;
    c6_B.re = c6_b_x.re - c6_x[2].re;
    c6_B.im = c6_b_x.im - c6_x[2].im;
    c6_b_ar = c6_dc0.re;
    c6_b_ai = c6_dc0.im;
    c6_b_br = c6_B.re;
    c6_b_bi = c6_B.im;
    if (c6_b_bi == 0.0) {
      if (c6_b_ai == 0.0) {
        c6_t.re = c6_b_ar / c6_b_br;
        c6_t.im = 0.0;
      } else if (c6_b_ar == 0.0) {
        c6_t.re = 0.0;
        c6_t.im = c6_b_ai / c6_b_br;
      } else {
        c6_t.re = c6_b_ar / c6_b_br;
        c6_t.im = c6_b_ai / c6_b_br;
      }
    } else if (c6_b_br == 0.0) {
      if (c6_b_ar == 0.0) {
        c6_t.re = c6_b_ai / c6_b_bi;
        c6_t.im = 0.0;
      } else if (c6_b_ai == 0.0) {
        c6_t.re = 0.0;
        c6_t.im = -(c6_b_ar / c6_b_bi);
      } else {
        c6_t.re = c6_b_ai / c6_b_bi;
        c6_t.im = -(c6_b_ar / c6_b_bi);
      }
    } else {
      c6_b_brm = muDoubleScalarAbs(c6_b_br);
      c6_b_bim = muDoubleScalarAbs(c6_b_bi);
      if (c6_b_brm > c6_b_bim) {
        c6_b_s = c6_b_bi / c6_b_br;
        c6_d_d = c6_b_br + c6_b_s * c6_b_bi;
        c6_b_nr = c6_b_ar + c6_b_s * c6_b_ai;
        c6_b_ni = c6_b_ai - c6_b_s * c6_b_ar;
        c6_t.re = c6_b_nr / c6_d_d;
        c6_t.im = c6_b_ni / c6_d_d;
      } else if (c6_b_bim == c6_b_brm) {
        if (c6_b_br > 0.0) {
          c6_b_sgnbr = 0.5;
        } else {
          c6_b_sgnbr = -0.5;
        }

        if (c6_b_bi > 0.0) {
          c6_b_sgnbi = 0.5;
        } else {
          c6_b_sgnbi = -0.5;
        }

        c6_b_nr = c6_b_ar * c6_b_sgnbr + c6_b_ai * c6_b_sgnbi;
        c6_b_ni = c6_b_ai * c6_b_sgnbr - c6_b_ar * c6_b_sgnbi;
        c6_t.re = c6_b_nr / c6_b_brm;
        c6_t.im = c6_b_ni / c6_b_brm;
      } else {
        c6_b_s = c6_b_br / c6_b_bi;
        c6_d_d = c6_b_bi + c6_b_s * c6_b_br;
        c6_b_nr = c6_b_s * c6_b_ar + c6_b_ai;
        c6_b_ni = c6_b_s * c6_b_ai - c6_b_ar;
        c6_t.re = c6_b_nr / c6_d_d;
        c6_t.im = c6_b_ni / c6_d_d;
      }
    }

    c6_b_x = c6_x[3];
    c6_B = c6_x[1];
    c6_l_x = c6_b_x;
    c6_c_ar = c6_l_x.re;
    c6_c_ai = c6_l_x.im;
    c6_c_br = c6_B.re;
    c6_c_bi = c6_B.im;
    if (c6_c_bi == 0.0) {
      if (c6_c_ai == 0.0) {
        c6_b_x.re = c6_c_ar / c6_c_br;
        c6_b_x.im = 0.0;
      } else if (c6_c_ar == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = c6_c_ai / c6_c_br;
      } else {
        c6_b_x.re = c6_c_ar / c6_c_br;
        c6_b_x.im = c6_c_ai / c6_c_br;
      }
    } else if (c6_c_br == 0.0) {
      if (c6_c_ar == 0.0) {
        c6_b_x.re = c6_c_ai / c6_c_bi;
        c6_b_x.im = 0.0;
      } else if (c6_c_ai == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = -(c6_c_ar / c6_c_bi);
      } else {
        c6_b_x.re = c6_c_ai / c6_c_bi;
        c6_b_x.im = -(c6_c_ar / c6_c_bi);
      }
    } else {
      c6_c_brm = muDoubleScalarAbs(c6_c_br);
      c6_c_bim = muDoubleScalarAbs(c6_c_bi);
      if (c6_c_brm > c6_c_bim) {
        c6_c_s = c6_c_bi / c6_c_br;
        c6_e_d = c6_c_br + c6_c_s * c6_c_bi;
        c6_c_nr = c6_c_ar + c6_c_s * c6_c_ai;
        c6_c_ni = c6_c_ai - c6_c_s * c6_c_ar;
        c6_b_x.re = c6_c_nr / c6_e_d;
        c6_b_x.im = c6_c_ni / c6_e_d;
      } else if (c6_c_bim == c6_c_brm) {
        if (c6_c_br > 0.0) {
          c6_c_sgnbr = 0.5;
        } else {
          c6_c_sgnbr = -0.5;
        }

        if (c6_c_bi > 0.0) {
          c6_c_sgnbi = 0.5;
        } else {
          c6_c_sgnbi = -0.5;
        }

        c6_c_nr = c6_c_ar * c6_c_sgnbr + c6_c_ai * c6_c_sgnbi;
        c6_c_ni = c6_c_ai * c6_c_sgnbr - c6_c_ar * c6_c_sgnbi;
        c6_b_x.re = c6_c_nr / c6_c_brm;
        c6_b_x.im = c6_c_ni / c6_c_brm;
      } else {
        c6_c_s = c6_c_br / c6_c_bi;
        c6_e_d = c6_c_bi + c6_c_s * c6_c_br;
        c6_c_nr = c6_c_s * c6_c_ar + c6_c_ai;
        c6_c_ni = c6_c_s * c6_c_ai - c6_c_ar;
        c6_b_x.re = c6_c_nr / c6_e_d;
        c6_b_x.im = c6_c_ni / c6_e_d;
      }
    }

    c6_m_x = c6_b_x;
    c6_b_x.re = c6_m_x.re * c6_t.re - c6_m_x.im * c6_t.im;
    c6_b_x.im = c6_m_x.re * c6_t.im + c6_m_x.im * c6_t.re;
    c6_y[0] = c6_b_x;
    c6_y[1].re = -c6_t.re;
    c6_y[1].im = -c6_t.im;
    c6_b_x.re = -c6_x[2].re;
    c6_b_x.im = -c6_x[2].im;
    c6_B = c6_x[1];
    c6_n_x = c6_b_x;
    c6_d_ar = c6_n_x.re;
    c6_d_ai = c6_n_x.im;
    c6_d_br = c6_B.re;
    c6_d_bi = c6_B.im;
    if (c6_d_bi == 0.0) {
      if (c6_d_ai == 0.0) {
        c6_b_x.re = c6_d_ar / c6_d_br;
        c6_b_x.im = 0.0;
      } else if (c6_d_ar == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = c6_d_ai / c6_d_br;
      } else {
        c6_b_x.re = c6_d_ar / c6_d_br;
        c6_b_x.im = c6_d_ai / c6_d_br;
      }
    } else if (c6_d_br == 0.0) {
      if (c6_d_ar == 0.0) {
        c6_b_x.re = c6_d_ai / c6_d_bi;
        c6_b_x.im = 0.0;
      } else if (c6_d_ai == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = -(c6_d_ar / c6_d_bi);
      } else {
        c6_b_x.re = c6_d_ai / c6_d_bi;
        c6_b_x.im = -(c6_d_ar / c6_d_bi);
      }
    } else {
      c6_d_brm = muDoubleScalarAbs(c6_d_br);
      c6_d_bim = muDoubleScalarAbs(c6_d_bi);
      if (c6_d_brm > c6_d_bim) {
        c6_d_s = c6_d_bi / c6_d_br;
        c6_f_d = c6_d_br + c6_d_s * c6_d_bi;
        c6_d_nr = c6_d_ar + c6_d_s * c6_d_ai;
        c6_d_ni = c6_d_ai - c6_d_s * c6_d_ar;
        c6_b_x.re = c6_d_nr / c6_f_d;
        c6_b_x.im = c6_d_ni / c6_f_d;
      } else if (c6_d_bim == c6_d_brm) {
        if (c6_d_br > 0.0) {
          c6_d_sgnbr = 0.5;
        } else {
          c6_d_sgnbr = -0.5;
        }

        if (c6_d_bi > 0.0) {
          c6_d_sgnbi = 0.5;
        } else {
          c6_d_sgnbi = -0.5;
        }

        c6_d_nr = c6_d_ar * c6_d_sgnbr + c6_d_ai * c6_d_sgnbi;
        c6_d_ni = c6_d_ai * c6_d_sgnbr - c6_d_ar * c6_d_sgnbi;
        c6_b_x.re = c6_d_nr / c6_d_brm;
        c6_b_x.im = c6_d_ni / c6_d_brm;
      } else {
        c6_d_s = c6_d_br / c6_d_bi;
        c6_f_d = c6_d_bi + c6_d_s * c6_d_br;
        c6_d_nr = c6_d_s * c6_d_ar + c6_d_ai;
        c6_d_ni = c6_d_s * c6_d_ai - c6_d_ar;
        c6_b_x.re = c6_d_nr / c6_f_d;
        c6_b_x.im = c6_d_ni / c6_f_d;
      }
    }

    c6_o_x = c6_b_x;
    c6_b_x.re = c6_o_x.re * c6_t.re - c6_o_x.im * c6_t.im;
    c6_b_x.im = c6_o_x.re * c6_t.im + c6_o_x.im * c6_t.re;
    c6_y[2] = c6_b_x;
    c6_b_x.re = c6_r.re * c6_t.re - c6_r.im * c6_t.im;
    c6_b_x.im = c6_r.re * c6_t.im + c6_r.im * c6_t.re;
    c6_y[3] = c6_b_x;
  } else {
    c6_b_x = c6_x[1];
    c6_B = c6_x[0];
    c6_e_ar = c6_b_x.re;
    c6_e_ai = c6_b_x.im;
    c6_e_br = c6_B.re;
    c6_e_bi = c6_B.im;
    if (c6_e_bi == 0.0) {
      if (c6_e_ai == 0.0) {
        c6_r.re = c6_e_ar / c6_e_br;
        c6_r.im = 0.0;
      } else if (c6_e_ar == 0.0) {
        c6_r.re = 0.0;
        c6_r.im = c6_e_ai / c6_e_br;
      } else {
        c6_r.re = c6_e_ar / c6_e_br;
        c6_r.im = c6_e_ai / c6_e_br;
      }
    } else if (c6_e_br == 0.0) {
      if (c6_e_ar == 0.0) {
        c6_r.re = c6_e_ai / c6_e_bi;
        c6_r.im = 0.0;
      } else if (c6_e_ai == 0.0) {
        c6_r.re = 0.0;
        c6_r.im = -(c6_e_ar / c6_e_bi);
      } else {
        c6_r.re = c6_e_ai / c6_e_bi;
        c6_r.im = -(c6_e_ar / c6_e_bi);
      }
    } else {
      c6_e_brm = muDoubleScalarAbs(c6_e_br);
      c6_e_bim = muDoubleScalarAbs(c6_e_bi);
      if (c6_e_brm > c6_e_bim) {
        c6_e_s = c6_e_bi / c6_e_br;
        c6_g_d = c6_e_br + c6_e_s * c6_e_bi;
        c6_e_nr = c6_e_ar + c6_e_s * c6_e_ai;
        c6_e_ni = c6_e_ai - c6_e_s * c6_e_ar;
        c6_r.re = c6_e_nr / c6_g_d;
        c6_r.im = c6_e_ni / c6_g_d;
      } else if (c6_e_bim == c6_e_brm) {
        if (c6_e_br > 0.0) {
          c6_e_sgnbr = 0.5;
        } else {
          c6_e_sgnbr = -0.5;
        }

        if (c6_e_bi > 0.0) {
          c6_e_sgnbi = 0.5;
        } else {
          c6_e_sgnbi = -0.5;
        }

        c6_e_nr = c6_e_ar * c6_e_sgnbr + c6_e_ai * c6_e_sgnbi;
        c6_e_ni = c6_e_ai * c6_e_sgnbr - c6_e_ar * c6_e_sgnbi;
        c6_r.re = c6_e_nr / c6_e_brm;
        c6_r.im = c6_e_ni / c6_e_brm;
      } else {
        c6_e_s = c6_e_br / c6_e_bi;
        c6_g_d = c6_e_bi + c6_e_s * c6_e_br;
        c6_e_nr = c6_e_s * c6_e_ar + c6_e_ai;
        c6_e_ni = c6_e_s * c6_e_ai - c6_e_ar;
        c6_r.re = c6_e_nr / c6_g_d;
        c6_r.im = c6_e_ni / c6_g_d;
      }
    }

    c6_b_x = c6_x[2];
    c6_p_x = c6_b_x;
    c6_b_x.re = c6_r.re * c6_p_x.re - c6_r.im * c6_p_x.im;
    c6_b_x.im = c6_r.re * c6_p_x.im + c6_r.im * c6_p_x.re;
    c6_B.re = c6_x[3].re - c6_b_x.re;
    c6_B.im = c6_x[3].im - c6_b_x.im;
    c6_f_ar = c6_dc0.re;
    c6_f_ai = c6_dc0.im;
    c6_f_br = c6_B.re;
    c6_f_bi = c6_B.im;
    if (c6_f_bi == 0.0) {
      if (c6_f_ai == 0.0) {
        c6_t.re = c6_f_ar / c6_f_br;
        c6_t.im = 0.0;
      } else if (c6_f_ar == 0.0) {
        c6_t.re = 0.0;
        c6_t.im = c6_f_ai / c6_f_br;
      } else {
        c6_t.re = c6_f_ar / c6_f_br;
        c6_t.im = c6_f_ai / c6_f_br;
      }
    } else if (c6_f_br == 0.0) {
      if (c6_f_ar == 0.0) {
        c6_t.re = c6_f_ai / c6_f_bi;
        c6_t.im = 0.0;
      } else if (c6_f_ai == 0.0) {
        c6_t.re = 0.0;
        c6_t.im = -(c6_f_ar / c6_f_bi);
      } else {
        c6_t.re = c6_f_ai / c6_f_bi;
        c6_t.im = -(c6_f_ar / c6_f_bi);
      }
    } else {
      c6_f_brm = muDoubleScalarAbs(c6_f_br);
      c6_f_bim = muDoubleScalarAbs(c6_f_bi);
      if (c6_f_brm > c6_f_bim) {
        c6_f_s = c6_f_bi / c6_f_br;
        c6_h_d = c6_f_br + c6_f_s * c6_f_bi;
        c6_f_nr = c6_f_ar + c6_f_s * c6_f_ai;
        c6_f_ni = c6_f_ai - c6_f_s * c6_f_ar;
        c6_t.re = c6_f_nr / c6_h_d;
        c6_t.im = c6_f_ni / c6_h_d;
      } else if (c6_f_bim == c6_f_brm) {
        if (c6_f_br > 0.0) {
          c6_f_sgnbr = 0.5;
        } else {
          c6_f_sgnbr = -0.5;
        }

        if (c6_f_bi > 0.0) {
          c6_f_sgnbi = 0.5;
        } else {
          c6_f_sgnbi = -0.5;
        }

        c6_f_nr = c6_f_ar * c6_f_sgnbr + c6_f_ai * c6_f_sgnbi;
        c6_f_ni = c6_f_ai * c6_f_sgnbr - c6_f_ar * c6_f_sgnbi;
        c6_t.re = c6_f_nr / c6_f_brm;
        c6_t.im = c6_f_ni / c6_f_brm;
      } else {
        c6_f_s = c6_f_br / c6_f_bi;
        c6_h_d = c6_f_bi + c6_f_s * c6_f_br;
        c6_f_nr = c6_f_s * c6_f_ar + c6_f_ai;
        c6_f_ni = c6_f_s * c6_f_ai - c6_f_ar;
        c6_t.re = c6_f_nr / c6_h_d;
        c6_t.im = c6_f_ni / c6_h_d;
      }
    }

    c6_b_x = c6_x[3];
    c6_B = c6_x[0];
    c6_q_x = c6_b_x;
    c6_g_ar = c6_q_x.re;
    c6_g_ai = c6_q_x.im;
    c6_g_br = c6_B.re;
    c6_g_bi = c6_B.im;
    if (c6_g_bi == 0.0) {
      if (c6_g_ai == 0.0) {
        c6_b_x.re = c6_g_ar / c6_g_br;
        c6_b_x.im = 0.0;
      } else if (c6_g_ar == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = c6_g_ai / c6_g_br;
      } else {
        c6_b_x.re = c6_g_ar / c6_g_br;
        c6_b_x.im = c6_g_ai / c6_g_br;
      }
    } else if (c6_g_br == 0.0) {
      if (c6_g_ar == 0.0) {
        c6_b_x.re = c6_g_ai / c6_g_bi;
        c6_b_x.im = 0.0;
      } else if (c6_g_ai == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = -(c6_g_ar / c6_g_bi);
      } else {
        c6_b_x.re = c6_g_ai / c6_g_bi;
        c6_b_x.im = -(c6_g_ar / c6_g_bi);
      }
    } else {
      c6_g_brm = muDoubleScalarAbs(c6_g_br);
      c6_g_bim = muDoubleScalarAbs(c6_g_bi);
      if (c6_g_brm > c6_g_bim) {
        c6_g_s = c6_g_bi / c6_g_br;
        c6_i_d = c6_g_br + c6_g_s * c6_g_bi;
        c6_g_nr = c6_g_ar + c6_g_s * c6_g_ai;
        c6_g_ni = c6_g_ai - c6_g_s * c6_g_ar;
        c6_b_x.re = c6_g_nr / c6_i_d;
        c6_b_x.im = c6_g_ni / c6_i_d;
      } else if (c6_g_bim == c6_g_brm) {
        if (c6_g_br > 0.0) {
          c6_g_sgnbr = 0.5;
        } else {
          c6_g_sgnbr = -0.5;
        }

        if (c6_g_bi > 0.0) {
          c6_g_sgnbi = 0.5;
        } else {
          c6_g_sgnbi = -0.5;
        }

        c6_g_nr = c6_g_ar * c6_g_sgnbr + c6_g_ai * c6_g_sgnbi;
        c6_g_ni = c6_g_ai * c6_g_sgnbr - c6_g_ar * c6_g_sgnbi;
        c6_b_x.re = c6_g_nr / c6_g_brm;
        c6_b_x.im = c6_g_ni / c6_g_brm;
      } else {
        c6_g_s = c6_g_br / c6_g_bi;
        c6_i_d = c6_g_bi + c6_g_s * c6_g_br;
        c6_g_nr = c6_g_s * c6_g_ar + c6_g_ai;
        c6_g_ni = c6_g_s * c6_g_ai - c6_g_ar;
        c6_b_x.re = c6_g_nr / c6_i_d;
        c6_b_x.im = c6_g_ni / c6_i_d;
      }
    }

    c6_r_x = c6_b_x;
    c6_b_x.re = c6_r_x.re * c6_t.re - c6_r_x.im * c6_t.im;
    c6_b_x.im = c6_r_x.re * c6_t.im + c6_r_x.im * c6_t.re;
    c6_y[0] = c6_b_x;
    c6_b_x.re = -c6_r.re;
    c6_b_x.im = -c6_r.im;
    c6_s_x = c6_b_x;
    c6_b_x.re = c6_s_x.re * c6_t.re - c6_s_x.im * c6_t.im;
    c6_b_x.im = c6_s_x.re * c6_t.im + c6_s_x.im * c6_t.re;
    c6_y[1] = c6_b_x;
    c6_b_x.re = -c6_x[2].re;
    c6_b_x.im = -c6_x[2].im;
    c6_B = c6_x[0];
    c6_t_x = c6_b_x;
    c6_h_ar = c6_t_x.re;
    c6_h_ai = c6_t_x.im;
    c6_h_br = c6_B.re;
    c6_h_bi = c6_B.im;
    if (c6_h_bi == 0.0) {
      if (c6_h_ai == 0.0) {
        c6_b_x.re = c6_h_ar / c6_h_br;
        c6_b_x.im = 0.0;
      } else if (c6_h_ar == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = c6_h_ai / c6_h_br;
      } else {
        c6_b_x.re = c6_h_ar / c6_h_br;
        c6_b_x.im = c6_h_ai / c6_h_br;
      }
    } else if (c6_h_br == 0.0) {
      if (c6_h_ar == 0.0) {
        c6_b_x.re = c6_h_ai / c6_h_bi;
        c6_b_x.im = 0.0;
      } else if (c6_h_ai == 0.0) {
        c6_b_x.re = 0.0;
        c6_b_x.im = -(c6_h_ar / c6_h_bi);
      } else {
        c6_b_x.re = c6_h_ai / c6_h_bi;
        c6_b_x.im = -(c6_h_ar / c6_h_bi);
      }
    } else {
      c6_h_brm = muDoubleScalarAbs(c6_h_br);
      c6_h_bim = muDoubleScalarAbs(c6_h_bi);
      if (c6_h_brm > c6_h_bim) {
        c6_h_s = c6_h_bi / c6_h_br;
        c6_j_d = c6_h_br + c6_h_s * c6_h_bi;
        c6_h_nr = c6_h_ar + c6_h_s * c6_h_ai;
        c6_h_ni = c6_h_ai - c6_h_s * c6_h_ar;
        c6_b_x.re = c6_h_nr / c6_j_d;
        c6_b_x.im = c6_h_ni / c6_j_d;
      } else if (c6_h_bim == c6_h_brm) {
        if (c6_h_br > 0.0) {
          c6_h_sgnbr = 0.5;
        } else {
          c6_h_sgnbr = -0.5;
        }

        if (c6_h_bi > 0.0) {
          c6_h_sgnbi = 0.5;
        } else {
          c6_h_sgnbi = -0.5;
        }

        c6_h_nr = c6_h_ar * c6_h_sgnbr + c6_h_ai * c6_h_sgnbi;
        c6_h_ni = c6_h_ai * c6_h_sgnbr - c6_h_ar * c6_h_sgnbi;
        c6_b_x.re = c6_h_nr / c6_h_brm;
        c6_b_x.im = c6_h_ni / c6_h_brm;
      } else {
        c6_h_s = c6_h_br / c6_h_bi;
        c6_j_d = c6_h_bi + c6_h_s * c6_h_br;
        c6_h_nr = c6_h_s * c6_h_ar + c6_h_ai;
        c6_h_ni = c6_h_s * c6_h_ai - c6_h_ar;
        c6_b_x.re = c6_h_nr / c6_j_d;
        c6_b_x.im = c6_h_ni / c6_j_d;
      }
    }

    c6_u_x = c6_b_x;
    c6_b_x.re = c6_u_x.re * c6_t.re - c6_u_x.im * c6_t.im;
    c6_b_x.im = c6_u_x.re * c6_t.im + c6_u_x.im * c6_t.re;
    c6_y[2] = c6_b_x;
    c6_y[3] = c6_t;
  }
}

static real_T c6_norm(SFc6_ZFBDInstanceStruct *chartInstance, creal_T c6_x[4])
{
  real_T c6_y;
  int32_T c6_j;
  real_T c6_b_j;
  real_T c6_s;
  int32_T c6_i;
  real_T c6_b_i;
  creal_T c6_b_x;
  real_T c6_x1;
  real_T c6_x2;
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_y;
  real_T c6_c_x;
  boolean_T c6_b_b;
  boolean_T exitg1;
  c6_y = 0.0;
  c6_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c6_j < 2)) {
    c6_b_j = 1.0 + (real_T)c6_j;
    c6_s = 0.0;
    for (c6_i = 0; c6_i < 2; c6_i++) {
      c6_b_i = 1.0 + (real_T)c6_i;
      c6_b_x = c6_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c6_b_i), 1, 2, 1, 0) + (((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_j),
        1, 2, 2, 0) - 1) << 1)) - 1];
      c6_x1 = c6_b_x.re;
      c6_x2 = c6_b_x.im;
      c6_a = c6_x1;
      c6_b = c6_x2;
      c6_b_y = muDoubleScalarHypot(c6_a, c6_b);
      c6_s += c6_b_y;
    }

    c6_c_x = c6_s;
    c6_b_b = muDoubleScalarIsNaN(c6_c_x);
    if (c6_b_b) {
      c6_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c6_s > c6_y) {
        c6_y = c6_s;
      }

      c6_j++;
    }
  }

  return c6_y;
}

static void c6_eml_warning(SFc6_ZFBDInstanceStruct *chartInstance)
{
  int32_T c6_i118;
  static char_T c6_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c6_u[27];
  const mxArray *c6_y = NULL;
  for (c6_i118 = 0; c6_i118 < 27; c6_i118++) {
    c6_u[c6_i118] = c6_varargin_1[c6_i118];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c6_y));
}

static void c6_b_eml_warning(SFc6_ZFBDInstanceStruct *chartInstance, char_T
  c6_varargin_2[14])
{
  int32_T c6_i119;
  static char_T c6_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c6_u[33];
  const mxArray *c6_y = NULL;
  int32_T c6_i120;
  char_T c6_b_u[14];
  const mxArray *c6_b_y = NULL;
  for (c6_i119 = 0; c6_i119 < 33; c6_i119++) {
    c6_u[c6_i119] = c6_varargin_1[c6_i119];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c6_i120 = 0; c6_i120 < 14; c6_i120++) {
    c6_b_u[c6_i120] = c6_varargin_2[c6_i120];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c6_y, 14, c6_b_y));
}

static void c6_c_eml_scalar_eg(SFc6_ZFBDInstanceStruct *chartInstance)
{
}

static void c6_e_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_sprintf, const char_T *c6_identifier, char_T c6_y[14])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_sprintf), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_sprintf);
}

static void c6_f_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, char_T c6_y[14])
{
  char_T c6_cv1[14];
  int32_T c6_i121;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c6_i121 = 0; c6_i121 < 14; c6_i121++) {
    c6_y[c6_i121] = c6_cv1[c6_i121];
  }

  sf_mex_destroy(&c6_u);
}

static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_g_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i122;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i122, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i122;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_h_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_ZFBD, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_is_active_c6_ZFBD),
    &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_ZFBD);
  return c6_y;
}

static uint8_T c6_i_emlrt_marshallIn(SFc6_ZFBDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_ZFBDInstanceStruct *chartInstance)
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

void sf_c6_ZFBD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1909576151U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1292980704U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(488504011U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2476373467U);
}

mxArray *sf_c6_ZFBD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("m1JglkF9OavHYmD8ht0q5F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
      pr[0] = (double)(2);
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

mxArray *sf_c6_ZFBD_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c6_ZFBD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"yr2\",},{M[8],M[0],T\"is_active_c6_ZFBD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_ZFBD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_ZFBDInstanceStruct *chartInstance;
    chartInstance = (SFc6_ZFBDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ZFBDMachineNumber_,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"rx2");
          _SFD_SET_DATA_PROPS(1,2,0,1,"yr2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"h2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"w2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,440);
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
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          creal_T (*c6_rx2)[20];
          creal_T (*c6_yr2)[20];
          creal_T (*c6_h2)[8];
          creal_T (*c6_w2)[8];
          c6_w2 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 2);
          c6_h2 = (creal_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
          c6_yr2 = (creal_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_rx2 = (creal_T (*)[20])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_rx2);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_yr2);
          _SFD_SET_DATA_VALUE_PTR(2U, *c6_h2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c6_w2);
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
  return "vBWTfkCrj5cZLRh2msbBx";
}

static void sf_opaque_initialize_c6_ZFBD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_ZFBDInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c6_ZFBD((SFc6_ZFBDInstanceStruct*) chartInstanceVar);
  initialize_c6_ZFBD((SFc6_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_ZFBD(void *chartInstanceVar)
{
  enable_c6_ZFBD((SFc6_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_ZFBD(void *chartInstanceVar)
{
  disable_c6_ZFBD((SFc6_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_ZFBD(void *chartInstanceVar)
{
  sf_c6_ZFBD((SFc6_ZFBDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_ZFBD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_ZFBD((SFc6_ZFBDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_ZFBD();/* state var info */
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

extern void sf_internal_set_sim_state_c6_ZFBD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_ZFBD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_ZFBD((SFc6_ZFBDInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_ZFBD(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_ZFBD(S);
}

static void sf_opaque_set_sim_state_c6_ZFBD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_ZFBD(S, st);
}

static void sf_opaque_terminate_c6_ZFBD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_ZFBDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ZFBD_optimization_info();
    }

    finalize_c6_ZFBD((SFc6_ZFBDInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_ZFBD((SFc6_ZFBDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_ZFBD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_ZFBD((SFc6_ZFBDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ZFBD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1134091678U));
  ssSetChecksum1(S,(3865313044U));
  ssSetChecksum2(S,(747134207U));
  ssSetChecksum3(S,(1745566761U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_ZFBD(SimStruct *S)
{
  SFc6_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc6_ZFBDInstanceStruct *)utMalloc(sizeof
    (SFc6_ZFBDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_ZFBDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_ZFBD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_ZFBD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_ZFBD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_ZFBD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_ZFBD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_ZFBD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_ZFBD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_ZFBD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_ZFBD;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_ZFBD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_ZFBD;
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

void c6_ZFBD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_ZFBD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_ZFBD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_ZFBD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_ZFBD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
