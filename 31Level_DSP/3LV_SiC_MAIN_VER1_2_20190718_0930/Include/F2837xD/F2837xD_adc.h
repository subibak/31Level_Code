//###########################################################################
//
// FILE:    F2837xD_adc.h
//
// TITLE:   F2837xD Device ADC Register Definitions.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 $
// $Release Date: Tue Nov  1 14:46:15 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xD_ADC_H__
#define __F2837xD_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCCTL1_BITS {                   // bits description
    Uint16 rsvd1:2;                     // 1:0 Reserved
    Uint16 INTPULSEPOS:1;               // 2 ADC Interrupt Pulse Position
    Uint16 rsvd2:4;                     // 6:3 Reserved
    Uint16 ADCPWDNZ:1;                  // 7 ADC Power Down
    Uint16 ADCBSYCHN:4;                 // 11:8 ADC Busy Channel
    Uint16 rsvd3:1;                     // 12 Reserved
    Uint16 ADCBSY:1;                    // 13 ADC Busy
    Uint16 rsvd4:2;                     // 15:14 Reserved
};

union ADCCTL1_REG {
    Uint16  all;
    struct  ADCCTL1_BITS  bit;
};

// ADCCTL1 Register
//// ADCCTL1 Register : Byte Value
#define ADCCTL1_ADCPWDNZ_AnalogPowDown					0x0000						// All Analog Circuitry inside the Core is Powered Down.
#define ADCCTL1_ADCPWDNZ_AnalogPowUp					0x0080						// All Analog Circuitry inside the Core is Powered Down.

#define ADCCTL1_INTPULSEPOS_EndOfAcqWindow				0x0000						// Interrupt Pulse Generation Occurs at the End of the Acquisition Window.
#define ADCCTL1_INTPULSEPOS_EndOfConversion				0x0004						// Interrupt Pulse Generation Occurs at the End of the Conversion, 1 Cycle Prior to the ADC Result Latching into its Result Register.

struct ADCCTL2_BITS {                   // bits description
    Uint16 PRESCALE:4;                  // 3:0 ADC Clock Prescaler
    Uint16 rsvd1:2;                     // 5:4 Reserved
    Uint16 RESOLUTION:1;                // 6 SOC Conversion Resolution
    Uint16 SIGNALMODE:1;                // 7 SOC Signaling Mode
    Uint16 rsvd2:5;                     // 12:8 Reserved
    Uint16 rsvd3:3;                     // 15:13 Reserved
};

union ADCCTL2_REG {
    Uint16  all;
    struct  ADCCTL2_BITS  bit;
};

// ADCCTL2 Register
//// ADCCTL2 Register : Byte Value
#define ADCCTL2_SIGNALMODE_Differential					0x0080						// Differential Input Mode.
#define ADCCTL2_SIGNALMODE_SingleEnded					0x0000						// Single-Ended Input Mode.

#define ADCCTL2_RESOLUTION_16Bit						0x0040						// 16-bit Resolution.
#define ADCCTL2_RESOLUTION_12Bit						0x0000						// 12-bit Resolution.

#define ADCCTL2_PRESCALE_Val(val)						(val & 0x000F)				// ADCCLK = Input Clock / (1.0 + 0.5 * val)

//// ADCCTL2 Register : Quick Value
#define ADCCTL2_SIG_RES_16BitDiff						0x00C0						// 16-bit Resolution with Differential Input Mode.
#define ADCCTL2_SIG_RES_12BitSingle						0x0000						// 12-bit Resolution with Single-Ended Input Mode.

//// ADCCTL2 Register : Bit Value
#define SIGNALMODE_Differential							1							// Differential Input Mode.
#define SIGNALMODE_SingleEnded							0							// Single-Ended Input Mode.

#define RESOLUTION_16Bit								1							// 16-bit Resolution.
#define RESOLUTION_12Bit								0							// 12-bit Resolution.

#define PRESCALE_Val(val)								val & 0xF					// ADCCLK = Input Clock / (1.0 + 0.5 * val)

struct ADCBURSTCTL_BITS {               // bits description
    Uint16 BURSTTRIGSEL:6;              // 5:0 SOC Burst Trigger Source Select
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 BURSTSIZE:4;                 // 11:8 SOC Burst Size Select
    Uint16 rsvd2:3;                     // 14:12 Reserved
    Uint16 BURSTEN:1;                   // 15 SOC Burst Mode Enable
};

union ADCBURSTCTL_REG {
    Uint16  all;
    struct  ADCBURSTCTL_BITS  bit;
};

// ADCBURSTCTL Register
//// ADCBURSTCTL Register : Byte Value
#define ADCBUSRTCTL_BURSTEN_BurstDis					0x0000						// Burst Mode Disable.
#define ADCBURSTCTL_BURSTEN_BurstEn						0x8000						// Burst Mode Enable.

#define ADCBURSTCTL_BURSTSIZE_Size(val)					((val - 1) & 0x0F00)		// 1 ~ 16(0 ~ F) SOCs Converterd.

#define ADCBUTSTCTL_BURSTTRIGSEL_SW						0x0000						// Software Only.
#define ADCBUTSTCTL_BURSTTRIGSEL_CPU1_Timer0			0x0001						// CPU1 Timer 0.
#define ADCBUTSTCTL_BURSTTRIGSEL_CPU1_Timer1			0x0002						// CPU1 Timer 1.
#define ADCBUTSTCTL_BURSTTRIGSEL_CPU1_Timer2			0x0003						// CPU1 Timer 2.
#define ADCBUTSTCTL_BURSTTRIGSEL_INUPTXBAR5				0x0004						// GPIO, Input X-Bar INPUT5.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM1_ADCSOCA			0x0005						// ePWM1, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM1_ADCSOCB			0x0006						// ePWM1, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM2_ADCSOCA			0x0007						// ePWM2, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM2_ADCSOCB			0x0008						// ePWM2, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM3_ADCSOCA			0x0009						// ePWM3, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM3_ADCSOCB			0x000A						// ePWM3, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM4_ADCSOCA			0x000B						// ePWM4, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM4_ADCSOCB			0x000C						// ePWM4, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM5_ADCSOCA			0x000D						// ePWM5, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM5_ADCSOCB			0x000E						// ePWM5, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM6_ADCSOCA			0x000F						// ePWM6, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM6_ADCSOCB			0x0010						// ePWM6, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM7_ADCSOCA			0x0011						// ePWM7, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM7_ADCSOCB			0x0012						// ePWM7, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM8_ADCSOCA			0x0013						// ePWM8, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM8_ADCSOCB			0x0014						// ePWM8, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM9_ADCSOCA			0x0015						// ePWM9, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM9_ADCSOCB			0x0016						// ePWM9, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM10_ADCSOCA			0x0017						// ePWM10, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM10_ADCSOCB			0x0018						// ePWM10, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM11_ADCSOCA			0x0019						// ePWM11, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM11_ADCSOCB			0x001A						// ePWM11, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM12_ADCSOCA			0x001B						// ePWM12, ADCSOCA.
#define ADCBUTSTCTL_BURSTTRIGSEL_EPWM12_ADCSOCB			0x001C						// ePWM12, ADCSOCB.
#define ADCBUTSTCTL_BURSTTRIGSEL_CPU2_Timer0			0x001D						// CPU2 Timer 0.
#define ADCBUTSTCTL_BURSTTRIGSEL_CPU2_Timer1			0x001E						// CPU2 Timer 1.
#define ADCBUTSTCTL_BURSTTRIGSEL_CPU2_Timer2			0x001F						// CPU2 Timer 2.

