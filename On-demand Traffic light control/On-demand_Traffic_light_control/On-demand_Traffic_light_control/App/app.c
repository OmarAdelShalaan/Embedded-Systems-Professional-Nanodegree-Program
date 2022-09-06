/*
 * app.c
 *
 * Created: 9/5/2022 12:43:52 PM
 *  Author: Omar
 */ 

#include "app.h"

LED_CAR_State LED_CAR_State_g = OFF;
void reset_init()
{
	DIO_init_pin(resetPORT, resetPIN, output);
	DIO_write_pin(resetPORT, resetPIN , LOW );
}
void reset()
{
	DIO_write_pin(resetPORT, resetPIN , High);
}
void LED_OFF_all()
{
	// Car LED OFF
	LED_off(LED_Car_PORT,LED_Car_Pin_Green);
	LED_off(LED_Car_PORT,LED_Car_Pin_Yellow);
	LED_off(LED_Car_PORT,LED_Car_Pin_Red);
	// Pedestrian LED OFF
	LED_off(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Green);
	LED_off(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Yellow);
	LED_off(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Red);
}
void Car_LED_Green_ON_Pedestrian_LED_Red_ON()
{
	LED_CAR_State_g = GREEN;
	// Car LED Green ON & Pedestrian LED Red ON
	LED_on(LED_Car_PORT,LED_Car_Pin_Green);
	LED_on(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Red);
}
void Car_LED_Yellow_blinking_Pedestrian_LED_Yellow_blinking_with_delay()
{
	uint8_t count = 0;
	LED_CAR_State_g = YELLOW;
	// Car LED Yellow blinking & Pedestrian LED Yellow blinking
	while (count < 5)
	{
		LED_on(LED_Car_PORT,LED_Car_Pin_Yellow);
		LED_on(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Yellow);
		_delay_ms(500);
		LED_off(LED_Car_PORT,LED_Car_Pin_Yellow);
		LED_off(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Yellow);
		_delay_ms(500);
		count++;
	}
}
void Car_LED_Yellow_ON_Pedestrian_LED_Yellow_ON()
{
	LED_on(LED_Car_PORT,LED_Car_Pin_Yellow);
	LED_on(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Yellow);
}
void Car_LED_Yellow_OFF_Pedestrian_LED_Yellow_OFF()
{
	LED_off(LED_Car_PORT,LED_Car_Pin_Yellow);
	LED_off(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Yellow);
}
void Car_LED_Red_ON_Pedestrian_LED_Green_ON()
{
	LED_CAR_State_g = RED;
	// Car LED Red ON & Pedestrian LED Green ON
	LED_on(LED_Car_PORT,LED_Car_Pin_Red);
	LED_on(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Green);
}
void Car_LED_Yellow_blink_Pedestrian_LED_Green_ON_with_delay()
{
	uint8_t count = 0;
	while( count < 5)
	{
		LED_on(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Green);
		Car_LED_Yellow_ON_Pedestrian_LED_Yellow_ON();
		_delay_ms(500);
		Car_LED_Yellow_OFF_Pedestrian_LED_Yellow_OFF();
		_delay_ms(500);
		count++;
	}
}
void normal_mode()
{
	LED_OFF_all();
	Car_LED_Green_ON_Pedestrian_LED_Red_ON();
	_delay_ms(5000);
	LED_OFF_all();
	Car_LED_Yellow_blinking_Pedestrian_LED_Yellow_blinking_with_delay();
	LED_OFF_all();
	Car_LED_Red_ON_Pedestrian_LED_Green_ON();
	_delay_ms(5000);
	LED_OFF_all();
	Car_LED_Yellow_blinking_Pedestrian_LED_Yellow_blinking_with_delay();
}
void pedestrian_mode()
{
	// State 1 cars' Red LED is on, the pedestrian's Green LED
	if( LED_CAR_State_g == RED)
	{
		//Car_LED_Red_ON_Pedestrian_LED_Green_ON();
		//_delay_ms(5000);
		return;
	}
	// State 2 the cars' Green LED is on or the cars' Yellow LED is blinking
	else if ( LED_CAR_State_g == GREEN || LED_CAR_State_g == YELLOW )
	{
		LED_OFF_all();
		Car_LED_Yellow_blinking_Pedestrian_LED_Yellow_blinking_with_delay();
		Car_LED_Red_ON_Pedestrian_LED_Green_ON();
		_delay_ms(5000);
	}
	LED_OFF_all();
	Car_LED_Yellow_blinking_Pedestrian_LED_Yellow_blinking_with_delay();
	LED_OFF_all();
}
ISR(EXT_INT_0)
{
	cli(); // Turn off Interrupt
	pedestrian_mode();
	sei(); // Turn on Interrupt
}

void App_init()
{
	 // Car LED
	 LED_init(LED_Car_PORT,LED_Car_Pin_Green);
	 LED_init(LED_Car_PORT,LED_Car_Pin_Yellow);
	 LED_init(LED_Car_PORT,LED_Car_Pin_Red);
	 // Pedestrian LED
	 LED_init(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Green);
	 LED_init(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Yellow);
	 LED_init(LED_Pedestrian_PORT,LED_Pedestrian_Pin_Red);
	 // Enable INT0
	 EXT_INT0_sense_control(falling_edge);
	 EXT_INT0_enable();
	 sei();
}
void App_start()
{
	 while (1)
	 {
		 normal_mode();
	 }
}