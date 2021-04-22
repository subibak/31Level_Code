/*
 * Define_FPGA.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_FPGA_H_
#define INCLUDE_DEFINE_FPGA_H_

#ifdef __cplusplus
extern "C" {
#endif

// Include Files
#ifndef INCLUDE_DEFINE_HEADER_H_
#include "Define_Header.h"
#endif
#include "FPGA\FPGA_GPIO.h"
#include "FPGA\FPGA_SPI.h"
#include "FPGA\FPGA_ADC.h"
#include "FPGA\FPGA_PWM.h"
#include "FPGA\FPGA_QEP.h"

#ifdef CPU1
// Prototype Define
//// Prototype Define : GPIO
extern void Init_FPGA_GPIO(void);
extern void FPGA_LED(void);

//// Prototype Define : SPI
extern void Init_FPGA_SPI(void);
extern void FPGA_SPI_TX(void);

//// Prototype Define : ADC
extern void Init_FPGA_ADC(void);

//// Prototype Define : PWM
extern void Init_FPGA_PWM(void);
extern void Start_FPGA_PWM(void);
extern void LV3Out_FPGA_PWM(void);

//// Prototype Define : QEP
extern void Init_FPGA_QEP(void);
extern void M1Position_Read(void);
extern void M1Speed_Cal(void);
#endif

// FPGA Registers Define
struct FPGA_CS2_REGS {										// Address		Description
	struct FPGA_GPx_REGS					GP0;			// 0x0010 0000	FPGA GPIO0 Registers (LED0 to LED3).
	struct FPGA_GPx_REGS					GP1;			// 0x0010 0004	FPGA GPIO1 Registers (/GATE_EN1 to /GATE_EN4).
	Uint16									rsvd0[30][4];	// 0x0010 0008	FPGA GPIO31 - 2 Reserved Register.
	struct FPGA_SPI_REGS					SPI0;			// 0x0010 0080	FPGA SPI0 Register.
	struct FPGA_SPI_REGS					SPI1;			// 0x0010 0090	FPGA SPI1 Register.
	Uint16									rsvd1[6][16];	// 0x0010 00A0	FPGA SPI7 - 2 Reserved Register.
	struct FPGA_ADC_REGS					ADC0;			// 0x0010 0100	FPGA ADC0 Register.
	struct FPGA_ADC_REGS					ADC1;			// 0x0010 0110	FPGA ADC1 Register.
	Uint16									rsvd2[6][16];	// 0x0010 0120	FPGA ADC7 - 2 Reserved Register.
	struct FPGA_PWMCLK_REGS					PWMCLK;			// 0x0010 0180	FPGA PWM Clock Register.
	struct FPGA_PWM_REGS					PWM0;			// 0x0010 0190	FPGA PWM0 Register.
	struct FPGA_PWM_REGS					PWM1;			// 0x0010 01A0	FPGA PWM1 Register.
	struct FPGA_PWM_REGS					PWM2;			// 0x0010 01B0	FPGA PWM2 Register.
	struct FPGA_PWM_REGS					PWM3;			// 0x0010 01C0	FPGA PWM3 Register.
	struct FPGA_PWM_REGS					PWM4;			// 0x0010 01D0	FPGA PWM4 Register.
	struct FPGA_PWM_REGS					PWM5;			// 0x0010 01E0	FPGA PWM5 Register.
	struct FPGA_PWM_REGS					PWM6;			// 0x0010 01F0	FPGA PWM6 Register.
	struct FPGA_PWM_REGS					PWM7;			// 0x0010 0200	FPGA PWM7 Register.
	struct FPGA_PWM_REGS					PWM8;			// 0x0010 0210	FPGA PWM8 Register.
	struct FPGA_PWM_REGS					PWM9;			// 0x0010 0220	FPGA PWM9 Register.
	struct FPGA_PWM_REGS					PWM10;			// 0x0010 0230	FPGA PWM10 Register.
	struct FPGA_PWM_REGS					PWM11;			// 0x0010 0240	FPGA PWM11 Register.
	Uint16									rsvd3[3][16];	// 0x0010 0250	Not Used Region.
	struct FPGA_QEP_REGS					QEP0;			// 0x0010 0280	FPGA QEP0 Register.
	Uint16									rsvd4[7][16];	// 0x0010 0290	FPGA QEP7 - 1 Reserved Register.
};

// FPGA External References and Function Declarations
#ifdef CPU1
extern volatile struct FPGA_CS2_REGS FpgaCs2Regs;
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_FPGA_H_ */
