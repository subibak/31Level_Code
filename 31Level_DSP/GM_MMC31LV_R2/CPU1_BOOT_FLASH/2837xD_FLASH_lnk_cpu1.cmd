/*
 * 2837xD_RAM_lnk_cpu1.cmd
 *
 *   Edited on: 2018. 9. 19.
 *      Author  : TI Co.
 *		Editor  : HJHeo
 *   Revised on : 2018.09.21
 *		Revisor : subi
 */

MEMORY
{
PAGE 0:													// Program Memory
	/* BEGIN is Used for the "Boot to SARAM" Bootloader Mode */

	RAM_BEGIN		: org = 0x000000, len = 0x000002		// SARAM Boot Mode Entry Point of CPU1
	RAMM0			: org = 0x000122, len = 0x0002DE		// On-Chop RAM Block M0 of CPU1
	RAMLS0			: org = 0x008000, len = 0x000800		//
	RAMLS1			: org = 0x008800, len = 0x000800		//
	RAMD0			: org = 0x00B000, len = 0x000800		//
	RESET			: org = 0x3FFFC0, len = 0x000002		//

	RAMGS05			: org = 0x00C000, len = 0x006000		// CPU1 Program Memory RAMGS0~5 because of FLASH LOAD RUN copy structure
//	RAMGS1			: org = 0x00D000, len = 0x001000		// CPU1 Program Memory
//	RAMGS2			: org = 0x00E000, len = 0x001000		// CPU1 Program Memory
//	RAMGS3			: org = 0x00F000, len = 0x001000		// CPU1 Data Memory
//	RAMGS4			: org = 0x010000, len = 0x001000		// CPU1 Data Memory
//	RAMGS5			: org = 0x011000, len = 0x001000		// CPU1 Data Memory
	RAMGS810		: org = 0x014000, len = 0x003000		// CPU2 Program Memory  RAMGS8~10 because of FLASH LOAD RUN copy structure
//	RAMGS9			: org = 0x015000, len = 0x001000		// CPU2 Program Memory
//	RAMGS10			: org = 0x016000, len = 0x001000		// CPU2 Program Memory

	FLASH_BEGIN		: org = 0x080000, len = 0x000002		// Flash Boot Mode Entry Point of CPUx
	FLASHA			: org = 0x080002, len = 0x001FFE		// On-Chip Flash
	FLASHBC			: org = 0x082000, len = 0x004000		// On-Chip Flash
//	FLASHC			: org = 0x084000, len = 0x002000		// On-Chip Flash
	FLASHD			: org = 0x086000, len = 0x002000		// On-Chip Flash
	FLASHEFGHI		: org = 0x088000, len = 0x028000		// On-Chip Flash

//	FLASHF			: org = 0x090000, len = 0x008000		// On-Chip Flash
//	FLASHG			: org = 0x098000, len = 0x008000		// On-Chip Flash
//	FLASHH			: org = 0x0A0000, len = 0x008000		// On-Chip Flash
//	FLASHI			: org = 0x0A8000, len = 0x008000		// On-Chip Flash
	FLASHJ			: org = 0x0B0000, len = 0x008000		// On-Chip Flash
	FLASHK			: org = 0x0B8000, len = 0x002000		// On-Chip Flash
	FLASHL			: org = 0x0BA000, len = 0x002000		// On-Chip Flash
	FLASHM			: org = 0x0BC000, len = 0x002000		// On-Chip Flash
	FLASHN			: org = 0x0BE000, len = 0x002000		// On-Chip Flash

PAGE 1:													// Data Memory

	BOOT_RSVD		: org = 0x000002, len = 0x000120		//// Part of M0, BOOT ROM will Use this for Stack
	RAMM1			: org = 0x000400, len = 0x000400		// On-Chip RAM Block M1 of CPU1
	RAMLS2345		: org = 0x009000, len = 0x002000		//
//	RAMLS3			: org = 0x009800, len = 0x000800		//
//	RAMLS4			: org = 0x00A000, len = 0x000800		//
//	RAMLS5			: org = 0x00A800, len = 0x000800		//
	RAMD1			: org = 0x00B800, len = 0x000800		//

	RAMGS6			: org = 0x012000, len = 0x001000		// CPU1 Data Memory
	RAMGS7			: org = 0x013000, len = 0x001000		// CPU1 Data Memory
	RAMGS11			: org = 0x017000, len = 0x001000		// CPU2 Program Memory
	RAMGS12			: org = 0x018000, len = 0x001000		// CPU2 Program Memory
	RAMGS13			: org = 0x019000, len = 0x001000		// CPU2 Data Memory
	RAMGS14			: org = 0x01A000, len = 0x001000		// CPU2 Data Memory
	RAMGS15			: org = 0x01B000, len = 0x001000		// CPU2 Data Memory
}

SECTIONS
{
	codestart		:> FLASH_BEGIN,									PAGE = 0					//
	wddisable		:> FLASHA,										PAGE = 0					//
	copysections	:> FLASHA,										PAGE = 0					//

	ramfuncs		: LOAD = FLASHA,								PAGE = 0					//
					  RUN =  RAMM0,									PAGE = 0
					  LOAD_START(_ramfunc_loadstart),
					  RUN_START(_ramfunc_runstart),
					  SIZE(_ramfunc_size)

	.text			: LOAD = FLASHEFGHI, 						   	PAGE = 0 					// Executable Code and Constant.
					  RUN = RAMGS05,	      						PAGE = 0
					  LOAD_START(_text_loadstart),
					  RUN_START(_text_runstart),
					  SIZE(_text_size)
	.cinit			: LOAD = FLASHA,								PAGE = 0					// Initialized Global and Static Variables.
					  RUN = RAMLS0,									PAGE = 0
					  LOAD_START(_cinit_loadstart),
					  RUN_START(_cinit_runstart),
					  SIZE(_cinit_size)
	.pinit			: LOAD = FLASHA,								PAGE = 0					// Table of C++ constructors called at startup
					  RUN = RAMM0,									PAGE = 0
					  LOAD_START(_pinit_loadstart),
					  RUN_START(_pinit_runstart),
					  SIZE(_pinit_size)
	.switch			: LOAD = FLASHA,								PAGE = 0					// Jump tables for certain switch statements
					  RUN = RAMM0,									PAGE = 0
					  LOAD_START(_switch_loadstart),
					  RUN_START(_switch_runstart),
					  SIZE(_switch_size)

	.reset			:> RESET,										PAGE = 0,	TYPE = DSECT	// Reset Vector

	.stack			:> RAMM1,										PAGE = 1					// System Stack
	.ebss			:> RAMLS2345,									PAGE = 1					// Global and Static Variables.

	.econst			: LOAD = FLASHBC,								PAGE = 0					// Initialized Global variables
					  RUN = RAMLS2345,								PAGE = 1
					  LOAD_START(_econst_loadstart),
					  RUN_START(_econst_runstart),
					  SIZE(_econst_size)
   .esysmem         :> RAMLS2345,    							 	PAGE = 1														// malloc heap

	/* The Following Section Definitions Are Required When Using the IPC API Drivers */
/*
	GROUP			:> CPU1TOCPU2RAM,								PAGE = 1
	{
		PUTBUFFER
		PUTWRITEIDX
		GETREADIDX
	}
	GROUP			:> CPU2TOCPU1RAM,								PAGE = 1
	{
		GETBUFFER	:	TYPE = DSECT
		GETWRITEIDX	:	TYPE = DSECT
		PUTREADIDX	:	TYPE = DSECT
	}
*/
}
