/******************************************************
 * Name: Youssef Khaled Ahmed
 * Date: 19/8/2023
 * Description: header file for external interrupt
 ******************************************************/

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "common_macros.h"
#include "dio.h"

#define GLOBAL_INTERRUPT_BIT_NUM 7

#define GLOBAL_INTERRUPT_ENABLE 1
#define GLOBAL_INTERRUPT_DISABLE 0

#define EXTERNAL_INT0 6
#define EXTERNAL_INT1 7
#define EXTERNAL_INT2 5

#define INT0_LOW_LEVEL 0
#define INT0_ANY_LOGICAL_CHANGE 1
#define INT0_FALLING_EDGE 2
#define INT0_RISING_EDGE 3

#define INT1_LOW_LEVEL 0
#define INT1_ANY_LOGICAL_CHANGE 1
#define INT1_FALLING_EDGE 2
#define INT1_RISING_EDGE 3

#define INT2_FALLING_EDGE 0
#define INT2_RISING_EDGE 1

#define INT0_MODE INT0_LOW_LEVEL
#define INT1_MODE INT1_FALLING_EDGE
#define INT2_MODE INT2_FALLING_EDGE

#define INT1_PORT PORTD_ID
#define INT1_PIN PIN3_ID


void EXTI_init(void);
void EXTI_int0_nit(void);
void EXTI_int1_nit(void);
void EXTI_int2_nit(void);


#endif /* EXTERNAL_INTERRUPT_H_ */
