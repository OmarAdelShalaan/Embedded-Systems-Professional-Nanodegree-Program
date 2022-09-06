/*
 * LED.h
 *
 * Created: 8/25/2022 3:17:35 AM
 *  Author: Omar
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_Driver/DIO.h"

void LED_init(portx LedPort,uint8_t LedPin);
void LED_on(portx LedPort,uint8_t LedPin);
void LED_off(portx LedPort,uint8_t LedPin);
void LED_toggle(portx LedPort,uint8_t LedPin);


#endif /* LED_H_ */