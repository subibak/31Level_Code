/*
 * 2837xD_RAM_lnk_cpu2.cmd
 *
 *   Edited on: 2019. 06. 22.
 *      Author: TI Co.
 *		Editor: HJHeo
 *
 */

MEMORY
{
PAGE 0:														// Program Memory
	RAM_BEGIN			: org = 0x000000,	len = 0x000002		// SARAM Boot Mode Entry Point of CPU2
	RAMM0				: org = 0x000080,	len = 0x000380		// On-Chip RAM Block M0 of CPU2
	RAMLS0				: org = 0x008000,	len = 0x000800		// On-Chip RAM Block LS0 of CPU2
	RAMLS1				: org = 0x008800,	len = 0x000800		// On-Chip RAM Block LS1 of CPU2
	RAMLS2				: org = 0x009000,	len = 0x000800		// On-Chip RAM Block LS2 of CPU2
	RAMLS3				: org = 0x009800,	len = 0x000800		// On-Chip RAM Block LS3 of CPU2
	RAMD0				: org = 0x00B000,	len = 0x000800		// On-Chip RAM Block D0 of CPU2

	RAMGS0(R)			: org = 0x00C000,	len = 0x001000		// On-Chip RAM Block GS0 : CPU1 Program Memory
	RAMGS1(R)			: org = 0x00D000,	len = 0x001000		// On-Chip RAM Block GS1 : CPU1 Program Memory
	RAMGS2(R)			: org = 0x00E000,	len = 0x001000		// On-Chip RAM Block GS2 : CPU1 Program Memory
	RAMGS3(R)			: org = 0x00F000,	len = 0x001000		// On-Chip RAM Block GS3 : CPU1 Program Memory
	RAMGS4(R)			: org = 0x010000,	len = 0x001000		// On-Chip RAM Block GS4 : CPU1 Program Memory

	RAMGS8				: org = 0x014000,	len = 0x001000		// On-Chip RAM Block GS8 : CPU2 Program Memory
	RAMGS9				: org = 0x015000,	len = 0x001000		// On-Chip RAM Block GS8 : CPU2 Program Memory
	RAMGS10				: org = 0x016000,	len = 0x001000		// On-Chip RAM Block GS8 : CPU2 Program Memory
	RAMGS11				: org = 0x017000,	len = 0x001000		// On-Chip RAM Block GS8 : CPU2 Program Memory
	RAMGS12				: org = 0x018000,	len = 0x001000		// On-Chip RAM Block GS8 : CPU2 Program Memory

															// Flash Memory
	FLASH_BEGIN			: org = 0x080000,	len = 0x000002		// FLASH Boot Mode Entry Point of CPU2
	FLASHA				: org = 0x080002,	len = 0x001FFE		// On-Chip FLASH Block A of CPU2
	FLASHB				: org = 0x082000,	len = 0x002000		// On-Chip FLASH Block B of CPU2
	FLASHC				: org = 0x084000,	len = 0x002000		// On-Chip FLASH Block C of CPU2
	FLASHD				: org = 0x086000,	len = 0x002000		// On-Chip FLASH Block D of CPU2
	FLASHE				: org = 0x088000,	len = 0x008000		// On-Chip FLASH Block E of CPU2
	FLASHF				: org = 0x090000,	len = 0x008000		// On-Chip FLASH Block F of CPU2
	FLASHG				: org = 0x098000,	len = 0x008000		// On-Chip FLASH Block G of CPU2
	FLASHH				: org = 0x0A0000,	len = 0x008000		// On-Chip FLASH Block H of CPU2
	FLASHI				: org = 0x0A8000,	len = 0x008000		// On-Chip FLASH Block I of CPU2
	FLASHJ				: org = 0x0B0000,	len = 0x008000		// On-Chip FLASH Block J of CPU2
	FLASHK				: org = 0x0B8000,	len = 0x002000		// On-Chip FLASH Block K of CPU2
	FLASHL				: org = 0x0BA000,	len = 0x002000		// On-Chip FLASH Block L of CPU2
	FLASHM				: org = 0x0BC000,	len = 0x002000		// On-Chip FLASH Block M of CPU2
	FLASHN				: org = 0x0BE000,	len = 0x002000		// On-Chip FLASH Block N of CPU2

	RESET				: org = 0x3FFFC0,	len = 0x000002		//

PAGE 1:														// Data Memory
	BOOT_RSVD			: org = 0x000002,	len = 0x00007E		// Part of M0, BOOT ROM will Use this for Stack
	RAMM1				: org = 0x000400,	len = 0x000400		// On-Chip RAM Block M1 of CPU2
	RAMLS4				: org = 0x00A000,	len = 0x000800		// On-Chip RAM Block LS4 of CPU2
	RAMLS5				: org = 0x00A800,	len = 0x000800		// On-Chip RAM Block LS5 of CPU2
	RAMD1				: org = 0x00B800,	len = 0x000800		// On-Chip RAM Block D1 of CPU2

	RAMGS5(R)			: org = 0x011000,	len = 0x001000		// On-Chip RAM Block GS5 : CPU1 Data Memory
	RAMGS6(R)			: org = 0x012000,	len = 0x001000		// On-Chip RAM Block GS6 : CPU1 Data Memory
	RAMGS7(R)			: org = 0x013000,	len = 0x001000		// On-Chip RAM Block GS7 : CPU1 Data Memory

	RAMGS13				: org = 0x019000,	len = 0x001000		// On-Chip RAM Block GS13 : CPU2 Data Memory
	RAMGS14				: org = 0x01A000,	len = 0x001000		// On-Chip RAM Block GS14 : CPU2 Data Memory
	RAMGS15				: org = 0x01B000,	len = 0x001000		// On-Chip RAM Block GS15 : CPU2 Data Memory

	CPU2TOCPU1RAM		: org = 0x03F800,	len = 0x000400
	CPU1TOCPU2RAM(R)	: org = 0x03FC00,	len = 0x000400

	CANA_MSG_RAM		: org = 0x049000,	len = 0x000800
	CANB_MSG_RAM		: org = 0x04B000,	len = 0x000800
}

SECTIONS
{
	codestart			:> RAM_BEGIN,								PAGE = 0
	.reset				:> RESET,									PAGE = 0,	TYPE = DSECT

#ifdef __TI_COMPILER_VERSION__
	#if __TI_COMPILER_VERSION__ >= 15009000
	.TI.ramfunc			: {} > RAMM0,								PAGE = 0
	#else
	ramfuncs			:> RAMM0,									PAGE = 0
	#endif
#endif

	// Allocate Program Area
	.cinit				:> RAMM0,									PAGE = 0					// Tables which Initialize Global Variables.
	.pinit				:> RAMM0,									PAGE = 0					// Table of C++ Constructors Called at Startup.
	.cio				:> RAMM0,									PAGE = 0					// Buffer for stdio Functions.
	.text				>> RAMGS8 | RAMGS9,							PAGE = 0					// Executable Code and Constant.

	// Allocate Uninitialized Data Section
	.stack				:> RAMM1,									PAGE = 1					// System Stack
	.esysmem			:> RAMLS4,									PAGE = 1					// Large Memory Model of Malloc Heap.
	.ebss				:> RAMLS5,									PAGE = 1					// Large Memory Model of Global Variables.

	// Allocate Initialized Data Section
	.switch				:> RAMM0,									PAGE = 0					// Jump Tables for Certain Switch Statements.
	.econst				:> RAMLS5,									PAGE = 1					// Initialized Global Variables.
}
