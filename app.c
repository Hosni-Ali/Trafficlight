/*
 * app.c
 *
 * Created: 10/8/2022 11:26:03 AM
 *  Author: Mohamed_Hosni
 */ 
 /************************************************************************/
 /*                         CPU frequency                                */
 /************************************************************************/
 #ifndef F_CPU
 #define F_CPU		8000000UL
 #endif
 
/************************************************************************/
/*                         INCLUDES                                     */
/************************************************************************/
// Standard C libraries.
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// AVR Standard libraries.
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// HAL Header files.
#include "../HAL/LED/LED.h"

// MCAL Header files.
#include "../MCAL/INT0/INT0.h"
#include "../MCAL/Timer0/Timer0.h"
 
/************************************************************************/
/*                         VARIABLES                                    */
/************************************************************************/
 typedef struct ledsGroup{
	 S_LED_t redLED;
	 S_LED_t yellowLED;
	 S_LED_t greenLED;	 
}S_LEDGROUP_t;

// array of LEDs.
S_LEDGROUP_t normalMode = {
	.redLED    = {&DDRA, &PORTA, PA2},
	.yellowLED = {&DDRA, &PORTA, PA1},
	.greenLED  = {&DDRA, &PORTA, PA0}
};

typedef enum current_led{
	red,
	yellow,
	green
}E_CURRENT_LED_t;

E_CURRENT_LED_t e_currentLed = red;

typedef enum userStory{
	NONE,
	USER_STORY1,
	USER_STORY2
}E_USER_STORY_t;

E_USER_STORY_t e_userStory;
static void userStroy_2(void);
// array of LEDs.
S_LEDGROUP_t pedestrianMode = {
	.redLED    = {&DDRB, &PORTB, PB2},
	.yellowLED = {&DDRB, &PORTB, PB1},
	.greenLED  = {&DDRB, &PORTB, PB0}
};

// null structure
void *null_structure;

static void toggle_yello_every_oneSecond(S_LEDGROUP_t s_ledGroup1, S_LEDGROUP_t s_ledGroup2)
{
	for(uint8_t i=0; i<5; i++)
	{
		HAL_LED_toggle(s_ledGroup1.yellowLED);
		HAL_LED_toggle(s_ledGroup2.yellowLED);
		MCAL_Timer0_delayMs(1000);	
	}
}

static void userStroy_1(void)
{
	//>>
	HAL_LED_turnOFF(normalMode.greenLED);
	
	//>>
	HAL_LED_turnOFF(pedestrianMode.redLED);
	toggle_yello_every_oneSecond(normalMode, pedestrianMode);
	
	//>> 
	HAL_LED_turnOFF(normalMode.yellowLED);
	HAL_LED_turnOFF(pedestrianMode.yellowLED);
	HAL_LED_turnON(normalMode.redLED);
	HAL_LED_turnON(pedestrianMode.greenLED);

	MCAL_Timer0_delayMs(5000);
	
	HAL_LED_turnOFF(normalMode.redLED);
	HAL_LED_turnOFF(pedestrianMode.greenLED);
	toggle_yello_every_oneSecond(normalMode, pedestrianMode);
	HAL_LED_turnOFF(normalMode.yellowLED);
	HAL_LED_turnOFF(pedestrianMode.yellowLED);
	HAL_LED_turnON(pedestrianMode.redLED);
	HAL_LED_turnON(normalMode.greenLED);
	MCAL_Timer0_delayMs(5000);
	e_userStory = NONE;
} 

static void userStroy_2(void)
{

	HAL_LED_turnOFF(normalMode.yellowLED);
	HAL_LED_turnON(normalMode.redLED);
	HAL_LED_turnON(pedestrianMode.greenLED);
	HAL_LED_turnOFF(pedestrianMode.redLED);

	MCAL_Timer0_delayMs(5000);

	HAL_LED_turnOFF(normalMode.redLED);
	HAL_LED_turnOFF(pedestrianMode.greenLED);
	toggle_yello_every_oneSecond(normalMode, pedestrianMode);
	HAL_LED_turnOFF(normalMode.yellowLED);
	HAL_LED_turnOFF(pedestrianMode.yellowLED);
	HAL_LED_turnON(pedestrianMode.redLED);
	HAL_LED_turnON(normalMode.greenLED);
	MCAL_Timer0_delayMs(5000);
	HAL_LED_turnOFF(normalMode.greenLED);

	toggle_yello_every_oneSecond(normalMode, *(S_LEDGROUP_t*)null_structure);
	e_userStory = NONE;


}

E_ERROR_STATE_t app_init(void)
{	
	// error 
	E_ERROR_STATE_t e_error = NOT_OK;
	
	// initialize all LEDs.
	// >> Normal Mode.
	HAL_LED_init(normalMode.redLED);
	HAL_LED_init(normalMode.yellowLED);
	HAL_LED_init(normalMode.greenLED);
	// >> pedestrian Mode.
	HAL_LED_init(pedestrianMode.redLED);
	HAL_LED_init(pedestrianMode.yellowLED);
	HAL_LED_init(pedestrianMode.greenLED);
	
	// Initialize the External interrupt INT0.
	MCAL_INTO_init(RAISING_EDGE);
	
	// Enable INT0.
	MCAL_INT0_enable();
	
	// Done.
	e_error = OK;
	
	// return.
	return e_error;
}

E_ERROR_STATE_t app_process(void)
{	
	// Ped. red LED.
	HAL_LED_turnON(pedestrianMode.redLED);
	
	// Normal Mode.
	while(true)
	{
		// Turn on red. 
		e_currentLed = red;
		HAL_LED_turnON(normalMode.redLED);
		HAL_LED_turnOFF(normalMode.yellowLED);
		HAL_LED_turnOFF(normalMode.greenLED);
		
		// Delay 5 seconds.
		MCAL_Timer0_delayMs(5000);
		
		// Turn on yellow.
		e_currentLed = yellow;
		HAL_LED_turnOFF(normalMode.redLED);
		HAL_LED_turnOFF(normalMode.greenLED);
		toggle_yello_every_oneSecond(normalMode, *(S_LEDGROUP_t *)null_structure);
		
		// Turn on green.
		e_currentLed = green;
		HAL_LED_turnON(pedestrianMode.redLED);
		HAL_LED_turnOFF(normalMode.redLED);
		HAL_LED_turnOFF(normalMode.yellowLED);
		HAL_LED_turnON(normalMode.greenLED);
		
		// Delay 5 seconds.
		MCAL_Timer0_delayMs(5000);
		
		if(e_userStory == USER_STORY1)
		{
			userStroy_1();	

		}
		
		// Turn on yellow.
		e_currentLed = yellow;
		HAL_LED_turnOFF(normalMode.redLED);
		HAL_LED_turnOFF(normalMode.greenLED);
		toggle_yello_every_oneSecond(normalMode, *(S_LEDGROUP_t*)null_structure);


		if(e_userStory == USER_STORY2)
		{
			userStroy_2();
		}

	}	
	return 0;
}

// INT0 ISR.
ISR(INT0_vect)
{
	// user story1
	if(e_currentLed == green)
	{
		e_userStory = USER_STORY1;	
	}
	else if(e_currentLed == yellow)
	{
		e_userStory = USER_STORY2;
	}
	else
	{

	}
}
