
#ifndef __STM32L475E_IOT01_HSENSOR_H
#define __STM32L475E_IOT01_HSENSOR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l475e_iot01.h"
#include "../Components/hts221/hts221.h"


typedef enum
{
  HSENSOR_OK = 0,
  HSENSOR_ERROR
}HSENSOR_Status_TypDef;



uint32_t BSP_HSENSOR_Init(void);
uint8_t  BSP_HSENSOR_ReadID(void);
float    BSP_HSENSOR_ReadHumidity(void);


#ifdef __cplusplus
}
#endif



#endif /* __STM32L475E_IOT01_HSENSOR_H */


