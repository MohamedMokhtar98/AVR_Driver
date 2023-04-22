/*
 * LCD_Header.h
 *
 *  Created on: Apr 22, 2023
 *      Author: Mohamed_Mokhtar
 */

#ifndef LCD_HEADER_H_
#define LCD_HEADER_H_

#include <avr/io.h>
#include "DIO_interface.h"
#include "STD_Types.h"

#define LCD_8BIT 1
#define LCD_4BIT 2

#define LCD_MODE LCD_8BIT

#if LCD_MODE == LCD_8BIT
//class LCD_8Bit {

#define DL           (u8)1//set to 1 to use 8BIT Configuration
#define Data_Port    (u8)PORT_A // Use this one with _ to use it in DIO file
#define Control_Port (u8)PORT_C// Use this one with _ to use it in DIO file
#define Data_Dir     (u8)PORT_A// Use this one with _ to use it in DIO file
#define Control_Dir  (u8)PORT_C// Use this one with _ to use it in DIO file
#define RS (u8)PIN_1
#define RW (u8)PIN_2
#define EN (u8)PIN_3

#define Function_Set  0x38
#define Display_ON    0x0C
#define Display_OFF   0x08
#define Display_Clear 0x01
#define Entry_Mode    0x06
#define Return_Home   0x02
#define Set_Cursor    0x80

void LCD_Init(void);
void WriteChar(u8 Data);
void WriteString(char *Data);
void IntegerToString (u16 data);
void GoXY(u8 Line,u8 Position);
void SendCommand(u8 Comamand_);


#elif  LCD_MODE == LCD_4BIT
//class LCD_4Bit {

#define DL           (u8)1//set to 1 to use 8BIT Configuration
#define LCD_Dir  DDRA			/* Define LCD data port direction */
#define LCD_Port PORTA
#define Control_Port PORTC
#define Control_Dir  DDRC
#define RS (u8)PIN_1
#define RW (u8)PIN_2
#define EN (u8)PIN_3



#define Function_Set_4Bit  0x03
#define Function_Set2_4Bit 0x08
#define Display_ON_4Bit    0x0C
#define Display_OFF_4Bit   0x08
#define Display_Clear_4Bit 0x01
#define Entry_Mode_4Bit    0x04
#define Return_Home_4Bit   0x02
#define Set_Cursor_4Bit    0x80


void LCD_Init(void);
void WriteChar(u8 Data);
void WriteString(char *Data);
void IntegerToString (u16 data);
void GoXY(u8 Line,u8 Position);
void SendCommand(u8 Comamand_);

#endif

#endif /* LCD_HEADER_H_ */
