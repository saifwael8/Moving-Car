/*
 * button.h
 *
 * Created: 8/30/2023 4:51:12 PM
 *  Author: LENOVO
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../LED Driver/led.h"

#define button1_port PORT_C
#define button2_port PORT_D

//Button state
#define HIGH 1
#define LOW 0


//initializing the button
uint8_t button_init(uint8_t buttonPort, uint8_t buttonPin);

//read button state
uint8_t button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value);




#endif /* BUTTON_H_ */