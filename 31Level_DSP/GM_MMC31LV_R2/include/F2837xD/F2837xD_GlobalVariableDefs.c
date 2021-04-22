//###########################################################################
//
// FILE:    F2837xD_GlobalVariableDefs.c
//
// TITLE:   F2837xD Global Variables and Data Section Pragmas.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 $
// $Release Date: Tue Nov  1 14:46:15 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################
//
// Edited by: HJHeo

#include "F2837xD_device.h"

// Define Common Global Peripheral Variables:
//----------------------------------------
#pragma DATA_SECTION(AdcaResultRegs,"AdcaResultFile");
volatile struct ADC_RESULT_REGS AdcaResultRegs;

//----------------------------------------
#pragma DATA_SECTION(AdcbResultRegs,"AdcbResultFile");
volatile struct ADC_RESULT_REGS AdcbResultRegs;

//----------------------------------------
#pragma DATA_SECTION(AdccResultRegs,"AdccResultFile");
volatile struct ADC_RESULT_REGS AdccResultRegs;

//----------------------------------------
#pragma DATA_SECTION(AdcdResultRegs,"AdcdResultFile");
volatile struct ADC_RESULT_REGS AdcdResultRegs;

//----------------------------------------
#pragma DATA_SECTION(Cla1SoftIntRegs,"Cla1SoftIntRegsFile");
volatile struct CLA_SOFTINT_REGS Cla1SoftIntRegs;

//----------------------------------------
#pragma DATA_SECTION(EPwm1Regs,"EPwm1RegsFile");
volatile struct EPWM_REGS EPwm1Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm2Regs,"EPwm2RegsFile");
volatile struct EPWM_REGS EPwm2Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm3Regs,"EPwm3RegsFile");
volatile struct EPWM_REGS EPwm3Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm4Regs,"EPwm4RegsFile");
volatile struct EPWM_REGS EPwm4Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm5Regs,"EPwm5RegsFile");
volatile struct EPWM_REGS EPwm5Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm6Regs,"EPwm6RegsFile");
volatile struct EPWM_REGS EPwm6Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm7Regs,"EPwm7RegsFile");
volatile struct EPWM_REGS EPwm7Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm8Regs,"EPwm8RegsFile");
volatile struct EPWM_REGS EPwm8Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm9Regs,"EPwm9RegsFile");
volatile struct EPWM_REGS EPwm9Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm10Regs,"EPwm10RegsFile");
volatile struct EPWM_REGS EPwm10Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm11Regs,"EPwm11RegsFile");
volatile struct EPWM_REGS EPwm11Regs;

//----------------------------------------
#pragma DATA_SECTION(EPwm12Regs,"EPwm12RegsFile");
volatile struct EPWM_REGS EPwm12Regs;

//----------------------------------------
#pragma DATA_SECTION(ECap1Regs,"ECap1RegsFile");
volatile struct ECAP_REGS ECap1Regs;

//----------------------------------------
#pragma DATA_SECTION(ECap2Regs,"ECap2RegsFile");
volatile struct ECAP_REGS ECap2Regs;

//----------------------------------------
#pragma DATA_SECTION(ECap3Regs,"ECap3RegsFile");
volatile struct ECAP_REGS ECap3Regs;

//----------------------------------------
#pragma DATA_SECTION(ECap4Regs,"ECap4RegsFile");
volatile struct ECAP_REGS ECap4Regs;

//----------------------------------------
#pragma DATA_SECTION(ECap5Regs,"ECap5RegsFile");
volatile struct ECAP_REGS ECap5Regs;

//----------------------------------------
#pragma DATA_SECTION(ECap6Regs,"ECap6RegsFile");
volatile struct ECAP_REGS ECap6Regs;

//----------------------------------------
#pragma DATA_SECTION(EQep1Regs,"EQep1RegsFile");
volatile struct EQEP_REGS EQep1Regs;

