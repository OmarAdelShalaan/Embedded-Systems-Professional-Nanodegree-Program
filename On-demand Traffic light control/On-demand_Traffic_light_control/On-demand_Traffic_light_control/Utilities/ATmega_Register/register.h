/*
 * register.h
 *
 * Created: 8/24/2022 10:49:31 PM
 *  Author: Omar
 */ 

/************************************/
/* All Micro Controller Registers	*/
/************************************/

#ifndef REGISTER_H_
#define REGISTER_H_

#include "../Types/Platform_Types.h"

/************************************************************************/
/*  PIN Registers                                                       */
/************************************************************************/
#define p0 0
#define p1 1
#define p2 2
#define p3 3
#define p4 4
#define p5 5
#define p6 6
#define p7 7

#define P0 0
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/************************************************************************/
/*  DIO Registers                                                       */
/************************************************************************/

// PORT A
#define PORTA (*(volatile uint8_t * ) 0x3B)
#define DDRA  (*(volatile uint8_t * ) 0x3A)
#define PINA  (*(volatile uint8_t * ) 0x39)
// PORT B
#define PORTB (*(volatile uint8_t * ) 0x38)
#define DDRB  (*(volatile uint8_t * ) 0x37)
#define PINB  (*(volatile uint8_t * ) 0x36)
// PORT C
#define PORTC (*(volatile uint8_t * ) 0x35)
#define DDRC  (*(volatile uint8_t * ) 0x34)
#define PINC  (*(volatile uint8_t * ) 0x33)
// PORT D
#define PORTD (*(volatile uint8_t * ) 0x32)
#define DDRD  (*(volatile uint8_t * ) 0x31)
#define PIND  (*(volatile uint8_t * ) 0x30)

//#define      (*(volatile uint8_t * ) 0x )

#define SREG   (*(volatile uint8_t * ) 0x5F )
#define SPH    (*(volatile uint8_t * ) 0x5E )
#define SPL    (*(volatile uint8_t * ) 0x5D )
#define OCR0   (*(volatile uint8_t * ) 0x5C )
#define GICR   (*(volatile uint8_t * ) 0x5B )
#define GIFR   (*(volatile uint8_t * ) 0x5A )
#define TIMSK  (*(volatile uint8_t * ) 0x59 )
#define TIFR   (*(volatile uint8_t * ) 0x58 )
#define SPMCR  (*(volatile uint8_t * ) 0x57 )
#define TWCR   (*(volatile uint8_t * ) 0x56 )
#define MCUCR  (*(volatile uint8_t * ) 0x55 )
#define MCUCSR (*(volatile uint8_t * ) 0x54 )
#define TCCR0  (*(volatile uint8_t * ) 0x53 )
#define TCNT0  (*(volatile uint8_t * ) 0x52 )
#define OSCCAL (*(volatile uint8_t * ) 0x51 )
#define OCDR   (*(volatile uint8_t * ) 0x51 )
#define SFIOR  (*(volatile uint8_t * ) 0x50 )
#define TCCR1A (*(volatile uint8_t * ) 0x4F )
#define TCCR1B (*(volatile uint8_t * ) 0x4E )
#define TCNT1H (*(volatile uint8_t * ) 0x4D )
#define TCNT1L (*(volatile uint8_t * ) 0x4C )
#define OCR1AH (*(volatile uint8_t * ) 0x4B )
#define OCR1AL (*(volatile uint8_t * ) 0x4A )
#define OCR1BH (*(volatile uint8_t * ) 0x49 )
#define OCR1BL (*(volatile uint8_t * ) 0x48 )
#define ICR1H  (*(volatile uint8_t * ) 0x47 )
#define ICR1L  (*(volatile uint8_t * ) 0x46 )
#define TCCR2  (*(volatile uint8_t * ) 0x45 )
#define TCNT2  (*(volatile uint8_t * ) 0x44 )
#define OCR2   (*(volatile uint8_t * ) 0x43 )
#define ASSR   (*(volatile uint8_t * ) 0x42 )
#define WDTCR  (*(volatile uint8_t * ) 0x41 )
#define UBRRH  (*(volatile uint8_t * ) 0x40 )
#define UCSRC  (*(volatile uint8_t * ) 0x40 )
#define EEARH  (*(volatile uint8_t * ) 0x3F )
#define EEARL  (*(volatile uint8_t * ) 0x3E )
#define EEDR   (*(volatile uint8_t * ) 0x3D )
#define EECR   (*(volatile uint8_t * ) 0x3C )

/************************************************************************/
/* timer 0 PINS for prescaler       Timer/Counter0 (8 Bits)             */
/************************************************************************/
#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define WGM00  6
#define COM00  4
#define COM01  5
#define FOC0   7
#define TOV0   0
#define OCF0   0
#define TOIE0  0
#define OCIE0  1
/************************************************************************/
/* timer 1 PINS for prescaler                                           */
/************************************************************************/
#define CS10 0
#define CS11 1
#define CS12 2
/************************************************************************/
/* timer 2 PINS for prescaler        Timer/Counter2 (8 Bits)            */
/************************************************************************/
#define CS20  0
#define CS21  1
#define CS22  2

/************************************************************************/
/* External Interrupts                                                  */
/************************************************************************/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6
#define INT1  7
#define INT0  6
#define INT2  5
#endif /* REGISTER_H_ */