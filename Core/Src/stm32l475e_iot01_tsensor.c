
#include "stm32l475e_iot01_tsensor.h"

static TSENSOR_DrvTypeDef *tsensor_drv;  

uint32_t BSP_TSENSOR_Init(void)
{  
  uint8_t ret = TSENSOR_ERROR;

#ifdef USE_LPS22HB_TEMP
  tsensor_drv = &LPS22HB_T_Drv;
#else /* USE_HTS221_TEMP */
  tsensor_drv = &HTS221_T_Drv; 
#endif

  /* Low level init */
  SENSOR_IO_Init();

  /* TSENSOR Init */   
  tsensor_drv->Init(TSENSOR_I2C_ADDRESS, NULL);

  ret = TSENSOR_OK;
  
  return ret;
}


float BSP_TSENSOR_ReadTemp(void)
{ 
  return tsensor_drv->ReadTemp(TSENSOR_I2C_ADDRESS);
}



