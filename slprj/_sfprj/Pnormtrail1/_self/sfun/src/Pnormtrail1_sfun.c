/* Include files */

#include "Pnormtrail1_sfun.h"
#include "Pnormtrail1_sfun_debug_macros.h"
#include "c1_Pnormtrail1.h"
#include "c2_Pnormtrail1.h"
#include "c3_Pnormtrail1.h"
#include "c4_Pnormtrail1.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Pnormtrail1MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Pnormtrail1_initializer(void)
{
}

void Pnormtrail1_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Pnormtrail1_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Pnormtrail1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Pnormtrail1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Pnormtrail1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Pnormtrail1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Pnormtrail1_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3942883486U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1887326352U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2023796111U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(162602531U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3069979659U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3991796138U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3816430326U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1461173986U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Pnormtrail1_get_check_sum(mxArray *plhs[]);
          sf_c1_Pnormtrail1_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Pnormtrail1_get_check_sum(mxArray *plhs[]);
          sf_c2_Pnormtrail1_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Pnormtrail1_get_check_sum(mxArray *plhs[]);
          sf_c3_Pnormtrail1_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Pnormtrail1_get_check_sum(mxArray *plhs[]);
          sf_c4_Pnormtrail1_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(91201351U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1893825567U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(298961540U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(467877135U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Pnormtrail1_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "h0a63r10rtCFFSMpfoFUuB") == 0) {
          extern mxArray *sf_c1_Pnormtrail1_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Pnormtrail1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "Nbjt4tgEA52gTyTDsJWVqB") == 0) {
          extern mxArray *sf_c2_Pnormtrail1_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Pnormtrail1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "cWJcuEWyhR5qtP0yEt3JWC") == 0) {
          extern mxArray *sf_c3_Pnormtrail1_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Pnormtrail1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "EZH4ImnO90sDswPYCvNSlE") == 0) {
          extern mxArray *sf_c4_Pnormtrail1_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Pnormtrail1_get_autoinheritance_info();
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

unsigned int sf_Pnormtrail1_get_eml_resolved_functions_info( int nlhs, mxArray *
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
        extern const mxArray *sf_c1_Pnormtrail1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Pnormtrail1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_Pnormtrail1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Pnormtrail1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_Pnormtrail1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Pnormtrail1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_Pnormtrail1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Pnormtrail1_get_eml_resolved_functions_info();
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

unsigned int sf_Pnormtrail1_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "p197Im0upp8ehZrZDp1h8C") == 0) {
          extern mxArray *sf_c1_Pnormtrail1_third_party_uses_info(void);
          plhs[0] = sf_c1_Pnormtrail1_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "FboYjGKNqpyYKo2kVhpwBD") == 0) {
          extern mxArray *sf_c2_Pnormtrail1_third_party_uses_info(void);
          plhs[0] = sf_c2_Pnormtrail1_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "VqLAst3tkkXm8lauBWHvmG") == 0) {
          extern mxArray *sf_c3_Pnormtrail1_third_party_uses_info(void);
          plhs[0] = sf_c3_Pnormtrail1_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "y015yCYxAIpSodtGkHDEdC") == 0) {
          extern mxArray *sf_c4_Pnormtrail1_third_party_uses_info(void);
          plhs[0] = sf_c4_Pnormtrail1_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Pnormtrail1_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Pnormtrail1MachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Pnormtrail1","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_Pnormtrail1MachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_Pnormtrail1MachineNumber_,
    0);
}

void Pnormtrail1_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Pnormtrail1_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Pnormtrail1",
      "Pnormtrail1");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Pnormtrail1_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
