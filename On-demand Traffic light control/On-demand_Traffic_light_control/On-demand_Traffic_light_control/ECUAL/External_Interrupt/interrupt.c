/*
 * interrupt.c
 *
 * Created: 8/29/2022 8:48:17 AM
 *  Author: Omar
 */ 

#include "interrupt.h"

void sei() //SREG -> Bit 7 is 1
{
	//SREG |= ( 1 << PIN7);
	DIO_init_reg( SREG, PIN7, high);
	
}
void cli() //SREG -> Bit 7 is 0
{
	//SREG &= ~( 1 << PIN7);
	DIO_init_reg( SREG, PIN7, input);
}

void EXT_INT0_enable()
{
	//GICR |= ( 1 << INT0);
	DIO_init_reg( GICR, INT0, out);
}
void EXT_INT1_enable()
{
	//GICR |= ( 1 << INT1);
	DIO_init_reg( GICR, INT1, out);
}
void EXT_INT2_enable()
{
	//GICR |= ( 1 << INT2);
	DIO_init_reg( GICR, INT2, out);
}

void EXT_INT0_disable()
{
	//GICR &= ~( 1 << INT0);
	DIO_init_reg( GICR, INT0, input);
}
void EXT_INT1_disable()
{
	//GICR &= ~( 1 << INT1);
	DIO_init_reg( GICR, INT1, input);
}
void EXT_INT2_disable()
{
	//GICR &= ~( 1 << INT2);
	DIO_init_reg( GICR, INT2, input);
}

void EXT_INT0_sense_control( Interrupt_Sense_Control Sense_Control )
{
	switch(Sense_Control)
	{
		case low_level:
// 			MCUCR &= ~( 1 << ISC00 );
// 			MCUCR &= ~( 1 << ISC01 );
			DIO_init_reg( MCUCR, ISC00, low);
			DIO_init_reg( MCUCR, ISC01, low);
			break;
		case logical_change:
// 			MCUCR |=  ( 1 << ISC00 );
// 			MCUCR &= ~( 1 << ISC01 );
			DIO_init_reg( MCUCR, ISC00, high);
			DIO_init_reg( MCUCR, ISC01, low);
			break;
		case falling_edge:
// 			MCUCR &= ~( 1 << ISC00 );
// 			MCUCR |=  ( 1 << ISC01 );
			DIO_init_reg( MCUCR, ISC00, low);
			DIO_init_reg( MCUCR, ISC01, high);
			break;
		case rising_edge:
// 			MCUCR |=  ( 1 << ISC00 );
// 			MCUCR |=  ( 1 << ISC01 );
			DIO_init_reg( MCUCR, ISC00, high);
			DIO_init_reg( MCUCR, ISC01, high);
			break;
	}
}
void EXT_INT1_sense_control(Interrupt_Sense_Control Sense_Control)
{
	switch(Sense_Control)
	{
		case low_level:
// 			MCUCR &= ~( 1 << ISC10 );
// 			MCUCR &= ~( 1 << ISC11 );
			DIO_init_reg( MCUCR, ISC10, low);
			DIO_init_reg( MCUCR, ISC11, low);
			break;
		case logical_change:
// 			MCUCR |=  ( 1 << ISC10 );
// 			MCUCR &= ~( 1 << ISC11 );
			DIO_init_reg( MCUCR, ISC10, high);
			DIO_init_reg( MCUCR, ISC11, low);
			break;
		case falling_edge:
// 			MCUCR &= ~( 1 << ISC10 );
// 			MCUCR |=  ( 1 << ISC11 );
			DIO_init_reg( MCUCR, ISC10, low);
			DIO_init_reg( MCUCR, ISC11, high);
			break;
		case rising_edge:
// 			MCUCR |=  ( 1 << ISC10 );
// 			MCUCR |=  ( 1 << ISC11 );
			DIO_init_reg( MCUCR, ISC10, high);
			DIO_init_reg( MCUCR, ISC11, high);
			break;
	}
}
void EXT_INT2_sense_control(Interrupt_Sense_Control Sense_Control)
{
	switch(Sense_Control)
	{
		case falling_edge:
			//MCUCSR &= ~( 1 << ISC2 );
			DIO_init_reg( MCUCSR, ISC2, low);
			break;
		case rising_edge:
			//MCUCSR |=  ( 1 << ISC2 );
			DIO_init_reg( MCUCSR, ISC2, high);
			break;
	}
}

