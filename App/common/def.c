/*
 * def.c
 *
 *  Created on: Mar 17, 2025
 *      Author: USER
 */


#include "def.h"
  int __io_putchar(int ch);

  uint8_t bt_rx_flag;
  uint8_t rb_rx_flag;
  uint8_t bt_rx_data;
  uint8_t rb_rx_data;
  uint8_t system_tim_1ms_flag = 0;

  float battery = 0.0f;
  float current_roll = 0.0f;
  float current_pitch = 0.0f;
  float current_yaw = 0.0f;
  float current_roll_rate = 0.0f;
  float current_pitch_rate = 0.0f;
  float current_yaw_rate = 0.0f;
  float current_altitude = 0.0f;
  float target_roll ;
  float target_pitch;
  float target_yaw;
  float target_altitude;
  float P_gain = 0.0f;
  float I_gain = 0.0f;
  float D_gain = 0.0f;

  bool is_System_Ready = false;
  bool is_neutral = true;
  bool is_controller_Ready = false;
  bool is_battery_ok = true;
  bool is_Rasberry_ok = false;
  uint32_t motor_power[4] = {0,};

  uint8_t bluetooth_rx_buffer[bluetooth_rx_buffer_size]; //블루투스로통신받은 문자열을 담는 buffer
  uint8_t bluetooth_tx_buffer[bluetooth_tx_buffer_size]; //블루통신을통해 master에 보낼 문자열을 담을 buffer

  PIDDouble roll;
  PIDDouble pitch;
  PIDSingle yaw_angle_neutral;
  PIDSingle yaw_angle_velocity_non_neutral;
  PIDSingle altitude;

  UART_HandleTypeDef *active_huart=&huart2;

  void set_print_uart(UART_HandleTypeDef *huart)
  {
	  active_huart=huart;
  }

  int __io_putchar(int ch){
  	HAL_UART_Transmit(active_huart, &ch, 1, 1000);
    return ch;
  }
