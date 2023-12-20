/*
 * button.c
 *
 *  Created on: Dec 11, 2023
 *      Author: negar
 */
#include "button.h"


void Btn_init(GPIO_TypeDef* gpio, uint16_t pin) {
  // Mode: Input
  gpio->MODER &= ~(0x3 << (pin * 2));
  // Pull-Up
  gpio->PUPDR &= ~(0x3 << (pin * 2));
  gpio->PUPDR |= 0x1 << (pin * 2);
}
uint8_t Btn_read(GPIO_TypeDef* gpio, uint16_t pin) {
  return (gpio->IDR & (1 << pin)) != 0;
}

void Key_init(Key* keys, const Key_PinConfig* configs, uint32_t len) {
  while (len-- > 0) {
    keys->Config = configs;
    keys->State = Key_State_None;
    keys++;
    configs++;
  }
}

void Key_handle(Key* keys, uint32_t len) {
  while (len-- > 0) {
    keys->State = ((keys->State << 1) | HAL_GPIO_ReadPin(keys->Config->GPIO, keys->Config->Pin)) & 3;

    if (!keys->Handled && keys->Callbacks.fn[keys->State] != NULL) {
      keys->Handled = keys->Callbacks.fn[keys->State](keys, keys->State);
    }
    else if (keys->State == Key_State_None) {
      keys->Handled = 0;
    }

    keys++;
  }
}
