//................???

#include "stm32l475e_iot01_gyro.h"

static GYRO_DrvTypeDef *GyroscopeDrv;

uint8_t BSP_GYRO_Init(void)
{  
  uint8_t ret = GYRO_ERROR;
  uint16_t ctrl = 0x0000;
  GYRO_InitTypeDef LSM6DSL_InitStructure;

  if(Lsm6dslGyroDrv.ReadID() != LSM6DSL_ACC_GYRO_WHO_AM_I)
  {
    ret = GYRO_ERROR;
  }
  else
  {
    /* Initialize the gyroscope driver structure */
    GyroscopeDrv = &Lsm6dslGyroDrv;

    /* Configure Mems : data rate, power mode, full scale and axes */
    LSM6DSL_InitStructure.Power_Mode = 0;
    LSM6DSL_InitStructure.Output_DataRate = LSM6DSL_ODR_52Hz;
    LSM6DSL_InitStructure.Axes_Enable = 0;
    LSM6DSL_InitStructure.Band_Width = 0;
    LSM6DSL_InitStructure.BlockData_Update = LSM6DSL_BDU_BLOCK_UPDATE;
    LSM6DSL_InitStructure.Endianness = 0;
    LSM6DSL_InitStructure.Full_Scale = LSM6DSL_GYRO_FS_2000; 

    /* Configure MEMS: data rate, full scale  */
    ctrl = (LSM6DSL_InitStructure.Full_Scale | LSM6DSL_InitStructure.Output_DataRate);

    /* Configure MEMS: BDU and Auto-increment for multi read/write */
    ctrl |= ((LSM6DSL_InitStructure.BlockData_Update | LSM6DSL_ACC_GYRO_IF_INC_ENABLED) << 8);

    /* Initialize component */
    GyroscopeDrv->Init(ctrl);
    
    ret = GYRO_OK;
  }
  
  return ret;
}


/**
  * @brief  DeInitialize Gyroscope.
  */
void BSP_GYRO_DeInit(void)
{
  /* DeInitialize the Gyroscope IO interfaces */
  if(GyroscopeDrv != NULL)
  {
    if(GyroscopeDrv->DeInit!= NULL)
    {
      GyroscopeDrv->DeInit();
    }
  }
}


void BSP_GYRO_LowPower(uint16_t status)
{
  /* Set/Unset component in low-power mode */
  if(GyroscopeDrv != NULL)
  {
    if(GyroscopeDrv->LowPower!= NULL)
    {
      GyroscopeDrv->LowPower(status);
    }
  }
}

void BSP_GYRO_GetXYZ(float* pfData)
{
  if(GyroscopeDrv != NULL)
  {
    if(GyroscopeDrv->GetXYZ!= NULL)
    {
      GyroscopeDrv->GetXYZ(pfData);
    }
  }
}




