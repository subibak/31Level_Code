/*
 * FPGA_struct.h
 *
 *  Created on: 2020. 10. 17.
 *      Author: subi
 */

#ifndef INCLUDE_FPGA_FPGA_STRUCT_H_
#define INCLUDE_FPGA_FPGA_STRUCT_H_


// EMIF1
// cs0n 0x8000 0000 - 8FFF FFFF         // Data
//(Asynchronous memory access 2n, 3n, 4n)
// As the default values of ADDR in FPGA is 000 and FFF, do not use these effective addresses not to cause some malfunction.
// A0 takes on A1's bit and EM1BA1 takes A0's bit
// cs2n 0x0010 0000 - 002F FFFF         // Program + Data effective address FFF
// cs3n 0x0030 0000 - 0037 FFFF         // Program + Data
// cs4n 0x0038 0000 - 003D FFFF         // Program + Data

// EMIF2(EtherCAT)
// cs0n 0x9000 0000 - 91FF FFFF         // Data
// cs2n 0x0000 2000 - 0000 2FFF         // Program + Data

struct FPGA_CS2_REGS {
    struct FPGA_GPIO_REGS       GPA;                // 0x0010 0000 - 0x0010 0003
    struct FPGA_GPIO_REGS       GPB;                // 0x0010 0004 - 0x0010 0007
    struct FPGA_GPIO_REGS       GPC;                // 0x0010 0008 - 0x0010 000B
    struct FPGA_GPIO_REGS       GPD;                // 0x0010 000C - 0x0010 000F
    struct FPGA_GPIO_REGS       GPE;                // 0x0010 0010 - 0x0010 0013
    struct FPGA_GPIO_REGS       GPF;                // 0x0010 0014 - 0x0010 0017
    struct FPGA_GPIO_REGS       GPG;                // 0x0010 0018 - 0x0010 001B
    struct FPGA_GPIO_REGS       GPH;                // 0x0010 001C - 0x0010 001F
};

#ifdef CPU2
extern volatile struct FPGA_CS2_REGS FpgaCs2Regs;
#endif
#endif /* INCLUDE_FPGA_FPGA_STRUCT_H_ */
