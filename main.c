/*
 * main.c
 *
 * Created: 10/6/2022 9:17:13 PM
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
// Compiler libraries.
//#include <xc.h>

// AVR standard libraries.
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/************************************************************************/
/*                         DEFINTIONS                                   */
/************************************************************************/
#define OK	    0x0U
#define NOT_OK  0x1U

/************************************************************************/
/*                         EXTERNAL FUNCTIONS                           */
/************************************************************************/
extern uint8_t app_init(void);
extern uint8_t app_process(void);

int main(void)
{	
	app_init();
	
    while(1)
    {
        //TODO:: Please write your application code 
		app_process();
	}
}
