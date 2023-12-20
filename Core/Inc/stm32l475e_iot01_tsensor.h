
#ifndef __STM32L475E_IOT01_TSENSOR_H
#define __STM32L475E_IOT01_TSENSOR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l475e_iot01.h"
#ifdef USE_LPS22HB_TEMP
#include "../Components/lps22hb/lps22hb.h"
#else /* USE_HTS221_TEMP */
#include "../Components/hts221/hts221.h"
#endif


typedef enum
{
  TSENSOR_OK = 0,
  TSENSOR_ERROR
}TSENSOR_Status_TypDef;


uint32_t BSP_TSENSOR_Init(void);
float BSP_TSENSOR_ReadTemp(void);


#ifdef __cplusplus
}
#endif



#endif /* __STM32L475E_IOT01_TSENSOR_H */


