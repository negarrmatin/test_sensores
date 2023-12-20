/*
 * led.h
 *
 *  Created on: Dec 11, 2023
 *      Author: negar
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32l4xx_hal.h"

void Led_init(GPIO_TypeDef* gpio, uint16_t pin);
void Led_toggle(GPIO_TypeDef* gpio, uint16_t pin);

#endif /* INC_LED_H_ */
