/*
 * DIO.c
 *
 * Created: 10/6/2022 9:29:05 PM
 *  Author: Mohamed_Hosni
 */ 
#include "DIO.h"

/************************************************************************/
/*                      FUNCTIONS                                       */
/************************************************************************/
//......
void MCAL_DIO_initPin(volatile uint8_t * DDR, volatile uint8_t * PORT, uint8_t pin, E_DATA_DIRECTION_t e_direction, E_PORT_OUTPUT_t e_initialState)
{	
	// Check the pin direction.
	if( e_direction == OUTPUT )
	{
		// set the pin in the output direction.
		*DDR |= (1<<pin);
		
		/* Set the initial value */
		if( e_initialState == HIGH )
		{
			// set the pin to logic one. 
			*PORT |= (1<<pin);			
		}/* if() */
		else if( e_initialState == LOW )
		{
			// set the pin to logic zero.
			*PORT &= ~(1<<pin);
		}/* else if() */
		else
		{
			// error handling.
			while(1);
		}/* else */
		
	}/* if() */
	else if( e_direction == INPUT )
	{
		// Set the pin in the input direction.
		*DDR &= ~(1<<pin);
		
	}/* else if() */
	else{
		// error Handling.
		while(1);
	}/* else */
}

//......
void MCAL_DIO_pinDigitalWrtie(volatile uint8_t * PORT, uint8_t pin, E_PORT_OUTPUT_t e_outState)
{
	// Check the logic value.
	if( e_outState == HIGH )
	{
		// Write logic one.
		*PORT |= (1<<pin);

	}/* if() */
	else if( e_outState == LOW )
	{
		// Write logic zero.
		*PORT &= ~(1<<pin);
		
	}/* else if() */
	else
	{
		// error handling.
		while(1);
	}/* else */
	
}

//......
void MCAL_DIO_pinToggle(volatile uint8_t * PORT, uint8_t pin)
{	
	// toggle the pin.
	*PORT ^= (1<<pin);	
}

//......
E_ERROR_STATE_t MCAL_DIO_readPin(volatile uint8_t * PIN, uint8_t pin, uint8_t * value)
{
	// error
	E_ERROR_STATE_t errorState = NOT_OK;
	
	// get the value.
	*value = (void*)0u;
	
	*value = (bool)( (*PIN) & (1<<pin) );
	
	// error check.
	if( (*value) != (void*)0)
	{
		errorState = OK;
	}/* if() */
	
	// return.
	return errorState;
}
