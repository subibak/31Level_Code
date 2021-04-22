/*
 * FPGA_SPI.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef FPGA_SPI_H_
#define FPGA_SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

// SPI Register Define
//// SPI Register Define : SPICFG
struct FPGA_SPICFG_BITS {				// bits	Description.
	Uint16	CHAR:4;						// 3:0	SPI TX Data Length.			(CHAR + 1) bit.						- Change is Allowed when SWRESET = 1
	Uint16	CLK_POL:1;					// 4	SPI Clock Polarity.			0(Active High), 1(Active Low).		- Change is Allowed when SWRESET = 1
	Uint16	CLK_PHA:1;					// 5	SPI Clock Phase.			0(Without Delay), 1(With Delay).	- Change is Allowed when SWRESET = 1
	Uint16	rsvd0:2;					// 7:6
	Uint16	MST_SLV:1;					// 8	SPI Master/Slave.			0(Slave), 1(Master).				- Read Only.
	Uint16	TALK:1;						// 9	SPI TX Enable.				0(Disable), 1(Enable).				- Change is Allowed when SWRESET = 1
	Uint16	LPB:1;						// 10	SPI LoopBack Mode			0(Normal Mode), 1(LoopBack Mode).	- Change is Allowed when SWRESET = 1
	Uint16	rsvd1:4;					// 14:9
	Uint16	SWRESET:1;					// 15	SPI Software Reset.			0(Normal Mode), 1(Configure Mode).
};

union FPGA_SPICFG_REG {
	Uint16	all;
	struct 	FPGA_SPICFG_BITS	bit;
};

// SPICFG Register.
#define SPICFG_CHAR_Length(len)				((len - 1) & 0x000F)

#define SPICFG_CLK_POL_ACTVHigh				0x0000
#define SPICFG_CLK_POL_ACTVLow				0x0010

#define SPICFG_CLK_PHA_Normal				0x0000
#define SPICFG_CLK_PHA_Delayed				0x0020

#define SPICFG_MST_SLV_Slave				0x0000
#define SPICFG_MST_SLV_Master				0x0100

#define SPICFG_TALK_TxDisable				0x0000
#define SPICFG_TALK_TxEnable				0x0200

#define SPICFG_LPB_LoopBackDisable			0x0000
#define SPICFG_LPB_LoopBackEnable			0x0400

#define SPICFG_SWRESET_ReadyMode			0x0000
#define SPICFG_SWRESET_ResetMode			0x8000

//// SPI Register Define : SPICSC
struct FPGA_SPICSC_BITS {				// bits	Description.
	Uint16	CSSET0_CS0EN:1;				// 0	CS Set 0 CS0 Enable.		0(Disable), 1(Enable).
	Uint16	CSSET0_CS1EN:1;				// 1	CS Set 0 CS1 Enable.		0(Disable), 1(Enable).
	Uint16	CSSET0_CS2EN:1;				// 2	CS Set 0 CS2 Enable.		0(Disable), 1(Enable).
	Uint16	CSSET0_CS3EN:1;				// 3	CS Set 0 CS3 Enable.		0(Disable), 1(Enable).
	Uint16	CSSET1_CS0EN:1;				// 4	CS Set 1 CS0 Enable.		0(Disable), 1(Enable).
	Uint16	CSSET1_CS1EN:1;				// 5	CS Set 1 CS1 Enable.		0(Disable), 1(Enable).
	Uint16	CSSET1_CS2EN:1;				// 6	CS Set 1 CS2 Enable.		0(Disable), 1(Enable).
	Uint16	CSSET1_CS3EN:1;				// 7	CS Set 1 CS3 Enable.		0(Disable), 1(Enable).
	Uint16	CS0POL:1;					// 8	Chip Select 0 Polarity.		0(Active High), 1(Active Low).
	Uint16	CS1POL:1;					// 9	Chip Select 0 Polarity.		0(Active High), 1(Active Low).
	Uint16	CS2POL:1;					// 10	Chip Select 0 Polarity.		0(Active High), 1(Active Low).
	Uint16	CS3POL:1;					// 11	Chip Select 0 Polarity.		0(Active High), 1(Active Low).
	Uint16	rsvd0:4;					// 15:12
};

union FPGA_SPICSC_REG {
	Uint16	all;
	struct	FPGA_SPICSC_BITS	bit;
};

#define SPICSC_CSSET0_CS0Disable			0x0000
#define SPICSC_CSSET0_CS0Enable				0x0001

#define SPICSC_CSSET0_CS1Disable			0x0000
#define SPICSC_CSSET0_CS1Enable				0x0002

#define SPICSC_CSSET0_CS2Disable			0x0000
#define SPICSC_CSSET0_CS2Enable				0x0004

#define SPICSC_CSSET0_CS3Disable			0x0000
#define SPICSC_CSSET0_CS3Enable				0x0008

#define SPICSC_CSSET1_CS0Disable			0x0000
#define SPICSC_CSSET1_CS0Enable				0x0010

#define SPICSC_CSSET1_CS1Disable			0x0000
#define SPICSC_CSSET1_CS1Enable				0x0020

#define SPICSC_CSSET1_CS2Disable			0x0000
#define SPICSC_CSSET1_CS2Enable				0x0040

#define SPICSC_CSSET1_CS3Disable			0x0000
#define SPICSC_CSSET1_CS3Enable				0x0080

#define SPICSC_CS0POL_CS0ACTVHigh			0x0000
#define SPICSC_CS0POL_CS0ACTVLow			0x0100

#define SPICSC_CS1POL_CS1ACTVHigh			0x0000
#define SPICSC_CS1POL_CS1ACTVLow			0x0200

#define SPICSC_CS2POL_CS2ACTVHigh			0x0000
#define SPICSC_CS2POL_CS2ACTVLow			0x0400

#define SPICSC_CS3POL_CS3ACTVHigh			0x0000
#define SPICSC_CS3POL_CS3ACTVLow			0x0800

//// SPI Register Define : SPIFFD
struct FPGA_SPIDLY_BITS {				// bits	Description.
	Uint16	DELAY:5;					// 4:0	TX to TX Delay.				DELAY x SPICLK Delay.
	Uint16	rsvd0:11;					// 15:5
};

union FPGA_SPIDLY_REG {
	Uint16	all;
	struct	FPGA_SPIDLY_BITS	bit;
};

//// SPI Register Define : SPISTS
struct FPGA_SPISTS_BITS {				// bits	Description.
	Uint16	CSSET0_DAT0_RX:1;			// 0	CSSET0_DAT0 Data Kinds.		0(TX), 1(RX).
	Uint16	CSSET0_DAT1_RX:1;			// 1	CSSET0_DAT1 Data Kinds.		0(TX), 1(RX).
	Uint16	CSSET0_DAT2_RX:1;			// 2	CSSET0_DAT2 Data Kinds.		0(TX), 1(RX).
	Uint16	CSSET0_DAT3_RX:1;			// 3	CSSET0_DAT3 Data Kinds.		0(TX), 1(RX).
	Uint16	CSSET1_DAT0_RX:1;			// 4	CSSET1_DAT0 Data Kinds.		0(TX), 1(RX).
	Uint16	CSSET1_DAT1_RX:1;			// 5	CSSET1_DAT1 Data Kinds.		0(TX), 1(RX).
	Uint16	CSSET1_DAT2_RX:1;			// 6	CSSET1_DAT2 Data Kinds.		0(TX), 1(RX).
	Uint16	CSSET1_DAT3_RX:1;			// 7	CSSET1_DAT3 Data Kinds.		0(TX), 1(RX).
	Uint16	rsvd0:8;					// 15:8
};

union FPGA_SPISTS_REG {
	Uint16	all;
	struct	FPGA_SPISTS_BITS	bit;
};

struct FPGA_SPI_REGS {										// Offset		Description
	union	FPGA_SPICFG_REG					CFG;			// 0x0000 0000	SPI Configuration Register.
	Uint16									BRR;			// 0x0000 0001	SPI Baud Rate Register. 		SPICLK = EMIFxCLK / (BRR + 1). Minimum Value is 9.
	union	FPGA_SPICSC_REG					CSC;			// 0x0000 0002	SPI Chip Select Control.
	union	FPGA_SPIDLY_REG					DLY;			// 0x0000 0003	SPI TX to TX Delay.
	union	FPGA_SPISTS_REG					STS;			// 0x0000 0004	SPI RX/TX Status.
	Uint16									CSSET0_DAT0;	// 0x0000 0005	SPI CS SET 0 DAT0.
	Uint16									CSSET0_DAT1;	// 0x0000 0006	SPI CS SET 0 DAT1.
	Uint16									CSSET0_DAT2;	// 0x0000 0007	SPI CS SET 0 DAT2.
	Uint16									CSSET0_DAT3;	// 0x0000 0008	SPI CS SET 0 DAT3.
	Uint16									CSSET1_DAT0;	// 0x0000 0009	SPI CS SET 1 DAT0.
	Uint16									CSSET1_DAT1;	// 0x0000 000A	SPI CS SET 1 DAT1.
	Uint16									CSSET1_DAT2;	// 0x0000 000B	SPI CS SET 1 DAT2.
	Uint16									CSSET1_DAT3;	// 0x0000 000C	SPI CS SET 1 DAT3.
	Uint16									rsvd0[3];		// 0x0000 000D
};

#ifdef __cplusplus
}
#endif

#endif /* FPGA_SPI_H_ */
