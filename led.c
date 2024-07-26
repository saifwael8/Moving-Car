/*
 * led.c
 *
 * Created: 8/29/2023 3:30:29 PM
 *  Author: LENOVO
 */ 
#include "led.h"
#include <stdlib.h>

uint8_t LED_init(uint8_t ledPort, uint8_t ledPin) //output device (direction output)
{
	uint8_t Error_value = DIO_init(ledPort, ledPin, OUT);
	return Error_value;
}

uint8_t LED_on(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t Error_val = DIO_write(ledPort, ledPin, HIGH);
	return Error_val;
}

uint8_t LED_off(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t Err_val = DIO_write(ledPort, ledPin, LOW);
	return Err_val;
}

uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t err = DIO_toggle(ledPort, ledPin);
	return err;
}

