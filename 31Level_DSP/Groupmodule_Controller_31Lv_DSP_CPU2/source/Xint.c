/*
 * Xint.c
 *
 *  Created on: 2019. 1. 7.
 *      Author: subi
 */

#include "Define_Header.h"


void Init_xint(void)
{
    EALLOW;
    XintRegs.XINT5CR.bit.POLARITY = 1;          // Falling edge interrupt
    XintRegs.XINT5CR.bit.ENABLE = 1;            // XINT5 Interrupt Enable
    EDIS;

    return;
}

