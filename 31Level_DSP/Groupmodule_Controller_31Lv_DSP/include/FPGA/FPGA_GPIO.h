/*
 * FPGA_GPIO.h
 *
 *  Created on: 2020. 10. 7.
 *      Author: subi
 */

#ifndef INCLUDE_FPGA_FPGA_GPIO_H_
#define INCLUDE_FPGA_FPGA_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

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

#define CLEAR_DATA                          ((volatile int *)(0x00300110))          //0001 0001 0000

//LED address
#define LED_FPGA_EN                         ((volatile int *)(0x00100001))          //0000 0000 0001

//RS422 address
#define RS422_TX_SET                        ((volatile int *)(0x00100002))          //0000 0000 0010
#define RS422_TX_NUM                        ((volatile int *)(0x00100004))          //0000 0000 0100
#define RS422_TX_FAULT                      ((volatile int *)(0x00100005))          //0000 0000 0101
#define RS422_TX_BYTEREADY                  ((volatile int *)(0x00100006))          //0000 0000 0101
#define RS422_TX_TBYTE                      ((volatile int *)(0x00100007))          //0000 0000 0101
#define RS422_TX_LOAD                       ((volatile int *)(0x00100009))          //0000 0000 0101

#define RS422_TX_REGISTER                   ((volatile int *)(0x00100008))          //0000 0000 1000
#define RS422_TX_AUX_SET                    ((volatile int *)(0x0010000B))          //0000 0000 1011


struct FPGA_GPIOx_BITS{
    Uint16              GPIO0:1;                //FPGA GPIO0 bit
    Uint16              GPIO1:1;                //FPGA GPIO1 bit
    Uint16              GPIO2:1;                //FPGA GPIO2 bit
    Uint16              GPIO3:1;                //FPGA GPIO3 bit
    Uint16              GPIO4:1;                //FPGA GPIO4 bit
    Uint16              GPIO5:1;                //FPGA GPIO5 bit
    Uint16              GPIO6:1;                //FPGA GPIO6 bit
    Uint16              GPIO7:1;                //FPGA GPIO7 bit
    Uint16              GPIO8:1;                //FPGA GPIO8 bit
    Uint16              GPIO9:1;                //FPGA GPIO9 bit
    Uint16              GPIO10:1;               //FPGA GPIO10 bit
    Uint16              GPIO12:1;               //FPGA GPIO12 bit
    Uint16              GPIO13:1;               //FPGA GPIO13 bit
    Uint16              GPIO14:1;               //FPGA GPIO14 bit
    Uint16              GPIO15:1;               //FPGA GPIO15 bit
};

union FPGA_GPIOx_REG {
    Uint16                      all;
    struct FPGA_GPIOx_BITS      bit;
};

struct FPGA_GPIOx_DATA_REG {
    union FPGA_GPIOx_REG    DIR;                //FPGA GPIO Direction (0: Input, 1: Output)
    union FPGA_GPIOx_REG    DAT;                //FPGA GPIO Data
    union FPGA_GPIOx_REG    SET;                //FPGA GPIO Output SET (1: SET, 0: No action)
    union FPGA_GPIOx_REG    CLEAR;              //FPGA GPIO Output CLEAR (1: Clear, 1: No action)
};

struct FPGA_EMIF1_CS2_REGS {
    struct FPGA_GPIOx_DATA_REG  GPA;            //0x0010 0000 FPGA GPIO A-Group Register
};


#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_FPGA_FPGA_GPIO_H_ */
