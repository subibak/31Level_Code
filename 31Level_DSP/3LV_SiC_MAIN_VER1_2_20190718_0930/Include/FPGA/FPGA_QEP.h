/*
 * FPGA_QEP.h
 *
 *  Created on: 2019. 6. 24.
 *      Author: HJHeo
 */

#ifndef FPGA_QEP_H_
#define FPGA_QEP_H_

#ifdef __cplusplus
extern "C" {
#endif

// QEPCTRL Register.
//// QEPCTRL Register : Register Define.
struct FPGA_QEPCTRL_BITS {				// bits		Description.
	Uint16	rsvd0:10;					// 9:0
	Uint16	SEI:1;						// 10		Reset Index Event.
	Uint16	rsvd1:1;					// 11
	Uint16	PCRM:2;						// 13:12	Reset Condition.
	Uint16	rsvd2:1;					// 14
	Uint16	RESET:1;					// 15		QEP Module Reset.
};

union FPGA_QEPCTRL_REG {
	Uint16						all;
	struct FPGA_QEPCTRL_BITS	bit;
};

//// QEPCTRL Register : Byte Value.
#define QEPCTRL_SEI_REdge					0x0000
#define QEPCTRL_SEI_CWREdgeCCWFEdge			0x0400

#define QEPCTRL_PCRM_Index					0x0000
#define QEPCTRL_PCRM_MaxValue				0x1000

#define QEPCTRL_RESET_NormalMode			0x0000
#define QEPCTRL_RESET_ResetMode				0x8000

// DECCTRL Register.
//// DECCTRL Register : Register Define.
struct FPGA_DECCTRL_BITS {				// bits		Description.
	Uint16	rsvd0:8;					// 7:0
	Uint16	QIZCP:1;					// 8		IZC Signal Invert.
	Uint16	QDBBP:1;					// 9		DBB Signal Invert.
	Uint16	QCAAP:1;					// 10		CAA Signal Invert.
	Uint16	SWAP:1;						// 11		CAA and DBB Signal Swap.
	Uint16	XCR:1;						// 12		External Clock Rate.
	Uint16	rsvd1:1;					// 13
	Uint16	QSRC:2;						// 15:14	Position Count Source.
};

union FPGA_DECCTRL_REG {
	Uint16						all;
	struct FPGA_DECCTRL_BITS	bit;
};

//// DECCTRL Register : Byte Value.
#define DECCTRL_QIZCP_IZCNormal				0x0000
#define DECCTRL_QIZCP_IZCInverted			0x0100

#define DECCTRL_QDBBP_DBBNormal				0x0000
#define DECCTRL_QDBBP_DBBInverted			0x0200

#define DECCTRL_QCAAP_CAANormal				0x0000
#define DECCTRL_QCAAP_CAAInverted			0x0400

#define DECCTRL_SWAP_CAA_DBBNormal			0x0000
#define DECCTRL_SWAP_CAA_DBBSwapped			0x0800

#define DECCTRL_XCR_2xCLK					0x0000
#define DECCTRL_XCR_1xCLK					0x1000

#define DECCTRL_QSRC_DirCount				0x0000
#define DECCTRL_QSRC_Encoder				0x4000
#define DECCTRL_QSRC_BLDC					0x8000

// QEPSTS Register.
//// QEPSTS Register : Register Define.
struct FPGA_QEPSTS_BITS {				// bits		Description
	Uint16	rsvd0:14;					// 13:0
	Uint16	DEC_WARN:1;					// 14
	Uint16	DIR:1;						// 15
};

union FPGA_QEPSTS_REG {
	Uint16						all;
	struct FPGA_QEPSTS_BITS		bit;
};

struct FPGA_QEP_REGS {										// Offset		Description
	union 	FPGA_QEPCTRL_REG				QEPCTRL;		// 0x0000
	union 	FPGA_DECCTRL_REG				DECCTRL;		// 0x0001
	Uint16									QPOSCNT;		// 0x0002
	Uint16									QPOSINIT;		// 0x0003
	Uint16									QPOSMAX;		// 0x0004
	union	FPGA_QEPSTS_REG					QEPSTS;			// 0x0005
	Uint16									rsvd0[10];		// 0x0006
};

#ifdef __cplusplus
}
#endif

#endif /* FPGA_QEP_H_ */
