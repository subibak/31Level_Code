/*
 * PieCtrl.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_PieCtrl.h"

void Init_PieCtrl(void)
{
	// CPUx Master Interrupt Disable.
	DINT;												// Master Interrupt Disable.

	// Clear All PIEIER Register.
	PieCtrlRegs.PIEIER1.all = 0x0000;
	PieCtrlRegs.PIEIER2.all = 0x0000;
	PieCtrlRegs.PIEIER3.all = 0x0000;
	PieCtrlRegs.PIEIER4.all = 0x0000;
	PieCtrlRegs.PIEIER5.all = 0x0000;
	PieCtrlRegs.PIEIER6.all = 0x0000;
	PieCtrlRegs.PIEIER7.all = 0x0000;
	PieCtrlRegs.PIEIER8.all = 0x0000;
	PieCtrlRegs.PIEIER9.all = 0x0000;
	PieCtrlRegs.PIEIER10.all = 0x0000;
	PieCtrlRegs.PIEIER11.all = 0x0000;
	PieCtrlRegs.PIEIER12.all = 0x0000;

	// Clear All PIEIFR Register of CPUx.
	PieCtrlRegs.PIEIFR1.all = 0x0000;
	PieCtrlRegs.PIEIFR2.all = 0x0000;
	PieCtrlRegs.PIEIFR3.all = 0x0000;
	PieCtrlRegs.PIEIFR4.all = 0x0000;
	PieCtrlRegs.PIEIFR5.all = 0x0000;
	PieCtrlRegs.PIEIFR6.all = 0x0000;
	PieCtrlRegs.PIEIFR7.all = 0x0000;
	PieCtrlRegs.PIEIFR8.all = 0x0000;
	PieCtrlRegs.PIEIFR9.all = 0x0000;
	PieCtrlRegs.PIEIFR10.all = 0x0000;
	PieCtrlRegs.PIEIFR11.all = 0x0000;
	PieCtrlRegs.PIEIFR12.all = 0x0000;

	// Clear All IER Register of CPUx.
	IER = 0x0000;
	asm(" RPT #10 || NOP");								// Wait 5 Cycles to Make Sure that Interrupt Reached the CPU IFR Register..

	// Clear All IFR Register of CPUx.
	IFR = 0x0000;

	return;
}

void Start_PieCtrl(void)
{
	// Enable Each Interrupt.
#ifdef CPU1
	PieCtrlRegs.PIEIER3.all |= M_INT1;					// ePWM1 Interrupt		; Main Interrupt #0 of CPU1.
	IER |= M_INT3;
#endif

#ifdef CPU2
	PieCtrlRegs.PIEIER3.all |= M_INT4;					// ePWM4 Interrupt		; Main Interrupt #0 of CPU2.
	IER |= M_INT3;
#endif

	// CPUx Master Interrupt Enable.
	EINT;												// Master Interrupt Enable.
	ERTM;												// Debug Interrupt Enable.

	return;
}
