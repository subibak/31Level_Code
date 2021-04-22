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

#ifdef CPU1
Uint16 IPCBootCPU2(Uint32 ulBootMode)
{
    // If CPU2 has already booted, return a fail to let the application
    // know that something is out of the ordinary.
    if ((IpcRegs.IPCBOOTSTS & 0x0000000F) == IPCBOOTSTS_ACKIPC)
        return STATUS_FAIL;

    // Wait Until CPU2 Control System Boot ROM is Ready.
    while ((IpcRegs.IPCBOOTSTS & 0x0000000F) != IPCBOOTSTS_ReadyIPC);

    // Wait Until IPC Flag 0 and 31 is Available.
    while ((IpcRegs.IPCFLG.all & (IPCxxx_IPC0 | IPCxxx_IPC31)) > 0);

    // Give GPIO and Module Control.

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

void IPC_DSP1_EtherCAT_RX(void){
    //Read from CPU2
    while(IpcRegs.IPCSTS.bit.IPC4 == 0);

    Sum_v_sm = IpcDspEcatSlave.SM_Vol_Sum;
    Fault_data = IpcDspEcatSlave.Fault.all;

    IpcRegs.IPCACK.bit.IPC4 = 1;

    return;
}




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
