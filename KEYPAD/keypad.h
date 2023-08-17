/***********************************************
 * Name: Youssef Khaled Ahmed
 * Date: 17/8/2023
 * Description: Header file for keypad driver
 ***********************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "dio.h"
#include "common_macros.h"
#include "standardTypes.h"

#define keypad_button_read_buffer_type uint8

/* this is the total number of buttons in one *
 * column and row                             */
#define KEYPAD_TOTAL_NUM_OF_COLS 4
#define KEYPAD_TOTAL_NUM_OF_ROWS 4

/* this is the IDs of the port that the columns  *
 * and rows are connected to                     */
#define KEYPAD_COLUMNS_PORT_ID PORTD_ID
#define KEYPAD_ROWS_PORT_ID PORTC_ID

/* this is the first column and row IDs */
#define KEYPAD_COLUMN_FIRST_PIN_ID PIN3_ID
#define KEYPAD_ROW_FIRST_PIN_ID PIN2_ID

/* these are the states of the buttons in the keypad
 * where I can define that if I pressed the button I
 * should check on LOGIC_LOW state and vice versa*/
#define KEYPAD_BUTTON_PRESSED_STATE LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED_STATE LOGIC_HIGH

typedef enum{
	row_0 , row_1 , row_2 , row_3
} ROWS_ID;

#if(KEYPAD_BUTTON_PRESSED_STATE == KEYPAD_BUTTON_RELEASED_STATE)
#error("the states of the button are the same")
#endif

STATUS KEYPAD_getPressedKey(keypad_button_read_buffer_type *);
STATUS KEYPAD_4x4_adjustKeyNumber(uint8 * , uint8 *);

#endif /* KEYPAD_H_ */
