/*
 * Timer0.h
 *
 * Created: 10/6/2022 10:53:49 PM
 *  Author: Mohamed_Hosni
 */ 
#ifndef TIMER0_H_
#define TIMER0_H_
/************************************************************************/
/*                         INCLUDES                                     */
/************************************************************************/
// AVR standard libraries
#include <avr/io.h>
#include <avr/interrupt.h>

// standard libraries.
#include <stdint.h>

/************************************************************************/
/*                         FUNCTIONS PROTOTYPE                          */
/************************************************************************/
/*-----------------------------------------------------------------------*/
/* @brief	  Function used to use timer0 in a specific delay time.                 
 * 
 * @param     time_ms	delay time.
 *
 * @retrieve  void
 */   
void MCAL_Timer0_delayMs(uint32_t time_ms);

#endif /* TIMER0_H_ */