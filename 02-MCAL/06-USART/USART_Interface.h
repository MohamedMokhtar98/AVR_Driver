/*
 * USART_Interface.h
 *
 *  Created on: Feb 03, 2023
 *      Author: Mohamed Mokhtar
 */
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "STD_TYPES.h"


/************************ Private Section *********************************/
#define DEACTIVATED 0
#define ACTIVATED   1

#define S_5_Bit     5
#define S_6_Bit     6
#define S_7_Bit     7
#define S_8_Bit     8
#define S_9_Bit     9

#define RX_INTERRUPT_ENABLE   1
#define RX_INTERRUPT_DISABLE  0

#if RX_INTERRUPT == RX_INTERRUPT_ENABLE
    extern USARTReceivedData;
#endif
/**************************************************************************/

/******************* ProtoTypes Global Function Section *******************/
extern void USART_Init(void);
extern void USART_SendChar(s8 data);
extern void USART_SendString(s8* StringPtr);
extern void USART_IntToString(u16 IntegerValue);
#if RX_INTERRUPT == RX_INTERRUPT_DISABLE
    extern s8 USART_ReceiveChar(void);
    extern void USART_ReceiveString(s8 * RecievedString);
#endif
/**************************************************************************/


/************************* Configuration Section **************************/
/*
Select Baud Rate
    Option:
        1200,
        2400,
        4800,
        9600,
        19200,
        115200 
*/
#define BAUDRATE 9600

/*
Activate Double speed mode:
    Option:
        DEACTIVATED
        ACTIVATED
*/
#define DOUBLE_SPEED_MODE DEACTIVATED

/*
Character Size:
    Option:
        S_5_Bit,
        S_6_Bit,
        S_7_Bit,
        S_8_Bit,
        S_9_Bit,
*/
#define CHARACTER_SIZE S_8_Bit

/* 
Interrupt Mode
    Option:
        RX_INTERRUPT_ENABLE
        RX_INTERRUPT_DISABLE
*/
#define RX_INTERRUPT RX_INTERRUPT_DISABLE


#if DOUBLE_SPEED_MODE == DEACTIVATED
    #define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#elif DOUBLE_SPEED_MODE == ACTIVATED
    #define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 8UL))) - 1)
#endif

/**************************************************************************/


#endif /* USART_HEADER_H_ */
