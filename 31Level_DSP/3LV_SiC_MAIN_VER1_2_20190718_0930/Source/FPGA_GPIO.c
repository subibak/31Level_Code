/*
 * FPGA_GPIO.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_FPGA.h"

#ifdef CPU1
void Init_FPGA_GPIO(void)
{
	FpgaCs2Regs.GP0.DIR.all = GPxDIR_GPIO0_Output			// 0	: GPIO0		; LED0
							| GPxDIR_GPIO1_Output			// 1	: GPIO1		; LED1
							| GPxDIR_GPIO2_Output			// 2	: GPIO2		; LED2
							| GPxDIR_GPIO3_Output			// 3	: GPIO3		; LED3
							| GPxDIR_GPIO4_Input			// 4	: GPIO4
							| GPxDIR_GPIO5_Input			// 5	: GPIO5
							| GPxDIR_GPIO6_Input			// 6	: GPIO6
							| GPxDIR_GPIO7_Input			// 7	: GPIO7
							| GPxDIR_GPIO8_Input			// 8	: GPIO8
							| GPxDIR_GPIO9_Input			// 9	: GPIO9
							| GPxDIR_GPIO10_Input			// 10	: GPIO10
							| GPxDIR_GPIO11_Input			// 11	: GPIO11
							| GPxDIR_GPIO12_Input			// 12	: GPIO12
							| GPxDIR_GPIO13_Input			// 13	: GPIO13
							| GPxDIR_GPIO14_Input			// 14	: GPIO14
							| GPxDIR_GPIO15_Input;			// 15	: GPIO15

	FpgaCs2Regs.GP1.DIR.all = GPxDIR_GPIO0_Output			// 0	: GPIO0		; /GATE_EN1
							| GPxDIR_GPIO1_Output			// 1	: GPIO1		; /GATE_EN2
							| GPxDIR_GPIO2_Output			// 2	: GPIO2		; /GATE_EN3
							| GPxDIR_GPIO3_Output			// 3	: GPIO3		; /GATE_EN4
							| GPxDIR_GPIO4_Input			// 4	: GPIO4
							| GPxDIR_GPIO5_Input			// 5	: GPIO5
							| GPxDIR_GPIO6_Input			// 6	: GPIO6
							| GPxDIR_GPIO7_Input			// 7	: GPIO7
							| GPxDIR_GPIO8_Input			// 8	: GPIO8
							| GPxDIR_GPIO9_Input			// 9	: GPIO9
							| GPxDIR_GPIO10_Input			// 10	: GPIO10
							| GPxDIR_GPIO11_Input			// 11	: GPIO11
							| GPxDIR_GPIO12_Input			// 12	: GPIO12
							| GPxDIR_GPIO13_Input			// 13	: GPIO13
							| GPxDIR_GPIO14_Input			// 14	: GPIO14
							| GPxDIR_GPIO15_Input;			// 15	: GPIO15
	FpgaCs2Regs.GP1.SET.all = GPxxx_GPIO0					// 0	: GPIO0		; /GATE_EN1
							| GPxxx_GPIO1					// 1	: GPIO1		; /GATE_EN2
							| GPxxx_GPIO2					// 2	: GPIO2		; /GATE_EN3
							| GPxxx_GPIO3;					// 3	: GPIO3		; /GATE_EN4

	return;
}

// Predefine
//// Predefine : LED Time
#define LEDCOUNT_MAX			1000										// 100[us] x 1000 = 100[ms]
#define FPGA_LED0_ON			FpgaCs2Regs.GP0.CLEAR.all = GPxxx_GPIO1;
#define FPGA_LED1_ON			FpgaCs2Regs.GP0.CLEAR.all = GPxxx_GPIO0;
#define FPGA_LED2_ON			FpgaCs2Regs.GP0.CLEAR.all = GPxxx_GPIO3;
#define FPGA_LED3_ON			FpgaCs2Regs.GP0.CLEAR.all = GPxxx_GPIO2;

#define FPGA_LED0_OFF			FpgaCs2Regs.GP0.SET.all = GPxxx_GPIO1;
#define FPGA_LED1_OFF			FpgaCs2Regs.GP0.SET.all = GPxxx_GPIO0;
#define FPGA_LED2_OFF			FpgaCs2Regs.GP0.SET.all = GPxxx_GPIO3;
#define FPGA_LED3_OFF			FpgaCs2Regs.GP0.SET.all = GPxxx_GPIO2;

void FPGA_LED(void)
{
	static Uint16 LEDCount = 1, LEDCase = 0;

	if (LEDCount++ > LEDCOUNT_MAX) {
		switch (LEDCase) {
		case 0:		FPGA_LED0_ON;	LEDCase++;	break;
		case 1: 	FPGA_LED1_ON;	LEDCase++;	break;
		case 2: 	FPGA_LED2_ON;	LEDCase++;	break;
		case 3: 	FPGA_LED3_ON;	LEDCase++;	break;
		case 4: 	FPGA_LED0_OFF;	LEDCase++;	break;
		case 5: 	FPGA_LED1_OFF;	LEDCase++;	break;
		case 6: 	FPGA_LED2_OFF;	LEDCase++;	break;
		default: 	FPGA_LED3_OFF;	LEDCase = 0;break;
		}

		LEDCount = 1;
	}

	return;
}

#endif
