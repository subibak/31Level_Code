/*
 * main.c
 */


#include "Define_Header.h"

void main(void) {

    DisableDog();

    //*********************** CPU2 ***********************//
#ifdef CPU2
    IpcRegs.IPCSET.all = 0x40000000;          //
    while((IpcRegs.IPCSTS.all & 0x40000000) == 0);    //
    IpcRegs.IPCACK.all = 0x40000000;          //
#endif
    //***************************************************//

    //*********************** CPU1 ***********************//
#ifdef CPU1
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
//  Init_XBAR();                                // Input/Output X-BAR Initializing.
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
    DELAY_US(1000000);
    Init_ADC();
    Init_Epwm();
    Init_xint();

    LPF_Parameter();

    Start_PieCtrl();
    //***************************************************//

    //*********************** CPU1 ***********************//
#ifdef CPU1
    // Start System
#if (CPU2_BOOT_ENABLE)
    while((IpcRegs.IPCSTS.all & IPCxxx_IPC30) == 0);    //
    IpcRegs.IPCACK.all = IPCxxx_IPC30;          //
#endif

#endif

    //*********************** CPU2 ***********************//
#ifdef CPU2
    IpcRegs.IPCSET.all = 0x40000000;          //
#endif

    for(;;);
}

