/*
 * def.h
 *
 *  Created on: Mar 14, 2025
 *      Author: USER
 */

#ifndef COMMON_DEF_H_
#define COMMON_DEF_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#define bluetooth_rx_buffer_size 50 //블루투스로받은 문자열을 담는 buffer의 크기
#define bluetooth_tx_buffer_size 50 //블루투스틑 통해 master에 보낼 문자열을 담을 buffer
#define MAX_THROTTLE 20000
#define MIN_THROTTLE 10000

extern uint8_t bt_rx_flag;
extern uint8_t rb_rx_flag;
extern uint8_t bt_rx_data;
extern uint8_t rb_rx_data;
extern uint8_t system_tim_1ms_flag;



enum power_mode
{
  with_cali,     //전원연결시 esc calibration을 하고 시작
  except_esc_cali//전원연결시 esc calibration을 하지 않고 시작
};

extern float battery;
extern float current_roll;      //센서로부터 받은 roll 값  -> 이중 PID의 current_value
extern float current_pitch;     //센서로부터 받은 pitch 값 -> 이중 PID의 current_value
extern float current_yaw;       //센서로부터 받은 yaw 값   -> 단일 PID의 current_value
extern float current_roll_rate; //센서로부터 받은 자이로 x 값  -> 이중 PID의 rate
extern float current_pitch_rate;//센서로부터 받은 자이로 y 값  -> 이중 PID의 rate
extern float current_yaw_rate;  //센서로부터 받은 자이로 z 값  -> 단일 PID의 angle_velocity
extern float current_altitude;  //센서로부터 받은 고도  값  -> 단일 PID의 current_value

extern float target_roll;       //블루투스통신으로 받은 target_value -> 이중 PID의 target_value
extern float target_pitch;      //블루투스통신으로 받은 target_value -> 이중 PID의 target_value
extern float target_yaw;        //블루투스통신으로 받은 target_value -> 단일 PID의 target_value
extern float target_altitude;   //블루투스통신으로 받은 target_value -> 단일 PID의 target_value

extern float temp_yaw;
extern float temp_alt;
extern float temp_roll;
extern float temp_pitch;
extern float P_gain;            //SD-카드로부터 읽어온 P게인
extern float I_gain;            //SD-카드로부터 읽어온 I게인
extern float D_gain;            //SD-카드로부터 읽어온 D게인

extern bool is_System_Ready;    //전역 시스템 가능 변수
extern bool is_neutral;         //중립 여부 판단
extern bool is_controller_Ready;//컨트롤러 통신 연결 여부
extern bool is_battery_ok;      //배터리 잔량 여부
extern bool is_Rasberry_ok;     //라즈베리파이 통신 연결 여부

extern uint32_t motor_power[4]; //모터 추력값 저장 배열
extern uint8_t bluetooth_rx_buffer[bluetooth_rx_buffer_size]; //블루투스로통신받은 문자열을 담는 buffer
extern uint8_t bluetooth_tx_buffer[bluetooth_tx_buffer_size]; //블루통신을통해 master에 보낼 문자열을 담을 buffer

typedef struct _PIDSingle
{
  float Kd;
  float Ki;
  float Kp;

  float reference;
  float measured_value;
  float prev_measured_value;

  float error;
  float error_sum;
  float error_deriv;
  float filtered_error_deriv;

  float p_result;
  float i_result;
  float d_result;

  float pid_result;
}PIDSingle;

typedef struct _PIDDouble
{
  PIDSingle internal_PID;
  PIDSingle external_PID;
}PIDDouble;


extern PIDDouble roll;
extern PIDDouble pitch;
extern PIDSingle yaw_angle_neutral;
extern PIDSingle yaw_angle_velocity_non_neutral;
extern PIDSingle altitude;

extern UART_HandleTypeDef *active_huart;

extern void set_print_uart(UART_HandleTypeDef *huart);
#endif /* COMMON_DEF_H_ */
