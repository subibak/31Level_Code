/*
 * FPGA_RAM.cmd
 *
 *  Created on: 2020. 10. 17.
 *      Author: subi
 */


MEMORY
{
PAGE 0:

PAGE 1:
	EMIF1_CS2		: org = 0x00100000, len = 0x00200000
	EMIF1_CS3		: org = 0x00300000, len = 0x00080000
	EMIF1_CS4		: org = 0x00380000, len = 0x00060000
}

SECTIONS
{
	FpgaCs2RegsFile		:> EMIF1_CS2, 				PAGE = 1
}