struct ADCINTFLG_BITS {                 // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Flag
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Flag
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Flag
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Flag
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTFLG_REG {
    Uint16  all;
    struct  ADCINTFLG_BITS  bit;
};

struct ADCINTFLGCLR_BITS {              // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Flag Clear
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Flag Clear
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Flag Clear
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Flag Clear
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTFLGCLR_REG {
    Uint16  all;
    struct  ADCINTFLGCLR_BITS  bit;
};

// ADCINTFLGCLR Register
//// ADCINTFLGCLR Register : Byte Value
#define ADCINTFLGCLR_ADCINT4_Clear						0x0008						// ADC Interrupt 4 Flag Clears.
#define ADCINTFLGCLR_ADCINT3_Clear						0x0004						// ADC Interrupt 3 Flag Clears.
#define ADCINTFLGCLR_ADCINT2_Clear						0x0002						// ADC Interrupt 2 Flag Clears.
#define ADCINTFLGCLR_ADCINT1_Clear						0x0001						// ADC Interrupt 1 Flag Clears.

//// ADCINTFLGCLR Register : Quick Value
#define ADCINTFLGCLR_ADCINT_ClearAll					0x000F						// ADC Interrupt 1 ~ 4 Flag Clears.

struct ADCINTOVF_BITS {                 // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Overflow Flags
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Overflow Flags
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Overflow Flags
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Overflow Flags
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTOVF_REG {
    Uint16  all;
    struct  ADCINTOVF_BITS  bit;
};

struct ADCINTOVFCLR_BITS {              // bits description
    Uint16 ADCINT1:1;                   // 0 ADC Interrupt 1 Overflow Clear Bits
    Uint16 ADCINT2:1;                   // 1 ADC Interrupt 2 Overflow Clear Bits
    Uint16 ADCINT3:1;                   // 2 ADC Interrupt 3 Overflow Clear Bits
    Uint16 ADCINT4:1;                   // 3 ADC Interrupt 4 Overflow Clear Bits
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union ADCINTOVFCLR_REG {
    Uint16  all;
    struct  ADCINTOVFCLR_BITS  bit;
};

// ADCINTOVFCLR Register
//// ADCINTOVFCLR Register : Byte Value
#define ADCINTOVFCLR_ADCINT4_Clear						0x0008						// ADC Interrupt 4 Overflow Clears.
#define ADCINTOVFCLR_ADCINT3_Clear						0x0004						// ADC Interrupt 3 Overflow Clears.
#define ADCINTOVFCLR_ADCINT2_Clear						0x0002						// ADC Interrupt 2 Overflow Clears.
#define ADCINTOVFCLR_ADCINT1_Clear						0x0001						// ADC Interrupt 1 Overflow Clears.

//// ADCINTFLGCLR Register : Quick Value
#define ADCINTOVFCLR_ADCINT_ClearAll					0x000F						// ADC Interrupt 1 ~ 4 Overflows Clear.

struct ADCINTSEL1N2_BITS {              // bits description
    Uint16 INT1SEL:4;                   // 3:0 ADCINT1 EOC Source Select
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 INT1E:1;                     // 5 ADCINT1 Interrupt Enable
    Uint16 INT1CONT:1;                  // 6 ADCINT1 Continuous Mode Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 INT2SEL:4;                   // 11:8 ADCINT2 EOC Source Select
    Uint16 rsvd3:1;                     // 12 Reserved
    Uint16 INT2E:1;                     // 13 ADCINT2 Interrupt Enable
    Uint16 INT2CONT:1;                  // 14 ADCINT2 Continuous Mode Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCINTSEL1N2_REG {
    Uint16  all;
    struct  ADCINTSEL1N2_BITS  bit;
};

// ADCINTSEL1N2 Register
//// ADCINTSEL1N2 Register : Byte Value
#define ADCINTSEL1N2_INT2CONT_OneShotMode				0x0000						// ADCINT2 Pulses are Not Generated Until ADCINT2 Flag is Cleared by User.
#define ADCINTSEL1N2_INT2CONT_ContinueMode				0x4000						// ADCINT2 Pulses are Generated Whenever an EOC Pulse is Generated Irrespective of Whether the Flag Bit is Cleared or Not.

#define ADCINTSEL1N2_INT2E_INT2Dis						0x0000						// ADCINT2 is Disabled.
#define ADCINTSEL1N2_INT2E_INT2En						0x2000						// ADCINT2 is Enabled.

#define ADCINTSEL1N2_INT2SEL_EOC(num)					(((num - 1) & 0x000F) << 8)	// EOCx is Trigger for ADCINT2

#define ADCINTSEL1N2_INT1CONT_OneShotMode				0x0000						// ADCINT1 Pulses are Not Generated Until ADCINT1 Flag is Cleared by User.
#define ADCINTSEL1N2_INT1CONT_ContinueMode				0x0040						// ADCINT1 Pulses are Generated Whenever an EOC Pulse is Generated Irrespective of Whether the Flag Bit is Cleared or Not.

#define ADCINTSEL1N2_INT1E_INT1Dis						0x0000						// ADCINT1 is Disabled.
#define ADCINTSEL1N2_INT1E_INT1En						0x0020						// ADCINT1 is Enabled.

#define ADCINTSEL1N2_INT1SEL_EOC(num)					((num - 1) & 0x000F)		// EOCx is Trigger for ADCINT1

struct ADCINTSEL3N4_BITS {              // bits description
    Uint16 INT3SEL:4;                   // 3:0 ADCINT3 EOC Source Select
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 INT3E:1;                     // 5 ADCINT3 Interrupt Enable
    Uint16 INT3CONT:1;                  // 6 ADCINT3 Continuous Mode Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 INT4SEL:4;                   // 11:8 ADCINT4 EOC Source Select
    Uint16 rsvd3:1;                     // 12 Reserved
    Uint16 INT4E:1;                     // 13 ADCINT4 Interrupt Enable
    Uint16 INT4CONT:1;                  // 14 ADCINT4 Continuous Mode Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCINTSEL3N4_REG {
    Uint16  all;
    struct  ADCINTSEL3N4_BITS  bit;
};

// ADCINTSEL3N4 Register
//// ADCINTSEL3N4 Register : Byte Value
#define ADCINTSEL3N4_INT4CONT_OneShotMode				0x0000						// ADCINT4 Pulses are Not Generated Until ADCINT4 Flag is Cleared by User.
#define ADCINTSEL3N4_INT4CONT_ContinueMode				0x4000						// ADCINT4 Pulses are Generated Whenever an EOC Pulse is Generated Irrespective of Whether the Flag Bit is Cleared or Not.

#define ADCINTSEL3N4_INT4E_INT4Dis						0x0000						// ADCINT4 is Disabled.
#define ADCINTSEL3N4_INT4E_IN43En						0x2000						// ADCINT4 is Enabled.

#define ADCINTSEL3N4_INT4SEL_EOC(num)					(((num - 1) & 0x000F) << 8)	// EOCx is Trigger for ADCINT4

#define ADCINTSEL3N4_INT3CONT_OneShotMode				0x0000						// ADCINT3 Pulses are Not Generated Until ADCINT3 Flag is Cleared by User.
#define ADCINTSEL3N4_INT3CONT_ContinueMode				0x0040						// ADCINT3 Pulses are Generated Whenever an EOC Pulse is Generated Irrespective of Whether the Flag Bit is Cleared or Not.

#define ADCINTSEL3N4_INT3E_INT3Dis						0x0000						// ADCINT3 is Disabled.
#define ADCINTSEL3N4_INT3E_INT3En						0x0020						// ADCINT3 is Enabled.

#define ADCINTSEL3N4_INT1SEL_EOC(num)					((num - 1) & 0x000F)		// EOCx is Trigger for ADCINT3

struct ADCSOCPRICTL_BITS {              // bits description
    Uint16 SOCPRIORITY:5;               // 4:0 SOC Priority
    Uint16 RRPOINTER:5;                 // 9:5 Round Robin Pointer
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCSOCPRICTL_REG {
    Uint16  all;
    struct  ADCSOCPRICTL_BITS  bit;
};

// ADCSOCPRICTL Register
//// ADCSOCPRICTL Register : Byte Value
#define ADCSOCPRICTL_SOCPRIORITY_RoundRobin				0x0000						// SOC Priority is Handled in Round Robin for All Channels.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0					0x0001						// SOC0 is High Priority, Rest of Channels are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC1				0x0002						// SOC0 - SOC1 are High Priority, SOC2 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC2				0x0003						// SOC0 - SOC2 are High Priority, SOC3 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC3				0x0004						// SOC0 - SOC3 are High Priority, SOC4 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC4				0x0005						// SOC0 - SOC4 are High Priority, SOC5 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC5				0x0006						// SOC0 - SOC5 are High Priority, SOC6 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC6				0x0007						// SOC0 - SOC6 are High Priority, SOC7 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC7				0x0008						// SOC0 - SOC7 are High Priority, SOC8 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC8				0x0009						// SOC0 - SOC8 are High Priority, SOC9 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC9				0x000A						// SOC0 - SOC9 are High Priority, SOC10 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC10			0x000B						// SOC0 - SOC10 are High Priority, SOC11 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC11			0x000C						// SOC0 - SOC11 are High Priority, SOC12 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC12			0x000D						// SOC0 - SOC12 are High Priority, SOC13 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC13			0x000E						// SOC0 - SOC13 are High Priority, SOC15 - SOC15 are in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_SOC0toSOC14			0x000F						// SOC0 - SOC14 are High Priority, SOC15 is in Round Robin Mode.
#define ADCSOCPRICTL_SOCPRIORITY_AllSOC					0x0010						// All SOCs are High Priority, Arbitrated by SOC Number.

struct ADCINTSOCSEL1_BITS {             // bits description
    Uint16 SOC0:2;                      // 1:0 SOC0 ADC Interrupt Trigger Select
    Uint16 SOC1:2;                      // 3:2 SOC1 ADC Interrupt Trigger Select
    Uint16 SOC2:2;                      // 5:4 SOC2 ADC Interrupt Trigger Select
    Uint16 SOC3:2;                      // 7:6 SOC3 ADC Interrupt Trigger Select
    Uint16 SOC4:2;                      // 9:8 SOC4 ADC Interrupt Trigger Select
    Uint16 SOC5:2;                      // 11:10 SOC5 ADC Interrupt Trigger Select
    Uint16 SOC6:2;                      // 13:12 SOC6 ADC Interrupt Trigger Select
    Uint16 SOC7:2;                      // 15:14 SOC7 ADC Interrupt Trigger Select
};

union ADCINTSOCSEL1_REG {
    Uint16  all;
    struct  ADCINTSOCSEL1_BITS  bit;
};

// ADCINTSOCSEL1 Register
//// ADCINTSOCSEL1 Register : Byte Value
#define ADCINTSOCSEL1_SOC7_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC7.
#define ADCINTSOCSEL1_SOC7_SOCbyADCINT1					0x4000						// ADCINT1 will Trigger SOC7.
#define ADCINTSOCSEL1_SOC7_SOCbyADCINT2					0x8000						// ADCINT2 will Trigger SOC7.

#define ADCINTSOCSEL1_SOC6_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC6.
#define ADCINTSOCSEL1_SOC6_SOCbyADCINT1					0x1000						// ADCINT1 will Trigger SOC6.
#define ADCINTSOCSEL1_SOC6_SOCbyADCINT2					0x2000						// ADCINT2 will Trigger SOC6.

#define ADCINTSOCSEL1_SOC5_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC5.
#define ADCINTSOCSEL1_SOC5_SOCbyADCINT1					0x0400						// ADCINT1 will Trigger SOC5.
#define ADCINTSOCSEL1_SOC5_SOCbyADCINT2					0x0800						// ADCINT2 will Trigger SOC5.

#define ADCINTSOCSEL1_SOC4_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC4.
#define ADCINTSOCSEL1_SOC4_SOCbyADCINT1					0x0100						// ADCINT1 will Trigger SOC4.
#define ADCINTSOCSEL1_SOC4_SOCbyADCINT2					0x0200						// ADCINT2 will Trigger SOC4.

#define ADCINTSOCSEL1_SOC3_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC3.
#define ADCINTSOCSEL1_SOC3_SOCbyADCINT1					0x0040						// ADCINT1 will Trigger SOC3.
#define ADCINTSOCSEL1_SOC3_SOCbyADCINT2					0x0080						// ADCINT2 will Trigger SOC3.

#define ADCINTSOCSEL1_SOC2_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC2.
#define ADCINTSOCSEL1_SOC2_SOCbyADCINT1					0x0010						// ADCINT1 will Trigger SOC2.
#define ADCINTSOCSEL1_SOC2_SOCbyADCINT2					0x0020						// ADCINT2 will Trigger SOC2.

#define ADCINTSOCSEL1_SOC1_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC1.
#define ADCINTSOCSEL1_SOC1_SOCbyADCINT1					0x0004						// ADCINT1 will Trigger SOC1.
#define ADCINTSOCSEL1_SOC1_SOCbyADCINT2					0x0008						// ADCINT2 will Trigger SOC1.

#define ADCINTSOCSEL1_SOC0_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC0.
#define ADCINTSOCSEL1_SOC0_SOCbyADCINT1					0x0001						// ADCINT1 will Trigger SOC0.
#define ADCINTSOCSEL1_SOC0_SOCbyADCINT2					0x0002						// ADCINT2 will Trigger SOC0.

struct ADCINTSOCSEL2_BITS {             // bits description
    Uint16 SOC8:2;                      // 1:0 SOC8 ADC Interrupt Trigger Select
    Uint16 SOC9:2;                      // 3:2 SOC9 ADC Interrupt Trigger Select
    Uint16 SOC10:2;                     // 5:4 SOC10 ADC Interrupt Trigger Select
    Uint16 SOC11:2;                     // 7:6 SOC11 ADC Interrupt Trigger Select
    Uint16 SOC12:2;                     // 9:8 SOC12 ADC Interrupt Trigger Select
    Uint16 SOC13:2;                     // 11:10 SOC13 ADC Interrupt Trigger Select
    Uint16 SOC14:2;                     // 13:12 SOC14 ADC Interrupt Trigger Select
    Uint16 SOC15:2;                     // 15:14 SOC15 ADC Interrupt Trigger Select
};

union ADCINTSOCSEL2_REG {
    Uint16  all;
    struct  ADCINTSOCSEL2_BITS  bit;
};

// ADCINTSOCSEL2 Register
//// ADCINTSOCSEL2 Register : Byte Value
#define ADCINTSOCSEL2_SOC15_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC15.
#define ADCINTSOCSEL2_SOC15_SOCbyADCINT1				0x4000						// ADCINT1 will Trigger SOC15.
#define ADCINTSOCSEL2_SOC15_SOCbyADCINT2				0x8000						// ADCINT2 will Trigger SOC15.

#define ADCINTSOCSEL2_SOC14_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC14.
#define ADCINTSOCSEL2_SOC14_SOCbyADCINT1				0x1000						// ADCINT1 will Trigger SOC14.
#define ADCINTSOCSEL2_SOC14_SOCbyADCINT2				0x2000						// ADCINT2 will Trigger SOC14.

#define ADCINTSOCSEL2_SOC13_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC13.
#define ADCINTSOCSEL2_SOC13_SOCbyADCINT1				0x0400						// ADCINT1 will Trigger SOC13.
#define ADCINTSOCSEL2_SOC13_SOCbyADCINT2				0x0800						// ADCINT2 will Trigger SOC13.

#define ADCINTSOCSEL2_SOC12_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC12.
#define ADCINTSOCSEL2_SOC12_SOCbyADCINT1				0x0100						// ADCINT1 will Trigger SOC12.
#define ADCINTSOCSEL2_SOC12_SOCbyADCINT2				0x0200						// ADCINT2 will Trigger SOC12.

#define ADCINTSOCSEL2_SOC11_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC11.
#define ADCINTSOCSEL2_SOC11_SOCbyADCINT1				0x0040						// ADCINT1 will Trigger SOC11.
#define ADCINTSOCSEL2_SOC11_SOCbyADCINT2				0x0080						// ADCINT2 will Trigger SOC11.

#define ADCINTSOCSEL2_SOC10_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC10.
#define ADCINTSOCSEL2_SOC10_SOCbyADCINT1				0x0010						// ADCINT1 will Trigger SOC10.
#define ADCINTSOCSEL2_SOC10_SOCbyADCINT2				0x0020						// ADCINT2 will Trigger SOC10.

#define ADCINTSOCSEL2_SOC9_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC9.
#define ADCINTSOCSEL2_SOC9_SOCbyADCINT1					0x0004						// ADCINT1 will Trigger SOC9.
#define ADCINTSOCSEL2_SOC9_SOCbyADCINT2					0x0008						// ADCINT2 will Trigger SOC9.

#define ADCINTSOCSEL2_SOC8_SOCByADCINTDis				0x0000						// No ADCINT will Trigger SOC8.
#define ADCINTSOCSEL2_SOC8_SOCbyADCINT1					0x0001						// ADCINT1 will Trigger SOC8.
#define ADCINTSOCSEL2_SOC8_SOCbyADCINT2					0x0002						// ADCINT2 will Trigger SOC8.

struct ADCSOCFLG1_BITS {                // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Start of Conversion Flag
    Uint16 SOC1:1;                      // 1 SOC1 Start of Conversion Flag
    Uint16 SOC2:1;                      // 2 SOC2 Start of Conversion Flag
    Uint16 SOC3:1;                      // 3 SOC3 Start of Conversion Flag
    Uint16 SOC4:1;                      // 4 SOC4 Start of Conversion Flag
    Uint16 SOC5:1;                      // 5 SOC5 Start of Conversion Flag
    Uint16 SOC6:1;                      // 6 SOC6 Start of Conversion Flag
    Uint16 SOC7:1;                      // 7 SOC7 Start of Conversion Flag
    Uint16 SOC8:1;                      // 8 SOC8 Start of Conversion Flag
    Uint16 SOC9:1;                      // 9 SOC9 Start of Conversion Flag
    Uint16 SOC10:1;                     // 10 SOC10 Start of Conversion Flag
    Uint16 SOC11:1;                     // 11 SOC11 Start of Conversion Flag
    Uint16 SOC12:1;                     // 12 SOC12 Start of Conversion Flag
    Uint16 SOC13:1;                     // 13 SOC13 Start of Conversion Flag
    Uint16 SOC14:1;                     // 14 SOC14 Start of Conversion Flag
    Uint16 SOC15:1;                     // 15 SOC15 Start of Conversion Flag
};

union ADCSOCFLG1_REG {
    Uint16  all;
    struct  ADCSOCFLG1_BITS  bit;
};

struct ADCSOCFRC1_BITS {                // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Force Start of Conversion Bit
    Uint16 SOC1:1;                      // 1 SOC1 Force Start of Conversion Bit
    Uint16 SOC2:1;                      // 2 SOC2 Force Start of Conversion Bit
    Uint16 SOC3:1;                      // 3 SOC3 Force Start of Conversion Bit
    Uint16 SOC4:1;                      // 4 SOC4 Force Start of Conversion Bit
    Uint16 SOC5:1;                      // 5 SOC5 Force Start of Conversion Bit
    Uint16 SOC6:1;                      // 6 SOC6 Force Start of Conversion Bit
    Uint16 SOC7:1;                      // 7 SOC7 Force Start of Conversion Bit
    Uint16 SOC8:1;                      // 8 SOC8 Force Start of Conversion Bit
    Uint16 SOC9:1;                      // 9 SOC9 Force Start of Conversion Bit
    Uint16 SOC10:1;                     // 10 SOC10 Force Start of Conversion Bit
    Uint16 SOC11:1;                     // 11 SOC11 Force Start of Conversion Bit
    Uint16 SOC12:1;                     // 12 SOC12 Force Start of Conversion Bit
    Uint16 SOC13:1;                     // 13 SOC13 Force Start of Conversion Bit
    Uint16 SOC14:1;                     // 14 SOC14 Force Start of Conversion Bit
    Uint16 SOC15:1;                     // 15 SOC15 Force Start of Conversion Bit
};

union ADCSOCFRC1_REG {
    Uint16  all;
    struct  ADCSOCFRC1_BITS  bit;
};

// ADCSOCFRC1 Register
//// ADCSOCFRC1 Register : Byte Value
#define ADCSOCFRC1_SOC15_SWSOC							0x8000						// Cause a Conversion to Start Once Priority is Given to SOC15.
#define ADCSOCFRC1_SOC14_SWSOC							0x4000						// Cause a Conversion to Start Once Priority is Given to SOC14.
#define ADCSOCFRC1_SOC13_SWSOC							0x2000						// Cause a Conversion to Start Once Priority is Given to SOC13.
#define ADCSOCFRC1_SOC12_SWSOC							0x1000						// Cause a Conversion to Start Once Priority is Given to SOC12.
#define ADCSOCFRC1_SOC11_SWSOC							0x0800						// Cause a Conversion to Start Once Priority is Given to SOC11.
#define ADCSOCFRC1_SOC10_SWSOC							0x0400						// Cause a Conversion to Start Once Priority is Given to SOC10.
#define ADCSOCFRC1_SOC9_SWSOC							0x0200						// Cause a Conversion to Start Once Priority is Given to SOC9.
#define ADCSOCFRC1_SOC8_SWSOC							0x0100						// Cause a Conversion to Start Once Priority is Given to SOC8.
#define ADCSOCFRC1_SOC7_SWSOC							0x0080						// Cause a Conversion to Start Once Priority is Given to SOC7.
#define ADCSOCFRC1_SOC6_SWSOC							0x0040						// Cause a Conversion to Start Once Priority is Given to SOC6.
#define ADCSOCFRC1_SOC5_SWSOC							0x0020						// Cause a Conversion to Start Once Priority is Given to SOC5.
#define ADCSOCFRC1_SOC4_SWSOC							0x0010						// Cause a Conversion to Start Once Priority is Given to SOC4.
#define ADCSOCFRC1_SOC3_SWSOC							0x0008						// Cause a Conversion to Start Once Priority is Given to SOC3.
#define ADCSOCFRC1_SOC2_SWSOC							0x0004						// Cause a Conversion to Start Once Priority is Given to SOC2.
#define ADCSOCFRC1_SOC1_SWSOC							0x0002						// Cause a Conversion to Start Once Priority is Given to SOC1.
#define ADCSOCFRC1_SOC0_SWSOC							0x0001						// Cause a Conversion to Start Once Priority is Given to SOC0.

struct ADCSOCOVF1_BITS {                // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Start of Conversion Overflow Flag
    Uint16 SOC1:1;                      // 1 SOC1 Start of Conversion Overflow Flag
    Uint16 SOC2:1;                      // 2 SOC2 Start of Conversion Overflow Flag
    Uint16 SOC3:1;                      // 3 SOC3 Start of Conversion Overflow Flag
    Uint16 SOC4:1;                      // 4 SOC4 Start of Conversion Overflow Flag
    Uint16 SOC5:1;                      // 5 SOC5 Start of Conversion Overflow Flag
    Uint16 SOC6:1;                      // 6 SOC6 Start of Conversion Overflow Flag
    Uint16 SOC7:1;                      // 7 SOC7 Start of Conversion Overflow Flag
    Uint16 SOC8:1;                      // 8 SOC8 Start of Conversion Overflow Flag
    Uint16 SOC9:1;                      // 9 SOC9 Start of Conversion Overflow Flag
    Uint16 SOC10:1;                     // 10 SOC10 Start of Conversion Overflow Flag
    Uint16 SOC11:1;                     // 11 SOC11 Start of Conversion Overflow Flag
    Uint16 SOC12:1;                     // 12 SOC12 Start of Conversion Overflow Flag
    Uint16 SOC13:1;                     // 13 SOC13 Start of Conversion Overflow Flag
    Uint16 SOC14:1;                     // 14 SOC14 Start of Conversion Overflow Flag
    Uint16 SOC15:1;                     // 15 SOC15 Start of Conversion Overflow Flag
};

union ADCSOCOVF1_REG {
    Uint16  all;
    struct  ADCSOCOVF1_BITS  bit;
};

struct ADCSOCOVFCLR1_BITS {             // bits description
    Uint16 SOC0:1;                      // 0 SOC0 Clear Start of Conversion Overflow Bit
    Uint16 SOC1:1;                      // 1 SOC1 Clear Start of Conversion Overflow Bit
    Uint16 SOC2:1;                      // 2 SOC2 Clear Start of Conversion Overflow Bit
    Uint16 SOC3:1;                      // 3 SOC3 Clear Start of Conversion Overflow Bit
    Uint16 SOC4:1;                      // 4 SOC4 Clear Start of Conversion Overflow Bit
    Uint16 SOC5:1;                      // 5 SOC5 Clear Start of Conversion Overflow Bit
    Uint16 SOC6:1;                      // 6 SOC6 Clear Start of Conversion Overflow Bit
    Uint16 SOC7:1;                      // 7 SOC7 Clear Start of Conversion Overflow Bit
    Uint16 SOC8:1;                      // 8 SOC8 Clear Start of Conversion Overflow Bit
    Uint16 SOC9:1;                      // 9 SOC9 Clear Start of Conversion Overflow Bit
    Uint16 SOC10:1;                     // 10 SOC10 Clear Start of Conversion Overflow Bit
    Uint16 SOC11:1;                     // 11 SOC11 Clear Start of Conversion Overflow Bit
    Uint16 SOC12:1;                     // 12 SOC12 Clear Start of Conversion Overflow Bit
    Uint16 SOC13:1;                     // 13 SOC13 Clear Start of Conversion Overflow Bit
    Uint16 SOC14:1;                     // 14 SOC14 Clear Start of Conversion Overflow Bit
    Uint16 SOC15:1;                     // 15 SOC15 Clear Start of Conversion Overflow Bit
};

union ADCSOCOVFCLR1_REG {
    Uint16  all;
    struct  ADCSOCOVFCLR1_BITS  bit;
};

// ADCSOCOVFCLR1 Register
//// ADCSOCOVFCLR1 Register : Byte Value
#define ADCSOCOVFCLR1_SOC15_OVFClear					0x8000						// Clear SOC15 Overflow Flag.
#define ADCSOCOVFCLR1_SOC14_OVFClear					0x4000						// Clear SOC14 Overflow Flag.
#define ADCSOCOVFCLR1_SOC13_OVFClear					0x2000						// Clear SOC13 Overflow Flag.
#define ADCSOCOVFCLR1_SOC12_OVFClear					0x1000						// Clear SOC12 Overflow Flag.
#define ADCSOCOVFCLR1_SOC11_OVFClear					0x0800						// Clear SOC11 Overflow Flag.
#define ADCSOCOVFCLR1_SOC10_OVFClear					0x0400						// Clear SOC10 Overflow Flag.
#define ADCSOCOVFCLR1_SOC9_OVFClear						0x0200						// Clear SOC9 Overflow Flag.
#define ADCSOCOVFCLR1_SOC8_OVFClear						0x0100						// Clear SOC8 Overflow Flag.
#define ADCSOCOVFCLR1_SOC7_OVFClear						0x0080						// Clear SOC7 Overflow Flag.
#define ADCSOCOVFCLR1_SOC6_OVFClear						0x0040						// Clear SOC6 Overflow Flag.
#define ADCSOCOVFCLR1_SOC5_OVFClear						0x0020						// Clear SOC5 Overflow Flag.
#define ADCSOCOVFCLR1_SOC4_OVFClear						0x0010						// Clear SOC4 Overflow Flag.
#define ADCSOCOVFCLR1_SOC3_OVFClear						0x0008						// Clear SOC3 Overflow Flag.
#define ADCSOCOVFCLR1_SOC2_OVFClear						0x0004						// Clear SOC2 Overflow Flag.
#define ADCSOCOVFCLR1_SOC1_OVFClear						0x0002						// Clear SOC1 Overflow Flag.
#define ADCSOCOVFCLR1_SOC0_OVFClear						0x0001						// Clear SOC0 Overflow Flag.

struct ADCSOC0CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC0CTL_REG {
    Uint32  all;
    struct  ADCSOC0CTL_BITS  bit;
};

struct ADCSOC1CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC1CTL_REG {
    Uint32  all;
    struct  ADCSOC1CTL_BITS  bit;
};

struct ADCSOC2CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC2CTL_REG {
    Uint32  all;
    struct  ADCSOC2CTL_BITS  bit;
};

struct ADCSOC3CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC3CTL_REG {
    Uint32  all;
    struct  ADCSOC3CTL_BITS  bit;
};

struct ADCSOC4CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC4CTL_REG {
    Uint32  all;
    struct  ADCSOC4CTL_BITS  bit;
};

struct ADCSOC5CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC5CTL_REG {
    Uint32  all;
    struct  ADCSOC5CTL_BITS  bit;
};

struct ADCSOC6CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC6CTL_REG {
    Uint32  all;
    struct  ADCSOC6CTL_BITS  bit;
};

struct ADCSOC7CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC7CTL_REG {
    Uint32  all;
    struct  ADCSOC7CTL_BITS  bit;
};

struct ADCSOC8CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC8CTL_REG {
    Uint32  all;
    struct  ADCSOC8CTL_BITS  bit;
};

struct ADCSOC9CTL_BITS {                // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC9CTL_REG {
    Uint32  all;
    struct  ADCSOC9CTL_BITS  bit;
};

struct ADCSOC10CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC10CTL_REG {
    Uint32  all;
    struct  ADCSOC10CTL_BITS  bit;
};

struct ADCSOC11CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC11CTL_REG {
    Uint32  all;
    struct  ADCSOC11CTL_BITS  bit;
};

struct ADCSOC12CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC12CTL_REG {
    Uint32  all;
    struct  ADCSOC12CTL_BITS  bit;
};

struct ADCSOC13CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC13CTL_REG {
    Uint32  all;
    struct  ADCSOC13CTL_BITS  bit;
};

struct ADCSOC14CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC14CTL_REG {
    Uint32  all;
    struct  ADCSOC14CTL_BITS  bit;
};

struct ADCSOC15CTL_BITS {               // bits description
    Uint16 ACQPS:9;                     // 8:0 SOC Acquisition Prescale
    Uint16 rsvd1:6;                     // 14:9 Reserved
    Uint32 CHSEL:4;                     // 18:15 SOC Channel Select
    Uint16 rsvd2:1;                     // 19 Reserved
    Uint16 TRIGSEL:5;                   // 24:20 SOC Trigger Source Select
    Uint16 rsvd3:7;                     // 31:25 Reserved
};

union ADCSOC15CTL_REG {
    Uint32  all;
    struct  ADCSOC15CTL_BITS  bit;
};

// ADCSOCxCTL Register
//// ADCSOCxCTL Register : Byte Value
#define ADCSOCxCTL_TRIGSEL_SW						0x00000000UL				// Software Only.
#define ADCSOCxCTL_TRIGSEL_CPU1_Timer0				0x00100000UL				// CPU1 Timer 0.
#define ADCSOCxCTL_TRIGSEL_CPU1_Timer1				0x00200000UL				// CPU1 Timer 1.
#define ADCSOCxCTL_TRIGSEL_CPU1_Timer2				0x00300000UL				// CPU1 Timer 2.
#define ADCSOCxCTL_TRIGSEL_INUPTXBAR5				0x00400000UL				// GPIO, Input X-Bar INPUT5.
#define ADCSOCxCTL_TRIGSEL_EPWM1_ADCSOCA			0x00500000UL				// ePWM1, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM1_ADCSOCB			0x00600000UL				// ePWM1, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM2_ADCSOCA			0x00700000UL				// ePWM2, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM2_ADCSOCB			0x00800000UL				// ePWM2, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM3_ADCSOCA			0x00900000UL				// ePWM3, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM3_ADCSOCB			0x00A00000UL				// ePWM3, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM4_ADCSOCA			0x00B00000UL				// ePWM4, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM4_ADCSOCB			0x00C00000UL				// ePWM4, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM5_ADCSOCA			0x00D00000UL				// ePWM5, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM5_ADCSOCB			0x00E00000UL				// ePWM5, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM6_ADCSOCA			0x00F00000UL				// ePWM6, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM6_ADCSOCB			0x01000000UL				// ePWM6, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM7_ADCSOCA			0x01100000UL				// ePWM7, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM7_ADCSOCB			0x01200000UL				// ePWM7, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM8_ADCSOCA			0x01300000UL				// ePWM8, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM8_ADCSOCB			0x01400000UL				// ePWM8, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM9_ADCSOCA			0x01500000UL				// ePWM9, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM9_ADCSOCB			0x01600000UL				// ePWM9, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM10_ADCSOCA			0x01700000UL				// ePWM10, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM10_ADCSOCB			0x01800000UL				// ePWM10, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM11_ADCSOCA			0x01900000UL				// ePWM11, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM11_ADCSOCB			0x01A00000UL				// ePWM11, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_EPWM12_ADCSOCA			0x01B00000UL				// ePWM12, ADCSOCA.
#define ADCSOCxCTL_TRIGSEL_EPWM12_ADCSOCB			0x01C00000UL				// ePWM12, ADCSOCB.
#define ADCSOCxCTL_TRIGSEL_CPU2_Timer0				0x01D00000UL				// CPU2 Timer 0.
#define ADCSOCxCTL_TRIGSEL_CPU2_Timer1				0x01E00000UL				// CPU2 Timer 1.
#define ADCSOCxCTL_TRIGSEL_CPU2_Timer2				0x01F00000UL				// CPU2 Timer 2.

////// ADCSOCxCTL Register : Byte Value - Single Ended Input
#define ADCSOCxCTL_CHSEL_SADCIN0					0x00000000UL				// Single-Ended Signal Mode. ADCIN0.
#define ADCSOCxCTL_CHSEL_SADCIN1					0x00008000UL				// Single-Ended Signal Mode. ADCIN1.
#define ADCSOCxCTL_CHSEL_SADCIN2					0x00010000UL				// Single-Ended Signal Mode. ADCIN2.
#define ADCSOCxCTL_CHSEL_SADCIN3					0x00018000UL				// Single-Ended Signal Mode. ADCIN3.
#define ADCSOCxCTL_CHSEL_SADCIN4					0x00020000UL				// Single-Ended Signal Mode. ADCIN4.
#define ADCSOCxCTL_CHSEL_SADCIN5					0x00028000UL				// Single-Ended Signal Mode. ADCIN5.
#define ADCSOCxCTL_CHSEL_SADCIN6					0x00030000UL				// Single-Ended Signal Mode. ADCIN6.
#define ADCSOCxCTL_CHSEL_SADCIN7					0x00038000UL				// Single-Ended Signal Mode. ADCIN7.
#define ADCSOCxCTL_CHSEL_SADCIN8					0x00040000UL				// Single-Ended Signal Mode. ADCIN8.
#define ADCSOCxCTL_CHSEL_SADCIN9					0x00048000UL				// Single-Ended Signal Mode. ADCIN9.
#define ADCSOCxCTL_CHSEL_SADCIN10					0x00050000UL				// Single-Ended Signal Mode. ADCIN10.
#define ADCSOCxCTL_CHSEL_SADCIN11					0x00058000UL				// Single-Ended Signal Mode. ADCIN11.
#define ADCSOCxCTL_CHSEL_SADCIN12					0x00060000UL				// Single-Ended Signal Mode. ADCIN12.
#define ADCSOCxCTL_CHSEL_SADCIN13					0x00068000UL				// Single-Ended Signal Mode. ADCIN13.
#define ADCSOCxCTL_CHSEL_SADCIN14					0x00070000UL				// Single-Ended Signal Mode. ADCIN14.
#define ADCSOCxCTL_CHSEL_SADCIN15					0x00078000UL				// Single-Ended Signal Mode. ADCIN15.

////// ADCSOCxCTL Register : Byte Value - Single Ended Input about ADC-A
#define ADCSOCxCTL_CHSEL_ADCA_ADCINA0				0x00000000UL
#define ADCSOCxCTL_CHSEL_ADCA_ADCINA1				0x00008000UL
#define ADCSOCxCTL_CHSEL_ADCA_ADCINA2				0x00010000UL
#define ADCSOCxCTL_CHSEL_ADCA_ADCINA3				0x00018000UL
#define ADCSOCxCTL_CHSEL_ADCA_ADCINA4				0x00020000UL
#define ADCSOCxCTL_CHSEL_ADCA_ADCINA5				0x00028000UL
#define ADCSOCxCTL_CHSEL_ADCA_VREFLOA               0x00040000UL
//#define ADCSOCxCTL_CHSEL_ADCA_VREFLOA				0x00048000UL
//#define ADCSOCxCTL_CHSEL_ADCA_ADCINA0				0x00060000UL
#define ADCSOCxCTL_CHSEL_ADCA_TEMP					0x00068000UL
#define ADCSOCxCTL_CHSEL_ADCA_ADCIN14				0x00070000UL
#define ADCSOCxCTL_CHSEL_ADCA_ADCIN15				0x00078000UL

////// ADCSOCxCTL Register : Byte Value - Single Ended Input about ADC-B
#define ADCSOCxCTL_CHSEL_ADCB_ADCINB0				0x00000000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCINB1				0x00008000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCINB2				0x00010000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCINB3				0x00018000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCINB4				0x00020000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCINB5				0x00028000UL
#define ADCSOCxCTL_CHSEL_ADCB_VREFLOB				0x00040000UL
//#define ADCSOCxCTL_CHSEL_ADCB_VREFLOB				0x00048000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCINA0				0x00060000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCIN14				0x00070000UL
#define ADCSOCxCTL_CHSEL_ADCB_ADCIN15				0x00078000UL

////// ADCSOCxCTL Register : Byte Value - Single Ended Input about ADC-C
#define ADCSOCxCTL_CHSEL_ADCC_ADCINC2				0x00010000UL
#define ADCSOCxCTL_CHSEL_ADCC_ADCINC3				0x00018000UL
#define ADCSOCxCTL_CHSEL_ADCC_ADCINC4				0x00020000UL
#define ADCSOCxCTL_CHSEL_ADCC_ADCINC5				0x00028000UL
#define ADCSOCxCTL_CHSEL_ADCC_VREFLOC				0x00040000UL
//#define ADCSOCxCTL_CHSEL_ADCC_VREFLOC				0x00048000UL
#define ADCSOCxCTL_CHSEL_ADCC_ADCINA0				0x00060000UL
#define ADCSOCxCTL_CHSEL_ADCC_ADCIN14				0x00070000UL
#define ADCSOCxCTL_CHSEL_ADCC_ADCIN15				0x00078000UL

////// ADCSOCxCTL Register : Byte Value - Single Ended Input about ADC-D
#define ADCSOCxCTL_CHSEL_ADCD_ADCIND0				0x00000000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCIND1				0x00008000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCIND2				0x00010000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCIND3				0x00018000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCIND4				0x00020000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCIND5				0x00028000UL
#define ADCSOCxCTL_CHSEL_ADCD_VREFLOD				0x00040000UL
//#define ADCSOCxCTL_CHSEL_ADCD_VREFLOD				0x00048000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCINA0				0x00060000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCIN14				0x00070000UL
#define ADCSOCxCTL_CHSEL_ADCD_ADCIN15				0x00078000UL

////// ADCSOCxCTL Register : Byte Value - Differential Input
#define ADCSOCxCTL_CHSEL_DADCIN0_ADCIN1				0x00000000UL				// Differential Signal Mode. ADCIN0 - ADCIN1.
#define ADCSOCxCTL_CHSEL_DADCIN2_ADCIN3				0x00010000UL				// Differential Signal Mode. ADCIN2 - ADCIN3.
#define ADCSOCxCTL_CHSEL_DADCIN4_ADCIN5				0x00020000UL				// Differential Signal Mode. ADCIN4 - ADCIN5.
#define ADCSOCxCTL_CHSEL_DADCIN6_ADCIN7				0x00030000UL				// Differential Signal Mode. ADCIN6 - ADCIN7.
#define ADCSOCxCTL_CHSEL_DADCIN8_ADCIN9				0x00040000UL				// Differential Signal Mode. ADCIN8 - ADCIN9.
#define ADCSOCxCTL_CHSEL_DADCIN10_ADCIN11			0x00050000UL				// Differential Signal Mode. ADCIN10 - ADCIN11.
#define ADCSOCxCTL_CHSEL_DADCIN12_ADCIN13			0x00060000UL				// Differential Signal Mode. ADCIN12 - ADCIN13.
#define ADCSOCxCTL_CHSEL_DADCIN14_ADCIN15			0x00070000UL				// Differential Signal Mode. ADCIN14 - ADCIN15.

#define ADCSOCxCTL_ACQPS_SampleWindow(wide)			((wide - 1) & 0x000001FF)	// S/H Windows Length. "wide" System Clock Cycle Wide. At Least as Long as one ADCCLK Cycle for Correct ADC Operation.

struct ADCEVTSTAT_BITS {                // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Flag
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Flag
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Flag
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Flag
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Flag
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Flag
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Flag
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Flag
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Flag
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Flag
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Flag
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Flag
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTSTAT_REG {
    Uint16  all;
    struct  ADCEVTSTAT_BITS  bit;
};

struct ADCEVTCLR_BITS {                 // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Clear
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Clear
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Clear
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Clear
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Clear
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Clear
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Clear
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Clear
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Clear
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Clear
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Clear
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Clear
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTCLR_REG {
    Uint16  all;
    struct  ADCEVTCLR_BITS  bit;
};

// ADCEVTCLR Register
//// ADCEVTCLR Register : Byte Value
#define ADCEVTCLR_PPB4ZERO_ZeroCrossClear			0x4000						// Post Processing Block 4 Zero Crossing Clear.
#define ADCEVTCLR_PPB4TRIPLO_TripLowClear			0x2000						// Post Processing Block 4 Trip Low Clear.
#define ADCEVTCLR_PPB4TRIPHI_TripHighClear			0x1000						// Post Processing Block 4 Trip High Clear.

#define ADCEVTCLR_PPB3ZERO_ZeroCrossClear			0x0400						// Post Processing Block 3 Zero Crossing Clear.
#define ADCEVTCLR_PPB3TRIPLO_TripLowClear			0x0200						// Post Processing Block 3 Trip Low Clear.
#define ADCEVTCLR_PPB3TRIPHI_TripHighClear			0x0100						// Post Processing Block 3 Trip High Clear.

#define ADCEVTCLR_PPB2ZERO_ZeroCrossClear			0x0040						// Post Processing Block 2 Zero Crossing Clear.
#define ADCEVTCLR_PPB2TRIPLO_TripLowClear			0x0020						// Post Processing Block 2 Trip Low Clear.
#define ADCEVTCLR_PPB2TRIPHI_TripHighClear			0x0010						// Post Processing Block 2 Trip High Clear.

#define ADCEVTCLR_PPB1ZERO_ZeroCrossClear			0x0004						// Post Processing Block 1 Zero Crossing Clear.
#define ADCEVTCLR_PPB1TRIPLO_TripLowClear			0x0002						// Post Processing Block 1 Trip Low Clear.
#define ADCEVTCLR_PPB1TRIPHI_TripHighClear			0x0001						// Post Processing Block 1 Trip High Clear.

struct ADCEVTSEL_BITS {                 // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Event Enable
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Event Enable
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Event Enable
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Event Enable
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Event Enable
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Event Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Event Enable
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Event Enable
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Event Enable
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Event Enable
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Event Enable
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Event Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTSEL_REG {
    Uint16  all;
    struct  ADCEVTSEL_BITS  bit;
};

// ADCEVTSEL Register
//// ADCEVTSEL Register : Byte Value
#define ADCEVTSEL_PPB4ZERO_ZeroCrossEvtDis			0x0000						// Post Processing Block 4 Zero Crossing Event Disable.
#define ADCEVTSEL_PPB4ZERO_ZeroCrossEvtEn			0x4000						// Post Processing Block 4 Zero Crossing Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB4TRIPLO_TripLowEvtDis			0x0000						// Post Processing Block 4 Trip Low Event Disable.
#define ADCEVTSEL_PPB4TRIPLO_TripLowEvtEn			0x2000						// Post Processing Block 4 Trip Low Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB4TRIPHI_TripHighEvtDis			0x0000						// Post Processing Block 4 Trip High Event Disable.
#define ADCEVTSEL_PPB4TRIPHI_TripHighEvtEn			0x1000						// Post Processing Block 4 Trip High Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB3ZERO_ZeroCrossEvtDis			0x0000						// Post Processing Block 3 Zero Crossing Event Disable.
#define ADCEVTSEL_PPB3ZERO_ZeroCrossEvtEn			0x0400						// Post Processing Block 3 Zero Crossing Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB3TRIPLO_TripLowEvtDis			0x0000						// Post Processing Block 3 Trip Low Event Disable.
#define ADCEVTSEL_PPB3TRIPLO_TripLowEvtEn			0x0200						// Post Processing Block 3 Trip Low Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB3TRIPHI_TripHighEvtDis			0x0000						// Post Processing Block 3 Trip High Event Disable.
#define ADCEVTSEL_PPB3TRIPHI_TripHighEvtEn			0x0100						// Post Processing Block 3 Trip High Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB2ZERO_ZeroCrossEvtDis			0x0000						// Post Processing Block 2 Zero Crossing Event Disable.
#define ADCEVTSEL_PPB2ZERO_ZeroCrossEvtEn			0x0040						// Post Processing Block 2 Zero Crossing Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB2TRIPLO_TripLowEvtDis			0x0000						// Post Processing Block 2 Trip Low Event Disable.
#define ADCEVTSEL_PPB2TRIPLO_TripLowEvtEn			0x0020						// Post Processing Block 2 Trip Low Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB2TRIPHI_TripHighEvtDis			0x0000						// Post Processing Block 2 Trip High Event Disable.
#define ADCEVTSEL_PPB2TRIPHI_TripHighEvtEn			0x0010						// Post Processing Block 2 Trip High Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB1ZERO_ZeroCrossEvtDis			0x0000						// Post Processing Block 1 Zero Crossing Event Disable.
#define ADCEVTSEL_PPB1ZERO_ZeroCrossEvtEn			0x0004						// Post Processing Block 1 Zero Crossing Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB1TRIPLO_TripLowEvtDis			0x0000						// Post Processing Block 1 Trip Low Event Disable.
#define ADCEVTSEL_PPB1TRIPLO_TripLowEvtEn			0x0002						// Post Processing Block 1 Trip Low Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

#define ADCEVTSEL_PPB1TRIPHI_TripHighEvtDis			0x0000						// Post Processing Block 1 Trip High Event Disable.
#define ADCEVTSEL_PPB1TRIPHI_TripHighEvtEn			0x0001						// Post Processing Block 1 Trip High Event Enable. Allows the Corresponding Flag to Active the Event Signal to the PWM Blocks.

struct ADCEVTINTSEL_BITS {              // bits description
    Uint16 PPB1TRIPHI:1;                // 0 Post Processing Block 1 Trip High Interrupt Enable
    Uint16 PPB1TRIPLO:1;                // 1 Post Processing Block 1 Trip Low Interrupt Enable
    Uint16 PPB1ZERO:1;                  // 2 Post Processing Block 1 Zero Crossing Interrupt Enable
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 PPB2TRIPHI:1;                // 4 Post Processing Block 2 Trip High Interrupt Enable
    Uint16 PPB2TRIPLO:1;                // 5 Post Processing Block 2 Trip Low Interrupt Enable
    Uint16 PPB2ZERO:1;                  // 6 Post Processing Block 2 Zero Crossing Interrupt Enable
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 PPB3TRIPHI:1;                // 8 Post Processing Block 3 Trip High Interrupt Enable
    Uint16 PPB3TRIPLO:1;                // 9 Post Processing Block 3 Trip Low Interrupt Enable
    Uint16 PPB3ZERO:1;                  // 10 Post Processing Block 3 Zero Crossing Interrupt Enable
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 PPB4TRIPHI:1;                // 12 Post Processing Block 4 Trip High Interrupt Enable
    Uint16 PPB4TRIPLO:1;                // 13 Post Processing Block 4 Trip Low Interrupt Enable
    Uint16 PPB4ZERO:1;                  // 14 Post Processing Block 4 Zero Crossing Interrupt Enable
    Uint16 rsvd4:1;                     // 15 Reserved
};

union ADCEVTINTSEL_REG {
    Uint16  all;
    struct  ADCEVTINTSEL_BITS  bit;
};

// ADCEVTINTSEL Register
//// ADCEVTINTSEL Register : Byte Value
#define ADCEVTINTSEL_PPB4ZERO_ZeroCrossIntDis		0x0000						// Post Processing Block 4 Zero Crossing Interrupt Disable.
#define ADCEVTINTSEL_PPB4ZERO_ZeroCrossIntEn		0x4000						// Post Processing Block 4 Zero Crossing Interrupt Enable.

#define ADCEVTINTSEL_PPB4TRIPLO_TripLowIntDis		0x0000						// Post Processing Block 4 Trip Low Interrupt Disable.
#define ADCEVTINTSEL_PPB4TRIPLO_TripLowIntEn		0x2000						// Post Processing Block 4 Trip Low Interrupt Enable.

#define ADCEVTINTSEL_PPB4TRIPHI_TripHighIntDis		0x0000						// Post Processing Block 4 Trip High Interrupt Disable.
#define ADCEVTINTSEL_PPB4TRIPHI_TripHighIntEn		0x1000						// Post Processing Block 4 Trip High Interrupt Enable.

#define ADCEVTINTSEL_PPB3ZERO_ZeroCrossIntDis		0x0000						// Post Processing Block 3 Zero Crossing Interrupt Disable.
#define ADCEVTINTSEL_PPB3ZERO_ZeroCrossIntEn		0x0400						// Post Processing Block 3 Zero Crossing Interrupt Enable.

#define ADCEVTINTSEL_PPB3TRIPLO_TripLowIntDis		0x0000						// Post Processing Block 3 Trip Low Interrupt Disable.
#define ADCEVTINTSEL_PPB3TRIPLO_TripLowIntEn		0x0200						// Post Processing Block 3 Trip Low Interrupt Enable.

#define ADCEVTINTSEL_PPB3TRIPHI_TripHighIntDis		0x0000						// Post Processing Block 3 Trip High Interrupt Disable.
#define ADCEVTINTSEL_PPB3TRIPHI_TripHighIntEn		0x0100						// Post Processing Block 3 Trip High Interrupt Enable.

#define ADCEVTINTSEL_PPB2ZERO_ZeroCrossIntDis		0x0000						// Post Processing Block 2 Zero Crossing Interrupt Disable.
#define ADCEVTINTSEL_PPB2ZERO_ZeroCrossIntEn		0x0040						// Post Processing Block 2 Zero Crossing Interrupt Enable.

#define ADCEVTINTSEL_PPB2TRIPLO_TripLowIntDis		0x0000						// Post Processing Block 2 Trip Low Interrupt Disable.
#define ADCEVTINTSEL_PPB2TRIPLO_TripLowIntEn		0x0020						// Post Processing Block 2 Trip Low Interrupt Enable.

#define ADCEVTINTSEL_PPB2TRIPHI_TripHighIntDis		0x0000						// Post Processing Block 2 Trip High Interrupt Disable.
#define ADCEVTINTSEL_PPB2TRIPHI_TripHighIntEn		0x0010						// Post Processing Block 2 Trip High Interrupt Enable.

#define ADCEVTINTSEL_PPB1ZERO_ZeroCrossIntDis		0x0000						// Post Processing Block 1 Zero Crossing Interrupt Disable.
#define ADCEVTINTSEL_PPB1ZERO_ZeroCrossIntEn		0x0004						// Post Processing Block 1 Zero Crossing Interrupt Enable.

#define ADCEVTINTSEL_PPB1TRIPLO_TripLowIntDis		0x0000						// Post Processing Block 1 Trip Low Interrupt Disable.
#define ADCEVTINTSEL_PPB1TRIPLO_TripLowIntEn		0x0002						// Post Processing Block 1 Trip Low Interrupt Enable.

#define ADCEVTINTSEL_PPB1TRIPHI_TripHighIntDis		0x0000						// Post Processing Block 1 Trip High Interrupt Disable.
#define ADCEVTINTSEL_PPB1TRIPHI_TripHighIntEn		0x0001						// Post Processing Block 1 Trip High Interrupt Enable.

struct ADCCOUNTER_BITS {                // bits description
    Uint16 FREECOUNT:12;                // 11:0 ADC Free Running Counter Value
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCCOUNTER_REG {
    Uint16  all;
    struct  ADCCOUNTER_BITS  bit;
};

struct ADCREV_BITS {                    // bits description
    Uint16 TYPE:8;                      // 7:0 ADC Type
    Uint16 REV:8;                       // 15:8 ADC Revision
};

union ADCREV_REG {
    Uint16  all;
    struct  ADCREV_BITS  bit;
};

struct ADCOFFTRIM_BITS {                // bits description
    Uint16 OFFTRIM:8;                   // 7:0 ADC Offset Trim
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union ADCOFFTRIM_REG {
    Uint16  all;
    struct  ADCOFFTRIM_BITS  bit;
};

struct ADCPPB1CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB1CONFIG_REG {
    Uint16  all;
    struct  ADCPPB1CONFIG_BITS  bit;
};

struct ADCPPB1STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB1STAMP_REG {
    Uint16  all;
    struct  ADCPPB1STAMP_BITS  bit;
};

struct ADCPPB1OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB1OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB1OFFCAL_BITS  bit;
};

struct ADCPPB1TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB1TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB1TRIPHI_BITS  bit;
};

struct ADCPPB1TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB1TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB1TRIPLO_BITS  bit;
};

struct ADCPPB2CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB2CONFIG_REG {
    Uint16  all;
    struct  ADCPPB2CONFIG_BITS  bit;
};

struct ADCPPB2STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB2STAMP_REG {
    Uint16  all;
    struct  ADCPPB2STAMP_BITS  bit;
};

struct ADCPPB2OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB2OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB2OFFCAL_BITS  bit;
};

struct ADCPPB2TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB2TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB2TRIPHI_BITS  bit;
};

struct ADCPPB2TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB2TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB2TRIPLO_BITS  bit;
};

struct ADCPPB3CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB3CONFIG_REG {
    Uint16  all;
    struct  ADCPPB3CONFIG_BITS  bit;
};

struct ADCPPB3STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB3STAMP_REG {
    Uint16  all;
    struct  ADCPPB3STAMP_BITS  bit;
};

struct ADCPPB3OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB3OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB3OFFCAL_BITS  bit;
};

struct ADCPPB3TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB3TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB3TRIPHI_BITS  bit;
};

struct ADCPPB3TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB3TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB3TRIPLO_BITS  bit;
};

struct ADCPPB4CONFIG_BITS {             // bits description
    Uint16 CONFIG:4;                    // 3:0 ADC Post Processing Block Configuration
    Uint16 TWOSCOMPEN:1;                // 4 ADC Post Processing Block Two's Complement Enable
    Uint16 rsvd1:11;                    // 15:5 Reserved
};

union ADCPPB4CONFIG_REG {
    Uint16  all;
    struct  ADCPPB4CONFIG_BITS  bit;
};

// ADCPPBxCONFIG Register
//// ADCPPBxCONFIG Register : Byte Value
#define ADCPPBxCONFIG_CBCEN_ManualClearADCEVTSTAT	0x0000						// ADC Post Processing Block Cycle By Cycle Disable.
#define ADCPPBxCONFIG_CBCEN_AutoClearADCEVTSTAT		0x0020						// ADC Post Processing Block Cycle By Cycle Enable. The Post Conversion H/W Processing Circuit to Automatically Clear the ADCEVTSTAT on a Conversion If the Event Condition is No Longer Present.

#define ADCPPBxCONFIG_TWOSCOMPEN_NorADCPPBxRESULT	0x0000						// ADCPPBxRESULT = ADCRESULTx - ADCPPBxOFFREF.
#define ADCPPBxCONFIG_TWOSCOMPEN_InvADCPPBxRESULT	0x0010						// ADCPPBxRESULT = ADCPPBxOFFREF - ADCRESULTx.

#define ADCPPBxCONFIG_CONFIG_SOC0Source				0x0000						// SOC0/EOC0/RESULT0 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC1Source				0x0001						// SOC0/EOC0/RESULT1 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC2Source				0x0002						// SOC0/EOC0/RESULT2 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC3Source				0x0003						// SOC0/EOC0/RESULT3 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC4Source				0x0004						// SOC0/EOC0/RESULT4 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC5Source				0x0005						// SOC0/EOC0/RESULT5 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC6Source				0x0006						// SOC0/EOC0/RESULT6 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC7Source				0x0007						// SOC0/EOC0/RESULT7 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC8Source				0x0008						// SOC0/EOC0/RESULT8 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC9Source				0x0009						// SOC0/EOC0/RESULT9 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC10Source			0x000A						// SOC0/EOC0/RESULT10 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC11Source			0x000B						// SOC0/EOC0/RESULT11 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC12Source			0x000C						// SOC0/EOC0/RESULT12 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC13Source			0x000D						// SOC0/EOC0/RESULT13 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC14Source			0x000E						// SOC0/EOC0/RESULT14 is Associated with Post Processing Block x.
#define ADCPPBxCONFIG_CONFIG_SOC15Source			0x000F						// SOC0/EOC0/RESULT15 is Associated with Post Processing Block x.

struct ADCPPB4STAMP_BITS {              // bits description
    Uint16 DLYSTAMP:12;                 // 11:0 ADC Post Processing Block Delay Time Stamp
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union ADCPPB4STAMP_REG {
    Uint16  all;
    struct  ADCPPB4STAMP_BITS  bit;
};

struct ADCPPB4OFFCAL_BITS {             // bits description
    Uint16 OFFCAL:10;                   // 9:0 ADC Post Processing Block Offset Correction
    Uint16 rsvd1:6;                     // 15:10 Reserved
};

union ADCPPB4OFFCAL_REG {
    Uint16  all;
    struct  ADCPPB4OFFCAL_BITS  bit;
};

struct ADCPPB4TRIPHI_BITS {             // bits description
    Uint16 LIMITHI:16;                  // 15:0 ADC Post Processing Block Trip High Limit
    Uint16 HSIGN:1;                     // 16 High Limit Sign Bit
    Uint16 rsvd1:15;                    // 31:17 Reserved
};

union ADCPPB4TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB4TRIPHI_BITS  bit;
};

struct ADCPPB4TRIPLO_BITS {             // bits description
    Uint16 LIMITLO:16;                  // 15:0 ADC Post Processing Block Trip Low Limit
    Uint16 LSIGN:1;                     // 16 Low Limit Sign Bit
    Uint16 rsvd1:3;                     // 19:17 Reserved
    Uint16 REQSTAMP:12;                 // 31:20 ADC Post Processing Block Request Time Stamp
};

union ADCPPB4TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB4TRIPLO_BITS  bit;
};

