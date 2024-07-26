/*
 * registers.h
 *
 * Created: 8/29/2023 1:22:20 PM
 *  Author: LENOVO
 */ 




#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"
//macros
//*************  DIO REGISTERS  ***********//

//PORTA registers
#define PORTA *((volatile uint8_t*)0x3B) //8-bit register (write)
#define DDRA *((volatile uint8_t*)0x3A) //8-bit register (initialization)
#define PINA *((volatile uint8_t*)0x39) //8-bit register (read)  ; needs pullup to prevent floating pin

//PORTB registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

//PORTC registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

//PORTD registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

//addresses of ports, DDR and pins are consecutive
//each definition is an 8-bit registers

//Interrupt registers
#define MCUCR *((volatile uint8_t *)0x55)
#define MCUCSR *((volatile uint8_t *)0x54)
#define GICR *((volatile uint8_t *)0x5B)
#define GIFR *((volatile uint8_t *)0x5A)

//Timer0 registers
#define TCNT0 *((volatile uint8_t *)0x52)
#define TIFR *((volatile uint8_t *)0x58)
#define TCCR0 *((volatile uint8_t *)0x53)
#define TIMSK *((volatile uint8_t *)0x59)


#endif /* REGISTERS_H_ */