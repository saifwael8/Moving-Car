/*
 * application.c
 *
 * Created: 9/2/2023 2:28:24 PM
 *  Author: LENOVO
 */ 
#include "application.h"
#define Led_number 7
#define Blink_number 4

#define DC_Hz 80
#define power_percentage_high 0.5
#define power_percentage_low 0.3
#define power_percentage_turning 0.4
#define long_distance_time 3000
#define short_distance_time 2000
#define turning_distance_time 2000
#define fast_Led_flag 0
#define slow_Led_flag 1
#define initial_delay_time 1000
#define initial_delay_press 0
#define car_stop 0
#define car_start 1


#define first_case 0
#define second_case 1
#define third_case 2
#define fourth_case 3
#define fifth_case 4
#define sixth_case 5
#define seventh_case 6
#define eighth_case 7


uint8_t static start_stop_button_flag = 0;
uint8_t static initial_delay_flag = 0;


 void start_button()
{
	start_stop_button_flag = 1;
}


 void stop_button()
{
	start_stop_button_flag = 0;
} 



void app_init()
{
	uint8_t err_pin1 = LED_init(PORT_B, PIN7);
	uint8_t err_pin2 = LED_init(PORT_D, PIN4);
	
	uint8_t err2 = LED_init(PORT_A, PIN0); //turning lights
	uint8_t err9 = LED_init(PORT_A, PIN5); //fast lights
	uint8_t err10 = LED_init(PORT_B, PIN1); //slow lights
	uint8_t err11 = LED_init(PORT_B, PIN6); //stop lights
	
	
	//Motor initialization
	uint8_t err3 = motor_init(PORT_A, PIN2); //motor 1
	uint8_t err4 = motor_init(PORT_B, PIN4); //motor 2
	uint8_t err5 = motor_init(PORT_C, PIN0); //motor 3
	uint8_t err8 = motor_init(PORT_D, PIN5); //motor 4

	
	uint8_t err6 = button_init(PORT_D, PIN2); //button 1
	uint8_t err7 = button_init(PORT_D, PIN3); //button 2

	if(err11 == Invalid_Port_num || err10 == Invalid_Port_num || err9 == Invalid_Port_num || err8 == Invalid_Port_num || err2 == Invalid_Port_num || err_pin2 == Invalid_Port_num ||err_pin1 == Invalid_Port_num || err3 == Invalid_Port_num || err4 == Invalid_Port_num || err5 == Invalid_Port_num || err6 == Invalid_Port_num || err7 == Invalid_Port_num)
	{
		LED_on(PORT_B, PIN7);
		LED_on(PORT_D, PIN4);
	}
	
	timer0_init();
	
	Interrupt_init();
}





void app_start()
{
	setCallback_0(stop_button);
	setCallback_1(start_button);
	while(1)
	{
		switch(start_stop_button_flag)
		{
			case first_case:
				break;
			case second_case:
				if(initial_delay_flag == initial_delay_press)
				{
					delay_ms(initial_delay_time); //initial delay after pressing button
					initial_delay_flag++;
				}
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				LED_on(PORT_A, PIN5);
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				motors_control(DC_Hz, power_percentage_high, long_distance_time, fast_Led_flag); //we will come out of this function with motors stopped
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				stop_motors();
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				turn_right(DC_Hz, power_percentage_turning, turning_distance_time);
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				stop_motors();
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				LED_on(PORT_B, PIN1);
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				motors_control(DC_Hz, power_percentage_high, short_distance_time, slow_Led_flag);
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				stop_motors();
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				turn_right(DC_Hz, power_percentage_turning, turning_distance_time);
				if(start_stop_button_flag == car_stop)
				{
					break;
				}
				stop_motors();
				break;
		}
	}
}


	





/*
Notes:
1) Includes is inside the #ifndef 

2) ISR function is called in the .c file outside of any function scope

3) Global variables are present in the .c file

4) Make the app layer as it will save so much time in debugging and will produce more organized code

5) Focus when determining the bits you are going to alter in the register

6) The error returned from wrong written value will be a hassle to detect, and this error is manufacturing error (which means that the does not have an access on altering the written value)

7) Take care of brackets in nested-switch case (cases does not require curly braces between them)
*/


