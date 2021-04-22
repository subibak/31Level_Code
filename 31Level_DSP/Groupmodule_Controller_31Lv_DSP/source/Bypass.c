/*
 * Bypass.c
 *
 *  Created on: 2018. 9. 6.
 *      Author: subi
 */

#include "Define_Header.h"

Uint16 RELAY_OP = 0;
Uint16 IGBT_OP = 0;

int Flag_Relay[6] = {0,0,0,0,0,0};
int Flag_IGBT[6] = {0,0,0,0,0,0};
int Flag_Bypass =0;

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

    return;
}


