/*
 * EMIF.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 *  Revised on: 2018.09.27
 *  Reviser   : subi
 */


#include "Define_Header.h"

void Init_Emif(void)
{   //EMIF1
#ifdef CPU2
    EALLOW;
    Emif1ConfigRegs.EMIF1LOCK.bit.LOCK_EMIF1 = 0;
    Emif1ConfigRegs.EMIF1COMMIT.bit.COMMIT_EMIF1 = 0;
    Emif1ConfigRegs.EMIF1MSEL.all = 0x93A5CE72;     // KEY value and Msel value must be written together at a time using 'all'
    Emif1ConfigRegs.EMIF1ACCPROT0.bit.CPUWRPROT_EMIF1 = 0;
    Emif1ConfigRegs.EMIF1ACCPROT0.bit.DMAWRPROT_EMIF1 = 0;
    Emif1ConfigRegs.EMIF1ACCPROT0.bit.FETCHPROT_EMIF1 = 0;
    EDIS;

    ClkCfgRegs.PERCLKDIVSEL.bit.EMIF1CLKDIV = 0;    // EMxCLK = PLLSYSCLK / 1, 0: 200 Mhz, 1: 100Mhz
    Emif1Regs.ASYNC_WCCR.bit.WP0 = 0;

    //// Chip Select 2 ////
    Emif1Regs.ASYNC_CS2_CR.bit.SS = 0;              // Select Strobe mode : 0(normal mode)
    Emif1Regs.ASYNC_CS2_CR.bit.EW = 0;              // Extend Wait mode
    Emif1Regs.ASYNC_CS2_CR.bit.TA = 0;              // Turn Around cycles
    Emif1Regs.ASYNC_CS2_CR.bit.ASIZE = 1;           // Asynchronous Memory size : 1(16 bit data bus)

    // Write cycle
    Emif1Regs.ASYNC_CS2_CR.bit.W_SETUP = 4;         // Write Strobe Setup cycles
    Emif1Regs.ASYNC_CS2_CR.bit.W_STROBE = 10;       // Write Strobe Duration cycles
    Emif1Regs.ASYNC_CS2_CR.bit.W_HOLD = 4;          // Write Strobe Hold cycles

    // Read cycle
    Emif1Regs.ASYNC_CS2_CR.bit.R_SETUP = 4;         // Read Strobe Setup cycles
    Emif1Regs.ASYNC_CS2_CR.bit.R_STROBE = 10;       // Read Strobe Duration cycles
    Emif1Regs.ASYNC_CS2_CR.bit.R_HOLD = 4;          // Read Strobe Hold cycles

    //// Chip Select 3 ////
    Emif1Regs.ASYNC_CS3_CR.bit.SS = 0;              // Select Strobe mode : 0(normal mode)
    Emif1Regs.ASYNC_CS3_CR.bit.EW = 0;              // Extend Wait mode
    Emif1Regs.ASYNC_CS3_CR.bit.TA = 0;              // Turn Around cycles
    Emif1Regs.ASYNC_CS3_CR.bit.ASIZE = 1;           // Asynchronous Memory size : 1(16 bit data bus)

    // Write cycle
    Emif1Regs.ASYNC_CS3_CR.bit.W_SETUP = 4;         // Write Strobe Setup cycles
    Emif1Regs.ASYNC_CS3_CR.bit.W_STROBE = 10;       // Write Strobe Duration cycles
    Emif1Regs.ASYNC_CS3_CR.bit.W_HOLD = 4;          // Write Strobe Hold cycles

    // Read cycle
    Emif1Regs.ASYNC_CS3_CR.bit.R_SETUP = 4;         // Read Strobe Setup cycles
    Emif1Regs.ASYNC_CS3_CR.bit.R_STROBE = 10;       // Read Strobe Duration cycles
    Emif1Regs.ASYNC_CS3_CR.bit.R_HOLD = 4;          // Read Strobe Hold cycles

    //// Chip Select 4 ////
    Emif1Regs.ASYNC_CS4_CR.bit.SS = 0;              // Select Strobe mode : 0(normal mode)
    Emif1Regs.ASYNC_CS4_CR.bit.EW = 0;              // Extend Wait mode
    Emif1Regs.ASYNC_CS4_CR.bit.TA = 0;              // Turn Around cycles
    Emif1Regs.ASYNC_CS4_CR.bit.ASIZE = 1;           // Asynchronous Memory size : 1(16 bit data bus)

    // Write cycle
    Emif1Regs.ASYNC_CS4_CR.bit.W_SETUP = 4;         // Write Strobe Setup cycles
    Emif1Regs.ASYNC_CS4_CR.bit.W_STROBE = 10;       // Write Strobe Duration cycles
    Emif1Regs.ASYNC_CS4_CR.bit.W_HOLD = 4;          // Write Strobe Hold cycles

    // Read cycle
    Emif1Regs.ASYNC_CS4_CR.bit.R_SETUP = 4;         // Read Strobe Setup cycles
    Emif1Regs.ASYNC_CS4_CR.bit.R_STROBE = 10;       // Read Strobe Duration cycles
    Emif1Regs.ASYNC_CS4_CR.bit.R_HOLD = 4;          // Read Strobe Hold cycles
#endif
#ifdef CPU1
    //EMIF2
    Emif2ConfigRegs.EMIF2LOCK.bit.LOCK_EMIF2 = 0;

    EALLOW;
    Emif2ConfigRegs.EMIF2LOCK.bit.LOCK_EMIF2 = 0;
    Emif2ConfigRegs.EMIF2ACCPROT0.bit.CPUWRPROT_EMIF2 = 0;
    Emif2ConfigRegs.EMIF2ACCPROT0.bit.FETCHPROT_EMIF2 = 0;
    EDIS;

    ClkCfgRegs.PERCLKDIVSEL.bit.EMIF2CLKDIV = 0;    // EMxCLK = PLLSYSCLK / 1, 0: 200 Mhz, 1: 100Mhz
    Emif2Regs.ASYNC_WCCR.bit.WP0 = 0;

    //// Chip Select 2 ////
    Emif2Regs.ASYNC_CS2_CR.bit.SS = 0;              // Select Strobe mode : 0(normal mode)
    Emif2Regs.ASYNC_CS2_CR.bit.EW = 0;              // Extend Wait mode
    Emif2Regs.ASYNC_CS2_CR.bit.TA = 0;              // Turn Around cycles
    Emif2Regs.ASYNC_CS2_CR.bit.ASIZE = 1;           // Asynchronous Memory size : 1(16 bit data bus)

    // Write cycle
    Emif2Regs.ASYNC_CS2_CR.bit.W_SETUP = 4;         // Write Strobe Setup cycles
    Emif2Regs.ASYNC_CS2_CR.bit.W_STROBE = 10;       // Write Strobe Duration cycles
    Emif2Regs.ASYNC_CS2_CR.bit.W_HOLD = 4;          // Write Strobe Hold cycles

    // Read cycle
    Emif2Regs.ASYNC_CS2_CR.bit.R_SETUP = 4;         // Read Strobe Setup cycles
    Emif2Regs.ASYNC_CS2_CR.bit.R_STROBE = 10;       // Read Strobe Duration cycles
    Emif2Regs.ASYNC_CS2_CR.bit.R_HOLD = 4;          // Read Strobe Hold cycles


    //// Chip Select 3 ////
    Emif2Regs.ASYNC_CS3_CR.bit.SS = 0;              // Select Strobe mode : 0(normal mode)
    Emif2Regs.ASYNC_CS3_CR.bit.EW = 0;              // Extend Wait mode
    Emif2Regs.ASYNC_CS3_CR.bit.TA = 0;              // Turn Around cycles
    Emif2Regs.ASYNC_CS3_CR.bit.ASIZE = 1;           // Asynchronous Memory size : 1(16 bit data bus)

    // Write cycle
    Emif2Regs.ASYNC_CS3_CR.bit.W_SETUP = 4;         // Write Strobe Setup cycles
    Emif2Regs.ASYNC_CS3_CR.bit.W_STROBE = 10;       // Write Strobe Duration cycles
    Emif2Regs.ASYNC_CS3_CR.bit.W_HOLD = 4;          // Write Strobe Hold cycles

    // Read cycle
    Emif2Regs.ASYNC_CS3_CR.bit.R_SETUP = 4;         // Read Strobe Setup cycles
    Emif2Regs.ASYNC_CS3_CR.bit.R_STROBE = 10;       // Read Strobe Duration cycles
    Emif2Regs.ASYNC_CS3_CR.bit.R_HOLD = 4;          // Read Strobe Hold cycles


    //// Chip Select 4 ////
    Emif2Regs.ASYNC_CS4_CR.bit.SS = 0;              // Select Strobe mode : 0(normal mode)
    Emif2Regs.ASYNC_CS4_CR.bit.EW = 0;              // Extend Wait mode
    Emif2Regs.ASYNC_CS4_CR.bit.TA = 0;              // Turn Around cycles
    Emif2Regs.ASYNC_CS4_CR.bit.ASIZE = 1;           // Asynchronous Memory size : 1(16 bit data bus)

    // Write cycle
    Emif2Regs.ASYNC_CS4_CR.bit.W_SETUP = 4;         // Write Strobe Setup cycles
    Emif2Regs.ASYNC_CS4_CR.bit.W_STROBE = 10;       // Write Strobe Duration cycles
    Emif2Regs.ASYNC_CS4_CR.bit.W_HOLD = 4;          // Write Strobe Hold cycles

    // Read cycle
    Emif2Regs.ASYNC_CS4_CR.bit.R_SETUP = 4;         // Read Strobe Setup cycles
    Emif2Regs.ASYNC_CS4_CR.bit.R_STROBE = 10;       // Read Strobe Duration cycles
    Emif2Regs.ASYNC_CS4_CR.bit.R_HOLD = 4;          // Read Strobe Hold cycles
#endif
    return;
}

void Emif1Initialize(void)
{
    EALLOW;
    //
    // Perform a Module soft reset on EMIF
    //
#ifdef CPU1
    DevCfgRegs.SOFTPRES1.all = 0x1;
   __asm (" nop");
    DevCfgRegs.SOFTPRES1.all = 0x0;
#endif
    EDIS;
}
