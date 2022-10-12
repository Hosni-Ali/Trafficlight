/*
 * DIO.h
 *
 * Created: 10/6/2022 9:29:21 PM
 *  Author: Mohamed_Hosni
 */ 

#ifndef DIO_H_
#define DIO_H_
/************************************************************************/
/*                         INCLUDES                                     */
/************************************************************************/
// AVR standard libraries
#include <avr/io.h>

// standard libraries.
#include <stdint.h>
#include <stdbool.h>

/************************************************************************/
/*                         DEFINES                                      */
/************************************************************************/
// NULL Definition.
#ifndef NULL
#define NULL	'\0'
#endif

/************************************************************************/
/*                         TYPE DEFINITONS                              */
/************************************************************************/
typedef enum DataDirection{
	// Input Direction
	INPUT = 0x0,
	// Output Direction
	OUTPUT = 0x1
}E_DATA_DIRECTION_t;

typedef enum PortOutput{
	// Logic Zero
	LOW = 0x0,
	// Logic One
	HIGH = 0x1
}E_PORT_OUTPUT_t;

typedef enum ErrorState{
	// ok state
	OK = 0x0,
	// Not ok state
	NOT_OK = 0x1
}E_ERROR_STATE_t;

/************************************************************************/
/*                         FUNCTIONS PROTOTYPE                          */
/************************************************************************/
/*-----------------------------------------------------------------------*/
/* @brief	  Function used to initialize a specific pin.                  
 * 
 * @param     DDR	       	   Data direction register.
 * @param     pin              The specific pin
 * @param     e_direction      pin direction if output or input pin.
 * @param     e_initialState   Pin initial state if it is output pin, high or low.
 *
 * @retrieve  Error state if ok or not.
 */   
void MCAL_DIO_initPin(volatile uint8_t * DDR, volatile uint8_t * PORT, uint8_t pin, E_DATA_DIRECTION_t e_direction, E_PORT_OUTPUT_t e_initialState);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to write logic value to a pin.                  
 * 
 * @param     PORT	       	   Output register.
 * @param     pin              The specific pin
 * @param     e_outState       logic value
 *
 * @retrieve  Error state if ok or not.
 */ 
void MCAL_DIO_pinDigitalWrtie(volatile uint8_t * PORT, uint8_t pin, E_PORT_OUTPUT_t e_outState);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to toggle the state of a pin.                  
 * 
 * @param     PORT	       	   Output register.
 * @param     pin              The specific pin
 * @param     e_outState       logic value
 *
 * @retrieve  Error state if ok or not.
 */ 
void MCAL_DIO_pinToggle(volatile uint8_t * PORT, uint8_t pin);

/*-----------------------------------------------------------------------*/
/* @brief	  Function used to read a logic value from a pin.                 
 * 
 * @param     PIN	       	   Data direction register.
 * @param     pin              The specific pin
 * @param     value            variable to write in.
 *
 * @retrieve  Error state if ok or not.
 */ 
E_ERROR_STATE_t MCAL_DIO_readPin(volatile uint8_t * PIN, uint8_t pin, uint8_t * value);
#endif /* DIO_H_ */
