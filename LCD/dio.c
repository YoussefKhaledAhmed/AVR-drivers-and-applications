#include "dio.h"

#include <stdio.h>
#include <avr/io.h>


STATUS DIO_setupPinDirection(DIO_PinConfiguration * configurations, DIO_PinDirectionType direction){
	uint8 PORT = configurations->port_num;
	uint8 PIN = configurations->pin_num;
	switch(PORT){
	case PORTA_ID:
		if(PIN_OUTPUT == direction){
			SET_BIT(DDRA , PIN);
		} else if(PIN_INPUT == direction){
			CLEAR_BIT(DDRA , PIN);
		}
		break;
	case PORTB_ID:
		if(PIN_OUTPUT == direction){
			SET_BIT(DDRB , PIN);
		} else if(PIN_INPUT == direction){
			CLEAR_BIT(DDRB , PIN);
		}
		break;
	case PORTC_ID:
		if(PIN_OUTPUT == direction){
			SET_BIT(DDRC , PIN);
		} else if(PIN_INPUT == direction){
			CLEAR_BIT(DDRC , PIN);
		}
		break;
	case PORTD_ID:
		if(PIN_OUTPUT == direction){
			SET_BIT(DDRD , PIN);
		} else if(PIN_INPUT == direction){
			CLEAR_BIT(DDRD , PIN);
		}
		break;
	default:
		return E_NOK;
		break;
	}
	return E_OK;
}



STATUS DIO_writePin(DIO_PinConfiguration * configurations , uint8 write_value){
	uint8 PORT = configurations->port_num;
	uint8 PIN = configurations->pin_num;
	switch(PORT){
	case PORTA_ID:
		if(LOGIC_HIGH == write_value){
			SET_BIT(PORTA , PIN);
		} else if(LOGIC_LOW == write_value){
			CLEAR_BIT(PORTA , PIN);
		}
		break;
	case PORTB_ID:
		if(LOGIC_HIGH == write_value){
			SET_BIT(PORTB , PIN);
		} else if(LOGIC_LOW == write_value){
			CLEAR_BIT(PORTB , PIN);
		}
		break;
	case PORTC_ID:
		if(LOGIC_HIGH == write_value){
			SET_BIT(PORTC , PIN);
		} else if(LOGIC_LOW == write_value){
			CLEAR_BIT(PORTC , PIN);
		}
		break;
	case PORTD_ID:
		if(LOGIC_HIGH == write_value){
			SET_BIT(PORTD , configurations->pin_num);
		} else if(LOGIC_LOW == write_value){
			CLEAR_BIT(PORTD , configurations->pin_num);
		}
		break;
	default:
		return E_NOK;
		break;
	}
	return E_OK;
}

STATUS DIO_togglePin(DIO_PinConfiguration * configurations){
	uint8 PORT = configurations->port_num;
	uint8 PIN = configurations->pin_num;
	switch(PORT){
	case PORTA_ID:
		TOGGLE_BIT(PORTA , PIN);
		break;
	case PORTB_ID:
		TOGGLE_BIT(PORTB , PIN);
		break;
	case PORTC_ID:
		TOGGLE_BIT(PORTC , PIN);
		break;
	case PORTD_ID:
		TOGGLE_BIT(PORTD , PIN);
		break;
	default:
		return E_NOK;
		break;
	}
	return E_OK;
}


STATUS DIO_readPin(DIO_PinConfiguration * configurations, uint8 * read_buffer){
	uint8 PORT = configurations->port_num;
	uint8 PIN = configurations->pin_num;
	switch(PORT){
	case PORTA_ID:
		*read_buffer = GET_BIT(PINA , PIN);
		break;
	case PORTB_ID:
		*read_buffer = GET_BIT(PINB , PIN);
		break;
	case PORTC_ID:
		*read_buffer = GET_BIT(PINC , PIN);
		break;
	case PORTD_ID:
		*read_buffer = GET_BIT(PIND , PIN);
		break;
	default:
		return E_NOK;
		break;
	}
	return E_OK;
}


STATUS DIO_setupPortDirection(DIO_PortDirectionConfigurations * configurations){
	uint8 PORT = configurations->port_num;
	uint8 direction = configurations->direction;
	switch(PORT){
	case PORTA_ID:
		if(PORT_OUTPUT == direction){
			PORTA = PORT_OUTPUT;
		} else if(PORT_INPUT == direction){
			PORTA = PORT_INPUT;
		}
		break;
	case PORTB_ID:
		if(PORT_OUTPUT == direction){
			PORTB = PORT_OUTPUT;
		} else if(PORT_INPUT == direction){
			PORTB = PORT_INPUT;
		}
		break;
	case PORTC_ID:
		if(PORT_OUTPUT == direction){
			PORTC = PORT_OUTPUT;
		} else if(PORT_INPUT == direction){
			PORTC = PORT_INPUT;
		}
		break;
	case PORTD_ID:
		if(PORT_OUTPUT == direction){
			PORTD = PORT_OUTPUT;
		} else if(PORT_INPUT == direction){
			PORTD = PORT_INPUT;
		}
		break;
	default:
		return E_NOK;
		break;
	}
	return E_OK;
}


STATUS DIO_writePort(uint8 port_num , uint8 write_value){
	switch(port_num){
	case PORTA_ID:
		PORTA = write_value;
		break;
	case PORTB_ID:
		PORTB = write_value;
		break;
	case PORTC_ID:
		PORTC = write_value;
		break;
	case PORTD_ID:
		PORTD = write_value;
		break;
	default:
		return E_NOK;
		break;
	}
	return E_OK;
}


STATUS DIO_readPort(uint8 port_num , uint8* read_buffer){
	switch(port_num){
	case PORTA_ID:
		*read_buffer = PINA;
		break;
	case PORTB_ID:
		*read_buffer = PINB;
		break;
	case PORTC_ID:
		*read_buffer = PINC;
		break;
	case PORTD_ID:
		*read_buffer = PIND;
		break;
	default:
		return E_NOK;
		break;
	}
	return E_OK;
}
