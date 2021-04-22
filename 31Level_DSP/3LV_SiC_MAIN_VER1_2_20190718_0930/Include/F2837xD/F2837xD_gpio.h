//###########################################################################
//
// FILE:    F2837xD_gpio.h
//
// TITLE:   F2837xD Device GPIO Register Definitions.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 $
// $Release Date: Tue Nov  1 14:46:15 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xD_GPIO_H__
#define __F2837xD_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// GPIO Individual Register Bit Definitions:

struct GPACTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO0 to GPIO7
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO8 to GPIO15
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO16 to GPIO23
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO24 to GPIO31
};

union GPACTRL_REG {
    Uint32  all;
    struct  GPACTRL_BITS  bit;
};

#ifdef CPU1
// GPACTRL Register
//// GPACTRL Register : Byte Value
#define GPACTRL_QUALPRD3_GPIO031to024_Value(val)		(((Uint32)val & 0x000000FFUL) << 24)
#define GPACTRL_QUALPRD2_GPIO023to016_Value(val)		(((Uint32)val & 0x000000FFUL) << 16)
#define GPACTRL_QUALPRD1_GPIO015to008_Value(val)		(((Uint32)val & 0x000000FFUL) << 8)
#define GPACTRL_QUALPRD0_GPIO007to000_Value(val)		((Uint32)val & 0x000000FFUL)
#endif

struct GPAQSEL1_BITS {                  // bits description
    Uint16 GPIO0:2;                     // 1:0 Select input qualification type for GPIO0
    Uint16 GPIO1:2;                     // 3:2 Select input qualification type for GPIO1
    Uint16 GPIO2:2;                     // 5:4 Select input qualification type for GPIO2
    Uint16 GPIO3:2;                     // 7:6 Select input qualification type for GPIO3
    Uint16 GPIO4:2;                     // 9:8 Select input qualification type for GPIO4
    Uint16 GPIO5:2;                     // 11:10 Select input qualification type for GPIO5
    Uint16 GPIO6:2;                     // 13:12 Select input qualification type for GPIO6
    Uint16 GPIO7:2;                     // 15:14 Select input qualification type for GPIO7
    Uint16 GPIO8:2;                     // 17:16 Select input qualification type for GPIO8
    Uint16 GPIO9:2;                     // 19:18 Select input qualification type for GPIO9
    Uint16 GPIO10:2;                    // 21:20 Select input qualification type for GPIO10
    Uint16 GPIO11:2;                    // 23:22 Select input qualification type for GPIO11
    Uint16 GPIO12:2;                    // 25:24 Select input qualification type for GPIO12
    Uint16 GPIO13:2;                    // 27:26 Select input qualification type for GPIO13
    Uint16 GPIO14:2;                    // 29:28 Select input qualification type for GPIO14
    Uint16 GPIO15:2;                    // 31:30 Select input qualification type for GPIO15
};

union GPAQSEL1_REG {
    Uint32  all;
    struct  GPAQSEL1_BITS  bit;
};

#ifdef CPU1
// GPAQSEL1 Register
//// GPAQSEL1 Register : Byte Value
#define GPAQSEL1_GPIO015_Synch							0x00000000UL
#define GPAQSEL1_GPIO015_3SampSynch						0x40000000UL
#define GPAQSEL1_GPIO015_6SampSynch						0x80000000UL
#define GPAQSEL1_GPIO015_Asynch							0xC0000000UL

#define GPAQSEL1_GPIO014_Synch							0x00000000UL
#define GPAQSEL1_GPIO014_3SampSynch						0x10000000UL
#define GPAQSEL1_GPIO014_6SampSynch						0x20000000UL
#define GPAQSEL1_GPIO014_Asynch							0x30000000UL

#define GPAQSEL1_GPIO013_Synch							0x00000000UL
#define GPAQSEL1_GPIO013_3SampSynch						0x04000000UL
#define GPAQSEL1_GPIO013_6SampSynch						0x08000000UL
#define GPAQSEL1_GPIO013_Asynch							0x0C000000UL

#define GPAQSEL1_GPIO012_Synch							0x00000000UL
#define GPAQSEL1_GPIO012_3SampSynch						0x01000000UL
#define GPAQSEL1_GPIO012_6SampSynch						0x02000000UL
#define GPAQSEL1_GPIO012_Asynch							0x03000000UL

#define GPAQSEL1_GPIO011_Synch							0x00000000UL
#define GPAQSEL1_GPIO011_3SampSynch						0x00400000UL
#define GPAQSEL1_GPIO011_6SampSynch						0x00800000UL
#define GPAQSEL1_GPIO011_Asynch							0x00C00000UL

#define GPAQSEL1_GPIO010_Synch							0x00000000UL
#define GPAQSEL1_GPIO010_3SampSynch						0x00100000UL
#define GPAQSEL1_GPIO010_6SampSynch						0x00200000UL
#define GPAQSEL1_GPIO010_Asynch							0x00300000UL

#define GPAQSEL1_GPIO009_Synch							0x00000000UL
#define GPAQSEL1_GPIO009_3SampSynch						0x00040000UL
#define GPAQSEL1_GPIO009_6SampSynch						0x00080000UL
#define GPAQSEL1_GPIO009_Asynch							0x000C0000UL

#define GPAQSEL1_GPIO008_Synch							0x00000000UL
#define GPAQSEL1_GPIO008_3SampSynch						0x00010000UL
#define GPAQSEL1_GPIO008_6SampSynch						0x00020000UL
#define GPAQSEL1_GPIO008_Asynch							0x00030000UL

#define GPAQSEL1_GPIO007_Synch							0x00000000UL
#define GPAQSEL1_GPIO007_3SampSynch						0x00004000UL
#define GPAQSEL1_GPIO007_6SampSynch						0x00008000UL
#define GPAQSEL1_GPIO007_Asynch							0x0000C000UL

#define GPAQSEL1_GPIO006_Synch							0x00000000UL
#define GPAQSEL1_GPIO006_3SampSynch						0x00001000UL
#define GPAQSEL1_GPIO006_6SampSynch						0x00002000UL
#define GPAQSEL1_GPIO006_Asynch							0x00003000UL

#define GPAQSEL1_GPIO005_Synch							0x00000000UL
#define GPAQSEL1_GPIO005_3SampSynch						0x00000400UL
#define GPAQSEL1_GPIO005_6SampSynch						0x00000800UL
#define GPAQSEL1_GPIO005_Asynch							0x00000C00UL

#define GPAQSEL1_GPIO004_Synch							0x00000000UL
#define GPAQSEL1_GPIO004_3SampSynch						0x00000100UL
#define GPAQSEL1_GPIO004_6SampSynch						0x00000200UL
#define GPAQSEL1_GPIO004_Asynch							0x00000300UL

#define GPAQSEL1_GPIO003_Synch							0x00000000UL
#define GPAQSEL1_GPIO003_3SampSynch						0x00000040UL
#define GPAQSEL1_GPIO003_6SampSynch						0x00000080UL
#define GPAQSEL1_GPIO003_Asynch							0x000000C0UL

#define GPAQSEL1_GPIO002_Synch							0x00000000UL
#define GPAQSEL1_GPIO002_3SampSynch						0x00000010UL
#define GPAQSEL1_GPIO002_6SampSynch						0x00000020UL
#define GPAQSEL1_GPIO002_Asynch							0x00000030UL

#define GPAQSEL1_GPIO001_Synch							0x00000000UL
#define GPAQSEL1_GPIO001_3SampSynch						0x00000004UL
#define GPAQSEL1_GPIO001_6SampSynch						0x00000008UL
#define GPAQSEL1_GPIO001_Asynch							0x0000000CUL

#define GPAQSEL1_GPIO000_Synch							0x00000000UL
#define GPAQSEL1_GPIO000_3SampSynch						0x00000001UL
#define GPAQSEL1_GPIO000_6SampSynch						0x00000002UL
#define GPAQSEL1_GPIO000_Asynch							0x00000003UL
#endif

struct GPAQSEL2_BITS {                  // bits description
    Uint16 GPIO16:2;                    // 1:0 Select input qualification type for GPIO16
    Uint16 GPIO17:2;                    // 3:2 Select input qualification type for GPIO17
    Uint16 GPIO18:2;                    // 5:4 Select input qualification type for GPIO18
    Uint16 GPIO19:2;                    // 7:6 Select input qualification type for GPIO19
    Uint16 GPIO20:2;                    // 9:8 Select input qualification type for GPIO20
    Uint16 GPIO21:2;                    // 11:10 Select input qualification type for GPIO21
    Uint16 GPIO22:2;                    // 13:12 Select input qualification type for GPIO22
    Uint16 GPIO23:2;                    // 15:14 Select input qualification type for GPIO23
    Uint16 GPIO24:2;                    // 17:16 Select input qualification type for GPIO24
    Uint16 GPIO25:2;                    // 19:18 Select input qualification type for GPIO25
    Uint16 GPIO26:2;                    // 21:20 Select input qualification type for GPIO26
    Uint16 GPIO27:2;                    // 23:22 Select input qualification type for GPIO27
    Uint16 GPIO28:2;                    // 25:24 Select input qualification type for GPIO28
    Uint16 GPIO29:2;                    // 27:26 Select input qualification type for GPIO29
    Uint16 GPIO30:2;                    // 29:28 Select input qualification type for GPIO30
    Uint16 GPIO31:2;                    // 31:30 Select input qualification type for GPIO31
};

union GPAQSEL2_REG {
    Uint32  all;
    struct  GPAQSEL2_BITS  bit;
};

#ifdef CPU1
// GPAQSEL2 Register
//// GPAQSEL2 Register : Byte Value
#define GPAQSEL2_GPIO031_Synch							0x00000000UL
#define GPAQSEL2_GPIO031_3SampSynch						0x40000000UL
#define GPAQSEL2_GPIO031_6SampSynch						0x80000000UL
#define GPAQSEL2_GPIO031_Asynch							0xC0000000UL

#define GPAQSEL2_GPIO030_Synch							0x00000000UL
#define GPAQSEL2_GPIO030_3SampSynch						0x10000000UL
#define GPAQSEL2_GPIO030_6SampSynch						0x20000000UL
#define GPAQSEL2_GPIO030_Asynch							0x30000000UL

#define GPAQSEL2_GPIO029_Synch							0x00000000UL
#define GPAQSEL2_GPIO029_3SampSynch						0x04000000UL
#define GPAQSEL2_GPIO029_6SampSynch						0x08000000UL
#define GPAQSEL2_GPIO029_Asynch							0x0C000000UL

#define GPAQSEL2_GPIO028_Synch							0x00000000UL
#define GPAQSEL2_GPIO028_3SampSynch						0x01000000UL
#define GPAQSEL2_GPIO028_6SampSynch						0x02000000UL
#define GPAQSEL2_GPIO028_Asynch							0x03000000UL

#define GPAQSEL2_GPIO027_Synch							0x00000000UL
#define GPAQSEL2_GPIO027_3SampSynch						0x00400000UL
#define GPAQSEL2_GPIO027_6SampSynch						0x00800000UL
#define GPAQSEL2_GPIO027_Asynch							0x00C00000UL

#define GPAQSEL2_GPIO026_Synch							0x00000000UL
#define GPAQSEL2_GPIO026_3SampSynch						0x00100000UL
#define GPAQSEL2_GPIO026_6SampSynch						0x00200000UL
#define GPAQSEL2_GPIO026_Asynch							0x00300000UL

#define GPAQSEL2_GPIO025_Synch							0x00000000UL
#define GPAQSEL2_GPIO025_3SampSynch						0x00040000UL
#define GPAQSEL2_GPIO025_6SampSynch						0x00080000UL
#define GPAQSEL2_GPIO025_Asynch							0x000C0000UL

#define GPAQSEL2_GPIO024_Synch							0x00000000UL
#define GPAQSEL2_GPIO024_3SampSynch						0x00010000UL
#define GPAQSEL2_GPIO024_6SampSynch						0x00020000UL
#define GPAQSEL2_GPIO024_Asynch							0x00030000UL

#define GPAQSEL2_GPIO023_Synch							0x00000000UL
#define GPAQSEL2_GPIO023_3SampSynch						0x00004000UL
#define GPAQSEL2_GPIO023_6SampSynch						0x00008000UL
#define GPAQSEL2_GPIO023_Asynch							0x0000C000UL

#define GPAQSEL2_GPIO022_Synch							0x00000000UL
#define GPAQSEL2_GPIO022_3SampSynch						0x00001000UL
#define GPAQSEL2_GPIO022_6SampSynch						0x00002000UL
#define GPAQSEL2_GPIO022_Asynch							0x00003000UL

#define GPAQSEL2_GPIO021_Synch							0x00000000UL
#define GPAQSEL2_GPIO021_3SampSynch						0x00000400UL
#define GPAQSEL2_GPIO021_6SampSynch						0x00000800UL
#define GPAQSEL2_GPIO021_Asynch							0x00000C00UL

#define GPAQSEL2_GPIO020_Synch							0x00000000UL
#define GPAQSEL2_GPIO020_3SampSynch						0x00000100UL
#define GPAQSEL2_GPIO020_6SampSynch						0x00000200UL
#define GPAQSEL2_GPIO020_Asynch							0x00000300UL

#define GPAQSEL2_GPIO019_Synch							0x00000000UL
#define GPAQSEL2_GPIO019_3SampSynch						0x00000040UL
#define GPAQSEL2_GPIO019_6SampSynch						0x00000080UL
#define GPAQSEL2_GPIO019_Asynch							0x000000C0UL

#define GPAQSEL2_GPIO018_Synch							0x00000000UL
#define GPAQSEL2_GPIO018_3SampSynch						0x00000010UL
#define GPAQSEL2_GPIO018_6SampSynch						0x00000020UL
#define GPAQSEL2_GPIO018_Asynch							0x00000030UL

#define GPAQSEL2_GPIO017_Synch							0x00000000UL
#define GPAQSEL2_GPIO017_3SampSynch						0x00000004UL
#define GPAQSEL2_GPIO017_6SampSynch						0x00000008UL
#define GPAQSEL2_GPIO017_Asynch							0x0000000CUL

#define GPAQSEL2_GPIO016_Synch							0x00000000UL
#define GPAQSEL2_GPIO016_3SampSynch						0x00000001UL
#define GPAQSEL2_GPIO016_6SampSynch						0x00000002UL
#define GPAQSEL2_GPIO016_Asynch							0x00000003UL

//// GPAQSEL2 Register : Bit Value
#define GPIOxxx_Synch									0U
#define GPIOxxx_3SampSynch								1U
#define GPIOxxx_6SampSynch								2U
#define GPIOxxx_Asynch									3U
#endif

struct GPAMUX1_BITS {                   // bits description
    Uint16 GPIO0:2;                     // 1:0 Defines pin-muxing selection for GPIO0
    Uint16 GPIO1:2;                     // 3:2 Defines pin-muxing selection for GPIO1
    Uint16 GPIO2:2;                     // 5:4 Defines pin-muxing selection for GPIO2
    Uint16 GPIO3:2;                     // 7:6 Defines pin-muxing selection for GPIO3
    Uint16 GPIO4:2;                     // 9:8 Defines pin-muxing selection for GPIO4
    Uint16 GPIO5:2;                     // 11:10 Defines pin-muxing selection for GPIO5
    Uint16 GPIO6:2;                     // 13:12 Defines pin-muxing selection for GPIO6
    Uint16 GPIO7:2;                     // 15:14 Defines pin-muxing selection for GPIO7
    Uint16 GPIO8:2;                     // 17:16 Defines pin-muxing selection for GPIO8
    Uint16 GPIO9:2;                     // 19:18 Defines pin-muxing selection for GPIO9
    Uint16 GPIO10:2;                    // 21:20 Defines pin-muxing selection for GPIO10
    Uint16 GPIO11:2;                    // 23:22 Defines pin-muxing selection for GPIO11
    Uint16 GPIO12:2;                    // 25:24 Defines pin-muxing selection for GPIO12
    Uint16 GPIO13:2;                    // 27:26 Defines pin-muxing selection for GPIO13
    Uint16 GPIO14:2;                    // 29:28 Defines pin-muxing selection for GPIO14
    Uint16 GPIO15:2;                    // 31:30 Defines pin-muxing selection for GPIO15
};

union GPAMUX1_REG {
    Uint32  all;
    struct  GPAMUX1_BITS  bit;
};

#ifdef CPU1
// GPAMUX1 Register
//// GPAMUX1 Register : Byte Value													// GMUX		MUX
#define GPAMUX1_GPIO015_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO015_OutEPWM8B						0x40000000UL				// 0b00		0b01
#define GPAMUX1_GPIO015_InSCITXDB						0x80000000UL				// 0b00		0b10
#define GPAMUX1_GPIO015_InOutMFSXB						0xC0000000UL				// 0b00		0b11
#define GPAMUX1_GPIO015_OutOUTPUTXBAR4					0x80000000UL				// 0b01		0b10
#define GPAMUX1_GPIO015_InOutUPP_D5						0xC0000000UL				// 0b11		0b11

#define GPAMUX1_GPIO014_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO014_OutEPWM8A						0x10000000UL				// 0b00		0b01
#define GPAMUX1_GPIO014_OutSCITXDB						0x20000000UL				// 0b00		0b10
#define GPAMUX1_GPIO014_InOutMCLKXB						0x30000000UL				// 0b00		0b11
#define GPAMUX1_GPIO014_OutOUTPUTXBAR3					0x20000000UL				// 0b01		0b10
#define GPAMUX1_GPIO014_InOutUPP_D6						0x30000000UL				// 0b11		0b11

#define GPAMUX1_GPIO013_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO013_OutEPWM7B						0x04000000UL				// 0b00		0b01
#define GPAMUX1_GPIO013_InCANRXB						0x08000000UL				// 0b00		0b10
#define GPAMUX1_GPIO013_InMDRB							0x0C000000UL				// 0b00		0b11
#define GPAMUX1_GPIO013_InOutEQEP1I						0x04000000UL				// 0b01		0b01
#define GPAMUX1_GPIO013_InSCIRXDC						0x08000000UL				// 0b01		0b10
#define GPAMUX1_GPIO013_InOutUPP_D7						0x0C000000UL				// 0b11		0b11

#define GPAMUX1_GPIO012_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO012_OutEPWM7A						0x01000000UL				// 0b00		0b01
#define GPAMUX1_GPIO012_OutCANTXB						0x02000000UL				// 0b00		0b10
#define GPAMUX1_GPIO012_OutMDXB							0x03000000UL				// 0b00		0b11
#define GPAMUX1_GPIO012_InOutEQEP1S						0x01000000UL				// 0b01		0b01
#define GPAMUX1_GPIO012_OutSCITXDC						0x02000000UL				// 0b01		0b10
#define GPAMUX1_GPIO012_InOutUPP_ENA					0x03000000UL				// 0b11		0b11

#define GPAMUX1_GPIO011_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO011_OutEPWM6B						0x00400000UL				// 0b00		0b01
#define GPAMUX1_GPIO011_InSCIRXDB						0x00800000UL				// 0b00		0b10
#define GPAMUX1_GPIO011_OutOUTPUTXBAR7					0x00C00000UL				// 0b00		0b11
#define GPAMUX1_GPIO011_InEQEP1B						0x00400000UL				// 0b01		0b01
#define GPAMUX1_GPIO011_InOutUPP_START					0x00C00000UL				// 0b11		0b11

#define GPAMUX1_GPIO010_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO010_OutEPWM6A						0x00100000UL				// 0b00		0b01
#define GPAMUX1_GPIO010_InCANRXB						0x00200000UL				// 0b00		0b10
#define GPAMUX1_GPIO010_OutADCSOCBO						0x00300000UL				// 0b00		0b11
#define GPAMUX1_GPIO010_InEQEP1A						0x00100000UL				// 0b01		0b01
#define GPAMUX1_GPIO010_OutSCITXDB						0x00200000UL				// 0b01		0b10
#define GPAMUX1_GPIO010_InOutUPP_WAIT					0x00300000UL				// 0b11		0b11

#define GPAMUX1_GPIO009_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO009_OutEPWM5B						0x00040000UL				// 0b00		0b01
#define GPAMUX1_GPIO009_OutSCITXDB						0x00080000UL				// 0b00		0b10
#define GPAMUX1_GPIO009_OutOUTPUTXBAR6					0x000C0000UL				// 0b00		0b11
#define GPAMUX1_GPIO009_InOutEQEP3I						0x00040000UL				// 0b01		0b01
#define GPAMUX1_GPIO009_InSCIRXDA						0x00080000UL				// 0b01		0b10

#define GPAMUX1_GPIO008_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO008_OutEPWM5A						0x00010000UL				// 0b00		0b01
#define GPAMUX1_GPIO008_OutCANTXB						0x00020000UL				// 0b00		0b10
#define GPAMUX1_GPIO008_OutADCSOCAO						0x00030000UL				// 0b00		0b11
#define GPAMUX1_GPIO008_InOutEQEP3S						0x00010000UL				// 0b01		0b01
#define GPAMUX1_GPIO008_OutSCITXDA						0x00020000UL				// 0b01		0b10

#define GPAMUX1_GPIO007_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO007_OutEPWM4B						0x00004000UL				// 0b00		0b01
#define GPAMUX1_GPIO007_InOutMCLKRA						0x00008000UL				// 0b00		0b10
#define GPAMUX1_GPIO007_OutOUTPUTXBAR5					0x0000C000UL				// 0b00		0b11
#define GPAMUX1_GPIO007_InEQEP3B						0x00004000UL				// 0b01		0b01
#define GPAMUX1_GPIO007_InCANRXB						0x00008000UL				// 0b01		0b10

#define GPAMUX1_GPIO006_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO006_OutEPWM4A						0x00001000UL				// 0b00		0b01
#define GPAMUX1_GPIO006_OutOUTPUTXBAR4					0x00002000UL				// 0b00		0b10
#define GPAMUX1_GPIO006_OutEXTSYNCOUT					0x00003000UL				// 0b00		0b11
#define GPAMUX1_GPIO006_InEQEP3A						0x00001000UL				// 0b01		0b01
#define GPAMUX1_GPIO006_OutCANTXB						0x00002000UL				// 0b01		0b10

#define GPAMUX1_GPIO005_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO005_OutEPWM3B						0x00000400UL				// 0b00		0b01
#define GPAMUX1_GPIO005_InOutMFSRA						0x00000800UL				// 0b00		0b10
#define GPAMUX1_GPIO005_OutOUTPUTXBAR3					0x00000C00UL				// 0b00		0b11
#define GPAMUX1_GPIO005_InCANRXA						0x00000800UL				// 0b01		0b10

#define GPAMUX1_GPIO004_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO004_OutEPWM3A						0x00000100UL				// 0b00		0b01
#define GPAMUX1_GPIO004_OutOUTPUTXBAR3					0x00000100UL				// 0b01		0b01
#define GPAMUX1_GPIO004_OutCANTXA						0x00000200UL				// 0b01		0b10

#define GPAMUX1_GPIO003_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO003_OutEPWM2B						0x00000040UL				// 0b00		0b01
#define GPAMUX1_GPIO003_OutOUTPUTXBAR2					0x00000080UL				// 0b00		0b10
#define GPAMUX1_GPIO003_InOutMCLKRB						0x000000C0UL				// 0b00		0b11
#define GPAMUX1_GPIO003_InODSCLB						0x00000080UL				// 0b01		0b10

#define GPAMUX1_GPIO002_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO002_OutEPWM2A						0x00000010UL				// 0b00		0b01
#define GPAMUX1_GPIO002_OutOUTPUTXBAR1					0x00000010UL				// 0b01		0b01
#define GPAMUX1_GPIO002_InODSDAB						0x00000020UL				// 0b01		0b10

#define GPAMUX1_GPIO001_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO001_OutEPWM1B						0x00000004UL				// 0b00		0b01
#define GPAMUX1_GPIO001_InOutMFSRB						0x0000000CUL				// 0b00		0b11
#define GPAMUX1_GPIO001_InODSCLA						0x00000008UL				// 0b01		0b10

#define GPAMUX1_GPIO000_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX1_GPIO000_OutEPWM1A						0x00000001UL				// 0b00		0b01
#define GPAMUX1_GPIO000_InODSDAA						0x00000002UL				// 0b01		0b10
#endif

struct GPAMUX2_BITS {                   // bits description
    Uint16 GPIO16:2;                    // 1:0 Defines pin-muxing selection for GPIO16
    Uint16 GPIO17:2;                    // 3:2 Defines pin-muxing selection for GPIO17
    Uint16 GPIO18:2;                    // 5:4 Defines pin-muxing selection for GPIO18
    Uint16 GPIO19:2;                    // 7:6 Defines pin-muxing selection for GPIO19
    Uint16 GPIO20:2;                    // 9:8 Defines pin-muxing selection for GPIO20
    Uint16 GPIO21:2;                    // 11:10 Defines pin-muxing selection for GPIO21
    Uint16 GPIO22:2;                    // 13:12 Defines pin-muxing selection for GPIO22
    Uint16 GPIO23:2;                    // 15:14 Defines pin-muxing selection for GPIO23
    Uint16 GPIO24:2;                    // 17:16 Defines pin-muxing selection for GPIO24
    Uint16 GPIO25:2;                    // 19:18 Defines pin-muxing selection for GPIO25
    Uint16 GPIO26:2;                    // 21:20 Defines pin-muxing selection for GPIO26
    Uint16 GPIO27:2;                    // 23:22 Defines pin-muxing selection for GPIO27
    Uint16 GPIO28:2;                    // 25:24 Defines pin-muxing selection for GPIO28
    Uint16 GPIO29:2;                    // 27:26 Defines pin-muxing selection for GPIO29
    Uint16 GPIO30:2;                    // 29:28 Defines pin-muxing selection for GPIO30
    Uint16 GPIO31:2;                    // 31:30 Defines pin-muxing selection for GPIO31
};

union GPAMUX2_REG {
    Uint32  all;
    struct  GPAMUX2_BITS  bit;
};

#ifdef CPU1
// GPAMUX2 Register
//// GPAMUX2 Register : Byte Value													// GMUX		MUX
#define GPAMUX2_GPIO031_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO031_OutCANTXA						0x40000000UL				// 0b00		0b01
#define GPAMUX2_GPIO031_OutnEM1WE						0x80000000UL				// 0b00		0b10
#define GPAMUX2_GPIO031_OutOUTPUTXBAR8					0x40000000UL				// 0b01		0b01
#define GPAMUX2_GPIO031_InOutEQEP3I						0x80000000UL				// 0b01		0b10
#define GPAMUX2_GPIO031_InSD2_D4						0xC0000000UL				// 0b01		0b11

#define GPAMUX2_GPIO030_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO030_InCANRXA						0x10000000UL				// 0b00		0b01
#define GPAMUX2_GPIO030_OutEM1CLK						0x20000000UL				// 0b00		0b10
#define GPAMUX2_GPIO030_OutOUTPUTXBAR7					0x10000000UL				// 0b01		0b01
#define GPAMUX2_GPIO030_InOutEQEP3S						0x20000000UL				// 0b01		0b10
#define GPAMUX2_GPIO030_InSD2_D4						0x30000000UL				// 0b01		0b11

#define GPAMUX2_GPIO029_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO029_OutSCITXDA						0x04000000UL				// 0b00		0b01
#define GPAMUX2_GPIO029_OutEM1SDCKE						0x08000000UL				// 0b00		0b10
#define GPAMUX2_GPIO029_OutOUTPUTXBAR6					0x04000000UL				// 0b01		0b01
#define GPAMUX2_GPIO029_InEQEP3B						0x08000000UL				// 0b01		0b10
#define GPAMUX2_GPIO029_InSD2_C3						0x0C000000UL				// 0b01		0b11

#define GPAMUX2_GPIO028_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO028_InSCIRXDA						0x01000000UL				// 0b00		0b01
#define GPAMUX2_GPIO028_OutnEM1CS4						0x02000000UL				// 0b00		0b10
#define GPAMUX2_GPIO028_OutOUTPUTXBAR5					0x01000000UL				// 0b01		0b01
#define GPAMUX2_GPIO028_InEQEP3A						0x02000000UL				// 0b01		0b10
#define GPAMUX2_GPIO028_InSD2_D3						0x03000000UL				// 0b01		0b11

#define GPAMUX2_GPIO027_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO027_OutOUTPUTXBAR4					0x00400000UL				// 0b00		0b01
#define GPAMUX2_GPIO027_InOutEQEP2S						0x00800000UL				// 0b00		0b10
#define GPAMUX2_GPIO027_InOutMFSXB						0x00C00000UL				// 0b00		0b11
#define GPAMUX2_GPIO027_InOutnSPISTEB					0x00800000UL				// 0b01		0b10
#define GPAMUX2_GPIO027_InSD2_C2						0x00C00000UL				// 0b01		0b11

#define GPAMUX2_GPIO026_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO026_OutOUTPUTXBAR3					0x00100000UL				// 0b00		0b01
#define GPAMUX2_GPIO026_InOutEQEP2I						0x00200000UL				// 0b00		0b10
#define GPAMUX2_GPIO026_InOutMCLKXB						0x00300000UL				// 0b00		0b11
#define GPAMUX2_GPIO026_InOutPICLKB						0x00200000UL				// 0b01		0b10
#define GPAMUX2_GPIO026_InSD2_D2						0x00300000UL				// 0b01		0b11

#define GPAMUX2_GPIO025_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO025_OutOUTPUTXBAR2					0x00040000UL				// 0b00		0b01
#define GPAMUX2_GPIO025_InEQEP2B						0x00080000UL				// 0b00		0b10
#define GPAMUX2_GPIO025_InMDRB							0x000C0000UL				// 0b00		0b11
#define GPAMUX2_GPIO025_InOutSPISOMIB					0x00080000UL				// 0b01		0b10
#define GPAMUX2_GPIO025_InSD2_C1						0x000C0000UL				// 0b01		0b11

#define GPAMUX2_GPIO024_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO024_OutOUTPUTXBAR1					0x00010000UL				// 0b00		0b01
#define GPAMUX2_GPIO024_InEQEP2A						0x00020000UL				// 0b00		0b10
#define GPAMUX2_GPIO024_OutMDXB							0x00030000UL				// 0b00		0b11
#define GPAMUX2_GPIO024_InOutSPISIMOB					0x00020000UL				// 0b01		0b10
#define GPAMUX2_GPIO024_InSD2_D1						0x00030000UL				// 0b01		0b11

#define GPAMUX2_GPIO023_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO023_InOutEQEP1I						0x00004000UL				// 0b00		0b01
#define GPAMUX2_GPIO023_InOutMFSXA						0x00008000UL				// 0b00		0b10
#define GPAMUX2_GPIO023_InSCITXDB						0x0000C000UL				// 0b00		0b11
#define GPAMUX2_GPIO023_OutEPWM12B						0x00004000UL				// 0b01		0b01
#define GPAMUX2_GPIO023_InOutnSPISTEB					0x00008000UL				// 0b01		0b10
#define GPAMUX2_GPIO023_InSD1_C4						0x0000C000UL				// 0b01		0b11

#define GPAMUX2_GPIO022_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO022_InOutEQEP1S						0x00001000UL				// 0b00		0b01
#define GPAMUX2_GPIO022_InOutMCLKXA						0x00002000UL				// 0b00		0b10
#define GPAMUX2_GPIO022_OutSCITXDB						0x00003000UL				// 0b00		0b11
#define GPAMUX2_GPIO022_OutEPWM12A						0x00001000UL				// 0b01		0b01
#define GPAMUX2_GPIO022_InOutSPICLKB					0x00002000UL				// 0b01		0b10
#define GPAMUX2_GPIO022_InSD1_D4						0x00003000UL				// 0b01		0b11

#define GPAMUX2_GPIO021_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO021_InEQEP1B						0x00000400UL				// 0b00		0b01
#define GPAMUX2_GPIO021_InMDRA							0x00000800UL				// 0b00		0b10
#define GPAMUX2_GPIO021_InCANRXB						0x00000C00UL				// 0b00		0b11
#define GPAMUX2_GPIO021_OutEPWM11B						0x00000400UL				// 0b01		0b01
#define GPAMUX2_GPIO021_InSD1_C3						0x00000C00UL				// 0b01		0b11
#define GPAMUX2_GPIO021_InOutUPP_CLK					0x00000C00UL				// 0b11		0b11

#define GPAMUX2_GPIO020_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO020_InEQEP1A						0x00000100UL				// 0b00		0b01
#define GPAMUX2_GPIO020_OutMDXA							0x00000200UL				// 0b00		0b10
#define GPAMUX2_GPIO020_OutCANTXB						0x00000300UL				// 0b00		0b11
#define GPAMUX2_GPIO020_OutEPWM11A						0x00000100UL				// 0b01		0b01
#define GPAMUX2_GPIO020_InSD1_D3						0x00000300UL				// 0b01		0b11
#define GPAMUX2_GPIO020_InOutUPP_D0						0x00000300UL				// 0b11		0b11

#define GPAMUX2_GPIO019_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO019_InOutnSPISTEA					0x00000040UL				// 0b00		0b01
#define GPAMUX2_GPIO019_InSCIRXDB						0x00000080UL				// 0b00		0b10
#define GPAMUX2_GPIO019_OutCANTXA						0x000000C0UL				// 0b00		0b11
#define GPAMUX2_GPIO019_OutEPWM10B						0x00000040UL				// 0b01		0b01
#define GPAMUX2_GPIO019_InSD1_C2						0x000000C0UL				// 0b01		0b11
#define GPAMUX2_GPIO019_InOutUPP_D1						0x000000C0UL				// 0b11		0b11

#define GPAMUX2_GPIO018_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO018_InOutSPICLKA					0x00000010UL				// 0b00		0b01
#define GPAMUX2_GPIO018_OutSCITXDB						0x00000020UL				// 0b00		0b10
#define GPAMUX2_GPIO018_InCANRXA						0x00000030UL				// 0b00		0b11
#define GPAMUX2_GPIO018_OutEPWM10A						0x00000010UL				// 0b01		0b01
#define GPAMUX2_GPIO018_InSD1_D2						0x00000030UL				// 0b01		0b11
#define GPAMUX2_GPIO018_InOutUPP_D2						0x00000030UL				// 0b11		0b11

#define GPAMUX2_GPIO017_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO017_InOutSPISOMIA					0x00000004UL				// 0b00		0b01
#define GPAMUX2_GPIO017_InCANTXB						0x00000008UL				// 0b00		0b10
#define GPAMUX2_GPIO017_OutOUTPUTXBAR8					0x0000000CUL				// 0b00		0b11
#define GPAMUX2_GPIO017_OutEPWM9B						0x00000004UL				// 0b01		0b01
#define GPAMUX2_GPIO017_InSD1_C1						0x0000000CUL				// 0b01		0b11
#define GPAMUX2_GPIO017_InOutUPP_D3						0x0000000CUL				// 0b11		0b11

#define GPAMUX2_GPIO016_InOutGPIO						0x00000000UL				// -		0b00
#define GPAMUX2_GPIO016_InOutSPISIMOA					0x00000001UL				// 0b00		0b01
#define GPAMUX2_GPIO016_OutCANTXB						0x00000002UL				// 0b00		0b10
#define GPAMUX2_GPIO016_OutOUTPUTXBAR7					0x00000003UL				// 0b00		0b11
#define GPAMUX2_GPIO016_OutEPWM9A						0x00000001UL				// 0b01		0b01
#define GPAMUX2_GPIO016_InSD1_D1						0x00000003UL				// 0b01		0b11
#define GPAMUX2_GPIO016_InOutUPP_D4						0x00000003UL				// 0b11		0b11

//// GPAMUX2 Register : Bit Value													// GMUX		MUX
#define MUX_GPIO031_InOutGPIO							0U							// -		0b00
#define MUX_GPIO031_OutCANTXA							1U							// 0b00		0b01
#define MUX_GPIO031_OutnEM1WE							2U							// 0b00		0b10
#define MUX_GPIO031_OutOUTPUTXBAR8						1U							// 0b01		0b01
#define MUX_GPIO031_InOutEQEP3I							2U							// 0b01		0b10
#define MUX_GPIO031_InSD2_D4							3U							// 0b01		0b11

#define MUX_GPIO030_InOutGPIO							0U							// -		0b00
#define MUX_GPIO030_InCANRXA							1U							// 0b00		0b01
#define MUX_GPIO030_OutEM1CLK							2U							// 0b00		0b10
#define MUX_GPIO030_OutOUTPUTXBAR7						1U							// 0b01		0b01
#define MUX_GPIO030_InOutEQEP3S							2U							// 0b01		0b10
#define MUX_GPIO030_InSD2_D4							3U							// 0b01		0b11

#define MUX_GPIO029_InOutGPIO							0U							// -		0b00
#define MUX_GPIO029_OutSCITXDA							1U							// 0b00		0b01
#define MUX_GPIO029_OutEM1SDCKE							2U							// 0b00		0b10
#define MUX_GPIO029_OutOUTPUTXBAR6						1U							// 0b01		0b01
#define MUX_GPIO029_InEQEP3B							2U							// 0b01		0b10
#define MUX_GPIO029_InSD2_C3							3U							// 0b01		0b11

#define MUX_GPIO028_InOutGPIO							0U							// -		0b00
#define MUX_GPIO028_InSCIRXDA							1U							// 0b00		0b01
#define MUX_GPIO028_OutnEM1CS4							2U							// 0b00		0b10
#define MUX_GPIO028_OutOUTPUTXBAR5						1U							// 0b01		0b01
#define MUX_GPIO028_InEQEP3A							2U							// 0b01		0b10
#define MUX_GPIO028_InSD2_D3							3U							// 0b01		0b11

#define MUX_GPIO027_InOutGPIO							0U							// -		0b00
#define MUX_GPIO027_OutOUTPUTXBAR4						1U							// 0b00		0b01
#define MUX_GPIO027_InOutEQEP2S							2U							// 0b00		0b10
#define MUX_GPIO027_InOutMFSXB							3U							// 0b00		0b11
#define MUX_GPIO027_InOutnSPISTEB						2U							// 0b01		0b10
#define MUX_GPIO027_InSD2_C2							3U							// 0b01		0b11

#define MUX_GPIO026_InOutGPIO							0U							// -		0b00
#define MUX_GPIO026_OutOUTPUTXBAR3						1U							// 0b00		0b01
#define MUX_GPIO026_InOutEQEP2I							2U							// 0b00		0b10
#define MUX_GPIO026_InOutMCLKXB							3U							// 0b00		0b11
#define MUX_GPIO026_InOutPICLKB							2U							// 0b01		0b10
#define MUX_GPIO026_InSD2_D2							3U							// 0b01		0b11

#define MUX_GPIO025_InOutGPIO							0U							// -		0b00
#define MUX_GPIO025_OutOUTPUTXBAR2						1U							// 0b00		0b01
#define MUX_GPIO025_InEQEP2B							2U							// 0b00		0b10
#define MUX_GPIO025_InMDRB								3U							// 0b00		0b11
#define MUX_GPIO025_InOutSPISOMIB						2U							// 0b01		0b10
#define MUX_GPIO025_InSD2_C1							3U							// 0b01		0b11

#define MUX_GPIO024_InOutGPIO							0U							// -		0b00
#define MUX_GPIO024_OutOUTPUTXBAR1						1U							// 0b00		0b01
#define MUX_GPIO024_InEQEP2A							2U							// 0b00		0b10
#define MUX_GPIO024_OutMDXB								3U							// 0b00		0b11
#define MUX_GPIO024_InOutSPISIMOB						2U							// 0b01		0b10
#define MUX_GPIO024_InSD2_D1							3U							// 0b01		0b11

#define MUX_GPIO023_InOutGPIO							0U							// -		0b00
#define MUX_GPIO023_InOutEQEP1I							1U							// 0b00		0b01
#define MUX_GPIO023_InOutMFSXA							2U							// 0b00		0b10
#define MUX_GPIO023_InSCITXDB							3U							// 0b00		0b11
#define MUX_GPIO023_OutEPWM12B							1U							// 0b01		0b01
#define MUX_GPIO023_InOutnSPISTEB						2U							// 0b01		0b10
#define MUX_GPIO023_InSD1_C4							3U							// 0b01		0b11

#define MUX_GPIO022_InOutGPIO							0U							// -		0b00
#define MUX_GPIO022_InOutEQEP1S							1U							// 0b00		0b01
#define MUX_GPIO022_InOutMCLKXA							2U							// 0b00		0b10
#define MUX_GPIO022_OutSCITXDB							3U							// 0b00		0b11
#define MUX_GPIO022_OutEPWM12A							1U							// 0b01		0b01
#define MUX_GPIO022_InOutSPICLKB						2U							// 0b01		0b10
#define MUX_GPIO022_InSD1_D4							3U							// 0b01		0b11

#define MUX_GPIO021_InOutGPIO							0U							// -		0b00
#define MUX_GPIO021_InEQEP1B							1U							// 0b00		0b01
#define MUX_GPIO021_InMDRA								2U							// 0b00		0b10
#define MUX_GPIO021_InCANRXB							3U							// 0b00		0b11
#define MUX_GPIO021_OutEPWM11B							1U							// 0b01		0b01
#define MUX_GPIO021_InSD1_C3							3U							// 0b01		0b11
#define MUX_GPIO021_InOutUPP_CLK						3U							// 0b11		0b11

#define MUX_GPIO020_InOutGPIO							0U							// -		0b00
#define MUX_GPIO020_InEQEP1A							1U							// 0b00		0b01
#define MUX_GPIO020_OutMDXA								2U							// 0b00		0b10
#define MUX_GPIO020_OutCANTXB							3U							// 0b00		0b11
#define MUX_GPIO020_OutEPWM11A							1U							// 0b01		0b01
#define MUX_GPIO020_InSD1_D3							3U							// 0b01		0b11
#define MUX_GPIO020_InOutUPP_D0							3U							// 0b11		0b11

#define MUX_GPIO019_InOutGPIO							0U							// -		0b00
#define MUX_GPIO019_InOutnSPISTEA						1U							// 0b00		0b01
#define MUX_GPIO019_InSCIRXDB							2U							// 0b00		0b10
#define MUX_GPIO019_OutCANTXA							3U							// 0b00		0b11
#define MUX_GPIO019_OutEPWM10B							1U							// 0b01		0b01
#define MUX_GPIO019_InSD1_C2							3U							// 0b01		0b11
#define MUX_GPIO019_InOutUPP_D1							3U							// 0b11		0b11

#define MUX_GPIO018_InOutGPIO							0U							// -		0b00
#define MUX_GPIO018_InOutSPICLKA						1U							// 0b00		0b01
#define MUX_GPIO018_OutSCITXDB							2U							// 0b00		0b10
#define MUX_GPIO018_InCANRXA							3U							// 0b00		0b11
#define MUX_GPIO018_OutEPWM10A							1U							// 0b01		0b01
#define MUX_GPIO018_InSD1_D2							3U							// 0b01		0b11
#define MUX_GPIO018_InOutUPP_D2							3U							// 0b11		0b11

#define MUX_GPIO017_InOutGPIO							0U							// -		0b00
#define MUX_GPIO017_InOutSPISOMIA						1U							// 0b00		0b01
#define MUX_GPIO017_InCANTXB							2U							// 0b00		0b10
#define MUX_GPIO017_OutOUTPUTXBAR8						3U							// 0b00		0b11
#define MUX_GPIO017_OutEPWM9B							1U							// 0b01		0b01
#define MUX_GPIO017_InSD1_C1							3U							// 0b01		0b11
#define MUX_GPIO017_InOutUPP_D3							3U							// 0b11		0b11

#define MUX_GPIO016_InOutGPIO							0U							// -		0b00
#define MUX_GPIO016_InOutSPISIMOA						1U							// 0b00		0b01
#define MUX_GPIO016_OutCANTXB							2U							// 0b00		0b10
#define MUX_GPIO016_OutOUTPUTXBAR7						3U							// 0b00		0b11
#define MUX_GPIO016_OutEPWM9A							1U							// 0b01		0b01
#define MUX_GPIO016_InSD1_D1							3U							// 0b01		0b11
#define MUX_GPIO016_InOutUPP_D4							3U							// 0b11		0b11
#endif

struct GPADIR_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO1:1;                     // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO2:1;                     // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO3:1;                     // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO4:1;                     // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO5:1;                     // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO6:1;                     // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO7:1;                     // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO8:1;                     // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO9:1;                     // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO10:1;                    // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO11:1;                    // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO12:1;                    // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO13:1;                    // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO14:1;                    // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO15:1;                    // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO16:1;                    // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO17:1;                    // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO18:1;                    // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO19:1;                    // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO20:1;                    // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO21:1;                    // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO22:1;                    // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO23:1;                    // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO24:1;                    // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO25:1;                    // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO26:1;                    // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO27:1;                    // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO28:1;                    // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO29:1;                    // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO30:1;                    // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO31:1;                    // 31 Defines direction for this pin in GPIO mode
};

union GPADIR_REG {
    Uint32  all;
    struct  GPADIR_BITS  bit;
};

#ifdef CPU1
// GPADIR Register
//// GPADIR Register : Byte Value
#define GPADIR_GPIO031_Input							0x00000000UL
#define GPADIR_GPIO031_Output							0x80000000UL

#define GPADIR_GPIO030_Input							0x00000000UL
#define GPADIR_GPIO030_Output							0x40000000UL

#define GPADIR_GPIO029_Input							0x00000000UL
#define GPADIR_GPIO029_Output							0x20000000UL

#define GPADIR_GPIO028_Input							0x00000000UL
#define GPADIR_GPIO028_Output							0x10000000UL

#define GPADIR_GPIO027_Input							0x00000000UL
#define GPADIR_GPIO027_Output							0x08000000UL

#define GPADIR_GPIO026_Input							0x00000000UL
#define GPADIR_GPIO026_Output							0x04000000UL

#define GPADIR_GPIO025_Input							0x00000000UL
#define GPADIR_GPIO025_Output							0x02000000UL

#define GPADIR_GPIO024_Input							0x00000000UL
#define GPADIR_GPIO024_Output							0x01000000UL

#define GPADIR_GPIO023_Input							0x00000000UL
#define GPADIR_GPIO023_Output							0x00800000UL

#define GPADIR_GPIO022_Input							0x00000000UL
#define GPADIR_GPIO022_Output							0x00400000UL

#define GPADIR_GPIO021_Input							0x00000000UL
#define GPADIR_GPIO021_Output							0x00200000UL

#define GPADIR_GPIO020_Input							0x00000000UL
#define GPADIR_GPIO020_Output							0x00100000UL

#define GPADIR_GPIO019_Input							0x00000000UL
#define GPADIR_GPIO019_Output							0x00080000UL

#define GPADIR_GPIO018_Input							0x00000000UL
#define GPADIR_GPIO018_Output							0x00040000UL

#define GPADIR_GPIO017_Input							0x00000000UL
#define GPADIR_GPIO017_Output							0x00020000UL

#define GPADIR_GPIO016_Input							0x00000000UL
#define GPADIR_GPIO016_Output							0x00010000UL

#define GPADIR_GPIO015_Input							0x00000000UL
#define GPADIR_GPIO015_Output							0x00008000UL

#define GPADIR_GPIO014_Input							0x00000000UL
#define GPADIR_GPIO014_Output							0x00004000UL

#define GPADIR_GPIO013_Input							0x00000000UL
#define GPADIR_GPIO013_Output							0x00002000UL

#define GPADIR_GPIO012_Input							0x00000000UL
#define GPADIR_GPIO012_Output							0x00001000UL

#define GPADIR_GPIO011_Input							0x00000000UL
#define GPADIR_GPIO011_Output							0x00000800UL

#define GPADIR_GPIO010_Input							0x00000000UL
#define GPADIR_GPIO010_Output							0x00000400UL

#define GPADIR_GPIO009_Input							0x00000000UL
#define GPADIR_GPIO009_Output							0x00000200UL

#define GPADIR_GPIO008_Input							0x00000000UL
#define GPADIR_GPIO008_Output							0x00000100UL

#define GPADIR_GPIO007_Input							0x00000000UL
#define GPADIR_GPIO007_Output							0x00000080UL

#define GPADIR_GPIO006_Input							0x00000000UL
#define GPADIR_GPIO006_Output							0x00000040UL

#define GPADIR_GPIO005_Input							0x00000000UL
#define GPADIR_GPIO005_Output							0x00000020UL

#define GPADIR_GPIO004_Input							0x00000000UL
#define GPADIR_GPIO004_Output							0x00000010UL

#define GPADIR_GPIO003_Input							0x00000000UL
#define GPADIR_GPIO003_Output							0x00000008UL

#define GPADIR_GPIO002_Input							0x00000000UL
#define GPADIR_GPIO002_Output							0x00000004UL

#define GPADIR_GPIO001_Input							0x00000000UL
#define GPADIR_GPIO001_Output							0x00000002UL

#define GPADIR_GPIO000_Input							0x00000000UL
#define GPADIR_GPIO000_Output							0x00000001UL

//// GPADIR Register : Bit Value
#define GPIOxxx_Input									0U
#define GPIOxxx_Output									1U
#endif

struct GPAPUD_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Pull-Up Disable control for this pin
    Uint16 GPIO1:1;                     // 1 Pull-Up Disable control for this pin
    Uint16 GPIO2:1;                     // 2 Pull-Up Disable control for this pin
    Uint16 GPIO3:1;                     // 3 Pull-Up Disable control for this pin
    Uint16 GPIO4:1;                     // 4 Pull-Up Disable control for this pin
    Uint16 GPIO5:1;                     // 5 Pull-Up Disable control for this pin
    Uint16 GPIO6:1;                     // 6 Pull-Up Disable control for this pin
    Uint16 GPIO7:1;                     // 7 Pull-Up Disable control for this pin
    Uint16 GPIO8:1;                     // 8 Pull-Up Disable control for this pin
    Uint16 GPIO9:1;                     // 9 Pull-Up Disable control for this pin
    Uint16 GPIO10:1;                    // 10 Pull-Up Disable control for this pin
    Uint16 GPIO11:1;                    // 11 Pull-Up Disable control for this pin
    Uint16 GPIO12:1;                    // 12 Pull-Up Disable control for this pin
    Uint16 GPIO13:1;                    // 13 Pull-Up Disable control for this pin
    Uint16 GPIO14:1;                    // 14 Pull-Up Disable control for this pin
    Uint16 GPIO15:1;                    // 15 Pull-Up Disable control for this pin
    Uint16 GPIO16:1;                    // 16 Pull-Up Disable control for this pin
    Uint16 GPIO17:1;                    // 17 Pull-Up Disable control for this pin
    Uint16 GPIO18:1;                    // 18 Pull-Up Disable control for this pin
    Uint16 GPIO19:1;                    // 19 Pull-Up Disable control for this pin
    Uint16 GPIO20:1;                    // 20 Pull-Up Disable control for this pin
    Uint16 GPIO21:1;                    // 21 Pull-Up Disable control for this pin
    Uint16 GPIO22:1;                    // 22 Pull-Up Disable control for this pin
    Uint16 GPIO23:1;                    // 23 Pull-Up Disable control for this pin
    Uint16 GPIO24:1;                    // 24 Pull-Up Disable control for this pin
    Uint16 GPIO25:1;                    // 25 Pull-Up Disable control for this pin
    Uint16 GPIO26:1;                    // 26 Pull-Up Disable control for this pin
    Uint16 GPIO27:1;                    // 27 Pull-Up Disable control for this pin
    Uint16 GPIO28:1;                    // 28 Pull-Up Disable control for this pin
    Uint16 GPIO29:1;                    // 29 Pull-Up Disable control for this pin
    Uint16 GPIO30:1;                    // 30 Pull-Up Disable control for this pin
    Uint16 GPIO31:1;                    // 31 Pull-Up Disable control for this pin
};

union GPAPUD_REG {
    Uint32  all;
    struct  GPAPUD_BITS  bit;
};

#ifdef CPU1
// GPAPUD Register
//// GPAPUD Register : Byte Value
#define GPAPUD_GPIO031_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO031_PullUpDisable					0x80000000UL

#define GPAPUD_GPIO030_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO030_PullUpDisable					0x40000000UL

#define GPAPUD_GPIO029_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO029_PullUpDisable					0x20000000UL

#define GPAPUD_GPIO028_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO028_PullUpDisable					0x10000000UL

#define GPAPUD_GPIO027_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO027_PullUpDisable					0x08000000UL

#define GPAPUD_GPIO026_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO026_PullUpDisable					0x04000000UL

#define GPAPUD_GPIO025_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO025_PullUpDisable					0x02000000UL

#define GPAPUD_GPIO024_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO024_PullUpDisable					0x01000000UL

#define GPAPUD_GPIO023_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO023_PullUpDisable					0x00800000UL

#define GPAPUD_GPIO022_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO022_PullUpDisable					0x00400000UL

#define GPAPUD_GPIO021_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO021_PullUpDisable					0x00200000UL

#define GPAPUD_GPIO020_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO020_PullUpDisable					0x00100000UL

#define GPAPUD_GPIO019_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO019_PullUpDisable					0x00080000UL

#define GPAPUD_GPIO018_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO018_PullUpDisable					0x00040000UL

#define GPAPUD_GPIO017_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO017_PullUpDisable					0x00020000UL

#define GPAPUD_GPIO016_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO016_PullUpDisable					0x00010000UL

#define GPAPUD_GPIO015_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO015_PullUpDisable					0x00008000UL

#define GPAPUD_GPIO014_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO014_PullUpDisable					0x00004000UL

#define GPAPUD_GPIO013_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO013_PullUpDisable					0x00002000UL

#define GPAPUD_GPIO012_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO012_PullUpDisable					0x00001000UL

#define GPAPUD_GPIO011_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO011_PullUpDisable					0x00000800UL

#define GPAPUD_GPIO010_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO010_PullUpDisable					0x00000400UL

#define GPAPUD_GPIO009_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO009_PullUpDisable					0x00000200UL

#define GPAPUD_GPIO008_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO008_PullUpDisable					0x00000100UL

#define GPAPUD_GPIO007_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO007_PullUpDisable					0x00000080UL

#define GPAPUD_GPIO006_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO006_PullUpDisable					0x00000040UL

#define GPAPUD_GPIO005_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO005_PullUpDisable					0x00000020UL

#define GPAPUD_GPIO004_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO004_PullUpDisable					0x00000010UL

#define GPAPUD_GPIO003_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO003_PullUpDisable					0x00000008UL

#define GPAPUD_GPIO002_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO002_PullUpDisable					0x00000004UL

#define GPAPUD_GPIO001_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO001_PullUpDisable					0x00000002UL

#define GPAPUD_GPIO000_PullUpEnable						0x00000000UL
#define GPAPUD_GPIO000_PullUpDisable					0x00000001UL

//// GPAPUD Register : Bit Value
#define GPIOxxx_PullUpEnable							0U
#define GPIOxxx_PullUpDisable							1U
#endif

struct GPAINV_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Input inversion control for this pin
    Uint16 GPIO1:1;                     // 1 Input inversion control for this pin
    Uint16 GPIO2:1;                     // 2 Input inversion control for this pin
    Uint16 GPIO3:1;                     // 3 Input inversion control for this pin
    Uint16 GPIO4:1;                     // 4 Input inversion control for this pin
    Uint16 GPIO5:1;                     // 5 Input inversion control for this pin
    Uint16 GPIO6:1;                     // 6 Input inversion control for this pin
    Uint16 GPIO7:1;                     // 7 Input inversion control for this pin
    Uint16 GPIO8:1;                     // 8 Input inversion control for this pin
    Uint16 GPIO9:1;                     // 9 Input inversion control for this pin
    Uint16 GPIO10:1;                    // 10 Input inversion control for this pin
    Uint16 GPIO11:1;                    // 11 Input inversion control for this pin
    Uint16 GPIO12:1;                    // 12 Input inversion control for this pin
    Uint16 GPIO13:1;                    // 13 Input inversion control for this pin
    Uint16 GPIO14:1;                    // 14 Input inversion control for this pin
    Uint16 GPIO15:1;                    // 15 Input inversion control for this pin
    Uint16 GPIO16:1;                    // 16 Input inversion control for this pin
    Uint16 GPIO17:1;                    // 17 Input inversion control for this pin
    Uint16 GPIO18:1;                    // 18 Input inversion control for this pin
    Uint16 GPIO19:1;                    // 19 Input inversion control for this pin
    Uint16 GPIO20:1;                    // 20 Input inversion control for this pin
    Uint16 GPIO21:1;                    // 21 Input inversion control for this pin
    Uint16 GPIO22:1;                    // 22 Input inversion control for this pin
    Uint16 GPIO23:1;                    // 23 Input inversion control for this pin
    Uint16 GPIO24:1;                    // 24 Input inversion control for this pin
    Uint16 GPIO25:1;                    // 25 Input inversion control for this pin
    Uint16 GPIO26:1;                    // 26 Input inversion control for this pin
    Uint16 GPIO27:1;                    // 27 Input inversion control for this pin
    Uint16 GPIO28:1;                    // 28 Input inversion control for this pin
    Uint16 GPIO29:1;                    // 29 Input inversion control for this pin
    Uint16 GPIO30:1;                    // 30 Input inversion control for this pin
    Uint16 GPIO31:1;                    // 31 Input inversion control for this pin
};

union GPAINV_REG {
    Uint32  all;
    struct  GPAINV_BITS  bit;
};

#ifdef CPU1
// GPAINV Register
//// GPAINV Register : Byte Value
#define GPAINV_GPIO031_InNormal							0x00000000UL
#define GPAINV_GPIO031_InInverted						0x80000000UL

#define GPAINV_GPIO030_InNormal							0x00000000UL
#define GPAINV_GPIO030_InInverted						0x40000000UL

#define GPAINV_GPIO029_InNormal							0x00000000UL
#define GPAINV_GPIO029_InInverted						0x20000000UL

#define GPAINV_GPIO028_InNormal							0x00000000UL
#define GPAINV_GPIO028_InInverted						0x10000000UL

#define GPAINV_GPIO027_InNormal							0x00000000UL
#define GPAINV_GPIO027_InInverted						0x08000000UL

#define GPAINV_GPIO026_InNormal							0x00000000UL
#define GPAINV_GPIO026_InInverted						0x04000000UL

#define GPAINV_GPIO025_InNormal							0x00000000UL
#define GPAINV_GPIO025_InInverted						0x02000000UL

#define GPAINV_GPIO024_InNormal							0x00000000UL
#define GPAINV_GPIO024_InInverted						0x01000000UL

#define GPAINV_GPIO023_InNormal							0x00000000UL
#define GPAINV_GPIO023_InInverted						0x00800000UL

#define GPAINV_GPIO022_InNormal							0x00000000UL
#define GPAINV_GPIO022_InInverted						0x00400000UL

#define GPAINV_GPIO021_InNormal							0x00000000UL
#define GPAINV_GPIO021_InInverted						0x00200000UL

#define GPAINV_GPIO020_InNormal							0x00000000UL
#define GPAINV_GPIO020_InInverted						0x00100000UL

#define GPAINV_GPIO019_InNormal							0x00000000UL
#define GPAINV_GPIO019_InInverted						0x00080000UL

#define GPAINV_GPIO018_InNormal							0x00000000UL
#define GPAINV_GPIO018_InInverted						0x00040000UL

#define GPAINV_GPIO017_InNormal							0x00000000UL
#define GPAINV_GPIO017_InInverted						0x00020000UL

#define GPAINV_GPIO016_InNormal							0x00000000UL
#define GPAINV_GPIO016_InInverted						0x00010000UL

#define GPAINV_GPIO015_InNormal							0x00000000UL
#define GPAINV_GPIO015_InInverted						0x00008000UL

#define GPAINV_GPIO014_InNormal							0x00000000UL
#define GPAINV_GPIO014_InInverted						0x00004000UL

#define GPAINV_GPIO013_InNormal							0x00000000UL
#define GPAINV_GPIO013_InInverted						0x00002000UL

#define GPAINV_GPIO012_InNormal							0x00000000UL
#define GPAINV_GPIO012_InInverted						0x00001000UL

#define GPAINV_GPIO011_InNormal							0x00000000UL
#define GPAINV_GPIO011_InInverted						0x00000800UL

#define GPAINV_GPIO010_InNormal							0x00000000UL
#define GPAINV_GPIO010_InInverted						0x00000400UL

#define GPAINV_GPIO009_InNormal							0x00000000UL
#define GPAINV_GPIO009_InInverted						0x00000200UL

#define GPAINV_GPIO008_InNormal							0x00000000UL
#define GPAINV_GPIO008_InInverted						0x00000100UL

#define GPAINV_GPIO007_InNormal							0x00000000UL
#define GPAINV_GPIO007_InInverted						0x00000080UL

#define GPAINV_GPIO006_InNormal							0x00000000UL
#define GPAINV_GPIO006_InInverted						0x00000040UL

#define GPAINV_GPIO005_InNormal							0x00000000UL
#define GPAINV_GPIO005_InInverted						0x00000020UL

#define GPAINV_GPIO004_InNormal							0x00000000UL
#define GPAINV_GPIO004_InInverted						0x00000010UL

#define GPAINV_GPIO003_InNormal							0x00000000UL
#define GPAINV_GPIO003_InInverted						0x00000008UL

#define GPAINV_GPIO002_InNormal							0x00000000UL
#define GPAINV_GPIO002_InInverted						0x00000004UL

#define GPAINV_GPIO001_InNormal							0x00000000UL
#define GPAINV_GPIO001_InInverted						0x00000002UL

#define GPAINV_GPIO000_InNormal							0x00000000UL
#define GPAINV_GPIO000_InInverted						0x00000001UL

//// GPAINV Register : Bit Value
#define GPIOxxx_InNormal								0U
#define GPIOxxx_InInverted								1U
#endif

struct GPAODR_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO1:1;                     // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO2:1;                     // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO3:1;                     // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO4:1;                     // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO5:1;                     // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO6:1;                     // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO7:1;                     // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO8:1;                     // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO9:1;                     // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO10:1;                    // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO11:1;                    // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO12:1;                    // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO13:1;                    // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO14:1;                    // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO15:1;                    // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO16:1;                    // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO17:1;                    // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO18:1;                    // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO19:1;                    // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO20:1;                    // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO21:1;                    // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO22:1;                    // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO23:1;                    // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO24:1;                    // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO25:1;                    // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO26:1;                    // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO27:1;                    // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO28:1;                    // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO29:1;                    // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO30:1;                    // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO31:1;                    // 31 Outpout Open-Drain control for this pin
};

union GPAODR_REG {
    Uint32  all;
    struct  GPAODR_BITS  bit;
};

#ifdef CPU1
// GPAODR Register
//// GPAODR Register : Byte Value
#define GPAODR_GPIO031_Normal							0x00000000UL
#define GPAODR_GPIO031_OpenDrain						0x80000000UL

#define GPAODR_GPIO030_Normal							0x00000000UL
#define GPAODR_GPIO030_OpenDrain						0x40000000UL

#define GPAODR_GPIO029_Normal							0x00000000UL
#define GPAODR_GPIO029_OpenDrain						0x20000000UL

#define GPAODR_GPIO028_Normal							0x00000000UL
#define GPAODR_GPIO028_OpenDrain						0x10000000UL

#define GPAODR_GPIO027_Normal							0x00000000UL
#define GPAODR_GPIO027_OpenDrain						0x08000000UL

#define GPAODR_GPIO026_Normal							0x00000000UL
#define GPAODR_GPIO026_OpenDrain						0x04000000UL

#define GPAODR_GPIO025_Normal							0x00000000UL
#define GPAODR_GPIO025_OpenDrain						0x02000000UL

#define GPAODR_GPIO024_Normal							0x00000000UL
#define GPAODR_GPIO024_OpenDrain						0x01000000UL

#define GPAODR_GPIO023_Normal							0x00000000UL
#define GPAODR_GPIO023_OpenDrain						0x00800000UL

#define GPAODR_GPIO022_Normal							0x00000000UL
#define GPAODR_GPIO022_OpenDrain						0x00400000UL

#define GPAODR_GPIO021_Normal							0x00000000UL
#define GPAODR_GPIO021_OpenDrain						0x00200000UL

#define GPAODR_GPIO020_Normal							0x00000000UL
#define GPAODR_GPIO020_OpenDrain						0x00100000UL

#define GPAODR_GPIO019_Normal							0x00000000UL
#define GPAODR_GPIO019_OpenDrain						0x00080000UL

#define GPAODR_GPIO018_Normal							0x00000000UL
#define GPAODR_GPIO018_OpenDrain						0x00040000UL

#define GPAODR_GPIO017_Normal							0x00000000UL
#define GPAODR_GPIO017_OpenDrain						0x00020000UL

#define GPAODR_GPIO016_Normal							0x00000000UL
#define GPAODR_GPIO016_OpenDrain						0x00010000UL

#define GPAODR_GPIO015_Normal							0x00000000UL
#define GPAODR_GPIO015_OpenDrain						0x00008000UL

#define GPAODR_GPIO014_Normal							0x00000000UL
#define GPAODR_GPIO014_OpenDrain						0x00004000UL

#define GPAODR_GPIO013_Normal							0x00000000UL
#define GPAODR_GPIO013_OpenDrain						0x00002000UL

#define GPAODR_GPIO012_Normal							0x00000000UL
#define GPAODR_GPIO012_OpenDrain						0x00001000UL

#define GPAODR_GPIO011_Normal							0x00000000UL
#define GPAODR_GPIO011_OpenDrain						0x00000800UL

#define GPAODR_GPIO010_Normal							0x00000000UL
#define GPAODR_GPIO010_OpenDrain						0x00000400UL

#define GPAODR_GPIO009_Normal							0x00000000UL
#define GPAODR_GPIO009_OpenDrain						0x00000200UL

#define GPAODR_GPIO008_Normal							0x00000000UL
#define GPAODR_GPIO008_OpenDrain						0x00000100UL

#define GPAODR_GPIO007_Normal							0x00000000UL
#define GPAODR_GPIO007_OpenDrain						0x00000080UL

#define GPAODR_GPIO006_Normal							0x00000000UL
#define GPAODR_GPIO006_OpenDrain						0x00000040UL

#define GPAODR_GPIO005_Normal							0x00000000UL
#define GPAODR_GPIO005_OpenDrain						0x00000020UL

#define GPAODR_GPIO004_Normal							0x00000000UL
#define GPAODR_GPIO004_OpenDrain						0x00000010UL

#define GPAODR_GPIO003_Normal							0x00000000UL
#define GPAODR_GPIO003_OpenDrain						0x00000008UL

#define GPAODR_GPIO002_Normal							0x00000000UL
#define GPAODR_GPIO002_OpenDrain						0x00000004UL

#define GPAODR_GPIO001_Normal							0x00000000UL
#define GPAODR_GPIO001_OpenDrain						0x00000002UL

#define GPAODR_GPIO000_Normal							0x00000000UL
#define GPAODR_GPIO000_OpenDrain						0x00000001UL

//// GPAODR Register : Bit Value
#define GPIOxxx_Normal									0U
#define GPIOxxx_OpenDrain								1U
#endif

struct GPAGMUX1_BITS {                  // bits description
    Uint16 GPIO0:2;                     // 1:0 Defines pin-muxing selection for GPIO0
    Uint16 GPIO1:2;                     // 3:2 Defines pin-muxing selection for GPIO1
    Uint16 GPIO2:2;                     // 5:4 Defines pin-muxing selection for GPIO2
    Uint16 GPIO3:2;                     // 7:6 Defines pin-muxing selection for GPIO3
    Uint16 GPIO4:2;                     // 9:8 Defines pin-muxing selection for GPIO4
    Uint16 GPIO5:2;                     // 11:10 Defines pin-muxing selection for GPIO5
    Uint16 GPIO6:2;                     // 13:12 Defines pin-muxing selection for GPIO6
    Uint16 GPIO7:2;                     // 15:14 Defines pin-muxing selection for GPIO7
    Uint16 GPIO8:2;                     // 17:16 Defines pin-muxing selection for GPIO8
    Uint16 GPIO9:2;                     // 19:18 Defines pin-muxing selection for GPIO9
    Uint16 GPIO10:2;                    // 21:20 Defines pin-muxing selection for GPIO10
    Uint16 GPIO11:2;                    // 23:22 Defines pin-muxing selection for GPIO11
    Uint16 GPIO12:2;                    // 25:24 Defines pin-muxing selection for GPIO12
    Uint16 GPIO13:2;                    // 27:26 Defines pin-muxing selection for GPIO13
    Uint16 GPIO14:2;                    // 29:28 Defines pin-muxing selection for GPIO14
    Uint16 GPIO15:2;                    // 31:30 Defines pin-muxing selection for GPIO15
};

union GPAGMUX1_REG {
    Uint32  all;
    struct  GPAGMUX1_BITS  bit;
};

#ifdef CPU1
// GPAGMUX1 Register
//// GPAGMUX1 Register : Byte Value													// GMUX		MUX
#define GPAGMUX1_GPIO015_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO015_OutEPWM8B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO015_InSCITXDB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO015_InOutMFSXB						0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO015_OutOUTPUTXBAR4					0x40000000UL				// 0b01		0b10
#define GPAGMUX1_GPIO015_InOutUPP_D5					0xC0000000UL				// 0b11		0b11

#define GPAGMUX1_GPIO014_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO014_OutEPWM8A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO014_OutSCITXDB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO014_InOutMCLKXB					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO014_OutOUTPUTXBAR3					0x10000000UL				// 0b01		0b10
#define GPAGMUX1_GPIO014_InOutUPP_D6					0x30000000UL				// 0b11		0b11

#define GPAGMUX1_GPIO013_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO013_OutEPWM7B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO013_InCANRXB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO013_InMDRB							0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO013_InOutEQEP1I					0x04000000UL				// 0b01		0b01
#define GPAGMUX1_GPIO013_InSCIRXDC						0x04000000UL				// 0b01		0b10
#define GPAGMUX1_GPIO013_InOutUPP_D7					0x0C000000UL				// 0b11		0b11

#define GPAGMUX1_GPIO012_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO012_OutEPWM7A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO012_OutCANTXB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO012_OutMDXB						0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO012_InOutEQEP1S					0x01000000UL				// 0b01		0b01
#define GPAGMUX1_GPIO012_OutSCITXDC						0x01000000UL				// 0b01		0b10
#define GPAGMUX1_GPIO012_InOutUPP_ENA					0x03000000UL				// 0b11		0b11

#define GPAGMUX1_GPIO011_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO011_OutEPWM6B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO011_InSCIRXDB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO011_OutOUTPUTXBAR7					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO011_InEQEP1B						0x00400000UL				// 0b01		0b01
#define GPAGMUX1_GPIO011_InOutUPP_START					0x00C00000UL				// 0b11		0b11

#define GPAGMUX1_GPIO010_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO010_OutEPWM6A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO010_InCANRXB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO010_OutADCSOCBO					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO010_InEQEP1A						0x00100000UL				// 0b01		0b01
#define GPAGMUX1_GPIO010_OutSCITXDB						0x00100000UL				// 0b01		0b10
#define GPAGMUX1_GPIO010_InOutUPP_WAIT					0x00300000UL				// 0b11		0b11

#define GPAGMUX1_GPIO009_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO009_OutEPWM5B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO009_OutSCITXDB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO009_OutOUTPUTXBAR6					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO009_InOutEQEP3I					0x00040000UL				// 0b01		0b01
#define GPAGMUX1_GPIO009_InSCIRXDA						0x00040000UL				// 0b01		0b10

#define GPAGMUX1_GPIO008_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO008_OutEPWM5A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO008_OutCANTXB						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO008_OutADCSOCAO					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO008_InOutEQEP3S					0x00010000UL				// 0b01		0b01
#define GPAGMUX1_GPIO008_OutSCITXDA						0x00010000UL				// 0b01		0b10

#define GPAGMUX1_GPIO007_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO007_OutEPWM4B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO007_InOutMCLKRA					0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO007_OutOUTPUTXBAR5					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO007_InEQEP3B						0x00004000UL				// 0b01		0b01
#define GPAGMUX1_GPIO007_InCANRXB						0x00004000UL				// 0b01		0b10

#define GPAGMUX1_GPIO006_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO006_OutEPWM4A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO006_OutOUTPUTXBAR4					0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO006_OutEXTSYNCOUT					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO006_InEQEP3A						0x00001000UL				// 0b01		0b01
#define GPAGMUX1_GPIO006_OutCANTXB						0x00001000UL				// 0b01		0b10

#define GPAGMUX1_GPIO005_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO005_OutEPWM3B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO005_InOutMFSRA						0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO005_OutOUTPUTXBAR3					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO005_InCANRXA						0x00000400UL				// 0b01		0b10

#define GPAGMUX1_GPIO004_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO004_OutEPWM3A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO004_OutOUTPUTXBAR3					0x00000100UL				// 0b01		0b01
#define GPAGMUX1_GPIO004_OutCANTXA						0x00000100UL				// 0b01		0b10

#define GPAGMUX1_GPIO003_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO003_OutEPWM2B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO003_OutOUTPUTXBAR2					0x00000000UL				// 0b00		0b10
#define GPAGMUX1_GPIO003_InOutMCLKRB					0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO003_InODSCLB						0x00000040UL				// 0b01		0b10

#define GPAGMUX1_GPIO002_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO002_OutEPWM2A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO002_OutOUTPUTXBAR1					0x00000010UL				// 0b01		0b01
#define GPAGMUX1_GPIO002_InODSDAB						0x00000010UL				// 0b01		0b10

#define GPAGMUX1_GPIO001_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO001_OutEPWM1B						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO001_InOutMFSRB						0x00000000UL				// 0b00		0b11
#define GPAGMUX1_GPIO001_InODSCLA						0x00000004UL				// 0b01		0b10

#define GPAGMUX1_GPIO000_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX1_GPIO000_OutEPWM1A						0x00000000UL				// 0b00		0b01
#define GPAGMUX1_GPIO000_InODSDAA						0x00000001UL				// 0b01		0b10
#endif

struct GPAGMUX2_BITS {                  // bits description
    Uint16 GPIO16:2;                    // 1:0 Defines pin-muxing selection for GPIO16
    Uint16 GPIO17:2;                    // 3:2 Defines pin-muxing selection for GPIO17
    Uint16 GPIO18:2;                    // 5:4 Defines pin-muxing selection for GPIO18
    Uint16 GPIO19:2;                    // 7:6 Defines pin-muxing selection for GPIO19
    Uint16 GPIO20:2;                    // 9:8 Defines pin-muxing selection for GPIO20
    Uint16 GPIO21:2;                    // 11:10 Defines pin-muxing selection for GPIO21
    Uint16 GPIO22:2;                    // 13:12 Defines pin-muxing selection for GPIO22
    Uint16 GPIO23:2;                    // 15:14 Defines pin-muxing selection for GPIO23
    Uint16 GPIO24:2;                    // 17:16 Defines pin-muxing selection for GPIO24
    Uint16 GPIO25:2;                    // 19:18 Defines pin-muxing selection for GPIO25
    Uint16 GPIO26:2;                    // 21:20 Defines pin-muxing selection for GPIO26
    Uint16 GPIO27:2;                    // 23:22 Defines pin-muxing selection for GPIO27
    Uint16 GPIO28:2;                    // 25:24 Defines pin-muxing selection for GPIO28
    Uint16 GPIO29:2;                    // 27:26 Defines pin-muxing selection for GPIO29
    Uint16 GPIO30:2;                    // 29:28 Defines pin-muxing selection for GPIO30
    Uint16 GPIO31:2;                    // 31:30 Defines pin-muxing selection for GPIO31
};

union GPAGMUX2_REG {
    Uint32  all;
    struct  GPAGMUX2_BITS  bit;
};

#ifdef CPU1
// GPAGMUX2 Register
//// GPAGMUX2 Register : Byte Value													// GMUX		MUX
#define GPAGMUX2_GPIO031_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO031_OutCANTXA						0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO031_OutnEM1WE						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO031_OutOUTPUTXBAR8					0x40000000UL				// 0b01		0b01
#define GPAGMUX2_GPIO031_InOutEQEP3I					0x40000000UL				// 0b01		0b10
#define GPAGMUX2_GPIO031_InSD2_D4						0x40000000UL				// 0b01		0b11

#define GPAGMUX2_GPIO030_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO030_InCANRXA						0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO030_OutEM1CLK						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO030_OutOUTPUTXBAR7					0x10000000UL				// 0b01		0b01
#define GPAGMUX2_GPIO030_InOutEQEP3S					0x10000000UL				// 0b01		0b10
#define GPAGMUX2_GPIO030_InSD2_D4						0x10000000UL				// 0b01		0b11

#define GPAGMUX2_GPIO029_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO029_OutSCITXDA						0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO029_OutEM1SDCKE					0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO029_OutOUTPUTXBAR6					0x04000000UL				// 0b01		0b01
#define GPAGMUX2_GPIO029_InEQEP3B						0x04000000UL				// 0b01		0b10
#define GPAGMUX2_GPIO029_InSD2_C3						0x04000000UL				// 0b01		0b11

#define GPAGMUX2_GPIO028_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO028_InSCIRXDA						0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO028_OutnEM1CS4						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO028_OutOUTPUTXBAR5					0x01000000UL				// 0b01		0b01
#define GPAGMUX2_GPIO028_InEQEP3A						0x01000000UL				// 0b01		0b10
#define GPAGMUX2_GPIO028_InSD2_D3						0x01000000UL				// 0b01		0b11

#define GPAGMUX2_GPIO027_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO027_OutOUTPUTXBAR4					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO027_InOutEQEP2S					0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO027_InOutMFSXB						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO027_InOutnSPISTEB					0x00400000UL				// 0b01		0b10
#define GPAGMUX2_GPIO027_InSD2_C2						0x00400000UL				// 0b01		0b11

#define GPAGMUX2_GPIO026_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO026_OutOUTPUTXBAR3					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO026_InOutEQEP2I					0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO026_InOutMCLKXB					0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO026_InOutPICLKB					0x00100000UL				// 0b01		0b10
#define GPAGMUX2_GPIO026_InSD2_D2						0x00100000UL				// 0b01		0b11

#define GPAGMUX2_GPIO025_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO025_OutOUTPUTXBAR2					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO025_InEQEP2B						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO025_InMDRB							0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO025_InOutSPISOMIB					0x00040000UL				// 0b01		0b10
#define GPAGMUX2_GPIO025_InSD2_C1						0x00040000UL				// 0b01		0b11

#define GPAGMUX2_GPIO024_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO024_OutOUTPUTXBAR1					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO024_InEQEP2A						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO024_OutMDXB						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO024_InOutSPISIMOB					0x00010000UL				// 0b01		0b10
#define GPAGMUX2_GPIO024_InSD2_D1						0x00010000UL				// 0b01		0b11

#define GPAGMUX2_GPIO023_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO023_InOutEQEP1I					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO023_InOutMFSXA						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO023_InSCITXDB						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO023_OutEPWM12B						0x00004000UL				// 0b01		0b01
#define GPAGMUX2_GPIO023_InOutnSPISTEB					0x00004000UL				// 0b01		0b10
#define GPAGMUX2_GPIO023_InSD1_C4						0x00004000UL				// 0b01		0b11

#define GPAGMUX2_GPIO022_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO022_InOutEQEP1S					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO022_InOutMCLKXA					0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO022_OutSCITXDB						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO022_OutEPWM12A						0x00001000UL				// 0b01		0b01
#define GPAGMUX2_GPIO022_InOutSPICLKB					0x00001000UL				// 0b01		0b10
#define GPAGMUX2_GPIO022_InSD1_D4						0x00001000UL				// 0b01		0b11

#define GPAGMUX2_GPIO021_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO021_InEQEP1B						0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO021_InMDRA							0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO021_InCANRXB						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO021_OutEPWM11B						0x00000400UL				// 0b01		0b01
#define GPAGMUX2_GPIO021_InSD1_C3						0x00000400UL				// 0b01		0b11
#define GPAGMUX2_GPIO021_InOutUPP_CLK					0x00000C00UL				// 0b11		0b11

#define GPAGMUX2_GPIO020_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO020_InEQEP1A						0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO020_OutMDXA						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO020_OutCANTXB						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO020_OutEPWM11A						0x00000100UL				// 0b01		0b01
#define GPAGMUX2_GPIO020_InSD1_D3						0x00000100UL				// 0b01		0b11
#define GPAGMUX2_GPIO020_InOutUPP_D0					0x00000300UL				// 0b11		0b11

#define GPAGMUX2_GPIO019_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO019_InOutnSPISTEA					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO019_InSCIRXDB						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO019_OutCANTXA						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO019_OutEPWM10B						0x00000040UL				// 0b01		0b01
#define GPAGMUX2_GPIO019_InSD1_C2						0x00000040UL				// 0b01		0b11
#define GPAGMUX2_GPIO019_InOutUPP_D1					0x000000C0UL				// 0b11		0b11

#define GPAGMUX2_GPIO018_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO018_InOutSPICLKA					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO018_OutSCITXDB						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO018_InCANRXA						0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO018_OutEPWM10A						0x00000010UL				// 0b01		0b01
#define GPAGMUX2_GPIO018_InSD1_D2						0x00000010UL				// 0b01		0b11
#define GPAGMUX2_GPIO018_InOutUPP_D2					0x00000030UL				// 0b11		0b11

#define GPAGMUX2_GPIO017_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO017_InOutSPISOMIA					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO017_InCANTXB						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO017_OutOUTPUTXBAR8					0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO017_OutEPWM9B						0x00000004UL				// 0b01		0b01
#define GPAGMUX2_GPIO017_InSD1_C1						0x00000004UL				// 0b01		0b11
#define GPAGMUX2_GPIO017_InOutUPP_D3					0x0000000CUL				// 0b11		0b11

#define GPAGMUX2_GPIO016_InOutGPIO						0x00000000UL				// -		0b00
#define GPAGMUX2_GPIO016_InOutSPISIMOA					0x00000000UL				// 0b00		0b01
#define GPAGMUX2_GPIO016_OutCANTXB						0x00000000UL				// 0b00		0b10
#define GPAGMUX2_GPIO016_OutOUTPUTXBAR7					0x00000000UL				// 0b00		0b11
#define GPAGMUX2_GPIO016_OutEPWM9A						0x00000001UL				// 0b01		0b01
#define GPAGMUX2_GPIO016_InSD1_D1						0x00000001UL				// 0b01		0b11
#define GPAGMUX2_GPIO016_InOutUPP_D4					0x00000003UL				// 0b11		0b11

//// GPAGMUX2 Register : Bit Value													// GMUX		MUX
#define GMUX_GPIO031_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO031_OutCANTXA							0U							// 0b00		0b01
#define GMUX_GPIO031_OutnEM1WE							0U							// 0b00		0b10
#define GMUX_GPIO031_OutOUTPUTXBAR8						1U							// 0b01		0b01
#define GMUX_GPIO031_InOutEQEP3I						1U							// 0b01		0b10
#define GMUX_GPIO031_InSD2_D4							1U							// 0b01		0b11

#define GMUX_GPIO030_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO030_InCANRXA							0U							// 0b00		0b01
#define GMUX_GPIO030_OutEM1CLK							0U							// 0b00		0b10
#define GMUX_GPIO030_OutOUTPUTXBAR7						1U							// 0b01		0b01
#define GMUX_GPIO030_InOutEQEP3S						1U							// 0b01		0b10
#define GMUX_GPIO030_InSD2_D4							1U							// 0b01		0b11

#define GMUX_GPIO029_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO029_OutSCITXDA							0U							// 0b00		0b01
#define GMUX_GPIO029_OutEM1SDCKE						0U							// 0b00		0b10
#define GMUX_GPIO029_OutOUTPUTXBAR6						1U							// 0b01		0b01
#define GMUX_GPIO029_InEQEP3B							1U							// 0b01		0b10
#define GMUX_GPIO029_InSD2_C3							1U							// 0b01		0b11

#define GMUX_GPIO028_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO028_InSCIRXDA							0U							// 0b00		0b01
#define GMUX_GPIO028_OutnEM1CS4							0U							// 0b00		0b10
#define GMUX_GPIO028_OutOUTPUTXBAR5						1U							// 0b01		0b01
#define GMUX_GPIO028_InEQEP3A							1U							// 0b01		0b10
#define GMUX_GPIO028_InSD2_D3							1U							// 0b01		0b11

#define GMUX_GPIO027_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO027_OutOUTPUTXBAR4						0U							// 0b00		0b01
#define GMUX_GPIO027_InOutEQEP2S						0U							// 0b00		0b10
#define GMUX_GPIO027_InOutMFSXB							0U							// 0b00		0b11
#define GMUX_GPIO027_InOutnSPISTEB						1U							// 0b01		0b10
#define GMUX_GPIO027_InSD2_C2							1U							// 0b01		0b11

#define GMUX_GPIO026_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO026_OutOUTPUTXBAR3						0U							// 0b00		0b01
#define GMUX_GPIO026_InOutEQEP2I						0U							// 0b00		0b10
#define GMUX_GPIO026_InOutMCLKXB						0U							// 0b00		0b11
#define GMUX_GPIO026_InOutPICLKB						1U							// 0b01		0b10
#define GMUX_GPIO026_InSD2_D2							1U							// 0b01		0b11

#define GMUX_GPIO025_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO025_OutOUTPUTXBAR2						0U							// 0b00		0b01
#define GMUX_GPIO025_InEQEP2B							0U							// 0b00		0b10
#define GMUX_GPIO025_InMDRB								0U							// 0b00		0b11
#define GMUX_GPIO025_InOutSPISOMIB						1U							// 0b01		0b10
#define GMUX_GPIO025_InSD2_C1							1U							// 0b01		0b11

#define GMUX_GPIO024_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO024_OutOUTPUTXBAR1						0U							// 0b00		0b01
#define GMUX_GPIO024_InEQEP2A							0U							// 0b00		0b10
#define GMUX_GPIO024_OutMDXB							0U							// 0b00		0b11
#define GMUX_GPIO024_InOutSPISIMOB						1U							// 0b01		0b10
#define GMUX_GPIO024_InSD2_D1							1U							// 0b01		0b11

#define GMUX_GPIO023_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO023_InOutEQEP1I						0U							// 0b00		0b01
#define GMUX_GPIO023_InOutMFSXA							0U							// 0b00		0b10
#define GMUX_GPIO023_InSCITXDB							0U							// 0b00		0b11
#define GMUX_GPIO023_OutEPWM12B							1U							// 0b01		0b01
#define GMUX_GPIO023_InOutnSPISTEB						1U							// 0b01		0b10
#define GMUX_GPIO023_InSD1_C4							1U							// 0b01		0b11

#define GMUX_GPIO022_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO022_InOutEQEP1S						0U							// 0b00		0b01
#define GMUX_GPIO022_InOutMCLKXA						0U							// 0b00		0b10
#define GMUX_GPIO022_OutSCITXDB							0U							// 0b00		0b11
#define GMUX_GPIO022_OutEPWM12A							1U							// 0b01		0b01
#define GMUX_GPIO022_InOutSPICLKB						1U							// 0b01		0b10
#define GMUX_GPIO022_InSD1_D4							1U							// 0b01		0b11

#define GMUX_GPIO021_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO021_InEQEP1B							0U							// 0b00		0b01
#define GMUX_GPIO021_InMDRA								0U							// 0b00		0b10
#define GMUX_GPIO021_InCANRXB							0U							// 0b00		0b11
#define GMUX_GPIO021_OutEPWM11B							1U							// 0b01		0b01
#define GMUX_GPIO021_InSD1_C3							1U							// 0b01		0b11
#define GMUX_GPIO021_InOutUPP_CLK						3U							// 0b11		0b11

#define GMUX_GPIO020_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO020_InEQEP1A							0U							// 0b00		0b01
#define GMUX_GPIO020_OutMDXA							0U							// 0b00		0b10
#define GMUX_GPIO020_OutCANTXB							0U							// 0b00		0b11
#define GMUX_GPIO020_OutEPWM11A							1U							// 0b01		0b01
#define GMUX_GPIO020_InSD1_D3							1U							// 0b01		0b11
#define GMUX_GPIO020_InOutUPP_D0						3U							// 0b11		0b11

#define GMUX_GPIO019_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO019_InOutnSPISTEA						0U							// 0b00		0b01
#define GMUX_GPIO019_InSCIRXDB							0U							// 0b00		0b10
#define GMUX_GPIO019_OutCANTXA							0U							// 0b00		0b11
#define GMUX_GPIO019_OutEPWM10B							1U							// 0b01		0b01
#define GMUX_GPIO019_InSD1_C2							1U							// 0b01		0b11
#define GMUX_GPIO019_InOutUPP_D1						3U							// 0b11		0b11

#define GMUX_GPIO018_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO018_InOutSPICLKA						0U							// 0b00		0b01
#define GMUX_GPIO018_OutSCITXDB							0U							// 0b00		0b10
#define GMUX_GPIO018_InCANRXA							0U							// 0b00		0b11
#define GMUX_GPIO018_OutEPWM10A							1U							// 0b01		0b01
#define GMUX_GPIO018_InSD1_D2							1U							// 0b01		0b11
#define GMUX_GPIO018_InOutUPP_D2						3U							// 0b11		0b11

#define GMUX_GPIO017_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO017_InOutSPISOMIA						0U							// 0b00		0b01
#define GMUX_GPIO017_InCANTXB							0U							// 0b00		0b10
#define GMUX_GPIO017_OutOUTPUTXBAR8						0U							// 0b00		0b11
#define GMUX_GPIO017_OutEPWM9B							1U							// 0b01		0b01
#define GMUX_GPIO017_InSD1_C1							1U							// 0b01		0b11
#define GMUX_GPIO017_InOutUPP_D3						3U							// 0b11		0b11

#define GMUX_GPIO016_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO016_InOutSPISIMOA						0U							// 0b00		0b01
#define GMUX_GPIO016_OutCANTXB							0U							// 0b00		0b10
#define GMUX_GPIO016_OutOUTPUTXBAR7						0U							// 0b00		0b11
#define GMUX_GPIO016_OutEPWM9A							1U							// 0b01		0b01
#define GMUX_GPIO016_InSD1_D1							1U							// 0b01		0b11
#define GMUX_GPIO016_InOutUPP_D4						3U							// 0b11		0b11
#endif

struct GPACSEL1_BITS {                  // bits description
    Uint16 GPIO0:4;                     // 3:0 GPIO0 Master CPU Select
    Uint16 GPIO1:4;                     // 7:4 GPIO1 Master CPU Select
    Uint16 GPIO2:4;                     // 11:8 GPIO2 Master CPU Select
    Uint16 GPIO3:4;                     // 15:12 GPIO3 Master CPU Select
    Uint16 GPIO4:4;                     // 19:16 GPIO4 Master CPU Select
    Uint16 GPIO5:4;                     // 23:20 GPIO5 Master CPU Select
    Uint16 GPIO6:4;                     // 27:24 GPIO6 Master CPU Select
    Uint16 GPIO7:4;                     // 31:28 GPIO7 Master CPU Select
};

union GPACSEL1_REG {
    Uint32  all;
    struct  GPACSEL1_BITS  bit;
};

#ifdef CPU1
// GPACSEL1 Register
//// GPACSEL1 Register : Byte Value
#define GPACSEL1_GPIO007_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO007_CPU1_CLA1Host					0x10000000UL
#define GPACSEL1_GPIO007_CPU2Host						0x20000000UL
#define GPACSEL1_GPIO007_CPU2_CLA1Host					0x30000000UL

#define GPACSEL1_GPIO006_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO006_CPU1_CLA1Host					0x01000000UL
#define GPACSEL1_GPIO006_CPU2Host						0x02000000UL
#define GPACSEL1_GPIO006_CPU2_CLA1Host					0x03000000UL

#define GPACSEL1_GPIO005_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO005_CPU1_CLA1Host					0x00100000UL
#define GPACSEL1_GPIO005_CPU2Host						0x00200000UL
#define GPACSEL1_GPIO005_CPU2_CLA1Host					0x00300000UL

#define GPACSEL1_GPIO004_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO004_CPU1_CLA1Host					0x00010000UL
#define GPACSEL1_GPIO004_CPU2Host						0x00020000UL
#define GPACSEL1_GPIO004_CPU2_CLA1Host					0x00030000UL

#define GPACSEL1_GPIO003_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO003_CPU1_CLA1Host					0x00001000UL
#define GPACSEL1_GPIO003_CPU2Host						0x00002000UL
#define GPACSEL1_GPIO003_CPU2_CLA1Host					0x00003000UL

#define GPACSEL1_GPIO002_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO002_CPU1_CLA1Host					0x00000100UL
#define GPACSEL1_GPIO002_CPU2Host						0x00000200UL
#define GPACSEL1_GPIO002_CPU2_CLA1Host					0x00000300UL

#define GPACSEL1_GPIO001_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO001_CPU1_CLA1Host					0x00000010UL
#define GPACSEL1_GPIO001_CPU2Host						0x00000020UL
#define GPACSEL1_GPIO001_CPU2_CLA1Host					0x00000030UL

#define GPACSEL1_GPIO000_CPU1Host						0x00000000UL
#define GPACSEL1_GPIO000_CPU1_CLA1Host					0x00000001UL
#define GPACSEL1_GPIO000_CPU2Host						0x00000002UL
#define GPACSEL1_GPIO000_CPU2_CLA1Host					0x00000003UL

//// GPACSEL1 Register : Quick Value
#define GPACSEL1_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPACSEL2_BITS {                  // bits description
    Uint16 GPIO8:4;                     // 3:0 GPIO8 Master CPU Select
    Uint16 GPIO9:4;                     // 7:4 GPIO9 Master CPU Select
    Uint16 GPIO10:4;                    // 11:8 GPIO10 Master CPU Select
    Uint16 GPIO11:4;                    // 15:12 GPIO11 Master CPU Select
    Uint16 GPIO12:4;                    // 19:16 GPIO12 Master CPU Select
    Uint16 GPIO13:4;                    // 23:20 GPIO13 Master CPU Select
    Uint16 GPIO14:4;                    // 27:24 GPIO14 Master CPU Select
    Uint16 GPIO15:4;                    // 31:28 GPIO15 Master CPU Select
};

union GPACSEL2_REG {
    Uint32  all;
    struct  GPACSEL2_BITS  bit;
};

#ifdef CPU1
// GPACSEL2 Register
//// GPACSEL2 Register : Byte Value
#define GPACSEL2_GPIO015_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO015_CPU1_CLA1Host					0x10000000UL
#define GPACSEL2_GPIO015_CPU2Host						0x20000000UL
#define GPACSEL2_GPIO015_CPU2_CLA1Host					0x30000000UL

#define GPACSEL2_GPIO014_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO014_CPU1_CLA1Host					0x01000000UL
#define GPACSEL2_GPIO014_CPU2Host						0x02000000UL
#define GPACSEL2_GPIO014_CPU2_CLA1Host					0x03000000UL

#define GPACSEL2_GPIO013_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO013_CPU1_CLA1Host					0x00100000UL
#define GPACSEL2_GPIO013_CPU2Host						0x00200000UL
#define GPACSEL2_GPIO013_CPU2_CLA1Host					0x00300000UL

#define GPACSEL2_GPIO012_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO012_CPU1_CLA1Host					0x00010000UL
#define GPACSEL2_GPIO012_CPU2Host						0x00020000UL
#define GPACSEL2_GPIO012_CPU2_CLA1Host					0x00030000UL

#define GPACSEL2_GPIO011_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO011_CPU1_CLA1Host					0x00001000UL
#define GPACSEL2_GPIO011_CPU2Host						0x00002000UL
#define GPACSEL2_GPIO011_CPU2_CLA1Host					0x00003000UL

#define GPACSEL2_GPIO010_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO010_CPU1_CLA1Host					0x00000100UL
#define GPACSEL2_GPIO010_CPU2Host						0x00000200UL
#define GPACSEL2_GPIO010_CPU2_CLA1Host					0x00000300UL

#define GPACSEL2_GPIO009_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO009_CPU1_CLA1Host					0x00000010UL
#define GPACSEL2_GPIO009_CPU2Host						0x00000020UL
#define GPACSEL2_GPIO009_CPU2_CLA1Host					0x00000030UL

#define GPACSEL2_GPIO008_CPU1Host						0x00000000UL
#define GPACSEL2_GPIO008_CPU1_CLA1Host					0x00000001UL
#define GPACSEL2_GPIO008_CPU2Host						0x00000002UL
#define GPACSEL2_GPIO008_CPU2_CLA1Host					0x00000003UL

//// GPACSEL2 Register : Quick Value
#define GPACSEL2_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPACSEL3_BITS {                  // bits description
    Uint16 GPIO16:4;                    // 3:0 GPIO16 Master CPU Select
    Uint16 GPIO17:4;                    // 7:4 GPIO17 Master CPU Select
    Uint16 GPIO18:4;                    // 11:8 GPIO18 Master CPU Select
    Uint16 GPIO19:4;                    // 15:12 GPIO19 Master CPU Select
    Uint16 GPIO20:4;                    // 19:16 GPIO20 Master CPU Select
    Uint16 GPIO21:4;                    // 23:20 GPIO21 Master CPU Select
    Uint16 GPIO22:4;                    // 27:24 GPIO22 Master CPU Select
    Uint16 GPIO23:4;                    // 31:28 GPIO23 Master CPU Select
};

union GPACSEL3_REG {
    Uint32  all;
    struct  GPACSEL3_BITS  bit;
};

#ifdef CPU1
// GPACSEL3 Register
//// GPACSEL3 Register : Byte Value
#define GPACSEL3_GPIO023_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO023_CPU1_CLA1Host					0x10000000UL
#define GPACSEL3_GPIO023_CPU2Host						0x20000000UL
#define GPACSEL3_GPIO023_CPU2_CLA1Host					0x30000000UL

#define GPACSEL3_GPIO022_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO022_CPU1_CLA1Host					0x01000000UL
#define GPACSEL3_GPIO022_CPU2Host						0x02000000UL
#define GPACSEL3_GPIO022_CPU2_CLA1Host					0x03000000UL

#define GPACSEL3_GPIO021_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO021_CPU1_CLA1Host					0x00100000UL
#define GPACSEL3_GPIO021_CPU2Host						0x00200000UL
#define GPACSEL3_GPIO021_CPU2_CLA1Host					0x00300000UL

#define GPACSEL3_GPIO020_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO020_CPU1_CLA1Host					0x00010000UL
#define GPACSEL3_GPIO020_CPU2Host						0x00020000UL
#define GPACSEL3_GPIO020_CPU2_CLA1Host					0x00030000UL

#define GPACSEL3_GPIO019_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO019_CPU1_CLA1Host					0x00001000UL
#define GPACSEL3_GPIO019_CPU2Host						0x00002000UL
#define GPACSEL3_GPIO019_CPU2_CLA1Host					0x00003000UL

#define GPACSEL3_GPIO018_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO018_CPU1_CLA1Host					0x00000100UL
#define GPACSEL3_GPIO018_CPU2Host						0x00000200UL
#define GPACSEL3_GPIO018_CPU2_CLA1Host					0x00000300UL

#define GPACSEL3_GPIO017_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO017_CPU1_CLA1Host					0x00000010UL
#define GPACSEL3_GPIO017_CPU2Host						0x00000020UL
#define GPACSEL3_GPIO017_CPU2_CLA1Host					0x00000030UL

#define GPACSEL3_GPIO016_CPU1Host						0x00000000UL
#define GPACSEL3_GPIO016_CPU1_CLA1Host					0x00000001UL
#define GPACSEL3_GPIO016_CPU2Host						0x00000002UL
#define GPACSEL3_GPIO016_CPU2_CLA1Host					0x00000003UL

//// GPACSEL3 Register : Quick Value
#define GPACSEL3_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPACSEL4_BITS {                  // bits description
    Uint16 GPIO24:4;                    // 3:0 GPIO24 Master CPU Select
    Uint16 GPIO25:4;                    // 7:4 GPIO25 Master CPU Select
    Uint16 GPIO26:4;                    // 11:8 GPIO26 Master CPU Select
    Uint16 GPIO27:4;                    // 15:12 GPIO27 Master CPU Select
    Uint16 GPIO28:4;                    // 19:16 GPIO28 Master CPU Select
    Uint16 GPIO29:4;                    // 23:20 GPIO29 Master CPU Select
    Uint16 GPIO30:4;                    // 27:24 GPIO30 Master CPU Select
    Uint16 GPIO31:4;                    // 31:28 GPIO31 Master CPU Select
};

union GPACSEL4_REG {
    Uint32  all;
    struct  GPACSEL4_BITS  bit;
};

#ifdef CPU1
// GPACSEL4 Register
//// GPACSEL4 Register : Byte Value
#define GPACSEL4_GPIO031_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO031_CPU1_CLA1Host					0x10000000UL
#define GPACSEL4_GPIO031_CPU2Host						0x20000000UL
#define GPACSEL4_GPIO031_CPU2_CLA1Host					0x30000000UL

#define GPACSEL4_GPIO030_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO030_CPU1_CLA1Host					0x01000000UL
#define GPACSEL4_GPIO030_CPU2Host						0x02000000UL
#define GPACSEL4_GPIO030_CPU2_CLA1Host					0x03000000UL

#define GPACSEL4_GPIO029_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO029_CPU1_CLA1Host					0x00100000UL
#define GPACSEL4_GPIO029_CPU2Host						0x00200000UL
#define GPACSEL4_GPIO029_CPU2_CLA1Host					0x00300000UL

#define GPACSEL4_GPIO028_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO028_CPU1_CLA1Host					0x00010000UL
#define GPACSEL4_GPIO028_CPU2Host						0x00020000UL
#define GPACSEL4_GPIO028_CPU2_CLA1Host					0x00030000UL

#define GPACSEL4_GPIO027_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO027_CPU1_CLA1Host					0x00001000UL
#define GPACSEL4_GPIO027_CPU2Host						0x00002000UL
#define GPACSEL4_GPIO027_CPU2_CLA1Host					0x00003000UL

#define GPACSEL4_GPIO026_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO026_CPU1_CLA1Host					0x00000100UL
#define GPACSEL4_GPIO026_CPU2Host						0x00000200UL
#define GPACSEL4_GPIO026_CPU2_CLA1Host					0x00000300UL

#define GPACSEL4_GPIO025_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO025_CPU1_CLA1Host					0x00000010UL
#define GPACSEL4_GPIO025_CPU2Host						0x00000020UL
#define GPACSEL4_GPIO025_CPU2_CLA1Host					0x00000030UL

#define GPACSEL4_GPIO024_CPU1Host						0x00000000UL
#define GPACSEL4_GPIO024_CPU1_CLA1Host					0x00000001UL
#define GPACSEL4_GPIO024_CPU2Host						0x00000002UL
#define GPACSEL4_GPIO024_CPU2_CLA1Host					0x00000003UL

//// GPACSEL4 Register : Bit Value
#define GPIOxxx_CPU1Host								0U
#define GPIOxxx_CPU1_CLA1Host							1U
#define GPIOxxx_CPU2Host								2U
#define GPIOxxx_CPU2_CLA1Host							3U

//// GPACSEL4 Register : Quick Value
#define GPACSEL4_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPALOCK_BITS {                   // bits description
    Uint16 GPIO0:1;                     // 0 Configuration Lock bit for this pin
    Uint16 GPIO1:1;                     // 1 Configuration Lock bit for this pin
    Uint16 GPIO2:1;                     // 2 Configuration Lock bit for this pin
    Uint16 GPIO3:1;                     // 3 Configuration Lock bit for this pin
    Uint16 GPIO4:1;                     // 4 Configuration Lock bit for this pin
    Uint16 GPIO5:1;                     // 5 Configuration Lock bit for this pin
    Uint16 GPIO6:1;                     // 6 Configuration Lock bit for this pin
    Uint16 GPIO7:1;                     // 7 Configuration Lock bit for this pin
    Uint16 GPIO8:1;                     // 8 Configuration Lock bit for this pin
    Uint16 GPIO9:1;                     // 9 Configuration Lock bit for this pin
    Uint16 GPIO10:1;                    // 10 Configuration Lock bit for this pin
    Uint16 GPIO11:1;                    // 11 Configuration Lock bit for this pin
    Uint16 GPIO12:1;                    // 12 Configuration Lock bit for this pin
    Uint16 GPIO13:1;                    // 13 Configuration Lock bit for this pin
    Uint16 GPIO14:1;                    // 14 Configuration Lock bit for this pin
    Uint16 GPIO15:1;                    // 15 Configuration Lock bit for this pin
    Uint16 GPIO16:1;                    // 16 Configuration Lock bit for this pin
    Uint16 GPIO17:1;                    // 17 Configuration Lock bit for this pin
    Uint16 GPIO18:1;                    // 18 Configuration Lock bit for this pin
    Uint16 GPIO19:1;                    // 19 Configuration Lock bit for this pin
    Uint16 GPIO20:1;                    // 20 Configuration Lock bit for this pin
    Uint16 GPIO21:1;                    // 21 Configuration Lock bit for this pin
    Uint16 GPIO22:1;                    // 22 Configuration Lock bit for this pin
    Uint16 GPIO23:1;                    // 23 Configuration Lock bit for this pin
    Uint16 GPIO24:1;                    // 24 Configuration Lock bit for this pin
    Uint16 GPIO25:1;                    // 25 Configuration Lock bit for this pin
    Uint16 GPIO26:1;                    // 26 Configuration Lock bit for this pin
    Uint16 GPIO27:1;                    // 27 Configuration Lock bit for this pin
    Uint16 GPIO28:1;                    // 28 Configuration Lock bit for this pin
    Uint16 GPIO29:1;                    // 29 Configuration Lock bit for this pin
    Uint16 GPIO30:1;                    // 30 Configuration Lock bit for this pin
    Uint16 GPIO31:1;                    // 31 Configuration Lock bit for this pin
};

union GPALOCK_REG {
    Uint32  all;
    struct  GPALOCK_BITS  bit;
};

struct GPACR_BITS {                     // bits description
    Uint16 GPIO0:1;                     // 0 Configuration lock commit bit for this pin
    Uint16 GPIO1:1;                     // 1 Configuration lock commit bit for this pin
    Uint16 GPIO2:1;                     // 2 Configuration lock commit bit for this pin
    Uint16 GPIO3:1;                     // 3 Configuration lock commit bit for this pin
    Uint16 GPIO4:1;                     // 4 Configuration lock commit bit for this pin
    Uint16 GPIO5:1;                     // 5 Configuration lock commit bit for this pin
    Uint16 GPIO6:1;                     // 6 Configuration lock commit bit for this pin
    Uint16 GPIO7:1;                     // 7 Configuration lock commit bit for this pin
    Uint16 GPIO8:1;                     // 8 Configuration lock commit bit for this pin
    Uint16 GPIO9:1;                     // 9 Configuration lock commit bit for this pin
    Uint16 GPIO10:1;                    // 10 Configuration lock commit bit for this pin
    Uint16 GPIO11:1;                    // 11 Configuration lock commit bit for this pin
    Uint16 GPIO12:1;                    // 12 Configuration lock commit bit for this pin
    Uint16 GPIO13:1;                    // 13 Configuration lock commit bit for this pin
    Uint16 GPIO14:1;                    // 14 Configuration lock commit bit for this pin
    Uint16 GPIO15:1;                    // 15 Configuration lock commit bit for this pin
    Uint16 GPIO16:1;                    // 16 Configuration lock commit bit for this pin
    Uint16 GPIO17:1;                    // 17 Configuration lock commit bit for this pin
    Uint16 GPIO18:1;                    // 18 Configuration lock commit bit for this pin
    Uint16 GPIO19:1;                    // 19 Configuration lock commit bit for this pin
    Uint16 GPIO20:1;                    // 20 Configuration lock commit bit for this pin
    Uint16 GPIO21:1;                    // 21 Configuration lock commit bit for this pin
    Uint16 GPIO22:1;                    // 22 Configuration lock commit bit for this pin
    Uint16 GPIO23:1;                    // 23 Configuration lock commit bit for this pin
    Uint16 GPIO24:1;                    // 24 Configuration lock commit bit for this pin
    Uint16 GPIO25:1;                    // 25 Configuration lock commit bit for this pin
    Uint16 GPIO26:1;                    // 26 Configuration lock commit bit for this pin
    Uint16 GPIO27:1;                    // 27 Configuration lock commit bit for this pin
    Uint16 GPIO28:1;                    // 28 Configuration lock commit bit for this pin
    Uint16 GPIO29:1;                    // 29 Configuration lock commit bit for this pin
    Uint16 GPIO30:1;                    // 30 Configuration lock commit bit for this pin
    Uint16 GPIO31:1;                    // 31 Configuration lock commit bit for this pin
};

union GPACR_REG {
    Uint32  all;
    struct  GPACR_BITS  bit;
};

struct GPBCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO32 to GPIO39
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO40 to GPIO47
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO48 to GPIO55
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO56 to GPIO63
};

union GPBCTRL_REG {
    Uint32  all;
    struct  GPBCTRL_BITS  bit;
};

#ifdef CPU1
// GPBCTRL Register
//// GPBCTRL Register : Byte Value
#define GPBCTRL_QUALPRD3_GPIO063to056_Value(val)		(((Uint32)val & 0x000000FFUL) << 24)
#define GPBCTRL_QUALPRD2_GPIO055to048_Value(val)		(((Uint32)val & 0x000000FFUL) << 16)
#define GPBCTRL_QUALPRD1_GPIO047to040_Value(val)		(((Uint32)val & 0x000000FFUL) << 8)
#define GPBCTRL_QUALPRD0_GPIO039to032_Value(val)		((Uint32)val & 0x000000FFUL)
#endif

struct GPBQSEL1_BITS {                  // bits description
    Uint16 GPIO32:2;                    // 1:0 Select input qualification type for GPIO32
    Uint16 GPIO33:2;                    // 3:2 Select input qualification type for GPIO33
    Uint16 GPIO34:2;                    // 5:4 Select input qualification type for GPIO34
    Uint16 GPIO35:2;                    // 7:6 Select input qualification type for GPIO35
    Uint16 GPIO36:2;                    // 9:8 Select input qualification type for GPIO36
    Uint16 GPIO37:2;                    // 11:10 Select input qualification type for GPIO37
    Uint16 GPIO38:2;                    // 13:12 Select input qualification type for GPIO38
    Uint16 GPIO39:2;                    // 15:14 Select input qualification type for GPIO39
    Uint16 GPIO40:2;                    // 17:16 Select input qualification type for GPIO40
    Uint16 GPIO41:2;                    // 19:18 Select input qualification type for GPIO41
    Uint16 GPIO42:2;                    // 21:20 Select input qualification type for GPIO42
    Uint16 GPIO43:2;                    // 23:22 Select input qualification type for GPIO43
    Uint16 GPIO44:2;                    // 25:24 Select input qualification type for GPIO44
    Uint16 GPIO45:2;                    // 27:26 Select input qualification type for GPIO45
    Uint16 GPIO46:2;                    // 29:28 Select input qualification type for GPIO46
    Uint16 GPIO47:2;                    // 31:30 Select input qualification type for GPIO47
};

union GPBQSEL1_REG {
    Uint32  all;
    struct  GPBQSEL1_BITS  bit;
};

#ifdef CPU1
// GPBQSEL1 Register
//// GPBQSEL1 Register : Byte Value
#define GPBQSEL1_GPIO047_Synch							0x00000000UL
#define GPBQSEL1_GPIO047_3SampSynch						0x40000000UL
#define GPBQSEL1_GPIO047_6SampSynch						0x80000000UL
#define GPBQSEL1_GPIO047_Asynch							0xC0000000UL

#define GPBQSEL1_GPIO046_Synch							0x00000000UL
#define GPBQSEL1_GPIO046_3SampSynch						0x10000000UL
#define GPBQSEL1_GPIO046_6SampSynch						0x20000000UL
#define GPBQSEL1_GPIO046_Asynch							0x30000000UL

#define GPBQSEL1_GPIO045_Synch							0x00000000UL
#define GPBQSEL1_GPIO045_3SampSynch						0x04000000UL
#define GPBQSEL1_GPIO045_6SampSynch						0x08000000UL
#define GPBQSEL1_GPIO045_Asynch							0x0C000000UL

#define GPBQSEL1_GPIO044_Synch							0x00000000UL
#define GPBQSEL1_GPIO044_3SampSynch						0x01000000UL
#define GPBQSEL1_GPIO044_6SampSynch						0x02000000UL
#define GPBQSEL1_GPIO044_Asynch							0x03000000UL

#define GPBQSEL1_GPIO043_Synch							0x00000000UL
#define GPBQSEL1_GPIO043_3SampSynch						0x00400000UL
#define GPBQSEL1_GPIO043_6SampSynch						0x00800000UL
#define GPBQSEL1_GPIO043_Asynch							0x00C00000UL

#define GPBQSEL1_GPIO042_Synch							0x00000000UL
#define GPBQSEL1_GPIO042_3SampSynch						0x00100000UL
#define GPBQSEL1_GPIO042_6SampSynch						0x00200000UL
#define GPBQSEL1_GPIO042_Asynch							0x00300000UL

#define GPBQSEL1_GPIO041_Synch							0x00000000UL
#define GPBQSEL1_GPIO041_3SampSynch						0x00040000UL
#define GPBQSEL1_GPIO041_6SampSynch						0x00080000UL
#define GPBQSEL1_GPIO041_Asynch							0x000C0000UL

#define GPBQSEL1_GPIO040_Synch							0x00000000UL
#define GPBQSEL1_GPIO040_3SampSynch						0x00010000UL
#define GPBQSEL1_GPIO040_6SampSynch						0x00020000UL
#define GPBQSEL1_GPIO040_Asynch							0x00030000UL

#define GPBQSEL1_GPIO039_Synch							0x00000000UL
#define GPBQSEL1_GPIO039_3SampSynch						0x00004000UL
#define GPBQSEL1_GPIO039_6SampSynch						0x00008000UL
#define GPBQSEL1_GPIO039_Asynch							0x0000C000UL

#define GPBQSEL1_GPIO038_Synch							0x00000000UL
#define GPBQSEL1_GPIO038_3SampSynch						0x00001000UL
#define GPBQSEL1_GPIO038_6SampSynch						0x00002000UL
#define GPBQSEL1_GPIO038_Asynch							0x00003000UL

#define GPBQSEL1_GPIO037_Synch							0x00000000UL
#define GPBQSEL1_GPIO037_3SampSynch						0x00000400UL
#define GPBQSEL1_GPIO037_6SampSynch						0x00000800UL
#define GPBQSEL1_GPIO037_Asynch							0x00000C00UL

#define GPBQSEL1_GPIO036_Synch							0x00000000UL
#define GPBQSEL1_GPIO036_3SampSynch						0x00000100UL
#define GPBQSEL1_GPIO036_6SampSynch						0x00000200UL
#define GPBQSEL1_GPIO036_Asynch							0x00000300UL

#define GPBQSEL1_GPIO035_Synch							0x00000000UL
#define GPBQSEL1_GPIO035_3SampSynch						0x00000040UL
#define GPBQSEL1_GPIO035_6SampSynch						0x00000080UL
#define GPBQSEL1_GPIO035_Asynch							0x000000C0UL

#define GPBQSEL1_GPIO034_Synch							0x00000000UL
#define GPBQSEL1_GPIO034_3SampSynch						0x00000010UL
#define GPBQSEL1_GPIO034_6SampSynch						0x00000020UL
#define GPBQSEL1_GPIO034_Asynch							0x00000030UL

#define GPBQSEL1_GPIO033_Synch							0x00000000UL
#define GPBQSEL1_GPIO033_3SampSynch						0x00000004UL
#define GPBQSEL1_GPIO033_6SampSynch						0x00000008UL
#define GPBQSEL1_GPIO033_Asynch							0x0000000CUL

#define GPBQSEL1_GPIO032_Synch							0x00000000UL
#define GPBQSEL1_GPIO032_3SampSynch						0x00000001UL
#define GPBQSEL1_GPIO032_6SampSynch						0x00000002UL
#define GPBQSEL1_GPIO032_Asynch							0x00000003UL
#endif

struct GPBQSEL2_BITS {                  // bits description
    Uint16 GPIO48:2;                    // 1:0 Select input qualification type for GPIO48
    Uint16 GPIO49:2;                    // 3:2 Select input qualification type for GPIO49
    Uint16 GPIO50:2;                    // 5:4 Select input qualification type for GPIO50
    Uint16 GPIO51:2;                    // 7:6 Select input qualification type for GPIO51
    Uint16 GPIO52:2;                    // 9:8 Select input qualification type for GPIO52
    Uint16 GPIO53:2;                    // 11:10 Select input qualification type for GPIO53
    Uint16 GPIO54:2;                    // 13:12 Select input qualification type for GPIO54
    Uint16 GPIO55:2;                    // 15:14 Select input qualification type for GPIO55
    Uint16 GPIO56:2;                    // 17:16 Select input qualification type for GPIO56
    Uint16 GPIO57:2;                    // 19:18 Select input qualification type for GPIO57
    Uint16 GPIO58:2;                    // 21:20 Select input qualification type for GPIO58
    Uint16 GPIO59:2;                    // 23:22 Select input qualification type for GPIO59
    Uint16 GPIO60:2;                    // 25:24 Select input qualification type for GPIO60
    Uint16 GPIO61:2;                    // 27:26 Select input qualification type for GPIO61
    Uint16 GPIO62:2;                    // 29:28 Select input qualification type for GPIO62
    Uint16 GPIO63:2;                    // 31:30 Select input qualification type for GPIO63
};

union GPBQSEL2_REG {
    Uint32  all;
    struct  GPBQSEL2_BITS  bit;
};

#ifdef CPU1
// GPBQSEL2 Register
//// GPBQSEL2 Register : Byte Value
#define GPBQSEL2_GPIO063_Synch							0x00000000UL
#define GPBQSEL2_GPIO063_3SampSynch						0x40000000UL
#define GPBQSEL2_GPIO063_6SampSynch						0x80000000UL
#define GPBQSEL2_GPIO063_Asynch							0xC0000000UL

#define GPBQSEL2_GPIO062_Synch							0x00000000UL
#define GPBQSEL2_GPIO062_3SampSynch						0x10000000UL
#define GPBQSEL2_GPIO062_6SampSynch						0x20000000UL
#define GPBQSEL2_GPIO062_Asynch							0x30000000UL

#define GPBQSEL2_GPIO061_Synch							0x00000000UL
#define GPBQSEL2_GPIO061_3SampSynch						0x04000000UL
#define GPBQSEL2_GPIO061_6SampSynch						0x08000000UL
#define GPBQSEL2_GPIO061_Asynch							0x0C000000UL

#define GPBQSEL2_GPIO060_Synch							0x00000000UL
#define GPBQSEL2_GPIO060_3SampSynch						0x01000000UL
#define GPBQSEL2_GPIO060_6SampSynch						0x02000000UL
#define GPBQSEL2_GPIO060_Asynch							0x03000000UL

#define GPBQSEL2_GPIO059_Synch							0x00000000UL
#define GPBQSEL2_GPIO059_3SampSynch						0x00400000UL
#define GPBQSEL2_GPIO059_6SampSynch						0x00800000UL
#define GPBQSEL2_GPIO059_Asynch							0x00C00000UL

#define GPBQSEL2_GPIO058_Synch							0x00000000UL
#define GPBQSEL2_GPIO058_3SampSynch						0x00100000UL
#define GPBQSEL2_GPIO058_6SampSynch						0x00200000UL
#define GPBQSEL2_GPIO058_Asynch							0x00300000UL

#define GPBQSEL2_GPIO057_Synch							0x00000000UL
#define GPBQSEL2_GPIO057_3SampSynch						0x00040000UL
#define GPBQSEL2_GPIO057_6SampSynch						0x00080000UL
#define GPBQSEL2_GPIO057_Asynch							0x000C0000UL

#define GPBQSEL2_GPIO056_Synch							0x00000000UL
#define GPBQSEL2_GPIO056_3SampSynch						0x00010000UL
#define GPBQSEL2_GPIO056_6SampSynch						0x00020000UL
#define GPBQSEL2_GPIO056_Asynch							0x00030000UL

#define GPBQSEL2_GPIO055_Synch							0x00000000UL
#define GPBQSEL2_GPIO055_3SampSynch						0x00004000UL
#define GPBQSEL2_GPIO055_6SampSynch						0x00008000UL
#define GPBQSEL2_GPIO055_Asynch							0x0000C000UL

#define GPBQSEL2_GPIO054_Synch							0x00000000UL
#define GPBQSEL2_GPIO054_3SampSynch						0x00001000UL
#define GPBQSEL2_GPIO054_6SampSynch						0x00002000UL
#define GPBQSEL2_GPIO054_Asynch							0x00003000UL

#define GPBQSEL2_GPIO053_Synch							0x00000000UL
#define GPBQSEL2_GPIO053_3SampSynch						0x00000400UL
#define GPBQSEL2_GPIO053_6SampSynch						0x00000800UL
#define GPBQSEL2_GPIO053_Asynch							0x00000C00UL

#define GPBQSEL2_GPIO052_Synch							0x00000000UL
#define GPBQSEL2_GPIO052_3SampSynch						0x00000100UL
#define GPBQSEL2_GPIO052_6SampSynch						0x00000200UL
#define GPBQSEL2_GPIO052_Asynch							0x00000300UL

#define GPBQSEL2_GPIO051_Synch							0x00000000UL
#define GPBQSEL2_GPIO051_3SampSynch						0x00000040UL
#define GPBQSEL2_GPIO051_6SampSynch						0x00000080UL
#define GPBQSEL2_GPIO051_Asynch							0x000000C0UL

#define GPBQSEL2_GPIO050_Synch							0x00000000UL
#define GPBQSEL2_GPIO050_3SampSynch						0x00000010UL
#define GPBQSEL2_GPIO050_6SampSynch						0x00000020UL
#define GPBQSEL2_GPIO050_Asynch							0x00000030UL

#define GPBQSEL2_GPIO049_Synch							0x00000000UL
#define GPBQSEL2_GPIO049_3SampSynch						0x00000004UL
#define GPBQSEL2_GPIO049_6SampSynch						0x00000008UL
#define GPBQSEL2_GPIO049_Asynch							0x0000000CUL

#define GPBQSEL2_GPIO048_Synch							0x00000000UL
#define GPBQSEL2_GPIO048_3SampSynch						0x00000001UL
#define GPBQSEL2_GPIO048_6SampSynch						0x00000002UL
#define GPBQSEL2_GPIO048_Asynch							0x00000003UL
#endif

struct GPBMUX1_BITS {                   // bits description
    Uint16 GPIO32:2;                    // 1:0 Defines pin-muxing selection for GPIO32
    Uint16 GPIO33:2;                    // 3:2 Defines pin-muxing selection for GPIO33
    Uint16 GPIO34:2;                    // 5:4 Defines pin-muxing selection for GPIO34
    Uint16 GPIO35:2;                    // 7:6 Defines pin-muxing selection for GPIO35
    Uint16 GPIO36:2;                    // 9:8 Defines pin-muxing selection for GPIO36
    Uint16 GPIO37:2;                    // 11:10 Defines pin-muxing selection for GPIO37
    Uint16 GPIO38:2;                    // 13:12 Defines pin-muxing selection for GPIO38
    Uint16 GPIO39:2;                    // 15:14 Defines pin-muxing selection for GPIO39
    Uint16 GPIO40:2;                    // 17:16 Defines pin-muxing selection for GPIO40
    Uint16 GPIO41:2;                    // 19:18 Defines pin-muxing selection for GPIO41
    Uint16 GPIO42:2;                    // 21:20 Defines pin-muxing selection for GPIO42
    Uint16 GPIO43:2;                    // 23:22 Defines pin-muxing selection for GPIO43
    Uint16 GPIO44:2;                    // 25:24 Defines pin-muxing selection for GPIO44
    Uint16 GPIO45:2;                    // 27:26 Defines pin-muxing selection for GPIO45
    Uint16 GPIO46:2;                    // 29:28 Defines pin-muxing selection for GPIO46
    Uint16 GPIO47:2;                    // 31:30 Defines pin-muxing selection for GPIO47
};

union GPBMUX1_REG {
    Uint32  all;
    struct  GPBMUX1_BITS  bit;
};

#ifdef CPU1
// GPBMUX1 Register
//// GPBMUX1 Register : Byte Value													// GMUX		MUX
#define GPBMUX1_GPIO047_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO047_OutEM1A7						0x80000000UL				// 0b00		0b10
#define GPBMUX1_GPIO047_OutSCITXDD						0x80000000UL				// 0b01		0b10

#define GPBMUX1_GPIO046_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO046_OutEM1A6						0x20000000UL				// 0b00		0b10
#define GPBMUX1_GPIO046_InSCIRXDD						0x20000000UL				// 0b01		0b10

#define GPBMUX1_GPIO045_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO045_OutEM1A5						0x08000000UL				// 0b00		0b10

#define GPBMUX1_GPIO044_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO044_OutEM1A4						0x02000000UL				// 0b00		0b10

#define GPBMUX1_GPIO043_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO043_InODSCLA						0x00800000UL				// 0b01		0b10
#define GPBMUX1_GPIO043_InSCIRXDA						0x00C00000UL				// 0b11		0b11

#define GPBMUX1_GPIO042_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO042_InODSDAA						0x00200000UL				// 0b01		0b10
#define GPBMUX1_GPIO042_OutSCITXDA						0x00300000UL				// 0b11		0b11

#define GPBMUX1_GPIO041_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO041_OutEM1A3						0x00080000UL				// 0b00		0b10
#define GPBMUX1_GPIO041_InODSCLB						0x00080000UL				// 0b01		0b10

#define GPBMUX1_GPIO040_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO040_OutEM1A2						0x00020000UL				// 0b00		0b10
#define GPBMUX1_GPIO040_InODSDAB						0x00020000UL				// 0b01		0b10

#define GPBMUX1_GPIO039_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO039_OutEM1A1						0x00008000UL				// 0b00		0b10
#define GPBMUX1_GPIO039_InSCIRXDC						0x00004000UL				// 0b01		0b01
#define GPBMUX1_GPIO039_InCANRXB						0x00008000UL				// 0b01		0b10

#define GPBMUX1_GPIO038_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO038_OutEM1A0						0x00002000UL				// 0b00		0b10
#define GPBMUX1_GPIO038_OutSCITXDC						0x00001000UL				// 0b01		0b01
#define GPBMUX1_GPIO038_OutCANTXB						0x00002000UL				// 0b01		0b10

#define GPBMUX1_GPIO037_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO037_OutOUTPUTXBAR2					0x00000400UL				// 0b00		0b01
#define GPBMUX1_GPIO037_OutnEM1OE						0x00000800UL				// 0b00		0b10
#define GPBMUX1_GPIO037_OutCANTXA						0x00000800UL				// 0b01		0b10

#define GPBMUX1_GPIO036_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO036_OutSCIRXDA						0x00000100UL				// 0b00		0b01
#define GPBMUX1_GPIO036_InEM1WAIT						0x00000200UL				// 0b00		0b10
#define GPBMUX1_GPIO036_InCANRXA						0x00000200UL				// 0b01		0b10

#define GPBMUX1_GPIO035_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO035_InSCIRXDA						0x00000040UL				// 0b00		0b01
#define GPBMUX1_GPIO035_OutnEM1CS3						0x00000080UL				// 0b00		0b10
#define GPBMUX1_GPIO035_InODSCLB						0x00000080UL				// 0b01		0b10

#define GPBMUX1_GPIO034_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO034_OutOUTPUTXBAR1					0x00000010UL				// 0b00		0b01
#define GPBMUX1_GPIO034_OutnEM1CS2						0x00000020UL				// 0b00		0b10
#define GPBMUX1_GPIO034_InODSDAB						0x00000020UL				// 0b01		0b10

#define GPBMUX1_GPIO033_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO033_InODSCLA						0x00000004UL				// 0b00		0b01
#define GPBMUX1_GPIO033_OutEM1RNW						0x00000008UL				// 0b00		0b10

#define GPBMUX1_GPIO032_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX1_GPIO032_InODSDAA						0x00000001UL				// 0b00		0b01
#define GPBMUX1_GPIO032_OutnEM1CS0						0x00000002UL				// 0b00		0b10

//// GPBMUX1 Register : Bit Value													// GMUX		MUX
#define MUX_GPIO047_InOutGPIO							0U							// -		0b00
#define MUX_GPIO047_OutEM1A7							2U							// 0b00		0b10
#define MUX_GPIO047_OutSCITXDD							2U							// 0b01		0b10

#define MUX_GPIO046_InOutGPIO							0U							// -		0b00
#define MUX_GPIO046_OutEM1A6							2U							// 0b00		0b10
#define MUX_GPIO046_InSCIRXDD							2U							// 0b01		0b10

#define MUX_GPIO045_InOutGPIO							0U							// -		0b00
#define MUX_GPIO045_OutEM1A5							2U							// 0b00		0b10

#define MUX_GPIO044_InOutGPIO							0U							// -		0b00
#define MUX_GPIO044_OutEM1A4							2U							// 0b00		0b10

#define MUX_GPIO043_InOutGPIO							0U							// -		0b00
#define MUX_GPIO043_InODSCLA							2U							// 0b01		0b10
#define MUX_GPIO043_InSCIRXDA							3U							// 0b11		0b11

#define MUX_GPIO042_InOutGPIO							0U							// -		0b00
#define MUX_GPIO042_InODSDAA							2U							// 0b01		0b10
#define MUX_GPIO042_OutSCITXDA							3U							// 0b11		0b11

#define MUX_GPIO041_InOutGPIO							0U							// -		0b00
#define MUX_GPIO041_OutEM1A3							2U							// 0b00		0b10
#define MUX_GPIO041_InODSCLB							2U							// 0b01		0b10

#define MUX_GPIO040_InOutGPIO							0U							// -		0b00
#define MUX_GPIO040_OutEM1A2							2U							// 0b00		0b10
#define MUX_GPIO040_InODSDAB							2U							// 0b01		0b10

#define MUX_GPIO039_InOutGPIO							0U							// -		0b00
#define MUX_GPIO039_OutEM1A1							2U							// 0b00		0b10
#define MUX_GPIO039_InSCIRXDC							1U							// 0b01		0b01
#define MUX_GPIO039_InCANRXB							2U							// 0b01		0b10

#define MUX_GPIO038_InOutGPIO							0U							// -		0b00
#define MUX_GPIO038_OutEM1A0							2U							// 0b00		0b10
#define MUX_GPIO038_OutSCITXDC							1U							// 0b01		0b01
#define MUX_GPIO038_OutCANTXB							2U							// 0b01		0b10

#define MUX_GPIO037_InOutGPIO							0U							// -		0b00
#define MUX_GPIO037_OutOUTPUTXBAR2						1U							// 0b00		0b01
#define MUX_GPIO037_OutnEM1OE							2U							// 0b00		0b10
#define MUX_GPIO037_OutCANTXA							2U							// 0b01		0b10

#define MUX_GPIO036_InOutGPIO							0U							// -		0b00
#define MUX_GPIO036_OutSCIRXDA							1U							// 0b00		0b01
#define MUX_GPIO036_InEM1WAIT							2U							// 0b00		0b10
#define MUX_GPIO036_InCANRXA							2U							// 0b01		0b10

#define MUX_GPIO035_InOutGPIO							0U							// -		0b00
#define MUX_GPIO035_InSCIRXDA							1U							// 0b00		0b01
#define MUX_GPIO035_OutnEM1CS3							2U							// 0b00		0b10
#define MUX_GPIO035_InODSCLB							2U							// 0b01		0b10

#define MUX_GPIO034_InOutGPIO							0U							// -		0b00
#define MUX_GPIO034_OutOUTPUTXBAR1						1U							// 0b00		0b01
#define MUX_GPIO034_OutnEM1CS2							2U							// 0b00		0b10
#define MUX_GPIO034_InODSDAB							2U							// 0b01		0b10

#define MUX_GPIO033_InOutGPIO							0U							// -		0b00
#define MUX_GPIO033_InODSCLA							1U							// 0b00		0b01
#define MUX_GPIO033_OutEM1RNW							2U							// 0b00		0b10

#define MUX_GPIO032_InOutGPIO							0U							// -		0b00
#define MUX_GPIO032_InODSDAA							1U							// 0b00		0b01
#define MUX_GPIO032_OutnEM1CS0							2U							// 0b00		0b10
#endif

struct GPBMUX2_BITS {                   // bits description
    Uint16 GPIO48:2;                    // 1:0 Defines pin-muxing selection for GPIO48
    Uint16 GPIO49:2;                    // 3:2 Defines pin-muxing selection for GPIO49
    Uint16 GPIO50:2;                    // 5:4 Defines pin-muxing selection for GPIO50
    Uint16 GPIO51:2;                    // 7:6 Defines pin-muxing selection for GPIO51
    Uint16 GPIO52:2;                    // 9:8 Defines pin-muxing selection for GPIO52
    Uint16 GPIO53:2;                    // 11:10 Defines pin-muxing selection for GPIO53
    Uint16 GPIO54:2;                    // 13:12 Defines pin-muxing selection for GPIO54
    Uint16 GPIO55:2;                    // 15:14 Defines pin-muxing selection for GPIO55
    Uint16 GPIO56:2;                    // 17:16 Defines pin-muxing selection for GPIO56
    Uint16 GPIO57:2;                    // 19:18 Defines pin-muxing selection for GPIO57
    Uint16 GPIO58:2;                    // 21:20 Defines pin-muxing selection for GPIO58
    Uint16 GPIO59:2;                    // 23:22 Defines pin-muxing selection for GPIO59
    Uint16 GPIO60:2;                    // 25:24 Defines pin-muxing selection for GPIO60
    Uint16 GPIO61:2;                    // 27:26 Defines pin-muxing selection for GPIO61
    Uint16 GPIO62:2;                    // 29:28 Defines pin-muxing selection for GPIO62
    Uint16 GPIO63:2;                    // 31:30 Defines pin-muxing selection for GPIO63
};

union GPBMUX2_REG {
    Uint32  all;
    struct  GPBMUX2_BITS  bit;
};

#ifdef CPU1
// GPBMUX2 Register
//// GPBMUX2 Register : Byte Value													// GMUX		MUX
#define GPBMUX2_GPIO063_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO063_OutSCITXDC						0x40000000UL				// 0b00		0b01
#define GPBMUX2_GPIO063_InOutEM1D21						0x80000000UL				// 0b00		0b10
#define GPBMUX2_GPIO063_InOutEM2D5						0xC0000000UL				// 0b00		0b11
#define GPBMUX2_GPIO063_InEQEP3B						0x40000000UL				// 0b01		0b01
#define GPBMUX2_GPIO063_OutCANTXA						0x80000000UL				// 0b01		0b10
#define GPBMUX2_GPIO063_InSD2_C4						0xC0000000UL				// 0b01		0b11
#define GPBMUX2_GPIO063_InOutHSPSPISIMOB				0xC0000000UL				// 0b11		0b11

#define GPBMUX2_GPIO062_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO062_InSCIRXDC						0x10000000UL				// 0b00		0b01
#define GPBMUX2_GPIO062_InOutEM1D22						0x20000000UL				// 0b00		0b10
#define GPBMUX2_GPIO062_InOutEM2D6						0x30000000UL				// 0b00		0b11
#define GPBMUX2_GPIO062_InEQEP3A						0x10000000UL				// 0b01		0b01
#define GPBMUX2_GPIO062_InCANRXA						0x20000000UL				// 0b01		0b10
#define GPBMUX2_GPIO062_InSD2_D4						0x30000000UL				// 0b01		0b11

#define GPBMUX2_GPIO061_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO061_InOutMFSRB						0x04000000UL				// 0b00		0b01
#define GPBMUX2_GPIO061_InOutEM1D23						0x08000000UL				// 0b00		0b10
#define GPBMUX2_GPIO061_InOutEM2D7						0x0C000000UL				// 0b00		0b11
#define GPBMUX2_GPIO061_OutOUTPUTXBAR4					0x04000000UL				// 0b01		0b01
#define GPBMUX2_GPIO061_InOutSPISOMIB					0x08000000UL				// 0b01		0b10
#define GPBMUX2_GPIO061_InSD2_C3						0x0C000000UL				// 0b01		0b11
#define GPBMUX2_GPIO061_InOutHSPnSPISTEA				0x0C000000UL				// 0b11		0b11

#define GPBMUX2_GPIO060_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO060_InOutMCLKRB						0x01000000UL				// 0b00		0b01
#define GPBMUX2_GPIO060_InOutEM1D24						0x02000000UL				// 0b00		0b10
#define GPBMUX2_GPIO060_InOutEM2D8						0x03000000UL				// 0b00		0b11
#define GPBMUX2_GPIO060_OutOUTPUTXBAR3					0x01000000UL				// 0b01		0b01
#define GPBMUX2_GPIO060_InOutSPISIMOB					0x02000000UL				// 0b01		0b10
#define GPBMUX2_GPIO060_InSD2_D3						0x03000000UL				// 0b01		0b11
#define GPBMUX2_GPIO060_InOutHSPSPICLKA					0x03000000UL				// 0b11		0b11

#define GPBMUX2_GPIO059_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO059_InOutMFSRA						0x00400000UL				// 0b00		0b01
#define GPBMUX2_GPIO059_InOutEM1D25						0x00800000UL				// 0b00		0b10
#define GPBMUX2_GPIO059_InOutEM2D9						0x00C00000UL				// 0b00		0b11
#define GPBMUX2_GPIO059_OutOUTPUTXBAR2					0x00400000UL				// 0b01		0b01
#define GPBMUX2_GPIO059_InOutnSPISTEB					0x00800000UL				// 0b01		0b10
#define GPBMUX2_GPIO059_InSD2_C2						0x00C00000UL				// 0b01		0b11
#define GPBMUX2_GPIO059_InOutHSPSPISOMIA				0x00C00000UL				// 0b11		0b11

#define GPBMUX2_GPIO058_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO058_InOutMCLKRA						0x00100000UL				// 0b00		0b01
#define GPBMUX2_GPIO058_InOutEM1D26						0x00200000UL				// 0b00		0b10
#define GPBMUX2_GPIO058_InOutEM2D10						0x00300000UL				// 0b00		0b11
#define GPBMUX2_GPIO058_OutOUTPUTXBAR1					0x00100000UL				// 0b01		0b01
#define GPBMUX2_GPIO058_InOutSPICLKB					0x00200000UL				// 0b01		0b10
#define GPBMUX2_GPIO058_InSD2_D2						0x00300000UL				// 0b01		0b11
#define GPBMUX2_GPIO058_InOutHSPSPISIMOA				0x00300000UL				// 0b11		0b11

#define GPBMUX2_GPIO057_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO057_InOutnSPISTEA					0x00040000UL				// 0b00		0b01
#define GPBMUX2_GPIO057_InOutEM1D27						0x00080000UL				// 0b00		0b10
#define GPBMUX2_GPIO057_InOutEM2D11						0x000C0000UL				// 0b00		0b11
#define GPBMUX2_GPIO057_InOutEQEP2I						0x00040000UL				// 0b01		0b01
#define GPBMUX2_GPIO057_InSCITXDC						0x00080000UL				// 0b01		0b10
#define GPBMUX2_GPIO057_InSD2_C1						0x000C0000UL				// 0b01		0b11

#define GPBMUX2_GPIO056_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO056_InOutSPICLKA					0x00010000UL				// 0b00		0b01
#define GPBMUX2_GPIO056_InOutEM1D28						0x00020000UL				// 0b00		0b10
#define GPBMUX2_GPIO056_InOutEM2D12						0x00030000UL				// 0b00		0b11
#define GPBMUX2_GPIO056_InOutEQEP2S						0x00010000UL				// 0b01		0b01
#define GPBMUX2_GPIO056_OutSCITXDC						0x00020000UL				// 0b01		0b10
#define GPBMUX2_GPIO056_InSD2_D1						0x00030000UL				// 0b01		0b11

#define GPBMUX2_GPIO055_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO055_InOutSPISOMIA					0x00004000UL				// 0b00		0b01
#define GPBMUX2_GPIO055_InOutEM1D29						0x00008000UL				// 0b00		0b10
#define GPBMUX2_GPIO055_InOutEM2D13						0x0000C000UL				// 0b00		0b11
#define GPBMUX2_GPIO055_InEQEP2B						0x00004000UL				// 0b01		0b01
#define GPBMUX2_GPIO055_InSCIRXDB						0x00008000UL				// 0b01		0b10
#define GPBMUX2_GPIO055_InSD1_C4						0x0000C000UL				// 0b01		0b11

#define GPBMUX2_GPIO054_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO054_InOutSPISIMOA					0x00001000UL				// 0b00		0b01
#define GPBMUX2_GPIO054_InOutEM1D30						0x00002000UL				// 0b00		0b10
#define GPBMUX2_GPIO054_InOutEM2D14						0x00003000UL				// 0b00		0b11
#define GPBMUX2_GPIO054_InEQEP2A						0x00001000UL				// 0b01		0b01
#define GPBMUX2_GPIO054_OutSCITXDB						0x00002000UL				// 0b01		0b10
#define GPBMUX2_GPIO054_InSD1_D4						0x00003000UL				// 0b01		0b11

#define GPBMUX2_GPIO053_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO053_InOutEQEP1I						0x00000400UL				// 0b00		0b01
#define GPBMUX2_GPIO053_InOutEM1D31						0x00000800UL				// 0b00		0b10
#define GPBMUX2_GPIO053_InOutEM2D15						0x00000C00UL				// 0b00		0b11
#define GPBMUX2_GPIO053_InOutnSPISTEC					0x00000800UL				// 0b01		0b10
#define GPBMUX2_GPIO053_InSD1_C3						0x00000C00UL				// 0b01		0b11

#define GPBMUX2_GPIO052_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO052_InOutEQEP1S						0x00000100UL				// 0b00		0b01
#define GPBMUX2_GPIO052_OutEM1A12						0x00000200UL				// 0b00		0b10
#define GPBMUX2_GPIO052_InOutSPICLKC					0x00000200UL				// 0b01		0b10
#define GPBMUX2_GPIO052_InSD1_D3						0x00000300UL				// 0b01		0b11

#define GPBMUX2_GPIO051_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO051_InEQEP1B						0x00000040UL				// 0b00		0b01
#define GPBMUX2_GPIO051_OutEM1A11						0x00000080UL				// 0b00		0b10
#define GPBMUX2_GPIO051_InOutSPISOMIC					0x00000080UL				// 0b01		0b10
#define GPBMUX2_GPIO051_InSD1_C2						0x000000C0UL				// 0b01		0b11

#define GPBMUX2_GPIO050_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO050_InEQEP1A						0x00000010UL				// 0b00		0b01
#define GPBMUX2_GPIO050_OutEM1A10						0x00000020UL				// 0b00		0b10
#define GPBMUX2_GPIO050_InOutSPISIMOC					0x00000020UL				// 0b01		0b10
#define GPBMUX2_GPIO050_InSD1_D2						0x00000030UL				// 0b01		0b11

#define GPBMUX2_GPIO049_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO049_OutOUTPUTXBAR4					0x00000004UL				// 0b00		0b01
#define GPBMUX2_GPIO049_OutEM1A9						0x00000008UL				// 0b00		0b10
#define GPBMUX2_GPIO049_InSCIRXDA						0x00000008UL				// 0b01		0b10
#define GPBMUX2_GPIO049_InSD1_C1						0x0000000CUL				// 0b01		0b11

#define GPBMUX2_GPIO048_InOutGPIO						0x00000000UL				// -		0b00
#define GPBMUX2_GPIO048_OutOUTPUTXBAR3					0x00000001UL				// 0b00		0b01
#define GPBMUX2_GPIO048_OutEM1A8						0x00000002UL				// 0b00		0b10
#define GPBMUX2_GPIO048_OutSCITXDA						0x00000002UL				// 0b01		0b10
#define GPBMUX2_GPIO048_InSD1_D1						0x00000003UL				// 0b01		0b11

//// GPBMUX2 Register : Byte Value													// GMUX		MUX
#define MUX_GPIO063_InOutGPIO							0U							// -		0b00
#define MUX_GPIO063_OutSCITXDC							1U							// 0b00		0b01
#define MUX_GPIO063_InOutEM1D21							2U							// 0b00		0b10
#define MUX_GPIO063_InOutEM2D5							3U							// 0b00		0b11
#define MUX_GPIO063_InEQEP3B							1U							// 0b01		0b01
#define MUX_GPIO063_OutCANTXA							2U							// 0b01		0b10
#define MUX_GPIO063_InSD2_C4							3U							// 0b01		0b11
#define MUX_GPIO063_InOutHSPSPISIMOB					3U							// 0b11		0b11

#define MUX_GPIO062_InOutGPIO							0U							// -		0b00
#define MUX_GPIO062_InSCIRXDC							1U							// 0b00		0b01
#define MUX_GPIO062_InOutEM1D22							2U							// 0b00		0b10
#define MUX_GPIO062_InOutEM2D6							3U							// 0b00		0b11
#define MUX_GPIO062_InEQEP3A							1U							// 0b01		0b01
#define MUX_GPIO062_InCANRXA							2U							// 0b01		0b10
#define MUX_GPIO062_InSD2_D4							3U							// 0b01		0b11

#define MUX_GPIO061_InOutGPIO							0U							// -		0b00
#define MUX_GPIO061_InOutMFSRB							1U							// 0b00		0b01
#define MUX_GPIO061_InOutEM1D23							2U							// 0b00		0b10
#define MUX_GPIO061_InOutEM2D7							3U							// 0b00		0b11
#define MUX_GPIO061_OutOUTPUTXBAR4						1U							// 0b01		0b01
#define MUX_GPIO061_InOutSPISOMIB						2U							// 0b01		0b10
#define MUX_GPIO061_InSD2_C3							3U							// 0b01		0b11
#define MUX_GPIO061_InOutHSPnSPISTEA					3U							// 0b11		0b11

#define MUX_GPIO060_InOutGPIO							0U							// -		0b00
#define MUX_GPIO060_InOutMCLKRB							1U							// 0b00		0b01
#define MUX_GPIO060_InOutEM1D24							2U							// 0b00		0b10
#define MUX_GPIO060_InOutEM2D8							3U							// 0b00		0b11
#define MUX_GPIO060_OutOUTPUTXBAR3						1U							// 0b01		0b01
#define MUX_GPIO060_InOutSPISIMOB						2U							// 0b01		0b10
#define MUX_GPIO060_InSD2_D3							3U							// 0b01		0b11
#define MUX_GPIO060_InOutHSPSPICLKA						3U							// 0b11		0b11

#define MUX_GPIO059_InOutGPIO							0U							// -		0b00
#define MUX_GPIO059_InOutMFSRA							1U							// 0b00		0b01
#define MUX_GPIO059_InOutEM1D25							2U							// 0b00		0b10
#define MUX_GPIO059_InOutEM2D9							3U							// 0b00		0b11
#define MUX_GPIO059_OutOUTPUTXBAR2						1U							// 0b01		0b01
#define MUX_GPIO059_InOutnSPISTEB						2U							// 0b01		0b10
#define MUX_GPIO059_InSD2_C2							3U							// 0b01		0b11
#define MUX_GPIO059_InOutHSPSPISOMIA					3U							// 0b11		0b11

#define MUX_GPIO058_InOutGPIO							0U							// -		0b00
#define MUX_GPIO058_InOutMCLKRA							1U							// 0b00		0b01
#define MUX_GPIO058_InOutEM1D26							2U							// 0b00		0b10
#define MUX_GPIO058_InOutEM2D10							3U							// 0b00		0b11
#define MUX_GPIO058_OutOUTPUTXBAR1						1U							// 0b01		0b01
#define MUX_GPIO058_InOutSPICLKB						2U							// 0b01		0b10
#define MUX_GPIO058_InSD2_D2							3U							// 0b01		0b11
#define MUX_GPIO058_InOutHSPSPISIMOA					3U							// 0b11		0b11

#define MUX_GPIO057_InOutGPIO							0U							// -		0b00
#define MUX_GPIO057_InOutnSPISTEA						1U							// 0b00		0b01
#define MUX_GPIO057_InOutEM1D27							2U							// 0b00		0b10
#define MUX_GPIO057_InOutEM2D11							3U							// 0b00		0b11
#define MUX_GPIO057_InOutEQEP2I							1U							// 0b01		0b01
#define MUX_GPIO057_InSCITXDC							2U							// 0b01		0b10
#define MUX_GPIO057_InSD2_C1							3U							// 0b01		0b11

#define MUX_GPIO056_InOutGPIO							0U							// -		0b00
#define MUX_GPIO056_InOutSPICLKA						1U							// 0b00		0b01
#define MUX_GPIO056_InOutEM1D28							2U							// 0b00		0b10
#define MUX_GPIO056_InOutEM2D12							3U							// 0b00		0b11
#define MUX_GPIO056_InOutEQEP2S							1U							// 0b01		0b01
#define MUX_GPIO056_OutSCITXDC							2U							// 0b01		0b10
#define MUX_GPIO056_InSD2_D1							3U							// 0b01		0b11

#define MUX_GPIO055_InOutGPIO							0U							// -		0b00
#define MUX_GPIO055_InOutSPISOMIA						1U							// 0b00		0b01
#define MUX_GPIO055_InOutEM1D29							2U							// 0b00		0b10
#define MUX_GPIO055_InOutEM2D13							3U							// 0b00		0b11
#define MUX_GPIO055_InEQEP2B							1U							// 0b01		0b01
#define MUX_GPIO055_InSCIRXDB							2U							// 0b01		0b10
#define MUX_GPIO055_InSD1_C4							3U							// 0b01		0b11

#define MUX_GPIO054_InOutGPIO							0U							// -		0b00
#define MUX_GPIO054_InOutSPISIMOA						1U							// 0b00		0b01
#define MUX_GPIO054_InOutEM1D30							2U							// 0b00		0b10
#define MUX_GPIO054_InOutEM2D14							3U							// 0b00		0b11
#define MUX_GPIO054_InEQEP2A							1U							// 0b01		0b01
#define MUX_GPIO054_OutSCITXDB							2U							// 0b01		0b10
#define MUX_GPIO054_InSD1_D4							3U							// 0b01		0b11

#define MUX_GPIO053_InOutGPIO							0U							// -		0b00
#define MUX_GPIO053_InOutEQEP1I							1U							// 0b00		0b01
#define MUX_GPIO053_InOutEM1D31							2U							// 0b00		0b10
#define MUX_GPIO053_InOutEM2D15							3U							// 0b00		0b11
#define MUX_GPIO053_InOutnSPISTEC						2U							// 0b01		0b10
#define MUX_GPIO053_InSD1_C3							3U							// 0b01		0b11

#define MUX_GPIO052_InOutGPIO							0U							// -		0b00
#define MUX_GPIO052_InOutEQEP1S							1U							// 0b00		0b01
#define MUX_GPIO052_OutEM1A12							2U							// 0b00		0b10
#define MUX_GPIO052_InOutSPICLKC						2U							// 0b01		0b10
#define MUX_GPIO052_InSD1_D3							3U							// 0b01		0b11

#define MUX_GPIO051_InOutGPIO							0U							// -		0b00
#define MUX_GPIO051_InEQEP1B							1U							// 0b00		0b01
#define MUX_GPIO051_OutEM1A11							2U							// 0b00		0b10
#define MUX_GPIO051_InOutSPISOMIC						2U							// 0b01		0b10
#define MUX_GPIO051_InSD1_C2							3U							// 0b01		0b11

#define MUX_GPIO050_InOutGPIO							0U							// -		0b00
#define MUX_GPIO050_InEQEP1A							1U							// 0b00		0b01
#define MUX_GPIO050_OutEM1A10							2U							// 0b00		0b10
#define MUX_GPIO050_InOutSPISIMOC						2U							// 0b01		0b10
#define MUX_GPIO050_InSD1_D2							3U							// 0b01		0b11

#define MUX_GPIO049_InOutGPIO							0U							// -		0b00
#define MUX_GPIO049_OutOUTPUTXBAR4						1U							// 0b00		0b01
#define MUX_GPIO049_OutEM1A9							2U							// 0b00		0b10
#define MUX_GPIO049_InSCIRXDA							2U							// 0b01		0b10
#define MUX_GPIO049_InSD1_C1							3U							// 0b01		0b11

#define MUX_GPIO048_InOutGPIO							0U							// -		0b00
#define MUX_GPIO048_OutOUTPUTXBAR3						1U							// 0b00		0b01
#define MUX_GPIO048_OutEM1A8							2U							// 0b00		0b10
#define MUX_GPIO048_OutSCITXDA							2U							// 0b01		0b10
#define MUX_GPIO048_InSD1_D1							3U							// 0b01		0b11
#endif

struct GPBDIR_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO33:1;                    // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO34:1;                    // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO35:1;                    // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO36:1;                    // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO37:1;                    // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO38:1;                    // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO39:1;                    // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO40:1;                    // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO41:1;                    // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO42:1;                    // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO43:1;                    // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO44:1;                    // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO45:1;                    // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO46:1;                    // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO47:1;                    // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO48:1;                    // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO49:1;                    // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO50:1;                    // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO51:1;                    // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO52:1;                    // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO53:1;                    // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO54:1;                    // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO55:1;                    // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO56:1;                    // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO57:1;                    // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO58:1;                    // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO59:1;                    // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO60:1;                    // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO61:1;                    // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO62:1;                    // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO63:1;                    // 31 Defines direction for this pin in GPIO mode
};

union GPBDIR_REG {
    Uint32  all;
    struct  GPBDIR_BITS  bit;
};

#ifdef CPU1
// GPBDIR Register
//// GPBDIR Register : Byte Value
#define GPBDIR_GPIO063_Input							0x00000000UL
#define GPBDIR_GPIO063_Output							0x80000000UL

#define GPBDIR_GPIO062_Input							0x00000000UL
#define GPBDIR_GPIO062_Output							0x40000000UL

#define GPBDIR_GPIO061_Input							0x00000000UL
#define GPBDIR_GPIO061_Output							0x20000000UL

#define GPBDIR_GPIO060_Input							0x00000000UL
#define GPBDIR_GPIO060_Output							0x10000000UL

#define GPBDIR_GPIO059_Input							0x00000000UL
#define GPBDIR_GPIO059_Output							0x08000000UL

#define GPBDIR_GPIO058_Input							0x00000000UL
#define GPBDIR_GPIO058_Output							0x04000000UL

#define GPBDIR_GPIO057_Input							0x00000000UL
#define GPBDIR_GPIO057_Output							0x02000000UL

#define GPBDIR_GPIO056_Input							0x00000000UL
#define GPBDIR_GPIO056_Output							0x01000000UL

#define GPBDIR_GPIO055_Input							0x00000000UL
#define GPBDIR_GPIO055_Output							0x00800000UL

#define GPBDIR_GPIO054_Input							0x00000000UL
#define GPBDIR_GPIO054_Output							0x00400000UL

#define GPBDIR_GPIO053_Input							0x00000000UL
#define GPBDIR_GPIO053_Output							0x00200000UL

#define GPBDIR_GPIO052_Input							0x00000000UL
#define GPBDIR_GPIO052_Output							0x00100000UL

#define GPBDIR_GPIO051_Input							0x00000000UL
#define GPBDIR_GPIO051_Output							0x00080000UL

#define GPBDIR_GPIO050_Input							0x00000000UL
#define GPBDIR_GPIO050_Output							0x00040000UL

#define GPBDIR_GPIO049_Input							0x00000000UL
#define GPBDIR_GPIO049_Output							0x00020000UL

#define GPBDIR_GPIO048_Input							0x00000000UL
#define GPBDIR_GPIO048_Output							0x00010000UL

#define GPBDIR_GPIO047_Input							0x00000000UL
#define GPBDIR_GPIO047_Output							0x00008000UL

#define GPBDIR_GPIO046_Input							0x00000000UL
#define GPBDIR_GPIO046_Output							0x00004000UL

#define GPBDIR_GPIO045_Input							0x00000000UL
#define GPBDIR_GPIO045_Output							0x00002000UL

#define GPBDIR_GPIO044_Input							0x00000000UL
#define GPBDIR_GPIO044_Output							0x00001000UL

#define GPBDIR_GPIO043_Input							0x00000000UL
#define GPBDIR_GPIO043_Output							0x00000800UL

#define GPBDIR_GPIO042_Input							0x00000000UL
#define GPBDIR_GPIO042_Output							0x00000400UL

#define GPBDIR_GPIO041_Input							0x00000000UL
#define GPBDIR_GPIO041_Output							0x00000200UL

#define GPBDIR_GPIO040_Input							0x00000000UL
#define GPBDIR_GPIO040_Output							0x00000100UL

#define GPBDIR_GPIO039_Input							0x00000000UL
#define GPBDIR_GPIO039_Output							0x00000080UL

#define GPBDIR_GPIO038_Input							0x00000000UL
#define GPBDIR_GPIO038_Output							0x00000040UL

#define GPBDIR_GPIO037_Input							0x00000000UL
#define GPBDIR_GPIO037_Output							0x00000020UL

#define GPBDIR_GPIO036_Input							0x00000000UL
#define GPBDIR_GPIO036_Output							0x00000010UL

#define GPBDIR_GPIO035_Input							0x00000000UL
#define GPBDIR_GPIO035_Output							0x00000008UL

#define GPBDIR_GPIO034_Input							0x00000000UL
#define GPBDIR_GPIO034_Output							0x00000004UL

#define GPBDIR_GPIO033_Input							0x00000000UL
#define GPBDIR_GPIO033_Output							0x00000002UL

#define GPBDIR_GPIO032_Input							0x00000000UL
#define GPBDIR_GPIO032_Output							0x00000001UL
#endif

struct GPBPUD_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Pull-Up Disable control for this pin
    Uint16 GPIO33:1;                    // 1 Pull-Up Disable control for this pin
    Uint16 GPIO34:1;                    // 2 Pull-Up Disable control for this pin
    Uint16 GPIO35:1;                    // 3 Pull-Up Disable control for this pin
    Uint16 GPIO36:1;                    // 4 Pull-Up Disable control for this pin
    Uint16 GPIO37:1;                    // 5 Pull-Up Disable control for this pin
    Uint16 GPIO38:1;                    // 6 Pull-Up Disable control for this pin
    Uint16 GPIO39:1;                    // 7 Pull-Up Disable control for this pin
    Uint16 GPIO40:1;                    // 8 Pull-Up Disable control for this pin
    Uint16 GPIO41:1;                    // 9 Pull-Up Disable control for this pin
    Uint16 GPIO42:1;                    // 10 Pull-Up Disable control for this pin
    Uint16 GPIO43:1;                    // 11 Pull-Up Disable control for this pin
    Uint16 GPIO44:1;                    // 12 Pull-Up Disable control for this pin
    Uint16 GPIO45:1;                    // 13 Pull-Up Disable control for this pin
    Uint16 GPIO46:1;                    // 14 Pull-Up Disable control for this pin
    Uint16 GPIO47:1;                    // 15 Pull-Up Disable control for this pin
    Uint16 GPIO48:1;                    // 16 Pull-Up Disable control for this pin
    Uint16 GPIO49:1;                    // 17 Pull-Up Disable control for this pin
    Uint16 GPIO50:1;                    // 18 Pull-Up Disable control for this pin
    Uint16 GPIO51:1;                    // 19 Pull-Up Disable control for this pin
    Uint16 GPIO52:1;                    // 20 Pull-Up Disable control for this pin
    Uint16 GPIO53:1;                    // 21 Pull-Up Disable control for this pin
    Uint16 GPIO54:1;                    // 22 Pull-Up Disable control for this pin
    Uint16 GPIO55:1;                    // 23 Pull-Up Disable control for this pin
    Uint16 GPIO56:1;                    // 24 Pull-Up Disable control for this pin
    Uint16 GPIO57:1;                    // 25 Pull-Up Disable control for this pin
    Uint16 GPIO58:1;                    // 26 Pull-Up Disable control for this pin
    Uint16 GPIO59:1;                    // 27 Pull-Up Disable control for this pin
    Uint16 GPIO60:1;                    // 28 Pull-Up Disable control for this pin
    Uint16 GPIO61:1;                    // 29 Pull-Up Disable control for this pin
    Uint16 GPIO62:1;                    // 30 Pull-Up Disable control for this pin
    Uint16 GPIO63:1;                    // 31 Pull-Up Disable control for this pin
};

union GPBPUD_REG {
    Uint32  all;
    struct  GPBPUD_BITS  bit;
};

#ifdef CPU1
// GPBPUD Register
//// GPBPUD Register : Byte Value
#define GPBPUD_GPIO063_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO063_PullUpDisable					0x80000000UL

#define GPBPUD_GPIO062_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO062_PullUpDisable					0x40000000UL

#define GPBPUD_GPIO061_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO061_PullUpDisable					0x20000000UL

#define GPBPUD_GPIO060_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO060_PullUpDisable					0x10000000UL

#define GPBPUD_GPIO059_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO059_PullUpDisable					0x08000000UL

#define GPBPUD_GPIO058_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO058_PullUpDisable					0x04000000UL

#define GPBPUD_GPIO057_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO057_PullUpDisable					0x02000000UL

#define GPBPUD_GPIO056_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO056_PullUpDisable					0x01000000UL

#define GPBPUD_GPIO055_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO055_PullUpDisable					0x00800000UL

#define GPBPUD_GPIO054_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO054_PullUpDisable					0x00400000UL

#define GPBPUD_GPIO053_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO053_PullUpDisable					0x00200000UL

#define GPBPUD_GPIO052_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO052_PullUpDisable					0x00100000UL

#define GPBPUD_GPIO051_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO051_PullUpDisable					0x00080000UL

#define GPBPUD_GPIO050_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO050_PullUpDisable					0x00040000UL

#define GPBPUD_GPIO049_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO049_PullUpDisable					0x00020000UL

#define GPBPUD_GPIO048_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO048_PullUpDisable					0x00010000UL

#define GPBPUD_GPIO047_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO047_PullUpDisable					0x00008000UL

#define GPBPUD_GPIO046_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO046_PullUpDisable					0x00004000UL

#define GPBPUD_GPIO045_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO045_PullUpDisable					0x00002000UL

#define GPBPUD_GPIO044_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO044_PullUpDisable					0x00001000UL

#define GPBPUD_GPIO043_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO043_PullUpDisable					0x00000800UL

#define GPBPUD_GPIO042_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO042_PullUpDisable					0x00000400UL

#define GPBPUD_GPIO041_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO041_PullUpDisable					0x00000200UL

#define GPBPUD_GPIO040_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO040_PullUpDisable					0x00000100UL

#define GPBPUD_GPIO039_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO039_PullUpDisable					0x00000080UL

#define GPBPUD_GPIO038_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO038_PullUpDisable					0x00000040UL

#define GPBPUD_GPIO037_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO037_PullUpDisable					0x00000020UL

#define GPBPUD_GPIO036_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO036_PullUpDisable					0x00000010UL

#define GPBPUD_GPIO035_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO035_PullUpDisable					0x00000008UL

#define GPBPUD_GPIO034_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO034_PullUpDisable					0x00000004UL

#define GPBPUD_GPIO033_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO033_PullUpDisable					0x00000002UL

#define GPBPUD_GPIO032_PullUpEnable						0x00000000UL
#define GPBPUD_GPIO032_PullUpDisable					0x00000001UL
#endif

struct GPBINV_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Input inversion control for this pin
    Uint16 GPIO33:1;                    // 1 Input inversion control for this pin
    Uint16 GPIO34:1;                    // 2 Input inversion control for this pin
    Uint16 GPIO35:1;                    // 3 Input inversion control for this pin
    Uint16 GPIO36:1;                    // 4 Input inversion control for this pin
    Uint16 GPIO37:1;                    // 5 Input inversion control for this pin
    Uint16 GPIO38:1;                    // 6 Input inversion control for this pin
    Uint16 GPIO39:1;                    // 7 Input inversion control for this pin
    Uint16 GPIO40:1;                    // 8 Input inversion control for this pin
    Uint16 GPIO41:1;                    // 9 Input inversion control for this pin
    Uint16 GPIO42:1;                    // 10 Input inversion control for this pin
    Uint16 GPIO43:1;                    // 11 Input inversion control for this pin
    Uint16 GPIO44:1;                    // 12 Input inversion control for this pin
    Uint16 GPIO45:1;                    // 13 Input inversion control for this pin
    Uint16 GPIO46:1;                    // 14 Input inversion control for this pin
    Uint16 GPIO47:1;                    // 15 Input inversion control for this pin
    Uint16 GPIO48:1;                    // 16 Input inversion control for this pin
    Uint16 GPIO49:1;                    // 17 Input inversion control for this pin
    Uint16 GPIO50:1;                    // 18 Input inversion control for this pin
    Uint16 GPIO51:1;                    // 19 Input inversion control for this pin
    Uint16 GPIO52:1;                    // 20 Input inversion control for this pin
    Uint16 GPIO53:1;                    // 21 Input inversion control for this pin
    Uint16 GPIO54:1;                    // 22 Input inversion control for this pin
    Uint16 GPIO55:1;                    // 23 Input inversion control for this pin
    Uint16 GPIO56:1;                    // 24 Input inversion control for this pin
    Uint16 GPIO57:1;                    // 25 Input inversion control for this pin
    Uint16 GPIO58:1;                    // 26 Input inversion control for this pin
    Uint16 GPIO59:1;                    // 27 Input inversion control for this pin
    Uint16 GPIO60:1;                    // 28 Input inversion control for this pin
    Uint16 GPIO61:1;                    // 29 Input inversion control for this pin
    Uint16 GPIO62:1;                    // 30 Input inversion control for this pin
    Uint16 GPIO63:1;                    // 31 Input inversion control for this pin
};

union GPBINV_REG {
    Uint32  all;
    struct  GPBINV_BITS  bit;
};

#ifdef CPU1
// GPBINV Register
//// GPBINV Register : Byte Value
#define GPBINV_GPIO063_InNormal							0x00000000UL
#define GPBINV_GPIO063_InInverted						0x80000000UL

#define GPBINV_GPIO062_InNormal							0x00000000UL
#define GPBINV_GPIO062_InInverted						0x40000000UL

#define GPBINV_GPIO061_InNormal							0x00000000UL
#define GPBINV_GPIO061_InInverted						0x20000000UL

#define GPBINV_GPIO060_InNormal							0x00000000UL
#define GPBINV_GPIO060_InInverted						0x10000000UL

#define GPBINV_GPIO059_InNormal							0x00000000UL
#define GPBINV_GPIO059_InInverted						0x08000000UL

#define GPBINV_GPIO058_InNormal							0x00000000UL
#define GPBINV_GPIO058_InInverted						0x04000000UL

#define GPBINV_GPIO057_InNormal							0x00000000UL
#define GPBINV_GPIO057_InInverted						0x02000000UL

#define GPBINV_GPIO056_InNormal							0x00000000UL
#define GPBINV_GPIO056_InInverted						0x01000000UL

#define GPBINV_GPIO055_InNormal							0x00000000UL
#define GPBINV_GPIO055_InInverted						0x00800000UL

#define GPBINV_GPIO054_InNormal							0x00000000UL
#define GPBINV_GPIO054_InInverted						0x00400000UL

#define GPBINV_GPIO053_InNormal							0x00000000UL
#define GPBINV_GPIO053_InInverted						0x00200000UL

#define GPBINV_GPIO052_InNormal							0x00000000UL
#define GPBINV_GPIO052_InInverted						0x00100000UL

#define GPBINV_GPIO051_InNormal							0x00000000UL
#define GPBINV_GPIO051_InInverted						0x00080000UL

#define GPBINV_GPIO050_InNormal							0x00000000UL
#define GPBINV_GPIO050_InInverted						0x00040000UL

#define GPBINV_GPIO049_InNormal							0x00000000UL
#define GPBINV_GPIO049_InInverted						0x00020000UL

#define GPBINV_GPIO048_InNormal							0x00000000UL
#define GPBINV_GPIO048_InInverted						0x00010000UL

#define GPBINV_GPIO047_InNormal							0x00000000UL
#define GPBINV_GPIO047_InInverted						0x00008000UL

#define GPBINV_GPIO046_InNormal							0x00000000UL
#define GPBINV_GPIO046_InInverted						0x00004000UL

#define GPBINV_GPIO045_InNormal							0x00000000UL
#define GPBINV_GPIO045_InInverted						0x00002000UL

#define GPBINV_GPIO044_InNormal							0x00000000UL
#define GPBINV_GPIO044_InInverted						0x00001000UL

#define GPBINV_GPIO043_InNormal							0x00000000UL
#define GPBINV_GPIO043_InInverted						0x00000800UL

#define GPBINV_GPIO042_InNormal							0x00000000UL
#define GPBINV_GPIO042_InInverted						0x00000400UL

#define GPBINV_GPIO041_InNormal							0x00000000UL
#define GPBINV_GPIO041_InInverted						0x00000200UL

#define GPBINV_GPIO040_InNormal							0x00000000UL
#define GPBINV_GPIO040_InInverted						0x00000100UL

#define GPBINV_GPIO039_InNormal							0x00000000UL
#define GPBINV_GPIO039_InInverted						0x00000080UL

#define GPBINV_GPIO038_InNormal							0x00000000UL
#define GPBINV_GPIO038_InInverted						0x00000040UL

#define GPBINV_GPIO037_InNormal							0x00000000UL
#define GPBINV_GPIO037_InInverted						0x00000020UL

#define GPBINV_GPIO036_InNormal							0x00000000UL
#define GPBINV_GPIO036_InInverted						0x00000010UL

#define GPBINV_GPIO035_InNormal							0x00000000UL
#define GPBINV_GPIO035_InInverted						0x00000008UL

#define GPBINV_GPIO034_InNormal							0x00000000UL
#define GPBINV_GPIO034_InInverted						0x00000004UL

#define GPBINV_GPIO033_InNormal							0x00000000UL
#define GPBINV_GPIO033_InInverted						0x00000002UL

#define GPBINV_GPIO032_InNormal							0x00000000UL
#define GPBINV_GPIO032_InInverted						0x00000001UL
#endif

struct GPBODR_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO33:1;                    // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO34:1;                    // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO35:1;                    // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO36:1;                    // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO37:1;                    // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO38:1;                    // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO39:1;                    // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO40:1;                    // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO41:1;                    // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO42:1;                    // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO43:1;                    // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO44:1;                    // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO45:1;                    // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO46:1;                    // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO47:1;                    // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO48:1;                    // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO49:1;                    // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO50:1;                    // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO51:1;                    // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO52:1;                    // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO53:1;                    // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO54:1;                    // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO55:1;                    // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO56:1;                    // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO57:1;                    // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO58:1;                    // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO59:1;                    // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO60:1;                    // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO61:1;                    // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO62:1;                    // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO63:1;                    // 31 Outpout Open-Drain control for this pin
};

union GPBODR_REG {
    Uint32  all;
    struct  GPBODR_BITS  bit;
};

#ifdef CPU1
// GPBODR Register
//// GPBODR Register : Byte Value
#define GPBODR_GPIO063_Normal							0x00000000UL
#define GPBODR_GPIO063_OpenDrain						0x80000000UL

#define GPBODR_GPIO062_Normal							0x00000000UL
#define GPBODR_GPIO062_OpenDrain						0x40000000UL

#define GPBODR_GPIO061_Normal							0x00000000UL
#define GPBODR_GPIO061_OpenDrain						0x20000000UL

#define GPBODR_GPIO060_Normal							0x00000000UL
#define GPBODR_GPIO060_OpenDrain						0x10000000UL

#define GPBODR_GPIO059_Normal							0x00000000UL
#define GPBODR_GPIO059_OpenDrain						0x08000000UL

#define GPBODR_GPIO058_Normal							0x00000000UL
#define GPBODR_GPIO058_OpenDrain						0x04000000UL

#define GPBODR_GPIO057_Normal							0x00000000UL
#define GPBODR_GPIO057_OpenDrain						0x02000000UL

#define GPBODR_GPIO056_Normal							0x00000000UL
#define GPBODR_GPIO056_OpenDrain						0x01000000UL

#define GPBODR_GPIO055_Normal							0x00000000UL
#define GPBODR_GPIO055_OpenDrain						0x00800000UL

#define GPBODR_GPIO054_Normal							0x00000000UL
#define GPBODR_GPIO054_OpenDrain						0x00400000UL

#define GPBODR_GPIO053_Normal							0x00000000UL
#define GPBODR_GPIO053_OpenDrain						0x00200000UL

#define GPBODR_GPIO052_Normal							0x00000000UL
#define GPBODR_GPIO052_OpenDrain						0x00100000UL

#define GPBODR_GPIO051_Normal							0x00000000UL
#define GPBODR_GPIO051_OpenDrain						0x00080000UL

#define GPBODR_GPIO050_Normal							0x00000000UL
#define GPBODR_GPIO050_OpenDrain						0x00040000UL

#define GPBODR_GPIO049_Normal							0x00000000UL
#define GPBODR_GPIO049_OpenDrain						0x00020000UL

#define GPBODR_GPIO048_Normal							0x00000000UL
#define GPBODR_GPIO048_OpenDrain						0x00010000UL

#define GPBODR_GPIO047_Normal							0x00000000UL
#define GPBODR_GPIO047_OpenDrain						0x00008000UL

#define GPBODR_GPIO046_Normal							0x00000000UL
#define GPBODR_GPIO046_OpenDrain						0x00004000UL

#define GPBODR_GPIO045_Normal							0x00000000UL
#define GPBODR_GPIO045_OpenDrain						0x00002000UL

#define GPBODR_GPIO044_Normal							0x00000000UL
#define GPBODR_GPIO044_OpenDrain						0x00001000UL

#define GPBODR_GPIO043_Normal							0x00000000UL
#define GPBODR_GPIO043_OpenDrain						0x00000800UL

#define GPBODR_GPIO042_Normal							0x00000000UL
#define GPBODR_GPIO042_OpenDrain						0x00000400UL

#define GPBODR_GPIO041_Normal							0x00000000UL
#define GPBODR_GPIO041_OpenDrain						0x00000200UL

#define GPBODR_GPIO040_Normal							0x00000000UL
#define GPBODR_GPIO040_OpenDrain						0x00000100UL

#define GPBODR_GPIO039_Normal							0x00000000UL
#define GPBODR_GPIO039_OpenDrain						0x00000080UL

#define GPBODR_GPIO038_Normal							0x00000000UL
#define GPBODR_GPIO038_OpenDrain						0x00000040UL

#define GPBODR_GPIO037_Normal							0x00000000UL
#define GPBODR_GPIO037_OpenDrain						0x00000020UL

#define GPBODR_GPIO036_Normal							0x00000000UL
#define GPBODR_GPIO036_OpenDrain						0x00000010UL

#define GPBODR_GPIO035_Normal							0x00000000UL
#define GPBODR_GPIO035_OpenDrain						0x00000008UL

#define GPBODR_GPIO034_Normal							0x00000000UL
#define GPBODR_GPIO034_OpenDrain						0x00000004UL

#define GPBODR_GPIO033_Normal							0x00000000UL
#define GPBODR_GPIO033_OpenDrain						0x00000002UL

#define GPBODR_GPIO032_Normal							0x00000000UL
#define GPBODR_GPIO032_OpenDrain						0x00000001UL
#endif

struct GPBAMSEL_BITS {                  // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:1;                     // 4 Reserved
    Uint16 rsvd6:1;                     // 5 Reserved
    Uint16 rsvd7:1;                     // 6 Reserved
    Uint16 rsvd8:1;                     // 7 Reserved
    Uint16 rsvd9:1;                     // 8 Reserved
    Uint16 rsvd10:1;                    // 9 Reserved
    Uint16 GPIO42:1;                    // 10 Analog Mode select for this pin
    Uint16 GPIO43:1;                    // 11 Analog Mode select for this pin
    Uint16 rsvd11:1;                    // 12 Reserved
    Uint16 rsvd12:1;                    // 13 Reserved
    Uint16 rsvd13:1;                    // 14 Reserved
    Uint16 rsvd14:1;                    // 15 Reserved
    Uint16 rsvd15:1;                    // 16 Reserved
    Uint16 rsvd16:1;                    // 17 Reserved
    Uint16 rsvd17:1;                    // 18 Reserved
    Uint16 rsvd18:1;                    // 19 Reserved
    Uint16 rsvd19:1;                    // 20 Reserved
    Uint16 rsvd20:1;                    // 21 Reserved
    Uint16 rsvd21:1;                    // 22 Reserved
    Uint16 rsvd22:1;                    // 23 Reserved
    Uint16 rsvd23:1;                    // 24 Reserved
    Uint16 rsvd24:1;                    // 25 Reserved
    Uint16 rsvd25:1;                    // 26 Reserved
    Uint16 rsvd26:1;                    // 27 Reserved
    Uint16 rsvd27:1;                    // 28 Reserved
    Uint16 rsvd28:1;                    // 29 Reserved
    Uint16 rsvd29:1;                    // 30 Reserved
    Uint16 rsvd30:1;                    // 31 Reserved
};

union GPBAMSEL_REG {
    Uint32  all;
    struct  GPBAMSEL_BITS  bit;
};

#ifdef CPU1
// GPBAMSEL Regsiter
//// GPBAMSEL Register : Byte Value
#define GPBAMSEL_GPIO043_GPBMUX							0x00000000UL				// GPBGMUX and GPBMUX Configure the Pin Function
#define GPBAMSEL_GPIO043_InOutUSB0DP					0x00000800UL				// GPIO043 is Configured to USB0DP

#define GPBAMSEL_GPIO042_GPBMUX							0x00000000UL				// GPBGMUX and GPBMUX Configure the Pin Function
#define GPBAMSEL_GPIO042_InOutUSB0DM					0x00000400UL				// GPIO042 si Configured to USB0DM
#endif

struct GPBGMUX1_BITS {                  // bits description
    Uint16 GPIO32:2;                    // 1:0 Defines pin-muxing selection for GPIO32
    Uint16 GPIO33:2;                    // 3:2 Defines pin-muxing selection for GPIO33
    Uint16 GPIO34:2;                    // 5:4 Defines pin-muxing selection for GPIO34
    Uint16 GPIO35:2;                    // 7:6 Defines pin-muxing selection for GPIO35
    Uint16 GPIO36:2;                    // 9:8 Defines pin-muxing selection for GPIO36
    Uint16 GPIO37:2;                    // 11:10 Defines pin-muxing selection for GPIO37
    Uint16 GPIO38:2;                    // 13:12 Defines pin-muxing selection for GPIO38
    Uint16 GPIO39:2;                    // 15:14 Defines pin-muxing selection for GPIO39
    Uint16 GPIO40:2;                    // 17:16 Defines pin-muxing selection for GPIO40
    Uint16 GPIO41:2;                    // 19:18 Defines pin-muxing selection for GPIO41
    Uint16 GPIO42:2;                    // 21:20 Defines pin-muxing selection for GPIO42
    Uint16 GPIO43:2;                    // 23:22 Defines pin-muxing selection for GPIO43
    Uint16 GPIO44:2;                    // 25:24 Defines pin-muxing selection for GPIO44
    Uint16 GPIO45:2;                    // 27:26 Defines pin-muxing selection for GPIO45
    Uint16 GPIO46:2;                    // 29:28 Defines pin-muxing selection for GPIO46
    Uint16 GPIO47:2;                    // 31:30 Defines pin-muxing selection for GPIO47
};

union GPBGMUX1_REG {
    Uint32  all;
    struct  GPBGMUX1_BITS  bit;
};

#ifdef CPU1
// GPBGMUX1 Register
//// GPBGMUX1 Register : Byte Value													// GMUX		MUX
#define GPBGMUX1_GPIO047_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO047_OutEM1A7						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO047_OutSCITXDD						0x40000000UL				// 0b01		0b10

#define GPBGMUX1_GPIO046_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO046_OutEM1A6						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO046_InSCIRXDD						0x10000000UL				// 0b01		0b10

#define GPBGMUX1_GPIO045_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO045_OutEM1A5						0x00000000UL				// 0b00		0b10

#define GPBGMUX1_GPIO044_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO044_OutEM1A4						0x00000000UL				// 0b00		0b10

#define GPBGMUX1_GPIO043_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO043_InODSCLA						0x00400000UL				// 0b01		0b10
#define GPBGMUX1_GPIO043_InSCIRXDA						0x00C00000UL				// 0b11		0b11

#define GPBGMUX1_GPIO042_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO042_InODSDAA						0x00100000UL				// 0b01		0b10
#define GPBGMUX1_GPIO042_OutSCITXDA						0x00300000UL				// 0b11		0b11

#define GPBGMUX1_GPIO041_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO041_OutEM1A3						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO041_InODSCLB						0x00040000UL				// 0b01		0b10

#define GPBGMUX1_GPIO040_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO040_OutEM1A2						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO040_InODSDAB						0x00010000UL				// 0b01		0b10

#define GPBGMUX1_GPIO039_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO039_OutEM1A1						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO039_InSCIRXDC						0x00004000UL				// 0b01		0b01
#define GPBGMUX1_GPIO039_InCANRXB						0x00004000UL				// 0b01		0b10

#define GPBGMUX1_GPIO038_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO038_OutEM1A0						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO038_OutSCITXDC						0x00001000UL				// 0b01		0b01
#define GPBGMUX1_GPIO038_OutCANTXB						0x00001000UL				// 0b01		0b10

#define GPBGMUX1_GPIO037_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO037_OutOUTPUTXBAR2					0x00000000UL				// 0b00		0b01
#define GPBGMUX1_GPIO037_OutnEM1OE						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO037_OutCANTXA						0x00000400UL				// 0b01		0b10

#define GPBGMUX1_GPIO036_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO036_OutSCIRXDA						0x00000000UL				// 0b00		0b01
#define GPBGMUX1_GPIO036_InEM1WAIT						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO036_InCANRXA						0x00000100UL				// 0b01		0b10

#define GPBGMUX1_GPIO035_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO035_InSCIRXDA						0x00000000UL				// 0b00		0b01
#define GPBGMUX1_GPIO035_OutnEM1CS3						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO035_InODSCLB						0x00000040UL				// 0b01		0b10

#define GPBGMUX1_GPIO034_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO034_OutOUTPUTXBAR1					0x00000000UL				// 0b00		0b01
#define GPBGMUX1_GPIO034_OutnEM1CS2						0x00000000UL				// 0b00		0b10
#define GPBGMUX1_GPIO034_InODSDAB						0x00000010UL				// 0b01		0b10

#define GPBGMUX1_GPIO033_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO033_InODSCLA						0x00000000UL				// 0b00		0b01
#define GPBGMUX1_GPIO033_OutEM1RNW						0x00000000UL				// 0b00		0b10

#define GPBGMUX1_GPIO032_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX1_GPIO032_InODSDAA						0x00000000UL				// 0b00		0b01
#define GPBGMUX1_GPIO032_OutnEM1CS0						0x00000000UL				// 0b00		0b10

//// GPBGMUX1 Register : Bit Value													// GMUX		MUX
#define GMUX_GPIO047_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO047_OutEM1A7							0U							// 0b00		0b10
#define GMUX_GPIO047_OutSCITXDD							1U							// 0b01		0b10

#define GMUX_GPIO046_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO046_OutEM1A6							0U							// 0b00		0b10
#define GMUX_GPIO046_InSCIRXDD							1U							// 0b01		0b10

#define GMUX_GPIO045_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO045_OutEM1A5							0U							// 0b00		0b10

#define GMUX_GPIO044_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO044_OutEM1A4							0U							// 0b00		0b10

#define GMUX_GPIO043_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO043_InODSCLA							1U							// 0b01		0b10
#define GMUX_GPIO043_InSCIRXDA							3U							// 0b11		0b11

#define GMUX_GPIO042_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO042_InODSDAA							1U							// 0b01		0b10
#define GMUX_GPIO042_OutSCITXDA							3U							// 0b11		0b11

#define GMUX_GPIO041_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO041_OutEM1A3							0U							// 0b00		0b10
#define GMUX_GPIO041_InODSCLB							1U							// 0b01		0b10

#define GMUX_GPIO040_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO040_OutEM1A2							0U							// 0b00		0b10
#define GMUX_GPIO040_InODSDAB							1U							// 0b01		0b10

#define GMUX_GPIO039_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO039_OutEM1A1							0U							// 0b00		0b10
#define GMUX_GPIO039_InSCIRXDC							1U							// 0b01		0b01
#define GMUX_GPIO039_InCANRXB							1U							// 0b01		0b10

#define GMUX_GPIO038_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO038_OutEM1A0							0U							// 0b00		0b10
#define GMUX_GPIO038_OutSCITXDC							1U							// 0b01		0b01
#define GMUX_GPIO038_OutCANTXB							1U							// 0b01		0b10

#define GMUX_GPIO037_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO037_OutOUTPUTXBAR2						0U							// 0b00		0b01
#define GMUX_GPIO037_OutnEM1OE							0U							// 0b00		0b10
#define GMUX_GPIO037_OutCANTXA							1U							// 0b01		0b10

#define GMUX_GPIO036_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO036_OutSCIRXDA							0U							// 0b00		0b01
#define GMUX_GPIO036_InEM1WAIT							0U							// 0b00		0b10
#define GMUX_GPIO036_InCANRXA							1U							// 0b01		0b10

#define GMUX_GPIO035_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO035_InSCIRXDA							0U							// 0b00		0b01
#define GMUX_GPIO035_OutnEM1CS3							0U							// 0b00		0b10
#define GMUX_GPIO035_InODSCLB							1U							// 0b01		0b10

#define GMUX_GPIO034_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO034_OutOUTPUTXBAR1						0U							// 0b00		0b01
#define GMUX_GPIO034_OutnEM1CS2							0U							// 0b00		0b10
#define GMUX_GPIO034_InODSDAB							1U							// 0b01		0b10

#define GMUX_GPIO033_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO033_InODSCLA							0U							// 0b00		0b01
#define GMUX_GPIO033_OutEM1RNW							0U							// 0b00		0b10

#define GMUX_GPIO032_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO032_InODSDAA							0U							// 0b00		0b01
#define GMUX_GPIO032_OutnEM1CS0							0U							// 0b00		0b10
#endif

struct GPBGMUX2_BITS {                  // bits description
    Uint16 GPIO48:2;                    // 1:0 Defines pin-muxing selection for GPIO48
    Uint16 GPIO49:2;                    // 3:2 Defines pin-muxing selection for GPIO49
    Uint16 GPIO50:2;                    // 5:4 Defines pin-muxing selection for GPIO50
    Uint16 GPIO51:2;                    // 7:6 Defines pin-muxing selection for GPIO51
    Uint16 GPIO52:2;                    // 9:8 Defines pin-muxing selection for GPIO52
    Uint16 GPIO53:2;                    // 11:10 Defines pin-muxing selection for GPIO53
    Uint16 GPIO54:2;                    // 13:12 Defines pin-muxing selection for GPIO54
    Uint16 GPIO55:2;                    // 15:14 Defines pin-muxing selection for GPIO55
    Uint16 GPIO56:2;                    // 17:16 Defines pin-muxing selection for GPIO56
    Uint16 GPIO57:2;                    // 19:18 Defines pin-muxing selection for GPIO57
    Uint16 GPIO58:2;                    // 21:20 Defines pin-muxing selection for GPIO58
    Uint16 GPIO59:2;                    // 23:22 Defines pin-muxing selection for GPIO59
    Uint16 GPIO60:2;                    // 25:24 Defines pin-muxing selection for GPIO60
    Uint16 GPIO61:2;                    // 27:26 Defines pin-muxing selection for GPIO61
    Uint16 GPIO62:2;                    // 29:28 Defines pin-muxing selection for GPIO62
    Uint16 GPIO63:2;                    // 31:30 Defines pin-muxing selection for GPIO63
};

union GPBGMUX2_REG {
    Uint32  all;
    struct  GPBGMUX2_BITS  bit;
};

#ifdef CPU1
// GPBGMUX2 Register
//// GPBGMUX2 Register : Byte Value													// GMUX		MUX
#define GPBGMUX2_GPIO063_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO063_OutSCITXDC						0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO063_InOutEM1D21					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO063_InOutEM2D5						0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO063_InEQEP3B						0x40000000UL				// 0b01		0b01
#define GPBGMUX2_GPIO063_OutCANTXA						0x40000000UL				// 0b01		0b10
#define GPBGMUX2_GPIO063_InSD2_C4						0x40000000UL				// 0b01		0b11
#define GPBGMUX2_GPIO063_InOutHSPSPISIMOB				0xC0000000UL				// 0b11		0b11

#define GPBGMUX2_GPIO062_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO062_InSCIRXDC						0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO062_InOutEM1D22					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO062_InOutEM2D6						0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO062_InEQEP3A						0x10000000UL				// 0b01		0b01
#define GPBGMUX2_GPIO062_InCANRXA						0x10000000UL				// 0b01		0b10
#define GPBGMUX2_GPIO062_InSD2_D4						0x10000000UL				// 0b01		0b11

#define GPBGMUX2_GPIO061_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO061_InOutMFSRB						0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO061_InOutEM1D23					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO061_InOutEM2D7						0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO061_OutOUTPUTXBAR4					0x04000000UL				// 0b01		0b01
#define GPBGMUX2_GPIO061_InOutSPISOMIB					0x04000000UL				// 0b01		0b10
#define GPBGMUX2_GPIO061_InSD2_C3						0x04000000UL				// 0b01		0b11
#define GPBGMUX2_GPIO061_InOutHSPnSPISTEA				0x0C000000UL				// 0b11		0b11

#define GPBGMUX2_GPIO060_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO060_InOutMCLKRB					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO060_InOutEM1D24					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO060_InOutEM2D8						0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO060_OutOUTPUTXBAR3					0x01000000UL				// 0b01		0b01
#define GPBGMUX2_GPIO060_InOutSPISIMOB					0x01000000UL				// 0b01		0b10
#define GPBGMUX2_GPIO060_InSD2_D3						0x01000000UL				// 0b01		0b11
#define GPBGMUX2_GPIO060_InOutHSPSPICLKA				0x03000000UL				// 0b11		0b11

#define GPBGMUX2_GPIO059_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO059_InOutMFSRA						0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO059_InOutEM1D25					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO059_InOutEM2D9						0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO059_OutOUTPUTXBAR2					0x00400000UL				// 0b01		0b01
#define GPBGMUX2_GPIO059_InOutnSPISTEB					0x00400000UL				// 0b01		0b10
#define GPBGMUX2_GPIO059_InSD2_C2						0x00400000UL				// 0b01		0b11
#define GPBGMUX2_GPIO059_InOutHSPSPISOMIA				0x00C00000UL				// 0b11		0b11

#define GPBGMUX2_GPIO058_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO058_InOutMCLKRA					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO058_InOutEM1D26					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO058_InOutEM2D10					0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO058_OutOUTPUTXBAR1					0x00100000UL				// 0b01		0b01
#define GPBGMUX2_GPIO058_InOutSPICLKB					0x00100000UL				// 0b01		0b10
#define GPBGMUX2_GPIO058_InSD2_D2						0x00100000UL				// 0b01		0b11
#define GPBGMUX2_GPIO058_InOutHSPSPISIMOA				0x00300000UL				// 0b11		0b11

#define GPBGMUX2_GPIO057_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO057_InOutnSPISTEA					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO057_InOutEM1D27					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO057_InOutEM2D11					0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO057_InOutEQEP2I					0x00040000UL				// 0b01		0b01
#define GPBGMUX2_GPIO057_InSCITXDC						0x00040000UL				// 0b01		0b10
#define GPBGMUX2_GPIO057_InSD2_C1						0x00040000UL				// 0b01		0b11

#define GPBGMUX2_GPIO056_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO056_InOutSPICLKA					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO056_InOutEM1D28					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO056_InOutEM2D12					0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO056_InOutEQEP2S					0x00010000UL				// 0b01		0b01
#define GPBGMUX2_GPIO056_OutSCITXDC						0x00010000UL				// 0b01		0b10
#define GPBGMUX2_GPIO056_InSD2_D1						0x00010000UL				// 0b01		0b11

#define GPBGMUX2_GPIO055_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO055_InOutSPISOMIA					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO055_InOutEM1D29					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO055_InOutEM2D13					0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO055_InEQEP2B						0x00004000UL				// 0b01		0b01
#define GPBGMUX2_GPIO055_InSCIRXDB						0x00004000UL				// 0b01		0b10
#define GPBGMUX2_GPIO055_InSD1_C4						0x00004000UL				// 0b01		0b11

#define GPBGMUX2_GPIO054_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO054_InOutSPISIMOA					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO054_InOutEM1D30					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO054_InOutEM2D14					0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO054_InEQEP2A						0x00001000UL				// 0b01		0b01
#define GPBGMUX2_GPIO054_OutSCITXDB						0x00001000UL				// 0b01		0b10
#define GPBGMUX2_GPIO054_InSD1_D4						0x00001000UL				// 0b01		0b11

#define GPBGMUX2_GPIO053_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO053_InOutEQEP1I					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO053_InOutEM1D31					0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO053_InOutEM2D15					0x00000000UL				// 0b00		0b11
#define GPBGMUX2_GPIO053_InOutnSPISTEC					0x00000400UL				// 0b01		0b10
#define GPBGMUX2_GPIO053_InSD1_C3						0x00000400UL				// 0b01		0b11

#define GPBGMUX2_GPIO052_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO052_InOutEQEP1S					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO052_OutEM1A12						0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO052_InOutSPICLKC					0x00000100UL				// 0b01		0b10
#define GPBGMUX2_GPIO052_InSD1_D3						0x00000100UL				// 0b01		0b11

#define GPBGMUX2_GPIO051_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO051_InEQEP1B						0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO051_OutEM1A11						0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO051_InOutSPISOMIC					0x00000040UL				// 0b01		0b10
#define GPBGMUX2_GPIO051_InSD1_C2						0x00000040UL				// 0b01		0b11

#define GPBGMUX2_GPIO050_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO050_InEQEP1A						0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO050_OutEM1A10						0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO050_InOutSPISIMOC					0x00000010UL				// 0b01		0b10
#define GPBGMUX2_GPIO050_InSD1_D2						0x00000010UL				// 0b01		0b11

#define GPBGMUX2_GPIO049_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO049_OutOUTPUTXBAR4					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO049_OutEM1A9						0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO049_InSCIRXDA						0x00000004UL				// 0b01		0b10
#define GPBGMUX2_GPIO049_InSD1_C1						0x00000004UL				// 0b01		0b11

#define GPBGMUX2_GPIO048_InOutGPIO						0x00000000UL				// -		0b00
#define GPBGMUX2_GPIO048_OutOUTPUTXBAR3					0x00000000UL				// 0b00		0b01
#define GPBGMUX2_GPIO048_OutEM1A8						0x00000000UL				// 0b00		0b10
#define GPBGMUX2_GPIO048_OutSCITXDA						0x00000001UL				// 0b01		0b10
#define GPBGMUX2_GPIO048_InSD1_D1						0x00000001UL				// 0b01		0b11

//// GPBGMUX2 Register : Bit Value													// GMUX		MUX
#define GMUX_GPIO063_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO063_OutSCITXDC							0U							// 0b00		0b01
#define GMUX_GPIO063_InOutEM1D21						0U							// 0b00		0b10
#define GMUX_GPIO063_InOutEM2D5							0U							// 0b00		0b11
#define GMUX_GPIO063_InEQEP3B							1U							// 0b01		0b01
#define GMUX_GPIO063_OutCANTXA							1U							// 0b01		0b10
#define GMUX_GPIO063_InSD2_C4							1U							// 0b01		0b11
#define GMUX_GPIO063_InOutHSPSPISIMOB					3U							// 0b11		0b11

#define GMUX_GPIO062_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO062_InSCIRXDC							0U							// 0b00		0b01
#define GMUX_GPIO062_InOutEM1D22						0U							// 0b00		0b10
#define GMUX_GPIO062_InOutEM2D6							0U							// 0b00		0b11
#define GMUX_GPIO062_InEQEP3A							1U							// 0b01		0b01
#define GMUX_GPIO062_InCANRXA							1U							// 0b01		0b10
#define GMUX_GPIO062_InSD2_D4							1U							// 0b01		0b11

#define GMUX_GPIO061_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO061_InOutMFSRB							0U							// 0b00		0b01
#define GMUX_GPIO061_InOutEM1D23						0U							// 0b00		0b10
#define GMUX_GPIO061_InOutEM2D7							0U							// 0b00		0b11
#define GMUX_GPIO061_OutOUTPUTXBAR4						1U							// 0b01		0b01
#define GMUX_GPIO061_InOutSPISOMIB						1U							// 0b01		0b10
#define GMUX_GPIO061_InSD2_C3							1U							// 0b01		0b11
#define GMUX_GPIO061_InOutHSPnSPISTEA					3U							// 0b11		0b11

#define GMUX_GPIO060_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO060_InOutMCLKRB						0U							// 0b00		0b01
#define GMUX_GPIO060_InOutEM1D24						0U							// 0b00		0b10
#define GMUX_GPIO060_InOutEM2D8							0U							// 0b00		0b11
#define GMUX_GPIO060_OutOUTPUTXBAR3						1U							// 0b01		0b01
#define GMUX_GPIO060_InOutSPISIMOB						1U							// 0b01		0b10
#define GMUX_GPIO060_InSD2_D3							1U							// 0b01		0b11
#define GMUX_GPIO060_InOutHSPSPICLKA					3U							// 0b11		0b11

#define GMUX_GPIO059_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO059_InOutMFSRA							0U							// 0b00		0b01
#define GMUX_GPIO059_InOutEM1D25						0U							// 0b00		0b10
#define GMUX_GPIO059_InOutEM2D9							0U							// 0b00		0b11
#define GMUX_GPIO059_OutOUTPUTXBAR2						1U							// 0b01		0b01
#define GMUX_GPIO059_InOutnSPISTEB						1U							// 0b01		0b10
#define GMUX_GPIO059_InSD2_C2							1U							// 0b01		0b11
#define GMUX_GPIO059_InOutHSPSPISOMIA					3U							// 0b11		0b11

#define GMUX_GPIO058_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO058_InOutMCLKRA						0U							// 0b00		0b01
#define GMUX_GPIO058_InOutEM1D26						0U							// 0b00		0b10
#define GMUX_GPIO058_InOutEM2D10						0U							// 0b00		0b11
#define GMUX_GPIO058_OutOUTPUTXBAR1						1U							// 0b01		0b01
#define GMUX_GPIO058_InOutSPICLKB						1U							// 0b01		0b10
#define GMUX_GPIO058_InSD2_D2							1U							// 0b01		0b11
#define GMUX_GPIO058_InOutHSPSPISIMOA					3U							// 0b11		0b11

#define GMUX_GPIO057_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO057_InOutnSPISTEA						0U							// 0b00		0b01
#define GMUX_GPIO057_InOutEM1D27						0U							// 0b00		0b10
#define GMUX_GPIO057_InOutEM2D11						0U							// 0b00		0b11
#define GMUX_GPIO057_InOutEQEP2I						1U							// 0b01		0b01
#define GMUX_GPIO057_InSCITXDC							1U							// 0b01		0b10
#define GMUX_GPIO057_InSD2_C1							1U							// 0b01		0b11

#define GMUX_GPIO056_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO056_InOutSPICLKA						0U							// 0b00		0b01
#define GMUX_GPIO056_InOutEM1D28						0U							// 0b00		0b10
#define GMUX_GPIO056_InOutEM2D12						0U							// 0b00		0b11
#define GMUX_GPIO056_InOutEQEP2S						1U							// 0b01		0b01
#define GMUX_GPIO056_OutSCITXDC							1U							// 0b01		0b10
#define GMUX_GPIO056_InSD2_D1							1U							// 0b01		0b11

#define GMUX_GPIO055_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO055_InOutSPISOMIA						0U							// 0b00		0b01
#define GMUX_GPIO055_InOutEM1D29						0U							// 0b00		0b10
#define GMUX_GPIO055_InOutEM2D13						0U							// 0b00		0b11
#define GMUX_GPIO055_InEQEP2B							1U							// 0b01		0b01
#define GMUX_GPIO055_InSCIRXDB							1U							// 0b01		0b10
#define GMUX_GPIO055_InSD1_C4							1U							// 0b01		0b11

#define GMUX_GPIO054_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO054_InOutSPISIMOA						0U							// 0b00		0b01
#define GMUX_GPIO054_InOutEM1D30						0U							// 0b00		0b10
#define GMUX_GPIO054_InOutEM2D14						0U							// 0b00		0b11
#define GMUX_GPIO054_InEQEP2A							1U							// 0b01		0b01
#define GMUX_GPIO054_OutSCITXDB							1U							// 0b01		0b10
#define GMUX_GPIO054_InSD1_D4							1U							// 0b01		0b11

#define GMUX_GPIO053_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO053_InOutEQEP1I						0U							// 0b00		0b01
#define GMUX_GPIO053_InOutEM1D31						0U							// 0b00		0b10
#define GMUX_GPIO053_InOutEM2D15						0U							// 0b00		0b11
#define GMUX_GPIO053_InOutnSPISTEC						1U							// 0b01		0b10
#define GMUX_GPIO053_InSD1_C3							1U							// 0b01		0b11

#define GMUX_GPIO052_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO052_InOutEQEP1S						0U							// 0b00		0b01
#define GMUX_GPIO052_OutEM1A12							0U							// 0b00		0b10
#define GMUX_GPIO052_InOutSPICLKC						1U							// 0b01		0b10
#define GMUX_GPIO052_InSD1_D3							1U							// 0b01		0b11

#define GMUX_GPIO051_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO051_InEQEP1B							0U							// 0b00		0b01
#define GMUX_GPIO051_OutEM1A11							0U							// 0b00		0b10
#define GMUX_GPIO051_InOutSPISOMIC						1U							// 0b01		0b10
#define GMUX_GPIO051_InSD1_C2							1U							// 0b01		0b11

#define GMUX_GPIO050_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO050_InEQEP1A							0U							// 0b00		0b01
#define GMUX_GPIO050_OutEM1A10							0U							// 0b00		0b10
#define GMUX_GPIO050_InOutSPISIMOC						1U							// 0b01		0b10
#define GMUX_GPIO050_InSD1_D2							1U							// 0b01		0b11

#define GMUX_GPIO049_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO049_OutOUTPUTXBAR4						0U							// 0b00		0b01
#define GMUX_GPIO049_OutEM1A9							0U							// 0b00		0b10
#define GMUX_GPIO049_InSCIRXDA							1U							// 0b01		0b10
#define GMUX_GPIO049_InSD1_C1							1U							// 0b01		0b11

#define GMUX_GPIO048_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO048_OutOUTPUTXBAR3						0U							// 0b00		0b01
#define GMUX_GPIO048_OutEM1A8							0U							// 0b00		0b10
#define GMUX_GPIO048_OutSCITXDA							1U							// 0b01		0b10
#define GMUX_GPIO048_InSD1_D1							1U							// 0b01		0b11
#endif

struct GPBCSEL1_BITS {                  // bits description
    Uint16 GPIO32:4;                    // 3:0 GPIO32 Master CPU Select
    Uint16 GPIO33:4;                    // 7:4 GPIO33 Master CPU Select
    Uint16 GPIO34:4;                    // 11:8 GPIO34 Master CPU Select
    Uint16 GPIO35:4;                    // 15:12 GPIO35 Master CPU Select
    Uint16 GPIO36:4;                    // 19:16 GPIO36 Master CPU Select
    Uint16 GPIO37:4;                    // 23:20 GPIO37 Master CPU Select
    Uint16 GPIO38:4;                    // 27:24 GPIO38 Master CPU Select
    Uint16 GPIO39:4;                    // 31:28 GPIO39 Master CPU Select
};

union GPBCSEL1_REG {
    Uint32  all;
    struct  GPBCSEL1_BITS  bit;
};

#ifdef CPU1
// GPBCSEL1 Register
//// GPBCSEL1 Register : Byte Value
#define GPBCSEL1_GPIO039_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO039_CPU1_CLA1Host					0x10000000UL
#define GPBCSEL1_GPIO039_CPU2Host						0x20000000UL
#define GPBCSEL1_GPIO039_CPU2_CLA1Host					0x30000000UL

#define GPBCSEL1_GPIO038_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO038_CPU1_CLA1Host					0x01000000UL
#define GPBCSEL1_GPIO038_CPU2Host						0x02000000UL
#define GPBCSEL1_GPIO038_CPU2_CLA1Host					0x03000000UL

#define GPBCSEL1_GPIO037_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO037_CPU1_CLA1Host					0x00100000UL
#define GPBCSEL1_GPIO037_CPU2Host						0x00200000UL
#define GPBCSEL1_GPIO037_CPU2_CLA1Host					0x00300000UL

#define GPBCSEL1_GPIO036_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO036_CPU1_CLA1Host					0x00010000UL
#define GPBCSEL1_GPIO036_CPU2Host						0x00020000UL
#define GPBCSEL1_GPIO036_CPU2_CLA1Host					0x00030000UL

#define GPBCSEL1_GPIO035_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO035_CPU1_CLA1Host					0x00001000UL
#define GPBCSEL1_GPIO035_CPU2Host						0x00002000UL
#define GPBCSEL1_GPIO035_CPU2_CLA1Host					0x00003000UL

#define GPBCSEL1_GPIO034_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO034_CPU1_CLA1Host					0x00000100UL
#define GPBCSEL1_GPIO034_CPU2Host						0x00000200UL
#define GPBCSEL1_GPIO034_CPU2_CLA1Host					0x00000300UL

#define GPBCSEL1_GPIO033_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO033_CPU1_CLA1Host					0x00000010UL
#define GPBCSEL1_GPIO033_CPU2Host						0x00000020UL
#define GPBCSEL1_GPIO033_CPU2_CLA1Host					0x00000030UL

#define GPBCSEL1_GPIO032_CPU1Host						0x00000000UL
#define GPBCSEL1_GPIO032_CPU1_CLA1Host					0x00000001UL
#define GPBCSEL1_GPIO032_CPU2Host						0x00000002UL
#define GPBCSEL1_GPIO032_CPU2_CLA1Host					0x00000003UL

//// GPBCSEL1 Register : Quick Value
#define GPBCSEL1_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPBCSEL2_BITS {                  // bits description
    Uint16 GPIO40:4;                    // 3:0 GPIO40 Master CPU Select
    Uint16 GPIO41:4;                    // 7:4 GPIO41 Master CPU Select
    Uint16 GPIO42:4;                    // 11:8 GPIO42 Master CPU Select
    Uint16 GPIO43:4;                    // 15:12 GPIO43 Master CPU Select
    Uint16 GPIO44:4;                    // 19:16 GPIO44 Master CPU Select
    Uint16 GPIO45:4;                    // 23:20 GPIO45 Master CPU Select
    Uint16 GPIO46:4;                    // 27:24 GPIO46 Master CPU Select
    Uint16 GPIO47:4;                    // 31:28 GPIO47 Master CPU Select
};

union GPBCSEL2_REG {
    Uint32  all;
    struct  GPBCSEL2_BITS  bit;
};

#ifdef CPU1
// GPBCSEL2 Register
//// GPBCSEL2 Register : Byte Value
#define GPBCSEL2_GPIO047_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO047_CPU1_CLA1Host					0x10000000UL
#define GPBCSEL2_GPIO047_CPU2Host						0x20000000UL
#define GPBCSEL2_GPIO047_CPU2_CLA1Host					0x30000000UL

#define GPBCSEL2_GPIO046_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO046_CPU1_CLA1Host					0x01000000UL
#define GPBCSEL2_GPIO046_CPU2Host						0x02000000UL
#define GPBCSEL2_GPIO046_CPU2_CLA1Host					0x03000000UL

#define GPBCSEL2_GPIO045_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO045_CPU1_CLA1Host					0x00100000UL
#define GPBCSEL2_GPIO045_CPU2Host						0x00200000UL
#define GPBCSEL2_GPIO045_CPU2_CLA1Host					0x00300000UL

#define GPBCSEL2_GPIO044_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO044_CPU1_CLA1Host					0x00010000UL
#define GPBCSEL2_GPIO044_CPU2Host						0x00020000UL
#define GPBCSEL2_GPIO044_CPU2_CLA1Host					0x00030000UL

#define GPBCSEL2_GPIO043_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO043_CPU1_CLA1Host					0x00001000UL
#define GPBCSEL2_GPIO043_CPU2Host						0x00002000UL
#define GPBCSEL2_GPIO043_CPU2_CLA1Host					0x00003000UL

#define GPBCSEL2_GPIO042_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO042_CPU1_CLA1Host					0x00000100UL
#define GPBCSEL2_GPIO042_CPU2Host						0x00000200UL
#define GPBCSEL2_GPIO042_CPU2_CLA1Host					0x00000300UL

#define GPBCSEL2_GPIO041_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO041_CPU1_CLA1Host					0x00000010UL
#define GPBCSEL2_GPIO041_CPU2Host						0x00000020UL
#define GPBCSEL2_GPIO041_CPU2_CLA1Host					0x00000030UL

#define GPBCSEL2_GPIO040_CPU1Host						0x00000000UL
#define GPBCSEL2_GPIO040_CPU1_CLA1Host					0x00000001UL
#define GPBCSEL2_GPIO040_CPU2Host						0x00000002UL
#define GPBCSEL2_GPIO040_CPU2_CLA1Host					0x00000003UL

//// GPBCSEL2 Register : Quick Value
#define GPBCSEL2_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPBCSEL3_BITS {                  // bits description
    Uint16 GPIO48:4;                    // 3:0 GPIO48 Master CPU Select
    Uint16 GPIO49:4;                    // 7:4 GPIO49 Master CPU Select
    Uint16 GPIO50:4;                    // 11:8 GPIO50 Master CPU Select
    Uint16 GPIO51:4;                    // 15:12 GPIO51 Master CPU Select
    Uint16 GPIO52:4;                    // 19:16 GPIO52 Master CPU Select
    Uint16 GPIO53:4;                    // 23:20 GPIO53 Master CPU Select
    Uint16 GPIO54:4;                    // 27:24 GPIO54 Master CPU Select
    Uint16 GPIO55:4;                    // 31:28 GPIO55 Master CPU Select
};

union GPBCSEL3_REG {
    Uint32  all;
    struct  GPBCSEL3_BITS  bit;
};

#ifdef CPU1
// GPBCSEL3 Register
//// GPBCSEL3 Register : Byte Value
#define GPBCSEL3_GPIO055_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO055_CPU1_CLA1Host					0x10000000UL
#define GPBCSEL3_GPIO055_CPU2Host						0x20000000UL
#define GPBCSEL3_GPIO055_CPU2_CLA1Host					0x30000000UL

#define GPBCSEL3_GPIO054_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO054_CPU1_CLA1Host					0x01000000UL
#define GPBCSEL3_GPIO054_CPU2Host						0x02000000UL
#define GPBCSEL3_GPIO054_CPU2_CLA1Host					0x03000000UL

#define GPBCSEL3_GPIO053_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO053_CPU1_CLA1Host					0x00100000UL
#define GPBCSEL3_GPIO053_CPU2Host						0x00200000UL
#define GPBCSEL3_GPIO053_CPU2_CLA1Host					0x00300000UL

#define GPBCSEL3_GPIO052_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO052_CPU1_CLA1Host					0x00010000UL
#define GPBCSEL3_GPIO052_CPU2Host						0x00020000UL
#define GPBCSEL3_GPIO052_CPU2_CLA1Host					0x00030000UL

#define GPBCSEL3_GPIO051_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO051_CPU1_CLA1Host					0x00001000UL
#define GPBCSEL3_GPIO051_CPU2Host						0x00002000UL
#define GPBCSEL3_GPIO051_CPU2_CLA1Host					0x00003000UL

#define GPBCSEL3_GPIO050_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO050_CPU1_CLA1Host					0x00000100UL
#define GPBCSEL3_GPIO050_CPU2Host						0x00000200UL
#define GPBCSEL3_GPIO050_CPU2_CLA1Host					0x00000300UL

#define GPBCSEL3_GPIO049_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO049_CPU1_CLA1Host					0x00000010UL
#define GPBCSEL3_GPIO049_CPU2Host						0x00000020UL
#define GPBCSEL3_GPIO049_CPU2_CLA1Host					0x00000030UL

#define GPBCSEL3_GPIO048_CPU1Host						0x00000000UL
#define GPBCSEL3_GPIO048_CPU1_CLA1Host					0x00000001UL
#define GPBCSEL3_GPIO048_CPU2Host						0x00000002UL
#define GPBCSEL3_GPIO048_CPU2_CLA1Host					0x00000003UL

//// GPBCSEL3 Register : Quick Value
#define GPBCSEL3_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPBCSEL4_BITS {                  // bits description
    Uint16 GPIO56:4;                    // 3:0 GPIO56 Master CPU Select
    Uint16 GPIO57:4;                    // 7:4 GPIO57 Master CPU Select
    Uint16 GPIO58:4;                    // 11:8 GPIO58 Master CPU Select
    Uint16 GPIO59:4;                    // 15:12 GPIO59 Master CPU Select
    Uint16 GPIO60:4;                    // 19:16 GPIO60 Master CPU Select
    Uint16 GPIO61:4;                    // 23:20 GPIO61 Master CPU Select
    Uint16 GPIO62:4;                    // 27:24 GPIO62 Master CPU Select
    Uint16 GPIO63:4;                    // 31:28 GPIO63 Master CPU Select
};

union GPBCSEL4_REG {
    Uint32  all;
    struct  GPBCSEL4_BITS  bit;
};

#ifdef CPU1
// GPBCSEL4 Register
//// GPBCSEL4 Register : Byte Value
#define GPBCSEL4_GPIO063_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO063_CPU1_CLA1Host					0x10000000UL
#define GPBCSEL4_GPIO063_CPU2Host						0x20000000UL
#define GPBCSEL4_GPIO063_CPU2_CLA1Host					0x30000000UL

#define GPBCSEL4_GPIO062_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO062_CPU1_CLA1Host					0x01000000UL
#define GPBCSEL4_GPIO062_CPU2Host						0x02000000UL
#define GPBCSEL4_GPIO062_CPU2_CLA1Host					0x03000000UL

#define GPBCSEL4_GPIO061_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO061_CPU1_CLA1Host					0x00100000UL
#define GPBCSEL4_GPIO061_CPU2Host						0x00200000UL
#define GPBCSEL4_GPIO061_CPU2_CLA1Host					0x00300000UL

#define GPBCSEL4_GPIO060_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO060_CPU1_CLA1Host					0x00010000UL
#define GPBCSEL4_GPIO060_CPU2Host						0x00020000UL
#define GPBCSEL4_GPIO060_CPU2_CLA1Host					0x00030000UL

#define GPBCSEL4_GPIO059_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO059_CPU1_CLA1Host					0x00001000UL
#define GPBCSEL4_GPIO059_CPU2Host						0x00002000UL
#define GPBCSEL4_GPIO059_CPU2_CLA1Host					0x00003000UL

#define GPBCSEL4_GPIO058_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO058_CPU1_CLA1Host					0x00000100UL
#define GPBCSEL4_GPIO058_CPU2Host						0x00000200UL
#define GPBCSEL4_GPIO058_CPU2_CLA1Host					0x00000300UL

#define GPBCSEL4_GPIO057_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO057_CPU1_CLA1Host					0x00000010UL
#define GPBCSEL4_GPIO057_CPU2Host						0x00000020UL
#define GPBCSEL4_GPIO057_CPU2_CLA1Host					0x00000030UL

#define GPBCSEL4_GPIO056_CPU1Host						0x00000000UL
#define GPBCSEL4_GPIO056_CPU1_CLA1Host					0x00000001UL
#define GPBCSEL4_GPIO056_CPU2Host						0x00000002UL
#define GPBCSEL4_GPIO056_CPU2_CLA1Host					0x00000003UL

//// GPBCSEL4 Register : Quick Value
#define GPBCSEL4_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPBLOCK_BITS {                   // bits description
    Uint16 GPIO32:1;                    // 0 Configuration Lock bit for this pin
    Uint16 GPIO33:1;                    // 1 Configuration Lock bit for this pin
    Uint16 GPIO34:1;                    // 2 Configuration Lock bit for this pin
    Uint16 GPIO35:1;                    // 3 Configuration Lock bit for this pin
    Uint16 GPIO36:1;                    // 4 Configuration Lock bit for this pin
    Uint16 GPIO37:1;                    // 5 Configuration Lock bit for this pin
    Uint16 GPIO38:1;                    // 6 Configuration Lock bit for this pin
    Uint16 GPIO39:1;                    // 7 Configuration Lock bit for this pin
    Uint16 GPIO40:1;                    // 8 Configuration Lock bit for this pin
    Uint16 GPIO41:1;                    // 9 Configuration Lock bit for this pin
    Uint16 GPIO42:1;                    // 10 Configuration Lock bit for this pin
    Uint16 GPIO43:1;                    // 11 Configuration Lock bit for this pin
    Uint16 GPIO44:1;                    // 12 Configuration Lock bit for this pin
    Uint16 GPIO45:1;                    // 13 Configuration Lock bit for this pin
    Uint16 GPIO46:1;                    // 14 Configuration Lock bit for this pin
    Uint16 GPIO47:1;                    // 15 Configuration Lock bit for this pin
    Uint16 GPIO48:1;                    // 16 Configuration Lock bit for this pin
    Uint16 GPIO49:1;                    // 17 Configuration Lock bit for this pin
    Uint16 GPIO50:1;                    // 18 Configuration Lock bit for this pin
    Uint16 GPIO51:1;                    // 19 Configuration Lock bit for this pin
    Uint16 GPIO52:1;                    // 20 Configuration Lock bit for this pin
    Uint16 GPIO53:1;                    // 21 Configuration Lock bit for this pin
    Uint16 GPIO54:1;                    // 22 Configuration Lock bit for this pin
    Uint16 GPIO55:1;                    // 23 Configuration Lock bit for this pin
    Uint16 GPIO56:1;                    // 24 Configuration Lock bit for this pin
    Uint16 GPIO57:1;                    // 25 Configuration Lock bit for this pin
    Uint16 GPIO58:1;                    // 26 Configuration Lock bit for this pin
    Uint16 GPIO59:1;                    // 27 Configuration Lock bit for this pin
    Uint16 GPIO60:1;                    // 28 Configuration Lock bit for this pin
    Uint16 GPIO61:1;                    // 29 Configuration Lock bit for this pin
    Uint16 GPIO62:1;                    // 30 Configuration Lock bit for this pin
    Uint16 GPIO63:1;                    // 31 Configuration Lock bit for this pin
};

union GPBLOCK_REG {
    Uint32  all;
    struct  GPBLOCK_BITS  bit;
};

struct GPBCR_BITS {                     // bits description
    Uint16 GPIO32:1;                    // 0 Configuration lock commit bit for this pin
    Uint16 GPIO33:1;                    // 1 Configuration lock commit bit for this pin
    Uint16 GPIO34:1;                    // 2 Configuration lock commit bit for this pin
    Uint16 GPIO35:1;                    // 3 Configuration lock commit bit for this pin
    Uint16 GPIO36:1;                    // 4 Configuration lock commit bit for this pin
    Uint16 GPIO37:1;                    // 5 Configuration lock commit bit for this pin
    Uint16 GPIO38:1;                    // 6 Configuration lock commit bit for this pin
    Uint16 GPIO39:1;                    // 7 Configuration lock commit bit for this pin
    Uint16 GPIO40:1;                    // 8 Configuration lock commit bit for this pin
    Uint16 GPIO41:1;                    // 9 Configuration lock commit bit for this pin
    Uint16 GPIO42:1;                    // 10 Configuration lock commit bit for this pin
    Uint16 GPIO43:1;                    // 11 Configuration lock commit bit for this pin
    Uint16 GPIO44:1;                    // 12 Configuration lock commit bit for this pin
    Uint16 GPIO45:1;                    // 13 Configuration lock commit bit for this pin
    Uint16 GPIO46:1;                    // 14 Configuration lock commit bit for this pin
    Uint16 GPIO47:1;                    // 15 Configuration lock commit bit for this pin
    Uint16 GPIO48:1;                    // 16 Configuration lock commit bit for this pin
    Uint16 GPIO49:1;                    // 17 Configuration lock commit bit for this pin
    Uint16 GPIO50:1;                    // 18 Configuration lock commit bit for this pin
    Uint16 GPIO51:1;                    // 19 Configuration lock commit bit for this pin
    Uint16 GPIO52:1;                    // 20 Configuration lock commit bit for this pin
    Uint16 GPIO53:1;                    // 21 Configuration lock commit bit for this pin
    Uint16 GPIO54:1;                    // 22 Configuration lock commit bit for this pin
    Uint16 GPIO55:1;                    // 23 Configuration lock commit bit for this pin
    Uint16 GPIO56:1;                    // 24 Configuration lock commit bit for this pin
    Uint16 GPIO57:1;                    // 25 Configuration lock commit bit for this pin
    Uint16 GPIO58:1;                    // 26 Configuration lock commit bit for this pin
    Uint16 GPIO59:1;                    // 27 Configuration lock commit bit for this pin
    Uint16 GPIO60:1;                    // 28 Configuration lock commit bit for this pin
    Uint16 GPIO61:1;                    // 29 Configuration lock commit bit for this pin
    Uint16 GPIO62:1;                    // 30 Configuration lock commit bit for this pin
    Uint16 GPIO63:1;                    // 31 Configuration lock commit bit for this pin
};

union GPBCR_REG {
    Uint32  all;
    struct  GPBCR_BITS  bit;
};

struct GPCCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO64 to GPIO71
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO72 to GPIO79
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO80 to GPIO87
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO88 to GPIO95
};

union GPCCTRL_REG {
    Uint32  all;
    struct  GPCCTRL_BITS  bit;
};

#ifdef CPU1
// GPCCTRL Register
//// GPCCTRL Register : Byte Value
#define GPCCTRL_QUALPRD3_GPIO095to088_Value(val)		(((Uint32)val & 0x000000FFUL) << 24)
#define GPCCTRL_QUALPRD2_GPIO087to080_Value(val)		(((Uint32)val & 0x000000FFUL) << 16)
#define GPCCTRL_QUALPRD1_GPIO079to072_Value(val)		(((Uint32)val & 0x000000FFUL) << 8)
#define GPCCTRL_QUALPRD0_GPIO071to064_Value(val)		((Uint32)val & 0x000000FFUL)
#endif

struct GPCQSEL1_BITS {                  // bits description
    Uint16 GPIO64:2;                    // 1:0 Select input qualification type for GPIO64
    Uint16 GPIO65:2;                    // 3:2 Select input qualification type for GPIO65
    Uint16 GPIO66:2;                    // 5:4 Select input qualification type for GPIO66
    Uint16 GPIO67:2;                    // 7:6 Select input qualification type for GPIO67
    Uint16 GPIO68:2;                    // 9:8 Select input qualification type for GPIO68
    Uint16 GPIO69:2;                    // 11:10 Select input qualification type for GPIO69
    Uint16 GPIO70:2;                    // 13:12 Select input qualification type for GPIO70
    Uint16 GPIO71:2;                    // 15:14 Select input qualification type for GPIO71
    Uint16 GPIO72:2;                    // 17:16 Select input qualification type for GPIO72
    Uint16 GPIO73:2;                    // 19:18 Select input qualification type for GPIO73
    Uint16 GPIO74:2;                    // 21:20 Select input qualification type for GPIO74
    Uint16 GPIO75:2;                    // 23:22 Select input qualification type for GPIO75
    Uint16 GPIO76:2;                    // 25:24 Select input qualification type for GPIO76
    Uint16 GPIO77:2;                    // 27:26 Select input qualification type for GPIO77
    Uint16 GPIO78:2;                    // 29:28 Select input qualification type for GPIO78
    Uint16 GPIO79:2;                    // 31:30 Select input qualification type for GPIO79
};

union GPCQSEL1_REG {
    Uint32  all;
    struct  GPCQSEL1_BITS  bit;
};

#ifdef CPU1
// GPCQSEL1 Register
//// GPCQSEL1 Register : Byte Value
#define GPCQSEL1_GPIO079_Synch							0x00000000UL
#define GPCQSEL1_GPIO079_3SampSynch						0x40000000UL
#define GPCQSEL1_GPIO079_6SampSynch						0x80000000UL
#define GPCQSEL1_GPIO079_Asynch							0xC0000000UL

#define GPCQSEL1_GPIO078_Synch							0x00000000UL
#define GPCQSEL1_GPIO078_3SampSynch						0x10000000UL
#define GPCQSEL1_GPIO078_6SampSynch						0x20000000UL
#define GPCQSEL1_GPIO078_Asynch							0x30000000UL

#define GPCQSEL1_GPIO077_Synch							0x00000000UL
#define GPCQSEL1_GPIO077_3SampSynch						0x04000000UL
#define GPCQSEL1_GPIO077_6SampSynch						0x08000000UL
#define GPCQSEL1_GPIO077_Asynch							0x0C000000UL

#define GPCQSEL1_GPIO076_Synch							0x00000000UL
#define GPCQSEL1_GPIO076_3SampSynch						0x01000000UL
#define GPCQSEL1_GPIO076_6SampSynch						0x02000000UL
#define GPCQSEL1_GPIO076_Asynch							0x03000000UL

#define GPCQSEL1_GPIO075_Synch							0x00000000UL
#define GPCQSEL1_GPIO075_3SampSynch						0x00400000UL
#define GPCQSEL1_GPIO075_6SampSynch						0x00800000UL
#define GPCQSEL1_GPIO075_Asynch							0x00C00000UL

#define GPCQSEL1_GPIO074_Synch							0x00000000UL
#define GPCQSEL1_GPIO074_3SampSynch						0x00100000UL
#define GPCQSEL1_GPIO074_6SampSynch						0x00200000UL
#define GPCQSEL1_GPIO074_Asynch							0x00300000UL

#define GPCQSEL1_GPIO073_Synch							0x00000000UL
#define GPCQSEL1_GPIO073_3SampSynch						0x00040000UL
#define GPCQSEL1_GPIO073_6SampSynch						0x00080000UL
#define GPCQSEL1_GPIO073_Asynch							0x000C0000UL

#define GPCQSEL1_GPIO072_Synch							0x00000000UL
#define GPCQSEL1_GPIO072_3SampSynch						0x00010000UL
#define GPCQSEL1_GPIO072_6SampSynch						0x00020000UL
#define GPCQSEL1_GPIO072_Asynch							0x00030000UL

#define GPCQSEL1_GPIO071_Synch							0x00000000UL
#define GPCQSEL1_GPIO071_3SampSynch						0x00004000UL
#define GPCQSEL1_GPIO071_6SampSynch						0x00008000UL
#define GPCQSEL1_GPIO071_Asynch							0x0000C000UL

#define GPCQSEL1_GPIO070_Synch							0x00000000UL
#define GPCQSEL1_GPIO070_3SampSynch						0x00001000UL
#define GPCQSEL1_GPIO070_6SampSynch						0x00002000UL
#define GPCQSEL1_GPIO070_Asynch							0x00003000UL

#define GPCQSEL1_GPIO069_Synch							0x00000000UL
#define GPCQSEL1_GPIO069_3SampSynch						0x00000400UL
#define GPCQSEL1_GPIO069_6SampSynch						0x00000800UL
#define GPCQSEL1_GPIO069_Asynch							0x00000C00UL

#define GPCQSEL1_GPIO068_Synch							0x00000000UL
#define GPCQSEL1_GPIO068_3SampSynch						0x00000100UL
#define GPCQSEL1_GPIO068_6SampSynch						0x00000200UL
#define GPCQSEL1_GPIO068_Asynch							0x00000300UL

#define GPCQSEL1_GPIO067_Synch							0x00000000UL
#define GPCQSEL1_GPIO067_3SampSynch						0x00000040UL
#define GPCQSEL1_GPIO067_6SampSynch						0x00000080UL
#define GPCQSEL1_GPIO067_Asynch							0x000000C0UL

#define GPCQSEL1_GPIO066_Synch							0x00000000UL
#define GPCQSEL1_GPIO066_3SampSynch						0x00000010UL
#define GPCQSEL1_GPIO066_6SampSynch						0x00000020UL
#define GPCQSEL1_GPIO066_Asynch							0x00000030UL

#define GPCQSEL1_GPIO065_Synch							0x00000000UL
#define GPCQSEL1_GPIO065_3SampSynch						0x00000004UL
#define GPCQSEL1_GPIO065_6SampSynch						0x00000008UL
#define GPCQSEL1_GPIO065_Asynch							0x0000000CUL

#define GPCQSEL1_GPIO064_Synch							0x00000000UL
#define GPCQSEL1_GPIO064_3SampSynch						0x00000001UL
#define GPCQSEL1_GPIO064_6SampSynch						0x00000002UL
#define GPCQSEL1_GPIO064_Asynch							0x00000003UL
#endif

struct GPCQSEL2_BITS {                  // bits description
    Uint16 GPIO80:2;                    // 1:0 Select input qualification type for GPIO80
    Uint16 GPIO81:2;                    // 3:2 Select input qualification type for GPIO81
    Uint16 GPIO82:2;                    // 5:4 Select input qualification type for GPIO82
    Uint16 GPIO83:2;                    // 7:6 Select input qualification type for GPIO83
    Uint16 GPIO84:2;                    // 9:8 Select input qualification type for GPIO84
    Uint16 GPIO85:2;                    // 11:10 Select input qualification type for GPIO85
    Uint16 GPIO86:2;                    // 13:12 Select input qualification type for GPIO86
    Uint16 GPIO87:2;                    // 15:14 Select input qualification type for GPIO87
    Uint16 GPIO88:2;                    // 17:16 Select input qualification type for GPIO88
    Uint16 GPIO89:2;                    // 19:18 Select input qualification type for GPIO89
    Uint16 GPIO90:2;                    // 21:20 Select input qualification type for GPIO90
    Uint16 GPIO91:2;                    // 23:22 Select input qualification type for GPIO91
    Uint16 GPIO92:2;                    // 25:24 Select input qualification type for GPIO92
    Uint16 GPIO93:2;                    // 27:26 Select input qualification type for GPIO93
    Uint16 GPIO94:2;                    // 29:28 Select input qualification type for GPIO94
    Uint16 GPIO95:2;                    // 31:30 Select input qualification type for GPIO95
};

union GPCQSEL2_REG {
    Uint32  all;
    struct  GPCQSEL2_BITS  bit;
};

#ifdef CPU1
// GPCQSEL2 Register
//// GPCQSEL2 Register : Byte Value
#define GPCQSEL2_GPIO095_Synch							0x00000000UL
#define GPCQSEL2_GPIO095_3SampSynch						0x40000000UL
#define GPCQSEL2_GPIO095_6SampSynch						0x80000000UL
#define GPCQSEL2_GPIO095_Asynch							0xC0000000UL

#define GPCQSEL2_GPIO094_Synch							0x00000000UL
#define GPCQSEL2_GPIO094_3SampSynch						0x10000000UL
#define GPCQSEL2_GPIO094_6SampSynch						0x20000000UL
#define GPCQSEL2_GPIO094_Asynch							0x30000000UL

#define GPCQSEL2_GPIO093_Synch							0x00000000UL
#define GPCQSEL2_GPIO093_3SampSynch						0x04000000UL
#define GPCQSEL2_GPIO093_6SampSynch						0x08000000UL
#define GPCQSEL2_GPIO093_Asynch							0x0C000000UL

#define GPCQSEL2_GPIO092_Synch							0x00000000UL
#define GPCQSEL2_GPIO092_3SampSynch						0x01000000UL
#define GPCQSEL2_GPIO092_6SampSynch						0x02000000UL
#define GPCQSEL2_GPIO092_Asynch							0x03000000UL

#define GPCQSEL2_GPIO091_Synch							0x00000000UL
#define GPCQSEL2_GPIO091_3SampSynch						0x00400000UL
#define GPCQSEL2_GPIO091_6SampSynch						0x00800000UL
#define GPCQSEL2_GPIO091_Asynch							0x00C00000UL

#define GPCQSEL2_GPIO090_Synch							0x00000000UL
#define GPCQSEL2_GPIO090_3SampSynch						0x00100000UL
#define GPCQSEL2_GPIO090_6SampSynch						0x00200000UL
#define GPCQSEL2_GPIO090_Asynch							0x00300000UL

#define GPCQSEL2_GPIO089_Synch							0x00000000UL
#define GPCQSEL2_GPIO089_3SampSynch						0x00040000UL
#define GPCQSEL2_GPIO089_6SampSynch						0x00080000UL
#define GPCQSEL2_GPIO089_Asynch							0x000C0000UL

#define GPCQSEL2_GPIO088_Synch							0x00000000UL
#define GPCQSEL2_GPIO088_3SampSynch						0x00010000UL
#define GPCQSEL2_GPIO088_6SampSynch						0x00020000UL
#define GPCQSEL2_GPIO088_Asynch							0x00030000UL

#define GPCQSEL2_GPIO087_Synch							0x00000000UL
#define GPCQSEL2_GPIO087_3SampSynch						0x00004000UL
#define GPCQSEL2_GPIO087_6SampSynch						0x00008000UL
#define GPCQSEL2_GPIO087_Asynch							0x0000C000UL

#define GPCQSEL2_GPIO086_Synch							0x00000000UL
#define GPCQSEL2_GPIO086_3SampSynch						0x00001000UL
#define GPCQSEL2_GPIO086_6SampSynch						0x00002000UL
#define GPCQSEL2_GPIO086_Asynch							0x00003000UL

#define GPCQSEL2_GPIO085_Synch							0x00000000UL
#define GPCQSEL2_GPIO085_3SampSynch						0x00000400UL
#define GPCQSEL2_GPIO085_6SampSynch						0x00000800UL
#define GPCQSEL2_GPIO085_Asynch							0x00000C00UL

#define GPCQSEL2_GPIO084_Synch							0x00000000UL
#define GPCQSEL2_GPIO084_3SampSynch						0x00000100UL
#define GPCQSEL2_GPIO084_6SampSynch						0x00000200UL
#define GPCQSEL2_GPIO084_Asynch							0x00000300UL

#define GPCQSEL2_GPIO083_Synch							0x00000000UL
#define GPCQSEL2_GPIO083_3SampSynch						0x00000040UL
#define GPCQSEL2_GPIO083_6SampSynch						0x00000080UL
#define GPCQSEL2_GPIO083_Asynch							0x000000C0UL

#define GPCQSEL2_GPIO082_Synch							0x00000000UL
#define GPCQSEL2_GPIO082_3SampSynch						0x00000010UL
#define GPCQSEL2_GPIO082_6SampSynch						0x00000020UL
#define GPCQSEL2_GPIO082_Asynch							0x00000030UL

#define GPCQSEL2_GPIO081_Synch							0x00000000UL
#define GPCQSEL2_GPIO081_3SampSynch						0x00000004UL
#define GPCQSEL2_GPIO081_6SampSynch						0x00000008UL
#define GPCQSEL2_GPIO081_Asynch							0x0000000CUL

#define GPCQSEL2_GPIO080_Synch							0x00000000UL
#define GPCQSEL2_GPIO080_3SampSynch						0x00000001UL
#define GPCQSEL2_GPIO080_6SampSynch						0x00000002UL
#define GPCQSEL2_GPIO080_Asynch							0x00000003UL
#endif

struct GPCMUX1_BITS {                   // bits description
    Uint16 GPIO64:2;                    // 1:0 Defines pin-muxing selection for GPIO64
    Uint16 GPIO65:2;                    // 3:2 Defines pin-muxing selection for GPIO65
    Uint16 GPIO66:2;                    // 5:4 Defines pin-muxing selection for GPIO66
    Uint16 GPIO67:2;                    // 7:6 Defines pin-muxing selection for GPIO67
    Uint16 GPIO68:2;                    // 9:8 Defines pin-muxing selection for GPIO68
    Uint16 GPIO69:2;                    // 11:10 Defines pin-muxing selection for GPIO69
    Uint16 GPIO70:2;                    // 13:12 Defines pin-muxing selection for GPIO70
    Uint16 GPIO71:2;                    // 15:14 Defines pin-muxing selection for GPIO71
    Uint16 GPIO72:2;                    // 17:16 Defines pin-muxing selection for GPIO72
    Uint16 GPIO73:2;                    // 19:18 Defines pin-muxing selection for GPIO73
    Uint16 GPIO74:2;                    // 21:20 Defines pin-muxing selection for GPIO74
    Uint16 GPIO75:2;                    // 23:22 Defines pin-muxing selection for GPIO75
    Uint16 GPIO76:2;                    // 25:24 Defines pin-muxing selection for GPIO76
    Uint16 GPIO77:2;                    // 27:26 Defines pin-muxing selection for GPIO77
    Uint16 GPIO78:2;                    // 29:28 Defines pin-muxing selection for GPIO78
    Uint16 GPIO79:2;                    // 31:30 Defines pin-muxing selection for GPIO79
};

union GPCMUX1_REG {
    Uint32  all;
    struct  GPCMUX1_BITS  bit;
};

#ifdef CPU1
// GPCMUX1 Register
//// GPCMUX1 Register : Byte Value													// GMUX		MUX
#define GPCMUX1_GPIO079_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO079_InOutEM1D5						0x80000000UL				// 0b00		0b10
#define GPCMUX1_GPIO079_InEQEP2B						0x80000000UL				// 0b01		0b10

#define GPCMUX1_GPIO078_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO078_InOutEM1D6						0x20000000UL				// 0b00		0b10
#define GPCMUX1_GPIO078_InEQEP2A						0x20000000UL				// 0b01		0b10

#define GPCMUX1_GPIO077_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO077_InOutEM1D7						0x08000000UL				// 0b00		0b10
#define GPCMUX1_GPIO077_InSCIRXDD						0x08000000UL				// 0b01		0b10

#define GPCMUX1_GPIO076_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO076_InOutEM1D8						0x02000000UL				// 0b00		0b10
#define GPCMUX1_GPIO076_OutSCITXDD						0x02000000UL				// 0b01		0b10

#define GPCMUX1_GPIO075_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO075_InOutEM1D9						0x00800000UL				// 0b00		0b10

#define GPCMUX1_GPIO074_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO074_InOutEM1D10						0x00200000UL				// 0b00		0b10

#define GPCMUX1_GPIO073_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO073_InOutEM1D11						0x00080000UL				// 0b00		0b10
#define GPCMUX1_GPIO073_OutXCLKOUT						0x000C0000UL				// 0b00		0b11
#define GPCMUX1_GPIO073_InCANRXB						0x00040000UL				// 0b01		0b01
#define GPCMUX1_GPIO073_InSCIRXDC						0x00080000UL				// 0b01		0b10

#define GPCMUX1_GPIO072_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO072_InOutEM1D12						0x00020000UL				// 0b00		0b10
#define GPCMUX1_GPIO072_OutCANTXB						0x00010000UL				// 0b01		0b01
#define GPCMUX1_GPIO072_OutSCITXDC						0x00020000UL				// 0b01		0b10
#define GPCMUX1_GPIO072_InOutHSPnSPISTEC				0x00030000UL				// 0b11		0b11

#define GPCMUX1_GPIO071_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO071_InOutEM1D13						0x00008000UL				// 0b00		0b10
#define GPCMUX1_GPIO071_OutCANTXA						0x00004000UL				// 0b01		0b01
#define GPCMUX1_GPIO071_InSCIRXDB						0x00008000UL				// 0b01		0b10
#define GPCMUX1_GPIO071_InOutSPICLKC					0x0000C000UL				// 0b11		0b11

#define GPCMUX1_GPIO070_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO070_InOutEM1D14						0x00002000UL				// 0b00		0b10
#define GPCMUX1_GPIO070_InCANRXA						0x00001000UL				// 0b01		0b01
#define GPCMUX1_GPIO070_OutSCITXDB						0x00002000UL				// 0b01		0b10
#define GPCMUX1_GPIO070_InOutHSPSPISOMIC				0x00003000UL				// 0b11		0b11

#define GPCMUX1_GPIO069_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO069_InOutEM1D15						0x00000800UL				// 0b00		0b10
#define GPCMUX1_GPIO069_InODSCLB						0x00000800UL				// 0b01		0b10
#define GPCMUX1_GPIO069_InOutHSPSPISIMOC				0x00000C00UL				// 0b11		0b11

#define GPCMUX1_GPIO068_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO068_InOutEM1D16						0x00000200UL				// 0b00		0b10
#define GPCMUX1_GPIO068_InOutEM2D0						0x00000300UL				// 0b00		0b11

#define GPCMUX1_GPIO067_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO067_InOutEM1D17						0x00000080UL				// 0b00		0b10
#define GPCMUX1_GPIO067_InOutEM2D1						0x000000C0UL				// 0b00		0b11

#define GPCMUX1_GPIO066_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO066_InOutEM1D18						0x00000020UL				// 0b00		0b10
#define GPCMUX1_GPIO066_InOutEM2D2						0x00000030UL				// 0b00		0b11
#define GPCMUX1_GPIO066_InODSDAB						0x00000020UL				// 0b01		0b10
#define GPCMUX1_GPIO066_InOutHSPnSPISTEB				0x00000030UL				// 0b11		0b11

#define GPCMUX1_GPIO065_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO065_InOutEM1D19						0x00000008UL				// 0b00		0b10
#define GPCMUX1_GPIO065_InOutEM2D3						0x0000000CUL				// 0b00		0b11
#define GPCMUX1_GPIO065_InOutEQEP3I						0x00000004UL				// 0b01		0b01
#define GPCMUX1_GPIO065_OutSCITXDA						0x00000008UL				// 0b01		0b10
#define GPCMUX1_GPIO065_InOutHSPSPICLKB					0x0000000CUL				// 0b11		0b11

#define GPCMUX1_GPIO064_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX1_GPIO064_InOutEM1D20						0x00000002UL				// 0b00		0b10
#define GPCMUX1_GPIO064_InOutEM2D4						0x00000003UL				// 0b00		0b11
#define GPCMUX1_GPIO064_InOutEQEP3S						0x00000001UL				// 0b01		0b01
#define GPCMUX1_GPIO064_InInSCIRXDA						0x00000002UL				// 0b01		0b10
#define GPCMUX1_GPIO064_InOutHSPSPISOMIB				0x00000003UL				// 0b11		0b11

//// GPCMUX1 Register : Bit Value													// GMUX		MUX
#define MUX_GPIO079_InOutGPIO							0U							// -		0b00
#define MUX_GPIO079_InOutEM1D5							2U							// 0b00		0b10
#define MUX_GPIO079_InEQEP2B							2U							// 0b01		0b10

#define MUX_GPIO078_InOutGPIO							0U							// -		0b00
#define MUX_GPIO078_InOutEM1D6							2U							// 0b00		0b10
#define MUX_GPIO078_InEQEP2A							2U							// 0b01		0b10

#define MUX_GPIO077_InOutGPIO							0U							// -		0b00
#define MUX_GPIO077_InOutEM1D7							2U							// 0b00		0b10
#define MUX_GPIO077_InSCIRXDD							2U							// 0b01		0b10

#define MUX_GPIO076_InOutGPIO							0U							// -		0b00
#define MUX_GPIO076_InOutEM1D8							2U							// 0b00		0b10
#define MUX_GPIO076_OutSCITXDD							2U							// 0b01		0b10

#define MUX_GPIO075_InOutGPIO							0U							// -		0b00
#define MUX_GPIO075_InOutEM1D9							2U							// 0b00		0b10

#define MUX_GPIO074_InOutGPIO							0U							// -		0b00
#define MUX_GPIO074_InOutEM1D10							2U							// 0b00		0b10

#define MUX_GPIO073_InOutGPIO							0U							// -		0b00
#define MUX_GPIO073_InOutEM1D11							2U							// 0b00		0b10
#define MUX_GPIO073_OutXCLKOUT							3U							// 0b00		0b11
#define MUX_GPIO073_InCANRXB							1U							// 0b01		0b01
#define MUX_GPIO073_InSCIRXDC							2U							// 0b01		0b10

#define MUX_GPIO072_InOutGPIO							0U							// -		0b00
#define MUX_GPIO072_InOutEM1D12							2U							// 0b00		0b10
#define MUX_GPIO072_OutCANTXB							1U							// 0b01		0b01
#define MUX_GPIO072_OutSCITXDC							2U							// 0b01		0b10
#define MUX_GPIO072_InOutHSPnSPISTEC					3U							// 0b11		0b11

#define MUX_GPIO071_InOutGPIO							0U							// -		0b00
#define MUX_GPIO071_InOutEM1D13							2U							// 0b00		0b10
#define MUX_GPIO071_OutCANTXA							1U							// 0b01		0b01
#define MUX_GPIO071_InSCIRXDB							2U							// 0b01		0b10
#define MUX_GPIO071_InOutSPICLKC						3U							// 0b11		0b11

#define MUX_GPIO070_InOutGPIO							0U							// -		0b00
#define MUX_GPIO070_InOutEM1D14							2U							// 0b00		0b10
#define MUX_GPIO070_InCANRXA							1U							// 0b01		0b01
#define MUX_GPIO070_OutSCITXDB							2U							// 0b01		0b10
#define MUX_GPIO070_InOutHSPSPISOMIC					3U							// 0b11		0b11

#define MUX_GPIO069_InOutGPIO							0U							// -		0b00
#define MUX_GPIO069_InOutEM1D15							2U							// 0b00		0b10
#define MUX_GPIO069_InODSCLB							2U							// 0b01		0b10
#define MUX_GPIO069_InOutHSPSPISIMOC					3U							// 0b11		0b11

#define MUX_GPIO068_InOutGPIO							0U							// -		0b00
#define MUX_GPIO068_InOutEM1D16							2U							// 0b00		0b10
#define MUX_GPIO068_InOutEM2D0							3U							// 0b00		0b11

#define MUX_GPIO067_InOutGPIO							0U							// -		0b00
#define MUX_GPIO067_InOutEM1D17							2U							// 0b00		0b10
#define MUX_GPIO067_InOutEM2D1							3U							// 0b00		0b11

#define MUX_GPIO066_InOutGPIO							0U							// -		0b00
#define MUX_GPIO066_InOutEM1D18							2U							// 0b00		0b10
#define MUX_GPIO066_InOutEM2D2							3U							// 0b00		0b11
#define MUX_GPIO066_InODSDAB							2U							// 0b01		0b10
#define MUX_GPIO066_InOutHSPnSPISTEB					3U							// 0b11		0b11

#define MUX_GPIO065_InOutGPIO							0U							// -		0b00
#define MUX_GPIO065_InOutEM1D19							2U							// 0b00		0b10
#define MUX_GPIO065_InOutEM2D3							3U							// 0b00		0b11
#define MUX_GPIO065_InOutEQEP3I							1U							// 0b01		0b01
#define MUX_GPIO065_OutSCITXDA							2U							// 0b01		0b10
#define MUX_GPIO065_InOutHSPSPICLKB						3U							// 0b11		0b11

#define MUX_GPIO064_InOutGPIO							0U							// -		0b00
#define MUX_GPIO064_InOutEM1D20							2U							// 0b00		0b10
#define MUX_GPIO064_InOutEM2D4							3U							// 0b00		0b11
#define MUX_GPIO064_InOutEQEP3S							1U							// 0b01		0b01
#define MUX_GPIO064_InInSCIRXDA							2U							// 0b01		0b10
#define MUX_GPIO064_InOutHSPSPISOMIB					3U							// 0b11		0b11
#endif


struct GPCMUX2_BITS {                   // bits description
    Uint16 GPIO80:2;                    // 1:0 Defines pin-muxing selection for GPIO80
    Uint16 GPIO81:2;                    // 3:2 Defines pin-muxing selection for GPIO81
    Uint16 GPIO82:2;                    // 5:4 Defines pin-muxing selection for GPIO82
    Uint16 GPIO83:2;                    // 7:6 Defines pin-muxing selection for GPIO83
    Uint16 GPIO84:2;                    // 9:8 Defines pin-muxing selection for GPIO84
    Uint16 GPIO85:2;                    // 11:10 Defines pin-muxing selection for GPIO85
    Uint16 GPIO86:2;                    // 13:12 Defines pin-muxing selection for GPIO86
    Uint16 GPIO87:2;                    // 15:14 Defines pin-muxing selection for GPIO87
    Uint16 GPIO88:2;                    // 17:16 Defines pin-muxing selection for GPIO88
    Uint16 GPIO89:2;                    // 19:18 Defines pin-muxing selection for GPIO89
    Uint16 GPIO90:2;                    // 21:20 Defines pin-muxing selection for GPIO90
    Uint16 GPIO91:2;                    // 23:22 Defines pin-muxing selection for GPIO91
    Uint16 GPIO92:2;                    // 25:24 Defines pin-muxing selection for GPIO92
    Uint16 GPIO93:2;                    // 27:26 Defines pin-muxing selection for GPIO93
    Uint16 GPIO94:2;                    // 29:28 Defines pin-muxing selection for GPIO94
    Uint16 GPIO95:2;                    // 31:30 Defines pin-muxing selection for GPIO95
};

union GPCMUX2_REG {
    Uint32  all;
    struct  GPCMUX2_BITS  bit;
};

#ifdef CPU1
// GPCMUX2 Register
//// GPCMUX2 Register : Byte Value													// GMUX		MUX
#define GPCMUX2_GPIO095_InOutGPIO						0x00000000UL				// -		0b00

#define GPCMUX2_GPIO094_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO094_InSCIRXDD						0x20000000UL				// 0b01		0b10

#define GPCMUX2_GPIO093_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO093_OutEM1BA0						0x0C000000UL				// 0b00		0b11
#define GPCMUX2_GPIO093_OutSCITXDD						0x08000000UL				// 0b01		0b10

#define GPCMUX2_GPIO092_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO092_OutEM1A19						0x02000000UL				// 0b00		0b10
#define GPCMUX2_GPIO092_OutEM1BA1						0x03000000UL				// 0b00		0b11
#define GPCMUX2_GPIO092_InODSCLA						0x02000000UL				// 0b01		0b10

#define GPCMUX2_GPIO091_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO091_OutEM1A18						0x00800000UL				// 0b00		0b10
#define GPCMUX2_GPIO091_OutEM1DQM3						0x00C00000UL				// 0b00		0b11
#define GPCMUX2_GPIO091_InODSDAA						0x00800000UL				// 0b01		0b10

#define GPCMUX2_GPIO090_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO090_OutEM1A17						0x00200000UL				// 0b00		0b10
#define GPCMUX2_GPIO090_OutEM1DQM2						0x00300000UL				// 0b00		0b11
#define GPCMUX2_GPIO090_InSCIRXDC						0x00200000UL				// 0b01		0b10

#define GPCMUX2_GPIO089_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO089_OutEM1A16						0x00080000UL				// 0b00		0b10
#define GPCMUX2_GPIO089_OutEM1DQM1						0x000C0000UL				// 0b00		0b11
#define GPCMUX2_GPIO089_OutSCITXDC						0x00080000UL				// 0b01		0b10

#define GPCMUX2_GPIO088_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO088_OutEM1A15						0x00020000UL				// 0b00		0b10
#define GPCMUX2_GPIO088_OutEM1DQM0						0x00030000UL				// 0b00		0b11

#define GPCMUX2_GPIO087_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO087_OutEM1A14						0x00008000UL				// 0b00		0b10
#define GPCMUX2_GPIO087_OutEM1RAS						0x0000C000UL				// 0b00		0b11
#define GPCMUX2_GPIO087_InSCIRXDB						0x00004000UL				// 0b01		0b01
#define GPCMUX2_GPIO087_InOutMFSXB						0x00008000UL				// 0b01		0b10
#define GPCMUX2_GPIO087_InOutMFSXA						0x0000C000UL				// 0b11		0b11

#define GPCMUX2_GPIO086_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO086_OutEM1A13						0x00002000UL				// 0b00		0b10
#define GPCMUX2_GPIO086_OutEM1CAS						0x00003000UL				// 0b00		0b11
#define GPCMUX2_GPIO086_OutSCIRXDB						0x00001000UL				// 0b01		0b01
#define GPCMUX2_GPIO086_InOutMCLKXB						0x00002000UL				// 0b01		0b10
#define GPCMUX2_GPIO086_InOutMCLKXA						0x00003000UL				// 0b11		0b11

#define GPCMUX2_GPIO085_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO085_InOutEM1D0						0x00000800UL				// 0b00		0b10
#define GPCMUX2_GPIO085_InSCIRXDA						0x00000400UL				// 0b01		0b01
#define GPCMUX2_GPIO085_InMDRB							0x00000800UL				// 0b01		0b10
#define GPCMUX2_GPIO085_InMDRA							0x00000C00UL				// 0b11		0b11

#define GPCMUX2_GPIO084_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO084_OutSCITXDA						0x00000100UL				// 0b01		0b01
#define GPCMUX2_GPIO084_OutMDXB							0x00000200UL				// 0b01		0b10
#define GPCMUX2_GPIO084_OutMDXA							0x00000300UL				// 0b11		0b11

#define GPCMUX2_GPIO083_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO083_InOutEM1D1						0x00000080UL				// 0b00		0b10

#define GPCMUX2_GPIO082_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO082_InOutEM1D2						0x00000020UL				// 0b00		0b10

#define GPCMUX2_GPIO081_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO081_InOutEM1D3						0x00000008UL				// 0b00		0b10
#define GPCMUX2_GPIO081_InOutEQEP2I						0x00000008UL				// 0b01		0b10

#define GPCMUX2_GPIO080_InOutGPIO						0x00000000UL				// -		0b00
#define GPCMUX2_GPIO080_InOutEM1D4						0x00000002UL				// 0b00		0b10
#define GPCMUX2_GPIO080_InOutEQEP2S						0x00000002UL				// 0b01		0b10
#endif

struct GPCDIR_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO65:1;                    // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO66:1;                    // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO67:1;                    // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO68:1;                    // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO69:1;                    // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO70:1;                    // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO71:1;                    // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO72:1;                    // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO73:1;                    // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO74:1;                    // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO75:1;                    // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO76:1;                    // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO77:1;                    // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO78:1;                    // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO79:1;                    // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO80:1;                    // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO81:1;                    // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO82:1;                    // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO83:1;                    // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO84:1;                    // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO85:1;                    // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO86:1;                    // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO87:1;                    // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO88:1;                    // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO89:1;                    // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO90:1;                    // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO91:1;                    // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO92:1;                    // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO93:1;                    // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO94:1;                    // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO95:1;                    // 31 Defines direction for this pin in GPIO mode
};

union GPCDIR_REG {
    Uint32  all;
    struct  GPCDIR_BITS  bit;
};

#ifdef CPU1
// GPCDIR Register
//// GPCDIR Register : Byte Value
#define GPCDIR_GPIO095_Input							0x00000000UL
#define GPCDIR_GPIO0695Output							0x80000000UL

#define GPCDIR_GPIO094_Input							0x00000000UL
#define GPCDIR_GPIO094_Output							0x40000000UL

#define GPCDIR_GPIO093_Input							0x00000000UL
#define GPCDIR_GPIO093_Output							0x20000000UL

#define GPCDIR_GPIO092_Input							0x00000000UL
#define GPCDIR_GPIO092_Output							0x10000000UL

#define GPCDIR_GPIO091_Input							0x00000000UL
#define GPCDIR_GPIO091_Output							0x08000000UL

#define GPCDIR_GPIO090_Input							0x00000000UL
#define GPCDIR_GPIO090_Output							0x04000000UL

#define GPCDIR_GPIO089_Input							0x00000000UL
#define GPCDIR_GPIO089_Output							0x02000000UL

#define GPCDIR_GPIO088_Input							0x00000000UL
#define GPCDIR_GPIO088_Output							0x01000000UL

#define GPCDIR_GPIO087_Input							0x00000000UL
#define GPCDIR_GPIO087_Output							0x00800000UL

#define GPCDIR_GPIO086_Input							0x00000000UL
#define GPCDIR_GPIO086_Output							0x00400000UL

#define GPCDIR_GPIO085_Input							0x00000000UL
#define GPCDIR_GPIO085_Output							0x00200000UL

#define GPCDIR_GPIO084_Input							0x00000000UL
#define GPCDIR_GPIO084_Output							0x00100000UL

#define GPCDIR_GPIO083_Input							0x00000000UL
#define GPCDIR_GPIO083_Output							0x00080000UL

#define GPCDIR_GPIO082_Input							0x00000000UL
#define GPCDIR_GPIO082_Output							0x00040000UL

#define GPCDIR_GPIO081_Input							0x00000000UL
#define GPCDIR_GPIO081_Output							0x00020000UL

#define GPCDIR_GPIO080_Input							0x00000000UL
#define GPCDIR_GPIO080_Output							0x00010000UL

#define GPCDIR_GPIO079_Input							0x00000000UL
#define GPCDIR_GPIO079_Output							0x00008000UL

#define GPCDIR_GPIO078_Input							0x00000000UL
#define GPCDIR_GPIO078_Output							0x00004000UL

#define GPCDIR_GPIO077_Input							0x00000000UL
#define GPCDIR_GPIO077_Output							0x00002000UL

#define GPCDIR_GPIO076_Input							0x00000000UL
#define GPCDIR_GPIO076_Output							0x00001000UL

#define GPCDIR_GPIO075_Input							0x00000000UL
#define GPCDIR_GPIO075_Output							0x00000800UL

#define GPCDIR_GPIO074_Input							0x00000000UL
#define GPCDIR_GPIO074_Output							0x00000400UL

#define GPCDIR_GPIO073_Input							0x00000000UL
#define GPCDIR_GPIO073_Output							0x00000200UL

#define GPCDIR_GPIO072_Input							0x00000000UL
#define GPCDIR_GPIO072_Output							0x00000100UL

#define GPCDIR_GPIO071_Input							0x00000000UL
#define GPCDIR_GPIO071_Output							0x00000080UL

#define GPCDIR_GPIO070_Input							0x00000000UL
#define GPCDIR_GPIO070_Output							0x00000040UL

#define GPCDIR_GPIO069_Input							0x00000000UL
#define GPCDIR_GPIO069_Output							0x00000020UL

#define GPCDIR_GPIO068_Input							0x00000000UL
#define GPCDIR_GPIO068_Output							0x00000010UL

#define GPCDIR_GPIO067_Input							0x00000000UL
#define GPCDIR_GPIO067_Output							0x00000008UL

#define GPCDIR_GPIO066_Input							0x00000000UL
#define GPCDIR_GPIO066_Output							0x00000004UL

#define GPCDIR_GPIO065_Input							0x00000000UL
#define GPCDIR_GPIO065_Output							0x00000002UL

#define GPCDIR_GPIO064_Input							0x00000000UL
#define GPCDIR_GPIO064_Output							0x00000001UL
#endif

struct GPCPUD_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Pull-Up Disable control for this pin
    Uint16 GPIO65:1;                    // 1 Pull-Up Disable control for this pin
    Uint16 GPIO66:1;                    // 2 Pull-Up Disable control for this pin
    Uint16 GPIO67:1;                    // 3 Pull-Up Disable control for this pin
    Uint16 GPIO68:1;                    // 4 Pull-Up Disable control for this pin
    Uint16 GPIO69:1;                    // 5 Pull-Up Disable control for this pin
    Uint16 GPIO70:1;                    // 6 Pull-Up Disable control for this pin
    Uint16 GPIO71:1;                    // 7 Pull-Up Disable control for this pin
    Uint16 GPIO72:1;                    // 8 Pull-Up Disable control for this pin
    Uint16 GPIO73:1;                    // 9 Pull-Up Disable control for this pin
    Uint16 GPIO74:1;                    // 10 Pull-Up Disable control for this pin
    Uint16 GPIO75:1;                    // 11 Pull-Up Disable control for this pin
    Uint16 GPIO76:1;                    // 12 Pull-Up Disable control for this pin
    Uint16 GPIO77:1;                    // 13 Pull-Up Disable control for this pin
    Uint16 GPIO78:1;                    // 14 Pull-Up Disable control for this pin
    Uint16 GPIO79:1;                    // 15 Pull-Up Disable control for this pin
    Uint16 GPIO80:1;                    // 16 Pull-Up Disable control for this pin
    Uint16 GPIO81:1;                    // 17 Pull-Up Disable control for this pin
    Uint16 GPIO82:1;                    // 18 Pull-Up Disable control for this pin
    Uint16 GPIO83:1;                    // 19 Pull-Up Disable control for this pin
    Uint16 GPIO84:1;                    // 20 Pull-Up Disable control for this pin
    Uint16 GPIO85:1;                    // 21 Pull-Up Disable control for this pin
    Uint16 GPIO86:1;                    // 22 Pull-Up Disable control for this pin
    Uint16 GPIO87:1;                    // 23 Pull-Up Disable control for this pin
    Uint16 GPIO88:1;                    // 24 Pull-Up Disable control for this pin
    Uint16 GPIO89:1;                    // 25 Pull-Up Disable control for this pin
    Uint16 GPIO90:1;                    // 26 Pull-Up Disable control for this pin
    Uint16 GPIO91:1;                    // 27 Pull-Up Disable control for this pin
    Uint16 GPIO92:1;                    // 28 Pull-Up Disable control for this pin
    Uint16 GPIO93:1;                    // 29 Pull-Up Disable control for this pin
    Uint16 GPIO94:1;                    // 30 Pull-Up Disable control for this pin
    Uint16 GPIO95:1;                    // 31 Pull-Up Disable control for this pin
};

union GPCPUD_REG {
    Uint32  all;
    struct  GPCPUD_BITS  bit;
};

#ifdef CPU1
// GPCPUD Register
//// GPCPUD Register : Byte Value
#define GPCPUD_GPIO095_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO095_PullUpDisable					0x80000000UL

#define GPCPUD_GPIO094_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO094_PullUpDisable					0x40000000UL

#define GPCPUD_GPIO093_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO093_PullUpDisable					0x20000000UL

#define GPCPUD_GPIO092_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO092_PullUpDisable					0x10000000UL

#define GPCPUD_GPIO091_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO091_PullUpDisable					0x08000000UL

#define GPCPUD_GPIO090_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO090_PullUpDisable					0x04000000UL

#define GPCPUD_GPIO089_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO089_PullUpDisable					0x02000000UL

#define GPCPUD_GPIO088_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO088_PullUpDisable					0x01000000UL

#define GPCPUD_GPIO087_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO087_PullUpDisable					0x00800000UL

#define GPCPUD_GPIO086_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO086_PullUpDisable					0x00400000UL

#define GPCPUD_GPIO085_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO085_PullUpDisable					0x00200000UL

#define GPCPUD_GPIO084_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO084_PullUpDisable					0x00100000UL

#define GPCPUD_GPIO083_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO083_PullUpDisable					0x00080000UL

#define GPCPUD_GPIO082_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO082_PullUpDisable					0x00040000UL

#define GPCPUD_GPIO081_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO081_PullUpDisable					0x00020000UL

#define GPCPUD_GPIO080_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO080_PullUpDisable					0x00010000UL

#define GPCPUD_GPIO079_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO079_PullUpDisable					0x00008000UL

#define GPCPUD_GPIO078_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO078_PullUpDisable					0x00004000UL

#define GPCPUD_GPIO077_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO077_PullUpDisable					0x00002000UL

#define GPCPUD_GPIO076_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO076_PullUpDisable					0x00001000UL

#define GPCPUD_GPIO075_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO075_PullUpDisable					0x00000800UL

#define GPCPUD_GPIO074_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO074_PullUpDisable					0x00000400UL

#define GPCPUD_GPIO073_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO073_PullUpDisable					0x00000200UL

#define GPCPUD_GPIO072_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO072_PullUpDisable					0x00000100UL

#define GPCPUD_GPIO071_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO071_PullUpDisable					0x00000080UL

#define GPCPUD_GPIO070_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO070_PullUpDisable					0x00000040UL

#define GPCPUD_GPIO069_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO069_PullUpDisable					0x00000020UL

#define GPCPUD_GPIO068_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO068_PullUpDisable					0x00000010UL

#define GPCPUD_GPIO067_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO067_PullUpDisable					0x00000008UL

#define GPCPUD_GPIO066_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO066_PullUpDisable					0x00000004UL

#define GPCPUD_GPIO065_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO065_PullUpDisable					0x00000002UL

#define GPCPUD_GPIO064_PullUpEnable						0x00000000UL
#define GPCPUD_GPIO064_PullUpDisable					0x00000001UL
#endif

struct GPCINV_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Input inversion control for this pin
    Uint16 GPIO65:1;                    // 1 Input inversion control for this pin
    Uint16 GPIO66:1;                    // 2 Input inversion control for this pin
    Uint16 GPIO67:1;                    // 3 Input inversion control for this pin
    Uint16 GPIO68:1;                    // 4 Input inversion control for this pin
    Uint16 GPIO69:1;                    // 5 Input inversion control for this pin
    Uint16 GPIO70:1;                    // 6 Input inversion control for this pin
    Uint16 GPIO71:1;                    // 7 Input inversion control for this pin
    Uint16 GPIO72:1;                    // 8 Input inversion control for this pin
    Uint16 GPIO73:1;                    // 9 Input inversion control for this pin
    Uint16 GPIO74:1;                    // 10 Input inversion control for this pin
    Uint16 GPIO75:1;                    // 11 Input inversion control for this pin
    Uint16 GPIO76:1;                    // 12 Input inversion control for this pin
    Uint16 GPIO77:1;                    // 13 Input inversion control for this pin
    Uint16 GPIO78:1;                    // 14 Input inversion control for this pin
    Uint16 GPIO79:1;                    // 15 Input inversion control for this pin
    Uint16 GPIO80:1;                    // 16 Input inversion control for this pin
    Uint16 GPIO81:1;                    // 17 Input inversion control for this pin
    Uint16 GPIO82:1;                    // 18 Input inversion control for this pin
    Uint16 GPIO83:1;                    // 19 Input inversion control for this pin
    Uint16 GPIO84:1;                    // 20 Input inversion control for this pin
    Uint16 GPIO85:1;                    // 21 Input inversion control for this pin
    Uint16 GPIO86:1;                    // 22 Input inversion control for this pin
    Uint16 GPIO87:1;                    // 23 Input inversion control for this pin
    Uint16 GPIO88:1;                    // 24 Input inversion control for this pin
    Uint16 GPIO89:1;                    // 25 Input inversion control for this pin
    Uint16 GPIO90:1;                    // 26 Input inversion control for this pin
    Uint16 GPIO91:1;                    // 27 Input inversion control for this pin
    Uint16 GPIO92:1;                    // 28 Input inversion control for this pin
    Uint16 GPIO93:1;                    // 29 Input inversion control for this pin
    Uint16 GPIO94:1;                    // 30 Input inversion control for this pin
    Uint16 GPIO95:1;                    // 31 Input inversion control for this pin
};

union GPCINV_REG {
    Uint32  all;
    struct  GPCINV_BITS  bit;
};

#ifdef CPU1
// GPCINV Register
//// GPCINV Register : Byte Value
#define GPCINV_GPIO095_InNormal							0x00000000UL
#define GPCINV_GPIO095_InInverted						0x80000000UL

#define GPCINV_GPIO094_InNormal							0x00000000UL
#define GPCINV_GPIO094_InInverted						0x40000000UL

#define GPCINV_GPIO093_InNormal							0x00000000UL
#define GPCINV_GPIO093_InInverted						0x20000000UL

#define GPCINV_GPIO092_InNormal							0x00000000UL
#define GPCINV_GPIO092_InInverted						0x10000000UL

#define GPCINV_GPIO091_InNormal							0x00000000UL
#define GPCINV_GPIO091_InInverted						0x08000000UL

#define GPCINV_GPIO090_InNormal							0x00000000UL
#define GPCINV_GPIO090_InInverted						0x04000000UL

#define GPCINV_GPIO089_InNormal							0x00000000UL
#define GPCINV_GPIO089_InInverted						0x02000000UL

#define GPCINV_GPIO088_InNormal							0x00000000UL
#define GPCINV_GPIO088_InInverted						0x01000000UL

#define GPCINV_GPIO087_InNormal							0x00000000UL
#define GPCINV_GPIO087_InInverted						0x00800000UL

#define GPCINV_GPIO086_InNormal							0x00000000UL
#define GPCINV_GPIO086_InInverted						0x00400000UL

#define GPCINV_GPIO085_InNormal							0x00000000UL
#define GPCINV_GPIO085_InInverted						0x00200000UL

#define GPCINV_GPIO084_InNormal							0x00000000UL
#define GPCINV_GPIO084_InInverted						0x00100000UL

#define GPCINV_GPIO083_InNormal							0x00000000UL
#define GPCINV_GPIO083_InInverted						0x00080000UL

#define GPCINV_GPIO082_InNormal							0x00000000UL
#define GPCINV_GPIO082_InInverted						0x00040000UL

#define GPCINV_GPIO081_InNormal							0x00000000UL
#define GPCINV_GPIO081_InInverted						0x00020000UL

#define GPCINV_GPIO080_InNormal							0x00000000UL
#define GPCINV_GPIO080_InInverted						0x00010000UL

#define GPCINV_GPIO079_InNormal							0x00000000UL
#define GPCINV_GPIO079_InInverted						0x00008000UL

#define GPCINV_GPIO078_InNormal							0x00000000UL
#define GPCINV_GPIO078_InInverted						0x00004000UL

#define GPCINV_GPIO077_InNormal							0x00000000UL
#define GPCINV_GPIO077_InInverted						0x00002000UL

#define GPCINV_GPIO076_InNormal							0x00000000UL
#define GPCINV_GPIO076_InInverted						0x00001000UL

#define GPCINV_GPIO075_InNormal							0x00000000UL
#define GPCINV_GPIO075_InInverted						0x00000800UL

#define GPCINV_GPIO074_InNormal							0x00000000UL
#define GPCINV_GPIO074_InInverted						0x00000400UL

#define GPCINV_GPIO073_InNormal							0x00000000UL
#define GPCINV_GPIO073_InInverted						0x00000200UL

#define GPCINV_GPIO072_InNormal							0x00000000UL
#define GPCINV_GPIO072_InInverted						0x00000100UL

#define GPCINV_GPIO071_InNormal							0x00000000UL
#define GPCINV_GPIO071_InInverted						0x00000080UL

#define GPCINV_GPIO070_InNormal							0x00000000UL
#define GPCINV_GPIO070_InInverted						0x00000040UL

#define GPCINV_GPIO069_InNormal							0x00000000UL
#define GPCINV_GPIO069_InInverted						0x00000020UL

#define GPCINV_GPIO068_InNormal							0x00000000UL
#define GPCINV_GPIO068_InInverted						0x00000010UL

#define GPCINV_GPIO067_InNormal							0x00000000UL
#define GPCINV_GPIO067_InInverted						0x00000008UL

#define GPCINV_GPIO066_InNormal							0x00000000UL
#define GPCINV_GPIO066_InInverted						0x00000004UL

#define GPCINV_GPIO065_InNormal							0x00000000UL
#define GPCINV_GPIO065_InInverted						0x00000002UL

#define GPCINV_GPIO064_InNormal							0x00000000UL
#define GPCINV_GPIO064_InInverted						0x00000001UL
#endif

struct GPCODR_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO65:1;                    // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO66:1;                    // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO67:1;                    // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO68:1;                    // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO69:1;                    // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO70:1;                    // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO71:1;                    // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO72:1;                    // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO73:1;                    // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO74:1;                    // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO75:1;                    // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO76:1;                    // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO77:1;                    // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO78:1;                    // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO79:1;                    // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO80:1;                    // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO81:1;                    // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO82:1;                    // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO83:1;                    // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO84:1;                    // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO85:1;                    // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO86:1;                    // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO87:1;                    // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO88:1;                    // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO89:1;                    // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO90:1;                    // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO91:1;                    // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO92:1;                    // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO93:1;                    // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO94:1;                    // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO95:1;                    // 31 Outpout Open-Drain control for this pin
};

union GPCODR_REG {
    Uint32  all;
    struct  GPCODR_BITS  bit;
};

#ifdef CPU1
// GPCODR Register
//// GPCODR Register : Byte Value
#define GPCODR_GPIO095_Normal							0x00000000UL
#define GPCODR_GPIO095_OpenDrain						0x80000000UL

#define GPCODR_GPIO094_Normal							0x00000000UL
#define GPCODR_GPIO094_OpenDrain						0x40000000UL

#define GPCODR_GPIO093_Normal							0x00000000UL
#define GPCODR_GPIO093_OpenDrain						0x20000000UL

#define GPCODR_GPIO092_Normal							0x00000000UL
#define GPCODR_GPIO092_OpenDrain						0x10000000UL

#define GPCODR_GPIO091_Normal							0x00000000UL
#define GPCODR_GPIO091_OpenDrain						0x08000000UL

#define GPCODR_GPIO090_Normal							0x00000000UL
#define GPCODR_GPIO090_OpenDrain						0x04000000UL

#define GPCODR_GPIO089_Normal							0x00000000UL
#define GPCODR_GPIO089_OpenDrain						0x02000000UL

#define GPCODR_GPIO088_Normal							0x00000000UL
#define GPCODR_GPIO088_OpenDrain						0x01000000UL

#define GPCODR_GPIO087_Normal							0x00000000UL
#define GPCODR_GPIO087_OpenDrain						0x00800000UL

#define GPCODR_GPIO086_Normal							0x00000000UL
#define GPCODR_GPIO086_OpenDrain						0x00400000UL

#define GPCODR_GPIO085_Normal							0x00000000UL
#define GPCODR_GPIO085_OpenDrain						0x00200000UL

#define GPCODR_GPIO084_Normal							0x00000000UL
#define GPCODR_GPIO084_OpenDrain						0x00100000UL

#define GPCODR_GPIO083_Normal							0x00000000UL
#define GPCODR_GPIO083_OpenDrain						0x00080000UL

#define GPCODR_GPIO082_Normal							0x00000000UL
#define GPCODR_GPIO082_OpenDrain						0x00040000UL

#define GPCODR_GPIO081_Normal							0x00000000UL
#define GPCODR_GPIO081_OpenDrain						0x00020000UL

#define GPCODR_GPIO080_Normal							0x00000000UL
#define GPCODR_GPIO080_OpenDrain						0x00010000UL

#define GPCODR_GPIO079_Normal							0x00000000UL
#define GPCODR_GPIO079_OpenDrain						0x00008000UL

#define GPCODR_GPIO078_Normal							0x00000000UL
#define GPCODR_GPIO078_OpenDrain						0x00004000UL

#define GPCODR_GPIO077_Normal							0x00000000UL
#define GPCODR_GPIO077_OpenDrain						0x00002000UL

#define GPCODR_GPIO076_Normal							0x00000000UL
#define GPCODR_GPIO076_OpenDrain						0x00001000UL

#define GPCODR_GPIO075_Normal							0x00000000UL
#define GPCODR_GPIO075_OpenDrain						0x00000800UL

#define GPCODR_GPIO074_Normal							0x00000000UL
#define GPCODR_GPIO074_OpenDrain						0x00000400UL

#define GPCODR_GPIO073_Normal							0x00000000UL
#define GPCODR_GPIO073_OpenDrain						0x00000200UL

#define GPCODR_GPIO072_Normal							0x00000000UL
#define GPCODR_GPIO072_OpenDrain						0x00000100UL

#define GPCODR_GPIO071_Normal							0x00000000UL
#define GPCODR_GPIO071_OpenDrain						0x00000080UL

#define GPCODR_GPIO070_Normal							0x00000000UL
#define GPCODR_GPIO070_OpenDrain						0x00000040UL

#define GPCODR_GPIO069_Normal							0x00000000UL
#define GPCODR_GPIO069_OpenDrain						0x00000020UL

#define GPCODR_GPIO068_Normal							0x00000000UL
#define GPCODR_GPIO068_OpenDrain						0x00000010UL

#define GPCODR_GPIO067_Normal							0x00000000UL
#define GPCODR_GPIO067_OpenDrain						0x00000008UL

#define GPCODR_GPIO066_Normal							0x00000000UL
#define GPCODR_GPIO066_OpenDrain						0x00000004UL

#define GPCODR_GPIO065_Normal							0x00000000UL
#define GPCODR_GPIO065_OpenDrain						0x00000002UL

#define GPCODR_GPIO064_Normal							0x00000000UL
#define GPCODR_GPIO064_OpenDrain						0x00000001UL
#endif

struct GPCGMUX1_BITS {                  // bits description
    Uint16 GPIO64:2;                    // 1:0 Defines pin-muxing selection for GPIO64
    Uint16 GPIO65:2;                    // 3:2 Defines pin-muxing selection for GPIO65
    Uint16 GPIO66:2;                    // 5:4 Defines pin-muxing selection for GPIO66
    Uint16 GPIO67:2;                    // 7:6 Defines pin-muxing selection for GPIO67
    Uint16 GPIO68:2;                    // 9:8 Defines pin-muxing selection for GPIO68
    Uint16 GPIO69:2;                    // 11:10 Defines pin-muxing selection for GPIO69
    Uint16 GPIO70:2;                    // 13:12 Defines pin-muxing selection for GPIO70
    Uint16 GPIO71:2;                    // 15:14 Defines pin-muxing selection for GPIO71
    Uint16 GPIO72:2;                    // 17:16 Defines pin-muxing selection for GPIO72
    Uint16 GPIO73:2;                    // 19:18 Defines pin-muxing selection for GPIO73
    Uint16 GPIO74:2;                    // 21:20 Defines pin-muxing selection for GPIO74
    Uint16 GPIO75:2;                    // 23:22 Defines pin-muxing selection for GPIO75
    Uint16 GPIO76:2;                    // 25:24 Defines pin-muxing selection for GPIO76
    Uint16 GPIO77:2;                    // 27:26 Defines pin-muxing selection for GPIO77
    Uint16 GPIO78:2;                    // 29:28 Defines pin-muxing selection for GPIO78
    Uint16 GPIO79:2;                    // 31:30 Defines pin-muxing selection for GPIO79
};

union GPCGMUX1_REG {
    Uint32  all;
    struct  GPCGMUX1_BITS  bit;
};

#ifdef CPU1
// GPCGMUX1 Register
//// GPCGMUX1 Register : Byte Value													// GMUX		MUX
#define GPCGMUX1_GPIO079_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO079_InOutEM1D5						0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO079_InEQEP2B						0x40000000UL				// 0b01		0b10

#define GPCGMUX1_GPIO078_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO078_InOutEM1D6						0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO078_InEQEP2A						0x10000000UL				// 0b01		0b10

#define GPCGMUX1_GPIO077_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO077_InOutEM1D7						0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO077_InSCIRXDD						0x04000000UL				// 0b01		0b10

#define GPCGMUX1_GPIO076_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO076_InOutEM1D8						0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO076_OutSCITXDD						0x01000000UL				// 0b01		0b10

#define GPCGMUX1_GPIO075_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO075_InOutEM1D9						0x00000000UL				// 0b00		0b10

#define GPCGMUX1_GPIO074_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO074_InOutEM1D10					0x00000000UL				// 0b00		0b10

#define GPCGMUX1_GPIO073_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO073_InOutEM1D11					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO073_OutXCLKOUT						0x00000000UL				// 0b00		0b11
#define GPCGMUX1_GPIO073_InCANRXB						0x00040000UL				// 0b01		0b01
#define GPCGMUX1_GPIO073_InSCIRXDC						0x00040000UL				// 0b01		0b10

#define GPCGMUX1_GPIO072_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO072_InOutEM1D12					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO072_OutCANTXB						0x00010000UL				// 0b01		0b01
#define GPCGMUX1_GPIO072_OutSCITXDC						0x00010000UL				// 0b01		0b10
#define GPCGMUX1_GPIO072_InOutHSPnSPISTEC				0x00030000UL				// 0b11		0b11

#define GPCGMUX1_GPIO071_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO071_InOutEM1D13					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO071_OutCANTXA						0x00004000UL				// 0b01		0b01
#define GPCGMUX1_GPIO071_InSCIRXDB						0x00004000UL				// 0b01		0b10
#define GPCGMUX1_GPIO071_InOutSPICLKC					0x0000C000UL				// 0b11		0b11

#define GPCGMUX1_GPIO070_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO070_InOutEM1D14					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO070_InCANRXA						0x00001000UL				// 0b01		0b01
#define GPCGMUX1_GPIO070_OutSCITXDB						0x00001000UL				// 0b01		0b10
#define GPCGMUX1_GPIO070_InOutHSPSPISOMIC				0x00003000UL				// 0b11		0b11

#define GPCGMUX1_GPIO069_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO069_InOutEM1D15					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO069_InODSCLB						0x00000400UL				// 0b01		0b10
#define GPCGMUX1_GPIO069_InOutHSPSPISIMOC				0x00000C00UL				// 0b11		0b11

#define GPCGMUX1_GPIO068_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO068_InOutEM1D16					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO068_InOutEM2D0						0x00000000UL				// 0b00		0b11

#define GPCGMUX1_GPIO067_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO067_InOutEM1D17					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO067_InOutEM2D1						0x00000000UL				// 0b00		0b11

#define GPCGMUX1_GPIO066_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO066_InOutEM1D18					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO066_InOutEM2D2						0x00000000UL				// 0b00		0b11
#define GPCGMUX1_GPIO066_InODSDAB						0x00000010UL				// 0b01		0b10
#define GPCGMUX1_GPIO066_InOutHSPnSPISTEB				0x00000030UL				// 0b11		0b11

#define GPCGMUX1_GPIO065_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO065_InOutEM1D19					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO065_InOutEM2D3						0x00000000UL				// 0b00		0b11
#define GPCGMUX1_GPIO065_InOutEQEP3I					0x00000004UL				// 0b01		0b01
#define GPCGMUX1_GPIO065_OutSCITXDA						0x00000004UL				// 0b01		0b10
#define GPCGMUX1_GPIO065_InOutHSPSPICLKB				0x0000000CUL				// 0b11		0b11

#define GPCGMUX1_GPIO064_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX1_GPIO064_InOutEM1D20					0x00000000UL				// 0b00		0b10
#define GPCGMUX1_GPIO064_InOutEM2D4						0x00000000UL				// 0b00		0b11
#define GPCGMUX1_GPIO064_InOutEQEP3S					0x00000001UL				// 0b01		0b01
#define GPCGMUX1_GPIO064_InInSCIRXDA					0x00000001UL				// 0b01		0b10
#define GPCGMUX1_GPIO064_InOutHSPSPISOMIB				0x00000003UL				// 0b11		0b11

//// GPCGMUX1 Register : Bit Value													// GMUX		MUX
#define GMUX_GPIO079_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO079_InOutEM1D5							0U							// 0b00		0b10
#define GMUX_GPIO079_InEQEP2B							1U							// 0b01		0b10

#define GMUX_GPIO078_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO078_InOutEM1D6							0U							// 0b00		0b10
#define GMUX_GPIO078_InEQEP2A							1U							// 0b01		0b10

#define GMUX_GPIO077_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO077_InOutEM1D7							0U							// 0b00		0b10
#define GMUX_GPIO077_InSCIRXDD							1U							// 0b01		0b10

#define GMUX_GPIO076_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO076_InOutEM1D8							0U							// 0b00		0b10
#define GMUX_GPIO076_OutSCITXDD							1U							// 0b01		0b10

#define GMUX_GPIO075_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO075_InOutEM1D9							0U							// 0b00		0b10

#define GMUX_GPIO074_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO074_InOutEM1D10						0U							// 0b00		0b10

#define GMUX_GPIO073_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO073_InOutEM1D11						0U							// 0b00		0b10
#define GMUX_GPIO073_OutXCLKOUT							0U							// 0b00		0b11
#define GMUX_GPIO073_InCANRXB							1U							// 0b01		0b01
#define GMUX_GPIO073_InSCIRXDC							1U							// 0b01		0b10

#define GMUX_GPIO072_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO072_InOutEM1D12						0U							// 0b00		0b10
#define GMUX_GPIO072_OutCANTXB							1U							// 0b01		0b01
#define GMUX_GPIO072_OutSCITXDC							1U							// 0b01		0b10
#define GMUX_GPIO072_InOutHSPnSPISTEC					3U							// 0b11		0b11

#define GMUX_GPIO071_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO071_InOutEM1D13						0U							// 0b00		0b10
#define GMUX_GPIO071_OutCANTXA							1U							// 0b01		0b01
#define GMUX_GPIO071_InSCIRXDB							1U							// 0b01		0b10
#define GMUX_GPIO071_InOutSPICLKC						3U							// 0b11		0b11

#define GMUX_GPIO070_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO070_InOutEM1D14						0U							// 0b00		0b10
#define GMUX_GPIO070_InCANRXA							1U							// 0b01		0b01
#define GMUX_GPIO070_OutSCITXDB							1U							// 0b01		0b10
#define GMUX_GPIO070_InOutHSPSPISOMIC					3U							// 0b11		0b11

#define GMUX_GPIO069_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO069_InOutEM1D15						0U							// 0b00		0b10
#define GMUX_GPIO069_InODSCLB							1U							// 0b01		0b10
#define GMUX_GPIO069_InOutHSPSPISIMOC					3U							// 0b11		0b11

#define GMUX_GPIO068_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO068_InOutEM1D16						0U							// 0b00		0b10
#define GMUX_GPIO068_InOutEM2D0							0U							// 0b00		0b11

#define GMUX_GPIO067_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO067_InOutEM1D17						0U							// 0b00		0b10
#define GMUX_GPIO067_InOutEM2D1							0U							// 0b00		0b11

#define GMUX_GPIO066_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO066_InOutEM1D18						0U							// 0b00		0b10
#define GMUX_GPIO066_InOutEM2D2							0U							// 0b00		0b11
#define GMUX_GPIO066_InODSDAB							1U							// 0b01		0b10
#define GMUX_GPIO066_InOutHSPnSPISTEB					3U							// 0b11		0b11

#define GMUX_GPIO065_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO065_InOutEM1D19						0U							// 0b00		0b10
#define GMUX_GPIO065_InOutEM2D3							0U							// 0b00		0b11
#define GMUX_GPIO065_InOutEQEP3I						1U							// 0b01		0b01
#define GMUX_GPIO065_OutSCITXDA							1U							// 0b01		0b10
#define GMUX_GPIO065_InOutHSPSPICLKB					3U							// 0b11		0b11

#define GMUX_GPIO064_InOutGPIO							0U							// -		0b00
#define GMUX_GPIO064_InOutEM1D20						0U							// 0b00		0b10
#define GMUX_GPIO064_InOutEM2D4							0U							// 0b00		0b11
#define GMUX_GPIO064_InOutEQEP3S						1U							// 0b01		0b01
#define GMUX_GPIO064_InInSCIRXDA						1U							// 0b01		0b10
#define GMUX_GPIO064_InOutHSPSPISOMIB					3U							// 0b11		0b11
#endif

struct GPCGMUX2_BITS {                  // bits description
    Uint16 GPIO80:2;                    // 1:0 Defines pin-muxing selection for GPIO80
    Uint16 GPIO81:2;                    // 3:2 Defines pin-muxing selection for GPIO81
    Uint16 GPIO82:2;                    // 5:4 Defines pin-muxing selection for GPIO82
    Uint16 GPIO83:2;                    // 7:6 Defines pin-muxing selection for GPIO83
    Uint16 GPIO84:2;                    // 9:8 Defines pin-muxing selection for GPIO84
    Uint16 GPIO85:2;                    // 11:10 Defines pin-muxing selection for GPIO85
    Uint16 GPIO86:2;                    // 13:12 Defines pin-muxing selection for GPIO86
    Uint16 GPIO87:2;                    // 15:14 Defines pin-muxing selection for GPIO87
    Uint16 GPIO88:2;                    // 17:16 Defines pin-muxing selection for GPIO88
    Uint16 GPIO89:2;                    // 19:18 Defines pin-muxing selection for GPIO89
    Uint16 GPIO90:2;                    // 21:20 Defines pin-muxing selection for GPIO90
    Uint16 GPIO91:2;                    // 23:22 Defines pin-muxing selection for GPIO91
    Uint16 GPIO92:2;                    // 25:24 Defines pin-muxing selection for GPIO92
    Uint16 GPIO93:2;                    // 27:26 Defines pin-muxing selection for GPIO93
    Uint16 GPIO94:2;                    // 29:28 Defines pin-muxing selection for GPIO94
    Uint16 GPIO95:2;                    // 31:30 Defines pin-muxing selection for GPIO95
};

union GPCGMUX2_REG {
    Uint32  all;
    struct  GPCGMUX2_BITS  bit;
};

#ifdef CPU1
// GPCGMUX2 Register
//// GPCGMUX2 Register : Byte Value													// GMUX		MUX
#define GPCGMUX2_GPIO095_InOutGPIO						0x00000000UL				// -		0b00

#define GPCGMUX2_GPIO094_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO094_InSCIRXDD						0x10000000UL				// 0b01		0b10

#define GPCGMUX2_GPIO093_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO093_OutEM1BA0						0x00000000UL				// 0b00		0b11
#define GPCGMUX2_GPIO093_OutSCITXDD						0x04000000UL				// 0b01		0b10

#define GPCGMUX2_GPIO092_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO092_OutEM1A19						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO092_OutEM1BA1						0x00000000UL				// 0b00		0b11
#define GPCGMUX2_GPIO092_InODSCLA						0x01000000UL				// 0b01		0b10

#define GPCGMUX2_GPIO091_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO091_OutEM1A18						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO091_OutEM1DQM3						0x00000000UL				// 0b00		0b11
#define GPCGMUX2_GPIO091_InODSDAA						0x00400000UL				// 0b01		0b10

#define GPCGMUX2_GPIO090_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO090_OutEM1A17						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO090_OutEM1DQM2						0x00000000UL				// 0b00		0b11
#define GPCGMUX2_GPIO090_InSCIRXDC						0x00100000UL				// 0b01		0b10

#define GPCGMUX2_GPIO089_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO089_OutEM1A16						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO089_OutEM1DQM1						0x00000000UL				// 0b00		0b11
#define GPCGMUX2_GPIO089_OutSCITXDC						0x00040000UL				// 0b01		0b10

#define GPCGMUX2_GPIO088_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO088_OutEM1A15						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO088_OutEM1DQM0						0x00000000UL				// 0b00		0b11

#define GPCGMUX2_GPIO087_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO087_OutEM1A14						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO087_OutEM1RAS						0x00000000UL				// 0b00		0b11
#define GPCGMUX2_GPIO087_InSCIRXDB						0x00004000UL				// 0b01		0b01
#define GPCGMUX2_GPIO087_InOutMFSXB						0x00004000UL				// 0b01		0b10
#define GPCGMUX2_GPIO087_InOutMFSXA						0x0000C000UL				// 0b11		0b11

#define GPCGMUX2_GPIO086_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO086_OutEM1A13						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO086_OutEM1CAS						0x00000000UL				// 0b00		0b11
#define GPCGMUX2_GPIO086_OutSCIRXDB						0x00001000UL				// 0b01		0b01
#define GPCGMUX2_GPIO086_InOutMCLKXB					0x00001000UL				// 0b01		0b10
#define GPCGMUX2_GPIO086_InOutMCLKXA					0x00003000UL				// 0b11		0b11

#define GPCGMUX2_GPIO085_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO085_InOutEM1D0						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO085_InSCIRXDA						0x00000400UL				// 0b01		0b01
#define GPCGMUX2_GPIO085_InMDRB							0x00000400UL				// 0b01		0b10
#define GPCGMUX2_GPIO085_InMDRA							0x00000C00UL				// 0b11		0b11

#define GPCGMUX2_GPIO084_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO084_OutSCITXDA						0x00000100UL				// 0b01		0b01
#define GPCGMUX2_GPIO084_OutMDXB						0x00000100UL				// 0b01		0b10
#define GPCGMUX2_GPIO084_OutMDXA						0x00000300UL				// 0b11		0b11

#define GPCGMUX2_GPIO083_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO083_InOutEM1D1						0x00000000UL				// 0b00		0b10

#define GPCGMUX2_GPIO082_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO082_InOutEM1D2						0x00000000UL				// 0b00		0b10

#define GPCGMUX2_GPIO081_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO081_InOutEM1D3						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO081_InOutEQEP2I					0x00000004UL				// 0b01		0b10

#define GPCGMUX2_GPIO080_InOutGPIO						0x00000000UL				// -		0b00
#define GPCGMUX2_GPIO080_InOutEM1D4						0x00000000UL				// 0b00		0b10
#define GPCGMUX2_GPIO080_InOutEQEP2S					0x00000001UL				// 0b01		0b10
#endif

struct GPCCSEL1_BITS {                  // bits description
    Uint16 GPIO64:4;                    // 3:0 GPIO64 Master CPU Select
    Uint16 GPIO65:4;                    // 7:4 GPIO65 Master CPU Select
    Uint16 GPIO66:4;                    // 11:8 GPIO66 Master CPU Select
    Uint16 GPIO67:4;                    // 15:12 GPIO67 Master CPU Select
    Uint16 GPIO68:4;                    // 19:16 GPIO68 Master CPU Select
    Uint16 GPIO69:4;                    // 23:20 GPIO69 Master CPU Select
    Uint16 GPIO70:4;                    // 27:24 GPIO70 Master CPU Select
    Uint16 GPIO71:4;                    // 31:28 GPIO71 Master CPU Select
};

union GPCCSEL1_REG {
    Uint32  all;
    struct  GPCCSEL1_BITS  bit;
};

#ifdef CPU1
// GPCCSEL1 Register
//// GPCCSEL1 Register : Byte Value
#define GPCCSEL1_GPIO071_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO071_CPU1_CLA1Host					0x10000000UL
#define GPCCSEL1_GPIO071_CPU2Host						0x20000000UL
#define GPCCSEL1_GPIO071_CPU2_CLA1Host					0x30000000UL

#define GPCCSEL1_GPIO070_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO070_CPU1_CLA1Host					0x01000000UL
#define GPCCSEL1_GPIO070_CPU2Host						0x02000000UL
#define GPCCSEL1_GPIO070_CPU2_CLA1Host					0x03000000UL

#define GPCCSEL1_GPIO069_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO069_CPU1_CLA1Host					0x00100000UL
#define GPCCSEL1_GPIO069_CPU2Host						0x00200000UL
#define GPCCSEL1_GPIO069_CPU2_CLA1Host					0x00300000UL

#define GPCCSEL1_GPIO068_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO068_CPU1_CLA1Host					0x00010000UL
#define GPCCSEL1_GPIO068_CPU2Host						0x00020000UL
#define GPCCSEL1_GPIO068_CPU2_CLA1Host					0x00030000UL

#define GPCCSEL1_GPIO067_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO067_CPU1_CLA1Host					0x00001000UL
#define GPCCSEL1_GPIO067_CPU2Host						0x00002000UL
#define GPCCSEL1_GPIO067_CPU2_CLA1Host					0x00003000UL

#define GPCCSEL1_GPIO066_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO066_CPU1_CLA1Host					0x00000100UL
#define GPCCSEL1_GPIO066_CPU2Host						0x00000200UL
#define GPCCSEL1_GPIO066_CPU2_CLA1Host					0x00000300UL

#define GPCCSEL1_GPIO065_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO065_CPU1_CLA1Host					0x00000010UL
#define GPCCSEL1_GPIO065_CPU2Host						0x00000020UL
#define GPCCSEL1_GPIO065_CPU2_CLA1Host					0x00000030UL

#define GPCCSEL1_GPIO064_CPU1Host						0x00000000UL
#define GPCCSEL1_GPIO064_CPU1_CLA1Host					0x00000001UL
#define GPCCSEL1_GPIO064_CPU2Host						0x00000002UL
#define GPCCSEL1_GPIO064_CPU2_CLA1Host					0x00000003UL

//// GPCCSEL1 Register : Byte Value
#define GPCCSEL1_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPCCSEL2_BITS {                  // bits description
    Uint16 GPIO72:4;                    // 3:0 GPIO72 Master CPU Select
    Uint16 GPIO73:4;                    // 7:4 GPIO73 Master CPU Select
    Uint16 GPIO74:4;                    // 11:8 GPIO74 Master CPU Select
    Uint16 GPIO75:4;                    // 15:12 GPIO75 Master CPU Select
    Uint16 GPIO76:4;                    // 19:16 GPIO76 Master CPU Select
    Uint16 GPIO77:4;                    // 23:20 GPIO77 Master CPU Select
    Uint16 GPIO78:4;                    // 27:24 GPIO78 Master CPU Select
    Uint16 GPIO79:4;                    // 31:28 GPIO79 Master CPU Select
};

union GPCCSEL2_REG {
    Uint32  all;
    struct  GPCCSEL2_BITS  bit;
};

#ifdef CPU1
// GPCCSEL2 Register
//// GPCCSEL2 Register : Byte Value
#define GPCCSEL2_GPIO079_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO079_CPU1_CLA1Host					0x10000000UL
#define GPCCSEL2_GPIO079_CPU2Host						0x20000000UL
#define GPCCSEL2_GPIO079_CPU2_CLA1Host					0x30000000UL

#define GPCCSEL2_GPIO078_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO078_CPU1_CLA1Host					0x01000000UL
#define GPCCSEL2_GPIO078_CPU2Host						0x02000000UL
#define GPCCSEL2_GPIO078_CPU2_CLA1Host					0x03000000UL

#define GPCCSEL2_GPIO077_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO077_CPU1_CLA1Host					0x00100000UL
#define GPCCSEL2_GPIO077_CPU2Host						0x00200000UL
#define GPCCSEL2_GPIO077_CPU2_CLA1Host					0x00300000UL

#define GPCCSEL2_GPIO076_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO076_CPU1_CLA1Host					0x00010000UL
#define GPCCSEL2_GPIO076_CPU2Host						0x00020000UL
#define GPCCSEL2_GPIO076_CPU2_CLA1Host					0x00030000UL

#define GPCCSEL2_GPIO075_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO075_CPU1_CLA1Host					0x00001000UL
#define GPCCSEL2_GPIO075_CPU2Host						0x00002000UL
#define GPCCSEL2_GPIO075_CPU2_CLA1Host					0x00003000UL

#define GPCCSEL2_GPIO074_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO074_CPU1_CLA1Host					0x00000100UL
#define GPCCSEL2_GPIO074_CPU2Host						0x00000200UL
#define GPCCSEL2_GPIO074_CPU2_CLA1Host					0x00000300UL

#define GPCCSEL2_GPIO073_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO073_CPU1_CLA1Host					0x00000010UL
#define GPCCSEL2_GPIO073_CPU2Host						0x00000020UL
#define GPCCSEL2_GPIO073_CPU2_CLA1Host					0x00000030UL

#define GPCCSEL2_GPIO072_CPU1Host						0x00000000UL
#define GPCCSEL2_GPIO072_CPU1_CLA1Host					0x00000001UL
#define GPCCSEL2_GPIO072_CPU2Host						0x00000002UL
#define GPCCSEL2_GPIO072_CPU2_CLA1Host					0x00000003UL

//// GPCCSEL2 Register : Byte Value
#define GPCCSEL2_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPCCSEL3_BITS {                  // bits description
    Uint16 GPIO80:4;                    // 3:0 GPIO80 Master CPU Select
    Uint16 GPIO81:4;                    // 7:4 GPIO81 Master CPU Select
    Uint16 GPIO82:4;                    // 11:8 GPIO82 Master CPU Select
    Uint16 GPIO83:4;                    // 15:12 GPIO83 Master CPU Select
    Uint16 GPIO84:4;                    // 19:16 GPIO84 Master CPU Select
    Uint16 GPIO85:4;                    // 23:20 GPIO85 Master CPU Select
    Uint16 GPIO86:4;                    // 27:24 GPIO86 Master CPU Select
    Uint16 GPIO87:4;                    // 31:28 GPIO87 Master CPU Select
};

union GPCCSEL3_REG {
    Uint32  all;
    struct  GPCCSEL3_BITS  bit;
};

#ifdef CPU1
// GPCCSEL3 Register
//// GPCCSEL3 Register : Byte Value
#define GPCCSEL3_GPIO087_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO087_CPU1_CLA1Host					0x10000000UL
#define GPCCSEL3_GPIO087_CPU2Host						0x20000000UL
#define GPCCSEL3_GPIO087_CPU2_CLA1Host					0x30000000UL

#define GPCCSEL3_GPIO086_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO086_CPU1_CLA1Host					0x01000000UL
#define GPCCSEL3_GPIO086_CPU2Host						0x02000000UL
#define GPCCSEL3_GPIO086_CPU2_CLA1Host					0x03000000UL

#define GPCCSEL3_GPIO085_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO085_CPU1_CLA1Host					0x00100000UL
#define GPCCSEL3_GPIO085_CPU2Host						0x00200000UL
#define GPCCSEL3_GPIO085_CPU2_CLA1Host					0x00300000UL

#define GPCCSEL3_GPIO084_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO084_CPU1_CLA1Host					0x00010000UL
#define GPCCSEL3_GPIO084_CPU2Host						0x00020000UL
#define GPCCSEL3_GPIO084_CPU2_CLA1Host					0x00030000UL

#define GPCCSEL3_GPIO083_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO083_CPU1_CLA1Host					0x00001000UL
#define GPCCSEL3_GPIO083_CPU2Host						0x00002000UL
#define GPCCSEL3_GPIO083_CPU2_CLA1Host					0x00003000UL

#define GPCCSEL3_GPIO082_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO082_CPU1_CLA1Host					0x00000100UL
#define GPCCSEL3_GPIO082_CPU2Host						0x00000200UL
#define GPCCSEL3_GPIO082_CPU2_CLA1Host					0x00000300UL

#define GPCCSEL3_GPIO081_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO081_CPU1_CLA1Host					0x00000010UL
#define GPCCSEL3_GPIO081_CPU2Host						0x00000020UL
#define GPCCSEL3_GPIO081_CPU2_CLA1Host					0x00000030UL

#define GPCCSEL3_GPIO080_CPU1Host						0x00000000UL
#define GPCCSEL3_GPIO080_CPU1_CLA1Host					0x00000001UL
#define GPCCSEL3_GPIO080_CPU2Host						0x00000002UL
#define GPCCSEL3_GPIO080_CPU2_CLA1Host					0x00000003UL

//// GPCCSEL3 Register : Byte Value
#define GPCCSEL3_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPCCSEL4_BITS {                  // bits description
    Uint16 GPIO88:4;                    // 3:0 GPIO88 Master CPU Select
    Uint16 GPIO89:4;                    // 7:4 GPIO89 Master CPU Select
    Uint16 GPIO90:4;                    // 11:8 GPIO90 Master CPU Select
    Uint16 GPIO91:4;                    // 15:12 GPIO91 Master CPU Select
    Uint16 GPIO92:4;                    // 19:16 GPIO92 Master CPU Select
    Uint16 GPIO93:4;                    // 23:20 GPIO93 Master CPU Select
    Uint16 GPIO94:4;                    // 27:24 GPIO94 Master CPU Select
    Uint16 GPIO95:4;                    // 31:28 GPIO95 Master CPU Select
};

union GPCCSEL4_REG {
    Uint32  all;
    struct  GPCCSEL4_BITS  bit;
};

#ifdef CPU1
// GPCCSEL4 Register
//// GPCCSEL4 Register : Byte Value
#define GPCCSEL4_GPIO095_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO095_CPU1_CLA1Host					0x10000000UL
#define GPCCSEL4_GPIO095_CPU2Host						0x20000000UL
#define GPCCSEL4_GPIO095_CPU2_CLA1Host					0x30000000UL

#define GPCCSEL4_GPIO094_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO094_CPU1_CLA1Host					0x01000000UL
#define GPCCSEL4_GPIO094_CPU2Host						0x02000000UL
#define GPCCSEL4_GPIO094_CPU2_CLA1Host					0x03000000UL

#define GPCCSEL4_GPIO093_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO093_CPU1_CLA1Host					0x00100000UL
#define GPCCSEL4_GPIO093_CPU2Host						0x00200000UL
#define GPCCSEL4_GPIO093_CPU2_CLA1Host					0x00300000UL

#define GPCCSEL4_GPIO092_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO092_CPU1_CLA1Host					0x00010000UL
#define GPCCSEL4_GPIO092_CPU2Host						0x00020000UL
#define GPCCSEL4_GPIO092_CPU2_CLA1Host					0x00030000UL

#define GPCCSEL4_GPIO091_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO091_CPU1_CLA1Host					0x00001000UL
#define GPCCSEL4_GPIO091_CPU2Host						0x00002000UL
#define GPCCSEL4_GPIO091_CPU2_CLA1Host					0x00003000UL

#define GPCCSEL4_GPIO090_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO090_CPU1_CLA1Host					0x00000100UL
#define GPCCSEL4_GPIO090_CPU2Host						0x00000200UL
#define GPCCSEL4_GPIO090_CPU2_CLA1Host					0x00000300UL

#define GPCCSEL4_GPIO089_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO089_CPU1_CLA1Host					0x00000010UL
#define GPCCSEL4_GPIO089_CPU2Host						0x00000020UL
#define GPCCSEL4_GPIO089_CPU2_CLA1Host					0x00000030UL

#define GPCCSEL4_GPIO088_CPU1Host						0x00000000UL
#define GPCCSEL4_GPIO088_CPU1_CLA1Host					0x00000001UL
#define GPCCSEL4_GPIO088_CPU2Host						0x00000002UL
#define GPCCSEL4_GPIO088_CPU2_CLA1Host					0x00000003UL

//// GPCCSEL4 Register : Byte Value
#define GPCCSEL4_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPCLOCK_BITS {                   // bits description
    Uint16 GPIO64:1;                    // 0 Configuration Lock bit for this pin
    Uint16 GPIO65:1;                    // 1 Configuration Lock bit for this pin
    Uint16 GPIO66:1;                    // 2 Configuration Lock bit for this pin
    Uint16 GPIO67:1;                    // 3 Configuration Lock bit for this pin
    Uint16 GPIO68:1;                    // 4 Configuration Lock bit for this pin
    Uint16 GPIO69:1;                    // 5 Configuration Lock bit for this pin
    Uint16 GPIO70:1;                    // 6 Configuration Lock bit for this pin
    Uint16 GPIO71:1;                    // 7 Configuration Lock bit for this pin
    Uint16 GPIO72:1;                    // 8 Configuration Lock bit for this pin
    Uint16 GPIO73:1;                    // 9 Configuration Lock bit for this pin
    Uint16 GPIO74:1;                    // 10 Configuration Lock bit for this pin
    Uint16 GPIO75:1;                    // 11 Configuration Lock bit for this pin
    Uint16 GPIO76:1;                    // 12 Configuration Lock bit for this pin
    Uint16 GPIO77:1;                    // 13 Configuration Lock bit for this pin
    Uint16 GPIO78:1;                    // 14 Configuration Lock bit for this pin
    Uint16 GPIO79:1;                    // 15 Configuration Lock bit for this pin
    Uint16 GPIO80:1;                    // 16 Configuration Lock bit for this pin
    Uint16 GPIO81:1;                    // 17 Configuration Lock bit for this pin
    Uint16 GPIO82:1;                    // 18 Configuration Lock bit for this pin
    Uint16 GPIO83:1;                    // 19 Configuration Lock bit for this pin
    Uint16 GPIO84:1;                    // 20 Configuration Lock bit for this pin
    Uint16 GPIO85:1;                    // 21 Configuration Lock bit for this pin
    Uint16 GPIO86:1;                    // 22 Configuration Lock bit for this pin
    Uint16 GPIO87:1;                    // 23 Configuration Lock bit for this pin
    Uint16 GPIO88:1;                    // 24 Configuration Lock bit for this pin
    Uint16 GPIO89:1;                    // 25 Configuration Lock bit for this pin
    Uint16 GPIO90:1;                    // 26 Configuration Lock bit for this pin
    Uint16 GPIO91:1;                    // 27 Configuration Lock bit for this pin
    Uint16 GPIO92:1;                    // 28 Configuration Lock bit for this pin
    Uint16 GPIO93:1;                    // 29 Configuration Lock bit for this pin
    Uint16 GPIO94:1;                    // 30 Configuration Lock bit for this pin
    Uint16 GPIO95:1;                    // 31 Configuration Lock bit for this pin
};

union GPCLOCK_REG {
    Uint32  all;
    struct  GPCLOCK_BITS  bit;
};

struct GPCCR_BITS {                     // bits description
    Uint16 GPIO64:1;                    // 0 Configuration lock commit bit for this pin
    Uint16 GPIO65:1;                    // 1 Configuration lock commit bit for this pin
    Uint16 GPIO66:1;                    // 2 Configuration lock commit bit for this pin
    Uint16 GPIO67:1;                    // 3 Configuration lock commit bit for this pin
    Uint16 GPIO68:1;                    // 4 Configuration lock commit bit for this pin
    Uint16 GPIO69:1;                    // 5 Configuration lock commit bit for this pin
    Uint16 GPIO70:1;                    // 6 Configuration lock commit bit for this pin
    Uint16 GPIO71:1;                    // 7 Configuration lock commit bit for this pin
    Uint16 GPIO72:1;                    // 8 Configuration lock commit bit for this pin
    Uint16 GPIO73:1;                    // 9 Configuration lock commit bit for this pin
    Uint16 GPIO74:1;                    // 10 Configuration lock commit bit for this pin
    Uint16 GPIO75:1;                    // 11 Configuration lock commit bit for this pin
    Uint16 GPIO76:1;                    // 12 Configuration lock commit bit for this pin
    Uint16 GPIO77:1;                    // 13 Configuration lock commit bit for this pin
    Uint16 GPIO78:1;                    // 14 Configuration lock commit bit for this pin
    Uint16 GPIO79:1;                    // 15 Configuration lock commit bit for this pin
    Uint16 GPIO80:1;                    // 16 Configuration lock commit bit for this pin
    Uint16 GPIO81:1;                    // 17 Configuration lock commit bit for this pin
    Uint16 GPIO82:1;                    // 18 Configuration lock commit bit for this pin
    Uint16 GPIO83:1;                    // 19 Configuration lock commit bit for this pin
    Uint16 GPIO84:1;                    // 20 Configuration lock commit bit for this pin
    Uint16 GPIO85:1;                    // 21 Configuration lock commit bit for this pin
    Uint16 GPIO86:1;                    // 22 Configuration lock commit bit for this pin
    Uint16 GPIO87:1;                    // 23 Configuration lock commit bit for this pin
    Uint16 GPIO88:1;                    // 24 Configuration lock commit bit for this pin
    Uint16 GPIO89:1;                    // 25 Configuration lock commit bit for this pin
    Uint16 GPIO90:1;                    // 26 Configuration lock commit bit for this pin
    Uint16 GPIO91:1;                    // 27 Configuration lock commit bit for this pin
    Uint16 GPIO92:1;                    // 28 Configuration lock commit bit for this pin
    Uint16 GPIO93:1;                    // 29 Configuration lock commit bit for this pin
    Uint16 GPIO94:1;                    // 30 Configuration lock commit bit for this pin
    Uint16 GPIO95:1;                    // 31 Configuration lock commit bit for this pin
};

union GPCCR_REG {
    Uint32  all;
    struct  GPCCR_BITS  bit;
};

struct GPDCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO96 to GPIO103
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO104 to GPIO111
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO112 to GPIO119
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO120 to GPIO127
};

union GPDCTRL_REG {
    Uint32  all;
    struct  GPDCTRL_BITS  bit;
};

#ifdef CPU1
// GPDCTRL Register
//// GPDCTRL Register : Byte Value
#define GPDCTRL_QUALPRD3_GPIO127to120_Value(val)		(((Uint32)val & 0x000000FFUL) << 24)
#define GPDCTRL_QUALPRD2_GPIO119to112_Value(val)		(((Uint32)val & 0x000000FFUL) << 16)
#define GPDCTRL_QUALPRD1_GPIO111to104_Value(val)		(((Uint32)val & 0x000000FFUL) << 8)
#define GPDCTRL_QUALPRD0_GPIO103to096_Value(val)		((Uint32)val & 0x000000FFUL)
#endif

struct GPDQSEL1_BITS {                  // bits description
    Uint16 GPIO96:2;                    // 1:0 Select input qualification type for GPIO96
    Uint16 GPIO97:2;                    // 3:2 Select input qualification type for GPIO97
    Uint16 GPIO98:2;                    // 5:4 Select input qualification type for GPIO98
    Uint16 GPIO99:2;                    // 7:6 Select input qualification type for GPIO99
    Uint16 GPIO100:2;                   // 9:8 Select input qualification type for GPIO100
    Uint16 GPIO101:2;                   // 11:10 Select input qualification type for GPIO101
    Uint16 GPIO102:2;                   // 13:12 Select input qualification type for GPIO102
    Uint16 GPIO103:2;                   // 15:14 Select input qualification type for GPIO103
    Uint16 GPIO104:2;                   // 17:16 Select input qualification type for GPIO104
    Uint16 GPIO105:2;                   // 19:18 Select input qualification type for GPIO105
    Uint16 GPIO106:2;                   // 21:20 Select input qualification type for GPIO106
    Uint16 GPIO107:2;                   // 23:22 Select input qualification type for GPIO107
    Uint16 GPIO108:2;                   // 25:24 Select input qualification type for GPIO108
    Uint16 GPIO109:2;                   // 27:26 Select input qualification type for GPIO109
    Uint16 GPIO110:2;                   // 29:28 Select input qualification type for GPIO110
    Uint16 GPIO111:2;                   // 31:30 Select input qualification type for GPIO111
};

union GPDQSEL1_REG {
    Uint32  all;
    struct  GPDQSEL1_BITS  bit;
};

#ifdef CPU1
// GPDQSEL1 Register
//// GPDQSEL1 Register : Byte Value
#define GPDQSEL1_GPIO111_Synch							0x00000000UL
#define GPDQSEL1_GPIO111_3SampSynch						0x40000000UL
#define GPDQSEL1_GPIO111_6SampSynch						0x80000000UL
#define GPDQSEL1_GPIO111_Asynch							0xC0000000UL

#define GPDQSEL1_GPIO110_Synch							0x00000000UL
#define GPDQSEL1_GPIO110_3SampSynch						0x10000000UL
#define GPDQSEL1_GPIO110_6SampSynch						0x20000000UL
#define GPDQSEL1_GPIO110_Asynch							0x30000000UL

#define GPDQSEL1_GPIO109_Synch							0x00000000UL
#define GPDQSEL1_GPIO109_3SampSynch						0x04000000UL
#define GPDQSEL1_GPIO109_6SampSynch						0x08000000UL
#define GPDQSEL1_GPIO109_Asynch							0x0C000000UL

#define GPDQSEL1_GPIO108_Synch							0x00000000UL
#define GPDQSEL1_GPIO108_3SampSynch						0x01000000UL
#define GPDQSEL1_GPIO108_6SampSynch						0x02000000UL
#define GPDQSEL1_GPIO108_Asynch							0x03000000UL

#define GPDQSEL1_GPIO107_Synch							0x00000000UL
#define GPDQSEL1_GPIO107_3SampSynch						0x00400000UL
#define GPDQSEL1_GPIO107_6SampSynch						0x00800000UL
#define GPDQSEL1_GPIO107_Asynch							0x00C00000UL

#define GPDQSEL1_GPIO106_Synch							0x00000000UL
#define GPDQSEL1_GPIO106_3SampSynch						0x00100000UL
#define GPDQSEL1_GPIO106_6SampSynch						0x00200000UL
#define GPDQSEL1_GPIO106_Asynch							0x00300000UL

#define GPDQSEL1_GPIO105_Synch							0x00000000UL
#define GPDQSEL1_GPIO105_3SampSynch						0x00040000UL
#define GPDQSEL1_GPIO105_6SampSynch						0x00080000UL
#define GPDQSEL1_GPIO105_Asynch							0x000C0000UL

#define GPDQSEL1_GPIO104_Synch							0x00000000UL
#define GPDQSEL1_GPIO104_3SampSynch						0x00010000UL
#define GPDQSEL1_GPIO104_6SampSynch						0x00020000UL
#define GPDQSEL1_GPIO104_Asynch							0x00030000UL

#define GPDQSEL1_GPIO103_Synch							0x00000000UL
#define GPDQSEL1_GPIO103_3SampSynch						0x00004000UL
#define GPDQSEL1_GPIO103_6SampSynch						0x00008000UL
#define GPDQSEL1_GPIO103_Asynch							0x0000C000UL

#define GPDQSEL1_GPIO102_Synch							0x00000000UL
#define GPDQSEL1_GPIO102_3SampSynch						0x00001000UL
#define GPDQSEL1_GPIO102_6SampSynch						0x00002000UL
#define GPDQSEL1_GPIO102_Asynch							0x00003000UL

#define GPDQSEL1_GPIO101_Synch							0x00000000UL
#define GPDQSEL1_GPIO101_3SampSynch						0x00000400UL
#define GPDQSEL1_GPIO101_6SampSynch						0x00000800UL
#define GPDQSEL1_GPIO101_Asynch							0x00000C00UL

#define GPDQSEL1_GPIO100_Synch							0x00000000UL
#define GPDQSEL1_GPIO100_3SampSynch						0x00000100UL
#define GPDQSEL1_GPIO100_6SampSynch						0x00000200UL
#define GPDQSEL1_GPIO100_Asynch							0x00000300UL

#define GPDQSEL1_GPIO099_Synch							0x00000000UL
#define GPDQSEL1_GPIO099_3SampSynch						0x00000040UL
#define GPDQSEL1_GPIO099_6SampSynch						0x00000080UL
#define GPDQSEL1_GPIO099_Asynch							0x000000C0UL

#define GPDQSEL1_GPIO098_Synch							0x00000000UL
#define GPDQSEL1_GPIO098_3SampSynch						0x00000010UL
#define GPDQSEL1_GPIO098_6SampSynch						0x00000020UL
#define GPDQSEL1_GPIO098_Asynch							0x00000030UL

#define GPDQSEL1_GPIO097_Synch							0x00000000UL
#define GPDQSEL1_GPIO097_3SampSynch						0x00000004UL
#define GPDQSEL1_GPIO097_6SampSynch						0x00000008UL
#define GPDQSEL1_GPIO097_Asynch							0x0000000CUL

#define GPDQSEL1_GPIO096_Synch							0x00000000UL
#define GPDQSEL1_GPIO096_3SampSynch						0x00000001UL
#define GPDQSEL1_GPIO096_6SampSynch						0x00000002UL
#define GPDQSEL1_GPIO096_Asynch							0x00000003UL
#endif

struct GPDQSEL2_BITS {                  // bits description
    Uint16 GPIO112:2;                   // 1:0 Select input qualification type for GPIO112
    Uint16 GPIO113:2;                   // 3:2 Select input qualification type for GPIO113
    Uint16 GPIO114:2;                   // 5:4 Select input qualification type for GPIO114
    Uint16 GPIO115:2;                   // 7:6 Select input qualification type for GPIO115
    Uint16 GPIO116:2;                   // 9:8 Select input qualification type for GPIO116
    Uint16 GPIO117:2;                   // 11:10 Select input qualification type for GPIO117
    Uint16 GPIO118:2;                   // 13:12 Select input qualification type for GPIO118
    Uint16 GPIO119:2;                   // 15:14 Select input qualification type for GPIO119
    Uint16 GPIO120:2;                   // 17:16 Select input qualification type for GPIO120
    Uint16 GPIO121:2;                   // 19:18 Select input qualification type for GPIO121
    Uint16 GPIO122:2;                   // 21:20 Select input qualification type for GPIO122
    Uint16 GPIO123:2;                   // 23:22 Select input qualification type for GPIO123
    Uint16 GPIO124:2;                   // 25:24 Select input qualification type for GPIO124
    Uint16 GPIO125:2;                   // 27:26 Select input qualification type for GPIO125
    Uint16 GPIO126:2;                   // 29:28 Select input qualification type for GPIO126
    Uint16 GPIO127:2;                   // 31:30 Select input qualification type for GPIO127
};

union GPDQSEL2_REG {
    Uint32  all;
    struct  GPDQSEL2_BITS  bit;
};

#ifdef CPU1
// GPDQSEL2 Register
//// GPDQSEL2 Register : Byte Value
#define GPDQSEL2_GPIO127_Synch							0x00000000UL
#define GPDQSEL2_GPIO127_3SampSynch						0x40000000UL
#define GPDQSEL2_GPIO127_6SampSynch						0x80000000UL
#define GPDQSEL2_GPIO127_Asynch							0xC0000000UL

#define GPDQSEL2_GPIO126_Synch							0x00000000UL
#define GPDQSEL2_GPIO126_3SampSynch						0x10000000UL
#define GPDQSEL2_GPIO126_6SampSynch						0x20000000UL
#define GPDQSEL2_GPIO126_Asynch							0x30000000UL

#define GPDQSEL2_GPIO125_Synch							0x00000000UL
#define GPDQSEL2_GPIO125_3SampSynch						0x04000000UL
#define GPDQSEL2_GPIO125_6SampSynch						0x08000000UL
#define GPDQSEL2_GPIO125_Asynch							0x0C000000UL

#define GPDQSEL2_GPIO124_Synch							0x00000000UL
#define GPDQSEL2_GPIO124_3SampSynch						0x01000000UL
#define GPDQSEL2_GPIO124_6SampSynch						0x02000000UL
#define GPDQSEL2_GPIO124_Asynch							0x03000000UL

#define GPDQSEL2_GPIO123_Synch							0x00000000UL
#define GPDQSEL2_GPIO123_3SampSynch						0x00400000UL
#define GPDQSEL2_GPIO123_6SampSynch						0x00800000UL
#define GPDQSEL2_GPIO123_Asynch							0x00C00000UL

#define GPDQSEL2_GPIO122_Synch							0x00000000UL
#define GPDQSEL2_GPIO122_3SampSynch						0x00100000UL
#define GPDQSEL2_GPIO122_6SampSynch						0x00200000UL
#define GPDQSEL2_GPIO122_Asynch							0x00300000UL

#define GPDQSEL2_GPIO121_Synch							0x00000000UL
#define GPDQSEL2_GPIO121_3SampSynch						0x00040000UL
#define GPDQSEL2_GPIO121_6SampSynch						0x00080000UL
#define GPDQSEL2_GPIO121_Asynch							0x000C0000UL

#define GPDQSEL2_GPIO120_Synch							0x00000000UL
#define GPDQSEL2_GPIO120_3SampSynch						0x00010000UL
#define GPDQSEL2_GPIO120_6SampSynch						0x00020000UL
#define GPDQSEL2_GPIO120_Asynch							0x00030000UL

#define GPDQSEL2_GPIO119_Synch							0x00000000UL
#define GPDQSEL2_GPIO119_3SampSynch						0x00004000UL
#define GPDQSEL2_GPIO119_6SampSynch						0x00008000UL
#define GPDQSEL2_GPIO119_Asynch							0x0000C000UL

#define GPDQSEL2_GPIO118_Synch							0x00000000UL
#define GPDQSEL2_GPIO118_3SampSynch						0x00001000UL
#define GPDQSEL2_GPIO118_6SampSynch						0x00002000UL
#define GPDQSEL2_GPIO118_Asynch							0x00003000UL

#define GPDQSEL2_GPIO117_Synch							0x00000000UL
#define GPDQSEL2_GPIO117_3SampSynch						0x00000400UL
#define GPDQSEL2_GPIO117_6SampSynch						0x00000800UL
#define GPDQSEL2_GPIO117_Asynch							0x00000C00UL

#define GPDQSEL2_GPIO116_Synch							0x00000000UL
#define GPDQSEL2_GPIO116_3SampSynch						0x00000100UL
#define GPDQSEL2_GPIO116_6SampSynch						0x00000200UL
#define GPDQSEL2_GPIO116_Asynch							0x00000300UL

#define GPDQSEL2_GPIO115_Synch							0x00000000UL
#define GPDQSEL2_GPIO115_3SampSynch						0x00000040UL
#define GPDQSEL2_GPIO115_6SampSynch						0x00000080UL
#define GPDQSEL2_GPIO115_Asynch							0x000000C0UL

#define GPDQSEL2_GPIO114_Synch							0x00000000UL
#define GPDQSEL2_GPIO114_3SampSynch						0x00000010UL
#define GPDQSEL2_GPIO114_6SampSynch						0x00000020UL
#define GPDQSEL2_GPIO114_Asynch							0x00000030UL

#define GPDQSEL2_GPIO113_Synch							0x00000000UL
#define GPDQSEL2_GPIO113_3SampSynch						0x00000004UL
#define GPDQSEL2_GPIO113_6SampSynch						0x00000008UL
#define GPDQSEL2_GPIO113_Asynch							0x0000000CUL

#define GPDQSEL2_GPIO112_Synch							0x00000000UL
#define GPDQSEL2_GPIO112_3SampSynch						0x00000001UL
#define GPDQSEL2_GPIO112_6SampSynch						0x00000002UL
#define GPDQSEL2_GPIO112_Asynch							0x00000003UL
#endif

struct GPDMUX1_BITS {                   // bits description
    Uint16 GPIO96:2;                    // 1:0 Defines pin-muxing selection for GPIO96
    Uint16 GPIO97:2;                    // 3:2 Defines pin-muxing selection for GPIO97
    Uint16 GPIO98:2;                    // 5:4 Defines pin-muxing selection for GPIO98
    Uint16 GPIO99:2;                    // 7:6 Defines pin-muxing selection for GPIO99
    Uint16 GPIO100:2;                   // 9:8 Defines pin-muxing selection for GPIO100
    Uint16 GPIO101:2;                   // 11:10 Defines pin-muxing selection for GPIO101
    Uint16 GPIO102:2;                   // 13:12 Defines pin-muxing selection for GPIO102
    Uint16 GPIO103:2;                   // 15:14 Defines pin-muxing selection for GPIO103
    Uint16 GPIO104:2;                   // 17:16 Defines pin-muxing selection for GPIO104
    Uint16 GPIO105:2;                   // 19:18 Defines pin-muxing selection for GPIO105
    Uint16 GPIO106:2;                   // 21:20 Defines pin-muxing selection for GPIO106
    Uint16 GPIO107:2;                   // 23:22 Defines pin-muxing selection for GPIO107
    Uint16 GPIO108:2;                   // 25:24 Defines pin-muxing selection for GPIO108
    Uint16 GPIO109:2;                   // 27:26 Defines pin-muxing selection for GPIO109
    Uint16 GPIO110:2;                   // 29:28 Defines pin-muxing selection for GPIO110
    Uint16 GPIO111:2;                   // 31:30 Defines pin-muxing selection for GPIO111
};

union GPDMUX1_REG {
    Uint32  all;
    struct  GPDMUX1_BITS  bit;
};

#ifdef CPU1
// GPDMUX1 Register
//// GPDMUX1 Register : Byte Value													// GMUX		MUX
#define GPDMUX1_GPIO111_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO111_OutEM2BA0						0xC0000000UL				// 0b00		0b11

#define GPDMUX1_GPIO110_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO110_OutEM2WAIT						0x30000000UL				// 0b00		0b11

#define GPDMUX1_GPIO109_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO109_OutEM2A11						0x0C000000UL				// 0b00		0b11

#define GPDMUX1_GPIO108_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO108_OutEM2A10						0x03000000UL				// 0b00		0b11

#define GPDMUX1_GPIO107_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO107_OutEM2A9						0x00C00000UL				// 0b00		0b11
#define GPDMUX1_GPIO107_InOutEQEP3I						0x00400000UL				// 0b01		0b01
#define GPDMUX1_GPIO107_InSCIRXDC						0x00800000UL				// 0b01		0b10

#define GPDMUX1_GPIO106_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO106_OutEM2A8						0x00300000UL				// 0b00		0b11
#define GPDMUX1_GPIO106_InOutEQEP3S						0x00100000UL				// 0b01		0b01
#define GPDMUX1_GPIO106_OutSCITXDC						0x00200000UL				// 0b01		0b10

#define GPDMUX1_GPIO105_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO105_InODSCLA						0x00040000UL				// 0b00		0b01
#define GPDMUX1_GPIO105_OutEM2A7						0x000C0000UL				// 0b00		0b11
#define GPDMUX1_GPIO105_InEQEP3B						0x00040000UL				// 0b01		0b01
#define GPDMUX1_GPIO105_InSCIRXDD						0x00080000UL				// 0b01		0b10

#define GPDMUX1_GPIO104_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO104_InODSDAA						0x00010000UL				// 0b00		0b01
#define GPDMUX1_GPIO104_OutEM2A6						0x00030000UL				// 0b00		0b11
#define GPDMUX1_GPIO104_InEQEP3A						0x00010000UL				// 0b01		0b01
#define GPDMUX1_GPIO104_OutSCITXDD						0x00020000UL				// 0b01		0b10

#define GPDMUX1_GPIO103_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO103_OutEM2A5						0x0000C000UL				// 0b00		0b11
#define GPDMUX1_GPIO103_InOutEQEP2I						0x00004000UL				// 0b01		0b01
#define GPDMUX1_GPIO103_InOutnSPISTEC					0x00008000UL				// 0b01		0b10

#define GPDMUX1_GPIO102_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO102_OutEM2A4						0x00003000UL				// 0b00		0b11
#define GPDMUX1_GPIO102_InOutEQEP2S						0x00001000UL				// 0b01		0b01
#define GPDMUX1_GPIO102_InOutSPICLKC					0x00002000UL				// 0b01		0b10

#define GPDMUX1_GPIO101_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO101_OutEM2A3						0x00000C00UL				// 0b00		0b11
#define GPDMUX1_GPIO101_InEQEP2B						0x00000400UL				// 0b01		0b01
#define GPDMUX1_GPIO101_InOutSPISOMIC					0x00000800UL				// 0b01		0b10

#define GPDMUX1_GPIO100_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO100_OutEM2A2						0x00000300UL				// 0b00		0b11
#define GPDMUX1_GPIO100_InEQEP2A						0x00000100UL				// 0b01		0b01
#define GPDMUX1_GPIO100_InOutSPISIMOC					0x00000200UL				// 0b01		0b10

#define GPDMUX1_GPIO099_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO099_OutEM2A1						0x000000C0UL				// 0b00		0b11
#define GPDMUX1_GPIO099_InOutEQEP1I						0x00000040UL				// 0b01		0b01

#define GPDMUX1_GPIO098_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO098_OutEM2A0						0x00000030UL				// 0b00		0b11
#define GPDMUX1_GPIO098_InOutEQEP1S						0x00000010UL				// 0b01		0b01

#define GPDMUX1_GPIO097_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO097_OutEM2DQM0						0x0000000CUL				// 0b00		0b11
#define GPDMUX1_GPIO097_InEQEP1B						0x00000004UL				// 0b01		0b01

#define GPDMUX1_GPIO096_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX1_GPIO096_OutEM2DQM1						0x00000003UL				// 0b00		0b11
#define GPDMUX1_GPIO096_InEQEP1A						0x00000001UL				// 0b01		0b01
#endif

struct GPDMUX2_BITS {                   // bits description
    Uint16 GPIO112:2;                   // 1:0 Defines pin-muxing selection for GPIO112
    Uint16 GPIO113:2;                   // 3:2 Defines pin-muxing selection for GPIO113
    Uint16 GPIO114:2;                   // 5:4 Defines pin-muxing selection for GPIO114
    Uint16 GPIO115:2;                   // 7:6 Defines pin-muxing selection for GPIO115
    Uint16 GPIO116:2;                   // 9:8 Defines pin-muxing selection for GPIO116
    Uint16 GPIO117:2;                   // 11:10 Defines pin-muxing selection for GPIO117
    Uint16 GPIO118:2;                   // 13:12 Defines pin-muxing selection for GPIO118
    Uint16 GPIO119:2;                   // 15:14 Defines pin-muxing selection for GPIO119
    Uint16 GPIO120:2;                   // 17:16 Defines pin-muxing selection for GPIO120
    Uint16 GPIO121:2;                   // 19:18 Defines pin-muxing selection for GPIO121
    Uint16 GPIO122:2;                   // 21:20 Defines pin-muxing selection for GPIO122
    Uint16 GPIO123:2;                   // 23:22 Defines pin-muxing selection for GPIO123
    Uint16 GPIO124:2;                   // 25:24 Defines pin-muxing selection for GPIO124
    Uint16 GPIO125:2;                   // 27:26 Defines pin-muxing selection for GPIO125
    Uint16 GPIO126:2;                   // 29:28 Defines pin-muxing selection for GPIO126
    Uint16 GPIO127:2;                   // 31:30 Defines pin-muxing selection for GPIO127
};

union GPDMUX2_REG {
    Uint32  all;
    struct  GPDMUX2_BITS  bit;
};

#ifdef CPU1
// GPDMUX2 Register
//// GPDMUX2 Register : Byte Value													// GMUX		MUX
#define GPDMUX2_GPIO127_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO127_InSD1_C3						0xC0000000UL				// 0b01		0b11

#define GPDMUX2_GPIO126_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO126_InSD1_D3						0x30000000UL				// 0b01		0b11

#define GPDMUX2_GPIO125_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO125_InOutnSPISTEC					0x08000000UL				// 0b01		0b10
#define GPDMUX2_GPIO125_InSD1_C2						0x0C000000UL				// 0b01		0b11

#define GPDMUX2_GPIO124_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO124_InOutSPICLKC					0x02000000UL				// 0b01		0b10
#define GPDMUX2_GPIO124_InSD1_D2						0x03000000UL				// 0b01		0b11

#define GPDMUX2_GPIO123_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO123_InOutSPISOMIC					0x00800000UL				// 0b01		0b10
#define GPDMUX2_GPIO123_InSD1_C1						0x00C00000UL				// 0b01		0b11

#define GPDMUX2_GPIO122_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO122_InOutSPISIMOC					0x00200000UL				// 0b01		0b10
#define GPDMUX2_GPIO122_InSD1_D1						0x00300000UL				// 0b01		0b11

#define GPDMUX2_GPIO121_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO121_OutnEM2OE						0x000C0000UL				// 0b00		0b11
#define GPDMUX2_GPIO121_InOutUSB0EPEN					0x000C0000UL				// 0b11		0b11

#define GPDMUX2_GPIO120_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO120_OutnEM2WE						0x00030000UL				// 0b00		0b11
#define GPDMUX2_GPIO120_InOutUSB0PFLT					0x00030000UL				// 0b11		0b11

#define GPDMUX2_GPIO119_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO119_OutEM2RNW						0x0000C000UL				// 0b00		0b11

#define GPDMUX2_GPIO118_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO118_OutEM2CLK						0x00003000UL				// 0b00		0b11

#define GPDMUX2_GPIO117_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO117_OutEM2SDCKE						0x00000C00UL				// 0b00		0b11

#define GPDMUX2_GPIO116_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO116_OutnEM2CS2						0x00000300UL				// 0b00		0b11

#define GPDMUX2_GPIO115_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO115_OutnEM2CS0						0x000000C0UL				// 0b00		0b11

#define GPDMUX2_GPIO114_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO114_OutEM2RAS						0x00000030UL				// 0b00		0b11

#define GPDMUX2_GPIO113_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO113_OutEM2CAS						0x0000000CUL				// 0b00		0b11

#define GPDMUX2_GPIO112_InOutGPIO						0x00000000UL				// -		0b00
#define GPDMUX2_GPIO112_OutEM2BA1						0x00000003UL				// 0b00		0b11
#endif

struct GPDDIR_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO97:1;                    // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO98:1;                    // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO99:1;                    // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO100:1;                   // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO101:1;                   // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO102:1;                   // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO103:1;                   // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO104:1;                   // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO105:1;                   // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO106:1;                   // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO107:1;                   // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO108:1;                   // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO109:1;                   // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO110:1;                   // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO111:1;                   // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO112:1;                   // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO113:1;                   // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO114:1;                   // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO115:1;                   // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO116:1;                   // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO117:1;                   // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO118:1;                   // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO119:1;                   // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO120:1;                   // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO121:1;                   // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO122:1;                   // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO123:1;                   // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO124:1;                   // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO125:1;                   // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO126:1;                   // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO127:1;                   // 31 Defines direction for this pin in GPIO mode
};

union GPDDIR_REG {
    Uint32  all;
    struct  GPDDIR_BITS  bit;
};

#ifdef CPU1
// GPDDIR Register
//// GPDDIR Register : Byte Value
#define GPDDIR_GPIO127_Input							0x00000000UL
#define GPDDIR_GPIO127_Output							0x80000000UL

#define GPDDIR_GPIO126_Input							0x00000000UL
#define GPDDIR_GPIO126_Output							0x40000000UL

#define GPDDIR_GPIO125_Input							0x00000000UL
#define GPDDIR_GPIO125_Output							0x20000000UL

#define GPDDIR_GPIO124_Input							0x00000000UL
#define GPDDIR_GPIO124_Output							0x10000000UL

#define GPDDIR_GPIO123_Input							0x00000000UL
#define GPDDIR_GPIO123_Output							0x08000000UL

#define GPDDIR_GPIO122_Input							0x00000000UL
#define GPDDIR_GPIO122_Output							0x04000000UL

#define GPDDIR_GPIO121_Input							0x00000000UL
#define GPDDIR_GPIO121_Output							0x02000000UL

#define GPDDIR_GPIO120_Input							0x00000000UL
#define GPDDIR_GPIO120_Output							0x01000000UL

#define GPDDIR_GPIO119_Input							0x00000000UL
#define GPDDIR_GPIO119_Output							0x00800000UL

#define GPDDIR_GPIO118_Input							0x00000000UL
#define GPDDIR_GPIO118_Output							0x00400000UL

#define GPDDIR_GPIO117_Input							0x00000000UL
#define GPDDIR_GPIO117_Output							0x00200000UL

#define GPDDIR_GPIO116_Input							0x00000000UL
#define GPDDIR_GPIO116_Output							0x00100000UL

#define GPDDIR_GPIO115_Input							0x00000000UL
#define GPDDIR_GPIO115_Output							0x00080000UL

#define GPDDIR_GPIO114_Input							0x00000000UL
#define GPDDIR_GPIO114_Output							0x00040000UL

#define GPDDIR_GPIO113_Input							0x00000000UL
#define GPDDIR_GPIO113_Output							0x00020000UL

#define GPDDIR_GPIO112_Input							0x00000000UL
#define GPDDIR_GPIO112_Output							0x00010000UL

#define GPDDIR_GPIO111_Input							0x00000000UL
#define GPDDIR_GPIO111_Output							0x00008000UL

#define GPDDIR_GPIO110_Input							0x00000000UL
#define GPDDIR_GPIO110_Output							0x00004000UL

#define GPDDIR_GPIO109_Input							0x00000000UL
#define GPDDIR_GPIO109_Output							0x00002000UL

#define GPDDIR_GPIO108_Input							0x00000000UL
#define GPDDIR_GPIO108_Output							0x00001000UL

#define GPDDIR_GPIO107_Input							0x00000000UL
#define GPDDIR_GPIO107_Output							0x00000800UL

#define GPDDIR_GPIO106_Input							0x00000000UL
#define GPDDIR_GPIO106_Output							0x00000400UL

#define GPDDIR_GPIO105_Input							0x00000000UL
#define GPDDIR_GPIO105_Output							0x00000200UL

#define GPDDIR_GPIO104_Input							0x00000000UL
#define GPDDIR_GPIO104_Output							0x00000100UL

#define GPDDIR_GPIO103_Input							0x00000000UL
#define GPDDIR_GPIO103_Output							0x00000080UL

#define GPDDIR_GPIO102_Input							0x00000000UL
#define GPDDIR_GPIO102_Output							0x00000040UL

#define GPDDIR_GPIO101_Input							0x00000000UL
#define GPDDIR_GPIO101_Output							0x00000020UL

#define GPDDIR_GPIO100_Input							0x00000000UL
#define GPDDIR_GPIO100_Output							0x00000010UL

#define GPDDIR_GPIO099_Input							0x00000000UL
#define GPDDIR_GPIO099_Output							0x00000008UL

#define GPDDIR_GPIO098_Input							0x00000000UL
#define GPDDIR_GPIO098_Output							0x00000004UL

#define GPDDIR_GPIO097_Input							0x00000000UL
#define GPDDIR_GPIO097_Output							0x00000002UL

#define GPDDIR_GPIO096_Input							0x00000000UL
#define GPDDIR_GPIO096_Output							0x00000001UL
#endif

struct GPDPUD_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Pull-Up Disable control for this pin
    Uint16 GPIO97:1;                    // 1 Pull-Up Disable control for this pin
    Uint16 GPIO98:1;                    // 2 Pull-Up Disable control for this pin
    Uint16 GPIO99:1;                    // 3 Pull-Up Disable control for this pin
    Uint16 GPIO100:1;                   // 4 Pull-Up Disable control for this pin
    Uint16 GPIO101:1;                   // 5 Pull-Up Disable control for this pin
    Uint16 GPIO102:1;                   // 6 Pull-Up Disable control for this pin
    Uint16 GPIO103:1;                   // 7 Pull-Up Disable control for this pin
    Uint16 GPIO104:1;                   // 8 Pull-Up Disable control for this pin
    Uint16 GPIO105:1;                   // 9 Pull-Up Disable control for this pin
    Uint16 GPIO106:1;                   // 10 Pull-Up Disable control for this pin
    Uint16 GPIO107:1;                   // 11 Pull-Up Disable control for this pin
    Uint16 GPIO108:1;                   // 12 Pull-Up Disable control for this pin
    Uint16 GPIO109:1;                   // 13 Pull-Up Disable control for this pin
    Uint16 GPIO110:1;                   // 14 Pull-Up Disable control for this pin
    Uint16 GPIO111:1;                   // 15 Pull-Up Disable control for this pin
    Uint16 GPIO112:1;                   // 16 Pull-Up Disable control for this pin
    Uint16 GPIO113:1;                   // 17 Pull-Up Disable control for this pin
    Uint16 GPIO114:1;                   // 18 Pull-Up Disable control for this pin
    Uint16 GPIO115:1;                   // 19 Pull-Up Disable control for this pin
    Uint16 GPIO116:1;                   // 20 Pull-Up Disable control for this pin
    Uint16 GPIO117:1;                   // 21 Pull-Up Disable control for this pin
    Uint16 GPIO118:1;                   // 22 Pull-Up Disable control for this pin
    Uint16 GPIO119:1;                   // 23 Pull-Up Disable control for this pin
    Uint16 GPIO120:1;                   // 24 Pull-Up Disable control for this pin
    Uint16 GPIO121:1;                   // 25 Pull-Up Disable control for this pin
    Uint16 GPIO122:1;                   // 26 Pull-Up Disable control for this pin
    Uint16 GPIO123:1;                   // 27 Pull-Up Disable control for this pin
    Uint16 GPIO124:1;                   // 28 Pull-Up Disable control for this pin
    Uint16 GPIO125:1;                   // 29 Pull-Up Disable control for this pin
    Uint16 GPIO126:1;                   // 30 Pull-Up Disable control for this pin
    Uint16 GPIO127:1;                   // 31 Pull-Up Disable control for this pin
};

union GPDPUD_REG {
    Uint32  all;
    struct  GPDPUD_BITS  bit;
};

#ifdef CPU1
// GPDPUD Register
//// GPDPUD Register : Byte Value
#define GPDPUD_GPIO127_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO127_PullUpDisable					0x80000000UL

#define GPDPUD_GPIO126_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO126_PullUpDisable					0x40000000UL

#define GPDPUD_GPIO125_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO125_PullUpDisable					0x20000000UL

#define GPDPUD_GPIO124_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO124_PullUpDisable					0x10000000UL

#define GPDPUD_GPIO123_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO123_PullUpDisable					0x08000000UL

#define GPDPUD_GPIO122_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO122_PullUpDisable					0x04000000UL

#define GPDPUD_GPIO121_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO121_PullUpDisable					0x02000000UL

#define GPDPUD_GPIO120_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO120_PullUpDisable					0x01000000UL

#define GPDPUD_GPIO119_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO119_PullUpDisable					0x00800000UL

#define GPDPUD_GPIO118_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO118_PullUpDisable					0x00400000UL

#define GPDPUD_GPIO117_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO117_PullUpDisable					0x00200000UL

#define GPDPUD_GPIO116_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO116_PullUpDisable					0x00100000UL

#define GPDPUD_GPIO115_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO115_PullUpDisable					0x00080000UL

#define GPDPUD_GPIO114_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO114_PullUpDisable					0x00040000UL

#define GPDPUD_GPIO113_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO113_PullUpDisable					0x00020000UL

#define GPDPUD_GPIO112_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO112_PullUpDisable					0x00010000UL

#define GPDPUD_GPIO111_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO111_PullUpDisable					0x00008000UL

#define GPDPUD_GPIO110_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO110_PullUpDisable					0x00004000UL

#define GPDPUD_GPIO109_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO109_PullUpDisable					0x00002000UL

#define GPDPUD_GPIO108_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO108_PullUpDisable					0x00001000UL

#define GPDPUD_GPIO107_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO107_PullUpDisable					0x00000800UL

#define GPDPUD_GPIO106_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO106_PullUpDisable					0x00000400UL

#define GPDPUD_GPIO105_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO105_PullUpDisable					0x00000200UL

#define GPDPUD_GPIO104_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO104_PullUpDisable					0x00000100UL

#define GPDPUD_GPIO103_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO103_PullUpDisable					0x00000080UL

#define GPDPUD_GPIO102_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO102_PullUpDisable					0x00000040UL

#define GPDPUD_GPIO101_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO101_PullUpDisable					0x00000020UL

#define GPDPUD_GPIO100_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO100_PullUpDisable					0x00000010UL

#define GPDPUD_GPIO099_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO099_PullUpDisable					0x00000008UL

#define GPDPUD_GPIO098_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO098_PullUpDisable					0x00000004UL

#define GPDPUD_GPIO097_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO097_PullUpDisable					0x00000002UL

#define GPDPUD_GPIO096_PullUpEnable						0x00000000UL
#define GPDPUD_GPIO096_PullUpDisable					0x00000001UL
#endif

struct GPDINV_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Input inversion control for this pin
    Uint16 GPIO97:1;                    // 1 Input inversion control for this pin
    Uint16 GPIO98:1;                    // 2 Input inversion control for this pin
    Uint16 GPIO99:1;                    // 3 Input inversion control for this pin
    Uint16 GPIO100:1;                   // 4 Input inversion control for this pin
    Uint16 GPIO101:1;                   // 5 Input inversion control for this pin
    Uint16 GPIO102:1;                   // 6 Input inversion control for this pin
    Uint16 GPIO103:1;                   // 7 Input inversion control for this pin
    Uint16 GPIO104:1;                   // 8 Input inversion control for this pin
    Uint16 GPIO105:1;                   // 9 Input inversion control for this pin
    Uint16 GPIO106:1;                   // 10 Input inversion control for this pin
    Uint16 GPIO107:1;                   // 11 Input inversion control for this pin
    Uint16 GPIO108:1;                   // 12 Input inversion control for this pin
    Uint16 GPIO109:1;                   // 13 Input inversion control for this pin
    Uint16 GPIO110:1;                   // 14 Input inversion control for this pin
    Uint16 GPIO111:1;                   // 15 Input inversion control for this pin
    Uint16 GPIO112:1;                   // 16 Input inversion control for this pin
    Uint16 GPIO113:1;                   // 17 Input inversion control for this pin
    Uint16 GPIO114:1;                   // 18 Input inversion control for this pin
    Uint16 GPIO115:1;                   // 19 Input inversion control for this pin
    Uint16 GPIO116:1;                   // 20 Input inversion control for this pin
    Uint16 GPIO117:1;                   // 21 Input inversion control for this pin
    Uint16 GPIO118:1;                   // 22 Input inversion control for this pin
    Uint16 GPIO119:1;                   // 23 Input inversion control for this pin
    Uint16 GPIO120:1;                   // 24 Input inversion control for this pin
    Uint16 GPIO121:1;                   // 25 Input inversion control for this pin
    Uint16 GPIO122:1;                   // 26 Input inversion control for this pin
    Uint16 GPIO123:1;                   // 27 Input inversion control for this pin
    Uint16 GPIO124:1;                   // 28 Input inversion control for this pin
    Uint16 GPIO125:1;                   // 29 Input inversion control for this pin
    Uint16 GPIO126:1;                   // 30 Input inversion control for this pin
    Uint16 GPIO127:1;                   // 31 Input inversion control for this pin
};

union GPDINV_REG {
    Uint32  all;
    struct  GPDINV_BITS  bit;
};

#ifdef CPU1
// GPDINV Register
//// GPDINV Register : Byte Value
#define GPDINV_GPIO127_InNormal							0x00000000UL
#define GPDINV_GPIO127_InInverted						0x80000000UL

#define GPDINV_GPIO126_InNormal							0x00000000UL
#define GPDINV_GPIO126_InInverted						0x40000000UL

#define GPDINV_GPIO125_InNormal							0x00000000UL
#define GPDINV_GPIO125_InInverted						0x20000000UL

#define GPDINV_GPIO124_InNormal							0x00000000UL
#define GPDINV_GPIO124_InInverted						0x10000000UL

#define GPDINV_GPIO123_InNormal							0x00000000UL
#define GPDINV_GPIO123_InInverted						0x08000000UL

#define GPDINV_GPIO122_InNormal							0x00000000UL
#define GPDINV_GPIO122_InInverted						0x04000000UL

#define GPDINV_GPIO121_InNormal							0x00000000UL
#define GPDINV_GPIO121_InInverted						0x02000000UL

#define GPDINV_GPIO120_InNormal							0x00000000UL
#define GPDINV_GPIO120_InInverted						0x01000000UL

#define GPDINV_GPIO119_InNormal							0x00000000UL
#define GPDINV_GPIO119_InInverted						0x00800000UL

#define GPDINV_GPIO118_InNormal							0x00000000UL
#define GPDINV_GPIO118_InInverted						0x00400000UL

#define GPDINV_GPIO117_InNormal							0x00000000UL
#define GPDINV_GPIO117_InInverted						0x00200000UL

#define GPDINV_GPIO116_InNormal							0x00000000UL
#define GPDINV_GPIO116_InInverted						0x00100000UL

#define GPDINV_GPIO115_InNormal							0x00000000UL
#define GPDINV_GPIO115_InInverted						0x00080000UL

#define GPDINV_GPIO114_InNormal							0x00000000UL
#define GPDINV_GPIO114_InInverted						0x00040000UL

#define GPDINV_GPIO113_InNormal							0x00000000UL
#define GPDINV_GPIO113_InInverted						0x00020000UL

#define GPDINV_GPIO112_InNormal							0x00000000UL
#define GPDINV_GPIO112_InInverted						0x00010000UL

#define GPDINV_GPIO111_InNormal							0x00000000UL
#define GPDINV_GPIO111_InInverted						0x00008000UL

#define GPDINV_GPIO110_InNormal							0x00000000UL
#define GPDINV_GPIO110_InInverted						0x00004000UL

#define GPDINV_GPIO109_InNormal							0x00000000UL
#define GPDINV_GPIO109_InInverted						0x00002000UL

#define GPDINV_GPIO108_InNormal							0x00000000UL
#define GPDINV_GPIO108_InInverted						0x00001000UL

#define GPDINV_GPIO107_InNormal							0x00000000UL
#define GPDINV_GPIO107_InInverted						0x00000800UL

#define GPDINV_GPIO106_InNormal							0x00000000UL
#define GPDINV_GPIO106_InInverted						0x00000400UL

#define GPDINV_GPIO105_InNormal							0x00000000UL
#define GPDINV_GPIO105_InInverted						0x00000200UL

#define GPDINV_GPIO104_InNormal							0x00000000UL
#define GPDINV_GPIO104_InInverted						0x00000100UL

#define GPDINV_GPIO103_InNormal							0x00000000UL
#define GPDINV_GPIO103_InInverted						0x00000080UL

#define GPDINV_GPIO102_InNormal							0x00000000UL
#define GPDINV_GPIO102_InInverted						0x00000040UL

#define GPDINV_GPIO101_InNormal							0x00000000UL
#define GPDINV_GPIO101_InInverted						0x00000020UL

#define GPDINV_GPIO100_InNormal							0x00000000UL
#define GPDINV_GPIO100_InInverted						0x00000010UL

#define GPDINV_GPIO099_InNormal							0x00000000UL
#define GPDINV_GPIO099_InInverted						0x00000008UL

#define GPDINV_GPIO098_InNormal							0x00000000UL
#define GPDINV_GPIO098_InInverted						0x00000004UL

#define GPDINV_GPIO097_InNormal							0x00000000UL
#define GPDINV_GPIO097_InInverted						0x00000002UL

#define GPDINV_GPIO096_InNormal							0x00000000UL
#define GPDINV_GPIO096_InInverted						0x00000001UL
#endif

struct GPDODR_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO97:1;                    // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO98:1;                    // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO99:1;                    // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO100:1;                   // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO101:1;                   // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO102:1;                   // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO103:1;                   // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO104:1;                   // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO105:1;                   // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO106:1;                   // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO107:1;                   // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO108:1;                   // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO109:1;                   // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO110:1;                   // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO111:1;                   // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO112:1;                   // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO113:1;                   // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO114:1;                   // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO115:1;                   // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO116:1;                   // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO117:1;                   // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO118:1;                   // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO119:1;                   // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO120:1;                   // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO121:1;                   // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO122:1;                   // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO123:1;                   // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO124:1;                   // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO125:1;                   // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO126:1;                   // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO127:1;                   // 31 Outpout Open-Drain control for this pin
};

union GPDODR_REG {
    Uint32  all;
    struct  GPDODR_BITS  bit;
};

#ifdef CPU1
// GPDODR Register
//// GPDODR Register : Byte Value
#define GPDODR_GPIO127_Normal							0x00000000UL
#define GPDODR_GPIO127_OpenDrain						0x80000000UL

#define GPDODR_GPIO126_Normal							0x00000000UL
#define GPDODR_GPIO126_OpenDrain						0x40000000UL

#define GPDODR_GPIO125_Normal							0x00000000UL
#define GPDODR_GPIO125_OpenDrain						0x20000000UL

#define GPDODR_GPIO124_Normal							0x00000000UL
#define GPDODR_GPIO124_OpenDrain						0x10000000UL

#define GPDODR_GPIO123_Normal							0x00000000UL
#define GPDODR_GPIO123_OpenDrain						0x08000000UL

#define GPDODR_GPIO122_Normal							0x00000000UL
#define GPDODR_GPIO122_OpenDrain						0x04000000UL

#define GPDODR_GPIO121_Normal							0x00000000UL
#define GPDODR_GPIO121_OpenDrain						0x02000000UL

#define GPDODR_GPIO120_Normal							0x00000000UL
#define GPDODR_GPIO120_OpenDrain						0x01000000UL

#define GPDODR_GPIO119_Normal							0x00000000UL
#define GPDODR_GPIO119_OpenDrain						0x00800000UL

#define GPDODR_GPIO118_Normal							0x00000000UL
#define GPDODR_GPIO118_OpenDrain						0x00400000UL

#define GPDODR_GPIO117_Normal							0x00000000UL
#define GPDODR_GPIO117_OpenDrain						0x00200000UL

#define GPDODR_GPIO116_Normal							0x00000000UL
#define GPDODR_GPIO116_OpenDrain						0x00100000UL

#define GPDODR_GPIO115_Normal							0x00000000UL
#define GPDODR_GPIO115_OpenDrain						0x00080000UL

#define GPDODR_GPIO114_Normal							0x00000000UL
#define GPDODR_GPIO114_OpenDrain						0x00040000UL

#define GPDODR_GPIO113_Normal							0x00000000UL
#define GPDODR_GPIO113_OpenDrain						0x00020000UL

#define GPDODR_GPIO112_Normal							0x00000000UL
#define GPDODR_GPIO112_OpenDrain						0x00010000UL

#define GPDODR_GPIO111_Normal							0x00000000UL
#define GPDODR_GPIO111_OpenDrain						0x00008000UL

#define GPDODR_GPIO110_Normal							0x00000000UL
#define GPDODR_GPIO110_OpenDrain						0x00004000UL

#define GPDODR_GPIO109_Normal							0x00000000UL
#define GPDODR_GPIO109_OpenDrain						0x00002000UL

#define GPDODR_GPIO108_Normal							0x00000000UL
#define GPDODR_GPIO108_OpenDrain						0x00001000UL

#define GPDODR_GPIO107_Normal							0x00000000UL
#define GPDODR_GPIO107_OpenDrain						0x00000800UL

#define GPDODR_GPIO106_Normal							0x00000000UL
#define GPDODR_GPIO106_OpenDrain						0x00000400UL

#define GPDODR_GPIO105_Normal							0x00000000UL
#define GPDODR_GPIO105_OpenDrain						0x00000200UL

#define GPDODR_GPIO104_Normal							0x00000000UL
#define GPDODR_GPIO104_OpenDrain						0x00000100UL

#define GPDODR_GPIO103_Normal							0x00000000UL
#define GPDODR_GPIO103_OpenDrain						0x00000080UL

#define GPDODR_GPIO102_Normal							0x00000000UL
#define GPDODR_GPIO102_OpenDrain						0x00000040UL

#define GPDODR_GPIO101_Normal							0x00000000UL
#define GPDODR_GPIO101_OpenDrain						0x00000020UL

#define GPDODR_GPIO100_Normal							0x00000000UL
#define GPDODR_GPIO100_OpenDrain						0x00000010UL

#define GPDODR_GPIO099_Normal							0x00000000UL
#define GPDODR_GPIO099_OpenDrain						0x00000008UL

#define GPDODR_GPIO098_Normal							0x00000000UL
#define GPDODR_GPIO098_OpenDrain						0x00000004UL

#define GPDODR_GPIO097_Normal							0x00000000UL
#define GPDODR_GPIO097_OpenDrain						0x00000002UL

#define GPDODR_GPIO096_Normal							0x00000000UL
#define GPDODR_GPIO096_OpenDrain						0x00000001UL
#endif

struct GPDGMUX1_BITS {                  // bits description
    Uint16 GPIO96:2;                    // 1:0 Defines pin-muxing selection for GPIO96
    Uint16 GPIO97:2;                    // 3:2 Defines pin-muxing selection for GPIO97
    Uint16 GPIO98:2;                    // 5:4 Defines pin-muxing selection for GPIO98
    Uint16 GPIO99:2;                    // 7:6 Defines pin-muxing selection for GPIO99
    Uint16 GPIO100:2;                   // 9:8 Defines pin-muxing selection for GPIO100
    Uint16 GPIO101:2;                   // 11:10 Defines pin-muxing selection for GPIO101
    Uint16 GPIO102:2;                   // 13:12 Defines pin-muxing selection for GPIO102
    Uint16 GPIO103:2;                   // 15:14 Defines pin-muxing selection for GPIO103
    Uint16 GPIO104:2;                   // 17:16 Defines pin-muxing selection for GPIO104
    Uint16 GPIO105:2;                   // 19:18 Defines pin-muxing selection for GPIO105
    Uint16 GPIO106:2;                   // 21:20 Defines pin-muxing selection for GPIO106
    Uint16 GPIO107:2;                   // 23:22 Defines pin-muxing selection for GPIO107
    Uint16 GPIO108:2;                   // 25:24 Defines pin-muxing selection for GPIO108
    Uint16 GPIO109:2;                   // 27:26 Defines pin-muxing selection for GPIO109
    Uint16 GPIO110:2;                   // 29:28 Defines pin-muxing selection for GPIO110
    Uint16 GPIO111:2;                   // 31:30 Defines pin-muxing selection for GPIO111
};

union GPDGMUX1_REG {
    Uint32  all;
    struct  GPDGMUX1_BITS  bit;
};

#ifdef CPU1
// GPDGMUX1 Register
//// GPDGMUX1 Register : Byte Value													// GMUX		MUX
#define GPDGMUX1_GPIO111_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO111_OutEM2BA0						0x00000000UL				// 0b00		0b11

#define GPDGMUX1_GPIO110_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO110_OutEM2WAIT						0x00000000UL				// 0b00		0b11

#define GPDGMUX1_GPIO109_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO109_OutEM2A11						0x00000000UL				// 0b00		0b11

#define GPDGMUX1_GPIO108_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO108_OutEM2A10						0x00000000UL				// 0b00		0b11

#define GPDGMUX1_GPIO107_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO107_OutEM2A9						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO107_InOutEQEP3I					0x00400000UL				// 0b01		0b01
#define GPDGMUX1_GPIO107_InSCIRXDC						0x00400000UL				// 0b01		0b10

#define GPDGMUX1_GPIO106_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO106_OutEM2A8						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO106_InOutEQEP3S					0x00100000UL				// 0b01		0b01
#define GPDGMUX1_GPIO106_OutSCITXDC						0x00100000UL				// 0b01		0b10

#define GPDGMUX1_GPIO105_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO105_InODSCLA						0x00000000UL				// 0b00		0b01
#define GPDGMUX1_GPIO105_OutEM2A7						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO105_InEQEP3B						0x00040000UL				// 0b01		0b01
#define GPDGMUX1_GPIO105_InSCIRXDD						0x00040000UL				// 0b01		0b10

#define GPDGMUX1_GPIO104_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO104_InODSDAA						0x00000000UL				// 0b00		0b01
#define GPDGMUX1_GPIO104_OutEM2A6						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO104_InEQEP3A						0x00010000UL				// 0b01		0b01
#define GPDGMUX1_GPIO104_OutSCITXDD						0x00010000UL				// 0b01		0b10

#define GPDGMUX1_GPIO103_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO103_OutEM2A5						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO103_InOutEQEP2I					0x00004000UL				// 0b01		0b01
#define GPDGMUX1_GPIO103_InOutnSPISTEC					0x00004000UL				// 0b01		0b10

#define GPDGMUX1_GPIO102_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO102_OutEM2A4						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO102_InOutEQEP2S					0x00001000UL				// 0b01		0b01
#define GPDGMUX1_GPIO102_InOutSPICLKC					0x00001000UL				// 0b01		0b10

#define GPDGMUX1_GPIO101_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO101_OutEM2A3						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO101_InEQEP2B						0x00000400UL				// 0b01		0b01
#define GPDGMUX1_GPIO101_InOutSPISOMIC					0x00000400UL				// 0b01		0b10

#define GPDGMUX1_GPIO100_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO100_OutEM2A2						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO100_InEQEP2A						0x00000100UL				// 0b01		0b01
#define GPDGMUX1_GPIO100_InOutSPISIMOC					0x00000100UL				// 0b01		0b10

#define GPDGMUX1_GPIO099_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO099_OutEM2A1						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO099_InOutEQEP1I					0x00000040UL				// 0b01		0b01

#define GPDGMUX1_GPIO098_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO098_OutEM2A0						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO098_InOutEQEP1S					0x00000010UL				// 0b01		0b01

#define GPDGMUX1_GPIO097_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO097_OutEM2DQM0						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO097_InEQEP1B						0x00000004UL				// 0b01		0b01

#define GPDGMUX1_GPIO096_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX1_GPIO096_OutEM2DQM1						0x00000000UL				// 0b00		0b11
#define GPDGMUX1_GPIO096_InEQEP1A						0x00000001UL				// 0b01		0b01
#endif

struct GPDGMUX2_BITS {                  // bits description
    Uint16 GPIO112:2;                   // 1:0 Defines pin-muxing selection for GPIO112
    Uint16 GPIO113:2;                   // 3:2 Defines pin-muxing selection for GPIO113
    Uint16 GPIO114:2;                   // 5:4 Defines pin-muxing selection for GPIO114
    Uint16 GPIO115:2;                   // 7:6 Defines pin-muxing selection for GPIO115
    Uint16 GPIO116:2;                   // 9:8 Defines pin-muxing selection for GPIO116
    Uint16 GPIO117:2;                   // 11:10 Defines pin-muxing selection for GPIO117
    Uint16 GPIO118:2;                   // 13:12 Defines pin-muxing selection for GPIO118
    Uint16 GPIO119:2;                   // 15:14 Defines pin-muxing selection for GPIO119
    Uint16 GPIO120:2;                   // 17:16 Defines pin-muxing selection for GPIO120
    Uint16 GPIO121:2;                   // 19:18 Defines pin-muxing selection for GPIO121
    Uint16 GPIO122:2;                   // 21:20 Defines pin-muxing selection for GPIO122
    Uint16 GPIO123:2;                   // 23:22 Defines pin-muxing selection for GPIO123
    Uint16 GPIO124:2;                   // 25:24 Defines pin-muxing selection for GPIO124
    Uint16 GPIO125:2;                   // 27:26 Defines pin-muxing selection for GPIO125
    Uint16 GPIO126:2;                   // 29:28 Defines pin-muxing selection for GPIO126
    Uint16 GPIO127:2;                   // 31:30 Defines pin-muxing selection for GPIO127
};

union GPDGMUX2_REG {
    Uint32  all;
    struct  GPDGMUX2_BITS  bit;
};

#ifdef CPU1
// GPDGMUX2 Register
//// GPDGMUX2 Register : Byte Value													// GMUX		MUX
#define GPDGMUX2_GPIO127_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO127_InSD1_C3						0x40000000UL				// 0b01		0b11

#define GPDGMUX2_GPIO126_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO126_InSD1_D3						0x10000000UL				// 0b01		0b11

#define GPDGMUX2_GPIO125_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO125_InOutnSPISTEC					0x04000000UL				// 0b01		0b10
#define GPDGMUX2_GPIO125_InSD1_C2						0x04000000UL				// 0b01		0b11

#define GPDGMUX2_GPIO124_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO124_InOutSPICLKC					0x01000000UL				// 0b01		0b10
#define GPDGMUX2_GPIO124_InSD1_D2						0x01000000UL				// 0b01		0b11

#define GPDGMUX2_GPIO123_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO123_InOutSPISOMIC					0x00400000UL				// 0b01		0b10
#define GPDGMUX2_GPIO123_InSD1_C1						0x00400000UL				// 0b01		0b11

#define GPDGMUX2_GPIO122_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO122_InOutSPISIMOC					0x00100000UL				// 0b01		0b10
#define GPDGMUX2_GPIO122_InSD1_D1						0x00100000UL				// 0b01		0b11

#define GPDGMUX2_GPIO121_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO121_OutnEM2OE						0x00000000UL				// 0b00		0b11
#define GPDGMUX2_GPIO121_InOutUSB0EPEN					0x000C0000UL				// 0b11		0b11

#define GPDGMUX2_GPIO120_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO120_OutnEM2WE						0x00000000UL				// 0b00		0b11
#define GPDGMUX2_GPIO120_InOutUSB0PFLT					0x00030000UL				// 0b11		0b11

#define GPDGMUX2_GPIO119_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO119_OutEM2RNW						0x00000000UL				// 0b00		0b11

#define GPDGMUX2_GPIO118_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO118_OutEM2CLK						0x00000000UL				// 0b00		0b11

#define GPDGMUX2_GPIO117_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO117_OutEM2SDCKE					0x00000000UL				// 0b00		0b11

#define GPDGMUX2_GPIO116_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO116_OutnEM2CS2						0x00000000UL				// 0b00		0b11

#define GPDGMUX2_GPIO115_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO115_OutnEM2CS0						0x00000000UL				// 0b00		0b11

#define GPDGMUX2_GPIO114_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO114_OutEM2RAS						0x00000000UL				// 0b00		0b11

#define GPDGMUX2_GPIO113_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO113_OutEM2CAS						0x00000000UL				// 0b00		0b11

#define GPDGMUX2_GPIO112_InOutGPIO						0x00000000UL				// -		0b00
#define GPDGMUX2_GPIO112_OutEM2BA1						0x00000000UL				// 0b00		0b11
#endif

struct GPDCSEL1_BITS {                  // bits description
    Uint16 GPIO96:4;                    // 3:0 GPIO96 Master CPU Select
    Uint16 GPIO97:4;                    // 7:4 GPIO97 Master CPU Select
    Uint16 GPIO98:4;                    // 11:8 GPIO98 Master CPU Select
    Uint16 GPIO99:4;                    // 15:12 GPIO99 Master CPU Select
    Uint16 GPIO100:4;                   // 19:16 GPIO100 Master CPU Select
    Uint16 GPIO101:4;                   // 23:20 GPIO101 Master CPU Select
    Uint16 GPIO102:4;                   // 27:24 GPIO102 Master CPU Select
    Uint16 GPIO103:4;                   // 31:28 GPIO103 Master CPU Select
};

union GPDCSEL1_REG {
    Uint32  all;
    struct  GPDCSEL1_BITS  bit;
};

#ifdef CPU1
// GPDCSEL1 Register
//// GPDCSEL1 Register : Byte Value
#define GPDCSEL1_GPIO103_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO103_CPU1_CLA1Host					0x10000000UL
#define GPDCSEL1_GPIO103_CPU2Host						0x20000000UL
#define GPDCSEL1_GPIO103_CPU2_CLA1Host					0x30000000UL

#define GPDCSEL1_GPIO102_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO102_CPU1_CLA1Host					0x01000000UL
#define GPDCSEL1_GPIO102_CPU2Host						0x02000000UL
#define GPDCSEL1_GPIO102_CPU2_CLA1Host					0x03000000UL

#define GPDCSEL1_GPIO101_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO101_CPU1_CLA1Host					0x00100000UL
#define GPDCSEL1_GPIO101_CPU2Host						0x00200000UL
#define GPDCSEL1_GPIO101_CPU2_CLA1Host					0x00300000UL

#define GPDCSEL1_GPIO100_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO100_CPU1_CLA1Host					0x00010000UL
#define GPDCSEL1_GPIO100_CPU2Host						0x00020000UL
#define GPDCSEL1_GPIO100_CPU2_CLA1Host					0x00030000UL

#define GPDCSEL1_GPIO099_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO099_CPU1_CLA1Host					0x00001000UL
#define GPDCSEL1_GPIO099_CPU2Host						0x00002000UL
#define GPDCSEL1_GPIO099_CPU2_CLA1Host					0x00003000UL

#define GPDCSEL1_GPIO098_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO098_CPU1_CLA1Host					0x00000100UL
#define GPDCSEL1_GPIO098_CPU2Host						0x00000200UL
#define GPDCSEL1_GPIO098_CPU2_CLA1Host					0x00000300UL

#define GPDCSEL1_GPIO097_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO097_CPU1_CLA1Host					0x00000010UL
#define GPDCSEL1_GPIO097_CPU2Host						0x00000020UL
#define GPDCSEL1_GPIO097_CPU2_CLA1Host					0x00000030UL

#define GPDCSEL1_GPIO096_CPU1Host						0x00000000UL
#define GPDCSEL1_GPIO096_CPU1_CLA1Host					0x00000001UL
#define GPDCSEL1_GPIO096_CPU2Host						0x00000002UL
#define GPDCSEL1_GPIO096_CPU2_CLA1Host					0x00000003UL

//// GPDCSEL1 Register : Quick Value
#define GPDCSEL1_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPDCSEL2_BITS {                  // bits description
    Uint16 GPIO104:4;                   // 3:0 GPIO104 Master CPU Select
    Uint16 GPIO105:4;                   // 7:4 GPIO105 Master CPU Select
    Uint16 GPIO106:4;                   // 11:8 GPIO106 Master CPU Select
    Uint16 GPIO107:4;                   // 15:12 GPIO107 Master CPU Select
    Uint16 GPIO108:4;                   // 19:16 GPIO108 Master CPU Select
    Uint16 GPIO109:4;                   // 23:20 GPIO109 Master CPU Select
    Uint16 GPIO110:4;                   // 27:24 GPIO110 Master CPU Select
    Uint16 GPIO111:4;                   // 31:28 GPIO111 Master CPU Select
};

union GPDCSEL2_REG {
    Uint32  all;
    struct  GPDCSEL2_BITS  bit;
};

#ifdef CPU1
// GPDCSEL2 Register
//// GPDCSEL2 Register : Byte Value
#define GPDCSEL2_GPIO111_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO111_CPU1_CLA1Host					0x10000000UL
#define GPDCSEL2_GPIO111_CPU2Host						0x20000000UL
#define GPDCSEL2_GPIO111_CPU2_CLA1Host					0x30000000UL

#define GPDCSEL2_GPIO110_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO110_CPU1_CLA1Host					0x01000000UL
#define GPDCSEL2_GPIO110_CPU2Host						0x02000000UL
#define GPDCSEL2_GPIO110_CPU2_CLA1Host					0x03000000UL

#define GPDCSEL2_GPIO109_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO109_CPU1_CLA1Host					0x00100000UL
#define GPDCSEL2_GPIO109_CPU2Host						0x00200000UL
#define GPDCSEL2_GPIO109_CPU2_CLA1Host					0x00300000UL

#define GPDCSEL2_GPIO108_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO108_CPU1_CLA1Host					0x00010000UL
#define GPDCSEL2_GPIO108_CPU2Host						0x00020000UL
#define GPDCSEL2_GPIO108_CPU2_CLA1Host					0x00030000UL

#define GPDCSEL2_GPIO107_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO107_CPU1_CLA1Host					0x00001000UL
#define GPDCSEL2_GPIO107_CPU2Host						0x00002000UL
#define GPDCSEL2_GPIO107_CPU2_CLA1Host					0x00003000UL

#define GPDCSEL2_GPIO106_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO106_CPU1_CLA1Host					0x00000100UL
#define GPDCSEL2_GPIO106_CPU2Host						0x00000200UL
#define GPDCSEL2_GPIO106_CPU2_CLA1Host					0x00000300UL

#define GPDCSEL2_GPIO105_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO105_CPU1_CLA1Host					0x00000010UL
#define GPDCSEL2_GPIO105_CPU2Host						0x00000020UL
#define GPDCSEL2_GPIO105_CPU2_CLA1Host					0x00000030UL

#define GPDCSEL2_GPIO104_CPU1Host						0x00000000UL
#define GPDCSEL2_GPIO104_CPU1_CLA1Host					0x00000001UL
#define GPDCSEL2_GPIO104_CPU2Host						0x00000002UL
#define GPDCSEL2_GPIO104_CPU2_CLA1Host					0x00000003UL

//// GPDCSEL2 Register : Quick Value
#define GPDCSEL2_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPDCSEL3_BITS {                  // bits description
    Uint16 GPIO112:4;                   // 3:0 GPIO112 Master CPU Select
    Uint16 GPIO113:4;                   // 7:4 GPIO113 Master CPU Select
    Uint16 GPIO114:4;                   // 11:8 GPIO114 Master CPU Select
    Uint16 GPIO115:4;                   // 15:12 GPIO115 Master CPU Select
    Uint16 GPIO116:4;                   // 19:16 GPIO116 Master CPU Select
    Uint16 GPIO117:4;                   // 23:20 GPIO117 Master CPU Select
    Uint16 GPIO118:4;                   // 27:24 GPIO118 Master CPU Select
    Uint16 GPIO119:4;                   // 31:28 GPIO119 Master CPU Select
};

union GPDCSEL3_REG {
    Uint32  all;
    struct  GPDCSEL3_BITS  bit;
};

#ifdef CPU1
// GPDCSEL3 Register
//// GPDCSEL3 Register : Byte Value
#define GPDCSEL3_GPIO119_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO119_CPU1_CLA1Host					0x10000000UL
#define GPDCSEL3_GPIO119_CPU2Host						0x20000000UL
#define GPDCSEL3_GPIO119_CPU2_CLA1Host					0x30000000UL

#define GPDCSEL3_GPIO118_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO118_CPU1_CLA1Host					0x01000000UL
#define GPDCSEL3_GPIO118_CPU2Host						0x02000000UL
#define GPDCSEL3_GPIO118_CPU2_CLA1Host					0x03000000UL

#define GPDCSEL3_GPIO117_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO117_CPU1_CLA1Host					0x00100000UL
#define GPDCSEL3_GPIO117_CPU2Host						0x00200000UL
#define GPDCSEL3_GPIO117_CPU2_CLA1Host					0x00300000UL

#define GPDCSEL3_GPIO116_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO116_CPU1_CLA1Host					0x00010000UL
#define GPDCSEL3_GPIO116_CPU2Host						0x00020000UL
#define GPDCSEL3_GPIO116_CPU2_CLA1Host					0x00030000UL

#define GPDCSEL3_GPIO115_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO115_CPU1_CLA1Host					0x00001000UL
#define GPDCSEL3_GPIO115_CPU2Host						0x00002000UL
#define GPDCSEL3_GPIO115_CPU2_CLA1Host					0x00003000UL

#define GPDCSEL3_GPIO114_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO114_CPU1_CLA1Host					0x00000100UL
#define GPDCSEL3_GPIO114_CPU2Host						0x00000200UL
#define GPDCSEL3_GPIO114_CPU2_CLA1Host					0x00000300UL

#define GPDCSEL3_GPIO113_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO113_CPU1_CLA1Host					0x00000010UL
#define GPDCSEL3_GPIO113_CPU2Host						0x00000020UL
#define GPDCSEL3_GPIO113_CPU2_CLA1Host					0x00000030UL

#define GPDCSEL3_GPIO112_CPU1Host						0x00000000UL
#define GPDCSEL3_GPIO112_CPU1_CLA1Host					0x00000001UL
#define GPDCSEL3_GPIO112_CPU2Host						0x00000002UL
#define GPDCSEL3_GPIO112_CPU2_CLA1Host					0x00000003UL

//// GPDCSEL3 Register : Quick Value
#define GPDCSEL3_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPDCSEL4_BITS {                  // bits description
    Uint16 GPIO120:4;                   // 3:0 GPIO120 Master CPU Select
    Uint16 GPIO121:4;                   // 7:4 GPIO121 Master CPU Select
    Uint16 GPIO122:4;                   // 11:8 GPIO122 Master CPU Select
    Uint16 GPIO123:4;                   // 15:12 GPIO123 Master CPU Select
    Uint16 GPIO124:4;                   // 19:16 GPIO124 Master CPU Select
    Uint16 GPIO125:4;                   // 23:20 GPIO125 Master CPU Select
    Uint16 GPIO126:4;                   // 27:24 GPIO126 Master CPU Select
    Uint16 GPIO127:4;                   // 31:28 GPIO127 Master CPU Select
};

union GPDCSEL4_REG {
    Uint32  all;
    struct  GPDCSEL4_BITS  bit;
};

#ifdef CPU1
// GPDCSEL4 Register
//// GPDCSEL4 Register : Byte Value
#define GPDCSEL4_GPIO127_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO127_CPU1_CLA1Host					0x10000000UL
#define GPDCSEL4_GPIO127_CPU2Host						0x20000000UL
#define GPDCSEL4_GPIO127_CPU2_CLA1Host					0x30000000UL

#define GPDCSEL4_GPIO126_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO126_CPU1_CLA1Host					0x01000000UL
#define GPDCSEL4_GPIO126_CPU2Host						0x02000000UL
#define GPDCSEL4_GPIO126_CPU2_CLA1Host					0x03000000UL

#define GPDCSEL4_GPIO125_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO125_CPU1_CLA1Host					0x00100000UL
#define GPDCSEL4_GPIO125_CPU2Host						0x00200000UL
#define GPDCSEL4_GPIO125_CPU2_CLA1Host					0x00300000UL

#define GPDCSEL4_GPIO124_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO124_CPU1_CLA1Host					0x00010000UL
#define GPDCSEL4_GPIO124_CPU2Host						0x00020000UL
#define GPDCSEL4_GPIO124_CPU2_CLA1Host					0x00030000UL

#define GPDCSEL4_GPIO123_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO123_CPU1_CLA1Host					0x00001000UL
#define GPDCSEL4_GPIO123_CPU2Host						0x00002000UL
#define GPDCSEL4_GPIO123_CPU2_CLA1Host					0x00003000UL

#define GPDCSEL4_GPIO122_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO122_CPU1_CLA1Host					0x00000100UL
#define GPDCSEL4_GPIO122_CPU2Host						0x00000200UL
#define GPDCSEL4_GPIO122_CPU2_CLA1Host					0x00000300UL

#define GPDCSEL4_GPIO121_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO121_CPU1_CLA1Host					0x00000010UL
#define GPDCSEL4_GPIO121_CPU2Host						0x00000020UL
#define GPDCSEL4_GPIO121_CPU2_CLA1Host					0x00000030UL

#define GPDCSEL4_GPIO120_CPU1Host						0x00000000UL
#define GPDCSEL4_GPIO120_CPU1_CLA1Host					0x00000001UL
#define GPDCSEL4_GPIO120_CPU2Host						0x00000002UL
#define GPDCSEL4_GPIO120_CPU2_CLA1Host					0x00000003UL

//// GPDCSEL4 Register : Quick Value
#define GPDCSEL4_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPDLOCK_BITS {                   // bits description
    Uint16 GPIO96:1;                    // 0 Configuration Lock bit for this pin
    Uint16 GPIO97:1;                    // 1 Configuration Lock bit for this pin
    Uint16 GPIO98:1;                    // 2 Configuration Lock bit for this pin
    Uint16 GPIO99:1;                    // 3 Configuration Lock bit for this pin
    Uint16 GPIO100:1;                   // 4 Configuration Lock bit for this pin
    Uint16 GPIO101:1;                   // 5 Configuration Lock bit for this pin
    Uint16 GPIO102:1;                   // 6 Configuration Lock bit for this pin
    Uint16 GPIO103:1;                   // 7 Configuration Lock bit for this pin
    Uint16 GPIO104:1;                   // 8 Configuration Lock bit for this pin
    Uint16 GPIO105:1;                   // 9 Configuration Lock bit for this pin
    Uint16 GPIO106:1;                   // 10 Configuration Lock bit for this pin
    Uint16 GPIO107:1;                   // 11 Configuration Lock bit for this pin
    Uint16 GPIO108:1;                   // 12 Configuration Lock bit for this pin
    Uint16 GPIO109:1;                   // 13 Configuration Lock bit for this pin
    Uint16 GPIO110:1;                   // 14 Configuration Lock bit for this pin
    Uint16 GPIO111:1;                   // 15 Configuration Lock bit for this pin
    Uint16 GPIO112:1;                   // 16 Configuration Lock bit for this pin
    Uint16 GPIO113:1;                   // 17 Configuration Lock bit for this pin
    Uint16 GPIO114:1;                   // 18 Configuration Lock bit for this pin
    Uint16 GPIO115:1;                   // 19 Configuration Lock bit for this pin
    Uint16 GPIO116:1;                   // 20 Configuration Lock bit for this pin
    Uint16 GPIO117:1;                   // 21 Configuration Lock bit for this pin
    Uint16 GPIO118:1;                   // 22 Configuration Lock bit for this pin
    Uint16 GPIO119:1;                   // 23 Configuration Lock bit for this pin
    Uint16 GPIO120:1;                   // 24 Configuration Lock bit for this pin
    Uint16 GPIO121:1;                   // 25 Configuration Lock bit for this pin
    Uint16 GPIO122:1;                   // 26 Configuration Lock bit for this pin
    Uint16 GPIO123:1;                   // 27 Configuration Lock bit for this pin
    Uint16 GPIO124:1;                   // 28 Configuration Lock bit for this pin
    Uint16 GPIO125:1;                   // 29 Configuration Lock bit for this pin
    Uint16 GPIO126:1;                   // 30 Configuration Lock bit for this pin
    Uint16 GPIO127:1;                   // 31 Configuration Lock bit for this pin
};

union GPDLOCK_REG {
    Uint32  all;
    struct  GPDLOCK_BITS  bit;
};

struct GPDCR_BITS {                     // bits description
    Uint16 GPIO96:1;                    // 0 Configuration lock commit bit for this pin
    Uint16 GPIO97:1;                    // 1 Configuration lock commit bit for this pin
    Uint16 GPIO98:1;                    // 2 Configuration lock commit bit for this pin
    Uint16 GPIO99:1;                    // 3 Configuration lock commit bit for this pin
    Uint16 GPIO100:1;                   // 4 Configuration lock commit bit for this pin
    Uint16 GPIO101:1;                   // 5 Configuration lock commit bit for this pin
    Uint16 GPIO102:1;                   // 6 Configuration lock commit bit for this pin
    Uint16 GPIO103:1;                   // 7 Configuration lock commit bit for this pin
    Uint16 GPIO104:1;                   // 8 Configuration lock commit bit for this pin
    Uint16 GPIO105:1;                   // 9 Configuration lock commit bit for this pin
    Uint16 GPIO106:1;                   // 10 Configuration lock commit bit for this pin
    Uint16 GPIO107:1;                   // 11 Configuration lock commit bit for this pin
    Uint16 GPIO108:1;                   // 12 Configuration lock commit bit for this pin
    Uint16 GPIO109:1;                   // 13 Configuration lock commit bit for this pin
    Uint16 GPIO110:1;                   // 14 Configuration lock commit bit for this pin
    Uint16 GPIO111:1;                   // 15 Configuration lock commit bit for this pin
    Uint16 GPIO112:1;                   // 16 Configuration lock commit bit for this pin
    Uint16 GPIO113:1;                   // 17 Configuration lock commit bit for this pin
    Uint16 GPIO114:1;                   // 18 Configuration lock commit bit for this pin
    Uint16 GPIO115:1;                   // 19 Configuration lock commit bit for this pin
    Uint16 GPIO116:1;                   // 20 Configuration lock commit bit for this pin
    Uint16 GPIO117:1;                   // 21 Configuration lock commit bit for this pin
    Uint16 GPIO118:1;                   // 22 Configuration lock commit bit for this pin
    Uint16 GPIO119:1;                   // 23 Configuration lock commit bit for this pin
    Uint16 GPIO120:1;                   // 24 Configuration lock commit bit for this pin
    Uint16 GPIO121:1;                   // 25 Configuration lock commit bit for this pin
    Uint16 GPIO122:1;                   // 26 Configuration lock commit bit for this pin
    Uint16 GPIO123:1;                   // 27 Configuration lock commit bit for this pin
    Uint16 GPIO124:1;                   // 28 Configuration lock commit bit for this pin
    Uint16 GPIO125:1;                   // 29 Configuration lock commit bit for this pin
    Uint16 GPIO126:1;                   // 30 Configuration lock commit bit for this pin
    Uint16 GPIO127:1;                   // 31 Configuration lock commit bit for this pin
};

union GPDCR_REG {
    Uint32  all;
    struct  GPDCR_BITS  bit;
};

struct GPECTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO128 to GPIO135
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO136 to GPIO143
    Uint16 QUALPRD2:8;                  // 23:16 Qualification sampling period for GPIO144 to GPIO151
    Uint16 QUALPRD3:8;                  // 31:24 Qualification sampling period for GPIO152 to GPIO159
};

union GPECTRL_REG {
    Uint32  all;
    struct  GPECTRL_BITS  bit;
};

#ifdef CPU1
// GPECTRL Register
//// GPECTRL Register : Byte Value
#define GPECTRL_QUALPRD3_GPIO159to152_Value(val)		(((Uint32)val & 0x000000FFUL) << 24)
#define GPECTRL_QUALPRD2_GPIO151to144_Value(val)		(((Uint32)val & 0x000000FFUL) << 16)
#define GPECTRL_QUALPRD1_GPIO143to136_Value(val)		(((Uint32)val & 0x000000FFUL) << 8)
#define GPECTRL_QUALPRD0_GPIO135to128_Value(val)		((Uint32)val & 0x000000FFUL)
#endif

struct GPEQSEL1_BITS {                  // bits description
    Uint16 GPIO128:2;                   // 1:0 Select input qualification type for GPIO128
    Uint16 GPIO129:2;                   // 3:2 Select input qualification type for GPIO129
    Uint16 GPIO130:2;                   // 5:4 Select input qualification type for GPIO130
    Uint16 GPIO131:2;                   // 7:6 Select input qualification type for GPIO131
    Uint16 GPIO132:2;                   // 9:8 Select input qualification type for GPIO132
    Uint16 GPIO133:2;                   // 11:10 Select input qualification type for GPIO133
    Uint16 GPIO134:2;                   // 13:12 Select input qualification type for GPIO134
    Uint16 GPIO135:2;                   // 15:14 Select input qualification type for GPIO135
    Uint16 GPIO136:2;                   // 17:16 Select input qualification type for GPIO136
    Uint16 GPIO137:2;                   // 19:18 Select input qualification type for GPIO137
    Uint16 GPIO138:2;                   // 21:20 Select input qualification type for GPIO138
    Uint16 GPIO139:2;                   // 23:22 Select input qualification type for GPIO139
    Uint16 GPIO140:2;                   // 25:24 Select input qualification type for GPIO140
    Uint16 GPIO141:2;                   // 27:26 Select input qualification type for GPIO141
    Uint16 GPIO142:2;                   // 29:28 Select input qualification type for GPIO142
    Uint16 GPIO143:2;                   // 31:30 Select input qualification type for GPIO143
};

union GPEQSEL1_REG {
    Uint32  all;
    struct  GPEQSEL1_BITS  bit;
};

#ifdef CPU1
// GPEQSEL1 Register
//// GPEQSEL1 Register : Byte Value
#define GPEQSEL1_GPIO143_Synch							0x00000000UL
#define GPEQSEL1_GPIO143_3SampSynch						0x40000000UL
#define GPEQSEL1_GPIO143_6SampSynch						0x80000000UL
#define GPEQSEL1_GPIO143_Asynch							0xC0000000UL

#define GPEQSEL1_GPIO142_Synch							0x00000000UL
#define GPEQSEL1_GPIO142_3SampSynch						0x10000000UL
#define GPEQSEL1_GPIO142_6SampSynch						0x20000000UL
#define GPEQSEL1_GPIO142_Asynch							0x30000000UL

#define GPEQSEL1_GPIO141_Synch							0x00000000UL
#define GPEQSEL1_GPIO141_3SampSynch						0x04000000UL
#define GPEQSEL1_GPIO141_6SampSynch						0x08000000UL
#define GPEQSEL1_GPIO141_Asynch							0x0C000000UL

#define GPEQSEL1_GPIO140_Synch							0x00000000UL
#define GPEQSEL1_GPIO140_3SampSynch						0x01000000UL
#define GPEQSEL1_GPIO140_6SampSynch						0x02000000UL
#define GPEQSEL1_GPIO140_Asynch							0x03000000UL

#define GPEQSEL1_GPIO139_Synch							0x00000000UL
#define GPEQSEL1_GPIO139_3SampSynch						0x00400000UL
#define GPEQSEL1_GPIO139_6SampSynch						0x00800000UL
#define GPEQSEL1_GPIO139_Asynch							0x00C00000UL

#define GPEQSEL1_GPIO138_Synch							0x00000000UL
#define GPEQSEL1_GPIO138_3SampSynch						0x00100000UL
#define GPEQSEL1_GPIO138_6SampSynch						0x00200000UL
#define GPEQSEL1_GPIO138_Asynch							0x00300000UL

#define GPEQSEL1_GPIO137_Synch							0x00000000UL
#define GPEQSEL1_GPIO137_3SampSynch						0x00040000UL
#define GPEQSEL1_GPIO137_6SampSynch						0x00080000UL
#define GPEQSEL1_GPIO137_Asynch							0x000C0000UL

#define GPEQSEL1_GPIO136_Synch							0x00000000UL
#define GPEQSEL1_GPIO136_3SampSynch						0x00010000UL
#define GPEQSEL1_GPIO136_6SampSynch						0x00020000UL
#define GPEQSEL1_GPIO136_Asynch							0x00030000UL

#define GPEQSEL1_GPIO135_Synch							0x00000000UL
#define GPEQSEL1_GPIO135_3SampSynch						0x00004000UL
#define GPEQSEL1_GPIO135_6SampSynch						0x00008000UL
#define GPEQSEL1_GPIO135_Asynch							0x0000C000UL

#define GPEQSEL1_GPIO134_Synch							0x00000000UL
#define GPEQSEL1_GPIO134_3SampSynch						0x00001000UL
#define GPEQSEL1_GPIO134_6SampSynch						0x00002000UL
#define GPEQSEL1_GPIO134_Asynch							0x00003000UL

#define GPEQSEL1_GPIO133_Synch							0x00000000UL
#define GPEQSEL1_GPIO133_3SampSynch						0x00000400UL
#define GPEQSEL1_GPIO133_6SampSynch						0x00000800UL
#define GPEQSEL1_GPIO133_Asynch							0x00000C00UL

#define GPEQSEL1_GPIO132_Synch							0x00000000UL
#define GPEQSEL1_GPIO132_3SampSynch						0x00000100UL
#define GPEQSEL1_GPIO132_6SampSynch						0x00000200UL
#define GPEQSEL1_GPIO132_Asynch							0x00000300UL

#define GPEQSEL1_GPIO131_Synch							0x00000000UL
#define GPEQSEL1_GPIO131_3SampSynch						0x00000040UL
#define GPEQSEL1_GPIO131_6SampSynch						0x00000080UL
#define GPEQSEL1_GPIO131_Asynch							0x000000C0UL

#define GPEQSEL1_GPIO130_Synch							0x00000000UL
#define GPEQSEL1_GPIO130_3SampSynch						0x00000010UL
#define GPEQSEL1_GPIO130_6SampSynch						0x00000020UL
#define GPEQSEL1_GPIO130_Asynch							0x00000030UL

#define GPEQSEL1_GPIO129_Synch							0x00000000UL
#define GPEQSEL1_GPIO129_3SampSynch						0x00000004UL
#define GPEQSEL1_GPIO129_6SampSynch						0x00000008UL
#define GPEQSEL1_GPIO129_Asynch							0x0000000CUL

#define GPEQSEL1_GPIO128_Synch							0x00000000UL
#define GPEQSEL1_GPIO128_3SampSynch						0x00000001UL
#define GPEQSEL1_GPIO128_6SampSynch						0x00000002UL
#define GPEQSEL1_GPIO128_Asynch							0x00000003UL
#endif

struct GPEQSEL2_BITS {                  // bits description
    Uint16 GPIO144:2;                   // 1:0 Select input qualification type for GPIO144
    Uint16 GPIO145:2;                   // 3:2 Select input qualification type for GPIO145
    Uint16 GPIO146:2;                   // 5:4 Select input qualification type for GPIO146
    Uint16 GPIO147:2;                   // 7:6 Select input qualification type for GPIO147
    Uint16 GPIO148:2;                   // 9:8 Select input qualification type for GPIO148
    Uint16 GPIO149:2;                   // 11:10 Select input qualification type for GPIO149
    Uint16 GPIO150:2;                   // 13:12 Select input qualification type for GPIO150
    Uint16 GPIO151:2;                   // 15:14 Select input qualification type for GPIO151
    Uint16 GPIO152:2;                   // 17:16 Select input qualification type for GPIO152
    Uint16 GPIO153:2;                   // 19:18 Select input qualification type for GPIO153
    Uint16 GPIO154:2;                   // 21:20 Select input qualification type for GPIO154
    Uint16 GPIO155:2;                   // 23:22 Select input qualification type for GPIO155
    Uint16 GPIO156:2;                   // 25:24 Select input qualification type for GPIO156
    Uint16 GPIO157:2;                   // 27:26 Select input qualification type for GPIO157
    Uint16 GPIO158:2;                   // 29:28 Select input qualification type for GPIO158
    Uint16 GPIO159:2;                   // 31:30 Select input qualification type for GPIO159
};

union GPEQSEL2_REG {
    Uint32  all;
    struct  GPEQSEL2_BITS  bit;
};

#ifdef CPU1
// GPEQSEL2 Register
//// GPEQSEL2 Register : Byte Value
#define GPEQSEL2_GPIO159_Synch							0x00000000UL
#define GPEQSEL2_GPIO159_3SampSynch						0x40000000UL
#define GPEQSEL2_GPIO159_6SampSynch						0x80000000UL
#define GPEQSEL2_GPIO159_Asynch							0xC0000000UL

#define GPEQSEL2_GPIO158_Synch							0x00000000UL
#define GPEQSEL2_GPIO158_3SampSynch						0x10000000UL
#define GPEQSEL2_GPIO158_6SampSynch						0x20000000UL
#define GPEQSEL2_GPIO158_Asynch							0x30000000UL

#define GPEQSEL2_GPIO157_Synch							0x00000000UL
#define GPEQSEL2_GPIO157_3SampSynch						0x04000000UL
#define GPEQSEL2_GPIO157_6SampSynch						0x08000000UL
#define GPEQSEL2_GPIO157_Asynch							0x0C000000UL

#define GPEQSEL2_GPIO156_Synch							0x00000000UL
#define GPEQSEL2_GPIO156_3SampSynch						0x01000000UL
#define GPEQSEL2_GPIO156_6SampSynch						0x02000000UL
#define GPEQSEL2_GPIO156_Asynch							0x03000000UL

#define GPEQSEL2_GPIO155_Synch							0x00000000UL
#define GPEQSEL2_GPIO155_3SampSynch						0x00400000UL
#define GPEQSEL2_GPIO155_6SampSynch						0x00800000UL
#define GPEQSEL2_GPIO155_Asynch							0x00C00000UL

#define GPEQSEL2_GPIO154_Synch							0x00000000UL
#define GPEQSEL2_GPIO154_3SampSynch						0x00100000UL
#define GPEQSEL2_GPIO154_6SampSynch						0x00200000UL
#define GPEQSEL2_GPIO154_Asynch							0x00300000UL

#define GPEQSEL2_GPIO153_Synch							0x00000000UL
#define GPEQSEL2_GPIO153_3SampSynch						0x00040000UL
#define GPEQSEL2_GPIO153_6SampSynch						0x00080000UL
#define GPEQSEL2_GPIO153_Asynch							0x000C0000UL

#define GPEQSEL2_GPIO152_Synch							0x00000000UL
#define GPEQSEL2_GPIO152_3SampSynch						0x00010000UL
#define GPEQSEL2_GPIO152_6SampSynch						0x00020000UL
#define GPEQSEL2_GPIO152_Asynch							0x00030000UL

#define GPEQSEL2_GPIO151_Synch							0x00000000UL
#define GPEQSEL2_GPIO151_3SampSynch						0x00004000UL
#define GPEQSEL2_GPIO151_6SampSynch						0x00008000UL
#define GPEQSEL2_GPIO151_Asynch							0x0000C000UL

#define GPEQSEL2_GPIO150_Synch							0x00000000UL
#define GPEQSEL2_GPIO150_3SampSynch						0x00001000UL
#define GPEQSEL2_GPIO150_6SampSynch						0x00002000UL
#define GPEQSEL2_GPIO150_Asynch							0x00003000UL

#define GPEQSEL2_GPIO149_Synch							0x00000000UL
#define GPEQSEL2_GPIO149_3SampSynch						0x00000400UL
#define GPEQSEL2_GPIO149_6SampSynch						0x00000800UL
#define GPEQSEL2_GPIO149_Asynch							0x00000C00UL

#define GPEQSEL2_GPIO148_Synch							0x00000000UL
#define GPEQSEL2_GPIO148_3SampSynch						0x00000100UL
#define GPEQSEL2_GPIO148_6SampSynch						0x00000200UL
#define GPEQSEL2_GPIO148_Asynch							0x00000300UL

#define GPEQSEL2_GPIO147_Synch							0x00000000UL
#define GPEQSEL2_GPIO147_3SampSynch						0x00000040UL
#define GPEQSEL2_GPIO147_6SampSynch						0x00000080UL
#define GPEQSEL2_GPIO147_Asynch							0x000000C0UL

#define GPEQSEL2_GPIO146_Synch							0x00000000UL
#define GPEQSEL2_GPIO146_3SampSynch						0x00000010UL
#define GPEQSEL2_GPIO146_6SampSynch						0x00000020UL
#define GPEQSEL2_GPIO146_Asynch							0x00000030UL

#define GPEQSEL2_GPIO145_Synch							0x00000000UL
#define GPEQSEL2_GPIO145_3SampSynch						0x00000004UL
#define GPEQSEL2_GPIO145_6SampSynch						0x00000008UL
#define GPEQSEL2_GPIO145_Asynch							0x0000000CUL

#define GPEQSEL2_GPIO144_Synch							0x00000000UL
#define GPEQSEL2_GPIO144_3SampSynch						0x00000001UL
#define GPEQSEL2_GPIO144_6SampSynch						0x00000002UL
#define GPEQSEL2_GPIO144_Asynch							0x00000003UL
#endif

struct GPEMUX1_BITS {                   // bits description
    Uint16 GPIO128:2;                   // 1:0 Defines pin-muxing selection for GPIO128
    Uint16 GPIO129:2;                   // 3:2 Defines pin-muxing selection for GPIO129
    Uint16 GPIO130:2;                   // 5:4 Defines pin-muxing selection for GPIO130
    Uint16 GPIO131:2;                   // 7:6 Defines pin-muxing selection for GPIO131
    Uint16 GPIO132:2;                   // 9:8 Defines pin-muxing selection for GPIO132
    Uint16 GPIO133:2;                   // 11:10 Defines pin-muxing selection for GPIO133
    Uint16 GPIO134:2;                   // 13:12 Defines pin-muxing selection for GPIO134
    Uint16 GPIO135:2;                   // 15:14 Defines pin-muxing selection for GPIO135
    Uint16 GPIO136:2;                   // 17:16 Defines pin-muxing selection for GPIO136
    Uint16 GPIO137:2;                   // 19:18 Defines pin-muxing selection for GPIO137
    Uint16 GPIO138:2;                   // 21:20 Defines pin-muxing selection for GPIO138
    Uint16 GPIO139:2;                   // 23:22 Defines pin-muxing selection for GPIO139
    Uint16 GPIO140:2;                   // 25:24 Defines pin-muxing selection for GPIO140
    Uint16 GPIO141:2;                   // 27:26 Defines pin-muxing selection for GPIO141
    Uint16 GPIO142:2;                   // 29:28 Defines pin-muxing selection for GPIO142
    Uint16 GPIO143:2;                   // 31:30 Defines pin-muxing selection for GPIO143
};

union GPEMUX1_REG {
    Uint32  all;
    struct  GPEMUX1_BITS  bit;
};

#ifdef CPU1
// GPEMUX1 Register
//// GPEMUX1 Register : Byte Value													// GMUX		MUX
#define GPEMUX1_GPIO143_InOutGPIO						0x00000000UL				// -		0b00

#define GPEMUX1_GPIO142_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO142_OutSCIRXDD						0x20000000UL				// 0b01		0b10

#define GPEMUX1_GPIO141_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO141_InSCIRXDD						0x08000000UL				// 0b01		0b10

#define GPEMUX1_GPIO140_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO140_OutSCIRXDC						0x02000000UL				// 0b01		0b10

#define GPEMUX1_GPIO139_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO139_InSCIRXDC						0x00800000UL				// 0b01		0b10

#define GPEMUX1_GPIO138_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO138_InSCIRXDB						0x00200000UL				// 0b01		0b10

#define GPEMUX1_GPIO137_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO137_OutSCIRXDB						0x00080000UL				// 0b01		0b10
#define GPEMUX1_GPIO137_InSD1_C4						0x000C0000UL				// 0b01		0b11

#define GPEMUX1_GPIO136_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO136_InSCIRXDA						0x00020000UL				// 0b01		0b10
#define GPEMUX1_GPIO136_InSD1_D4						0x00030000UL				// 0b01		0b11

#define GPEMUX1_GPIO135_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO135_OutSCITXDA						0x00008000UL				// 0b01		0b10
#define GPEMUX1_GPIO135_InSD1_C3						0x0000C000UL				// 0b01		0b11

#define GPEMUX1_GPIO134_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO134_InSD1_D3						0x00003000UL				// 0b01		0b11

#define GPEMUX1_GPIO133_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO133_InSD1_C2						0x00000C00UL				// 0b01		0b11

#define GPEMUX1_GPIO132_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO132_InSD1_D2						0x00000300UL				// 0b01		0b11

#define GPEMUX1_GPIO131_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO131_InSD1_C1						0x000000C0UL				// 0b01		0b11

#define GPEMUX1_GPIO130_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO130_InSD1_D1						0x00000030UL				// 0b01		0b11

#define GPEMUX1_GPIO129_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO129_InSD1_C4						0x0000000CUL				// 0b01		0b11

#define GPEMUX1_GPIO128_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX1_GPIO128_InSD1_D4						0x00000003UL				// 0b01		0b11
#endif

struct GPEMUX2_BITS {                   // bits description
    Uint16 GPIO144:2;                   // 1:0 Defines pin-muxing selection for GPIO144
    Uint16 GPIO145:2;                   // 3:2 Defines pin-muxing selection for GPIO145
    Uint16 GPIO146:2;                   // 5:4 Defines pin-muxing selection for GPIO146
    Uint16 GPIO147:2;                   // 7:6 Defines pin-muxing selection for GPIO147
    Uint16 GPIO148:2;                   // 9:8 Defines pin-muxing selection for GPIO148
    Uint16 GPIO149:2;                   // 11:10 Defines pin-muxing selection for GPIO149
    Uint16 GPIO150:2;                   // 13:12 Defines pin-muxing selection for GPIO150
    Uint16 GPIO151:2;                   // 15:14 Defines pin-muxing selection for GPIO151
    Uint16 GPIO152:2;                   // 17:16 Defines pin-muxing selection for GPIO152
    Uint16 GPIO153:2;                   // 19:18 Defines pin-muxing selection for GPIO153
    Uint16 GPIO154:2;                   // 21:20 Defines pin-muxing selection for GPIO154
    Uint16 GPIO155:2;                   // 23:22 Defines pin-muxing selection for GPIO155
    Uint16 GPIO156:2;                   // 25:24 Defines pin-muxing selection for GPIO156
    Uint16 GPIO157:2;                   // 27:26 Defines pin-muxing selection for GPIO157
    Uint16 GPIO158:2;                   // 29:28 Defines pin-muxing selection for GPIO158
    Uint16 GPIO159:2;                   // 31:30 Defines pin-muxing selection for GPIO159
};

union GPEMUX2_REG {
    Uint32  all;
    struct  GPEMUX2_BITS  bit;
};

#ifdef CPU1
// GPEMUX2 Register
//// GPEMUX2 Register : Byte Value													// GMUX		MUX
#define GPEMUX2_GPIO159_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO159_OutEPWM8A						0x40000000UL				// 0b00		0b01

#define GPEMUX2_GPIO158_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO158_OutEPWM7B						0x10000000UL				// 0b00		0b01

#define GPEMUX2_GPIO157_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO157_OutEPWM7A						0x04000000UL				// 0b00		0b01

#define GPEMUX2_GPIO156_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO156_OutEPWM6B						0x01000000UL				// 0b00		0b01

#define GPEMUX2_GPIO155_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO155_OutEPWM6A						0x00400000UL				// 0b00		0b01

#define GPEMUX2_GPIO154_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO154_OutEPWM5B						0x00100000UL				// 0b00		0b01

#define GPEMUX2_GPIO153_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO153_OutEPWM5A						0x00040000UL				// 0b00		0b01

#define GPEMUX2_GPIO152_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO152_OutEPWM4B						0x00010000UL				// 0b00		0b01

#define GPEMUX2_GPIO151_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO151_OutEPWM4A						0x00004000UL				// 0b00		0b01

#define GPEMUX2_GPIO150_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO150_OutEPWM3B						0x00001000UL				// 0b00		0b01

#define GPEMUX2_GPIO149_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO149_OutEPWM3A						0x00000400UL				// 0b00		0b01

#define GPEMUX2_GPIO148_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO148_OutEPWM2B						0x00000100UL				// 0b00		0b01

#define GPEMUX2_GPIO147_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO147_OutEPWM2A						0x00000040UL				// 0b00		0b01

#define GPEMUX2_GPIO146_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO146_OutEPWM1B						0x00000010UL				// 0b00		0b01

#define GPEMUX2_GPIO145_InOutGPIO						0x00000000UL				// -		0b00
#define GPEMUX2_GPIO145_OutEPWM1A						0x00000004UL				// 0b00		0b01

#define GPEMUX2_GPIO144_InOutGPIO						0x00000000UL				// -		0b00
#endif

struct GPEDIR_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO129:1;                   // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO130:1;                   // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO131:1;                   // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO132:1;                   // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO133:1;                   // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO134:1;                   // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO135:1;                   // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO136:1;                   // 8 Defines direction for this pin in GPIO mode
    Uint16 GPIO137:1;                   // 9 Defines direction for this pin in GPIO mode
    Uint16 GPIO138:1;                   // 10 Defines direction for this pin in GPIO mode
    Uint16 GPIO139:1;                   // 11 Defines direction for this pin in GPIO mode
    Uint16 GPIO140:1;                   // 12 Defines direction for this pin in GPIO mode
    Uint16 GPIO141:1;                   // 13 Defines direction for this pin in GPIO mode
    Uint16 GPIO142:1;                   // 14 Defines direction for this pin in GPIO mode
    Uint16 GPIO143:1;                   // 15 Defines direction for this pin in GPIO mode
    Uint16 GPIO144:1;                   // 16 Defines direction for this pin in GPIO mode
    Uint16 GPIO145:1;                   // 17 Defines direction for this pin in GPIO mode
    Uint16 GPIO146:1;                   // 18 Defines direction for this pin in GPIO mode
    Uint16 GPIO147:1;                   // 19 Defines direction for this pin in GPIO mode
    Uint16 GPIO148:1;                   // 20 Defines direction for this pin in GPIO mode
    Uint16 GPIO149:1;                   // 21 Defines direction for this pin in GPIO mode
    Uint16 GPIO150:1;                   // 22 Defines direction for this pin in GPIO mode
    Uint16 GPIO151:1;                   // 23 Defines direction for this pin in GPIO mode
    Uint16 GPIO152:1;                   // 24 Defines direction for this pin in GPIO mode
    Uint16 GPIO153:1;                   // 25 Defines direction for this pin in GPIO mode
    Uint16 GPIO154:1;                   // 26 Defines direction for this pin in GPIO mode
    Uint16 GPIO155:1;                   // 27 Defines direction for this pin in GPIO mode
    Uint16 GPIO156:1;                   // 28 Defines direction for this pin in GPIO mode
    Uint16 GPIO157:1;                   // 29 Defines direction for this pin in GPIO mode
    Uint16 GPIO158:1;                   // 30 Defines direction for this pin in GPIO mode
    Uint16 GPIO159:1;                   // 31 Defines direction for this pin in GPIO mode
};

union GPEDIR_REG {
    Uint32  all;
    struct  GPEDIR_BITS  bit;
};

#ifdef CPU1
// GPEDIR Register
//// GPEDIR Register : Byte Value
#define GPEDIR_GPIO159_Input							0x00000000UL
#define GPEDIR_GPIO159_Output							0x80000000UL

#define GPEDIR_GPIO158_Input							0x00000000UL
#define GPEDIR_GPIO158_Output							0x40000000UL

#define GPEDIR_GPIO157_Input							0x00000000UL
#define GPEDIR_GPIO157_Output							0x20000000UL

#define GPEDIR_GPIO156_Input							0x00000000UL
#define GPEDIR_GPIO156_Output							0x10000000UL

#define GPEDIR_GPIO155_Input							0x00000000UL
#define GPEDIR_GPIO155_Output							0x08000000UL

#define GPEDIR_GPIO154_Input							0x00000000UL
#define GPEDIR_GPIO154_Output							0x04000000UL

#define GPEDIR_GPIO153_Input							0x00000000UL
#define GPEDIR_GPIO153_Output							0x02000000UL

#define GPEDIR_GPIO152_Input							0x00000000UL
#define GPEDIR_GPIO152_Output							0x01000000UL

#define GPEDIR_GPIO151_Input							0x00000000UL
#define GPEDIR_GPIO151_Output							0x00800000UL

#define GPEDIR_GPIO150_Input							0x00000000UL
#define GPEDIR_GPIO150_Output							0x00400000UL

#define GPEDIR_GPIO149_Input							0x00000000UL
#define GPEDIR_GPIO149_Output							0x00200000UL

#define GPEDIR_GPIO148_Input							0x00000000UL
#define GPEDIR_GPIO148_Output							0x00100000UL

#define GPEDIR_GPIO147_Input							0x00000000UL
#define GPEDIR_GPIO147_Output							0x00080000UL

#define GPEDIR_GPIO146_Input							0x00000000UL
#define GPEDIR_GPIO146_Output							0x00040000UL

#define GPEDIR_GPIO145_Input							0x00000000UL
#define GPEDIR_GPIO145_Output							0x00020000UL

#define GPEDIR_GPIO144_Input							0x00000000UL
#define GPEDIR_GPIO144_Output							0x00010000UL

#define GPEDIR_GPIO143_Input							0x00000000UL
#define GPEDIR_GPIO143_Output							0x00008000UL

#define GPEDIR_GPIO142_Input							0x00000000UL
#define GPEDIR_GPIO142_Output							0x00004000UL

#define GPEDIR_GPIO141_Input							0x00000000UL
#define GPEDIR_GPIO141_Output							0x00002000UL

#define GPEDIR_GPIO140_Input							0x00000000UL
#define GPEDIR_GPIO140_Output							0x00001000UL

#define GPEDIR_GPIO139_Input							0x00000000UL
#define GPEDIR_GPIO139_Output							0x00000800UL

#define GPEDIR_GPIO138_Input							0x00000000UL
#define GPEDIR_GPIO138_Output							0x00000400UL

#define GPEDIR_GPIO137_Input							0x00000000UL
#define GPEDIR_GPIO137_Output							0x00000200UL

#define GPEDIR_GPIO136_Input							0x00000000UL
#define GPEDIR_GPIO136_Output							0x00000100UL

#define GPEDIR_GPIO135_Input							0x00000000UL
#define GPEDIR_GPIO135_Output							0x00000080UL

#define GPEDIR_GPIO134_Input							0x00000000UL
#define GPEDIR_GPIO134_Output							0x00000040UL

#define GPEDIR_GPIO133_Input							0x00000000UL
#define GPEDIR_GPIO133_Output							0x00000020UL

#define GPEDIR_GPIO132_Input							0x00000000UL
#define GPEDIR_GPIO132_Output							0x00000010UL

#define GPEDIR_GPIO131_Input							0x00000000UL
#define GPEDIR_GPIO131_Output							0x00000008UL

#define GPEDIR_GPIO130_Input							0x00000000UL
#define GPEDIR_GPIO130_Output							0x00000004UL

#define GPEDIR_GPIO129_Input							0x00000000UL
#define GPEDIR_GPIO129_Output							0x00000002UL

#define GPEDIR_GPIO128_Input							0x00000000UL
#define GPEDIR_GPIO128_Output							0x00000001UL
#endif

struct GPEPUD_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Pull-Up Disable control for this pin
    Uint16 GPIO129:1;                   // 1 Pull-Up Disable control for this pin
    Uint16 GPIO130:1;                   // 2 Pull-Up Disable control for this pin
    Uint16 GPIO131:1;                   // 3 Pull-Up Disable control for this pin
    Uint16 GPIO132:1;                   // 4 Pull-Up Disable control for this pin
    Uint16 GPIO133:1;                   // 5 Pull-Up Disable control for this pin
    Uint16 GPIO134:1;                   // 6 Pull-Up Disable control for this pin
    Uint16 GPIO135:1;                   // 7 Pull-Up Disable control for this pin
    Uint16 GPIO136:1;                   // 8 Pull-Up Disable control for this pin
    Uint16 GPIO137:1;                   // 9 Pull-Up Disable control for this pin
    Uint16 GPIO138:1;                   // 10 Pull-Up Disable control for this pin
    Uint16 GPIO139:1;                   // 11 Pull-Up Disable control for this pin
    Uint16 GPIO140:1;                   // 12 Pull-Up Disable control for this pin
    Uint16 GPIO141:1;                   // 13 Pull-Up Disable control for this pin
    Uint16 GPIO142:1;                   // 14 Pull-Up Disable control for this pin
    Uint16 GPIO143:1;                   // 15 Pull-Up Disable control for this pin
    Uint16 GPIO144:1;                   // 16 Pull-Up Disable control for this pin
    Uint16 GPIO145:1;                   // 17 Pull-Up Disable control for this pin
    Uint16 GPIO146:1;                   // 18 Pull-Up Disable control for this pin
    Uint16 GPIO147:1;                   // 19 Pull-Up Disable control for this pin
    Uint16 GPIO148:1;                   // 20 Pull-Up Disable control for this pin
    Uint16 GPIO149:1;                   // 21 Pull-Up Disable control for this pin
    Uint16 GPIO150:1;                   // 22 Pull-Up Disable control for this pin
    Uint16 GPIO151:1;                   // 23 Pull-Up Disable control for this pin
    Uint16 GPIO152:1;                   // 24 Pull-Up Disable control for this pin
    Uint16 GPIO153:1;                   // 25 Pull-Up Disable control for this pin
    Uint16 GPIO154:1;                   // 26 Pull-Up Disable control for this pin
    Uint16 GPIO155:1;                   // 27 Pull-Up Disable control for this pin
    Uint16 GPIO156:1;                   // 28 Pull-Up Disable control for this pin
    Uint16 GPIO157:1;                   // 29 Pull-Up Disable control for this pin
    Uint16 GPIO158:1;                   // 30 Pull-Up Disable control for this pin
    Uint16 GPIO159:1;                   // 31 Pull-Up Disable control for this pin
};

union GPEPUD_REG {
    Uint32  all;
    struct  GPEPUD_BITS  bit;
};

#ifdef CPU1
// GPEPUD Register
//// GPEPUD Register : Byte Value
#define GPEPUD_GPIO159_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO159_PullUpDisable					0x80000000UL

#define GPEPUD_GPIO158_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO158_PullUpDisable					0x40000000UL

#define GPEPUD_GPIO157_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO157_PullUpDisable					0x20000000UL

#define GPEPUD_GPIO156_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO156_PullUpDisable					0x10000000UL

#define GPEPUD_GPIO155_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO155_PullUpDisable					0x08000000UL

#define GPEPUD_GPIO154_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO154_PullUpDisable					0x04000000UL

#define GPEPUD_GPIO153_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO153_PullUpDisable					0x02000000UL

#define GPEPUD_GPIO152_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO152_PullUpDisable					0x01000000UL

#define GPEPUD_GPIO151_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO151_PullUpDisable					0x00800000UL

#define GPEPUD_GPIO150_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO150_PullUpDisable					0x00400000UL

#define GPEPUD_GPIO149_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO149_PullUpDisable					0x00200000UL

#define GPEPUD_GPIO148_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO148_PullUpDisable					0x00100000UL

#define GPEPUD_GPIO147_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO147_PullUpDisable					0x00080000UL

#define GPEPUD_GPIO146_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO146_PullUpDisable					0x00040000UL

#define GPEPUD_GPIO145_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO145_PullUpDisable					0x00020000UL

#define GPEPUD_GPIO144_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO144_PullUpDisable					0x00010000UL

#define GPEPUD_GPIO143_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO143_PullUpDisable					0x00008000UL

#define GPEPUD_GPIO142_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO142_PullUpDisable					0x00004000UL

#define GPEPUD_GPIO141_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO141_PullUpDisable					0x00002000UL

#define GPEPUD_GPIO140_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO140_PullUpDisable					0x00001000UL

#define GPEPUD_GPIO139_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO139_PullUpDisable					0x00000800UL

#define GPEPUD_GPIO138_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO138_PullUpDisable					0x00000400UL

#define GPEPUD_GPIO137_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO137_PullUpDisable					0x00000200UL

#define GPEPUD_GPIO136_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO136_PullUpDisable					0x00000100UL

#define GPEPUD_GPIO135_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO135_PullUpDisable					0x00000080UL

#define GPEPUD_GPIO134_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO134_PullUpDisable					0x00000040UL

#define GPEPUD_GPIO133_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO133_PullUpDisable					0x00000020UL

#define GPEPUD_GPIO132_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO132_PullUpDisable					0x00000010UL

#define GPEPUD_GPIO131_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO131_PullUpDisable					0x00000008UL

#define GPEPUD_GPIO130_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO130_PullUpDisable					0x00000004UL

#define GPEPUD_GPIO129_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO129_PullUpDisable					0x00000002UL

#define GPEPUD_GPIO128_PullUpEnable						0x00000000UL
#define GPEPUD_GPIO128_PullUpDisable					0x00000001UL
#endif

struct GPEINV_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Input inversion control for this pin
    Uint16 GPIO129:1;                   // 1 Input inversion control for this pin
    Uint16 GPIO130:1;                   // 2 Input inversion control for this pin
    Uint16 GPIO131:1;                   // 3 Input inversion control for this pin
    Uint16 GPIO132:1;                   // 4 Input inversion control for this pin
    Uint16 GPIO133:1;                   // 5 Input inversion control for this pin
    Uint16 GPIO134:1;                   // 6 Input inversion control for this pin
    Uint16 GPIO135:1;                   // 7 Input inversion control for this pin
    Uint16 GPIO136:1;                   // 8 Input inversion control for this pin
    Uint16 GPIO137:1;                   // 9 Input inversion control for this pin
    Uint16 GPIO138:1;                   // 10 Input inversion control for this pin
    Uint16 GPIO139:1;                   // 11 Input inversion control for this pin
    Uint16 GPIO140:1;                   // 12 Input inversion control for this pin
    Uint16 GPIO141:1;                   // 13 Input inversion control for this pin
    Uint16 GPIO142:1;                   // 14 Input inversion control for this pin
    Uint16 GPIO143:1;                   // 15 Input inversion control for this pin
    Uint16 GPIO144:1;                   // 16 Input inversion control for this pin
    Uint16 GPIO145:1;                   // 17 Input inversion control for this pin
    Uint16 GPIO146:1;                   // 18 Input inversion control for this pin
    Uint16 GPIO147:1;                   // 19 Input inversion control for this pin
    Uint16 GPIO148:1;                   // 20 Input inversion control for this pin
    Uint16 GPIO149:1;                   // 21 Input inversion control for this pin
    Uint16 GPIO150:1;                   // 22 Input inversion control for this pin
    Uint16 GPIO151:1;                   // 23 Input inversion control for this pin
    Uint16 GPIO152:1;                   // 24 Input inversion control for this pin
    Uint16 GPIO153:1;                   // 25 Input inversion control for this pin
    Uint16 GPIO154:1;                   // 26 Input inversion control for this pin
    Uint16 GPIO155:1;                   // 27 Input inversion control for this pin
    Uint16 GPIO156:1;                   // 28 Input inversion control for this pin
    Uint16 GPIO157:1;                   // 29 Input inversion control for this pin
    Uint16 GPIO158:1;                   // 30 Input inversion control for this pin
    Uint16 GPIO159:1;                   // 31 Input inversion control for this pin
};

union GPEINV_REG {
    Uint32  all;
    struct  GPEINV_BITS  bit;
};

#ifdef CPU1
// GPEINV Register
//// GPEINV Register : Byte Value
#define GPEINV_GPIO159_InNormal							0x00000000UL
#define GPEINV_GPIO159_InInverted						0x80000000UL

#define GPEINV_GPIO158_InNormal							0x00000000UL
#define GPEINV_GPIO158_InInverted						0x40000000UL

#define GPEINV_GPIO157_InNormal							0x00000000UL
#define GPEINV_GPIO157_InInverted						0x20000000UL

#define GPEINV_GPIO156_InNormal							0x00000000UL
#define GPEINV_GPIO156_InInverted						0x10000000UL

#define GPEINV_GPIO155_InNormal							0x00000000UL
#define GPEINV_GPIO155_InInverted						0x08000000UL

#define GPEINV_GPIO154_InNormal							0x00000000UL
#define GPEINV_GPIO154_InInverted						0x04000000UL

#define GPEINV_GPIO153_InNormal							0x00000000UL
#define GPEINV_GPIO153_InInverted						0x02000000UL

#define GPEINV_GPIO152_InNormal							0x00000000UL
#define GPEINV_GPIO152_InInverted						0x01000000UL

#define GPEINV_GPIO151_InNormal							0x00000000UL
#define GPEINV_GPIO151_InInverted						0x00800000UL

#define GPEINV_GPIO150_InNormal							0x00000000UL
#define GPEINV_GPIO150_InInverted						0x00400000UL

#define GPEINV_GPIO149_InNormal							0x00000000UL
#define GPEINV_GPIO149_InInverted						0x00200000UL

#define GPEINV_GPIO148_InNormal							0x00000000UL
#define GPEINV_GPIO148_InInverted						0x00100000UL

#define GPEINV_GPIO147_InNormal							0x00000000UL
#define GPEINV_GPIO147_InInverted						0x00080000UL

#define GPEINV_GPIO146_InNormal							0x00000000UL
#define GPEINV_GPIO146_InInverted						0x00040000UL

#define GPEINV_GPIO145_InNormal							0x00000000UL
#define GPEINV_GPIO145_InInverted						0x00020000UL

#define GPEINV_GPIO144_InNormal							0x00000000UL
#define GPEINV_GPIO144_InInverted						0x00010000UL

#define GPEINV_GPIO143_InNormal							0x00000000UL
#define GPEINV_GPIO143_InInverted						0x00008000UL

#define GPEINV_GPIO142_InNormal							0x00000000UL
#define GPEINV_GPIO142_InInverted						0x00004000UL

#define GPEINV_GPIO141_InNormal							0x00000000UL
#define GPEINV_GPIO141_InInverted						0x00002000UL

#define GPEINV_GPIO140_InNormal							0x00000000UL
#define GPEINV_GPIO140_InInverted						0x00001000UL

#define GPEINV_GPIO139_InNormal							0x00000000UL
#define GPEINV_GPIO139_InInverted						0x00000800UL

#define GPEINV_GPIO138_InNormal							0x00000000UL
#define GPEINV_GPIO138_InInverted						0x00000400UL

#define GPEINV_GPIO137_InNormal							0x00000000UL
#define GPEINV_GPIO137_InInverted						0x00000200UL

#define GPEINV_GPIO136_InNormal							0x00000000UL
#define GPEINV_GPIO136_InInverted						0x00000100UL

#define GPEINV_GPIO135_InNormal							0x00000000UL
#define GPEINV_GPIO135_InInverted						0x00000080UL

#define GPEINV_GPIO134_InNormal							0x00000000UL
#define GPEINV_GPIO134_InInverted						0x00000040UL

#define GPEINV_GPIO133_InNormal							0x00000000UL
#define GPEINV_GPIO133_InInverted						0x00000020UL

#define GPEINV_GPIO132_InNormal							0x00000000UL
#define GPEINV_GPIO132_InInverted						0x00000010UL

#define GPEINV_GPIO131_InNormal							0x00000000UL
#define GPEINV_GPIO131_InInverted						0x00000008UL

#define GPEINV_GPIO130_InNormal							0x00000000UL
#define GPEINV_GPIO130_InInverted						0x00000004UL

#define GPEINV_GPIO129_InNormal							0x00000000UL
#define GPEINV_GPIO129_InInverted						0x00000002UL

#define GPEINV_GPIO128_InNormal							0x00000000UL
#define GPEINV_GPIO128_InInverted						0x00000001UL
#endif

struct GPEODR_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO129:1;                   // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO130:1;                   // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO131:1;                   // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO132:1;                   // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO133:1;                   // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO134:1;                   // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO135:1;                   // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO136:1;                   // 8 Outpout Open-Drain control for this pin
    Uint16 GPIO137:1;                   // 9 Outpout Open-Drain control for this pin
    Uint16 GPIO138:1;                   // 10 Outpout Open-Drain control for this pin
    Uint16 GPIO139:1;                   // 11 Outpout Open-Drain control for this pin
    Uint16 GPIO140:1;                   // 12 Outpout Open-Drain control for this pin
    Uint16 GPIO141:1;                   // 13 Outpout Open-Drain control for this pin
    Uint16 GPIO142:1;                   // 14 Outpout Open-Drain control for this pin
    Uint16 GPIO143:1;                   // 15 Outpout Open-Drain control for this pin
    Uint16 GPIO144:1;                   // 16 Outpout Open-Drain control for this pin
    Uint16 GPIO145:1;                   // 17 Outpout Open-Drain control for this pin
    Uint16 GPIO146:1;                   // 18 Outpout Open-Drain control for this pin
    Uint16 GPIO147:1;                   // 19 Outpout Open-Drain control for this pin
    Uint16 GPIO148:1;                   // 20 Outpout Open-Drain control for this pin
    Uint16 GPIO149:1;                   // 21 Outpout Open-Drain control for this pin
    Uint16 GPIO150:1;                   // 22 Outpout Open-Drain control for this pin
    Uint16 GPIO151:1;                   // 23 Outpout Open-Drain control for this pin
    Uint16 GPIO152:1;                   // 24 Outpout Open-Drain control for this pin
    Uint16 GPIO153:1;                   // 25 Outpout Open-Drain control for this pin
    Uint16 GPIO154:1;                   // 26 Outpout Open-Drain control for this pin
    Uint16 GPIO155:1;                   // 27 Outpout Open-Drain control for this pin
    Uint16 GPIO156:1;                   // 28 Outpout Open-Drain control for this pin
    Uint16 GPIO157:1;                   // 29 Outpout Open-Drain control for this pin
    Uint16 GPIO158:1;                   // 30 Outpout Open-Drain control for this pin
    Uint16 GPIO159:1;                   // 31 Outpout Open-Drain control for this pin
};

union GPEODR_REG {
    Uint32  all;
    struct  GPEODR_BITS  bit;
};

#ifdef CPU1
// GPEODR Register
//// GPEODR Register : Byte Value
#define GPEODR_GPIO159_Normal							0x00000000UL
#define GPEODR_GPIO159_OpenDrain						0x80000000UL

#define GPEODR_GPIO158_Normal							0x00000000UL
#define GPEODR_GPIO158_OpenDrain						0x40000000UL

#define GPEODR_GPIO157_Normal							0x00000000UL
#define GPEODR_GPIO157_OpenDrain						0x20000000UL

#define GPEODR_GPIO156_Normal							0x00000000UL
#define GPEODR_GPIO156_OpenDrain						0x10000000UL

#define GPEODR_GPIO155_Normal							0x00000000UL
#define GPEODR_GPIO155_OpenDrain						0x08000000UL

#define GPEODR_GPIO154_Normal							0x00000000UL
#define GPEODR_GPIO154_OpenDrain						0x04000000UL

#define GPEODR_GPIO153_Normal							0x00000000UL
#define GPEODR_GPIO153_OpenDrain						0x02000000UL

#define GPEODR_GPIO152_Normal							0x00000000UL
#define GPEODR_GPIO152_OpenDrain						0x01000000UL

#define GPEODR_GPIO151_Normal							0x00000000UL
#define GPEODR_GPIO151_OpenDrain						0x00800000UL

#define GPEODR_GPIO150_Normal							0x00000000UL
#define GPEODR_GPIO150_OpenDrain						0x00400000UL

#define GPEODR_GPIO149_Normal							0x00000000UL
#define GPEODR_GPIO149_OpenDrain						0x00200000UL

#define GPEODR_GPIO148_Normal							0x00000000UL
#define GPEODR_GPIO148_OpenDrain						0x00100000UL

#define GPEODR_GPIO147_Normal							0x00000000UL
#define GPEODR_GPIO147_OpenDrain						0x00080000UL

#define GPEODR_GPIO146_Normal							0x00000000UL
#define GPEODR_GPIO146_OpenDrain						0x00040000UL

#define GPEODR_GPIO145_Normal							0x00000000UL
#define GPEODR_GPIO145_OpenDrain						0x00020000UL

#define GPEODR_GPIO144_Normal							0x00000000UL
#define GPEODR_GPIO144_OpenDrain						0x00010000UL

#define GPEODR_GPIO143_Normal							0x00000000UL
#define GPEODR_GPIO143_OpenDrain						0x00008000UL

#define GPEODR_GPIO142_Normal							0x00000000UL
#define GPEODR_GPIO142_OpenDrain						0x00004000UL

#define GPEODR_GPIO141_Normal							0x00000000UL
#define GPEODR_GPIO141_OpenDrain						0x00002000UL

#define GPEODR_GPIO140_Normal							0x00000000UL
#define GPEODR_GPIO140_OpenDrain						0x00001000UL

#define GPEODR_GPIO139_Normal							0x00000000UL
#define GPEODR_GPIO139_OpenDrain						0x00000800UL

#define GPEODR_GPIO138_Normal							0x00000000UL
#define GPEODR_GPIO138_OpenDrain						0x00000400UL

#define GPEODR_GPIO137_Normal							0x00000000UL
#define GPEODR_GPIO137_OpenDrain						0x00000200UL

#define GPEODR_GPIO136_Normal							0x00000000UL
#define GPEODR_GPIO136_OpenDrain						0x00000100UL

#define GPEODR_GPIO135_Normal							0x00000000UL
#define GPEODR_GPIO135_OpenDrain						0x00000080UL

#define GPEODR_GPIO134_Normal							0x00000000UL
#define GPEODR_GPIO134_OpenDrain						0x00000040UL

#define GPEODR_GPIO133_Normal							0x00000000UL
#define GPEODR_GPIO133_OpenDrain						0x00000020UL

#define GPEODR_GPIO132_Normal							0x00000000UL
#define GPEODR_GPIO132_OpenDrain						0x00000010UL

#define GPEODR_GPIO131_Normal							0x00000000UL
#define GPEODR_GPIO131_OpenDrain						0x00000008UL

#define GPEODR_GPIO130_Normal							0x00000000UL
#define GPEODR_GPIO130_OpenDrain						0x00000004UL

#define GPEODR_GPIO129_Normal							0x00000000UL
#define GPEODR_GPIO129_OpenDrain						0x00000002UL

#define GPEODR_GPIO128_Normal							0x00000000UL
#define GPEODR_GPIO128_OpenDrain						0x00000001UL
#endif

struct GPEGMUX1_BITS {                  // bits description
    Uint16 GPIO128:2;                   // 1:0 Defines pin-muxing selection for GPIO128
    Uint16 GPIO129:2;                   // 3:2 Defines pin-muxing selection for GPIO129
    Uint16 GPIO130:2;                   // 5:4 Defines pin-muxing selection for GPIO130
    Uint16 GPIO131:2;                   // 7:6 Defines pin-muxing selection for GPIO131
    Uint16 GPIO132:2;                   // 9:8 Defines pin-muxing selection for GPIO132
    Uint16 GPIO133:2;                   // 11:10 Defines pin-muxing selection for GPIO133
    Uint16 GPIO134:2;                   // 13:12 Defines pin-muxing selection for GPIO134
    Uint16 GPIO135:2;                   // 15:14 Defines pin-muxing selection for GPIO135
    Uint16 GPIO136:2;                   // 17:16 Defines pin-muxing selection for GPIO136
    Uint16 GPIO137:2;                   // 19:18 Defines pin-muxing selection for GPIO137
    Uint16 GPIO138:2;                   // 21:20 Defines pin-muxing selection for GPIO138
    Uint16 GPIO139:2;                   // 23:22 Defines pin-muxing selection for GPIO139
    Uint16 GPIO140:2;                   // 25:24 Defines pin-muxing selection for GPIO140
    Uint16 GPIO141:2;                   // 27:26 Defines pin-muxing selection for GPIO141
    Uint16 GPIO142:2;                   // 29:28 Defines pin-muxing selection for GPIO142
    Uint16 GPIO143:2;                   // 31:30 Defines pin-muxing selection for GPIO143
};

union GPEGMUX1_REG {
    Uint32  all;
    struct  GPEGMUX1_BITS  bit;
};

#ifdef CPU1
// GPEGMUX1 Register
//// GPEGMUX1 Register : Byte Value													// GMUX		MUX
#define GPEGMUX1_GPIO143_InOutGPIO						0x00000000UL				// -		0b00

#define GPEGMUX1_GPIO142_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO142_OutSCIRXDD						0x10000000UL				// 0b01		0b10

#define GPEGMUX1_GPIO141_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO141_InSCIRXDD						0x04000000UL				// 0b01		0b10

#define GPEGMUX1_GPIO140_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO140_OutSCIRXDC						0x01000000UL				// 0b01		0b10

#define GPEGMUX1_GPIO139_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO139_InSCIRXDC						0x00400000UL				// 0b01		0b10

#define GPEGMUX1_GPIO138_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO138_InSCIRXDB						0x00100000UL				// 0b01		0b10

#define GPEGMUX1_GPIO137_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO137_OutSCIRXDB						0x00040000UL				// 0b01		0b10
#define GPEGMUX1_GPIO137_InSD1_C4						0x00040000UL				// 0b01		0b11

#define GPEGMUX1_GPIO136_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO136_InSCIRXDA						0x00010000UL				// 0b01		0b10
#define GPEGMUX1_GPIO136_InSD1_D4						0x00010000UL				// 0b01		0b11

#define GPEGMUX1_GPIO135_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO135_OutSCITXDA						0x00004000UL				// 0b01		0b10
#define GPEGMUX1_GPIO135_InSD1_C3						0x00004000UL				// 0b01		0b11

#define GPEGMUX1_GPIO134_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO134_InSD1_D3						0x00001000UL				// 0b01		0b11

#define GPEGMUX1_GPIO133_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO133_InSD1_C2						0x00000400UL				// 0b01		0b11

#define GPEGMUX1_GPIO132_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO132_InSD1_D2						0x00000100UL				// 0b01		0b11

#define GPEGMUX1_GPIO131_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO131_InSD1_C1						0x00000040UL				// 0b01		0b11

#define GPEGMUX1_GPIO130_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO130_InSD1_D1						0x00000010UL				// 0b01		0b11

#define GPEGMUX1_GPIO129_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO129_InSD1_C4						0x00000004UL				// 0b01		0b11

#define GPEGMUX1_GPIO128_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX1_GPIO128_InSD1_D4						0x00000001UL				// 0b01		0b11
#endif

struct GPEGMUX2_BITS {                  // bits description
    Uint16 GPIO144:2;                   // 1:0 Defines pin-muxing selection for GPIO144
    Uint16 GPIO145:2;                   // 3:2 Defines pin-muxing selection for GPIO145
    Uint16 GPIO146:2;                   // 5:4 Defines pin-muxing selection for GPIO146
    Uint16 GPIO147:2;                   // 7:6 Defines pin-muxing selection for GPIO147
    Uint16 GPIO148:2;                   // 9:8 Defines pin-muxing selection for GPIO148
    Uint16 GPIO149:2;                   // 11:10 Defines pin-muxing selection for GPIO149
    Uint16 GPIO150:2;                   // 13:12 Defines pin-muxing selection for GPIO150
    Uint16 GPIO151:2;                   // 15:14 Defines pin-muxing selection for GPIO151
    Uint16 GPIO152:2;                   // 17:16 Defines pin-muxing selection for GPIO152
    Uint16 GPIO153:2;                   // 19:18 Defines pin-muxing selection for GPIO153
    Uint16 GPIO154:2;                   // 21:20 Defines pin-muxing selection for GPIO154
    Uint16 GPIO155:2;                   // 23:22 Defines pin-muxing selection for GPIO155
    Uint16 GPIO156:2;                   // 25:24 Defines pin-muxing selection for GPIO156
    Uint16 GPIO157:2;                   // 27:26 Defines pin-muxing selection for GPIO157
    Uint16 GPIO158:2;                   // 29:28 Defines pin-muxing selection for GPIO158
    Uint16 GPIO159:2;                   // 31:30 Defines pin-muxing selection for GPIO159
};

union GPEGMUX2_REG {
    Uint32  all;
    struct  GPEGMUX2_BITS  bit;
};

#ifdef CPU1
// GPEGMUX2 Register
//// GPEGMUX2 Register : Byte Value													// GMUX		MUX
#define GPEGMUX2_GPIO159_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO159_OutEPWM8A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO158_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO158_OutEPWM7B						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO157_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO157_OutEPWM7A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO156_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO156_OutEPWM6B						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO155_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO155_OutEPWM6A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO154_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO154_OutEPWM5B						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO153_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO153_OutEPWM5A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO152_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO152_OutEPWM4B						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO151_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO151_OutEPWM4A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO150_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO150_OutEPWM3B						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO149_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO149_OutEPWM3A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO148_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO148_OutEPWM2B						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO147_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO147_OutEPWM2A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO146_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO146_OutEPWM1B						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO145_InOutGPIO						0x00000000UL				// -		0b00
#define GPEGMUX2_GPIO145_OutEPWM1A						0x00000000UL				// 0b00		0b01

#define GPEGMUX2_GPIO144_InOutGPIO						0x00000000UL				// -		0b00
#endif

struct GPECSEL1_BITS {                  // bits description
    Uint16 GPIO128:4;                   // 3:0 GPIO128 Master CPU Select
    Uint16 GPIO129:4;                   // 7:4 GPIO129 Master CPU Select
    Uint16 GPIO130:4;                   // 11:8 GPIO130 Master CPU Select
    Uint16 GPIO131:4;                   // 15:12 GPIO131 Master CPU Select
    Uint16 GPIO132:4;                   // 19:16 GPIO132 Master CPU Select
    Uint16 GPIO133:4;                   // 23:20 GPIO133 Master CPU Select
    Uint16 GPIO134:4;                   // 27:24 GPIO134 Master CPU Select
    Uint16 GPIO135:4;                   // 31:28 GPIO135 Master CPU Select
};

union GPECSEL1_REG {
    Uint32  all;
    struct  GPECSEL1_BITS  bit;
};

#ifdef CPU1
// GPECSEL1 Register
//// GPECSEL1 Register : Byte Value
#define GPECSEL1_GPIO135_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO135_CPU1_CLA1Host					0x10000000UL
#define GPECSEL1_GPIO135_CPU2Host						0x20000000UL
#define GPECSEL1_GPIO135_CPU2_CLA1Host					0x30000000UL

#define GPECSEL1_GPIO134_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO134_CPU1_CLA1Host					0x01000000UL
#define GPECSEL1_GPIO134_CPU2Host						0x02000000UL
#define GPECSEL1_GPIO134_CPU2_CLA1Host					0x03000000UL

#define GPECSEL1_GPIO133_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO133_CPU1_CLA1Host					0x00100000UL
#define GPECSEL1_GPIO133_CPU2Host						0x00200000UL
#define GPECSEL1_GPIO133_CPU2_CLA1Host					0x00300000UL

#define GPECSEL1_GPIO132_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO132_CPU1_CLA1Host					0x00010000UL
#define GPECSEL1_GPIO132_CPU2Host						0x00020000UL
#define GPECSEL1_GPIO132_CPU2_CLA1Host					0x00030000UL

#define GPECSEL1_GPIO131_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO131_CPU1_CLA1Host					0x00001000UL
#define GPECSEL1_GPIO131_CPU2Host						0x00002000UL
#define GPECSEL1_GPIO131_CPU2_CLA1Host					0x00003000UL

#define GPECSEL1_GPIO130_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO130_CPU1_CLA1Host					0x00000100UL
#define GPECSEL1_GPIO130_CPU2Host						0x00000200UL
#define GPECSEL1_GPIO130_CPU2_CLA1Host					0x00000300UL

#define GPECSEL1_GPIO129_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO129_CPU1_CLA1Host					0x00000010UL
#define GPECSEL1_GPIO129_CPU2Host						0x00000020UL
#define GPECSEL1_GPIO129_CPU2_CLA1Host					0x00000030UL

#define GPECSEL1_GPIO128_CPU1Host						0x00000000UL
#define GPECSEL1_GPIO128_CPU1_CLA1Host					0x00000001UL
#define GPECSEL1_GPIO128_CPU2Host						0x00000002UL
#define GPECSEL1_GPIO128_CPU2_CLA1Host					0x00000003UL

//// GPECSEL1 Register : Byte Value
#define GPECSEL1_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPECSEL2_BITS {                  // bits description
    Uint16 GPIO136:4;                   // 3:0 GPIO136 Master CPU Select
    Uint16 GPIO137:4;                   // 7:4 GPIO137 Master CPU Select
    Uint16 GPIO138:4;                   // 11:8 GPIO138 Master CPU Select
    Uint16 GPIO139:4;                   // 15:12 GPIO139 Master CPU Select
    Uint16 GPIO140:4;                   // 19:16 GPIO140 Master CPU Select
    Uint16 GPIO141:4;                   // 23:20 GPIO141 Master CPU Select
    Uint16 GPIO142:4;                   // 27:24 GPIO142 Master CPU Select
    Uint16 GPIO143:4;                   // 31:28 GPIO143 Master CPU Select
};

union GPECSEL2_REG {
    Uint32  all;
    struct  GPECSEL2_BITS  bit;
};

#ifdef CPU1
// GPECSEL2 Register
//// GPECSEL2 Register : Byte Value
#define GPECSEL2_GPIO143_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO143_CPU1_CLA1Host					0x10000000UL
#define GPECSEL2_GPIO143_CPU2Host						0x20000000UL
#define GPECSEL2_GPIO143_CPU2_CLA1Host					0x30000000UL

#define GPECSEL2_GPIO142_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO142_CPU1_CLA1Host					0x01000000UL
#define GPECSEL2_GPIO142_CPU2Host						0x02000000UL
#define GPECSEL2_GPIO142_CPU2_CLA1Host					0x03000000UL

#define GPECSEL2_GPIO141_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO141_CPU1_CLA1Host					0x00100000UL
#define GPECSEL2_GPIO141_CPU2Host						0x00200000UL
#define GPECSEL2_GPIO141_CPU2_CLA1Host					0x00300000UL

#define GPECSEL2_GPIO140_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO140_CPU1_CLA1Host					0x00010000UL
#define GPECSEL2_GPIO140_CPU2Host						0x00020000UL
#define GPECSEL2_GPIO140_CPU2_CLA1Host					0x00030000UL

#define GPECSEL2_GPIO139_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO139_CPU1_CLA1Host					0x00001000UL
#define GPECSEL2_GPIO139_CPU2Host						0x00002000UL
#define GPECSEL2_GPIO139_CPU2_CLA1Host					0x00003000UL

#define GPECSEL2_GPIO138_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO138_CPU1_CLA1Host					0x00000100UL
#define GPECSEL2_GPIO138_CPU2Host						0x00000200UL
#define GPECSEL2_GPIO138_CPU2_CLA1Host					0x00000300UL

#define GPECSEL2_GPIO137_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO137_CPU1_CLA1Host					0x00000010UL
#define GPECSEL2_GPIO137_CPU2Host						0x00000020UL
#define GPECSEL2_GPIO137_CPU2_CLA1Host					0x00000030UL

#define GPECSEL2_GPIO136_CPU1Host						0x00000000UL
#define GPECSEL2_GPIO136_CPU1_CLA1Host					0x00000001UL
#define GPECSEL2_GPIO136_CPU2Host						0x00000002UL
#define GPECSEL2_GPIO136_CPU2_CLA1Host					0x00000003UL

//// GPECSEL2 Register : Byte Value
#define GPECSEL2_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPECSEL3_BITS {                  // bits description
    Uint16 GPIO144:4;                   // 3:0 GPIO144 Master CPU Select
    Uint16 GPIO145:4;                   // 7:4 GPIO145 Master CPU Select
    Uint16 GPIO146:4;                   // 11:8 GPIO146 Master CPU Select
    Uint16 GPIO147:4;                   // 15:12 GPIO147 Master CPU Select
    Uint16 GPIO148:4;                   // 19:16 GPIO148 Master CPU Select
    Uint16 GPIO149:4;                   // 23:20 GPIO149 Master CPU Select
    Uint16 GPIO150:4;                   // 27:24 GPIO150 Master CPU Select
    Uint16 GPIO151:4;                   // 31:28 GPIO151 Master CPU Select
};

union GPECSEL3_REG {
    Uint32  all;
    struct  GPECSEL3_BITS  bit;
};

#ifdef CPU1
// GPECSEL3 Register
//// GPECSEL3 Register : Byte Value
#define GPECSEL3_GPIO151_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO151_CPU1_CLA1Host					0x10000000UL
#define GPECSEL3_GPIO151_CPU2Host						0x20000000UL
#define GPECSEL3_GPIO151_CPU2_CLA1Host					0x30000000UL

#define GPECSEL3_GPIO150_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO150_CPU1_CLA1Host					0x01000000UL
#define GPECSEL3_GPIO150_CPU2Host						0x02000000UL
#define GPECSEL3_GPIO150_CPU2_CLA1Host					0x03000000UL

#define GPECSEL3_GPIO149_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO149_CPU1_CLA1Host					0x00100000UL
#define GPECSEL3_GPIO149_CPU2Host						0x00200000UL
#define GPECSEL3_GPIO149_CPU2_CLA1Host					0x00300000UL

#define GPECSEL3_GPIO148_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO148_CPU1_CLA1Host					0x00010000UL
#define GPECSEL3_GPIO148_CPU2Host						0x00020000UL
#define GPECSEL3_GPIO148_CPU2_CLA1Host					0x00030000UL

#define GPECSEL3_GPIO147_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO147_CPU1_CLA1Host					0x00001000UL
#define GPECSEL3_GPIO147_CPU2Host						0x00002000UL
#define GPECSEL3_GPIO147_CPU2_CLA1Host					0x00003000UL

#define GPECSEL3_GPIO146_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO146_CPU1_CLA1Host					0x00000100UL
#define GPECSEL3_GPIO146_CPU2Host						0x00000200UL
#define GPECSEL3_GPIO146_CPU2_CLA1Host					0x00000300UL

#define GPECSEL3_GPIO145_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO145_CPU1_CLA1Host					0x00000010UL
#define GPECSEL3_GPIO145_CPU2Host						0x00000020UL
#define GPECSEL3_GPIO145_CPU2_CLA1Host					0x00000030UL

#define GPECSEL3_GPIO144_CPU1Host						0x00000000UL
#define GPECSEL3_GPIO144_CPU1_CLA1Host					0x00000001UL
#define GPECSEL3_GPIO144_CPU2Host						0x00000002UL
#define GPECSEL3_GPIO144_CPU2_CLA1Host					0x00000003UL

//// GPECSEL3 Register : Byte Value
#define GPECSEL3_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPECSEL4_BITS {                  // bits description
    Uint16 GPIO152:4;                   // 3:0 GPIO152 Master CPU Select
    Uint16 GPIO153:4;                   // 7:4 GPIO153 Master CPU Select
    Uint16 GPIO154:4;                   // 11:8 GPIO154 Master CPU Select
    Uint16 GPIO155:4;                   // 15:12 GPIO155 Master CPU Select
    Uint16 GPIO156:4;                   // 19:16 GPIO156 Master CPU Select
    Uint16 GPIO157:4;                   // 23:20 GPIO157 Master CPU Select
    Uint16 GPIO158:4;                   // 27:24 GPIO158 Master CPU Select
    Uint16 GPIO159:4;                   // 31:28 GPIO159 Master CPU Select
};

union GPECSEL4_REG {
    Uint32  all;
    struct  GPECSEL4_BITS  bit;
};

#ifdef CPU1
// GPECSEL4 Register
//// GPECSEL4 Register : Byte Value
#define GPECSEL4_GPIO159_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO159_CPU1_CLA1Host					0x10000000UL
#define GPECSEL4_GPIO159_CPU2Host						0x20000000UL
#define GPECSEL4_GPIO159_CPU2_CLA1Host					0x30000000UL

#define GPECSEL4_GPIO158_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO158_CPU1_CLA1Host					0x01000000UL
#define GPECSEL4_GPIO158_CPU2Host						0x02000000UL
#define GPECSEL4_GPIO158_CPU2_CLA1Host					0x03000000UL

#define GPECSEL4_GPIO157_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO157_CPU1_CLA1Host					0x00100000UL
#define GPECSEL4_GPIO157_CPU2Host						0x00200000UL
#define GPECSEL4_GPIO157_CPU2_CLA1Host					0x00300000UL

#define GPECSEL4_GPIO156_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO156_CPU1_CLA1Host					0x00010000UL
#define GPECSEL4_GPIO156_CPU2Host						0x00020000UL
#define GPECSEL4_GPIO156_CPU2_CLA1Host					0x00030000UL

#define GPECSEL4_GPIO155_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO155_CPU1_CLA1Host					0x00001000UL
#define GPECSEL4_GPIO155_CPU2Host						0x00002000UL
#define GPECSEL4_GPIO155_CPU2_CLA1Host					0x00003000UL

#define GPECSEL4_GPIO154_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO154_CPU1_CLA1Host					0x00000100UL
#define GPECSEL4_GPIO154_CPU2Host						0x00000200UL
#define GPECSEL4_GPIO154_CPU2_CLA1Host					0x00000300UL

#define GPECSEL4_GPIO153_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO153_CPU1_CLA1Host					0x00000010UL
#define GPECSEL4_GPIO153_CPU2Host						0x00000020UL
#define GPECSEL4_GPIO153_CPU2_CLA1Host					0x00000030UL

#define GPECSEL4_GPIO152_CPU1Host						0x00000000UL
#define GPECSEL4_GPIO152_CPU1_CLA1Host					0x00000001UL
#define GPECSEL4_GPIO152_CPU2Host						0x00000002UL
#define GPECSEL4_GPIO152_CPU2_CLA1Host					0x00000003UL

//// GPECSEL4 Register : Byte Value
#define GPECSEL4_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPELOCK_BITS {                   // bits description
    Uint16 GPIO128:1;                   // 0 Configuration Lock bit for this pin
    Uint16 GPIO129:1;                   // 1 Configuration Lock bit for this pin
    Uint16 GPIO130:1;                   // 2 Configuration Lock bit for this pin
    Uint16 GPIO131:1;                   // 3 Configuration Lock bit for this pin
    Uint16 GPIO132:1;                   // 4 Configuration Lock bit for this pin
    Uint16 GPIO133:1;                   // 5 Configuration Lock bit for this pin
    Uint16 GPIO134:1;                   // 6 Configuration Lock bit for this pin
    Uint16 GPIO135:1;                   // 7 Configuration Lock bit for this pin
    Uint16 GPIO136:1;                   // 8 Configuration Lock bit for this pin
    Uint16 GPIO137:1;                   // 9 Configuration Lock bit for this pin
    Uint16 GPIO138:1;                   // 10 Configuration Lock bit for this pin
    Uint16 GPIO139:1;                   // 11 Configuration Lock bit for this pin
    Uint16 GPIO140:1;                   // 12 Configuration Lock bit for this pin
    Uint16 GPIO141:1;                   // 13 Configuration Lock bit for this pin
    Uint16 GPIO142:1;                   // 14 Configuration Lock bit for this pin
    Uint16 GPIO143:1;                   // 15 Configuration Lock bit for this pin
    Uint16 GPIO144:1;                   // 16 Configuration Lock bit for this pin
    Uint16 GPIO145:1;                   // 17 Configuration Lock bit for this pin
    Uint16 GPIO146:1;                   // 18 Configuration Lock bit for this pin
    Uint16 GPIO147:1;                   // 19 Configuration Lock bit for this pin
    Uint16 GPIO148:1;                   // 20 Configuration Lock bit for this pin
    Uint16 GPIO149:1;                   // 21 Configuration Lock bit for this pin
    Uint16 GPIO150:1;                   // 22 Configuration Lock bit for this pin
    Uint16 GPIO151:1;                   // 23 Configuration Lock bit for this pin
    Uint16 GPIO152:1;                   // 24 Configuration Lock bit for this pin
    Uint16 GPIO153:1;                   // 25 Configuration Lock bit for this pin
    Uint16 GPIO154:1;                   // 26 Configuration Lock bit for this pin
    Uint16 GPIO155:1;                   // 27 Configuration Lock bit for this pin
    Uint16 GPIO156:1;                   // 28 Configuration Lock bit for this pin
    Uint16 GPIO157:1;                   // 29 Configuration Lock bit for this pin
    Uint16 GPIO158:1;                   // 30 Configuration Lock bit for this pin
    Uint16 GPIO159:1;                   // 31 Configuration Lock bit for this pin
};

union GPELOCK_REG {
    Uint32  all;
    struct  GPELOCK_BITS  bit;
};

struct GPECR_BITS {                     // bits description
    Uint16 GPIO128:1;                   // 0 Configuration lock commit bit for this pin
    Uint16 GPIO129:1;                   // 1 Configuration lock commit bit for this pin
    Uint16 GPIO130:1;                   // 2 Configuration lock commit bit for this pin
    Uint16 GPIO131:1;                   // 3 Configuration lock commit bit for this pin
    Uint16 GPIO132:1;                   // 4 Configuration lock commit bit for this pin
    Uint16 GPIO133:1;                   // 5 Configuration lock commit bit for this pin
    Uint16 GPIO134:1;                   // 6 Configuration lock commit bit for this pin
    Uint16 GPIO135:1;                   // 7 Configuration lock commit bit for this pin
    Uint16 GPIO136:1;                   // 8 Configuration lock commit bit for this pin
    Uint16 GPIO137:1;                   // 9 Configuration lock commit bit for this pin
    Uint16 GPIO138:1;                   // 10 Configuration lock commit bit for this pin
    Uint16 GPIO139:1;                   // 11 Configuration lock commit bit for this pin
    Uint16 GPIO140:1;                   // 12 Configuration lock commit bit for this pin
    Uint16 GPIO141:1;                   // 13 Configuration lock commit bit for this pin
    Uint16 GPIO142:1;                   // 14 Configuration lock commit bit for this pin
    Uint16 GPIO143:1;                   // 15 Configuration lock commit bit for this pin
    Uint16 GPIO144:1;                   // 16 Configuration lock commit bit for this pin
    Uint16 GPIO145:1;                   // 17 Configuration lock commit bit for this pin
    Uint16 GPIO146:1;                   // 18 Configuration lock commit bit for this pin
    Uint16 GPIO147:1;                   // 19 Configuration lock commit bit for this pin
    Uint16 GPIO148:1;                   // 20 Configuration lock commit bit for this pin
    Uint16 GPIO149:1;                   // 21 Configuration lock commit bit for this pin
    Uint16 GPIO150:1;                   // 22 Configuration lock commit bit for this pin
    Uint16 GPIO151:1;                   // 23 Configuration lock commit bit for this pin
    Uint16 GPIO152:1;                   // 24 Configuration lock commit bit for this pin
    Uint16 GPIO153:1;                   // 25 Configuration lock commit bit for this pin
    Uint16 GPIO154:1;                   // 26 Configuration lock commit bit for this pin
    Uint16 GPIO155:1;                   // 27 Configuration lock commit bit for this pin
    Uint16 GPIO156:1;                   // 28 Configuration lock commit bit for this pin
    Uint16 GPIO157:1;                   // 29 Configuration lock commit bit for this pin
    Uint16 GPIO158:1;                   // 30 Configuration lock commit bit for this pin
    Uint16 GPIO159:1;                   // 31 Configuration lock commit bit for this pin
};

union GPECR_REG {
    Uint32  all;
    struct  GPECR_BITS  bit;
};

struct GPFCTRL_BITS {                   // bits description
    Uint16 QUALPRD0:8;                  // 7:0 Qualification sampling period for GPIO160 to GPIO167
    Uint16 QUALPRD1:8;                  // 15:8 Qualification sampling period for GPIO168
    Uint16 rsvd1:8;                     // 23:16 Reserved
    Uint16 rsvd2:8;                     // 31:24 Reserved
};

union GPFCTRL_REG {
    Uint32  all;
    struct  GPFCTRL_BITS  bit;
};

#ifdef CPU1
// GPFCTRL Register
//// GPFCTRL Register : Byte Value
#define GPFCTRL_QUALPRD1_GPIO168(val)					(((Uint32)val & 0x000000FFUL) << 8)
#define GPFCTRL_QUALPRD0_GPIO167to160_Value(val)		((Uint32)val & 0x000000FFUL)
#endif

struct GPFQSEL1_BITS {                  // bits description
    Uint16 GPIO160:2;                   // 1:0 Select input qualification type for GPIO160
    Uint16 GPIO161:2;                   // 3:2 Select input qualification type for GPIO161
    Uint16 GPIO162:2;                   // 5:4 Select input qualification type for GPIO162
    Uint16 GPIO163:2;                   // 7:6 Select input qualification type for GPIO163
    Uint16 GPIO164:2;                   // 9:8 Select input qualification type for GPIO164
    Uint16 GPIO165:2;                   // 11:10 Select input qualification type for GPIO165
    Uint16 GPIO166:2;                   // 13:12 Select input qualification type for GPIO166
    Uint16 GPIO167:2;                   // 15:14 Select input qualification type for GPIO167
    Uint16 GPIO168:2;                   // 17:16 Select input qualification type for GPIO168
    Uint16 rsvd1:2;                     // 19:18 Reserved
    Uint16 rsvd2:2;                     // 21:20 Reserved
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 rsvd4:2;                     // 25:24 Reserved
    Uint16 rsvd5:2;                     // 27:26 Reserved
    Uint16 rsvd6:2;                     // 29:28 Reserved
    Uint16 rsvd7:2;                     // 31:30 Reserved
};

union GPFQSEL1_REG {
    Uint32  all;
    struct  GPFQSEL1_BITS  bit;
};

#ifdef CPU1
// GPFQSEL1 Register
//// GPFQSEL1 Register : Byte Value
#define GPFQSEL1_GPIO168_Synch							0x00000000UL
#define GPFQSEL1_GPIO168_3SampSynch						0x00010000UL
#define GPFQSEL1_GPIO168_6SampSynch						0x00020000UL
#define GPFQSEL1_GPIO168_Asynch							0x00030000UL

#define GPFQSEL1_GPIO167_Synch							0x00000000UL
#define GPFQSEL1_GPIO167_3SampSynch						0x00004000UL
#define GPFQSEL1_GPIO167_6SampSynch						0x00008000UL
#define GPFQSEL1_GPIO167_Asynch							0x0000C000UL

#define GPFQSEL1_GPIO166_Synch							0x00000000UL
#define GPFQSEL1_GPIO166_3SampSynch						0x00001000UL
#define GPFQSEL1_GPIO166_6SampSynch						0x00002000UL
#define GPFQSEL1_GPIO166_Asynch							0x00003000UL

#define GPFQSEL1_GPIO165_Synch							0x00000000UL
#define GPFQSEL1_GPIO165_3SampSynch						0x00000400UL
#define GPFQSEL1_GPIO165_6SampSynch						0x00000800UL
#define GPFQSEL1_GPIO165_Asynch							0x00000C00UL

#define GPFQSEL1_GPIO164_Synch							0x00000000UL
#define GPFQSEL1_GPIO164_3SampSynch						0x00000100UL
#define GPFQSEL1_GPIO164_6SampSynch						0x00000200UL
#define GPFQSEL1_GPIO164_Asynch							0x00000300UL

#define GPFQSEL1_GPIO163_Synch							0x00000000UL
#define GPFQSEL1_GPIO163_3SampSynch						0x00000040UL
#define GPFQSEL1_GPIO163_6SampSynch						0x00000080UL
#define GPFQSEL1_GPIO163_Asynch							0x000000C0UL

#define GPFQSEL1_GPIO162_Synch							0x00000000UL
#define GPFQSEL1_GPIO162_3SampSynch						0x00000010UL
#define GPFQSEL1_GPIO162_6SampSynch						0x00000020UL
#define GPFQSEL1_GPIO162_Asynch							0x00000030UL

#define GPFQSEL1_GPIO161_Synch							0x00000000UL
#define GPFQSEL1_GPIO161_3SampSynch						0x00000004UL
#define GPFQSEL1_GPIO161_6SampSynch						0x00000008UL
#define GPFQSEL1_GPIO161_Asynch							0x0000000CUL

#define GPFQSEL1_GPIO160_Synch							0x00000000UL
#define GPFQSEL1_GPIO160_3SampSynch						0x00000001UL
#define GPFQSEL1_GPIO160_6SampSynch						0x00000002UL
#define GPFQSEL1_GPIO160_Asynch							0x00000003UL
#endif

struct GPFMUX1_BITS {                   // bits description
    Uint16 GPIO160:2;                   // 1:0 Defines pin-muxing selection for GPIO160
    Uint16 GPIO161:2;                   // 3:2 Defines pin-muxing selection for GPIO161
    Uint16 GPIO162:2;                   // 5:4 Defines pin-muxing selection for GPIO162
    Uint16 GPIO163:2;                   // 7:6 Defines pin-muxing selection for GPIO163
    Uint16 GPIO164:2;                   // 9:8 Defines pin-muxing selection for GPIO164
    Uint16 GPIO165:2;                   // 11:10 Defines pin-muxing selection for GPIO165
    Uint16 GPIO166:2;                   // 13:12 Defines pin-muxing selection for GPIO166
    Uint16 GPIO167:2;                   // 15:14 Defines pin-muxing selection for GPIO167
    Uint16 GPIO168:2;                   // 17:16 Defines pin-muxing selection for GPIO168
    Uint16 rsvd1:2;                     // 19:18 Reserved
    Uint16 rsvd2:2;                     // 21:20 Reserved
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 rsvd4:2;                     // 25:24 Reserved
    Uint16 rsvd5:2;                     // 27:26 Reserved
    Uint16 rsvd6:2;                     // 29:28 Reserved
    Uint16 rsvd7:2;                     // 31:30 Reserved
};

union GPFMUX1_REG {
    Uint32  all;
    struct  GPFMUX1_BITS  bit;
};

#ifdef CPU1
// GPFMUX1 Register
//// GPFMUX1 Register : Byte Value													// GMUX		MUX
#define GPFMUX1_GPIO168_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO168_OutEPWM12B						0x00010000UL				// 0b00		0b01

#define GPFMUX1_GPIO167_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO167_OutEPWM12A						0x00004000UL				// 0b00		0b01

#define GPFMUX1_GPIO166_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO166_OutEPWM11B						0x00001000UL				// 0b00		0b01

#define GPFMUX1_GPIO165_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO165_OutEPWM11A						0x00000400UL				// 0b00		0b01

#define GPFMUX1_GPIO164_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO164_OutEPWM10B						0x00000100UL				// 0b00		0b01

#define GPFMUX1_GPIO163_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO163_OutEPWM10A						0x00000040UL				// 0b00		0b01

#define GPFMUX1_GPIO162_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO162_OutEPWM9B						0x00000010UL				// 0b00		0b01

#define GPFMUX1_GPIO161_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO161_OutEPWM9A						0x00000004UL				// 0b00		0b01

#define GPFMUX1_GPIO160_InOutGPIO						0x00000000UL				// -		0b00
#define GPFMUX1_GPIO160_OutEPWM8B						0x00000001UL				// 0b00		0b01
#endif

struct GPFDIR_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Defines direction for this pin in GPIO mode
    Uint16 GPIO161:1;                   // 1 Defines direction for this pin in GPIO mode
    Uint16 GPIO162:1;                   // 2 Defines direction for this pin in GPIO mode
    Uint16 GPIO163:1;                   // 3 Defines direction for this pin in GPIO mode
    Uint16 GPIO164:1;                   // 4 Defines direction for this pin in GPIO mode
    Uint16 GPIO165:1;                   // 5 Defines direction for this pin in GPIO mode
    Uint16 GPIO166:1;                   // 6 Defines direction for this pin in GPIO mode
    Uint16 GPIO167:1;                   // 7 Defines direction for this pin in GPIO mode
    Uint16 GPIO168:1;                   // 8 Defines direction for this pin in GPIO mode
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFDIR_REG {
    Uint32  all;
    struct  GPFDIR_BITS  bit;
};

#ifdef CPU1
// GPFDIR Register
//// GPFDIR Register : Byte Value
#define GPFDIR_GPIO168_Input							0x00000000UL
#define GPFDIR_GPIO168_Output							0x00000100UL

#define GPFDIR_GPIO167_Input							0x00000000UL
#define GPFDIR_GPIO167_Output							0x00000080UL

#define GPFDIR_GPIO166_Input							0x00000000UL
#define GPFDIR_GPIO166_Output							0x00000040UL

#define GPFDIR_GPIO165_Input							0x00000000UL
#define GPFDIR_GPIO165_Output							0x00000020UL

#define GPFDIR_GPIO164_Input							0x00000000UL
#define GPFDIR_GPIO164_Output							0x00000010UL

#define GPFDIR_GPIO163_Input							0x00000000UL
#define GPFDIR_GPIO163_Output							0x00000008UL

#define GPFDIR_GPIO162_Input							0x00000000UL
#define GPFDIR_GPIO162_Output							0x00000004UL

#define GPFDIR_GPIO161_Input							0x00000000UL
#define GPFDIR_GPIO161_Output							0x00000002UL

#define GPFDIR_GPIO160_Input							0x00000000UL
#define GPFDIR_GPIO160_Output							0x00000001UL
#endif

struct GPFPUD_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Pull-Up Disable control for this pin
    Uint16 GPIO161:1;                   // 1 Pull-Up Disable control for this pin
    Uint16 GPIO162:1;                   // 2 Pull-Up Disable control for this pin
    Uint16 GPIO163:1;                   // 3 Pull-Up Disable control for this pin
    Uint16 GPIO164:1;                   // 4 Pull-Up Disable control for this pin
    Uint16 GPIO165:1;                   // 5 Pull-Up Disable control for this pin
    Uint16 GPIO166:1;                   // 6 Pull-Up Disable control for this pin
    Uint16 GPIO167:1;                   // 7 Pull-Up Disable control for this pin
    Uint16 GPIO168:1;                   // 8 Pull-Up Disable control for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFPUD_REG {
    Uint32  all;
    struct  GPFPUD_BITS  bit;
};

#ifdef CPU1
// GPFPUD Register
//// GPFPUD Register : Byte Value
#define GPFPUD_GPIO168_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO168_PullUpDisable					0x00000100UL

#define GPFPUD_GPIO167_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO167_PullUpDisable					0x00000080UL

#define GPFPUD_GPIO166_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO166_PullUpDisable					0x00000040UL

#define GPFPUD_GPIO165_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO165_PullUpDisable					0x00000020UL

#define GPFPUD_GPIO164_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO164_PullUpDisable					0x00000010UL

#define GPFPUD_GPIO163_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO163_PullUpDisable					0x00000008UL

#define GPFPUD_GPIO162_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO162_PullUpDisable					0x00000004UL

#define GPFPUD_GPIO161_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO161_PullUpDisable					0x00000002UL

#define GPFPUD_GPIO160_PullUpEnable						0x00000000UL
#define GPFPUD_GPIO160_PullUpDisable					0x00000001UL
#endif

struct GPFINV_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Input inversion control for this pin
    Uint16 GPIO161:1;                   // 1 Input inversion control for this pin
    Uint16 GPIO162:1;                   // 2 Input inversion control for this pin
    Uint16 GPIO163:1;                   // 3 Input inversion control for this pin
    Uint16 GPIO164:1;                   // 4 Input inversion control for this pin
    Uint16 GPIO165:1;                   // 5 Input inversion control for this pin
    Uint16 GPIO166:1;                   // 6 Input inversion control for this pin
    Uint16 GPIO167:1;                   // 7 Input inversion control for this pin
    Uint16 GPIO168:1;                   // 8 Input inversion control for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFINV_REG {
    Uint32  all;
    struct  GPFINV_BITS  bit;
};

#ifdef CPU1
// GPFINV Register
//// GPFINV Register : Byte Value
#define GPFINV_GPIO168_InNormal							0x00000000UL
#define GPFINV_GPIO168_InInverted						0x00000100UL

#define GPFINV_GPIO167_InNormal							0x00000000UL
#define GPFINV_GPIO167_InInverted						0x00000080UL

#define GPFINV_GPIO166_InNormal							0x00000000UL
#define GPFINV_GPIO166_InInverted						0x00000040UL

#define GPFINV_GPIO165_InNormal							0x00000000UL
#define GPFINV_GPIO165_InInverted						0x00000020UL

#define GPFINV_GPIO164_InNormal							0x00000000UL
#define GPFINV_GPIO164_InInverted						0x00000010UL

#define GPFINV_GPIO163_InNormal							0x00000000UL
#define GPFINV_GPIO163_InInverted						0x00000008UL

#define GPFINV_GPIO162_InNormal							0x00000000UL
#define GPFINV_GPIO162_InInverted						0x00000004UL

#define GPFINV_GPIO161_InNormal							0x00000000UL
#define GPFINV_GPIO161_InInverted						0x00000002UL

#define GPFINV_GPIO160_InNormal							0x00000000UL
#define GPFINV_GPIO160_InInverted						0x00000001UL
#endif

struct GPFODR_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Outpout Open-Drain control for this pin
    Uint16 GPIO161:1;                   // 1 Outpout Open-Drain control for this pin
    Uint16 GPIO162:1;                   // 2 Outpout Open-Drain control for this pin
    Uint16 GPIO163:1;                   // 3 Outpout Open-Drain control for this pin
    Uint16 GPIO164:1;                   // 4 Outpout Open-Drain control for this pin
    Uint16 GPIO165:1;                   // 5 Outpout Open-Drain control for this pin
    Uint16 GPIO166:1;                   // 6 Outpout Open-Drain control for this pin
    Uint16 GPIO167:1;                   // 7 Outpout Open-Drain control for this pin
    Uint16 GPIO168:1;                   // 8 Outpout Open-Drain control for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFODR_REG {
    Uint32  all;
    struct  GPFODR_BITS  bit;
};

#ifdef CPU1
// GPFODR Register
//// GPFODR Register : Byte Value
#define GPFODR_GPIO168_Normal							0x00000000UL
#define GPFODR_GPIO168_OpenDrain						0x00000100UL

#define GPFODR_GPIO167_Normal							0x00000000UL
#define GPFODR_GPIO167_OpenDrain						0x00000080UL

#define GPFODR_GPIO166_Normal							0x00000000UL
#define GPFODR_GPIO166_OpenDrain						0x00000040UL

#define GPFODR_GPIO165_Normal							0x00000000UL
#define GPFODR_GPIO165_OpenDrain						0x00000020UL

#define GPFODR_GPIO164_Normal							0x00000000UL
#define GPFODR_GPIO164_OpenDrain						0x00000010UL

#define GPFODR_GPIO163_Normal							0x00000000UL
#define GPFODR_GPIO163_OpenDrain						0x00000008UL

#define GPFODR_GPIO162_Normal							0x00000000UL
#define GPFODR_GPIO162_OpenDrain						0x00000004UL

#define GPFODR_GPIO161_Normal							0x00000000UL
#define GPFODR_GPIO161_OpenDrain						0x00000002UL

#define GPFODR_GPIO160_Normal							0x00000000UL
#define GPFODR_GPIO160_OpenDrain						0x00000001UL
#endif

struct GPFGMUX1_BITS {                  // bits description
    Uint16 GPIO160:2;                   // 1:0 Defines pin-muxing selection for GPIO160
    Uint16 GPIO161:2;                   // 3:2 Defines pin-muxing selection for GPIO161
    Uint16 GPIO162:2;                   // 5:4 Defines pin-muxing selection for GPIO162
    Uint16 GPIO163:2;                   // 7:6 Defines pin-muxing selection for GPIO163
    Uint16 GPIO164:2;                   // 9:8 Defines pin-muxing selection for GPIO164
    Uint16 GPIO165:2;                   // 11:10 Defines pin-muxing selection for GPIO165
    Uint16 GPIO166:2;                   // 13:12 Defines pin-muxing selection for GPIO166
    Uint16 GPIO167:2;                   // 15:14 Defines pin-muxing selection for GPIO167
    Uint16 GPIO168:2;                   // 17:16 Defines pin-muxing selection for GPIO168
    Uint16 rsvd1:2;                     // 19:18 Reserved
    Uint16 rsvd2:2;                     // 21:20 Reserved
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 rsvd4:2;                     // 25:24 Reserved
    Uint16 rsvd5:2;                     // 27:26 Reserved
    Uint16 rsvd6:2;                     // 29:28 Reserved
    Uint16 rsvd7:2;                     // 31:30 Reserved
};

union GPFGMUX1_REG {
    Uint32  all;
    struct  GPFGMUX1_BITS  bit;
};

#ifdef CPU1
// GPFGMUX1 Register
//// GPFGMUX1 Register : Byte Value													// GMUX		MUX
#define GPFGMUX1_GPIO168_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO168_OutEPWM12B						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO167_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO167_OutEPWM12A						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO166_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO166_OutEPWM11B						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO165_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO165_OutEPWM11A						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO164_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO164_OutEPWM10B						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO163_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO163_OutEPWM10A						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO162_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO162_OutEPWM9B						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO161_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO161_OutEPWM9A						0x00000000UL				// 0b00		0b01

#define GPFGMUX1_GPIO160_InOutGPIO						0x00000000UL				// -		0b00
#define GPFGMUX1_GPIO160_OutEPWM8B						0x00000000UL				// 0b00		0b01
#endif

struct GPFCSEL1_BITS {                  // bits description
    Uint16 GPIO160:4;                   // 3:0 GPIO160 Master CPU Select
    Uint16 GPIO161:4;                   // 7:4 GPIO161 Master CPU Select
    Uint16 GPIO162:4;                   // 11:8 GPIO162 Master CPU Select
    Uint16 GPIO163:4;                   // 15:12 GPIO163 Master CPU Select
    Uint16 GPIO164:4;                   // 19:16 GPIO164 Master CPU Select
    Uint16 GPIO165:4;                   // 23:20 GPIO165 Master CPU Select
    Uint16 GPIO166:4;                   // 27:24 GPIO166 Master CPU Select
    Uint16 GPIO167:4;                   // 31:28 GPIO167 Master CPU Select
};

union GPFCSEL1_REG {
    Uint32  all;
    struct  GPFCSEL1_BITS  bit;
};

#ifdef CPU1
// GPFCSEL1 Register
//// GPFCSEL1 Register : Byte Value
#define GPFCSEL1_GPIO167_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO167_CPU1_CLA1Host					0x10000000UL
#define GPFCSEL1_GPIO167_CPU2Host						0x20000000UL
#define GPFCSEL1_GPIO167_CPU2_CLA1Host					0x30000000UL

#define GPFCSEL1_GPIO166_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO166_CPU1_CLA1Host					0x01000000UL
#define GPFCSEL1_GPIO166_CPU2Host						0x02000000UL
#define GPFCSEL1_GPIO166_CPU2_CLA1Host					0x03000000UL

#define GPFCSEL1_GPIO165_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO165_CPU1_CLA1Host					0x00100000UL
#define GPFCSEL1_GPIO165_CPU2Host						0x00200000UL
#define GPFCSEL1_GPIO165_CPU2_CLA1Host					0x00300000UL

#define GPFCSEL1_GPIO164_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO164_CPU1_CLA1Host					0x00010000UL
#define GPFCSEL1_GPIO164_CPU2Host						0x00020000UL
#define GPFCSEL1_GPIO164_CPU2_CLA1Host					0x00030000UL

#define GPFCSEL1_GPIO163_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO163_CPU1_CLA1Host					0x00001000UL
#define GPFCSEL1_GPIO163_CPU2Host						0x00002000UL
#define GPFCSEL1_GPIO163_CPU2_CLA1Host					0x00003000UL

#define GPFCSEL1_GPIO162_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO162_CPU1_CLA1Host					0x00000100UL
#define GPFCSEL1_GPIO162_CPU2Host						0x00000200UL
#define GPFCSEL1_GPIO162_CPU2_CLA1Host					0x00000300UL

#define GPFCSEL1_GPIO161_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO161_CPU1_CLA1Host					0x00000010UL
#define GPFCSEL1_GPIO161_CPU2Host						0x00000020UL
#define GPFCSEL1_GPIO161_CPU2_CLA1Host					0x00000030UL

#define GPFCSEL1_GPIO160_CPU1Host						0x00000000UL
#define GPFCSEL1_GPIO160_CPU1_CLA1Host					0x00000001UL
#define GPFCSEL1_GPIO160_CPU2Host						0x00000002UL
#define GPFCSEL1_GPIO160_CPU2_CLA1Host					0x00000003UL

//// GPFCSEL1 Register : Byte Value
#define GPFCSEL1_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPFCSEL2_BITS {                  // bits description
    Uint16 GPIO168:4;                   // 3:0 GPIO168 Master CPU Select
    Uint16 rsvd1:4;                     // 7:4 Reserved
    Uint16 rsvd2:4;                     // 11:8 Reserved
    Uint16 rsvd3:4;                     // 15:12 Reserved
    Uint16 rsvd4:4;                     // 19:16 Reserved
    Uint16 rsvd5:4;                     // 23:20 Reserved
    Uint16 rsvd6:4;                     // 27:24 Reserved
    Uint16 rsvd7:4;                     // 31:28 Reserved
};

union GPFCSEL2_REG {
    Uint32  all;
    struct  GPFCSEL2_BITS  bit;
};

#ifdef CPU1
// GPFCSEL2 Register
//// GPFCSEL2 Register : Byte Value
#define GPFCSEL2_GPIO168_CPU1Host						0x00000000UL
#define GPFCSEL2_GPIO168_CPU1_CLA1Host					0x00000001UL
#define GPFCSEL2_GPIO168_CPU2Host						0x00000002UL
#define GPFCSEL2_GPIO168_CPU2_CLA1Host					0x00000003UL

//// GPFCSEL2 Register : Byte Value
#define GPFCSEL2_GPIOAll_CPU1Host						0x00000000UL
#endif

struct GPFLOCK_BITS {                   // bits description
    Uint16 GPIO160:1;                   // 0 Configuration Lock bit for this pin
    Uint16 GPIO161:1;                   // 1 Configuration Lock bit for this pin
    Uint16 GPIO162:1;                   // 2 Configuration Lock bit for this pin
    Uint16 GPIO163:1;                   // 3 Configuration Lock bit for this pin
    Uint16 GPIO164:1;                   // 4 Configuration Lock bit for this pin
    Uint16 GPIO165:1;                   // 5 Configuration Lock bit for this pin
    Uint16 GPIO166:1;                   // 6 Configuration Lock bit for this pin
    Uint16 GPIO167:1;                   // 7 Configuration Lock bit for this pin
    Uint16 GPIO168:1;                   // 8 Configuration Lock bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFLOCK_REG {
    Uint32  all;
    struct  GPFLOCK_BITS  bit;
};

struct GPFCR_BITS {                     // bits description
    Uint16 GPIO160:1;                   // 0 Configuration lock commit bit for this pin
    Uint16 GPIO161:1;                   // 1 Configuration lock commit bit for this pin
    Uint16 GPIO162:1;                   // 2 Configuration lock commit bit for this pin
    Uint16 GPIO163:1;                   // 3 Configuration lock commit bit for this pin
    Uint16 GPIO164:1;                   // 4 Configuration lock commit bit for this pin
    Uint16 GPIO165:1;                   // 5 Configuration lock commit bit for this pin
    Uint16 GPIO166:1;                   // 6 Configuration lock commit bit for this pin
    Uint16 GPIO167:1;                   // 7 Configuration lock commit bit for this pin
    Uint16 GPIO168:1;                   // 8 Configuration lock commit bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFCR_REG {
    Uint32  all;
    struct  GPFCR_BITS  bit;
};

struct GPIO_CTRL_REGS {
    union   GPACTRL_REG                      GPACTRL;                      // GPIO A Qualification Sampling Period Control (GPIO0 to 31)
    union   GPAQSEL1_REG                     GPAQSEL1;                     // GPIO A Qualifier Select 1 Register (GPIO0 to 15)
    union   GPAQSEL2_REG                     GPAQSEL2;                     // GPIO A Qualifier Select 2 Register (GPIO16 to 31)
    union   GPAMUX1_REG                      GPAMUX1;                      // GPIO A Mux 1 Register (GPIO0 to 15)
    union   GPAMUX2_REG                      GPAMUX2;                      // GPIO A Mux 2 Register (GPIO16 to 31)
    union   GPADIR_REG                       GPADIR;                       // GPIO A Direction Register (GPIO0 to 31)
    union   GPAPUD_REG                       GPAPUD;                       // GPIO A Pull Up Disable Register (GPIO0 to 31) 
    Uint16                                   rsvd1[2];                     // Reserved
    union   GPAINV_REG                       GPAINV;                       // GPIO A Input Polarity Invert Registers (GPIO0 to 31)
    union   GPAODR_REG                       GPAODR;                       // GPIO A Open Drain Output Register (GPIO0 to GPIO31)
    Uint16                                   rsvd2[12];                    // Reserved
    union   GPAGMUX1_REG                     GPAGMUX1;                     // GPIO A Peripheral Group Mux (GPIO0 to 15)
    union   GPAGMUX2_REG                     GPAGMUX2;                     // GPIO A Peripheral Group Mux (GPIO16 to 31)
    Uint16                                   rsvd3[4];                     // Reserved
    union   GPACSEL1_REG                     GPACSEL1;                     // GPIO A Core Select Register (GPIO0 to 7)
    union   GPACSEL2_REG                     GPACSEL2;                     // GPIO A Core Select Register (GPIO8 to 15)
    union   GPACSEL3_REG                     GPACSEL3;                     // GPIO A Core Select Register (GPIO16 to 23)
    union   GPACSEL4_REG                     GPACSEL4;                     // GPIO A Core Select Register (GPIO24 to 31)
    Uint16                                   rsvd4[12];                    // Reserved
    union   GPALOCK_REG                      GPALOCK;                      // GPIO A Lock Configuration Register (GPIO0 to 31)
    union   GPACR_REG                        GPACR;                        // GPIO A Lock Commit Register (GPIO0 to 31)
    union   GPBCTRL_REG                      GPBCTRL;                      // GPIO B Qualification Sampling Period Control (GPIO32 to 63)
    union   GPBQSEL1_REG                     GPBQSEL1;                     // GPIO B Qualifier Select 1 Register (GPIO32 to 47)
    union   GPBQSEL2_REG                     GPBQSEL2;                     // GPIO B Qualifier Select 2 Register (GPIO48 to 63)
    union   GPBMUX1_REG                      GPBMUX1;                      // GPIO B Mux 1 Register (GPIO32 to 47)
    union   GPBMUX2_REG                      GPBMUX2;                      // GPIO B Mux 2 Register (GPIO48 to 63)
    union   GPBDIR_REG                       GPBDIR;                       // GPIO B Direction Register (GPIO32 to 63)
    union   GPBPUD_REG                       GPBPUD;                       // GPIO B Pull Up Disable Register (GPIO32 to 63) 
    Uint16                                   rsvd5[2];                     // Reserved
    union   GPBINV_REG                       GPBINV;                       // GPIO B Input Polarity Invert Registers (GPIO32 to 63)
    union   GPBODR_REG                       GPBODR;                       // GPIO B Open Drain Output Register (GPIO32 to GPIO63)
    union   GPBAMSEL_REG                     GPBAMSEL;                     // GPIO B Analog Mode Select register (GPIO32 to GPIO63)
    Uint16                                   rsvd6[10];                    // Reserved
    union   GPBGMUX1_REG                     GPBGMUX1;                     // GPIO B Peripheral Group Mux (GPIO32 to 47)
    union   GPBGMUX2_REG                     GPBGMUX2;                     // GPIO B Peripheral Group Mux (GPIO48 to 63)
    Uint16                                   rsvd7[4];                     // Reserved
    union   GPBCSEL1_REG                     GPBCSEL1;                     // GPIO B Core Select Register (GPIO32 to 39)
    union   GPBCSEL2_REG                     GPBCSEL2;                     // GPIO B Core Select Register (GPIO40 to 47)
    union   GPBCSEL3_REG                     GPBCSEL3;                     // GPIO B Core Select Register (GPIO48 to 55)
    union   GPBCSEL4_REG                     GPBCSEL4;                     // GPIO B Core Select Register (GPIO56 to 63)
    Uint16                                   rsvd8[12];                    // Reserved
    union   GPBLOCK_REG                      GPBLOCK;                      // GPIO B Lock Configuration Register (GPIO32 to 63)
    union   GPBCR_REG                        GPBCR;                        // GPIO B Lock Commit Register (GPIO32 to 63)
    union   GPCCTRL_REG                      GPCCTRL;                      // GPIO C Qualification Sampling Period Control (GPIO64 to 95)
    union   GPCQSEL1_REG                     GPCQSEL1;                     // GPIO C Qualifier Select 1 Register (GPIO64 to 79)
    union   GPCQSEL2_REG                     GPCQSEL2;                     // GPIO C Qualifier Select 2 Register (GPIO80  to 95)
    union   GPCMUX1_REG                      GPCMUX1;                      // GPIO C Mux 1 Register (GPIO64 to 79)
    union   GPCMUX2_REG                      GPCMUX2;                      // GPIO C Mux 2 Register (GPIO80  to 95)
    union   GPCDIR_REG                       GPCDIR;                       // GPIO C Direction Register (GPIO64 to 95)
    union   GPCPUD_REG                       GPCPUD;                       // GPIO C Pull Up Disable Register (GPIO64 to 95) 
    Uint16                                   rsvd9[2];                     // Reserved
    union   GPCINV_REG                       GPCINV;                       // GPIO C Input Polarity Invert Registers (GPIO64 to 95)
    union   GPCODR_REG                       GPCODR;                       // GPIO C Open Drain Output Register (GPIO64 to GPIO95)
    Uint16                                   rsvd10[12];                   // Reserved
    union   GPCGMUX1_REG                     GPCGMUX1;                     // GPIO C Peripheral Group Mux (GPIO64 to 79)
    union   GPCGMUX2_REG                     GPCGMUX2;                     // GPIO C Peripheral Group Mux (GPIO80  to 95)
    Uint16                                   rsvd11[4];                    // Reserved
    union   GPCCSEL1_REG                     GPCCSEL1;                     // GPIO C Core Select Register (GPIO64 to 71)
    union   GPCCSEL2_REG                     GPCCSEL2;                     // GPIO C Core Select Register (GPIO72 to 79)
    union   GPCCSEL3_REG                     GPCCSEL3;                     // GPIO C Core Select Register (GPIO80  to 87)
    union   GPCCSEL4_REG                     GPCCSEL4;                     // GPIO C Core Select Register (GPIO88 to 95)
    Uint16                                   rsvd12[12];                   // Reserved
    union   GPCLOCK_REG                      GPCLOCK;                      // GPIO C Lock Configuration Register (GPIO64 to 95)
    union   GPCCR_REG                        GPCCR;                        // GPIO C Lock Commit Register (GPIO64 to 95)
    union   GPDCTRL_REG                      GPDCTRL;                      // GPIO D Qualification Sampling Period Control (GPIO96 to 127)
    union   GPDQSEL1_REG                     GPDQSEL1;                     // GPIO D Qualifier Select 1 Register (GPIO96 to 111)
    union   GPDQSEL2_REG                     GPDQSEL2;                     // GPIO D Qualifier Select 2 Register (GPIO112 to 127)
    union   GPDMUX1_REG                      GPDMUX1;                      // GPIO D Mux 1 Register (GPIO96 to 111)
    union   GPDMUX2_REG                      GPDMUX2;                      // GPIO D Mux 2 Register (GPIO112 to 127)
    union   GPDDIR_REG                       GPDDIR;                       // GPIO D Direction Register (GPIO96 to 127)
    union   GPDPUD_REG                       GPDPUD;                       // GPIO D Pull Up Disable Register (GPIO96 to 127) 
    Uint16                                   rsvd13[2];                    // Reserved
    union   GPDINV_REG                       GPDINV;                       // GPIO D Input Polarity Invert Registers (GPIO96 to 127)
    union   GPDODR_REG                       GPDODR;                       // GPIO D Open Drain Output Register (GPIO96 to GPIO127)
    Uint16                                   rsvd14[12];                   // Reserved
    union   GPDGMUX1_REG                     GPDGMUX1;                     // GPIO D Peripheral Group Mux (GPIO96 to 111)
    union   GPDGMUX2_REG                     GPDGMUX2;                     // GPIO D Peripheral Group Mux (GPIO112 to 127)
    Uint16                                   rsvd15[4];                    // Reserved
    union   GPDCSEL1_REG                     GPDCSEL1;                     // GPIO D Core Select Register (GPIO96 to 103)
    union   GPDCSEL2_REG                     GPDCSEL2;                     // GPIO D Core Select Register (GPIO104 to 111)
    union   GPDCSEL3_REG                     GPDCSEL3;                     // GPIO D Core Select Register (GPIO112 to 119)
    union   GPDCSEL4_REG                     GPDCSEL4;                     // GPIO D Core Select Register (GPIO120 to 127)
    Uint16                                   rsvd16[12];                   // Reserved
    union   GPDLOCK_REG                      GPDLOCK;                      // GPIO D Lock Configuration Register (GPIO96 to 127)
    union   GPDCR_REG                        GPDCR;                        // GPIO D Lock Commit Register (GPIO96 to 127)
    union   GPECTRL_REG                      GPECTRL;                      // GPIO E Qualification Sampling Period Control (GPIO128 to 159)
    union   GPEQSEL1_REG                     GPEQSEL1;                     // GPIO E Qualifier Select 1 Register (GPIO128 to 143)
    union   GPEQSEL2_REG                     GPEQSEL2;                     // GPIO E Qualifier Select 2 Register (GPIO144  to 159)
    union   GPEMUX1_REG                      GPEMUX1;                      // GPIO E Mux 1 Register (GPIO128 to 143)
    union   GPEMUX2_REG                      GPEMUX2;                      // GPIO E Mux 2 Register (GPIO144  to 159)
    union   GPEDIR_REG                       GPEDIR;                       // GPIO E Direction Register (GPIO128 to 159)
    union   GPEPUD_REG                       GPEPUD;                       // GPIO E Pull Up Disable Register (GPIO128 to 159) 
    Uint16                                   rsvd17[2];                    // Reserved
    union   GPEINV_REG                       GPEINV;                       // GPIO E Input Polarity Invert Registers (GPIO128 to 159)
    union   GPEODR_REG                       GPEODR;                       // GPIO E Open Drain Output Register (GPIO128 to GPIO159)
    Uint16                                   rsvd18[12];                   // Reserved
    union   GPEGMUX1_REG                     GPEGMUX1;                     // GPIO E Peripheral Group Mux (GPIO128 to 143)
    union   GPEGMUX2_REG                     GPEGMUX2;                     // GPIO E Peripheral Group Mux (GPIO144  to 159)
    Uint16                                   rsvd19[4];                    // Reserved
    union   GPECSEL1_REG                     GPECSEL1;                     // GPIO E Core Select Register (GPIO128 to 135)
    union   GPECSEL2_REG                     GPECSEL2;                     // GPIO E Core Select Register (GPIO136 to 143)
    union   GPECSEL3_REG                     GPECSEL3;                     // GPIO E Core Select Register (GPIO144  to 151)
    union   GPECSEL4_REG                     GPECSEL4;                     // GPIO E Core Select Register (GPIO152 to 159)
    Uint16                                   rsvd20[12];                   // Reserved
    union   GPELOCK_REG                      GPELOCK;                      // GPIO E Lock Configuration Register (GPIO128 to 159)
    union   GPECR_REG                        GPECR;                        // GPIO E Lock Commit Register (GPIO128 to 159)
    union   GPFCTRL_REG                      GPFCTRL;                      // GPIO F Qualification Sampling Period Control (GPIO160 to 168)
    union   GPFQSEL1_REG                     GPFQSEL1;                     // GPIO F Qualifier Select 1 Register (GPIO160 to 168)
    Uint16                                   rsvd21[2];                    // Reserved
    union   GPFMUX1_REG                      GPFMUX1;                      // GPIO F Mux 1 Register (GPIO160 to 168)
    Uint16                                   rsvd22[2];                    // Reserved
    union   GPFDIR_REG                       GPFDIR;                       // GPIO F Direction Register (GPIO160 to 168)
    union   GPFPUD_REG                       GPFPUD;                       // GPIO F Pull Up Disable Register (GPIO160 to 168) 
    Uint16                                   rsvd23[2];                    // Reserved
    union   GPFINV_REG                       GPFINV;                       // GPIO F Input Polarity Invert Registers (GPIO160 to 168)
    union   GPFODR_REG                       GPFODR;                       // GPIO F Open Drain Output Register (GPIO160 to GPIO168)
    Uint16                                   rsvd24[12];                   // Reserved
    union   GPFGMUX1_REG                     GPFGMUX1;                     // GPIO F Peripheral Group Mux (GPIO160 to 168)
    Uint16                                   rsvd25[6];                    // Reserved
    union   GPFCSEL1_REG                     GPFCSEL1;                     // GPIO F Core Select Register (GPIO160 to 167)
    union   GPFCSEL2_REG                     GPFCSEL2;                     // GPIO F Core Select Register (GPIO168)
    Uint16                                   rsvd26[16];                   // Reserved
    union   GPFLOCK_REG                      GPFLOCK;                      // GPIO F Lock Configuration Register (GPIO160 to 168)
    union   GPFCR_REG                        GPFCR;                        // GPIO F Lock Commit Register (GPIO160 to 168)
};

struct GPADAT_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Data Register for this pin
    Uint16 GPIO1:1;                     // 1 Data Register for this pin
    Uint16 GPIO2:1;                     // 2 Data Register for this pin
    Uint16 GPIO3:1;                     // 3 Data Register for this pin
    Uint16 GPIO4:1;                     // 4 Data Register for this pin
    Uint16 GPIO5:1;                     // 5 Data Register for this pin
    Uint16 GPIO6:1;                     // 6 Data Register for this pin
    Uint16 GPIO7:1;                     // 7 Data Register for this pin
    Uint16 GPIO8:1;                     // 8 Data Register for this pin
    Uint16 GPIO9:1;                     // 9 Data Register for this pin
    Uint16 GPIO10:1;                    // 10 Data Register for this pin
    Uint16 GPIO11:1;                    // 11 Data Register for this pin
    Uint16 GPIO12:1;                    // 12 Data Register for this pin
    Uint16 GPIO13:1;                    // 13 Data Register for this pin
    Uint16 GPIO14:1;                    // 14 Data Register for this pin
    Uint16 GPIO15:1;                    // 15 Data Register for this pin
    Uint16 GPIO16:1;                    // 16 Data Register for this pin
    Uint16 GPIO17:1;                    // 17 Data Register for this pin
    Uint16 GPIO18:1;                    // 18 Data Register for this pin
    Uint16 GPIO19:1;                    // 19 Data Register for this pin
    Uint16 GPIO20:1;                    // 20 Data Register for this pin
    Uint16 GPIO21:1;                    // 21 Data Register for this pin
    Uint16 GPIO22:1;                    // 22 Data Register for this pin
    Uint16 GPIO23:1;                    // 23 Data Register for this pin
    Uint16 GPIO24:1;                    // 24 Data Register for this pin
    Uint16 GPIO25:1;                    // 25 Data Register for this pin
    Uint16 GPIO26:1;                    // 26 Data Register for this pin
    Uint16 GPIO27:1;                    // 27 Data Register for this pin
    Uint16 GPIO28:1;                    // 28 Data Register for this pin
    Uint16 GPIO29:1;                    // 29 Data Register for this pin
    Uint16 GPIO30:1;                    // 30 Data Register for this pin
    Uint16 GPIO31:1;                    // 31 Data Register for this pin
};

union GPADAT_REG {
    Uint32  all;
    struct  GPADAT_BITS  bit;
};

struct GPASET_BITS {                    // bits description
    Uint16 GPIO0:1;                     // 0 Output Set bit for this pin
    Uint16 GPIO1:1;                     // 1 Output Set bit for this pin
    Uint16 GPIO2:1;                     // 2 Output Set bit for this pin
    Uint16 GPIO3:1;                     // 3 Output Set bit for this pin
    Uint16 GPIO4:1;                     // 4 Output Set bit for this pin
    Uint16 GPIO5:1;                     // 5 Output Set bit for this pin
    Uint16 GPIO6:1;                     // 6 Output Set bit for this pin
    Uint16 GPIO7:1;                     // 7 Output Set bit for this pin
    Uint16 GPIO8:1;                     // 8 Output Set bit for this pin
    Uint16 GPIO9:1;                     // 9 Output Set bit for this pin
    Uint16 GPIO10:1;                    // 10 Output Set bit for this pin
    Uint16 GPIO11:1;                    // 11 Output Set bit for this pin
    Uint16 GPIO12:1;                    // 12 Output Set bit for this pin
    Uint16 GPIO13:1;                    // 13 Output Set bit for this pin
    Uint16 GPIO14:1;                    // 14 Output Set bit for this pin
    Uint16 GPIO15:1;                    // 15 Output Set bit for this pin
    Uint16 GPIO16:1;                    // 16 Output Set bit for this pin
    Uint16 GPIO17:1;                    // 17 Output Set bit for this pin
    Uint16 GPIO18:1;                    // 18 Output Set bit for this pin
    Uint16 GPIO19:1;                    // 19 Output Set bit for this pin
    Uint16 GPIO20:1;                    // 20 Output Set bit for this pin
    Uint16 GPIO21:1;                    // 21 Output Set bit for this pin
    Uint16 GPIO22:1;                    // 22 Output Set bit for this pin
    Uint16 GPIO23:1;                    // 23 Output Set bit for this pin
    Uint16 GPIO24:1;                    // 24 Output Set bit for this pin
    Uint16 GPIO25:1;                    // 25 Output Set bit for this pin
    Uint16 GPIO26:1;                    // 26 Output Set bit for this pin
    Uint16 GPIO27:1;                    // 27 Output Set bit for this pin
    Uint16 GPIO28:1;                    // 28 Output Set bit for this pin
    Uint16 GPIO29:1;                    // 29 Output Set bit for this pin
    Uint16 GPIO30:1;                    // 30 Output Set bit for this pin
    Uint16 GPIO31:1;                    // 31 Output Set bit for this pin
};

union GPASET_REG {
    Uint32  all;
    struct  GPASET_BITS  bit;
};

struct GPACLEAR_BITS {                  // bits description
    Uint16 GPIO0:1;                     // 0 Output Clear bit for this pin
    Uint16 GPIO1:1;                     // 1 Output Clear bit for this pin
    Uint16 GPIO2:1;                     // 2 Output Clear bit for this pin
    Uint16 GPIO3:1;                     // 3 Output Clear bit for this pin
    Uint16 GPIO4:1;                     // 4 Output Clear bit for this pin
    Uint16 GPIO5:1;                     // 5 Output Clear bit for this pin
    Uint16 GPIO6:1;                     // 6 Output Clear bit for this pin
    Uint16 GPIO7:1;                     // 7 Output Clear bit for this pin
    Uint16 GPIO8:1;                     // 8 Output Clear bit for this pin
    Uint16 GPIO9:1;                     // 9 Output Clear bit for this pin
    Uint16 GPIO10:1;                    // 10 Output Clear bit for this pin
    Uint16 GPIO11:1;                    // 11 Output Clear bit for this pin
    Uint16 GPIO12:1;                    // 12 Output Clear bit for this pin
    Uint16 GPIO13:1;                    // 13 Output Clear bit for this pin
    Uint16 GPIO14:1;                    // 14 Output Clear bit for this pin
    Uint16 GPIO15:1;                    // 15 Output Clear bit for this pin
    Uint16 GPIO16:1;                    // 16 Output Clear bit for this pin
    Uint16 GPIO17:1;                    // 17 Output Clear bit for this pin
    Uint16 GPIO18:1;                    // 18 Output Clear bit for this pin
    Uint16 GPIO19:1;                    // 19 Output Clear bit for this pin
    Uint16 GPIO20:1;                    // 20 Output Clear bit for this pin
    Uint16 GPIO21:1;                    // 21 Output Clear bit for this pin
    Uint16 GPIO22:1;                    // 22 Output Clear bit for this pin
    Uint16 GPIO23:1;                    // 23 Output Clear bit for this pin
    Uint16 GPIO24:1;                    // 24 Output Clear bit for this pin
    Uint16 GPIO25:1;                    // 25 Output Clear bit for this pin
    Uint16 GPIO26:1;                    // 26 Output Clear bit for this pin
    Uint16 GPIO27:1;                    // 27 Output Clear bit for this pin
    Uint16 GPIO28:1;                    // 28 Output Clear bit for this pin
    Uint16 GPIO29:1;                    // 29 Output Clear bit for this pin
    Uint16 GPIO30:1;                    // 30 Output Clear bit for this pin
    Uint16 GPIO31:1;                    // 31 Output Clear bit for this pin
};

union GPACLEAR_REG {
    Uint32  all;
    struct  GPACLEAR_BITS  bit;
};

struct GPATOGGLE_BITS {                 // bits description
    Uint16 GPIO0:1;                     // 0 Output Toggle bit for this pin
    Uint16 GPIO1:1;                     // 1 Output Toggle bit for this pin
    Uint16 GPIO2:1;                     // 2 Output Toggle bit for this pin
    Uint16 GPIO3:1;                     // 3 Output Toggle bit for this pin
    Uint16 GPIO4:1;                     // 4 Output Toggle bit for this pin
    Uint16 GPIO5:1;                     // 5 Output Toggle bit for this pin
    Uint16 GPIO6:1;                     // 6 Output Toggle bit for this pin
    Uint16 GPIO7:1;                     // 7 Output Toggle bit for this pin
    Uint16 GPIO8:1;                     // 8 Output Toggle bit for this pin
    Uint16 GPIO9:1;                     // 9 Output Toggle bit for this pin
    Uint16 GPIO10:1;                    // 10 Output Toggle bit for this pin
    Uint16 GPIO11:1;                    // 11 Output Toggle bit for this pin
    Uint16 GPIO12:1;                    // 12 Output Toggle bit for this pin
    Uint16 GPIO13:1;                    // 13 Output Toggle bit for this pin
    Uint16 GPIO14:1;                    // 14 Output Toggle bit for this pin
    Uint16 GPIO15:1;                    // 15 Output Toggle bit for this pin
    Uint16 GPIO16:1;                    // 16 Output Toggle bit for this pin
    Uint16 GPIO17:1;                    // 17 Output Toggle bit for this pin
    Uint16 GPIO18:1;                    // 18 Output Toggle bit for this pin
    Uint16 GPIO19:1;                    // 19 Output Toggle bit for this pin
    Uint16 GPIO20:1;                    // 20 Output Toggle bit for this pin
    Uint16 GPIO21:1;                    // 21 Output Toggle bit for this pin
    Uint16 GPIO22:1;                    // 22 Output Toggle bit for this pin
    Uint16 GPIO23:1;                    // 23 Output Toggle bit for this pin
    Uint16 GPIO24:1;                    // 24 Output Toggle bit for this pin
    Uint16 GPIO25:1;                    // 25 Output Toggle bit for this pin
    Uint16 GPIO26:1;                    // 26 Output Toggle bit for this pin
    Uint16 GPIO27:1;                    // 27 Output Toggle bit for this pin
    Uint16 GPIO28:1;                    // 28 Output Toggle bit for this pin
    Uint16 GPIO29:1;                    // 29 Output Toggle bit for this pin
    Uint16 GPIO30:1;                    // 30 Output Toggle bit for this pin
    Uint16 GPIO31:1;                    // 31 Output Toggle bit for this pin
};

union GPATOGGLE_REG {
    Uint32  all;
    struct  GPATOGGLE_BITS  bit;
};

// GPAxxx Register
//// GPAxxx Register : Byte Value
#define GPAxxx_GPIO031									0x80000000UL
#define GPAxxx_GPIO030									0x40000000UL
#define GPAxxx_GPIO029									0x20000000UL
#define GPAxxx_GPIO028									0x10000000UL
#define GPAxxx_GPIO027									0x08000000UL
#define GPAxxx_GPIO026									0x04000000UL
#define GPAxxx_GPIO025									0x02000000UL
#define GPAxxx_GPIO024									0x01000000UL
#define GPAxxx_GPIO023									0x00800000UL
#define GPAxxx_GPIO022									0x00400000UL
#define GPAxxx_GPIO021									0x00200000UL
#define GPAxxx_GPIO020									0x00100000UL
#define GPAxxx_GPIO019									0x00080000UL
#define GPAxxx_GPIO018									0x00040000UL
#define GPAxxx_GPIO017									0x00020000UL
#define GPAxxx_GPIO016									0x00010000UL
#define GPAxxx_GPIO015									0x00008000UL
#define GPAxxx_GPIO014									0x00004000UL
#define GPAxxx_GPIO013									0x00002000UL
#define GPAxxx_GPIO012									0x00001000UL
#define GPAxxx_GPIO011									0x00000800UL
#define GPAxxx_GPIO010									0x00000400UL
#define GPAxxx_GPIO009									0x00000200UL
#define GPAxxx_GPIO008									0x00000100UL
#define GPAxxx_GPIO007									0x00000080UL
#define GPAxxx_GPIO006									0x00000040UL
#define GPAxxx_GPIO005									0x00000020UL
#define GPAxxx_GPIO004									0x00000010UL
#define GPAxxx_GPIO003									0x00000008UL
#define GPAxxx_GPIO002									0x00000004UL
#define GPAxxx_GPIO001									0x00000002UL
#define GPAxxx_GPIO000									0x00000001UL

struct GPBDAT_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Data Register for this pin
    Uint16 GPIO33:1;                    // 1 Data Register for this pin
    Uint16 GPIO34:1;                    // 2 Data Register for this pin
    Uint16 GPIO35:1;                    // 3 Data Register for this pin
    Uint16 GPIO36:1;                    // 4 Data Register for this pin
    Uint16 GPIO37:1;                    // 5 Data Register for this pin
    Uint16 GPIO38:1;                    // 6 Data Register for this pin
    Uint16 GPIO39:1;                    // 7 Data Register for this pin
    Uint16 GPIO40:1;                    // 8 Data Register for this pin
    Uint16 GPIO41:1;                    // 9 Data Register for this pin
    Uint16 GPIO42:1;                    // 10 Data Register for this pin
    Uint16 GPIO43:1;                    // 11 Data Register for this pin
    Uint16 GPIO44:1;                    // 12 Data Register for this pin
    Uint16 GPIO45:1;                    // 13 Data Register for this pin
    Uint16 GPIO46:1;                    // 14 Data Register for this pin
    Uint16 GPIO47:1;                    // 15 Data Register for this pin
    Uint16 GPIO48:1;                    // 16 Data Register for this pin
    Uint16 GPIO49:1;                    // 17 Data Register for this pin
    Uint16 GPIO50:1;                    // 18 Data Register for this pin
    Uint16 GPIO51:1;                    // 19 Data Register for this pin
    Uint16 GPIO52:1;                    // 20 Data Register for this pin
    Uint16 GPIO53:1;                    // 21 Data Register for this pin
    Uint16 GPIO54:1;                    // 22 Data Register for this pin
    Uint16 GPIO55:1;                    // 23 Data Register for this pin
    Uint16 GPIO56:1;                    // 24 Data Register for this pin
    Uint16 GPIO57:1;                    // 25 Data Register for this pin
    Uint16 GPIO58:1;                    // 26 Data Register for this pin
    Uint16 GPIO59:1;                    // 27 Data Register for this pin
    Uint16 GPIO60:1;                    // 28 Data Register for this pin
    Uint16 GPIO61:1;                    // 29 Data Register for this pin
    Uint16 GPIO62:1;                    // 30 Data Register for this pin
    Uint16 GPIO63:1;                    // 31 Data Register for this pin
};

union GPBDAT_REG {
    Uint32  all;
    struct  GPBDAT_BITS  bit;
};

struct GPBSET_BITS {                    // bits description
    Uint16 GPIO32:1;                    // 0 Output Set bit for this pin
    Uint16 GPIO33:1;                    // 1 Output Set bit for this pin
    Uint16 GPIO34:1;                    // 2 Output Set bit for this pin
    Uint16 GPIO35:1;                    // 3 Output Set bit for this pin
    Uint16 GPIO36:1;                    // 4 Output Set bit for this pin
    Uint16 GPIO37:1;                    // 5 Output Set bit for this pin
    Uint16 GPIO38:1;                    // 6 Output Set bit for this pin
    Uint16 GPIO39:1;                    // 7 Output Set bit for this pin
    Uint16 GPIO40:1;                    // 8 Output Set bit for this pin
    Uint16 GPIO41:1;                    // 9 Output Set bit for this pin
    Uint16 GPIO42:1;                    // 10 Output Set bit for this pin
    Uint16 GPIO43:1;                    // 11 Output Set bit for this pin
    Uint16 GPIO44:1;                    // 12 Output Set bit for this pin
    Uint16 GPIO45:1;                    // 13 Output Set bit for this pin
    Uint16 GPIO46:1;                    // 14 Output Set bit for this pin
    Uint16 GPIO47:1;                    // 15 Output Set bit for this pin
    Uint16 GPIO48:1;                    // 16 Output Set bit for this pin
    Uint16 GPIO49:1;                    // 17 Output Set bit for this pin
    Uint16 GPIO50:1;                    // 18 Output Set bit for this pin
    Uint16 GPIO51:1;                    // 19 Output Set bit for this pin
    Uint16 GPIO52:1;                    // 20 Output Set bit for this pin
    Uint16 GPIO53:1;                    // 21 Output Set bit for this pin
    Uint16 GPIO54:1;                    // 22 Output Set bit for this pin
    Uint16 GPIO55:1;                    // 23 Output Set bit for this pin
    Uint16 GPIO56:1;                    // 24 Output Set bit for this pin
    Uint16 GPIO57:1;                    // 25 Output Set bit for this pin
    Uint16 GPIO58:1;                    // 26 Output Set bit for this pin
    Uint16 GPIO59:1;                    // 27 Output Set bit for this pin
    Uint16 GPIO60:1;                    // 28 Output Set bit for this pin
    Uint16 GPIO61:1;                    // 29 Output Set bit for this pin
    Uint16 GPIO62:1;                    // 30 Output Set bit for this pin
    Uint16 GPIO63:1;                    // 31 Output Set bit for this pin
};

union GPBSET_REG {
    Uint32  all;
    struct  GPBSET_BITS  bit;
};

struct GPBCLEAR_BITS {                  // bits description
    Uint16 GPIO32:1;                    // 0 Output Clear bit for this pin
    Uint16 GPIO33:1;                    // 1 Output Clear bit for this pin
    Uint16 GPIO34:1;                    // 2 Output Clear bit for this pin
    Uint16 GPIO35:1;                    // 3 Output Clear bit for this pin
    Uint16 GPIO36:1;                    // 4 Output Clear bit for this pin
    Uint16 GPIO37:1;                    // 5 Output Clear bit for this pin
    Uint16 GPIO38:1;                    // 6 Output Clear bit for this pin
    Uint16 GPIO39:1;                    // 7 Output Clear bit for this pin
    Uint16 GPIO40:1;                    // 8 Output Clear bit for this pin
    Uint16 GPIO41:1;                    // 9 Output Clear bit for this pin
    Uint16 GPIO42:1;                    // 10 Output Clear bit for this pin
    Uint16 GPIO43:1;                    // 11 Output Clear bit for this pin
    Uint16 GPIO44:1;                    // 12 Output Clear bit for this pin
    Uint16 GPIO45:1;                    // 13 Output Clear bit for this pin
    Uint16 GPIO46:1;                    // 14 Output Clear bit for this pin
    Uint16 GPIO47:1;                    // 15 Output Clear bit for this pin
    Uint16 GPIO48:1;                    // 16 Output Clear bit for this pin
    Uint16 GPIO49:1;                    // 17 Output Clear bit for this pin
    Uint16 GPIO50:1;                    // 18 Output Clear bit for this pin
    Uint16 GPIO51:1;                    // 19 Output Clear bit for this pin
    Uint16 GPIO52:1;                    // 20 Output Clear bit for this pin
    Uint16 GPIO53:1;                    // 21 Output Clear bit for this pin
    Uint16 GPIO54:1;                    // 22 Output Clear bit for this pin
    Uint16 GPIO55:1;                    // 23 Output Clear bit for this pin
    Uint16 GPIO56:1;                    // 24 Output Clear bit for this pin
    Uint16 GPIO57:1;                    // 25 Output Clear bit for this pin
    Uint16 GPIO58:1;                    // 26 Output Clear bit for this pin
    Uint16 GPIO59:1;                    // 27 Output Clear bit for this pin
    Uint16 GPIO60:1;                    // 28 Output Clear bit for this pin
    Uint16 GPIO61:1;                    // 29 Output Clear bit for this pin
    Uint16 GPIO62:1;                    // 30 Output Clear bit for this pin
    Uint16 GPIO63:1;                    // 31 Output Clear bit for this pin
};

union GPBCLEAR_REG {
    Uint32  all;
    struct  GPBCLEAR_BITS  bit;
};

struct GPBTOGGLE_BITS {                 // bits description
    Uint16 GPIO32:1;                    // 0 Output Toggle bit for this pin
    Uint16 GPIO33:1;                    // 1 Output Toggle bit for this pin
    Uint16 GPIO34:1;                    // 2 Output Toggle bit for this pin
    Uint16 GPIO35:1;                    // 3 Output Toggle bit for this pin
    Uint16 GPIO36:1;                    // 4 Output Toggle bit for this pin
    Uint16 GPIO37:1;                    // 5 Output Toggle bit for this pin
    Uint16 GPIO38:1;                    // 6 Output Toggle bit for this pin
    Uint16 GPIO39:1;                    // 7 Output Toggle bit for this pin
    Uint16 GPIO40:1;                    // 8 Output Toggle bit for this pin
    Uint16 GPIO41:1;                    // 9 Output Toggle bit for this pin
    Uint16 GPIO42:1;                    // 10 Output Toggle bit for this pin
    Uint16 GPIO43:1;                    // 11 Output Toggle bit for this pin
    Uint16 GPIO44:1;                    // 12 Output Toggle bit for this pin
    Uint16 GPIO45:1;                    // 13 Output Toggle bit for this pin
    Uint16 GPIO46:1;                    // 14 Output Toggle bit for this pin
    Uint16 GPIO47:1;                    // 15 Output Toggle bit for this pin
    Uint16 GPIO48:1;                    // 16 Output Toggle bit for this pin
    Uint16 GPIO49:1;                    // 17 Output Toggle bit for this pin
    Uint16 GPIO50:1;                    // 18 Output Toggle bit for this pin
    Uint16 GPIO51:1;                    // 19 Output Toggle bit for this pin
    Uint16 GPIO52:1;                    // 20 Output Toggle bit for this pin
    Uint16 GPIO53:1;                    // 21 Output Toggle bit for this pin
    Uint16 GPIO54:1;                    // 22 Output Toggle bit for this pin
    Uint16 GPIO55:1;                    // 23 Output Toggle bit for this pin
    Uint16 GPIO56:1;                    // 24 Output Toggle bit for this pin
    Uint16 GPIO57:1;                    // 25 Output Toggle bit for this pin
    Uint16 GPIO58:1;                    // 26 Output Toggle bit for this pin
    Uint16 GPIO59:1;                    // 27 Output Toggle bit for this pin
    Uint16 GPIO60:1;                    // 28 Output Toggle bit for this pin
    Uint16 GPIO61:1;                    // 29 Output Toggle bit for this pin
    Uint16 GPIO62:1;                    // 30 Output Toggle bit for this pin
    Uint16 GPIO63:1;                    // 31 Output Toggle bit for this pin
};

union GPBTOGGLE_REG {
    Uint32  all;
    struct  GPBTOGGLE_BITS  bit;
};

// GPBxxx Register
//// GPBxxx Register : Byte Value
#define GPBxxx_GPIO063									0x80000000UL
#define GPBxxx_GPIO062									0x40000000UL
#define GPBxxx_GPIO061									0x20000000UL
#define GPBxxx_GPIO060									0x10000000UL
#define GPBxxx_GPIO059									0x08000000UL
#define GPBxxx_GPIO058									0x04000000UL
#define GPBxxx_GPIO057									0x02000000UL
#define GPBxxx_GPIO056									0x01000000UL
#define GPBxxx_GPIO055									0x00800000UL
#define GPBxxx_GPIO054									0x00400000UL
#define GPBxxx_GPIO053									0x00200000UL
#define GPBxxx_GPIO052									0x00100000UL
#define GPBxxx_GPIO051									0x00080000UL
#define GPBxxx_GPIO050									0x00040000UL
#define GPBxxx_GPIO049									0x00020000UL
#define GPBxxx_GPIO048									0x00010000UL
#define GPBxxx_GPIO047									0x00008000UL
#define GPBxxx_GPIO046									0x00004000UL
#define GPBxxx_GPIO045									0x00002000UL
#define GPBxxx_GPIO044									0x00001000UL
#define GPBxxx_GPIO043									0x00000800UL
#define GPBxxx_GPIO042									0x00000400UL
#define GPBxxx_GPIO041									0x00000200UL
#define GPBxxx_GPIO040									0x00000100UL
#define GPBxxx_GPIO039									0x00000080UL
#define GPBxxx_GPIO038									0x00000040UL
#define GPBxxx_GPIO037									0x00000020UL
#define GPBxxx_GPIO036									0x00000010UL
#define GPBxxx_GPIO035									0x00000008UL
#define GPBxxx_GPIO034									0x00000004UL
#define GPBxxx_GPIO033									0x00000002UL
#define GPBxxx_GPIO032									0x00000001UL

struct GPCDAT_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Data Register for this pin
    Uint16 GPIO65:1;                    // 1 Data Register for this pin
    Uint16 GPIO66:1;                    // 2 Data Register for this pin
    Uint16 GPIO67:1;                    // 3 Data Register for this pin
    Uint16 GPIO68:1;                    // 4 Data Register for this pin
    Uint16 GPIO69:1;                    // 5 Data Register for this pin
    Uint16 GPIO70:1;                    // 6 Data Register for this pin
    Uint16 GPIO71:1;                    // 7 Data Register for this pin
    Uint16 GPIO72:1;                    // 8 Data Register for this pin
    Uint16 GPIO73:1;                    // 9 Data Register for this pin
    Uint16 GPIO74:1;                    // 10 Data Register for this pin
    Uint16 GPIO75:1;                    // 11 Data Register for this pin
    Uint16 GPIO76:1;                    // 12 Data Register for this pin
    Uint16 GPIO77:1;                    // 13 Data Register for this pin
    Uint16 GPIO78:1;                    // 14 Data Register for this pin
    Uint16 GPIO79:1;                    // 15 Data Register for this pin
    Uint16 GPIO80:1;                    // 16 Data Register for this pin
    Uint16 GPIO81:1;                    // 17 Data Register for this pin
    Uint16 GPIO82:1;                    // 18 Data Register for this pin
    Uint16 GPIO83:1;                    // 19 Data Register for this pin
    Uint16 GPIO84:1;                    // 20 Data Register for this pin
    Uint16 GPIO85:1;                    // 21 Data Register for this pin
    Uint16 GPIO86:1;                    // 22 Data Register for this pin
    Uint16 GPIO87:1;                    // 23 Data Register for this pin
    Uint16 GPIO88:1;                    // 24 Data Register for this pin
    Uint16 GPIO89:1;                    // 25 Data Register for this pin
    Uint16 GPIO90:1;                    // 26 Data Register for this pin
    Uint16 GPIO91:1;                    // 27 Data Register for this pin
    Uint16 GPIO92:1;                    // 28 Data Register for this pin
    Uint16 GPIO93:1;                    // 29 Data Register for this pin
    Uint16 GPIO94:1;                    // 30 Data Register for this pin
    Uint16 GPIO95:1;                    // 31 Data Register for this pin
};

union GPCDAT_REG {
    Uint32  all;
    struct  GPCDAT_BITS  bit;
};

struct GPCSET_BITS {                    // bits description
    Uint16 GPIO64:1;                    // 0 Output Set bit for this pin
    Uint16 GPIO65:1;                    // 1 Output Set bit for this pin
    Uint16 GPIO66:1;                    // 2 Output Set bit for this pin
    Uint16 GPIO67:1;                    // 3 Output Set bit for this pin
    Uint16 GPIO68:1;                    // 4 Output Set bit for this pin
    Uint16 GPIO69:1;                    // 5 Output Set bit for this pin
    Uint16 GPIO70:1;                    // 6 Output Set bit for this pin
    Uint16 GPIO71:1;                    // 7 Output Set bit for this pin
    Uint16 GPIO72:1;                    // 8 Output Set bit for this pin
    Uint16 GPIO73:1;                    // 9 Output Set bit for this pin
    Uint16 GPIO74:1;                    // 10 Output Set bit for this pin
    Uint16 GPIO75:1;                    // 11 Output Set bit for this pin
    Uint16 GPIO76:1;                    // 12 Output Set bit for this pin
    Uint16 GPIO77:1;                    // 13 Output Set bit for this pin
    Uint16 GPIO78:1;                    // 14 Output Set bit for this pin
    Uint16 GPIO79:1;                    // 15 Output Set bit for this pin
    Uint16 GPIO80:1;                    // 16 Output Set bit for this pin
    Uint16 GPIO81:1;                    // 17 Output Set bit for this pin
    Uint16 GPIO82:1;                    // 18 Output Set bit for this pin
    Uint16 GPIO83:1;                    // 19 Output Set bit for this pin
    Uint16 GPIO84:1;                    // 20 Output Set bit for this pin
    Uint16 GPIO85:1;                    // 21 Output Set bit for this pin
    Uint16 GPIO86:1;                    // 22 Output Set bit for this pin
    Uint16 GPIO87:1;                    // 23 Output Set bit for this pin
    Uint16 GPIO88:1;                    // 24 Output Set bit for this pin
    Uint16 GPIO89:1;                    // 25 Output Set bit for this pin
    Uint16 GPIO90:1;                    // 26 Output Set bit for this pin
    Uint16 GPIO91:1;                    // 27 Output Set bit for this pin
    Uint16 GPIO92:1;                    // 28 Output Set bit for this pin
    Uint16 GPIO93:1;                    // 29 Output Set bit for this pin
    Uint16 GPIO94:1;                    // 30 Output Set bit for this pin
    Uint16 GPIO95:1;                    // 31 Output Set bit for this pin
};

union GPCSET_REG {
    Uint32  all;
    struct  GPCSET_BITS  bit;
};

struct GPCCLEAR_BITS {                  // bits description
    Uint16 GPIO64:1;                    // 0 Output Clear bit for this pin
    Uint16 GPIO65:1;                    // 1 Output Clear bit for this pin
    Uint16 GPIO66:1;                    // 2 Output Clear bit for this pin
    Uint16 GPIO67:1;                    // 3 Output Clear bit for this pin
    Uint16 GPIO68:1;                    // 4 Output Clear bit for this pin
    Uint16 GPIO69:1;                    // 5 Output Clear bit for this pin
    Uint16 GPIO70:1;                    // 6 Output Clear bit for this pin
    Uint16 GPIO71:1;                    // 7 Output Clear bit for this pin
    Uint16 GPIO72:1;                    // 8 Output Clear bit for this pin
    Uint16 GPIO73:1;                    // 9 Output Clear bit for this pin
    Uint16 GPIO74:1;                    // 10 Output Clear bit for this pin
    Uint16 GPIO75:1;                    // 11 Output Clear bit for this pin
    Uint16 GPIO76:1;                    // 12 Output Clear bit for this pin
    Uint16 GPIO77:1;                    // 13 Output Clear bit for this pin
    Uint16 GPIO78:1;                    // 14 Output Clear bit for this pin
    Uint16 GPIO79:1;                    // 15 Output Clear bit for this pin
    Uint16 GPIO80:1;                    // 16 Output Clear bit for this pin
    Uint16 GPIO81:1;                    // 17 Output Clear bit for this pin
    Uint16 GPIO82:1;                    // 18 Output Clear bit for this pin
    Uint16 GPIO83:1;                    // 19 Output Clear bit for this pin
    Uint16 GPIO84:1;                    // 20 Output Clear bit for this pin
    Uint16 GPIO85:1;                    // 21 Output Clear bit for this pin
    Uint16 GPIO86:1;                    // 22 Output Clear bit for this pin
    Uint16 GPIO87:1;                    // 23 Output Clear bit for this pin
    Uint16 GPIO88:1;                    // 24 Output Clear bit for this pin
    Uint16 GPIO89:1;                    // 25 Output Clear bit for this pin
    Uint16 GPIO90:1;                    // 26 Output Clear bit for this pin
    Uint16 GPIO91:1;                    // 27 Output Clear bit for this pin
    Uint16 GPIO92:1;                    // 28 Output Clear bit for this pin
    Uint16 GPIO93:1;                    // 29 Output Clear bit for this pin
    Uint16 GPIO94:1;                    // 30 Output Clear bit for this pin
    Uint16 GPIO95:1;                    // 31 Output Clear bit for this pin
};

union GPCCLEAR_REG {
    Uint32  all;
    struct  GPCCLEAR_BITS  bit;
};

struct GPCTOGGLE_BITS {                 // bits description
    Uint16 GPIO64:1;                    // 0 Output Toggle bit for this pin
    Uint16 GPIO65:1;                    // 1 Output Toggle bit for this pin
    Uint16 GPIO66:1;                    // 2 Output Toggle bit for this pin
    Uint16 GPIO67:1;                    // 3 Output Toggle bit for this pin
    Uint16 GPIO68:1;                    // 4 Output Toggle bit for this pin
    Uint16 GPIO69:1;                    // 5 Output Toggle bit for this pin
    Uint16 GPIO70:1;                    // 6 Output Toggle bit for this pin
    Uint16 GPIO71:1;                    // 7 Output Toggle bit for this pin
    Uint16 GPIO72:1;                    // 8 Output Toggle bit for this pin
    Uint16 GPIO73:1;                    // 9 Output Toggle bit for this pin
    Uint16 GPIO74:1;                    // 10 Output Toggle bit for this pin
    Uint16 GPIO75:1;                    // 11 Output Toggle bit for this pin
    Uint16 GPIO76:1;                    // 12 Output Toggle bit for this pin
    Uint16 GPIO77:1;                    // 13 Output Toggle bit for this pin
    Uint16 GPIO78:1;                    // 14 Output Toggle bit for this pin
    Uint16 GPIO79:1;                    // 15 Output Toggle bit for this pin
    Uint16 GPIO80:1;                    // 16 Output Toggle bit for this pin
    Uint16 GPIO81:1;                    // 17 Output Toggle bit for this pin
    Uint16 GPIO82:1;                    // 18 Output Toggle bit for this pin
    Uint16 GPIO83:1;                    // 19 Output Toggle bit for this pin
    Uint16 GPIO84:1;                    // 20 Output Toggle bit for this pin
    Uint16 GPIO85:1;                    // 21 Output Toggle bit for this pin
    Uint16 GPIO86:1;                    // 22 Output Toggle bit for this pin
    Uint16 GPIO87:1;                    // 23 Output Toggle bit for this pin
    Uint16 GPIO88:1;                    // 24 Output Toggle bit for this pin
    Uint16 GPIO89:1;                    // 25 Output Toggle bit for this pin
    Uint16 GPIO90:1;                    // 26 Output Toggle bit for this pin
    Uint16 GPIO91:1;                    // 27 Output Toggle bit for this pin
    Uint16 GPIO92:1;                    // 28 Output Toggle bit for this pin
    Uint16 GPIO93:1;                    // 29 Output Toggle bit for this pin
    Uint16 GPIO94:1;                    // 30 Output Toggle bit for this pin
    Uint16 GPIO95:1;                    // 31 Output Toggle bit for this pin
};

union GPCTOGGLE_REG {
    Uint32  all;
    struct  GPCTOGGLE_BITS  bit;
};

// GPCxxx Register
//// GPCxxx Register : Byte Value
#define GPCxxx_GPIO095									0x80000000UL
#define GPCxxx_GPIO094									0x40000000UL
#define GPCxxx_GPIO093									0x20000000UL
#define GPCxxx_GPIO092									0x10000000UL
#define GPCxxx_GPIO091									0x08000000UL
#define GPCxxx_GPIO090									0x04000000UL
#define GPCxxx_GPIO089									0x02000000UL
#define GPCxxx_GPIO088									0x01000000UL
#define GPCxxx_GPIO087									0x00800000UL
#define GPCxxx_GPIO086									0x00400000UL
#define GPCxxx_GPIO085									0x00200000UL
#define GPCxxx_GPIO084									0x00100000UL
#define GPCxxx_GPIO083									0x00080000UL
#define GPCxxx_GPIO082									0x00040000UL
#define GPCxxx_GPIO081									0x00020000UL
#define GPCxxx_GPIO080									0x00010000UL
#define GPCxxx_GPIO079									0x00008000UL
#define GPCxxx_GPIO078									0x00004000UL
#define GPCxxx_GPIO077									0x00002000UL
#define GPCxxx_GPIO076									0x00001000UL
#define GPCxxx_GPIO075									0x00000800UL
#define GPCxxx_GPIO074									0x00000400UL
#define GPCxxx_GPIO073									0x00000200UL
#define GPCxxx_GPIO072									0x00000100UL
#define GPCxxx_GPIO071									0x00000080UL
#define GPCxxx_GPIO070									0x00000040UL
#define GPCxxx_GPIO069									0x00000020UL
#define GPCxxx_GPIO068									0x00000010UL
#define GPCxxx_GPIO067									0x00000008UL
#define GPCxxx_GPIO066									0x00000004UL
#define GPCxxx_GPIO065									0x00000002UL
#define GPCxxx_GPIO064									0x00000001UL

struct GPDDAT_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Data Register for this pin
    Uint16 GPIO97:1;                    // 1 Data Register for this pin
    Uint16 GPIO98:1;                    // 2 Data Register for this pin
    Uint16 GPIO99:1;                    // 3 Data Register for this pin
    Uint16 GPIO100:1;                   // 4 Data Register for this pin
    Uint16 GPIO101:1;                   // 5 Data Register for this pin
    Uint16 GPIO102:1;                   // 6 Data Register for this pin
    Uint16 GPIO103:1;                   // 7 Data Register for this pin
    Uint16 GPIO104:1;                   // 8 Data Register for this pin
    Uint16 GPIO105:1;                   // 9 Data Register for this pin
    Uint16 GPIO106:1;                   // 10 Data Register for this pin
    Uint16 GPIO107:1;                   // 11 Data Register for this pin
    Uint16 GPIO108:1;                   // 12 Data Register for this pin
    Uint16 GPIO109:1;                   // 13 Data Register for this pin
    Uint16 GPIO110:1;                   // 14 Data Register for this pin
    Uint16 GPIO111:1;                   // 15 Data Register for this pin
    Uint16 GPIO112:1;                   // 16 Data Register for this pin
    Uint16 GPIO113:1;                   // 17 Data Register for this pin
    Uint16 GPIO114:1;                   // 18 Data Register for this pin
    Uint16 GPIO115:1;                   // 19 Data Register for this pin
    Uint16 GPIO116:1;                   // 20 Data Register for this pin
    Uint16 GPIO117:1;                   // 21 Data Register for this pin
    Uint16 GPIO118:1;                   // 22 Data Register for this pin
    Uint16 GPIO119:1;                   // 23 Data Register for this pin
    Uint16 GPIO120:1;                   // 24 Data Register for this pin
    Uint16 GPIO121:1;                   // 25 Data Register for this pin
    Uint16 GPIO122:1;                   // 26 Data Register for this pin
    Uint16 GPIO123:1;                   // 27 Data Register for this pin
    Uint16 GPIO124:1;                   // 28 Data Register for this pin
    Uint16 GPIO125:1;                   // 29 Data Register for this pin
    Uint16 GPIO126:1;                   // 30 Data Register for this pin
    Uint16 GPIO127:1;                   // 31 Data Register for this pin
};

union GPDDAT_REG {
    Uint32  all;
    struct  GPDDAT_BITS  bit;
};

struct GPDSET_BITS {                    // bits description
    Uint16 GPIO96:1;                    // 0 Output Set bit for this pin
    Uint16 GPIO97:1;                    // 1 Output Set bit for this pin
    Uint16 GPIO98:1;                    // 2 Output Set bit for this pin
    Uint16 GPIO99:1;                    // 3 Output Set bit for this pin
    Uint16 GPIO100:1;                   // 4 Output Set bit for this pin
    Uint16 GPIO101:1;                   // 5 Output Set bit for this pin
    Uint16 GPIO102:1;                   // 6 Output Set bit for this pin
    Uint16 GPIO103:1;                   // 7 Output Set bit for this pin
    Uint16 GPIO104:1;                   // 8 Output Set bit for this pin
    Uint16 GPIO105:1;                   // 9 Output Set bit for this pin
    Uint16 GPIO106:1;                   // 10 Output Set bit for this pin
    Uint16 GPIO107:1;                   // 11 Output Set bit for this pin
    Uint16 GPIO108:1;                   // 12 Output Set bit for this pin
    Uint16 GPIO109:1;                   // 13 Output Set bit for this pin
    Uint16 GPIO110:1;                   // 14 Output Set bit for this pin
    Uint16 GPIO111:1;                   // 15 Output Set bit for this pin
    Uint16 GPIO112:1;                   // 16 Output Set bit for this pin
    Uint16 GPIO113:1;                   // 17 Output Set bit for this pin
    Uint16 GPIO114:1;                   // 18 Output Set bit for this pin
    Uint16 GPIO115:1;                   // 19 Output Set bit for this pin
    Uint16 GPIO116:1;                   // 20 Output Set bit for this pin
    Uint16 GPIO117:1;                   // 21 Output Set bit for this pin
    Uint16 GPIO118:1;                   // 22 Output Set bit for this pin
    Uint16 GPIO119:1;                   // 23 Output Set bit for this pin
    Uint16 GPIO120:1;                   // 24 Output Set bit for this pin
    Uint16 GPIO121:1;                   // 25 Output Set bit for this pin
    Uint16 GPIO122:1;                   // 26 Output Set bit for this pin
    Uint16 GPIO123:1;                   // 27 Output Set bit for this pin
    Uint16 GPIO124:1;                   // 28 Output Set bit for this pin
    Uint16 GPIO125:1;                   // 29 Output Set bit for this pin
    Uint16 GPIO126:1;                   // 30 Output Set bit for this pin
    Uint16 GPIO127:1;                   // 31 Output Set bit for this pin
};

union GPDSET_REG {
    Uint32  all;
    struct  GPDSET_BITS  bit;
};

struct GPDCLEAR_BITS {                  // bits description
    Uint16 GPIO96:1;                    // 0 Output Clear bit for this pin
    Uint16 GPIO97:1;                    // 1 Output Clear bit for this pin
    Uint16 GPIO98:1;                    // 2 Output Clear bit for this pin
    Uint16 GPIO99:1;                    // 3 Output Clear bit for this pin
    Uint16 GPIO100:1;                   // 4 Output Clear bit for this pin
    Uint16 GPIO101:1;                   // 5 Output Clear bit for this pin
    Uint16 GPIO102:1;                   // 6 Output Clear bit for this pin
    Uint16 GPIO103:1;                   // 7 Output Clear bit for this pin
    Uint16 GPIO104:1;                   // 8 Output Clear bit for this pin
    Uint16 GPIO105:1;                   // 9 Output Clear bit for this pin
    Uint16 GPIO106:1;                   // 10 Output Clear bit for this pin
    Uint16 GPIO107:1;                   // 11 Output Clear bit for this pin
    Uint16 GPIO108:1;                   // 12 Output Clear bit for this pin
    Uint16 GPIO109:1;                   // 13 Output Clear bit for this pin
    Uint16 GPIO110:1;                   // 14 Output Clear bit for this pin
    Uint16 GPIO111:1;                   // 15 Output Clear bit for this pin
    Uint16 GPIO112:1;                   // 16 Output Clear bit for this pin
    Uint16 GPIO113:1;                   // 17 Output Clear bit for this pin
    Uint16 GPIO114:1;                   // 18 Output Clear bit for this pin
    Uint16 GPIO115:1;                   // 19 Output Clear bit for this pin
    Uint16 GPIO116:1;                   // 20 Output Clear bit for this pin
    Uint16 GPIO117:1;                   // 21 Output Clear bit for this pin
    Uint16 GPIO118:1;                   // 22 Output Clear bit for this pin
    Uint16 GPIO119:1;                   // 23 Output Clear bit for this pin
    Uint16 GPIO120:1;                   // 24 Output Clear bit for this pin
    Uint16 GPIO121:1;                   // 25 Output Clear bit for this pin
    Uint16 GPIO122:1;                   // 26 Output Clear bit for this pin
    Uint16 GPIO123:1;                   // 27 Output Clear bit for this pin
    Uint16 GPIO124:1;                   // 28 Output Clear bit for this pin
    Uint16 GPIO125:1;                   // 29 Output Clear bit for this pin
    Uint16 GPIO126:1;                   // 30 Output Clear bit for this pin
    Uint16 GPIO127:1;                   // 31 Output Clear bit for this pin
};

union GPDCLEAR_REG {
    Uint32  all;
    struct  GPDCLEAR_BITS  bit;
};

struct GPDTOGGLE_BITS {                 // bits description
    Uint16 GPIO96:1;                    // 0 Output Toggle bit for this pin
    Uint16 GPIO97:1;                    // 1 Output Toggle bit for this pin
    Uint16 GPIO98:1;                    // 2 Output Toggle bit for this pin
    Uint16 GPIO99:1;                    // 3 Output Toggle bit for this pin
    Uint16 GPIO100:1;                   // 4 Output Toggle bit for this pin
    Uint16 GPIO101:1;                   // 5 Output Toggle bit for this pin
    Uint16 GPIO102:1;                   // 6 Output Toggle bit for this pin
    Uint16 GPIO103:1;                   // 7 Output Toggle bit for this pin
    Uint16 GPIO104:1;                   // 8 Output Toggle bit for this pin
    Uint16 GPIO105:1;                   // 9 Output Toggle bit for this pin
    Uint16 GPIO106:1;                   // 10 Output Toggle bit for this pin
    Uint16 GPIO107:1;                   // 11 Output Toggle bit for this pin
    Uint16 GPIO108:1;                   // 12 Output Toggle bit for this pin
    Uint16 GPIO109:1;                   // 13 Output Toggle bit for this pin
    Uint16 GPIO110:1;                   // 14 Output Toggle bit for this pin
    Uint16 GPIO111:1;                   // 15 Output Toggle bit for this pin
    Uint16 GPIO112:1;                   // 16 Output Toggle bit for this pin
    Uint16 GPIO113:1;                   // 17 Output Toggle bit for this pin
    Uint16 GPIO114:1;                   // 18 Output Toggle bit for this pin
    Uint16 GPIO115:1;                   // 19 Output Toggle bit for this pin
    Uint16 GPIO116:1;                   // 20 Output Toggle bit for this pin
    Uint16 GPIO117:1;                   // 21 Output Toggle bit for this pin
    Uint16 GPIO118:1;                   // 22 Output Toggle bit for this pin
    Uint16 GPIO119:1;                   // 23 Output Toggle bit for this pin
    Uint16 GPIO120:1;                   // 24 Output Toggle bit for this pin
    Uint16 GPIO121:1;                   // 25 Output Toggle bit for this pin
    Uint16 GPIO122:1;                   // 26 Output Toggle bit for this pin
    Uint16 GPIO123:1;                   // 27 Output Toggle bit for this pin
    Uint16 GPIO124:1;                   // 28 Output Toggle bit for this pin
    Uint16 GPIO125:1;                   // 29 Output Toggle bit for this pin
    Uint16 GPIO126:1;                   // 30 Output Toggle bit for this pin
    Uint16 GPIO127:1;                   // 31 Output Toggle bit for this pin
};

union GPDTOGGLE_REG {
    Uint32  all;
    struct  GPDTOGGLE_BITS  bit;
};

// GPDxxx Register
//// GPDxxx Register : Byte Value
#define GPDxxx_GPIO127									0x80000000UL
#define GPDxxx_GPIO126									0x40000000UL
#define GPDxxx_GPIO125									0x20000000UL
#define GPDxxx_GPIO124									0x10000000UL
#define GPDxxx_GPIO123									0x08000000UL
#define GPDxxx_GPIO122									0x04000000UL
#define GPDxxx_GPIO121									0x02000000UL
#define GPDxxx_GPIO120									0x01000000UL
#define GPDxxx_GPIO119									0x00800000UL
#define GPDxxx_GPIO118									0x00400000UL
#define GPDxxx_GPIO117									0x00200000UL
#define GPDxxx_GPIO116									0x00100000UL
#define GPDxxx_GPIO115									0x00080000UL
#define GPDxxx_GPIO114									0x00040000UL
#define GPDxxx_GPIO113									0x00020000UL
#define GPDxxx_GPIO112									0x00010000UL
#define GPDxxx_GPIO111									0x00008000UL
#define GPDxxx_GPIO110									0x00004000UL
#define GPDxxx_GPIO109									0x00002000UL
#define GPDxxx_GPIO108									0x00001000UL
#define GPDxxx_GPIO107									0x00000800UL
#define GPDxxx_GPIO106									0x00000400UL
#define GPDxxx_GPIO105									0x00000200UL
#define GPDxxx_GPIO104									0x00000100UL
#define GPDxxx_GPIO103									0x00000080UL
#define GPDxxx_GPIO102									0x00000040UL
#define GPDxxx_GPIO101									0x00000020UL
#define GPDxxx_GPIO100									0x00000010UL
#define GPDxxx_GPIO099									0x00000008UL
#define GPDxxx_GPIO098									0x00000004UL
#define GPDxxx_GPIO097									0x00000002UL
#define GPDxxx_GPIO096									0x00000001UL

struct GPEDAT_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Data Register for this pin
    Uint16 GPIO129:1;                   // 1 Data Register for this pin
    Uint16 GPIO130:1;                   // 2 Data Register for this pin
    Uint16 GPIO131:1;                   // 3 Data Register for this pin
    Uint16 GPIO132:1;                   // 4 Data Register for this pin
    Uint16 GPIO133:1;                   // 5 Data Register for this pin
    Uint16 GPIO134:1;                   // 6 Data Register for this pin
    Uint16 GPIO135:1;                   // 7 Data Register for this pin
    Uint16 GPIO136:1;                   // 8 Data Register for this pin
    Uint16 GPIO137:1;                   // 9 Data Register for this pin
    Uint16 GPIO138:1;                   // 10 Data Register for this pin
    Uint16 GPIO139:1;                   // 11 Data Register for this pin
    Uint16 GPIO140:1;                   // 12 Data Register for this pin
    Uint16 GPIO141:1;                   // 13 Data Register for this pin
    Uint16 GPIO142:1;                   // 14 Data Register for this pin
    Uint16 GPIO143:1;                   // 15 Data Register for this pin
    Uint16 GPIO144:1;                   // 16 Data Register for this pin
    Uint16 GPIO145:1;                   // 17 Data Register for this pin
    Uint16 GPIO146:1;                   // 18 Data Register for this pin
    Uint16 GPIO147:1;                   // 19 Data Register for this pin
    Uint16 GPIO148:1;                   // 20 Data Register for this pin
    Uint16 GPIO149:1;                   // 21 Data Register for this pin
    Uint16 GPIO150:1;                   // 22 Data Register for this pin
    Uint16 GPIO151:1;                   // 23 Data Register for this pin
    Uint16 GPIO152:1;                   // 24 Data Register for this pin
    Uint16 GPIO153:1;                   // 25 Data Register for this pin
    Uint16 GPIO154:1;                   // 26 Data Register for this pin
    Uint16 GPIO155:1;                   // 27 Data Register for this pin
    Uint16 GPIO156:1;                   // 28 Data Register for this pin
    Uint16 GPIO157:1;                   // 29 Data Register for this pin
    Uint16 GPIO158:1;                   // 30 Data Register for this pin
    Uint16 GPIO159:1;                   // 31 Data Register for this pin
};

union GPEDAT_REG {
    Uint32  all;
    struct  GPEDAT_BITS  bit;
};

struct GPESET_BITS {                    // bits description
    Uint16 GPIO128:1;                   // 0 Output Set bit for this pin
    Uint16 GPIO129:1;                   // 1 Output Set bit for this pin
    Uint16 GPIO130:1;                   // 2 Output Set bit for this pin
    Uint16 GPIO131:1;                   // 3 Output Set bit for this pin
    Uint16 GPIO132:1;                   // 4 Output Set bit for this pin
    Uint16 GPIO133:1;                   // 5 Output Set bit for this pin
    Uint16 GPIO134:1;                   // 6 Output Set bit for this pin
    Uint16 GPIO135:1;                   // 7 Output Set bit for this pin
    Uint16 GPIO136:1;                   // 8 Output Set bit for this pin
    Uint16 GPIO137:1;                   // 9 Output Set bit for this pin
    Uint16 GPIO138:1;                   // 10 Output Set bit for this pin
    Uint16 GPIO139:1;                   // 11 Output Set bit for this pin
    Uint16 GPIO140:1;                   // 12 Output Set bit for this pin
    Uint16 GPIO141:1;                   // 13 Output Set bit for this pin
    Uint16 GPIO142:1;                   // 14 Output Set bit for this pin
    Uint16 GPIO143:1;                   // 15 Output Set bit for this pin
    Uint16 GPIO144:1;                   // 16 Output Set bit for this pin
    Uint16 GPIO145:1;                   // 17 Output Set bit for this pin
    Uint16 GPIO146:1;                   // 18 Output Set bit for this pin
    Uint16 GPIO147:1;                   // 19 Output Set bit for this pin
    Uint16 GPIO148:1;                   // 20 Output Set bit for this pin
    Uint16 GPIO149:1;                   // 21 Output Set bit for this pin
    Uint16 GPIO150:1;                   // 22 Output Set bit for this pin
    Uint16 GPIO151:1;                   // 23 Output Set bit for this pin
    Uint16 GPIO152:1;                   // 24 Output Set bit for this pin
    Uint16 GPIO153:1;                   // 25 Output Set bit for this pin
    Uint16 GPIO154:1;                   // 26 Output Set bit for this pin
    Uint16 GPIO155:1;                   // 27 Output Set bit for this pin
    Uint16 GPIO156:1;                   // 28 Output Set bit for this pin
    Uint16 GPIO157:1;                   // 29 Output Set bit for this pin
    Uint16 GPIO158:1;                   // 30 Output Set bit for this pin
    Uint16 GPIO159:1;                   // 31 Output Set bit for this pin
};

union GPESET_REG {
    Uint32  all;
    struct  GPESET_BITS  bit;
};

struct GPECLEAR_BITS {                  // bits description
    Uint16 GPIO128:1;                   // 0 Output Clear bit for this pin
    Uint16 GPIO129:1;                   // 1 Output Clear bit for this pin
    Uint16 GPIO130:1;                   // 2 Output Clear bit for this pin
    Uint16 GPIO131:1;                   // 3 Output Clear bit for this pin
    Uint16 GPIO132:1;                   // 4 Output Clear bit for this pin
    Uint16 GPIO133:1;                   // 5 Output Clear bit for this pin
    Uint16 GPIO134:1;                   // 6 Output Clear bit for this pin
    Uint16 GPIO135:1;                   // 7 Output Clear bit for this pin
    Uint16 GPIO136:1;                   // 8 Output Clear bit for this pin
    Uint16 GPIO137:1;                   // 9 Output Clear bit for this pin
    Uint16 GPIO138:1;                   // 10 Output Clear bit for this pin
    Uint16 GPIO139:1;                   // 11 Output Clear bit for this pin
    Uint16 GPIO140:1;                   // 12 Output Clear bit for this pin
    Uint16 GPIO141:1;                   // 13 Output Clear bit for this pin
    Uint16 GPIO142:1;                   // 14 Output Clear bit for this pin
    Uint16 GPIO143:1;                   // 15 Output Clear bit for this pin
    Uint16 GPIO144:1;                   // 16 Output Clear bit for this pin
    Uint16 GPIO145:1;                   // 17 Output Clear bit for this pin
    Uint16 GPIO146:1;                   // 18 Output Clear bit for this pin
    Uint16 GPIO147:1;                   // 19 Output Clear bit for this pin
    Uint16 GPIO148:1;                   // 20 Output Clear bit for this pin
    Uint16 GPIO149:1;                   // 21 Output Clear bit for this pin
    Uint16 GPIO150:1;                   // 22 Output Clear bit for this pin
    Uint16 GPIO151:1;                   // 23 Output Clear bit for this pin
    Uint16 GPIO152:1;                   // 24 Output Clear bit for this pin
    Uint16 GPIO153:1;                   // 25 Output Clear bit for this pin
    Uint16 GPIO154:1;                   // 26 Output Clear bit for this pin
    Uint16 GPIO155:1;                   // 27 Output Clear bit for this pin
    Uint16 GPIO156:1;                   // 28 Output Clear bit for this pin
    Uint16 GPIO157:1;                   // 29 Output Clear bit for this pin
    Uint16 GPIO158:1;                   // 30 Output Clear bit for this pin
    Uint16 GPIO159:1;                   // 31 Output Clear bit for this pin
};

union GPECLEAR_REG {
    Uint32  all;
    struct  GPECLEAR_BITS  bit;
};

struct GPETOGGLE_BITS {                 // bits description
    Uint16 GPIO128:1;                   // 0 Output Toggle bit for this pin
    Uint16 GPIO129:1;                   // 1 Output Toggle bit for this pin
    Uint16 GPIO130:1;                   // 2 Output Toggle bit for this pin
    Uint16 GPIO131:1;                   // 3 Output Toggle bit for this pin
    Uint16 GPIO132:1;                   // 4 Output Toggle bit for this pin
    Uint16 GPIO133:1;                   // 5 Output Toggle bit for this pin
    Uint16 GPIO134:1;                   // 6 Output Toggle bit for this pin
    Uint16 GPIO135:1;                   // 7 Output Toggle bit for this pin
    Uint16 GPIO136:1;                   // 8 Output Toggle bit for this pin
    Uint16 GPIO137:1;                   // 9 Output Toggle bit for this pin
    Uint16 GPIO138:1;                   // 10 Output Toggle bit for this pin
    Uint16 GPIO139:1;                   // 11 Output Toggle bit for this pin
    Uint16 GPIO140:1;                   // 12 Output Toggle bit for this pin
    Uint16 GPIO141:1;                   // 13 Output Toggle bit for this pin
    Uint16 GPIO142:1;                   // 14 Output Toggle bit for this pin
    Uint16 GPIO143:1;                   // 15 Output Toggle bit for this pin
    Uint16 GPIO144:1;                   // 16 Output Toggle bit for this pin
    Uint16 GPIO145:1;                   // 17 Output Toggle bit for this pin
    Uint16 GPIO146:1;                   // 18 Output Toggle bit for this pin
    Uint16 GPIO147:1;                   // 19 Output Toggle bit for this pin
    Uint16 GPIO148:1;                   // 20 Output Toggle bit for this pin
    Uint16 GPIO149:1;                   // 21 Output Toggle bit for this pin
    Uint16 GPIO150:1;                   // 22 Output Toggle bit for this pin
    Uint16 GPIO151:1;                   // 23 Output Toggle bit for this pin
    Uint16 GPIO152:1;                   // 24 Output Toggle bit for this pin
    Uint16 GPIO153:1;                   // 25 Output Toggle bit for this pin
    Uint16 GPIO154:1;                   // 26 Output Toggle bit for this pin
    Uint16 GPIO155:1;                   // 27 Output Toggle bit for this pin
    Uint16 GPIO156:1;                   // 28 Output Toggle bit for this pin
    Uint16 GPIO157:1;                   // 29 Output Toggle bit for this pin
    Uint16 GPIO158:1;                   // 30 Output Toggle bit for this pin
    Uint16 GPIO159:1;                   // 31 Output Toggle bit for this pin
};

union GPETOGGLE_REG {
    Uint32  all;
    struct  GPETOGGLE_BITS  bit;
};

// GPExxx Register
//// GPExxx Register : Byte Value
#define GPExxx_GPIO159									0x80000000UL
#define GPExxx_GPIO158									0x40000000UL
#define GPExxx_GPIO157									0x20000000UL
#define GPExxx_GPIO156									0x10000000UL
#define GPExxx_GPIO155									0x08000000UL
#define GPExxx_GPIO154									0x04000000UL
#define GPExxx_GPIO153									0x02000000UL
#define GPExxx_GPIO152									0x01000000UL
#define GPExxx_GPIO151									0x00800000UL
#define GPExxx_GPIO150									0x00400000UL
#define GPExxx_GPIO149									0x00200000UL
#define GPExxx_GPIO148									0x00100000UL
#define GPExxx_GPIO147									0x00080000UL
#define GPExxx_GPIO146									0x00040000UL
#define GPExxx_GPIO145									0x00020000UL
#define GPExxx_GPIO144									0x00010000UL
#define GPExxx_GPIO143									0x00008000UL
#define GPExxx_GPIO142									0x00004000UL
#define GPExxx_GPIO141									0x00002000UL
#define GPExxx_GPIO140									0x00001000UL
#define GPExxx_GPIO139									0x00000800UL
#define GPExxx_GPIO138									0x00000400UL
#define GPExxx_GPIO137									0x00000200UL
#define GPExxx_GPIO136									0x00000100UL
#define GPExxx_GPIO135									0x00000080UL
#define GPExxx_GPIO134									0x00000040UL
#define GPExxx_GPIO133									0x00000020UL
#define GPExxx_GPIO132									0x00000010UL
#define GPExxx_GPIO131									0x00000008UL
#define GPExxx_GPIO130									0x00000004UL
#define GPExxx_GPIO129									0x00000002UL
#define GPExxx_GPIO128									0x00000001UL

struct GPFDAT_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Data Register for this pin
    Uint16 GPIO161:1;                   // 1 Data Register for this pin
    Uint16 GPIO162:1;                   // 2 Data Register for this pin
    Uint16 GPIO163:1;                   // 3 Data Register for this pin
    Uint16 GPIO164:1;                   // 4 Data Register for this pin
    Uint16 GPIO165:1;                   // 5 Data Register for this pin
    Uint16 GPIO166:1;                   // 6 Data Register for this pin
    Uint16 GPIO167:1;                   // 7 Data Register for this pin
    Uint16 GPIO168:1;                   // 8 Data Register for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFDAT_REG {
    Uint32  all;
    struct  GPFDAT_BITS  bit;
};

struct GPFSET_BITS {                    // bits description
    Uint16 GPIO160:1;                   // 0 Output Set bit for this pin
    Uint16 GPIO161:1;                   // 1 Output Set bit for this pin
    Uint16 GPIO162:1;                   // 2 Output Set bit for this pin
    Uint16 GPIO163:1;                   // 3 Output Set bit for this pin
    Uint16 GPIO164:1;                   // 4 Output Set bit for this pin
    Uint16 GPIO165:1;                   // 5 Output Set bit for this pin
    Uint16 GPIO166:1;                   // 6 Output Set bit for this pin
    Uint16 GPIO167:1;                   // 7 Output Set bit for this pin
    Uint16 GPIO168:1;                   // 8 Output Set bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFSET_REG {
    Uint32  all;
    struct  GPFSET_BITS  bit;
};

struct GPFCLEAR_BITS {                  // bits description
    Uint16 GPIO160:1;                   // 0 Output Clear bit for this pin
    Uint16 GPIO161:1;                   // 1 Output Clear bit for this pin
    Uint16 GPIO162:1;                   // 2 Output Clear bit for this pin
    Uint16 GPIO163:1;                   // 3 Output Clear bit for this pin
    Uint16 GPIO164:1;                   // 4 Output Clear bit for this pin
    Uint16 GPIO165:1;                   // 5 Output Clear bit for this pin
    Uint16 GPIO166:1;                   // 6 Output Clear bit for this pin
    Uint16 GPIO167:1;                   // 7 Output Clear bit for this pin
    Uint16 GPIO168:1;                   // 8 Output Clear bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFCLEAR_REG {
    Uint32  all;
    struct  GPFCLEAR_BITS  bit;
};

struct GPFTOGGLE_BITS {                 // bits description
    Uint16 GPIO160:1;                   // 0 Output Toggle bit for this pin
    Uint16 GPIO161:1;                   // 1 Output Toggle bit for this pin
    Uint16 GPIO162:1;                   // 2 Output Toggle bit for this pin
    Uint16 GPIO163:1;                   // 3 Output Toggle bit for this pin
    Uint16 GPIO164:1;                   // 4 Output Toggle bit for this pin
    Uint16 GPIO165:1;                   // 5 Output Toggle bit for this pin
    Uint16 GPIO166:1;                   // 6 Output Toggle bit for this pin
    Uint16 GPIO167:1;                   // 7 Output Toggle bit for this pin
    Uint16 GPIO168:1;                   // 8 Output Toggle bit for this pin
    Uint16 rsvd1:1;                     // 9 Reserved
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:1;                     // 12 Reserved
    Uint16 rsvd5:1;                     // 13 Reserved
    Uint16 rsvd6:1;                     // 14 Reserved
    Uint16 rsvd7:1;                     // 15 Reserved
    Uint16 rsvd8:1;                     // 16 Reserved
    Uint16 rsvd9:1;                     // 17 Reserved
    Uint16 rsvd10:1;                    // 18 Reserved
    Uint16 rsvd11:1;                    // 19 Reserved
    Uint16 rsvd12:1;                    // 20 Reserved
    Uint16 rsvd13:1;                    // 21 Reserved
    Uint16 rsvd14:1;                    // 22 Reserved
    Uint16 rsvd15:1;                    // 23 Reserved
    Uint16 rsvd16:1;                    // 24 Reserved
    Uint16 rsvd17:1;                    // 25 Reserved
    Uint16 rsvd18:1;                    // 26 Reserved
    Uint16 rsvd19:1;                    // 27 Reserved
    Uint16 rsvd20:1;                    // 28 Reserved
    Uint16 rsvd21:1;                    // 29 Reserved
    Uint16 rsvd22:1;                    // 30 Reserved
    Uint16 rsvd23:1;                    // 31 Reserved
};

union GPFTOGGLE_REG {
    Uint32  all;
    struct  GPFTOGGLE_BITS  bit;
};

// GPFxxx Register
//// GPFxxx Register : Byte Value
#define GPFxxx_GPIO168									0x00000100UL
#define GPFxxx_GPIO167									0x00000080UL
#define GPFxxx_GPIO166									0x00000040UL
#define GPFxxx_GPIO165									0x00000020UL
#define GPFxxx_GPIO164									0x00000010UL
#define GPFxxx_GPIO163									0x00000008UL
#define GPFxxx_GPIO162									0x00000004UL
#define GPFxxx_GPIO161									0x00000002UL
#define GPFxxx_GPIO160									0x00000001UL

struct GPIO_DATA_REGS {
    union   GPADAT_REG                       GPADAT;                       // GPIO A Data Register (GPIO0 to 31)
    union   GPASET_REG                       GPASET;                       // GPIO A Data Set Register (GPIO0 to 31)
    union   GPACLEAR_REG                     GPACLEAR;                     // GPIO A Data Clear Register (GPIO0 to 31)
    union   GPATOGGLE_REG                    GPATOGGLE;                    // GPIO A Data Toggle Register (GPIO0 to 31) 
    union   GPBDAT_REG                       GPBDAT;                       // GPIO B Data Register (GPIO32 to 63)
    union   GPBSET_REG                       GPBSET;                       // GPIO B Data Set Register (GPIO32 to 63)
    union   GPBCLEAR_REG                     GPBCLEAR;                     // GPIO B Data Clear Register (GPIO32 to 63)
    union   GPBTOGGLE_REG                    GPBTOGGLE;                    // GPIO B Data Toggle Register (GPIO32 to 63) 
    union   GPCDAT_REG                       GPCDAT;                       // GPIO C Data Register (GPIO64 to 95)
    union   GPCSET_REG                       GPCSET;                       // GPIO C Data Set Register (GPIO64 to 95)
    union   GPCCLEAR_REG                     GPCCLEAR;                     // GPIO C Data Clear Register (GPIO64 to 95)
    union   GPCTOGGLE_REG                    GPCTOGGLE;                    // GPIO C Data Toggle Register (GPIO64 to 95) 
    union   GPDDAT_REG                       GPDDAT;                       // GPIO D Data Register (GPIO96 to 127)
    union   GPDSET_REG                       GPDSET;                       // GPIO D Data Set Register (GPIO96 to 127)
    union   GPDCLEAR_REG                     GPDCLEAR;                     // GPIO D Data Clear Register (GPIO96 to 127)
    union   GPDTOGGLE_REG                    GPDTOGGLE;                    // GPIO D Data Toggle Register (GPIO96 to 127) 
    union   GPEDAT_REG                       GPEDAT;                       // GPIO E Data Register (GPIO128 to 159)
    union   GPESET_REG                       GPESET;                       // GPIO E Data Set Register (GPIO128 to 159)
    union   GPECLEAR_REG                     GPECLEAR;                     // GPIO E Data Clear Register (GPIO128 to 159)
    union   GPETOGGLE_REG                    GPETOGGLE;                    // GPIO E Data Toggle Register (GPIO128 to 159) 
    union   GPFDAT_REG                       GPFDAT;                       // GPIO F Data Register (GPIO160 to 168)
    union   GPFSET_REG                       GPFSET;                       // GPIO F Data Set Register (GPIO160 to 168)
    union   GPFCLEAR_REG                     GPFCLEAR;                     // GPIO F Data Clear Register (GPIO160 to 168)
    union   GPFTOGGLE_REG                    GPFTOGGLE;                    // GPIO F Data Toggle Register (GPIO160 to 168) 
};

//---------------------------------------------------------------------------
// GPIO External References & Function Declarations:
//
#ifdef CPU1
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
#endif
#ifdef CPU2
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
#endif
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
