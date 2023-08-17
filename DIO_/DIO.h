/********************************
 * Name: Youssef Khaled Ahmed
 * Date: 15/8/2023
 ********************************/


#ifndef GPIO_H_
#define GPIO_H_

#include "common_macros.h"
#include "standardTypes.h"

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7


typedef enum{
	PIN_INPUT , PIN_OUTPUT
}DIO_PinDirectionType;

typedef enum{
	PORT_INPUT, PORT_OUTPUT = 0xff
}DIO_PortDirectionType;

typedef struct{
	uint8 port_num;
	uint8 pin_num;
}DIO_PinConfiguration;

typedef struct{
	DIO_PinConfiguration * Pinconfiguration;
	DIO_PinDirectionType direction;
} DIO_PinDirectionConfigurations;


typedef struct{
	uint8 port_num;
	DIO_PortDirectionType direction;
} DIO_PortDirectionConfigurations;

/*declarations of the functions */
STATUS DIO_setupPinDirection(DIO_PinDirectionConfigurations * );
STATUS DIO_writePin(DIO_PinConfiguration * , uint8);
STATUS DIO_readPin(DIO_PinConfiguration * , uint8 *);
STATUS DIO_setupPortDirection(DIO_PortDirectionConfigurations *);
STATUS DIO_writePort(uint8 port_num , uint8 write_value);
STATUS DIO_readPort(uint8 port_num , uint8* read_buffer);

#endif /* GPIO_H_ */
