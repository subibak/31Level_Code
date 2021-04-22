/*
 * EMIF.c
 *
 *  Created on: 2015. 8. 18.
 *      Author: cjs9426
 */


#include "Define_Header.h"

void Init_Emif(void)
{
	ClkCfgRegs.PERCLKDIVSEL.bit.EMIF1CLKDIV = 0;	// EMxCLK = PLLSYSCLK / 1, 0: 200 Mhz, 1: 100Mhz
	Emif1Regs.ASYNC_WCCR.bit.WP0 = 0;
	/*
	//// Chip Select 0 ////
	Emif1Regs.SDRAM_CR.bit.SR = 1;					// Self Refresh : 1(Self Refresh)
	Emif1Regs.SDRAM_CR.bit.PD = 0;					// Power Down mode : 1(Power Down)
	Emif1Regs.SDRAM_CR.bit.PDWR = 1;				// 1(exit the Power Down state)
	Emif1Regs.SDRAM_CR.bit.NM = 1;					// Narrow mode : 0(System Bus : Memory Bus = 1 : 1)
													//				 1(System Bus : Memory Bus = 2 : 1)
	Emif1Regs.SDRAM_CR.bit.CL = 2;					// CAS latency : Only 2 or 3 are supported
	Emif1Regs.SDRAM_CR.bit.BIT_11_9_LOCK = 1;		// Bit Lock : 1(Write Only at Bit 11 to 9)
	Emif1Regs.SDRAM_CR.bit.PAGESIGE = 0;			// Internal Page Size : 0(256-word, 8 column address bits)
													//						1(512-word, 9 column address bits)
													//						2(1024-word, 10 column address bits)
													//						3(2048-word, 11 column address bits)
	*/
	//// Chip Select 2 ////
	Emif1Regs.ASYNC_CS2_CR.bit.SS = 0;				// Select Strobe mode : 0(normal mode)
	Emif1Regs.ASYNC_CS2_CR.bit.EW = 0;				// Extend Wait mode
	Emif1Regs.ASYNC_CS2_CR.bit.TA = 0;				// Turn Around cycles
	Emif1Regs.ASYNC_CS2_CR.bit.ASIZE = 1;			// Asynchronous Memory size : 1(16 bit data bus)

	// Write cycle
	Emif1Regs.ASYNC_CS2_CR.bit.W_SETUP = 4;			// Write Strobe Setup cycles
	Emif1Regs.ASYNC_CS2_CR.bit.W_STROBE = 10;		// Write Strobe Duration cycles
	Emif1Regs.ASYNC_CS2_CR.bit.W_HOLD = 4;			// Write Strobe Hold cycles

	// Read cycle
	Emif1Regs.ASYNC_CS2_CR.bit.R_SETUP = 4;			// Read Strobe Setup cycles
	Emif1Regs.ASYNC_CS2_CR.bit.R_STROBE = 10;		// Read Strobe Duration cycles
	Emif1Regs.ASYNC_CS2_CR.bit.R_HOLD = 4;			// Read Strobe Hold cycles


	//// Chip Select 3 ////
	Emif1Regs.ASYNC_CS3_CR.bit.SS = 0;				// Select Strobe mode : 0(normal mode)
	Emif1Regs.ASYNC_CS3_CR.bit.EW = 0;				// Extend Wait mode
	Emif1Regs.ASYNC_CS3_CR.bit.TA = 0;				// Turn Around cycles
	Emif1Regs.ASYNC_CS3_CR.bit.ASIZE = 1;			// Asynchronous Memory size : 1(16 bit data bus)

	// Write cycle
	Emif1Regs.ASYNC_CS3_CR.bit.W_SETUP = 4;			// Write Strobe Setup cycles
	Emif1Regs.ASYNC_CS3_CR.bit.W_STROBE = 10;		// Write Strobe Duration cycles
	Emif1Regs.ASYNC_CS3_CR.bit.W_HOLD = 4;			// Write Strobe Hold cycles

	// Read cycle
	Emif1Regs.ASYNC_CS3_CR.bit.R_SETUP = 4;			// Read Strobe Setup cycles
	Emif1Regs.ASYNC_CS3_CR.bit.R_STROBE = 10;		// Read Strobe Duration cycles
	Emif1Regs.ASYNC_CS3_CR.bit.R_HOLD = 4;			// Read Strobe Hold cycles


	//// Chip Select 4 ////
	Emif1Regs.ASYNC_CS4_CR.bit.SS = 0;				// Select Strobe mode : 0(normal mode)
	Emif1Regs.ASYNC_CS4_CR.bit.EW = 0;				// Extend Wait mode
	Emif1Regs.ASYNC_CS4_CR.bit.TA = 0;				// Turn Around cycles
	Emif1Regs.ASYNC_CS4_CR.bit.ASIZE = 1;			// Asynchronous Memory size : 1(16 bit data bus)

	// Write cycle
	Emif1Regs.ASYNC_CS4_CR.bit.W_SETUP = 4;			// Write Strobe Setup cycles
	Emif1Regs.ASYNC_CS4_CR.bit.W_STROBE = 10;		// Write Strobe Duration cycles
	Emif1Regs.ASYNC_CS4_CR.bit.W_HOLD = 4;			// Write Strobe Hold cycles

	// Read cycle
	Emif1Regs.ASYNC_CS4_CR.bit.R_SETUP = 4;			// Read Strobe Setup cycles
	Emif1Regs.ASYNC_CS4_CR.bit.R_STROBE = 10;		// Read Strobe Duration cycles
	Emif1Regs.ASYNC_CS4_CR.bit.R_HOLD = 4;			// Read Strobe Hold cycles

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
