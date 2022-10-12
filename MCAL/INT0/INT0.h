/*
 * INT0.h
 *
 * Created: 10/6/2022 10:34:56 PM
 *  Author: Mohamed_Hosni
 */ 
#ifndef INT0_H_
#define INT0_H_
/************************************************************************/
/*                         INCLUDES                                     */
/************************************************************************/
// AVR standard libraries
#include <avr/io.h>
#include <avr/interrupt.h>

// standard libraries.
#include <stdint.h>

// Custom Includes
#include "../DIO/DIO.h"

/************************************************************************/
/*                         TYPE DEFINITONS                              */
/************************************************************************/
typedef enum mode{
	LOW_LEVEL,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RAISING_EDGE
}E_MODE_t;

/************************************************************************/
/*                         FUNCTIONS PROTOTYPE                          */
/************************************************************************/
/*-----------------------------------------------------------------------*/
/* @brief	  Function used to initialize the external interrupt INT0.                  
 * 
 * @param     e_mode	Mode of operation
 *
 * @retrieve  Error state if ok or not.
 */ 
E_ERROR_STATE_t MCAL_INTO_init(E_MODE_t e_mode);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to enable INT0.                  
 * 
 * @param     void.
 *
 * @retrieve  Error state if ok or not.
 */
void MCAL_INT0_enable(void);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to disable INT0.                  
 * 
 * @param     void.
 *
 * @retrieve  Error state if ok or not.
 */
void MCAL_INT0_disable(void);
#endif /* INT0_H_ */