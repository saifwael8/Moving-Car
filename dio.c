/*
 * dio.c
 *
 * Created: 8/29/2023 1:42:59 PM
 *  Author: LENOVO
 */ 
#include "dio.h"
#include "../Timer/timer.h"

//variable storing current state of write
uint8_t write_state = 0;


uint8_t DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction)
{
	switch(portNum)
	{
		case(PORT_A):
		{
			if(direction == OUT)
			{
				DDRA |= (1<<pinNum); //set pin (output)
				return Valid_direction;
			}
			else if(direction == IN)
			{
				DDRA &= ~(1<<pinNum); //clear pin (input)
				return Valid_direction;
			}	
			else
			{
				//error handling of wrong direction
				return Invalid_direction;
			}
		}
		case(PORT_B):
		{
			if(direction == OUT)
			{
				DDRB |= (1<<pinNum); //set pin (output)
				return Valid_direction;
			}
			else if(direction == IN)
			{
				DDRB &= ~(1<<pinNum); //clear pin (input)
				return Valid_direction;
			}
			else
			{
				//error handling of wrong direction
				return Invalid_direction;
			}
		}
		case(PORT_C):
		{
			if(direction == OUT)
			{
				DDRC |= (1<<pinNum); //set pin (output)
				return Valid_direction;
			}
			else if(direction == IN)
			{
				DDRC &= ~(1<<pinNum); //clear pin (input)
				return Valid_direction;
			}
			else
			{
				//error handling of wrong direction
				return Invalid_direction;
			}
		}
		case(PORT_D):
		{
			if(direction == OUT)
			{
				DDRD |= (1<<pinNum); //set pin (output)
				return Valid_direction;
			}
			else if(direction == IN)
			{
				DDRD &= ~(1<<pinNum); //clear pin (input)
				return Valid_direction;
			}
			else
			{
				//error handling of wrong direction
				return Invalid_direction;
			}
		}
		default:
		//error handling of wrong portNum
			return Invalid_Port_num;
	}
}

uint8_t DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value)
{
	switch(portNum)
	{
		case(PORT_A):
		{
			if(value == HIGH)
			{
				PORTA |= (1<<pinNum);
				write_state = HIGH;
				break;
			}
			else if(value == LOW)
			{
				PORTA &= ~(1<<pinNum);
				write_state = LOW;
				break;
			}
			else
			{
				//wrong value error handling (function will return a value representing the error)
				return Invalid_value;
			}
		}
		case(PORT_B):
		{
			if(value == HIGH)
			{
				PORTB |= (1<<pinNum);
				write_state = HIGH;
				break;
			}
			else if(value == LOW)
			{
				PORTB &= ~(1<<pinNum);
				write_state = LOW;
				break;
			}
			else
			{
				//wrong value error handling (function will return a value representing the error)
				return Invalid_value;
			}
		}
		case(PORT_C):
		{
			if(value == HIGH)
			{
				PORTC |= (1<<pinNum);
				write_state = HIGH;
				break;
			}
			else if(value == LOW)
			{
				PORTC &= ~(1<<pinNum);
				write_state = LOW;
				break;
			}
			else
			{
				//wrong value error handling (function will return a value representing the error)
				return Invalid_value;
			}
		}
		case(PORT_D):
		{
			if(value == HIGH)
			{
				PORTD |= (1<<pinNum);
				write_state = HIGH;
				break;
			}
			else if(value == LOW)
			{
				PORTD &= ~(1<<pinNum);
				write_state = LOW;
				break;
			}
			else
			{
				//wrong value error handling (function will return a value representing the error)
				return Invalid_value;
			}
		}
		default:
		//wrong value error handling
			return Invalid_Port_num;
		break;
	}
}

uint8_t DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value) //value is ptr so it can change outside the function
{
	switch(portNum)
	{
		case PORT_A:
		{
			*value = ((PINA & (1 << pinNum)) >> pinNum); //you read from pins and not ports, but write on ports
			break;
		}
		case PORT_B:
			*value = (PINB & (1<<pinNum))>>pinNum;
		break;
		case PORT_C:
			*value = (PINC & (1<<pinNum))>>pinNum;
		break;
		case PORT_D:
			*value = (PIND & (1<<pinNum))>>pinNum;
		break; 
		default:
		return Invalid_Port_num;
		//error handling
		break;
	}
}

uint8_t DIO_toggle(uint8_t portNum, uint8_t pinNum)
{
	uint8_t value;
	uint8_t err = DIO_read(portNum, pinNum, &value);
	if(value == HIGH)
	{
		DIO_write(portNum, pinNum, LOW);
		return Valid_value;
	}
	else if(value == LOW)
	{
		DIO_write(portNum, pinNum, HIGH);
		return Valid_value;
	}
	else
	{
		return Invalid_value;
	}
}





/* uint8_t get_write_state()
{
	return write_state;
} */

/*
void ISR(EXT_INT0)
{
	if(LedNum < 8)
	{
		LedNum++;
		return;
	}
	LedNum = 0;
}
*/

/* 

//cases will change by ISR
while(1)
{
	switch(LedNum)
	case 0:
	{
		LED_off(PORT_A, PIN0);	
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_off(PORT_A, PIN3);
	}
	case 1:
	{
		LED_on(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_off(PORT_A, PIN3);
	}
	case 2:
	{
		LED_on(PORT_A, PIN0);
		LED_on(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_off(PORT_A, PIN3);
	}
	case 3:
	{
		LED_on(PORT_A, PIN0);
		LED_on(PORT_A, PIN1);
		LED_on(PORT_A, PIN2);
		LED_off(PORT_A, PIN3);
	}
	case 4:
	{
		LED_on(PORT_A, PIN0);
		LED_on(PORT_A, PIN1);
		LED_on(PORT_A, PIN2);
		LED_on(PORT_A, PIN3);
	}
	case 5:
	{
		LED_off(PORT_A, PIN0);
		LED_on(PORT_A, PIN1);
		LED_on(PORT_A, PIN2);
		LED_on(PORT_A, PIN3);
	}
	case 6:
	{
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_on(PORT_A, PIN2);
		LED_on(PORT_A, PIN3);
	}
	case 7:
	{
		LED_off(PORT_A, PIN0);
		LED_off(PORT_A, PIN1);
		LED_off(PORT_A, PIN2);
		LED_on(PORT_A, PIN3);
	}
}

*/

//old algorithm without ISR
/*
while (1)
{
	_delay_ms(120);
	uint8_t buttonState = LOW;
	button_read(button1_port, PIN0, &buttonState);
	
	if(buttonState == HIGH)
	{
		if(counter > 3)
		{
			counter = 0;
			while(1)
			{
				button_read(button1_port, PIN0, &buttonState);
				_delay_ms(120);
				if(counter >= 4)
				{
					break;
				}
				else if(buttonState == HIGH)
				{
					LED_off(PORT_A, PIN0 + counter);
					counter++;
				}
				else if(buttonState == LOW)
				{
					
				}
			}
			counter = 0;
			continue;
		}
		
		LED_on(PORT_A, PIN0 + counter);
		counter++;
		//_delay_ms(500);
		//continue;
		//_delay_ms(500);
	}
	else if(buttonState == LOW) // else if completes the loop
	{
		//_delay_ms(500);
		//LED_off(PORT_A, PIN0);
		//counter++;
		//continue;
	}
	
	
	
} */