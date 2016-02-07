/* Include files */

#include "SDR_Lowpass_sfun.h"
#include "SDR_Lowpass_sfun_debug_macros.h"
#include "c1_SDR_Lowpass.h"
#include "c2_SDR_Lowpass.h"
#include "c3_SDR_Lowpass.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SDR_LowpassMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void SDR_Lowpass_initializer(void)
{
}

void SDR_Lowpass_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SDR_Lowpass_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_SDR_Lowpass_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_SDR_Lowpass_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SDR_Lowpass_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SDR_Lowpass_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3414927527U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3050620954U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(643391198U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3024796272U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1761845505U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3674069297U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1768250587U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2152265298U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SDR_Lowpass_get_check_sum(mxArray *plhs[]);
          sf_c1_SDR_Lowpass_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_SDR_Lowpass_get_check_sum(mxArray *plhs[]);
          sf_c2_SDR_Lowpass_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SDR_Lowpass_get_check_sum(mxArray *plhs[]);
          sf_c3_SDR_Lowpass_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(704186288U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3339105040U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1788994246U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2309445510U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SDR_Lowpass_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "2y3awVZaSZ79zEV0sNQNrH") == 0) {
          extern mxArray *sf_c1_SDR_Lowpass_get_autoinheritance_info(void);
          plhs[0] = sf_c1_SDR_Lowpass_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "yAgbUiEaioLfUpSt4SVPFD") == 0) {
          extern mxArray *sf_c2_SDR_Lowpass_get_autoinheritance_info(void);
          plhs[0] = sf_c2_SDR_Lowpass_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "cWJcuEWyhR5qtP0yEt3JWC") == 0) {
          extern mxArray *sf_c3_SDR_Lowpass_get_autoinheritance_info(void);
          plhs[0] = sf_c3_SDR_Lowpass_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SDR_Lowpass_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_SDR_Lowpass_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SDR_Lowpass_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_SDR_Lowpass_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_SDR_Lowpass_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_SDR_Lowpass_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SDR_Lowpass_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SDR_Lowpass_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "6pIYeK2IEu53vx5cEtW3kG") == 0) {
          extern mxArray *sf_c1_SDR_Lowpass_third_party_uses_info(void);
          plhs[0] = sf_c1_SDR_Lowpass_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "JpNuTXX5j5SETDYPPPDd0C") == 0) {
          extern mxArray *sf_c2_SDR_Lowpass_third_party_uses_info(void);
          plhs[0] = sf_c2_SDR_Lowpass_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "VqLAst3tkkXm8lauBWHvmG") == 0) {
          extern mxArray *sf_c3_SDR_Lowpass_third_party_uses_info(void);
          plhs[0] = sf_c3_SDR_Lowpass_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void SDR_Lowpass_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _SDR_LowpassMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "SDR_Lowpass","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_SDR_LowpassMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_SDR_LowpassMachineNumber_,
    0);
}

void SDR_Lowpass_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SDR_Lowpass_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("SDR_Lowpass",
      "SDR_Lowpass");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SDR_Lowpass_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
