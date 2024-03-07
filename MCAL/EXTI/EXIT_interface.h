/*************************************
* @name     : Hossam Emad 
* @date     : 13/12/2023
* @SWC      : EXTI external interrupt
* @version  : 1.0
***************************************/
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


#define EXTI_U8_INDX0   0
#define EXTI_U8_INDX1   1

#define EXTI_U8_RISING      0
#define EXTI_U8_FALLING     1
#define EXTI_U8_LOW         2
#define EXTI_U8_CHANGE      3



u8 EXTI_u8SetCallBack(void(*pf)(void),u8 Copy_u8EXTIIndex);

u8 EXIT_u8EXITEnable ( u8 Copy_u8EXTIIndex, u8 Copy_u8EXTIEdge);

u8 EXIT_u8EXITDisable ( u8 Copy_u8EXTIIndex);




#endif