/*
 * Timer_Program.c
 *
 *  Created on: Mar 04, 2023
 *      Author: Mohamed Mokhtar
 */

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include "Timer_Interface.h"

/******************* Global Function implementation Section*******************/

void Timer_n_Init(u8 Timer_n)
{
    switch (Timer_n)
    {
        case TIMER_0:
            #if NORMAL_MODE == TIMER_0_MODE
                TCNT0  = ZERO;
                TIMSK |= (1 << TOIE0);
                TCCR0 |= (1 << FOC0);
                TCCR0 |= TIMER0_PRESCALER;
                SREG  |= (1 << 7);
            #elif CTC_MODE == TIMER_0_MODE
                TCNT0  = ZERO;
                TIMSK |= (1 << TOIE0) | (1 << OCIE0);
                TCCR0 |= (1 << WGM01) | (1 << FOC0);
                TCCR0 |= TIMER0_PRESCALER;
                OCR0   = ZERO;
                SREG  |= (1 << 7);
            #elif PWM_PHASE_CORRECT_MODE == TIMER_0_MODE
                DDRB  |= (1 << PIN3);
                TCNT0  = ZERO;
                TIMSK |= (1 << TOIE0) | (1 << OCIE0);
                TCCR0 |= (1 << WGM00) | (1 << COM00) | (1 << COM01);
                TCCR0 |= TIMER0_PRESCALER;
                OCR0   = ZERO;
            #elif FAST_PWM_MODE == TIMER_0_MODE
                DDRB  |= (1 << PIN3);
                TCNT0  = ZERO;
                TIMSK |= (1 << TOIE0) | (1 << OCIE0);
                TCCR0 |= (1 << WGM01) | (1 << WGM00) | (1 << COM00) | (1 << COM01);
                TCCR0 |= TIMER0_PRESCALER;
                OCR0   = ZERO;
            #endif
        break;

        case TIMER_1:

        break;

        case TIMER_2:
            #if NORMAL_MODE == TIMER_2_MODE
                SREG  |= (1 << 7);
                TCNT2  = ZERO;
                TIMSK |= (1 << TOIE2);
                TCCR2 |= (1 << FOC2);
                TCCR2 |= TIMER2_PRESCALER;
            #elif CTC_MODE == TIMER_2_MODE
                SREG  |= (1 << 7);
                TCNT2  = ZERO;
                TIMSK |= (1 << TOIE2) | (1 << OCIE2);
                TCCR2 |= (1 << WGM21) | (1 << FOC2);
                TCCR2 |= TIMER2_PRESCALER;
                OCR2   = ZERO;
            #elif PWM_PHASE_CORRECT_MODE == TIMER_2_MODE
                DDRD  |= (1 << PIN7);
                TCNT2  = ZERO;
                TIMSK |= (1 << TOIE2) | (1 << OCIE2);
                TCCR2 |= (1 << WGM20) | (1 << COM20) | (1 << COM21);
                TCCR2 |= TIMER2_PRESCALER;
                OCR2   = ZERO;
            #elif FAST_PWM_MODE == TIMER_2_MODE
                DDRD  |= (1 << PIN7);
                TCNT2  = ZERO;
                TIMSK |= (1 << TOIE2) | (1 << OCIE2);
                TCCR2 |= (1 << WGM21) | (1 << WGM20) | (1 << COM20) | (1 << COM21);
                TCCR2 |= TIMER2_PRESCALER;
                OCR2   = ZERO;
            #endif

        break;
    }
}
#if NORMAL_MODE == TIMER_0_MODE
ISR(TIMER0_OVF_vect)
{
    static int overflow = 0;
    if(overflow >= NumberOfOverFlowT0 )
    {
        overflow = 0;
        /* Add you code here */

    }
    overflow++;
}
#elif CTC_MODE == TIMER_0_MODE
void Timer1_ChangeCompValue(u8 CompValue)
{
    OCR0 = CompValue;
}
ISR(TIMER0_COMP_vect)
{
    static int overflow = 0;
    if(overflow >= NumberOfOverFlowT0 )
    {
        overflow = 0;
        /* Add you code here */

    }
    overflow++;
}
#endif

#if NORMAL_MODE == TIMER_2_MODE
ISR(TIMER2_OVF_vect)
{
    static int overflow = 0;
    if(overflow >= NumberOfOverFlowT2 )
    {
        overflow = 0;
        /* Add you code here */

    }
    overflow++;
}
#endif


/*************************************************************************/



/* Timer_PROGRAM */