//----------------------------------------
#pragma DATA_SECTION(EQep2Regs,"EQep2RegsFile");
volatile struct EQEP_REGS EQep2Regs;

//----------------------------------------
#pragma DATA_SECTION(EQep3Regs,"EQep3RegsFile");
volatile struct EQEP_REGS EQep3Regs;

//----------------------------------------
#pragma DATA_SECTION(DacaRegs,"DacaRegsFile");
volatile struct DAC_REGS DacaRegs;

//----------------------------------------
#pragma DATA_SECTION(DacbRegs,"DacbRegsFile");
volatile struct DAC_REGS DacbRegs;

//----------------------------------------
#pragma DATA_SECTION(DaccRegs,"DaccRegsFile");
volatile struct DAC_REGS DaccRegs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss1Regs,"Cmpss1RegsFile");
volatile struct CMPSS_REGS Cmpss1Regs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss2Regs,"Cmpss2RegsFile");
volatile struct CMPSS_REGS Cmpss2Regs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss3Regs,"Cmpss3RegsFile");
volatile struct CMPSS_REGS Cmpss3Regs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss4Regs,"Cmpss4RegsFile");
volatile struct CMPSS_REGS Cmpss4Regs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss5Regs,"Cmpss5RegsFile");
volatile struct CMPSS_REGS Cmpss5Regs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss6Regs,"Cmpss6RegsFile");
volatile struct CMPSS_REGS Cmpss6Regs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss7Regs,"Cmpss7RegsFile");
volatile struct CMPSS_REGS Cmpss7Regs;

//----------------------------------------
#pragma DATA_SECTION(Cmpss8Regs,"Cmpss8RegsFile");
volatile struct CMPSS_REGS Cmpss8Regs;

//----------------------------------------
#pragma DATA_SECTION(Sdfm1Regs,"Sdfm1RegsFile");
volatile struct SDFM_REGS Sdfm1Regs;

//----------------------------------------
#pragma DATA_SECTION(Sdfm2Regs,"Sdfm2RegsFile");
volatile struct SDFM_REGS Sdfm2Regs;

//----------------------------------------
#pragma DATA_SECTION(McbspaRegs,"McbspaRegsFile");
volatile struct McBSP_REGS McbspaRegs;

//----------------------------------------
#pragma DATA_SECTION(McbspbRegs,"McbspbRegsFile");
volatile struct McBSP_REGS McbspbRegs;

//----------------------------------------
#pragma DATA_SECTION(SpiaRegs,"SpiaRegsFile");
volatile struct SPI_REGS SpiaRegs;

//----------------------------------------
#pragma DATA_SECTION(SpibRegs,"SpibRegsFile");
volatile struct SPI_REGS SpibRegs;

//----------------------------------------
#pragma DATA_SECTION(SpicRegs,"SpicRegsFile");
volatile struct SPI_REGS SpicRegs;

//----------------------------------------
#pragma DATA_SECTION(SciaRegs,"SciaRegsFile");
volatile struct SCI_REGS SciaRegs;

//----------------------------------------
#pragma DATA_SECTION(ScibRegs,"ScibRegsFile");
volatile struct SCI_REGS ScibRegs;

//----------------------------------------
#pragma DATA_SECTION(ScicRegs,"ScicRegsFile");
volatile struct SCI_REGS ScicRegs;

//----------------------------------------
#pragma DATA_SECTION(ScidRegs,"ScidRegsFile");
volatile struct SCI_REGS ScidRegs;

//----------------------------------------
#pragma DATA_SECTION(I2caRegs,"I2caRegsFile");
volatile struct I2C_REGS I2caRegs;

//----------------------------------------
#pragma DATA_SECTION(I2cbRegs,"I2cbRegsFile");
volatile struct I2C_REGS I2cbRegs;

//----------------------------------------
#pragma DATA_SECTION(AdcaRegs,"AdcaRegsFile");
volatile struct ADC_REGS AdcaRegs;

