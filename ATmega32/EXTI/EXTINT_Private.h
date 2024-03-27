/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : EXTI
 * @about :
****************************************/

#ifndef MCAL_EXTINT_EXTINT_PRIVATE_H_
#define MCAL_EXTINT_EXTINT_PRIVATE_H_

#define EXT_INT_FALLING_EDGE            1
#define EXT_INT_RISING_EDGE             2
#define EXT_INT_LOW_LEVEL               3
#define EXT_INT_ANY_LOGICAL_CHANGE      4

/*** EXT_INT REGISTERS   ***/
#define MCUCR_REG     *(volatile u8*)0x55
#define GICR_REG      *(volatile u8*)0x5B
#define MCUCSR_REG    *(volatile u8*)0x54


/*** MCUCSR BITS ***/
#define ISC2_BIT      6

/*** MCUCR BITS ***/
#define ISC11_BIT     3
#define ISC10_BIT     2
#define ISC01_BIT     1
#define ISC00_BIT     0

/*** GICR BITS ***/
#define INT1_BIT      7
#define INT0_BIT      6
#define INT2_BIT      5



#endif /* MCAL_EXTINT_EXTINT_PRIVATE_H_ */
