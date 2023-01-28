/*
 * DIO_Interface.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Mohamed Mokhtar
 */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

/******************** Private Section ************************/
#define  PORT_A 0x1B
#define  DDR_A  0x1A
#define  PIN_A  0x19

#define  PORT_B 0x18
#define  DDR_B  0x17
#define  PIN_B  0x16

#define  PORT_C 0x15
#define  DDR_C  0x14
#define  PIN_C  0x13

#define  PORT_D 0x12
#define  DDR_D  0x11
#define  PIN_D  0x10

#define PORT_OFFS (u8)0
#define DDR_OFFS  (u8)1
#define PIN_OFFS  (u8)2

#define OUTPUT (u8)0xFF
#define INPUT  (u8)0x00
#define MAX    (u8)0xFF
#define MIN    (u8)0x00
#define HIGH   (u8)1
#define LOW    (u8) 0

#define PIN_0	(u8)0
#define PIN_1	(u8)1
#define PIN_2	(u8)2
#define PIN_3	(u8)3
#define PIN_4	(u8)4
#define PIN_5	(u8)5
#define PIN_6	(u8)6
#define PIN_7	(u8)7

#define DIO_INTERNAL_INPUT_PULL_UP   1
#define DIO_INPUT_PULL_DOWN          2
/*************************************************************************/

/******************* ProtoTypes Global Function Section*******************/
State DIO_SetPortDir(u8 DIO_Port, u8 DIO_Dir);

State DIO_SetPortValue(u8 DIO_Port, u8 DIO_PORT_Value);

State DIO_SetPinDir(u8 DIO_Port, u8 DIO_Pin, u8 DIO_Pin_Dir);

State DIO_SetPinValue(u8 DIO_Port, u8 DIO_Pin, u8 DIO_Pin_Value);

State DIO_GetPinValue(u8 DIO_Port, u8 DIO_Pin, u8 *DIO_PointerToReturnValue);
/*************************************************************************/


/* Configuration Section */
/**
 * Choose one of these options:
 * DIO_INTERNAL_INPUT_PULL_UP
 * DIO_INPUT_PULL_DOWN
 * 
 * NOTE: For more information check Atmel Datasheet for 
 *       ATMEGA32, I/O section table 20
*/
#define DIO_INTERNAL_PULL_UP_ENABLE DIO_INTERNAL_INPUT_PULL_UP

#endif /* DIO_HEADER_H_ */