#pragma DATA_SECTION(AdcbRegs,"AdcbRegsFile");
volatile struct ADC_REGS AdcbRegs;

#pragma DATA_SECTION(AdccRegs,"AdccRegsFile");
volatile struct ADC_REGS AdccRegs;

#pragma DATA_SECTION(AdcdRegs,"AdcdRegsFile");
volatile struct ADC_REGS AdcdRegs;

//----------------------------------------
#pragma DATA_SECTION(Emif1Regs,"Emif1RegsFile");
volatile struct EMIF_REGS  Emif1Regs;

// Define Common Global Peripheral Variables (Based On Semaphore):
//----------------------------------------
#pragma DATA_SECTION(ClkCfgRegs,"ClkCfgRegsFile");
volatile struct CLK_CFG_REGS ClkCfgRegs;


// Define CPUx Global Variables (CPU1 and CPU2 Registers are Same):
//----------------------------------------
#pragma DATA_SECTION(CpuTimer0Regs,"CpuTimer0RegsFile");
volatile struct CPUTIMER_REGS CpuTimer0Regs;

//----------------------------------------
#pragma DATA_SECTION(CpuTimer1Regs,"CpuTimer1RegsFile");
volatile struct CPUTIMER_REGS CpuTimer1Regs;

//----------------------------------------
#pragma DATA_SECTION(CpuTimer2Regs,"CpuTimer2RegsFile");
volatile struct CPUTIMER_REGS CpuTimer2Regs;

//----------------------------------------
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");
volatile struct PIE_CTRL_REGS PieCtrlRegs;

//----------------------------------------
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");
volatile struct PIE_VECT_TABLE PieVectTable;

//--------------------------------------
#pragma DATA_SECTION(EmuKey,"EmuKeyVar");
Uint16 EmuKey;

//----------------------------------------
#pragma DATA_SECTION(EmuBMode,"EmuBModeVar");
Uint16 EmuBMode;

//----------------------------------------
#pragma DATA_SECTION(DmaRegs,"DmaRegsFile");
volatile struct DMA_REGS DmaRegs;

//----------------------------------------
#pragma DATA_SECTION(Cla1Regs,"Cla1RegsFile");
volatile struct CLA_REGS Cla1Regs;

//----------------------------------------
#pragma DATA_SECTION(WdRegs,"WdRegsFile");
volatile struct WD_REGS WdRegs;

//----------------------------------------
#pragma DATA_SECTION(NmiIntruptRegs,"NmiIntruptRegsFile");
volatile struct NMI_INTRUPT_REGS NmiIntruptRegs;

//----------------------------------------
#pragma DATA_SECTION(XintRegs,"XintRegsFile");
volatile struct XINT_REGS XintRegs;

//----------------------------------------
#pragma DATA_SECTION(DmaClaSrcSelRegs,"DmaClaSrcSelRegsFile");
volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;

//----------------------------------------
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
volatile struct GPIO_DATA_REGS GpioDataRegs;

//----------------------------------------
#pragma DATA_SECTION(CpuSysRegs,"CpuSysRegsFile");
volatile struct CPU_SYS_REGS CpuSysRegs;

//----------------------------------------
#pragma DATA_SECTION(DcsmZ1Regs,"DcsmZ1RegsFile");
volatile struct DCSM_Z1_REGS DcsmZ1Regs;

//----------------------------------------
#pragma DATA_SECTION(DcsmZ2Regs,"DcsmZ2RegsFile");
volatile struct DCSM_Z2_REGS DcsmZ2Regs;

//----------------------------------------
#pragma DATA_SECTION(DcsmCommonRegs,"DcsmCommonRegsFile");
volatile struct DCSM_COMMON_REGS DcsmCommonRegs;

//----------------------------------------
#pragma DATA_SECTION(MemCfgRegs,"MemCfgRegsFile");
volatile struct MEM_CFG_REGS MemCfgRegs;

