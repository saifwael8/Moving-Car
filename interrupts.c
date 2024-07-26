/*
 * interrupts.c
 *
 * Created: 9/3/2023 9:59:23 PM
 *  Author: LENOVO
 */ 
#include "interrupts.h"
#include <stdlib.h>



typedef enum
{
	PUSH_BUTTON_0 =  0,
	PUSH_BUTTON_1     ,
	TOTAL_BUTTONS
} enum_pushButton_index;

//global variable used to store function from app_start()  (used for int0)
void (*INT0_func)(void) = NULL;

//global variable used to store function from app_start()  (used for int1)
void (*INT1_func)(void) = NULL;

//typedef void (ptr_func_pb_callback) (enum_pushButton_index button_index);

//void 

void Interrupt_init()
{
	sei(); //Enabling global variables
	
	//Interrupt sensing configuration (rising edge)
	MCUCR |= (1<<0) | (1<<1); //INT0 sensing configuration
	MCUCR |= (1<<2) | (1<<3); //INT1 sensing configuration
	
	//Enabling interrupt on INT0
	GICR |= (1<<6);
	
	//Enabling interrupt on INT1
	GICR |= (1<<7);
}

void setCallback_0(void (*func)(void)) //prototype should be in .h file
{
	if(func != NULL)
	{
		INT0_func = func;
	}
}

void setCallback_1(void (*func)(void)) //prototype should be in .h file
{
	if(func != NULL)
	{
		INT1_func = func;
	}
}

//correct location of ISR
ISR(EXT_INT0)
{
	if(INT0_func != NULL)
	{
		INT0_func();	//pointer to function (holding the address of the led_increment function); previously ISR
	}
} 


ISR(EXT_INT1)
{
	if(INT1_func != NULL)
	{
		INT1_func();	//pointer to function (holding the address of the led_increment function); previously ISR
	}
}

//ISR should be in interrupts.h as the global variable used in it is defined in the interrupts.c, otherwise we will include the ECUAL in the MCAL which is not valid dependency as higher depends on lower but not the opposite
//ISR should be in the interrupts.h as the global variable is defined in the interrupts.c, otherwise we will define the global variable in the interrupts.h which is not valid (unless we use extern)