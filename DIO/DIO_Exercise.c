/********************************************
 * Name: Yousef Khaled Ahmed
 * Date: 17/8/2023
 ********************************************/

#include <util/delay.h> /* To use the delay functions */
#include "DIO.h"
#include <avr/io.h>

int main(void)
{
	uint8 read_buffer;
	DIO_PinConfiguration LED = {PORTA_ID , PIN4_ID};
	DIO_PinConfiguration push_button = {PORTC_ID , PIN2_ID};

	DIO_setupPinDirection(&LED , PIN_OUTPUT);
	DIO_setupPinDirection(&push_button , PIN_INPUT);
	DIO_writePin(&LED , LOGIC_LOW);

	while(1)
	{
		DIO_readPin(&push_button, &read_buffer);
		if(LOGIC_HIGH == read_buffer){
			_delay_ms(30);
			DIO_readPin(&push_button, &read_buffer);
			if(LOGIC_HIGH == read_buffer){
				DIO_togglePin(&LED);
			}
		}
	}
	return 0;
}


