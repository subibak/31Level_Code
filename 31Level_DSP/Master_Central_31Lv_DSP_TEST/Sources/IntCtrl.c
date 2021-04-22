/*
 * IntCtrl.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_IntCtrl.h"
#include "Define_Interrupt.h"

#ifdef __cplusplus
#pragma DATA_SECTION(".vects");
#else
#pragma DATA_SECTION(ISR_TABLE, ".vects");
#pragma DATA_ALIGN(ISR_TABLE, 1024);
#endif
Uint32 ISR_TABLE[16][8];

void Init_Interrupt(void)
{
    // Global Interrupt Disable.
	CSR &= ~(0x00000001);	// Global Interrupt Disable.
	IER &= ~(0xFFFFFFF0);	// Individual Interrupt Disable.

	// Interrupt Clear.
	DSP_ICFGRegs.EVTCLR0.all = 0xFFFFFFFF;
	DSP_ICFGRegs.EVTCLR1.all = 0xFFFFFFFF;
	DSP_ICFGRegs.EVTCLR2.all = 0xFFFFFFFF;
	DSP_ICFGRegs.EVTCLR3.all = 0xFFFFFFFF;


	// EVT0, EVT1, EVT2, EVT3 Mask.
	DSP_ICFGRegs.EVTMASK0.all = 0xFFFFFFFF;
	DSP_ICFGRegs.EVTMASK1.all = 0xFFFFFFFF;
	DSP_ICFGRegs.EVTMASK2.all = 0xFFFFFFFF;
	DSP_ICFGRegs.EVTMASK3.all = 0xFFFFFFFF;

	// Interrupt Selector.
	DSP_ICFGRegs.INTMUX1.bit.INTSEL4 = INTSEL_IRQ67;
	DSP_ICFGRegs.INTMUX1.bit.INTSEL5 = INTSEL_IRQ67;
	DSP_ICFGRegs.INTMUX1.bit.INTSEL6 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX1.bit.INTSEL7 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX2.bit.INTSEL8 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX2.bit.INTSEL9 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX2.bit.INTSEL10 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX2.bit.INTSEL11 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX3.bit.INTSEL12 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX3.bit.INTSEL13 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX3.bit.INTSEL14 = INTSEL_SYS_CMPA;
	DSP_ICFGRegs.INTMUX3.bit.INTSEL15 = INTSEL_SYS_CMPA;

    ICR = 0x0000FFFF;

	// Interrupt Vector Table Base.
	ISTP = (Uint32)&(ISR_TABLE[0][0]);

    /* Clear Dropped interrupts */
	DSP_ICFGRegs.INTXCLR.bit.CLEAR = 1;

	// Interrupt Vector Table.
	USERISR_RSTSET(ISR_TABLE[0], &ISR_Reset);
	USERISR_SET(ISR_TABLE[4], &ADC_Offset);
	USERISR_SET(ISR_TABLE[5], &ISR_DSPTimer);
	USERISR_SET(ISR_TABLE[6], &ISR_Default6);
	USERISR_SET(ISR_TABLE[7], &ISR_Default7);
	USERISR_SET(ISR_TABLE[8], &ISR_Default8);
	USERISR_SET(ISR_TABLE[9], &ISR_Default9);
	USERISR_SET(ISR_TABLE[10], &ISR_Default10);
	USERISR_SET(ISR_TABLE[11], &ISR_Default11);
	USERISR_SET(ISR_TABLE[12], &ISR_Default12);
	USERISR_SET(ISR_TABLE[13], &ISR_Default13);
	USERISR_SET(ISR_TABLE[14], &ISR_Default14);
	USERISR_SET(ISR_TABLE[15], &ISR_Default15);

	// Interrupt Enable. Interrupt Selector 4
	IER |= 0x00000012;
	CSR |= 0x00000001;

	return;
}

void USERISR_RSTSET(Uint32 *table, void *isr)
{
    Uint32 cst21 = ((Uint32)isr - (Uint32)&table[0]) >> 2;

    table[0] = 0x00000012 | (cst21 << 7);    /* B.S2            #ptr */
    table[1] = 0x00006000;                   /* NOP 4 */
    table[2] = 0x00006000;                   /* NOP 4 */
    table[3] = 0x00006000;                   /* NOP 4 */
    table[4] = 0x00006000;                   /* NOP 4 */
    table[5] = 0x00006000;                   /* NOP 4 */
    table[6] = 0x00006000;                   /* NOP 4 */
    table[7] = 0x00006000;                   /* NOP 4 */

    return;
}


void USERISR_SET(Uint32 *table, void *isr)
{
	Uint32 low = (Uint32)isr & 0x0000FFFF;
	Uint32 high = (Uint32)isr >> 16;

	table[0] = 0x003C54F6;						/* STW.D2T2		B0,*B15--[2] */
	table[1] = 0x0000002A | ((low) << 7);		/* MVK.S2		#ptr,B0 */
	table[2] = 0x0000006A | ((high) << 7);		/* MVKH.S2		#ptr,B0 */
	table[3] = 0x00000362;						/* B.S2			B0 */
	table[4] = 0x003C52E6;						/* LDW.D2T2		*++B15[2],B0 */
	table[5] = 0x00006000;						/* NOP 4 */
	table[6] = 0x00000000;						/* NOP */
	table[7] = 0x00000000;						/* NOP */

	return;
}

interrupt void ISR_Reset(void)
{

}

interrupt void ISR_DefaultNMI(void)
{
	while(1);
}

interrupt void ISR_Default5(void)
{

}

interrupt void ISR_Default6(void)
{

}

interrupt void ISR_Default7(void)
{

}

interrupt void ISR_Default8(void)
{

}

interrupt void ISR_Default9(void)
{

}

interrupt void ISR_Default10(void)
{

}

interrupt void ISR_Default11(void)
{

}

interrupt void ISR_Default12(void)
{

}

interrupt void ISR_Default13(void)
{

}

interrupt void ISR_Default14(void)
{

}

interrupt void ISR_Default15(void)
{

}
