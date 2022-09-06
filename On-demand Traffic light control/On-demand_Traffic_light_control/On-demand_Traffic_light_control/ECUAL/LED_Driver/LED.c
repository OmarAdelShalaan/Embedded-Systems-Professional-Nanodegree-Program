/*
 * LED.c
 *
 * Created: 8/25/2022 3:17:46 AM
 *  Author: Omar
 */ 

#include "LED.h" 

void LED_init(portx LedPort,uint8_t LedPin)
{
	//DIO_init( portx PORTX, uint8_t PX, dirction in_out )
	DIO_init_pin(  LedPort, LedPin, out );
}
void LED_on(portx LedPort,uint8_t LedPin)
{
	//void DIO_write( portx PORTX, uint8_t PX, uint8_t data );
	DIO_write_pin(  LedPort, LedPin, HIGH );
}
void LED_off(portx LedPort,uint8_t LedPin)
{
	//void DIO_write( portx PORTX, uint8_t PX, uint8_t data );
	DIO_write_pin(  LedPort, LedPin, LOW );
}
void LED_toggle(portx LedPort,uint8_t LedPin)
{
	//void DIO_toggle( portx PORTX, uint8_t PX );
	DIO_toggle(  LedPort, LedPin );
}
