/*
 * FAN.c
 *
 *  Created on: 2018. 9. 6.
 *      Author: subi
 */

#include "Define_Header.h"

Uint16 Flag_FAN[6] = {0,0,0,0,0,0};
Uint16 FAN_OP = 0;

void FAN(void)
{
    for(k = 0; k < 6; k++)  FAN_OP = FAN_OP | (((Uint16)Flag_FAN[k]) << k);
    *VENT_FAN = FAN_OP;

    FAN_OP = 0;

    for(k = 0; k < 6; k++)
    {
        if ((Temp[k] > TEMP_LIMIT) | (Temp[k+1] > TEMP_LIMIT)) Flag_FAN[k] = 1;
        else if((Temp[k] < 30) | (Temp[k+1] < 30))             Flag_FAN[k] = 0;

    }

    return;
}
