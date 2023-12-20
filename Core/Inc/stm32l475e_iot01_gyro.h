
#ifndef __STM32L475E_IOT01_GYRO_H
#define __STM32L475E_IOT01_GYRO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l475e_iot01.h"
/* Include Gyro component driver */
#include "../Components/lsm6dsl/lsm6dsl.h"   

typedef enum 
{
  GYRO_OK = 0,
  GYRO_ERROR = 1,
  GYRO_TIMEOUT = 2
} 
GYRO_StatusTypeDef;


uint8_t BSP_GYRO_Init(void); 
void BSP_GYRO_DeInit(void);
void BSP_GYRO_LowPower(uint16_t status);   /* 0 Means Disable Low Power Mode, otherwise Low Power Mode is enabled */
void BSP_GYRO_GetXYZ(float* pfData);



#ifdef __cplusplus
}
#endif

#endif /* __STM32L475E_IOT01_GYRO_H */


