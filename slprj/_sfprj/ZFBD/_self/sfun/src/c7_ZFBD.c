/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ZFBD_sfun.h"
#include "c7_ZFBD.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ZFBD_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[5] = { "nargin", "nargout", "y1", "y2",
  "y" };

/* Function Declarations */
static void initialize_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void initialize_params_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void enable_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void disable_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_ZFBD(SFc7_ZFBDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_ZFBD(SFc7_ZFBDInstanceStruct
  *chartInstance);
static void set_sim_state_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance, const
  mxArray *c7_st);
static void finalize_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void sf_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void initSimStructsc7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void registerMessagesc7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance, const
  mxArray *c7_y, const char_T *c7_identifier, creal_T c7_b_y[40]);
static void c7_b_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance, const
  mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, creal_T c7_y[40]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_d_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_e_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_ZFBD, const char_T *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_ZFBDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_ZFBD = 0U;
}

static void initialize_params_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
}

static void enable_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_ZFBD(SFc7_ZFBDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c7_ZFBD(SFc7_ZFBDInstanceStruct
  *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  creal_T c7_u[40];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  creal_T (*c7_d_y)[40];
  c7_d_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  for (c7_i0 = 0; c7_i0 < 40; c7_i0++) {
    c7_u[c7_i0] = (*c7_d_y)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 0, 1U, 1U, 0U, 2, 4, 10),
                FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal = chartInstance->c7_is_active_c7_ZFBD;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance, const
  mxArray *c7_st)
{
  const mxArray *c7_u;
  creal_T c7_dcv0[40];
  int32_T c7_i1;
  creal_T (*c7_y)[40];
  c7_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "y",
                      c7_dcv0);
  for (c7_i1 = 0; c7_i1 < 40; c7_i1++) {
    (*c7_y)[c7_i1] = c7_dcv0[c7_i1];
  }

  chartInstance->c7_is_active_c7_ZFBD = c7_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 1)), "is_active_c7_ZFBD");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_ZFBD(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
}

static void sf_c7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
  int32_T c7_i2;
  creal_T c7_y1[20];
  int32_T c7_i3;
  creal_T c7_y2[20];
  uint32_T c7_debug_family_var_map[5];
  real_T c7_nargin = 2.0;
  real_T c7_nargout = 1.0;
  creal_T c7_y[40];
  int32_T c7_i4;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  creal_T (*c7_b_y)[40];
  creal_T (*c7_b_y2)[20];
  creal_T (*c7_b_y1)[20];
  c7_b_y2 = (creal_T (*)[20])ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_y1 = (creal_T (*)[20])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i2 = 0; c7_i2 < 20; c7_i2++) {
    c7_y1[c7_i2] = (*c7_b_y1)[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 20; c7_i3++) {
    c7_y2[c7_i3] = (*c7_b_y2)[c7_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_y1, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_y2, 3U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_y, 4U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 2);
  c7_i4 = 0;
  c7_i5 = 0;
  for (c7_i6 = 0; c7_i6 < 10; c7_i6++) {
    for (c7_i7 = 0; c7_i7 < 2; c7_i7++) {
      c7_y[c7_i7 + c7_i4] = c7_y1[c7_i7 + c7_i5];
    }

    c7_i4 += 4;
    c7_i5 += 2;
  }

  c7_i8 = 0;
  c7_i9 = 0;
  for (c7_i10 = 0; c7_i10 < 10; c7_i10++) {
    for (c7_i11 = 0; c7_i11 < 2; c7_i11++) {
      c7_y[(c7_i11 + c7_i8) + 2] = c7_y2[c7_i11 + c7_i9];
    }

    c7_i8 += 4;
    c7_i9 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c7_i12 = 0; c7_i12 < 40; c7_i12++) {
    (*c7_b_y)[c7_i12] = c7_y[c7_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ZFBDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
}

static void registerMessagesc7_ZFBD(SFc7_ZFBDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  creal_T c7_b_inData[40];
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  creal_T c7_u[40];
  const mxArray *c7_y = NULL;
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i13 = 0;
  for (c7_i14 = 0; c7_i14 < 10; c7_i14++) {
    for (c7_i15 = 0; c7_i15 < 4; c7_i15++) {
      c7_b_inData[c7_i15 + c7_i13] = (*(creal_T (*)[40])c7_inData)[c7_i15 +
        c7_i13];
    }

    c7_i13 += 4;
  }

  c7_i16 = 0;
  for (c7_i17 = 0; c7_i17 < 10; c7_i17++) {
    for (c7_i18 = 0; c7_i18 < 4; c7_i18++) {
      c7_u[c7_i18 + c7_i16] = c7_b_inData[c7_i18 + c7_i16];
    }

    c7_i16 += 4;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 1U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance, const
  mxArray *c7_y, const char_T *c7_identifier, creal_T c7_b_y[40])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_y), &c7_thisId, c7_b_y);
  sf_mex_destroy(&c7_y);
}

static void c7_b_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance, const
  mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, creal_T c7_y[40])
{
  creal_T c7_dcv1[40];
  int32_T c7_i19;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dcv1, 1, 0, 1U, 1, 0U, 2, 4,
                10);
  for (c7_i19 = 0; c7_i19 < 40; c7_i19++) {
    c7_y[c7_i19] = c7_dcv1[c7_i19];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_y;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  creal_T c7_b_y[40];
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)chartInstanceVoid;
  c7_y = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_y), &c7_thisId, c7_b_y);
  sf_mex_destroy(&c7_y);
  c7_i20 = 0;
  for (c7_i21 = 0; c7_i21 < 10; c7_i21++) {
    for (c7_i22 = 0; c7_i22 < 4; c7_i22++) {
      (*(creal_T (*)[40])c7_outData)[c7_i22 + c7_i20] = c7_b_y[c7_i22 + c7_i20];
    }

    c7_i20 += 4;
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  creal_T c7_b_inData[20];
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  creal_T c7_u[20];
  const mxArray *c7_y = NULL;
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i23 = 0;
  for (c7_i24 = 0; c7_i24 < 10; c7_i24++) {
    for (c7_i25 = 0; c7_i25 < 2; c7_i25++) {
      c7_b_inData[c7_i25 + c7_i23] = (*(creal_T (*)[20])c7_inData)[c7_i25 +
        c7_i23];
    }

    c7_i23 += 2;
  }

  c7_i26 = 0;
  for (c7_i27 = 0; c7_i27 < 10; c7_i27++) {
    for (c7_i28 = 0; c7_i28 < 2; c7_i28++) {
      c7_u[c7_i28 + c7_i26] = c7_b_inData[c7_i28 + c7_i26];
    }

    c7_i26 += 2;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 1U, 1U, 0U, 2, 2, 10), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_ZFBD_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_d_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i29;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i29, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i29;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_ZFBD, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_is_active_c7_ZFBD),
    &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_ZFBD);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn(SFc7_ZFBDInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_ZFBDInstanceStruct *chartInstance)
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

