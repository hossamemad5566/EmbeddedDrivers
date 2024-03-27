/*************************************
* @name     : Hossam Emad 
* @date     : 13/12/2023
* @SWC      : EXTI external interrupt
* @version  : 1.0
***************************************/
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

/*Registers of EXIT*/


#define EXTI_EICRA       (*(volatile u8*)0x69)
#define EXTI_EIMSK       (*(volatile u8*)0x3D)
#define EXTI_EIFR        (*(volatile u8*)0x3C)








/**
- EICRA – External Interrupt Control Register A
>>>> : Interrupt Sense Control BITS (action generate interrupt)
- EIMSK – External Interrupt Mask Register
>>>> :  External Interrupt Request Enable (PIE)
- EIFR – External Interrupt Flag Register 
>>>> : (PIF)
*/
#endif
