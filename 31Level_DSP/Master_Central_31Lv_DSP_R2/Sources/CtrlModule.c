/*
 * CtrlModule.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_CtrlModule.h"

void Init_DSP_IRQCROSSBAR(void)
{
	return;
}

void Init_PAD(void)
{
	Uint32 ui_gpmc;

	CTRL_CORE_MMR_LOCK_5 = CTRL_CORE_MMR_LOCK_5_Unlocked;

	// GPMC
	ui_gpmc = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
			| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
			| CTRL_CORE_PAD_INPUTENABLE_RXModeEn
			| CTRL_CORE_PAD_PULLTYPESELECT_PullDown
			| CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
			| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
			| CTRL_CORE_PAD_MUXMODE_MuxMode(0);

	CTRL_CORE_PAD_GPMC_AD0 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD1 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD2 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD3 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD4 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD5 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD6 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD7 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD8 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD9 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD10 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD11 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD12 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD13 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD14 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_AD15 = ui_gpmc;

	CTRL_CORE_PAD_GPMC_A0 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A1 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A2 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A3 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A4 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A5 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A6 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A7 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A8 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A9 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A10 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A11 = ui_gpmc;
//	CTRL_CORE_PAD_GPMC_A12 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A13 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A14 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A15 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A16 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A17 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A18 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A19 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A20 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A21 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A22 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A23 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A24 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A25 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A26 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_A27 = ui_gpmc;

	ui_gpmc = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
			| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
			| CTRL_CORE_PAD_INPUTENABLE_RXModeDis
			| CTRL_CORE_PAD_PULLTYPESELECT_PullUp
			| CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
			| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
			| CTRL_CORE_PAD_MUXMODE_MuxMode(0);

	CTRL_CORE_PAD_GPMC_CS0 = ui_gpmc;
	CTRL_CORE_PAD_GPMC_CS3 = ui_gpmc;

	CTRL_CORE_PAD_GPMC_OEN_REN = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
							| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
							| CTRL_CORE_PAD_INPUTENABLE_RXModeEn
							| CTRL_CORE_PAD_PULLTYPESELECT_PullUp
							| CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
							| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
							| CTRL_CORE_PAD_MUXMODE_MuxMode(0);
	CTRL_CORE_PAD_GPMC_WEN = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
							| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
							| CTRL_CORE_PAD_INPUTENABLE_RXModeEn
							| CTRL_CORE_PAD_PULLTYPESELECT_PullUp
							| CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
							| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
							| CTRL_CORE_PAD_MUXMODE_MuxMode(0);
	CTRL_CORE_PAD_GPMC_WAIT0 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
							| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
							| CTRL_CORE_PAD_INPUTENABLE_RXModeEn
							| CTRL_CORE_PAD_PULLTYPESELECT_PullUp
							| CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
							| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
							| CTRL_CORE_PAD_MUXMODE_MuxMode(0);
    //GPIO 2_22
    CTRL_CORE_PAD_GPMC_CLK = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(0);
    //GPIO 2_23
    CTRL_CORE_PAD_GPMC_ADVN_ALE = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);
    //GPIO 2_26
    CTRL_CORE_PAD_GPMC_BEN0 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullDown
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);
    //GPIO 2_27
    CTRL_CORE_PAD_GPMC_BEN1 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullDown
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    //GPIO 2_2
    CTRL_CORE_PAD_GPMC_A12 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullDown
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);


	// VIN1A
	//// VIN1A : D0 - GPIO3_4
	CTRL_CORE_PAD_VIN1A_D0 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D1 - GPIO3_5
    CTRL_CORE_PAD_VIN1A_D1 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D2 - GPIO3_6
    CTRL_CORE_PAD_VIN1A_D2 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D3 - GPIO3_7
    CTRL_CORE_PAD_VIN1A_D3 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D4 - GPIO3_8
    CTRL_CORE_PAD_VIN1A_D4 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
	//// VIN1A : D6 - GPIO3_10
	CTRL_CORE_PAD_VIN1A_D6 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
							| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
							| CTRL_CORE_PAD_INPUTENABLE_RXModeDis
							| CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
							| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
							| CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D7 - GPIO3_11
    CTRL_CORE_PAD_VIN1A_D7 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);
    // VIN1A
    //// VIN1A : D8 - GPIO3_12
    CTRL_CORE_PAD_VIN1A_D8 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D9 - GPIO3_13
    CTRL_CORE_PAD_VIN1A_D9 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D10 - GPIO3_14
    CTRL_CORE_PAD_VIN1A_D10 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D11 - GPIO3_15
    CTRL_CORE_PAD_VIN1A_D11= CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D16 - GPIO3_20(DI 1)
    CTRL_CORE_PAD_VIN1A_D16= CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D18 - GPIO3_22(DI 2)
    CTRL_CORE_PAD_VIN1A_D18= CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D19 - GPIO3_23(DI 3)
    CTRL_CORE_PAD_VIN1A_D19= CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D20 - GPIO3_24(DI 5)
    CTRL_CORE_PAD_VIN1A_D20= CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN1A
    //// VIN1A : D21 - GPIO3_25(DI 6)
    CTRL_CORE_PAD_VIN1A_D21= CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // VIN2A
    //// VIN2A : VSYNC0 - GPIO4_0(STATUSLED0_RED)
    CTRL_CORE_PAD_VIN2A_VSYNC0 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

    // GPIO6
    //// GPIO6 : GPIO6_14(DI 4)
    CTRL_CORE_PAD_GPIO6_14 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeEn
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(0);

    // GPIO6
    //// GPIO6 : GPIO6_15(check signal)
    CTRL_CORE_PAD_GPIO6_15 = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(0);

    // GPIO7
    //// GPIO7 : GPIO7_7(check signal)
    CTRL_CORE_PAD_SPI1_SCLK = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

	// UART1
	//// UART1 : RXD - GPIO7_22
	CTRL_CORE_PAD_UART1_RXD = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
							| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
							| CTRL_CORE_PAD_INPUTENABLE_RXModeDis
							| CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
							| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
							| CTRL_CORE_PAD_MUXMODE_MuxMode(14);
	//// UART1 : TXD - GPIO7_23
	CTRL_CORE_PAD_UART1_TXD = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
							| CTRL_CORE_PAD_SLEWCONTROL_FastSlew
							| CTRL_CORE_PAD_INPUTENABLE_RXModeDis
							| CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
							| CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
							| CTRL_CORE_PAD_MUXMODE_MuxMode(14);
	// GPIO 7_16 : SPI Load signal
	CTRL_CORE_PAD_SPI2_D0 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(14);

	//SPI2
	CTRL_CORE_PAD_SPI2_SCLK = CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(0);
	CTRL_CORE_PAD_SPI2_D1 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDDis
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(0);
	CTRL_CORE_PAD_SPI2_CS0 =  CTRL_CORE_PAD_WAKEUPENABLE_WKUPDis
                            | CTRL_CORE_PAD_SLEWCONTROL_FastSlew
                            | CTRL_CORE_PAD_INPUTENABLE_RXModeDis
                            | CTRL_CORE_PAD_PULLTYPESELECT_PullUp
                            | CTRL_CORE_PAD_PULLUDENABLE_PullUDEn
                            | CTRL_CORE_PAD_MODESELECT_DefaultIOTiming
                            | CTRL_CORE_PAD_MUXMODE_MuxMode(0);

//	CTRL_CORE_MMR_LOCK_5 = CTRL_CORE_MMR_LOCK_5_Locked;

	return;
}
