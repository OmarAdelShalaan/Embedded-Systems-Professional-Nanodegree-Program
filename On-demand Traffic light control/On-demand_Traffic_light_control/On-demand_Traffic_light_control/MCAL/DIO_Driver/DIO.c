/*
 * DIO.c
 *
 * Created: 8/24/2022 2:44:01 AM
 *  Author: Omar
 */ 


#include "DIO.h"


/*
 the Data Direction Register (DDRX) -> control/configuration register 
 control pin input/output
 if pin input  make DDRX -> 0 clear bit
 if pin output make DDRX -> 1 set bit

 the Port Register (PORTX)
 use to write pin 
 pull each pin high or low 
 pull high pin -> 1 == 5V
 pull low  pin -> 0 == 0V

 the Port Input Register (PINX)
 use to read pin
*/

void DIO_init_pin( portx PORTX, uint8_t PX, dirction in_out )
{
	switch( PORTX )
	{
		case porta:
			if( in_out == out)
			{
				DDRA |= (1 << PX);	
			}
			else if( in_out == input)
			{
				DDRA &= ~(1 << PX);
			}
			break;
		case portb:
			if( in_out == out)
			{
				DDRB |= (1 << PX);
			}
			else if( in_out == input)
			{
				DDRB &= ~(1 << PX);
			}
			break;
		case portc:
			if( in_out == out)
			{
				DDRC |= (1 << PX);
			}
			else if( in_out == input)
			{
				DDRC &= ~(1 << PX);
			}
			break;
		case portd:
			if( in_out == out)
			{
				DDRD |= (1 << PX);
			}
			else if( in_out == input)
			{
				DDRD &= ~(1 << PX);
			}
			break;
		
	}
}
void DIO_init_nibble( portx PORTX, nibble upper_lower, dirction in_out )
{
	switch( PORTX )
	{
		case porta:
			if( in_out == out)
			{
				if ( upper_lower == upper)
				{
					DDRA = ( DDRA | 0xF0 ); // make upper nibble output
				}
				else if ( upper_lower == lower)
				{
					DDRA = ( DDRA | 0x0F ); // make lower nibble output
				}
			}
			else if( in_out == input)
			{
				if ( upper_lower == upper)
				{
					DDRA = ( DDRA & 0x0F ); // make upper nibble input
				}
				else if ( upper_lower == lower)
				{
					DDRA = ( DDRA & 0xF0 ); // make lower nibble input
				}
			}
			break;
		case portb:
				if( in_out == out)
				{
					if ( upper_lower == upper)
					{
						DDRB = ( DDRB | 0xF0 ); // make upper nibble output
					}
					else if ( upper_lower == lower)
					{
						DDRB = ( DDRB | 0x0F ); // make lower nibble output
					}
				}
				else if( in_out == input)
				{
					if ( upper_lower == upper)
					{
						DDRB = ( DDRB & 0x0F ); // make upper nibble input
					}
					else if ( upper_lower == lower)
					{
						DDRB = ( DDRB & 0xF0 ); // make lower nibble input
					}
				}
				break;
			case portc:
				if( in_out == out)
				{
					if ( upper_lower == upper)
					{
						DDRC = ( DDRC | 0xF0 ); // make upper nibble output
					}
					else if ( upper_lower == lower)
					{
						DDRC = ( DDRC | 0x0F ); // make lower nibble output
					}
				}
				else if( in_out == input)
				{
					if ( upper_lower == upper)
					{
						DDRC = ( DDRC & 0x0F ); // make upper nibble input
					}
					else if ( upper_lower == lower)
					{
						DDRC = ( DDRC & 0xF0 ); // make lower nibble input
					}
				}
				break;
			case portd:
				if( in_out == out)
				{
					if ( upper_lower == upper)
					{
						DDRD = ( DDRD | 0xF0 ); // make upper nibble output
					}
					else if ( upper_lower == lower)
					{
						DDRD = ( DDRD | 0x0F ); // make lower nibble output
					}
				}
				else if( in_out == input)
				{
					if ( upper_lower == upper)
					{
						DDRD = ( DDRD & 0x0F ); // make upper nibble input
					}
					else if ( upper_lower == lower)
					{
						DDRD = ( DDRD & 0xF0 ); // make lower nibble input
					}
				}
				break;
	}
}
void DIO_init_port( portx PORTX, dirction in_out )
{
	switch( PORTX )
	{
		case porta:
			if( in_out == out)
			{
				DDRA = 0xFF; // make port A output
			}
			else if( in_out == input)
			{
				DDRA = 0x00; // make port A input
			}
			break;
		case portb:
			if( in_out == out)
			{
				DDRB = 0xFF;
			}
			else if( in_out == input)
			{
				DDRB = 0x00;
			}
			break;
		case portc:
			if( in_out == out)
			{
				DDRC = 0xFF;
			}
			else if( in_out == input)
			{
				DDRC = 0x00;
			}
			break;
		case portd:
			if( in_out == out)
			{
				DDRD = 0xFF;
			}
			else if( in_out == input)
			{
				DDRD = 0x00;
			}
			break;
	}
}
void DIO_init_group( portx PORTX, uint8_t startPin, uint8_t endPin, dirction in_out )
{
	uint8_t i;
	switch(PORTX)
	{
		case porta:
			if(in_out == out)
			{
				for (i = startPin; i <= endPin; i++)
				{
					 DIO_init_pin( porta, i , out );
				}
			}
			else if(in_out == input)
			{
				for (i = startPin; i <= endPin; i++)
				{
					DIO_init_pin( porta, i , input );
				}
			}
			break;
		case portb:
			if(in_out == out)
			{
				for (i = startPin; i <= endPin; i++)
				{
					DIO_init_pin( portb, i , out );
				}
			}
			else if(in_out == input)
			{
				for (i = startPin; i <= endPin; i++)
				{
					DIO_init_pin( portb, i , input );
				}
			}
			break;
		case portc:
			if(in_out == out)
			{
				for (i = startPin; i <= endPin; i++)
				{
					DIO_init_pin( portc, i , out );
				}
			}
			else if(in_out == input)
			{
				for (i = startPin; i <= endPin; i++)
				{
					DIO_init_pin( portc, i , input );
				}
			}
			break;
		case portd:
		if(in_out == out)
		{
			for (i = startPin; i <= endPin; i++)
			{
				DIO_init_pin( portd, i , out );
			}
		}
		else if(in_out == input)
		{
			for (i = startPin; i <= endPin; i++)
			{
				DIO_init_pin( portd, i , input );
			}
		}
		break;
	}
}

