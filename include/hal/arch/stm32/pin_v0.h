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
#ifndef HAL_PIN_STM32_V0_H_INCLUDED
#define HAL_PIN_STM32_V0_H_INCLUDED

#if !defined(HAL_PIN_H_INCLUDED)
# error please do not include HAL library internals directly
#endif

#include <hal/arch/stm32/pin_common.h>
#include <libopencm3/cm3/nvic.h>

BEGIN_DECLS

/*****************************************************************************/

INLINE uint32_t _pin_port(const uint32_t pin)
{
	return pin & ~15;
}

INLINE uint32_t _pin_pin(const uint32_t pin)
{
	return 1 << (pin & 15);
}

INLINE uint32_t _pin_pinno(const uint32_t pin)
{
	return pin & 15;
}

INLINE void pin_clock_enable(const uint32_t pin)
{
	switch (_pin_port(pin)) {
#if defined(GPIO_PORT_A_BASE)
	case GPIOA: rcc_periph_clock_enable(RCC_GPIOA); break;
#endif
#if defined(GPIO_PORT_B_BASE)
	case GPIOB: rcc_periph_clock_enable(RCC_GPIOB); break;
#endif
#if defined(GPIO_PORT_C_BASE)
	case GPIOC: rcc_periph_clock_enable(RCC_GPIOC); break;
#endif
#if defined(GPIO_PORT_D_BASE)
	case GPIOD: rcc_periph_clock_enable(RCC_GPIOD); break;
#endif
#if defined(GPIO_PORT_E_BASE)
	case GPIOE: rcc_periph_clock_enable(RCC_GPIOE); break;
#endif
#if defined(GPIO_PORT_F_BASE)
	case GPIOF: rcc_periph_clock_enable(RCC_GPIOF); break;
#endif
#if defined(GPIO_PORT_G_BASE)
	case GPIOG: rcc_periph_clock_enable(RCC_GPIOG); break;
#endif
#if defined(GPIO_PORT_H_BASE)
	case GPIOH: rcc_periph_clock_enable(RCC_GPIOH); break;
#endif
#if defined(GPIO_PORT_I_BASE)
	case GPIOI: rcc_periph_clock_enable(RCC_GPIOI); break;
#endif
	default:
		break;
	}
}

INLINE void _pin_setmode(uint32_t pin, const uint32_t mode)
{
	const uint32_t pinid = (_pin_pinno(pin) < 8) ? (_pin_pin(pin)*4) : ((_pin_pin(pin)-8)*4);

	if (_pin_pinno(pin) < 8) {
		GPIO_CRL(_pin_port(pin)) = (mode << pinid) |
			(GPIO_CRL(_pin_port(pin)) & ~(0x0f << pinid));
	}
	else {
		GPIO_CRH(_pin_port(pin)) = (mode << pinid) |
			(GPIO_CRH(_pin_port(pin)) & ~(0x0f << pinid));
	}
}

INLINE void _pin_setspd(uint32_t pin, const uint32_t mode)
{
	if (_pin_pinno(pin) < 8) {
		const uint32_t bit = _pin_pinno(pin)*4;
		GPIO_CRL(_pin_port(pin)) = (mode << bit) |
			(GPIO_CRL(_pin_port(pin)) & ~(0x04 << bit));
	}
	else {
		const uint32_t bit = _pin_pinno(pin)*4 - 8*4;
		GPIO_CRH(_pin_port(pin)) = (mode << bit) |
			(GPIO_CRH(_pin_port(pin)) & ~(0x04 << bit));
	}
}

/******************************************************************************/

INLINE bool pin_get(const uint32_t pin)
{
	return (GPIO_IDR(_pin_port(pin)) & _pin_pin(pin)) != 0;
}

INLINE void pin_set(const uint32_t pin, bool val)
{
	GPIO_BSRR(_pin_port(pin)) = (val) ? _pin_pin(pin) : (_pin_pin(pin) << 16);
}

INLINE void pin_toggle(const uint32_t pin)
{
	uint32_t val = GPIO_ODR(_pin_port(pin));
	GPIO_BSRR(_pin_port(pin)) = ((val & _pin_pin(pin)) << 16) | (~val & _pin_pin(pin));
}

/******************************************************************************/
/* these are valid only when pin is input */

INLINE void pin_pull_disable(const uint32_t pin)
{
	_pin_setmode(pin, GPIO_MODE_INPUT | (GPIO_CNF_INPUT_FLOAT << 2));
}

INLINE void pin_pull_down(const uint32_t pin)
{
	pin_set(pin, false);
	_pin_setmode(pin, GPIO_MODE_INPUT | (GPIO_CNF_INPUT_PULL_UPDOWN << 2));
}

INLINE void pin_pull_up(const uint32_t pin)
{
	pin_set(pin, true);
	_pin_setmode(pin, GPIO_MODE_INPUT | (GPIO_CNF_INPUT_PULL_UPDOWN << 2));
}

/******************************************************************************/

INLINE void pin_output_pushpull(const uint32_t pin, const bool initial_state)
{
	_pin_setmode(pin, GPIO_MODE_OUTPUT_50_MHZ | (GPIO_CNF_OUTPUT_PUSHPULL << 2));
}

INLINE void pin_output_opendrain(const uint32_t pin)
{
	_pin_setmode(pin, GPIO_MODE_OUTPUT_50_MHZ | (GPIO_CNF_OUTPUT_OPENDRAIN << 2));
}

INLINE void pin_af_pushpull(const uint32_t pin)
{
	_pin_setmode(pin, GPIO_MODE_OUTPUT_50_MHZ | (GPIO_CNF_OUTPUT_ALTFN_PUSHPULL << 2));
}

INLINE void pin_af_opendrain(const uint32_t pin)
{
	_pin_setmode(pin, GPIO_MODE_OUTPUT_50_MHZ | (GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN << 2));
}

INLINE void pin_input(const uint32_t pin)
{
	_pin_setmode(pin, GPIO_MODE_INPUT | (GPIO_CNF_INPUT_FLOAT << 2));
}

INLINE void pin_analog(const uint32_t pin)
{
	_pin_setmode(pin, GPIO_MODE_INPUT | (GPIO_CNF_INPUT_ANALOG << 2));
}

/******************************************************************************/
/* these are valid only when pin is output */

INLINE void pin_speed_low(const uint32_t pin)
{
	_pin_setspd(pin, GPIO_MODE_OUTPUT_2_MHZ);
}

INLINE void pin_speed_medium(const uint32_t pin)
{
	_pin_setspd(pin, GPIO_MODE_OUTPUT_10_MHZ);
}

INLINE void pin_speed_fast(const uint32_t pin)
{
	_pin_setspd(pin, GPIO_MODE_OUTPUT_50_MHZ);
}

INLINE void pin_speed_high(const uint32_t pin)
{
	_pin_setspd(pin, GPIO_MODE_OUTPUT_50_MHZ);
}

/******************************************************************************/

INLINE void pin_af_map(const uint32_t pin, const uint32_t af)
{
	/* Makes no sense on this architecture */
	(void)pin;
	(void)af;
}

END_DECLS


#endif /* HAL_PIN_STM32_V1_H_INCLUDED */
