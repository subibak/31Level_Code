/*
 * FPGA_ADC.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef FPGA_ADC_H_
#define FPGA_ADC_H_

#ifdef __cplusplus
extern "C" {
#endif

// Predefine Value.
//// Predefine Value : SPI Communication.
////// Predefine Value : SPI Communication - Reg0
#define ADCSPI_DATA_Normal					0x0000
#define ADCSPI_DATA_DeskewPattern			0x0400
#define ADCSPI_DATA_SyncPattern				0x0800
#define ADCSPI_DATA_CustomPattern			0x0C00

#define ADCSPI_DATASR_3_5mA					0x0000
#define ADCSPI_DATASR_2_5mA					0x0100
#define ADCSPI_DATASR_4_5mA					0x0200
#define ADCSPI_DATASR_6_0mA					0x0300

////// Predefine Value : SPI Communication - Reg1
#define ADCSPI_CLKSR_3_5mA					0x1000
#define ADCSPI_CLKSR_7_0mA					0x1100

#define ADCSPI_LMMODE_LSBFirst				0x1000
#define ADCSPI_LMMODE_MSBFirst				0x1400

////// Predefine Value : SPI Communication - Reg2
#define ADCSPI_PWDOWN_CH0Enable				0x2000
#define ADCSPI_PWDOWN_CH0Disable			0x2100

#define ADCSPI_PWDOWN_CH1Enable				0x2000
#define ADCSPI_PWDOWN_CH1Disable			0x2200

#define ADCSPI_PWDOWN_CH2Enable				0x2000
#define ADCSPI_PWDOWN_CH2Disable			0x2400

#define ADCSPI_PWDOWN_CH3Enable				0x2000
#define ADCSPI_PWDOWN_CH3Disable			0x2800

////// Predefine Value : SPI Communication - Reg3
#define ADCSPI_PWDOWN_CH4Enable				0x3000
#define ADCSPI_PWDOWN_CH4Disable			0x3100

#define ADCSPI_PWDOWN_CH5Enable				0x3000
#define ADCSPI_PWDOWN_CH5Disable			0x3200

#define ADCSPI_PWDOWN_CH6Enable				0x3000
#define ADCSPI_PWDOWN_CH6Disable			0x3400

#define ADCSPI_PWDOWN_CH7Enable				0x3000
#define ADCSPI_PWDOWN_CH7Disable			0x3800

////// Predefine Value : SPI Communication - Reg4 ~ 6
#define ADCSPI_CUSTOM_BYTE0(val)			(0x4000 | ((val & 0x000F) << 8))
#define ADCSPI_CUSTOM_BYTE1(val)			(0x5000 | ((val & 0x00F0) << 4))
#define ADCSPI_CUSTOM_BYTE2(val)			(0x6000 | (val & 0x0F00))

// ADC Register Define.
//// ADC Register Define : ADCCFG
struct FPGA_ADCCFG_BITS {				// bits	Description.
	Uint16	DIV:4;						// 3:0	ADC Clock Division.			6 x EMIFxCLK / 5 / (DIV + 1).	!!!!! 20[MHz] ~ 40[MHz] !!!!!
	Uint16	rsvd0:4;					// 7:4
	Uint16	rsvd1:7;					// 14:8
	Uint16	RESET:1;					// 15	ADC Reset.					0(Normal Mode), 1(Reset Mode).
};

union FPGA_ADCCFG_REG {
	Uint16	all;
	struct	FPGA_ADCCFG_BITS	bit;
};

// ADCCFG Register.
//// ADCCFG Register : Byte Value.
#define ADCCFG_DIV_Value(val)				(val & 0x000F)

#define ADCCFG_RESET_Normal					0x0000
#define ADCCFG_RESET_Reset					0x8000

//// ADC Register Define : ADCSWSOC
struct FPGA_ADCSWSOC_BITS {				// bits	Description.
	Uint16	SWSOC_CH0:1;				// 0	CH0 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	SWSOC_CH1:1;				// 1	CH1 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	SWSOC_CH2:1;				// 2	CH2 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	SWSOC_CH3:1;				// 3	CH3 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	SWSOC_CH4:1;				// 4	CH4 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	SWSOC_CH5:1;				// 5	CH5 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	SWSOC_CH6:1;				// 6	CH6 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	SWSOC_CH7:1;				// 7	CH7 S/W SOC.				0 (S/W Latch Disable), 1(S/W Latch Enable).
	Uint16	rsvd0:8;					// 15:8
};

union FPGA_ADCSWSOC_REG {
	Uint16	all;
	struct	FPGA_ADCSWSOC_BITS	bit;
};

// ADCSWSOC Register.
//// ADCSWSOC Register : Byte Value.
#define ADCSWSOC_SWSOC_CH0SOC				0x0001
#define ADCSWSOC_SWSOC_CH1SOC				0x0002
#define ADCSWSOC_SWSOC_CH2SOC				0x0004
#define ADCSWSOC_SWSOC_CH3SOC				0x0008
#define ADCSWSOC_SWSOC_CH4SOC				0x0010
#define ADCSWSOC_SWSOC_CH5SOC				0x0020
#define ADCSWSOC_SWSOC_CH6SOC				0x0040
#define ADCSWSOC_SWSOC_CH7SOC				0x0080

//// ADCSOC Register : Quick Value.
#define ADCSWSOC_SWSOC_CHAllSOC				0x00FF

//// ADC Register Define : ADCSOC0
struct FPGA_ADCSOC0_BITS {				// bits	Description.
	Uint16	SOCEN_CH0:4;				// 3:0	CH0 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
	Uint16	SOCEN_CH1:4;				// 7:4	CH1 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
	Uint16	SOCEN_CH2:4;				// 11:8	CH2 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
	Uint16	SOCEN_CH3:4;				// 15:12CH3 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
};

union FPGA_ADCSOC0_REG {
	Uint16	all;
	struct	FPGA_ADCSOC0_BITS	bit;
};

// ADCSOC0 Register.
//// ADCSOC0 Register : Byte Value.
#define ADCSOC0_SOCEN_CH0Disable			0x0000
#define ADCSOC0_SOCEN_CH0PWMSOCA			0x0001
#define ADCSOC0_SOCEN_CH0PWMSOCB			0x0002
#define ADCSOC0_SOCEN_CH0PWMSOCC			0x0003
#define ADCSOC0_SOCEN_CH0PWMSOCD			0x0004

#define ADCSOC0_SOCEN_CH1Disable			0x0000
#define ADCSOC0_SOCEN_CH1PWMSOCA			0x0010
#define ADCSOC0_SOCEN_CH1PWMSOCB			0x0020
#define ADCSOC0_SOCEN_CH1PWMSOCC			0x0030
#define ADCSOC0_SOCEN_CH1PWMSOCD			0x0040

#define ADCSOC0_SOCEN_CH2Disable			0x0000
#define ADCSOC0_SOCEN_CH2PWMSOCA			0x0100
#define ADCSOC0_SOCEN_CH2PWMSOCB			0x0200
#define ADCSOC0_SOCEN_CH2PWMSOCC			0x0300
#define ADCSOC0_SOCEN_CH2PWMSOCD			0x0400

#define ADCSOC0_SOCEN_CH3Disable			0x0000
#define ADCSOC0_SOCEN_CH3PWMSOCA			0x1000
#define ADCSOC0_SOCEN_CH3PWMSOCB			0x2000
#define ADCSOC0_SOCEN_CH3PWMSOCC			0x3000
#define ADCSOC0_SOCEN_CH3PWMSOCD			0x4000

//// ADC Register Define : ADCSOC1
struct FPGA_ADCSOC1_BITS {				// bits	Description.
	Uint16	SOCEN_CH4:4;				// 3:0	CH4 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
	Uint16	SOCEN_CH5:4;				// 7:4	CH5 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
	Uint16	SOCEN_CH6:4;				// 11:8	CH6 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
	Uint16	SOCEN_CH7:4;				// 15:12CH7 SOC Enable.				0(Disable), 1(PWM SOCA), 2(PWM SOCB), 3(PWM SOCC), 4(PWM SOCD), 5-15(Reserved).
};

union FPGA_ADCSOC1_REG {
	Uint16	all;
	struct	FPGA_ADCSOC1_BITS	bit;
};

// ADCSOC1 Register.
//// ADCSOC1 Register : Byte Value.
#define ADCSOC1_SOCEN_CH4Disable			0x0000
#define ADCSOC1_SOCEN_CH4PWMSOCA			0x0001
#define ADCSOC1_SOCEN_CH4PWMSOCB			0x0002
#define ADCSOC1_SOCEN_CH4PWMSOCC			0x0003
#define ADCSOC1_SOCEN_CH4PWMSOCD			0x0004

#define ADCSOC1_SOCEN_CH5Disable			0x0000
#define ADCSOC1_SOCEN_CH5PWMSOCA			0x0010
#define ADCSOC1_SOCEN_CH5PWMSOCB			0x0020
#define ADCSOC1_SOCEN_CH5PWMSOCC			0x0030
#define ADCSOC1_SOCEN_CH5PWMSOCD			0x0040

#define ADCSOC1_SOCEN_CH6Disable			0x0000
#define ADCSOC1_SOCEN_CH6PWMSOCA			0x0100
#define ADCSOC1_SOCEN_CH6PWMSOCB			0x0200
#define ADCSOC1_SOCEN_CH6PWMSOCC			0x0300
#define ADCSOC1_SOCEN_CH6PWMSOCD			0x0400

#define ADCSOC1_SOCEN_CH7Disable			0x0000
#define ADCSOC1_SOCEN_CH7PWMSOCA			0x1000
#define ADCSOC1_SOCEN_CH7PWMSOCB			0x2000
#define ADCSOC1_SOCEN_CH7PWMSOCC			0x3000
#define ADCSOC1_SOCEN_CH7PWMSOCD			0x4000

struct FPGA_ADC_REGS {										// Offset		Description
	union	FPGA_ADCCFG_REG					CFG;			// 0x0000 0000	ADC Configuration.
	union	FPGA_ADCSWSOC_REG				SWSOC;			// 0x0000 0001	ADC S/W Latch.
	union	FPGA_ADCSOC0_REG				SOC0;			// 0x0000 0002	ADC SOC0 Enable.
	union	FPGA_ADCSOC1_REG				SOC1;			// 0x0000 0003	ADC SOC1 Enable.
	Uint16									CH0RESULT;		// 0x0000 0004	ADC CH0 Result.
	Uint16									CH1RESULT;		// 0x0000 0005	ADC CH1 Result.
	Uint16									CH2RESULT;		// 0x0000 0006	ADC CH2 Result.
	Uint16									CH3RESULT;		// 0x0000 0007	ADC CH3 Result.
	Uint16									CH4RESULT;		// 0x0000 0008	ADC CH4 Result.
	Uint16									CH5RESULT;		// 0x0000 0009	ADC CH5 Result.
	Uint16									CH6RESULT;		// 0x0000 000A	ADC CH6 Result.
	Uint16									CH7RESULT;		// 0x0000 000B	ADC CH7 Result.
	Uint16									rsvd0[4];		// 0x0000 000C
};

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_FPGA_FPGA_ADC_H_ */
