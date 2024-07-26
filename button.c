/*
 * button.c
 *
 * Created: 8/30/2023 4:51:30 PM
 *  Author: LENOVO
 */ 
#include "button.h"

uint8_t button_init(uint8_t buttonPort, uint8_t buttonPin) //button is an input device therefore direction is in
{
	uint8_t Error_value = DIO_init(buttonPort, buttonPin, IN);
	return Error_value;
}

uint8_t button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value)
{
	uint8_t err_val = DIO_read(buttonPort, buttonPin, value);
	return err_val;
}