/*
 * LED.h
 *
 * Created: 10/6/2022 11:14:18 PM
 *  Author: Mohamed_Hosni
 */ 
#ifndef LED_H_
#define LED_H_
/************************************************************************/
/*                         INCLUDES                                     */
/************************************************************************/
#include "../../MCAL/DIO/DIO.h"

/************************************************************************/
/*                         TYPE DEFINITONS                              */
/************************************************************************/
typedef struct led{
	volatile uint8_t * DDR;
	volatile uint8_t * PORT;
	uint8_t pin;
}S_LED_t;

/************************************************************************/
/*                         FUNCTIONS PROTOTYPE                          */
/************************************************************************/
/*-----------------------------------------------------------------------*/
/* @brief	  Function used to initialize a LED.                  
 * 
 * @param     s_led	 Structure containing the DDR, PORT ,and the pin of the led.
 *
 * @retrieve  Error state if ok or not.
 */  
E_ERROR_STATE_t HAL_LED_init(S_LED_t s_led);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to turn on the LED .                  
 * 
 * @param     s_led	 Structure containing the DDR, PORT ,and the pin of the led.
 *
 * @retrieve  Error state if ok or not.
 */  
E_ERROR_STATE_t HAL_LED_turnON(S_LED_t s_led);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to turn off the LED.                  
 * 
 * @param     s_led	 Structure containing the DDR, PORT ,and the pin of the led.
 *
 * @retrieve  Error state if ok or not.
 */   
E_ERROR_STATE_t HAL_LED_turnOFF(S_LED_t s_led);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to toggle the state of a LED.                  
 * 
 * @param     s_led	 Structure containing the DDR, PORT ,and the pin of the led.
 *
 * @retrieve  Error state if ok or not.
 */  
E_ERROR_STATE_t HAL_LED_toggle(S_LED_t s_led);




#endif /* LED_H_ */
