/*
 * timer.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 */


#include "Define_Header.h"

void Init_Timer(void)
{
	CpuTimer0Regs.PRD.bit.MSW = 0;
	CpuTimer0Regs.PRD.bit.LSW = 0;
	CpuTimer0Regs.TPR.bit.TDDR = 31;
	CpuTimer0Regs.TPRH.bit.TDDRH = 78;
	CpuTimer0Regs.TCR.bit.FREE = 2;
	CpuTimer0Regs.TCR.bit.TSS = 1;

	CpuTimer0Regs.TCR.bit.TIE = 1;

	return;
}

void Start_Timer(void)
{
	CpuTimer0Regs.TCR.bit.TSS = 0;

	return;
}
