/*
 * FPGA_ADC.c
 *
 *  Created on: 2018. 10. 17.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_FPGA.h"

#ifdef CPU1

void Init_FPGA_ADC(void)
{
	// ---------------------------------------- ADC0 ---------------------------------------- //
	// Reset Mode for ADC0 Initialization.
	FpgaCs2Regs.ADC0.CFG.bit.RESET = 1U;						// 15	: RESET		; 0(Normal), 1(Reset).

	FpgaCs2Regs.ADC0.CFG.all = ADCCFG_RESET_Reset				// 15	: RESET		; 0(Normal), 1(Reset).
							| ADCCFG_DIV_Value(7);				// 3-0	: DIV		; ADCLK = 12 x EMIFxCLK / 5 / (DIV + 1).
																//					; 20[MHz] = 12 x 100[MHz] / 5 / (11 + 1).

	FpgaCs2Regs.ADC0.SOC1.all = ADCSOC1_SOCEN_CH7Disable		// 15-12: SOCEN_CH7	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC1_SOCEN_CH6Disable			// 11-8	: SOCEN_CH6	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC1_SOCEN_CH5Disable			// 7-4	: SOCEN_CH5	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC1_SOCEN_CH4Disable;			// 3-0	: SOCEN_CH4	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
	FpgaCs2Regs.ADC0.SOC0.all = ADCSOC0_SOCEN_CH3Disable		// 15-12: SOCEN_CH3	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC0_SOCEN_CH2Disable			// 11-8	: SOCEN_CH2	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC0_SOCEN_CH1Disable			// 7-4	: SOCEN_CH1	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC0_SOCEN_CH0Disable;			// 3-0	: SOCEN_CH0	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).

	// Normal Mode for ADC0 Operation.
	FpgaCs2Regs.ADC0.CFG.bit.RESET = 0;							// 15	: RESET		; 0(Normal), 1(Reset).

	asm(" RPT #10 || NOP");

	FpgaCs2Regs.SPI1.CSSET0_DAT0 = ADCSPI_LMMODE_MSBFirst;

	// ---------------------------------------- ADC1 ---------------------------------------- //
	// Reset Mode for ADC0 Initialization.
	FpgaCs2Regs.ADC1.CFG.bit.RESET = 1;							// 15	: RESET		; 0(Normal), 1(Reset).

	FpgaCs2Regs.ADC1.CFG.all = ADCCFG_RESET_Reset				// 15	: RESET		; 0(Normal), 1(Reset).
							| ADCCFG_DIV_Value(11);				// 3-0	: DIV		; ADCLK = 12 x EMIFxCLK / 5 / (DIV + 1).
																//					; 20[MHz] = 12 x 100[MHz] / 5 / (11 + 1).

	FpgaCs2Regs.ADC1.SOC1.all = ADCSOC1_SOCEN_CH7Disable		// 15-12: SOCEN_CH7	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC1_SOCEN_CH6Disable			// 11-8	: SOCEN_CH6	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC1_SOCEN_CH5Disable			// 7-4	: SOCEN_CH5	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC1_SOCEN_CH4Disable;			// 3-0	: SOCEN_CH4	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
	FpgaCs2Regs.ADC1.SOC0.all = ADCSOC0_SOCEN_CH3Disable		// 15-12: SOCEN_CH3	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC0_SOCEN_CH2Disable			// 11-8	: SOCEN_CH2	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC0_SOCEN_CH1Disable			// 7-4	: SOCEN_CH1	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).
							| ADCSOC0_SOCEN_CH0Disable;			// 3-0	: SOCEN_CH0	; 0(Disable), 1(PWMSOCA), 2(PWMSOCB), 3(PWMSOCC), 4(PWMSOCD).

	// Normal Mode for ADC0 Operation.
	FpgaCs2Regs.ADC1.CFG.bit.RESET = 0;							// 15	: RESET		; 0(Normal), 1(Reset).

	asm(" RPT #10 || NOP");

	FpgaCs2Regs.SPI1.CSSET1_DAT0 = ADCSPI_LMMODE_MSBFirst;

	return;
}

#endif
