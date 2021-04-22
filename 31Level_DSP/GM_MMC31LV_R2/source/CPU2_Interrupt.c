/*
 * CPU2_Interrupt.c
 *
 *  Created on: 2020. 10. 11.
 *      Author: subi
 */

#include "Define_Header.h"

#ifdef CPU2
interrupt void ISR_ePWM2_CPU2_MMC_OP(void)
{
    XF2_ON;

    LED_DSP();
    LED_FPGA();

    XF2_OFF;

    EPwm2Regs.ETCLR.bit.INT = 1;            // ePWM2 Interrupt Clear
    PieCtrlRegs.PIEACK.bit.ACK3 = 1;        // ePWM2 PIE Interrupt Clear
}
#endif
