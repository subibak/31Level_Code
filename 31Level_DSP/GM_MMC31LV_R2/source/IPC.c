/*
 * IPC.c
 *
 *  Created on: 2018. 9. 19.
 *      Author: HJHeo
 *  Revised on: 2018. 9. 28.
 *      Reviser:subi
 */

// CPU1 WR : IPCxxx_IPC4(IPC_FLAG4)
// CPU1 RD : IPCxxx_IPC5(IPC_FLAG5)
// CPU2 WR : IPCxxx_IPC6(IPC_FLAG6)
// CPU2 RD : IPCxxx_IPC7(IPC_FLAG7)

#include "Define_Header.h"

float Sum_v_sm_old = 0;



/*****************************************************************************
//! Executes a CPU02 control system bootloader.
//!
//! \param ulBootMode specifies which CPU02 control system boot mode to execute.
//!
//! This function will allow the CPU01 master system to boot the CPU02 control
//! system via the following modes: Boot to RAM, Boot to Flash, Boot via SPI,
//! SCI, I2C, or parallel I/O. Unlike other IPCLite driver functions, this
//! function blocks and waits until the control system boot ROM is configured
//! and ready to receive CPU01 to CPU02 IPC INT0 interrupts. It then blocks and
//! waits until IPC INT0 and IPC FLAG31 are available in the CPU02 boot ROM
//! prior to sending the command to execute the selected bootloader. The \e
//! ulBootMode parameter accepts one of the following values: \b
//! C1C2_BROM_BOOTMODE_BOOT_FROM_PARALLEL, \b
//! C1C2_BROM_BOOTMODE_BOOT_FROM_SCI, \b
//! C1C2_BROM_BOOTMODE_BOOT_FROM_SPI, \b
//! C1C2_BROM_BOOTMODE_BOOT_FROM_I2C, \b C1C2_BROM_BOOTMODE_BOOT_FROM_CAN,
//! \b C1C2_BROM_BOOTMODE_BOOT_FROM_RAM, \b
//! C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH.
//!
//! \return 0 (success) if command is sent, or 1 (failure) if boot mode is
//! invalid and command was not sent.
/
*/

#ifdef CPU1
Uint16 IPCBootCPU2(Uint32 ulBootMode)
{
    // When CPU2 Already Booted.
    if ((IpcRegs.IPCBOOTSTS & 0x0000000F) == IPCBOOTSTS_ACKIPC)
        return STATUS_FAIL;

    // Wait Until CPU2 Control System Boot ROM is Ready.
    while ((IpcRegs.IPCBOOTSTS & 0x0000000F) != IPCBOOTSTS_ReadyIPC);

    // Wait Until IPC Flag 0 and 31 is Available.
    while ((IpcRegs.IPCFLG.all & (IPCxxx_IPC0 | IPCxxx_IPC31)) > 0);

    // CPU2 Boot.
    IpcRegs.IPCBOOTMODE = ulBootMode;
    IpcRegs.IPCSENDCOM = IPCSENDCOM_EXECUTE_BOOTMODE_CMD;
    IpcRegs.IPCSET.all = IPCxxx_IPC31 | IPCxxx_IPC0;

    return STATUS_PASS;
}
#endif

void IPCWrite32bitProtect(Uint32 addr, Uint32 data)
{
    IpcRegs.IPCSENDCOM = 0x0000000E;
    IpcRegs.IPCSENDADDR = addr;
    IpcRegs.IPCSENDDATA = data;
    IpcRegs.IPCSET.all = (0x80000000 | 0x00000001);

    return;
}

//extern void IPC_DSP1_Temp_TX(void);
//extern void IPC_DSP1_Temp_RX(void);
#ifdef CPU1
void IPC_DSP1_EtherCAT_TX(void)
{
    //Write to CPU2
    while(IpcRegs.IPCFLG.bit.IPC7 == 1);

    IpcDspEcatMaster.STATUS.all = Status_data;
    IpcDspEcatMaster.Operation.all = Operation_data;
    IpcDspEcatMaster.Bypass.all = Bypass_data;
    IpcDspEcatMaster.SM_Vol_Under_Limit = Limit_v_sm_under;
    IpcDspEcatMaster.SM_Vol_Over_Limit = Limit_v_sm_over;
    IpcDspEcatMaster.SM_Temp_Limit = Limit_temperature;
    IpcDspEcatMaster.Slave_OP_Mode.all = Slave_OP_mode;
    IpcDspEcatMaster.FLASH_MSB = Flash_ROM_msb;
    IpcDspEcatMaster.FLASH_LSB = Flash_ROM_lsb;
    IpcDspEcatMaster.REF = Ref;
    IpcDspEcatMaster.SlaveStatus = SlaveStatus;

    IpcRegs.IPCSET.bit.IPC7 = 1;

    return;
}
#endif

#ifdef CPU1
void IPC_DSP1_EtherCAT_RX(void){
    //Read from CPU2
    while(IpcRegs.IPCSTS.bit.IPC4 == 0);

    Sum_v_sm = IpcDspEcatSlave.SM_Vol_Sum;
    Fault_data = IpcDspEcatSlave.Fault.all;

    IpcRegs.IPCACK.bit.IPC4 = 1;

    return;
}
#endif



