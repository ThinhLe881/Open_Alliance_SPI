/*
 * OA_TC6.h
 *
 *  Created on: Mar. 25, 2025
 *      Author: thinh
 */

#ifndef ENET_OA_SPI_OA_TC6_H_
#define ENET_OA_SPI_OA_TC6_H_

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

#define OA_MMS_MASK             0x0F    /* 4-bit */
#define OA_LEN_MASK             0x7F    /* 7-bit */
#define OA_REG_DATA_LEN         4u      /* 32-bit register always, 0s left padding for 16-bit register */
#define OA_MIN_RW_REG           1u
#define OA_ABS_MAX_RW_REG       128u    /* Specified by OA-TC6 */
#define OA_BUF_MIN_SZ           12u     /* Buffer has to be large enough to use control command for a single 32-bit register
                                            and data transmit with 8-byte data chunk.
                                        - 4-byte header + 4-byte data (32-bit register data) + 4-byte padding
                                        - 4-byte header + 8-byte data chunk */

/* User-defined */
/* This value has to be large enough for the number of RW registers in a single transaction (OA_MAX_RW_REG)
    and large enough for a data transaction of a single chunk (8, 16, 32, or 64 bytes) */
#define OA_BUF_SZ               68u
#define OA_MAX_RW_REG           15u
/* Default parameters */
#ifndef OA_BUF_SZ
#define OA_BUF_SZ               OA_BUF_MIN_SZ
#elif OA_BUF_SZ < OA_BUF_MIN_SZ
#define OA_BUF_SZ               OA_BUF_MIN_SZ
#endif /* OA_BUF_SZ */
#ifndef OA_MAX_RW_REG           /* This value depends on the buffer size (OA_BUF_SZ) */
#define OA_MAX_RW_REG           OA_MIN_RW_REG
#elif OA_MAX_RW_REG < OA_MIN_RW_REG
#define OA_MAX_RW_REG           OA_MIN_RW_REG
#elif OA_MAX_RW_REG > OA_ABS_MAX_RW_REG
#define OA_MAX_RW_REG           OA_ABS_MAX_RW_REG
#endif /* OA_MAX_RW_REG */


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


/* **********************************************************************/
/* ***               Definition of global types                       ***/
/* **********************************************************************/
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    /* Parity - Parity bit over bits 31:1 of the transmit data header field. This field is set such that there is an
        odd total number of bits set within the header. */
    uint32_t P          : 1;
    /* Length - This field specifies the number of successive registers to read/write within the control command.
        The length is the number of registers to access minus one. Up to 128 consecutive registers may be read
        or written by a single control command. When accessing only a single register, this field is zero. */
    uint32_t LEN        : 7;
    /*Address - This field specifies the address of the first register to access within the selected memory map.*/
    uint32_t ADDR       : 16;
    /* Memory Map Selector - This bit field selects the device memory map to be accessed */
    uint32_t MMS        : 4;
    /* Address Increment Disable - Normally, when this bit is 0, the address is post-incremented by 1 following each
        read/write register access within the same control command. When this bit is 1, subsequent reads or writes
        within the same control command will result in the same register address being accessed. This feature is
        useful for reading and writing register FIFOs located at a single address.
    0: Register address will automatically be post-incremented following each read/write within the same control command.
    1: Register address will not be post-incremented following each read/write within the same control command,
        allowing successive access to the same register address. */
    uint32_t AID        : 1;
    /* Write, Not Read - This bit indicates the type of control access to perform.
    0: Control/Status register read
    1: Control/Status register write */
    uint32_t WNR        : 1;
    /* Header Bad - Indication from the MAC-PHY to the SPI host that it received a transaction header with an invalid parity. */
    uint32_t HDRB       : 1;
    /* Data, Not Control - Flag indicating the type of transaction, data or control.
    0: Control (register read/write)
    1: Data (Ethernet frame) */
    uint32_t DNC        : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint32_t DNC        : 1;
    uint32_t HDRB       : 1;
    uint32_t WNR        : 1;
    uint32_t AID        : 1;
    uint32_t MMS        : 4;
    uint32_t ADDR       : 16;
    uint32_t LEN        : 7;
    uint32_t P          : 1;
#endif /* DRV_BYTE_ORDER */
} st_OASPI_Ctrl_Hdr_t;

typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    /* Parity - Parity bit over bits 31:1 of the transmit data header field. This field is set such that there is an
        odd total number of bits set within the header. */
    uint32_t P          : 1;
    uint32_t            : 5; /* Set this to 0, it's for padding */
    /* Timestamp Capture - The SPI host may use this field to indicate to the MAC-PHY to request a timestampt capture
        when an Ethernet frame is transmitted onto the network into the specified timestamp capture register.
    Note: This field is ignored when frame timestamping is disabled in the Frame Timestamp Enable (FTSE) bit of the Configuration 0
        (OA_CONFIG0) register. This field is ignored in all other conditions except when the Data Valid (DV) and Start Valid (SV)
        bits are both set to �1� to indicate the beginning of a new Ethernet frame transfer.
    00: Do not capture frame egress timestamp
    01: Capture frame egress timestamp into Transmit Timestamp Capture Register A (TTSCA)
    10: Capture frame egress timestamp into Transmit Timestamp Capture Register B (TTSCB)
    11: Capture frame egress timestamp into Transmit Timestamp Capture Register C (TTSCC) */
    uint32_t TSC        : 2;
    /* End Byte Offset - This field indicated which byte of the chunk data payload contains the last byte
        of the end of an Ethernet frame. This field is ignored when Data Valid or End Valid bits are �0�. */
    uint32_t EBO        : 6;
    /* End Valid - This bit is set by the host MCU to indicate that the end of an Ethernet frame is contained within
        the chunk data payload. The end of the frame is located by the End Byte Offset (EBO) field. The EV bit is
        ignored if the Data Valid bit is �0�. */
    uint32_t EV         : 1;
    uint32_t            : 1; /* Set this to 0, it's for padding */
    /* Start Word Offset - This field indicates which 32-bit word of the chunk data payload contains the first word of
        a new Ethernet frame. This field is ignored when Data Valid or Start Valid bits are �0�. */
    uint32_t SWO        : 4;
    /* Start Valid - This bit is set by the host MCU to indicate that the beginning of an Ethernet frame is contained within the
        chunk data payload. The beginning of the frame is located by the Start Word Offset (SWO) field. The SV bit is ignored
        if the Data Valid bit is �0�. */
    uint32_t SV         : 1;
    /* Data Valid - host MCU sets to indicate that the Ethernet frame data is being transferred within the chunk data payload */
    uint32_t DV         : 1;
    /* Reserved for future use by ONSEMI, host MCU shall set this to 0 */
    uint32_t VS         : 2;
    uint32_t            : 5; /* Set to 0 */
    /* No Receive - Indicates to MAC-PHY that the host MCU will ignore any received Ethernet frames during this chunk */
    uint32_t NORX       : 1;
    /* Data Chunk Sequence - Indication of data chunk sequence (even or odd) */
    uint32_t SEQ        : 1;
    /* Data, Not Control - 1 for Data, 0 for Control (register read/write) */
    uint32_t DNC        : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint32_t DNC        : 1;
    uint32_t SEQ        : 1;
    uint32_t NORX       : 1;
    uint32_t            : 5;
    uint32_t VS         : 2;
    uint32_t DV         : 1;
    uint32_t SV         : 1;
    uint32_t SWO        : 4;
    uint32_t            : 1;
    uint32_t EV         : 1;
    uint32_t EBO        : 6;
    uint32_t TSC        : 2;
    uint32_t            : 5;
    uint32_t P          : 1;
#endif /* DRV_BYTE_ORDER */
} st_OASPI_Data_Hdr_t;

