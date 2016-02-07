#include "__cf_DPC_Model.h"
#include <math.h>
#include "DPC_Model_acc.h"
#include "DPC_Model_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
void RandSrcInitState_U_64 ( const uint32_T seed [ ] , real_T state [ ] ,
int32_T nChans ) { int32_T i ; uint32_T j ; int32_T k ; int32_T n ; real_T d
; for ( i = 0 ; i < nChans ; i ++ ) { j = seed [ i ] != 0U ? seed [ i ] :
2147483648U ; state [ 35 * i + 34 ] = j ; for ( k = 0 ; k < 32 ; k ++ ) { d =
0.0 ; for ( n = 0 ; n < 53 ; n ++ ) { j ^= j << 13 ; j ^= j >> 17 ; j ^= j <<
5 ; d = ( real_T ) ( ( int32_T ) ( j >> 19 ) & 1 ) + ( d + d ) ; } state [ 35
* i + k ] = ldexp ( d , - 53 ) ; } state [ 35 * i + 32 ] = 0.0 ; state [ 35 *
i + 33 ] = 0.0 ; } } void RandSrc_U_D ( real_T y [ ] , const real_T minVec [
] , int32_T minLen , const real_T maxVec [ ] , int32_T maxLen , real_T state
[ ] , int32_T nChans , int32_T nSamps ) { int32_T one ; int32_T lsw ; int8_T
( * onePtr ) [ ] ; int32_T chan ; real_T min ; real_T max ; int32_T samps ;
real_T d ; int32_T i ; uint32_T j ; one = 1 ; onePtr = ( int8_T ( * ) [ ] ) &
one ; lsw = ( ( * onePtr ) [ 0U ] == 0 ) ; for ( chan = 0 ; chan < nChans ;
chan ++ ) { min = minVec [ minLen > 1 ? chan : 0 ] ; max = maxVec [ maxLen >
1 ? chan : 0 ] ; max -= min ; i = ( int32_T ) ( ( uint32_T ) state [ chan *
35 + 33 ] & 31U ) ; j = ( uint32_T ) state [ chan * 35 + 34 ] ; for ( samps =
0 ; samps < nSamps ; samps ++ ) { d = state [ ( ( i + 20 ) & 31 ) + chan * 35
] ; d -= state [ ( ( i + 5 ) & 31 ) + chan * 35 ] ; d -= state [ chan * 35 +
32 ] ; if ( d >= 0.0 ) { state [ chan * 35 + 32 ] = 0.0 ; } else { d ++ ;
state [ chan * 35 + 32 ] = 1.1102230246251565E-16 ; } state [ chan * 35 + i ]
= d ; i = ( i + 1 ) & 31 ; ( * ( int32_T ( * ) [ ] ) & d ) [ lsw ] ^= j ; j
^= j << 13 ; j ^= j >> 17 ; j ^= j << 5 ; ( * ( int32_T ( * ) [ ] ) & d ) [
lsw ^ 1 ] ^= j & 1048575U ; y [ chan * nSamps + samps ] = max * d + min ; }
state [ chan * 35 + 33 ] = i ; state [ chan * 35 + 34 ] = j ; } } static void
mdlOutputs ( SimStruct * S , int_T tid ) { int32_T inIdx ; int32_T outIdx ;
int32_T symbolIndex ; int32_T m ; real_T err ; real_T sym ; real_T ratio ;
real_T B_4_13_0 [ 80 ] ; real_T B_4_2_0 [ 80 ] ; int32_T i ; B_DPC_Model_T *
_rtB ; P_DPC_Model_T * _rtP ; DW_DPC_Model_T * _rtDW ; _rtDW = ( (
DW_DPC_Model_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_DPC_Model_T * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_DPC_Model_T * ) _ssGetBlockIO ( S )
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { RandSrc_U_D ( B_4_2_0 , & _rtP ->
P_0 , 1 , & _rtP -> P_1 , 1 , _rtDW -> RandomSource_STATE_DWORK , 1 , 80 ) ;
for ( i = 0 ; i < 80 ; i ++ ) { B_4_13_0 [ i ] = _rtP -> P_2 [ i ] ; B_4_2_0
[ i ] = ( B_4_2_0 [ i ] > _rtP -> P_2 [ i ] ) ; } inIdx = 0 ; outIdx = 0 ;
for ( i = 0 ; i < 40 ; i ++ ) { err = B_4_2_0 [ inIdx ] ; inIdx ++ ;
symbolIndex = ( int32_T ) muDoubleScalarFloor ( err ) << 1 ; err = B_4_2_0 [
inIdx ] ; inIdx ++ ; symbolIndex += ( int32_T ) muDoubleScalarFloor ( err ) ;
m = 1 ; while ( m < 2 ) { symbolIndex ^= symbolIndex >> 1 ; m = 2 ; } _rtB ->
B_4_3_0 [ outIdx ] . re = DPC_Model_rtConstP . MPSKModulatorBaseband_modmap [
( symbolIndex << 1 ) ] ; _rtB -> B_4_3_0 [ outIdx ] . im = DPC_Model_rtConstP
. MPSKModulatorBaseband_modmap [ ( symbolIndex << 1 ) + 1 ] ; outIdx ++ ; }
_rtB -> B_4_4_0 = _rtP -> P_3 ; _rtB -> B_4_5_0 = _rtP -> P_4 ;
ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_8_0 = _rtP -> P_5 ;
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i <
16 ; i ++ ) { _rtB -> B_4_11_0 [ i ] . re = 0.0 ; _rtB -> B_4_11_0 [ i ] . im
= 0.0 ; } _rtB -> B_4_11_0 [ 0 ] . re = _rtB -> B_2_0_3 [ 0 ] . re ; _rtB ->
B_4_11_0 [ 0 ] . im = _rtB -> B_2_0_3 [ 0 ] . im ; _rtB -> B_4_11_0 [ 5 ] .
re = _rtB -> B_2_0_3 [ 5 ] . re ; _rtB -> B_4_11_0 [ 5 ] . im = _rtB ->
B_2_0_3 [ 5 ] . im ; _rtB -> B_4_11_0 [ 10 ] . re = _rtB -> B_2_0_3 [ 10 ] .
re ; _rtB -> B_4_11_0 [ 10 ] . im = _rtB -> B_2_0_3 [ 10 ] . im ; _rtB ->
B_4_11_0 [ 15 ] . re = _rtB -> B_2_0_3 [ 15 ] . re ; _rtB -> B_4_11_0 [ 15 ]
. im = _rtB -> B_2_0_3 [ 15 ] . im ; ssCallAccelRunBlock ( S , 3 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; for ( outIdx = 0 ; outIdx < 40 ; outIdx ++ ) { if (
_rtB -> B_3_0_1 [ outIdx ] . re > 0.0 ) { if ( _rtB -> B_3_0_1 [ outIdx ] .
im >= 0.0 ) { symbolIndex = 0 ; } else { symbolIndex = 3 ; } } else if ( _rtB
-> B_3_0_1 [ outIdx ] . re < 0.0 ) { if ( _rtB -> B_3_0_1 [ outIdx ] . im <=
0.0 ) { symbolIndex = 2 ; } else { symbolIndex = 1 ; } } else if ( _rtB ->
B_3_0_1 [ outIdx ] . im < 0.0 ) { symbolIndex = 3 ; } else if ( _rtB ->
B_3_0_1 [ outIdx ] . im > 0.0 ) { symbolIndex = 1 ; } else { symbolIndex = 0
; } inIdx = symbolIndex >> 1 ^ symbolIndex ; B_4_13_0 [ ( outIdx << 1 ) + 1 ]
= inIdx % 2 ; inIdx >>= 1 ; B_4_13_0 [ outIdx << 1 ] = inIdx % 2 ; } err =
0.0 ; sym = 0.0 ; ratio = 0.0 ; for ( inIdx = 0 ; inIdx < 80 ; inIdx ++ ) {
_rtDW -> txBuff = B_4_2_0 [ inIdx ] ; if ( _rtDW -> curTx == 0 ) { _rtDW ->
curTx = 0 ; } else { _rtDW -> curTx ++ ; } if ( _rtDW -> STDelay < 0 ) {
_rtDW -> STDelay ++ ; } else { if ( _rtDW -> useFrame [ inIdx ] ) { sym ++ ;
if ( _rtDW -> txBuff != B_4_13_0 [ inIdx ] ) { err ++ ; } } } } _rtDW ->
symbols += sym ; _rtDW -> errors += err ; if ( _rtDW -> symbols > 0.0 ) {
ratio = _rtDW -> errors / _rtDW -> symbols ; } _rtB -> B_4_14_0 [ 0U ] =
ratio ; _rtB -> B_4_14_0 [ 1U ] = _rtDW -> errors ; _rtB -> B_4_14_0 [ 2U ] =
_rtDW -> symbols ; ssCallAccelRunBlock ( S , 4 , 15 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 16 , SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER ( tid
) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S
, 0 , 3322976325U ) ; ssSetChecksumVal ( S , 1 , 3563923875U ) ;
ssSetChecksumVal ( S , 2 , 321600468U ) ; ssSetChecksumVal ( S , 3 ,
1285237352U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.1" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_DPC_Model_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_DPC_Model_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_DPC_Model_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & DPC_Model_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) )
; } static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct *
childS ; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
