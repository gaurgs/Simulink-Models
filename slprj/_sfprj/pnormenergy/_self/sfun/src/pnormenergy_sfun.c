/* Include files */

#include "pnormenergy_sfun.h"
#include "pnormenergy_sfun_debug_macros.h"
#include "c1_pnormenergy.h"
#include "c2_pnormenergy.h"
#include "c3_pnormenergy.h"
#include "c4_pnormenergy.h"
#include "c5_pnormenergy.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _pnormenergyMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void pnormenergy_initializer(void)
{
}

void pnormenergy_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_pnormenergy_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_pnormenergy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_pnormenergy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_pnormenergy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_pnormenergy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_pnormenergy_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_pnormenergy_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564838635U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2288118608U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4108389758U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1335621850U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4083179411U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1365739049U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1154896047U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1669023648U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_pnormenergy_get_check_sum(mxArray *plhs[]);
          sf_c1_pnormenergy_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_pnormenergy_get_check_sum(mxArray *plhs[]);
          sf_c2_pnormenergy_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_pnormenergy_get_check_sum(mxArray *plhs[]);
          sf_c3_pnormenergy_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_pnormenergy_get_check_sum(mxArray *plhs[]);
          sf_c4_pnormenergy_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_pnormenergy_get_check_sum(mxArray *plhs[]);
          sf_c5_pnormenergy_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2134163714U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2653501950U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3730741618U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4018767677U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_pnormenergy_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "Zi0gbFICSf5UdxGX3Ts7QB") == 0) {
          extern mxArray *sf_c1_pnormenergy_get_autoinheritance_info(void);
          plhs[0] = sf_c1_pnormenergy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "DFLLTYt9MRjJzwyTUDGUGG") == 0) {
          extern mxArray *sf_c2_pnormenergy_get_autoinheritance_info(void);
          plhs[0] = sf_c2_pnormenergy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "cWJcuEWyhR5qtP0yEt3JWC") == 0) {
          extern mxArray *sf_c3_pnormenergy_get_autoinheritance_info(void);
          plhs[0] = sf_c3_pnormenergy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "jozjiXcBOdUGwkbtttrBqC") == 0) {
          extern mxArray *sf_c4_pnormenergy_get_autoinheritance_info(void);
          plhs[0] = sf_c4_pnormenergy_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "kHjvT1kshAVklCb4HBx1qE") == 0) {
          extern mxArray *sf_c5_pnormenergy_get_autoinheritance_info(void);
          plhs[0] = sf_c5_pnormenergy_get_autoinheritance_info();
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

unsigned int sf_pnormenergy_get_eml_resolved_functions_info( int nlhs, mxArray *
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
        extern const mxArray *sf_c1_pnormenergy_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_pnormenergy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_pnormenergy_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_pnormenergy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_pnormenergy_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_pnormenergy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_pnormenergy_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_pnormenergy_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_pnormenergy_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_pnormenergy_get_eml_resolved_functions_info();
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

unsigned int sf_pnormenergy_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "B29x3CfHJJMSzESyVAtnJ") == 0) {
          extern mxArray *sf_c1_pnormenergy_third_party_uses_info(void);
          plhs[0] = sf_c1_pnormenergy_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "FDYqvISR5fyXgcdCpppTaG") == 0) {
          extern mxArray *sf_c2_pnormenergy_third_party_uses_info(void);
          plhs[0] = sf_c2_pnormenergy_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "VqLAst3tkkXm8lauBWHvmG") == 0) {
          extern mxArray *sf_c3_pnormenergy_third_party_uses_info(void);
          plhs[0] = sf_c3_pnormenergy_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "eCNMETS0VqNWAHHmDjTWAE") == 0) {
          extern mxArray *sf_c4_pnormenergy_third_party_uses_info(void);
          plhs[0] = sf_c4_pnormenergy_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wDcHyzuMMWqn6qE6A5HxDC") == 0) {
          extern mxArray *sf_c5_pnormenergy_third_party_uses_info(void);
          plhs[0] = sf_c5_pnormenergy_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void pnormenergy_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _pnormenergyMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "pnormenergy","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_pnormenergyMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_pnormenergyMachineNumber_,
    0);
}

void pnormenergy_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_pnormenergy_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("pnormenergy",
      "pnormenergy");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_pnormenergy_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
