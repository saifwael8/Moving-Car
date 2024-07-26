/*
 * led.h
 *
 * Created: 8/29/2023 3:26:35 PM
 *  Author: LENOVO
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Interrupt Library/interrupts.h"
#include "../../MCAL/Timer/timer.h"
#include <stdlib.h>


uint8_t LED_init(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_on(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_off(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin);
void Interrupt_init(void);

#endif /* LED_H_ */