/*************************************
* @name     : Hossam Emad 
* @date     : 23/12/2023
* @SWC      : ADC
* @version  : 1.0
***************************************/
#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

/*VREF choices*/
#define ADC_VREF_AREF       0
#define ADC_VREF_AVCC       1
#define ADC_VREF_INTERNAL   2
/*adjustment Choices*/
#define ADC_R_ADJ           0
#define ADC_L_ADJ           1
/*Clock select choices*/
#define ADC_PRE_2       0
#define ADC_PRE_4       1
#define ADC_PRE_8       2
#define ADC_PRE_16      3
#define ADC_PRE_32      4
#define ADC_PRE_64      5
#define ADC_PRE_128     6
    
/* 1- select VRef : AVCC */ 
#define ADC_VREF (ADC_VREF_AVCC)
/* 2- select adjustment */
#define ADC_ADJUST (ADC_R_ADJ)
/* 3- Clock select */
#define ADC_CLOCK (ADC_PRE_128)



#endif
