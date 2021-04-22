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

struct IPC_EtherCAT_Slave_DATA  Dsp2EcatSlave;
struct IPC_EtherCAT_Master_DATA  Dsp2EcatMaster;

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

    // Give GPIO and Module Control.

    // CPU2 Boot.
    IpcRegs.IPCBOOTMODE = ulBootMode;
    IpcRegs.IPCSENDCOM = IPCSENDCOM_EXECUTE_BOOTMODE_CMD;
    IpcRegs.IPCSET.all = IPCxxx_IPC31 | IPCxxx_IPC0;

    return STATUS_PASS;
}
#endif

void IPC_DSP2_Temp_TX(void)
{
    //Write
    while((IpcRegs.IPCFLG.bit.IPC5 & 0x00F0) == IPCxxx_IPC5);
    IpcRegs.IPCSET.all |= IPCxxx_IPC6;

    for(t = 0; t < D_Number_SM; t++)  IPC_Temp_Vol[t].all = Vol_Temp[0];

    IpcRegs.IPCSET.all = 0;

    return;
}

void IPC_DSP2_Temp_RX(void)
{
   while((IpcRegs.IPCFLG.bit.IPC4 & 0x00F0) == IPCxxx_IPC4);
   IpcRegs.IPCSET.all |= IPCxxx_IPC7;

   for(t = 0; t < D_Number_SM; t++) Temp[t] = IPC_Temp_Cal[t].all;

   IpcRegs.IPCSET.all = 0;

   return;
}


void IPC_DSP2_EtherCAT_TX(void)
{
    //Write to DSP1
    while(IpcRegs.IPCFLG.bit.IPC4 == 1);

    IpcDspEcatSlave.SM_Vol_Sum = Dsp2EcatSlave.SM_Vol_Sum;
    IpcDspEcatSlave.Fault.all = Dsp2EcatSlave.Fault.all;

    IpcRegs.IPCSET.bit.IPC4 = 1;

    return;
}

void IPC_DSP2_EtherCAT_RX(void)
{
    //Read from DSP1
    while(IpcRegs.IPCSTS.bit.IPC7 == 0);

    Dsp2EcatMaster.STATUS.all = IpcDspEcatMaster.STATUS.all;
    Dsp2EcatMaster.Operation.all= IpcDspEcatMaster.Operation.all;
    Dsp2EcatMaster.Bypass.all= IpcDspEcatMaster.Bypass.all;
    Dsp2EcatMaster.SM_Vol_Under_Limit= IpcDspEcatMaster.SM_Vol_Under_Limit;
    Dsp2EcatMaster.SM_Vol_Over_Limit= IpcDspEcatMaster.SM_Vol_Over_Limit;
    Dsp2EcatMaster.SM_Temp_Limit= IpcDspEcatMaster.SM_Temp_Limit;
    Dsp2EcatMaster.Slave_OP_Mode.all = IpcDspEcatMaster.Slave_OP_Mode.all;
    Dsp2EcatMaster.FLASH_MSB= IpcDspEcatMaster.FLASH_MSB;
    Dsp2EcatMaster.FLASH_LSB= IpcDspEcatMaster.FLASH_LSB;
    Dsp2EcatMaster.REF = IpcDspEcatMaster.REF;
    Dsp2EcatMaster.SlaveStatus = IpcDspEcatMaster.SlaveStatus;

    IpcRegs.IPCACK.bit.IPC7 = 1;

    return;
}

//void IPCWrite32bitProtect(Uint32 addr, Uint32 data)
//{
//    IpcRegs.IPCSENDCOM = 0x0000000E;
//    IpcRegs.IPCSENDADDR = addr;
//    IpcRegs.IPCSENDDATA = data;
//    IpcRegs.IPCSET.all = (0x80000000 | 0x00000001);
//
//    return;
//}

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
