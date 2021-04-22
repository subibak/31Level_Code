/*
 * FPGA_GPIO.h
 *
 *  Created on: 2020. 10. 16.
 *      Author: subi
 */

#ifndef INCLUDE_FPGA_FPGA_GPIO_H_
#define INCLUDE_FPGA_FPGA_GPIO_H_



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

struct FPGA_GPIO_BITS {
    Uint16 GPIO0:1;
    Uint16 GPIO1:1;
    Uint16 GPIO2:1;
    Uint16 GPIO3:1;
    Uint16 GPIO4:1;
    Uint16 GPIO5:1;
    Uint16 GPIO6:1;
    Uint16 GPIO7:1;
    Uint16 GPIO8:1;
    Uint16 GPIO9:1;
    Uint16 GPIO10:1;
    Uint16 GPIO11:1;
    Uint16 GPIO12:1;
    Uint16 GPIO13:1;
    Uint16 GPIO14:1;
    Uint16 GPIO15:1;
};

union FPGA_GPIO_REG {
    Uint16                      all;
    struct FPGA_GPIO_BITS       bit;
};

struct FPGA_GPIO_REGS {
    union FPGA_GPIO_REG         DIR;    // 0x0000
    union FPGA_GPIO_REG         DAT;    // 0x0001
    union FPGA_GPIO_REG         SET;    // 0x0002
    union FPGA_GPIO_REG         CLR;    // 0x0003
};

#endif /* INCLUDE_CYCLONE4_CYCLONE4_GPIO_H_ */
