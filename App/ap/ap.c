/*
 * ap.c
 *
 *  Created on: Mar 14, 2025
 *      Author: USER
 */


#include "ap.h"

void apInit()
{
    hwInit();

}
//센서 데이터 받기, CALI()

void apMain()
{
	HAL_UART_Receive_IT(&huart6, &bt_rx_data, 1);
   while(1)
   {
       // PIDDouble_Calc(&roll, target_roll, current_roll, current_roll_rate);//roll회전 PID연산 후 저장
       // PIDDouble_Calc(&pitch, target_pitch,current_pitch,current_pitch_rate);//pitch회전 PID연산 후 저장
        if (bt_rx_flag == 1) {
//                    switch (bluetooth_rx_buffer[0]) {
//                        case 'A':
//                            // Calibration 로직
//                            // 여기에 Calibration 구현
//                            break;
//
//                        case 'B':
//                            bluetooth_receive();
//                            set_print_uart(&huart2);
//                            printf("LX:%.1f,LY:%.1f,RX:%.1f,RY:%.1f ", target_yaw, target_altitude, target_roll, target_pitch);
//                            break;
//
//                        default:
//                            // 잘못된 헤더 디버깅
//                            HAL_UART_Transmit(&huart2, (uint8_t*)"Unknown Command: ", 17, 100);
//                            HAL_UART_Transmit(&huart2, bluetooth_rx_buffer, strlen((char*)bluetooth_rx_buffer), 100);
//                            HAL_UART_Transmit(&huart2, (uint8_t*)"\n", 1, 100);
//                            break;
//                    }
//                    bt_rx_flag = 0;
        	if(bluetooth_rx_buffer[0] == 'B')
        	{

        		set_print_uart(&huart2);
        		printf(bluetooth_rx_buffer);//디버깅용 프린트
        		printf("\n");
//        		if(sscanf((char*)bluetooth_rx_buffer, "BLX:%.3f,LY:%.3f,RX:%.3f,RY:%.3f\n", &target_yaw, &target_altitude, &target_roll, &target_pitch)==4)
//        		{
//        			printf("SENT : LX:%.3f,LY:%.3f,RX:%.3f,RY:%.3f \r \n ", target_yaw, target_altitude, target_roll, target_pitch);
//        		}
        		char *token = strtok(bluetooth_rx_buffer, ":");

        		    // 값 추출
				while (token != NULL) {
					if (strcmp(token, "BLX") == 0) {
						token = strtok(NULL, ",");
						target_yaw = atof(token);  // 실수로 변환
					}
					else if (strcmp(token, "LY") == 0) {
						token = strtok(NULL, ",");
						target_altitude = atof(token);  // 실수로 변환
					}
					else if (strcmp(token, "RX") == 0) {
						token = strtok(NULL, ",");
						target_roll = atof(token);  // 실수로 변환
					}
					else if (strcmp(token, "RY") == 0) {
						token = strtok(NULL, ",");
						target_pitch = atof(token);  // 실수로 변환
					}

					// 다음 토큰으로 이동
					token = strtok(NULL, ":");
				}
				 printf("SENT : LX:%.3f,LY:%.3f,RX:%.3f,RY:%.3f \r \n ", target_yaw, target_altitude, target_roll, target_pitch);
        	}
        	bt_rx_flag=0;
	       // HAL_UART_Transmit(&huart2, (uint8_t*)"Unknown Command: \r\n ", 17, 100);
	       //HAL_Delay(1000);
        }
   }
}