//----------------------------------------
#pragma DATA_SECTION(Emif1ConfigRegs,"Emif1ConfigRegsFile");
volatile struct EMIF1_CONFIG_REGS Emif1ConfigRegs;

//----------------------------------------
#pragma DATA_SECTION(AccessProtectionRegs,"AccessProtectionRegsFile");
volatile struct ACCESS_PROTECTION_REGS AccessProtectionRegs;

//----------------------------------------
#pragma DATA_SECTION(MemoryErrorRegs,"MemoryErrorRegsFile");
volatile struct MEMORY_ERROR_REGS MemoryErrorRegs;

//----------------------------------------
#pragma DATA_SECTION(Flash0CtrlRegs,"Flash0CtrlRegsFile");
volatile struct FLASH_CTRL_REGS Flash0CtrlRegs;

//----------------------------------------
#pragma DATA_SECTION(Flash0EccRegs,"Flash0EccRegsFile");
volatile struct FLASH_ECC_REGS Flash0EccRegs;

//----------------------------------------
#pragma DATA_SECTION(DcsmZ1Otp,"DcsmZ1OtpFile");
volatile struct DCSM_Z1_OTP DcsmZ1Otp;

//----------------------------------------
#pragma DATA_SECTION(DcsmZ2Otp,"DcsmZ2OtpFile");
volatile struct DCSM_Z2_OTP DcsmZ2Otp;


// Define CPUx Global Variables (CPU1 and CPU2 Registers are Different):
#ifdef CPU1
//----------------------------------------
#pragma DATA_SECTION(IpcRegs,"IpcRegsFile");
volatile struct IPC_REGS_CPU1 IpcRegs;

//----------------------------------------
#pragma DATA_SECTION(FlashPumpSemaphoreRegs,"FlashPumpSemaphoreRegsFile");
volatile struct FLASH_PUMP_SEMAPHORE_REGS FlashPumpSemaphoreRegs;

#endif

#ifdef CPU2
//----------------------------------------
#pragma DATA_SECTION(IpcRegs,"IpcRegsFile");
volatile struct IPC_REGS_CPU2 IpcRegs;

//----------------------------------------
#pragma DATA_SECTION(FlashPumpSemaphoreRegs,"FlashPumpSemaphoreRegsFile");
volatile struct FLASH_PUMP_SEMAPHORE_REGS FlashPumpSemaphoreRegs;

#endif


// Define CPU1 Global Variables:
#ifdef CPU1
//----------------------------------------
#pragma DATA_SECTION(UppRegs,"UppRegsFile");
volatile struct UPP_REGS UppRegs;

//----------------------------------------
#pragma DATA_SECTION(InputXbarRegs,"InputXbarRegsFile");
volatile struct INPUT_XBAR_REGS InputXbarRegs;

//----------------------------------------
#pragma DATA_SECTION(XbarRegs,"XbarRegsFile");
volatile struct XBAR_REGS XbarRegs;

//----------------------------------------
#pragma DATA_SECTION(SyncSocRegs,"SyncSocRegsFile");
volatile struct SYNC_SOC_REGS SyncSocRegs;

//----------------------------------------
#pragma DATA_SECTION(EPwmXbarRegs,"EPwmXbarRegsFile");
volatile struct EPWM_XBAR_REGS EPwmXbarRegs;

//----------------------------------------
#pragma DATA_SECTION(OutputXbarRegs,"OutputXbarRegsFile");
volatile struct OUTPUT_XBAR_REGS OutputXbarRegs;

//----------------------------------------
#pragma DATA_SECTION(GpioCtrlRegs,"GpioCtrlRegsFile");
volatile struct GPIO_CTRL_REGS GpioCtrlRegs;

//----------------------------------------
//#ifdef __cplusplus
//
//#else
//
//#endif
// !!!!!!!!!! Register About USB !!!!!!!!!!

