/*
 * FPGA.cmd
 *
 *	Created on: 2018. 9. 22.
 *		Author: HJHeo
 */

MEMORY
{
PAGE 0:

PAGE 1:
	EMIF1_CS0_SDRAM	: org = 0x80000000, len = 0x10000000				// EMIF1 CS0 Memory Address (256M x 16)
	EMIF1_CS2		: org = 0x00100000, len = 0x00200000				// EMIF1 CS2 Memory Address	(2M x 16)
	EMIF1_CS3		: org = 0x00300000, len = 0x00080000				// EMIF1 CS3 Memory Address	(512k x 16)
	EMIF1_CS4		: org = 0x00380000, len = 0x00060000				// EMIF1 CS4 Memory Address	(393k x 16)

	EMIF2_CS0_SDRAM	: org = 0x90000000, len = 0x02000000				// EMIF2 CS0 Memory Address (3M x16)
	EMIF2_CS2		: org = 0x00002000, len = 0x00001000				// EMIF2 CS2 Memory Address (4k x 16)
}

SECTIONS
{
	FpgaCs2RegsFile	:> EMIF1_CS2,				PAGE = 1
}
