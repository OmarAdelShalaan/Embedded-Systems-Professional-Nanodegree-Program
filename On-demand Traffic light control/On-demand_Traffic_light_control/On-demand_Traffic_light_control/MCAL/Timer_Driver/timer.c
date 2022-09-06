/*
 * timer.c
 *
 * Created: 8/26/2022 3:38:31 AM
 *  Author: Omar
 */ 

#include "timer.h"


//TCNT0
//TCCR0 control in prescaler
/*
T_tick = 1/F_CPU = 1 /(F_CPU/prescaler) = prescaler/F_CPU
T_max_delay = T_tick * 2^n
Timer_initial_value = (T_max_delay - T_delay)/T_max
N_overflows = (ceil)(T_delay / T_max_delay)
Timer_initial_value = 2^n - (T_delay / T_tick) / N_overflows
*/

void Timer0_init(TimerMode mode)
{
	//Normal Mode
	if( mode == Normal_mode)
	{
		TCCR0 &= ~( 1 << WGM00 );
		TCCR0 &= ~( 1 << WGM01 );
	}
	// CTC Mode
	else if ( mode == CTC_mode )
	{
		TCCR0 &= ~( 1 << WGM00 );
		TCCR0 |=  ( 1 << WGM01 );
	}
}
void Timer0_normalMode(prescaler Prescaler)
{
	Timer0_init(Normal_mode);
	switch(Prescaler)
	{
		case prescaler_0:
			Timer0_off();
			break;
		case prescaler_1:
			TCCR0 |=  ( 1 << CS00 );
			TCCR0 &= ~( 1 << CS01 );
			TCCR0 &= ~( 1 << CS02 );
			break;
		case prescaler_8:
			TCCR0 &= ~( 1 << CS00 );
			TCCR0 |=  ( 1 << CS01 );
			TCCR0 &= ~( 1 << CS02 );
			break;
		case prescaler_64:
			TCCR0 |=  ( 1 << CS00 );
			TCCR0 |=  ( 1 << CS01 );
			TCCR0 &= ~( 1 << CS02 );
			break;
		case prescaler_256:
			TCCR0 &= ~( 1 << CS00 );
			TCCR0 &= ~( 1 << CS01 );
			TCCR0 |=  ( 1 << CS02 );
			break;
		case prescaler_1024:
			TCCR0 |=  ( 1 << CS00 );
			TCCR0 &= ~( 1 << CS01 );
			TCCR0 |=  ( 1 << CS02 );
			break;
	}
}
void Timer0_off()
{
	TCCR0 &= ~( 1 << CS00 );
	TCCR0 &= ~( 1 << CS01 );
	TCCR0 &= ~( 1 << CS02 );
}
void Timer0_read(uint8_t *timerData)
{
	*timerData = TCNT0;
}
void Timer0_write(uint8_t timerdelay)
{
	TCNT0 = timerdelay;
}
void Timer0_counter_rising_edge()
{
	TCCR0 |=  ( 1 << CS00 );
	TCCR0 |=  ( 1 << CS01 );
	TCCR0 |=  ( 1 << CS02 );
}
void Timer0_counter_falling_edge()
{
	TCCR0 &= ~( 1 << CS00 );
	TCCR0 |=  ( 1 << CS01 );
	TCCR0 |=  ( 1 << CS02 );
}
bool Timer0_overflow()
{
	if( ( ( TIFR & 1 << TOV0 ) >> TOV0 ) == High)
	{
		TIFR |= ( 1 << TOV0 );
		return True;
	}
	return False;
}
void Timer0_normalMode_squareWave()
{
	TCCR0 &= ~( 1 << COM00 );
	TCCR0 &= ~( 1 << COM01 );
}
/************************************************************************/
/*                                                                      */
/************************************************************************/


void Timer0_CTC_mode( CTC_mode_State State )
{
	Timer0_init( CTC_mode );
	if ( State == CTC_normal )
	{
// 		TCCR0 &= ~( 1 << COM00 );
// 		TCCR0 &= ~( 1 << COM01 );
	}
	else if ( State == CTC_toggle)
	{
		TCCR0 |=  ( 1 << COM00 );
		TCCR0 &= ~( 1 << COM01 );
	}
	else if ( State == CTC_clear )
	{
		TCCR0 &= ~( 1 << COM00 );
		TCCR0 |=  ( 1 << COM01 );
	}
	else if ( State == CTC_set)
	{
		TCCR0 |=  ( 1 << COM00 );	
		TCCR0 |=  ( 1 << COM01 );
	}
}
void Timer0_CTC_write_compare_value(uint8_t compare_value)
{
	OCR0 = compare_value;
}
bool Timer0_CTC_occur()
{
	if( ( ( TIFR & 1 << OCF0 ) >> OCF0 ) == High)
	{
		TIFR |= ( 1 << OCF0 );
		return True;
	}
	return False;
}
