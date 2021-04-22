/*
 * Define_eQEP.h
 *
 *  Created on: 2017. 4. 25.
 *      Author: Seung Hwan
 */

#ifndef EQEP_H_
#define EQEP_H_

#ifdef __cplusplus
extern "C" {
#endif

// Emulation Mode
#define EMUMODE_FREE						0x2			// Free Run
#define EMUMODE_SOFT						0x1			// Stop when Counter Complete a Whole Cycle
#define EMUMODE_HARD						0x0			// Stop after the next time-base counter direction changed.

// Position Counter Reset Mode
#define PST_RESET_INDEX						0x0
#define PST_RESET_MAXIMUM					0x1
#define PST_RESET_FIRST_INDEX				0x2
#define PST_RESET_UNIT_TIME					0x3

// Position Counter Enable/Sort Reset
#define PST_DISABLE							0x0
#define PST_ENABLE							0x1

// Position Count Mode
#define PST_QUAD							0x0
#define PST_DIRT							0x1
#define PST_UP								0x2
#define PST_DOWN							0x3

// Input Inverse
#define EQEPNX_NORMAL						0x0
#define EQEPNX_INVERSE						0x1

// A/B Swap
#define EQEPAB_NORMAL						0x0
#define EQEPAB_SWAPPED						0x1

// Unit timer Latch Mode
#define UNIT_LATCH_DISABLE					0x0
#define UNIT_LATCH_ENABLE					0x1

// Unit timer Enable
#define UNIT_DISABLE						0x0
#define UNIT_ENABLE							0x1

// Watch Dog Enable
#define WATCH_DISABLE						0x0
#define WATCH_ENABLE						0x1

// Position Compare Synchro output Enable
#define SYNCH_DISABLE						0x0
#define SYNCH_ENABLE						0x1

// Compare Unit Enable
#define COMP_DISABLE						0x0
#define COMP_ENABLE							0x1

// Capture Unit Enable
#define CAPT_DISABLE						0x0
#define CAPT_ENABLE							0x1

// Capture Unit Divier
#define CAPT_DIV1							0x0
#define CAPT_DIV2							0x1
#define CAPT_DIV4							0x2
#define CAPT_DIV8							0x3
#define CAPT_DIV16							0x4
#define CAPT_DIV32							0x5
#define CAPT_DIV64							0x6
#define CAPT_DIV128							0x7

// UPEVENT
#define QCLK_1								0x0

// capture latch mode
#define READ_QPOSCNT						0x0

// QCTMR
#define TIME_QCTMR_CNT						20e-9		// When CAPT_DIV4, QCLK_1
#define TIME_QCTMR_MAX						1.31e-3		// When CAPT_DIV4, QCLK_1

#ifdef __cplusplus
}
#endif



#endif /* EQEP_H_ */
