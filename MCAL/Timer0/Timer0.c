/*
 * Timer0.c
 *
 * Created: 10/6/2022 10:53:36 PM
 *  Author: Mohamed_Hosni
 */ 
#include "Timer0.h"

/* MCU frequency = 8MHZ.
 * prescaler = 1/64.
 * Tclk = 0.125 [us].
 * T[timer] = 64*0.125 = 8 [usec].
 * # of counts = T[delay] / T[timer] = 1 [ms]/8 [us] = 125.
 * initial value (TCNT0) = 255 - 126 + 1(roll over)= 131
 */
void MCAL_Timer0_delayMs(uint32_t time_ms)
{
	for(uint32_t i=time_ms; i>0; i--){
		// load initial value for 1 ms delay.
		TCNT0 = 131U;

		// Normal mode.
		TCCR0 &= ~(1<<WGM01);
		TCCR0 &= ~(1<<WGM00);

		// prescaler = 1/64.
		TCCR0 |= (1<<CS00);
		TCCR0 |= (1<<CS01);
		TCCR0 &= ~(1<<CS02);

		// Wait for TOV0 to roll over.
		while( (TIFR&(1<<TOV0)) == 0);

		// Turn off timer.
		TCCR0 = 0x00;

		// Clear TOV0.
		TIFR |= (1<<TOV0);
	}
	return;
}