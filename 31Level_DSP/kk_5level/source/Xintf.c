/*
 * Xintf.c
 *
 *  Created on: 2012. 9. 11.
 *      Author: HJHeo
 */

#include "Define_Header.h"

void Init_Xintf(void)
{
	EALLOW;
//-------------------------------------------------------------------------------------------------//
//--------------------------------------------All  Zone--------------------------------------------//
//-------------------------------------------------------------------------------------------------//

	XintfRegs.XINTCNF2.bit.WRBUFF = 0;

//-------------------------------------------------------------------------------------------------//
//---------------------------------------------Zone  0---------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// Zone Write Timing
	XintfRegs.XTIMING0.bit.XWRLEAD = 3;
	XintfRegs.XTIMING0.bit.XWRACTIVE = 7;
	XintfRegs.XTIMING0.bit.XWRTRAIL = 3;

	// Zone Read Timing
    XintfRegs.XTIMING0.bit.XRDLEAD = 3;
    XintfRegs.XTIMING0.bit.XRDACTIVE = 7;
    XintfRegs.XTIMING0.bit.XRDTRAIL = 3;

    // double all Zone read/write lead/active/trail timing
    XintfRegs.XTIMING0.bit.X2TIMING = 1;

    // Zone will sample XREADY signal
    XintfRegs.XTIMING0.bit.USEREADY = 0;
    XintfRegs.XTIMING0.bit.READYMODE = 1;  // sample asynchronous

    // Bus Bit
    XintfRegs.XTIMING0.bit.XSIZE = 3;

//-------------------------------------------------------------------------------------------------//
//---------------------------------------------Zone  6---------------------------------------------//
//-------------------------------------------------------------------------------------------------//
    // Zone write timing
	XintfRegs.XTIMING6.bit.XWRLEAD = 3;
	XintfRegs.XTIMING6.bit.XWRACTIVE = 7;
	XintfRegs.XTIMING6.bit.XWRTRAIL = 3;

	// Zone read timing
	XintfRegs.XTIMING6.bit.XRDLEAD = 3;
	XintfRegs.XTIMING6.bit.XRDACTIVE = 7;
	XintfRegs.XTIMING6.bit.XRDTRAIL = 3;

	// double all Zone read/write lead/active/trail timing
	XintfRegs.XTIMING6.bit.X2TIMING = 1;

	// Zone will sample XREADY signal
	XintfRegs.XTIMING6.bit.USEREADY = 0;
	XintfRegs.XTIMING6.bit.READYMODE = 1;  // sample asynchronous

	// Bus Bit
	XintfRegs.XTIMING6.bit.XSIZE = 3;

//-------------------------------------------------------------------------------------------------//
//---------------------------------------------Zone  7---------------------------------------------//
//-------------------------------------------------------------------------------------------------//
	// Zone write timing
	XintfRegs.XTIMING7.bit.XWRLEAD = 3;
	XintfRegs.XTIMING7.bit.XWRACTIVE = 7;
	XintfRegs.XTIMING7.bit.XWRTRAIL = 3;
	// Zone read timing
	XintfRegs.XTIMING7.bit.XRDLEAD = 3;
	XintfRegs.XTIMING7.bit.XRDACTIVE = 7;
	XintfRegs.XTIMING7.bit.XRDTRAIL = 3;

	// double all Zone read/write lead/active/trail timing
	XintfRegs.XTIMING7.bit.X2TIMING = 1;

	// Zone will sample XREADY signal
	XintfRegs.XTIMING7.bit.USEREADY = 0;
	XintfRegs.XTIMING7.bit.READYMODE = 1;  // sample asynchronous

	// Bus Bit
	XintfRegs.XTIMING7.bit.XSIZE = 3;

	// Bank switching
	// Assume Zone 7 is slow, so add additional BCYC cycles
	// when ever switching from Zone 7 to another Zone.
	// This will help avoid bus contention.
	XintfRegs.XBANK.bit.BANK = 0;
	XintfRegs.XBANK.bit.BCYC = 7;

	EDIS;

	asm(" RPT #7 || NOP");

	return;
}
