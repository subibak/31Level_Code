/*
 * device.c
 *
 *  Created on: 2018. 12. 13.
 *      Author: subi
 */

#include "Define_Header.h"

static Uint32 readTime32(void)
{
    Uint32 timeVal;

    #if defined (_TMS320C6X)
    timeVal = TSCL;
    #elif __ARM_ARCH_7A__
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal));
    #else
    /* M4 specific implementation*/
    static uint32_t simuTimer = 0;
    simuTimer++;
    timeVal = simuTimer;
    #endif
    return timeVal;
}

void cycleDelay (Uint32 count)                      // 1/416MHz -> 1 cycle time
{
    Uint32 start = (Uint32)readTime32();

    while (((Uint32)readTime32() - start) < count);
}
