/*******************************************************************************/
/*Auther  : Mohamed Mokhtar                                                    */
/*Date    : 13 July 2021                                                       */
/*Version : V01                                                                */
/*******************************************************************************/


#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)   VAR |= (1<<BIT)
#define CLR_BIT(VAR,BIT)   VAR &=~(1<<BIT)
#define TOG_BIT(VAR,BIT)   VAR ^= (1<<BIT)
#define GET_BIT(VAR,BIT)   ((VAR >> BIT) & 1)

#ifndef __SFR_OFFSET
#  if __AVR_ARCH__ >= 100
#    define __SFR_OFFSET 0x00
#  else
#    define __SFR_OFFSET 0x20
#  endif
#endif

#endif