void sf_c7_ZFBD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4102750813U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3282597120U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(812162466U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3936078846U);
}

mxArray *sf_c7_ZFBD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("39RovJutyQcxbvLcAYz61B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

mxArray *sf_c7_ZFBD_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c7_ZFBD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c7_ZFBD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_ZFBD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_ZFBDInstanceStruct *chartInstance;
    chartInstance = (SFc7_ZFBDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ZFBDMachineNumber_,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"y1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"y2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,48);
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
            1.0,0,1,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          creal_T (*c7_y1)[20];
          creal_T (*c7_y)[40];
          creal_T (*c7_y2)[20];
          c7_y2 = (creal_T (*)[20])ssGetInputPortSignal(chartInstance->S, 1);
          c7_y = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
          c7_y1 = (creal_T (*)[20])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_y1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c7_y2);
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
  return "dkO5kHaJW4fwFvEYmcfcpC";
}

static void sf_opaque_initialize_c7_ZFBD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_ZFBDInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c7_ZFBD((SFc7_ZFBDInstanceStruct*) chartInstanceVar);
  initialize_c7_ZFBD((SFc7_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_ZFBD(void *chartInstanceVar)
{
  enable_c7_ZFBD((SFc7_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_ZFBD(void *chartInstanceVar)
{
  disable_c7_ZFBD((SFc7_ZFBDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_ZFBD(void *chartInstanceVar)
{
  sf_c7_ZFBD((SFc7_ZFBDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_ZFBD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_ZFBD((SFc7_ZFBDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_ZFBD();/* state var info */
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

extern void sf_internal_set_sim_state_c7_ZFBD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_ZFBD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_ZFBD((SFc7_ZFBDInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_ZFBD(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_ZFBD(S);
}

static void sf_opaque_set_sim_state_c7_ZFBD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c7_ZFBD(S, st);
}

static void sf_opaque_terminate_c7_ZFBD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_ZFBDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ZFBD_optimization_info();
    }

    finalize_c7_ZFBD((SFc7_ZFBDInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_ZFBD((SFc7_ZFBDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_ZFBD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_ZFBD((SFc7_ZFBDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ZFBD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(485450462U));
  ssSetChecksum1(S,(2071452988U));
  ssSetChecksum2(S,(3636996891U));
  ssSetChecksum3(S,(3166198436U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_ZFBD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_ZFBD(SimStruct *S)
{
  SFc7_ZFBDInstanceStruct *chartInstance;
  chartInstance = (SFc7_ZFBDInstanceStruct *)utMalloc(sizeof
    (SFc7_ZFBDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_ZFBDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_ZFBD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_ZFBD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_ZFBD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_ZFBD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_ZFBD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_ZFBD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_ZFBD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_ZFBD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_ZFBD;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_ZFBD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_ZFBD;
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

void c7_ZFBD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_ZFBD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_ZFBD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_ZFBD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_ZFBD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
