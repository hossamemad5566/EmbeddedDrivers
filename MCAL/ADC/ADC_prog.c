/*************************************
* @name     : Hossam Emad 
* @date     : 23/12/2023
* @SWC      : ADC
* @version  : 1.0
***************************************/
/*LIBRARY*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*INCLUSION*/
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void (*ADC_PvoidCallBack)(u16 DigitalVal) = NULL;



void ADC_voidinit(void)
{
    /*vref*/
    #if   (ADC_VREF == ADC_VREF_AREF)
    CLR_BIT(ADC_u8_ADMUX,6);    CLR_BIT(ADC_u8_ADMUX,7);
    #elif (ADC_VREF == ADC_VREF_AVCC)
    SET_BIT(ADC_u8_ADMUX,6);    CLR_BIT(ADC_u8_ADMUX,7);
    #elif (ADC_VREF == ADC_VREF_INTERNAL)
    CLR_BIT(ADC_u8_ADMUX,6);    CLR_BIT(ADC_u8_ADMUX,7);
    #endif

    /*adjusment*/
    #if     (ADC_ADJUST == ADC_R_ADJ)
    CLR_BIT(ADC_u8_ADMUX,5);
    #elif   (ADC_ADJUST == ADC_L_ADJ)
    SET_BIT(ADC_u8_ADMUX,5);
    #endif
    
    /* 3- Clock select : prescaler 128 */ 
    #if  (ADC_CLOCK == ADC_PRE_2)
        CLR_BIT(ADC_u8_ADCSRA,0);   CLR_BIT(ADC_u8_ADCSRA,1);   CLR_BIT(ADC_u8_ADCSRA,2);
    #elif(ADC_CLOCK == ADC_PRE_4)
        CLR_BIT(ADC_u8_ADCSRA,0);   SET_BIT(ADC_u8_ADCSRA,1);   CLR_BIT(ADC_u8_ADCSRA,2);
    #elif(ADC_CLOCK == ADC_PRE_8)
        SET_BIT(ADC_u8_ADCSRA,0);   SET_BIT(ADC_u8_ADCSRA,1);   CLR_BIT(ADC_u8_ADCSRA,2);
    #elif(ADC_CLOCK == ADC_PRE_16)
        CLR_BIT(ADC_u8_ADCSRA,0);   CLR_BIT(ADC_u8_ADCSRA,1);   SET_BIT(ADC_u8_ADCSRA,2);
    #elif(ADC_CLOCK == ADC_PRE_32)
        SET_BIT(ADC_u8_ADCSRA,0);   CLR_BIT(ADC_u8_ADCSRA,1);   SET_BIT(ADC_u8_ADCSRA,2);
    #elif(ADC_CLOCK == ADC_PRE_64)
        CLR_BIT(ADC_u8_ADCSRA,0);   SET_BIT(ADC_u8_ADCSRA,1);   SET_BIT(ADC_u8_ADCSRA,2);
    #elif(ADC_CLOCK == ADC_PRE_128)
        SET_BIT(ADC_u8_ADCSRA,0);   SET_BIT(ADC_u8_ADCSRA,1);   SET_BIT(ADC_u8_ADCSRA,2);
    #endif
    /* 4- check auto trigger */
    CLR_BIT(ADC_u8_ADCSRA,5);
    /* 5- enable ADC */
    SET_BIT(ADC_u8_ADCSRA,7);
}

u8 ADC_u8GetDigitalValueSyncNonBlocking(u8 Copy_u8ChannedId , u16 *Copy_u16DigitalVal)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    u16 Local_u16Counter =0;    /*unblocking counter */
    u8 Local_u8Flag =0;
    if ((Copy_u8ChannedId <= ADC_u8_ADC7) && (Copy_u16DigitalVal != NULL))
    {
         /* 1 - choose channel */
         /*clear the old Mux bits value*/
         ADC_u8_ADMUX &= 0b11110000;
         /*set the new channel */
         ADC_u8_ADMUX |= Copy_u8ChannedId;
         /* 2 - START CONVERSION*/
        SET_BIT(ADC_u8_ADCSRA,6);
         /* 3 - wait converion finish*/
        while (((GET_BIT(ADC_u8_ADCSRA,4))==0) && (Local_u16Counter < 50000))
        {
            Local_u16Counter ++;
            Local_u8Flag = 1;

        }
        /* 4 - read the digital val of ADC*/
        if(1 == Local_u8Flag)
        {
            /*read value*/
            *Copy_u16DigitalVal = ADC_u16_ADC; 
            /* 5 - clear flag*/
            SET_BIT(ADC_u8_ADCSRA,4) ;
            /*here we clear the flag as it will sill raised if the isr not used*/
        }
        
       
    }
    else
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState ;

}

u8 ADC_u8GetDigitalValueAsync(u8 Copy_u8ChannedId , void (*Copy_PvoidCallBack)(u16 DigitalVal))
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    if((Copy_u8ChannedId <= ADC_u8_ADC7) && (Copy_PvoidCallBack != NULL))
    {
        /* 1 - check if ADC not Busy */
        if(((GET_BIT(ADC_u8_ADCSRA,4))== 0))
        {
            /* 2 - udate Global PTR to function */
            ADC_PvoidCallBack = Copy_PvoidCallBack;
            /* 3 - set channel */
            /*clear the old Mux bits value*/
            ADC_u8_ADMUX &= 0b11110000;
            /*set the new channel */
            ADC_u8_ADMUX |= Copy_u8ChannedId;
            /* 4 - START CONVERSION*/
            SET_BIT(ADC_u8_ADCSRA,6);
            /* 5 - Enable PIE of ADC */
            SET_BIT(ADC_u8_ADCSRA,3);
        }
       
    }
    else
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState;

}

void __vector_21 (void) __attribute__((signal));
void __vector_21 (void)
{
    ADC_PvoidCallBack(ADC_u16_ADC);
}