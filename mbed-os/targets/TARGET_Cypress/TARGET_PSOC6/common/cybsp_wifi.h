/***************************************************************************//**
* \file cybsp_wifi.h
*
* \brief
* Basic abstraction layer for dealing with boards containing a Cypress MCU. This
* API provides convenience methods for initializing and manipulating different
* hardware found on the board.
*
********************************************************************************
* \copyright
* Copyright 2018-2019 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/**
* \addtogroup group_bsp_wifi WiFi
* \{
* Basic abstraction layer for dealing with boards containing a Cypress MCU. This
* API provides convenience methods for initializing and manipulating different
* hardware found on the board.
*
* \defgroup group_bsp_wifi_macros Macros
* \defgroup group_bsp_wifi_functions Functions
*/
#pragma once

#include "cy_result.h"
#include "whd_wifi_api.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_bsp_wifi_macros
* \{
*/

/** Initialization of the wifi driver failed. */
#define CYBSP_RSLT_WIFI_INIT_FAILED (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_BSP, 4))

/** \} group_bsp_board_macros */

/**
* \addtogroup group_bsp_wifi_functions
* \{
*/

/** Initializes the primary interface for the wifi driver on the board. This function does the following
 * 1) Initializes the wifi driver.
 * 2) Turns on the WIFI chip.
 * 
 * @param[out] interface Interface to be initialized 
 * @return CY_RSLT_SUCCESS for successful initialization or error if initialization failed.
 */
cy_rslt_t cybsp_wifi_init_primary(whd_interface_t* interface);

/** This function initializes and adds a secondary interface to the wifi driver.
 *  @note This function does not initialize the wifi driver or turn on the wifi chip.
 * That is required to be done by the primary interface
 * 
 * @param[out] interface Interface to be initialized
 * @param[in] mac_address Mac address for secondary interface
 * @return CY_RSLT_SUCCESS for successful initialization or error if initialization failed.
 */
cy_rslt_t cybsp_wifi_init_secondary(whd_interface_t* interface, whd_mac_t* mac_address);

/** Gets the wifi driver instance initialized by the driver. This should only be called
 * after the interface is initialized by cybsp_wifi_init_primary().
 *
 * @return Wifi driver instance pointer.
 */
whd_driver_t cybsp_get_wifi_driver(void);

/** \} group_bsp_wifi_functions */

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** \} group_bsp_wifi */
