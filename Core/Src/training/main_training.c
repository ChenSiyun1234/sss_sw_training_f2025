/*
 * main_training.c
 *
 *  Created on: Sep 22, 2025
 *      Author: dilgill
 */

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "main.h"

#include "gpio_training.h"

#define LED_PORT GPIOC
#define LED_PIN  13

int main(void)
{
	setup_training();

	rcc_enable(GPIO_C_ENABLE);
	/* The Blue Pill LED is active-low. Preload high so it starts off. */
	gpio_high(LED_PORT, LED_PIN);
	gpio_configureMode(LED_PORT, LED_PIN, GPIO_OUTPUT_PUSH_PULL, GPIO_LOW_SPEED);
	GPIO_VALUE led = GPIO_HIGH;

	/* Infinite loop */
	while (1)
	{
	  HAL_Delay(1000);
	  led = (led == GPIO_HIGH) ? GPIO_LOW : GPIO_HIGH;
	  gpio_set(LED_PORT, LED_PIN, led);
	}
}

