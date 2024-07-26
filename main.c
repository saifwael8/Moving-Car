/*
 * My First Project.c
 * write high on pin 0 port A
 * Created: 8/26/2023 2:12:15 PM
 * Author : LENOVO
 */ 

#include "Application/application.h"
#define F_CPU 1000000UL //what does it mean?


#include "util/delay.h"

//#define F_CPU 1000000UL
//Declaring and initializing variables
//Writing logic that will be repeated only once

int main(void)
{
		
	app_init();
	
	app_start();
	
	
	//unit testing
	/* uint8_t err = LED_init(PORT_A, PIN0);
	uint8_t x = LED_init(PORT_D, PIN3);
	uint8_t err1 = LED_on(25, PIN0);
	
	if(err1 == Invalid_Port_num)
	{
		LED_on(PORT_D, PIN3);	
	} */
}
	
	
	
