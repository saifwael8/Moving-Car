/*
 * pwm.c
 *
 * Created: 9/16/2023 2:16:31 PM
 *  Author: LENOVO
 */ 
#include "pwm.h"

 

void pwm_init(void)
{
	//Normal mode
	TCCR0 = 0x00;
	
	//setting initial value
	TCNT0 = 0x00;
}

