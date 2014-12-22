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
 * @code
 *  #include <hal/pin.h>
 *  #define LED	PA8	// dependent on board
 *  
 *  int main(void)
 *  {
 *  	pin_clock_enable(LED);
 *  	pin_set(LED, false);
 *  	pin_output_pushpull(LED);
 *  	
 *  	while (true) {
 *  		pin_toggle(LED);
 *  	}
 *  }
 *  
 * @endcode
 *
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
static void pin_pull_disable(const uint32_t pin);
static void pin_pull_down(const uint32_t pin);
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
static void pin_output_pushpull(const uint32_t pin);
static void pin_output_opendrain(const uint32_t pin);
static void pin_af_pushpull(const uint32_t pin);
static void pin_af_opendrain(const uint32_t pin);
static void pin_input(const uint32_t pin);
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
static void pin_speed_low(const uint32_t pin);
static void pin_speed_medium(const uint32_t pin);
static void pin_speed_fast(const uint32_t pin);
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
static void pin_af_map(const uint32_t pin, const uint32_t af);
/**@}*/

END_DECLS

/*****************************************************************************/
/* Architecture dependent implementations                                    */
/*****************************************************************************/

#if defined(STM32F0)
# include <lib/arch/stm32/pin_v1.h>
#elif defined(STM32F1)
# include <hal/arch/stm32/pin_v0.h>
#elif defined(STM32F2)
# include <lib/arch/stm32/pin_v1.h>
#elif defined(STM32F3)
# include <lib/arch/stm32/pin_v1.h>
#elif defined(STM32F4)
# include <lib/arch/stm32/pin_v1.h>
#elif defined(STM32F7)
# include <lib/arch/stm32/pin_v1.h>
#elif defined(STM32L0)
# include <lib/arch/stm32/pin_v1.h>
#elif defined(STM32L1)
# include <lib/arch/stm32/pin_v1.h>
#else
# error "hal/pin.h have not defined your architecture."
#endif


/**@}*/

#endif // HAL_PIN_H_INCLUDED
