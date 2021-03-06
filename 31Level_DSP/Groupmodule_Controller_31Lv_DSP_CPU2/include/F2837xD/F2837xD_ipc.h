//###########################################################################
//
// FILE:    F2837xD_ipc.h
//
// TITLE:   F2837xD Device IPC Register Definitions.
//
//###########################################################################
// $TI Release: F2837xD Support Library v210 $
// $Release Date: Tue Nov  1 14:46:15 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef __F2837xD_IPC_H__
#define __F2837xD_IPC_H__

#ifdef __cplusplus
extern "C" {
#endif

#define STATUS_FAIL                     0x0001
#define STATUS_PASS                     0x0000

#define IPC_BUFFER_SIZE             4     // # of tIpcMessage messages in
                                          // circular buffer
                                          // (must be interval of 2)
#define NUM_IPC_INTERRUPTS          4     // # of IPC interrupts using circular
                                          // buffer
                                          // (must be same number on both CPUs
#define MAX_BUFFER_INDEX            IPC_BUFFER_SIZE - 1




//---------------------------------------------------------------------------
// IPC Individual Register Bit Definitions:

struct IPCACK_BITS {                    // bits description
    Uint16 IPC0:1;                      // 0 Local IPC Flag 0 Acknowledgement
    Uint16 IPC1:1;                      // 1 Local IPC Flag 1 Acknowledgement
    Uint16 IPC2:1;                      // 2 Local IPC Flag 2 Acknowledgement
    Uint16 IPC3:1;                      // 3 Local IPC Flag 3 Acknowledgement
    Uint16 IPC4:1;                      // 4 Local IPC Flag 4 Acknowledgement
    Uint16 IPC5:1;                      // 5 Local IPC Flag 5 Acknowledgement
    Uint16 IPC6:1;                      // 6 Local IPC Flag 6 Acknowledgement
    Uint16 IPC7:1;                      // 7 Local IPC Flag 7 Acknowledgement
    Uint16 IPC8:1;                      // 8 Local IPC Flag 8 Acknowledgement
    Uint16 IPC9:1;                      // 9 Local IPC Flag 9 Acknowledgement
    Uint16 IPC10:1;                     // 10 Local IPC Flag 10 Acknowledgement
    Uint16 IPC11:1;                     // 11 Local IPC Flag 11 Acknowledgement
    Uint16 IPC12:1;                     // 12 Local IPC Flag 12 Acknowledgement
    Uint16 IPC13:1;                     // 13 Local IPC Flag 13 Acknowledgement
    Uint16 IPC14:1;                     // 14 Local IPC Flag 14 Acknowledgement
    Uint16 IPC15:1;                     // 15 Local IPC Flag 15 Acknowledgement
    Uint16 IPC16:1;                     // 16 Local IPC Flag 16 Acknowledgement
    Uint16 IPC17:1;                     // 17 Local IPC Flag 17 Acknowledgement
    Uint16 IPC18:1;                     // 18 Local IPC Flag 18 Acknowledgement
    Uint16 IPC19:1;                     // 19 Local IPC Flag 19 Acknowledgement
    Uint16 IPC20:1;                     // 20 Local IPC Flag 20 Acknowledgement
    Uint16 IPC21:1;                     // 21 Local IPC Flag 21 Acknowledgement
    Uint16 IPC22:1;                     // 22 Local IPC Flag 22 Acknowledgement
    Uint16 IPC23:1;                     // 23 Local IPC Flag 23 Acknowledgement
    Uint16 IPC24:1;                     // 24 Local IPC Flag 24 Acknowledgement
    Uint16 IPC25:1;                     // 25 Local IPC Flag 25 Acknowledgement
    Uint16 IPC26:1;                     // 26 Local IPC Flag 26 Acknowledgement
    Uint16 IPC27:1;                     // 27 Local IPC Flag 27 Acknowledgement
    Uint16 IPC28:1;                     // 28 Local IPC Flag 28 Acknowledgement
    Uint16 IPC29:1;                     // 29 Local IPC Flag 29 Acknowledgement
    Uint16 IPC30:1;                     // 30 Local IPC Flag 30 Acknowledgement
    Uint16 IPC31:1;                     // 31 Local IPC Flag 31 Acknowledgement
};

union IPCACK_REG {
    Uint32  all;
    struct  IPCACK_BITS  bit;
};

struct IPCSTS_BITS {                    // bits description
    Uint16 IPC0:1;                      // 0 Local IPC Flag 0 Status
    Uint16 IPC1:1;                      // 1 Local IPC Flag 1 Status
    Uint16 IPC2:1;                      // 2 Local IPC Flag 2 Status
    Uint16 IPC3:1;                      // 3 Local IPC Flag 3 Status
    Uint16 IPC4:1;                      // 4 Local IPC Flag 4 Status
    Uint16 IPC5:1;                      // 5 Local IPC Flag 5 Status
    Uint16 IPC6:1;                      // 6 Local IPC Flag 6 Status
    Uint16 IPC7:1;                      // 7 Local IPC Flag 7 Status
    Uint16 IPC8:1;                      // 8 Local IPC Flag 8 Status
    Uint16 IPC9:1;                      // 9 Local IPC Flag 9 Status
    Uint16 IPC10:1;                     // 10 Local IPC Flag 10 Status
    Uint16 IPC11:1;                     // 11 Local IPC Flag 11 Status
    Uint16 IPC12:1;                     // 12 Local IPC Flag 12 Status
    Uint16 IPC13:1;                     // 13 Local IPC Flag 13 Status
    Uint16 IPC14:1;                     // 14 Local IPC Flag 14 Status
    Uint16 IPC15:1;                     // 15 Local IPC Flag 15 Status
    Uint16 IPC16:1;                     // 16 Local IPC Flag 16 Status
    Uint16 IPC17:1;                     // 17 Local IPC Flag 17 Status
    Uint16 IPC18:1;                     // 18 Local IPC Flag 18 Status
    Uint16 IPC19:1;                     // 19 Local IPC Flag 19 Status
    Uint16 IPC20:1;                     // 20 Local IPC Flag 20 Status
    Uint16 IPC21:1;                     // 21 Local IPC Flag 21 Status
    Uint16 IPC22:1;                     // 22 Local IPC Flag 22 Status
    Uint16 IPC23:1;                     // 23 Local IPC Flag 23 Status
    Uint16 IPC24:1;                     // 24 Local IPC Flag 24 Status
    Uint16 IPC25:1;                     // 25 Local IPC Flag 25 Status
    Uint16 IPC26:1;                     // 26 Local IPC Flag 26 Status
    Uint16 IPC27:1;                     // 27 Local IPC Flag 27 Status
    Uint16 IPC28:1;                     // 28 Local IPC Flag 28 Status
    Uint16 IPC29:1;                     // 29 Local IPC Flag 29 Status
    Uint16 IPC30:1;                     // 30 Local IPC Flag 30 Status
    Uint16 IPC31:1;                     // 31 Local IPC Flag 31 Status
};

union IPCSTS_REG {
    Uint32  all;
    struct  IPCSTS_BITS  bit;
};

struct IPCSET_BITS {                    // bits description
    Uint16 IPC0:1;                      // 0 Set Remote IPC0 Flag
    Uint16 IPC1:1;                      // 1 Set Remote IPC1 Flag
    Uint16 IPC2:1;                      // 2 Set Remote IPC2 Flag
    Uint16 IPC3:1;                      // 3 Set Remote IPC3 Flag
    Uint16 IPC4:1;                      // 4 Set Remote IPC4 Flag
    Uint16 IPC5:1;                      // 5 Set Remote IPC5 Flag
    Uint16 IPC6:1;                      // 6 Set Remote IPC6 Flag
    Uint16 IPC7:1;                      // 7 Set Remote IPC7 Flag
    Uint16 IPC8:1;                      // 8 Set Remote IPC8 Flag
    Uint16 IPC9:1;                      // 9 Set Remote IPC9 Flag
    Uint16 IPC10:1;                     // 10 Set Remote IPC10 Flag
    Uint16 IPC11:1;                     // 11 Set Remote IPC11 Flag
    Uint16 IPC12:1;                     // 12 Set Remote IPC12 Flag
    Uint16 IPC13:1;                     // 13 Set Remote IPC13 Flag
    Uint16 IPC14:1;                     // 14 Set Remote IPC14 Flag
    Uint16 IPC15:1;                     // 15 Set Remote IPC15 Flag
    Uint16 IPC16:1;                     // 16 Set Remote IPC16 Flag
    Uint16 IPC17:1;                     // 17 Set Remote IPC17 Flag
    Uint16 IPC18:1;                     // 18 Set Remote IPC18 Flag
    Uint16 IPC19:1;                     // 19 Set Remote IPC19 Flag
    Uint16 IPC20:1;                     // 20 Set Remote IPC20 Flag
    Uint16 IPC21:1;                     // 21 Set Remote IPC21 Flag
    Uint16 IPC22:1;                     // 22 Set Remote IPC22 Flag
    Uint16 IPC23:1;                     // 23 Set Remote IPC23 Flag
    Uint16 IPC24:1;                     // 24 Set Remote IPC24 Flag
    Uint16 IPC25:1;                     // 25 Set Remote IPC25 Flag
    Uint16 IPC26:1;                     // 26 Set Remote IPC26 Flag
    Uint16 IPC27:1;                     // 27 Set Remote IPC27 Flag
    Uint16 IPC28:1;                     // 28 Set Remote IPC28 Flag
    Uint16 IPC29:1;                     // 29 Set Remote IPC29 Flag
    Uint16 IPC30:1;                     // 30 Set Remote IPC30 Flag
    Uint16 IPC31:1;                     // 31 Set Remote IPC31 Flag
};

union IPCSET_REG {
    Uint32  all;
    struct  IPCSET_BITS  bit;
};

struct IPCCLR_BITS {                    // bits description
    Uint16 IPC0:1;                      // 0 Clear Remote IPC0 Flag
    Uint16 IPC1:1;                      // 1 Clear Remote IPC1 Flag
    Uint16 IPC2:1;                      // 2 Clear Remote IPC2 Flag
    Uint16 IPC3:1;                      // 3 Clear Remote IPC3 Flag
    Uint16 IPC4:1;                      // 4 Clear Remote IPC4 Flag
    Uint16 IPC5:1;                      // 5 Clear Remote IPC5 Flag
    Uint16 IPC6:1;                      // 6 Clear Remote IPC6 Flag
    Uint16 IPC7:1;                      // 7 Clear Remote IPC7 Flag
    Uint16 IPC8:1;                      // 8 Clear Remote IPC8 Flag
    Uint16 IPC9:1;                      // 9 Clear Remote IPC9 Flag
    Uint16 IPC10:1;                     // 10 Clear Remote IPC10 Flag
    Uint16 IPC11:1;                     // 11 Clear Remote IPC11 Flag
    Uint16 IPC12:1;                     // 12 Clear Remote IPC12 Flag
    Uint16 IPC13:1;                     // 13 Clear Remote IPC13 Flag
    Uint16 IPC14:1;                     // 14 Clear Remote IPC14 Flag
    Uint16 IPC15:1;                     // 15 Clear Remote IPC15 Flag
    Uint16 IPC16:1;                     // 16 Clear Remote IPC16 Flag
    Uint16 IPC17:1;                     // 17 Clear Remote IPC17 Flag
    Uint16 IPC18:1;                     // 18 Clear Remote IPC18 Flag
    Uint16 IPC19:1;                     // 19 Clear Remote IPC19 Flag
    Uint16 IPC20:1;                     // 20 Clear Remote IPC20 Flag
    Uint16 IPC21:1;                     // 21 Clear Remote IPC21 Flag
    Uint16 IPC22:1;                     // 22 Clear Remote IPC22 Flag
    Uint16 IPC23:1;                     // 23 Clear Remote IPC23 Flag
    Uint16 IPC24:1;                     // 24 Clear Remote IPC24 Flag
    Uint16 IPC25:1;                     // 25 Clear Remote IPC25 Flag
    Uint16 IPC26:1;                     // 26 Clear Remote IPC26 Flag
    Uint16 IPC27:1;                     // 27 Clear Remote IPC27 Flag
    Uint16 IPC28:1;                     // 28 Clear Remote IPC28 Flag
    Uint16 IPC29:1;                     // 29 Clear Remote IPC29 Flag
    Uint16 IPC30:1;                     // 30 Clear Remote IPC30 Flag
    Uint16 IPC31:1;                     // 31 Clear Remote IPC31 Flag
};

union IPCCLR_REG {
    Uint32  all;
    struct  IPCCLR_BITS  bit;
};

struct IPCFLG_BITS {                    // bits description
    Uint16 IPC0:1;                      // 0 Remote IPC0 Flag Status
    Uint16 IPC1:1;                      // 1 Remote IPC1 Flag Status
    Uint16 IPC2:1;                      // 2 Remote IPC2 Flag Status
    Uint16 IPC3:1;                      // 3 Remote IPC3 Flag Status
    Uint16 IPC4:1;                      // 4 Remote IPC4 Flag Status
    Uint16 IPC5:1;                      // 5 Remote IPC5 Flag Status
    Uint16 IPC6:1;                      // 6 Remote IPC6 Flag Status
    Uint16 IPC7:1;                      // 7 Remote IPC7 Flag Status
    Uint16 IPC8:1;                      // 8 Remote IPC8 Flag Status
    Uint16 IPC9:1;                      // 9 Remote IPC9 Flag Status
    Uint16 IPC10:1;                     // 10 Remote IPC10 Flag Status
    Uint16 IPC11:1;                     // 11 Remote IPC11 Flag Status
    Uint16 IPC12:1;                     // 12 Remote IPC12 Flag Status
    Uint16 IPC13:1;                     // 13 Remote IPC13 Flag Status
    Uint16 IPC14:1;                     // 14 Remote IPC14 Flag Status
    Uint16 IPC15:1;                     // 15 Remote IPC15 Flag Status
    Uint16 IPC16:1;                     // 16 Remote IPC16 Flag Status
    Uint16 IPC17:1;                     // 17 Remote IPC17 Flag Status
    Uint16 IPC18:1;                     // 18 Remote IPC18 Flag Status
    Uint16 IPC19:1;                     // 19 Remote IPC19 Flag Status
    Uint16 IPC20:1;                     // 20 Remote IPC20 Flag Status
    Uint16 IPC21:1;                     // 21 Remote IPC21 Flag Status
    Uint16 IPC22:1;                     // 22 Remote IPC22 Flag Status
    Uint16 IPC23:1;                     // 23 Remote IPC23 Flag Status
    Uint16 IPC24:1;                     // 24 Remote IPC24 Flag Status
    Uint16 IPC25:1;                     // 25 Remote IPC25 Flag Status
    Uint16 IPC26:1;                     // 26 Remote IPC26 Flag Status
    Uint16 IPC27:1;                     // 27 Remote IPC27 Flag Status
    Uint16 IPC28:1;                     // 28 Remote IPC28 Flag Status
    Uint16 IPC29:1;                     // 29 Remote IPC29 Flag Status
    Uint16 IPC30:1;                     // 30 Remote IPC30 Flag Status
    Uint16 IPC31:1;                     // 31 Remote IPC31 Flag Status
};

union IPCFLG_REG {
    Uint32  all;
    struct  IPCFLG_BITS  bit;
};

// IPCxxx Register
//// IPCxxx Register : Byte Value
#define IPCxxx_IPC0                                     0x00000001                  //
#define IPCxxx_IPC1                                     0x00000002                  //
#define IPCxxx_IPC2                                     0x00000004                  //
#define IPCxxx_IPC3                                     0x00000008                  //
#define IPCxxx_IPC4                                     0x00000010                  //
#define IPCxxx_IPC5                                     0x00000020                  //
#define IPCxxx_IPC6                                     0x00000040                  //
#define IPCxxx_IPC7                                     0x00000080                  //
#define IPCxxx_IPC8                                     0x00000100                  //
#define IPCxxx_IPC9                                     0x00000200                  //
#define IPCxxx_IPC10                                    0x00000400                  //
#define IPCxxx_IPC11                                    0x00000800                  //
#define IPCxxx_IPC12                                    0x00001000                  //
#define IPCxxx_IPC13                                    0x00002000                  //
#define IPCxxx_IPC14                                    0x00004000                  //
#define IPCxxx_IPC15                                    0x00008000                  //
#define IPCxxx_IPC16                                    0x00010000                  //
#define IPCxxx_IPC17                                    0x00020000                  //
#define IPCxxx_IPC18                                    0x00040000                  //
#define IPCxxx_IPC19                                    0x00080000                  //
#define IPCxxx_IPC20                                    0x00100000                  //
#define IPCxxx_IPC21                                    0x00200000                  //
#define IPCxxx_IPC22                                    0x00400000                  //
#define IPCxxx_IPC23                                    0x00800000                  //
#define IPCxxx_IPC24                                    0x01000000                  //
#define IPCxxx_IPC25                                    0x02000000                  //
#define IPCxxx_IPC26                                    0x04000000                  //
#define IPCxxx_IPC27                                    0x08000000                  //
#define IPCxxx_IPC28                                    0x10000000                  //
#define IPCxxx_IPC29                                    0x20000000                  //
#define IPCxxx_IPC30                                    0x40000000                  //
#define IPCxxx_IPC31                                    0x80000000                  //

// IPCSENDCOM Register
//// IPCSENDCOM Register : Byte Value
#define IPCSENDCOM_COMMAND_ILLEGAL                      0x00000000                  // Illegal Command.
#define IPCSENDCOM_SET_16BIT                            0x00000001                  //          *(Address) |= Data;
#define IPCSENDCOM_SET_32BIT                            0x00000002                  //          *(Address) |= Data;
#define IPCSENDCOM_CLEAR_16BIT                          0x00000003                  //          *(Address) &= ~Data;
#define IPCSENDCOM_CLEAR_32BIT                          0x00000004                  //          *(Address) &= ~Data;
#define IPCSENDCOM_DATAWrite_16BIT                      0x00000005                  //          *(Address) = Data;
#define IPCSENDCOM_DATAWrite_32BIT                      0x00000006                  //          *(Address) = Data;
#define IPCSENDCOM_DATARead_16BIT                       0x00000007                  //          return *(Address);
#define IPCSENDCOM_DATARead_32BIT                       0x00000008                  //          return *(Address);
#define IPCSENDCOM_SET_PROTECTED_16BIT                  0x00000009                  // EALLOW;  *(Address) |= Data;     EDIS;
#define IPCSENDCOM_SET_PROTECTED_32BIT                  0x0000000A                  // EALLOW;  *(Address) |= Data;     EDIS;
#define IPCSENDCOM_CLEAR_PROTECTED_16BIT                0x0000000B                  // EALLOW;  *(Address) &= ~Data;    EDIS;
#define IPCSENDCOM_CLEAR_PROTECTED_32BIT                0x0000000C                  // EALLOW;  *(Address) &= ~Data;    EDIS;
#define IPCSENDCOM_DATAWrite_PROTECTED_16BIT            0x0000000D                  // EALLOW;  *(Address) = Data;      EDIS;
#define IPCSENDCOM_DATAWrite_PROTECTED_32BIT            0x0000000E                  // EALLOW;  *(Address) = Data;      EDIS;
#define IPCSENDCOM_DATARead_PROTECTED_16BIT             0x0000000F                  // EALLOW;  return *(Address);      EDIS;
#define IPCSENDCOM_DATARead_PROTECTED_32BIT             0x00000010                  // EALLOW;  return *(Address);      EDIS;
#ifdef CPU1
#define IPCSENDCOM_JUMP_TO_ADDR                         0x00000011                  // Jump to the Address in ADDR Register and Starts Executing.
#define IPCSENDCOM_FUNCTION_CALL                        0x00000012                  // Jump to the Address in ADDR Register and Starts Executing. Data is Used for Parameter of Function. The Result Value will be Returned.
#define IPCSENDCOM_EXECUTE_BOOTMODE_CMD                 0x00000013                  // Execute Loaders As Per Request Value In IPCBOOTMODE Register.
#endif

#ifdef CPU1
// IPCBOOTMODE Register
//// IPCBOOTMODE Register : Byte Value
#define IPCBOOTMODE_PARALLEL                            0x00000000                  // CPU2 Boot From Parallel Communication.
#define IPCBOOTMODE_SCIA                                0x00000001                  // CPU2 Boot From SCI Communication.
#define IPCBOOTMODE_SPIA                                0x00000004                  // CPU2 Boot From SPI Communication.
#define IPCBOOTMODE_I2CA                                0x00000005                  // CPU2 Boot From I2C Communication.
#define IPCBOOTMODE_CANA                                0x00000007                  // CPU2 Boot From CAN Communication.
#define IPCBOOTMODE_RAM                                 0x0000000A                  // CPU2 Boot From RAM.
#define IPCBOOTMODE_FLASH                               0x0000000B                  // CPU2 Boot From Flash.
#endif

// IPCBOOTSTS Register
//// IPCBOOTSTS Register : Byte Value
#define IPCBOOTSTS_INVALID                              0x00000000                  // Invalid Status. CPU2 Hasn't Set a Valid Status Yet.
#define IPCBOOTSTS_StartRun                             0x00000001                  // CPU2 Boot ROM Has Started Running.
#define IPCBOOTSTS_ReadyIPC                             0x00000002                  // CPU2 Boot ROM Has Completed and is Ready for IPC Commands.
#define IPCBOOTSTS_ACKIPC                               0x00000003                  // CPU2 ACKs the Boot Command in C1TOC2BOOTMODE Register.
#define IPCBOOTSTS_NotSupportIPC                        0x00000004                  // CPU2 Doesn't Support the Command in C1TOC2BOOTMODE Register.
#define IPCBOOTSTS_NACKIPC                              0x00000005                  // CPU2 NAKs the Boot Command in C1TOC2BOOTMODE Register.

struct IPC_REGS_CPU1 {
    union   IPCACK_REG                       IPCACK;                       // IPC incoming flag clear (acknowledge) register
    union   IPCSTS_REG                       IPCSTS;                       // IPC incoming flag status register
    union   IPCSET_REG                       IPCSET;                       // IPC remote flag set register
    union   IPCCLR_REG                       IPCCLR;                       // IPC remote flag clear register
    union   IPCFLG_REG                       IPCFLG;                       // IPC remote flag status register
    Uint16                                   rsvd1[2];                     // Reserved
    Uint32                                   IPCCOUNTERL;                  // IPC Counter Low Register 
    Uint32                                   IPCCOUNTERH;                  // IPC Counter High Register 
    Uint32                                   IPCSENDCOM;                   // Local to Remote IPC Command Register
    Uint32                                   IPCSENDADDR;                  // Local to Remote IPC Address Register
    Uint32                                   IPCSENDDATA;                  // Local to Remote IPC Data Register
    Uint32                                   IPCREMOTEREPLY;               // Remote to Local IPC Reply Data Register
    Uint32                                   IPCRECVCOM;                   // Remote to Local IPC Command Register
    Uint32                                   IPCRECVADDR;                  // Remote to Local IPC Address Register
    Uint32                                   IPCRECVDATA;                  // Remote to Local IPC Data Register
    Uint32                                   IPCLOCALREPLY;                // Local to Remote IPC Reply Data Register
    Uint32                                   IPCBOOTSTS;                   // CPU2 to CPU1 IPC Boot Status Register
    Uint32                                   IPCBOOTMODE;                  // CPU1 to CPU2 IPC Boot Mode Register
};

struct IPC_REGS_CPU2 {
    union   IPCACK_REG                       IPCACK;                       // IPC incoming flag clear (acknowledge) register
    union   IPCSTS_REG                       IPCSTS;                       // IPC incoming flag status register
    union   IPCSET_REG                       IPCSET;                       // IPC remote flag set register
    union   IPCCLR_REG                       IPCCLR;                       // IPC remote flag clear register
    union   IPCFLG_REG                       IPCFLG;                       // IPC remote flag status register
    Uint16                                   rsvd1[2];                     // Reserved
    Uint32                                   IPCCOUNTERL;                  // IPC Counter Low Register 
    Uint32                                   IPCCOUNTERH;                  // IPC Counter High Register 
    Uint32                                   IPCRECVCOM;                   // Remote to Local IPC Command Register
    Uint32                                   IPCRECVADDR;                  // Remote to Local IPC Address Register
    Uint32                                   IPCRECVDATA;                  // Remote to Local IPC Data Register
    Uint32                                   IPCLOCALREPLY;                // Local to Remote IPC Reply Data Register
    Uint32                                   IPCSENDCOM;                   // Local to Remote IPC Command Register
    Uint32                                   IPCSENDADDR;                  // Local to Remote IPC Address Register
    Uint32                                   IPCSENDDATA;                  // Local to Remote IPC Data Register
    Uint32                                   IPCREMOTEREPLY;               // Remote to Local IPC Reply Data Register
    Uint32                                   IPCBOOTSTS;                   // CPU2 to CPU1 IPC Boot Status Register
    Uint32                                   IPCBOOTMODE;                  // CPU1 to CPU2 IPC Boot Mode Register
};
//---------------------------------------------------------------------------
// IPC External References & Function Declarations:
//
#ifdef CPU1
extern volatile struct IPC_REGS_CPU1 IpcRegs;
#endif
#ifdef CPU2
extern volatile struct IPC_REGS_CPU2 IpcRegs;
#endif

// IPC_Temperature
typedef struct _IPC_MSG_BITS{
    Uint32       MSB:16;
    Uint32       LSB:16;
}IPC_MSG_BITS;

typedef union _IPC_MSG{
    float           all;
    IPC_MSG_BITS    Var;
}IPC_MSG;

extern IPC_MSG    IPC_Temp_Vol[12];                 // Measured value in CPU2
extern IPC_MSG    IPC_Temp_Cal[12];                 // Calculated value in CPU1

// IPC_EtherCAT
// Slave to Master
struct IPC_EtherCAT_Slave_Fault_BITS {
    Uint32                      Fault_RS485:8;
    Uint32                      Fault_SM_Vol:8;
    Uint32                      Fault_SM_Temp:16;
};

union IPC_EtherCAT_Slave_Fault_DATA {
    struct IPC_EtherCAT_Slave_Fault_BITS                    bit;
    Uint32                                                  all;
};

struct IPC_EtherCAT_Slave_DATA {
    float                                               SM_Vol_Sum;
    union  IPC_EtherCAT_Slave_Fault_DATA                     Fault;
};
#ifdef CPU1
extern volatile struct IPC_EtherCAT_Slave_DATA   IpcDspEcatSlave;
extern struct IPC_EtherCAT_Slave_DATA   Dsp1EcatSlave;
#endif
#ifdef CPU2
extern volatile struct IPC_EtherCAT_Slave_DATA   IpcDspEcatSlave;
extern struct IPC_EtherCAT_Slave_DATA   Dsp2EcatSlave;
#endif

// Master to Slave
struct IPC_EtherCAT_Master_STATUS_BITS {
    Uint16              Slave_Num:6;                    //Slave Number
    Uint16              HMI_Page:2;                     //Mode selection, Main controller
    Uint16              Operation_Mode:4;               //PTP, BTB, Single, Test
    Uint16              Device:2;                       //Converter, Inverter
    Uint16              Switching_Method:2;              //NLC, PD
};

union IPC_EtherCAT_Master_STATUS_DATA {
    struct IPC_EtherCAT_Master_STATUS_BITS                  bit;
    Uint16                                                  all;
};

struct IPC_EtherCAT_Master_Operation_BITS {
    Uint16              Arm_current_Dir:2;              //Positive, Negative
    Uint16              EtherCAT_Ready:2;               //EtherCAT Ready
    Uint16              DAQ_READY:4;                    //DAQ_Ready
    Uint16              Flag_Operation:8;               //Stop, Reset, Start
};

union IPC_EtherCAT_Master_Operation_DATA {
    struct IPC_EtherCAT_Master_Operation_BITS               bit;
    Uint16                                                  all;
};

struct IPC_EtherCAT_Master_Bypass_BITS {
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

union IPC_EtherCAT_Master_Bypass_DATA {
    struct IPC_EtherCAT_Master_Bypass_BITS                  bit;
    Uint16                                                  all;
};

struct IPC_EtherCAT_Master_Slave_OP_MODE_BITS {
    Uint16                      OP_Mode:4;
    Uint16                      TEST_value:12;
};

union IPC_EtherCAT_Master_Slave_OP_MODE_DATA {
    struct IPC_EtherCAT_Master_Slave_OP_MODE_BITS           bit;
    Uint16                                                  all;
};

struct IPC_EtherCAT_Master_DATA {
    union IPC_EtherCAT_Master_STATUS_DATA                   STATUS;
    union IPC_EtherCAT_Master_Operation_DATA                Operation;
    union IPC_EtherCAT_Master_Bypass_DATA                   Bypass;
    Uint16                                                  SM_Vol_Under_Limit;
    Uint16                                                  SM_Vol_Over_Limit;
    Uint16                                                  SM_Temp_Limit;
    union IPC_EtherCAT_Master_Slave_OP_MODE_DATA            Slave_OP_Mode;
    Uint16                                                  FLASH_MSB;
    Uint16                                                  FLASH_LSB;
    Uint16                                                  REF;
    Uint16                                                  SlaveStatus;
};

#ifdef CPU1
extern volatile struct IPC_EtherCAT_Master_DATA  IpcDspEcatMaster;
extern struct IPC_EtherCAT_Master_DATA  DspEcatMaster
#endif
#ifdef CPU2
extern volatile struct IPC_EtherCAT_Master_DATA  IpcDspEcatMaster;
extern struct IPC_EtherCAT_Master_DATA  Dsp2EcatMaster;
#endif

#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