//----------------------------------------
#pragma DATA_SECTION(Emif2Regs,"Emif2RegsFile");
volatile struct EMIF_REGS  Emif2Regs;

//----------------------------------------
#pragma DATA_SECTION(DevCfgRegs,"DevCfgRegsFile");
volatile struct DEV_CFG_REGS DevCfgRegs;

//----------------------------------------
#pragma DATA_SECTION(AnalogSubsysRegs,"AnalogSubsysRegsFile");
volatile struct ANALOG_SUBSYS_REGS AnalogSubsysRegs;

//----------------------------------------
#pragma DATA_SECTION(RomPrefetchRegs,"RomPrefetchRegsFile");
volatile struct ROM_PREFETCH_REGS RomPrefetchRegs;

//----------------------------------------
#pragma DATA_SECTION(Emif2ConfigRegs,"Emif2ConfigRegsFile");
volatile struct EMIF2_CONFIG_REGS Emif2ConfigRegs;

#pragma DATA_SECTION(RomWaitStateRegs,"RomWaitStateRegsFile");
volatile struct ROM_WAIT_STATE_REGS RomWaitStateRegs;

#endif

//----------------------------------------
#pragma DATA_SECTION(IPC_Temp_Vol,"IpcTempVolFile");
IPC_MSG    IPC_Temp_Vol[12];
//----------------------------------------
#pragma DATA_SECTION(IPC_Temp_Cal,"IpcTempCalFile");
IPC_MSG    IPC_Temp_Cal[12];

//----------------------------------------
#pragma DATA_SECTION(IpcDspEcatSlave,"IpcEcatSlaveFile");
volatile struct IPC_EtherCAT_Slave_DATA   IpcDspEcatSlave;
//----------------------------------------
#pragma DATA_SECTION(IpcDspEcatMaster,"IpcEcatMasterFile");
volatile struct IPC_EtherCAT_Master_DATA  IpcDspEcatMaster;
//----------------------------------------

//#ifdef CPU1
//
//#pragma DATA_SECTION(IPCCPU1toCPU2Buffers, "PUTBUFFER");
//
//#pragma DATA_SECTION(PutWriteIndexes, "PUTWRITEIDX");
//
//#pragma DATA_SECTION(GetReadIndexes, "GETREADIDX");
//
//#pragma DATA_SECTION(IPCCPU2toCPU1Buffers, "GETBUFFER");
//
//#pragma DATA_SECTION(GetWriteIndexes, "GETWRITEIDX");
//
//#pragma DATA_SECTION(PutReadIndexes, "PUTREADIDX");
//
//#endif
//
//#ifdef CPU2
//
//#pragma DATA_SECTION(IPCCPU2toCPU1Buffers, "PUTBUFFER");
//
//#pragma DATA_SECTION(PutWriteIndexes, "PUTWRITEIDX");
//
//#pragma DATA_SECTION(GetReadIndexes, "GETREADIDX");
//
//#pragma DATA_SECTION(IPCCPU1toCPU2Buffers, "GETBUFFER");
//
//#pragma DATA_SECTION(GetWriteIndexes, "GETWRITEIDX");
//
//#pragma DATA_SECTION(PutReadIndexes, "PUTREADIDX");
//
//#endif
//
//
//IpcMessage IPCCPU1toCPU2Buffers[NUM_IPC_INTERRUPTS][IPC_BUFFER_SIZE];
//
//IpcMessage IPCCPU2toCPU1Buffers[NUM_IPC_INTERRUPTS][IPC_BUFFER_SIZE];
//
////
//// Global Circular Buffer Index Definitions
////
//Uint16 PutWriteIndexes[NUM_IPC_INTERRUPTS];
//Uint16 PutReadIndexes[NUM_IPC_INTERRUPTS];
//Uint16 GetWriteIndexes[NUM_IPC_INTERRUPTS];
//Uint16 GetReadIndexes[NUM_IPC_INTERRUPTS];
//

#ifdef __cpluscplus
}
#endif


