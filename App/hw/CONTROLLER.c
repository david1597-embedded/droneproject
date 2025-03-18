/*
 * CONTROLLER.c
 *
 *  Created on: Mar 16, 2025
 *      Author: USER
 */

#include "CONTROLLER.h"


void bluetooth_init()
{

	is_controller_Ready=false;
	bt_rx_flag=0;
	bt_rx_data=0;
	rb_rx_data=0;
	rb_rx_flag=0;
	memset(bluetooth_rx_buffer, 0, bluetooth_rx_buffer_size); // 배열을 0으로 초기화
	memset(bluetooth_tx_buffer, 0, bluetooth_tx_buffer_size); // 배열을 0으로 초기화
	print_usart6_status();
}
//수신받은 문자열에서 조이스틱 값을 target값에 할당
void bluetooth_receive()
{
   //target_roll = 통신받은 roll 각도
   //target_pitch = 통신받은 pitch 각도
   //target_yaw = 통신받은 yaw 각도
   //target_altitude = 통신받은 고도
	//왼쪽 조이스틱

	        // "BLX:0.5,LY:-0.3,RX:-0.8,RY:1.0" 형식 가
	sscanf((uint8_t*)bluetooth_rx_buffer, "BLX:%.3f,LY:%.3f,RX:%.3f,RY:%.3f", &target_yaw, &target_altitude, &target_roll, &target_pitch);

}
void bluetooth_trasmint(char * packet)
{

}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
//	//라즈베리파이용
////	if(huart->Instance == USART2)
////	{
////		static uint8_t rx1Head = 0;
////
////		HAL_UART_Receive_IT(&huart2, &rx1Data, 1);
////	}
//	//블루트스용
	if(huart->Instance == USART6)
	{

//		static uint32_t toggle_counter = 0;
//	    toggle_counter++;
//		if (toggle_counter >= 5000) // 100번 인터럽트마다 토글
//		{
//			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//			toggle_counter = 0;
//		}
		//HEADER
		static uint8_t bt_rx_head = 0;
		if(bt_rx_data == '\n' || bt_rx_data == '\r' || bt_rx_data == '\0')
		{
			bluetooth_rx_buffer[bt_rx_head] = '\0';
			bt_rx_head = 0;
            bt_rx_flag = 1;
		}
		else
		{
			bluetooth_rx_buffer[bt_rx_head++] = bt_rx_data;
		}
     	HAL_UART_Receive_IT(&huart6,  &bt_rx_data, 1);
	}
}
void print_usart6_status()
{
    uint32_t cr1 = USART6->CR1;
    uint32_t sr = USART6->SR;
    uint8_t buffer[50];
    sprintf(buffer, "CR1: 0x%08X, SR: 0x%08X", cr1, sr);
    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 100);
}