typedef	struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    /* Parity - Parity bit over bits 31:1 of the transmit data header field. This field is set such that there is an
        odd total number of bits set within the header. */
    uint32_t P          : 1;
    /* Transmit Credits - This field contains the minimum number of transmit data chunks of frame data that the SPI
        host can write in a single transaction without incurring a transmit buffer overflow error. */
    uint32_t TXC        : 5;
    /* Received Timestamp Parity - Parity bit calculated over the 32-bit/64-bit timestamp added to the beginning of the
        received frame. This field is set such that there is an odd total number of bits set within the timestamp.
        The MAC-PHY shall set this bit to 0 when RTSA = 0. */
    uint32_t RTSP       : 1;
    /* Receive Timestamp Added - This bit is set when a 32-bit or 64-bit timestamp has been added to the beginning of the
        received frame. The MAC-PHY shall set this bit to zero when SV = 0. */
    uint32_t RTSA       : 1;
    /* End Byte Offset - This field indicated which byte of the chunk data payload contains the last byte of the end of
        an Ethernet frame. This field is ignored when Data Valid or End Valid bits are �0�. */
    uint32_t EBO        : 6;
    /* End Valid - This bit is set by the host MCU to indicate that the end of an Ethernet frame is contained within the
        chunk data payload. The end of the frame is located by the End Byte Offset (EBO) field. The EV bit is ignored if
        the Data Valid bit is �0�. */
    uint32_t EV         : 1;
    /* Frame Drop - When set, this bit indicates that the MAC has detected a condition for which the MCU host should drop
        the received frame. This bit is only valid at the end of a received frame (EV = 1) and shall be zero at all other times. */
    uint32_t FD         : 1;
    /* Start Word Offset - This field indicates which 32-bit word of the chunk data payload contains the first word of a
        new Ethernet frame. This field is ignored when Data Valid or Start Valid bits are �0�. */
    uint32_t SWO        : 4;
    /* Start Valid - This bit is set by the host MCU to indicate that the beginning of an Ethernet frame is contained within
        the chunk data payload. The beginning of the frame is located by the Start Word Offset (SWO) field. The SV bit is
        ignored if the Data Valid bit is �0�. */
    uint32_t SV         : 1;
    /* Data Valid - host MCU sets to indicate that the Ethernet frame data is being transferred within the chunk data payload */
    uint32_t DV         : 1;
    /* Reserved for future use by ONSEMI, host MCU shall set this to 0 */
    uint32_t VS         : 2;
    /* Receive Chunks Available - Indicate to the MCU host the minimum number of additional receive data chunks of frame data
        that are available for reading beyond the current receive data chunk. This field is 0 when there is no receive frame
        data pending in the MAC-PHY's buffer for reading. */
    uint32_t RCA        : 5;
    /* Configuration Synchronized flag - 0 indicates that the MAC-PHY configuration may not be as expected by the MCU host.
        Following configuration, the MCU host sets the corresponding bit in the configuration register which is reflected
        in this field. */
    uint32_t SYNC       : 1;
    /* Received Header Bad - Indicating that the MAC-PHY received a control or data header with a parity error */
    uint32_t HDRB       : 1;
    /* Extended Status */
    uint32_t EXST       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint32_t EXST       : 1;
    uint32_t HDRB       : 1;
    uint32_t SYNC       : 1;
    uint32_t RCA        : 5;
    uint32_t VS         : 2;
    uint32_t DV         : 1;
    uint32_t SV         : 1;
    uint32_t SWO        : 4;
    uint32_t FD         : 1;
    uint32_t EV         : 1;
    uint32_t EBO        : 6;
    uint32_t RTSA       : 1;
    uint32_t RTSP       : 1;
    uint32_t TXC        : 5;
    uint32_t P          : 1;
#endif /* DRV_BYTE_ORDER */
} st_OASPI_Data_Ftr_t;

typedef union
{
    st_OASPI_Ctrl_Hdr_t     ctrl_hdr;
    st_OASPI_Data_Hdr_t     data_hdr;
    st_OASPI_Data_Ftr_t     data_ftr;
    uint32_t                u32_word;
} un_OASPI_Hdr_t;

typedef enum
{
    en_OASPI_WNR_READ,
    en_OASPI_WNR_WRITE
} en_OASPI_WNR_t;

typedef enum
{
    en_OASPI_AI_ENABLE,
    en_OASPI_AI_DISABLE,
} en_OASPI_AID_t;

typedef enum
{
    en_PROTE_DISABLE,
    en_PROTE_ENABLE,
} en_OASPI_PROTE_t;

typedef struct
{
    en_OASPI_WNR_t          mode;
    uint8_t                 reg_mms;
    uint8_t                 reg_addr;
    uint8_t                 num_regs;
    uint32_t *              data;
} st_OASPI_Control_Cmd_t;

typedef struct
{
    uint8_t                 spi_device;
    uint8_t                 irqn_port;
    uint8_t                 irqn_pin;
    un_OASPI_Hdr_t          spi_status;
    en_OASPI_PROTE_t        spi_prote;
} st_OASPI_Interface_t;


/* **********************************************************************/
/* ***            Declaration of global functions                     ***/
/* **********************************************************************/



#endif /* ENET_OA_SPI_OA_TC6_H_ */