struct ADC_REGS {
    union   ADCCTL1_REG                      ADCCTL1;                      // ADC Control 1 Register
    union   ADCCTL2_REG                      ADCCTL2;                      // ADC Control 2 Register
    union   ADCBURSTCTL_REG                  ADCBURSTCTL;                  // ADC Burst Control Register
    union   ADCINTFLG_REG                    ADCINTFLG;                    // ADC Interrupt Flag Register
    union   ADCINTFLGCLR_REG                 ADCINTFLGCLR;                 // ADC Interrupt Flag Clear Register
    union   ADCINTOVF_REG                    ADCINTOVF;                    // ADC Interrupt Overflow Register
    union   ADCINTOVFCLR_REG                 ADCINTOVFCLR;                 // ADC Interrupt Overflow Clear Register
    union   ADCINTSEL1N2_REG                 ADCINTSEL1N2;                 // ADC Interrupt 1 and 2 Selection Register
    union   ADCINTSEL3N4_REG                 ADCINTSEL3N4;                 // ADC Interrupt 3 and 4 Selection Register
    union   ADCSOCPRICTL_REG                 ADCSOCPRICTL;                 // ADC SOC Priority Control Register
    union   ADCINTSOCSEL1_REG                ADCINTSOCSEL1;                // ADC Interrupt SOC Selection 1 Register
    union   ADCINTSOCSEL2_REG                ADCINTSOCSEL2;                // ADC Interrupt SOC Selection 2 Register
    union   ADCSOCFLG1_REG                   ADCSOCFLG1;                   // ADC SOC Flag 1 Register
    union   ADCSOCFRC1_REG                   ADCSOCFRC1;                   // ADC SOC Force 1 Register
    union   ADCSOCOVF1_REG                   ADCSOCOVF1;                   // ADC SOC Overflow 1 Register
    union   ADCSOCOVFCLR1_REG                ADCSOCOVFCLR1;                // ADC SOC Overflow Clear 1 Register
    union   ADCSOC0CTL_REG                   ADCSOC0CTL;                   // ADC SOC0 Control Register
    union   ADCSOC1CTL_REG                   ADCSOC1CTL;                   // ADC SOC1 Control Register
    union   ADCSOC2CTL_REG                   ADCSOC2CTL;                   // ADC SOC2 Control Register
    union   ADCSOC3CTL_REG                   ADCSOC3CTL;                   // ADC SOC3 Control Register
    union   ADCSOC4CTL_REG                   ADCSOC4CTL;                   // ADC SOC4 Control Register
    union   ADCSOC5CTL_REG                   ADCSOC5CTL;                   // ADC SOC5 Control Register
    union   ADCSOC6CTL_REG                   ADCSOC6CTL;                   // ADC SOC6 Control Register
    union   ADCSOC7CTL_REG                   ADCSOC7CTL;                   // ADC SOC7 Control Register
    union   ADCSOC8CTL_REG                   ADCSOC8CTL;                   // ADC SOC8 Control Register
    union   ADCSOC9CTL_REG                   ADCSOC9CTL;                   // ADC SOC9 Control Register
    union   ADCSOC10CTL_REG                  ADCSOC10CTL;                  // ADC SOC10 Control Register
    union   ADCSOC11CTL_REG                  ADCSOC11CTL;                  // ADC SOC11 Control Register
    union   ADCSOC12CTL_REG                  ADCSOC12CTL;                  // ADC SOC12 Control Register
    union   ADCSOC13CTL_REG                  ADCSOC13CTL;                  // ADC SOC13 Control Register
    union   ADCSOC14CTL_REG                  ADCSOC14CTL;                  // ADC SOC14 Control Register
    union   ADCSOC15CTL_REG                  ADCSOC15CTL;                  // ADC SOC15 Control Register
    union   ADCEVTSTAT_REG                   ADCEVTSTAT;                   // ADC Event Status Register
    Uint16                                   rsvd1;                        // Reserved
    union   ADCEVTCLR_REG                    ADCEVTCLR;                    // ADC Event Clear Register
    Uint16                                   rsvd2;                        // Reserved
    union   ADCEVTSEL_REG                    ADCEVTSEL;                    // ADC Event Selection Register
    Uint16                                   rsvd3;                        // Reserved
    union   ADCEVTINTSEL_REG                 ADCEVTINTSEL;                 // ADC Event Interrupt Selection Register
    Uint16                                   rsvd4[2];                     // Reserved
    union   ADCCOUNTER_REG                   ADCCOUNTER;                   // ADC Counter Register
    union   ADCREV_REG                       ADCREV;                       // ADC Revision Register
    union   ADCOFFTRIM_REG                   ADCOFFTRIM;                   // ADC Offset Trim Register
    Uint16                                   rsvd5[4];                     // Reserved
    union   ADCPPB1CONFIG_REG                ADCPPB1CONFIG;                // ADC PPB1 Config Register
    union   ADCPPB1STAMP_REG                 ADCPPB1STAMP;                 // ADC PPB1 Sample Delay Time Stamp Register
    union   ADCPPB1OFFCAL_REG                ADCPPB1OFFCAL;                // ADC PPB1 Offset Calibration Register
    Uint16                                   ADCPPB1OFFREF;                // ADC PPB1 Offset Reference Register
    union   ADCPPB1TRIPHI_REG                ADCPPB1TRIPHI;                // ADC PPB1 Trip High Register
    union   ADCPPB1TRIPLO_REG                ADCPPB1TRIPLO;                // ADC PPB1 Trip Low/Trigger Time Stamp Register
    union   ADCPPB2CONFIG_REG                ADCPPB2CONFIG;                // ADC PPB2 Config Register
    union   ADCPPB2STAMP_REG                 ADCPPB2STAMP;                 // ADC PPB2 Sample Delay Time Stamp Register
    union   ADCPPB2OFFCAL_REG                ADCPPB2OFFCAL;                // ADC PPB2 Offset Calibration Register
    Uint16                                   ADCPPB2OFFREF;                // ADC PPB2 Offset Reference Register
    union   ADCPPB2TRIPHI_REG                ADCPPB2TRIPHI;                // ADC PPB2 Trip High Register
    union   ADCPPB2TRIPLO_REG                ADCPPB2TRIPLO;                // ADC PPB2 Trip Low/Trigger Time Stamp Register
    union   ADCPPB3CONFIG_REG                ADCPPB3CONFIG;                // ADC PPB3 Config Register
    union   ADCPPB3STAMP_REG                 ADCPPB3STAMP;                 // ADC PPB3 Sample Delay Time Stamp Register
    union   ADCPPB3OFFCAL_REG                ADCPPB3OFFCAL;                // ADC PPB3 Offset Calibration Register
    Uint16                                   ADCPPB3OFFREF;                // ADC PPB3 Offset Reference Register
    union   ADCPPB3TRIPHI_REG                ADCPPB3TRIPHI;                // ADC PPB3 Trip High Register
    union   ADCPPB3TRIPLO_REG                ADCPPB3TRIPLO;                // ADC PPB3 Trip Low/Trigger Time Stamp Register
    union   ADCPPB4CONFIG_REG                ADCPPB4CONFIG;                // ADC PPB4 Config Register
    union   ADCPPB4STAMP_REG                 ADCPPB4STAMP;                 // ADC PPB4 Sample Delay Time Stamp Register
    union   ADCPPB4OFFCAL_REG                ADCPPB4OFFCAL;                // ADC PPB4 Offset Calibration Register
    Uint16                                   ADCPPB4OFFREF;                // ADC PPB4 Offset Reference Register
    union   ADCPPB4TRIPHI_REG                ADCPPB4TRIPHI;                // ADC PPB4 Trip High Register
    union   ADCPPB4TRIPLO_REG                ADCPPB4TRIPLO;                // ADC PPB4 Trip Low/Trigger Time Stamp Register
    Uint16                                   rsvd6[16];                    // Reserved
    Uint32                                   ADCINLTRIM1;                  // ADC Linearity Trim 1 Register
    Uint32                                   ADCINLTRIM2;                  // ADC Linearity Trim 2 Register
    Uint32                                   ADCINLTRIM3;                  // ADC Linearity Trim 3 Register
    Uint32                                   ADCINLTRIM4;                  // ADC Linearity Trim 4 Register
    Uint32                                   ADCINLTRIM5;                  // ADC Linearity Trim 5 Register
    Uint32                                   ADCINLTRIM6;                  // ADC Linearity Trim 6 Register
    Uint16                                   rsvd7[4];                     // Reserved
};

