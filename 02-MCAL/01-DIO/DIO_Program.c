/*
 * DIO_Program.c
 *
 *  Created on: Jan 28, 2023
 *      Author: Mohamed Mokhtar
 */

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

/******************* Global Function implementation Section*******************/

/**
 * @brief Set the Port Direction object
 * 
 * @param DIO_Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param DIO_Dir  (OUTPUT, INPUT, Value between 0..255)
 * @return State SUCCESS if every thing is ok, FAILED if there is an error
 */
State DIO_SetPortDir(u8 DIO_Port, u8 DIO_Dir)
{
    if((DIO_Port != PORT_A) && (DIO_Port != PORT_B) && (DIO_Port != PORT_C) && (DIO_Port != PORT_D))
    {
        return FAILED;
    }
    else if((DIO_Dir < MIN) || (DIO_Dir > MAX))
    {
        return FAILED;
    }
    else
    {
        (*(volatile uint8_t *)((DIO_Port - DDR_OFFS) + __SFR_OFFSET)) = DIO_Dir;
        return SUCCESS;
    }
}
/**
 * @brief Set the Port Value object
 * 
 * @param DIO_Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param DIO_Dir  (OUTPUT, INPUT, Value between 0..255)
 * @return State SUCCESS if every thing is ok, FAILED if there is an error
 */
State DIO_SetPortValue(u8 DIO_Port, u8 DIO_PORT_Value)
{
    if((DIO_Port != PORT_A) && (DIO_Port != PORT_B) && (DIO_Port != PORT_C) && (DIO_Port != PORT_D))
    {
        return FAILED;
    }
    else if((DIO_PORT_Value < MIN) || (DIO_PORT_Value > MAX))
    {
        return FAILED;
    }
    else
    {
        (*(volatile u8 *)((DIO_Port + PORT_OFFS) + __SFR_OFFSET)) = DIO_PORT_Value;
        return SUCCESS;
    }
}
/**
 * @brief Set the Pin Direction object
 * 
 * @param DIO_Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param DIO_Pin  (PIN_0 .. PIN_7)
 * @param DIO_Pin_Dir (INPUT, OUPUT)
 * @return State SUCCESS if every thing is ok, FAILED if there is an error 
 */
State DIO_SetPinDir(u8 DIO_Port, u8 DIO_Pin, u8 DIO_Pin_Dir)
{
    if((DIO_Port != PORT_A) && (DIO_Port != PORT_B) && (DIO_Port != PORT_C) && (DIO_Port != PORT_D))
    {
        return FAILED;
    }
    else if((DIO_Pin < PIN_0) || (DIO_Pin > PIN_7))
    {
        return FAILED;
    }
    else
    {
        if(DIO_Pin_Dir == OUTPUT)
        {
            SET_BIT((*(volatile uint8_t *)((DIO_Port - DDR_OFFS) + __SFR_OFFSET)), DIO_Pin);
            return SUCCESS;
        }
        else if(DIO_Pin_Dir == INPUT)
        {
            #if DIO_INTERNAL_PULL_UP_ENABLE == DIO_INTERNAL_INPUT_PULL_UP
                CLR_BIT((*(volatile uint8_t *)((DIO_Port - DDR_OFFS) + __SFR_OFFSET)), DIO_Pin);
                SET_BIT((*(volatile uint8_t *)((DIO_Port + PORT_OFFS) + __SFR_OFFSET)), DIO_Pin);
            #elif DIO_INTERNAL_PULL_UP_ENABLE == DIO_INPUT_PULL_DOWN
                CLR_BIT((*(volatile uint8_t *)((DIO_Port - DDR_OFFS) + __SFR_OFFSET)), DIO_Pin);
            #endif
            return SUCCESS;
        }
        else
        {
            return FAILED;
        }
    }
}
/**
 * @brief Set the Pin Value object
 * 
 * @param DIO_Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param DIO_Pin  (PIN_0 .. PIN_7)
 * @param DIO_Pin_Value (HIGH, LOW)
 * @return State SUCCESS if every thing is ok, FAILED if there is an error
 */
State DIO_SetPinValue(u8 DIO_Port, u8 DIO_Pin, u8 DIO_Pin_Value)
{
    if((DIO_Port != PORT_A) && (DIO_Port != PORT_B) && (DIO_Port != PORT_C) && (DIO_Port != PORT_D))
    {
        return FAILED;
    }
    else if((DIO_Pin < PIN_0) || (DIO_Pin > PIN_7))
    {
        return FAILED;
    }
    else
    {
        if(DIO_Pin_Value == HIGH)
        {
            SET_BIT((*(volatile uint8_t *)((DIO_Port + PORT_OFFS) + __SFR_OFFSET)), DIO_Pin);
            return SUCCESS;
        }
        else if(DIO_Pin_Value == LOW)
        {
            CLR_BIT((*(volatile uint8_t *)((DIO_Port + PORT_OFFS) + __SFR_OFFSET)), DIO_Pin);
            return SUCCESS;
        }
        else
        {
            return FAILED;
        }
    }
}
/**
 * @brief Get the Pin Value object
 * 
 * @param DIO_Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param DIO_Pin  (PIN_0 .. PIN_7)
 * @param DIO_PointerToReturnValue: Pass addresses of variable to store the pin value
 * @return State SUCCESS if every thing is ok, FAILED if there is an error
 */
State DIO_GetPinValue(u8 DIO_Port, u8 DIO_Pin, u8 *DIO_PointerToReturnValue)
{
    if((DIO_Port != PORT_A) && (DIO_Port != PORT_B) && (DIO_Port != PORT_C) && (DIO_Port != PORT_D))
    {
        return FAILED;
    }
    else if((DIO_Pin < PIN_0) || (DIO_Pin > PIN_7))
    {
        return FAILED;
    }
    else
    {
        *DIO_PointerToReturnValue = GET_BIT((*(volatile uint8_t *)((DIO_Port - PIN_OFFS) + __SFR_OFFSET)), DIO_Pin);
        return SUCCESS;
    }
}
/*************************************************************************/



/* DIO_PROGRAM */
