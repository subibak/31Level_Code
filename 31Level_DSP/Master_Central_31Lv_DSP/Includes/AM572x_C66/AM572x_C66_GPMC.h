/*
 * AM572x_C66_GPMC.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef AM572X_C66_GPMC_H_
#define AM572X_C66_GPMC_H_

#ifdef __cplusplus
extern "C" {
#endif

struct GPMC_SYSCONFIG_BITS {
	Uint32	AUTOIDLE:1;
	Uint32	SOFTRESET:1;
	Uint32	rsvd0:1;
	Uint32	IDLEMODE:2;
	Uint32	rsvd1:27;
};

union GPMC_SYSCONFIG_REG {
	Uint32						all;
	struct GPMC_SYSCONFIG_BITS	bit;
};

struct GPMC_SYSSTATUS_BITS {
	Uint32	RESETDONE:1;
	Uint32	rsvd0:31;
};

union GPMC_SYSSTATUS_REG {
	Uint32						all;
	struct GPMC_SYSSTATUS_BITS	bit;
};

struct GPMC_IRQSTATUS_BITS {
    Uint32 FIFOEVENTSTATUS:1;
    Uint32 TERMINALCOUNTSTATUS:1;
    Uint32 rsvd0:2;
    Uint32 WAIT0EDGEDETECTIONSTATUS:1;
    Uint32 WAIT1EDGEDETECTIONSTATUS:1;
    Uint32 rsvd1:22;
};

union GPMC_IRQSTATUS_REG {
    Uint32                      all;
    struct GPMC_IRQSTATUS_BITS  bit;
};

struct GPMC_IRQENABLE_BITS {
    Uint32 FIFOEVENTENABLE:1;
    Uint32 TERMINALCOUNTEVENTENABLE:1;
    Uint32 rsvd0:6;
    Uint32 WAIT0EDGEDETECTIONENABLE:1;
    Uint32 WAIT1EDGEDETECTIONENABLE:1;
    Uint32 rsvd1:22;
};

union GPMC_IRQENABLE_REG {
    Uint32                      all;
    struct GPMC_IRQENABLE_BITS  bit;
 };


struct GPMC_CONFIG_BITS {
	Uint32	NANDFORCEPOSTEDWRITE:1;
	Uint32	rsvd0:7;
	Uint32	WAIT0PINPOLARITY:1;
	Uint32	WAIT1PINPOLARITY:1;
	Uint32	rsvd1:22;
};

union GPMC_CONFIG_REG {
	Uint32						all;
	struct GPMC_CONFIG_BITS		bit;
};

struct GPMC_TIMEOUT_CONTROL_BITS {
    Uint32 TIMEOUTENABLE:1;
    Uint32 rsvd0:3;
    Uint32 TIMEOUTSTARTVALUE:9;
    Uint32 rsvd1:19;
};

union GPMC_TIMEOUT_CONTROL_REG {
    Uint32                           all;
    struct GPMC_TIMEOUT_CONTROL_BITS bit;
};

struct GPMC_STATUS_BITS {
	Uint32	EMPTYWRITEBUFFERSTATUS:1;
	Uint32	rsvd0:7;
	Uint32	WAIT0STATUS:1;
	Uint32	WAIT1STATUS:1;
	Uint32	rsvd1:22;
};

union GPMC_STATUS_REG {
	Uint32						all;
	struct GPMC_STATUS_BITS		bit;
};

struct GPMC_CONFIG1_i_BITS {
	Uint32	GPMCFCLKDIVIDER:2;			// 1:0
	Uint32	rsvd0:2;					// 3:2
	Uint32	TIMEPARAGRANULARITY:1;		// 4
	Uint32	rsvd1:3;					// 7:5
	Uint32	MUXADDATA:2;				// 9:8
	Uint32	DEVICETYPE:2;				// 11:10
	Uint32	DEVICESIZE:2;				// 13:12
	Uint32	rsvd2:2;					// 15:14
	Uint32	WAITPINSELECT:2;			// 17:16
	Uint32	WAITMONITORINGTIME:2;		// 19:18
	Uint32	rsvd3:1;					// 20
	Uint32	WAITWRITEMONITORING:1;		// 21
	Uint32	WAITREADMONITORING:1;		// 22
	Uint32	ATTACHEDDEVICEPAGELENGTH:2;	// 24:23
	Uint32	CLKACTIVATIONTIME:2;		// 26:25
	Uint32	WRITETYPE:1;				// 27
	Uint32	WRITEMULTIPLE:1;			// 28
	Uint32	READTYPE:1;					// 29
	Uint32	READMULTIPLE:1;				// 30
	Uint32	WRAPBURST:1;				// 31
};

union GPMC_CONFIG1_i_REG {
	Uint32						all;
	struct GPMC_CONFIG1_i_BITS	bit;
};

struct GPMC_CONFIG2_i_BITS {
	Uint32	CSONTIME:4;
	Uint32	rsvd0:3;
	Uint32	CSEXTRADELAY:1;
	Uint32	CSRDOFFTIME:5;
	Uint32	rsvd1:3;
	Uint32	CSWROFFTIME:5;
	Uint32	rsvd2:11;
};

union GPMC_CONFIG2_i_REG {
	Uint32						all;
	struct GPMC_CONFIG2_i_BITS	bit;
};

struct GPMC_CONFIG3_i_BITS {
	Uint32	ADVONTIME:4;				// 3:0
	Uint32	ADVAADMUXONTIME:3;			// 6:4
	Uint32	ADVEXTRADELAY:1;			// 7
	Uint32	ADVRDOFFTIME:5;				// 12:8
	Uint32	rsvd0:3;					// 15:13
	Uint32	ADVWROFFTIME:5;				// 20:16
	Uint32	rsvd1:3;					// 23:21
	Uint32	ADVAADMUXRDOFFTIME:3;		// 26:24
	Uint32	rsvd2:1;					// 27
	Uint32	ADVAADMUXWROFFTIME:3;		// 30:28
	Uint32	rsvd3:1;					// 31
};

union GPMC_CONFIG3_i_REG {
	Uint32						all;
	struct GPMC_CONFIG3_i_BITS	bit;
};

struct GPMC_CONFIG4_i_BITS {
	Uint32	OEONTIME:4;					// 3:0
	Uint32	OEAADMUXONTIME:3;			// 6:4
	Uint32	OEEXTRADELAY:1;				// 7
	Uint32	OEOFFTIME:5;				// 12:8
	Uint32	OEAADMUXOFFTIME:3;			// 15:13
	Uint32	WEONTIME:4;					// 19:16
	Uint32	rsvd0:3;					// 22:20
	Uint32	WEEXTRADELAY:1;				// 23
	Uint32	WEOFFTIME:5;				// 28:24
	Uint32	rsvd1:3;					// 31:29
};

union GPMC_CONFIG4_i_REG {
	Uint32						all;
	struct GPMC_CONFIG4_i_BITS	bit;
};

struct GPMC_CONFIG5_i_BITS {
	Uint32	RDCYCLETIME:5;
	Uint32	rsvd0:3;
	Uint32	WRCYCLETIME:5;
	Uint32	rsvd1:3;
	Uint32	RDACCESSTIME:5;
	Uint32	rsvd2:3;
	Uint32	PAGEBURSTACCESSTIME:4;
	Uint32	rsvd3:4;
};

union GPMC_CONFIG5_i_REG {
	Uint32						all;
	struct GPMC_CONFIG5_i_BITS	bit;
};

struct GPMC_CONFIG6_i_BITS {
	Uint32	BUSTURNAROUND:4;			// 3:0
	Uint32	rsvd0:2;					// 5:4
	Uint32	CYCLE2CYCLEDIFFCSEN:1;		// 6
	Uint32	CYCLE2CYCLESAMECSEN:1;		// 7
	Uint32	CYCLE2CYCLEDELAY:4;			// 11:8
	Uint32	rsvd1:4;					// 15:12
	Uint32	WRDATAONADMUXBUS:4;			// 19:16
	Uint32	rsvd2:4;					// 23:20
	Uint32	WRACCESSTIME:5;				// 28:24
	Uint32	rsvd3:3;					// 31:29
};

union GPMC_CONFIG6_i_REG {
	Uint32						all;
	struct GPMC_CONFIG6_i_BITS	bit;
};

struct GPMC_CONFIG7_i_BITS {
	Uint32	BASEADDRESS:6;
	Uint32	CSVALID:1;
	Uint32	rsvd0:1;
	Uint32	MASKADDRESS:4;
	Uint32	rsvd1:20;
};

union GPMC_CONFIG7_i_REG {
	Uint32						all;
	struct GPMC_CONFIG7_i_BITS	bit;
};


struct GPMC_PREFETCH_CONFIG1_BITS {
    Uint32  ACCESSMODE:1;
    Uint32  rsvd0:1;
    Uint32  DMAMODE:1;
    Uint32  SYNCHROMODE:1;
    Uint32  WAITPINSELECTOR:2;
    Uint32  rsvd1:1;
    Uint32  ENABLEENGINE:1;
    Uint32  FIFOTHRESHOLD:7;
    Uint32  rsvd2:1;
    Uint32  PFPWWEIGHTEDPRIO:4;
    Uint32  rsvd3:3;
    Uint32  PFPWENROUNDROBIN:1;
    Uint32  ENGINECSSELECTOR:3;
    Uint32  ENABLEOPTIMIZEDACCESS:1;
    Uint32  CYCLEOPTIMIZATION:3;
    Uint32  rsvd4:1;
};

union GPMC_PREFETCH_CONFIG1_REG {
    Uint32                              all;
    struct GPMC_PREFETCH_CONFIG1_BITS   bit;
};


// -------------------- Registers Define --------------------//
struct GPMC_REGS {
	Uint32						    GPMC_REVISION;				// 0x0000
	Uint32						    rsvd0_48C[3];				// 0x0004
	union GPMC_SYSCONFIG_REG	    GPMC_SYSCONFIG;				// 0x0010
	union GPMC_SYSSTATUS_REG	    GPMC_SYSSTATUS;				// 0x0014
	union GPMC_IRQSTATUS_REG	    GPMC_IRQSTATUS;				// 0x0018
	union GPMC_IRQENABLE_REG        GPMC_IRQENABLE;				// 0x001C
	Uint32						    rsvd2[4];					// 0x0020
	Uint32						    rsvd3[4];					// 0x0030
	union GPMC_TIMEOUT_CONTROL_REG  GPMC_TIMEOUT_CONTROL;		// 0x0040
	Uint32					    	GPMC_ERR_ADDRESS;			// 0x0044
	Uint32					    	GPMC_ERR_TYPE;				// 0x0048
	Uint32					    	rsvd4_C;					// 0x004C
	union GPMC_CONFIG_REG	    	GPMC_CONFIG;				// 0x0050
	union GPMC_STATUS_REG	    	GPMC_STATUS;				// 0x0054
	Uint32						    rsvd5_8C[2];				// 0x0058
	union GPMC_CONFIG1_i_REG	    GPMC_CONFIG1_0;				// 0x0060
	union GPMC_CONFIG2_i_REG	    GPMC_CONFIG2_0;				// 0x0064
	union GPMC_CONFIG3_i_REG	    GPMC_CONFIG3_0;				// 0x0068
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_0;				// 0x006C
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_0;				// 0x0070
	union GPMC_CONFIG6_i_REG	    GPMC_CONFIG6_0;				// 0x0074
	union GPMC_CONFIG7_i_REG	    GPMC_CONFIG7_0;				// 0x0078
	Uint32						    GPMC_NAND_COMMAND_0;		// 0x007C
	Uint32						    GPMC_NAND_ADDRESS_0;		// 0x0080
	Uint32					    	GPMC_NAND_DATA_0;			// 0x0084
	Uint32						    rsvd8_8C[2];				// 0x0088
	union GPMC_CONFIG1_i_REG    	GPMC_CONFIG1_1;				// 0x0090
	union GPMC_CONFIG2_i_REG    	GPMC_CONFIG2_1;				// 0x0094
	union GPMC_CONFIG3_i_REG    	GPMC_CONFIG3_1;				// 0x0098
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_1;				// 0x009C
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_1;				// 0x00A0
	union GPMC_CONFIG6_i_REG	    GPMC_CONFIG6_1;				// 0x00A4
	union GPMC_CONFIG7_i_REG	    GPMC_CONFIG7_1;				// 0x00A8
	Uint32						    GPMC_NAND_COMMAND_1;		// 0x00AC
	Uint32					    	GPMC_NAND_ADDRESS_1;		// 0x00B0
	Uint32					    	GPMC_NAND_DATA_1;			// 0x00B4
	Uint32					    	rsvdB_8C[2];				// 0x00B8
	union GPMC_CONFIG1_i_REG    	GPMC_CONFIG1_2;				// 0x00C0
	union GPMC_CONFIG2_i_REG    	GPMC_CONFIG2_2;				// 0x00C4
	union GPMC_CONFIG3_i_REG    	GPMC_CONFIG3_2;				// 0x00C8
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_2;				// 0x00CC
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_2;				// 0x00D0
	union GPMC_CONFIG6_i_REG    	GPMC_CONFIG6_2;				// 0x00D4
	union GPMC_CONFIG7_i_REG    	GPMC_CONFIG7_2;				// 0x00D8
	Uint32					    	GPMC_NAND_COMMAND_2;		// 0x00DC
	Uint32					    	GPMC_NAND_ADDRESS_2;		// 0x00E0
	Uint32					    	GPMC_NAND_DATA_2;			// 0x00E4
	Uint32					    	rsvdE_8C[2];				// 0x00E8
	union GPMC_CONFIG1_i_REG    	GPMC_CONFIG1_3;				// 0x00F0
	union GPMC_CONFIG2_i_REG    	GPMC_CONFIG2_3;				// 0x00F4
	union GPMC_CONFIG3_i_REG    	GPMC_CONFIG3_3;				// 0x00F8
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_3;				// 0x00FC
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_3;				// 0x0100
	union GPMC_CONFIG6_i_REG    	GPMC_CONFIG6_3;				// 0x0104
	union GPMC_CONFIG7_i_REG    	GPMC_CONFIG7_3;				// 0x0108
	Uint32					       	GPMC_NAND_COMMAND_3;		// 0x010C
	Uint32					    	GPMC_NAND_ADDRESS_3;		// 0x0110
	Uint32						    GPMC_NAND_DATA_3;			// 0x0114
	Uint32					    	rsvd11_8C[2];				// 0x0118
	union GPMC_CONFIG1_i_REG    	GPMC_CONFIG1_4;				// 0x0120
	union GPMC_CONFIG2_i_REG    	GPMC_CONFIG2_4;				// 0x0124
	union GPMC_CONFIG3_i_REG    	GPMC_CONFIG3_4;				// 0x0128
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_4;				// 0x012C
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_4;				// 0x0130
	union GPMC_CONFIG6_i_REG    	GPMC_CONFIG6_4;				// 0x0134
	union GPMC_CONFIG7_i_REG    	GPMC_CONFIG7_4;				// 0x0138
	Uint32					    	GPMC_NAND_COMMAND_4;		// 0x013C
	Uint32					    	GPMC_NAND_ADDRESS_4;		// 0x0140
	Uint32					    	GPMC_NAND_DATA_4;			// 0x0144
	Uint32					    	rsvd14_8C[2];				// 0x0148
	union GPMC_CONFIG1_i_REG	    GPMC_CONFIG1_5;				// 0x0150
	union GPMC_CONFIG2_i_REG	    GPMC_CONFIG2_5;				// 0x0154
	union GPMC_CONFIG3_i_REG    	GPMC_CONFIG3_5;				// 0x0158
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_5;				// 0x015C
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_5;				// 0x0160
	union GPMC_CONFIG6_i_REG    	GPMC_CONFIG6_5;				// 0x0164
	union GPMC_CONFIG7_i_REG    	GPMC_CONFIG7_5;				// 0x0168
	Uint32					    	GPMC_NAND_COMMAND_5;		// 0x016C
	Uint32					    	GPMC_NAND_ADDRESS_5;		// 0x0170
	Uint32					    	GPMC_NAND_DATA_5;			// 0x0174
	Uint32					    	rsvd17_8C[2];				// 0x0178
	union GPMC_CONFIG1_i_REG    	GPMC_CONFIG1_6;				// 0x0180
	union GPMC_CONFIG2_i_REG    	GPMC_CONFIG2_6;				// 0x0184
	union GPMC_CONFIG3_i_REG    	GPMC_CONFIG3_6;				// 0x0188
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_6;				// 0x018C
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_6;				// 0x0190
	union GPMC_CONFIG6_i_REG    	GPMC_CONFIG6_6;				// 0x0194
	union GPMC_CONFIG7_i_REG    	GPMC_CONFIG7_6;				// 0x0198
	Uint32					    	GPMC_NAND_COMMAND_6;		// 0x019C
	Uint32					    	GPMC_NAND_ADDRESS_6;		// 0x01A0
	Uint32					    	GPMC_NAND_DATA_6;			// 0x01A4
	Uint32					    	rsvd1A_8C[2];				// 0x01A8
	union GPMC_CONFIG1_i_REG    	GPMC_CONFIG1_7;				// 0x01B0
	union GPMC_CONFIG2_i_REG    	GPMC_CONFIG2_7;				// 0x01B4
	union GPMC_CONFIG3_i_REG    	GPMC_CONFIG3_7;				// 0x01B8
	union GPMC_CONFIG4_i_REG    	GPMC_CONFIG4_7;				// 0x01BC
	union GPMC_CONFIG5_i_REG    	GPMC_CONFIG5_7;				// 0x01C0
	union GPMC_CONFIG6_i_REG    	GPMC_CONFIG6_7;				// 0x01C4
	union GPMC_CONFIG7_i_REG    	GPMC_CONFIG7_7;				// 0x01C8
	Uint32					    	GPMC_NAND_COMMAND_7;		// 0x01CC
	Uint32					    	GPMC_NAND_ADDRESS_7;		// 0x01D0
	Uint32					    	GPMC_NAND_DATA_7;			// 0x01D4
	Uint32					    	rsvd1D_8C[2];				// 0x01D8
	union GPMC_PREFETCH_CONFIG1_REG GPMC_PREFETCH_CONFIG1;		// 0x01E0
	Uint32					    	GPMC_PREFETCH_CONFIG2;		// 0x01E4
	Uint32			    			GPMC_PREFETCH_CONTROL;		// 0x01EC
	Uint32			    			GPMC_PREFETCH_STATUS;		// 0x01F0
	Uint32			    			GPMC_ECC_CONFIG;			// 0x01F4
	Uint32			    			GPMC_ECC_CONTROL;			// 0x01F8
	Uint32			    			GPMC_ECC_SIZE_CONFIG;		// 0x01FC
	Uint32			    			GPMC_ECC0_RESULT;			// 0x0200
	Uint32			    			GPMC_ECC1_RESULT;			// 0x0204
	Uint32			    			GPMC_ECC2_RESULT;			// 0x0208
	Uint32			    			GPMC_ECC3_RESULT;			// 0x020C
	Uint32			    			GPMC_ECC4_RESULT;			// 0x0210
	Uint32			    			GPMC_ECC5_RESULT;			// 0x0214
	Uint32			    			GPMC_ECC6_RESULT;			// 0x0218
	Uint32			    			GPMC_ECC7_RESULT;			// 0x021C
	Uint32				    		GPMC_ECC8_RESULT;			// 0x0220
	Uint32		    				rsvd22_48C[3];				// 0x0224
	Uint32		    				rsvd23[4];					// 0x0230
	Uint32		    				GPMC_BCH_RESULT0_0;			// 0x0240
	Uint32		    				GPMC_BCH_RESULT1_0;			// 0x0244
	Uint32		    				GPMC_BCH_RESULT2_0;			// 0x0248
	Uint32		    				GPMC_BCH_RESULT3_0;			// 0x024C
	Uint32		    				GPMC_BCH_RESULT0_1;			// 0x0250
	Uint32		    				GPMC_BCH_RESULT1_1;			// 0x0254
	Uint32		    				GPMC_BCH_RESULT2_1;			// 0x0258
	Uint32		    				GPMC_BCH_RESULT3_1;			// 0x025C
	Uint32		    				GPMC_BCH_RESULT0_2;			// 0x0260
	Uint32		    				GPMC_BCH_RESULT1_2;			// 0x0264
	Uint32		    				GPMC_BCH_RESULT2_2;			// 0x0268
	Uint32		    				GPMC_BCH_RESULT3_2;			// 0x026C
	Uint32		    				GPMC_BCH_RESULT0_3;			// 0x0270
	Uint32		    				GPMC_BCH_RESULT1_3;			// 0x0274
	Uint32		    				GPMC_BCH_RESULT2_3;			// 0x0278
	Uint32		    				GPMC_BCH_RESULT3_3;			// 0x027C
	Uint32		    				GPMC_BCH_RESULT0_4;			// 0x0280
	Uint32		    				GPMC_BCH_RESULT1_4;			// 0x0284
	Uint32		    				GPMC_BCH_RESULT2_4;			// 0x0288
	Uint32		    				GPMC_BCH_RESULT3_4;			// 0x028C
	Uint32		    				GPMC_BCH_RESULT0_5;			// 0x0290
	Uint32		    				GPMC_BCH_RESULT1_5;			// 0x0294
	Uint32		    				GPMC_BCH_RESULT2_5;			// 0x0298
	Uint32		    				GPMC_BCH_RESULT3_5;			// 0x029C
	Uint32		    				GPMC_BCH_RESULT0_6;			// 0x02A0
	Uint32		    				GPMC_BCH_RESULT1_6;			// 0x02A4
	Uint32		    				GPMC_BCH_RESULT2_6;			// 0x02A8
	Uint32		    				GPMC_BCH_RESULT3_6;			// 0x02AC
	Uint32		    				GPMC_BCH_RESULT0_7;			// 0x02B0
	Uint32		    				GPMC_BCH_RESULT1_7;			// 0x02B4
	Uint32		    				GPMC_BCH_RESULT2_7;			// 0x02B8
	Uint32		    				GPMC_BCH_RESULT3_7;			// 0x02BC
	Uint32		    				rsvd2C[4];					// 0x02C0
	Uint32			    			GPMC_BCH_SWDATA;			// 0x02D0
	Uint32		    				rsvd2D_48C[3];				// 0x02D4
	Uint32		    				rsvd2E[4];					// 0x02E0
	Uint32		    				rsvd2F[4];					// 0x02F0
	Uint32		    				GPMC_BCH_RESULT4_0;			// 0x0300
	Uint32		    				GPMC_BCH_RESULT5_0;			// 0x0304
	Uint32		    				GPMC_BCH_RESULT6_0;			// 0x0308
	Uint32		    				rsvd30_C;					// 0x030C
	Uint32		    				GPMC_BCH_RESULT4_1;			// 0x0310
	Uint32		    				GPMC_BCH_RESULT5_1;			// 0x0314
	Uint32		    				GPMC_BCH_RESULT6_1;			// 0x0318
	Uint32			    			rsvd31_C;					// 0x031C
	Uint32			    			GPMC_BCH_RESULT4_2;			// 0x0320
	Uint32			    			GPMC_BCH_RESULT5_2;			// 0x0324
	Uint32			    			GPMC_BCH_RESULT6_2;			// 0x0328
	Uint32			    			rsvd32_C;					// 0x032C
	Uint32			    			GPMC_BCH_RESULT4_3;			// 0x0330
	Uint32			    			GPMC_BCH_RESULT5_3;			// 0x0334
	Uint32			    			GPMC_BCH_RESULT6_3;			// 0x0338
	Uint32				    		rsvd33_C;					// 0x033C
	Uint32				    		GPMC_BCH_RESULT4_4;			// 0x0340
	Uint32				    		GPMC_BCH_RESULT5_4;			// 0x0344
	Uint32				    		GPMC_BCH_RESULT6_4;			// 0x0348
	Uint32				    		rsvd34_C;					// 0x034C
	Uint32				    		GPMC_BCH_RESULT4_5;			// 0x0350
	Uint32				    		GPMC_BCH_RESULT5_5;			// 0x0354
	Uint32				    		GPMC_BCH_RESULT6_5;			// 0x0358
	Uint32				    		rsvd35_C;					// 0x035C
	Uint32				    		GPMC_BCH_RESULT4_6;			// 0x0360
	Uint32				    		GPMC_BCH_RESULT5_6;			// 0x0364
	Uint32				    		GPMC_BCH_RESULT6_6;			// 0x0368
	Uint32				    		rsvd36_C;					// 0x036C
	Uint32				    		GPMC_BCH_RESULT4_7;			// 0x0370
	Uint32				    		GPMC_BCH_RESULT5_7;			// 0x0374
	Uint32				    		GPMC_BCH_RESULT6_7;			// 0x0378
};

extern volatile struct GPMC_REGS	GPMCRegs;




struct CENTRAL_TO_LEG_MASTER_MEM {
    Uint16                  Data0;              //0x00
    Uint16                  Data1;              //0x02
    Uint16                  Data2;              //0x04
    Uint16                  Data3;              //0x06
    Uint16                  Data4;              //0x08
    Uint16                  Data5;              //0x0A
    Uint16                  Data6;              //0x0C
    Uint16                  Data7;              //0x0E
    Uint16                  Data8;              //0x10
    Uint16                  Data9;              //0x12
    Uint16                  Data10;             //0x14
    Uint16                  Data11;             //0x16
    Uint16                  Data12;             //0x18
    Uint16                  Data13;             //0x1A
    Uint16                  Data14;             //0x1C
    Uint16                  Data15;             //0x1E
    Uint16                  Data16;             //0x20
    Uint16                  Data17;             //0x22
    Uint16                  Data18;             //0x24
    Uint16                  Data19;             //0x26
    Uint16                  Data20;             //0x28
    Uint16                  Data21;             //0x2A
    Uint16                  Data22;             //0x2C
    Uint16                  Data23;             //0x2E
    Uint16                  Data24;             //0x30
    Uint16                  Data25;             //0x32
    Uint16                  Data26;             //0x34
    Uint16                  Data27;             //0x36
    Uint16                  Data28;             //0x38
    Uint16                  Data29;             //0x3A
    Uint16                  Data30;             //0x3C
    Uint16                  Data31;             //0x3E
    Uint16                  Data32;             //0x40
    Uint16                  Data33;             //0x42
    Uint16                  Data34;             //0x44
    Uint16                  Data35;             //0x46
    Uint16                  Data36;             //0x48
    Uint16                  Data37;             //0x4A
    Uint16                  Data38;             //0x4C
    Uint16                  Data39;             //0x4E
};

struct CENTRAL_TO_LEG_MASTER {
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_Common;           //0x18000000
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_LEG1;             //0x18000050
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_LEG2;             //0x180000A0
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_LEG3;             //0x180000F0
    struct CENTRAL_TO_LEG_MASTER_MEM      LEG1_Central;             //0x18000140
    struct CENTRAL_TO_LEG_MASTER_MEM      LEG2_Central;             //0x18000190
    struct CENTRAL_TO_LEG_MASTER_MEM      LEG3_Central;             //0x180001E0
};

extern volatile struct CENTRAL_TO_LEG_MASTER CentralLegMaster;


struct LEG_TO_CENTRAL_MASTER {
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_Common;           //0x18000500
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_LEG1;             //0x18000550
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_LEG2;             //0x180005A0
    struct CENTRAL_TO_LEG_MASTER_MEM      Central_LEG3;             //0x180005F0
    struct CENTRAL_TO_LEG_MASTER_MEM      LEG1_Central;             //0x18000640
    struct CENTRAL_TO_LEG_MASTER_MEM      LEG2_Central;             //0x18000690
    struct CENTRAL_TO_LEG_MASTER_MEM      LEG3_Central;             //0x180006E0
};

extern struct LEG_TO_CENTRAL_MASTER LegCentralMaster;

///////////////////////////////////////////////////////////////////////////////////
// Central Master to Leg Master
struct CENTRAL_LEG_STATUS_BITS {
    Uint16              rsvd:6;                         //Slave Number
    Uint16              HMI_Page:2;                     //Mode selection, Main controller
    Uint16              Operation_Mode:4;               //PTP, BTB, Single, Test
    Uint16              Device:2;                       //Converter, Inverter
    Uint16              Switching_Method:2;             //NLC, PD
};

union CENTRAL_LEG_STATUS_DATA {
    struct CENTRAL_LEG_STATUS_BITS                     bit;
    Uint16                                             all;
};

struct CENTRAL_LEG_Operation_BITS {
    Uint16              Arm_current_Dir:2;              //Positive, Negative
    Uint16              EtherCAT_Ready:2;               //EtherCAT Ready
    Uint16              DAQ_READY:4;                    //DAQ_Ready
    Uint16              Flag_Operation:8;               //Stop, Reset, Start
};

union CENTRAL_LEG_Operation_DATA {
    struct CENTRAL_LEG_Operation_BITS                   bit;
    Uint16                                              all;
};


extern union  CENTRAL_LEG_Operation_DATA CenLegOpData_Aupper;
extern union  CENTRAL_LEG_Operation_DATA CenLegOpData_Alower;
extern union  CENTRAL_LEG_Operation_DATA CenLegOpData_Bupper;
extern union  CENTRAL_LEG_Operation_DATA CenLegOpData_Blower;
extern union  CENTRAL_LEG_Operation_DATA CenLegOpData_Cupper;
extern union  CENTRAL_LEG_Operation_DATA CenLegOpData_Clower;

struct CENTRAL_LEG_Bypass_BITS {
    Uint16              SM1_RELAY:1;
    Uint16              SM2_RELAY:1;
    Uint16              SM3_RELAY:1;
    Uint16              SM4_RELAY:1;
    Uint16              SM5_RELAY:1;
    Uint16              SM6_RELAY:1;
    Uint16              rsvd0:2;
    Uint16              SM1_IGBT:1;
    Uint16              SM2_IGBT:1;
    Uint16              SM3_IGBT:1;
    Uint16              SM4_IGBT:1;
    Uint16              SM5_IGBT:1;
    Uint16              SM6_IGBT:1;
    Uint16              rsvd1:2;
};

union CENTRAL_LEG_Bypass_DATA {
    struct CENTRAL_LEG_Bypass_BITS                      bit;
    Uint16                                              all;
};

struct CENTRAL_LEG_Bypass   {
    union CENTRAL_LEG_Bypass_DATA                       Upper1;                  // 0x0000 0000
    union CENTRAL_LEG_Bypass_DATA                       Upper2;                  // 0x0000 0002
    union CENTRAL_LEG_Bypass_DATA                       Upper3;                  // 0x0000 0004
    union CENTRAL_LEG_Bypass_DATA                       Upper4;                  // 0x0000 0006
    union CENTRAL_LEG_Bypass_DATA                       Upper5;                  // 0x0000 0008
    union CENTRAL_LEG_Bypass_DATA                       Lower1;                  // 0x0000 000A
    union CENTRAL_LEG_Bypass_DATA                       Lower2;                  // 0x0000 000C
    union CENTRAL_LEG_Bypass_DATA                       Lower3;                  // 0x0000 000E
    union CENTRAL_LEG_Bypass_DATA                       Lower4;                  // 0x0000 0010
    union CENTRAL_LEG_Bypass_DATA                       Lower5;                  // 0x0000 0012
};

extern struct CENTRAL_LEG_Bypass CenLegBypass_A;
extern struct CENTRAL_LEG_Bypass CenLegBypass_B;
extern struct CENTRAL_LEG_Bypass CenLegBypass_C;

struct CENTRAL_LEG_Slave_OP_MODE_BITS {
    Uint16                      OP_Mode:4;
    Uint16                      TEST_value:12;
};

union CENTRAL_LEG_Slave_OP_MODE_DATA {
    struct CENTRAL_LEG_Slave_OP_MODE_BITS               bit;
    Uint16                                              all;
};

struct CENTRAL_LEG_COMMON_DATA {
    union CENTRAL_LEG_STATUS_DATA                           STATUS;                     // 0x0000 0000
    Uint16                                                  SM_Vol_Under_Limit;         // 0x0000 0002
    Uint16                                                  SM_Vol_Over_Limit;          // 0x0000 0004
    Uint16                                                  SM_Temp_Limit;              // 0x0000 0006
    union CENTRAL_LEG_Slave_OP_MODE_DATA                    Slave_OP_Mode;              // 0x0000 0008
    Uint16                                                  FLASH_MSB;                  // 0x0000 000A
    Uint16                                                  FLASH_LSB;                  // 0x0000 000C
};

extern struct CENTRAL_LEG_COMMON_DATA  CenLegComm;

struct REF_BITS {
    Uint32                  LSB:16;
    Uint32                  MSB:16;
};

union REF_DATA {
    struct REF_BITS                     bit;
    Uint32                              all_U;
    float                               all_F;
};

extern union REF_DATA    NLC_REF_AU;
extern union REF_DATA    NLC_REF_AL;
extern union REF_DATA    NLC_REF_BU;
extern union REF_DATA    NLC_REF_BL;
extern union REF_DATA    NLC_REF_CU;
extern union REF_DATA    NLC_REF_CL;

struct SM_SUM_BITS {
    Uint32                  LSB:16;
    Uint32                  MSB:16;
};

union SM_SUM_DATA {
    struct SM_SUM_BITS                  bit;
    Uint32                              all_U;
    float                               all_F;
};

extern union SM_SUM_DATA    SmSumAU;
extern union SM_SUM_DATA    SmSumAL;
extern union SM_SUM_DATA    SmSumBU;
extern union SM_SUM_DATA    SmSumBL;
extern union SM_SUM_DATA    SmSumCU;
extern union SM_SUM_DATA    SmSumCL;

struct CNT_BITS {
    Uint32                  LSB:16;
    Uint32                  MSB:16;
};

union CNT_DATA {
    struct CNT_BITS         bit;
    Uint32                  all_U;
};

extern union CNT_DATA   DiffTime;
extern union CNT_DATA   DiffTimeOld
;
struct SM_FAULT_C_V_BITS {
    Uint16                  Communication:8;
    Uint16                  SM_VOLATGE:8;
};

union SM_FAULT_C_V_DATA {
    struct SM_FAULT_C_V_BITS                bit;
    Uint16                                  all;
};
struct SM_FAULT_BITS {
    union SM_FAULT_C_V_DATA                 COM_VOL;
    Uint32                                  TEMPERATURE:16;
};

union SM_FAULT_DATA {
    struct SM_FAULT_BITS                    bit;
    Uint32                                  all;
};

extern union SM_FAULT_DATA  SmFaultAU[5];
extern union SM_FAULT_DATA  SmFaultAL[5];
extern union SM_FAULT_DATA  SmFaultBU[5];
extern union SM_FAULT_DATA  SmFaultBL[5];
extern union SM_FAULT_DATA  SmFaultCU[5];
extern union SM_FAULT_DATA  SmFaultCL[5];

extern union SM_FAULT_DATA  SmFaultA;
extern union SM_FAULT_DATA  SmFaultB;
extern union SM_FAULT_DATA  SmFaultC;

#ifdef __cplusplus
}
#endif

#endif /* AM572X_C66_GPMC_H_ */
