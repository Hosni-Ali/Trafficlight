/*
 * INT0.c
 *
 * Created: 10/6/2022 10:33:05 PM
 *  Author: Mohamed_Hosni
 */
#include "INT0.h"

/************************************************************************/
/*                      FUNCTIONS                                       */
/************************************************************************/
E_ERROR_STATE_t MCAL_INTO_init(E_MODE_t e_mode) 
{
	// error.
	E_ERROR_STATE_t e_error = NOT_OK;
	
	// Select mode.
	switch(e_mode){
		// The low level of INT0 generates an interrupt request.
		case LOW_LEVEL:
		MCUCR &= ~(1<<ISC00);
		MCUCR &= ~(1<<ISC01);
		// Done.
		e_error = OK;
		break;

		// Any logical change on INT0 generates an interrupt request.
		case ANY_LOGICAL_CHANGE:
		MCUCR |=  (1<<ISC00);
		MCUCR &= ~(1<<ISC01);
		// Done.
		e_error = OK;
		break;

		// The falling edge of INT0 generates an interrupt request.
		case FALLING_EDGE:
		MCUCR &= ~(1<<ISC00);
		MCUCR |=  (1<<ISC01);
		// Done.
		e_error = OK;
		break;

		// The raising edge of INT0 generates an interrupt request.
		case RAISING_EDGE:
		MCUCR |= (1<<ISC00);
		MCUCR |= (1<<ISC01);
		// Done.
		e_error = OK;
		break;
	}

	// Enable external interrupt 0.
	GICR |= (1<<INT0);

	// Enable global interrupts.
	sei();
	
	return e_error;
}

//.....
void MCAL_INT0_enable(void)
{
	// Enable external interrupt 0.
	GICR |= (1<<INT0);
}

//.....
void MCAL_INT0_disable(void)
{
	// Disable external interrupt 0.
	GICR &= ~(1<<INT0);
}