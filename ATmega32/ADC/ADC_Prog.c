/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : ADC
 * @about :
****************************************/


#include "ADC_Interface.h"
#include "ADC_Private.h"





void M_ADC_Void_ADCInit(void)
{
#if   ADC_VREF   ==   AVCC
	SET_BIT(ADMUX_REG,REFS0_BIT);
	CLR_BIT(ADMUX_REG,REFS1_BIT);
#elif ADC_VREF   ==   AREF_PIN
	CLR_BIT(ADMUX_REG,REFS0_BIT);
	CLR_BIT(ADMUX_REG,REFS1_BIT);
#elif ADC_VREF   ==   _2V5
	SET_BIT(ADMUX_REG,REFS0_BIT);
	SET_BIT(ADMUX_REG,REFS1_BIT);
#endif
	/* TO SELECT RIGHT ADJUST */
	CLR_BIT(ADMUX_REG,ADLAR_BIT);
#if   ADC_PRESCALER_DV   ==   128
	SET_BIT(ADCSRA_REG,ADPS0_BIT);
	SET_BIT(ADCSRA_REG,ADPS1_BIT);
	SET_BIT(ADCSRA_REG,ADPS2_BIT);
#elif ADC_PRESCALER_DV   ==   64
	CLR_BIT(ADCSRA_REG,ADPS0_BIT);
	SET_BIT(ADCSRA_REG,ADPS1_BIT);
	SET_BIT(ADCSRA_REG,ADPS2_BIT);
#endif
	/* TO ENABLE AUTO TRIGGER MODE */
	SET_BIT(ADCSRA_REG,ADATE_BIT);
	/* TO ENABLE ADC CIRCIUT */
	SET_BIT(ADCSRA_REG,ADEN_BIT);

}

u16  M_ADC_U16_ADCRead(u8 Copy_U8_AdcChannel)
{
	u32 Local_U32_Counter = 0;
	/* TO START CONVERSION */
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	ADMUX_REG = ADMUX_REG & 0b11100000;
	ADMUX_REG = ADMUX_REG | Copy_U8_AdcChannel;
	while(Local_U32_Counter < 2000000)
	{
		Local_U32_Counter++;
		if((GET_BIT((ADCSRA_REG),(ADIF_BIT))) == ADC_CONVERSION_COMPLETE)
		{
			break;
		}
	}
	return ADCVALUE;
}








