/*
 * PID_control.h
 *
 *  Created on: Mar 14, 2025
 *      Author: USER
 */

#ifndef INC_PID_CONTROL_H_
#define INC_PID_CONTROL_H_

#include "hw.h"



void PIDDouble_Calc(PIDDouble* axis, float target_value, float current_value, float rate);
void PIDSingle_Calc_yaw_angle(PIDSingle* axis, float target_value, float current_value, float rate); //스로틀 중립시 각도 제어
void PIDSingle_calc_yaw_angle_velocity(PIDSingle* axis, float target_value, float current_value);    //스로틀 중립이 아닐 시 각속도 제어
void PIDSingle_altitude_Calc(PIDSingle* altitude, float target_value, float current_value);
void Reset_PID_Integrator(PIDSingle* pid);
void Reset_All_PID_Integrator();
#endif /* INC_PID_CONTROL_H_ */
