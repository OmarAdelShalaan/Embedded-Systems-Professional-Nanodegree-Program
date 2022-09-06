/*
 * delay.h
 *
 * Created: 9/5/2022 7:29:17 AM
 *  Author: Omar
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "../../MCAL/Timer_Driver/timer.h"

void delay();
void delay_us(uint16_t Time_delay);
void delay_ms(uint32_t Time_delay);




#endif /* DELAY_H_ */