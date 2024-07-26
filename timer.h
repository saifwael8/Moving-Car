/*
 * timer.h
 *
 * Created: 9/9/2023 1:44:53 PM
 *  Author: LENOVO
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utility/registers.h"

uint8_t delay_ms(unsigned int ms);

void timer0_init(void);


#endif /* TIMER_H_ */