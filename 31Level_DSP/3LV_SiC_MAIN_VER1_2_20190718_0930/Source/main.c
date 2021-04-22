/*
 * main.c
 *
 *  Created on: 2019. 6. 21.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_SysCtrl.h"
#include "Define_MemConfig.h"
#include "Define_GPIO.h"
#include "Define_PieCtrl.h"
#include "Define_PieVect.h"
#include "Define_ePWM.h"
#include "Define_LPF.h"
#include "Define_EMIF.h"
#include "Define_FPGA.h"

void main(void)
{
	// Disable WatchDogs.
	DisableDog();

//**************************************** CPU1 ****************************************//
#ifdef CPU1
	// Clock Initializing.
	Init_PLL(PLL_CPU1HOST);								// PLL Initializing(200[MHz]).

	// GSx Memory and Module Host Initializing.
	Init_GSRAM();										// GSx RAM Setting.
	Init_CPUHost();										// Peripheral Module Setting.

	#if (CPU2_BOOT_ENABLE)
		#if (CPU2_FLASH_BOOT)
		// CPU2 FLASH Boot Start.
		IPCBootCPU2(IPCBOOTMODE_FLASH);					// CPU2 Boot Execution.
		#endif
	while(IpcRegs.IPCSTS.bit.IPC30 == 0U);				// Wait Until CPU2 Boot Done.
	IpcRegs.IPCACK.all = IPCxxx_IPC30;					// Flag Clear.
	#endif

	Init_GPIO();										// Pin Function Selection.

	#if CPU2_BOOT_ENABLE
	IpcRegs.IPCSET.bit.IPC29 = 1U;						// Send Flag for Announcing GPIO Initialization Done.
	#endif
#endif

//**************************************** CPU2 ****************************************//
#ifdef CPU2
	IpcRegs.IPCSET.bit.IPC30 = 1U;						// Send Flag for Announcing Boot Done.
	while(IpcRegs.IPCSTS.bit.IPC29 == 0U);				// Wait Until CPU1 Initialize GPIO.
	IpcRegs.IPCACK.all = IPCxxx_IPC29;					// Flag Clear.
	Init_GPIO();										// Pin Function Selection.
#endif

//************************************ CPU1 & CPU2 ************************************//
	// Memory Host Initializing.
	Init_RAM();											// Dx and LSx RAM Setting.

	// Clock Initializing.
	Init_PeripheralClocks();							// Peripheral Clock Enable/Disable.

	// Interrupt Initializing.
	Init_PieCtrl();										// Interrupt Enable Initializing.
	Init_PieVectTable();								// Interrupt Vector Table Initializing.

	// Each Module Initializing.
	Init_ePWM();										// ePWM Module Initializing.
	LPF_Parameter();									// Low Pass Filter Parameter.

//**************************************** CPU1 ****************************************//
#ifdef CPU1
	//// Each Module Initializing : CPU1.
	Init_EMIF1(EMIF1_CPU1HOST);							// EMIF1 Module Initializing.
	Init_FPGA_GPIO();									// FPGA GPIO Initializing - LED.
	Init_FPGA_SPI();									// FPGA SPI Initializing - DAC and ADC.
	Init_FPGA_ADC();									// FPGA ADC Initializing.
	Init_FPGA_PWM();									// FPGA PWM Initializing.
	Init_FPGA_QEP();									// FPGA QEP Initializing.
#endif

//**************************************** CPU2 ****************************************//
#ifdef CPU2
	//// Each Module Initializing : CPU2.

#endif

//************************************ CPU1 & CPU2 ************************************//
	// Start System
	Start_PieCtrl();									// Interrupt Enable.

//**************************************** CPU1 ****************************************//
#ifdef CPU1
	//// Start System : PWM Time Base.
	#if (CPU2_BOOT_ENABLE)
	while(IpcRegs.IPCSTS.bit.IPC29 == 0U);				// Wait Until CPU2 Done the Module Initializing.
	IpcRegs.IPCACK.all = IPCxxx_IPC29;					// Flag Clear.
	#endif

	Start_FPGA_PWM();									// FPGA PWM Enable.
	Start_ePWM();										// ePWM Time Base Enable.
#endif

//**************************************** CPU2 ****************************************//
#ifdef CPU2
	//// Start System : PWM Time Base.
	IpcRegs.IPCSET.all = IPCxxx_IPC29;					// Send Flag for Announcing Module Initializing Done.
#endif

	while(1) {
	}
}
