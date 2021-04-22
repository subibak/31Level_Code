/*
 * Bypass.c
 *
 *  Created on: 2018. 9. 6.
 *      Author: subi
 */

#include "Define_Header.h"

Uint16 RELAY_OP = 0;
Uint16 IGBT_OP = 0;

Uint16 Flag_Relay[6] = {0,0,0,0,0,0};
Uint16 Flag_IGBT[6] = {0,0,0,0,0,0};
Uint16 Flag_Bypass =0;

void BYPASSING(void)
{
    RELAY_OP = 0;
    IGBT_OP = 0;
    for(k = 0; k < 6; k++)
    {
        RELAY_OP = RELAY_OP | (((Uint16)Flag_Relay[k]) << k);
        IGBT_OP = IGBT_OP | (((Uint16)Flag_IGBT[k]) << k);
    }

    if (RELAY_OP | IGBT_OP)
    {
        Flag_Buffer_HW[1] = 1;
        Flag_Buffer_HW[2] = 1;
    }

    *BYPASS_RELAY = RELAY_OP;
    *BYPASS_IGBT = IGBT_OP;

    Dsp2EcatMaster.Bypass.bit.SM1_IGBT = Flag_IGBT[0];
    Dsp2EcatMaster.Bypass.bit.SM2_IGBT = Flag_IGBT[1];
    Dsp2EcatMaster.Bypass.bit.SM3_IGBT = Flag_IGBT[2];
    Dsp2EcatMaster.Bypass.bit.SM4_IGBT = Flag_IGBT[3];
    Dsp2EcatMaster.Bypass.bit.SM5_IGBT = Flag_IGBT[4];
    Dsp2EcatMaster.Bypass.bit.SM6_IGBT = Flag_IGBT[5];

    Dsp2EcatMaster.Bypass.bit.SM1_RELAY = Flag_Relay[0];
    Dsp2EcatMaster.Bypass.bit.SM2_RELAY = Flag_Relay[1];
    Dsp2EcatMaster.Bypass.bit.SM3_RELAY = Flag_Relay[2];
    Dsp2EcatMaster.Bypass.bit.SM4_RELAY = Flag_Relay[3];
    Dsp2EcatMaster.Bypass.bit.SM5_RELAY = Flag_Relay[4];
    Dsp2EcatMaster.Bypass.bit.SM6_RELAY = Flag_Relay[5];

    return;
}


