/*
 * MOTOR.h
 *
 *  Created on: Mar 16, 2025
 *      Author: USER
 */

#ifndef HW_MOTOR_H_
#define HW_MOTOR_H_

#include "hw.h"

void ESC_CALI();
void ESC_NO_CALI();
void SET_Throttle(uint32_t* motor_throttle);
#endif /* HW_MOTOR_H_ */