//LED v3 code
/*
setCallback_0(LED_num_increment); //only needs to be valled once
setCallback_1(Blink_increment);
switch(LedNumber)
{
	case first_case:
	err1 = LED_off(PORT_A, PIN0);
	err2 = LED_off(PORT_A, PIN1);
	err3 = LED_off(PORT_A, PIN2);
	err4 = LED_off(PORT_A, PIN3);
	if(err1 == Invalid_Port_num || err2 == Invalid_Port_num || err3 == Invalid_Port_num || err4 == Invalid_Port_num)
	{
		err_led = LED_on(PORT_D, PIN4);
	}
	break;
	case second_case:
	switch(Blink)
	{
		case first_case:
		LED_toggle(PORT_A, PIN0);
		delay_ms(100);
		LED_toggle(PORT_A, PIN0);
		delay_ms(900);
		break;
		case second_case:
		LED_toggle(PORT_A, PIN0);
		delay_ms(200);
		LED_toggle(PORT_A, PIN0);
		delay_ms(800);
		break;
		case third_case:
		LED_toggle(PORT_A, PIN0);
		delay_ms(300);
		LED_toggle(PORT_A, PIN0);
		delay_ms(700);
		break;
		case fourth_case:
		LED_toggle(PORT_A, PIN0);
		delay_ms(500);
		LED_toggle(PORT_A, PIN0);
		delay_ms(500);
		break;
		case fifth_case:
		LED_toggle(PORT_A, PIN0);
		delay_ms(800);
		LED_toggle(PORT_A, PIN0);
		delay_ms(200);
		break;
	}
	
	break;
	case third_case:
	switch(Blink)
	{
		case first_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(100);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(900);
		break;
		case second_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(200);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(800);
		break;
		case third_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(300);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(700);
		break;
		case fourth_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(500);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(500);
		break;
		case fifth_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(800);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		delay_ms(200);
		break;
	}
	
	
	
	break;
	case fourth_case:
	switch(Blink)
	{
		case first_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(100);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(900);
		break;
		case second_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(200);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(800);
		break;
		case third_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(300);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(700);
		break;
		case fourth_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(500);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(500);
		break;
		case fifth_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(800);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		delay_ms(200);
		break;
	}
	
	
	
	break;
	case fifth_case:
	switch(Blink)
	{
		case first_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(100);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(900);
		break;
		case second_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		break;
		case third_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(300);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(700);
		break;
		case fourth_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		break;
		case fifth_case:
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		break;
	}
	
	
	
	break;
	case sixth_case:
	switch(Blink)
	{
		case first_case:
		LED_off(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(100);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(900);
		break;
		case second_case:
		LED_off(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		//LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		break;
		case third_case:
		LED_off(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(300);
		//LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(700);
		break;
		case fourth_case:
		LED_off(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		//LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		break;
		case fifth_case:
		LED_off(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		//LED_toggle(PORT_A, PIN0);
		LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		break;
	}
	
	
	break;
	case seventh_case:
	switch(Blink)
	{
		case first_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(100);
		//LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(900);
		break;
		case second_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		break;
		case third_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(300);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(700);
		break;
		case fourth_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		break;
		case fifth_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		break;
	}
	
	
	break;
	case eighth_case:
	switch(Blink)
	{
		case first_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(100);
		//LED_toggle(PORT_A, PIN1);
		//LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(900);
		break;
		case second_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		//LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		break;
		case third_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(300);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		//LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(700);
		break;
		case fourth_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		//LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(500);
		break;
		case fifth_case:
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(800);
		//LED_toggle(PORT_A, PIN0);
		//LED_toggle(PORT_A, PIN1);
		//LED_toggle(PORT_A, PIN2);
		LED_toggle(PORT_A, PIN3);
		delay_ms(200);
		break;
	}
	
	
	break;
}

*/