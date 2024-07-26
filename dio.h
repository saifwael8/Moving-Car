/*
 * dio.h
 *
 * Created: 8/29/2023 1:42:43 PM
 *  Author: LENOVO
 */ 


#ifndef DIO_H_
#define DIO_H_

//Port definitions 
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//PINs definitions
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


//Direction definitions
#define IN 0
#define OUT 1

//Value definition 
#define HIGH 1
#define LOW 0

//Error handling
#define Valid_direction 100
#define Invalid_direction 101
#define Invalid_Port_num 102 
#define Invalid_value 103
#define Valid_value 104


#include "../../Utility/registers.h"
//#include "../Interrupt Library/interrupts.h"



uint8_t DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction);

uint8_t DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value);

uint8_t DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value); //value is ptr so it can change outside the function

uint8_t DIO_toggle(uint8_t portNum, uint8_t pinNum);


#endif /* DIO_H_ */