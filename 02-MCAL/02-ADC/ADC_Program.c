/*
 * ADC_Program.c
 *
 *  Created on: Feb 03, 2023
 *      Author: Mohamed Mokhtar
 */

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Interface.h"
#include "DIO_Interface.h"

/******************* Global Function implementation Section*******************/
void ADC_Init(u8 Channel)
{
    DIO_SetPinDir(PORT_A,Channel,INPUT);              // Set the required channel as input
    ADCSRA |= ADC_PRESCALER;                          // 16Mhz/128 = 125Khz the ADC reference clock
    ADMUX  |= (REFERENCE_VOLTAGE_SELECTION << REFS0); // Voltage reference from Avcc (5v)
    ADCSRA |= (1<<ADEN);                              // Turn on ADC
    ADCSRA |= (1<<ADSC);                              // Do an initial conversion because this one is the slowest and to ensure that everything is up and running
}

u16 ADC_Read(u8 Channel)
{
    ADMUX  &= 0xF0;                              // Clear the older channel that was read
    ADMUX  |= Channel;                           // Defines the new ADC channel to be read
    ADCSRA |= (1<<ADSC);                         // Starts a new conversion
    while(ADCSRA & (1<<ADSC));                   // Wait until the conversion is done
    return ADCW;                                 // Returns the ADC value of the chosen channel
}
/*************************************************************************/



/* ADC_PROGRAM */
