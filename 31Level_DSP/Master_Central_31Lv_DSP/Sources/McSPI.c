/*
 * McSPI.c
 *
 *  Created on: 2018. 12. 14.
 *      Author: subi
 */

#include "Define_Header.h"


void Init_McSPI(void)
{
    McSPI2Regs.MCSPI_SYSCONFIG.bit.SOFTRESET = 1;
    while (McSPI2Regs.MCSPI_SYSSTATUS.bit.RESETDONE == 0);

    //Configure static settings (such as SPI master or slave) as required.

//    McSPI2Regs.MCSPI_MODULCTRL.bit.FDAA = 0x0;                      // 0x0: FIFO data managed by MCSPI_TXx and MCSPI_RXx registers.
//    McSPI2Regs.MCSPI_MODULCTRL.bit.MOA = 0x0;                       // 0x0: Multiple word access disabled
//    McSPI2Regs.MCSPI_MODULCTRL.bit.INITDLY = 0x0;                   // 0x0: No delay for first spi transfer.
//    McSPI2Regs.MCSPI_MODULCTRL.bit.SYSTEM_TEST = 0x0;               // 0x0: Functional mode

    McSPI2Regs.MCSPI_MODULCTRL.bit.MS = 0x0;                        // 0x0: Master - The module generates the SPICLK and SPIEN[3:0].
    McSPI2Regs.MCSPI_MODULCTRL.bit.PIN34 = 0x0;                     // 0x0: SPIEN is used as a chip-select.
    McSPI2Regs.MCSPI_MODULCTRL.bit.SINGLE = 0x0;                    // 0x1: Only one channel will be used in master mode. This bit must be set in Force SPIEN[x] mode.

    //Sys Configuration

//    McSPI2Regs.MCSPI_SYSCONFIG.bit.CLOCKACTIVITY = 0x0;             // 0x0: Interface and functional clocks may be switched off.
//    McSPI2Regs.MCSPI_SYSCONFIG.bit.SIDLEMODE = 0x3;                 // 0x3: Reserved - do not use.
//    McSPI2Regs.MCSPI_SYSCONFIG.bit.ENAWAKEUP = 0x0;                 // 0x0: Wake-up capability is disabled.

    McSPI2Regs.MCSPI_CH0CONF.bit.TRM = 0x2;                         // Transmit-only mode
    McSPI2Regs.MCSPI_CH0CONF.bit.EPOL = 0x1;                        // SPIEN polarity 0x1 : SPIEN is held low during the ACTIVE state
    McSPI2Regs.MCSPI_CH0CONF.bit.CLKD = 0x2;                        // Frequency divider by 4  -> 12 MHz
    McSPI2Regs.MCSPI_CH0CONF.bit.WL = 0xF;                          // The SPI word is 16 bits long
    McSPI2Regs.MCSPI_CH0CONF.bit.FFEW = 0x1;                        // FIFO enabled for transmit 0x1: The buffer is used to transmit data
    McSPI2Regs.MCSPI_CH0CONF.bit.DPE1 = 0x0;                        // Transmission enable for data line 1  0x0 : enable
    McSPI2Regs.MCSPI_CH0CONF.bit.DPE0 = 0x1;                        // Transmission enable for data line 0  0x1 : disenable
    McSPI2Regs.MCSPI_IRQSTATUS.all = 0x0003777F;                    // All of status is reset

    McSPI2Regs.MCSPI_CH0CTRL.bit.EN = 0x1;                          // Channel 0 is enabled
//    McSPI2Regs.MCSPI_CH1CTRL.bit.EN = 0x0;                          // Channel 1 is disabled
//    McSPI2Regs.MCSPI_CH2CTRL.bit.EN = 0x0;                          // Channel 2 is disabled
//    McSPI2Regs.MCSPI_CH3CTRL.bit.EN = 0x0;                          // Channel 3 is disabled

    return;
}
