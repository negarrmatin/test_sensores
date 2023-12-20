
#include "stm32l475e_iot01_psensor.h"

static PSENSOR_DrvTypeDef *Psensor_drv;  

uint32_t BSP_PSENSOR_Init(void)
{
  uint32_t ret;
   
  if(LPS22HB_P_Drv.ReadID(LPS22HB_I2C_ADDRESS) != LPS22HB_WHO_AM_I_VAL)
  {
    ret = PSENSOR_ERROR;
  }
  else
  {
     Psensor_drv = &LPS22HB_P_Drv;
     
    /* PSENSOR Init */   
    Psensor_drv->Init(LPS22HB_I2C_ADDRESS);
    ret = PSENSOR_OK;
  }
  
  return ret;
}


uint8_t BSP_PSENSOR_ReadID(void)
{ 
  return Psensor_drv->ReadID(LPS22HB_I2C_ADDRESS);
}

float BSP_PSENSOR_ReadPressure(void)
{ 
  return Psensor_drv->ReadPressure(LPS22HB_I2C_ADDRESS);
}


