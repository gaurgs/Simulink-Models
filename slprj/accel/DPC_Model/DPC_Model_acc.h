#include "__cf_DPC_Model.h"
#ifndef RTW_HEADER_DPC_Model_acc_h_
#define RTW_HEADER_DPC_Model_acc_h_
#ifndef DPC_Model_acc_COMMON_INCLUDES_
#define DPC_Model_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "DPC_Model_acc_types.h"
typedef struct { creal_T B_4_3_0 [ 40 ] ; creal_T B_4_11_0 [ 16 ] ; creal_T
B_3_0_1 [ 40 ] ; creal_T B_2_0_1 [ 16 ] ; creal_T B_2_0_2 [ 40 ] ; creal_T
B_2_0_3 [ 16 ] ; creal_T B_1_0_1 [ 40 ] ; creal_T B_0_0_1 [ 40 ] ; real_T
B_4_4_0 ; real_T B_4_5_0 ; real_T B_4_8_0 ; real_T B_4_14_0 [ 3 ] ; }
B_DPC_Model_T ; typedef struct { real_T errors ; real_T symbols ; real_T
txBuff ; real_T RandomSource_STATE_DWORK [ 35 ] ; void * Result_PWORK ;
int32_T STDelay ; int32_T curTx ; uint32_T RandomSource_SEED_DWORK ;
boolean_T useFrame [ 80 ] ; char pad_useFrame [ 4 ] ; } DW_DPC_Model_T ;
typedef struct { real_T MPSKModulatorBaseband_modmap [ 8 ] ; }
ConstP_DPC_Model_T ; struct P_DPC_Model_T_ { real_T P_0 ; real_T P_1 ; real_T
P_2 [ 80 ] ; real_T P_3 ; real_T P_4 ; real_T P_5 ; uint32_T P_6 ; char
pad_P_6 [ 4 ] ; } ; extern P_DPC_Model_T DPC_Model_rtDefaultP ; extern const
ConstP_DPC_Model_T DPC_Model_rtConstP ;
#endif
