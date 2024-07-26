/*
 * timer.c
 *
 * Created: 9/9/2023 1:44:37 PM
 *  Author: LENOVO
 */ 
#include "timer.h"
//#define F_CPU 1000000UL //what does it mean?
#include <math.h>
#include <stdio.h>
#define over_flow_num 2000
#define timer_finished 1

unsigned int overflow_counter = 0;

uint8_t delay_ms(unsigned int ms)
{
	double overflow_num = (ms*(pow(10,-3)))/(256*(pow(10,-6)));  //use double when diving large numbers
	
	overflow_num = ceil(overflow_num);  
	
	TCCR0 |= (1<<0); //No Pre-scalar
	
	//waiting till all of the overflows are finished
	while(overflow_counter < overflow_num)
	{
		//checking on overflow
		while((TIFR & (1<<0)) == 0); //busy wait
	
		//Clear over flow flag (by writing 1 on the first bit)
		TIFR |= (1<<0);
		
		overflow_counter++;
	}
	overflow_counter = 0;
	
	//stop timer
	TCCR0 = 0x00;
	
	return timer_finished;
}


void timer0_init(void)
{
	//Normal mode
	TCCR0 = 0x00;
	
	//setting initial value
	TCNT0 = 0x00;
}



	

