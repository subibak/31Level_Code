/*
 * PieVect.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_PieVect.h"
#include "Define_CPU1_Interrupt.h"
#include "Define_CPU2_Interrupt.h"

void Init_PieVectTable(void)
{
	Uint16 ui_Temp;

	PINT *DEST = (PINT *) &PieVectTable;

	EALLOW;

	// Enable the PIE Vector Table of CPUx.
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;									//		: ENPIE			; 0(Disable PieVect), 1(Enable PieVect).

	// Do Not Write Over First 3 32-bit Location.
	// These Location are Initialized by Boot ROM with Boot Variables.
	// INT1 - INT12 are Not Used in TMS320F28377D.
	DEST += 13;

	// Initializing ISR to Default ISR.
	for (ui_Temp = 0; ui_Temp < 211; ui_Temp++)
		*(DEST++) = &ISR_Default;

	// Initializing Each Interrupt ISR
#ifdef CPU1
	PieVectTable.EPWM1_INT = &ISR_CPU1_EPWM1_OFFSET;					// PWM1 Interrupt		; Main Controller #0 of CPU1.
#endif

#ifdef CPU2
	PieVectTable.EPWM4_INT = &ISR_CPU2_EPWM4_OFFSET;					// PWM4 Interrupt		; Main Controller #0 of CPU1.
#endif

	EDIS;

	return;
}

interrupt void ISR_Default(void)
{
	ESTOP0;																// Emulation Stop.
	while(1);
}
