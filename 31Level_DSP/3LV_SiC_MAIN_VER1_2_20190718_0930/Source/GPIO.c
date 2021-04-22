/*
 * GPIO.c
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_GPIO.h"

void Init_GPIO(void)
{
	Uint32 uil_CPU1GPxSet, uil_CPU1GPxClear;
	Uint32 uil_CPU2GPxSet, uil_CPU2GPxClear;

	EALLOW;

	// Initializing GPIO A
#ifdef CPU1
	//// Initializing GPIO A : Pin Function
	////// Initializing GPIO A : Pin Function - Group MUX
	GpioCtrlRegs.GPAGMUX1.all = GPAGMUX1_GPIO000_InOutGPIO				// GPIO000	;
							| GPAGMUX1_GPIO001_InOutGPIO				// GPIO001	;
							| GPAGMUX1_GPIO002_InOutGPIO				// GPIO002	;
							| GPAGMUX1_GPIO003_InOutGPIO				// GPIO003	;
							| GPAGMUX1_GPIO004_InOutGPIO				// GPIO004	;
							| GPAGMUX1_GPIO005_InOutGPIO				// GPIO005	;
							| GPAGMUX1_GPIO006_InOutGPIO				// GPIO006	;
							| GPAGMUX1_GPIO007_InOutGPIO				// GPIO007	;
							| GPAGMUX1_GPIO008_InOutGPIO				// GPIO008	;
							| GPAGMUX1_GPIO009_InOutGPIO				// GPIO009	;
							| GPAGMUX1_GPIO010_InOutGPIO				// GPIO010	;
							| GPAGMUX1_GPIO011_InOutGPIO				// GPIO011	;
							| GPAGMUX1_GPIO012_InOutGPIO				// GPIO012	;
							| GPAGMUX1_GPIO013_InOutGPIO				// GPIO013	; GPIO		: DSP_SLAVE_IN1
							| GPAGMUX1_GPIO014_InOutGPIO				// GPIO014	; GPIO		: DSP_SLAVE_IN2
							| GPAGMUX1_GPIO015_InOutGPIO;				// GPIO015	;
	GpioCtrlRegs.GPAGMUX2.all = GPAGMUX2_GPIO016_InOutSPISIMOA			// GPIO016	; SPISIMOA	: ROM_SI
							| GPAGMUX2_GPIO017_InOutSPISOMIA			// GPIO017	; SPISOMIA	: ROM_SO
							| GPAGMUX2_GPIO018_InOutSPICLKA				// GPIO018	; SPICLKA	: ROM_SCK
							| GPAGMUX2_GPIO019_InOutnSPISTEA			// GPIO019	; /SPISTEA	: /ROM_CS
							| GPAGMUX2_GPIO020_InOutGPIO				// GPIO020	;
							| GPAGMUX2_GPIO021_InOutGPIO				// GPIO021	;
							| GPAGMUX2_GPIO022_InOutGPIO				// GPIO022	;
							| GPAGMUX2_GPIO023_InOutGPIO				// GPIO023	;
							| GPAGMUX2_GPIO024_InOutGPIO				// GPIO024	;
							| GPAGMUX2_GPIO025_InOutGPIO				// GPIO025	;
							| GPAGMUX2_GPIO026_InOutGPIO				// GPIO026	;
							| GPAGMUX2_GPIO027_InOutGPIO				// GPIO027	;
							| GPAGMUX2_GPIO028_OutnEM1CS4				// GPIO028	; /EM1CS4	: /EM1CS4
							| GPAGMUX2_GPIO029_InOutGPIO				// GPIO029	;
							| GPAGMUX2_GPIO030_OutEM1CLK				// GPIO030	; EM1CLK	: EM1CLK
							| GPAGMUX2_GPIO031_OutnEM1WE;				// GPIO031	; /EM1WE	: /EM1WE

	////// Initializing GPIO A : Pin Function - MUX
	GpioCtrlRegs.GPAMUX1.all = GPAMUX1_GPIO000_InOutGPIO				// GPIO000	;
							| GPAMUX1_GPIO001_InOutGPIO					// GPIO001	;
							| GPAMUX1_GPIO002_InOutGPIO					// GPIO002	;
							| GPAMUX1_GPIO003_InOutGPIO					// GPIO003	;
							| GPAMUX1_GPIO004_InOutGPIO					// GPIO004	;
							| GPAMUX1_GPIO005_InOutGPIO					// GPIO005	;
							| GPAMUX1_GPIO006_InOutGPIO					// GPIO006	;
							| GPAMUX1_GPIO007_InOutGPIO					// GPIO007	;
							| GPAMUX1_GPIO008_InOutGPIO					// GPIO008	;
							| GPAMUX1_GPIO009_InOutGPIO					// GPIO009	;
							| GPAMUX1_GPIO010_InOutGPIO					// GPIO010	;
							| GPAMUX1_GPIO011_InOutGPIO					// GPIO011	;
							| GPAMUX1_GPIO012_InOutGPIO					// GPIO012	;
							| GPAMUX1_GPIO013_InOutGPIO					// GPIO013	; GPIO		: DSP_SLAVE_IN1
							| GPAMUX1_GPIO014_InOutGPIO					// GPIO014	; GPIO		: DSP_SLAVE_IN2
							| GPAMUX1_GPIO015_InOutGPIO;				// GPIO015	;
	GpioCtrlRegs.GPAMUX2.all = GPAMUX2_GPIO016_InOutSPISIMOA			// GPIO016	; SPISIMOA	: ROM_SI
							| GPAMUX2_GPIO017_InOutSPISOMIA				// GPIO017	; SPISOMIA	: ROM_SO
							| GPAMUX2_GPIO018_InOutSPICLKA				// GPIO018	; SPICLKA	: ROM_SCK
							| GPAMUX2_GPIO019_InOutnSPISTEA				// GPIO019	; /SPISTEA	: /ROM_CS
							| GPAMUX2_GPIO020_InOutGPIO					// GPIO020	;
							| GPAMUX2_GPIO021_InOutGPIO					// GPIO021	;
							| GPAMUX2_GPIO022_InOutGPIO					// GPIO022	;
							| GPAMUX2_GPIO023_InOutGPIO					// GPIO023	;
							| GPAMUX2_GPIO024_InOutGPIO					// GPIO024	;
							| GPAMUX2_GPIO025_InOutGPIO					// GPIO025	;
							| GPAMUX2_GPIO026_InOutGPIO					// GPIO026	;
							| GPAMUX2_GPIO027_InOutGPIO					// GPIO027	;
							| GPAMUX2_GPIO028_OutnEM1CS4				// GPIO028	; /EM1CS4	: /EM1CS4
							| GPAMUX2_GPIO029_InOutGPIO					// GPIO029	;
							| GPAMUX2_GPIO030_OutEM1CLK					// GPIO030	; EM1CLK	: EM1CLK
							| GPAMUX2_GPIO031_OutnEM1WE;				// GPIO031	; /EM1WE	: /EM1WE

	//// Initializing GPIO A : Pin Direction
	GpioCtrlRegs.GPADIR.all = GPADIR_GPIO000_Input						// GPIO000	;
							| GPADIR_GPIO001_Input						// GPIO001	;
							| GPADIR_GPIO002_Input						// GPIO002	;
							| GPADIR_GPIO003_Input						// GPIO003	;
							| GPADIR_GPIO004_Input						// GPIO004	;
							| GPADIR_GPIO005_Input						// GPIO005	;
							| GPADIR_GPIO006_Input						// GPIO006	;
							| GPADIR_GPIO007_Input						// GPIO007	;
							| GPADIR_GPIO008_Input						// GPIO008	;
							| GPADIR_GPIO009_Input						// GPIO009	;
							| GPADIR_GPIO010_Input						// GPIO010	;
							| GPADIR_GPIO011_Input						// GPIO011	;
							| GPADIR_GPIO012_Input						// GPIO012	;
							| GPADIR_GPIO013_Input						// GPIO013	; GPIO		: DSP_SLAVE_IN1
							| GPADIR_GPIO014_Input						// GPIO014	; GPIO		: DSP_SLAVE_IN2
							| GPADIR_GPIO015_Input						// GPIO015	;
							| GPADIR_GPIO016_Output						// GPIO016	; SPISIMOA	: ROM_SI
							| GPADIR_GPIO017_Input						// GPIO017	; SPISOMIA	: ROM_SO
							| GPADIR_GPIO018_Output						// GPIO018	; SPICLKA	: ROM_SCK
							| GPADIR_GPIO019_Output						// GPIO019	; /SPISTEA	: /ROM_CS
							| GPADIR_GPIO020_Input						// GPIO020	;
							| GPADIR_GPIO021_Input						// GPIO021	;
							| GPADIR_GPIO022_Input						// GPIO022	;
							| GPADIR_GPIO023_Input						// GPIO023	;
							| GPADIR_GPIO024_Input						// GPIO024	;
							| GPADIR_GPIO025_Input						// GPIO025	;
							| GPADIR_GPIO026_Input						// GPIO026	;
							| GPADIR_GPIO027_Input						// GPIO027	;
							| GPADIR_GPIO028_Output						// GPIO028	; /EM1CS4	: nEM1CS4
							| GPADIR_GPIO029_Input						// GPIO029	;
							| GPADIR_GPIO030_Output						// GPIO030	; EM1CLK	: EM1CLK
							| GPADIR_GPIO031_Output;					// GPIO031	; /EM1WE	: EM1WE_/XWE0

	//// Initializing GPIO A : Pull Up
	GpioCtrlRegs.GPAPUD.all = GPAPUD_GPIO000_PullUpDisable				// GPIO000	;
							| GPAPUD_GPIO001_PullUpDisable				// GPIO001	;
							| GPAPUD_GPIO002_PullUpDisable				// GPIO002	;
							| GPAPUD_GPIO003_PullUpDisable				// GPIO003	;
							| GPAPUD_GPIO004_PullUpDisable				// GPIO004	;
							| GPAPUD_GPIO005_PullUpDisable				// GPIO005	;
							| GPAPUD_GPIO006_PullUpDisable				// GPIO006	;
							| GPAPUD_GPIO007_PullUpDisable				// GPIO007	;
							| GPAPUD_GPIO008_PullUpDisable				// GPIO008	;
							| GPAPUD_GPIO009_PullUpDisable				// GPIO009	;
							| GPAPUD_GPIO010_PullUpDisable				// GPIO010	;
							| GPAPUD_GPIO011_PullUpDisable				// GPIO011	;
							| GPAPUD_GPIO012_PullUpDisable				// GPIO012	;
							| GPAPUD_GPIO013_PullUpDisable				// GPIO013	; GPIO		: DSP_SLAVE_IN1
							| GPAPUD_GPIO014_PullUpDisable				// GPIO014	; GPIO		: DSP_SLAVE_IN2
							| GPAPUD_GPIO015_PullUpDisable				// GPIO015	;
							| GPAPUD_GPIO016_PullUpDisable				// GPIO016	; SPISIMOA	: ROM_SI
							| GPAPUD_GPIO017_PullUpDisable				// GPIO017	; SPISOMIA	: ROM_SO
							| GPAPUD_GPIO018_PullUpDisable				// GPIO018	; SPICLKA	: ROM_SCK
							| GPAPUD_GPIO019_PullUpDisable				// GPIO019	; /SPISTEA	: /ROM_CS
							| GPAPUD_GPIO020_PullUpDisable				// GPIO020	;
							| GPAPUD_GPIO021_PullUpDisable				// GPIO021	;
							| GPAPUD_GPIO022_PullUpDisable				// GPIO022	;
							| GPAPUD_GPIO023_PullUpDisable				// GPIO023	;
							| GPAPUD_GPIO024_PullUpDisable				// GPIO024	;
							| GPAPUD_GPIO025_PullUpDisable				// GPIO025	;
							| GPAPUD_GPIO026_PullUpDisable				// GPIO026	;
							| GPAPUD_GPIO027_PullUpDisable				// GPIO027	;
							| GPAPUD_GPIO028_PullUpDisable				// GPIO028	; /EM1CS4	: /EM1CS4
							| GPAPUD_GPIO029_PullUpDisable				// GPIO029	;
							| GPAPUD_GPIO030_PullUpDisable				// GPIO030	; EM1CLK	: EM1CLK
							| GPAPUD_GPIO031_PullUpDisable;				// GPIO031	; /EM1WE	: /EM1WE

	//// Initializing GPIO A : Open Drain
	GpioCtrlRegs.GPAODR.all = GPAODR_GPIO000_Normal						// GPIO000	;
							| GPAODR_GPIO001_Normal						// GPIO001	;
							| GPAODR_GPIO002_Normal						// GPIO002	;
							| GPAODR_GPIO003_Normal						// GPIO003	;
							| GPAODR_GPIO004_Normal						// GPIO004	;
							| GPAODR_GPIO005_Normal						// GPIO005	;
							| GPAODR_GPIO006_Normal						// GPIO006	;
							| GPAODR_GPIO007_Normal						// GPIO007	;
							| GPAODR_GPIO008_Normal						// GPIO008	;
							| GPAODR_GPIO009_Normal						// GPIO009	;
							| GPAODR_GPIO010_Normal						// GPIO010	;
							| GPAODR_GPIO011_Normal						// GPIO011	;
							| GPAODR_GPIO012_Normal						// GPIO012	;
							| GPAODR_GPIO013_Normal						// GPIO013	; GPIO		: DSP_SLAVE_IN1
							| GPAODR_GPIO014_Normal						// GPIO014	; GPIO		: DSP_SLAVE_IN2
							| GPAODR_GPIO015_Normal						// GPIO015	;
							| GPAODR_GPIO016_Normal						// GPIO016	; SPISIMOA	: ROM_SI
							| GPAODR_GPIO017_Normal						// GPIO017	; SPISOMIA	: ROM_SO
							| GPAODR_GPIO018_Normal						// GPIO018	; SPICLKA	: ROM_SCK
							| GPAODR_GPIO019_Normal						// GPIO019	; /SPISTEA	: /ROM_CS
							| GPAODR_GPIO020_Normal						// GPIO020	;
							| GPAODR_GPIO021_Normal						// GPIO021	;
							| GPAODR_GPIO022_Normal						// GPIO022	;
							| GPAODR_GPIO023_Normal						// GPIO023	;
							| GPAODR_GPIO024_Normal						// GPIO024	;
							| GPAODR_GPIO025_Normal						// GPIO025	;
							| GPAODR_GPIO026_Normal						// GPIO026	;
							| GPAODR_GPIO027_Normal						// GPIO027	;
							| GPAODR_GPIO028_Normal						// GPIO028	; /EM1CS4	: /EM1CS4
							| GPAODR_GPIO029_Normal						// GPIO029	;
							| GPAODR_GPIO030_Normal						// GPIO030	; EM1CLK	: EM1CLK
							| GPAODR_GPIO031_Normal;					// GPIO031	; /EM1WE	: /EM1WE

	//// Initializing GPIO A : Input Sampling Freq.
	GpioCtrlRegs.GPACTRL.all = GPACTRL_QUALPRD0_GPIO007to000_Value(0)	// QUALPRD0	; QUALPRDCLKx = PLLSYSCLK / (2 x QUALPRDx)
							| GPACTRL_QUALPRD1_GPIO015to008_Value(0)	// QUALPRD1	; 0(/1), 1(/2), 2(/4), 3(/6)
							| GPACTRL_QUALPRD2_GPIO023to016_Value(0)	// QUALPRD2	; ...
							| GPACTRL_QUALPRD3_GPIO031to024_Value(0);	// QUALPRD3	; 253(/506), 254(/508), 255(/510)

	//// Initializing GPIO A : Input Sampling Mode
	GpioCtrlRegs.GPAQSEL1.all = GPAQSEL1_GPIO000_Asynch					// GPIO000	;
							| GPAQSEL1_GPIO001_Asynch					// GPIO001	;
							| GPAQSEL1_GPIO002_Asynch					// GPIO002	;
							| GPAQSEL1_GPIO003_Asynch					// GPIO003	;
							| GPAQSEL1_GPIO004_Asynch					// GPIO004	;
							| GPAQSEL1_GPIO005_Asynch					// GPIO005	;
							| GPAQSEL1_GPIO006_Asynch					// GPIO006	;
							| GPAQSEL1_GPIO007_Asynch					// GPIO007	;
							| GPAQSEL1_GPIO008_Asynch					// GPIO008	;
							| GPAQSEL1_GPIO009_Asynch					// GPIO009	;
							| GPAQSEL1_GPIO010_Asynch					// GPIO010	;
							| GPAQSEL1_GPIO011_Asynch					// GPIO011	;
							| GPAQSEL1_GPIO012_Asynch					// GPIO012	;
							| GPAQSEL1_GPIO013_Asynch					// GPIO013	; GPIO		: DSP_SLAVE_IN1
							| GPAQSEL1_GPIO014_Asynch					// GPIO014	; GPIO		: DSP_SLAVE_IN2
							| GPAQSEL1_GPIO015_Asynch;					// GPIO015	;
	GpioCtrlRegs.GPAQSEL1.all =	GPAQSEL2_GPIO016_Asynch					// GPIO016	; SPISIMOA	: ROM_SI
							| GPAQSEL2_GPIO017_Asynch					// GPIO017	; SPISOMIA	: ROM_SO
							| GPAQSEL2_GPIO018_Asynch					// GPIO018	; SPICLKA	: ROM_SCK
							| GPAQSEL2_GPIO019_Asynch					// GPIO019	; /SPISTEA	: /ROM_CS
							| GPAQSEL2_GPIO020_Asynch					// GPIO020	;
							| GPAQSEL2_GPIO021_Asynch					// GPIO021	;
							| GPAQSEL2_GPIO022_Asynch					// GPIO022	;
							| GPAQSEL2_GPIO023_Asynch					// GPIO023	;
							| GPAQSEL2_GPIO024_Asynch					// GPIO024	;
							| GPAQSEL2_GPIO025_Asynch					// GPIO025	;
							| GPAQSEL2_GPIO026_Asynch					// GPIO026	;
							| GPAQSEL2_GPIO027_Asynch					// GPIO027	;
							| GPAQSEL2_GPIO028_Asynch					// GPIO028	; /EM1CS4	: /EM1CS4
							| GPAQSEL2_GPIO029_Asynch					// GPIO029	;
							| GPAQSEL2_GPIO030_Asynch					// GPIO030	; EM1CLK	: EM1CLK
							| GPAQSEL2_GPIO031_Asynch;					// GPIO031	; /EM1WE	: /EM1WE

	//// Initializing GPIO A : Input Polarity
	GpioCtrlRegs.GPAINV.all = GPAINV_GPIO000_InNormal					// GPIO000	;
							| GPAINV_GPIO001_InNormal					// GPIO001	;
							| GPAINV_GPIO002_InNormal					// GPIO002	;
							| GPAINV_GPIO003_InNormal					// GPIO003	;
							| GPAINV_GPIO004_InNormal					// GPIO004	;
							| GPAINV_GPIO005_InNormal					// GPIO005	;
							| GPAINV_GPIO006_InNormal					// GPIO006	;
							| GPAINV_GPIO007_InNormal					// GPIO007	;
							| GPAINV_GPIO008_InNormal					// GPIO008	;
							| GPAINV_GPIO009_InNormal					// GPIO009	;
							| GPAINV_GPIO010_InNormal					// GPIO010	;
							| GPAINV_GPIO011_InNormal					// GPIO011	;
							| GPAINV_GPIO012_InNormal					// GPIO012	;
							| GPAINV_GPIO013_InNormal					// GPIO013	; GPIO		: DSP_SLAVE_IN1
							| GPAINV_GPIO014_InNormal					// GPIO014	; GPIO		: DSP_SLAVE_IN2
							| GPAINV_GPIO015_InNormal					// GPIO015	;
							| GPAINV_GPIO016_InNormal					// GPIO016	; SPISIMOA	: ROM_SI
							| GPAINV_GPIO017_InNormal					// GPIO017	; SPISOMIA	: ROM_SO
							| GPAINV_GPIO018_InNormal					// GPIO018	; SPICLKA	: ROM_SCK
							| GPAINV_GPIO019_InNormal					// GPIO019	; /SPISTEA	: /ROM_CS
							| GPAINV_GPIO020_InNormal					// GPIO020	;
							| GPAINV_GPIO021_InNormal					// GPIO021	;
							| GPAINV_GPIO022_InNormal					// GPIO022	;
							| GPAINV_GPIO023_InNormal					// GPIO023	;
							| GPAINV_GPIO024_InNormal					// GPIO024	;
							| GPAINV_GPIO025_InNormal					// GPIO025	;
							| GPAINV_GPIO026_InNormal					// GPIO026	;
							| GPAINV_GPIO027_InNormal					// GPIO027	;
							| GPAINV_GPIO028_InNormal					// GPIO028	; /EM1CS4	: /EM1CS4
							| GPAINV_GPIO029_InNormal					// GPIO029	;
							| GPAINV_GPIO030_InNormal					// GPIO030	; EM1CLK	: EM1CLK
							| GPAINV_GPIO031_InNormal;					// GPIO031	; /EM1WE	: /EM1WE

	//// Initializing GPIO A : Host Define
#if (CPU2_BOOT_ENABLE)
		GpioCtrlRegs.GPACSEL1.all = GPACSEL1_GPIO000_CPU1Host			// GPIO000	;
								| GPACSEL1_GPIO001_CPU1Host				// GPIO001	;
								| GPACSEL1_GPIO002_CPU1Host				// GPIO002	;
								| GPACSEL1_GPIO003_CPU1Host				// GPIO003	;
								| GPACSEL1_GPIO004_CPU1Host				// GPIO004	;
								| GPACSEL1_GPIO005_CPU1Host				// GPIO005	;
								| GPACSEL1_GPIO006_CPU1Host				// GPIO006	;
								| GPACSEL1_GPIO007_CPU1Host;			// GPIO007	;
		GpioCtrlRegs.GPACSEL2.all = GPACSEL2_GPIO008_CPU1Host			// GPIO008	;
								| GPACSEL2_GPIO009_CPU1Host				// GPIO009	;
								| GPACSEL2_GPIO010_CPU1Host				// GPIO010	;
								| GPACSEL2_GPIO011_CPU1Host				// GPIO011	;
								| GPACSEL2_GPIO012_CPU1Host				// GPIO012	;
								| GPACSEL2_GPIO013_CPU1Host				// GPIO013	; GPIO		: DSP_SLAVE_IN1
								| GPACSEL2_GPIO014_CPU1Host				// GPIO014	; GPIO		: DSP_SLAVE_IN2
								| GPACSEL2_GPIO015_CPU1Host;			// GPIO015	;
		GpioCtrlRegs.GPACSEL3.all = GPACSEL3_GPIO016_CPU1Host			// GPIO016	; SPISIMOA	: ROM_SI
								| GPACSEL3_GPIO017_CPU1Host				// GPIO017	; SPISOMIA	: ROM_SO
								| GPACSEL3_GPIO018_CPU1Host				// GPIO018	; SPICLKA	: ROM_SCK
								| GPACSEL3_GPIO019_CPU1Host				// GPIO019	; /SPISTEA	: /ROM_CS
								| GPACSEL3_GPIO020_CPU1Host				// GPIO020	;
								| GPACSEL3_GPIO021_CPU1Host				// GPIO021	;
								| GPACSEL3_GPIO022_CPU1Host				// GPIO022	;
								| GPACSEL3_GPIO023_CPU1Host;			// GPIO023	;
		GpioCtrlRegs.GPACSEL4.all = GPACSEL4_GPIO024_CPU1Host			// GPIO024	;
								| GPACSEL4_GPIO025_CPU1Host				// GPIO025	;
								| GPACSEL4_GPIO026_CPU1Host				// GPIO026	;
								| GPACSEL4_GPIO027_CPU1Host				// GPIO027	;
								| GPACSEL4_GPIO028_CPU1Host				// GPIO028	; /EM1CS4	: /EM1CS4
								| GPACSEL4_GPIO029_CPU1Host				// GPIO029	;
								| GPACSEL4_GPIO030_CPU1Host				// GPIO030	; EM1CLK	: EM1CLK
								| GPACSEL4_GPIO031_CPU1Host;			// GPIO031	; /EM1WE	: /EM1WE
	#else
		GpioCtrlRegs.GPACSEL1.all = GPACSEL1_GPIOAll_CPU1Host;
		GpioCtrlRegs.GPACSEL2.all = GPACSEL2_GPIOAll_CPU1Host;
		GpioCtrlRegs.GPACSEL3.all = GPACSEL3_GPIOAll_CPU1Host;
		GpioCtrlRegs.GPACSEL4.all = GPACSEL4_GPIOAll_CPU1Host;
	#endif
#endif

	//// Initializing GPIO A : Initial Value
	////// Initializing GPIO A : Initial Value - CPU1
	uil_CPU1GPxSet = 0UL;
	uil_CPU1GPxClear = 0UL;

	////// Initializing GPIO A : Initial Value - CPU2
	uil_CPU2GPxSet = 0UL;
	uil_CPU2GPxClear = 0UL;

#ifdef CPU1
	#if (!CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO A : Set Initial Value - CPU1 and CPU2
	GpioDataRegs.GPASET.all = uil_CPU1GPxSet
							| uil_CPU2GPxSet;
	GpioDataRegs.GPACLEAR.all = uil_CPU1GPxClear
								| uil_CPU2GPxClear;
	#elif (CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO A : Set Initial Value - CPU1
	GpioDataRegs.GPASET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPACLEAR.all = uil_CPU1GPxClear;
	#elif (CPU2_BOOT_ENABLE && CPU2_FLASH_BOOT)
	////// Initializing GPIO A : Set Initial Value - CPU1
	GpioDataRegs.GPASET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPACLEAR.all = uil_CPU1GPxClear;

	////// Initializing GPIO A : Set Initial Value - CPU2
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPASET.all)), uil_CPU2GPxSet);
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPACLEAR.all)), uil_CPU2GPxClear);
	#endif
#endif

#ifdef CPU2
	#if (!CPU2_FLASH_BOOT)
	////// Initializing GPIO A : Set Initial Value - CPU2
	GpioDataRegs.GPASET.all = uil_CPU2GPxSet;
	GpioDataRegs.GPACLEAR.all = uil_CPU2GPxClear;
	#endif
#endif

	// Initializing GPIO B
#ifdef CPU1
	//// Initializing GPIO B : Pin Function
	////// Initializing GPIO B : Pin Function - Group MUX
	GpioCtrlRegs.GPBGMUX1.all = GPBGMUX1_GPIO032_OutnEM1CS0				// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBGMUX1_GPIO033_OutEM1RNW				// GPIO033	; EM1RNW	: EM1RNW
							| GPBGMUX1_GPIO034_OutnEM1CS2				// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBGMUX1_GPIO035_OutnEM1CS3				// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBGMUX1_GPIO036_InEM1WAIT				// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBGMUX1_GPIO037_OutnEM1OE				// GPIO037	; /EM1OE	: /EM1OE
							| GPBGMUX1_GPIO038_OutEM1A0					// GPIO038	; EM1A0		: EM1A0
							| GPBGMUX1_GPIO039_OutEM1A1					// GPIO039	; EM1A1		: EM1A1
							| GPBGMUX1_GPIO040_OutEM1A2					// GPIO040	; EM1A2		: EM1A2
							| GPBGMUX1_GPIO041_OutEM1A3					// GPIO041	; EM1A3		: EM1A3
							| GPBGMUX1_GPIO042_InOutGPIO				// GPIO042	;
							| GPBGMUX1_GPIO043_InOutGPIO				// GPIO043	;
							| GPBGMUX1_GPIO044_OutEM1A4					// GPIO044	; EM1A4		: EM1A4
							| GPBGMUX1_GPIO045_OutEM1A5					// GPIO045	; EM1A5		: EM1A5
							| GPBGMUX1_GPIO046_OutEM1A6					// GPIO046	; EM1A6		: EM1A6
							| GPBGMUX1_GPIO047_OutEM1A7;				// GPIO047	; EM1A7		: EM1A7
	GpioCtrlRegs.GPBGMUX2.all = GPBGMUX2_GPIO048_OutEM1A8				// GPIO048	; EM1A8		: EM1A8
							| GPBGMUX2_GPIO049_OutEM1A9					// GPIO049	; EM1A9		: EM1A9
							| GPBGMUX2_GPIO050_OutEM1A10				// GPIO050	; EM1A10	: EM1A10
							| GPBGMUX2_GPIO051_OutEM1A11				// GPIO051	; EM1A11	: EM1A11
							| GPBGMUX2_GPIO052_InOutGPIO				// GPIO052	;
							| GPBGMUX2_GPIO053_InOutEM2D15				// GPIO053	; EM2D15	: EM2D15
							| GPBGMUX2_GPIO054_InOutEM2D14				// GPIO054	; EM2D14	: EM2D14
							| GPBGMUX2_GPIO055_InOutEM2D13				// GPIO055	; EM2D13	: EM2D13
							| GPBGMUX2_GPIO056_InOutEM2D12				// GPIO056	; EM2D12	: EM2D12
							| GPBGMUX2_GPIO057_InOutEM2D11				// GPIO057	; EM2D11	: EM2D11
							| GPBGMUX2_GPIO058_InOutEM2D10				// GPIO058	; EM2D10	: EM2D10
							| GPBGMUX2_GPIO059_InOutEM2D9				// GPIO059	; EM2D9		: EM2D9
							| GPBGMUX2_GPIO060_InOutEM2D8				// GPIO060	; EM2D8		: EM2D8
							| GPBGMUX2_GPIO061_InOutEM2D7				// GPIO061	; EM2D7		: EM2D7
							| GPBGMUX2_GPIO062_InOutEM2D6				// GPIO062	; EM2D6		: EM2D6
							| GPBGMUX2_GPIO063_InOutEM2D5;				// GPIO063	; EM2D5		: EM2D5

	////// Initializing GPIO B : Pin Function - MUX
	GpioCtrlRegs.GPBMUX1.all = GPBMUX1_GPIO032_OutnEM1CS0				// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBMUX1_GPIO033_OutEM1RNW					// GPIO033	; EM1RNW	: EM1RNW
							| GPBMUX1_GPIO034_OutnEM1CS2				// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBMUX1_GPIO035_OutnEM1CS3				// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBMUX1_GPIO036_InEM1WAIT					// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBMUX1_GPIO037_OutnEM1OE					// GPIO037	; /EM1OE	: /EM1OE
							| GPBMUX1_GPIO038_OutEM1A0					// GPIO038	; EM1A0		: EM1A0
							| GPBMUX1_GPIO039_OutEM1A1					// GPIO039	; EM1A1		: EM1A1
							| GPBMUX1_GPIO040_OutEM1A2					// GPIO040	; EM1A2		: EM1A2
							| GPBMUX1_GPIO041_OutEM1A3					// GPIO041	; EM1A3		: EM1A3
							| GPBMUX1_GPIO042_InOutGPIO					// GPIO042	;
							| GPBMUX1_GPIO043_InOutGPIO					// GPIO043	;
							| GPBMUX1_GPIO044_OutEM1A4					// GPIO044	; EM1A4		: EM1A4
							| GPBMUX1_GPIO045_OutEM1A5					// GPIO045	; EM1A5		: EM1A5
							| GPBMUX1_GPIO046_OutEM1A6					// GPIO046	; EM1A6		: EM1A6
							| GPBMUX1_GPIO047_OutEM1A7;					// GPIO047	; EM1A7		: EM1A7
	GpioCtrlRegs.GPBMUX2.all = GPBMUX2_GPIO048_OutEM1A8					// GPIO048	; EM1A8		: EM1A8
							| GPBMUX2_GPIO049_OutEM1A9					// GPIO049	; EM1A9		: EM1A9
							| GPBMUX2_GPIO050_OutEM1A10					// GPIO050	; EM1A10	: EM1A10
							| GPBMUX2_GPIO051_OutEM1A11					// GPIO051	; EM1A11	: EM1A11
							| GPBMUX2_GPIO052_InOutGPIO					// GPIO052	;
							| GPBMUX2_GPIO053_InOutEM2D15				// GPIO053	; EM2D15	: EM2D15
							| GPBMUX2_GPIO054_InOutEM2D14				// GPIO054	; EM2D14	: EM2D14
							| GPBMUX2_GPIO055_InOutEM2D13				// GPIO055	; EM2D13	: EM2D13
							| GPBMUX2_GPIO056_InOutEM2D12				// GPIO056	; EM2D12	: EM2D12
							| GPBMUX2_GPIO057_InOutEM2D11				// GPIO057	; EM2D11	: EM2D11
							| GPBMUX2_GPIO058_InOutEM2D10				// GPIO058	; EM2D10	: EM2D10
							| GPBMUX2_GPIO059_InOutEM2D9				// GPIO059	; EM2D9		: EM2D9
							| GPBMUX2_GPIO060_InOutEM2D8				// GPIO060	; EM2D8		: EM2D8
							| GPBMUX2_GPIO061_InOutEM2D7				// GPIO061	; EM2D7		: EM2D7
							| GPBMUX2_GPIO062_InOutEM2D6				// GPIO062	; EM2D6		: EM2D6
							| GPBMUX2_GPIO063_InOutEM2D5;				// GPIO063	; EM2D5		: EM2D5

	////// Initializing GPIO B : Pin Function - Analog
	GpioCtrlRegs.GPBAMSEL.all = GPBAMSEL_GPIO042_GPBMUX					// GPIO042	;
							| GPBAMSEL_GPIO043_GPBMUX;					// GPIO043	;

	//// Initializing GPIO B : Pin Direction
	GpioCtrlRegs.GPBDIR.all = GPBDIR_GPIO032_Output						// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBDIR_GPIO033_Output						// GPIO033	; EM1RNW	: EM1RNW
							| GPBDIR_GPIO034_Output						// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBDIR_GPIO035_Output						// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBDIR_GPIO036_Input						// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBDIR_GPIO037_Output						// GPIO037	; /EM1OE	: /EM1OE
							| GPBDIR_GPIO038_Output						// GPIO038	; EM1A0		: EM1A0
							| GPBDIR_GPIO039_Output						// GPIO039	; EM1A1		: EM1A1
							| GPBDIR_GPIO040_Output						// GPIO040	; EM1A2		: EM1A2
							| GPBDIR_GPIO041_Output						// GPIO041	; EM1A3		: EM1A3
							| GPBDIR_GPIO042_Input						// GPIO042	;
							| GPBDIR_GPIO043_Input						// GPIO043	;
							| GPBDIR_GPIO044_Output						// GPIO044	; EM1A4		: EM1A4
							| GPBDIR_GPIO045_Output						// GPIO045	; EM1A5		: EM1A5
							| GPBDIR_GPIO046_Output						// GPIO046	; EM1A6		: EM1A6
							| GPBDIR_GPIO047_Output						// GPIO047	; EM1A7		: EM1A7
							| GPBDIR_GPIO048_Output						// GPIO048	; EM1A8		: EM1A8
							| GPBDIR_GPIO049_Output						// GPIO049	; EM1A9		: EM1A9
							| GPBDIR_GPIO050_Output						// GPIO050	; EM1A10	: EM1A10
							| GPBDIR_GPIO051_Output						// GPIO051	; EM1A11	: EM1A11
							| GPBDIR_GPIO052_Input						// GPIO052	;
							| GPBDIR_GPIO053_Input						// GPIO053	; EM2D15	: EM2D15
							| GPBDIR_GPIO054_Input						// GPIO054	; EM2D14	: EM2D14
							| GPBDIR_GPIO055_Input						// GPIO055	; EM2D13	: EM2D13
							| GPBDIR_GPIO056_Input						// GPIO056	; EM2D12	: EM2D12
							| GPBDIR_GPIO057_Input						// GPIO057	; EM2D11	: EM2D11
							| GPBDIR_GPIO058_Input						// GPIO058	; EM2D10	: EM2D10
							| GPBDIR_GPIO059_Input						// GPIO059	; EM2D9		: EM2D9
							| GPBDIR_GPIO060_Input						// GPIO060	; EM2D8		: EM2D8
							| GPBDIR_GPIO061_Input						// GPIO061	; EM2D7		: EM2D7
							| GPBDIR_GPIO062_Input						// GPIO062	; EM2D6		: EM2D6
							| GPBDIR_GPIO063_Input;						// GPIO063	; EM2D5		: EM2D5

	//// Initializing GPIO B : Pull Up
	GpioCtrlRegs.GPBPUD.all = GPBPUD_GPIO032_PullUpDisable				// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBPUD_GPIO033_PullUpDisable				// GPIO033	; EM1RNW	: EM1RNW
							| GPBPUD_GPIO034_PullUpDisable				// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBPUD_GPIO035_PullUpDisable				// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBPUD_GPIO036_PullUpDisable				// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBPUD_GPIO037_PullUpDisable				// GPIO037	; /EM1OE	: /EM1OE
							| GPBPUD_GPIO038_PullUpDisable				// GPIO038	; EM1A0		: EM1A0
							| GPBPUD_GPIO039_PullUpDisable				// GPIO039	; EM1A1		: EM1A1
							| GPBPUD_GPIO040_PullUpDisable				// GPIO040	; EM1A2		: EM1A2
							| GPBPUD_GPIO041_PullUpDisable				// GPIO041	; EM1A3		: EM1A3
							| GPBPUD_GPIO042_PullUpDisable				// GPIO042	;
							| GPBPUD_GPIO043_PullUpDisable				// GPIO043	;
							| GPBPUD_GPIO044_PullUpDisable				// GPIO044	; EM1A4		: EM1A4
							| GPBPUD_GPIO045_PullUpDisable				// GPIO045	; EM1A5		: EM1A5
							| GPBPUD_GPIO046_PullUpDisable				// GPIO046	; EM1A6		: EM1A6
							| GPBPUD_GPIO047_PullUpDisable				// GPIO047	; EM1A7		: EM1A7
							| GPBPUD_GPIO048_PullUpDisable				// GPIO048	; EM1A8		: EM1A8
							| GPBPUD_GPIO049_PullUpDisable				// GPIO049	; EM1A9		: EM1A9
							| GPBPUD_GPIO050_PullUpDisable				// GPIO050	; EM1A10	: EM1A10
							| GPBPUD_GPIO051_PullUpDisable				// GPIO051	; EM1A11	: EM1A11
							| GPBPUD_GPIO052_PullUpDisable				// GPIO052	;
							| GPBPUD_GPIO053_PullUpDisable				// GPIO053	; EM2D15	: EM2D15
							| GPBPUD_GPIO054_PullUpDisable				// GPIO054	; EM2D14	: EM2D14
							| GPBPUD_GPIO055_PullUpDisable				// GPIO055	; EM2D13	: EM2D13
							| GPBPUD_GPIO056_PullUpDisable				// GPIO056	; EM2D12	: EM2D12
							| GPBPUD_GPIO057_PullUpDisable				// GPIO057	; EM2D11	: EM2D11
							| GPBPUD_GPIO058_PullUpDisable				// GPIO058	; EM2D10	: EM2D10
							| GPBPUD_GPIO059_PullUpDisable				// GPIO059	; EM2D9		: EM2D9
							| GPBPUD_GPIO060_PullUpDisable				// GPIO060	; EM2D8		: EM2D8
							| GPBPUD_GPIO061_PullUpDisable				// GPIO061	; EM2D7		: EM2D7
							| GPBPUD_GPIO062_PullUpDisable				// GPIO062	; EM2D6		: EM2D6
							| GPBPUD_GPIO063_PullUpDisable;				// GPIO063	; EM2D5		: EM2D5

	//// Initializing GPIO B : Open Drain
	GpioCtrlRegs.GPBODR.all = GPBODR_GPIO032_Normal						// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBODR_GPIO033_Normal						// GPIO033	; EM1RNW	: EM1RNW
							| GPBODR_GPIO034_Normal						// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBODR_GPIO035_Normal						// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBODR_GPIO036_Normal						// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBODR_GPIO037_Normal						// GPIO037	; /EM1OE	: /EM1OE
							| GPBODR_GPIO038_Normal						// GPIO038	; EM1A0		: EM1A0
							| GPBODR_GPIO039_Normal						// GPIO039	; EM1A1		: EM1A1
							| GPBODR_GPIO040_Normal						// GPIO040	; EM1A2		: EM1A2
							| GPBODR_GPIO041_Normal						// GPIO041	; EM1A3		: EM1A3
							| GPBODR_GPIO042_Normal						// GPIO042	;
							| GPBODR_GPIO043_Normal						// GPIO043	;
							| GPBODR_GPIO044_Normal						// GPIO044	; EM1A4		: EM1A4
							| GPBODR_GPIO045_Normal						// GPIO045	; EM1A5		: EM1A5
							| GPBODR_GPIO046_Normal						// GPIO046	; EM1A6		: EM1A6
							| GPBODR_GPIO047_Normal						// GPIO047	; EM1A7		: EM1A7
							| GPBODR_GPIO048_Normal						// GPIO048	; EM1A8		: EM1A8
							| GPBODR_GPIO049_Normal						// GPIO049	; EM1A9		: EM1A9
							| GPBODR_GPIO050_Normal						// GPIO050	; EM1A10	: EM1A10
							| GPBODR_GPIO051_Normal						// GPIO051	; EM1A11	: EM1A11
							| GPBODR_GPIO052_Normal						// GPIO052	;
							| GPBODR_GPIO053_Normal						// GPIO053	; EM2D15	: EM2D15
							| GPBODR_GPIO054_Normal						// GPIO054	; EM2D14	: EM2D14
							| GPBODR_GPIO055_Normal						// GPIO055	; EM2D13	: EM2D13
							| GPBODR_GPIO056_Normal						// GPIO056	; EM2D12	: EM2D12
							| GPBODR_GPIO057_Normal						// GPIO057	; EM2D11	: EM2D11
							| GPBODR_GPIO058_Normal						// GPIO058	; EM2D10	: EM2D10
							| GPBODR_GPIO059_Normal						// GPIO059	; EM2D9		: EM2D9
							| GPBODR_GPIO060_Normal						// GPIO060	; EM2D8		: EM2D8
							| GPBODR_GPIO061_Normal						// GPIO061	; EM2D7		: EM2D7
							| GPBODR_GPIO062_Normal						// GPIO062	; EM2D6		: EM2D6
							| GPBODR_GPIO063_Normal;					// GPIO063	; EM2D5		: EM2D5

	//// Initializing GPIO B : Input Sampling Freq.
	GpioCtrlRegs.GPBCTRL.all = GPBCTRL_QUALPRD0_GPIO039to032_Value(0)	// QUALPRD0	; QUALPRDCLKx = PLLSYSCLK / (2 x QUALPRDx)
							| GPBCTRL_QUALPRD1_GPIO047to040_Value(0)	// QUALPRD1	; 0(/1), 1(/2), 2(/4), 3(/6)
							| GPBCTRL_QUALPRD2_GPIO055to048_Value(0)	// QUALPRD2	; ...
							| GPBCTRL_QUALPRD3_GPIO063to056_Value(0);	// QUALPRD3	; 253(/506), 254(/508), 255(/510)

	//// Initializing GPIO B : Input Sampling Mode
	GpioCtrlRegs.GPBQSEL1.all = GPBQSEL1_GPIO032_Asynch					// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBQSEL1_GPIO033_Asynch					// GPIO033	; EM1RNW	: EM1RNW
							| GPBQSEL1_GPIO034_Asynch					// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBQSEL1_GPIO035_Asynch					// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBQSEL1_GPIO036_Asynch					// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBQSEL1_GPIO037_Asynch					// GPIO037	; /EM1OE	: /EM1OE
							| GPBQSEL1_GPIO038_Asynch					// GPIO038	; EM1A0		: EM1A0
							| GPBQSEL1_GPIO039_Asynch					// GPIO039	; EM1A1		: EM1A1
							| GPBQSEL1_GPIO040_Asynch					// GPIO040	; EM1A2		: EM1A2
							| GPBQSEL1_GPIO041_Asynch					// GPIO041	; EM1A3		: EM1A3
							| GPBQSEL1_GPIO042_Asynch					// GPIO042	;
							| GPBQSEL1_GPIO043_Asynch					// GPIO043	;
							| GPBQSEL1_GPIO044_Asynch					// GPIO044	; EM1A4		: EM1A4
							| GPBQSEL1_GPIO045_Asynch					// GPIO045	; EM1A5		: EM1A5
							| GPBQSEL1_GPIO046_Asynch					// GPIO046	; EM1A6		: EM1A6
							| GPBQSEL1_GPIO047_Asynch;					// GPIO047	; EM1A7		: EM1A7
	GpioCtrlRegs.GPBQSEL1.all = GPBQSEL2_GPIO048_Asynch					// GPIO048	; EM1A8		: EM1A8
							| GPBQSEL2_GPIO049_Asynch					// GPIO049	; EM1A9		: EM1A9
							| GPBQSEL2_GPIO050_Asynch					// GPIO050	; EM1A10	: EM1A10
							| GPBQSEL2_GPIO051_Asynch					// GPIO051	; EM1A11	: EM1A11
							| GPBQSEL2_GPIO052_Asynch					// GPIO052	;
							| GPBQSEL2_GPIO053_Asynch					// GPIO053	; EM2D15	: EM2D15
							| GPBQSEL2_GPIO054_Asynch					// GPIO054	; EM2D14	: EM2D14
							| GPBQSEL2_GPIO055_Asynch					// GPIO055	; EM2D13	: EM2D13
							| GPBQSEL2_GPIO056_Asynch					// GPIO056	; EM2D12	: EM2D12
							| GPBQSEL2_GPIO057_Asynch					// GPIO057	; EM2D11	: EM2D11
							| GPBQSEL2_GPIO058_Asynch					// GPIO058	; EM2D10	: EM2D10
							| GPBQSEL2_GPIO059_Asynch					// GPIO059	; EM2D9		: EM2D9
							| GPBQSEL2_GPIO060_Asynch					// GPIO060	; EM2D8		: EM2D8
							| GPBQSEL2_GPIO061_Asynch					// GPIO061	; EM2D7		: EM2D7
							| GPBQSEL2_GPIO062_Asynch					// GPIO062	; EM2D6		: EM2D6
							| GPBQSEL2_GPIO063_Asynch;					// GPIO063	; EM2D5		: EM2D5

	//// Initializing GPIO B : Input Polarity
	GpioCtrlRegs.GPBINV.all = GPBINV_GPIO032_InNormal					// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBINV_GPIO033_InNormal					// GPIO033	; EM1RNW	: EM1RNW
							| GPBINV_GPIO034_InNormal					// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBINV_GPIO035_InNormal					// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBINV_GPIO036_InNormal					// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBINV_GPIO037_InNormal					// GPIO037	; /EM1OE	: /EM1OE
							| GPBINV_GPIO038_InNormal					// GPIO038	; EM1A0		: EM1A0
							| GPBINV_GPIO039_InNormal					// GPIO039	; EM1A1		: EM1A1
							| GPBINV_GPIO040_InNormal					// GPIO040	; EM1A2		: EM1A2
							| GPBINV_GPIO041_InNormal					// GPIO041	; EM1A3		: EM1A3
							| GPBINV_GPIO042_InNormal					// GPIO042	;
							| GPBINV_GPIO043_InNormal					// GPIO043	;
							| GPBINV_GPIO044_InNormal					// GPIO044	; EM1A4		: EM1A4
							| GPBINV_GPIO045_InNormal					// GPIO045	; EM1A5		: EM1A5
							| GPBINV_GPIO046_InNormal					// GPIO046	; EM1A6		: EM1A6
							| GPBINV_GPIO047_InNormal					// GPIO047	; EM1A7		: EM1A7
							| GPBINV_GPIO048_InNormal					// GPIO048	; EM1A8		: EM1A8
							| GPBINV_GPIO049_InNormal					// GPIO049	; EM1A9		: EM1A9
							| GPBINV_GPIO050_InNormal					// GPIO050	; EM1A10	: EM1A10
							| GPBINV_GPIO051_InNormal					// GPIO051	; EM1A11	: EM1A11
							| GPBINV_GPIO052_InNormal					// GPIO052	;
							| GPBINV_GPIO053_InNormal					// GPIO053	; EM2D15	: EM2D15
							| GPBINV_GPIO054_InNormal					// GPIO054	; EM2D14	: EM2D14
							| GPBINV_GPIO055_InNormal					// GPIO055	; EM2D13	: EM2D13
							| GPBINV_GPIO056_InNormal					// GPIO056	; EM2D12	: EM2D12
							| GPBINV_GPIO057_InNormal					// GPIO057	; EM2D11	: EM2D11
							| GPBINV_GPIO058_InNormal					// GPIO058	; EM2D10	: EM2D10
							| GPBINV_GPIO059_InNormal					// GPIO059	; EM2D9		: EM2D9
							| GPBINV_GPIO060_InNormal					// GPIO060	; EM2D8		: EM2D8
							| GPBINV_GPIO061_InNormal					// GPIO061	; EM2D7		: EM2D7
							| GPBINV_GPIO062_InNormal					// GPIO062	; EM2D6		: EM2D6
							| GPBINV_GPIO063_InNormal;					// GPIO063	; EM2D5		: EM2D5

	//// Initializing GPIO B : Host Define
	#if (CPU2_BOOT_ENABLE)
	GpioCtrlRegs.GPBCSEL1.all = GPBCSEL1_GPIO032_CPU1Host				// GPIO032	; /EM1CS0	: /EM1CS0
							| GPBCSEL1_GPIO033_CPU1Host					// GPIO033	; EM1RNW	: EM1RNW
							| GPBCSEL1_GPIO034_CPU1Host					// GPIO034	; /EM1CS2	: /EM1CS2
							| GPBCSEL1_GPIO035_CPU1Host					// GPIO035	; /EM1CS3	: /EM1CS3
							| GPBCSEL1_GPIO036_CPU1Host					// GPIO036	; EM1WAIT	: EM1WAIT
							| GPBCSEL1_GPIO037_CPU1Host					// GPIO037	; /EM1OE	: /EM1OE
							| GPBCSEL1_GPIO038_CPU1Host					// GPIO038	; EM1A0		: EM1A0
							| GPBCSEL1_GPIO039_CPU1Host;				// GPIO039	; EM1A1		: EM1A1
	GpioCtrlRegs.GPBCSEL2.all = GPBCSEL2_GPIO040_CPU1Host				// GPIO040	; EM1A2		: EM1A2
							| GPBCSEL2_GPIO041_CPU1Host					// GPIO041	; EM1A3		: EM1A3
							| GPBCSEL2_GPIO042_CPU1Host					// GPIO042	;
							| GPBCSEL2_GPIO043_CPU1Host					// GPIO043	;
							| GPBCSEL2_GPIO044_CPU1Host					// GPIO044	; EM1A4		: EM1A4
							| GPBCSEL2_GPIO045_CPU1Host					// GPIO045	; EM1A5		: EM1A5
							| GPBCSEL2_GPIO046_CPU1Host					// GPIO046	; EM1A6		: EM1A6
							| GPBCSEL2_GPIO047_CPU1Host;				// GPIO047	; EM1A7		: EM1A7
	GpioCtrlRegs.GPBCSEL3.all = GPBCSEL3_GPIO048_CPU1Host				// GPIO048	; EM1A8		: EM1A8
							| GPBCSEL3_GPIO049_CPU1Host					// GPIO049	; EM1A9		: EM1A9
							| GPBCSEL3_GPIO050_CPU1Host					// GPIO050	; EM1A10	: EM1A10
							| GPBCSEL3_GPIO051_CPU1Host					// GPIO051	; EM1A11	: EM1A11
							| GPBCSEL3_GPIO052_CPU1Host					// GPIO052	;
							| GPBCSEL3_GPIO053_CPU1Host					// GPIO053	; EM2D15	: EM2D15
							| GPBCSEL3_GPIO054_CPU1Host					// GPIO054	; EM2D14	: EM2D14
							| GPBCSEL3_GPIO055_CPU1Host;				// GPIO055	; EM2D13	: EM2D13
	GpioCtrlRegs.GPBCSEL4.all = GPBCSEL4_GPIO056_CPU1Host				// GPIO056	; EM2D12	: EM2D12
							| GPBCSEL4_GPIO057_CPU1Host					// GPIO057	; EM2D11	: EM2D11
							| GPBCSEL4_GPIO058_CPU1Host					// GPIO058	; EM2D10	: EM2D10
							| GPBCSEL4_GPIO059_CPU1Host					// GPIO059	; EM2D9		: EM2D9
							| GPBCSEL4_GPIO060_CPU1Host					// GPIO060	; EM2D8		: EM2D8
							| GPBCSEL4_GPIO061_CPU1Host					// GPIO061	; EM2D7		: EM2D7
							| GPBCSEL4_GPIO062_CPU1Host					// GPIO062	; EM2D6		: EM2D6
							| GPBCSEL4_GPIO063_CPU1Host;				// GPIO063	; EM2D5		: EM2D5
	#else
	GpioCtrlRegs.GPBCSEL1.all = GPBCSEL1_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPBCSEL2.all = GPBCSEL2_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPBCSEL3.all = GPBCSEL3_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPBCSEL4.all = GPBCSEL4_GPIOAll_CPU1Host;
	#endif
#endif

	//// Initializing GPIO B : Initial Value
	////// Initializing GPIO B : Initial Value - CPU1
	uil_CPU1GPxSet = 0L;
	uil_CPU1GPxClear = 0L;

	////// Initializing GPIO B : Initial Value - CPU2
	uil_CPU2GPxSet = 0L;
	uil_CPU2GPxClear = 0L;

#ifdef CPU1
	#if (!CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO B : Set Initial Value - CPU1 and CPU2
	GpioDataRegs.GPBSET.all = uil_CPU1GPxSet
							| uil_CPU2GPxSet;
	GpioDataRegs.GPBCLEAR.all = uil_CPU1GPxClear
								| uil_CPU2GPxClear;
	#elif (CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO B : Set Initial Value - CPU1
	GpioDataRegs.GPBSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPBCLEAR.all = uil_CPU1GPxClear;
	#elif (CPU2_BOOT_ENABLE && CPU2_FLASH_BOOT)
	////// Initializing GPIO B : Set Initial Value - CPU1
	GpioDataRegs.GPBSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPBCLEAR.all = uil_CPU1GPxClear;

	////// Initializing GPIO B : Set Initial Value - CPU2
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPBSET.all)), uil_CPU2GPxSet);
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPBCLEAR.all)), uil_CPU2GPxClear);
	#endif
#endif

#ifdef CPU2
	#if (!CPU2_FLASH_BOOT)
	////// Initializing GPIO B : Set Initial Value - CPU2
	GpioDataRegs.GPBSET.all = uil_CPU2GPxSet;
	GpioDataRegs.GPBCLEAR.all = uil_CPU2GPxClear;
	#endif
#endif

	// Initializing GPIO C
#ifdef CPU1
	//// Initializing GPIO C : Pin Function
	////// Initializing GPIO C : Pin Function - Group MUX
	GpioCtrlRegs.GPCGMUX1.all = GPCGMUX1_GPIO064_InOutEM2D4				// GPIO064	; EM2D4		: EM2D4
							| GPCGMUX1_GPIO065_InOutEM2D3				// GPIO065	; EM2D3		: EM2D3
							| GPCGMUX1_GPIO066_InOutEM2D2				// GPIO066	; EM2D2		: EM2D2
							| GPCGMUX1_GPIO067_InOutEM2D1				// GPIO067	; EM2D1		: EM2D1
							| GPCGMUX1_GPIO068_InOutEM2D0				// GPIO068	; EM2D0		: EM2D0
							| GPCGMUX1_GPIO069_InOutEM1D15				// GPIO069	; EM1D15	: EM1D15
							| GPCGMUX1_GPIO070_InOutEM1D14				// GPIO070	; EM1D14	: EM1D14
							| GPCGMUX1_GPIO071_InOutEM1D13				// GPIO071	; EM1D13	: EM1D13
							| GPCGMUX1_GPIO072_InOutEM1D12				// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCGMUX1_GPIO073_InOutEM1D11				// GPIO073	; EM1D11	: EM1D11
							| GPCGMUX1_GPIO074_InOutEM1D10				// GPIO074	; EM1D10	: EM1D10
							| GPCGMUX1_GPIO075_InOutEM1D9				// GPIO075	; EM1D9		: EM1D9
							| GPCGMUX1_GPIO076_InOutEM1D8				// GPIO076	; EM1D8		: EM1D8
							| GPCGMUX1_GPIO077_InOutEM1D7				// GPIO077	; EM1D7		: EM1D7
							| GPCGMUX1_GPIO078_InOutEM1D6				// GPIO078	; EM1D6		: EM1D6
							| GPCGMUX1_GPIO079_InOutEM1D5;				// GPIO079	; EM1D5		: EM1D5
	GpioCtrlRegs.GPCGMUX2.all = GPCGMUX2_GPIO080_InOutEM1D4				// GPIO080	; EM1D4		: EM1D4
							| GPCGMUX2_GPIO081_InOutEM1D3				// GPIO081	; EM1D3		: EM1D3
							| GPCGMUX2_GPIO082_InOutEM1D2				// GPIO082	; EM1D2		: EM1D2
							| GPCGMUX2_GPIO083_InOutEM1D1				// GPIO083	; EM1D1		: EM1D1
							| GPCGMUX2_GPIO084_InOutGPIO				// GPIO084	; GPIO		: BOOT_SEL2
							| GPCGMUX2_GPIO085_InOutEM1D0				// GPIO085	; EM1D0		: EM1D0
							| GPCGMUX2_GPIO086_InOutGPIO				// GPIO086	;
							| GPCGMUX2_GPIO087_InOutGPIO				// GPIO087	;
							| GPCGMUX2_GPIO088_OutEM1DQM0				// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCGMUX2_GPIO089_OutEM1DQM1				// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCGMUX2_GPIO090_InOutGPIO				// GPIO090	;
							| GPCGMUX2_GPIO091_InOutGPIO				// GPIO091	;
							| GPCGMUX2_GPIO092_OutEM1BA1				// GPIO092	; EM1BA1	: EM1BA1
							| GPCGMUX2_GPIO093_OutEM1BA0				// GPIO093	; EM1BA0	: EM1BA0
							| GPCGMUX2_GPIO094_InOutGPIO				// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCGMUX2_GPIO095_InOutGPIO;				// GPIO095	;

	////// Initializing GPIO C : Pin Function - MUX
	GpioCtrlRegs.GPCMUX1.all = GPCMUX1_GPIO064_InOutEM2D4				// GPIO064	; EM2D4		: EM2D4
							| GPCMUX1_GPIO065_InOutEM2D3				// GPIO065	; EM2D3		: EM2D3
							| GPCMUX1_GPIO066_InOutEM2D2				// GPIO066	; EM2D2		: EM2D2
							| GPCMUX1_GPIO067_InOutEM2D1				// GPIO067	; EM2D1		: EM2D1
							| GPCMUX1_GPIO068_InOutEM2D0				// GPIO068	; EM2D0		: EM2D0
							| GPCMUX1_GPIO069_InOutEM1D15				// GPIO069	; EM1D15	: EM1D15
							| GPCMUX1_GPIO070_InOutEM1D14				// GPIO070	; EM1D14	: EM1D14
							| GPCMUX1_GPIO071_InOutEM1D13				// GPIO071	; EM1D13	: EM1D13
							| GPCMUX1_GPIO072_InOutEM1D12				// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCMUX1_GPIO073_InOutEM1D11				// GPIO073	; EM1D11	: EM1D11
							| GPCMUX1_GPIO074_InOutEM1D10				// GPIO074	; EM1D10	: EM1D10
							| GPCMUX1_GPIO075_InOutEM1D9				// GPIO075	; EM1D9		: EM1D9
							| GPCMUX1_GPIO076_InOutEM1D8				// GPIO076	; EM1D8		: EM1D8
							| GPCMUX1_GPIO077_InOutEM1D7				// GPIO077	; EM1D7		: EM1D7
							| GPCMUX1_GPIO078_InOutEM1D6				// GPIO078	; EM1D6		: EM1D6
							| GPCMUX1_GPIO079_InOutEM1D5;				// GPIO079	; EM1D5		: EM1D5
	GpioCtrlRegs.GPCMUX2.all = GPCMUX2_GPIO080_InOutEM1D4				// GPIO080	; EM1D4		: EM1D4
							| GPCMUX2_GPIO081_InOutEM1D3				// GPIO081	; EM1D3		: EM1D3
							| GPCMUX2_GPIO082_InOutEM1D2				// GPIO082	; EM1D2		: EM1D2
							| GPCMUX2_GPIO083_InOutEM1D1				// GPIO083	; EM1D1		: EM1D1
							| GPCMUX2_GPIO084_InOutGPIO					// GPIO084	; GPIO		: BOOT_SEL2
							| GPCMUX2_GPIO085_InOutEM1D0				// GPIO085	; EM1D0		: EM1D0
							| GPCMUX2_GPIO086_InOutGPIO					// GPIO086	;
							| GPCMUX2_GPIO087_InOutGPIO					// GPIO087	;
							| GPCMUX2_GPIO088_OutEM1DQM0				// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCMUX2_GPIO089_OutEM1DQM1				// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCMUX2_GPIO090_InOutGPIO					// GPIO090	;
							| GPCMUX2_GPIO091_InOutGPIO					// GPIO091	;
							| GPCMUX2_GPIO092_OutEM1BA1					// GPIO092	; EM1BA1	: EM1BA1
							| GPCMUX2_GPIO093_OutEM1BA0					// GPIO093	; EM1BA0	: EM1BA0
							| GPCMUX2_GPIO094_InOutGPIO					// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCMUX2_GPIO095_InOutGPIO;				// GPIO095	;

	//// Initializing GPIO C : Pin Direction
	GpioCtrlRegs.GPCDIR.all = GPCDIR_GPIO064_Input						// GPIO064	; EM2D4		: EM2D4
							| GPCDIR_GPIO065_Input						// GPIO065	; EM2D3		: EM2D3
							| GPCDIR_GPIO066_Input						// GPIO066	; EM2D2		: EM2D2
							| GPCDIR_GPIO067_Input						// GPIO067	; EM2D1		: EM2D1
							| GPCDIR_GPIO068_Input						// GPIO068	; EM2D0		: EM2D0
							| GPCDIR_GPIO069_Input						// GPIO069	; EM1D15	: EM1D15
							| GPCDIR_GPIO070_Input						// GPIO070	; EM1D14	: EM1D14
							| GPCDIR_GPIO071_Input						// GPIO071	; EM1D13	: EM1D13
							| GPCDIR_GPIO072_Input						// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCDIR_GPIO073_Input						// GPIO073	; EM1D11	: EM1D11
							| GPCDIR_GPIO074_Input						// GPIO074	; EM1D10	: EM1D10
							| GPCDIR_GPIO075_Input						// GPIO075	; EM1D9		: EM1D9
							| GPCDIR_GPIO076_Input						// GPIO076	; EM1D8		: EM1D8
							| GPCDIR_GPIO077_Input						// GPIO077	; EM1D7		: EM1D7
							| GPCDIR_GPIO078_Input						// GPIO078	; EM1D6		: EM1D6
							| GPCDIR_GPIO079_Input						// GPIO079	; EM1D5		: EM1D5
							| GPCDIR_GPIO080_Input						// GPIO080	; EM1D4		: EM1D4
							| GPCDIR_GPIO081_Input						// GPIO081	; EM1D3		: EM1D3
							| GPCDIR_GPIO082_Input						// GPIO082	; EM1D2		: EM1D2
							| GPCDIR_GPIO083_Input						// GPIO083	; EM1D1		: EM1D1
							| GPCDIR_GPIO084_Input						// GPIO084	; GPIO		: BOOT_SEL2
							| GPCDIR_GPIO085_Input						// GPIO085	; EM1D0		: EM1D0
							| GPCDIR_GPIO086_Input						// GPIO086	;
							| GPCDIR_GPIO087_Input						// GPIO087	;
							| GPCDIR_GPIO088_Output						// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCDIR_GPIO089_Output						// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCDIR_GPIO090_Input						// GPIO090	;
							| GPCDIR_GPIO091_Input						// GPIO091	;
							| GPCDIR_GPIO092_Output						// GPIO092	; EM1BA1	: EM1BA1
							| GPCDIR_GPIO093_Output						// GPIO093	; EM1BA0	: EM1BA0
							| GPCDIR_GPIO094_Input						// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCDIR_GPIO095_Input;						// GPIO095	;

	//// Initializing GPIO C : Pull Up
	GpioCtrlRegs.GPCPUD.all = GPCPUD_GPIO064_PullUpDisable				// GPIO064	; EM2D4		: EM2D4
							| GPCPUD_GPIO065_PullUpDisable				// GPIO065	; EM2D3		: EM2D3
							| GPCPUD_GPIO066_PullUpDisable				// GPIO066	; EM2D2		: EM2D2
							| GPCPUD_GPIO067_PullUpDisable				// GPIO067	; EM2D1		: EM2D1
							| GPCPUD_GPIO068_PullUpDisable				// GPIO068	; EM2D0		: EM2D0
							| GPCPUD_GPIO069_PullUpDisable				// GPIO069	; EM1D15	: EM1D15
							| GPCPUD_GPIO070_PullUpDisable				// GPIO070	; EM1D14	: EM1D14
							| GPCPUD_GPIO071_PullUpDisable				// GPIO071	; EM1D13	: EM1D13
							| GPCPUD_GPIO072_PullUpDisable				// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCPUD_GPIO073_PullUpDisable				// GPIO073	; EM1D11	: EM1D11
							| GPCPUD_GPIO074_PullUpDisable				// GPIO074	; EM1D10	: EM1D10
							| GPCPUD_GPIO075_PullUpDisable				// GPIO075	; EM1D9		: EM1D9
							| GPCPUD_GPIO076_PullUpDisable				// GPIO076	; EM1D8		: EM1D8
							| GPCPUD_GPIO077_PullUpDisable				// GPIO077	; EM1D7		: EM1D7
							| GPCPUD_GPIO078_PullUpDisable				// GPIO078	; EM1D6		: EM1D6
							| GPCPUD_GPIO079_PullUpDisable				// GPIO079	; EM1D5		: EM1D5
							| GPCPUD_GPIO080_PullUpDisable				// GPIO080	; EM1D4		: EM1D4
							| GPCPUD_GPIO081_PullUpDisable				// GPIO081	; EM1D3		: EM1D3
							| GPCPUD_GPIO082_PullUpDisable				// GPIO082	; EM1D2		: EM1D2
							| GPCPUD_GPIO083_PullUpDisable				// GPIO083	; EM1D1		: EM1D1
							| GPCPUD_GPIO084_PullUpDisable				// GPIO084	; GPIO		: BOOT_SEL2
							| GPCPUD_GPIO085_PullUpDisable				// GPIO085	; EM1D0		: EM1D0
							| GPCPUD_GPIO086_PullUpDisable				// GPIO086	;
							| GPCPUD_GPIO087_PullUpDisable				// GPIO087	;
							| GPCPUD_GPIO088_PullUpDisable				// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCPUD_GPIO089_PullUpDisable				// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCPUD_GPIO090_PullUpDisable				// GPIO090	;
							| GPCPUD_GPIO091_PullUpDisable				// GPIO091	;
							| GPCPUD_GPIO092_PullUpDisable				// GPIO092	; EM1BA1	: EM1BA1
							| GPCPUD_GPIO093_PullUpDisable				// GPIO093	; EM1BA0	: EM1BA0
							| GPCPUD_GPIO094_PullUpDisable				// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCPUD_GPIO095_PullUpDisable;				// GPIO095	;

	//// Initializing GPIO C : Open Drain
	GpioCtrlRegs.GPCODR.all = GPCODR_GPIO064_Normal						// GPIO064	; EM2D4		: EM2D4
							| GPCODR_GPIO065_Normal						// GPIO065	; EM2D3		: EM2D3
							| GPCODR_GPIO066_Normal						// GPIO066	; EM2D2		: EM2D2
							| GPCODR_GPIO067_Normal						// GPIO067	; EM2D1		: EM2D1
							| GPCODR_GPIO068_Normal						// GPIO068	; EM2D0		: EM2D0
							| GPCODR_GPIO069_Normal						// GPIO069	; EM1D15	: EM1D15
							| GPCODR_GPIO070_Normal						// GPIO070	; EM1D14	: EM1D14
							| GPCODR_GPIO071_Normal						// GPIO071	; EM1D13	: EM1D13
							| GPCODR_GPIO072_Normal						// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCODR_GPIO073_Normal						// GPIO073	; EM1D11	: EM1D11
							| GPCODR_GPIO074_Normal						// GPIO074	; EM1D10	: EM1D10
							| GPCODR_GPIO075_Normal						// GPIO075	; EM1D9		: EM1D9
							| GPCODR_GPIO076_Normal						// GPIO076	; EM1D8		: EM1D8
							| GPCODR_GPIO077_Normal						// GPIO077	; EM1D7		: EM1D7
							| GPCODR_GPIO078_Normal						// GPIO078	; EM1D6		: EM1D6
							| GPCODR_GPIO079_Normal						// GPIO079	; EM1D5		: EM1D5
							| GPCODR_GPIO080_Normal						// GPIO080	; EM1D4		: EM1D4
							| GPCODR_GPIO081_Normal						// GPIO081	; EM1D3		: EM1D3
							| GPCODR_GPIO082_Normal						// GPIO082	; EM1D2		: EM1D2
							| GPCODR_GPIO083_Normal						// GPIO083	; EM1D1		: EM1D1
							| GPCODR_GPIO084_Normal						// GPIO084	; GPIO		: BOOT_SEL2
							| GPCODR_GPIO085_Normal						// GPIO085	; EM1D0		: EM1D0
							| GPCODR_GPIO086_Normal						// GPIO086	;
							| GPCODR_GPIO087_Normal						// GPIO087	;
							| GPCODR_GPIO088_Normal						// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCODR_GPIO089_Normal						// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCODR_GPIO090_Normal						// GPIO090	;
							| GPCODR_GPIO091_Normal						// GPIO091	;
							| GPCODR_GPIO092_Normal						// GPIO092	; EM1BA1	: EM1BA1
							| GPCODR_GPIO093_Normal						// GPIO093	; EM1BA0	: EM1BA0
							| GPCODR_GPIO094_Normal						// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCODR_GPIO095_Normal;					// GPIO095	;

	//// Initializing GPIO C : Input Sampling Freq.
	GpioCtrlRegs.GPCCTRL.all = GPCCTRL_QUALPRD0_GPIO071to064_Value(0)	// QUALPRD0	; QUALPRDCLKx = PLLSYSCLK / (2 x QUALPRDx)
							| GPCCTRL_QUALPRD1_GPIO079to072_Value(0)	// QUALPRD1	; 0(/1), 1(/2), 2(/4), 3(/6)
							| GPCCTRL_QUALPRD2_GPIO087to080_Value(0)	// QUALPRD2	; ...
							| GPCCTRL_QUALPRD3_GPIO095to088_Value(0);	// QUALPRD3	; 253(/506), 254(/508), 255(/510)

	//// Initializing GPIO C : Input Sampling Mode
	GpioCtrlRegs.GPCQSEL1.all = GPCQSEL1_GPIO064_Asynch					// GPIO064	; EM2D4		: EM2D4
							| GPCQSEL1_GPIO065_Asynch					// GPIO065	; EM2D3		: EM2D3
							| GPCQSEL1_GPIO066_Asynch					// GPIO066	; EM2D2		: EM2D2
							| GPCQSEL1_GPIO067_Asynch					// GPIO067	; EM2D1		: EM2D1
							| GPCQSEL1_GPIO068_Asynch					// GPIO068	; EM2D0		: EM2D0
							| GPCQSEL1_GPIO069_Asynch					// GPIO069	; EM1D15	: EM1D15
							| GPCQSEL1_GPIO070_Asynch					// GPIO070	; EM1D14	: EM1D14
							| GPCQSEL1_GPIO071_Asynch					// GPIO071	; EM1D13	: EM1D13
							| GPCQSEL1_GPIO072_Asynch					// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCQSEL1_GPIO073_Asynch					// GPIO073	; EM1D11	: EM1D11
							| GPCQSEL1_GPIO074_Asynch					// GPIO074	; EM1D10	: EM1D10
							| GPCQSEL1_GPIO075_Asynch					// GPIO075	; EM1D9		: EM1D9
							| GPCQSEL1_GPIO076_Asynch					// GPIO076	; EM1D8		: EM1D8
							| GPCQSEL1_GPIO077_Asynch					// GPIO077	; EM1D7		: EM1D7
							| GPCQSEL1_GPIO078_Asynch					// GPIO078	; EM1D6		: EM1D6
							| GPCQSEL1_GPIO079_Asynch;					// GPIO079	; EM1D5		: EM1D5
	GpioCtrlRegs.GPCQSEL2.all = GPCQSEL2_GPIO080_Asynch					// GPIO080	; EM1D4		: EM1D4
							| GPCQSEL2_GPIO081_Asynch					// GPIO081	; EM1D3		: EM1D3
							| GPCQSEL2_GPIO082_Asynch					// GPIO082	; EM1D2		: EM1D2
							| GPCQSEL2_GPIO083_Asynch					// GPIO083	; EM1D1		: EM1D1
							| GPCQSEL2_GPIO084_Asynch					// GPIO084	; GPIO		: BOOT_SEL2
							| GPCQSEL2_GPIO085_Asynch					// GPIO085	; EM1D0		: EM1D0
							| GPCQSEL2_GPIO086_Asynch					// GPIO086	;
							| GPCQSEL2_GPIO087_Asynch					// GPIO087	;
							| GPCQSEL2_GPIO088_Asynch					// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCQSEL2_GPIO089_Asynch					// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCQSEL2_GPIO090_Asynch					// GPIO090	;
							| GPCQSEL2_GPIO091_Asynch					// GPIO091	;
							| GPCQSEL2_GPIO092_Asynch					// GPIO092	; EM1BA1	: EM1BA1
							| GPCQSEL2_GPIO093_Asynch					// GPIO093	; EM1BA0	: EM1BA0
							| GPCQSEL2_GPIO094_Asynch					// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCQSEL2_GPIO095_Asynch;					// GPIO095	;

	//// Initializing GPIO C : Input Polarity
	GpioCtrlRegs.GPCINV.all = GPCINV_GPIO064_InNormal					// GPIO064	; EM2D4		: EM2D4
							| GPCINV_GPIO065_InNormal					// GPIO065	; EM2D3		: EM2D3
							| GPCINV_GPIO066_InNormal					// GPIO066	; EM2D2		: EM2D2
							| GPCINV_GPIO067_InNormal					// GPIO067	; EM2D1		: EM2D1
							| GPCINV_GPIO068_InNormal					// GPIO068	; EM2D0		: EM2D0
							| GPCINV_GPIO069_InNormal					// GPIO069	; EM1D15	: EM1D15
							| GPCINV_GPIO070_InNormal					// GPIO070	; EM1D14	: EM1D14
							| GPCINV_GPIO071_InNormal					// GPIO071	; EM1D13	: EM1D13
							| GPCINV_GPIO072_InNormal					// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCINV_GPIO073_InNormal					// GPIO073	; EM1D11	: EM1D11
							| GPCINV_GPIO074_InNormal					// GPIO074	; EM1D10	: EM1D10
							| GPCINV_GPIO075_InNormal					// GPIO075	; EM1D9		: EM1D9
							| GPCINV_GPIO076_InNormal					// GPIO076	; EM1D8		: EM1D8
							| GPCINV_GPIO077_InNormal					// GPIO077	; EM1D7		: EM1D7
							| GPCINV_GPIO078_InNormal					// GPIO078	; EM1D6		: EM1D6
							| GPCINV_GPIO079_InNormal					// GPIO079	; EM1D5		: EM1D5
							| GPCINV_GPIO080_InNormal					// GPIO080	; EM1D4		: EM1D4
							| GPCINV_GPIO081_InNormal					// GPIO081	; EM1D3		: EM1D3
							| GPCINV_GPIO082_InNormal					// GPIO082	; EM1D2		: EM1D2
							| GPCINV_GPIO083_InNormal					// GPIO083	; EM1D1		: EM1D1
							| GPCINV_GPIO084_InNormal					// GPIO084	; GPIO		: BOOT_SEL2
							| GPCINV_GPIO085_InNormal					// GPIO085	; EM1D0		: EM1D0
							| GPCINV_GPIO086_InNormal					// GPIO086	;
							| GPCINV_GPIO087_InNormal					// GPIO087	;
							| GPCINV_GPIO088_InNormal					// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCINV_GPIO089_InNormal					// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCINV_GPIO090_InNormal					// GPIO090	;
							| GPCINV_GPIO091_InNormal					// GPIO091	;
							| GPCINV_GPIO092_InNormal					// GPIO092	; EM1BA1	: EM1BA1
							| GPCINV_GPIO093_InNormal					// GPIO093	; EM1BA0	: EM1BA0
							| GPCINV_GPIO094_InNormal					// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCINV_GPIO095_InNormal;					// GPIO095	;

	//// Initializing GPIO C : Host Define
	#if (CPU2_BOOT_ENABLE)
	GpioCtrlRegs.GPCCSEL1.all = GPCCSEL1_GPIO064_CPU1Host				// GPIO064	; EM2D4		: EM2D4
							| GPCCSEL1_GPIO065_CPU1Host					// GPIO065	; EM2D3		: EM2D3
							| GPCCSEL1_GPIO066_CPU1Host					// GPIO066	; EM2D2		: EM2D2
							| GPCCSEL1_GPIO067_CPU1Host					// GPIO067	; EM2D1		: EM2D1
							| GPCCSEL1_GPIO068_CPU1Host					// GPIO068	; EM2D0		: EM2D0
							| GPCCSEL1_GPIO069_CPU1Host					// GPIO069	; EM1D15	: EM1D15
							| GPCCSEL1_GPIO070_CPU1Host					// GPIO070	; EM1D14	: EM1D14
							| GPCCSEL1_GPIO071_CPU1Host;				// GPIO071	; EM1D13	: EM1D13
	GpioCtrlRegs.GPCCSEL2.all =	GPCCSEL2_GPIO072_CPU1Host				// GPIO072	; EM1D12	: EM1D12 / (BOOT_SEL1)
							| GPCCSEL2_GPIO073_CPU1Host					// GPIO073	; EM1D11	: EM1D11
							| GPCCSEL2_GPIO074_CPU1Host					// GPIO074	; EM1D10	: EM1D10
							| GPCCSEL2_GPIO075_CPU1Host					// GPIO075	; EM1D9		: EM1D9
							| GPCCSEL2_GPIO076_CPU1Host					// GPIO076	; EM1D8		: EM1D8
							| GPCCSEL2_GPIO077_CPU1Host					// GPIO077	; EM1D7		: EM1D7
							| GPCCSEL2_GPIO078_CPU1Host					// GPIO078	; EM1D6		: EM1D6
							| GPCCSEL2_GPIO079_CPU1Host;				// GPIO079	; EM1D5		: EM1D5
	GpioCtrlRegs.GPCCSEL3.all = GPCCSEL3_GPIO080_CPU1Host				// GPIO080	; EM1D4		: EM1D4
							| GPCCSEL3_GPIO081_CPU1Host					// GPIO081	; EM1D3		: EM1D3
							| GPCCSEL3_GPIO082_CPU1Host					// GPIO082	; EM1D2		: EM1D2
							| GPCCSEL3_GPIO083_CPU1Host					// GPIO083	; EM1D1		: EM1D1
							| GPCCSEL3_GPIO084_CPU1Host					// GPIO084	; GPIO		: BOOT_SEL2
							| GPCCSEL3_GPIO085_CPU1Host					// GPIO085	; EM1D0		: EM1D0
							| GPCCSEL3_GPIO086_CPU1Host					// GPIO086	;
							| GPCCSEL3_GPIO087_CPU1Host;				// GPIO087	;
	GpioCtrlRegs.GPCCSEL4.all =	GPCCSEL4_GPIO088_CPU1Host				// GPIO088	; EM1DQM0	: EM1DQM0
							| GPCCSEL4_GPIO089_CPU1Host					// GPIO089	; EM1DQM1	: EM1DQM1
							| GPCCSEL4_GPIO090_CPU1Host					// GPIO090	;
							| GPCCSEL4_GPIO091_CPU1Host					// GPIO091	;
							| GPCCSEL4_GPIO092_CPU1Host					// GPIO092	; EM1BA1	: EM1BA1
							| GPCCSEL4_GPIO093_CPU1Host					// GPIO093	; EM1BA0	: EM1BA0
							| GPCCSEL4_GPIO094_CPU1Host					// GPIO094	; GPIO		: PIN_A3_DSP
							| GPCCSEL4_GPIO095_CPU1Host;				// GPIO095	;
	#else
	GpioCtrlRegs.GPCCSEL1.all = GPCCSEL1_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPCCSEL1.all = GPCCSEL2_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPCCSEL1.all = GPCCSEL3_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPCCSEL1.all = GPCCSEL4_GPIOAll_CPU1Host;
	#endif
#endif

	//// Initializing GPIO C : Initial Value
	////// Initializing GPIO C : Initial Value - CPU1
	uil_CPU1GPxSet = 0L;
	uil_CPU1GPxClear = 0L;

	////// Initializing GPIO C : Initial Value - CPU2
	uil_CPU2GPxSet = 0L;
	uil_CPU2GPxClear = 0L;
#ifdef CPU1
	#if (!CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO A : Set Initial Value - CPU1 and CPU2
	GpioDataRegs.GPCSET.all = uil_CPU1GPxSet
							| uil_CPU2GPxSet;
	GpioDataRegs.GPCCLEAR.all = uil_CPU1GPxClear
								| uil_CPU2GPxClear;
	#elif (CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO C : Set Initial Value - CPU1
	GpioDataRegs.GPCSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPCCLEAR.all = uil_CPU1GPxClear;
	#elif (CPU2_BOOT_ENABLE && CPU2_FLASH_BOOT)
	////// Initializing GPIO C : Set Initial Value - CPU1
	GpioDataRegs.GPCSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPCCLEAR.all = uil_CPU1GPxClear;

	////// Initializing GPIO C : Set Initial Value - CPU2
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPCSET.all)), uil_CPU2GPxSet);
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPCCLEAR.all)), uil_CPU2GPxClear);
	#endif
#endif

#ifdef CPU2
	#if (!CPU2_FLASH_BOOT)
	////// Initializing GPIO C : Set Initial Value - CPU2
	GpioDataRegs.GPCSET.all = uil_CPU2GPxSet;
	GpioDataRegs.GPCCLEAR.all = uil_CPU2GPxClear;
	#endif
#endif

	// Initializing GPIO D
#ifdef CPU1
	//// Initializing GPIO D : Pin Function
	////// Initializing GPIO D : Pin Function - Group MUX
	GpioCtrlRegs.GPDGMUX1.all = GPDGMUX1_GPIO096_OutEM2DQM1				// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDGMUX1_GPIO097_OutEM2DQM0				// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDGMUX1_GPIO098_OutEM2A0					// GPIO098	; EM2A0		: EM2A0
							| GPDGMUX1_GPIO099_OutEM2A1					// GPIO099	; EM2A1		: EM2A1
							| GPDGMUX1_GPIO100_OutEM2A2					// GPIO100	; EM2A2		: EM2A2
							| GPDGMUX1_GPIO101_OutEM2A3					// GPIO101	; EM2A3		: EM2A3
							| GPDGMUX1_GPIO102_OutEM2A4					// GPIO102	; EM2A4		: EM2A4
							| GPDGMUX1_GPIO103_OutEM2A5					// GPIO103	; EM2A5		: EM2A5
							| GPDGMUX1_GPIO104_OutEM2A6					// GPIO104	; EM2A6		: EM2A6
							| GPDGMUX1_GPIO105_OutEM2A7					// GPIO105	; EM2A7		: EM2A7
							| GPDGMUX1_GPIO106_OutEM2A8					// GPIO106	; EM2A8		: EM2A8
							| GPDGMUX1_GPIO107_OutEM2A9					// GPIO107	; EM2A9		: EM2A9
							| GPDGMUX1_GPIO108_OutEM2A10				// GPIO108	; EM2A10	: EM2A10
							| GPDGMUX1_GPIO109_OutEM2A11				// GPIO109	; EM2A11	: EM2A11
							| GPDGMUX1_GPIO110_OutEM2WAIT				// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDGMUX1_GPIO111_InOutGPIO;				// GPIO111	;
	GpioCtrlRegs.GPDGMUX2.all = GPDGMUX2_GPIO112_OutEM2BA1				// GPIO112	; EM2BA1	: EM2BA1
							| GPDGMUX2_GPIO113_OutEM2CAS				// GPIO113	; EM2CAS	: EM2CAS
							| GPDGMUX2_GPIO114_OutEM2RAS				// GPIO114	; EM2RAS	: EM2RAS
							| GPDGMUX2_GPIO115_InOutGPIO				// GPIO115	;
							| GPDGMUX2_GPIO116_OutnEM2CS2				// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDGMUX2_GPIO117_InOutGPIO				// GPIO117	;
							| GPDGMUX2_GPIO118_InOutGPIO				// GPIO118	;
							| GPDGMUX2_GPIO119_OutEM2RNW				// GPIO119	; EM2RNW	: EM2RNW
							| GPDGMUX2_GPIO120_OutnEM2WE				// GPIO120	; /EM2WE	: /EM2WE
							| GPDGMUX2_GPIO121_OutnEM2OE				// GPIO121	; /EM2OE	: /EM2OE
							| GPDGMUX2_GPIO122_InOutGPIO				// GPIO122	;
							| GPDGMUX2_GPIO123_InOutGPIO				// GPIO123	;
							| GPDGMUX2_GPIO124_InOutGPIO				// GPIO124	;
							| GPDGMUX2_GPIO125_InOutGPIO				// GPIO125	;
							| GPDGMUX2_GPIO126_InOutGPIO				// GPIO126	;
							| GPDGMUX2_GPIO127_InOutGPIO;				// GPIO127	;

	////// Initializing GPIO D : Pin Function - MUX
	GpioCtrlRegs.GPDMUX1.all = GPDMUX1_GPIO096_OutEM2DQM1				// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDMUX1_GPIO097_OutEM2DQM0				// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDMUX1_GPIO098_OutEM2A0					// GPIO098	; EM2A0		: EM2A0
							| GPDMUX1_GPIO099_OutEM2A1					// GPIO099	; EM2A1		: EM2A1
							| GPDMUX1_GPIO100_OutEM2A2					// GPIO100	; EM2A2		: EM2A2
							| GPDMUX1_GPIO101_OutEM2A3					// GPIO101	; EM2A3		: EM2A3
							| GPDMUX1_GPIO102_OutEM2A4					// GPIO102	; EM2A4		: EM2A4
							| GPDMUX1_GPIO103_OutEM2A5					// GPIO103	; EM2A5		: EM2A5
							| GPDMUX1_GPIO104_OutEM2A6					// GPIO104	; EM2A6		: EM2A6
							| GPDMUX1_GPIO105_OutEM2A7					// GPIO105	; EM2A7		: EM2A7
							| GPDMUX1_GPIO106_OutEM2A8					// GPIO106	; EM2A8		: EM2A8
							| GPDMUX1_GPIO107_OutEM2A9					// GPIO107	; EM2A9		: EM2A9
							| GPDMUX1_GPIO108_OutEM2A10					// GPIO108	; EM2A10	: EM2A10
							| GPDMUX1_GPIO109_OutEM2A11					// GPIO109	; EM2A11	: EM2A11
							| GPDMUX1_GPIO110_OutEM2WAIT				// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDMUX1_GPIO111_InOutGPIO;				// GPIO111	;
	GpioCtrlRegs.GPDMUX2.all = GPDMUX2_GPIO112_OutEM2BA1				// GPIO112	; EM2BA1	: EM2BA1
							| GPDMUX2_GPIO113_OutEM2CAS					// GPIO113	; EM2CAS	: EM2CAS
							| GPDMUX2_GPIO114_OutEM2RAS					// GPIO114	; EM2RAS	: EM2RAS
							| GPDMUX2_GPIO115_InOutGPIO					// GPIO115	;
							| GPDMUX2_GPIO116_OutnEM2CS2				// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDMUX2_GPIO117_InOutGPIO					// GPIO117	;
							| GPDMUX2_GPIO118_InOutGPIO					// GPIO118	;
							| GPDMUX2_GPIO119_OutEM2RNW					// GPIO119	; EM2RNW	: EM2RNW
							| GPDMUX2_GPIO120_OutnEM2WE					// GPIO120	; /EM2WE	: /EM2WE
							| GPDMUX2_GPIO121_OutnEM2OE					// GPIO121	; /EM2OE	: /EM2OE
							| GPDMUX2_GPIO122_InOutGPIO					// GPIO122	;
							| GPDMUX2_GPIO123_InOutGPIO					// GPIO123	;
							| GPDMUX2_GPIO124_InOutGPIO					// GPIO124	;
							| GPDMUX2_GPIO125_InOutGPIO					// GPIO125	;
							| GPDMUX2_GPIO126_InOutGPIO					// GPIO126	;
							| GPDMUX2_GPIO127_InOutGPIO;				// GPIO127	;

	//// Initializing GPIO D : Pin Direction
	GpioCtrlRegs.GPDDIR.all = GPDDIR_GPIO096_Output						// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDDIR_GPIO097_Output						// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDDIR_GPIO098_Output						// GPIO098	; EM2A0		: EM2A0
							| GPDDIR_GPIO099_Output						// GPIO099	; EM2A1		: EM2A1
							| GPDDIR_GPIO100_Output						// GPIO100	; EM2A2		: EM2A2
							| GPDDIR_GPIO101_Output						// GPIO101	; EM2A3		: EM2A3
							| GPDDIR_GPIO102_Output						// GPIO102	; EM2A4		: EM2A4
							| GPDDIR_GPIO103_Output						// GPIO103	; EM2A5		: EM2A5
							| GPDDIR_GPIO104_Output						// GPIO104	; EM2A6		: EM2A6
							| GPDDIR_GPIO105_Output						// GPIO105	; EM2A7		: EM2A7
							| GPDDIR_GPIO106_Output						// GPIO106	; EM2A8		: EM2A8
							| GPDDIR_GPIO107_Output						// GPIO107	; EM2A9		: EM2A9
							| GPDDIR_GPIO108_Output						// GPIO108	; EM2A10	: EM2A10
							| GPDDIR_GPIO109_Output						// GPIO109	; EM2A11	: EM2A11
							| GPDDIR_GPIO110_Output						// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDDIR_GPIO111_Input						// GPIO111	;
							| GPDDIR_GPIO112_Output						// GPIO112	; EM2BA1	: EM2BA1
							| GPDDIR_GPIO113_Output						// GPIO113	; EM2CAS	: EM2CAS
							| GPDDIR_GPIO114_Output						// GPIO114	; EM2RAS	: EM2RAS
							| GPDDIR_GPIO115_Input						// GPIO115	;
							| GPDDIR_GPIO116_Output						// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDDIR_GPIO117_Input						// GPIO117	;
							| GPDDIR_GPIO118_Input						// GPIO118	;
							| GPDDIR_GPIO119_Output						// GPIO119	; EM2RNW	: EM2RNW
							| GPDDIR_GPIO120_Output						// GPIO120	; /EM2WE	: /EM2WE
							| GPDDIR_GPIO121_Output						// GPIO121	; /EM2OE	: /EM2OE
							| GPDDIR_GPIO122_Input						// GPIO122	;
							| GPDDIR_GPIO123_Input						// GPIO123	;
							| GPDDIR_GPIO124_Input						// GPIO124	;
							| GPDDIR_GPIO125_Input						// GPIO125	;
							| GPDDIR_GPIO126_Input						// GPIO126	;
							| GPDDIR_GPIO127_Input;						// GPIO127	;

	//// Initializing GPIO D : Pull Up
	GpioCtrlRegs.GPDPUD.all = GPDPUD_GPIO096_PullUpDisable				// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDPUD_GPIO097_PullUpDisable				// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDPUD_GPIO098_PullUpDisable				// GPIO098	; EM2A0		: EM2A0
							| GPDPUD_GPIO099_PullUpDisable				// GPIO099	; EM2A1		: EM2A1
							| GPDPUD_GPIO100_PullUpDisable				// GPIO100	; EM2A2		: EM2A2
							| GPDPUD_GPIO101_PullUpDisable				// GPIO101	; EM2A3		: EM2A3
							| GPDPUD_GPIO102_PullUpDisable				// GPIO102	; EM2A4		: EM2A4
							| GPDPUD_GPIO103_PullUpDisable				// GPIO103	; EM2A5		: EM2A5
							| GPDPUD_GPIO104_PullUpDisable				// GPIO104	; EM2A6		: EM2A6
							| GPDPUD_GPIO105_PullUpDisable				// GPIO105	; EM2A7		: EM2A7
							| GPDPUD_GPIO106_PullUpDisable				// GPIO106	; EM2A8		: EM2A8
							| GPDPUD_GPIO107_PullUpDisable				// GPIO107	; EM2A9		: EM2A9
							| GPDPUD_GPIO108_PullUpDisable				// GPIO108	; EM2A10	: EM2A10
							| GPDPUD_GPIO109_PullUpDisable				// GPIO109	; EM2A11	: EM2A11
							| GPDPUD_GPIO110_PullUpDisable				// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDPUD_GPIO111_PullUpDisable				// GPIO111	;
							| GPDPUD_GPIO112_PullUpDisable				// GPIO112	; EM2BA1	: EM2BA1
							| GPDPUD_GPIO113_PullUpDisable				// GPIO113	; EM2CAS	: EM2CAS
							| GPDPUD_GPIO114_PullUpDisable				// GPIO114	; EM2RAS	: EM2RAS
							| GPDPUD_GPIO115_PullUpDisable				// GPIO115	;
							| GPDPUD_GPIO116_PullUpDisable				// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDPUD_GPIO117_PullUpDisable				// GPIO117	;
							| GPDPUD_GPIO118_PullUpDisable				// GPIO118	;
							| GPDPUD_GPIO119_PullUpDisable				// GPIO119	; EM2RNW	: EM2RNW
							| GPDPUD_GPIO120_PullUpDisable				// GPIO120	; /EM2WE	: /EM2WE
							| GPDPUD_GPIO121_PullUpDisable				// GPIO121	; /EM2OE	: /EM2OE
							| GPDPUD_GPIO122_PullUpDisable				// GPIO122	;
							| GPDPUD_GPIO123_PullUpDisable				// GPIO123	;
							| GPDPUD_GPIO124_PullUpDisable				// GPIO124	;
							| GPDPUD_GPIO125_PullUpDisable				// GPIO125	;
							| GPDPUD_GPIO126_PullUpDisable				// GPIO126	;
							| GPDPUD_GPIO127_PullUpDisable;				// GPIO127	;

	//// Initializing GPIO D : Open Drain
	GpioCtrlRegs.GPDODR.all = GPDODR_GPIO096_Normal						// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDODR_GPIO097_Normal						// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDODR_GPIO098_Normal						// GPIO098	; EM2A0		: EM2A0
							| GPDODR_GPIO099_Normal						// GPIO099	; EM2A1		: EM2A1
							| GPDODR_GPIO100_Normal						// GPIO100	; EM2A2		: EM2A2
							| GPDODR_GPIO101_Normal						// GPIO101	; EM2A3		: EM2A3
							| GPDODR_GPIO102_Normal						// GPIO102	; EM2A4		: EM2A4
							| GPDODR_GPIO103_Normal						// GPIO103	; EM2A5		: EM2A5
							| GPDODR_GPIO104_Normal						// GPIO104	; EM2A6		: EM2A6
							| GPDODR_GPIO105_Normal						// GPIO105	; EM2A7		: EM2A7
							| GPDODR_GPIO106_Normal						// GPIO106	; EM2A8		: EM2A8
							| GPDODR_GPIO107_Normal						// GPIO107	; EM2A9		: EM2A9
							| GPDODR_GPIO108_Normal						// GPIO108	; EM2A10	: EM2A10
							| GPDODR_GPIO109_Normal						// GPIO109	; EM2A11	: EM2A11
							| GPDODR_GPIO110_Normal						// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDODR_GPIO111_Normal						// GPIO111	;
							| GPDODR_GPIO112_Normal						// GPIO112	; EM2BA1	: EM2BA1
							| GPDODR_GPIO113_Normal						// GPIO113	; EM2CAS	: EM2CAS
							| GPDODR_GPIO114_Normal						// GPIO114	; EM2RAS	: EM2RAS
							| GPDODR_GPIO115_Normal						// GPIO115	;
							| GPDODR_GPIO116_Normal						// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDODR_GPIO117_Normal						// GPIO117	;
							| GPDODR_GPIO118_Normal						// GPIO118	;
							| GPDODR_GPIO119_Normal						// GPIO119	; EM2RNW	: EM2RNW
							| GPDODR_GPIO120_Normal						// GPIO120	; /EM2WE	: /EM2WE
							| GPDODR_GPIO121_Normal						// GPIO121	; /EM2OE	: /EM2OE
							| GPDODR_GPIO122_Normal						// GPIO122	;
							| GPDODR_GPIO123_Normal						// GPIO123	;
							| GPDODR_GPIO124_Normal						// GPIO124	;
							| GPDODR_GPIO125_Normal						// GPIO125	;
							| GPDODR_GPIO126_Normal						// GPIO126	;
							| GPDODR_GPIO127_Normal;					// GPIO127	;

	//// Initializing GPIO D : Input Sampling Freq.
	GpioCtrlRegs.GPDCTRL.all = GPDCTRL_QUALPRD0_GPIO103to096_Value(0)	// QUALPRD0	; QUALPRDCLKx = PLLSYSCLK / (2 x QUALPRDx)
							| GPDCTRL_QUALPRD1_GPIO111to104_Value(0)	// QUALPRD1	; 0(/1), 1(/2), 2(/4), 3(/6)
							| GPDCTRL_QUALPRD2_GPIO119to112_Value(0)	// QUALPRD2	; ...
							| GPDCTRL_QUALPRD3_GPIO127to120_Value(0);	// QUALPRD3	; 253(/506), 254(/508), 255(/510)

	//// Initializing GPIO D : Input Sampling Mode
	GpioCtrlRegs.GPDQSEL1.all = GPDQSEL1_GPIO096_Asynch					// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDQSEL1_GPIO097_Asynch					// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDQSEL1_GPIO098_Asynch					// GPIO098	; EM2A0		: EM2A0
							| GPDQSEL1_GPIO099_Asynch					// GPIO099	; EM2A1		: EM2A1
							| GPDQSEL1_GPIO100_Asynch					// GPIO100	; EM2A2		: EM2A2
							| GPDQSEL1_GPIO101_Asynch					// GPIO101	; EM2A3		: EM2A3
							| GPDQSEL1_GPIO102_Asynch					// GPIO102	; EM2A4		: EM2A4
							| GPDQSEL1_GPIO103_Asynch					// GPIO103	; EM2A5		: EM2A5
							| GPDQSEL1_GPIO104_Asynch					// GPIO104	; EM2A6		: EM2A6
							| GPDQSEL1_GPIO105_Asynch					// GPIO105	; EM2A7		: EM2A7
							| GPDQSEL1_GPIO106_Asynch					// GPIO106	; EM2A8		: EM2A8
							| GPDQSEL1_GPIO107_Asynch					// GPIO107	; EM2A9		: EM2A9
							| GPDQSEL1_GPIO108_Asynch					// GPIO108	; EM2A10	: EM2A10
							| GPDQSEL1_GPIO109_Asynch					// GPIO109	; EM2A11	: EM2A11
							| GPDQSEL1_GPIO110_Asynch					// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDQSEL1_GPIO111_Asynch;					// GPIO111	;
	GpioCtrlRegs.GPDQSEL2.all = GPDQSEL2_GPIO112_Asynch					// GPIO112	; EM2BA1	: EM2BA1
							| GPDQSEL2_GPIO113_Asynch					// GPIO113	; EM2CAS	: EM2CAS
							| GPDQSEL2_GPIO114_Asynch					// GPIO114	; EM2RAS	: EM2RAS
							| GPDQSEL2_GPIO115_Asynch					// GPIO115	;
							| GPDQSEL2_GPIO116_Asynch					// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDQSEL2_GPIO117_Asynch					// GPIO117	;
							| GPDQSEL2_GPIO118_Asynch					// GPIO118	;
							| GPDQSEL2_GPIO119_Asynch					// GPIO119	; EM2RNW	: EM2RNW
							| GPDQSEL2_GPIO120_Asynch					// GPIO120	; /EM2WE	: /EM2WE
							| GPDQSEL2_GPIO121_Asynch					// GPIO121	; /EM2OE	: /EM2OE
							| GPDQSEL2_GPIO122_Asynch					// GPIO122	;
							| GPDQSEL2_GPIO123_Asynch					// GPIO123	;
							| GPDQSEL2_GPIO124_Asynch					// GPIO124	;
							| GPDQSEL2_GPIO125_Asynch					// GPIO125	;
							| GPDQSEL2_GPIO126_Asynch					// GPIO126	;
							| GPDQSEL2_GPIO127_Asynch;					// GPIO127	;

	//// Initializing GPIO D : Input Polarity
	GpioCtrlRegs.GPDINV.all = GPDINV_GPIO096_InNormal					// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDINV_GPIO097_InNormal					// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDINV_GPIO098_InNormal					// GPIO098	; EM2A0		: EM2A0
							| GPDINV_GPIO099_InNormal					// GPIO099	; EM2A1		: EM2A1
							| GPDINV_GPIO100_InNormal					// GPIO100	; EM2A2		: EM2A2
							| GPDINV_GPIO101_InNormal					// GPIO101	; EM2A3		: EM2A3
							| GPDINV_GPIO102_InNormal					// GPIO102	; EM2A4		: EM2A4
							| GPDINV_GPIO103_InNormal					// GPIO103	; EM2A5		: EM2A5
							| GPDINV_GPIO104_InNormal					// GPIO104	; EM2A6		: EM2A6
							| GPDINV_GPIO105_InNormal					// GPIO105	; EM2A7		: EM2A7
							| GPDINV_GPIO106_InNormal					// GPIO106	; EM2A8		: EM2A8
							| GPDINV_GPIO107_InNormal					// GPIO107	; EM2A9		: EM2A9
							| GPDINV_GPIO108_InNormal					// GPIO108	; EM2A10	: EM2A10
							| GPDINV_GPIO109_InNormal					// GPIO109	; EM2A11	: EM2A11
							| GPDINV_GPIO110_InNormal					// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDINV_GPIO111_InNormal					// GPIO111	;
							| GPDINV_GPIO112_InNormal					// GPIO112	; EM2BA1	: EM2BA1
							| GPDINV_GPIO113_InNormal					// GPIO113	; EM2CAS	: EM2CAS
							| GPDINV_GPIO114_InNormal					// GPIO114	; EM2RAS	: EM2RAS
							| GPDINV_GPIO115_InNormal					// GPIO115	;
							| GPDINV_GPIO116_InNormal					// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDINV_GPIO117_InNormal					// GPIO117	;
							| GPDINV_GPIO118_InNormal					// GPIO118	;
							| GPDINV_GPIO119_InNormal					// GPIO119	; EM2RNW	: EM2RNW
							| GPDINV_GPIO120_InNormal					// GPIO120	; /EM2WE	: /EM2WE
							| GPDINV_GPIO121_InNormal					// GPIO121	; /EM2OE	: /EM2OE
							| GPDINV_GPIO122_InNormal					// GPIO122	;
							| GPDINV_GPIO123_InNormal					// GPIO123	;
							| GPDINV_GPIO124_InNormal					// GPIO124	;
							| GPDINV_GPIO125_InNormal					// GPIO125	;
							| GPDINV_GPIO126_InNormal					// GPIO126	;
							| GPDINV_GPIO127_InNormal;					// GPIO127	;

	//// Initializing GPIO D : Host Define
	#if (CPU2_BOOT_ENABLE)
	GpioCtrlRegs.GPDCSEL1.all = GPDCSEL1_GPIO096_CPU1Host				// GPIO096	; EM2DQM1	: EM2DQM1
							| GPDCSEL1_GPIO097_CPU1Host					// GPIO097	; EM2DQM0	: EM2DQM0
							| GPDCSEL1_GPIO098_CPU1Host					// GPIO098	; EM2A0		: EM2A0
							| GPDCSEL1_GPIO099_CPU1Host					// GPIO099	; EM2A1		: EM2A1
							| GPDCSEL1_GPIO100_CPU1Host					// GPIO100	; EM2A2		: EM2A2
							| GPDCSEL1_GPIO101_CPU1Host					// GPIO101	; EM2A3		: EM2A3
							| GPDCSEL1_GPIO102_CPU1Host					// GPIO102	; EM2A4		: EM2A4
							| GPDCSEL1_GPIO103_CPU1Host;				// GPIO103	; EM2A5		: EM2A5
	GpioCtrlRegs.GPDCSEL2.all = GPDCSEL2_GPIO104_CPU1Host				// GPIO104	; EM2A6		: EM2A6
							| GPDCSEL2_GPIO105_CPU1Host					// GPIO105	; EM2A7		: EM2A7
							| GPDCSEL2_GPIO106_CPU1Host					// GPIO106	; EM2A8		: EM2A8
							| GPDCSEL2_GPIO107_CPU1Host					// GPIO107	; EM2A9		: EM2A9
							| GPDCSEL2_GPIO108_CPU1Host					// GPIO108	; EM2A10	: EM2A10
							| GPDCSEL2_GPIO109_CPU1Host					// GPIO109	; EM2A11	: EM2A11
							| GPDCSEL2_GPIO110_CPU1Host					// GPIO110	; EM2WAIT	: EM2WAIT
							| GPDCSEL2_GPIO111_CPU1Host;				// GPIO111	;
	GpioCtrlRegs.GPDCSEL3.all =  GPDCSEL3_GPIO112_CPU1Host				// GPIO112	; EM2BA1	: EM2BA1
							| GPDCSEL3_GPIO113_CPU1Host					// GPIO113	; EM2CAS	: EM2CAS
							| GPDCSEL3_GPIO114_CPU1Host					// GPIO114	; EM2RAS	: EM2RAS
							| GPDCSEL3_GPIO115_CPU1Host					// GPIO115	;
							| GPDCSEL3_GPIO116_CPU1Host					// GPIO116	; /EM2CS2	: /EM2CS2
							| GPDCSEL3_GPIO117_CPU1Host					// GPIO117	;
							| GPDCSEL3_GPIO118_CPU1Host					// GPIO118	;
							| GPDCSEL3_GPIO119_CPU1Host;				// GPIO119	; EM2RNW	: EM2RNW
	GpioCtrlRegs.GPDCSEL4.all =  GPDCSEL4_GPIO120_CPU1Host				// GPIO120	; /EM2WE	: /EM2WE
							| GPDCSEL4_GPIO121_CPU1Host					// GPIO121	; /EM2OE	: /EM2OE
							| GPDCSEL4_GPIO122_CPU1Host					// GPIO122	;
							| GPDCSEL4_GPIO123_CPU1Host					// GPIO123	;
							| GPDCSEL4_GPIO124_CPU1Host					// GPIO124	;
							| GPDCSEL4_GPIO125_CPU1Host					// GPIO125	;
							| GPDCSEL4_GPIO126_CPU1Host					// GPIO126	;
							| GPDCSEL4_GPIO127_CPU1Host;				// GPIO127	;
	#else
	GpioCtrlRegs.GPDCSEL1.all = GPDCSEL1_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPDCSEL2.all = GPDCSEL2_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPDCSEL3.all = GPDCSEL3_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPDCSEL4.all = GPDCSEL4_GPIOAll_CPU1Host;
	#endif
#endif

	//// Initializing GPIO D : Initial Value
	////// Initializing GPIO D : Initial Value - CPU1
	uil_CPU1GPxSet = 0L;
	uil_CPU1GPxClear = 0L;

	////// Initializing GPIO D : Initial Value - CPU2
	uil_CPU2GPxSet = 0L;
	uil_CPU2GPxClear = 0L;

#ifdef CPU1
	#if (!CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO D : Set Initial Value - CPU1 and CPU2
	GpioDataRegs.GPDSET.all = uil_CPU1GPxSet
							| uil_CPU2GPxSet;
	GpioDataRegs.GPDCLEAR.all = uil_CPU1GPxClear
								| uil_CPU2GPxClear;
	#elif (CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO D : Set Initial Value - CPU1
	GpioDataRegs.GPDSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPDCLEAR.all = uil_CPU1GPxClear;
	#elif (CPU2_BOOT_ENABLE && CPU2_FLASH_BOOT)
	////// Initializing GPIO D : Set Initial Value - CPU1
	GpioDataRegs.GPDSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPDCLEAR.all = uil_CPU1GPxClear;

	////// Initializing GPIO D : Set Initial Value - CPU2
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPDSET.all)), uil_CPU2GPxSet);
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPDCLEAR.all)), uil_CPU2GPxClear);
	#endif
#endif

#ifdef CPU2
	#if (!CPU2_FLASH_BOOT)
	////// Initializing GPIO D : Set Initial Value - CPU2
	GpioDataRegs.GPDSET.all = uil_CPU2GPxSet;
	GpioDataRegs.GPDCLEAR.all = uil_CPU2GPxClear;
	#endif
#endif

	// Initializing GPIO E
#ifdef CPU1
	//// Initializing GPIO E : Pin Function
	////// Initializing GPIO E : Pin Function - Group MUX
	GpioCtrlRegs.GPEGMUX1.all = GPEGMUX1_GPIO128_InOutGPIO				// GPIO128	;
							| GPEGMUX1_GPIO129_InOutGPIO				// GPIO129	;
							| GPEGMUX1_GPIO130_InOutGPIO				// GPIO130	;
							| GPEGMUX1_GPIO131_InOutGPIO				// GPIO131	;
							| GPEGMUX1_GPIO132_InOutGPIO				// GPIO132	;
							| GPEGMUX1_GPIO133_InOutGPIO				// GPIO133	;
							| GPEGMUX1_GPIO134_InOutGPIO				// GPIO134	; GPIO		: XF2
							| GPEGMUX1_GPIO135_InOutGPIO				// GPIO135	;
							| GPEGMUX1_GPIO136_InOutGPIO				// GPIO136	; GPIO		: IRQ
							| GPEGMUX1_GPIO137_InOutGPIO				// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPEGMUX1_GPIO138_InOutGPIO				// GPIO138	; GPIO		: LED3
							| GPEGMUX1_GPIO139_InOutGPIO				// GPIO139	; GPIO		: LED2
							| GPEGMUX1_GPIO140_InOutGPIO				// GPIO140	; GPIO		: LED1
							| GPEGMUX1_GPIO141_InOutGPIO				// GPIO141	; GPIO		: LED0
							| GPEGMUX1_GPIO142_InOutGPIO				// GPIO142	;
							| GPEGMUX1_GPIO143_InOutGPIO;				// GPIO143	;
	GpioCtrlRegs.GPEGMUX2.all = GPEGMUX2_GPIO144_InOutGPIO				// GPIO144	; GPIO		: XF1
							| GPEGMUX2_GPIO145_InOutGPIO				// GPIO145	;
							| GPEGMUX2_GPIO146_InOutGPIO				// GPIO146	;
							| GPEGMUX2_GPIO147_InOutGPIO				// GPIO147	;
							| GPEGMUX2_GPIO148_InOutGPIO				// GPIO148	;
							| GPEGMUX2_GPIO149_InOutGPIO				// GPIO149	;
							| GPEGMUX2_GPIO150_InOutGPIO				// GPIO150	;
							| GPEGMUX2_GPIO151_InOutGPIO				// GPIO151	;
							| GPEGMUX2_GPIO152_InOutGPIO				// GPIO152	; GPIO		: PIN_D13_DSP
							| GPEGMUX2_GPIO153_InOutGPIO				// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPEGMUX2_GPIO154_InOutGPIO				// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPEGMUX2_GPIO155_InOutGPIO				// GPIO155	;
							| GPEGMUX2_GPIO156_InOutGPIO				// GPIO156	;
							| GPEGMUX2_GPIO157_InOutGPIO				// GPIO157	;
							| GPEGMUX2_GPIO158_InOutGPIO				// GPIO158	;
							| GPEGMUX2_GPIO159_InOutGPIO;				// GPIO159	;

	////// Initializing GPIO E : Pin Function - MUX
	GpioCtrlRegs.GPEMUX1.all = GPEMUX1_GPIO128_InOutGPIO				// GPIO128	;
							| GPEMUX1_GPIO129_InOutGPIO					// GPIO129	;
							| GPEMUX1_GPIO130_InOutGPIO					// GPIO130	;
							| GPEMUX1_GPIO131_InOutGPIO					// GPIO131	;
							| GPEMUX1_GPIO132_InOutGPIO					// GPIO132	;
							| GPEMUX1_GPIO133_InOutGPIO					// GPIO133	;
							| GPEMUX1_GPIO134_InOutGPIO					// GPIO134	; GPIO		: XF2
							| GPEMUX1_GPIO135_InOutGPIO					// GPIO135	;
							| GPEMUX1_GPIO136_InOutGPIO					// GPIO136	; GPIO		: IRQ
							| GPEMUX1_GPIO137_InOutGPIO					// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPEMUX1_GPIO138_InOutGPIO					// GPIO138	; GPIO		: LED3
							| GPEMUX1_GPIO139_InOutGPIO					// GPIO139	; GPIO		: LED2
							| GPEMUX1_GPIO140_InOutGPIO					// GPIO140	; GPIO		: LED1
							| GPEMUX1_GPIO141_InOutGPIO					// GPIO141	; GPIO		: LED0
							| GPEMUX1_GPIO142_InOutGPIO					// GPIO142	;
							| GPEMUX1_GPIO143_InOutGPIO;				// GPIO143	;
	GpioCtrlRegs.GPEMUX2.all = GPEMUX2_GPIO144_InOutGPIO				// GPIO144	; GPIO		: XF1
							| GPEMUX2_GPIO145_InOutGPIO					// GPIO145	;
							| GPEMUX2_GPIO146_InOutGPIO					// GPIO146	;
							| GPEMUX2_GPIO147_InOutGPIO					// GPIO147	;
							| GPEMUX2_GPIO148_InOutGPIO					// GPIO148	;
							| GPEMUX2_GPIO149_InOutGPIO					// GPIO149	;
							| GPEMUX2_GPIO150_InOutGPIO					// GPIO150	;
							| GPEMUX2_GPIO151_InOutGPIO					// GPIO151	;
							| GPEMUX2_GPIO152_InOutGPIO					// GPIO152	; GPIO		: PIN_D13_DSP
							| GPEMUX2_GPIO153_InOutGPIO					// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPEMUX2_GPIO154_InOutGPIO					// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPEMUX2_GPIO155_InOutGPIO					// GPIO155	;
							| GPEMUX2_GPIO156_InOutGPIO					// GPIO156	;
							| GPEMUX2_GPIO157_InOutGPIO					// GPIO157	;
							| GPEMUX2_GPIO158_InOutGPIO					// GPIO158	;
							| GPEMUX2_GPIO159_InOutGPIO;				// GPIO159	;

	//// Initializing GPIO E : Pin Direction
	GpioCtrlRegs.GPEDIR.all = GPEDIR_GPIO128_Input						// GPIO128	;
							| GPEDIR_GPIO129_Input						// GPIO129	;
							| GPEDIR_GPIO130_Input						// GPIO130	;
							| GPEDIR_GPIO131_Input						// GPIO131	;
							| GPEDIR_GPIO132_Input						// GPIO132	;
							| GPEDIR_GPIO133_Input						// GPIO133	;
							| GPEDIR_GPIO134_Output						// GPIO134	; GPIO		: XF2
							| GPEDIR_GPIO135_Input						// GPIO135	;
							| GPEDIR_GPIO136_Input						// GPIO136	; GPIO		: IRQ
							| GPEDIR_GPIO137_Input						// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPEDIR_GPIO138_Output						// GPIO138	; GPIO		: LED3
							| GPEDIR_GPIO139_Output						// GPIO139	; GPIO		: LED2
							| GPEDIR_GPIO140_Output						// GPIO140	; GPIO		: LED1
							| GPEDIR_GPIO141_Output						// GPIO141	; GPIO		: LED0
							| GPEDIR_GPIO142_Input						// GPIO142	;
							| GPEDIR_GPIO143_Input						// GPIO143	;
							| GPEDIR_GPIO144_Output						// GPIO144	; GPIO		: XF1
							| GPEDIR_GPIO145_Input						// GPIO145	;
							| GPEDIR_GPIO146_Input						// GPIO146	;
							| GPEDIR_GPIO147_Input						// GPIO147	;
							| GPEDIR_GPIO148_Input						// GPIO148	;
							| GPEDIR_GPIO149_Input						// GPIO149	;
							| GPEDIR_GPIO150_Input						// GPIO150	;
							| GPEDIR_GPIO151_Input						// GPIO151	;
							| GPEDIR_GPIO152_Input						// GPIO152	; GPIO		: PIN_D13_DSP
							| GPEDIR_GPIO153_Input						// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPEDIR_GPIO154_Input						// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPEDIR_GPIO155_Input						// GPIO155	;
							| GPEDIR_GPIO156_Input						// GPIO156	;
							| GPEDIR_GPIO157_Input						// GPIO157	;
							| GPEDIR_GPIO158_Input						// GPIO158	;
							| GPEDIR_GPIO159_Input;						// GPIO159	;

	//// Initializing GPIO E : Pull Up
	GpioCtrlRegs.GPEPUD.all = GPEPUD_GPIO128_PullUpDisable				// GPIO128	;
							| GPEPUD_GPIO129_PullUpDisable				// GPIO129	;
							| GPEPUD_GPIO130_PullUpDisable				// GPIO130	;
							| GPEPUD_GPIO131_PullUpDisable				// GPIO131	;
							| GPEPUD_GPIO132_PullUpDisable				// GPIO132	;
							| GPEPUD_GPIO133_PullUpDisable				// GPIO133	;
							| GPEPUD_GPIO134_PullUpDisable				// GPIO134	; GPIO		: XF2
							| GPEPUD_GPIO135_PullUpDisable				// GPIO135	;
							| GPEPUD_GPIO136_PullUpDisable				// GPIO136	; GPIO		: IRQ
							| GPEPUD_GPIO137_PullUpDisable				// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPEPUD_GPIO138_PullUpDisable				// GPIO138	; GPIO		: LED3
							| GPEPUD_GPIO139_PullUpDisable				// GPIO139	; GPIO		: LED2
							| GPEPUD_GPIO140_PullUpDisable				// GPIO140	; GPIO		: LED1
							| GPEPUD_GPIO141_PullUpDisable				// GPIO141	; GPIO		: LED0
							| GPEPUD_GPIO142_PullUpDisable				// GPIO142	;
							| GPEPUD_GPIO143_PullUpDisable				// GPIO143	;
							| GPEPUD_GPIO144_PullUpDisable				// GPIO144	;
							| GPEPUD_GPIO145_PullUpDisable				// GPIO145	;
							| GPEPUD_GPIO146_PullUpDisable				// GPIO146	;
							| GPEPUD_GPIO147_PullUpDisable				// GPIO147	;
							| GPEPUD_GPIO148_PullUpDisable				// GPIO148	;
							| GPEPUD_GPIO149_PullUpDisable				// GPIO149	;
							| GPEPUD_GPIO150_PullUpDisable				// GPIO150	;
							| GPEPUD_GPIO151_PullUpDisable				// GPIO151	;
							| GPEPUD_GPIO152_PullUpDisable				// GPIO152	; GPIO		: PIN_D13_DSP
							| GPEPUD_GPIO153_PullUpDisable				// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPEPUD_GPIO154_PullUpDisable				// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPEPUD_GPIO155_PullUpDisable				// GPIO155	;
							| GPEPUD_GPIO156_PullUpDisable				// GPIO156	;
							| GPEPUD_GPIO157_PullUpDisable				// GPIO157	;
							| GPEPUD_GPIO158_PullUpDisable				// GPIO158	;
							| GPEPUD_GPIO159_PullUpDisable;				// GPIO159	;

	//// Initializing GPIO E : Open Drain
	GpioCtrlRegs.GPEODR.all = GPEODR_GPIO128_Normal						// GPIO128	;
							| GPEODR_GPIO129_Normal						// GPIO129	;
							| GPEODR_GPIO130_Normal						// GPIO130	;
							| GPEODR_GPIO131_Normal						// GPIO131	;
							| GPEODR_GPIO132_Normal						// GPIO132	;
							| GPEODR_GPIO133_Normal						// GPIO133	;
							| GPEODR_GPIO134_Normal						// GPIO134	; GPIO		: XF2
							| GPEODR_GPIO135_Normal						// GPIO135	;
							| GPEODR_GPIO136_Normal						// GPIO136	; GPIO		: IRQ
							| GPEODR_GPIO137_Normal						// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPEODR_GPIO138_OpenDrain					// GPIO138	; GPIO		: LED3
							| GPEODR_GPIO139_OpenDrain					// GPIO139	; GPIO		: LED2
							| GPEODR_GPIO140_OpenDrain					// GPIO140	; GPIO		: LED1
							| GPEODR_GPIO141_OpenDrain					// GPIO141	; GPIO		: LED0
							| GPEODR_GPIO142_Normal						// GPIO142	;
							| GPEODR_GPIO143_Normal						// GPIO143	;
							| GPEODR_GPIO144_Normal						// GPIO144	;
							| GPEODR_GPIO145_Normal						// GPIO145	;
							| GPEODR_GPIO146_Normal						// GPIO146	;
							| GPEODR_GPIO147_Normal						// GPIO147	;
							| GPEODR_GPIO148_Normal						// GPIO148	;
							| GPEODR_GPIO149_Normal						// GPIO149	;
							| GPEODR_GPIO150_Normal						// GPIO150	;
							| GPEODR_GPIO151_Normal						// GPIO151	;
							| GPEODR_GPIO152_Normal						// GPIO152	; GPIO		: PIN_D13_DSP
							| GPEODR_GPIO153_Normal						// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPEODR_GPIO154_Normal						// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPEODR_GPIO155_Normal						// GPIO155	;
							| GPEODR_GPIO156_Normal						// GPIO156	;
							| GPEODR_GPIO157_Normal						// GPIO157	;
							| GPEODR_GPIO158_Normal						// GPIO158	;
							| GPEODR_GPIO159_Normal;					// GPIO159	;

	//// Initializing GPIO E : Input Sampling Freq.
	GpioCtrlRegs.GPECTRL.all = GPECTRL_QUALPRD0_GPIO135to128_Value(0)	// QUALPRD0	; QUALPRDCLKx = PLLSYSCLK / (2 x QUALPRDx)
							| GPECTRL_QUALPRD1_GPIO143to136_Value(0)	// QUALPRD1	; 0(/1), 1(/2), 2(/4), 3(/6)
							| GPECTRL_QUALPRD2_GPIO151to144_Value(0)	// QUALPRD2	; ...
							| GPECTRL_QUALPRD3_GPIO159to152_Value(0);	// QUALPRD3	; 253(/506), 254(/508), 255(/510)

	//// Initializing GPIO E : Input Sampling Mode
	GpioCtrlRegs.GPEQSEL1.all = GPEQSEL1_GPIO128_Asynch					// GPIO128	;
							| GPEQSEL1_GPIO129_Asynch					// GPIO129	;
							| GPEQSEL1_GPIO130_Asynch					// GPIO130	;
							| GPEQSEL1_GPIO131_Asynch					// GPIO131	;
							| GPEQSEL1_GPIO132_Asynch					// GPIO132	;
							| GPEQSEL1_GPIO133_Asynch					// GPIO133	;
							| GPEQSEL1_GPIO134_Asynch					// GPIO134	; GPIO		: XF2
							| GPEQSEL1_GPIO135_Asynch					// GPIO135	;
							| GPEQSEL1_GPIO136_Asynch					// GPIO136	; GPIO		: IRQ
							| GPEQSEL1_GPIO137_Asynch					// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPEQSEL1_GPIO138_Asynch					// GPIO138	; GPIO		: LED3
							| GPEQSEL1_GPIO139_Asynch					// GPIO139	; GPIO		: LED2
							| GPEQSEL1_GPIO140_Asynch					// GPIO140	; GPIO		: LED1
							| GPEQSEL1_GPIO141_Asynch					// GPIO141	; GPIO		: LED0
							| GPEQSEL1_GPIO142_Asynch					// GPIO142	;
							| GPEQSEL1_GPIO143_Asynch;					// GPIO143	;
	GpioCtrlRegs.GPEQSEL2.all = GPEQSEL2_GPIO144_Asynch					// GPIO144	;
							| GPEQSEL2_GPIO145_Asynch					// GPIO145	;
							| GPEQSEL2_GPIO146_Asynch					// GPIO146	;
							| GPEQSEL2_GPIO147_Asynch					// GPIO147	;
							| GPEQSEL2_GPIO148_Asynch					// GPIO148	;
							| GPEQSEL2_GPIO149_Asynch					// GPIO149	;
							| GPEQSEL2_GPIO150_Asynch					// GPIO150	;
							| GPEQSEL2_GPIO151_Asynch					// GPIO151	;
							| GPEQSEL2_GPIO152_Asynch					// GPIO152	; GPIO		: PIN_D13_DSP
							| GPEQSEL2_GPIO153_Asynch					// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPEQSEL2_GPIO154_Asynch					// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPEQSEL2_GPIO155_Asynch					// GPIO155	;
							| GPEQSEL2_GPIO156_Asynch					// GPIO156	;
							| GPEQSEL2_GPIO157_Asynch					// GPIO157	;
							| GPEQSEL2_GPIO158_Asynch					// GPIO158	;
							| GPEQSEL2_GPIO159_Asynch;					// GPIO159	;

	//// Initializing GPIO E : Input Polarity
	GpioCtrlRegs.GPEINV.all = GPEINV_GPIO128_InNormal					// GPIO128	;
							| GPEINV_GPIO129_InNormal					// GPIO129	;
							| GPEINV_GPIO130_InNormal					// GPIO130	;
							| GPEINV_GPIO131_InNormal					// GPIO131	;
							| GPEINV_GPIO132_InNormal					// GPIO132	;
							| GPEINV_GPIO133_InNormal					// GPIO133	;
							| GPEINV_GPIO134_InNormal					// GPIO134	; GPIO		: XF2
							| GPEINV_GPIO135_InNormal					// GPIO135	;
							| GPEINV_GPIO136_InNormal					// GPIO136	; GPIO		: IRQ
							| GPEINV_GPIO137_InNormal					// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPEINV_GPIO138_InNormal					// GPIO138	; GPIO		: LED3
							| GPEINV_GPIO139_InNormal					// GPIO139	; GPIO		: LED2
							| GPEINV_GPIO140_InNormal					// GPIO140	; GPIO		: LED1
							| GPEINV_GPIO141_InNormal					// GPIO141	; GPIO		: LED0
							| GPEINV_GPIO142_InNormal					// GPIO142	;
							| GPEINV_GPIO143_InNormal					// GPIO143	;
							| GPEINV_GPIO144_InNormal					// GPIO144	;
							| GPEINV_GPIO145_InNormal					// GPIO145	;
							| GPEINV_GPIO146_InNormal					// GPIO146	;
							| GPEINV_GPIO147_InNormal					// GPIO147	;
							| GPEINV_GPIO148_InNormal					// GPIO148	;
							| GPEINV_GPIO149_InNormal					// GPIO149	;
							| GPEINV_GPIO150_InNormal					// GPIO150	;
							| GPEINV_GPIO151_InNormal					// GPIO151	;
							| GPEINV_GPIO152_InNormal					// GPIO152	; GPIO		: PIN_D13_DSP
							| GPEINV_GPIO153_InNormal					// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPEINV_GPIO154_InNormal					// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPEINV_GPIO155_InNormal					// GPIO155	;
							| GPEINV_GPIO156_InNormal					// GPIO156	;
							| GPEINV_GPIO157_InNormal					// GPIO157	;
							| GPEINV_GPIO158_InNormal					// GPIO158	;
							| GPEINV_GPIO159_InNormal;					// GPIO159	;

	//// Initializing GPIO E : Host Define
	#if (CPU2_BOOT_ENABLE)
	GpioCtrlRegs.GPECSEL1.all = GPECSEL1_GPIO128_CPU1Host				// GPIO128	;
							| GPECSEL1_GPIO129_CPU1Host					// GPIO129	;
							| GPECSEL1_GPIO130_CPU1Host					// GPIO130	;
							| GPECSEL1_GPIO131_CPU1Host					// GPIO131	;
							| GPECSEL1_GPIO132_CPU1Host					// GPIO132	;
							| GPECSEL1_GPIO133_CPU1Host					// GPIO133	;
							| GPECSEL1_GPIO134_CPU2Host					// GPIO134	; GPIO		: XF2
							| GPECSEL1_GPIO135_CPU1Host;				// GPIO135	;
	GpioCtrlRegs.GPECSEL2.all = GPECSEL2_GPIO136_CPU1Host				// GPIO136	; GPIO		: IRQ
							| GPECSEL2_GPIO137_CPU1Host					// GPIO137	; GPIO		: /RESET_EHTERCAT
							| GPECSEL2_GPIO138_CPU2Host					// GPIO138	; GPIO		: LED3
							| GPECSEL2_GPIO139_CPU2Host					// GPIO139	; GPIO		: LED2
							| GPECSEL2_GPIO140_CPU1Host					// GPIO140	; GPIO		: LED1
							| GPECSEL2_GPIO141_CPU1Host					// GPIO141	; GPIO		: LED0
							| GPECSEL2_GPIO142_CPU1Host					// GPIO142	;
							| GPECSEL2_GPIO143_CPU1Host;				// GPIO143	;
	GpioCtrlRegs.GPECSEL3.all = GPECSEL3_GPIO144_CPU1Host				// GPIO144	;
							| GPECSEL3_GPIO145_CPU1Host					// GPIO145	;
							| GPECSEL3_GPIO146_CPU1Host					// GPIO146	;
							| GPECSEL3_GPIO147_CPU1Host					// GPIO147	;
							| GPECSEL3_GPIO148_CPU1Host					// GPIO148	;
							| GPECSEL3_GPIO149_CPU1Host					// GPIO149	;
							| GPECSEL3_GPIO150_CPU1Host					// GPIO150	;
							| GPECSEL3_GPIO151_CPU1Host;				// GPIO151	;
	GpioCtrlRegs.GPECSEL4.all = GPECSEL4_GPIO152_CPU1Host				// GPIO152	; GPIO		: PIN_D13_DSP
							| GPECSEL4_GPIO153_CPU1Host					// GPIO153	; GPIO		: DSP_MASTER_OUT1
							| GPECSEL4_GPIO154_CPU1Host					// GPIO154	; GPIO		: DSP_MASTER_OUT2
							| GPECSEL4_GPIO155_CPU1Host					// GPIO155	;
							| GPECSEL4_GPIO156_CPU1Host					// GPIO156	;
							| GPECSEL4_GPIO157_CPU1Host					// GPIO157	;
							| GPECSEL4_GPIO158_CPU1Host					// GPIO158	;
							| GPECSEL4_GPIO159_CPU1Host;				// GPIO159	;
	#else
	GpioCtrlRegs.GPECSEL1.all = GPECSEL1_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPECSEL2.all = GPECSEL2_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPECSEL3.all = GPECSEL3_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPECSEL4.all = GPECSEL4_GPIOAll_CPU1Host;
	#endif
#endif

	//// Initializing GPIO E : Initial Value
	////// Initializing GPIO E : Initial Value - CPU1
	uil_CPU1GPxSet = GPExxx_GPIO140										// GPIO140	; GPIO		: LED1
					| GPExxx_GPIO141;									// GPIO141	; GPIO		: LED0
	uil_CPU1GPxClear = GPExxx_GPIO144;									// GPIO144	; GPIO		: XF1;

	////// Initializing GPIO E : Initial Value - CPU2
	uil_CPU2GPxSet = GPExxx_GPIO138										// GPIO138	; GPIO		: LED3
					| GPExxx_GPIO139;									// GPIO139	; GPIO		: LED2
	uil_CPU2GPxClear = GPExxx_GPIO134;									// GPIO134	; GPIO		: XF2

#ifdef CPU1
	#if (!CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO E : Set Initial Value - CPU1 and CPU2
	GpioDataRegs.GPESET.all = uil_CPU1GPxSet
							| uil_CPU2GPxSet;
	GpioDataRegs.GPECLEAR.all = uil_CPU1GPxClear
								| uil_CPU2GPxClear;
	#elif (CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO E : Set Initial Value - CPU1
	GpioDataRegs.GPESET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPECLEAR.all = uil_CPU1GPxClear;
	#elif (CPU2_BOOT_ENABLE && CPU2_FLASH_BOOT)
	////// Initializing GPIO E : Set Initial Value - CPU1
	GpioDataRegs.GPESET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPECLEAR.all = uil_CPU1GPxClear;

	////// Initializing GPIO E : Set Initial Value - CPU2
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPESET.all)), uil_CPU2GPxSet);
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPECLEAR.all)), uil_CPU2GPxClear);
	#endif
#endif

#ifdef CPU2
	#if (!CPU2_FLASH_BOOT)
	////// Initializing GPIO E : Set Initial Value - CPU2
	GpioDataRegs.GPESET.all = uil_CPU2GPxSet;
	GpioDataRegs.GPECLEAR.all = uil_CPU2GPxClear;
	#endif
#endif

	// Initializing GPIO F
#ifdef CPU1
	//// Initializing GPIO F : Pin Function
	////// Initializing GPIO F : Pin Function - Group MUX
	GpioCtrlRegs.GPFGMUX1.all = GPFGMUX1_GPIO160_InOutGPIO				// GPIO160	;
							| GPFGMUX1_GPIO161_InOutGPIO				// GPIO161	;
							| GPFGMUX1_GPIO162_InOutGPIO				// GPIO162	;
							| GPFGMUX1_GPIO163_InOutGPIO				// GPIO163	;
							| GPFGMUX1_GPIO164_InOutGPIO				// GPIO164	;
							| GPFGMUX1_GPIO165_InOutGPIO				// GPIO165	;
							| GPFGMUX1_GPIO166_InOutGPIO				// GPIO166	;
							| GPFGMUX1_GPIO167_InOutGPIO				// GPIO167	;
							| GPFGMUX1_GPIO168_InOutGPIO;				// GPIO168	;

	////// Initializing GPIO F : Pin Function - MUX
	GpioCtrlRegs.GPFMUX1.all = GPFMUX1_GPIO160_InOutGPIO				// GPIO160	;
							| GPFMUX1_GPIO161_InOutGPIO					// GPIO161	;
							| GPFMUX1_GPIO162_InOutGPIO					// GPIO162	;
							| GPFMUX1_GPIO163_InOutGPIO					// GPIO163	;
							| GPFMUX1_GPIO164_InOutGPIO					// GPIO164	;
							| GPFMUX1_GPIO165_InOutGPIO					// GPIO165	;
							| GPFMUX1_GPIO166_InOutGPIO					// GPIO166	;
							| GPFMUX1_GPIO167_InOutGPIO					// GPIO167	;
							| GPFMUX1_GPIO168_InOutGPIO;				// GPIO168	;

	//// Initializing GPIO F : Pin Direction
	GpioCtrlRegs.GPFDIR.all = GPFDIR_GPIO160_Input						// GPIO160	;
							| GPFDIR_GPIO161_Input						// GPIO161	;
							| GPFDIR_GPIO162_Input						// GPIO162	;
							| GPFDIR_GPIO163_Input						// GPIO163	;
							| GPFDIR_GPIO164_Input						// GPIO164	;
							| GPFDIR_GPIO165_Output						// GPIO165	;
							| GPFDIR_GPIO166_Output						// GPIO166	;
							| GPFDIR_GPIO167_Input						// GPIO167	;
							| GPFDIR_GPIO168_Input;						// GPIO168	;

	//// Initializing GPIO F : Pull Up
	GpioCtrlRegs.GPFPUD.all = GPFPUD_GPIO160_PullUpDisable				// GPIO160	;
							| GPFPUD_GPIO161_PullUpDisable				// GPIO161	;
							| GPFPUD_GPIO162_PullUpDisable				// GPIO162	;
							| GPFPUD_GPIO163_PullUpDisable				// GPIO163	;
							| GPFPUD_GPIO164_PullUpDisable				// GPIO164	;
							| GPFPUD_GPIO165_PullUpDisable				// GPIO165	;
							| GPFPUD_GPIO166_PullUpDisable				// GPIO166	;
							| GPFPUD_GPIO167_PullUpDisable				// GPIO167	;
							| GPFPUD_GPIO168_PullUpDisable;				// GPIO168	;

	//// Initializing GPIO F : Open Drain
	GpioCtrlRegs.GPFODR.all = GPFODR_GPIO160_Normal						// GPIO160	;
							| GPFODR_GPIO161_Normal						// GPIO161	;
							| GPFODR_GPIO162_Normal						// GPIO162	;
							| GPFODR_GPIO163_Normal						// GPIO163	;
							| GPFODR_GPIO164_Normal						// GPIO164	;
							| GPFODR_GPIO165_Normal						// GPIO165	;
							| GPFODR_GPIO166_Normal						// GPIO166	;
							| GPFODR_GPIO167_Normal						// GPIO167	;
							| GPFODR_GPIO168_Normal;					// GPIO168	;

	//// Initializing GPIO F : Input Sampling Freq.
	GpioCtrlRegs.GPFCTRL.all = GPFCTRL_QUALPRD0_GPIO167to160_Value(0)	// QUALPRD0	; QUALPRDCLKx = PLLSYSCLK / (2 x QUALPRDx)
							| GPFCTRL_QUALPRD1_GPIO168(0);				// QUALPRD1	; 0(/1), 1(/2), 2(/4), 3(/6), ..., 253(/506), 254(/508), 255(/510).

	//// Initializing GPIO F : Input Sampling Mode
	GpioCtrlRegs.GPFQSEL1.all = GPFQSEL1_GPIO160_Asynch					// GPIO160	;
							| GPFQSEL1_GPIO161_Asynch					// GPIO161	;
							| GPFQSEL1_GPIO162_Asynch					// GPIO162	;
							| GPFQSEL1_GPIO163_Asynch					// GPIO163	;
							| GPFQSEL1_GPIO164_Asynch					// GPIO164	;
							| GPFQSEL1_GPIO165_Asynch					// GPIO165	;
							| GPFQSEL1_GPIO166_Asynch					// GPIO166	;
							| GPFQSEL1_GPIO167_Asynch					// GPIO167	;
							| GPFQSEL1_GPIO168_Asynch;					// GPIO168	;

	//// Initializing GPIO F : Input Polarity
	GpioCtrlRegs.GPFINV.all = GPFINV_GPIO160_InNormal					// GPIO160	;
							| GPFINV_GPIO161_InNormal					// GPIO161	;
							| GPFINV_GPIO162_InNormal					// GPIO162	;
							| GPFINV_GPIO163_InNormal					// GPIO163	;
							| GPFINV_GPIO164_InNormal					// GPIO164	;
							| GPFINV_GPIO165_InNormal					// GPIO165	;
							| GPFINV_GPIO166_InNormal					// GPIO166	;
							| GPFINV_GPIO167_InNormal					// GPIO167	;
							| GPFINV_GPIO168_InNormal;					// GPIO168	;

	//// Initializing GPIO F : Host Define
	#if (CPU2_BOOT_ENABLE)
	GpioCtrlRegs.GPFCSEL1.all = GPFCSEL1_GPIO160_CPU1Host				// GPIO160	;
							| GPFCSEL1_GPIO161_CPU1Host					// GPIO161	;
							| GPFCSEL1_GPIO162_CPU1Host					// GPIO162	;
							| GPFCSEL1_GPIO163_CPU1Host					// GPIO163	;
							| GPFCSEL1_GPIO164_CPU1Host					// GPIO164	;
							| GPFCSEL1_GPIO165_CPU1Host					// GPIO165	;
							| GPFCSEL1_GPIO166_CPU1Host					// GPIO166	;
							| GPFCSEL1_GPIO167_CPU1Host;				// GPIO167	;
	GpioCtrlRegs.GPFCSEL2.all = GPFCSEL2_GPIO168_CPU1Host;				// GPIO168	;
	#else
	GpioCtrlRegs.GPFCSEL1.all = GPFCSEL1_GPIOAll_CPU1Host;
	GpioCtrlRegs.GPFCSEL2.all = GPFCSEL2_GPIOAll_CPU1Host;
	#endif
#endif

	//// Initializing GPIO F : Initial Value
	////// Initializing GPIO F : Initial Value - CPU1
	uil_CPU1GPxSet = 0L;
	uil_CPU1GPxClear = 0L;

	////// Initializing GPIO F : Initial Value - CPU2
	uil_CPU2GPxSet = 0L;
	uil_CPU2GPxClear = 0L;

#ifdef CPU1
	#if (!CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO F : Set Initial Value - CPU1 and CPU2
	GpioDataRegs.GPFSET.all = uil_CPU1GPxSet
							| uil_CPU2GPxSet;
	GpioDataRegs.GPFCLEAR.all = uil_CPU1GPxClear
								| uil_CPU2GPxClear;
	#elif (CPU2_BOOT_ENABLE && !CPU2_FLASH_BOOT)
	////// Initializing GPIO F : Set Initial Value - CPU1
	GpioDataRegs.GPFSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPFCLEAR.all = uil_CPU1GPxClear;
	#elif (CPU2_BOOT_ENABLE && CPU2_FLASH_BOOT)
	////// Initializing GPIO F : Set Initial Value - CPU1
	GpioDataRegs.GPFSET.all = uil_CPU1GPxSet;
	GpioDataRegs.GPFCLEAR.all = uil_CPU1GPxClear;

	////// Initializing GPIO F : Set Initial Value - CPU2
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPFSET.all)), uil_CPU2GPxSet);
	IPCWrite32bitProtect((Uint32)(&(GpioDataRegs.GPFCLEAR.all)), uil_CPU2GPxClear);
	#endif
#endif

#ifdef CPU2
	#if (!CPU2_FLASH_BOOT)
	////// Initializing GPIO F : Set Initial Value - CPU2
	GpioDataRegs.GPFSET.all = uil_CPU2GPxSet;
	GpioDataRegs.GPFCLEAR.all = uil_CPU2GPxClear;
	#endif
#endif

	EDIS;

	return;
}
