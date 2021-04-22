/*
 * FPGA_PWM.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef FPGA_PWM_H_
#define FPGA_PWM_H_

#ifdef __cplusplus
extern "C" {
#endif

// MSTCTRL Register.
//// MSTCTRL Register : Register Define.
struct FPGA_MSTCTRL_BITS {				// bits		Description.
	Uint16	PWM0SWSYNC:1;				// 0 		PWM0 Module Synchronization Signal.
	Uint16	PWM1SWSYNC:1;				// 1 		PWM1 Module Synchronization Signal.
	Uint16	PWM2SWSYNC:1;				// 2 		PWM2 Module Synchronization Signal.
	Uint16	PWM3SWSYNC:1;				// 3 		PWM3 Module Synchronization Signal.
	Uint16	PWM4SWSYNC:1;				// 4 		PWM4 Module Synchronization Signal.
	Uint16	PWM5SWSYNC:1;				// 5 		PWM5 Module Synchronization Signal.
	Uint16	PWM6SWSYNC:1;				// 6 		PWM6 Module Synchronization Signal.
	Uint16	PWM7SWSYNC:1;				// 7 		PWM7 Module Synchronization Signal.
	Uint16	PWM8SWSYNC:1;				// 8 		PWM8 Module Synchronization Signal.
	Uint16	PWM9SWSYNC:1;				// 9 		PWM9 Module Synchronization Signal.
	Uint16	PWM10SWSYNC:1;				// 10 		PWM10 Module Synchronization Signal.
	Uint16	PWM11SWSYNC:1;				// 11 		PWM11 Module Synchronization Signal.
	Uint16	rsvd0:3;					// 14:12
	Uint16	MSTCLKEN:1;					// 15		Master Clock Enable.
};

union FPGA_MSTCTRL_REG {
	Uint16						all;
	struct	FPGA_MSTCTRL_BITS	bit;
};

//// MSTCTRL Register : Byte Value.
#define MSTCTRL_SWSYNC_PWM0MDSync			0x0001
#define MSTCTRL_SWSYNC_PWM1MDSync			0x0002
#define MSTCTRL_SWSYNC_PWM2MDSync			0x0004
#define MSTCTRL_SWSYNC_PWM3MDSync			0x0008
#define MSTCTRL_SWSYNC_PWM4MDSync			0x0010
#define MSTCTRL_SWSYNC_PWM5MDSync			0x0020
#define MSTCTRL_SWSYNC_PWM6MDSync			0x0040
#define MSTCTRL_SWSYNC_PWM7MDSync			0x0080
#define MSTCTRL_SWSYNC_PWM8MDSync			0x0100
#define MSTCTRL_SWSYNC_PWM9MDSync			0x0200
#define MSTCTRL_SWSYNC_PWM10MDSync			0x0400
#define MSTCTRL_SWSYNC_PWM11MDSync			0x0800

#define MSTCTRL_MSTCLKEN_MSTCLKDis			0x0000
#define MSTCTRL_MSTCLKEN_MSTCLKEn			0x8000

// CLKEN Register.
//// CLKEN Register : Register Define.
struct FPGA_PWMEN_BITS {				// bits		Description.
	Uint16	PWM0EN:1;					// 0		PWM0 Module Clock Enable.
	Uint16	PWM1EN:1;					// 1		PWM1 Module Clock Enable.
	Uint16	PWM2EN:1;					// 2		PWM2 Module Clock Enable.
	Uint16	PWM3EN:1;					// 3		PWM3 Module Clock Enable.
	Uint16	PWM4EN:1;					// 4		PWM4 Module Clock Enable.
	Uint16	PWM5EN:1;					// 5		PWM5 Module Clock Enable.
	Uint16	PWM6EN:1;					// 6		PWM6 Module Clock Enable.
	Uint16	PWM7EN:1;					// 7		PWM7 Module Clock Enable.
	Uint16	PWM8EN:1;					// 8		PWM8 Module Clock Enable.
	Uint16	PWM9EN:1;					// 9		PWM9 Module Clock Enable.
	Uint16	PWM10EN:1;					// 10		PWM10 Module Clock Enable.
	Uint16	PWM11EN:1;					// 11		PWM11 Module Clock Enable.
	Uint16	PWM0GREN:1;					// 12		PWM0 ~ 2 Module Clock Enable.
	Uint16	PWM1GREN:1;					// 13		PWM3 ~ 5 Module Clock Enable.
	Uint16	PWM2GREN:1;					// 14		PWM6 ~ 8 Module Clock Enable.
	Uint16	PWM3GREN:1;					// 15		PWM9 ~ 11 Module Clock Enable.
};

union FPGA_PWMEN_REG {
	Uint16						all;
	struct FPGA_PWMEN_BITS		bit;
};

//// CLKEN Register : Byte Value.
#define PWMEN_PWM0EN_CLKDis					0x0000
#define PWMEN_PWM0EN_CLKEn					0x0001

#define PWMEN_PWM1EN_CLKDis					0x0000
#define PWMEN_PWM1EN_CLKEn					0x0002

#define PWMEN_PWM2EN_CLKDis					0x0000
#define PWMEN_PWM2EN_CLKEn					0x0004

#define PWMEN_PWM3EN_CLKDis					0x0000
#define PWMEN_PWM3EN_CLKEn					0x0008

#define PWMEN_PWM4EN_CLKDis					0x0000
#define PWMEN_PWM4EN_CLKEn					0x0010

#define PWMEN_PWM5EN_CLKDis					0x0000
#define PWMEN_PWM5EN_CLKEn					0x0020

#define PWMEN_PWM6EN_CLKDis					0x0000
#define PWMEN_PWM6EN_CLKEn					0x0040

#define PWMEN_PWM7EN_CLKDis					0x0000
#define PWMEN_PWM7EN_CLKEn					0x0080

#define PWMEN_PWM8EN_CLKDis					0x0000
#define PWMEN_PWM8EN_CLKEn					0x0100

#define PWMEN_PWM9EN_CLKDis					0x0000
#define PWMEN_PWM9EN_CLKEn					0x0200

#define PWMEN_PWM10EN_CLKDis				0x0000
#define PWMEN_PWM10EN_CLKEn					0x0400

#define PWMEN_PWM11EN_CLKDis				0x0000
#define PWMEN_PWM11EN_CLKEn					0x0800

#define PWMEN_PWM0GREN_CLKDis				0x0000
#define PWMEN_PWM0GREN_CLKEn				0x1000

#define PWMEN_PWM1GREN_CLKDis				0x0000
#define PWMEN_PWM1GREN_CLKEn				0x2000

#define PWMEN_PWM2GREN_CLKDis				0x0000
#define PWMEN_PWM2GREN_CLKEn				0x4000

#define PWMEN_PWM3GREN_CLKDis				0x0000
#define PWMEN_PWM3GREN_CLKEn				0x8000

// CLKSRC0 Register.
//// CLKSRC0 Register : Register Define.
struct FPGA_CLKSRC0_BITS {				// bits		Description.
	Uint16	PWM0SRC:2;					// 1:0		PWM0 Clock Source.
	Uint16	PWM1SRC:2;					// 3:2		PWM1 Clock Source.
	Uint16	PWM2SRC:2;					// 5:4		PWM2 Clock Source.
	Uint16	rsvd0:2;					// 7:6
	Uint16	PWM3SRC:2;					// 9:8		PWM3 Clock Source.
	Uint16	PWM4SRC:2;					// 11:10	PWM4 Clock Source.
	Uint16	PWM5SRC:2;					// 13:12	PWM5 Clock Source.
	Uint16	rsvd1:2;					// 15:14
};

union FPGA_CLKSRC0_REG {
	Uint16						all;
	struct FPGA_CLKSRC0_BITS	bit;
};

//// CLKSRC0 Register : Byte Value.
#define CLKSRC0_PWM0SRC_CLKDis				0x0000
#define CLKSRC0_PWM0SRC_EMIFxCLK			0x0001

#define CLKSRC0_PWM1SRC_CLKDis				0x0000
#define CLKSRC0_PWM1SRC_EMIFxCLK			0x0004

#define CLKSRC0_PWM2SRC_CLKDis				0x0000
#define CLKSRC0_PWM2SRC_EMIFxCLK			0x0010

#define CLKSRC0_PWM3SRC_CLKDis				0x0000
#define CLKSRC0_PWM3SRC_EMIFxCLK			0x0100

#define CLKSRC0_PWM4SRC_CLKDis				0x0000
#define CLKSRC0_PWM4SRC_EMIFxCLK			0x0400

#define CLKSRC0_PWM5SRC_CLKDis				0x0000
#define CLKSRC0_PWM5SRC_EMIFxCLK			0x1000

// CLKSRC1 Register.
//// CLKSRC1 Register : Register Define.
struct FPGA_CLKSRC1_BITS {				// bits		Description.
	Uint16	PWM6SRC:2;					// 1:0		PWM6 Clock Source.
	Uint16	PWM7SRC:2;					// 3:2		PWM7 Clock Source.
	Uint16	PWM8SRC:2;					// 5:4		PWM8 Clock Source.
	Uint16	rsvd0:2;					// 7:6
	Uint16	PWM9SRC:2;					// 9:8		PWM9 Clock Source.
	Uint16	PWM10SRC:2;					// 11:10	PWM10 Clock Source.
	Uint16	PWM11SRC:2;					// 13:12	PWM11 Clock Source.
	Uint16	rsvd1:2;					// 15:14
};

union FPGA_CLKSRC1_REG {
	Uint16						all;
	struct FPGA_CLKSRC1_BITS	bit;
};

//// CLKSRC0 Register : Byte Value.
#define CLKSRC1_PWM6SRC_CLKDis				0x0000
#define CLKSRC1_PWM6SRC_EMIFxCLK			0x0001

#define CLKSRC1_PWM7SRC_CLKDis				0x0000
#define CLKSRC1_PWM7SRC_EMIFxCLK			0x0004

#define CLKSRC1_PWM8SRC_CLKDis				0x0000
#define CLKSRC1_PWM8SRC_EMIFxCLK			0x0010

#define CLKSRC1_PWM9SRC_CLKDis				0x0000
#define CLKSRC1_PWM9SRC_EMIFxCLK			0x0100

#define CLKSRC1_PWM10SRC_CLKDis				0x0000
#define CLKSRC1_PWM10SRC_EMIFxCLK			0x0400

#define CLKSRC1_PWM11SRC_CLKDis				0x0000
#define CLKSRC1_PWM11SRC_EMIFxCLK			0x1000

struct FPGA_PWMCLK_REGS {									// Offset		Description
	union	FPGA_MSTCTRL_REG				MSTCTRL;		// 0x0000
	union	FPGA_PWMEN_REG					PWMEN;			// 0x0001
	union	FPGA_CLKSRC0_REG				CLKSRC0;		// 0x0002
	union	FPGA_CLKSRC1_REG				CLKSRC1;		// 0x0003
	Uint16									rsvd[12];		// 0x0004
};

// TBCTRL Register.
//// TBCTRL Register : Register Define.
struct FPGA_TBCTRL_BITS {				// bits		Description.
	Uint16	PREDIV:7;					// 6:0		Pre-Scale Divider.
	Uint16  PREEN:1;                    // 7        Pre-Scale Enable.
	Uint16	DIR:1;						// 8		Direction.
	Uint16	PHSDIR:1;					// 9		Phase Load Direction.
	Uint16	PHSEN:1;					// 10		Phase Enable.
	Uint16	rsvd0:1;					// 11
	Uint16	PRDLOADMODE:2;				// 13:12	Period Load Mode.
	Uint16	rsvd1:1;					// 14
	Uint16	RESET:1;					// 15		PWM Module Reset.
};

union FPGA_TBCTRL_REG {
	Uint16						all;
	struct FPGA_TBCTRL_BITS		bit;
};

//// TBCTRL Register : Byte Value.
#define TBCTRL_PREDIV_DIV(val)				((val >> 1) & 0x007F)

#define TBCTRL_PREEN_PREDis                 0x0000
#define TBCTRL_PREEN_PREEn                  0x0080

#define TBCTRL_DIR_UpCount					0x0000
#define TBCTRL_DIR_DownCount				0x0100

#define TBCTRL_PHSDIR_UpCount				0x0000
#define TBCTRL_PHSDIR_DownCount				0x0200

#define TBCTRL_PHSEN_PHSDis					0x0000
#define TBCTRL_PHSEN_PHSEn					0x0400

#define TBCTRL_PRDLOADMODE_Hold				0x0000
#define TBCTRL_PRDLOADMODE_Zero				0x1000

#define TBCTRL_RESET_NormalMode				0x0000
#define TBCTRL_RESET_ResetMode				0x8000

// CMPCTRL Register.
//// CMPCTRL Register : Register Define.
struct FPGA_CMPCTRL_BITS {
	Uint16	CMPALOADMODE:2;				// 1:0
	Uint16	rsvd0:2;					// 3:2
	Uint16	CMPBLOADMODE:2;				// 5:4
	Uint16	rsvd1:2;					// 7:6
	Uint16	CMPCLOADMODE:2;				// 9:8
	Uint16	rsvd2:2;					// 11:10
	Uint16	CMPDLOADMODE:2;				// 13:12
	Uint16	rsvd3:2;					// 15:14
};

union FPGA_CMPCTRL_REG {
	Uint16						all;
	struct FPGA_CMPCTRL_BITS	bit;
};

#define CMPCTRL_CMPALOADMODE_Hold			0x0000
#define CMPCTRL_CMPALOADMODE_Zero			0x0001
#define CMPCTRL_CMPALOADMODE_Period			0x0002
#define CMPCTRL_CMPALOADMODE_ZeroPeriod		0x0003

#define CMPCTRL_CMPBLOADMODE_Hold			0x0000
#define CMPCTRL_CMPBLOADMODE_Zero			0x0010
#define CMPCTRL_CMPBLOADMODE_Period			0x0020
#define CMPCTRL_CMPBLOADMODE_ZeroPeriod		0x0030

#define CMPCTRL_CMPCLOADMODE_Hold			0x0000
#define CMPCTRL_CMPCLOADMODE_Zero			0x0100
#define CMPCTRL_CMPCLOADMODE_Period			0x0200
#define CMPCTRL_CMPCLOADMODE_ZeroPeriod		0x0300

#define CMPCTRL_CMPDLOADMODE_Hold			0x0000
#define CMPCTRL_CMPDLOADMODE_Zero			0x1000
#define CMPCTRL_CMPDLOADMODE_Period			0x2000
#define CMPCTRL_CMPDLOADMODE_ZeroPeriod		0x3000

// AQCTRL Register.
//// AQCTRL Register : Register Define.
struct FPGA_AQCTRLx_BITS {
	Uint16	ZRO:2;						// 1:0
	Uint16	PRD:2;						// 3:2
	Uint16	CAU:2;						// 5:4
	Uint16	CAD:2;						// 7:6
	Uint16	CBU:2;						// 9:8
	Uint16	CBD:2;						// 11:10
	Uint16	rsvd0:2;					// 13:12
	Uint16	AQLOADMODE:2;				// 15:14
};

union FPGA_AQCTRLx_REG {
	Uint16						all;
	struct FPGA_AQCTRLx_BITS	bit;
};

//// AQCTRL Register : Byte Value.
#define AQCTRLx_ZRO_Nothing					0x0000
#define AQCTRLx_ZRO_Clear					0x0001
#define AQCTRLx_ZRO_Set						0x0002
#define AQCTRLx_ZRO_Toggle					0x0003

#define AQCTRLx_PRD_Nothing					0x0000
#define AQCTRLx_PRD_Clear					0x0004
#define AQCTRLx_PRD_Set						0x0008
#define AQCTRLx_PRD_Toggle					0x000C

#define AQCTRLx_CAU_Nothing					0x0000
#define AQCTRLx_CAU_Clear					0x0010
#define AQCTRLx_CAU_Set						0x0020
#define AQCTRLx_CAU_Toggle					0x0030

#define AQCTRLx_CAD_Nothing					0x0000
#define AQCTRLx_CAD_Clear					0x0040
#define AQCTRLx_CAD_Set						0x0080
#define AQCTRLx_CAD_Toggle					0x00C0

#define AQCTRLx_CBU_Nothing					0x0000
#define AQCTRLx_CBU_Clear					0x0100
#define AQCTRLx_CBU_Set						0x0200
#define AQCTRLx_CBU_Toggle					0x0300

#define AQCTRLx_CBD_Nothing					0x0000
#define AQCTRLx_CBD_Clear					0x0400
#define AQCTRLx_CBD_Set						0x0800
#define AQCTRLx_CBD_Toggle					0x0C00

#define AQCTRLx_AQLOADMODE_Async			0x0000
#define AQCTRLx_AQLOADMODE_Zero				0x4000
#define AQCTRLx_AQLOADMODE_Period			0x8000
#define AQCTRLx_AQLOADMODE_ZeroPeriod		0xC000

// DTCTRL Register.
//// DTCTRL Register : Register Define.
struct FPGA_DTCTRL_BITS {
	Uint16	REDIN:1;					// 0
	Uint16	FEDIN:1;					// 1
	Uint16	HLINE:2;					// 3:2
	Uint16	HINV:1;						// 4
	Uint16	HOUTEN:1;					// 5
	Uint16	HDISSTS:1;					// 6
	Uint16	LLINE:2;					// 8:7
	Uint16	LINV:1;						// 9
	Uint16	LOUTEN:1;					// 10
	Uint16	LDISSTS:1;					// 11
	Uint16	DTLOADMODE:2;				// 13:12
	Uint16	rsvd1:2;					// 15:14
};

union FPGA_DTCTRL_REG {
	Uint16						all;
	struct FPGA_DTCTRL_BITS		bit;
};

//// DTCTRL Register : Byte Value.
#define DTCTRL_REDIN_PWM0					0x0000
#define DTCTRL_REDIN_PWM1					0x0001

#define DTCTRL_FEDIN_PWM0					0x0000
#define DTCTRL_FEDIN_PWM1					0x0002

#define DTCTRL_HLINE_PWM0					0x0000
#define DTCTRL_HLINE_PWM1					0x0004
#define DTCTRL_HLINE_RED					0x0008
#define DTCTRL_HLINE_FED					0x000C

#define DTCTRL_HINV_Normal					0x0000
#define DTCTRL_HINV_Invert					0x0010

#define DTCTRL_HEN_Dis						0x0000
#define DTCTRL_HEN_En						0x0020

#define DTCTRL_HDISSTS_Low					0x0000
#define DTCTRL_HDISSTS_High					0x0040

#define DTCTRL_LLINE_PWM0					0x0000
#define DTCTRL_LLINE_PWM1					0x0080
#define DTCTRL_LLINE_RED					0x0100
#define DTCTRL_LLINE_FED					0x0180

#define DTCTRL_LINV_Normal					0x0000
#define DTCTRL_LINV_Invert					0x0200

#define DTCTRL_LEN_Dis						0x0000
#define DTCTRL_LEN_En						0x0400

#define DTCTRL_LDISSTS_Low					0x0000
#define DTCTRL_LDISSTS_High					0x0800

#define DTCTRL_DTLOADMODE_Async				0x0000
#define DTCTRL_DTLOADMODE_Zero				0x1000
#define DTCTRL_DTLOADMODE_Period			0x2000
#define DTCTRL_DTLOADMODE_ZeroPeriod		0x3000

// ETCTRL Register.
//// ETCTRL Register : Register Define.
struct FPGA_ETCTRL_BITS {
	Uint16	SOCASRC:3;					// 2:0
	Uint16	SOCBSRC:3;					// 5:3
	Uint16	SOCCSRC:3;					// 8:6
	Uint16	SOCDSRC:3;					// 11:9
	Uint16	rsvd0:2;					// 13:12
	Uint16	ETLOADMODE:2;				// 15:14
};

union FPGA_ETCTRL_REG {
	Uint16						all;
	struct FPGA_ETCTRL_BITS		bit;
};

//// ETCTRL Register : Byte Value.
#define ETCTRL_SOCASRC_None					0x0000
#define ETCTRL_SOCASRC_Zero					0x0001
#define ETCTRL_SOCASRC_Period				0x0002
#define ETCTRL_SOCASRC_CCU					0x0003
#define ETCTRL_SOCASRC_CCD					0x0004
#define ETCTRL_SOCASRC_CDU					0x0005
#define ETCTRL_SOCASRC_CDD					0x0006

#define ETCTRL_SOCBSRC_None					0x0000
#define ETCTRL_SOCBSRC_Zero					0x0008
#define ETCTRL_SOCBSRC_Period				0x0010
#define ETCTRL_SOCBSRC_CCU					0x0018
#define ETCTRL_SOCBSRC_CCD					0x0020
#define ETCTRL_SOCBSRC_CDU					0x0028
#define ETCTRL_SOCBSRC_CDD					0x0030

#define ETCTRL_SOCCSRC_None					0x0000
#define ETCTRL_SOCCSRC_Zero					0x0040
#define ETCTRL_SOCCSRC_Period				0x0080
#define ETCTRL_SOCCSRC_CCU					0x00C0
#define ETCTRL_SOCCSRC_CCD					0x0100
#define ETCTRL_SOCCSRC_CDU					0x0140
#define ETCTRL_SOCCSRC_CDD					0x0180

#define ETCTRL_SOCDSRC_None					0x0000
#define ETCTRL_SOCDSRC_Zero					0x0200
#define ETCTRL_SOCDSRC_Period				0x0400
#define ETCTRL_SOCDSRC_CCU					0x0600
#define ETCTRL_SOCDSRC_CCD					0x0800
#define ETCTRL_SOCDSRC_CDU					0x0A00
#define ETCTRL_SOCDSRC_CDD					0x0C00

#define ETCTRL_ETLOADMODE_Async				0x0000
#define ETCTRL_ETLOADMODE_Zero				0x4000
#define ETCTRL_ETLOADMODE_Period			0x8000
#define ETCTRL_ETLOADMODE_ZeroPeriod		0xC000

struct FPGA_PWM_REGS {										// Offset		Description
	union	FPGA_TBCTRL_REG					TBCTRL;			// 0x0000
	Uint16									TBCNT;			// 0x0001
	Uint16									TBPRD;			// 0x0002
	Uint16									TBPHS;			// 0x0003
	union	FPGA_CMPCTRL_REG				CMPCTRL;		// 0x0004
	Uint16									CMPA;			// 0x0005
	Uint16									CMPB;			// 0x0006
	Uint16									CMPC;			// 0x0007
	Uint16									CMPD;			// 0x0008
	union	FPGA_AQCTRLx_REG				AQCTRL0;		// 0x0009
	union	FPGA_AQCTRLx_REG				AQCTRL1;		// 0x000A
	union	FPGA_DTCTRL_REG					DTCTRL;			// 0x000B
	Uint16									REDPRD;			// 0x000C
	Uint16									FEDPRD;			// 0x000D
	union	FPGA_ETCTRL_REG					ETCTRL;			// 0x000E
	Uint16									rsvd1;			// 0x000F
};

#ifdef __cplusplus
}
#endif

#endif /* FPGA_PWM_H_ */
