
#ifndef __STM32L475E_IOT01_PSENSOR_H
#define __STM32L475E_IOT01_PSENSOR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l475e_iot01.h"
#include "../Components/lps22hb/lps22hb.h"


typedef enum
{
  PSENSOR_OK = 0,
  PSENSOR_ERROR
}PSENSOR_Status_TypDef;



uint32_t BSP_PSENSOR_Init(void);
uint8_t  BSP_PSENSOR_ReadID(void);
float    BSP_PSENSOR_ReadPressure(void);


#ifdef __cplusplus
}
#endif

#endif /* __STM32L475E_IOT01_PSENSOR_H */


