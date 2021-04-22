/*
 * GPIO.c
 *
 *  Created on: 2015. 4. 21.
 *     Power Conversion Lab, Pusan Univ, Korea.
 */

/*
 * GPIO 0~7 : Digital Input/Output
 * GPIO 8~11 : Do not use
 * GPIO 12~13 : CAN
 * GPIO 14~15 : SCI
 *
 */

#include "Define_Header.h"

void Init_GPIO(void)
{
	EALLOW;
//-------------------------------------------------------------------------------------------------//
//-------------------------------------------- GPIOA-1 --------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// GPIOA-1 MUX
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;		// 0(GPIO0), 	1(EPWM1A[O]),	2(Reserved),	3(Reserved)				; GPIO0(DO_1)
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;		// 0(GPIO1), 	1(EPWM1B[O]),	2(ECAP6[I/O]),	3(MFSRB[I/O])			; GPIO1(DO_2)
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;		// 0(GPIO2), 	1(EPWM2A[O]), 	2(Reserved), 	3(Reserved)				; GPIO2(DO_3)
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;		// 0(GPIO3), 	1(EPWM2B[O]), 	2(ECAP5[I/O]),	3(MCLKRB[I/O])			; GPIO3(DO_4)
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;		// 0(GPIO4), 	1(EPWM3A[O]), 	2(Reserved), 	3(Reserved)				; GPIO4(DI_1)
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;		// 0(GPIO5), 	1(EPWM3B[O]), 	2(MFSRA[I/O]),	3(ECAP1[I/O])			; GPIO5(DI_2)
	GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;		// 0(GPIO6), 	1(EPWM4A[O]), 	2(EPWMSYNCI[I]),3(EPWMSYNCO[O])			; GPIO6(DI_3)
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;		// 0(GPIO7), 	1(EPWM4B[O]), 	2(MCLKRA[I/O]),	3(ECAP2[I/O])			; GPIO7(DI_4)
	GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;		// 0(GPIO8), 	1(EPWM5A[O]), 	2(CANTXB[O]), 	3(ADCSOCAO[O])
	GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;		// 0(GPIO9), 	1(EPWM5B[O]), 	2(SCITXDB[O]),	3(ECAP3[I/O])
	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;	// 0(GPIO10), 	1(EPWM6A[O]), 	2(CANRXB[I]), 	3(ADCSOCBO[O])
	GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;	// 0(GPIO11), 	1(EPWM6B[O]), 	2(SCIRXDB[I]),	3(ECAP4[I/O])
	GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 2;	// 0(GPIO12), 	1(TZ1[I]), 		2(CANTXB[O]), 	3(MDXB[O])				; CANTXB[O]
	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 2;	// 0(GPIO13), 	1(TZ2[I]), 		2(CANRXB[I]), 	3(MDRB[O])				; CANRXB[I]
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 2;	// 0(GPIO14), 	1(TZ3/XHOLD[I]),2(SCIRXDB[O]),	3(MCLKXB[I/O])			; SCIRXDB[O]
	GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 2;	// 0(GPIO15), 	1(TZ4/XHOLDA[I])2(SCIRXDB[I]),	3(MFSXB[I/O])			; SCIRXDB[I]

	// GPIOA-1 Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO4 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO5 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO6 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO7 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;

	// GPIOA-1 Sampling Frequency of GPIO	; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)	: 0(/1), 1(/2), 2(/4), ..., 255(/510)
	GpioCtrlRegs.GPACTRL.bit.QUALPRD0 = 0;	// GPIO 0 ~ 7
	GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0;	// GPIO 8 ~ 15

	// GPIOA-1 Qualification Mode			; ACQCLK = SAMPCLK/GPAQSELn				: 0(/1), 1(/2), 2(/5), 3(ASYNCH)
	GpioCtrlRegs.GPAQSEL1.bit.GPIO0 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO3 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO4 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO8 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO10 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 0;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;

	// GPIOA-1 Internal Pull-up				; 0(Enable), 1(Disable)
	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO12 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO13 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO14 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO15 = 1;

	// GPIOA-1 Initial Value of GPIOx Output; 0(Low), 1(High)
	GpioDataRegs.GPASET.bit.GPIO0 = 1;
	GpioDataRegs.GPASET.bit.GPIO1 = 1;
	GpioDataRegs.GPASET.bit.GPIO2 = 1;
	GpioDataRegs.GPASET.bit.GPIO3 = 1;
	GpioDataRegs.GPASET.bit.GPIO4 = 1;
	GpioDataRegs.GPASET.bit.GPIO5 = 1;
	GpioDataRegs.GPASET.bit.GPIO6 = 1;
	GpioDataRegs.GPASET.bit.GPIO7 = 1;
	GpioDataRegs.GPADAT.bit.GPIO8 = 0;
	GpioDataRegs.GPADAT.bit.GPIO9 = 0;
	GpioDataRegs.GPADAT.bit.GPIO10 = 0;
	GpioDataRegs.GPADAT.bit.GPIO11 = 0;
	GpioDataRegs.GPADAT.bit.GPIO12 = 0;
	GpioDataRegs.GPADAT.bit.GPIO13 = 0;
	GpioDataRegs.GPADAT.bit.GPIO14 = 0;
	GpioDataRegs.GPADAT.bit.GPIO15 = 0;

//-------------------------------------------------------------------------------------------------//
//-------------------------------------------- GPIOA-2 --------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// GPIOA-2 MUX
	GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;	// 0(GPIO16), 	1(SPISMOA[I/O]),2(CANTXB[O]),	3(TZ5[I])				; SPISMOA(Flash ROM)
	GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;	// 0(GPIO17), 	1(SPISOMIA[I/O])2(CANRXB[I]),	3(TZ6[I])				; SPISOMIA(Flash ROM)
	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1;	// 0(GPIO18), 	1(SPICLKA[I/O]),2(SCITXDB[O]), 	3(CANRXA[I])			; SPICLKA(Flash ROM)
	GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 1;	// 0(GPIO19), 	1(SPISTEA[I/O]),2(SCIRXDB[I]),	3(CANTXA[O])			; SPISTEA(Flash ROM)
	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0;	// 0(GPIO20), 	1(EQEP1A[I]),	2(MDXA[O]), 	3(CANTXB[O])			; GPIO20(XF1)
	GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0;	// 0(GPIO21), 	1(EQEP1B[I]),	2(MDRA[I]),		3(CANRXB[I])
	GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;	// 0(GPIO22), 	1(EQEP1S[I/O]),	2(MCLKXA[I/O]),	3(SCITXDB[O])
	GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0;	// 0(GPIO23), 	1(EQEP1I[I/O]),	2(MFSXA[I/O]),	3(SCIRXDB[I])
	GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;	// 0(GPIO24), 	1(ECAP1[I/O]),	2(EQEP2A[I]), 	3(MDXB[O])
	GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 0;	// 0(GPIO25), 	1(ECAP2[I/O]),	2(EQEP2B[I]),	3(MDRB[I])
	GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;	// 0(GPIO26), 	1(ECAP3[I/O]),	2(EQEP2I[I/O]), 3(MCLKXB[I/O])
	GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;	// 0(GPIO27), 	1(ECAP4[I/O]),	2(EQEP2S[I/O]),	3(MFSXB[I/O])
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 2;	// 0(GPIO28), 	1(SCIRXDA[I]),	2(XZCS6[O]), 	3(XZCS6[O])				; XZCS6[O]
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 2;	// 0(GPIO29), 	1(SCITXDA[O]),	2(XA19[O]), 	3(XA19[O])				; XA19[O]
	GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 2;	// 0(GPIO30), 	1(CANRXA[I]),	2(XA18[O]),		3(XA18[O])				; XA18[O]
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 2;	// 0(GPIO31), 	1(CANTXA[O]),	2(XA17[O]),		3(XA17[O])				; XA17[O]

	// GPIOA-2 Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO18 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO21 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO22 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO23 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO24 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO25 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO26 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO27 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO28 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO29 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;

	// GPIOA-2 Sampling Frequency of GPIO	; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)	: 0(/1), 1(/2), 2(/4), ..., 255(/510)
	GpioCtrlRegs.GPACTRL.bit.QUALPRD2 = 0;	// GPIO 16 ~ 23
	GpioCtrlRegs.GPACTRL.bit.QUALPRD3 = 0;	// GPIO 24 ~ 31

	// GPIOA-2 Qualification Mode			; ACQCLK = SAMPCLK/GPAQSELn				: 0(/1), 1(/2), 2(/5), 3(ASYNCH)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO22 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO30 = 0;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO31 = 0;

	// GPIOA-2 Internal Pull-up				; 0(Enable), 1(Disable)
	GpioCtrlRegs.GPAPUD.bit.GPIO16 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO17 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO18 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO19 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO20 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO21 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO22 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO23 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO24 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO25 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO26 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO27 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO30 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO31 = 1;

	// GPIOA-2 Initial Value of GPIOx Output; 0(Low), 1(High)
	GpioDataRegs.GPADAT.bit.GPIO16 = 0;
	GpioDataRegs.GPADAT.bit.GPIO17 = 0;
	GpioDataRegs.GPADAT.bit.GPIO18 = 0;
	GpioDataRegs.GPADAT.bit.GPIO19 = 0;
	GpioDataRegs.GPADAT.bit.GPIO20 = 0;
	GpioDataRegs.GPADAT.bit.GPIO21 = 0;
	GpioDataRegs.GPADAT.bit.GPIO22 = 0;
	GpioDataRegs.GPADAT.bit.GPIO23 = 0;
	GpioDataRegs.GPADAT.bit.GPIO24 = 0;
	GpioDataRegs.GPADAT.bit.GPIO25 = 0;
	GpioDataRegs.GPADAT.bit.GPIO26 = 0;
	GpioDataRegs.GPADAT.bit.GPIO27 = 0;
	GpioDataRegs.GPADAT.bit.GPIO28 = 0;
	GpioDataRegs.GPADAT.bit.GPIO29 = 0;
	GpioDataRegs.GPADAT.bit.GPIO30 = 0;
	GpioDataRegs.GPADAT.bit.GPIO31 = 0;

//-------------------------------------------------------------------------------------------------//
//-------------------------------------------- GPIOB-1 --------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// GPIOB-1 MUX
	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;	// 0(GPIO32), 	1(SDAA[I/OC]),	2(EPWMSYNCI[I]),3(ADCSOCA0[O])			; EPWMSYNCI[I]
	GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0;	// 0(GPIO33), 	1(SCLA[I/OC]),	2(EPWMSYNCO[O]),3(ADCSOCB0[O])			; EPWMSYNCO[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 3;	// 0(GPIO34), 	1(ECAP1[I/O]),	2(XREADY[I]), 	3(XREADY[I])			; XREADY[I]
	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 3;	// 0(GPIO35), 	1(SCITXDA[O]),	2(XR/W[O]),		3(XR/W[O])				; XR/W[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 3;	// 0(GPIO36), 	1(SCIRXDA[I]),	2(XZCS0[O]), 	3(XZCS0[O])				; XZCS0[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 3;	// 0(GPIO37), 	1(ECAP2[I/O]),	2(XZCS7[O]),	3(XZCS7[O])				; XZCS7[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 3;	// 0(GPIO38), 	1(Reserved),	2(/XWE0[O]),	3(/XWE0[O])				; /XWE0
	GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 3;	// 0(GPIO39), 	1(Reserved),	2(XA16[O]),		3(XA16[O])				; XA16[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 0;	// 0(GPIO40), 	1(Reserved),	2(XA0/XWE1[O]), 3(XA0/XWE1[O])
	GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 0;	// 0(GPIO41), 	1(Reserved),	2(XA1[O]),		3(XA1[O])
	GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 0;	// 0(GPIO42), 	1(Reserved),	2(XA2[O]), 		3(XA2[O])
	GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 0;	// 0(GPIO43), 	1(Reserved),	2(XA3[O]),		3(XA3[O])
	GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 2;	// 0(GPIO44), 	1(Reserved),	2(XA4[O]), 		3(XA4[O])				; XA4[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 2;	// 0(GPIO45), 	1(Reserved),	2(XA5[O]), 		3(XA5[O])				; XA5[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO46 = 2;	// 0(GPIO46), 	1(Reserved),	2(XA6[O]),		3(XA6[O])				; XA6[O]
	GpioCtrlRegs.GPBMUX1.bit.GPIO47 = 2;	// 0(GPIO47), 	1(Reserved),	2(XA7[O]),		3(XA7[O])				; XA7[O]

	// GPIOB-1 Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPBDIR.bit.GPIO32 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO35 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO36 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO37 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO38 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO39 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO40 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO41 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO42 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO43 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO44 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO45 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO46 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO47 = 1;

	// GPIOB-1 Sampling Frequency of GPIO	; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)	: 0(/1), 1(/2), 2(/4), ..., 255(/510)
	GpioCtrlRegs.GPBCTRL.bit.QUALPRD0 = 0;	// GPIO 32 ~ 39
	GpioCtrlRegs.GPBCTRL.bit.QUALPRD1 = 0;	// GPIO 40 ~ 47

	// GPIOB-1 Qualification Mode			; ACQCLK = SAMPCLK/GPAQSELn				: 0(/1), 1(/2), 2(/5), 3(ASYNCH)
	GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO34 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO35 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO36 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO37 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO38 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO39 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO40 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO41 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO42 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO43 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO44 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO45 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO46 = 0;
	GpioCtrlRegs.GPBQSEL1.bit.GPIO47 = 0;

	// GPIOB-1 Internal Pull-up				; 0(Enable), 1(Disable)
	GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO33 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO35 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO36 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO37 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO38 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO39 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO40 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO41 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO42 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO43 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO44 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO45 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO46 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO47 = 1;

	// GPIOB-1 Initial Value of GPIOx Output; 0(Low), 1(High)
	GpioDataRegs.GPBDAT.bit.GPIO32 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO33 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO34 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO35 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO36 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO37 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO38 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO39 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO40 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO41 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO42 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO43 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO44 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO45 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO46 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO47 = 0;

	//Configure GPIO32 as XINT3
	GpioIntRegs.GPIOXINT3SEL.bit.GPIOSEL = 0x0000;



//-------------------------------------------------------------------------------------------------//
//-------------------------------------------- GPIOB-2 --------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// GPIOB-2 MUX
	GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 0;	// 0(GPIO48), 	1(ECAP5[I/O]),	2(XD31[I/O]),	3(SPISIMOD[I/O])
	GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 0;	// 0(GPIO49), 	1(ECAP6[I/O]),	2(XD30[I/O]),	3(SPISOMID[I/O])
	GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 0;	// 0(GPIO50), 	1(EQEP1A[I]),	2(XD29[I/O]), 	3(SPICLKD[I/O])			; GPIO50
	GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 0;	// 0(GPIO51), 	1(EQEP1B[I]),	2(XD28[I/O]),	3(SPISTED[I/O])			; GPIO51
	GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;	// 0(GPIO52), 	1(EQEP1S[I/O]),	2(XD27[I/O]), 	3(Reserved)				; GPIO52
	GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 0;	// 0(GPIO53), 	1(EPQE1I[I/O]),	2(XD26[I/O]),	3(Reserved)				; GPIO53
	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0;	// 0(GPIO54), 	1(SPISIMOA[I/O])2(XD25[I/O]),	3(EQEP3A[I])			; GPIO54
	GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0;	// 0(GPIO55), 	1(SPISOMIA[I/O])2(XD24[I/O]),	3(EQEP3B[I])			; GPIO55
	GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;	// 0(GPIO56), 	1(SPICLKA[I/O]),2(XD23[I/O]),	3(EQEP3S[I/O])			; GPIO56
	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;	// 0(GPIO57), 	1(SPISTEA[I/O]),2(XD22[I/O]),	3(EQEP3I[I/O])			; GPIO57
	GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;	// 0(GPIO58), 	1(MCLKRA[I/O]),	2(XD21[I/O]), 	3(EPWM7A[O])			; GPIO58
	GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0;	// 0(GPIO59), 	1(MFSRA[I/O]),	2(XD20[I/O]),	3(EPWM7B[O])
	GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;	// 0(GPIO60), 	1(MCLKRB[I/O]),	2(XD19[I/O]), 	3(EPWM8A[O])
	GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 0;	// 0(GPIO61), 	1(MFSRB[I/O]),	2(XD18[I/O]), 	3(EPWM8B[O])
	GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1;	// 0(GPIO62), 	1(SCIRXDC[I]),	2(XD17[I/O]),	3(EPWM9A[O])			; SCIRXDC[I]
	GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1;	// 0(GPIO63), 	1(SCITXDC[O]),	2(XD16[I/O]),	3(EPWM9A[O])			; SCITXDC[O]

	// GPIOB-2 Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPBDIR.bit.GPIO48 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO50 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO51 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO52 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO53 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO54 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO55 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO56 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO58 = 1;      // Balance Algorithm Enable - 1
	GpioCtrlRegs.GPBDIR.bit.GPIO59 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO62 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO63 = 1;

	// GPIOB-2 Sampling Frequency of GPIO	; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)	: 0(/1), 1(/2), 2(/4), ..., 255(/510)
	GpioCtrlRegs.GPBCTRL.bit.QUALPRD2 = 0;	// GPIO 48 ~ 55
	GpioCtrlRegs.GPBCTRL.bit.QUALPRD3 = 0;	// GPIO 56 ~ 63

	// GPIOB-2 Qualification Mode			; ACQCLK = SAMPCLK/GPAQSELn				: 0(/1), 1(/2), 2(/5), 3(ASYNCH)
	GpioCtrlRegs.GPBQSEL2.bit.GPIO48 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO49 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO52 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO60 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO63 = 0;

	// GPIOB-2 Internal Pull-up				; 0(Enable), 1(Disable)
	GpioCtrlRegs.GPBPUD.bit.GPIO48 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO49 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO50 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO51 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO52 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO53 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO54 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO55 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO56 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO57 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO58 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO59 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO60 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO61 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 1;

	// GPIOB-2 Initial Value of GPIOx Output; 0(Low), 1(High)
	GpioDataRegs.GPBDAT.bit.GPIO48 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO49 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO50 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO51 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO52 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO53 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO54 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO55 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO56 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO57 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO58 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO59 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO60 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO61 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO62 = 0;
	GpioDataRegs.GPBDAT.bit.GPIO63 = 0;

//-------------------------------------------------------------------------------------------------//
//-------------------------------------------- GPIOC-1 --------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// GPIOC-1 MUX
	GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 3;	// 0(GPIO64),	1(GPIO64),		2(XD15[I/O]),	3(XD15[I/O])			; XD15
	GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 3;	// 0(GPIO65),	1(GPIO65),		2(XD14[I/O]),	3(XD14[I/O])			; XD14
	GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 3;	// 0(GPIO66),	1(GPIO66),		2(XD13[I/O]),	3(XD13[I/O])			; XD13
	GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 3;	// 0(GPIO67),	1(GPIO67),		2(XD12[I/O]),	3(XD12[I/O])			; XD12
	GpioCtrlRegs.GPCMUX1.bit.GPIO68 = 3;	// 0(GPIO68),	1(GPIO68),		2(XD11[I/O]),	3(XD11[I/O])			; XD11
	GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 3;	// 0(GPIO69),	1(GPIO69),		2(XD10[I/O]),	3(XD10[I/O])			; XD10
	GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 3;	// 0(GPIO70),	1(GPIO70),		2(XD9[I/O]),	3(XD9[I/O])				; XD9
	GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 3;	// 0(GPIO71),	1(GPIO71),		2(XD8[I/O]),	3(XD8[I/O])				; XD8
	GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 3;	// 0(GPIO72),	1(GPIO72),		2(XD7[I/O]),	3(XD7[I/O])				; XD7
	GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 3;	// 0(GPIO73),	1(GPIO73),		2(XD6[I/O]),	3(XD6[I/O])				; XD6
	GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 3;	// 0(GPIO74),	1(GPIO74),		2(XD5[I/O]),	3(XD5[I/O])				; XD5
	GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 3;	// 0(GPIO75),	1(GPIO75),		2(XD4[I/O]),	3(XD4[I/O])				; XD4
	GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 3;	// 0(GPIO76),	1(GPIO76),		2(XD3[I/O]),	3(XD3[I/O])				; XD3
	GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 3;	// 0(GPIO77),	1(GPIO77),		2(XD2[I/O]),	3(XD2[I/O])				; XD2
	GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 3;	// 0(GPIO78),	1(GPIO78),		2(XD1[I/O]),	3(XD1[I/O])				; XD1
	GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 3;	// 0(GPIO79),	1(GPIO79),		2(XD0[I/O]),	3(XD0[I/O])				; XD0

	// GPIOC-1 Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPCDIR.bit.GPIO64 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO65 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO66 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO67 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO68 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO69 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO70 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO71 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO72 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO73 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO74 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO75 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO76 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO77 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO78 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO79 = 1;

	// GPIOC-1 Internal Pull-up				; 0(Enable), 1(Disable)
	GpioCtrlRegs.GPCPUD.bit.GPIO64 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO65 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO66 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO67 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO68 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO69 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO70 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO71 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO72 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO73 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO74 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO75 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO76 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO77 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO78 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO79 = 1;

	// GPIOC-1 Initial Value of GPIOx Output; 0(Low), 1(High)
	GpioDataRegs.GPCDAT.bit.GPIO64 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO65 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO66 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO67 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO68 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO69 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO70 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO71 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO72 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO73 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO74 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO75 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO76 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO77 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO78 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO79 = 0;

//-------------------------------------------------------------------------------------------------//
//-------------------------------------------- GPIOC-2 --------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// GPIOC-2 MUX
	GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 3;	// 0(GPIO80),	1(GPIO80),		2(XA8[I/O]),	3(XA8[I/O])				; XA8
	GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 3;	// 0(GPIO81),	1(GPIO81),		2(XA9[I/O]),	3(XA9[I/O])				; XA9
	GpioCtrlRegs.GPCMUX2.bit.GPIO82 = 3;	// 0(GPIO82),	1(GPIO82),		2(XA10[I/O]),	3(XA10[I/O])			; XA10
	GpioCtrlRegs.GPCMUX2.bit.GPIO83 = 3;	// 0(GPIO83),	1(GPIO83),		2(XA11[I/O]),	3(XA11[I/O])			; XA11
	GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 0;	// 0(GPIO84),	1(GPIO84),		2(XA12[I/O]),	3(XA12[I/O])			; GPIO84(BOOT_SEL1)
	GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 0;	// 0(GPIO85),	1(GPIO85),		2(XA13[I/O]),	3(XA13[I/O])			; GPIO85(BOOT_SEL2)
	GpioCtrlRegs.GPCMUX2.bit.GPIO86 = 0;	// 0(GPIO86),	1(GPIO86),		2(XA14[I/O]),	3(XA14[I/O])			; GPIO86(BOOT_SEL3)
	GpioCtrlRegs.GPCMUX2.bit.GPIO87 = 0;	// 0(GPIO87),	1(GPIO87),		2(XA15[I/O]),	3(XA15[I/O])			; GPIO87(BOOT_SEL4)

	// GPIOC-2 Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPCDIR.bit.GPIO80 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO81 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO82 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO83 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO84 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO85 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO86 = 1;
	GpioCtrlRegs.GPCDIR.bit.GPIO87 = 1;

	// GPIOC-2 Internal Pull-up				; 0(Enable), 1(Disable)
	GpioCtrlRegs.GPCPUD.bit.GPIO80 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO81 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO82 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO83 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO84 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO85 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO86 = 1;
	GpioCtrlRegs.GPCPUD.bit.GPIO87 = 1;

	// GPIOC-2 Initial Value of GPIOx Output; 0(Low), 1(High)
	GpioDataRegs.GPCDAT.bit.GPIO80 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO81 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO82 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO83 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO84 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO85 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO86 = 0;
	GpioDataRegs.GPCDAT.bit.GPIO87 = 0;

	EDIS;
}
