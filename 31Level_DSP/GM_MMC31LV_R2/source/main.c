/*
 * main.c
 *
 *  Created on: 2018. 9. 19.
 *      Author: HJHeo
 *  Revised on: 2020. 10. 08.
 *      Reviser: subi
 */

#include "Define_Header.h"

void main(void) {

    DisableDog();

    //*********************** CPU2 ***********************//
#ifdef CPU2
    IpcRegs.IPCSET.all = IPCxxx_IPC30;              // Inform necessary cpu1 that cpu2 complete until DisableDog()
    while((IpcRegs.IPCSTS.all & IPCxxx_IPC30) == 0);// Wait until cpu1's works is done
    IpcRegs.IPCACK.all = IPCxxx_IPC30;              // Clear cpu1's IPC30 (CPU1's work until Init_GPIO)
#endif
    //***************************************************//

    //*********************** CPU1 ***********************//
#ifdef CPU1
    /* initialize the Hardware and the EtherCAT Slave Controller */
    Init_PLL();                                     // PLL Initialization
    Init_GSMem_Sel();                               // Global Share Memory Core Selection
    Init_GPIO();                                    // Pin Function Selection
    Init_CpuSelect();                               // Peripheral Module Host Selection

#ifdef CPU2_BOOT_ENABLE
#ifdef CPU2_FLASH_BOOT
    IPCBootCPU2(IPCBOOTMODE_FLASH);                 // CPU2 Boot Execution.
#endif
    while((IpcRegs.IPCSTS.all & IPCxxx_IPC30) == 0);// Wait until cpu2 Disable() is done
    IpcRegs.IPCACK.all = IPCxxx_IPC30;              // Clear cpu2's IPC30
    IpcRegs.IPCSET.all = IPCxxx_IPC30;              // Inform necessary cpu2 that cpu1 complete until Init_Gpio()
#endif

#endif
    //***************************************************//

    //******************** CPU1 & CPU2 ********************//
    Init_Mem();                                     // Memory Initialization
    Init_PeripheralClocks();                        // Peripheral Clock Enable/Disable.
    Init_PieCtrl();                                 // Interrupt Enable Initializing.
    Init_PieVectTable();                            // Interrupt Vector Table Initializing.
    Init_Epwm();                                    // ePWM Initialization
//    Init_InputXbar();                                 // InputXbar Initializing

    //*********************** CPU1 ***********************//
#ifdef CPU1
#endif

    //*********************** CPU2 ***********************//
#ifdef CPU2
    Init_Emif1();                                   // EMIF Initialization
    Init_LED_FPGA();                                // Initialize FPGA GPIO
#endif
    //***************************************************//

    //******************** CPU1 & CPU2 ********************//
    Start_PieCtrl();                                // Interrupt Enable
    //***************************************************//

    //*********************** CPU2 ***********************//
#ifdef CPU2
    IpcRegs.IPCSET.all = IPCxxx_IPC30;              // Inform cpu1 that cpu2 complete until Start_Piectrl()
#endif
    //***************************************************//

//    //*********************** CPU1 ***********************//
#ifdef CPU1
    // Start System
#ifdef CPU2_BOOT_ENABLE
    while((IpcRegs.IPCSTS.all & IPCxxx_IPC30) == 0);// Wait until cpu2 work's is done
    IpcRegs.IPCACK.all = IPCxxx_IPC30;              // Clear cpu2's IPC30
#endif
    //***************************************************//
    Start_PWM();                                    // ePWM Time Base Enable

#endif

    while(1);                                        // endless loop - wait for an interrupt

}

#ifdef CPU1
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
#endif