void DIO_read_pin( portx PORTX, uint8_t PX, uint8_t *ptrData)
{
	switch( PORTX )
	{
		case porta:
			*ptrData =  ( ( PINA & ( 1 << PX ) ) >> PX );
			break;
		case portb:
			*ptrData =  ( ( PINB & ( 1 << PX ) ) >> PX );
			break;
		case portc:
			*ptrData =  ( ( PINC & ( 1 << PX ) ) >> PX );
			break;
		case portd:
			*ptrData =  ( ( PIND & ( 1 << PX ) ) >> PX );
			break;
	
	}
}
void DIO_write_pin( portx PORTX, uint8_t PX, uint8_t data )
{
	switch( PORTX )
	{
		case porta:
			if( data == HIGH )
			{
				PORTA |= ( 1 << PX );
			}
			else if( data == LOW )
			{
				PORTA &= ~( 1 << PX );
			} 
			break;
		case portb:
			if( data == HIGH )
			{
				PORTB |= ( 1 << PX );
			}
			else if( data == LOW )
			{
				PORTB &= ~( 1 << PX );
			}
			break;
		case portc:
			if( data == HIGH )
			{
				PORTC |= ( 1 << PX );
			}
			else if( data == LOW )
			{
				PORTC &= ~( 1 << PX );
			}
			break;
		case portd:
			if( data == HIGH )
			{
				PORTD |= ( 1 << PX );
			}
			else if( data == LOW )
			{
				PORTD &= ~( 1 << PX );
			}
			break; 
		
	}
}
void DIO_write_nibble( portx PORTX, nibble upper_lower, uint8_t data )
{
	switch(PORTX)
	{
		case porta:
			if( upper_lower == upper)
			{
				PORTA = ( ( PORTA & 0x0F) | data );
			}
			else if( upper_lower == lower)
			{
				PORTA = ( ( PORTA & 0xF0) | data );
			}
			break;
		case portb:
			if( upper_lower == upper)
			{
				PORTB = ( ( PORTB & 0x0F) | data );
			}
			else if( upper_lower == lower)
			{
				PORTB = ( ( PORTB & 0xF0) | data );
			}
			break;
		case portc:	
			if( upper_lower == upper)
			{
				PORTC = ( ( PORTC & 0x0F) | data );
			}
			else if( upper_lower == lower)
			{
				PORTC = ( ( PORTC & 0xF0) | data );
			}
			break;
		case portd:
			if( upper_lower == upper)
			{
				PORTD = ( ( PORTD & 0x0F) | data );
			}
			else if( upper_lower == lower)
			{
				PORTD = ( ( PORTD & 0xF0) | data );
			}
			break;
	}
}
void DIO_write_port( portx PORTX, uint8_t data )
{
	switch(PORTX)
	{
		case porta:
			PORTA = data;
			break;
		case portb:
			PORTB = data;
			break;
		case portc:
			PORTC = data;
			break;
		case portd:
			PORTD = data;
			break;
	}
}



void DIO_toggle( portx PORTX, uint8_t PX )
{
	switch( PORTX )
	{
		case porta:
			PORTA ^= ( 1 << PX );
			break;
		case portb:
			PORTB ^= ( 1 << PX );
			break;
		case portc:
			PORTC ^= ( 1 << PX );
			break;
		case portd:
			PORTD ^= ( 1 << PX );
			break;
		
	}
}

// 
// void DIO_init_reg(uint8_t Reg, uint8_t PX, dirction in_out)
// {
// 	if(in_out == high)
// 	{
// 		Reg |= ( 1 << PX);
// 	}
// 	else if (in_out == low)
// 	{
// 		Reg &= ~( 1 << PX );
// 	}
// }