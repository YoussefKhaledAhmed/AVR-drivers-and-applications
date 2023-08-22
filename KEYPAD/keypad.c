/***********************************************
 * Name: Youssef Khaled Ahmed
 * Date: 17/8/2023
 * Description: Source file for keypad driver
 ***********************************************/

#include <avr/io.h>
#include "keypad.h"
#include "dio.h"

void KEYPAD_init(){
	DIO_PinConfiguration pind3 ={PORTD_ID , PIN3_ID};
	DIO_PinConfiguration pind5 ={PORTD_ID , PIN5_ID};
	DIO_PinConfiguration pind6 ={PORTD_ID , PIN6_ID};
	DIO_PinConfiguration pind7 ={PORTD_ID , PIN7_ID};
	DIO_PinConfiguration pinc2 ={PORTC_ID , PIN2_ID};
	DIO_PinConfiguration pinc3 ={PORTC_ID , PIN3_ID};
	DIO_PinConfiguration pinc4 ={PORTC_ID , PIN4_ID};
	DIO_PinConfiguration pinc5 ={PORTC_ID , PIN5_ID};

	DIO_setupPinDirection(&pinc2, PIN_OUTPUT);
	DIO_setupPinDirection(&pinc3, PIN_OUTPUT);
	DIO_setupPinDirection(&pinc4, PIN_OUTPUT);
	DIO_setupPinDirection(&pinc5, PIN_OUTPUT);
	DIO_setupPinDirection(&pind3, PIN_OUTPUT);
	DIO_setupPinDirection(&pind5, PIN_OUTPUT);
	DIO_setupPinDirection(&pind6, PIN_OUTPUT);
	DIO_setupPinDirection(&pind7, PIN_OUTPUT);

	DIO_writePin(&pinc2, LOGIC_HIGH);
	DIO_writePin(&pinc3, LOGIC_HIGH);
	DIO_writePin(&pinc4, LOGIC_HIGH);
	DIO_writePin(&pinc5, LOGIC_HIGH);
	DIO_writePin(&pind3, LOGIC_HIGH);
	DIO_writePin(&pind5, LOGIC_HIGH);
	DIO_writePin(&pind6, LOGIC_HIGH);
	DIO_writePin(&pind7, LOGIC_HIGH);


}

