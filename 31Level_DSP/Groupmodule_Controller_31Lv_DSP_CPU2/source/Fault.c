/*
 * Fault.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 *  Revised on: 2018. 9. 29
 *     Reviser: subi
 */


#include "Define_Header.h"

float SM_VOL_UNDER_Limit = 90;
float SM_VOL_OVER_LIMIT = 90;
float TEMP_LIMIT = 70;

union Flag_Fault_DATA FlagFault;

void Fault(void)
{

    if(V_SM[0] > SM_VOL_OVER_LIMIT)    FlagFault.bit.V_SM1 = 1;
    else                        FlagFault.bit.V_SM1 = 0;
    if(V_SM[1] > SM_VOL_OVER_LIMIT)    FlagFault.bit.V_SM2 = 1;
    else                        FlagFault.bit.V_SM2 = 0;
    if(V_SM[2] > SM_VOL_OVER_LIMIT)    FlagFault.bit.V_SM3 = 1;
    else                        FlagFault.bit.V_SM3 = 0;
    if(V_SM[3] > SM_VOL_OVER_LIMIT)    FlagFault.bit.V_SM4 = 1;
    else                        FlagFault.bit.V_SM4 = 0;
    if(V_SM[4] > SM_VOL_OVER_LIMIT)    FlagFault.bit.V_SM5 = 1;
    else                        FlagFault.bit.V_SM5 = 0;
    if(V_SM[5] > SM_VOL_OVER_LIMIT)    FlagFault.bit.V_SM6 = 1;
    else                        FlagFault.bit.V_SM6 = 0;

    if(Temp[0] > TEMP_LIMIT)      FlagFault.bit.TEMP1 = 1;
    else                        FlagFault.bit.TEMP1 = 0;
    if(Temp[1] > TEMP_LIMIT)      FlagFault.bit.TEMP2 = 1;
    else                        FlagFault.bit.TEMP2 = 0;
    if(Temp[2] > TEMP_LIMIT)      FlagFault.bit.TEMP3 = 1;
    else                        FlagFault.bit.TEMP3 = 0;
    if(Temp[3] > TEMP_LIMIT)      FlagFault.bit.TEMP4 = 1;
    else                        FlagFault.bit.TEMP4 = 0;
    if(Temp[4] > TEMP_LIMIT)      FlagFault.bit.TEMP5 = 1;
    else                        FlagFault.bit.TEMP5 = 0;
    if(Temp[5] > TEMP_LIMIT)      FlagFault.bit.TEMP6 = 1;
    else                        FlagFault.bit.TEMP6 = 0;
    if(Temp[6] > TEMP_LIMIT)      FlagFault.bit.TEMP7 = 1;
    else                        FlagFault.bit.TEMP7 = 0;
    if(Temp[7] > TEMP_LIMIT)      FlagFault.bit.TEMP8 = 1;
    else                        FlagFault.bit.TEMP8 = 0;
    if(Temp[8] > TEMP_LIMIT)      FlagFault.bit.TEMP9 = 1;
    else                        FlagFault.bit.TEMP9 = 0;
    if(Temp[9] > TEMP_LIMIT)      FlagFault.bit.TEMP10 = 1;
    else                        FlagFault.bit.TEMP10 = 0;
    if(Temp[10] > TEMP_LIMIT)     FlagFault.bit.TEMP11 = 1;
    else                        FlagFault.bit.TEMP11 = 0;
    if(Temp[11] > TEMP_LIMIT)     FlagFault.bit.TEMP12 = 1;
    else                        FlagFault.bit.TEMP12 = 0;

    Dsp2EcatSlave.Fault.all = FlagFault.all;

    return;
}
