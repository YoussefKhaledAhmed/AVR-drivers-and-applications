/************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 18/8/2023
 * Description: Source file for LCD driver
 ************************************************/
#include "lcd.h"
#include <util/delay.h>

STATUS LCD_init(void){
	DIO_PinConfiguration RS = {LCD_CMD_PORT_ID , LCD_RS};
	DIO_PinConfiguration EN = {LCD_CMD_PORT_ID , LCD_EN};

	DIO_PinConfiguration D4 = {LCD_DATA_PORT_ID , LCD_D4};
	DIO_PinConfiguration D5 = {LCD_DATA_PORT_ID , LCD_D5};
	DIO_PinConfiguration D6 = {LCD_DATA_PORT_ID , LCD_D6};
	DIO_PinConfiguration D7 = {LCD_DATA_PORT_ID , LCD_D7};

	DIO_setupPinDirection(&RS, PIN_OUTPUT);
	DIO_setupPinDirection(&EN, PIN_OUTPUT);

	DIO_setupPinDirection(&D4, PIN_OUTPUT);
	DIO_setupPinDirection(&D5, PIN_OUTPUT);
	DIO_setupPinDirection(&D6, PIN_OUTPUT);
	DIO_setupPinDirection(&D7, PIN_OUTPUT);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	_delay_ms(1);
	LCD_sendCommand(LCD_CURSOR_OFF);
	_delay_ms(1);
	LCD_sendCommand(LCD_CLEAR_COMMAND);
	_delay_ms(1);
	LCD_sendCommand(LCD_GO_TO_HOME);
	_delay_ms(1);


	return E_OK;
}



STATUS LCD_sendCommand(uint8 command){
	uint8 LCD_dataPortReadBuffer;
	uint8 LCD_value;
	DIO_PinConfiguration RS = {LCD_CMD_PORT_ID , LCD_RS};
	DIO_PinConfiguration EN = {LCD_CMD_PORT_ID , LCD_EN};

	DIO_writePin(&RS, LOGIC_LOW);
	_delay_ms(1);
	DIO_writePin(&EN, LOGIC_HIGH);
	_delay_ms(1);

	DIO_readPort(LCD_DATA_PORT_ID, &LCD_dataPortReadBuffer);
	LCD_value = (LCD_dataPortReadBuffer&0xE8) | ((command & 0x70)>>4) | ((command & 0x80)>>3);

	DIO_writePort(LCD_DATA_PORT_ID, LCD_value);
	_delay_ms(1);
	DIO_writePin(&EN, LOGIC_LOW);
	_delay_ms(1);

	DIO_writePin(&EN, LOGIC_HIGH);
	_delay_ms(1);

	DIO_readPort(LCD_DATA_PORT_ID, &LCD_dataPortReadBuffer);
	LCD_value = (LCD_dataPortReadBuffer&0xE8) | (command & 0x07) | ((command & 0x08)<<1);

	DIO_writePort(LCD_DATA_PORT_ID, LCD_value);
	_delay_ms(1);
	DIO_writePin(&EN, LOGIC_LOW);
	_delay_ms(1);
	return E_OK;
}


STATUS LCD_displayCharacter(uint8 data){
	uint8 LCD_dataPortReadBuffer;
	uint8 LCD_value;
	DIO_PinConfiguration RS = {LCD_CMD_PORT_ID , LCD_RS};
	DIO_PinConfiguration EN = {LCD_CMD_PORT_ID , LCD_EN};

	DIO_writePin(&RS, LOGIC_HIGH);
	_delay_ms(1);
	DIO_writePin(&EN, LOGIC_HIGH);
	_delay_ms(1);

	DIO_readPort(LCD_DATA_PORT_ID, &LCD_dataPortReadBuffer);
	LCD_value = (LCD_dataPortReadBuffer&0xE8) | ((data & 0x70)>>4) | ((data & 0x80)>>3);

	DIO_writePort(LCD_DATA_PORT_ID, LCD_value);
	_delay_ms(1);
	DIO_writePin(&EN, LOGIC_LOW);
	_delay_ms(1);

	DIO_writePin(&EN, LOGIC_HIGH);
	_delay_ms(1);

	DIO_readPort(LCD_DATA_PORT_ID, &LCD_dataPortReadBuffer);
	LCD_value = (LCD_dataPortReadBuffer&0xE8) | (data & 0x07) | ((data & 0x08)<<1);

	DIO_writePort(LCD_DATA_PORT_ID, LCD_value);
	_delay_ms(1);
	DIO_writePin(&EN, LOGIC_LOW);
	_delay_ms(1);
	return E_OK;
}


STATUS LCD_displayString(uint8* s){
	int i=0;
	while(s[i] != '\0'){
		LCD_displayCharacter(s[i]);
		i++;
	}
	return E_OK;
}


STATUS LCD_moveCursor(uint8 , uint8){

	return E_OK;
}
