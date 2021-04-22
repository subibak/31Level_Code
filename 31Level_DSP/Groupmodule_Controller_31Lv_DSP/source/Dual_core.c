/*
 * Dual_core.c
 *
 *  Created on: 2015. 9. 29.
 *      Author: cjs9426
 */


#include "Define_Header.h"

void Init_CpuSelect(void)
{
	EALLOW;

	// 0 : CPU1,	1 : CPU2
	// ePWM
	DevCfgRegs.CPUSEL0.bit.EPWM1 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM2 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM3 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM4 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM5 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM6 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM7 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM8 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM9 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM10 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM11 = 0;
	DevCfgRegs.CPUSEL0.bit.EPWM12 = 0;

	// eCAP
	DevCfgRegs.CPUSEL1.bit.ECAP1 = 0;
	DevCfgRegs.CPUSEL1.bit.ECAP2 = 0;
	DevCfgRegs.CPUSEL1.bit.ECAP3 = 0;
	DevCfgRegs.CPUSEL1.bit.ECAP4 = 0;
	DevCfgRegs.CPUSEL1.bit.ECAP5 = 0;
	DevCfgRegs.CPUSEL1.bit.ECAP6 = 0;

	// eQEP
	DevCfgRegs.CPUSEL2.bit.EQEP1 = 0;
	DevCfgRegs.CPUSEL2.bit.EQEP2 = 0;
	DevCfgRegs.CPUSEL2.bit.EQEP3 = 0;

	// SD
	DevCfgRegs.CPUSEL4.bit.SD1 = 0;
	DevCfgRegs.CPUSEL4.bit.SD2 = 0;

	// SCI
	DevCfgRegs.CPUSEL5.bit.SCI_A = 0;
	DevCfgRegs.CPUSEL5.bit.SCI_B = 0;
	DevCfgRegs.CPUSEL5.bit.SCI_C = 0;
	DevCfgRegs.CPUSEL5.bit.SCI_D = 0;

	// SPI
	DevCfgRegs.CPUSEL6.bit.SPI_A = 1;
	DevCfgRegs.CPUSEL6.bit.SPI_B = 0;
	DevCfgRegs.CPUSEL6.bit.SPI_C = 0;

	// I2C
	DevCfgRegs.CPUSEL7.bit.I2C_A = 0;
	DevCfgRegs.CPUSEL7.bit.I2C_B = 0;

	// CAN
	DevCfgRegs.CPUSEL8.bit.CAN_A = 0;
	DevCfgRegs.CPUSEL8.bit.CAN_B = 0;

	// McBSP
	DevCfgRegs.CPUSEL9.bit.McBSP_A = 0;
	DevCfgRegs.CPUSEL9.bit.McBSP_B = 0;

	// ADC
	DevCfgRegs.CPUSEL11.bit.ADC_A = 0;
	DevCfgRegs.CPUSEL11.bit.ADC_B = 0;
	DevCfgRegs.CPUSEL11.bit.ADC_C = 0;
	DevCfgRegs.CPUSEL11.bit.ADC_D = 0;

	// CMPSS
	DevCfgRegs.CPUSEL12.bit.CMPSS1 = 0;
	DevCfgRegs.CPUSEL12.bit.CMPSS2 = 0;
	DevCfgRegs.CPUSEL12.bit.CMPSS3 = 0;
	DevCfgRegs.CPUSEL12.bit.CMPSS4 = 0;
	DevCfgRegs.CPUSEL12.bit.CMPSS5 = 0;
	DevCfgRegs.CPUSEL12.bit.CMPSS6 = 0;
	DevCfgRegs.CPUSEL12.bit.CMPSS7 = 0;
	DevCfgRegs.CPUSEL12.bit.CMPSS8 = 0;

	// DAC
	DevCfgRegs.CPUSEL14.bit.DAC_A = 1;
	DevCfgRegs.CPUSEL14.bit.DAC_B = 1;
	DevCfgRegs.CPUSEL14.bit.DAC_C = 1;

	EDIS;
}
