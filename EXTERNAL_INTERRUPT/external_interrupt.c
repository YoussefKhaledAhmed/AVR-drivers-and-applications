/******************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 19/8/2023
 * Description: source file for external interrupt
 ******************************************************/
#include <avr/io.h>
#include "common_macros.h"
#include "external_interrupt.h"

void EXTI_init(void){
	SET_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM);
}


void EXTI_int0_nit(void){
	CLEAR_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM);
	uint8 MCUCR_replaceValue = (MCUCR & (0xFC)) | (INT0_MODE);
	MCUCR = MCUCR_replaceValue;
	SET_BIT(GICR , INT0);
}

void EXTI_int1_nit(void){
	CLEAR_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM);
	uint8 MCUCR_replaceValue = (MCUCR & (0xF3)) | (INT1_MODE<<2);
	MCUCR = MCUCR_replaceValue;
	SET_BIT(GICR , INT1);
}

void EXTI_int2_nit(void){
	CLEAR_BIT(SREG , GLOBAL_INTERRUPT_BIT_NUM);
	CLEAR_BIT(MCUCSR , ISC2);
	MCUCSR |= (INT2_MODE<<ISC2);
	SET_BIT(GICR , INT2);
}

