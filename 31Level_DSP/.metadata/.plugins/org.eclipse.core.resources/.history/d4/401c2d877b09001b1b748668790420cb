/*
 * Define_ePWM.h
 *
 *  Created on: 2015. 8. 24.
 *      Author: cjs9426
 */

#ifndef DEFINE_EPWM_H_
#define DEFINE_EPWM_H_

#ifdef __cplusplus
extern "C" {
#endif

// Emulation Mode
#define EMUMODE_FREE						0x2			// Free Run
#define EMUMODE_SOFT						0x1			// Stop when Counter Complete a Whole Cycle
#define EMUMODE_HARD						0x0			// Stop after the next time-base counter direction changed.

// Clock Pre-scale
#define EPWM_CLK_DIV1						0x0
#define EPWM_CLK_DIV2						0x1

#define TB_DIV1								0x0
#define TB_DIV2								0x1
#define TB_DIV4								0x2
#define TB_DIV8								0x3
#define TB_DIV16							0x4
#define TB_DIV32							0x5
#define TB_DIV64							0x6
#define TB_DIV128							0x7

#define TB_HSPDIV1							0x0
#define TB_HSPDIV2							0x1
#define TB_HSPDIV4							0x2
#define TB_HSPDIV6							0x3
#define TB_HSPDIV8							0x4
#define TB_HSPDIV10							0x5
#define TB_HSPDIV12							0x6
#define TB_HSPDIV14							0x7

// Time base clock
#define TB_SHADOW							0x0
#define TB_IMMEDIATE						0x1

#define TB_DISABLE							0x0
#define TB_ENABLE							0x1

#define TB_COUNT_UP							0x0
#define TB_COUNT_DOWN						0x1
#define TB_COUNT_UPDOWN						0x2
#define TB_COUNT_DISABLE					0x3

// Compare Register
#define CC_SHADOW							0x0
#define CC_IMMEDIATE						0x1

#define CC_CTR_ZERO							0x0
#define CC_CTR_PRD							0x1
#define CC_CTR_ZERO_PRD						0x2
#define CC_CTR_DISABLE						0x3

// Action Qualifier
#define AQ_NO_ACTION						0x0
#define AQ_CLEAR							0x1
#define AQ_SET								0x2
#define AQ_TOGGLE							0x3

// Dead Band
#define DB_HALF_DISABLE						0x0
#define DB_HALF_ENABLE						0x1

#define DB_MODE_SINGLE						0x0
#define DB_MODE_DUAL						0x1

#define DB_OUTSWAP_DISABLE					0x0
#define DB_OUTSWAP_PATHA					0x1
#define DB_OUTSWAP_PATHB					0x2
#define DB_OUTSWAP_ENABLE					0x3

#define DB_IMMEDIATE						0x0
#define DB_SHADOW							0x1

#define DB_LD_ZERO							0x0
#define DB_LD_PRD							0x1
#define DB_LD_ZERO_PRD						0x2
#define DB_LD_DISABLE						0x3

#define DBA_ALL								0x0
#define DBB_RED_DBA_FED						0x1
#define DBA_RED_DBB_FED						0x2
#define DBB_ALL								0x3

#define DB_ACTV_HI							0x0
#define DB_ACTV_LOC							0x1
#define DB_ACTV_HIC							0x2
#define DB_ACTV_LO							0x3

#define DB_DISABLE							0x0
#define DBA_ENABLE							0x1
#define DBB_ENABLE							0x2
#define DB_FULL_ENABLE						0x3

// Event Trigger Select
#define	ET_CTR_ZERO							0x1
#define	ET_CTR_PRD							0x2
#define	ET_CTRU_CMPA						0x4
#define	ET_CTRD_CMPA						0x5
#define	ET_CTRU_CMPB						0x6
#define	ET_CTRD_CMPB						0x7

#define EPWMSOC_DISABLE						0x0
#define EPWMSOC_ENABLE						0x1

#define EPWMSOC_DCBEVT1						0x0
#define EPWMSOC_ZERO						0x1
#define EPWMSOC_PRD							0x2
#define EPWMSOC_ZERO_PRD					0x3
#define EPWMSOC_INCRE_AC					0x4
#define EPWMSOC_DECRE_AC					0x5
#define EPWMSOC_INCRE_BD					0x6
#define EPWMSOC_DECRE_BD					0x7

#define SOC_PRESCALE_CNT					0x0
#define SOC_PRESCALE_CNT2					0x1

#define SOC_PRD_DISABLE						0x0
#define SOC_PRD_FST							0x1
#define SOC_PRD_SND							0x2
#define SOC_PRD_TDH							0x3

// Event Trigger Pre-scaler
#define	ET_DISABLE							0x0
#define	ET_1ST								0x1
#define	ET_2ND								0x2
#define	ET_3RD								0x3

// Event Trigger Interrupt Enable
#define ET_DISABLE							0x0
#define ET_ENABLE							0x1

#define TB_BPHS_0DELAY						0x0000;
#define TB_BPHS_1DELAY						0x0002;
#define TB_BPHS_2DELAY						0x0004;
#define TB_BPHS_3DELAY						0x0006;

// Sync
#define TB_SYNC_IN							0x0
#define TB_CTR_ZERO							0x1
#define TB_CTR_CMPB							0x2
#define TB_SYNC_DISABLE						0x3

// Phase Direction Bit
#define TB_DOWN								0x0			// Count Down after the Synchronization event.
#define TB_UP								0x1			// Count Up after the Synchronization event.

// Chopping


// High resolution period


// One Shot Load mode






#endif /* DEFINE_EPWM_H_ */
