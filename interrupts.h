/*
 * interrupts.h
 *
 * Created: 9/2/2023 12:30:40 PM
 *  Author: LENOVO
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utility/types.h"
#include "../../Utility/registers.h"
#include <stdlib.h>


//Interrupt Vectors
#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define EXT_INT2 __vector_3

//void static (*INT0_func)(void) = NULL; //extern used for global variables in .h
//global variables should be defined in .c files

//Enabling global variables
#define sei() __asm__ __volatile__("sei" ::: "memory")

//Disabling global variables
#define cli() __asm__ __volatile__("cli" ::: "memory")

//ISR Macro definition
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal, used));\
void INT_VECT(void)

void setCallback_0(void (*func)(void));

void setCallback_1(void (*func)(void));

void Interrupt_init();




#endif /* INTERRUPTS_H_ */