
#include "stm32l475e_iot01_magneto.h"

static MAGNETO_DrvTypeDef  *MagnetoDrv;

MAGNETO_StatusTypeDef BSP_MAGNETO_Init(void)
{
  MAGNETO_StatusTypeDef ret = MAGNETO_OK;
  MAGNETO_InitTypeDef LIS3MDL_InitStructureMag;

  if(Lis3mdlMagDrv.ReadID() != I_AM_LIS3MDL)
  {
    ret = MAGNETO_ERROR;
  }
  else
  {
    /* Initialize the MAGNETO magnetometer driver structure */
    MagnetoDrv = &Lis3mdlMagDrv;
    
    /* MEMS configuration ------------------------------------------------------*/
    /* Fill the MAGNETO magnetometer structure */
    LIS3MDL_InitStructureMag.Register1 = LIS3MDL_MAG_TEMPSENSOR_DISABLE | LIS3MDL_MAG_OM_XY_HIGH | LIS3MDL_MAG_ODR_40_HZ;
    LIS3MDL_InitStructureMag.Register2 = LIS3MDL_MAG_FS_4_GA | LIS3MDL_MAG_REBOOT_DEFAULT | LIS3MDL_MAG_SOFT_RESET_DEFAULT;
    LIS3MDL_InitStructureMag.Register3 = LIS3MDL_MAG_CONFIG_NORMAL_MODE | LIS3MDL_MAG_CONTINUOUS_MODE;
    LIS3MDL_InitStructureMag.Register4 = LIS3MDL_MAG_OM_Z_HIGH | LIS3MDL_MAG_BLE_LSB;
    LIS3MDL_InitStructureMag.Register5 = LIS3MDL_MAG_BDU_MSBLSB;
    /* Configure the MAGNETO magnetometer main parameters */
    MagnetoDrv->Init(LIS3MDL_InitStructureMag);
  } 

  return ret;  
}

/**
  * @brief  DeInitialize the MAGNETO.
  */
void BSP_MAGNETO_DeInit(void)
{
  /* DeInitialize the  magnetometer IO interfaces */
  if(MagnetoDrv != NULL)
  {
    if(MagnetoDrv->DeInit != NULL)
    {
      MagnetoDrv->DeInit();
    }
  }
}

/**
  * @brief  Set/Unset the MAGNETO in low power mode.
  */
void BSP_MAGNETO_LowPower(uint16_t status)
{
  /* Put the magnetometer in low power mode */
  if(MagnetoDrv != NULL)
  {
    if(MagnetoDrv->LowPower != NULL)
    {
      MagnetoDrv->LowPower(status);
    }
  }
}

void BSP_MAGNETO_GetXYZ(int16_t *pDataXYZ)
{
  if(MagnetoDrv != NULL)
  {
    if(MagnetoDrv->GetXYZ != NULL)
    {   
      MagnetoDrv->GetXYZ(pDataXYZ);
    }
  }
}


