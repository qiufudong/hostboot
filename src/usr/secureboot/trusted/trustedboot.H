/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file trustedboot.H
 *
 * @brief Trustedboot TPM interfaces
 *
 */
#ifndef __TRUSTEDBOOT_H
#define __TRUSTEDBOOT_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <secureboot/trustedbootif.H>

namespace TRUSTEDBOOT
{

enum
{
    MAX_SYSTEM_TPMS = 2,
    BUFSIZE         = 256,
    TPM_MASTER_INDEX = 0,     ///< Index into tpmTargets array for master chip
    TPM_BACKUP_INDEX = 1,     ///< Index for backup chip TPM
};


/**
 * @brief Initialize the targetted TPM
 * @param[in/out] io_target Current TPM target structure
 * @param[in] i_nodeTarget Node Target
 * @param[in] i_chip Chip to initialize
*/
    void tpmInitialize(TRUSTEDBOOT::TpmTarget & io_target,
                       TARGETING::Target* i_nodeTarget,
                       TPMDD::tpm_chip_types_t i_chip);

/// Class object to store system TPM information
class SystemTpms
{
public:
    SystemTpms();

    TpmTarget tpm[MAX_SYSTEM_TPMS];
};

// Command structures taken from Trusted Platform Module Library Part 3:
//    Commands Family "2.0"
struct TPM2_BaseIn {
    uint16_t      tag;       ///< Type TPM_ST_xx
    uint32_t      commandSize; ///< Total # output bytes incl cmdSize and tag
    uint32_t      commandCode;   ///< Type TPM_CC_xx
} PACKED;

/// Base of all outgoing messages
struct TPM2_BaseOut {
    uint16_t      tag;       ///< Type TPM_ST_xx
    uint32_t      responseSize; ///< Total # output bytes incl paramSize and tag
    uint32_t      responseCode;///< The return code of the operation
} PACKED;

/// Generic TPM Input Command structure with a 2 byte param
struct TPM2_2ByteIn {
    TPM2_BaseIn  base;
    uint16_t     param;
} PACKED;

/// Generic TPM Output Command structure with a 4 byte return data
struct TPM2_4ByteOut {
    TPM2_BaseOut base;
    uint32_t     resp;
} PACKED;

/// Incoming TPM_GetCapability structure
struct TPM2_GetCapabilityIn {
    TPM2_BaseIn  base;
    uint32_t    capability;      ///< group selection
    uint32_t    property;        ///< Further definition
    uint32_t    propertyCount;   ///< Number of properties to return
} PACKED;

/// Outgoing TPM_GetCapability structure
struct TPM2_GetCapabilityOut {
    TPM2_BaseOut base;
    uint8_t     moreData;    ///< Flag to indicate if more values available
    uint8_t     capData[];   ///< The capability response
} PACKED;

/// Various static values
enum {
    // Command structure tags
    TPM_ST_NO_SESSIONS        = 0x8001,     ///< A command with no sess/auth


    // Command Codes
    TPM_CC_Startup            = 0x00000144,
    TPM_CC_GetCapability      = 0x0000017A,
    TPM_CC_PCR_Read           = 0x0000017E,
    TPM_CC_PCR_Extend         = 0x00000182,


    // TPM Startup types
    TPM_SU_CLEAR              = 0x0000,  ///< TPM perform reset,restart
    TPM_SU_STATE              = 0x0001,  ///< TPM perform restore saved state

    // Capability
    TPM_CAP_TPM_PROPERTIES    = 0x00000006, ///< Pull TPM Properties

    // TPM Properties
    TPM_PT_MANUFACTURER       = 0x00000105,

    // TPM Return Codes
    TPM_SUCCESS               = 0x000,

    TPM_RC_INITIALIZE         = 0x100,

};



} // end TRUSTEDBOOT namespace
#endif
