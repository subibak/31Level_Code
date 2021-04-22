

/**
 * main.c
 */

#include "Define_Header.h"
#include "Define_PRCM.h"
#include "Define_CtrlModule.h"
#include "Define_GPIO.h"
#include "Define_IntCtrl.h"
#include "Define_GPMC.h"
#include "Define_Timer.h"

void main(void)
{
    //Boot SEQ  1. A15, 2. DSP
//    while(MAILBOX7Regs.MAILBOX_MSGSTATUS_11.bit.NBOFMSGMBM == 0);
//    while(MAILBOX7Regs.MAILBOX_MESSAGE_11.MESSAGEVALUEMBM != 0x3FFF);

    // PRCM.
    Init_PRCM();

    // GPIO.
    Init_PAD();
    Init_GPIO();

    // Interrupt.
    Init_Interrupt();

    // SPI2
    Init_McSPI();
    // GPMC
    Init_GPMC();

    PRE_MC_OFF;
    MAIN_MC_OFF;
    RELAY3_OFF;
    RELAY4_OFF;

    // ADC
//    Init_ADC();
    // Timer.
    Init_Timer();

    TSCL = 1;
    // Start.
    Start_Timer();

	while(1);

}
