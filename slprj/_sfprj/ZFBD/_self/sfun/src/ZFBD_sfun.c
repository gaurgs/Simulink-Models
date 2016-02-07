/* Include files */

#include "ZFBD_sfun.h"
#include "ZFBD_sfun_debug_macros.h"
#include "c1_ZFBD.h"
#include "c2_ZFBD.h"
#include "c3_ZFBD.h"
#include "c4_ZFBD.h"
#include "c5_ZFBD.h"
#include "c6_ZFBD.h"
#include "c7_ZFBD.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ZFBDMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void ZFBD_initializer(void)
{
}

void ZFBD_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ZFBD_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_ZFBD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_ZFBD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_ZFBD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_ZFBD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_ZFBD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_ZFBD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_ZFBD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ZFBD_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(369658106U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3687049554U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1814734326U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1338277342U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3928056732U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2431573586U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2458416890U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3869092816U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_ZFBD_get_check_sum(mxArray *plhs[]);
          sf_c1_ZFBD_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_ZFBD_get_check_sum(mxArray *plhs[]);
          sf_c2_ZFBD_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_ZFBD_get_check_sum(mxArray *plhs[]);
          sf_c3_ZFBD_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_ZFBD_get_check_sum(mxArray *plhs[]);
          sf_c4_ZFBD_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_ZFBD_get_check_sum(mxArray *plhs[]);
          sf_c5_ZFBD_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_ZFBD_get_check_sum(mxArray *plhs[]);
          sf_c6_ZFBD_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_ZFBD_get_check_sum(mxArray *plhs[]);
          sf_c7_ZFBD_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1455026277U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3035238955U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2174983052U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(439674865U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ZFBD_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "gTl7j3rRMh3Om0rBfx4nc") == 0) {
          extern mxArray *sf_c1_ZFBD_get_autoinheritance_info(void);
          plhs[0] = sf_c1_ZFBD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "hcvzIcisy8lsmNUsQ2SWKE") == 0) {
          extern mxArray *sf_c2_ZFBD_get_autoinheritance_info(void);
          plhs[0] = sf_c2_ZFBD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "NLng3U5k7dzSiqvoSMeu7") == 0) {
          extern mxArray *sf_c3_ZFBD_get_autoinheritance_info(void);
          plhs[0] = sf_c3_ZFBD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "W2xTQpJay1uS4tKAmB0HUD") == 0) {
          extern mxArray *sf_c4_ZFBD_get_autoinheritance_info(void);
          plhs[0] = sf_c4_ZFBD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "Kytmqqv1jTKYuZIH1o1XiE") == 0) {
          extern mxArray *sf_c5_ZFBD_get_autoinheritance_info(void);
          plhs[0] = sf_c5_ZFBD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "m1JglkF9OavHYmD8ht0q5F") == 0) {
          extern mxArray *sf_c6_ZFBD_get_autoinheritance_info(void);
          plhs[0] = sf_c6_ZFBD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "39RovJutyQcxbvLcAYz61B") == 0) {
          extern mxArray *sf_c7_ZFBD_get_autoinheritance_info(void);
          plhs[0] = sf_c7_ZFBD_get_autoinheritance_info();
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

unsigned int sf_ZFBD_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_ZFBD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ZFBD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_ZFBD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_ZFBD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_ZFBD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_ZFBD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_ZFBD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_ZFBD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_ZFBD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_ZFBD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_ZFBD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_ZFBD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_ZFBD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_ZFBD_get_eml_resolved_functions_info();
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

unsigned int sf_ZFBD_third_party_uses_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "XBHSQqyteizHJQ9cqrGinF") == 0) {
          extern mxArray *sf_c1_ZFBD_third_party_uses_info(void);
          plhs[0] = sf_c1_ZFBD_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "2bwo7BOpVaIg61wjA7sDtD") == 0) {
          extern mxArray *sf_c2_ZFBD_third_party_uses_info(void);
          plhs[0] = sf_c2_ZFBD_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "1hPtv39f1X13ibpuHDGv3G") == 0) {
          extern mxArray *sf_c3_ZFBD_third_party_uses_info(void);
          plhs[0] = sf_c3_ZFBD_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "1o0z8zQWMLqSENUbV6eaJC") == 0) {
          extern mxArray *sf_c4_ZFBD_third_party_uses_info(void);
          plhs[0] = sf_c4_ZFBD_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "qMBWWFSQUj5vnHq9rdTz7C") == 0) {
          extern mxArray *sf_c5_ZFBD_third_party_uses_info(void);
          plhs[0] = sf_c5_ZFBD_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vBWTfkCrj5cZLRh2msbBx") == 0) {
          extern mxArray *sf_c6_ZFBD_third_party_uses_info(void);
          plhs[0] = sf_c6_ZFBD_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "dkO5kHaJW4fwFvEYmcfcpC") == 0) {
          extern mxArray *sf_c7_ZFBD_third_party_uses_info(void);
          plhs[0] = sf_c7_ZFBD_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ZFBD_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _ZFBDMachineNumber_ = sf_debug_initialize_machine(debugInstance,"ZFBD","sfun",
    0,7,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_ZFBDMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_ZFBDMachineNumber_,0);
}

void ZFBD_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ZFBD_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("ZFBD", "ZFBD");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ZFBD_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
