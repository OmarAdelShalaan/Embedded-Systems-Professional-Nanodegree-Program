/*
 * app.h
 *
 * Created: 9/5/2022 12:43:41 PM
 *  Author: Omar
 */ 


#ifndef APP_H_
#define APP_H_
/**************************************/
#include "../ECUAL/External_Interrupt/interrupt.h"
#include "../ECUAL/LED_Driver/LED.h"
#include "../ECUAL/Delay_Driver/delay.h"
/**************************************/
#define _delay_ms(delayValue) delay_ms(delayValue)
#define LED_Car_PORT        porta
#define LED_Car_Pin_Green	0
#define LED_Car_Pin_Yellow  1
#define LED_Car_Pin_Red     2

#define LED_Pedestrian_PORT			portb
#define LED_Pedestrian_Pin_Green    0
#define LED_Pedestrian_Pin_Yellow	1
#define LED_Pedestrian_Pin_Red		2
/**************************************/
#define resetPORT  portc
#define resetPIN   0
/**************************************/
typedef enum{
	OFF,
	GREEN,
	YELLOW,
	RED
}LED_CAR_State;
/************************************************************************/
/*  Function App                                                        */
/************************************************************************/
void normal_mode();
void pedestrian_mode();
void LED_OFF_all();
void Car_LED_Green_ON_Pedestrian_LED_Red_ON();
void Car_LED_Yellow_blinking_Pedestrian_LED_Yellow_blinking_with_delay();
void Car_LED_Yellow_ON_Pedestrian_LED_Yellow_ON();
void Car_LED_Yellow_OFF_Pedestrian_LED_Yellow_OFF();
void Car_LED_Red_ON_Pedestrian_LED_Green_ON();
void Car_LED_Yellow_blink_Pedestrian_LED_Green_ON_with_delay();
/*****************************************/
void reset_init();
void reset();
/*****************************************/
void App_init();
void App_start();

#endif /* APP_H_ */