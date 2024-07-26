/*
 * motor.c
 *
 * Created: 9/16/2023 3:16:12 PM
 *  Author: LENOVO
 */ 
#include "motor.h"

//on-off pwm flag
uint8_t cycle_counter = 0;

//pwm global variables
double total_time = 0;
double t_ON = 0;
double t_OFF = 0;
double number_of_cycles = 0;

uint8_t Led_flag = 0;


uint8_t motor_init(uint8_t PortNum, uint8_t PinNum)
{
	pwm_init();
	uint8_t err = DIO_init(PortNum, PinNum, OUT); //as motors are actuator (output devices)
	return err;
}

void motors_control(double Duty_cycle, float power_percentage, unsigned int time_ms, uint8_t Led_flag)
{
	pwm_var_init(Duty_cycle, power_percentage, time_ms);
	
	//PWM
	while(cycle_counter < (number_of_cycles - (number_of_cycles * 0.4))) //subtracting the delays of other calls
	{
		//toggle motor
		DIO_toggle(PORT_A, PIN2);
		DIO_toggle(PORT_B, PIN4);
		DIO_toggle(PORT_C, PIN0);
		DIO_toggle(PORT_D, PIN5);
		delay_ms(t_ON);
		DIO_toggle(PORT_A, PIN2);
		DIO_toggle(PORT_B, PIN4);
		DIO_toggle(PORT_C, PIN0);
		DIO_toggle(PORT_D, PIN5);
		delay_ms(t_OFF);
		cycle_counter++; //increment after 1 cycle
	}
	cycle_counter = 0;
	if(Led_flag == 0)
	{
		LED_off(PORT_A, PIN5);
	}
	else if(Led_flag == 1)
	{
		LED_off(PORT_B, PIN1);
	}
}

void turn_right(double Duty_cycle, float power_percentage,  unsigned int time_ms)
{
	pwm_var_init(Duty_cycle, power_percentage, time_ms);
	LED_on(PORT_A, PIN0);
	while(cycle_counter < (number_of_cycles - (number_of_cycles * 0.4)))
	{
		DIO_toggle(PORT_A, PIN2);
		DIO_toggle(PORT_B, PIN4);
		delay_ms(t_ON);
		DIO_toggle(PORT_A, PIN2);
		DIO_toggle(PORT_B, PIN4);
		delay_ms(t_OFF);
		cycle_counter++;
	}	
	cycle_counter = 0;
	LED_off(PORT_A, PIN0);
}

void pwm_var_init(double Duty_cycle, float power_percentage, unsigned int time_ms)
{
	uint8_t temp = power_percentage * 10;
	power_percentage = temp / 10.0;
	total_time = (1/Duty_cycle)*(pow(10,3)); //conversion of Duty_cycle Hz to ms
	t_ON = power_percentage * total_time;
	t_OFF = total_time - t_ON;  //take care of data types
	number_of_cycles = time_ms / total_time;
	number_of_cycles = ceil(number_of_cycles);
}

void stop_motors(void)
{
	LED_on(PORT_B, PIN6);
	delay_ms(500);
	LED_off(PORT_B, PIN6);
}