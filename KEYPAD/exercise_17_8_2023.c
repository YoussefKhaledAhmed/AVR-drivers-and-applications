/**********************************************
 * Name: Youssef Khaled Ahmed
 * Date: 17/8/2023
 * Description: testing keypad driver
 **********************************************/


#include "dio.h"
#include "lcd.h"
#include "keypad.h"
#include <util/delay.h>

int main(){
	KEYPAD_init();
	uint8 keypad_button_read_buffer;
	DIO_PinConfiguration LED_YELLOW = {PORTA_ID , PIN4_ID};
	DIO_setupPinDirection(&LED_YELLOW , PIN_OUTPUT);
	DIO_PinConfiguration LED_OTHER = {PORTA_ID , PIN3_ID};
	DIO_setupPinDirection(&LED_OTHER , PIN_OUTPUT);
	//	DIO_writePin(&LED_OTHER , LOGIC_LOW);
	LCD_init();

	while(1){
		KEYPAD_getPressedKey(&keypad_button_read_buffer);
		switch(keypad_button_read_buffer){
		case 7:
			LCD_displayCharacter('7');
			break;
		case 8:
			LCD_displayCharacter('8');
			break;
		case 9:
			LCD_displayCharacter('9');
			break;
		case '%':
			LCD_displayCharacter('%');
			break;
		case 4:
			LCD_displayCharacter('4');
			break;
		case 5:
			LCD_displayCharacter('5');
			break;
		case 6:
			LCD_displayCharacter('6');
			break;
		case '*':
			LCD_displayCharacter('*');
			break;
		case 1:
			LCD_displayCharacter('1');
			break;
		case 2:
			LCD_displayCharacter('2');
			break;
		case 3:
			LCD_displayCharacter('3');
			break;
		case '-':
			LCD_displayCharacter('-');
			break;
		case 13:
			LCD_displayCharacter('E'); /*Enter*/
			break;
		case 0:
			LCD_displayCharacter('0');
			break;
		case '=':
			LCD_displayCharacter('=');
			break;
		case '+':
			LCD_displayCharacter('+');
			break;
		}

	}
	return 0;
}
