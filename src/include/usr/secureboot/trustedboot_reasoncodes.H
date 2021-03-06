/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/trustedboot_reasoncodes.H $        */
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
#ifndef __TRUSTEDBOOT_REASONCODES_H
#define __TRUSTEDBOOT_REASONCODES_H

#include <hbotcompid.H>

namespace TRUSTEDBOOT
{
    enum TRUSTEDModuleId
    {
        MOD_HOST_UPDATE_MASTER_TPM      = 0x00,
        MOD_TPM_INITIALIZE              = 0x01,
    };

    enum TRUSTEDReasonCode
    {
        // Reason codes 0x00 - 0x9F reserved for secure_reasoncodes.H

        RC_TPM_START_FAIL               = SECURE_COMP_ID | 0xA0,
        RC_TPM_EXISTENCE_FAIL           = SECURE_COMP_ID | 0xA1,
    };
}

#endif
