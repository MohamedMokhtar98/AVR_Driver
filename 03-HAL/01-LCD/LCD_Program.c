/*
 * LCD_Program.c
 *
 *  Created on: Apr 22, 2023
 *      Author: Mohamed_Mokhtar
 */

#include <avr/io.h>
#include <stdlib.h>
#include <avr/delay.h>
#include "STD_Types.h"
#include "DIO_interface.h"
#include "LCD_Header.h"
#include "BIT_MATH.h"

#if LCD_MODE == LCD_8BIT
void LCD_Init(void) {
	DIO_SetPortDir(Data_Dir, OUTPUT);
	DIO_SetPinDir(Control_Dir, RS, OUTPUT);
	DIO_SetPinDir(Control_Dir, RW, OUTPUT);
	DIO_SetPinDir(Control_Dir, EN, OUTPUT);

	_delay_ms(30);
	SendCommand(Return_Home);
	_delay_ms(15);
	SendCommand(Function_Set);
	_delay_ms(1);
	SendCommand(Display_ON);
	_delay_ms(1);
	SendCommand(Display_Clear);
	_delay_ms(15);
	SendCommand(Entry_Mode);
	_delay_ms(2);
	//////////////////////////////////////
}
void SendCommand(u8 Comamand_) {
	DIO_SetPinValue(Control_Port, RS, LOW);
	DIO_SetPinValue(Control_Port, RW, LOW);
	DIO_SetPinValue(Control_Port, EN, HIGH);
	DIO_SetPortValue(Data_Port, Comamand_);
	DIO_SetPinValue(Control_Port, EN, LOW);
	_delay_ms(5);
	DIO_SetPinValue(Control_Port, EN, HIGH);
	_delay_ms(10);
}
void WriteChar(u8 Data) {
	DIO_SetPinValue(Control_Port, RS, HIGH);
	DIO_SetPinValue(Control_Port, RW, LOW);
	DIO_SetPinValue(Control_Port, EN, HIGH);
	DIO_SetPortValue(Data_Port, Data);
	DIO_SetPinValue(Control_Port, EN, LOW);
	_delay_ms(2);
	DIO_SetPinValue(Control_Port, EN, HIGH);
	_delay_ms(10);
}
void WriteString(char *Data) {

	while (*Data != NULL ) {
		WriteChar(*Data);
		Data++;
	}
}
void IntegerToString(u16 data) {
	char buff[20];
	itoa(data, buff, 10);
	WriteString(buff);
}
void GoXY(u8 Line, u8 Position) {
	if (Position >= 0 && Position <= 16) {
		switch (Line) {
			case 1:
			SendCommand(Position + 127);
			break;
			case 2:
			SendCommand(Position + 191);
			break;
			default:
			break;
		}
	}
}
#elif  LCD_MODE == LCD_4BIT

LCD_Init() {
	LCD_Dir = 0xFF; /* Make LCD port direction as o/p */
	Control_Dir |= (1 << RS ) | (1 << RW ) | (1 << EN );
	_delay_ms(20); /* LCD Power ON delay always >15ms */

	SendCommand(0x02); /* send for 4 bit initialization of LCD  */
	SendCommand(0x28); /* 2 line, 5*7 matrix in 4-bit mode */
	SendCommand(0x0c); /* Display on cursor off*/
	SendCommand(0x06); /* Increment cursor (shift cursor to right)*/
	SendCommand(0x01); /* Clear display screen*/
	_delay_ms(2);
}

void SendCommand(u8 Comamand_) {
	LCD_Port = (LCD_Port & 0x0F) | (Comamand_ & 0xF0); /* sending upper nibble */
	Control_Port &= ~(1 << RS ); /* RS=0, command reg. */
	Control_Port |= (1 << EN ); /* Enable pulse */
	_delay_us(1);
	Control_Port &= ~(1 << EN );

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (Comamand_ << 4); /* sending lower nibble */
	Control_Port |= (1 << EN );
	_delay_us(1);
	Control_Port &= ~(1 << EN );
	_delay_ms(2);

}

void WriteChar(u8 Data) {
	LCD_Port = (LCD_Port & 0x0F) | (Data & 0xF0); /* sending upper nibble */
	Control_Port |= (1 << RS ); /* RS=1, data reg. */
	Control_Port |= (1 << EN );
	_delay_us(1);
	Control_Port &= ~(1 << EN );

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (Data << 4); /* sending lower nibble */
	Control_Port |= (1 << EN );
	_delay_us(1);
	Control_Port &= ~(1 << EN );
	_delay_ms(2);
}
void WriteString(char *Data) {

	while (*Data != NULL ) {
		WriteChar(*Data);
		_delay_ms(10);
		Data++;
	}
}
void IntegerToString(u16 data) {
	char buff[20];
	itoa(data, buff, 10);
	WriteString(buff);
}
void GoXY(u8 Line, u8 Position) {
	if (Position >= 0 && Position <= 16) {
		switch (Line) {
		case 1:
			SendCommand(Position + 128);
			break;
		case 2:
			SendCommand(Position + 192);
			break;
		default:
			break;
		}
	}
}

#endif


