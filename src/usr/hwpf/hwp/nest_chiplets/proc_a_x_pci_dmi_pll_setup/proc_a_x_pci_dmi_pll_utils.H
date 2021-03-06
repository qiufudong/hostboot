/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: proc_a_x_pci_dmi_pll_utils.H,v 1.4 2015/05/14 21:18:32 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_a_x_pci_dmi_pll_utils.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_a_x_pci_dmi_pll_utils.H
// *! DESCRIPTION : PLL configuration utility functions
// *!
// *! OWNER NAME  : Joe McGill               Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_A_X_PCI_DMI_PLL_UTILS_H_
#define _PROC_A_X_PCI_DMI_PLL_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
enum p8_pll_utils_ring_address
{
    RING_ADDRESS_MEMB_TP_BNDY_PLL = 0x01030088,
    RING_ADDRESS_PROC_AB_BNDY_PLL = 0x08030088,
    RING_ADDRESS_PROC_PCI_BNDY_PLL = 0x09030088,
    RING_ADDRESS_PROC_PB_BNDY_DMIPLL = 0x02030088
};

enum p8_pll_utils_ring_id
{
    RING_ID_ABUS = 1,
    RING_ID_PCI = 2,
    RING_ID_DMI = 3
};

enum p8_pll_utils_ring_op
{
    RING_OP_BASE = 0,
    RING_OP_MOD_VCO_S1 = 1,
    RING_OP_MOD_VCO_S2 = 2,
    RING_OP_MOD_REFCLK_SEL = 3,
    RING_OP_MOD_PFD360 = 4
};

enum p8_pll_utils_bus_id
{
    RING_BUS_ID_0 = 0,
    RING_BUS_ID_1 = 1,
    RING_BUS_ID_2 = 2,
    RING_BUS_ID_3 = 3,
    RING_BUS_ID_4 = 4,
    RING_BUS_ID_5 = 5,
    RING_BUS_ID_6 = 6,
    RING_BUS_ID_7 = 7
};


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function:
//      Scan PLL boundary ring with setpulse
//
// parameters: i_target              => chip target
//             i_pll_ring_addr       => PLL ring address
//             i_pll_ring_op         => modification to be made to base PLL content
//             i_pll_bus_id          => bus instance to target for modification
//             i_mask_scan_collision => mask scan collision bit in chiplet
//                                      pervasive LFIR
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_scan_bndy(
    const fapi::Target& i_target,
    const p8_pll_utils_ring_address i_pll_ring_addr,
    const p8_pll_utils_ring_op i_pll_ring_op,
    const p8_pll_utils_bus_id i_pll_bus_id,
    const bool i_mask_scan_collision);


//------------------------------------------------------------------------------
// function:
//      Release chiplet PLL from test mode/bypass/reset and optionally check
//      for lock
//
// parameters: i_target                 => chip target
//
//             i_chiplet_base_scom_addr => aligned base address of chiplet SCOM
//                                         address space
//             i_check_lock             => check for PLL lock?
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_a_x_pci_dmi_pll_release_pll(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_scom_addr,
    const bool i_check_lock);


} // extern "C"

#endif // _PROC_A_X_PCI_DMI_PLL_UTILS_H_
