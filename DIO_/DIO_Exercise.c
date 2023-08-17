

#include <util/delay.h> /* To use the delay functions */
#include "DIO.h"
#include <avr/io.h>

int main(void)
{
	DIO_PinConfiguration LED = {PORTA_ID , PIN4_ID};
	DIO_PinDirectionConfigurations PIN3A_configurations =
	{&LED , PIN_OUTPUT};

	DIO_setupPinDirection(&PIN3A_configurations);
	DIO_writePin(&LED , LOGIC_LOW);


	while(1)
	{
		_delay_ms(1000);
		DIO_writePin(&LED , LOGIC_HIGH);
		_delay_ms(1000);
		DIO_writePin(&LED , LOGIC_LOW);
	}

//	SET_BIT(DDRA , PIN4_ID);
//	CLEAR_BIT(PORTA , PIN4_ID);
//	while(1){
//		SET_BIT(PORTA , PIN4_ID);
//		_delay_ms(1000);
//		CLEAR_BIT(PORTA , PIN4_ID);
//		_delay_ms(1000);
//	}
}


