/*
 * application.h
 *
 * Created: 9/2/2023 2:25:32 PM
 *  Author: LENOVO
 */ 





#ifndef APPLICATION_H_
#define APPLICATION_H_

//#include "../MCAL/DIO/dio.h"
//#include "../MCAL/Interrupt Library/interrupts.h"  //MCAL should not be includded in application
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Motor Driver/motor.h"
#include "../Utility/registers.h"
#include "../Utility/types.h"

void app_init();

void LED_num_increment(void);

void app_start();





#endif /* APPLICATION_H_ */