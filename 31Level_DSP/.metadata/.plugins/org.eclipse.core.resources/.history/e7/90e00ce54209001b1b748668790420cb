/*
 * FAN.c
 *
 *  Created on: 2018. 9. 6.
 *      Author: subi
 */

#include "Define_Header.h"

int Flag_FAN[6] = {0,0,0,0,0,0};
Uint16 FAN_OP = 0;

void FAN(void)
{
    FAN_OP = 0;
    for(k = 0; k < 6; k++)  FAN_OP = FAN_OP | (((Uint16)Flag_FAN[k]) << k);
    *VENT_FAN = FAN_OP;

    return;
}
