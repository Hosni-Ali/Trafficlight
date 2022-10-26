/*
 * LED.c
 *
 * Created: 10/6/2022 11:13:50 PM
 *  Author: Mohamed_Hosni
 */ 
#include "LED.h"

E_ERROR_STATE_t HAL_LED_init(S_LED_t s_led)
{
	// error
	E_ERROR_STATE_t e_error = NOT_OK;
	
	// Initialize the pin
	//  >> Output pin
	//  >> Initiallay HIGH
	MCAL_DIO_initPin(s_led.DDR, s_led.PORT, s_led.pin, OUTPUT, LOW);
	
	// Done
	e_error = OK;
	
	// return
	return e_error;  	
	
}

//.....
E_ERROR_STATE_t HAL_LED_turnON(S_LED_t s_led)
{
	// error.
	E_ERROR_STATE_t e_error = NOT_OK;
	
	// Turn on the LED. 
	MCAL_DIO_pinDigitalWrtie(s_led.PORT, s_led.pin, HIGH);
	
	// Done.
	e_error = OK;
	
	// return.
	return e_error;
}

//.....
E_ERROR_STATE_t HAL_LED_turnOFF(S_LED_t s_led)
{
		// error.
		E_ERROR_STATE_t e_error = NOT_OK;
		
		// Turn on the LED.
		MCAL_DIO_pinDigitalWrtie(s_led.PORT, s_led.pin, LOW);
		
		// Done.
		e_error = OK;
		
		// return.
		return e_error;
}

//.....
E_ERROR_STATE_t HAL_LED_toggle(S_LED_t s_led)
{
	// error.
	E_ERROR_STATE_t e_error = NOT_OK;
	
	// Toggle the pin.		
	MCAL_DIO_pinToggle(s_led.PORT, s_led.pin);
	
	// Done.
	e_error = OK;
	
	// return.
	return e_error;
}