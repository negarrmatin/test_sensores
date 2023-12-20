/*
 * led.c
 *
 *  Created on: Dec 11, 2023
 *      Author: negar
 */
#include "led.h"

void Led_init(GPIO_TypeDef* gpio, uint16_t pin) {
  // Mode: Output
  gpio->MODER &= ~(0x3 << (pin * 2));
  gpio->MODER |= 0x1 << (pin * 2);
  // Output Type: Push-Pull
  gpio->OTYPER &= ~(0x1 << pin);
  // Speed: Very High
  gpio->OSPEEDR |= 0x3 << (pin * 2);
}
void Led_toggle(GPIO_TypeDef* gpio, uint16_t pin) {
  gpio->ODR ^= 1 << pin;
}
