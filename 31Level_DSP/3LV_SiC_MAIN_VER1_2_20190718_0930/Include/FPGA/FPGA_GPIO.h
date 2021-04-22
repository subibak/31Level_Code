/*
 * FPGA_GPIO.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef FPGA_GPIO_H_
#define FPGA_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

// GPIO Register Define
//// GPIO Register Define : GP0xxx
struct FPGA_GPxxx_BITS {				// bits Description.
	Uint16	GPIO0:1;					// 0 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO1:1;					// 1 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO2:1;					// 2 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO3:1;					// 3 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO4:1;					// 4	Data Register for FPGA GPIO Pin.
	Uint16	GPIO5:1;					// 5 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO6:1;					// 6 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO7:1;					// 7 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO8:1;					// 8 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO9:1;					// 9 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO10:1;					// 10 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO11:1;					// 11 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO12:1;					// 12 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO13:1;					// 13 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO14:1;					// 14 	Data Register for FPGA GPIO Pin.
	Uint16	GPIO15:1;					// 15 	Data Register for FPGA GPIO Pin.
};

union FPGA_GPxxx_REG {
	Uint16	all;
	struct	FPGA_GPxxx_BITS	bit;
};

struct FPGA_GPx_REGS {										// Offset		Description
	union	FPGA_GPxxx_REG					DIR;			// 0x0000 0000	FPGA GPIO 0 Direction Register (GPIO0 to 16).
	union 	FPGA_GPxxx_REG					DAT;			// 0x0000 0001	FPGA GPIO 0 Data Register (GPIO0 to 16).
	union	FPGA_GPxxx_REG					SET;			// 0x0000 0002	FPGA GPIO 0 Set Register (GPIO0 to 16).
	union	FPGA_GPxxx_REG					CLEAR;			// 0x0000 0003	FPGA GPIO 0 Clear Register (GPIO0 to 16).
};

// GP0DIR Register
//// GP0DIR Register : Byte Value
#define GPxDIR_GPIO0_Input					0x0000
#define GPxDIR_GPIO0_Output					0x0001

#define GPxDIR_GPIO1_Input					0x0000
#define GPxDIR_GPIO1_Output					0x0002

#define GPxDIR_GPIO2_Input					0x0000
#define GPxDIR_GPIO2_Output					0x0004

#define GPxDIR_GPIO3_Input					0x0000
#define GPxDIR_GPIO3_Output					0x0008

#define GPxDIR_GPIO4_Input					0x0000
#define GPxDIR_GPIO4_Output					0x0010

#define GPxDIR_GPIO5_Input					0x0000
#define GPxDIR_GPIO5_Output					0x0020

#define GPxDIR_GPIO6_Input					0x0000
#define GPxDIR_GPIO6_Output					0x0040

#define GPxDIR_GPIO7_Input					0x0000
#define GPxDIR_GPIO7_Output					0x0080

#define GPxDIR_GPIO8_Input					0x0000
#define GPxDIR_GPIO8_Output					0x0100

#define GPxDIR_GPIO9_Input					0x0000
#define GPxDIR_GPIO9_Output					0x0200

#define GPxDIR_GPIO10_Input					0x0000
#define GPxDIR_GPIO10_Output				0x0400

#define GPxDIR_GPIO11_Input					0x0000
#define GPxDIR_GPIO11_Output				0x0800

#define GPxDIR_GPIO12_Input					0x0000
#define GPxDIR_GPIO12_Output				0x1000

#define GPxDIR_GPIO13_Input					0x0000
#define GPxDIR_GPIO13_Output				0x2000

#define GPxDIR_GPIO14_Input					0x0000
#define GPxDIR_GPIO14_Output				0x4000

#define GPxDIR_GPIO15_Input					0x0000
#define GPxDIR_GPIO15_Output				0x8000

// GP0xxx Register
//// GP0xxx Register : Byte Value
#define GPxxx_GPIO0							0x0001
#define GPxxx_GPIO1							0x0002
#define GPxxx_GPIO2							0x0004
#define GPxxx_GPIO3							0x0008
#define GPxxx_GPIO4							0x0010
#define GPxxx_GPIO5							0x0020
#define GPxxx_GPIO6							0x0040
#define GPxxx_GPIO7							0x0080
#define GPxxx_GPIO8							0x0100
#define GPxxx_GPIO9							0x0200
#define GPxxx_GPIO10						0x0400
#define GPxxx_GPIO11						0x0800
#define GPxxx_GPIO12						0x1000
#define GPxxx_GPIO13						0x2000
#define GPxxx_GPIO14						0x4000
#define GPxxx_GPIO15						0x8000

#ifdef __cplusplus
}
#endif

#endif /* FPGA_GPIO_H_ */