STATUS KEYPAD_getPressedKey(keypad_button_read_buffer_type * read_buffer){
	uint8 col , row , button_number;
	uint8 keypad_row0_buttons_state_read_buffer;
	uint8 keypad_row1_buttons_state_read_buffer;
	uint8 keypad_row2_buttons_state_read_buffer;
	uint8 keypad_row3_buttons_state_read_buffer;


	DIO_PinConfiguration pind3 ={PORTD_ID , PIN3_ID};
	DIO_PinConfiguration pind5 ={PORTD_ID , PIN5_ID};
	DIO_PinConfiguration pind6 ={PORTD_ID , PIN6_ID};
	DIO_PinConfiguration pind7 ={PORTD_ID , PIN7_ID};
	DIO_PinConfiguration pinc2 ={PORTC_ID , PIN2_ID};
	DIO_PinConfiguration pinc3 ={PORTC_ID , PIN3_ID};
	DIO_PinConfiguration pinc4 ={PORTC_ID , PIN4_ID};
	DIO_PinConfiguration pinc5 ={PORTC_ID , PIN5_ID};

	DIO_setupPinDirection(&pinc2 , PIN_INPUT);
	DIO_setupPinDirection(&pinc3 , PIN_INPUT);
	DIO_setupPinDirection(&pinc4 , PIN_INPUT);
	DIO_setupPinDirection(&pinc5 , PIN_INPUT);

	while(1){
		for(col = 0 ; col<KEYPAD_TOTAL_NUM_OF_COLS ; col++){
			switch(col){
			case 0:
				DIO_setupPinDirection(&pind7 , PIN_OUTPUT);
				DIO_setupPinDirection(&pind6 , PIN_INPUT);
				DIO_setupPinDirection(&pind5 , PIN_INPUT);
				DIO_setupPinDirection(&pind3 , PIN_INPUT);
				DIO_writePin(&pind3, KEYPAD_BUTTON_PRESSED_STATE);
				break;
			case 1:
				DIO_setupPinDirection(&pind7 , PIN_INPUT);
				DIO_setupPinDirection(&pind6 , PIN_OUTPUT);
				DIO_setupPinDirection(&pind5 , PIN_INPUT);
				DIO_setupPinDirection(&pind3 , PIN_INPUT);
				DIO_writePin(&pind5, KEYPAD_BUTTON_PRESSED_STATE);
				break;
			case 2:
				DIO_setupPinDirection(&pind7 , PIN_INPUT);
				DIO_setupPinDirection(&pind6 , PIN_INPUT);
				DIO_setupPinDirection(&pind5 , PIN_OUTPUT);
				DIO_setupPinDirection(&pind3 , PIN_INPUT);
				DIO_writePin(&pind6, KEYPAD_BUTTON_PRESSED_STATE);
				break;
			case 3:
				DIO_setupPinDirection(&pind7 , PIN_INPUT);
				DIO_setupPinDirection(&pind6 , PIN_INPUT);
				DIO_setupPinDirection(&pind5 , PIN_INPUT);
				DIO_setupPinDirection(&pind3 , PIN_OUTPUT);
				DIO_writePin(&pind7, KEYPAD_BUTTON_PRESSED_STATE);
				break;
			}
			for(row = 0 ; row<KEYPAD_TOTAL_NUM_OF_ROWS ; row++){
				DIO_readPin(&pinc5, &keypad_row0_buttons_state_read_buffer);
				DIO_readPin(&pinc4, &keypad_row1_buttons_state_read_buffer);
				DIO_readPin(&pinc3, &keypad_row2_buttons_state_read_buffer);
				DIO_readPin(&pinc2, &keypad_row3_buttons_state_read_buffer);

				if(KEYPAD_BUTTON_PRESSED_STATE == keypad_row0_buttons_state_read_buffer){

					button_number = (row_0*KEYPAD_TOTAL_NUM_OF_ROWS) + col;
					KEYPAD_4x4_adjustKeyNumber(&button_number, read_buffer);
					while(KEYPAD_BUTTON_PRESSED_STATE == keypad_row0_buttons_state_read_buffer){
						DIO_readPin(&pinc5, &keypad_row0_buttons_state_read_buffer);
					}
					return E_OK;

				} else if(KEYPAD_BUTTON_PRESSED_STATE == keypad_row1_buttons_state_read_buffer){

					button_number = (row_1*KEYPAD_TOTAL_NUM_OF_ROWS) + col;
					KEYPAD_4x4_adjustKeyNumber(&button_number, read_buffer);
					while(KEYPAD_BUTTON_PRESSED_STATE == keypad_row1_buttons_state_read_buffer){
						DIO_readPin(&pinc4, &keypad_row1_buttons_state_read_buffer);
					}
					return E_OK;
				} else if(KEYPAD_BUTTON_PRESSED_STATE == keypad_row2_buttons_state_read_buffer){

					button_number = (row_2*KEYPAD_TOTAL_NUM_OF_ROWS) + col;
					KEYPAD_4x4_adjustKeyNumber(&button_number, read_buffer);
					while(KEYPAD_BUTTON_PRESSED_STATE == keypad_row2_buttons_state_read_buffer){
						DIO_readPin(&pinc3, &keypad_row2_buttons_state_read_buffer);
					}
					return E_OK;

				} else if(KEYPAD_BUTTON_PRESSED_STATE == keypad_row3_buttons_state_read_buffer){

					button_number = (row_3*KEYPAD_TOTAL_NUM_OF_ROWS) + col;
					KEYPAD_4x4_adjustKeyNumber(&button_number, read_buffer);
					while(KEYPAD_BUTTON_PRESSED_STATE == keypad_row3_buttons_state_read_buffer){
						DIO_readPin(&pinc2, &keypad_row3_buttons_state_read_buffer);
					}
					return E_OK;

				} else{ /* do nothing... */}
			}
//			col = 0;
		}
	}
	return E_NOK;
}


STATUS KEYPAD_4x4_adjustKeyNumber(uint8* button_number , uint8* button_read_buffer){
	switch(*button_number){
	case 0:
		*button_read_buffer = 7 ;
		break;
	case 1:
		*button_read_buffer = 8 ;
		break;
	case 2:
		*button_read_buffer = 9 ;
		break;
	case 3:
		*button_read_buffer = '%';
		break;
	case 4:
		*button_read_buffer = 4 ;
		break;
	case 5:
		*button_read_buffer = 5 ;
		break;
	case 6:
		*button_read_buffer = 6 ;
		break;
	case 7:
		*button_read_buffer = '*' ;
		break;
	case 8:
		*button_read_buffer = 1 ;
		break;
	case 9:
		*button_read_buffer = 2 ;
		break;
	case 10:
		*button_read_buffer = 3 ;
		break;
	case 11:
		*button_read_buffer = '-' ;
		break;
	case 12:
		*button_read_buffer = 13 ; /*Ascii for enter*/
		break;
	case 13:
		*button_read_buffer = 0 ;
		break;
	case 14:
		*button_read_buffer = '=' ;
		break;
	case 15:
		*button_read_buffer = '+' ;
		break;
	default:
		return E_NOK;
	}
	return E_OK;
}
