/*
 * USART_Program.c
 *
 *  Created on: Feb 03, 2023
 *      Author: Mohamed Mokhtar
 */

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdlib.h>
#include "USART_Interface.h"

// TODO Add SetCallBack function
// TODO Read/Send the ninth bit
// TODO Add all configuration for stop bit and A/sync mode etc
/******************* Global Function implementation Section*******************/
void USART_Init(void)
{
    UBRRH  = (uint8_t)(BAUD_PRESCALLER>>8);
    UBRRL  = (uint8_t)(BAUD_PRESCALLER);
    #if RX_INTERRUPT == RX_INTERRUPT_DISABLE
        UCSRB  = (1<<RXEN)|(1<<TXEN);
    #elif RX_INTERRUPT == RX_INTERRUPT_ENABLE
        UCSRB |= (1 << RXEN) | (1 << RXCIE);
    #endif
    #if CHARACTER_SIZE == S_5_Bit
        UCSRC = (1<<URSEL);
    #elif CHARACTER_SIZE == S_6_Bit
        UCSRC = (1<<UCSZ0)|(1<<URSEL);
    #elif CHARACTER_SIZE == S_7_Bit
        UCSRC = (1<<UCSZ1)|(1<<URSEL);
    #elif CHARACTER_SIZE == S_8_Bit
        UCSRC = (1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL);
    #elif CHARACTER_SIZE == S_9_Bit
        UCSRC = (1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL);
        UCSRB |= (1<<UCSZ2);
    #endif

    #if DOUBLE_SPEED_MODE == DEACTIVATED
        CLR_BIT(UCSRA,U2X);
    #elif DOUBLE_SPEED_MODE == ACTIVATED
        SET_BIT(UCSRA,U2X);
    #endif
}

void USART_SendChar(s8 data)
{
    while(!(UCSRA & (1<<UDRE)));
    UDR = data;
}

void USART_SendString(s8* StringPtr)
{
    while(*StringPtr != NULL)
    {
        USART_SendChar(*StringPtr);
        StringPtr++;
    }
}

void USART_IntToString(u16 IntegerValue)
{
    s8 buffer[10];
    itoa(IntegerValue, buffer, 10);
    USART_SendString(buffer);
}

#if RX_INTERRUPT == RX_INTERRUPT_DISABLE
    s8 USART_ReceiveChar(void)
    {
        while ((UCSRA & (1 << RXC)) == 0);
        return(UDR);
    }
    void USART_ReceiveString(s8 * RecievedString)
    {
    s8 CharReceived = 0;
    CharReceived = USART_ReceiveChar();
    while(CharReceived != '*')
    {
        *RecievedString = CharReceived;
        RecievedString++;
        CharReceived = USART_ReceiveChar();
    }
    *RecievedString = '\0';
    }
#elif RX_INTERRUPT == RX_INTERRUPT_ENABLE
    u8 USARTReceivedData = 0;
    ISR(USART_RXC_vect)
    {
        USARTReceivedData = UDR;
    }
#endif
/*************************************************************************/



/* USART_PROGRAM */