//void CPU_Msg_Write(Uint16 EtherCAT_Msg_WR[])
//{
//    // CPU1 WR : IPCxxx_IPC4(IPC_FLAG4)
//    // CPU1 RD : IPCxxx_IPC5(IPC_FLAG5)
//    // CPU2 WR : IPCxxx_IPC6(IPC_FLAG6)
//    // CPU2 RD : IPCxxx_IPC7(IPC_FLAG7)
//#ifdef CPU1
//    while((IpcRegs.IPCFLG.bit.IPC7 & 0x00F0) == IPCxxx_IPC7);
//    IpcRegs.IPCSET.all |= IPCxxx_IPC4;
//    IpcMsgCPU1t2.Message0 = EtherCAT_Msg_WR[0];
//    IpcRegs.IPCSET.all = 0;
//#endif
//
//
//#ifdef CPU2
//    while((IpcRegs.IPCFLG.bit.IPC5 & 0x00F0) == IPCxxx_IPC5);
//    IpcRegs.IPCSET.all |= IPCxxx_IPC6;
//    IpcMsgCPU2t1.Message0 = EtherCAT_Msg_WR[0];
//    IpcRegs.IPCSET.all = 0;
//#endif
//
//    return;
//}
//
//void CPU_Msg_Read(Uint16 EtherCAT_Msg_RD[])
//{
//    // CPU1 WR : IPCxxx_IPC4(IPC_FLAG4)
//    // CPU1 RD : IPCxxx_IPC5(IPC_FLAG5)
//    // CPU2 WR : IPCxxx_IPC6(IPC_FLAG6)
//    // CPU2 RD : IPCxxx_IPC7(IPC_FLAG7)
//#ifdef CPU1
//    while((IpcRegs.IPCFLG.bit.IPC6 & 0x00F0) == IPCxxx_IPC6);
//    IpcRegs.IPCSET.all |= IPCxxx_IPC5;
//    EtherCAT_Msg_RD[0] = IpcMsgCPU2t1.Message0;
//    IpcRegs.IPCSET.all = 0;
//#endif
//
//#ifdef CPU2
//    while((IpcRegs.IPCFLG.bit.IPC4 & 0x00F0) == IPCxxx_IPC4);
//    IpcRegs.IPCSET.all |= IPCxxx_IPC7;
//    EtherCAT_Msg_RD[0] = IpcMsgCPU1t2.Message0;
//    IpcRegs.IPCSET.all = 0;
//#endif
//
//    return;
//}
/*
uint32_t
IPCGetBootStatus (void)
{
   return(IpcRegs.IPCBOOTSTS);
}

#if defined (CPU1)


Uint16 IPCBootCPU2temp(uint32_t ulBootMode)
{
    Uint16 bootStatus;
    Uint16 pin;
    Uint16 returnStatus = STATUS_PASS;

    //
    // If CPU2 has already booted, return a fail to let the application
    // know that something is out of the ordinary.
    //
    bootStatus = IPCGetBootStatus() & 0x0000000F;

    if(bootStatus == C2_BOOTROM_BOOTSTS_C2TOC1_BOOT_CMD_ACK)
    {
        //
        // Check if MSB is set as well
        //
        bootStatus = ((uint32_t)(IPCGetBootStatus() & 0x80000000)) >> 31U;

        if(bootStatus != 0)
        {
            returnStatus = STATUS_FAIL;

            return returnStatus;
        }
    }

    //
    // Wait until CPU02 control system boot ROM is ready to receive
    // CPU01 to CPU02 INT1 interrupts.
    //
    do
    {
        bootStatus = IPCGetBootStatus() & C2_BOOTROM_BOOTSTS_SYSTEM_READY;
    } while ((bootStatus != C2_BOOTROM_BOOTSTS_SYSTEM_READY));

    //
    // Loop until CPU02 control system IPC flags 1 and 32 are available
    //
    while ((IPCLtoRFlagBusy(IPC_FLAG0) == 1) ||
           (IPCLtoRFlagBusy(IPC_FLAG31) == 1))
    {

    }

    if (ulBootMode >= C1C2_BROM_BOOTMODE_BOOT_COMMAND_MAX_SUPPORT_VALUE)
    {
        returnStatus = STATUS_FAIL;
    }
    else
    {
        //
        // Based on boot mode, enable pull-ups on peripheral pins and
        // give GPIO pin control to CPU02 control system.
        //
        switch (ulBootMode)
        {
            case C1C2_BROM_BOOTMODE_BOOT_FROM_SCI:

                 EALLOW;

                 //
                 //SCIA connected to CPU02
                 //
                 DevCfgRegs.CPUSEL5.bit.SCI_A = 1;

                 //
                 //Allows CPU02 bootrom to take control of clock
                 //configuration registers
                 //
                 ClkCfgRegs.CLKSEM.all = 0xA5A50000;

                 ClkCfgRegs.LOSPCP.all = 0x0002;
                 EDIS;

                 GPIO_SetupPinOptions(29, GPIO_OUTPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(29,GPIO_MUX_CPU2,1);

                 GPIO_SetupPinOptions(28, GPIO_INPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(28,GPIO_MUX_CPU2,1);

                break;

            case C1C2_BROM_BOOTMODE_BOOT_FROM_SPI:
                 EALLOW;

                 //
                 //SPI-A connected to CPU02
                 //
                 DevCfgRegs.CPUSEL6.bit.SPI_A = 1;

                 //
                 //Allows CPU02 bootrom to take control of clock configuration
                 // registers
                 //
                 ClkCfgRegs.CLKSEM.all = 0xA5A50000;
                 EDIS;

                 GPIO_SetupPinOptions(16, GPIO_INPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(16,GPIO_MUX_CPU2,1);

                 GPIO_SetupPinOptions(17, GPIO_INPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(17,GPIO_MUX_CPU2,1);

                 GPIO_SetupPinOptions(18, GPIO_INPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(18,GPIO_MUX_CPU2,1);

                 GPIO_SetupPinOptions(19, GPIO_OUTPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(19,GPIO_MUX_CPU2,0);

                break;

            case C1C2_BROM_BOOTMODE_BOOT_FROM_I2C:
                 EALLOW;

                 //
                 //I2CA connected to CPU02
                 //
                 DevCfgRegs.CPUSEL7.bit.I2C_A = 1;

                 //
                 //Allows CPU2 bootrom to take control of clock
                 //configuration registers
                 //
                 ClkCfgRegs.CLKSEM.all = 0xA5A50000;
                 ClkCfgRegs.LOSPCP.all = 0x0002;
                 EDIS;
                 GPIO_SetupPinOptions(32, GPIO_INPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(32,GPIO_MUX_CPU2,1);

                 GPIO_SetupPinOptions(33, GPIO_INPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(33,GPIO_MUX_CPU2,1);

                break;
            case C1C2_BROM_BOOTMODE_BOOT_FROM_PARALLEL:

                 for(pin=58;pin<=65;pin++)
                 {
                    GPIO_SetupPinOptions(pin, GPIO_INPUT, GPIO_ASYNC);
                    GPIO_SetupPinMux(pin,GPIO_MUX_CPU2,0);
                 }

                 GPIO_SetupPinOptions(69, GPIO_OUTPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(69,GPIO_MUX_CPU2,0);

                 GPIO_SetupPinOptions(70, GPIO_INPUT, GPIO_ASYNC);
                 GPIO_SetupPinMux(70,GPIO_MUX_CPU2,0);
                 break;


            case C1C2_BROM_BOOTMODE_BOOT_FROM_CAN:
                 //
                 //Set up the GPIO mux to bring out CANATX on GPIO71
                 //and CANARX on GPIO70
                 //
                 EALLOW;
                 GpioCtrlRegs.GPCLOCK.all = 0x00000000; //Unlock GPIOs 64-95

                 //
                 //Give CPU2 control just in case
                 //
                 GpioCtrlRegs.GPCCSEL1.bit.GPIO71 = GPIO_MUX_CPU2;

                 //
                 //Set the extended mux to 0x5
                 //
                 GpioCtrlRegs.GPCGMUX1.bit.GPIO71 = 0x1;
                 GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 0x1;

                 //
                 //Set qualification to async just in case
                 //
                 GpioCtrlRegs.GPCQSEL1.bit.GPIO71 = 0x3;

                 GpioCtrlRegs.GPCLOCK.all = 0x00000000; //Unlock GPIOs 64-95

                 //
                 //Give CPU2 control just in case
                 //
                 GpioCtrlRegs.GPCCSEL1.bit.GPIO70 = GPIO_MUX_CPU2;

                 //
                 //Set the extended mux to bring out CANATX
                 //
                 GpioCtrlRegs.GPCGMUX1.bit.GPIO70 = 0x1;
                 GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 0x1;

                 //
                 //Set qualification to async just in case
                 //
                 GpioCtrlRegs.GPCQSEL1.bit.GPIO70 = 0x3;
                 GpioCtrlRegs.GPCLOCK.all = 0xFFFFFFFF; //Lock GPIOs 64-95
                 ClkCfgRegs.CLKSRCCTL2.bit.CANABCLKSEL = 0x0;
                 CpuSysRegs.PCLKCR10.bit.CAN_A = 1;
                 EDIS;

               break;

         }

        //
        //CPU01 to CPU02 IPC Boot Mode Register
        //
        IpcRegs.IPCBOOTMODE = ulBootMode;

        //
        // CPU01 To CPU02 IPC Command Register
        //
        IpcRegs.IPCSENDCOM  = BROM_IPC_EXECUTE_BOOTMODE_CMD;

        //
        // CPU01 to CPU02 IPC flag register
        //
        IpcRegs.IPCSET.all = 0x80000001;

    }



    return returnStatus;
}
*/
