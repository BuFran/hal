/*
 * This file is part of the HAL project, inline library above libopencm3.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
/** @defgroup PIN_module PIN manipulation module
 *
 * @brief PIN manipulation API
 *
 * @ingroup modules
 *
 * LGPL License Terms @ref lgpl_license
 *
 * Basic example of usage:
 *
 * \includelineno pin/blink_basic.c
 *
 * Extended usage with board dependency:
 *
 * \includelineno pin/blink_multiboard.c
 *
 * Extended usage with alternate function selection:
 *
 * \includelineno pin/periph_altfn.c
 */
#ifndef HAL_PIN_H_INCLUDED
#define HAL_PIN_H_INCLUDED

#include <hal/common.h>

/**@{*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup PIN_api_clock PIN Peripheral Clock API
 * @ingroup PIN_module
 *
 * @brief Pin Peripheral Clock manipulation
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief Enable peripheral clock for port occupying specified pin
 *
 * @note should be called before any config done on that pin, or all ports
 * should have clocks enabled prior to use.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_clock_enable(const uint32_t pin);
/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup PIN_api_opmode PIN State API
 * @ingroup PIN_module
 *
 * @brief Pin state manipulation
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief Get the actual pin state
 *
 * This function returns actual voltage level on the pin.
 *
 * @note If the pin was configured as an output, the function can return
 * opposite level, than the one that is used for output, indicating signal
 * collision on that pin. Collisions are not recommended for high-speed
 * settings for the output.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 * @returns true, if pin is held high, false otherwise
 */
static bool pin_get(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set the pin state
 *
 * @param[in] pin pin name (@ref pin_name_base)
 * @param[in] val value to set
 */
static void pin_set(const uint32_t pin, bool val);

/*---------------------------------------------------------------------------*/
/** @brief Toggle the pin level state
 *
 * The function creates edge on the specified pin.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_toggle(const uint32_t pin);

/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup PIN_api_pullup PIN PullUp/PullDown API
 * @ingroup PIN_module
 *
 * @brief Pin pullup manipulation
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief Disable pullups or pulldowns on specified pin
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_pull_disable(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set PullDown on the pin
 *
 * After call, unconnected input pin should read 0 (false/low level)
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_pull_down(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set PullUp on the pin
 *
 * After call, unconnected input pin should read 1 (true/high level)
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_pull_up(const uint32_t pin);
/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup PIN_api_direction PIN Direction API
 * @ingroup PIN_module
 *
 * @brief Pin direction manipulation
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief Set pin to GPIO Output mode, source and sink
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_output_pushpull(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin to GPIO Output mode, sink only
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_output_opendrain(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin to AuxFn Output mode, source and sink
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_af_pushpull(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin to AuxFn Output mode, sink only
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_af_opendrain(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin to Input mode
 *
 * @note In this mode, the pin_speed_* functions are useless
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_input(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin to Analog mode
 *
 * This mode disconnects all digital electronics from the pin, allowing to
 * float everywhere between 0 and VDD of the chip.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_analog(const uint32_t pin);
/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup PIN_api_speed PIN Speed API
 * @ingroup PIN_module
 *
 * @brief Pin speed manipulation
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief Set pin speed to slowest mode
 *
 * As an side effect, maximum current draw from/to the pin will be very limited.
 *
 * @warning Should be called after output mode set. Do not call when pin is in
 * input or analog mode.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_speed_low(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin speed to medium speed mode
 *
 * As an side effect, maximum current draw from/to the pin will be limited.
 *
 * @warning Should be called after output mode set. Do not call when pin is in
 * input or analog mode.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_speed_medium(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin speed to fast mode
 *
 * As an side effect, maximum current draw from/to the pin will be less limited.
 *
 * @warning Should be called after output mode set. Do not call when pin is in
 * input or analog mode.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_speed_fast(const uint32_t pin);

/*---------------------------------------------------------------------------*/
/** @brief Set pin speed to highest mode
 *
 * As an side effect, maximum current draw from/to the pin will not be limited,
 * allowing external device may destroy the pin during collision.
 *
 * @warning Should be called after output mode set. Do not call when pin is in
 * input or analog mode.
 *
 * @note when architecture doesn't support this mode, the meaning should be
 * same as @ref pin_speed_fast function
 *
 * @param[in] pin pin name (@ref pin_name_base)
 */
static void pin_speed_high(const uint32_t pin);
/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup PIN_api_af PIN Alternate function API
 * @ingroup PIN_module
 *
 * @brief Pin Alternate Function manipulation
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief Map the alternate function to the pin
 *
 * The AF should be emulated on architectures, they doesn't support AF mapping.
 * @warning care must be taken because one call can touch mapping of other pins
 * in one call on architectures they doesn't support AF mapping.
 *
 * @param[in] pin pin name (@ref pin_name_base)
 * @param[in] af AF index (@ref pin_name_base)
 */
static void pin_af_map(const uint32_t pin, const uint32_t af);
/**@}*/

END_DECLS

/*****************************************************************************/
/* Architecture dependent implementations                                    */
/*****************************************************************************/

#if defined(STM32F0)
# include <hal/arch/stm32/pin_v1.h>
#elif defined(STM32F1)
# include <hal/arch/stm32/pin_v0.h>
#elif defined(STM32F2)
# include <hal/arch/stm32/pin_v1.h>
#elif defined(STM32F3)
# include <hal/arch/stm32/pin_v1.h>
#elif defined(STM32F4)
# include <hal/arch/stm32/pin_v1.h>
#elif defined(STM32F7)
# include <hal/arch/stm32/pin_v1.h>
#elif defined(STM32L0)
# include <hal/arch/stm32/pin_v1.h>
#elif defined(STM32L1)
# include <hal/arch/stm32/pin_v1.h>
#else
# error "hal/pin.h have not defined your architecture."
#endif


/**@}*/

#endif // HAL_PIN_H_INCLUDED
