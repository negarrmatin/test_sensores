
#ifndef __STM32L475E_IOT01_ACCELERO_H
#define __STM32L475E_IOT01_ACCELERO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l475e_iot01.h"
/* Include Accelero component driver */
#include "../Components/lsm6dsl/lsm6dsl.h"
   

typedef enum 
{
  ACCELERO_OK = 0,
  ACCELERO_ERROR = 1,
  ACCELERO_TIMEOUT = 2
} 
ACCELERO_StatusTypeDef;

ACCELERO_StatusTypeDef BSP_ACCELERO_Init(void);
void BSP_ACCELERO_DeInit(void);
void BSP_ACCELERO_LowPower(uint16_t status); /* 0 Means Disable Low Power Mode, otherwise Low Power Mode is enabled */
void BSP_ACCELERO_AccGetXYZ(int16_t *pDataXYZ);



#ifdef __cplusplus
}
#endif

#endif /* __STM32L475E_IOT01_ACCELERO_H */


