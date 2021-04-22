/*
 * AM572x_C66_IPC.h
 *
 *  Created on: 2019. 1. 8.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_AM572X_C66_IPC_H_
#define INCLUDES_AM572X_C66_AM572X_C66_IPC_H_

#ifdef __cplusplus
extern "C" {
#endif

struct IPC_FLAG_BITS {
    Uint32                  IPC_FLAG1:1;
    Uint32                  IPC_FLAG2:1;
    Uint32                  IPC_FLAG3:1;
    Uint32                  IPC_FLAG4:1;
    Uint32                  rsvd:28;
};

union IPC_FLAG_REG  {
    struct IPC_FLAG_BITS                    bit;
    Uint32                                  all;
};

extern volatile union IPC_FLAG_REG IpcFlagReg;                      // 0x8E000000


#ifdef __cpluscplus
}
#endif



#endif /* INCLUDES_AM572X_C66_AM572X_C66_IPC_H_ */
