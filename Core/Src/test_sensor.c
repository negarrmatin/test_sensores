

#include "main.h"

int16_t pDataXYZ[3] = {0};
float pGyroDataXYZ[3] = {0};
char counter_buff[30];
uint8_t Pressure_flag;
uint8_t humidity_flag;
uint8_t Temperature_flag;


void Pressure_Test(void)
{

  float press_value = 0;
  Pressure_flag = 1;

  BSP_PSENSOR_Init();
  press_value = BSP_PSENSOR_ReadPressure();
  printf("PRESSURE is = %.2f mBar \r\n\n", press_value);
  ILI9341_Draw_Text("PRESSURE is : ", 10, 10, BLACK, 2, GREEN);
  sprintf(counter_buff, " %.2f", press_value);
  ILI9341_Draw_Text(counter_buff, 50, 50, BLACK, 2, GREEN);
  ILI9341_Draw_Text("mBar ", 145, 50, BLACK, 2, GREEN);

}

//......................
void Humidity_Test(void)
{

  float humidity_value = 0;
  humidity_flag = 1;

  BSP_HSENSOR_Init();
  ILI9341_Reset();
  humidity_value = BSP_HSENSOR_ReadHumidity();
  printf("HUMIDITY is = %.2f %%\r\n\n", humidity_value);
  ILI9341_Draw_Text("HUMIDITY is : ", 10, 10, BLACK, 2, GREEN);
  sprintf(counter_buff, " %.2f", humidity_value);
  ILI9341_Draw_Text(counter_buff, 50, 50, BLACK, 2, GREEN);
  ILI9341_Draw_Text("% ", 135, 50, BLACK, 2, GREEN);



}

//...........................
void Temperature_Test(void)
{

  float temp_value = 0;
  Temperature_flag = 1;
  /*
    HAL_I2C_Mem_Read(&hi2c2, HTS221_ADDR, 0x0F, I2C_MEMADD_SIZE_8BIT, &who_am_I, 1, 1000);
  uint32_t len = snprintf(str, sizeof(str) - 1,"who am I : %X\r\n", who_am_I);
  HAL_UART_Transmit(&huart1, (uint8_t *)str, len, 1000);

  HAL_I2C_Mem_Read(&hi2c2, HTS221_ADDR, 0x2A, I2C_MEMADD_SIZE_8BIT, buffer, sizeof(buffer), 1000);
  temp = buffer[0]| (uint16_t )buffer[1] << 8;
  len = snprintf(str, sizeof(str) - 1,"temp : %d\r\n", temp/8);
  HAL_UART_Transmit(&huart1, (uint8_t *)str, len, 1000);


  */
  BSP_TSENSOR_Init();
  temp_value = BSP_TSENSOR_ReadTemp();
  printf("TEMPERATURE is = %.2f C\r\n\n", temp_value);
  ILI9341_Draw_Text("TEMPERATURE is : ", 10, 10, BLACK, 2, GREEN);
  sprintf(counter_buff, " %.2f", temp_value);
  ILI9341_Draw_Text(counter_buff, 50, 50, BLACK, 2, GREEN);
  ILI9341_Draw_Text("C ", 135, 50, BLACK, 2, GREEN);

}

//................................
void Accelero_Test(void)
{

  BSP_ACCELERO_Init();
  BSP_ACCELERO_AccGetXYZ(pDataXYZ);
  printf("ACCELERO_X = %d \r\n", pDataXYZ[0]);
  printf("ACCELERO_Y = %d \r\n", pDataXYZ[1]);
  printf("ACCELERO_Z = %d \r\n\n", pDataXYZ[2]);

}
//...................................
void Gyro_Test(void)
{

  BSP_GYRO_Init();
  BSP_GYRO_GetXYZ(pGyroDataXYZ);
  printf("GYRO_X = %.2f \r\n", pGyroDataXYZ[0]);
  printf("GYRO_Y = %.2f \r\n", pGyroDataXYZ[1]);
  printf("GYRO_Z = %.2f \r\n\n", pGyroDataXYZ[2]);

}

//................................................
void Magneto_Test(void)
{

  BSP_MAGNETO_Init();
  BSP_MAGNETO_GetXYZ(pDataXYZ);
  printf("MAGNETO_X = %d \r\n", pDataXYZ[0]);
  printf("MAGNETO_Y = %d \r\n", pDataXYZ[1]);
  printf("MAGNETO_Z = %d \r\n\n", pDataXYZ[2]);


}
