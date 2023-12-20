
#ifndef __STM32L475E_IOT01_MAGNETO_H
#define __STM32L475E_IOT01_MAGNETO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l475e_iot01.h"   
/* Include Magnetometer component driver */
#include "../Components/lis3mdl/lis3mdl.h"  
   

typedef enum 
{
  MAGNETO_OK = 0,
  MAGNETO_ERROR = 1,
  MAGNETO_TIMEOUT = 2
} 
MAGNETO_StatusTypeDef;

MAGNETO_StatusTypeDef BSP_MAGNETO_Init(void);
void BSP_MAGNETO_DeInit(void);
void BSP_MAGNETO_LowPower(uint16_t status); /* 0 Means Disable Low Power Mode, otherwise Low Power Mode is enabled */
void BSP_MAGNETO_GetXYZ(int16_t *pDataXYZ);


#ifdef __cplusplus
}
#endif

#endif /* __STM32L475E_IOT01_MAGNETO_H */


