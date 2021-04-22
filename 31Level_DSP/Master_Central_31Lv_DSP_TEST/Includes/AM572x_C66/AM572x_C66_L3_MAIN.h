/*
 * AM572x_C66_L3_MAIN.h
 *
 *  Created on: 2018. 12. 2.
 *      Author: subi
 */

#ifndef AM572x_C66_L3_MAIN_H_
#define AM572x_C66_L3_MAIN_H_

#ifdef __cplusplus
extern "C" {
#endif

struct ERROR_LOG_BITS{
    Uint32  REQINFO_ERRLOG:12;
    Uint32  REGION_END_ERRLOG:5;
    Uint32  REGION_START_ERRLOG:5;
    Uint32  rsvd0:1;
    Uint32  BLK_BURST_VIOLATION:1;
    Uint32  rsvd1:8
};

union ERROR_LOG_REG {
    Uint32                              all;
    struct ERROR_LOG_BITS               bit;
};


#ifdef _cplusplus
extern }
#endif

#endif
