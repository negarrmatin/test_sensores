/**
  ******************************************************************************
  * @file    stm32l475e_iot01_hsensor.c
  * @author  MCD Application Team
  * @brief   This file provides a set of functions needed to manage the humidity sensor
  ******************************************************************************
  * @attention
  *
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l475e_iot01_hsensor.h"

static HSENSOR_DrvTypeDef *Hsensor_drv;  

uint32_t BSP_HSENSOR_Init(void)
{
  uint32_t ret;
  
  if(HTS221_H_Drv.ReadID(HTS221_I2C_ADDRESS) != HTS221_WHO_AM_I_VAL)
  {
    ret = HSENSOR_ERROR;
  }
  else
  {
    Hsensor_drv = &HTS221_H_Drv;
    /* HSENSOR Init */   
    Hsensor_drv->Init(HTS221_I2C_ADDRESS);
    ret = HSENSOR_OK;
  }
  
  return ret;
}

uint8_t BSP_HSENSOR_ReadID(void)
{ 
  return Hsensor_drv->ReadID(HTS221_I2C_ADDRESS);
}


float BSP_HSENSOR_ReadHumidity(void)
{ 
  return Hsensor_drv->ReadHumidity(HTS221_I2C_ADDRESS);
}


