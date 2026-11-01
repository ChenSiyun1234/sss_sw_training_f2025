/*
 * gpio.c
 *
 * FOR SSS SOFTWARE FALL 2025 TRAINING
 *
 *
 *  Created on: Sep 21, 2025
 *      Author: nithinsenthil
 */

#include "gpio_training.h"

void gpio_high(GPIO_TypeDef *port, int pin) {
	port->BSRR = 1U << pin;
}

void gpio_low(GPIO_TypeDef *port, int pin) {
	port->BSRR = 1U << (pin + 16);
}

void gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value) {
	if (value == GPIO_HIGH) {
		gpio_high(port, pin);
	} else {
		gpio_low(port, pin);
	}
}

void gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_CNF cnf, GPIO_MODE mode) {
	volatile uint32_t *config = (pin < 8) ? &port->CRL : &port->CRH;
	uint32_t shift = (pin % 8) * 4U;
	uint32_t setting = ((uint32_t)cnf << 2) | (uint32_t)mode;

	/* Each pin owns four bits. Leave the other pins unchanged. */
	*config = (*config & ~(0xFU << shift)) | (setting << shift);
}

/*
 * Pls don't modify cause I will be sad D:
 */
void rcc_enable(RCC_SELECT reg) {
	RCC->APB2ENR |= reg;
}

