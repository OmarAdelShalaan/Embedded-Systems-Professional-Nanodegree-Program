/*
 * timer.h
 *
 * Created: 8/26/2022 3:38:21 AM
 *  Author: Omar
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/ATmega_Register/register.h"




#define MICRO_UNIT 1000000
#define MILI_UNIT ( MICRO_UNIT / 1000 )
#define F_CPU	   1000000

typedef enum{
	Normal_mode,
	CTC_mode, // Clear Timer on Compare match
	}TimerMode;
typedef enum{
	CTC_normal,
	CTC_toggle,
	CTC_clear,
	CTC_set
	}CTC_mode_State;
	
typedef enum{
	prescaler_0 = 0,
	prescaler_1 = 1,
	prescaler_8 = 8,
	prescaler_64 = 64,
	prescaler_256 = 256,
	prescaler_1024 = 1024
	}prescaler;

void Timer0_init(TimerMode mode);
void Timer0_off();
/************************************************************************/
/* Normal Mode                                                          */
/************************************************************************/
void Timer0_normalMode(prescaler Prescaler);
void Timer0_read(uint8_t *timerData);
void Timer0_write(uint8_t timerdelay);
void Timer0_counter_rising_edge();
void Timer0_counter_falling_edge();
bool Timer0_overflow();
/**********************************************/
void Timer0_normalMode_squareWave();
/**********************************************/
/************************************************************************/
/* Clear Timer on Compare match (CTC) Mode						        */
/************************************************************************/
void Timer0_CTC_mode( CTC_mode_State State );
void Timer0_CTC_write_compare_value(uint8_t compare_value);
bool Timer0_CTC_occur();



#endif /* TIMER_H_ */

/*
from Data Sheet
TCNT0 for accessing Timer/Counter0 counter value and so on.
in the Timer/Counter Control Register (TCCR0). For details on clock sources and prescaler
BOTTOM The counter reaches the BOTTOM when it becomes 0x00.
MAX The counter reaches its MAXimum when it becomes 0xFF (decimal 255).
TOP The counter reaches the TOP when it becomes equal to the highest
	value in the count sequence. The TOP value can be assigned to be the
	fixed value 0xFF (MAX) or the value stored in the OCR0 Register. The
	assignment is dependent on the mode of operation.
The counting sequence is determined by the setting of the WGM01 and WGM00 bits located in
the Timer/Counter Control Register (TCCR0).
The Timer/Counter Overflow (TOV0) Flag
*/