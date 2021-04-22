/*
 * WatchDog.c
 *
 *  Created on: 2015. 8. 20.
 *      Author: cjs9426
 */


#include "Define_Header.h"

void DisableDog(void)
{
    volatile Uint16 temp;

    EALLOW;
    //Grab the clock config so we don't clobber it
    temp = WdRegs.WDCR.all & 0x0007;
    WdRegs.WDCR.all = 0x0068 | temp;
    EDIS;


    return;
}

