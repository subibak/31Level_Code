/*
 * main.c
 */


#include "Define_Header.h"

void USER_application(void)
{
    XF1_ON;                                 // XF1 Pin ON
    if(IpcRegs.IPCSTS.bit.IPC5 == 1)
    {
    //    if(Status_data == 1)         XF1_ON;                                 // XF1 Pin ON
    //    else                         XF1_OFF;                                // XF1 Pin OFF

        IPC_DSP1_EtherCAT_TX();
        IPC_DSP1_EtherCAT_RX();

        XF1_OFF;                                // XF1 Pin OFF

        LED_DSP();
    }

}

void main(void) {

    DisableDog();

    //*********************** CPU2 ***********************//
#ifdef CPU2
    IpcRegs.IPCSET.all = IPCxxx_IPC30;          //
    while((IpcRegs.IPCSTS.all & IPCxxx_IPC30) == 0);    //
    IpcRegs.IPCACK.all = IPCxxx_IPC30;          //
#endif
    //***************************************************//

    //*********************** CPU1 ***********************//
#ifdef CPU1
    /* initialize the Hardware and the EtherCAT Slave Controller */
    Init_PLL();

#if (CPU2_BOOT_ENABLE)
    // CPU2 Boot Start.
    IPCBootCPU2(IPCBOOTMODE_FLASH);             // CPU2 Boot Execution.
#endif

    Init_Mem();
    Init_CpuSelect();
    // Pin Function Initializing.
#if (CPU2_BOOT_ENABLE)
    while((IpcRegs.IPCSTS.all & IPCxxx_IPC30) == 0);    //
    IpcRegs.IPCACK.all = IPCxxx_IPC30;          //
#endif
    Init_GPIO();                                // Pin Function Selection.
    IpcRegs.IPCSET.all = IPCxxx_IPC30;

#endif
    //***************************************************//

    //******************** CPU1 & CPU2 ********************//
    // Clock Initializing.
    Init_PeripheralClocks();                    // Peripheral Clock Enable/Disable.

    // Interrupt Initializing.
    Init_PieCtrl();                             // Interrupt Enable Initializing.
    Init_PieVectTable();                        // Interrupt Vector Table Initializing.

    Init_Emif();

    HW_Init();
//	Init_Epwm();
//	Init_InputXbar();
//	LPF_Parameter();

    MainInit();
//	Start_PieCtrl();
    //***************************************************//

//    //*********************** CPU1 ***********************//
#ifdef CPU1
    // Start System
#if (CPU2_BOOT_ENABLE)
    while((IpcRegs.IPCSTS.all & IPCxxx_IPC30) == 0);    //
    IpcRegs.IPCACK.all = IPCxxx_IPC30;          //
#endif

#endif
    //*********************** CPU2 ***********************//
#ifdef CPU2
    IpcRegs.IPCSET.all = IPCxxx_IPC30;          //
#endif

    bRunApplication = TRUE;
    do
    {
        MainLoop();

    } while (bRunApplication == TRUE);

    HW_Release();
}

