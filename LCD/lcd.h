/************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 18/8/2023
 * Description: Header file for LCD driver
 ************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "lcd_cfg.h"


STATUS LCD_init(void);
STATUS LCD_sendCommand(uint8);
STATUS LCD_displayCharacter(uint8);
STATUS LCD_displayString(uint8 *);
STATUS LCD_moveCursor(uint8 , uint8);
STATUS LCD_displayStringRowCol(uint8 , uint8 , const uint8 *);
STATUS LCD_integerToString(int);
STATUS LCD_clearScreen(void);


#endif /* LCD_H_ */
