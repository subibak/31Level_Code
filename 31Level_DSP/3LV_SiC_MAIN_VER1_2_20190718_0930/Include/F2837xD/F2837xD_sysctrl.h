//###########################################################################
//
// FILE:    F2837xD_sysctrl.h
//
// TITLE:   F2837xD Device SYSCTRL Register Definitions.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 $
// $Release Date: Tue Nov  1 14:46:15 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xD_SYSCTRL_H__
#define __F2837xD_SYSCTRL_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SYSCTRL Individual Register Bit Definitions:

struct DEVCFGLOCK1_BITS {               // bits description
    Uint16 CPUSEL0:1;                   // 0 Lock bit for CPUSEL0 register
    Uint16 CPUSEL1:1;                   // 1 Lock bit for CPUSEL1 register
    Uint16 CPUSEL2:1;                   // 2 Lock bit for CPUSEL2 register
    Uint16 CPUSEL3:1;                   // 3 Lock bit for CPUSEL3 register
    Uint16 CPUSEL4:1;                   // 4 Lock bit for CPUSEL4 register
    Uint16 CPUSEL5:1;                   // 5 Lock bit for CPUSEL5 register
    Uint16 CPUSEL6:1;                   // 6 Lock bit for CPUSEL6 register
    Uint16 CPUSEL7:1;                   // 7 Lock bit for CPUSEL7 register
    Uint16 CPUSEL8:1;                   // 8 Lock bit for CPUSEL8 register
    Uint16 CPUSEL9:1;                   // 9 Lock bit for CPUSEL9 register
    Uint16 CPUSEL10:1;                  // 10 Lock bit for CPUSEL10 register
    Uint16 CPUSEL11:1;                  // 11 Lock bit for CPUSEL11 register
    Uint16 CPUSEL12:1;                  // 12 Lock bit for CPUSEL12 register
    Uint16 CPUSEL13:1;                  // 13 Lock bit for CPUSEL13 register
    Uint16 CPUSEL14:1;                  // 14 Lock bit for CPUSEL14 register
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DEVCFGLOCK1_REG {
    Uint32  all;
    struct  DEVCFGLOCK1_BITS  bit;
};

#ifdef CPU1
// DEVCFGLOCK1 Register
//// DEVCFGLOCK1 Register : Byte Value
#define DEVCFGLOCK1_CPUSEL14_Lock						0x00004000UL				// CPUSEL14 Register is Locked.
#define DEVCFGLOCK1_CPUSEL13_Lock						0x00002000UL				// CPUSEL13 Register is Locked.
#define DEVCFGLOCK1_CPUSEL12_Lock						0x00001000UL				// CPUSEL12 Register is Locked.
#define DEVCFGLOCK1_CPUSEL11_Lock						0x00000800UL				// CPUSEL11 Register is Locked.
#define DEVCFGLOCK1_CPUSEL10_Lock						0x00000400UL				// CPUSEL10 Register is Locked.
#define DEVCFGLOCK1_CPUSEL9_Lock						0x00000200UL				// CPUSEL9 Register is Locked.
#define DEVCFGLOCK1_CPUSEL8_Lock						0x00000100UL				// CPUSEL8 Register is Locked.
#define DEVCFGLOCK1_CPUSEL7_Lock						0x00000080UL				// CPUSEL7 Register is Locked.
#define DEVCFGLOCK1_CPUSEL6_Lock						0x00000040UL				// CPUSEL6 Register is Locked.
#define DEVCFGLOCK1_CPUSEL5_Lock						0x00000020UL				// CPUSEL5 Register is Locked.
#define DEVCFGLOCK1_CPUSEL4_Lock						0x00000010UL				// CPUSEL4 Register is Locked.
#define DEVCFGLOCK1_CPUSEL3_Lock						0x00000008UL				// CPUSEL3 Register is Locked.
#define DEVCFGLOCK1_CPUSEL2_Lock						0x00000004UL				// CPUSEL2 Register is Locked.
#define DEVCFGLOCK1_CPUSEL1_Lock						0x00000002UL				// CPUSEL1 Register is Locked.
#define DEVCFGLOCK1_CPUSEL0_Lock						0x00000001UL				// CPUSEL0 Register is Locked.

//// DEVCFGLOCK1 Register : Quick Value
#define DEVCFGLOCK1_CPUSEL_AllLock						0x00007FFF					// CPUSEL14 - CPUSEL0 Register is Locked.
#endif

struct PARTIDL_BITS {                   // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 rsvd2:2;                     // 4:3 Reserved
    Uint16 rsvd3:1;                     // 5 Reserved
    Uint16 QUAL:2;                      // 7:6 Qualification Status
    Uint16 PIN_COUNT:3;                 // 10:8 Device Pin Count
    Uint16 rsvd4:1;                     // 11 Reserved
    Uint16 rsvd5:1;                     // 12 Reserved
    Uint16 INSTASPIN:2;                 // 14:13 Motorware feature set
    Uint16 rsvd6:1;                     // 15 Reserved
    Uint16 FLASH_SIZE:8;                // 23:16 Flash size in KB
    Uint16 rsvd7:4;                     // 27:24 Reserved
    Uint16 PARTID_FORMAT_REVISION:4;    // 31:28 Revision of the PARTID format
};

union PARTIDL_REG {
    Uint32  all;
    struct  PARTIDL_BITS  bit;
};

struct PARTIDH_BITS {                   // bits description
    Uint16 rsvd1:8;                     // 7:0 Reserved
    Uint16 FAMILY:8;                    // 15:8 Device family
    Uint16 PARTNO:8;                    // 23:16 Device part number
    Uint16 DEVICE_CLASS_ID:8;           // 31:24 Device class ID
};

union PARTIDH_REG {
    Uint32  all;
    struct  PARTIDH_BITS  bit;
};

struct DC0_BITS {                       // bits description
    Uint16 SINGLE_CORE:1;               // 0 Single Core vs Dual Core 
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC0_REG {
    Uint32  all;
    struct  DC0_BITS  bit;
};

struct DC1_BITS {                       // bits description
    Uint16 CPU1_FPU_TMU:1;              // 0 CPU1's FPU1+TMU1 
    Uint16 CPU2_FPU_TMU:1;              // 1 CPU2's FPU2+TMU2 
    Uint16 CPU1_VCU:1;                  // 2 CPU1's VCU 
    Uint16 CPU2_VCU:1;                  // 3 CPU2's VCU 
    Uint16 rsvd1:2;                     // 5:4 Reserved
    Uint16 CPU1_CLA1:1;                 // 6 CPU1.CLA1 
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 CPU2_CLA1:1;                 // 8 CPU2.CLA1 
    Uint16 rsvd3:1;                     // 9 Reserved
    Uint16 rsvd4:6;                     // 15:10 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union DC1_REG {
    Uint32  all;
    struct  DC1_BITS  bit;
};

struct DC2_BITS {                       // bits description
    Uint16 EMIF1:1;                     // 0 EMIF1 
    Uint16 EMIF2:1;                     // 1 EMIF2 
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC2_REG {
    Uint32  all;
    struct  DC2_BITS  bit;
};

struct DC3_BITS {                       // bits description
    Uint16 EPWM1:1;                     // 0 EPWM1 
    Uint16 EPWM2:1;                     // 1 EPWM2 
    Uint16 EPWM3:1;                     // 2 EPWM3 
    Uint16 EPWM4:1;                     // 3 EPWM4 
    Uint16 EPWM5:1;                     // 4 EPWM5 
    Uint16 EPWM6:1;                     // 5 EPWM6 
    Uint16 EPWM7:1;                     // 6 EPWM7 
    Uint16 EPWM8:1;                     // 7 EPWM8 
    Uint16 EPWM9:1;                     // 8 EPWM9 
    Uint16 EPWM10:1;                    // 9 EPWM10 
    Uint16 EPWM11:1;                    // 10 EPWM11 
    Uint16 EPWM12:1;                    // 11 EPWM12 
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 rsvd2:1;                     // 13 Reserved
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 rsvd4:1;                     // 15 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union DC3_REG {
    Uint32  all;
    struct  DC3_BITS  bit;
};

struct DC4_BITS {                       // bits description
    Uint16 ECAP1:1;                     // 0 ECAP1 
    Uint16 ECAP2:1;                     // 1 ECAP2 
    Uint16 ECAP3:1;                     // 2 ECAP3 
    Uint16 ECAP4:1;                     // 3 ECAP4 
    Uint16 ECAP5:1;                     // 4 ECAP5 
    Uint16 ECAP6:1;                     // 5 ECAP6 
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union DC4_REG {
    Uint32  all;
    struct  DC4_BITS  bit;
};

struct DC5_BITS {                       // bits description
    Uint16 EQEP1:1;                     // 0 EQEP1 
    Uint16 EQEP2:1;                     // 1 EQEP2 
    Uint16 EQEP3:1;                     // 2 EQEP3 
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union DC5_REG {
    Uint32  all;
    struct  DC5_BITS  bit;
};

struct DC7_BITS {                       // bits description
    Uint16 SD1:1;                       // 0 SD1 
    Uint16 SD2:1;                       // 1 SD2 
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:1;                     // 5 Reserved
    Uint16 rsvd5:1;                     // 6 Reserved
    Uint16 rsvd6:1;                     // 7 Reserved
    Uint16 rsvd7:8;                     // 15:8 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union DC7_REG {
    Uint32  all;
    struct  DC7_BITS  bit;
};

struct DC8_BITS {                       // bits description
    Uint16 SCI_A:1;                     // 0 SCI_A 
    Uint16 SCI_B:1;                     // 1 SCI_B 
    Uint16 SCI_C:1;                     // 2 SCI_C 
    Uint16 SCI_D:1;                     // 3 SCI_D 
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC8_REG {
    Uint32  all;
    struct  DC8_BITS  bit;
};

struct DC9_BITS {                       // bits description
    Uint16 SPI_A:1;                     // 0 SPI_A 
    Uint16 SPI_B:1;                     // 1 SPI_B 
    Uint16 SPI_C:1;                     // 2 SPI_C 
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:1;                     // 16 Reserved
    Uint16 rsvd4:1;                     // 17 Reserved
    Uint16 rsvd5:14;                    // 31:18 Reserved
};

union DC9_REG {
    Uint32  all;
    struct  DC9_BITS  bit;
};

struct DC10_BITS {                      // bits description
    Uint16 I2C_A:1;                     // 0 I2C_A 
    Uint16 I2C_B:1;                     // 1 I2C_B 
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:1;                     // 16 Reserved
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 rsvd4:14;                    // 31:18 Reserved
};

union DC10_REG {
    Uint32  all;
    struct  DC10_BITS  bit;
};

struct DC11_BITS {                      // bits description
    Uint16 CAN_A:1;                     // 0 CAN_A 
    Uint16 CAN_B:1;                     // 1 CAN_B 
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:12;                    // 15:4 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union DC11_REG {
    Uint32  all;
    struct  DC11_BITS  bit;
};

struct DC12_BITS {                      // bits description
    Uint16 McBSP_A:1;                   // 0 McBSP_A 
    Uint16 McBSP_B:1;                   // 1 McBSP_B 
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 USB_A:2;                     // 17:16 Decides the capability of the USB_A Module
    Uint16 rsvd2:2;                     // 19:18 Reserved
    Uint16 rsvd3:12;                    // 31:20 Reserved
};

union DC12_REG {
    Uint32  all;
    struct  DC12_BITS  bit;
};

struct DC13_BITS {                      // bits description
    Uint16 uPP_A:1;                     // 0 uPP_A 
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 rsvd2:14;                    // 15:2 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union DC13_REG {
    Uint32  all;
    struct  DC13_BITS  bit;
};

struct DC14_BITS {                      // bits description
    Uint16 ADC_A:1;                     // 0 ADC_A
    Uint16 ADC_B:1;                     // 1 ADC_B
    Uint16 ADC_C:1;                     // 2 ADC_C
    Uint16 ADC_D:1;                     // 3 ADC_D
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC14_REG {
    Uint32  all;
    struct  DC14_BITS  bit;
};

struct DC15_BITS {                      // bits description
    Uint16 CMPSS1:1;                    // 0 CMPSS1 
    Uint16 CMPSS2:1;                    // 1 CMPSS2 
    Uint16 CMPSS3:1;                    // 2 CMPSS3 
    Uint16 CMPSS4:1;                    // 3 CMPSS4 
    Uint16 CMPSS5:1;                    // 4 CMPSS5 
    Uint16 CMPSS6:1;                    // 5 CMPSS6 
    Uint16 CMPSS7:1;                    // 6 CMPSS7 
    Uint16 CMPSS8:1;                    // 7 CMPSS8 
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC15_REG {
    Uint32  all;
    struct  DC15_BITS  bit;
};

struct DC17_BITS {                      // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:12;                    // 15:4 Reserved
    Uint16 DAC_A:1;                     // 16 Buffered-DAC_A
    Uint16 DAC_B:1;                     // 17 Buffered-DAC_B
    Uint16 DAC_C:1;                     // 18 Buffered-DAC_C
    Uint16 rsvd6:1;                     // 19 Reserved
    Uint16 rsvd7:12;                    // 31:20 Reserved
};

union DC17_REG {
    Uint32  all;
    struct  DC17_BITS  bit;
};

struct DC18_BITS {                      // bits description
    Uint16 LS0_1:1;                     // 0 LS0_1 
    Uint16 LS1_1:1;                     // 1 LS1_1 
    Uint16 LS2_1:1;                     // 2 LS2_1 
    Uint16 LS3_1:1;                     // 3 LS3_1 
    Uint16 LS4_1:1;                     // 4 LS4_1 
    Uint16 LS5_1:1;                     // 5 LS5_1 
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC18_REG {
    Uint32  all;
    struct  DC18_BITS  bit;
};

struct DC19_BITS {                      // bits description
    Uint16 LS0_2:1;                     // 0 LS0_2 
    Uint16 LS1_2:1;                     // 1 LS1_2 
    Uint16 LS2_2:1;                     // 2 LS2_2 
    Uint16 LS3_2:1;                     // 3 LS3_2 
    Uint16 LS4_2:1;                     // 4 LS4_2 
    Uint16 LS5_2:1;                     // 5 LS5_2 
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DC19_REG {
    Uint32  all;
    struct  DC19_BITS  bit;
};

struct DC20_BITS {                      // bits description
    Uint16 GS0:1;                       // 0 GS0 
    Uint16 GS1:1;                       // 1 GS1 
    Uint16 GS2:1;                       // 2 GS2 
    Uint16 GS3:1;                       // 3 GS3 
    Uint16 GS4:1;                       // 4 GS4 
    Uint16 GS5:1;                       // 5 GS5 
    Uint16 GS6:1;                       // 6 GS6 
    Uint16 GS7:1;                       // 7 GS7 
    Uint16 GS8:1;                       // 8 GS8 
    Uint16 GS9:1;                       // 9 GS9 
    Uint16 GS10:1;                      // 10 GS10 
    Uint16 GS11:1;                      // 11 GS11 
    Uint16 GS12:1;                      // 12 GS12 
    Uint16 GS13:1;                      // 13 GS13 
    Uint16 GS14:1;                      // 14 GS14 
    Uint16 GS15:1;                      // 15 GS15 
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union DC20_REG {
    Uint32  all;
    struct  DC20_BITS  bit;
};

struct PERCNF1_BITS {                   // bits description
    Uint16 ADC_A_MODE:1;                // 0 ADC_A mode setting bit
    Uint16 ADC_B_MODE:1;                // 1 ADC_B mode setting bit
    Uint16 ADC_C_MODE:1;                // 2 ADC_C mode setting bit
    Uint16 ADC_D_MODE:1;                // 3 ADC_D mode setting bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 USB_A_PHY:1;                 // 16 USB_A_PHY 
    Uint16 rsvd2:1;                     // 17 Reserved
    Uint16 rsvd3:14;                    // 31:18 Reserved
};

union PERCNF1_REG {
    Uint32  all;
    struct  PERCNF1_BITS  bit;
};

struct FUSEERR_BITS {                   // bits description
    Uint16 ALERR:5;                     // 4:0 Efuse Autoload Error Status
    Uint16 ERR:1;                       // 5 Efuse Self Test Error Status
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FUSEERR_REG {
    Uint32  all;
    struct  FUSEERR_BITS  bit;
};

struct SOFTPRES0_BITS {                 // bits description
    Uint16 CPU1_CLA1:1;                 // 0 CPU1_CLA1 software reset bit
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 CPU2_CLA1:1;                 // 2 CPU2_CLA1 software reset bit
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:12;                    // 15:4 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union SOFTPRES0_REG {
    Uint32  all;
    struct  SOFTPRES0_BITS  bit;
};

struct SOFTPRES1_BITS {                 // bits description
    Uint16 EMIF1:1;                     // 0 EMIF1 software reset bit
    Uint16 EMIF2:1;                     // 1 EMIF2 software reset bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES1_REG {
    Uint32  all;
    struct  SOFTPRES1_BITS  bit;
};

struct SOFTPRES2_BITS {                 // bits description
    Uint16 EPWM1:1;                     // 0 EPWM1 software reset bit
    Uint16 EPWM2:1;                     // 1 EPWM2 software reset bit
    Uint16 EPWM3:1;                     // 2 EPWM3 software reset bit
    Uint16 EPWM4:1;                     // 3 EPWM4 software reset bit
    Uint16 EPWM5:1;                     // 4 EPWM5 software reset bit
    Uint16 EPWM6:1;                     // 5 EPWM6 software reset bit
    Uint16 EPWM7:1;                     // 6 EPWM7 software reset bit
    Uint16 EPWM8:1;                     // 7 EPWM8 software reset bit
    Uint16 EPWM9:1;                     // 8 EPWM9 software reset bit
    Uint16 EPWM10:1;                    // 9 EPWM10 software reset bit
    Uint16 EPWM11:1;                    // 10 EPWM11 software reset bit
    Uint16 EPWM12:1;                    // 11 EPWM12 software reset bit
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 rsvd2:1;                     // 13 Reserved
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 rsvd4:1;                     // 15 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union SOFTPRES2_REG {
    Uint32  all;
    struct  SOFTPRES2_BITS  bit;
};

struct SOFTPRES3_BITS {                 // bits description
    Uint16 ECAP1:1;                     // 0 ECAP1 software reset bit
    Uint16 ECAP2:1;                     // 1 ECAP2 software reset bit
    Uint16 ECAP3:1;                     // 2 ECAP3 software reset bit
    Uint16 ECAP4:1;                     // 3 ECAP4 software reset bit
    Uint16 ECAP5:1;                     // 4 ECAP5 software reset bit
    Uint16 ECAP6:1;                     // 5 ECAP6 software reset bit
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union SOFTPRES3_REG {
    Uint32  all;
    struct  SOFTPRES3_BITS  bit;
};

struct SOFTPRES4_BITS {                 // bits description
    Uint16 EQEP1:1;                     // 0 EQEP1 software reset bit
    Uint16 EQEP2:1;                     // 1 EQEP2 software reset bit
    Uint16 EQEP3:1;                     // 2 EQEP3 software reset bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union SOFTPRES4_REG {
    Uint32  all;
    struct  SOFTPRES4_BITS  bit;
};

struct SOFTPRES6_BITS {                 // bits description
    Uint16 SD1:1;                       // 0 SD1 software reset bit
    Uint16 SD2:1;                       // 1 SD2 software reset bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:1;                     // 5 Reserved
    Uint16 rsvd5:1;                     // 6 Reserved
    Uint16 rsvd6:1;                     // 7 Reserved
    Uint16 rsvd7:8;                     // 15:8 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union SOFTPRES6_REG {
    Uint32  all;
    struct  SOFTPRES6_BITS  bit;
};

struct SOFTPRES7_BITS {                 // bits description
    Uint16 SCI_A:1;                     // 0 SCI_A software reset bit
    Uint16 SCI_B:1;                     // 1 SCI_B software reset bit
    Uint16 SCI_C:1;                     // 2 SCI_C software reset bit
    Uint16 SCI_D:1;                     // 3 SCI_D software reset bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES7_REG {
    Uint32  all;
    struct  SOFTPRES7_BITS  bit;
};

struct SOFTPRES8_BITS {                 // bits description
    Uint16 SPI_A:1;                     // 0 SPI_A software reset bit
    Uint16 SPI_B:1;                     // 1 SPI_B software reset bit
    Uint16 SPI_C:1;                     // 2 SPI_C software reset bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:1;                     // 16 Reserved
    Uint16 rsvd4:1;                     // 17 Reserved
    Uint16 rsvd5:14;                    // 31:18 Reserved
};

union SOFTPRES8_REG {
    Uint32  all;
    struct  SOFTPRES8_BITS  bit;
};

struct SOFTPRES9_BITS {                 // bits description
    Uint16 I2C_A:1;                     // 0 I2C_A software reset bit
    Uint16 I2C_B:1;                     // 1 I2C_B software reset bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:1;                     // 16 Reserved
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 rsvd4:14;                    // 31:18 Reserved
};

union SOFTPRES9_REG {
    Uint32  all;
    struct  SOFTPRES9_BITS  bit;
};

struct SOFTPRES11_BITS {                // bits description
    Uint16 McBSP_A:1;                   // 0 McBSP_A software reset bit
    Uint16 McBSP_B:1;                   // 1 McBSP_B software reset bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 USB_A:1;                     // 16 USB_A software reset bit
    Uint16 rsvd2:1;                     // 17 Reserved
    Uint16 rsvd3:14;                    // 31:18 Reserved
};

union SOFTPRES11_REG {
    Uint32  all;
    struct  SOFTPRES11_BITS  bit;
};

struct SOFTPRES13_BITS {                // bits description
    Uint16 ADC_A:1;                     // 0 ADC_A software reset bit
    Uint16 ADC_B:1;                     // 1 ADC_B software reset bit
    Uint16 ADC_C:1;                     // 2 ADC_C software reset bit
    Uint16 ADC_D:1;                     // 3 ADC_D software reset bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES13_REG {
    Uint32  all;
    struct  SOFTPRES13_BITS  bit;
};

struct SOFTPRES14_BITS {                // bits description
    Uint16 CMPSS1:1;                    // 0 CMPSS1 software reset bit
    Uint16 CMPSS2:1;                    // 1 CMPSS2 software reset bit
    Uint16 CMPSS3:1;                    // 2 CMPSS3 software reset bit
    Uint16 CMPSS4:1;                    // 3 CMPSS4 software reset bit
    Uint16 CMPSS5:1;                    // 4 CMPSS5 software reset bit
    Uint16 CMPSS6:1;                    // 5 CMPSS6 software reset bit
    Uint16 CMPSS7:1;                    // 6 CMPSS7 software reset bit
    Uint16 CMPSS8:1;                    // 7 CMPSS8 software reset bit
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SOFTPRES14_REG {
    Uint32  all;
    struct  SOFTPRES14_BITS  bit;
};

struct SOFTPRES16_BITS {                // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:12;                    // 15:4 Reserved
    Uint16 DAC_A:1;                     // 16 Buffered_DAC_A software reset bit
    Uint16 DAC_B:1;                     // 17 Buffered_DAC_B software reset bit
    Uint16 DAC_C:1;                     // 18 Buffered_DAC_C software reset bit
    Uint16 rsvd6:1;                     // 19 Reserved
    Uint16 rsvd7:12;                    // 31:20 Reserved
};

union SOFTPRES16_REG {
    Uint32  all;
    struct  SOFTPRES16_BITS  bit;
};

struct CPUSEL0_BITS {                   // bits description
    Uint16 EPWM1:1;                     // 0 EPWM1 CPU select bit
    Uint16 EPWM2:1;                     // 1 EPWM2 CPU select bit
    Uint16 EPWM3:1;                     // 2 EPWM3 CPU select bit
    Uint16 EPWM4:1;                     // 3 EPWM4 CPU select bit
    Uint16 EPWM5:1;                     // 4 EPWM5 CPU select bit
    Uint16 EPWM6:1;                     // 5 EPWM6 CPU select bit
    Uint16 EPWM7:1;                     // 6 EPWM7 CPU select bit
    Uint16 EPWM8:1;                     // 7 EPWM8 CPU select bit
    Uint16 EPWM9:1;                     // 8 EPWM9 CPU select bit
    Uint16 EPWM10:1;                    // 9 EPWM10 CPU select bit
    Uint16 EPWM11:1;                    // 10 EPWM11 CPU select bit
    Uint16 EPWM12:1;                    // 11 EPWM12 CPU select bit
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 rsvd2:1;                     // 13 Reserved
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 rsvd4:1;                     // 15 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union CPUSEL0_REG {
    Uint32  all;
    struct  CPUSEL0_BITS  bit;
};

#ifdef CPU1
// CPUSEL0 Register
//// CPUSEL0 Register : Byte Value
#define CPUSEL0_EPWM12_CPU1Host							0x00000000UL				// EPWM12 Connected to CPU1
#define CPUSEL0_EPWM12_CPU2Host							0x00000800UL				// EPWM12 Connected to CPU2

#define CPUSEL0_EPWM11_CPU1Host							0x00000000UL				// EPWM11 Connected to CPU1
#define CPUSEL0_EPWM11_CPU2Host							0x00000400UL				// EPWM11 Connected to CPU2

#define CPUSEL0_EPWM10_CPU1Host							0x00000000UL				// EPWM10 Connected to CPU1
#define CPUSEL0_EPWM10_CPU2Host							0x00000200UL				// EPWM10 Connected to CPU2

#define CPUSEL0_EPWM9_CPU1Host							0x00000000UL				// EPWM9 Connected to CPU1
#define CPUSEL0_EPWM9_CPU2Host							0x00000100UL				// EPWM9 Connected to CPU2

#define CPUSEL0_EPWM8_CPU1Host							0x00000000UL				// EPWM8 Connected to CPU1
#define CPUSEL0_EPWM8_CPU2Host							0x00000080UL				// EPWM8 Connected to CPU2

#define CPUSEL0_EPWM7_CPU1Host							0x00000000UL				// EPWM7 Connected to CPU1
#define CPUSEL0_EPWM7_CPU2Host							0x00000040UL				// EPWM7 Connected to CPU2

#define CPUSEL0_EPWM6_CPU1Host							0x00000000UL				// EPWM6 Connected to CPU1
#define CPUSEL0_EPWM6_CPU2Host							0x00000020UL				// EPWM6 Connected to CPU2

#define CPUSEL0_EPWM5_CPU1Host							0x00000000UL				// EPWM5 Connected to CPU1
#define CPUSEL0_EPWM5_CPU2Host							0x00000010UL				// EPWM5 Connected to CPU2

#define CPUSEL0_EPWM4_CPU1Host							0x00000000UL				// EPWM4 Connected to CPU1
#define CPUSEL0_EPWM4_CPU2Host							0x00000008UL				// EPWM4 Connected to CPU2

#define CPUSEL0_EPWM3_CPU1Host							0x00000000UL				// EPWM3 Connected to CPU1
#define CPUSEL0_EPWM3_CPU2Host							0x00000004UL				// EPWM3 Connected to CPU2

#define CPUSEL0_EPWM2_CPU1Host							0x00000000UL				// EPWM2 Connected to CPU1
#define CPUSEL0_EPWM2_CPU2Host							0x00000002UL				// EPWM2 Connected to CPU2

#define CPUSEL0_EPWM1_CPU1Host							0x00000000UL				// EPWM1 Connected to CPU1
#define CPUSEL0_EPWM1_CPU2Host							0x00000001UL				// EPWM1 Connected to CPU2
#endif

struct CPUSEL1_BITS {                   // bits description
    Uint16 ECAP1:1;                     // 0 ECAP1 CPU select bit
    Uint16 ECAP2:1;                     // 1 ECAP2 CPU select bit
    Uint16 ECAP3:1;                     // 2 ECAP3 CPU select bit
    Uint16 ECAP4:1;                     // 3 ECAP4 CPU select bit
    Uint16 ECAP5:1;                     // 4 ECAP5 CPU select bit
    Uint16 ECAP6:1;                     // 5 ECAP6 CPU select bit
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union CPUSEL1_REG {
    Uint32  all;
    struct  CPUSEL1_BITS  bit;
};

#ifdef CPU1
// CPUSEL1 Register
//// CPUSEL1 Register : Byte Value
#define CPUSEL1_ECAP6_CPU1Host							0x00000000UL				// CAP6 Connected to CPU1.
#define CPUSEL1_ECAP6_CPU2Host							0x00000020UL				// CAP6 Connected to CPU2.

#define CPUSEL1_ECAP5_CPU1Host							0x00000000UL				// CAP5 Connected to CPU1.
#define CPUSEL1_ECAP5_CPU2Host							0x00000010UL				// CAP5 Connected to CPU2.

#define CPUSEL1_ECAP4_CPU1Host							0x00000000UL				// CAP4 Connected to CPU1.
#define CPUSEL1_ECAP4_CPU2Host							0x00000008UL				// CAP4 Connected to CPU2.

#define CPUSEL1_ECAP3_CPU1Host							0x00000000UL				// CAP3 Connected to CPU1.
#define CPUSEL1_ECAP3_CPU2Host							0x00000004UL				// CAP3 Connected to CPU2.

#define CPUSEL1_ECAP2_CPU1Host							0x00000000UL				// CAP2 Connected to CPU1.
#define CPUSEL1_ECAP2_CPU2Host							0x00000002UL				// CAP2 Connected to CPU2.

#define CPUSEL1_ECAP1_CPU1Host							0x00000000UL				// CAP1 Connected to CPU1.
#define CPUSEL1_ECAP1_CPU2Host							0x00000001UL				// CAP1 Connected to CPU2.
#endif

struct CPUSEL2_BITS {                   // bits description
    Uint16 EQEP1:1;                     // 0 EQEP1 CPU select bit
    Uint16 EQEP2:1;                     // 1 EQEP2 CPU select bit
    Uint16 EQEP3:1;                     // 2 EQEP3 CPU select bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CPUSEL2_REG {
    Uint32  all;
    struct  CPUSEL2_BITS  bit;
};

#ifdef CPU1
// CPUSEL2 Register
//// CPUSEL2 Register : Byte Value
#define CPUSEL2_EQEP3_CPU1Host							0x00000000UL				// EQEP3 Connected to CPU1.
#define CPUSEL2_EQEP3_CPU2Host							0x00000004UL				// EQEP3 Connected to CPU2.

#define CPUSEL2_EQEP2_CPU1Host							0x00000000UL				// EQEP2 Connected to CPU1.
#define CPUSEL2_EQEP2_CPU2Host							0x00000002UL				// EQEP2 Connected to CPU2.

#define CPUSEL2_EQEP1_CPU1Host							0x00000000UL				// EQEP1 Connected to CPU1.
#define CPUSEL2_EQEP1_CPU2Host							0x00000001UL				// EQEP1 Connected to CPU2.
#endif

struct CPUSEL4_BITS {                   // bits description
    Uint16 SD1:1;                       // 0 SD1 CPU select bit
    Uint16 SD2:1;                       // 1 SD2 CPU select bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:1;                     // 5 Reserved
    Uint16 rsvd5:1;                     // 6 Reserved
    Uint16 rsvd6:1;                     // 7 Reserved
    Uint16 rsvd7:8;                     // 15:8 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union CPUSEL4_REG {
    Uint32  all;
    struct  CPUSEL4_BITS  bit;
};

#ifdef CPU1
// CPUSEL4 Register
//// CPUSEL4 Register : Byte Value
#define CPUSEL4_SD2_CPU1Host							0x00000000UL				// SD2 Connected to CPU1.
#define CPUSEL4_SD2_CPU2Host							0x00000002UL				// SD2 Connected to CPU2.

#define CPUSEL4_SD1_CPU1Host							0x00000000UL				// SD1 Connected to CPU1.
#define CPUSEL4_SD1_CPU2Host							0x00000001UL				// SD1 Connected to CPU2.
#endif

struct CPUSEL5_BITS {                   // bits description
    Uint16 SCI_A:1;                     // 0 SCI_A CPU select bit
    Uint16 SCI_B:1;                     // 1 SCI_B CPU select bit
    Uint16 SCI_C:1;                     // 2 SCI_C CPU select bit
    Uint16 SCI_D:1;                     // 3 SCI_D CPU select bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CPUSEL5_REG {
    Uint32  all;
    struct  CPUSEL5_BITS  bit;
};

#ifdef CPU1
// CPUSEL5 Register
//// CPUSEL5 Register : Byte Value
#define CPUSEL5_SCI_D_CPU1Host							0x00000000UL				// SCI-D Connected to CPU1.
#define CPUSEL5_SCI_D_CPU2Host							0x00000008UL				// SCI-D Connected to CPU2.

#define CPUSEL5_SCI_C_CPU1Host							0x00000000UL				// SCI-C Connected to CPU1.
#define CPUSEL5_SCI_C_CPU2Host							0x00000004UL				// SCI-C Connected to CPU2.

#define CPUSEL5_SCI_B_CPU1Host							0x00000000UL				// SCI-B Connected to CPU1.
#define CPUSEL5_SCI_B_CPU2Host							0x00000002UL				// SCI-B Connected to CPU2.

#define CPUSEL5_SCI_A_CPU1Host							0x00000000UL				// SCI-A Connected to CPU1.
#define CPUSEL5_SCI_A_CPU2Host							0x00000001UL				// SCI-A Connected to CPU2.
#endif

struct CPUSEL6_BITS {                   // bits description
    Uint16 SPI_A:1;                     // 0 SPI_A CPU select bit
    Uint16 SPI_B:1;                     // 1 SPI_B CPU select bit
    Uint16 SPI_C:1;                     // 2 SPI_C CPU select bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:1;                     // 16 Reserved
    Uint16 rsvd4:1;                     // 17 Reserved
    Uint16 rsvd5:14;                    // 31:18 Reserved
};

union CPUSEL6_REG {
    Uint32  all;
    struct  CPUSEL6_BITS  bit;
};

#ifdef CPU1
// CPUSEL6 Register
//// CPUSEL6 Register : Byte Value
#define CPUSEL6_SPI_C_CPU1Host							0x00000000UL				// SPI-C Connected to CPU1.
#define CPUSEL6_SPI_C_CPU2Host							0x00000004UL				// SPI-C Connected to CPU2.

#define CPUSEL6_SPI_B_CPU1Host							0x00000000UL				// SPI-B Connected to CPU1.
#define CPUSEL6_SPI_B_CPU2Host							0x00000002UL				// SPI-B Connected to CPU2.

#define CPUSEL6_SPI_A_CPU1Host							0x00000000UL				// SPI-A Connected to CPU1.
#define CPUSEL6_SPI_A_CPU2Host							0x00000001UL				// SPI-A Connected to CPU2.
#endif

struct CPUSEL7_BITS {                   // bits description
    Uint16 I2C_A:1;                     // 0 I2C_A CPU select bit
    Uint16 I2C_B:1;                     // 1 I2C_B CPU select bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:1;                     // 16 Reserved
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 rsvd4:14;                    // 31:18 Reserved
};

union CPUSEL7_REG {
    Uint32  all;
    struct  CPUSEL7_BITS  bit;
};

#ifdef CPU1
// CPUSEL7 Register
//// CPUSEL7 Register : Byte Value
#define CPUSEL7_I2C_B_CPU1Host							0x00000000UL				// I2C-B Connected to CPU1.
#define CPUSEL7_I2C_B_CPU2Host							0x00000002UL				// I2C-B Connected to CPU2.

#define CPUSEL7_I2C_A_CPU1Host							0x00000000UL				// I2C-A Connected to CPU1.
#define CPUSEL7_I2C_A_CPU2Host							0x00000001UL				// I2C-A Connected to CPU2.
#endif

struct CPUSEL8_BITS {                   // bits description
    Uint16 CAN_A:1;                     // 0 CAN_A CPU select bit
    Uint16 CAN_B:1;                     // 1 CAN_B CPU select bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:12;                    // 15:4 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union CPUSEL8_REG {
    Uint32  all;
    struct  CPUSEL8_BITS  bit;
};

#ifdef CPU1
// CPUSEL8 Register
//// CPUSEL8 Register : Byte Value
#define CPUSEL8_CAN_B_CPU1Host							0x00000000UL				// CAN-B Connected to CPU1.
#define CPUSEL8_CAN_B_CPU2Host							0x00000002UL				// CAN-B Connected to CPU2.

#define CPUSEL8_CAN_A_CPU1Host							0x00000000UL				// CAN-A Connected to CPU1.
#define CPUSEL8_CAN_A_CPU2Host							0x00000001UL				// CAN-A Connected to CPU2.
#endif

struct CPUSEL9_BITS {                   // bits description
    Uint16 McBSP_A:1;                   // 0 McBSP_A CPU select bit
    Uint16 McBSP_B:1;                   // 1 McBSP_B CPU select bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CPUSEL9_REG {
    Uint32  all;
    struct  CPUSEL9_BITS  bit;
};

#ifdef CPU1
// CPUSEL9 Register
//// CPUSEL9 Register : Byte Value
#define CPUSEL9_McBSP_B_CPU1Host						0x00000000UL				// McBSP-B Connected to CPU1.
#define CPUSEL9_McBSP_B_CPU2Host						0x00000002UL				// McBSP-B Connected to CPU2.

#define CPUSEL9_McBSP_A_CPU1Host						0x00000000UL				// McBSP-A Connected to CPU1.
#define CPUSEL9_McBSP_A_CPU2Host						0x00000001UL				// McBSP-A Connected to CPU2.
#endif

struct CPUSEL11_BITS {                  // bits description
    Uint16 ADC_A:1;                     // 0 ADC_A CPU select bit
    Uint16 ADC_B:1;                     // 1 ADC_B CPU select bit
    Uint16 ADC_C:1;                     // 2 ADC_C CPU select bit
    Uint16 ADC_D:1;                     // 3 ADC_D CPU select bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CPUSEL11_REG {
    Uint32  all;
    struct  CPUSEL11_BITS  bit;
};

#ifdef CPU1
// CPUSEL11 Register
//// CPUSEL11 Register : Byte Value
#define CPUSEL11_ADC_D_CFGREG_CPU1Host					0x00000000UL				// ADC-D Configuration Register Connected to CPU1. ADC Result Register Readable from All CPU.
#define CPUSEL11_ADC_D_CFGREG_CPU2Host					0x00000008UL				// ADC-D Configuration Register Connected to CPU2. ADC Result Register Readable from All CPU.

#define CPUSEL11_ADC_C_CFGREG_CPU1Host					0x00000000UL				// ADC-C Configuration Register Connected to CPU1. ADC Result Register Readable from All CPU.
#define CPUSEL11_ADC_C_CFGREG_CPU2Host					0x00000004UL				// ADC-C Configuration Register Connected to CPU2. ADC Result Register Readable from All CPU.

#define CPUSEL11_ADC_B_CFGREG_CPU1Host					0x00000000UL				// ADC-B Configuration Register Connected to CPU1. ADC Result Register Readable from All CPU.
#define CPUSEL11_ADC_B_CFGREG_CPU2Host					0x00000002UL				// ADC-B Configuration Register Connected to CPU2. ADC Result Register Readable from All CPU.

#define CPUSEL11_ADC_A_CFGREG_CPU1Host					0x00000000UL				// ADC-A Configuration Register Connected to CPU1. ADC Result Register Readable from All CPU.
#define CPUSEL11_ADC_A_CFGREG_CPU2Host					0x00000001UL				// ADC-A Configuration Register Connected to CPU2. ADC Result Register Readable from All CPU.
#endif

struct CPUSEL12_BITS {                  // bits description
    Uint16 CMPSS1:1;                    // 0 CMPSS1 CPU select bit
    Uint16 CMPSS2:1;                    // 1 CMPSS2 CPU select bit
    Uint16 CMPSS3:1;                    // 2 CMPSS3 CPU select bit
    Uint16 CMPSS4:1;                    // 3 CMPSS4 CPU select bit
    Uint16 CMPSS5:1;                    // 4 CMPSS5 CPU select bit
    Uint16 CMPSS6:1;                    // 5 CMPSS6 CPU select bit
    Uint16 CMPSS7:1;                    // 6 CMPSS7 CPU select bit
    Uint16 CMPSS8:1;                    // 7 CMPSS8 CPU select bit
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CPUSEL12_REG {
    Uint32  all;
    struct  CPUSEL12_BITS  bit;
};

#ifdef CPU1
// CPUSEL12 Register
//// CPUSEL12 Register : Byte Value
#define CPUSEL12_CMPSS8_CPU1Host						0x00000000UL				// CMPSS8 Connected to CPU1.
#define CPUSEL12_CMPSS8_CPU2Host						0x00000080UL				// CMPSS8 Connected to CPU2.

#define CPUSEL12_CMPSS7_CPU1Host						0x00000000UL				// CMPSS7 Connected to CPU1.
#define CPUSEL12_CMPSS7_CPU2Host						0x00000040UL				// CMPSS7 Connected to CPU2.

#define CPUSEL12_CMPSS6_CPU1Host						0x00000000UL				// CMPSS6 Connected to CPU1.
#define CPUSEL12_CMPSS6_CPU2Host						0x00000020UL				// CMPSS6 Connected to CPU2.

#define CPUSEL12_CMPSS5_CPU1Host						0x00000000UL				// CMPSS5 Connected to CPU1.
#define CPUSEL12_CMPSS5_CPU2Host						0x00000010UL				// CMPSS5 Connected to CPU2.

#define CPUSEL12_CMPSS4_CPU1Host						0x00000000UL				// CMPSS4 Connected to CPU1.
#define CPUSEL12_CMPSS4_CPU2Host						0x00000008UL				// CMPSS4 Connected to CPU2.

#define CPUSEL12_CMPSS3_CPU1Host						0x00000000UL				// CMPSS3 Connected to CPU1.
#define CPUSEL12_CMPSS3_CPU2Host						0x00000004UL				// CMPSS3 Connected to CPU2.

#define CPUSEL12_CMPSS2_CPU1Host						0x00000000UL				// CMPSS2 Connected to CPU1.
#define CPUSEL12_CMPSS2_CPU2Host						0x00000002UL				// CMPSS2 Connected to CPU2.

#define CPUSEL12_CMPSS1_CPU1Host						0x00000000UL				// CMPSS1 Connected to CPU1.
#define CPUSEL12_CMPSS1_CPU2Host						0x00000001UL				// CMPSS1 Connected to CPU2.
#endif

struct CPUSEL14_BITS {                  // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:12;                    // 15:4 Reserved
    Uint16 DAC_A:1;                     // 16 Buffered_DAC_A CPU select bit
    Uint16 DAC_B:1;                     // 17 Buffered_DAC_B CPU select bit
    Uint16 DAC_C:1;                     // 18 Buffered_DAC_C CPU select bit
    Uint16 rsvd6:1;                     // 19 Reserved
    Uint16 rsvd7:12;                    // 31:20 Reserved
};

union CPUSEL14_REG {
    Uint32  all;
    struct  CPUSEL14_BITS  bit;
};

#ifdef CPU1
// CPUSEL14 Register
//// CPUSEL14 Register : Byte Value
#define CPUSEL14_DAC_C_CPU1Host							0x00000000UL				// DAC-C Connected to CPU1.
#define CPUSEL14_DAC_C_CPU2Host							0x00040000UL				// DAC-C Connected to CPU2.

#define CPUSEL14_DAC_B_CPU1Host							0x00000000UL				// DAC-C Connected to CPU1.
#define CPUSEL14_DAC_B_CPU2Host							0x00020000UL				// DAC-C Connected to CPU2.

#define CPUSEL14_DAC_A_CPU1Host							0x00000000UL				// DAC-C Connected to CPU1.
#define CPUSEL14_DAC_A_CPU2Host							0x00010000UL				// DAC-C Connected to CPU2.
#endif

struct CPU2RESCTL_BITS {                // bits description
    Uint16 RESET:1;                     // 0 CPU2 Reset Control bit
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 KEY:16;                      // 31:16 Key Qualifier for writes to this register
};

union CPU2RESCTL_REG {
    Uint32  all;
    struct  CPU2RESCTL_BITS  bit;
};

struct RSTSTAT_BITS {                   // bits description
    Uint16 CPU2RES:1;                   // 0 CPU2 Reset Status bit
    Uint16 CPU2NMIWDRST:1;              // 1 Indicates whether a CPU2.NMIWD reset was issued to CPU2
    Uint16 CPU2HWBISTRST0:1;            // 2 Indicates whether a HWBIST reset was issued to CPU2
    Uint16 CPU2HWBISTRST1:1;            // 3 Indicates whether a HWBIST reset was issued to CPU2
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union RSTSTAT_REG {
    Uint16  all;
    struct  RSTSTAT_BITS  bit;
};

struct LPMSTAT_BITS {                   // bits description
    Uint16 CPU2LPMSTAT:2;               // 1:0 CPU2 LPM Status
    Uint16 rsvd1:14;                    // 15:2 Reserved
};

union LPMSTAT_REG {
    Uint16  all;
    struct  LPMSTAT_BITS  bit;
};

struct SYSDBGCTL_BITS {                 // bits description
    Uint16 BIT_0:1;                     // 0 Used in PLL startup. Only reset by POR.
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYSDBGCTL_REG {
    Uint32  all;
    struct  SYSDBGCTL_BITS  bit;
};

#ifdef CPU1
// SYSDBGCTL Register
//// SYSDBGCTL Register : Byte Value
#define SYSDBGCTL_BIT_0_PLLNormal						0x00000000UL				// PLL StartUp is Ended.
#define SYSDBGCTL_BIT_0_PLLStart						0x00000001UL				// PLL Startup.
#endif

struct DEV_CFG_REGS {
    union   DEVCFGLOCK1_REG                  DEVCFGLOCK1;                  // Lock bit for CPUSELx registers
    Uint16                                   rsvd1[6];                     // Reserved
    union   PARTIDL_REG                      PARTIDL;                      // Lower 32-bit of Device PART Identification Number
    union   PARTIDH_REG                      PARTIDH;                      // Upper 32-bit of Device PART Identification Number
    Uint32                                   REVID;                        // Device Revision Number
    Uint16                                   rsvd2[2];                     // Reserved
    union   DC0_REG                          DC0;                          // Device Capability: Device Information
    union   DC1_REG                          DC1;                          // Device Capability: Processing Block Customization
    union   DC2_REG                          DC2;                          // Device Capability: EMIF Customization
    union   DC3_REG                          DC3;                          // Device Capability: Peripheral Customization
    union   DC4_REG                          DC4;                          // Device Capability: Peripheral Customization
    union   DC5_REG                          DC5;                          // Device Capability: Peripheral Customization
    Uint16                                   rsvd3[2];                     // Reserved
    union   DC7_REG                          DC7;                          // Device Capability: Peripheral Customization
    union   DC8_REG                          DC8;                          // Device Capability: Peripheral Customization
    union   DC9_REG                          DC9;                          // Device Capability: Peripheral Customization
    union   DC10_REG                         DC10;                         // Device Capability: Peripheral Customization
    union   DC11_REG                         DC11;                         // Device Capability: Peripheral Customization
    union   DC12_REG                         DC12;                         // Device Capability: Peripheral Customization
    union   DC13_REG                         DC13;                         // Device Capability: Peripheral Customization
    union   DC14_REG                         DC14;                         // Device Capability: Analog Modules Customization
    union   DC15_REG                         DC15;                         // Device Capability: Analog Modules Customization
    Uint16                                   rsvd4[2];                     // Reserved
    union   DC17_REG                         DC17;                         // Device Capability: Analog Modules Customization
    union   DC18_REG                         DC18;                         // Device Capability: CPU1 Lx SRAM Customization
    union   DC19_REG                         DC19;                         // Device Capability: CPU2 Lx SRAM Customization
    union   DC20_REG                         DC20;                         // Device Capability: GSx SRAM Customization
    Uint16                                   rsvd5[38];                    // Reserved
    union   PERCNF1_REG                      PERCNF1;                      // Peripheral Configuration register
    Uint16                                   rsvd6[18];                    // Reserved
    union   FUSEERR_REG                      FUSEERR;                      // e-Fuse error Status register
    Uint16                                   rsvd7[12];                    // Reserved
    union   SOFTPRES0_REG                    SOFTPRES0;                    // Processing Block Software Reset register
    union   SOFTPRES1_REG                    SOFTPRES1;                    // EMIF Software Reset register
    union   SOFTPRES2_REG                    SOFTPRES2;                    // Peripheral Software Reset register
    union   SOFTPRES3_REG                    SOFTPRES3;                    // Peripheral Software Reset register
    union   SOFTPRES4_REG                    SOFTPRES4;                    // Peripheral Software Reset register
    Uint16                                   rsvd8[2];                     // Reserved
    union   SOFTPRES6_REG                    SOFTPRES6;                    // Peripheral Software Reset register
    union   SOFTPRES7_REG                    SOFTPRES7;                    // Peripheral Software Reset register
    union   SOFTPRES8_REG                    SOFTPRES8;                    // Peripheral Software Reset register
    union   SOFTPRES9_REG                    SOFTPRES9;                    // Peripheral Software Reset register
    Uint16                                   rsvd9[2];                     // Reserved
    union   SOFTPRES11_REG                   SOFTPRES11;                   // Peripheral Software Reset register
    Uint16                                   rsvd10[2];                    // Reserved
    union   SOFTPRES13_REG                   SOFTPRES13;                   // Peripheral Software Reset register
    union   SOFTPRES14_REG                   SOFTPRES14;                   // Peripheral Software Reset register
    Uint16                                   rsvd11[2];                    // Reserved
    union   SOFTPRES16_REG                   SOFTPRES16;                   // Peripheral Software Reset register
    Uint16                                   rsvd12[50];                   // Reserved
    union   CPUSEL0_REG                      CPUSEL0;                      // CPU Select register for common peripherals
    union   CPUSEL1_REG                      CPUSEL1;                      // CPU Select register for common peripherals
    union   CPUSEL2_REG                      CPUSEL2;                      // CPU Select register for common peripherals
    Uint16                                   rsvd13[2];                    // Reserved
    union   CPUSEL4_REG                      CPUSEL4;                      // CPU Select register for common peripherals
    union   CPUSEL5_REG                      CPUSEL5;                      // CPU Select register for common peripherals
    union   CPUSEL6_REG                      CPUSEL6;                      // CPU Select register for common peripherals
    union   CPUSEL7_REG                      CPUSEL7;                      // CPU Select register for common peripherals
    union   CPUSEL8_REG                      CPUSEL8;                      // CPU Select register for common peripherals
    union   CPUSEL9_REG                      CPUSEL9;                      // CPU Select register for common peripherals
    Uint16                                   rsvd14[2];                    // Reserved
    union   CPUSEL11_REG                     CPUSEL11;                     // CPU Select register for common peripherals
    union   CPUSEL12_REG                     CPUSEL12;                     // CPU Select register for common peripherals
    Uint16                                   rsvd15[2];                    // Reserved
    union   CPUSEL14_REG                     CPUSEL14;                     // CPU Select register for common peripherals
    Uint16                                   rsvd16[46];                   // Reserved
    union   CPU2RESCTL_REG                   CPU2RESCTL;                   // CPU2 Reset Control Register
    union   RSTSTAT_REG                      RSTSTAT;                      // Reset Status register for secondary C28x CPUs
    union   LPMSTAT_REG                      LPMSTAT;                      // LPM Status Register for secondary C28x CPUs
    Uint16                                   rsvd17[6];                    // Reserved
    union   SYSDBGCTL_REG                    SYSDBGCTL;                    // System Debug Control register
};

struct CLKSEM_BITS {                    // bits description
    Uint16 SEM:2;                       // 1:0 Semaphore for CLKCFG Ownership by CPU1 or CPU2
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 KEY:16;                      // 31:16 Key Qualifier for writes to this register
};

union CLKSEM_REG {
    Uint32  all;
    struct  CLKSEM_BITS  bit;
};

// CLKSEM Register
//// CLKSEM Register : Byte Value
#define CLKSEM_KEY_MatchedKey							0xA5A50000UL				// Must Write 0x5A5A for Wiring the SEM Bits. Only 32-bit Write will Succeed.

#define CLKSEM_SEM_CPU1Hostless							0x00000000UL				// CLK_CFG_REG is Owned by CPU1. But CPU2 can Change the Ownership.
#define CLKSEM_SEM_CPU2Host								0x00000001UL				// CLK_CFG_REG is Owned by CPU2.
#define CLKSEM_SEM_CPU1Host								0x00000002UL				// CLK_CFG_REG is Owned by CPU1.

struct CLKCFGLOCK1_BITS {               // bits description
    Uint16 CLKSRCCTL1:1;                // 0 Lock bit for CLKSRCCTL1 register
    Uint16 CLKSRCCTL2:1;                // 1 Lock bit for CLKSRCCTL2 register
    Uint16 CLKSRCCTL3:1;                // 2 Lock bit for CLKSRCCTL3 register
    Uint16 SYSPLLCTL1:1;                // 3 Lock bit for SYSPLLCTL1 register
    Uint16 SYSPLLCTL2:1;                // 4 Lock bit for SYSPLLCTL2 register
    Uint16 SYSPLLCTL3:1;                // 5 Lock bit for SYSPLLCTL3 register
    Uint16 SYSPLLMULT:1;                // 6 Lock bit for SYSPLLMULT register
    Uint16 AUXPLLCTL1:1;                // 7 Lock bit for AUXPLLCTL1 register
    Uint16 rsvd1:1;                     // 8 Reserved
    Uint16 rsvd2:1;                     // 9 Reserved
    Uint16 AUXPLLMULT:1;                // 10 Lock bit for AUXPLLMULT register
    Uint16 SYSCLKDIVSEL:1;              // 11 Lock bit for SYSCLKDIVSEL register
    Uint16 AUXCLKDIVSEL:1;              // 12 Lock bit for AUXCLKDIVSEL register
    Uint16 PERCLKDIVSEL:1;              // 13 Lock bit for PERCLKDIVSEL register
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 LOSPCP:1;                    // 15 Lock bit for LOSPCP register
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union CLKCFGLOCK1_REG {
    Uint32  all;
    struct  CLKCFGLOCK1_BITS  bit;
};

// CLKCFGLOCK1 Register
//// CLKCFGLOCK1 Register : Byte Value
#define CLFCFGLOCK1_LOSPCP_LOSPCPEDIS					0x00008000UL				// LOSPCP Register is Locked.
#define CLFCFGLOCK1_PERCLKDIVSEL_PERCLKDIVSELEDIS		0x00002000UL				// PERCLKDIVSEL Register is Locked.
#define CLFCFGLOCK1_AUXCLKDIVSEL_AUXCLKDIVSELEDIS		0x00001000UL				// AUXCLKDIVSEL Register is Locked.
#define CLFCFGLOCK1_SYSCLKDIVSEL_SYSCLKDIVSELEDIS		0x00000800UL				// SYSCLKDIVSEL Register is Locked.
#define CLFCFGLOCK1_AUXPLLMULT_AUXPLLMULTEDIS			0x00000400UL				// AUXPLLMULT Register is Locked.
#define CLFCFGLOCK1_AUXPLLCTL1_AUXPLLCTL1EDIS			0x00000080UL				// AUXPLLCTL1 Register is Locked.
#define CLFCFGLOCK1_SYSPLLMULT_SYSPLLMULTEDIS			0x00000040UL				// SYSPLLMULT Register is Locked.
#define CLFCFGLOCK1_SYSPLLCTL3_SYSPLLCLT3EDIS			0x00000020UL				// SYSPLLCTL3 Register is Locked.
#define CLFCFGLOCK1_SYSPLLCTL2_SYSPLLCLT2EDIS			0x00000010UL				// SYSPLLCTL2 Register is Locked.
#define CLFCFGLOCK1_SYSPLLCTL1_SYSPLLCLT1EDIS			0x00000008UL				// SYSPLLCTL1 Register is Locked.
#define CLFCFGLOCK1_CLKSRCCTL3_CLKSRCCTL3EDIS			0x00000004UL				// CLKSRCCTL3 Register is Locked.
#define CLFCFGLOCK1_CLKSRCCTL2_CLKSRCCTL2EDIS			0x00000002UL				// CLKSRCCTL2 Register is Locked.
#define CLFCFGLOCK1_CLKSRCCTL1_CLKSRCCTL1EDIS			0x00000001UL				// CLKSRCCTL1 Register is Locked.

struct CLKSRCCTL1_BITS {                // bits description
    Uint16 OSCCLKSRCSEL:2;              // 1:0 OSCCLK Source Select Bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 INTOSC2OFF:1;                // 3 Internal Oscillator 2 Off Bit
    Uint16 XTALOFF:1;                   // 4 Crystal (External) Oscillator Off Bit
    Uint16 WDHALTI:1;                   // 5 Watchdog HALT Mode Ignore Bit
    Uint16 rsvd2:10;                    // 15:6 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CLKSRCCTL1_REG {
    Uint32  all;
    struct  CLKSRCCTL1_BITS  bit;
};

// CLKSRCCTL1 Register
//// CLKSRCCTL1 Register : Byte Value
#define CLKSRCCTL1_WDHALTI_CPU1WDStopInHALTMode			0x00000000UL				// CPU1.WD is not Functional in the HALT Mode. INTOSC1/2 are Powered-Down. CPU2.WD Always is not Functional.
#define CLKSRCCTL1_WDHALTI_CPU1WDRunInHALTMode			0x00000020UL				// CPU1.WD is Functional in HALT Mode. INTOSC1/2 are not Powered-Down. CPU2.WD Always is not Functional.

#define CLKSRCCTL1_XTALOFF_EXTOSCEn						0x00000000UL				// Crystal(External) Oscillator On.
#define CLKSRCCTL1_XTALOFF_EXTOSCDis					0x00000010UL				// Crystal(External) Oscillator Off.

#define CLKSRCCTL1_INTOSC2OFF_INTOSC2En					0x00000000UL				// Internal Oscillator 2 On.
#define CLKSRCCTL1_INTOSC2OFF_INTOSC2Dis				0x00000008UL				// Internal Oscillator 2 Off.

#define CLKSRCCTL1_OSCCLKSRCSEL_INTOSC2					0x00000000UL				// Oscillator Clock Source is INTOSC2.
#define CLKSRCCTL1_OSCCLKSRCSEL_EXTOSC					0x00000001UL				// Oscillator Clock Source is EXTOSC.
#define CLKSRCCTL1_OSCCLKSRCSEL_INTOSC1					0x00000002UL				// Oscillator Clock Source is INTOSC1. It's Recommended for Back-Up OSCCLK.

struct CLKSRCCTL2_BITS {                // bits description
    Uint16 AUXOSCCLKSRCSEL:2;           // 1:0 AUXOSCCLK Source Select Bit
    Uint16 CANABCLKSEL:2;               // 3:2 CANA Bit Clock Source Select Bit
    Uint16 CANBBCLKSEL:2;               // 5:4 CANB Bit Clock Source Select Bit
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 rsvd2:2;                     // 9:8 Reserved
    Uint16 rsvd3:6;                     // 15:10 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union CLKSRCCTL2_REG {
    Uint32  all;
    struct  CLKSRCCTL2_BITS  bit;
};

// CLKSRCCLT2 Register
//// CLKSRCCLT2 Register : Byte Value
#define CLKSRCCTL2_CANBBCLKSEL_PERxSYSCLK				0x00000000UL				// CANB Clock Source is PERx.SYSCLK.
#define CLKSRCCTL2_CANBBCLKSEL_EXTOSC					0x00000010UL				// CANB Clock Source is EXTOSC.
#define CLKSRCCTL2_CANBBCLKSEL_AUXCLKIN					0x00000020UL				// CANB Clock Source is AUXCLKIN.

#define CLKSRCCTL2_CANABCLKSEL_PERxSYSCLK				0x00000000UL				// CANB Clock Source is PERx.SYSCLK.
#define CLKSRCCTL2_CANABCLKSEL_EXTOSC					0x00000004UL				// CANB Clock Source is EXTOSC.
#define CLKSRCCTL2_CANABCLKSEL_AUXCLKIN					0x00000008UL				// CANB Clock Source is AUXCLKIN(from GPIO).

#define CLKSRCCTL2_AUXOSCCLKSRCSEL_INTOSC2				0x00000000UL				// AUXOSCCLK Clock Source is INTOSC2.
#define CLKSRCCTL2_AUXOSCCLKSRCSEL_EXTOSC				0x00000001UL				// AUXOSCCLK Clock Source is EXTOSC.
#define CLKSRCCTL2_AUXOSCCLKSRCSEL_AUXCLKIN				0x00000002UL				// AUXOSCCLK Clock Source is AUXCLKIN(from GPIO).

//// CLKSRCCLT2 Register : Bit Value
#define CANBBCLKSEL_PERxSYSCLK							0U							// CANB Clock Source is PERx.SYSCLK.
#define CANBBCLKSEL_EXTOSC								1U							// CANB Clock Source is EXTOSC.
#define CANBBCLKSEL_AUXCLKIN							2U							// CANB Clock Source is AUXCLKIN.

#define CANABCLKSEL_PERxSYSCLK							0U							// CANB Clock Source is PERx.SYSCLK.
#define CANABCLKSEL_EXTOSC								1U							// CANB Clock Source is EXTOSC.
#define CANABCLKSEL_AUXCLKIN							2U							// CANB Clock Source is AUXCLKIN(from GPIO).

#define AUXOSCCLKSRCSEL_INTOSC2							0U							// AUXOSCCLK Clock Source is INTOSC2.
#define AUXOSCCLKSRCSEL_EXTOSC							1U							// AUXOSCCLK Clock Source is EXTOSC.
#define AUXOSCCLKSRCSEL_AUXCLKIN						2U							// AUXOSCCLK Clock Source is AUXCLKIN(from GPIO).



struct CLKSRCCTL3_BITS {                // bits description
    Uint16 XCLKOUTSEL:3;                // 2:0 XCLKOUT Source Select Bit
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLKSRCCTL3_REG {
    Uint32  all;
    struct  CLKSRCCTL3_BITS  bit;
};

// CLKSRCCLT3 Register
//// CLKSRCCLT3 Register : Byte Value
#define CLKSRCCTL3_XCLKOUTSEL_PLLSYSCLK					0x00000000UL				// XLCKOUT Clock Source is PLLSYSCLK.
#define CLKSRCCTL3_XCLKOUTSEL_PLLRAWCLK					0x00000001UL				// XLCKOUT Clock Source is PLLRAWCLK.
#define CLKSRCCTL3_XCLKOUTSEL_CPU1SYSCLK				0x00000002UL				// XLCKOUT Clock Source is CPU1.SYSCLK.
#define CLKSRCCTL3_XCLKOUTSEL_CPU2SYSCLK				0x00000003UL				// XLCKOUT Clock Source is CPU2.SYSCLK.
#define CLKSRCCTL3_XCLKOUTSEL_AUXPLLRAWCLK				0x00000004UL				// XLCKOUT Clock Source is AUXPLLRAWCLK.
#define CLKSRCCTL3_XCLKOUTSEL_INTOSC1					0x00000005UL				// XLCKOUT Clock Source is INTOSC1.
#define CLKSRCCTL3_XCLKOUTSEL_INTOSC2					0x00000006UL				// XLCKOUT Clock Source is INTOSC2.

struct SYSPLLCTL1_BITS {                // bits description
    Uint16 PLLEN:1;                     // 0 SYSPLL enable/disable bit
    Uint16 PLLCLKEN:1;                  // 1 SYSPLL bypassed or included in the PLLSYSCLK path
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYSPLLCTL1_REG {
    Uint32  all;
    struct  SYSPLLCTL1_BITS  bit;
};

// SYSPLLCTL1 Register
//// SYSPLLCTL1 Register : Byte Value
#define SYSPLLCTL1_PLLCLKEN_PLLBypassed					0x00000000UL				// PLLSYSCLK is Fed from SYSPLL Clock Output.
#define SYSPLLCTL1_PLLCLKEN_PLLUsed						0x00000002UL				// PLLSYSCLK is Fed from OSCCLK. SYSPLL is Bypassed.

#define SYSPLLCTL1_PLLEN_PLLDis							0x00000000UL				// SYSPLL is Powered Off. PLLSYSCLK is Fed from OSCCLK.
#define SYSPLLCTL1_PLLEN_PLLEn							0x00000001UL				// SYSPLL is Enabled.

//// SYSPLLCTL1 Register : Bit Value
#define PLLCLKEN_PLLBypassed							0U							// PLLSYSCLK is Fed from SYSPLL Clock Output.
#define PLLCLKEN_PLLUsed								1U							// PLLSYSCLK is Fed from OSCCLK. SYSPLL is Bypassed.

#define PLLEN_PLLDis									0U							// SYSPLL is Powered Off. PLLSYSCLK is Fed from OSCCLK.
#define PLLEN_PLLEn										1U							// SYSPLL is Enabled.

struct SYSPLLMULT_BITS {                // bits description
    Uint16 IMULT:7;                     // 6:0 SYSPLL Integer Multiplier
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 FMULT:2;                     // 9:8 SYSPLL Fractional Multiplier
    Uint16 rsvd2:6;                     // 15:10 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union SYSPLLMULT_REG {
    Uint32  all;
    struct  SYSPLLMULT_BITS  bit;
};

// SYSPLLMULT Register
//// SYSPLLMULT Register : Byte Value
#define SYSPLLMULT_FMULT_0P00							0x00000000UL				// PLLRAWCLK = OSCCLK x (IMULT + 0.00).
#define SYSPLLMULT_FMULT_0P25							0x00000100UL				// PLLRAWCLK = OSCCLK x (IMULT + 0.25).
#define SYSPLLMULT_FMULT_0P50							0x00000200UL				// PLLRAWCLK = OSCCLK x (IMULT + 0.50).
#define SYSPLLMULT_FMULT_0P75							0x00000300UL				// PLLRAWCLK = OSCCLK x (IMULT + 0.75).

#define SYSPLLMULT_IMULT_MULT(mul)						(mul & 0x000007FFUL)		// PLLRAWCLK = OSCCLK x (mul + (0.25 x FMULT)).

struct SYSPLLSTS_BITS {                 // bits description
    Uint16 LOCKS:1;                     // 0 SYSPLL Lock Status Bit
    Uint16 SLIPS:1;                     // 1 SYSPLL Slip Status Bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYSPLLSTS_REG {
    Uint32  all;
    struct  SYSPLLSTS_BITS  bit;
};

struct AUXPLLCTL1_BITS {                // bits description
    Uint16 PLLEN:1;                     // 0 AUXPLL enable/disable bit
    Uint16 PLLCLKEN:1;                  // 1 AUXPLL bypassed or included in the AUXPLLCLK path
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union AUXPLLCTL1_REG {
    Uint32  all;
    struct  AUXPLLCTL1_BITS  bit;
};

// AUXPLLCTL1 Register
//// AUXPLLCTL1 Register : Byte Value
#define AUXPLLCTL1_PLLCLKEN_PLLBypassed					0x00000000UL				// AUXPLLCLK is Fed from AUXOSCCLK.
#define AUXPLLCTL1_PLLCLKEN_PLLUsed						0x00000002UL				// AUXPLLCLK is Fed from AUXPLL Clock Output.

#define AUXPLLCTL1_PLLEN_PLLDis							0x00000000UL				// AUXPLL is Powered Off. AUXPLLCLK is Fed from AUXOSCCLK.
#define AUXPLLCTL1_PLLEN_PLLEn							0x00000001UL				// AUXPLL is Enabled.

struct AUXPLLMULT_BITS {                // bits description
    Uint16 IMULT:7;                     // 6:0 AUXPLL Integer Multiplier
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 FMULT:2;                     // 9:8 AUXPLL Fractional Multiplier
    Uint16 rsvd2:6;                     // 15:10 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union AUXPLLMULT_REG {
    Uint32  all;
    struct  AUXPLLMULT_BITS  bit;
};

// AUXPLLMULT Register
//// AUXPLLMULT Register : Byte Value
#define AUXPLLMULT_FMULT_0P00							0x00000000UL				// AUXPLLRAWCLK = AUXOSCCLK x (IMULT + 0.00).
#define AUXPLLMULT_FMULT_0P25							0x00000100UL				// AUXPLLRAWCLK = AUXOSCCLK x (IMULT + 0.25).
#define AUXPLLMULT_FMULT_0P50							0x00000200UL				// AUXPLLRAWCLK = AUXOSCCLK x (IMULT + 0.50).
#define AUXPLLMULT_FMULT_0P75							0x00000300UL				// AUXPLLRAWCLK = AUXOSCCLK x (IMULT + 0.75).

#define AUXPLLMULT_IMULT_MULT(mul)						(mul & 0x000007FFUL)		// AUXPLLRAWCLK = AUXOSCCLK x (mul + (0.25 x FMULT)).

struct AUXPLLSTS_BITS {                 // bits description
    Uint16 LOCKS:1;                     // 0 AUXPLL Lock Status Bit
    Uint16 SLIPS:1;                     // 1 AUXPLL Slip Status Bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union AUXPLLSTS_REG {
    Uint32  all;
    struct  AUXPLLSTS_BITS  bit;
};

struct SYSCLKDIVSEL_BITS {              // bits description
    Uint16 PLLSYSCLKDIV:6;              // 5:0 PLLSYSCLK Divide Select
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYSCLKDIVSEL_REG {
    Uint32  all;
    struct  SYSCLKDIVSEL_BITS  bit;
};

struct AUXCLKDIVSEL_BITS {              // bits description
    Uint16 AUXPLLDIV:2;                 // 1:0 AUXPLLCLK Divide Select
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union AUXCLKDIVSEL_REG {
    Uint32  all;
    struct  AUXCLKDIVSEL_BITS  bit;
};

struct PERCLKDIVSEL_BITS {              // bits description
    Uint16 EPWMCLKDIV:2;                // 1:0 EPWM Clock Divide Select
    Uint16 rsvd1:2;                     // 3:2 Reserved
    Uint16 EMIF1CLKDIV:1;               // 4 EMIF1  Clock Divide Select
    Uint16 rsvd2:1;                     // 5 Reserved
    Uint16 EMIF2CLKDIV:1;               // 6 EMIF2 Clock Divide Select
    Uint16 rsvd3:9;                     // 15:7 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union PERCLKDIVSEL_REG {
    Uint32  all;
    struct  PERCLKDIVSEL_BITS  bit;
};

// PERCLKDIVSEL Register
//// PERCLKDIVSEL Register : Byte Value
#define PERCLKDIVSEL_EMIF2CLKDIV_DIV1					0x00000000UL				// EMIF2CLK = CPU1.SYSCLK / 1.
#define PERCLKDIVSEL_EMIF2CLKDIV_DIV2					0x00000040UL				// EMIF2CLK = CPU1.SYSCLK / 2.

#define PERCLKDIVSEL_EMIF1CLKDIV_DIV1					0x00000000UL				// EMIF1CLK = PLLSYSCLK / 1.
#define PERCLKDIVSEL_EMIF1CLKDIV_DIV2					0x00000010UL				// EMIF1CLK = PLLSYSCLK / 2.

#define PERCLKDIVSEL_EPWMCLKDIV_DIV1					0x00000000UL				// EPWMCLK = PLLSYSCLK / 1.
#define PERCLKDIVSEL_EPWMCLKDIV_DIV2					0x00000001UL				// EPWMCLK = PLLSYSCLK / 2.

struct XCLKOUTDIVSEL_BITS {             // bits description
    Uint16 XCLKOUTDIV:2;                // 1:0 XCLKOUT Divide Select
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union XCLKOUTDIVSEL_REG {
    Uint32  all;
    struct  XCLKOUTDIVSEL_BITS  bit;
};

// XCLKOUTDIVSEL Register
//// XCLKOUTDIVSEL Register : Byte Value
#define XCLKOUTDIVSEL_XCLKOUTDIV_DIV1					0x00000000UL				// XCLKOUT = ??? / 1.
#define XCLKOUTDIVSEL_XCLKOUTDIV_DIV2					0x00000001UL				// XCLKOUT = ??? / 2.
#define XCLKOUTDIVSEL_XCLKOUTDIV_DIV4					0x00000002UL				// XCLKOUT = ??? / 4.
#define XCLKOUTDIVSEL_XCLKOUTDIV_DIV8					0x00000003UL				// XCLKOUT = ??? / 8.

struct LOSPCP_BITS {                    // bits description
    Uint16 LSPCLKDIV:3;                 // 2:0 LSPCLK Divide Select
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LOSPCP_REG {
    Uint32  all;
    struct  LOSPCP_BITS  bit;
};

// LOSPCP Register
//// LOSPCP Register : Byte Value
#define LOSPCP_LSPCLKDIV_DIV1							0x00000000UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 1.
#define LOSPCP_LSPCLKDIV_DIV2							0x00000001UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 2.
#define LOSPCP_LSPCLKDIV_DIV4							0x00000002UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 4.
#define LOSPCP_LSPCLKDIV_DIV6							0x00000003UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 6.
#define LOSPCP_LSPCLKDIV_DIV8							0x00000004UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 8.
#define LOSPCP_LSPCLKDIV_DIV10							0x00000005UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 10.
#define LOSPCP_LSPCLKDIV_DIV12							0x00000006UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 12.
#define LOSPCP_LSPCLKDIV_DIV14							0x00000007UL				// LSCPCLK = CPU1.SYSCLK or CPU2.SYSCLK / 14.

struct MCDCR_BITS {                     // bits description
    Uint16 MCLKSTS:1;                   // 0 Missing Clock Status Bit
    Uint16 MCLKCLR:1;                   // 1 Missing Clock Clear Bit
    Uint16 MCLKOFF:1;                   // 2 Missing Clock Detect Off Bit
    Uint16 OSCOFF:1;                    // 3 Oscillator Clock Off Bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union MCDCR_REG {
    Uint32  all;
    struct  MCDCR_BITS  bit;
};

// MCDCR Register
//// MCDCR Register : Byte Value
#define MCDCR_OSCOFF_OSCCLKtoMCDCon						0x00000000UL				// OSCCLK Connected to OSCCLK Counter in MCD Module.
#define MCDCR_OSCOFF_OSCCLKtoMCDDiscon					0x00000008UL				// OSCCLK Disconnected to OSCCLK Counter in MCD Module.

#define MCDCR_MCLKOFF_MissCLKEn							0x00000000UL				// Missing Clock Detect Circuit Enabled.
#define MCDCR_MCLKOFF_MissCLKDis						0x00000004UL				// Missing Clock Detect Circuit Disabled.

#define MCDCR_MCLKCLR_MissFlagClear						0x00000002UL				// Clear MCLKSTS bit and Reset the Missing Clock Detect Circuit.

struct X1CNT_BITS {                     // bits description
    Uint16 X1CNT:10;                    // 9:0 X1 Counter
    Uint16 rsvd1:6;                     // 15:10 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union X1CNT_REG {
    Uint32  all;
    struct  X1CNT_BITS  bit;
};

struct CLK_CFG_REGS {
    union   CLKSEM_REG                       CLKSEM;                       // Clock Control Semaphore Register
    union   CLKCFGLOCK1_REG                  CLKCFGLOCK1;                  // Lock bit for CLKCFG registers
    Uint16                                   rsvd1[4];                     // Reserved
    union   CLKSRCCTL1_REG                   CLKSRCCTL1;                   // Clock Source Control register-1
    union   CLKSRCCTL2_REG                   CLKSRCCTL2;                   // Clock Source Control register-2
    union   CLKSRCCTL3_REG                   CLKSRCCTL3;                   // Clock Source Control register-3
    union   SYSPLLCTL1_REG                   SYSPLLCTL1;                   // SYSPLL Control register-1
    Uint16                                   rsvd2[4];                     // Reserved
    union   SYSPLLMULT_REG                   SYSPLLMULT;                   // SYSPLL Multiplier register
    union   SYSPLLSTS_REG                    SYSPLLSTS;                    // SYSPLL Status register
    union   AUXPLLCTL1_REG                   AUXPLLCTL1;                   // AUXPLL Control register-1
    Uint16                                   rsvd3[4];                     // Reserved
    union   AUXPLLMULT_REG                   AUXPLLMULT;                   // AUXPLL Multiplier register
    union   AUXPLLSTS_REG                    AUXPLLSTS;                    // AUXPLL Status register
    union   SYSCLKDIVSEL_REG                 SYSCLKDIVSEL;                 // System Clock Divider Select register
    union   AUXCLKDIVSEL_REG                 AUXCLKDIVSEL;                 // Auxillary Clock Divider Select register
    union   PERCLKDIVSEL_REG                 PERCLKDIVSEL;                 // Peripheral Clock Divider Selet register
    union   XCLKOUTDIVSEL_REG                XCLKOUTDIVSEL;                // XCLKOUT Divider Select register
    Uint16                                   rsvd4[2];                     // Reserved
    union   LOSPCP_REG                       LOSPCP;                       // Low Speed Clock Source Prescalar
    union   MCDCR_REG                        MCDCR;                        // Missing Clock Detect Control Register
    union   X1CNT_REG                        X1CNT;                        // 10-bit Counter on X1 Clock
};

struct CPUSYSLOCK1_BITS {               // bits description
    Uint16 HIBBOOTMODE:1;               // 0 Lock bit for HIBBOOTMODE register
    Uint16 IORESTOREADDR:1;             // 1 Lock bit for IORESTOREADDR Register
    Uint16 PIEVERRADDR:1;               // 2 Lock bit for PIEVERRADDR Register
    Uint16 PCLKCR0:1;                   // 3 Lock bit for PCLKCR0 Register
    Uint16 PCLKCR1:1;                   // 4 Lock bit for PCLKCR1 Register
    Uint16 PCLKCR2:1;                   // 5 Lock bit for PCLKCR2 Register
    Uint16 PCLKCR3:1;                   // 6 Lock bit for PCLKCR3 Register
    Uint16 PCLKCR4:1;                   // 7 Lock bit for PCLKCR4 Register
    Uint16 PCLKCR5:1;                   // 8 Lock bit for PCLKCR5 Register
    Uint16 PCLKCR6:1;                   // 9 Lock bit for PCLKCR6 Register
    Uint16 PCLKCR7:1;                   // 10 Lock bit for PCLKCR7 Register
    Uint16 PCLKCR8:1;                   // 11 Lock bit for PCLKCR8 Register
    Uint16 PCLKCR9:1;                   // 12 Lock bit for PCLKCR9 Register
    Uint16 PCLKCR10:1;                  // 13 Lock bit for PCLKCR10 Register
    Uint16 PCLKCR11:1;                  // 14 Lock bit for PCLKCR11 Register
    Uint16 PCLKCR12:1;                  // 15 Lock bit for PCLKCR12 Register
    Uint16 PCLKCR13:1;                  // 16 Lock bit for PCLKCR13 Register
    Uint16 PCLKCR14:1;                  // 17 Lock bit for PCLKCR14 Register
    Uint16 PCLKCR15:1;                  // 18 Lock bit for PCLKCR15 Register
    Uint16 PCLKCR16:1;                  // 19 Lock bit for PCLKCR16 Register
    Uint16 SECMSEL:1;                   // 20 Lock bit for SECMSEL Register
    Uint16 LPMCR:1;                     // 21 Lock bit for LPMCR Register
    Uint16 GPIOLPMSEL0:1;               // 22 Lock bit for GPIOLPMSEL0 Register
    Uint16 GPIOLPMSEL1:1;               // 23 Lock bit for GPIOLPMSEL1 Register
    Uint16 rsvd1:8;                     // 31:24 Reserved
};

union CPUSYSLOCK1_REG {
    Uint32  all;
    struct  CPUSYSLOCK1_BITS  bit;
};

// CPUSYSLOCK1 Register
//// CPUSYSLOCK1 Register : Byte Value
#define CPUSYSLOCK1_GPIOLPMSEL1_Lock					0x00800000UL				// PGIOLPMSEL1 Register is Locked.
#define CPUSYSLOCK1_GPIOLPMSEL0_Lock					0x00400000UL				// PGIOLPMSEL0 Register is Locked.
#define CPUSYSLOCK1_LPMCR_Lock							0x00200000UL				// LPMCR Register is Locked.
#define CPUSYSLOCK1_SECMSEL_Lock						0x00100000UL				// SECMSEL Register is Locked.
#define CPUSYSLOCK1_PCLKCR16_Lock						0x00080000UL				// PCLKCR16 Register is Locked.
#define CPUSYSLOCK1_PCLKCR15_Lock						0x00040000UL				// PCLKCR15 Register is Locked.
#define CPUSYSLOCK1_PCLKCR14_Lock						0x00020000UL				// PCLKCR14 Register is Locked.
#define CPUSYSLOCK1_PCLKCR13_Lock						0x00010000UL				// PCLKCR13 Register is Locked.
#define CPUSYSLOCK1_PCLKCR12_Lock						0x00008000UL				// PCLKCR12 Register is Locked.
#define CPUSYSLOCK1_PCLKCR11_Lock						0x00004000UL				// PCLKCR11 Register is Locked.
#define CPUSYSLOCK1_PCLKCR10_Lock						0x00002000UL				// PCLKCR10 Register is Locked.
#define CPUSYSLOCK1_PCLKCR9_Lock						0x00001000UL				// PCLKCR9 Register is Locked.
#define CPUSYSLOCK1_PCLKCR8_Lock						0x00000800UL				// PCLKCR8 Register is Locked.
#define CPUSYSLOCK1_PCLKCR7_Lock						0x00000400UL				// PCLKCR7 Register is Locked.
#define CPUSYSLOCK1_PCLKCR6_Lock						0x00000200UL				// PCLKCR6 Register is Locked.
#define CPUSYSLOCK1_PCLKCR5_Lock						0x00000100UL				// PCLKCR5 Register is Locked.
#define CPUSYSLOCK1_PCLKCR4_Lock						0x00000080UL				// PCLKCR4 Register is Locked.
#define CPUSYSLOCK1_PCLKCR3_Lock						0x00000040UL				// PCLKCR3 Register is Locked.
#define CPUSYSLOCK1_PCLKCR2_Lock						0x00000020UL				// PCLKCR2 Register is Locked.
#define CPUSYSLOCK1_PCLKCR1_Lock						0x00000010UL				// PCLKCR1 Register is Locked.
#define CPUSYSLOCK1_PCLKCR0_Lock						0x00000008UL				// PCLKCR0 Register is Locked.
#define CPUSYSLOCK1_PIEVERRADDR_Lock					0x00000004UL				// PIEVERRADDR Register is Locked.
#define CPUSYSLOCK1_IORESTOREADDR_Lock					0x00000002UL				// IORESTOREADDR Register is Locked.
#define CPUSYSLOCK1_HIBBOOTMODE_Lock					0x00000001UL				// HIBBOOTMODE Register is Locked.

//// CPUSYSLOCK1 Register : Quick Value
#define CPUSYSLOCK1_PCLKCR_AllLock						0x000FFFF8UL				// All PCLKCR Registers are Locked.

struct IORESTOREADDR_BITS {             // bits description
    Uint32 ADDR:22;                     // 21:0 restoreIO() routine address
    Uint16 rsvd1:10;                    // 31:22 Reserved
};

union IORESTOREADDR_REG {
    Uint32  all;
    struct  IORESTOREADDR_BITS  bit;
};

struct PIEVERRADDR_BITS {               // bits description
    Uint32 ADDR:22;                     // 21:0 PIE Vector Fetch Error Handler Routine Address
    Uint16 rsvd1:10;                    // 31:22 Reserved
};

union PIEVERRADDR_REG {
    Uint32  all;
    struct  PIEVERRADDR_BITS  bit;
};

struct PCLKCR0_BITS {                   // bits description
    Uint16 CLA1:1;                      // 0 CLA1 Clock Enable Bit
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 DMA:1;                       // 2 DMA Clock Enable bit
    Uint16 CPUTIMER0:1;                 // 3 CPUTIMER0 Clock Enable bit
    Uint16 CPUTIMER1:1;                 // 4 CPUTIMER1 Clock Enable bit
    Uint16 CPUTIMER2:1;                 // 5 CPUTIMER2 Clock Enable bit
    Uint16 rsvd2:10;                    // 15:6 Reserved
    Uint16 HRPWM:1;                     // 16 HRPWM Clock Enable Bit
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 TBCLKSYNC:1;                 // 18 EPWM Time Base Clock sync
    Uint16 GTBCLKSYNC:1;                // 19 EPWM Time Base Clock Global sync
    Uint16 rsvd4:12;                    // 31:20 Reserved
};

union PCLKCR0_REG {
    Uint32  all;
    struct  PCLKCR0_BITS  bit;
};

// PCLKCR0 Register
//// PCLKCR0 Register : Byte Value
#ifdef CPU1
#define PCLKCR0_GTBCLKSYNC_PWMGlobalCLKDis				0x00000000UL				// EPWM Time Base Clock Global Stop.
#define PCLKCR0_GTBCLKSYNC_PWMGlobalCLKEn				0x00080000UL				// EPWM Time Base Clock Global Start.

#define PCLKCR0_HRPWM_CLKDis							0x00000000UL				// HRPWM Clock is Disabled.
#define PCLKCR0_HRPWM_CLKEn								0x00010000UL				// HRPWM Clock is Enabled.
#endif

#define PCLKCR0_TBCLKSYNC_PWMCPUCLKDis					0x00000000UL				// EPWM Time Base Clock Owned By CPUx Stop.
#define PCLKCR0_TBCLKSYNC_PWMCPUCLKEn					0x00040000UL				// EPWM Time Base Clock Owned By CPUx Start.

#define PCLKCR0_CPUTIME2_CLKDis							0x00000000UL				// CPUx.Timer2 Clock is Disabled.
#define PCLKCR0_CPUTIME2_CLKEn							0x00000020UL				// CPUx.Timer2 Clock is Enabled.

#define PCLKCR0_CPUTIME1_CLKDis							0x00000000UL				// CPUx.Timer1 Clock is Disabled.
#define PCLKCR0_CPUTIME1_CLKEn							0x00000010UL				// CPUx.Timer1 Clock is Enabled.

#define PCLKCR0_CPUTIME0_CLKDis							0x00000000UL				// CPUx.Timer0 Clock is Disabled.
#define PCLKCR0_CPUTIME0_CLKEn							0x00000008UL				// CPUx.Timer0 Clock is Enabled.

#define PCLKCR0_DMA_CLKDis								0x00000000UL				// DMA Clock is Disabled.
#define PCLKCR0_DMA_CLKEn								0x00000004UL				// DMA Clock is Enabled.

#define PCLKCR0_CLA1_CLKDis								0x00000000UL				// CLA1 Clock is Disabled.
#define PCLKCR0_CLA1_CLKEn								0x00000001UL				// CLA1 Clock is Enabled.

struct PCLKCR1_BITS {                   // bits description
    Uint16 EMIF1:1;                     // 0 EMIF1 Clock Enable bit
    Uint16 EMIF2:1;                     // 1 EMIF2 Clock Enable bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR1_REG {
    Uint32  all;
    struct  PCLKCR1_BITS  bit;
};

#ifdef CPU1
// PCLKCR1 Register
//// PCLKCR1 Register : Byte Value
#define PCLKCR1_EMIF2_CLKDis							0x00000000UL				// EMIF2 Clock is Disabled.
#define PCLKCR1_EMIF2_CLKEn								0x00000002UL				// EMIF2 Clock is Enabled.

#define PCLKCR1_EMIF1_CLKDis							0x00000000UL				// EMIF1 Clock is Disabled.
#define PCLKCR1_EMIF1_CLKEn								0x00000001UL				// EMIF1 Clock is Enabled.
#endif

struct PCLKCR2_BITS {                   // bits description
    Uint16 EPWM1:1;                     // 0 EPWM1 Clock Enable bit
    Uint16 EPWM2:1;                     // 1 EPWM2 Clock Enable bit
    Uint16 EPWM3:1;                     // 2 EPWM3 Clock Enable bit
    Uint16 EPWM4:1;                     // 3 EPWM4 Clock Enable bit
    Uint16 EPWM5:1;                     // 4 EPWM5 Clock Enable bit
    Uint16 EPWM6:1;                     // 5 EPWM6 Clock Enable bit
    Uint16 EPWM7:1;                     // 6 EPWM7 Clock Enable bit
    Uint16 EPWM8:1;                     // 7 EPWM8 Clock Enable bit
    Uint16 EPWM9:1;                     // 8 EPWM9 Clock Enable bit
    Uint16 EPWM10:1;                    // 9 EPWM10 Clock Enable bit
    Uint16 EPWM11:1;                    // 10 EPWM11 Clock Enable bit
    Uint16 EPWM12:1;                    // 11 EPWM12 Clock Enable bit
    Uint16 rsvd1:1;                     // 12 Reserved
    Uint16 rsvd2:1;                     // 13 Reserved
    Uint16 rsvd3:1;                     // 14 Reserved
    Uint16 rsvd4:1;                     // 15 Reserved
    Uint16 rsvd5:16;                    // 31:16 Reserved
};

union PCLKCR2_REG {
    Uint32  all;
    struct  PCLKCR2_BITS  bit;
};

// PCLKCR2 Register
//// PCLKCR2 Register : Byte Value
#define PCLKCR2_EPWM12_CLKDis							0x00000000UL				// EPWM12 Clock is Disabled.
#define PCLKCR2_EPWM12_CLKEn							0x00000800UL				// EPWM12 Clock is Enabled.

#define PCLKCR2_EPWM11_CLKDis							0x00000000UL				// EPWM11 Clock is Disabled.
#define PCLKCR2_EPWM11_CLKEn							0x00000400UL				// EPWM11 Clock is Enabled.

#define PCLKCR2_EPWM10_CLKDis							0x00000000UL				// EPWM10 Clock is Disabled.
#define PCLKCR2_EPWM10_CLKEn							0x00000200UL				// EPWM10 Clock is Enabled.

#define PCLKCR2_EPWM9_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM9_CLKEn								0x00000100UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM8_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM8_CLKEn								0x00000080UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM7_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM7_CLKEn								0x00000040UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM6_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM6_CLKEn								0x00000020UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM5_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM5_CLKEn								0x00000010UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM4_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM4_CLKEn								0x00000008UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM3_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM3_CLKEn								0x00000004UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM2_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM2_CLKEn								0x00000002UL				// EPWM9 Clock is Enabled.

#define PCLKCR2_EPWM1_CLKDis							0x00000000UL				// EPWM9 Clock is Disabled.
#define PCLKCR2_EPWM1_CLKEn								0x00000001UL				// EPWM9 Clock is Enabled.

struct PCLKCR3_BITS {                   // bits description
    Uint16 ECAP1:1;                     // 0 ECAP1 Clock Enable bit
    Uint16 ECAP2:1;                     // 1 ECAP2 Clock Enable bit
    Uint16 ECAP3:1;                     // 2 ECAP3 Clock Enable bit
    Uint16 ECAP4:1;                     // 3 ECAP4 Clock Enable bit
    Uint16 ECAP5:1;                     // 4 ECAP5 Clock Enable bit
    Uint16 ECAP6:1;                     // 5 ECAP6 Clock Enable bit
    Uint16 rsvd1:1;                     // 6 Reserved
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:8;                     // 15:8 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union PCLKCR3_REG {
    Uint32  all;
    struct  PCLKCR3_BITS  bit;
};

// PCLKCR3 Register
//// PCLKCR3 Register : Byte Value
#define PCLKCR3_ECAP6_CLKDis							0x00000000UL				// ECAP6 Clock is Disabled.
#define PCLKCR3_ECAP6_CLKEn								0x00000020UL				// ECAP6 Clock is Enabled.

#define PCLKCR3_ECAP5_CLKDis							0x00000000UL				// ECAP6 Clock is Disabled.
#define PCLKCR3_ECAP5_CLKEn								0x00000010UL				// ECAP6 Clock is Enabled.

#define PCLKCR3_ECAP4_CLKDis							0x00000000UL				// ECAP6 Clock is Disabled.
#define PCLKCR3_ECAP4_CLKEn								0x00000008UL				// ECAP6 Clock is Enabled.

#define PCLKCR3_ECAP3_CLKDis							0x00000000UL				// ECAP6 Clock is Disabled.
#define PCLKCR3_ECAP3_CLKEn								0x00000004UL				// ECAP6 Clock is Enabled.

#define PCLKCR3_ECAP2_CLKDis							0x00000000UL				// ECAP6 Clock is Disabled.
#define PCLKCR3_ECAP2_CLKEn								0x00000002UL				// ECAP6 Clock is Enabled.

#define PCLKCR3_ECAP1_CLKDis							0x00000000UL				// ECAP6 Clock is Disabled.
#define PCLKCR3_ECAP1_CLKEn								0x00000001UL				// ECAP6 Clock is Enabled.


struct PCLKCR4_BITS {                   // bits description
    Uint16 EQEP1:1;                     // 0 EQEP1 Clock Enable bit
    Uint16 EQEP2:1;                     // 1 EQEP2 Clock Enable bit
    Uint16 EQEP3:1;                     // 2 EQEP3 Clock Enable bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union PCLKCR4_REG {
    Uint32  all;
    struct  PCLKCR4_BITS  bit;
};

// PCLKCR4 Register
//// PCLKCR4 Register : Byte Value
#define PCLKCR4_EQEP3_CLKDis							0x00000000UL				// EQEP3 Clock is Disabled.
#define PCLKCR4_EQEP3_CLKEn								0x00000004UL				// EQEP3 Clock is Enabled.

#define PCLKCR4_EQEP2_CLKDis							0x00000000UL				// EQEP3 Clock is Disabled.
#define PCLKCR4_EQEP2_CLKEn								0x00000002UL				// EQEP3 Clock is Enabled.

#define PCLKCR4_EQEP1_CLKDis							0x00000000UL				// EQEP3 Clock is Disabled.
#define PCLKCR4_EQEP1_CLKEn								0x00000001UL				// EQEP3 Clock is Enabled.

struct PCLKCR6_BITS {                   // bits description
    Uint16 SD1:1;                       // 0 SD1 Clock Enable bit
    Uint16 SD2:1;                       // 1 SD2 Clock Enable bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:1;                     // 5 Reserved
    Uint16 rsvd5:1;                     // 6 Reserved
    Uint16 rsvd6:1;                     // 7 Reserved
    Uint16 rsvd7:8;                     // 15:8 Reserved
    Uint16 rsvd8:16;                    // 31:16 Reserved
};

union PCLKCR6_REG {
    Uint32  all;
    struct  PCLKCR6_BITS  bit;
};

// PCLKCR6 Register
//// PCLKCR6 Register : Byte Value
#define PCLKCR6_SD2_CLKDis								0x00000000UL				// SD2 Clock is Disabled.
#define PCLKCR6_SD2_CLKEn								0x00000002UL				// SD2 Clock is Enabled.

#define PCLKCR6_SD1_CLKDis								0x00000000UL				// SD1 Clock is Disabled.
#define PCLKCR6_SD1_CLKEn								0x00000001UL				// SD1 Clock is Enabled.

struct PCLKCR7_BITS {                   // bits description
    Uint16 SCI_A:1;                     // 0 SCI_A Clock Enable bit
    Uint16 SCI_B:1;                     // 1 SCI_B Clock Enable bit
    Uint16 SCI_C:1;                     // 2 SCI_C Clock Enable bit
    Uint16 SCI_D:1;                     // 3 SCI_D Clock Enable bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR7_REG {
    Uint32  all;
    struct  PCLKCR7_BITS  bit;
};

// PCLKCR7 Register
//// PCLKCR7 Register : Byte Value
#define PCLKCR7_SCI_D_CLKDis							0x00000000UL				// SCI-D Clock is Disabled.
#define PCLKCR7_SCI_D_CLKEn								0x00000008UL				// SCI-D Clock is Enabled.

#define PCLKCR7_SCI_C_CLKDis							0x00000000UL				// SCI-C Clock is Disabled.
#define PCLKCR7_SCI_C_CLKEn								0x00000004UL				// SCI-C Clock is Enabled.

#define PCLKCR7_SCI_B_CLKDis							0x00000000UL				// SCI-B Clock is Disabled.
#define PCLKCR7_SCI_B_CLKEn								0x00000002UL				// SCI-B Clock is Enabled.

#define PCLKCR7_SCI_A_CLKDis							0x00000000UL				// SCI-A Clock is Disabled.
#define PCLKCR7_SCI_A_CLKEn								0x00000001UL				// SCI-A Clock is Enabled.

struct PCLKCR8_BITS {                   // bits description
    Uint16 SPI_A:1;                     // 0 SPI_A Clock Enable bit
    Uint16 SPI_B:1;                     // 1 SPI_B Clock Enable bit
    Uint16 SPI_C:1;                     // 2 SPI_C Clock Enable bit
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:12;                    // 15:4 Reserved
    Uint16 rsvd3:1;                     // 16 Reserved
    Uint16 rsvd4:1;                     // 17 Reserved
    Uint16 rsvd5:14;                    // 31:18 Reserved
};

union PCLKCR8_REG {
    Uint32  all;
    struct  PCLKCR8_BITS  bit;
};

// PCLKCR8 Register
//// PCLKCR8 Register : Byte Value
#define PCLKCR8_SPI_C_CLKDis							0x00000000UL				// SPI-C Clock is Disabled.
#define PCLKCR8_SPI_C_CLKEn								0x00000004UL				// SPI-C Clock is Enabled.

#define PCLKCR8_SPI_B_CLKDis							0x00000000UL				// SPI-B Clock is Disabled.
#define PCLKCR8_SPI_B_CLKEn								0x00000002UL				// SPI-B Clock is Enabled.

#define PCLKCR8_SPI_A_CLKDis							0x00000000UL				// SPI-A Clock is Disabled.
#define PCLKCR8_SPI_A_CLKEn								0x00000001UL				// SPI-A Clock is Enabled.

struct PCLKCR9_BITS {                   // bits description
    Uint16 I2C_A:1;                     // 0 I2C_A Clock Enable bit
    Uint16 I2C_B:1;                     // 1 I2C_B Clock Enable bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:1;                     // 16 Reserved
    Uint16 rsvd3:1;                     // 17 Reserved
    Uint16 rsvd4:14;                    // 31:18 Reserved
};

union PCLKCR9_REG {
    Uint32  all;
    struct  PCLKCR9_BITS  bit;
};

// PCLKCR9 Register
//// PCLKCR9 Register : Byte Value
#define PCLKCR9_I2C_B_CLKDis							0x00000000UL				// I2C-B Clock is Disabled.
#define PCLKCR9_I2C_B_CLKEn								0x00000002UL				// I2C-B Clock is Enabled.

#define PCLKCR9_I2C_A_CLKDis							0x00000000UL				// I2C-A Clock is Disabled.
#define PCLKCR9_I2C_A_CLKEn								0x00000001UL				// I2C-A Clock is Enabled.

struct PCLKCR10_BITS {                  // bits description
    Uint16 CAN_A:1;                     // 0 CAN_A Clock Enable bit
    Uint16 CAN_B:1;                     // 1 CAN_B Clock Enable bit
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:12;                    // 15:4 Reserved
    Uint16 rsvd4:16;                    // 31:16 Reserved
};

union PCLKCR10_REG {
    Uint32  all;
    struct  PCLKCR10_BITS  bit;
};

// PCLKCR10 Register
//// PCLKCR10 Register : Byte Value
#define PCLKCR10_CAN_B_CLKDis							0x00000000UL				// CAN-B Clock is Disabled.
#define PCLKCR10_CAN_B_CLKEn							0x00000002UL				// CAN-B Clock is Enabled.

#define PCLKCR10_CAN_A_CLKDis							0x00000000UL				// CAN-A Clock is Disabled.
#define PCLKCR10_CAN_A_CLKEn							0x00000001UL				// CAN-A Clock is Enabled.

struct PCLKCR11_BITS {                  // bits description
    Uint16 McBSP_A:1;                   // 0 McBSP_A Clock Enable bit
    Uint16 McBSP_B:1;                   // 1 McBSP_B Clock Enable bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 USB_A:1;                     // 16 USB_A Clock Enable bit
    Uint16 rsvd2:1;                     // 17 Reserved
    Uint16 rsvd3:14;                    // 31:18 Reserved
};

union PCLKCR11_REG {
    Uint32  all;
    struct  PCLKCR11_BITS  bit;
};

// PCLKCR11 Register
//// PCLKCR11 Register : Byte Value
#define PCLKCR11_USB_A_CLKDis							0x00000000UL				// USB-A Clock is Disabled.
#define PCLKCR11_USB_A_CLKEn							0x00010000UL				// USB-A Clock is Enabled.

#define PCLKCR11_McBSP_B_CLKDis							0x00000000UL				// McBSP-B Clock is Disabled.
#define PCLKCR11_McBSP_B_CLKEn							0x00000002UL				// McBSP-B Clock is Enabled.

#define PCLKCR11_McBSP_A_CLKDis							0x00000000UL				// McBSP-A Clock is Disabled.
#define PCLKCR11_McBSP_A_CLKEn							0x00000001UL				// McBSP-A Clock is Enabled.

struct PCLKCR12_BITS {                  // bits description
    Uint16 uPP_A:1;                     // 0 uPP_A Clock Enable bit
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 rsvd2:14;                    // 15:2 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union PCLKCR12_REG {
    Uint32  all;
    struct  PCLKCR12_BITS  bit;
};

#ifdef CPU1
// PCLKCR12 Register
//// PCLKCR12 Register : Byte Value
#define PCLKCR12_UPP_A_CLKDis							0x00000000UL				// uPP-A Clock is Disabled.
#define PCLKCR12_UPP_A_CLKEn							0x00000001UL				// uPP-A Clock is Enabled.
#endif

struct PCLKCR13_BITS {                  // bits description
    Uint16 ADC_A:1;                     // 0 ADC_A Clock Enable bit
    Uint16 ADC_B:1;                     // 1 ADC_B Clock Enable bit
    Uint16 ADC_C:1;                     // 2 ADC_C Clock Enable bit
    Uint16 ADC_D:1;                     // 3 ADC_D Clock Enable bit
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR13_REG {
    Uint32  all;
    struct  PCLKCR13_BITS  bit;
};

// PCLKCR13 Register
//// PCLKCR13 Register : Byte Value
#define PCLKCR13_ADC_D_CLKDis							0x00000000UL				// ADC-D Clock is Disabled.
#define PCLKCR13_ADC_D_CLKEn							0x00000008UL				// ADC-D Clock is Enabled.

#define PCLKCR13_ADC_C_CLKDis							0x00000000UL				// ADC-C Clock is Disabled.
#define PCLKCR13_ADC_C_CLKEn							0x00000004UL				// ADC-C Clock is Enabled.

#define PCLKCR13_ADC_B_CLKDis							0x00000000UL				// ADC-B Clock is Disabled.
#define PCLKCR13_ADC_B_CLKEn							0x00000002UL				// ADC-B Clock is Enabled.

#define PCLKCR13_ADC_A_CLKDis							0x00000000UL				// ADC-A Clock is Disabled.
#define PCLKCR13_ADC_A_CLKEn							0x00000001UL				// ADC-A Clock is Enabled.

struct PCLKCR14_BITS {                  // bits description
    Uint16 CMPSS1:1;                    // 0 CMPSS1 Clock Enable bit
    Uint16 CMPSS2:1;                    // 1 CMPSS2 Clock Enable bit
    Uint16 CMPSS3:1;                    // 2 CMPSS3 Clock Enable bit
    Uint16 CMPSS4:1;                    // 3 CMPSS4 Clock Enable bit
    Uint16 CMPSS5:1;                    // 4 CMPSS5 Clock Enable bit
    Uint16 CMPSS6:1;                    // 5 CMPSS6 Clock Enable bit
    Uint16 CMPSS7:1;                    // 6 CMPSS7 Clock Enable bit
    Uint16 CMPSS8:1;                    // 7 CMPSS8 Clock Enable bit
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PCLKCR14_REG {
    Uint32  all;
    struct  PCLKCR14_BITS  bit;
};

// PCLKCR14 Register
//// PCLKCR14 Register : Byte Value
#define PCLKCR14_CMPSS8_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS8_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

#define PCLKCR14_CMPSS7_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS7_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

#define PCLKCR14_CMPSS6_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS6_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

#define PCLKCR14_CMPSS5_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS5_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

#define PCLKCR14_CMPSS4_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS4_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

#define PCLKCR14_CMPSS3_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS3_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

#define PCLKCR14_CMPSS2_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS2_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

#define PCLKCR14_CMPSS1_CLKDis							0x00000000UL				// Compare Sub-System Clock is Disabled.
#define PCLKCR14_CMPSS1_CLKEn							0x00000008UL				// Compare Sub-System Clock is Enabled.

struct PCLKCR16_BITS {                  // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:12;                    // 15:4 Reserved
    Uint16 DAC_A:1;                     // 16 Buffered_DAC_A Clock Enable Bit
    Uint16 DAC_B:1;                     // 17 Buffered_DAC_B Clock Enable Bit
    Uint16 DAC_C:1;                     // 18 Buffered_DAC_C Clock Enable Bit
    Uint16 rsvd6:1;                     // 19 Reserved
    Uint16 rsvd7:12;                    // 31:20 Reserved
};

union PCLKCR16_REG {
    Uint32  all;
    struct  PCLKCR16_BITS  bit;
};

// PCLKCR16 Register
//// PCLKCR16 Register : Byte Value
#define PCLKCR16_DAC_C_CLKDis							0x00000000UL				// DAC-C Clock is Disabled.
#define PCLKCR16_DAC_C_CLKEn							0x00040000UL				// DAC-C Clock is Enabled.

#define PCLKCR16_DAC_B_CLKDis							0x00000000UL				// DAC-B Clock is Disabled.
#define PCLKCR16_DAC_B_CLKEn							0x00020000UL				// DAC-B Clock is Enabled.

#define PCLKCR16_DAC_A_CLKDis							0x00000000UL				// DAC-A Clock is Disabled.
#define PCLKCR16_DAC_A_CLKEn							0x00010000UL				// DAC-A Clock is Enabled.

struct SECMSEL_BITS {                   // bits description
    Uint16 PF1SEL:2;                    // 1:0 Secondary Master Select for VBUS32_1 Bridge
    Uint16 PF2SEL:2;                    // 3:2 Secondary Master Select for VBUS32_2 Bridge
    Uint16 rsvd1:2;                     // 5:4 Reserved
    Uint16 rsvd2:2;                     // 7:6 Reserved
    Uint16 rsvd3:2;                     // 9:8 Reserved
    Uint16 rsvd4:2;                     // 11:10 Reserved
    Uint16 rsvd5:2;                     // 13:12 Reserved
    Uint16 rsvd6:2;                     // 15:14 Reserved
    Uint16 rsvd7:16;                    // 31:16 Reserved
};

union SECMSEL_REG {
    Uint32  all;
    struct  SECMSEL_BITS  bit;
};

struct LPMCR_BITS {                     // bits description
    Uint16 LPM:2;                       // 1:0 Low Power Mode setting
    Uint16 QUALSTDBY:6;                 // 7:2 STANDBY Wakeup Pin Qualification Setting
    Uint16 rsvd1:7;                     // 14:8 Reserved
    Uint16 WDINTE:1;                    // 15 Enable for WDINT wakeup from STANDBY
    Uint16 M0M1MODE:2;                  // 17:16 Configuration for M0 and M1 mode during HIB
    Uint16 rsvd2:13;                    // 30:18 Reserved
    Uint16 IOISODIS:1;                  // 31 IO Isolation Disable
};

union LPMCR_REG {
    Uint32  all;
    struct  LPMCR_BITS  bit;
};

struct GPIOLPMSEL0_BITS {               // bits description
    Uint16 GPIO0:1;                     // 0 GPIO0 Enable for LPM Wakeup
    Uint16 GPIO1:1;                     // 1 GPIO1 Enable for LPM Wakeup
    Uint16 GPIO2:1;                     // 2 GPIO2 Enable for LPM Wakeup
    Uint16 GPIO3:1;                     // 3 GPIO3 Enable for LPM Wakeup
    Uint16 GPIO4:1;                     // 4 GPIO4 Enable for LPM Wakeup
    Uint16 GPIO5:1;                     // 5 GPIO5 Enable for LPM Wakeup
    Uint16 GPIO6:1;                     // 6 GPIO6 Enable for LPM Wakeup
    Uint16 GPIO7:1;                     // 7 GPIO7 Enable for LPM Wakeup
    Uint16 GPIO8:1;                     // 8 GPIO8 Enable for LPM Wakeup
    Uint16 GPIO9:1;                     // 9 GPIO9 Enable for LPM Wakeup
    Uint16 GPIO10:1;                    // 10 GPIO10 Enable for LPM Wakeup
    Uint16 GPIO11:1;                    // 11 GPIO11 Enable for LPM Wakeup
    Uint16 GPIO12:1;                    // 12 GPIO12 Enable for LPM Wakeup
    Uint16 GPIO13:1;                    // 13 GPIO13 Enable for LPM Wakeup
    Uint16 GPIO14:1;                    // 14 GPIO14 Enable for LPM Wakeup
    Uint16 GPIO15:1;                    // 15 GPIO15 Enable for LPM Wakeup
    Uint16 GPIO16:1;                    // 16 GPIO16 Enable for LPM Wakeup
    Uint16 GPIO17:1;                    // 17 GPIO17 Enable for LPM Wakeup
    Uint16 GPIO18:1;                    // 18 GPIO18 Enable for LPM Wakeup
    Uint16 GPIO19:1;                    // 19 GPIO19 Enable for LPM Wakeup
    Uint16 GPIO20:1;                    // 20 GPIO20 Enable for LPM Wakeup
    Uint16 GPIO21:1;                    // 21 GPIO21 Enable for LPM Wakeup
    Uint16 GPIO22:1;                    // 22 GPIO22 Enable for LPM Wakeup
    Uint16 GPIO23:1;                    // 23 GPIO23 Enable for LPM Wakeup
    Uint16 GPIO24:1;                    // 24 GPIO24 Enable for LPM Wakeup
    Uint16 GPIO25:1;                    // 25 GPIO25 Enable for LPM Wakeup
    Uint16 GPIO26:1;                    // 26 GPIO26 Enable for LPM Wakeup
    Uint16 GPIO27:1;                    // 27 GPIO27 Enable for LPM Wakeup
    Uint16 GPIO28:1;                    // 28 GPIO28 Enable for LPM Wakeup
    Uint16 GPIO29:1;                    // 29 GPIO29 Enable for LPM Wakeup
    Uint16 GPIO30:1;                    // 30 GPIO30 Enable for LPM Wakeup
    Uint16 GPIO31:1;                    // 31 GPIO31 Enable for LPM Wakeup
};

union GPIOLPMSEL0_REG {
    Uint32  all;
    struct  GPIOLPMSEL0_BITS  bit;
};

struct GPIOLPMSEL1_BITS {               // bits description
    Uint16 GPIO32:1;                    // 0 GPIO32 Enable for LPM Wakeup
    Uint16 GPIO33:1;                    // 1 GPIO33 Enable for LPM Wakeup
    Uint16 GPIO34:1;                    // 2 GPIO34 Enable for LPM Wakeup
    Uint16 GPIO35:1;                    // 3 GPIO35 Enable for LPM Wakeup
    Uint16 GPIO36:1;                    // 4 GPIO36 Enable for LPM Wakeup
    Uint16 GPIO37:1;                    // 5 GPIO37 Enable for LPM Wakeup
    Uint16 GPIO38:1;                    // 6 GPIO38 Enable for LPM Wakeup
    Uint16 GPIO39:1;                    // 7 GPIO39 Enable for LPM Wakeup
    Uint16 GPIO40:1;                    // 8 GPIO40 Enable for LPM Wakeup
    Uint16 GPIO41:1;                    // 9 GPIO41 Enable for LPM Wakeup
    Uint16 GPIO42:1;                    // 10 GPIO42 Enable for LPM Wakeup
    Uint16 GPIO43:1;                    // 11 GPIO43 Enable for LPM Wakeup
    Uint16 GPIO44:1;                    // 12 GPIO44 Enable for LPM Wakeup
    Uint16 GPIO45:1;                    // 13 GPIO45 Enable for LPM Wakeup
    Uint16 GPIO46:1;                    // 14 GPIO46 Enable for LPM Wakeup
    Uint16 GPIO47:1;                    // 15 GPIO47 Enable for LPM Wakeup
    Uint16 GPIO48:1;                    // 16 GPIO48 Enable for LPM Wakeup
    Uint16 GPIO49:1;                    // 17 GPIO49 Enable for LPM Wakeup
    Uint16 GPIO50:1;                    // 18 GPIO50 Enable for LPM Wakeup
    Uint16 GPIO51:1;                    // 19 GPIO51 Enable for LPM Wakeup
    Uint16 GPIO52:1;                    // 20 GPIO52 Enable for LPM Wakeup
    Uint16 GPIO53:1;                    // 21 GPIO53 Enable for LPM Wakeup
    Uint16 GPIO54:1;                    // 22 GPIO54 Enable for LPM Wakeup
    Uint16 GPIO55:1;                    // 23 GPIO55 Enable for LPM Wakeup
    Uint16 GPIO56:1;                    // 24 GPIO56 Enable for LPM Wakeup
    Uint16 GPIO57:1;                    // 25 GPIO57 Enable for LPM Wakeup
    Uint16 GPIO58:1;                    // 26 GPIO58 Enable for LPM Wakeup
    Uint16 GPIO59:1;                    // 27 GPIO59 Enable for LPM Wakeup
    Uint16 GPIO60:1;                    // 28 GPIO60 Enable for LPM Wakeup
    Uint16 GPIO61:1;                    // 29 GPIO61 Enable for LPM Wakeup
    Uint16 GPIO62:1;                    // 30 GPIO62 Enable for LPM Wakeup
    Uint16 GPIO63:1;                    // 31 GPIO63 Enable for LPM Wakeup
};

union GPIOLPMSEL1_REG {
    Uint32  all;
    struct  GPIOLPMSEL1_BITS  bit;
};

struct TMR2CLKCTL_BITS {                // bits description
    Uint16 TMR2CLKSRCSEL:3;             // 2:0 CPU Timer 2 Clock Source Select Bit
    Uint16 TMR2CLKPRESCALE:3;           // 5:3 CPU Timer 2 Clock Pre-Scale Value
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union TMR2CLKCTL_REG {
    Uint32  all;
    struct  TMR2CLKCTL_BITS  bit;
};

struct RESC_BITS {                      // bits description
    Uint16 POR:1;                       // 0 POR Reset Cause Indication Bit
    Uint16 XRSn:1;                      // 1 XRSn Reset Cause Indication Bit
    Uint16 WDRSn:1;                     // 2 WDRSn Reset Cause Indication Bit
    Uint16 NMIWDRSn:1;                  // 3 NMIWDRSn Reset Cause Indication Bit
    Uint16 rsvd1:1;                     // 4 Reserved
    Uint16 HWBISTn:1;                   // 5 HWBISTn Reset Cause Indication Bit
    Uint16 HIBRESETn:1;                 // 6 HIBRESETn Reset Cause Indication Bit
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 SCCRESETn:1;                 // 8 SCCRESETn Reset Cause Indication Bit
    Uint16 rsvd3:7;                     // 15:9 Reserved
    Uint16 rsvd4:14;                    // 29:16 Reserved
    Uint16 XRSn_pin_status:1;           // 30 XRSN Pin Status
    Uint16 TRSTn_pin_status:1;          // 31 TRSTn Status
};

union RESC_REG {
    Uint32  all;
    struct  RESC_BITS  bit;
};

struct CPU_SYS_REGS {
    union   CPUSYSLOCK1_REG                  CPUSYSLOCK1;                  // Lock bit for CPUSYS registers
    Uint16                                   rsvd1[4];                     // Reserved
    Uint32                                   HIBBOOTMODE;                  // HIB Boot Mode Register
    union   IORESTOREADDR_REG                IORESTOREADDR;                // IORestore() routine Address Register
    union   PIEVERRADDR_REG                  PIEVERRADDR;                  // PIE Vector Fetch Error Address register
    Uint16                                   rsvd2[22];                    // Reserved
    union   PCLKCR0_REG                      PCLKCR0;                      // Peripheral Clock Gating Registers
    union   PCLKCR1_REG                      PCLKCR1;                      // Peripheral Clock Gating Registers
    union   PCLKCR2_REG                      PCLKCR2;                      // Peripheral Clock Gating Registers
    union   PCLKCR3_REG                      PCLKCR3;                      // Peripheral Clock Gating Registers
    union   PCLKCR4_REG                      PCLKCR4;                      // Peripheral Clock Gating Registers
    Uint16                                   rsvd3[2];                     // Reserved
    union   PCLKCR6_REG                      PCLKCR6;                      // Peripheral Clock Gating Registers
    union   PCLKCR7_REG                      PCLKCR7;                      // Peripheral Clock Gating Registers
    union   PCLKCR8_REG                      PCLKCR8;                      // Peripheral Clock Gating Registers
    union   PCLKCR9_REG                      PCLKCR9;                      // Peripheral Clock Gating Registers
    union   PCLKCR10_REG                     PCLKCR10;                     // Peripheral Clock Gating Registers
    union   PCLKCR11_REG                     PCLKCR11;                     // Peripheral Clock Gating Registers
    union   PCLKCR12_REG                     PCLKCR12;                     // Peripheral Clock Gating Registers
    union   PCLKCR13_REG                     PCLKCR13;                     // Peripheral Clock Gating Registers
    union   PCLKCR14_REG                     PCLKCR14;                     // Peripheral Clock Gating Registers
    Uint16                                   rsvd4[2];                     // Reserved
    union   PCLKCR16_REG                     PCLKCR16;                     // Peripheral Clock Gating Registers
    Uint16                                   rsvd5[48];                    // Reserved
    union   SECMSEL_REG                      SECMSEL;                      // Secondary Master Select register for common peripherals: Selects between CLA & DMA
    union   LPMCR_REG                        LPMCR;                        // LPM Control Register
    union   GPIOLPMSEL0_REG                  GPIOLPMSEL0;                  // GPIO LPM Wakeup select registers
    union   GPIOLPMSEL1_REG                  GPIOLPMSEL1;                  // GPIO LPM Wakeup select registers
    union   TMR2CLKCTL_REG                   TMR2CLKCTL;                   // Timer2 Clock Measurement functionality control register
    Uint16                                   rsvd6[2];                     // Reserved
    union   RESC_REG                         RESC;                         // Reset Cause register
};

struct SCSR_BITS {                      // bits description
    Uint16 WDOVERRIDE:1;                // 0 WD Override for WDDIS bit
    Uint16 WDENINT:1;                   // 1 WD Interrupt Enable
    Uint16 WDINTS:1;                    // 2 WD Interrupt Status
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union SCSR_REG {
    Uint16  all;
    struct  SCSR_BITS  bit;
};

// SCSR Register
//// SCSR Register : Byte Value
#define SCSR_WDENINT_WDResetMode						0x0000						// WatchDog Reset(/WDRST) Output Signal is Enabled and WatchDog Interrupt(/WDINT) Output Signal is Disabled.
#define SCSR_WDENINT_WDInterruptMode					0x0002						// WatchDog Reset(/WDRST) Output Signal is Disabled and WatchDog Interrupt(/WDINT) Output Signal is Enabled.

#define SCSR_WDOVERRIDE_WDDISEDIS						0x0001						// WDDIS bit in WDCR Register cannot be Modified by User.

struct WDCNTR_BITS {                    // bits description
    Uint16 WDCNTR:8;                    // 7:0 WD Counter
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union WDCNTR_REG {
    Uint16  all;
    struct  WDCNTR_BITS  bit;
};

struct WDKEY_BITS {                     // bits description
    Uint16 WDKEY:8;                     // 7:0 WD KEY
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union WDKEY_REG {
    Uint16  all;
    struct  WDKEY_BITS  bit;
};

struct WDCR_BITS {                      // bits description
    Uint16 WDPS:3;                      // 2:0 WD Clock Prescalar
    Uint16 WDCHK:3;                     // 5:3 WD Check Bits
    Uint16 WDDIS:1;                     // 6 WD Disable
    Uint16 rsvd1:1;                     // 7 Reserved
    Uint16 rsvd2:8;                     // 15:8 Reserved
};

union WDCR_REG {
    Uint16  all;
    struct  WDCR_BITS  bit;
};

// WDCR Register
//// WDCR Register : Byte Value
#define WDCR_WDDIS_WDEn									0x0000						// WatchDog Enable.
#define WDCR_WDDIS_WDDis								0x0040						// WatchDog Disable.

#define WDCR_WDCHK_WDCheckSum							0x0028						// Must ALWAYS Write 1, 0, 1 to These bits.

#define WDCR_WDPS_DIV512								0x0001						// WDCLK = INTSOC1 / 512 / 1.
#define WDCR_WDPS_DIV1024								0x0002						// WDCLK = INTSOC1 / 512 / 2.
#define WDCR_WDPS_DIV2048								0x0003						// WDCLK = INTSOC1 / 512 / 4.
#define WDCR_WDPS_DIV4096								0x0004						// WDCLK = INTSOC1 / 512 / 8.
#define WDCR_WDPS_DIV8192								0x0005						// WDCLK = INTSOC1 / 512 / 16.
#define WDCR_WDPS_DIV16384								0x0006						// WDCLK = INTSOC1 / 512 / 32.
#define WDCR_WDPS_DIV32768								0x0007						// WDCLK = INTSOC1 / 512 / 64.

struct WDWCR_BITS {                     // bits description
    Uint16 MIN:8;                       // 7:0 WD Min Threshold setting for Windowed Watchdog functionality
    Uint16 FIRSTKEY:1;                  // 8 First Key Detect Flag
    Uint16 rsvd1:7;                     // 15:9 Reserved
};

union WDWCR_REG {
    Uint16  all;
    struct  WDWCR_BITS  bit;
};

struct WD_REGS {
    Uint16                                   rsvd1[34];                    // Reserved
    union   SCSR_REG                         SCSR;                         // System Control & Status Register
    union   WDCNTR_REG                       WDCNTR;                       // Watchdog Counter Register
    Uint16                                   rsvd2;                        // Reserved
    union   WDKEY_REG                        WDKEY;                        // Watchdog Reset Key Register
    Uint16                                   rsvd3[3];                     // Reserved
    union   WDCR_REG                         WDCR;                         // Watchdog Control Register
    union   WDWCR_REG                        WDWCR;                        // Watchdog Windowed Control Register
};

struct CLA1TASKSRCSELLOCK_BITS {        // bits description
    Uint16 CLA1TASKSRCSEL1:1;           // 0 CLA1TASKSRCSEL1 Register Lock bit
    Uint16 CLA1TASKSRCSEL2:1;           // 1 CLA1TASKSRCSEL2 Register Lock bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CLA1TASKSRCSELLOCK_REG {
    Uint32  all;
    struct  CLA1TASKSRCSELLOCK_BITS  bit;
};

struct DMACHSRCSELLOCK_BITS {           // bits description
    Uint16 DMACHSRCSEL1:1;              // 0 DMACHSRCSEL1 Register Lock bit
    Uint16 DMACHSRCSEL2:1;              // 1 DMACHSRCSEL2 Register Lock bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union DMACHSRCSELLOCK_REG {
    Uint32  all;
    struct  DMACHSRCSELLOCK_BITS  bit;
};

struct CLA1TASKSRCSEL1_BITS {           // bits description
    Uint16 TASK1:8;                     // 7:0 Selects the Trigger Source for TASK1 of CLA1
    Uint16 TASK2:8;                     // 15:8 Selects the Trigger Source for TASK2 of CLA1
    Uint16 TASK3:8;                     // 23:16 Selects the Trigger Source for TASK3 of CLA1
    Uint16 TASK4:8;                     // 31:24 Selects the Trigger Source for TASK4 of CLA1
};

union CLA1TASKSRCSEL1_REG {
    Uint32  all;
    struct  CLA1TASKSRCSEL1_BITS  bit;
};

struct CLA1TASKSRCSEL2_BITS {           // bits description
    Uint16 TASK5:8;                     // 7:0 Selects the Trigger Source for TASK5 of CLA1
    Uint16 TASK6:8;                     // 15:8 Selects the Trigger Source for TASK6 of CLA1
    Uint16 TASK7:8;                     // 23:16 Selects the Trigger Source for TASK7 of CLA1
    Uint16 TASK8:8;                     // 31:24 Selects the Trigger Source for TASK8 of CLA1
};

union CLA1TASKSRCSEL2_REG {
    Uint32  all;
    struct  CLA1TASKSRCSEL2_BITS  bit;
};

struct DMACHSRCSEL1_BITS {              // bits description
    Uint16 CH1:8;                       // 7:0 Selects the Trigger and Sync Source CH1 of DMA
    Uint16 CH2:8;                       // 15:8 Selects the Trigger and Sync Source CH2 of DMA
    Uint16 CH3:8;                       // 23:16 Selects the Trigger and Sync Source CH3 of DMA
    Uint16 CH4:8;                       // 31:24 Selects the Trigger and Sync Source CH4 of DMA
};

union DMACHSRCSEL1_REG {
    Uint32  all;
    struct  DMACHSRCSEL1_BITS  bit;
};

struct DMACHSRCSEL2_BITS {              // bits description
    Uint16 CH5:8;                       // 7:0 Selects the Trigger and Sync Source CH5 of DMA
    Uint16 CH6:8;                       // 15:8 Selects the Trigger and Sync Source CH6 of DMA
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union DMACHSRCSEL2_REG {
    Uint32  all;
    struct  DMACHSRCSEL2_BITS  bit;
};

struct DMA_CLA_SRC_SEL_REGS {
    union   CLA1TASKSRCSELLOCK_REG           CLA1TASKSRCSELLOCK;           // CLA1 Task Trigger Source Select Lock Register
    Uint16                                   rsvd1[2];                     // Reserved
    union   DMACHSRCSELLOCK_REG              DMACHSRCSELLOCK;              // DMA Channel Triger Source Select Lock Register
    union   CLA1TASKSRCSEL1_REG              CLA1TASKSRCSEL1;              // CLA1 Task Trigger Source Select Register-1
    union   CLA1TASKSRCSEL2_REG              CLA1TASKSRCSEL2;              // CLA1 Task Trigger Source Select Register-2
    Uint16                                   rsvd2[12];                    // Reserved
    union   DMACHSRCSEL1_REG                 DMACHSRCSEL1;                 // DMA Channel Trigger Source Select Register-1
    union   DMACHSRCSEL2_REG                 DMACHSRCSEL2;                 // DMA Channel Trigger Source Select Register-2
};

struct SYNCSELECT_BITS {                // bits description
    Uint16 EPWM4SYNCIN:3;               // 2:0 Selects Sync Input Source for EPWM4
    Uint16 EPWM7SYNCIN:3;               // 5:3 Selects Sync Input Source for EPWM7
    Uint16 EPWM10SYNCIN:3;              // 8:6 Selects Sync Input Source for EPWM10
    Uint16 ECAP1SYNCIN:3;               // 11:9 Selects Sync Input Source for ECAP1
    Uint16 ECAP4SYNCIN:3;               // 14:12 Selects Sync Input Source for ECAP4
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 rsvd2:11;                    // 26:16 Reserved
    Uint16 SYNCOUT:2;                   // 28:27 Select Syncout Source
    Uint16 rsvd3:3;                     // 31:29 Reserved
};

union SYNCSELECT_REG {
    Uint32  all;
    struct  SYNCSELECT_BITS  bit;
};

struct ADCSOCOUTSELECT_BITS {           // bits description
    Uint16 PWM1SOCAEN:1;                // 0 PWM1SOCAEN Enable for ADCSOCAO 
    Uint16 PWM2SOCAEN:1;                // 1 PWM2SOCAEN Enable for ADCSOCAO 
    Uint16 PWM3SOCAEN:1;                // 2 PWM3SOCAEN Enable for ADCSOCAO 
    Uint16 PWM4SOCAEN:1;                // 3 PWM4SOCAEN Enable for ADCSOCAO 
    Uint16 PWM5SOCAEN:1;                // 4 PWM5SOCAEN Enable for ADCSOCAO 
    Uint16 PWM6SOCAEN:1;                // 5 PWM6SOCAEN Enable for ADCSOCAO 
    Uint16 PWM7SOCAEN:1;                // 6 PWM7SOCAEN Enable for ADCSOCAO 
    Uint16 PWM8SOCAEN:1;                // 7 PWM8SOCAEN Enable for ADCSOCAO 
    Uint16 PWM9SOCAEN:1;                // 8 PWM9SOCAEN Enable for ADCSOCAO 
    Uint16 PWM10SOCAEN:1;               // 9 PWM10SOCAEN Enable for ADCSOCAO 
    Uint16 PWM11SOCAEN:1;               // 10 PWM11SOCAEN Enable for ADCSOCAO 
    Uint16 PWM12SOCAEN:1;               // 11 PWM12SOCAEN Enable for ADCSOCAO 
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 PWM1SOCBEN:1;                // 16 PWM1SOCBEN Enable for ADCSOCBO 
    Uint16 PWM2SOCBEN:1;                // 17 PWM2SOCBEN Enable for ADCSOCBO 
    Uint16 PWM3SOCBEN:1;                // 18 PWM3SOCBEN Enable for ADCSOCBO 
    Uint16 PWM4SOCBEN:1;                // 19 PWM4SOCBEN Enable for ADCSOCBO 
    Uint16 PWM5SOCBEN:1;                // 20 PWM5SOCBEN Enable for ADCSOCBO 
    Uint16 PWM6SOCBEN:1;                // 21 PWM6SOCBEN Enable for ADCSOCBO 
    Uint16 PWM7SOCBEN:1;                // 22 PWM7SOCBEN Enable for ADCSOCBO 
    Uint16 PWM8SOCBEN:1;                // 23 PWM8SOCBEN Enable for ADCSOCBO 
    Uint16 PWM9SOCBEN:1;                // 24 PWM9SOCBEN Enable for ADCSOCBO 
    Uint16 PWM10SOCBEN:1;               // 25 PWM10SOCBEN Enable for ADCSOCBO 
    Uint16 PWM11SOCBEN:1;               // 26 PWM11SOCBEN Enable for ADCSOCBO 
    Uint16 PWM12SOCBEN:1;               // 27 PWM12SOCBEN Enable for ADCSOCBO 
    Uint16 rsvd2:4;                     // 31:28 Reserved
};

union ADCSOCOUTSELECT_REG {
    Uint32  all;
    struct  ADCSOCOUTSELECT_BITS  bit;
};

struct SYNCSOCLOCK_BITS {               // bits description
    Uint16 SYNCSELECT:1;                // 0 SYNCSEL Register Lock bit
    Uint16 ADCSOCOUTSELECT:1;           // 1 ADCSOCOUTSELECT Register Lock bit
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SYNCSOCLOCK_REG {
    Uint32  all;
    struct  SYNCSOCLOCK_BITS  bit;
};

struct SYNC_SOC_REGS {
    union   SYNCSELECT_REG                   SYNCSELECT;                   // Sync Input and Output Select Register
    union   ADCSOCOUTSELECT_REG              ADCSOCOUTSELECT;              // External ADC (Off Chip) SOC Select Register
    union   SYNCSOCLOCK_REG                  SYNCSOCLOCK;                  // SYNCSEL and EXTADCSOC Select Lock register
};

//---------------------------------------------------------------------------
// SYSCTRL External References & Function Declarations:
//
#ifdef CPU1
extern volatile struct WD_REGS WdRegs;
extern volatile struct SYNC_SOC_REGS SyncSocRegs;
extern volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;
extern volatile struct DEV_CFG_REGS DevCfgRegs;
extern volatile struct CLK_CFG_REGS ClkCfgRegs;
extern volatile struct CPU_SYS_REGS CpuSysRegs;
#endif
#ifdef CPU2
extern volatile struct WD_REGS WdRegs;
extern volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;
extern volatile struct CLK_CFG_REGS ClkCfgRegs;
extern volatile struct CPU_SYS_REGS CpuSysRegs;
#endif
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
