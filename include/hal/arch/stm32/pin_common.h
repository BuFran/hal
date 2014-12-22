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
#ifndef HAL_PIN_STM32_COMMON_H_INCLUDED
#define HAL_PIN_STM32_COMMON_H_INCLUDED

#if !defined(HAL_PIN_H_INCLUDED)
# error please do not include HAL library internals directly
#endif

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

#if defined(GPIO_PORT_A_BASE)
#define PA0	(GPIOA | 0)
#define PA1	(GPIOA | 1)
#define PA2	(GPIOA | 2)
#define PA3	(GPIOA | 3)
#define PA4	(GPIOA | 4)
#define PA5	(GPIOA | 5)
#define PA6	(GPIOA | 6)
#define PA7	(GPIOA | 7)
#define PA8	(GPIOA | 8)
#define PA9	(GPIOA | 9)
#define PA10	(GPIOA | 10)
#define PA11	(GPIOA | 11)
#define PA12	(GPIOA | 12)
#define PA13	(GPIOA | 13)
#define PA14	(GPIOA | 14)
#define PA15	(GPIOA | 15)
#endif

#if defined(GPIO_PORT_B_BASE)
#define PB0	(GPIOB | 0)
#define PB1	(GPIOB | 1)
#define PB2	(GPIOB | 2)
#define PB3	(GPIOB | 3)
#define PB4	(GPIOB | 4)
#define PB5	(GPIOB | 5)
#define PB6	(GPIOB | 6)
#define PB7	(GPIOB | 7)
#define PB8	(GPIOB | 8)
#define PB9	(GPIOB | 9)
#define PB10	(GPIOB | 10)
#define PB11	(GPIOB | 11)
#define PB12	(GPIOB | 12)
#define PB13	(GPIOB | 13)
#define PB14	(GPIOB | 14)
#define PB15	(GPIOB | 15)
#endif

#if defined(GPIO_PORT_C_BASE)
#define PC0	(GPIOC | 0)
#define PC1	(GPIOC | 1)
#define PC2	(GPIOC | 2)
#define PC3	(GPIOC | 3)
#define PC4	(GPIOC | 4)
#define PC5	(GPIOC | 5)
#define PC6	(GPIOC | 6)
#define PC7	(GPIOC | 7)
#define PC8	(GPIOC | 8)
#define PC9	(GPIOC | 9)
#define PC10	(GPIOC | 10)
#define PC11	(GPIOC | 11)
#define PC12	(GPIOC | 12)
#define PC13	(GPIOC | 13)
#define PC14	(GPIOC | 14)
#define PC15	(GPIOC | 15)
#endif

#if defined(GPIO_PORT_D_BASE)
#define PD0	(GPIOD | 0)
#define PD1	(GPIOD | 1)
#define PD2	(GPIOD | 2)
#define PD3	(GPIOD | 3)
#define PD4	(GPIOD | 4)
#define PD5	(GPIOD | 5)
#define PD6	(GPIOD | 6)
#define PD7	(GPIOD | 7)
#define PD8	(GPIOD | 8)
#define PD9	(GPIOD | 9)
#define PD10	(GPIOD | 10)
#define PD11	(GPIOD | 11)
#define PD12	(GPIOD | 12)
#define PD13	(GPIOD | 13)
#define PD14	(GPIOD | 14)
#define PD15	(GPIOD | 15)
#endif

#if defined(GPIO_PORT_E_BASE)
#define PE0	(GPIOE | 0)
#define PE1	(GPIOE | 1)
#define PE2	(GPIOE | 2)
#define PE3	(GPIOE | 3)
#define PE4	(GPIOE | 4)
#define PE5	(GPIOE | 5)
#define PE6	(GPIOE | 6)
#define PE7	(GPIOE | 7)
#define PE8	(GPIOE | 8)
#define PE9	(GPIOE | 9)
#define PE10	(GPIOE | 10)
#define PE11	(GPIOE | 11)
#define PE12	(GPIOE | 12)
#define PE13	(GPIOE | 13)
#define PE14	(GPIOE | 14)
#define PE15	(GPIOE | 15)
#endif

#if defined(GPIO_PORT_F_BASE)
#define PF0	(GPIOF | 0)
#define PF1	(GPIOF | 1)
#define PF2	(GPIOF | 2)
#define PF3	(GPIOF | 3)
#define PF4	(GPIOF | 4)
#define PF5	(GPIOF | 5)
#define PF6	(GPIOF | 6)
#define PF7	(GPIOF | 7)
#define PF8	(GPIOF | 8)
#define PF9	(GPIOF | 9)
#define PF10	(GPIOF | 10)
#define PF11	(GPIOF | 11)
#define PF12	(GPIOF | 12)
#define PF13	(GPIOF | 13)
#define PF14	(GPIOF | 14)
#define PF15	(GPIOF | 15)
#endif

#if defined(GPIO_PORT_G_BASE)
#define PG0	(GPIOG | 0)
#define PG1	(GPIOG | 1)
#define PG2	(GPIOG | 2)
#define PG3	(GPIOG | 3)
#define PG4	(GPIOG | 4)
#define PG5	(GPIOG | 5)
#define PG6	(GPIOG | 6)
#define PG7	(GPIOG | 7)
#define PG8	(GPIOG | 8)
#define PG9	(GPIOG | 9)
#define PG10	(GPIOG | 10)
#define PG11	(GPIOG | 11)
#define PG12	(GPIOG | 12)
#define PG13	(GPIOG | 13)
#define PG14	(GPIOG | 14)
#define PG15	(GPIOG | 15)
#endif

#if defined(GPIO_PORT_H_BASE)
#define PH0	(GPIOH | 0)
#define PH1	(GPIOH | 1)
#define PH2	(GPIOH | 2)
#define PH3	(GPIOH | 3)
#define PH4	(GPIOH | 4)
#define PH5	(GPIOH | 5)
#define PH6	(GPIOH | 6)
#define PH7	(GPIOH | 7)
#define PH8	(GPIOH | 8)
#define PH9	(GPIOH | 9)
#define PH10	(GPIOH | 10)
#define PH11	(GPIOH | 11)
#define PH12	(GPIOH | 12)
#define PH13	(GPIOH | 13)
#define PH14	(GPIOH | 14)
#define PH15	(GPIOH | 15)
#endif

#if defined(GPIO_PORT_I_BASE)
#define PI0	(GPIOI | 0)
#define PI1	(GPIOI | 1)
#define PI2	(GPIOI | 2)
#define PI3	(GPIOI | 3)
#define PI4	(GPIOI | 4)
#define PI5	(GPIOI | 5)
#define PI6	(GPIOI | 6)
#define PI7	(GPIOI | 7)
#define PI8	(GPIOI | 8)
#define PI9	(GPIOI | 9)
#define PI10	(GPIOI | 10)
#define PI11	(GPIOI | 11)
#define PI12	(GPIOI | 12)
#define PI13	(GPIOI | 13)
#define PI14	(GPIOI | 14)
#define PI15	(GPIOI | 15)
#endif

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

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

END_DECLS

#endif /* HAL_PIN_STM32_COMMON_H_INCLUDED */