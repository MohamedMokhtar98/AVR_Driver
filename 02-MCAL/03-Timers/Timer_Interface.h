/*
 * Timer_Interface.h
 *
 *  Created on: Mar 04, 2023
 *      Author: Mohamed Mokhtar
 */
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "STD_TYPES.h"

/******************** Private Section ************************/
#define TIMER_0   0
#define TIMER_1   1
#define TIMER_2   2

#define NORMAL_MODE             0
#define CTC_MODE                1
#define PWM_PHASE_CORRECT_MODE  2
#define FAST_PWM_MODE           3

#define NO_CLOCK_SOURCE         0
#define NO_PRESCALING           1
#define X8_PRESCALER            2
#define X64_PRESCALER           3
#define X256_PRESCALER          4
#define X1024_PRESCALER         5
#define EXT_CLKSR_T0_FALEDG     6
#define EXT_CLKSR_T0_RISEDG     7
/*************************************************************************/

/******************* ProtoTypes Global Function Section*******************/
void Timer_n_Init(u8 Timer_n);
/*************************************************************************/

/* Configuration Section */
/********************* Timer 0 Configuration *****************************/
/*
    Option:
        NORMAL_MODE
        CTC_MODE
        PWM_PHASE_CORRECT_MODE
        FAST_PWM_MODE
*/
#define TIMER_0_MODE CTC_MODE

/*
    Option:
        NO_CLOCK_SOURCE
        NO_PRESCALING
        X8_PRESCALER
        X64_PRESCALER
        X256_PRESCALER
        X1024_PRESCALER
        EXT_CLKSR_T0_FALEDG
        EXT_CLKSR_T0_RISEDG
*/
#define TIMER0_PRESCALER X8_PRESCALER

/*
    NOTE: Choose the same Prescaler from TIMERn_PRESCALER
    Option:
        1
        8
        64
        256
        1024
*/
#define TIMER0_EQ_PRESCALER 8
/*
    Required time in milliseconds
*/
#define RequiredTimeT0 1000

#define NumberOfOverFlowT0 ((float)RequiredTimeT0 / ((((float)TIMER0_EQ_PRESCALER/(float)F_CPU) * 256.0) * 1000.0))


/********************* Timer 1 Configuration *****************************/



/********************* Timer 2 Configuration *****************************/
/*
    Option:
        NORMAL_MODE
        CTC_MODE
        PWM_PHASE_CORRECT_MODE
        FAST_PWM_MODE
*/
#define TIMER_2_MODE NORMAL_MODE

/*
    Option:
        NO_CLOCK_SOURCE
        NO_PRESCALING
        X8_PRESCALER
        X64_PRESCALER
        X256_PRESCALER
        X1024_PRESCALER
        EXT_CLKSR_T0_FALEDG
        EXT_CLKSR_T0_RISEDG
*/
#define TIMER2_PRESCALER X8_PRESCALER

/*
    NOTE: Choose the same Prescaler from TIMERn_PRESCALER
    Option:
        1
        8
        64
        256
        1024
*/
#define TIMER2_EQ_PRESCALER 8
/*
    Required time in milliseconds
*/
#define RequiredTimeT2 1000

#define NumberOfOverFlowT2 ((float)RequiredTimeT2 / ((((float)TIMER2_EQ_PRESCALER/(float)F_CPU) * 256.0) * 1000.0))


#endif /* Timer_HEADER_H_ */
