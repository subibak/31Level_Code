/*
 * Define_Mailbox.h
 *
 *  Created on: 2019. 1. 9.
 *      Author: subi
 */

#ifndef INCLUDES_DEFINE_MAILBOX_H_
#define INCLUDES_DEFINE_MAILBOX_H_

#ifdef __cplusplus
extern "C" {
#endif

extern Uint32 MAILBOX_RD_TEST[48];
extern Uint32 MAILBOX_WR_TEST[30];
extern Uint16 b, c;

extern void Mailbox_RD(void);
extern void Mailbox_WR(void);
extern void HMI_CenMa_Matching(void);

#ifdef __cplusplus
}
#endif


#endif /* INCLUDES_DEFINE_MAILBOX_H_ */
