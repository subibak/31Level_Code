/*
 * 2837xD_RAM_lnk_cpu1.cmd
 *
 *   Edited on  : 2018. 9. 21.
 *      Author  : TI Co.
 *   Revised on : 2018.09.23
 *		Revisor : subi
 */

MEMORY
{
PAGE 0 :
	/* BEGIN is Used for the "Boot to SARAM" Bootloader Mode */
	RAM_BEGIN		: org = 0x000000, len = 0x000002		// SARAM Boot Mode Entry Point of CPU1
	RAMM0			: org = 0x000122, len = 0x0002DE		// On-Chop RAM Block M0 of CPU1
	RAMLS0			: org = 0x008000, len = 0x000800		//
	RAMLS1			: org = 0x008800, len = 0x000800		//
	RAMLS2			: org = 0x009000, len = 0x000800		//
	RAMLS3			: org = 0x009800, len = 0x000800		//
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
	FLASHB			: org = 0x082000, len = 0x002000		// On-Chip Flash
	FLASHC			: org = 0x084000, len = 0x002000		// On-Chip Flash
	FLASHD			: org = 0x086000, len = 0x002000		// On-Chip Flash
	FLASHE			: org = 0x088000, len = 0x008000		// On-Chip Flash
	FLASHF			: org = 0x090000, len = 0x008000		// On-Chip Flash
	FLASHG			: org = 0x098000, len = 0x008000		// On-Chip Flash
	FLASHH			: org = 0x0A0000, len = 0x008000		// On-Chip Flash
	FLASHI			: org = 0x0A8000, len = 0x008000		// On-Chip Flash
	FLASHJ			: org = 0x0B0000, len = 0x008000		// On-Chip Flash
	FLASHK			: org = 0x0B8000, len = 0x002000		// On-Chip Flash
	FLASHL			: org = 0x0BA000, len = 0x002000		// On-Chip Flash
	FLASHM			: org = 0x0BC000, len = 0x002000		// On-Chip Flash
	FLASHN			: org = 0x0BE000, len = 0x002000		// On-Chip Flash

PAGE 1 :
	BOOT_RSVD		: org = 0x000002, len = 0x000120		//// Part of M0, BOOT ROM will Use this for Stack
	RAMM1			: org = 0x000400, len = 0x000400		// On-Chip RAM Block M1 of CPU1
	RAMLS45			: org = 0x00A000, len = 0x001000		//
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
	codestart		: > RAM_BEGIN,	 PAGE = 0					//

	ramfuncs		: > RAMM0,		 PAGE = 0					//
   
   .text            : > RAMGS05, 	 PAGE = 0					// Executable Code and Constant.
   .cinit           : > RAMLS0,  	 PAGE = 0					// Initialized Global and Static Variables.
   .pinit           : > RAMM0,   	 PAGE = 0					// Table of C++ constructors called at startup
   .switch          : > RAMM0,   	 PAGE = 0					// Jump tables for certain switch statements
    .reset          : > RESET,   	 PAGE = 0, TYPE = DSECT		// Reset Vector

   .stack           : > RAMM1,    	 PAGE = 1					// System Stack.
   .ebss            : > RAMLS45,  	 PAGE = 1					// Global and Static Variables.
   .econst          : > RAMLS45,  	 PAGE = 1					// Initialized Global variables
   .esysmem         : > RAMLS45, 	 PAGE = 1					// malloc heap
}

