/*************************************
* @name     : Hossam Emad 
* @date     : 23/12/2023
* @SWC      : ADC
* @version  : 1.0
***************************************/
#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

/*registers*/

#define ADC_u8_ADMUX          (*(volatile u8 *)0x7C)
#define ADC_u8_ADCSRA         (*(volatile u8 *)0x7A)
#define ADC_u8_ADCH           (*(volatile u8 *)0x79)
#define ADC_u8_ADCL           (*(volatile u8 *)0x78)
/* the next line is to point to 2 bytes using one pointer */
#define ADC_u16_ADC           (*(volatile u16*)0x78)
#define ADC_u8_ADCSRB         (*(volatile u8 *)0x7B)
#define ADC_u8_DIDR0          (*(volatile u8 *)0x7E)



#endif