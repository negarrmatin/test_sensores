/*
 * button.h
 *
 *  Created on: Dec 11, 2023
 *      Author: negar
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32l4xx_hal.h"

typedef enum {
  Key_State_Hold        = 0x00,
  Key_State_Released    = 0x01,
  Key_State_Pressed     = 0x02,
  Key_State_None        = 0x03,
} Key_State;

typedef struct {
  GPIO_TypeDef*         GPIO;
  uint16_t              Pin;
} Key_PinConfig;

struct __Key;
typedef struct __Key Key;

typedef uint8_t (*Key_CallbackFn)(Key* key, Key_State state);

typedef union {
  Key_CallbackFn      fn[4];
  struct {
    Key_CallbackFn    onHold;
    Key_CallbackFn    onReleased;
    Key_CallbackFn    onPressed;
    Key_CallbackFn    onNone;
  };
} Key_Callbacks;

struct __Key {
  const Key_PinConfig*  Config;
  Key_Callbacks         Callbacks;
  Key_State             State;
  uint8_t               Handled;
};

void Btn_init(GPIO_TypeDef* gpio, uint16_t pin);
uint8_t Btn_read(GPIO_TypeDef* gpio, uint16_t pin);
void Key_init(Key* keys, const Key_PinConfig* configs, uint32_t len);
void Key_handle(Key* keys, uint32_t len);


#endif /* INC_BUTTON_H_ */
