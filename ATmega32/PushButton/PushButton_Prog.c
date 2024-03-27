/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : PushButton
 * @about :
****************************************/
/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "PushButton_Config.h"
#include "PushButton_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_PushButton_Void_PushButtonInit(u8 Copy_U8_PushButton)
{
	switch(Copy_U8_PushButton)
	{
	case PUSH_BUTTON_0: M_DIO_Void_SetPinDirection(PUSH_BUTTON_0_PIN,INPUT); break;
	case PUSH_BUTTON_1: M_DIO_Void_SetPinDirection(PUSH_BUTTON_1_PIN,INPUT); break;
	case PUSH_BUTTON_2: M_DIO_Void_SetPinDirection(PUSH_BUTTON_2_PIN,INPUT); break;
	case PUSH_BUTTON_3: M_DIO_Void_SetPinDirection(PUSH_BUTTON_3_PIN,INPUT); break;
	default:                                                                 break;
	}
}

u8   H_PushButton_U8_PushButtonRead(u8 Copy_U8_PushButton)
{
	u8 Local_U8_Reading = PUSH_BUTTON_RELEASED;
	switch(Copy_U8_PushButton)
	{
	case PUSH_BUTTON_0:
		if(M_DIO_Void_GetPinValue(PUSH_BUTTON_0_PIN) == PUSH_BUTTON_PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_DIO_Void_GetPinValue(PUSH_BUTTON_0_PIN) == PUSH_BUTTON_PRESSED)
			{
				//while(M_DIO_Void_GetPinValue(PUSH_BUTTON_0_PIN) == PUSH_BUTTON_PRESSED);
				Local_U8_Reading = PUSH_BUTTON_PRESSED;
			}
		}
		break;
	case PUSH_BUTTON_1:
		if(M_DIO_Void_GetPinValue(PUSH_BUTTON_1_PIN) == PUSH_BUTTON_PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_DIO_Void_GetPinValue(PUSH_BUTTON_1_PIN) == PUSH_BUTTON_PRESSED)
			{
				//while(M_DIO_Void_GetPinValue(PUSH_BUTTON_1_PIN) == PUSH_BUTTON_PRESSED);
				Local_U8_Reading = PUSH_BUTTON_PRESSED;
			}
		}
		break;
	case PUSH_BUTTON_2:
		if(M_DIO_Void_GetPinValue(PUSH_BUTTON_2_PIN) == PUSH_BUTTON_PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_DIO_Void_GetPinValue(PUSH_BUTTON_2_PIN) == PUSH_BUTTON_PRESSED)
			{
				//while(M_DIO_Void_GetPinValue(PUSH_BUTTON_2_PIN) == PUSH_BUTTON_PRESSED);
				Local_U8_Reading = PUSH_BUTTON_PRESSED;
			}
		}
		break;
	case PUSH_BUTTON_3:
		if(M_DIO_Void_GetPinValue(PUSH_BUTTON_3_PIN) == PUSH_BUTTON_PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_DIO_Void_GetPinValue(PUSH_BUTTON_3_PIN) == PUSH_BUTTON_PRESSED)
			{
				//while(M_DIO_Void_GetPinValue(PUSH_BUTTON_3_PIN) == PUSH_BUTTON_PRESSED);
				Local_U8_Reading = PUSH_BUTTON_PRESSED;
			}
		}
		break;
	default:                                                         break;
	}
	return Local_U8_Reading;
}

