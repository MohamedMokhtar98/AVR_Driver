/*
 * ADC_Interface.h
 *
 *  Created on: Feb 03, 2023
 *      Author: Mohamed Mokhtar
 */
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"


/************************ Private Section *********************************/
#define AREF_PIN    0
#define VCC_5V      1
#define RESERVED    2
#define INTERNAL_2  3
#define x2    0x01
#define x4    0x02
#define x8    0x03
#define x16   0x04
#define x32   0x05
#define x64   0x06
#define x128  0x07
/**************************************************************************/

/******************* ProtoTypes Global Function Section *******************/
extern void ADC_Init(u8 Channel);
extern u16 ADC_Read(u8 Channel);
/**************************************************************************/


/************************* Configuration Section **************************/
/*
Reference voltage selection for ADC:
Option:
    AREF_PIN
    VCC_5V
    RESERVED
    INTERNAL_2
*/
#define REFERENCE_VOLTAGE_SELECTION VCC_5V

/*
ADC Prescaler:
Option:
       x2
       x4
       x8
       x16
       x32
       x64
       x128
*/
#define ADC_PRESCALER x128

/**************************************************************************/


#endif /* ADC_HEADER_H_ */
