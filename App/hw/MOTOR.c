/*
 * MOTOR.c
 *
 *  Created on: Mar 16, 2025
 *      Author: USER
 */


#include "MOTOR.h"



void ESC_CALI()
{
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, MAX_THROTTLE);//Throttle 1ms
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, MAX_THROTTLE);
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, MAX_THROTTLE);
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, MAX_THROTTLE);

	  HAL_Delay(3000);

	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, MIN_THROTTLE);//Throttle 1ms
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, MIN_THROTTLE);
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, MIN_THROTTLE);
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, MIN_THROTTLE);

	  HAL_Delay(5000);
}


void ESC_NO_CALI()
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, MIN_THROTTLE);//Throttle 1ms
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, MIN_THROTTLE);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, MIN_THROTTLE);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, MIN_THROTTLE);
	HAL_Delay(3000);
}

void SET_Throttle(uint32_t* motor_throttle)
{



}
