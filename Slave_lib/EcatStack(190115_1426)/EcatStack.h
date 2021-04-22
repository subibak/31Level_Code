/*
 * EcatStack.h
 *
 *  Created on: 2018. 11. 30.
 *      Author: PSM
 */

#ifndef ECATSTACK_ECATSTACK_H_
#define ECATSTACK_ECATSTACK_H_

#define BOOL    unsigned char
#define UINT8   unsigned char
#define UINT16  unsigned int
#define UINT32  unsigned long
#define REAL32  float

#define TRUE    1
#define FALSE   0

extern BOOL bRunApplication;

extern REAL32 Sum_v_sm;
extern UINT32 Fault_data;

extern UINT16 Status_data;
extern UINT16 Operation_data;
extern UINT16 Bypass_data;
extern UINT16 Limit_v_sm_under;
extern UINT16 Limit_v_sm_over;
extern UINT16 Limit_temperature;
extern UINT16 Slave_OP_mode;
extern UINT16 Flash_ROM_msb;
extern UINT16 Flash_ROM_lsb;
extern UINT16 Ref;

UINT8 HW_Init(void);
UINT16 MainInit(void);
void MainLoop(void);
void HW_Release(void);
extern void USER_application(void);
void ESC_ConfigureSync0GPIO(void);

#endif /* ECATSTACK_ECATSTACK_H_ */
