/*
 * hw.c
 *
 *  Created on: Mar 14, 2025
 *      Author: USER
 */

#include "hw.h"


void hwInit()
{
  MX_USART2_UART_Init();
  MX_USART6_UART_Init();
  //초기화 필요한 애들은 다 여기에
  bluetooth_init();
}

void delay(uint32_t time_ms)
{
  HAL_Delay(time_ms);
}

uint32_t millis()
{
  return HAL_Gettick();
}
