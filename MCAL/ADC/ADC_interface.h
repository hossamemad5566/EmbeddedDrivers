/*************************************
* @name     : Hossam Emad 
* @date     : 23/12/2023
* @SWC      : ADC
* @version  : 1.0
***************************************/
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

/*Copy_u8ChannedId choices*/
#define ADC_u8_ADC0     0
#define ADC_u8_ADC1     1
#define ADC_u8_ADC2     2
#define ADC_u8_ADC3     3
#define ADC_u8_ADC4     4
#define ADC_u8_ADC5     5
#define ADC_u8_ADC6     6
#define ADC_u8_ADC7     7

void ADC_voidinit(void);

u8 ADC_u8GetDigitalValueSyncNonBlocking(u8 Copy_u8ChannedId , u16 *Copy_u16DigitalVal);

u8 ADC_u8GetDigitalValueAsync(u8 Copy_u8ChannedId , void (*Copy_PvoidCallBack)(u16 DigitalVal));


#endif