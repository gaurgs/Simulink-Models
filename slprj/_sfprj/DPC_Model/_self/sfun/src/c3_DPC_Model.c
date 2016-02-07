/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DPC_Model_sfun.h"
#include "c3_DPC_Model.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DPC_Model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[7] = { "a1", "a2", "nargin", "nargout",
  "h1", "data", "signal" };

/* Function Declarations */
static void initialize_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance);
static void initialize_params_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance);
static void enable_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance);
static void disable_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance);
static void set_sim_state_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance);
static void sf_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance);
static void c3_chartstep_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance);
static void initSimStructsc3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance);
static void registerMessagesc3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_signal, const char_T *c3_identifier, creal_T c3_y[40]);
static void c3_b_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, creal_T c3_y[40]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_eml_scalar_eg(SFc3_DPC_ModelInstanceStruct *chartInstance);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_DPC_Model, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_DPC_ModelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_DPC_Model = 0U;
}

static void initialize_params_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void enable_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  creal_T c3_u[40];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  creal_T (*c3_signal)[40];
  c3_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 40; c3_i0++) {
    c3_u[c3_i0] = (*c3_signal)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 1U, 1U, 0U, 2, 4, 10),
                FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_DPC_Model;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  creal_T c3_dcv0[40];
  int32_T c3_i1;
  creal_T (*c3_signal)[40];
  c3_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "signal", c3_dcv0);
  for (c3_i1 = 0; c3_i1 < 40; c3_i1++) {
    (*c3_signal)[c3_i1] = c3_dcv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_DPC_Model = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_DPC_Model");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_DPC_Model(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance)
{
}

static void sf_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_DPC_Model(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DPC_ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance)
{
  int32_T c3_i2;
  creal_T c3_h1[16];
  int32_T c3_i3;
  creal_T c3_data[40];
  uint32_T c3_debug_family_var_map[7];
  real_T c3_a1[40];
  real_T c3_a2[40];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  creal_T c3_signal[40];
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  creal_T c3_a[16];
  int32_T c3_i8;
  creal_T c3_b[40];
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  creal_T c3_C[40];
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  creal_T c3_b_a;
  int32_T c3_i20;
  creal_T (*c3_b_signal)[40];
  creal_T (*c3_b_data)[40];
  creal_T (*c3_b_h1)[16];
  c3_b_data = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_h1 = (creal_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 16; c3_i2++) {
    c3_h1[c3_i2] = (*c3_b_h1)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 40; c3_i3++) {
    c3_data[c3_i3] = (*c3_b_data)[c3_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_a1, 0U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_a2, 1U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_h1, 4U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_data, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_signal, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  for (c3_i4 = 0; c3_i4 < 40; c3_i4++) {
    c3_a1[c3_i4] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i5 = 0; c3_i5 < 40; c3_i5++) {
    c3_a2[c3_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i6 = 0; c3_i6 < 40; c3_i6++) {
    c3_signal[c3_i6].re = 0.0;
    c3_signal[c3_i6].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  for (c3_i7 = 0; c3_i7 < 16; c3_i7++) {
    c3_a[c3_i7] = c3_h1[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 40; c3_i8++) {
    c3_b[c3_i8] = c3_data[c3_i8];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i9 = 0; c3_i9 < 40; c3_i9++) {
    c3_signal[c3_i9].re = 0.0;
    c3_signal[c3_i9].im = 0.0;
  }

  for (c3_i10 = 0; c3_i10 < 40; c3_i10++) {
    c3_signal[c3_i10].re = 0.0;
    c3_signal[c3_i10].im = 0.0;
  }

  for (c3_i11 = 0; c3_i11 < 40; c3_i11++) {
    c3_C[c3_i11] = c3_signal[c3_i11];
  }

  for (c3_i12 = 0; c3_i12 < 40; c3_i12++) {
    c3_signal[c3_i12] = c3_C[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 40; c3_i13++) {
    c3_C[c3_i13] = c3_signal[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 40; c3_i14++) {
    c3_signal[c3_i14] = c3_C[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    c3_i16 = 0;
    for (c3_i17 = 0; c3_i17 < 10; c3_i17++) {
      c3_signal[c3_i16 + c3_i15].re = 0.0;
      c3_signal[c3_i16 + c3_i15].im = 0.0;
      c3_i18 = 0;
      for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
        c3_b_a.re = c3_a[c3_i18 + c3_i15].re * c3_b[c3_i19 + c3_i16].re -
          c3_a[c3_i18 + c3_i15].im * c3_b[c3_i19 + c3_i16].im;
        c3_b_a.im = c3_a[c3_i18 + c3_i15].re * c3_b[c3_i19 + c3_i16].im +
          c3_a[c3_i18 + c3_i15].im * c3_b[c3_i19 + c3_i16].re;
        c3_signal[c3_i16 + c3_i15].re += c3_b_a.re;
        c3_signal[c3_i16 + c3_i15].im += c3_b_a.im;
        c3_i18 += 4;
      }

      c3_i16 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i20 = 0; c3_i20 < 40; c3_i20++) {
    (*c3_b_signal)[c3_i20] = c3_signal[c3_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc3_DPC_Model(SFc3_DPC_ModelInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  creal_T c3_b_inData[40];
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  creal_T c3_u[40];
  const mxArray *c3_y = NULL;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i21 = 0;
  for (c3_i22 = 0; c3_i22 < 10; c3_i22++) {
    for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
      c3_b_inData[c3_i23 + c3_i21] = (*(creal_T (*)[40])c3_inData)[c3_i23 +
        c3_i21];
    }

    c3_i21 += 4;
  }

  c3_i24 = 0;
  for (c3_i25 = 0; c3_i25 < 10; c3_i25++) {
    for (c3_i26 = 0; c3_i26 < 4; c3_i26++) {
      c3_u[c3_i26 + c3_i24] = c3_b_inData[c3_i26 + c3_i24];
    }

    c3_i24 += 4;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 1U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_signal, const char_T *c3_identifier, creal_T c3_y[40])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_signal), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_signal);
}

static void c3_b_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, creal_T c3_y[40])
{
  creal_T c3_dcv1[40];
  int32_T c3_i27;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dcv1, 1, 0, 1U, 1, 0U, 2, 4,
                10);
  for (c3_i27 = 0; c3_i27 < 40; c3_i27++) {
    c3_y[c3_i27] = c3_dcv1[c3_i27];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_signal;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  creal_T c3_y[40];
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_signal = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_signal), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_signal);
  c3_i28 = 0;
  for (c3_i29 = 0; c3_i29 < 10; c3_i29++) {
    for (c3_i30 = 0; c3_i30 < 4; c3_i30++) {
      (*(creal_T (*)[40])c3_outData)[c3_i30 + c3_i28] = c3_y[c3_i30 + c3_i28];
    }

    c3_i28 += 4;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  creal_T c3_b_inData[16];
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  creal_T c3_u[16];
  const mxArray *c3_y = NULL;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i31 = 0;
  for (c3_i32 = 0; c3_i32 < 4; c3_i32++) {
    for (c3_i33 = 0; c3_i33 < 4; c3_i33++) {
      c3_b_inData[c3_i33 + c3_i31] = (*(creal_T (*)[16])c3_inData)[c3_i33 +
        c3_i31];
    }

    c3_i31 += 4;
  }

  c3_i34 = 0;
  for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
    for (c3_i36 = 0; c3_i36 < 4; c3_i36++) {
      c3_u[c3_i36 + c3_i34] = c3_b_inData[c3_i36 + c3_i34];
    }

    c3_i34 += 4;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 1U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  real_T c3_b_inData[40];
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  real_T c3_u[40];
  const mxArray *c3_y = NULL;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i37 = 0;
  for (c3_i38 = 0; c3_i38 < 10; c3_i38++) {
    for (c3_i39 = 0; c3_i39 < 4; c3_i39++) {
      c3_b_inData[c3_i39 + c3_i37] = (*(real_T (*)[40])c3_inData)[c3_i39 +
        c3_i37];
    }

    c3_i37 += 4;
  }

  c3_i40 = 0;
  for (c3_i41 = 0; c3_i41 < 10; c3_i41++) {
    for (c3_i42 = 0; c3_i42 < 4; c3_i42++) {
      c3_u[c3_i42 + c3_i40] = c3_b_inData[c3_i42 + c3_i40];
    }

    c3_i40 += 4;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 10), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_DPC_Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[9];
  c3_ResolvedFunctionInfo (*c3_b_info)[9];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i43;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[9])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mtimes";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[0].fileTimeLo = 1289503492U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[1].name = "eml_index_class";
  (*c3_b_info)[1].dominantType = "";
  (*c3_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c3_b_info)[1].fileTimeLo = 1323154378U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[2].name = "eml_scalar_eg";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[2].fileTimeLo = 1286806196U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[3].name = "eml_xgemm";
  (*c3_b_info)[3].dominantType = "char";
  (*c3_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c3_b_info)[3].fileTimeLo = 1299060572U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c3_b_info)[4].name = "eml_blas_inline";
  (*c3_b_info)[4].dominantType = "";
  (*c3_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c3_b_info)[4].fileTimeLo = 1299060568U;
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c3_b_info)[5].name = "mtimes";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[5].fileTimeLo = 1289503492U;
  (*c3_b_info)[5].fileTimeHi = 0U;
  (*c3_b_info)[5].mFileTimeLo = 0U;
  (*c3_b_info)[5].mFileTimeHi = 0U;
  (*c3_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c3_b_info)[6].name = "eml_index_class";
  (*c3_b_info)[6].dominantType = "";
  (*c3_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c3_b_info)[6].fileTimeLo = 1323154378U;
  (*c3_b_info)[6].fileTimeHi = 0U;
  (*c3_b_info)[6].mFileTimeLo = 0U;
  (*c3_b_info)[6].mFileTimeHi = 0U;
  (*c3_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c3_b_info)[7].name = "eml_scalar_eg";
  (*c3_b_info)[7].dominantType = "double";
  (*c3_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[7].fileTimeLo = 1286806196U;
  (*c3_b_info)[7].fileTimeHi = 0U;
  (*c3_b_info)[7].mFileTimeLo = 0U;
  (*c3_b_info)[7].mFileTimeHi = 0U;
  (*c3_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c3_b_info)[8].name = "eml_refblas_xgemm";
  (*c3_b_info)[8].dominantType = "char";
  (*c3_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c3_b_info)[8].fileTimeLo = 1299060574U;
  (*c3_b_info)[8].fileTimeHi = 0U;
  (*c3_b_info)[8].mFileTimeLo = 0U;
  (*c3_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c3_i43 = 0; c3_i43 < 9; c3_i43++) {
    c3_r0 = &c3_info[c3_i43];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i43);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i43);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i43);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i43);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i43);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i43);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i43);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i43);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_eml_scalar_eg(SFc3_DPC_ModelInstanceStruct *chartInstance)
{
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i44;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i44, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i44;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_DPC_Model, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_DPC_Model), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_DPC_Model);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_DPC_ModelInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_DPC_ModelInstanceStruct *chartInstance)
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

