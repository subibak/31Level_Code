/*
 * F2837xD_Headers_nonBIOS.cmd
 *
 *   Edited on: 2018. 3. 29.
 *      Author: TI Co.
 *		Editor: HJHeo
 * 	 Revised on: 2018.09.27
 		Revisor: subi
 */

MEMORY
{
PAGE 0:																				// Program Memory

PAGE 1:																				// Data Memory
	ADCA_RESULT					: org = 0x000B00, len = 0x000020						// ADC-A Result Register
	ADCB_RESULT					: org = 0x000B20, len = 0x000020						// ADC-B Result Register
	ADCC_RESULT					: org = 0x000B40, len = 0x000020						// ADC-C Result Register
	ADCD_RESULT					: org = 0x000B60, len = 0x000020						// ADC-D Result Register

	CPUx_TIMER0					: org = 0x000C00, len = 0x000008						// CPU Timer 0 Register of CPUx, For User Application.
	CPUx_TIMER1					: org = 0x000C08, len = 0x000008						// CPU Timer 1 Register of CPUx, For User Application.
	CPUx_TIMER2					: org = 0x000C10, len = 0x000008						// CPU Timer 2 Register of CPUx, For Operating System. If OS is not Used, It can be also Used for User Application.

	CPUx_PIE_CTRL				: org = 0x000CE0, len = 0x000020						// PIE Control Register of CPUx
	CPUx_PIE_VECT				: org = 0x000D00, len = 0x000200						// PIE Vector Table of CPUx

	CPUx_DMA					: org = 0x001000, len = 0x000200						// DMA Register of CPUx
	CPUx_CLA1					: org = 0x001400, len = 0x000040						// CLA1 Register of CPUx

	EPWM1						: org = 0x004000, len = 0x000100						// Enhanced PWM 1 Register
	EPWM2						: org = 0x004100, len = 0x000100						// Enhanced PWM 2 Register
	EPWM3						: org = 0x004200, len = 0x000100						// Enhanced PWM 3 Register
	EPWM4						: org = 0x004300, len = 0x000100						// Enhanced PWM 4 Register
	EPWM5						: org = 0x004400, len = 0x000100						// Enhanced PWM 5 Register
	EPWM6						: org = 0x004500, len = 0x000100						// Enhanced PWM 6 Register
	EPWM7						: org = 0x004600, len = 0x000100						// Enhanced PWM 7 Register
	EPWM8						: org = 0x004700, len = 0x000100						// Enhanced PWM 8 Register
	EPWM9						: org = 0x004800, len = 0x000100						// Enhanced PWM 9 Register
	EPWM10						: org = 0x004900, len = 0x000100						// Enhanced PWM 10 Register
	EPWM11						: org = 0x004A00, len = 0x000100						// Enhanced PWM 11 Register
	EPWM12						: org = 0x004B00, len = 0x000100						// Enhanced PWM 12 Register

	ECAP1						: org = 0x005000, len = 0x000020						// Enhanced Capture 1 Register
	ECAP2						: org = 0x005020, len = 0x000020						// Enhanced Capture 2 Register
	ECAP3						: org = 0x005040, len = 0x000020						// Enhanced Capture 3 Register
	ECAP4						: org = 0x005060, len = 0x000020						// Enhanced Capture 4 Register
	ECAP5						: org = 0x005080, len = 0x000020						// Enhanced Capture 5 Register
	ECAP6						: org = 0x0050A0, len = 0x000020						// Enhanced Capture 6 Register

	EQEP1						: org = 0x005100, len = 0x000040						// Enhanced QEP 1 Register
	EQEP2						: org = 0x005140, len = 0x000040						// Enhanced QEP 2 Register
	EQEP3						: org = 0x005180, len = 0x000040						// Enhanced QEP 3 Register

	DACA						: org = 0x005C00, len = 0x000010						// DAC-A Register
	DACB						: org = 0x005C10, len = 0x000010						// DAC-B Register
	DACC						: org = 0x005C20, len = 0x000010						// DAC-C Register

	CMPSS1						: org = 0x005C80, len = 0x000020						// Compare Sub-System 1 Register
	CMPSS2						: org = 0x005CA0, len = 0x000020						// Compare Sub-System 2 Register
	CMPSS3						: org = 0x005CC0, len = 0x000020						// Compare Sub-System 3 Register
	CMPSS4						: org = 0x005CE0, len = 0x000020						// Compare Sub-System 4 Register
	CMPSS5						: org = 0x005D00, len = 0x000020						// Compare Sub-System 5 Register
	CMPSS6						: org = 0x005D20, len = 0x000020						// Compare Sub-System 6 Register
	CMPSS7						: org = 0x005D40, len = 0x000020						// Compare Sub-System 7 Register
	CMPSS8						: org = 0x005D60, len = 0x000020						// Compare Sub-System 8 Register

	SDFM1						: org = 0x005E00, len = 0x000080						// Sigma-Delta Filter Module 1 Register
	SDFM2						: org = 0x005E80, len = 0x000080						// Sigma-Delta Filter Module 2 Register

	MCBSPA						: org = 0x006000, len = 0x000040						// MCBSP-A Register
	MCBSPB						: org = 0x006040, len = 0x000040						// MCBSP-B Register

	SPIA						: org = 0x006100, len = 0x000010						// SPI-A Register
	SPIB						: org = 0x006110, len = 0x000010						// SPI-B Register
	SPIC						: org = 0x006120, len = 0x000010						// SPI-C Register

	CPU1_UPP					: org = 0x006200, len = 0x000100						// uPP Register. Only CPU1 Reachable.

	CPUx_WD						: org = 0x007000, len = 0x000040						// WatchDog Register of CPUx.
	CPUx_NMIINTRUPT				: org = 0x007060, len = 0x000010						// Non-Maskable Interrupt Register of CPUx.
	CPUx_XINT					: org = 0x007070, len = 0x000010						// External Interrupt Register of CPUx.

	SCIA						: org = 0x007200, len = 0x000010						// SCI-A Register
	SCIB						: org = 0x007210, len = 0x000010						// SCI-B Register
	SCIC						: org = 0x007220, len = 0x000010						// SCI-C Register
	SCID						: org = 0x007230, len = 0x000010						// SCI-D Register

	I2CA						: org = 0x007300, len = 0x000040						// I2C-A Register
	I2CB						: org = 0x007340, len = 0x000040						// I2C-B Register

	ADCA						: org = 0x007400, len = 0x000080						// ADC-A Register
	ADCB						: org = 0x007480, len = 0x000080						// ADC-B Register
	ADCC						: org = 0x007500, len = 0x000080						// ADC-C Register
	ADCD						: org = 0x007580, len = 0x000080						// ADC-D Register

	CPU1_INPUT_XBAR				: org = 0x007900, len = 0x000020						// Input X-BAR Register. Only CPU1 Reachable.
	CPU1_XBAR					: org = 0x007920, len = 0x000020						// X-BAR Register. Only CPU1 Reachable.
	CPU1_SYNC_SOC				: org = 0x007940, len = 0x000010						// Syncronous and Start of Conversion Register. Only CPU1 Reachable.

	CPUx_DMACLASRCSEL			: org = 0x007980, len = 0x000040						// DMA/CLA Trigger Source Selection Register of CPUx.

	CPU1_EPWM_XBAR				: org = 0x007A00, len = 0x000040						// Enhanced PWM X-BAR Register. Only CPU1 Reachable.
	CPU1_OUTPUT_XBAR			: org = 0x007A80, len = 0x000040						// Output X-BAR Register. Only CPU1 Reachable.

	CPU1_GPIOCTRL				: org = 0x007C00, len = 0x000180						// GPIO Control Register. Only CPU1 Reachable.
	CPUx_GPIODATA				: org = 0x007F00, len = 0x000030						// GPIO Data Register. Only CPU1 Reachable.

	CPU1_USBA					: org = 0x040000, len = 0x001000						// USB Register. Only CPU1 Reachable.

	EMIF1						: org = 0x047000, len = 0x000800						// External Memory Interface 1 Register.
	CPU1_EMIF2					: org = 0x047800, len = 0x000800						// External Memory Interface 2 Register. Only CPU1 Reachable.

	CPUx_IPC					: org = 0x050000, len = 0x000024						// Interprocessor Communication Module Register of CPUx.
	CPUx_FLASHPUMPSEMAPHORE		: org = 0x050024, len = 0x000002						// Flash Pump Semaphore Register of CPUx.

	CPU1_DEV_CFG				: org = 0x05D000, len = 0x000180						// Device Configure Register. Only CPU1 Reachable.
	CPU1_ANALOG_SUBSYS			: org = 0x05D180, len = 0x000080						// Analog Sub-System Register. Only CPU1 Reachable.

	CLK_CFG						: org = 0x05D200, len = 0x000100						// Clock Cofigure Register. CPU1 and CPU2 Share the Register Based on a Semaphore.

	CPUx_CPU_SYS				: org = 0x05D300, len = 0x000100						// CPU System Register of CPUx.

	CPU1_ROMPREFETCH			: org = 0x05E608, len = 0x000002						// ROM Prefetch Register. Only CPU1 Reachable.

	CPUx_DCSM_Z1				: org = 0x05F000, len = 0x000030						// Zone 1 Dual Code Security Module Register of CPUx.
	CPUx_DCSM_Z2				: org = 0x05F040, len = 0x000030						// Zone 2 Dual Code Security Module Register of CPUx.
	CPUx_DCSM_COMMON			: org = 0x05F070, len = 0x000010						// Common Dual Code Security Module Register of CPUx.
	CPUx_MEMCFG					: org = 0x05F400, len = 0x000080						// Memory Configure Register of CPUx.

	CPUx_EMIF1CONFIG			: org = 0x05F480, len = 0x000020						// External Memory Interface 1 Configure Register of CPUx.
	CPU1_EMIF2CONFIG			: org = 0x05F4A0, len = 0x000020						// External Memory Interface 2 Configure Register. Only CPU1 Reachable.

	CPUx_ACCESSPROTECTION		: org = 0x05F4C0, len = 0x000040						// Access Protection Register of CPUx.
	CPUx_MEMORYERROR			: org = 0x05F500, len = 0x000040						// Memory Error Register of CPUx.

	CPU1_ROMWAITSTATE			: org = 0x05F540, len = 0x000002						// ROM Configure Register. Only CPU1 Reachable.

	CPUx_FLASH0_CTRL			: org = 0x05F800, len = 0x000300						// Flash ROM 1 Control Register of CPUx.
	CPUx_FLASH0_ECC				: org = 0x05FB00, len = 0x000040						// Flash ROM 1 Error Correction Code Register of CPUx.

	CPUx_DCSM_Z1_OTP			: org = 0x078000, len = 0x000020						// Part of Z1 OTP. LinkerPointer/JTAG Lock/Boot Mode of CPUx.
	CPUx_DCSM_Z2_OTP			: org = 0x078200, len = 0x000020						// Part of Z2 OTP. LinkerPointer/JTAG Lock.

	IPC_CPU2TO1_TEMP			: org = 0x03F800, len = 0x000018		//
	IPC_CPU2TO1_EtherCAT		: org = 0x03F818, len = 0x0003E8		//

	IPC_CPU1TO2_TEMP			: org = 0x03FC00, len = 0x000018		//
	IPC_CPU1TO2_EtherCAT		: org = 0x03FC18, len = 0x0003E8		//
}

