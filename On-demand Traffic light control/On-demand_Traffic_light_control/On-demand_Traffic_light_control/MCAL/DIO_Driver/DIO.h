/*
 * DIO.h
 *
 * Created: 8/24/2022 2:43:28 AM
 *  Author: Omar
 */ 

#ifndef  DIO_H_
#define  DIO_H_
// include register.h
#include "../../Utilities/ATmega_Register/register.h"

// all driver macros
// Value Define
#define  LOW  0
#define  HIGH 1

// enum of PORT 
typedef enum{
	porta,
	portb,
	portc,
	portd,
	port
	}portx;

typedef enum{
	upper = 0,
	upper_nibble = 0,
	lower = 1,
	lower_nibble = 1
	}nibble;

// Direction of PORT Define
typedef enum{
	//in = 0,
	input = 0,
	low = 0,
	out = 1,
	output = 1,
	high = 1,
	}dirction;
// macros
#define  DIO_init_reg( Reg, PINX, state)  (state)?(Reg |= ( 1 << PINX)):\
						(Reg &= ~( 1 << PINX) )	
// all driver function
void DIO_init_pin( portx PORTX, uint8_t PX, dirction in_out );
void DIO_init_nibble( portx PORTX, nibble upper_lower, dirction in_out );
void DIO_init_port( portx PORTX, dirction in_out );
void DIO_init_group( portx PORTX, uint8_t startPin, uint8_t endPin, dirction in_out );

void DIO_read_pin( portx PORTX, uint8_t PX, uint8_t *ptrData);

void DIO_write_pin( portx PORTX, uint8_t PX, uint8_t data );
void DIO_write_nibble( portx PORTX, nibble upper_lower, uint8_t data );
void DIO_write_port( portx PORTX, uint8_t data );
//void DIO_write_group( portx PORTX, uint8_t PX, uint8_t data );

void DIO_toggle( portx PORTX, uint8_t PX );

//void DIO_init_reg(uint8_t Reg, uint8_t PX, dirction in_out);

#endif 