struct ADCPPB1RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB1RESULT_REG {
    Uint32  all;
    struct  ADCPPB1RESULT_BITS  bit;
};

struct ADCPPB2RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB2RESULT_REG {
    Uint32  all;
    struct  ADCPPB2RESULT_BITS  bit;
};

struct ADCPPB3RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB3RESULT_REG {
    Uint32  all;
    struct  ADCPPB3RESULT_BITS  bit;
};

struct ADCPPB4RESULT_BITS {             // bits description
    Uint16 PPBRESULT:16;                // 15:0 ADC Post Processing Block Result
    Uint16 SIGN:16;                     // 31:16 Sign Extended Bits
};

union ADCPPB4RESULT_REG {
    Uint32  all;
    struct  ADCPPB4RESULT_BITS  bit;
};

struct ADC_RESULT_REGS {
    Uint16                                   ADCRESULT0;                   // ADC Result 0 Register
    Uint16                                   ADCRESULT1;                   // ADC Result 1 Register
    Uint16                                   ADCRESULT2;                   // ADC Result 2 Register
    Uint16                                   ADCRESULT3;                   // ADC Result 3 Register
    Uint16                                   ADCRESULT4;                   // ADC Result 4 Register
    Uint16                                   ADCRESULT5;                   // ADC Result 5 Register
    Uint16                                   ADCRESULT6;                   // ADC Result 6 Register
    Uint16                                   ADCRESULT7;                   // ADC Result 7 Register
    Uint16                                   ADCRESULT8;                   // ADC Result 8 Register
    Uint16                                   ADCRESULT9;                   // ADC Result 9 Register
    Uint16                                   ADCRESULT10;                  // ADC Result 10 Register
    Uint16                                   ADCRESULT11;                  // ADC Result 11 Register
    Uint16                                   ADCRESULT12;                  // ADC Result 12 Register
    Uint16                                   ADCRESULT13;                  // ADC Result 13 Register
    Uint16                                   ADCRESULT14;                  // ADC Result 14 Register
    Uint16                                   ADCRESULT15;                  // ADC Result 15 Register
    union   ADCPPB1RESULT_REG                ADCPPB1RESULT;                // ADC Post Processing Block 1 Result Register
    union   ADCPPB2RESULT_REG                ADCPPB2RESULT;                // ADC Post Processing Block 2 Result Register
    union   ADCPPB3RESULT_REG                ADCPPB3RESULT;                // ADC Post Processing Block 3 Result Register
    union   ADCPPB4RESULT_REG                ADCPPB4RESULT;                // ADC Post Processing Block 4 Result Register
};

//---------------------------------------------------------------------------
// ADC External References & Function Declarations:
//
#ifdef CPU1
extern volatile struct ADC_RESULT_REGS AdcaResultRegs;
extern volatile struct ADC_RESULT_REGS AdcbResultRegs;
extern volatile struct ADC_RESULT_REGS AdccResultRegs;
extern volatile struct ADC_RESULT_REGS AdcdResultRegs;
extern volatile struct ADC_REGS AdcaRegs;
extern volatile struct ADC_REGS AdcbRegs;
extern volatile struct ADC_REGS AdccRegs;
extern volatile struct ADC_REGS AdcdRegs;
#endif
#ifdef CPU2
extern volatile struct ADC_RESULT_REGS AdcaResultRegs;
extern volatile struct ADC_RESULT_REGS AdcbResultRegs;
extern volatile struct ADC_RESULT_REGS AdccResultRegs;
extern volatile struct ADC_RESULT_REGS AdcdResultRegs;
extern volatile struct ADC_REGS AdcaRegs;
extern volatile struct ADC_REGS AdcbRegs;
extern volatile struct ADC_REGS AdccRegs;
extern volatile struct ADC_REGS AdcdRegs;
#endif
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
