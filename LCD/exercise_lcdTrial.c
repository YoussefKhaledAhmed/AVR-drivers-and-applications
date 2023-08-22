/************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 18/8/2023
 * Description: Source file to test LCD driver
 ************************************************/

#include "lcd.h"

int main(){
	uint8 * data = "Youssef Khaled";
	LCD_init();
	LCD_displayString(data);
	while(1){

	}
	return 0;
}
