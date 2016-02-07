/* Include files */

#include "BPSK_Embedded_sfun.h"
#include "BPSK_Embedded_sfun_debug_macros.h"
#include "c1_BPSK_Embedded.h"
#include "c2_BPSK_Embedded.h"
#include "c3_BPSK_Embedded.h"
#include "c4_BPSK_Embedded.h"
#include "c5_BPSK_Embedded.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _BPSK_EmbeddedMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void BPSK_Embedded_initializer(void)
{
}

void BPSK_Embedded_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_BPSK_Embedded_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_BPSK_Embedded_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_BPSK_Embedded_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_BPSK_Embedded_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_BPSK_Embedded_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_BPSK_Embedded_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_BPSK_Embedded_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(953612215U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1594683134U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2576884388U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1337169703U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2439411102U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2414084983U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(648280060U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(739569907U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_BPSK_Embedded_get_check_sum(mxArray *plhs[]);
          sf_c1_BPSK_Embedded_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_BPSK_Embedded_get_check_sum(mxArray *plhs[]);
          sf_c2_BPSK_Embedded_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_BPSK_Embedded_get_check_sum(mxArray *plhs[]);
          sf_c3_BPSK_Embedded_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_BPSK_Embedded_get_check_sum(mxArray *plhs[]);
          sf_c4_BPSK_Embedded_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_BPSK_Embedded_get_check_sum(mxArray *plhs[]);
          sf_c5_BPSK_Embedded_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1023841270U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1396568799U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3281839181U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3163784533U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BPSK_Embedded_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "mUbDTzmrzScsUhxgJ0Kcf") == 0) {
          extern mxArray *sf_c1_BPSK_Embedded_get_autoinheritance_info(void);
          plhs[0] = sf_c1_BPSK_Embedded_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "cU05DaLr4SchkqBKsyW5nD") == 0) {
          extern mxArray *sf_c2_BPSK_Embedded_get_autoinheritance_info(void);
          plhs[0] = sf_c2_BPSK_Embedded_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "Q1mlYa97dYfd05zRKG1lHF") == 0) {
          extern mxArray *sf_c3_BPSK_Embedded_get_autoinheritance_info(void);
          plhs[0] = sf_c3_BPSK_Embedded_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "5RAQOHI4AYx1r8qF1axZmH") == 0) {
          extern mxArray *sf_c4_BPSK_Embedded_get_autoinheritance_info(void);
          plhs[0] = sf_c4_BPSK_Embedded_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "VA9NDQY04fXTMIEvzBpWBH") == 0) {
          extern mxArray *sf_c5_BPSK_Embedded_get_autoinheritance_info(void);
          plhs[0] = sf_c5_BPSK_Embedded_get_autoinheritance_info();
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

unsigned int sf_BPSK_Embedded_get_eml_resolved_functions_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray
          *sf_c1_BPSK_Embedded_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_BPSK_Embedded_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_BPSK_Embedded_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_BPSK_Embedded_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_BPSK_Embedded_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_BPSK_Embedded_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_BPSK_Embedded_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_BPSK_Embedded_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_BPSK_Embedded_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_BPSK_Embedded_get_eml_resolved_functions_info();
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

unsigned int sf_BPSK_Embedded_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "36u2a68vB92szA9rmEZ9KD") == 0) {
          extern mxArray *sf_c1_BPSK_Embedded_third_party_uses_info(void);
          plhs[0] = sf_c1_BPSK_Embedded_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "HKnar0AVVqwzKpIz0lsIsD") == 0) {
          extern mxArray *sf_c2_BPSK_Embedded_third_party_uses_info(void);
          plhs[0] = sf_c2_BPSK_Embedded_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "5VMnIzls1QwlAoO7qBCd5D") == 0) {
          extern mxArray *sf_c3_BPSK_Embedded_third_party_uses_info(void);
          plhs[0] = sf_c3_BPSK_Embedded_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "aPofulJMYTAUWDfs44z3AB") == 0) {
          extern mxArray *sf_c4_BPSK_Embedded_third_party_uses_info(void);
          plhs[0] = sf_c4_BPSK_Embedded_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "8MIEoEH4txmSXeZsEmaIxE") == 0) {
          extern mxArray *sf_c5_BPSK_Embedded_third_party_uses_info(void);
          plhs[0] = sf_c5_BPSK_Embedded_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void BPSK_Embedded_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _BPSK_EmbeddedMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "BPSK_Embedded","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _BPSK_EmbeddedMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _BPSK_EmbeddedMachineNumber_,0);
}

void BPSK_Embedded_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_BPSK_Embedded_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("BPSK_Embedded",
      "BPSK_Embedded");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_BPSK_Embedded_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
