/**********************************************
 * Name: Youssef Khaled Ahmed
 * Date: 17/8/2023
 * Description: testing keypad driver
 **********************************************/


#include "dio.h"
#include "keypad.h"

int main(){
	uint8 keypad_button_read_buffer;
	DIO_PinConfiguration LED = {PORTA_ID , PIN4_ID};

	DIO_setupPinDirection(&LED , PIN_OUTPUT);
	DIO_writePin(&LED , LOGIC_LOW);

	while(1){
		KEYPAD_getPressedKey(&keypad_button_read_buffer);
		if(1 == keypad_button_read_buffer){
			DIO_writePin(&LED , LOGIC_HIGH);
		}
//		if(2 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if(3 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if('C' == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if(4 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if(5 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if(6 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if('B' == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if(7 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if(8 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if(9 == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
//		if('A' == keypad_button_read_buffer){
//			DIO_writePin(&LED , LOGIC_HIGH);
//		}
		if('#' == keypad_button_read_buffer){
			DIO_writePin(&LED , LOGIC_LOW);
		}
	}
	return 0;
}