SECTIONS
{
	AdcaResultFile				:> ADCA_RESULT, 			PAGE = 1
	AdcbResultFile				:> ADCB_RESULT, 			PAGE = 1
	AdccResultFile				:> ADCC_RESULT, 			PAGE = 1
	AdcdResultFile				:> ADCD_RESULT, 			PAGE = 1

	CpuTimer0RegsFile			:> CPUx_TIMER0,				PAGE = 1
	CpuTimer1RegsFile			:> CPUx_TIMER1,				PAGE = 1
	CpuTimer2RegsFile			:> CPUx_TIMER2,				PAGE = 1

	PieCtrlRegsFile				:> CPUx_PIE_CTRL,			PAGE = 1
	Cla1SoftIntRegsFile			:> CPUx_PIE_CTRL,			PAGE = 1, TYPE = DSECT		// Only CLA1 Reachable. CPU Uses this Address for PieCtrlRegs.

	// PIE VECT Table and Boot ROM Variables Structures //
	UNION RUN = CPUx_PIE_VECT, PAGE = 1
	{
		PieVectTableFile
		GROUP
		{
			EmuKeyVar
			EmuBModeVar
			FlashCallbackVar
			FlashScalingVar
		}
	}

	DmaRegsFile					:> CPUx_DMA,				PAGE = 1
	Cla1RegsFile				:> CPUx_CLA1,				PAGE = 1

	EPwm1RegsFile				:> EPWM1,					PAGE = 1
	EPwm2RegsFile				:> EPWM2,					PAGE = 1
	EPwm3RegsFile				:> EPWM3,					PAGE = 1
	EPwm4RegsFile				:> EPWM4,					PAGE = 1
	EPwm5RegsFile				:> EPWM5,					PAGE = 1
	EPwm6RegsFile				:> EPWM6,					PAGE = 1
	EPwm7RegsFile				:> EPWM7,					PAGE = 1
	EPwm8RegsFile				:> EPWM8,					PAGE = 1
	EPwm9RegsFile				:> EPWM9,					PAGE = 1
	EPwm10RegsFile				:> EPWM10,					PAGE = 1
	EPwm11RegsFile				:> EPWM11,					PAGE = 1
	EPwm12RegsFile				:> EPWM12,					PAGE = 1

	ECap1RegsFile				:> ECAP1,					PAGE = 1
	ECap2RegsFile				:> ECAP2,					PAGE = 1
	ECap3RegsFile				:> ECAP3,					PAGE = 1
	ECap4RegsFile				:> ECAP4,					PAGE = 1
	ECap5RegsFile				:> ECAP5,					PAGE = 1
	ECap6RegsFile				:> ECAP6,					PAGE = 1

	EQep1RegsFile				:> EQEP1,					PAGE = 1
	EQep2RegsFile				:> EQEP2,					PAGE = 1
	EQep3RegsFile				:> EQEP3,					PAGE = 1

	DacaRegsFile				:> DACA,					PAGE = 1
	DacbRegsFile				:> DACB,					PAGE = 1
	DaccRegsFile				:> DACC,					PAGE = 1

	Cmpss1RegsFile				:> CMPSS1,					PAGE = 1
	Cmpss2RegsFile				:> CMPSS2,					PAGE = 1
	Cmpss3RegsFile				:> CMPSS3,					PAGE = 1
	Cmpss4RegsFile				:> CMPSS4,					PAGE = 1
	Cmpss5RegsFile				:> CMPSS5,					PAGE = 1
	Cmpss6RegsFile				:> CMPSS6,					PAGE = 1
	Cmpss7RegsFile				:> CMPSS7,					PAGE = 1
	Cmpss8RegsFile				:> CMPSS8,					PAGE = 1

	Sdfm1RegsFile				:> SDFM1,					PAGE = 1
	Sdfm2RegsFile				:> SDFM2,					PAGE = 1

	McbspaRegsFile				:> MCBSPA,					PAGE = 1
	McbspbRegsFile				:> MCBSPB,					PAGE = 1

	SpiaRegsFile				:> SPIA,					PAGE = 1
	SpibRegsFile				:> SPIB,					PAGE = 1
	SpicRegsFile				:> SPIC,					PAGE = 1

	UppRegsFile					:> CPU1_UPP					PAGE = 1

	WdRegsFile					:> CPUx_WD					PAGE = 1
	NmiIntruptRegsFile			:> CPUx_NMIINTRUPT,			PAGE = 1
	XintRegsFile				:> CPUx_XINT,				PAGE = 1

	SciaRegsFile				:> SCIA,					PAGE = 1
	ScibRegsFile				:> SCIB,					PAGE = 1
	ScicRegsFile				:> SCIC,					PAGE = 1
	ScidRegsFile				:> SCID,					PAGE = 1

	I2caRegsFile				:> I2CA,					PAGE = 1
	I2cbRegsFile				:> I2CB,					PAGE = 1

	AdcaRegsFile				:> ADCA,					PAGE = 1
	AdcbRegsFile				:> ADCB,					PAGE = 1
	AdccRegsFile				:> ADCC,					PAGE = 1
	AdcdRegsFile				:> ADCD,					PAGE = 1

	InputXbarRegsFile			:> CPU1_INPUT_XBAR,			PAGE = 1
	XbarRegsFile				:> CPU1_XBAR,				PAGE = 1
	SyncSocRegsFile				:> CPU1_SYNC_SOC,			PAGE = 1

	DmaClaSrcSelRegsFile		:> CPUx_DMACLASRCSEL,		PAGE = 1

	EPwmXbarRegsFile			:> CPU1_EPWM_XBAR,			PAGE = 1
	OutputXbarRegsFile			:> CPU1_OUTPUT_XBAR,		PAGE = 1

	GpioCtrlRegsFile			:> CPU1_GPIOCTRL,			PAGE = 1
	GpioDataRegsFile			:> CPUx_GPIODATA,			PAGE = 1

//	UsbaRegsFile				:> CPU1_USBA,				PAGE = 1

	Emif1RegsFile				:> EMIF1,					PAGE = 1
	Emif2RegsFile				:> CPU1_EMIF2,				PAGE = 1

	IpcRegsFile					:> CPUx_IPC,				PAGE = 1
	FlashPumpSemaphoreRegsFile	:> CPUx_FLASHPUMPSEMAPHORE,	PAGE = 1

	DevCfgRegsFile				:> CPU1_DEV_CFG,			PAGE = 1
	AnalogSubsysRegsFile		:> CPU1_ANALOG_SUBSYS,		PAGE = 1

	ClkCfgRegsFile				:> CLK_CFG,					PAGE = 1

	CpuSysRegsFile				:> CPUx_CPU_SYS,			PAGE = 1

	RomPrefetchRegsFile			:> CPU1_ROMPREFETCH,		PAGE = 1

	DcsmZ1RegsFile				:> CPUx_DCSM_Z1,			PAGE = 1
	DcsmZ2RegsFile				:> CPUx_DCSM_Z2,			PAGE = 1
	DcsmCommonRegsFile			:> CPUx_DCSM_COMMON,		PAGE = 1
	MemCfgRegsFile				:> CPUx_MEMCFG,				PAGE = 1

	Emif1ConfigRegsFile			:> CPUx_EMIF1CONFIG,		PAGE = 1
	Emif2ConfigRegsFile			:> CPU1_EMIF2CONFIG,		PAGE = 1

	AccessProtectionRegsFile	:> CPUx_ACCESSPROTECTION,	PAGE = 1
	MemoryErrorRegsFile			:> CPUx_MEMORYERROR,		PAGE = 1

	RomWaitStateRegsFile		:> CPU1_ROMWAITSTATE,		PAGE = 1

	Flash0CtrlRegsFile			:> CPUx_FLASH0_CTRL,		PAGE = 1
	Flash0EccRegsFile			:> CPUx_FLASH0_ECC,			PAGE = 1

	// Warning: Only Remove "TYPE = NOLOAD" to Program OTP Locations //
	DcsmZ1OtpFile				:> CPUx_DCSM_Z1_OTP,		PAGE = 1, TYPE = NOLOAD
	DcsmZ2OtpFile				:> CPUx_DCSM_Z2_OTP,		PAGE = 1, TYPE = NOLOAD

	IpcTempVolFile				:> IPC_CPU2TO1_TEMP			PAGE = 1
	IpcEcatSlaveFile			:> IPC_CPU2TO1_EtherCAT		PAGE = 1

	IpcTempCalFile				:> IPC_CPU1TO2_TEMP			PAGE = 1
	IpcEcatMasterFile			:> IPC_CPU1TO2_EtherCAT		PAGE = 1
}
