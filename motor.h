/*
 * motor.h
 *
 * Created: 9/16/2023 3:15:52 PM
 *  Author: LENOVO
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../../MCAL/PWM/pwm.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Timer/timer.h"
#include <math.h>

uint8_t motor_init(uint8_t PortNum, uint8_t PinNum);

void motors_control(double Duty_cycle, float power_percentage, unsigned int time_ms, uint8_t Led_flag);

void turn_right(double Duty_cycle, float power_percentage, unsigned int time_ms);

void stop_motors(void);

//utility
void pwm_var_init(double Duty_cycle, float power_percentage, unsigned int time_ms);

#endif /* MOTOR_H_ */