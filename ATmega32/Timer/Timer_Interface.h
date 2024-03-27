/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : TIMER
 * @about :
****************************************/

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "STD.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include <avr/interrupt.h>

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define  TIMER0_CHANNEL         0
#define  TIMER1_CHANNEL         1
#define  TIMER2_CHANNEL         2

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerInit(void);
void M_Timer_Void_TimerSetTime(u32);
void M_Timer_Void_TimerStart(u8);
void M_Timer_Void_TimerStop(u8);
void M_Timer_Void_PWMInit(u8);
void M_Timer_Void_PWMSetDutyCycle(u8,f32);
void M_Timer_Void_PWMStart(u8);
void M_Timer_Void_PWMStop(u8);
void M_Timer_Void_SetCallBack(void(*)(void));

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
