/*
 * OA_TC6_Reg.h
 *
 *  Created on: Apr 22, 2025
 *      Author: thinh
 */

#ifndef ENET_OA_SPI_OA_TC6_REG_H_
#define ENET_OA_SPI_OA_TC6_REG_H_

/* **********************************************************************/
/*                  System and library files included                   */
/* 1) system and project includes                                       */
/* 2) needed interfaces from external units                             */
/* 3) internal and external interfaces from this unit                   */
/* **********************************************************************/
#include <stdint.h>


/* **********************************************************************/
/* ***           Definition of global plain CONSTants                 ***/
/* **********************************************************************/
#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__
#define DRV_LITTLE_ENDIAN               (1234)
#define DRV_BIG_ENDIAN                  (4321)
/** If __BYTE_ORDER__ is not defined, choose the endianness of your architecture
 * by uncommenting the define which fits your platform endianness.
 */
/* #define DRV_BYTE_ORDER                  (DRV_BIG_ENDIAN) */
#define DRV_BYTE_ORDER                  (DRV_LITTLE_ENDIAN)
#else /* defined __BYTE_ORDER__ */
#define DRV_LITTLE_ENDIAN               (__ORDER_LITTLE_ENDIAN__)
#define DRV_BIG_ENDIAN                  (__ORDER_BIG_ENDIAN__)
#define DRV_BYTE_ORDER                  (__BYTE_ORDER__)
#endif /* __BYTE_ORDER__ */
#endif /* DRV_BYTE_ORDER */


/* ********************************************************************/
/* ***                    Register Addresses                        ***/
/* ********************************************************************/
#define ADDREG_IDVER            0x00
#define MMS_IDVER               0x00
#define ADDREG_PHYID            0x01
#define MMS_PHYID               0x00
#define ADDREG_ADDRFILT0L       0x10
#define MMS_ADDRFILT0L          0x01
#define ADDREG_ADDRFILT0H       0x11
#define MMS_ADDRFILT0H          0x01
#define ADDREG_ADDRFILT1L       0x12
#define MMS_ADDRFILT1L          0x01
#define ADDREG_ADDRFILT1H       0x13
#define MMS_ADDRFILT1H          0x01
#define ADDREG_ADDRFILT2L       0x14
#define MMS_ADDRFILT2L          0x01
#define ADDREG_ADDRFILT2H       0x15
#define MMS_ADDRFILT2H          0x01
#define ADDREG_ADDRFILT3L       0x16
#define MMS_ADDRFILT3L          0x01
#define ADDREG_ADDRFILT3H       0x17
#define MMS_ADDRFILT3H          0x01


/* **********************************************************************/
/* ***            Declaration of global register types                ***/
/* **********************************************************************/
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint32_t MINVER                 : 4;
    uint32_t MAJVER                 : 4;
    uint32_t                        : 24;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint32_t                        : 24;
    uint32_t MAJVER                 : 4;
    uint32_t MINVER                 : 4;
#endif /* DRV_BYTE_ORDER */
} REG_IDVER_R_0_00h_t;

typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint32_t REVISION               : 4;
    uint32_t MODEL                  : 6;
    uint32_t OUI                    : 22;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint32_t OUI                    : 22;
    uint32_t MODEL                  : 6;
    uint32_t REVISION               : 4;
#endif /* DRV_BYTE_ORDER */
} REG_PHYID_R_0_01h_t;

typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint32_t MINCPS                 : 4;
    uint32_t                        : 1;
    uint32_t SEQC                   : 1;
    uint32_t AIDC                   : 1;
    uint32_t FTSC                   : 1;
    uint32_t CTC                    : 1;
    uint32_t DPRAC                  : 1;
    uint32_t IPRAC                  : 1;
    uint32_t TXFCSVC                : 1;
    uint32_t                        : 21;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint32_t                        : 21;
    uint32_t TXFCSVC                : 1;
    uint32_t IPRAC                  : 1;
    uint32_t DPRAC                  : 1;
    uint32_t CTC                    : 1;
    uint32_t FTSC                   : 1;
    uint32_t AIDC                   : 1;
    uint32_t SEQC                   : 1;
    uint32_t                        : 1;
    uint32_t MINCPS                 : 4;
#endif /* DRV_BYTE_ORDER */
} REG_STDCAP_R_0_02h_t;

typedef union
{
    uint32_t                        u32_word;

    REG_IDVER_R_0_00h_t             Reg_IDVER;
    REG_PHYID_R_0_01h_t             Reg_PHYID;
    REG_STDCAP_R_0_02h_t            Reg_STDCAP;
} un_OASPI_Reg_t;


#endif /* ENET_OA_SPI_OA_TC6_REG_H_ */