void sf_c3_DPC_Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(953033078U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2026665989U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2352330941U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3257124453U);
}

mxArray *sf_c3_DPC_Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("cHhyTJ7a03Imyr0IBCVCNF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

mxArray *sf_c3_DPC_Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_DPC_Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"signal\",},{M[8],M[0],T\"is_active_c3_DPC_Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_DPC_Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_DPC_ModelInstanceStruct *chartInstance;
    chartInstance = (SFc3_DPC_ModelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DPC_ModelMachineNumber_,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"h1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"signal");
          _SFD_SET_DATA_PROPS(2,1,1,0,"data");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,145);
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
            1.0,0,1,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          creal_T (*c3_h1)[16];
          creal_T (*c3_signal)[40];
          creal_T (*c3_data)[40];
          c3_data = (creal_T (*)[40])ssGetInputPortSignal(chartInstance->S, 1);
          c3_signal = (creal_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_h1 = (creal_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_h1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_signal);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_data);
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
  return "9gd2C0d8pwSvXbakFUy2LE";
}

static void sf_opaque_initialize_c3_DPC_Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*)
    chartInstanceVar);
  initialize_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_DPC_Model(void *chartInstanceVar)
{
  enable_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_DPC_Model(void *chartInstanceVar)
{
  disable_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_DPC_Model(void *chartInstanceVar)
{
  sf_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_DPC_Model(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_DPC_Model();/* state var info */
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

extern void sf_internal_set_sim_state_c3_DPC_Model(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_DPC_Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_DPC_Model(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_DPC_Model(S);
}

static void sf_opaque_set_sim_state_c3_DPC_Model(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_DPC_Model(S, st);
}

static void sf_opaque_terminate_c3_DPC_Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DPC_Model_optimization_info();
    }

    finalize_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_DPC_Model((SFc3_DPC_ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_DPC_Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_DPC_Model((SFc3_DPC_ModelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DPC_Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3525213887U));
  ssSetChecksum1(S,(2889820148U));
  ssSetChecksum2(S,(488222972U));
  ssSetChecksum3(S,(2105437201U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_DPC_Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_DPC_Model(SimStruct *S)
{
  SFc3_DPC_ModelInstanceStruct *chartInstance;
  chartInstance = (SFc3_DPC_ModelInstanceStruct *)utMalloc(sizeof
    (SFc3_DPC_ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_DPC_ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_DPC_Model;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_DPC_Model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_DPC_Model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_DPC_Model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_DPC_Model;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_DPC_Model;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_DPC_Model;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_DPC_Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_DPC_Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_DPC_Model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_DPC_Model;
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

void c3_DPC_Model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_DPC_Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_DPC_Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_DPC_Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_DPC_Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
