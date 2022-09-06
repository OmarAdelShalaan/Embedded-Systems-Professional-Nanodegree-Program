/*
 * interrupt.h
 *
 * Created: 8/29/2022 8:47:48 AM
 *  Author: Omar
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../MCAl/DIO_Driver/DIO.h"

#define EXT_INT_0  __vector_1
#define EXT_INT_1  __vector_2
#define EXT_INT_2  __vector_3

#define ISR(INT_VECT)  void INT_VECT(void) __attribute__ (( signal ));\
void INT_VECT(void)

typedef enum{
	low_level,
	logical_change,
	falling_edge,
	rising_edge
	}Interrupt_Sense_Control;

void sei();//SREG -> Bit 7 is 1
void cli();//SREG -> Bit 7 is 0

void EXT_INT0_enable();
void EXT_INT1_enable();
void EXT_INT2_enable();

void EXT_INT0_disable();
void EXT_INT1_disable();
void EXT_INT2_disable();

void EXT_INT0_sense_control(Interrupt_Sense_Control);
void EXT_INT1_sense_control(Interrupt_Sense_Control);
void EXT_INT2_sense_control(Interrupt_Sense_Control);



#endif /* INTERRUPT_H_ */