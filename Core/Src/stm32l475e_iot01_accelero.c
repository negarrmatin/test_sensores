
#include "stm32l475e_iot01_accelero.h"

static ACCELERO_DrvTypeDef *AccelerometerDrv;  

ACCELERO_StatusTypeDef BSP_ACCELERO_Init(void)
{  
  ACCELERO_StatusTypeDef ret = ACCELERO_OK;
  uint16_t ctrl = 0x0000;
  ACCELERO_InitTypeDef LSM6DSL_InitStructure;

  if(Lsm6dslAccDrv.ReadID() != LSM6DSL_ACC_GYRO_WHO_AM_I)
  {
    ret = ACCELERO_ERROR;
  }
  else
  {
    /* Initialize the ACCELERO accelerometer driver structure */
    AccelerometerDrv = &Lsm6dslAccDrv;
  
    /* MEMS configuration ------------------------------------------------------*/
    /* Fill the ACCELERO accelerometer structure */
    LSM6DSL_InitStructure.AccOutput_DataRate = LSM6DSL_ODR_52Hz;
    LSM6DSL_InitStructure.Axes_Enable = 0;
    LSM6DSL_InitStructure.AccFull_Scale = LSM6DSL_ACC_FULLSCALE_2G;
    LSM6DSL_InitStructure.BlockData_Update = LSM6DSL_BDU_BLOCK_UPDATE;
    LSM6DSL_InitStructure.High_Resolution = 0;
    LSM6DSL_InitStructure.Communication_Mode = 0;
        
    /* Configure MEMS: data rate, full scale  */
    ctrl =  (LSM6DSL_InitStructure.AccOutput_DataRate | LSM6DSL_InitStructure.AccFull_Scale);
    
    /* Configure MEMS: BDU and Auto-increment for multi read/write */
    ctrl |= ((LSM6DSL_InitStructure.BlockData_Update | LSM6DSL_ACC_GYRO_IF_INC_ENABLED) << 8);

    /* Configure the ACCELERO accelerometer main parameters */
    AccelerometerDrv->Init(ctrl);
  }  

  return ret;
}

/**
  * @brief  DeInitialize the ACCELERO.
  * @retval None.
  */
void BSP_ACCELERO_DeInit(void)
{
  /* DeInitialize the accelerometer IO interfaces */
  if(AccelerometerDrv != NULL)
  {
    if(AccelerometerDrv->DeInit != NULL)
    {
      AccelerometerDrv->DeInit();
    }
  }
}


void BSP_ACCELERO_LowPower(uint16_t status)
{
  /* Set/Unset the ACCELERO in low power mode */
  if(AccelerometerDrv != NULL)
  {
    if(AccelerometerDrv->LowPower != NULL)
    {
      AccelerometerDrv->LowPower(status);
    }
  }
}

void BSP_ACCELERO_AccGetXYZ(int16_t *pDataXYZ)
{
  if(AccelerometerDrv != NULL)
  {
    if(AccelerometerDrv->GetXYZ != NULL)
    {   
      AccelerometerDrv->GetXYZ(pDataXYZ);
    }
  }
}



