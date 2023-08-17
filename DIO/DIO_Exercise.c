

#include <util/delay.h> /* To use the delay functions */
#include "DIO.h"
#include <avr/io.h>

int main(void)
{
	DIO_PinConfiguration LED = {PORTA_ID , PIN4_ID};


	DIO_setupPinDirection(&LED , PIN_OUTPUT);
	DIO_writePin(&LED , LOGIC_LOW);


	while(1)
	{
		_delay_ms(1000);
		DIO_writePin(&LED , LOGIC_HIGH);
		_delay_ms(1000);
		DIO_writePin(&LED , LOGIC_LOW);
	}
	return 0;
}


