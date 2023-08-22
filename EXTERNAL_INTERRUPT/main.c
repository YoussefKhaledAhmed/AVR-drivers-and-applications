/**********************************************
 * Name: Youssef Khaled Ahmed
 * Date: 19/8/2023
 * Description: source file for testing the
 **********************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "dio.h"
#include "external_interrupt.h"

#define NULL (void *)0

void (*callBack_ptr)(void) = NULL;


void LED_toggle(void){
	TOGGLE_BIT(PORTA , PIN6_ID);

}


ISR(INT1_vect){
	LED_toggle();
	//	TOGGLE_BIT(PORTA , PIN6_ID);
}

int main(){
	DIO_PinConfiguration push_button = {INT1_PORT ,INT1_PIN};
	DIO_setupPinDirection(&push_button, PIN_INPUT);
	SET_BIT(PORTD , INT1_PIN);
	DIO_PinConfiguration LED = {PORTA_ID ,PIN6_ID};
	DIO_setupPinDirection(&LED, PIN_OUTPUT);
	DIO_writePin(&LED, LOGIC_LOW);
	EXTI_int1_nit();
	EXTI_init();
	while(1){

	}
	return 0;
}
