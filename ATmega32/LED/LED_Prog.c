/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : LED
 * @about :
****************************************/

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "LED_Config.h"
#include "LED_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedInit(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_YEL: M_DIO_Void_SetPinDirection(LED_YEL_PIN,OUTPUT); break;
	case LED_BLU: M_DIO_Void_SetPinDirection(LED_BLU_PIN,OUTPUT); break;
	case LED_GRN: M_DIO_Void_SetPinDirection(LED_GRN_PIN,OUTPUT); break;
	case LED_RED: M_DIO_Void_SetPinDirection(LED_RED_PIN,OUTPUT); break;
	default:                                                      break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedOn(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_YEL: M_DIO_Void_SetPinValue(LED_YEL_PIN,HIGH); break;
	case LED_BLU: M_DIO_Void_SetPinValue(LED_BLU_PIN,HIGH); break;
	case LED_GRN: M_DIO_Void_SetPinValue(LED_GRN_PIN,HIGH); break;
	case LED_RED: M_DIO_Void_SetPinValue(LED_RED_PIN,HIGH); break;
	default:                                                break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedOff(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_YEL: M_DIO_Void_SetPinValue(LED_YEL_PIN,LOW); break;
	case LED_BLU: M_DIO_Void_SetPinValue(LED_BLU_PIN,LOW); break;
	case LED_GRN: M_DIO_Void_SetPinValue(LED_GRN_PIN,LOW); break;
	case LED_RED: M_DIO_Void_SetPinValue(LED_RED_PIN,LOW); break;
	default:                                               break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedBlink(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_YEL:
		M_DIO_Void_SetPinValue(LED_YEL_PIN,HIGH);
		_delay_ms(LED_BLINKING_TIME);
		M_DIO_Void_SetPinValue(LED_YEL_PIN,LOW);
		break;
	case LED_BLU:
		M_DIO_Void_SetPinValue(LED_BLU_PIN,HIGH);
		_delay_ms(LED_BLINKING_TIME);
		M_DIO_Void_SetPinValue(LED_BLU_PIN,LOW);
		break;
	case LED_GRN:
		M_DIO_Void_SetPinValue(LED_GRN_PIN,HIGH);
		_delay_ms(LED_BLINKING_TIME);
		M_DIO_Void_SetPinValue(LED_GRN_PIN,LOW);
		break;
	case LED_RED:
		M_DIO_Void_SetPinValue(LED_RED_PIN,HIGH);
		_delay_ms(LED_BLINKING_TIME);
		M_DIO_Void_SetPinValue(LED_RED_PIN,LOW);
		break;
	default:   break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedTog(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case LED_YEL: M_DIO_Void_TogPin(LED_YEL_PIN); break;
	case LED_BLU: M_DIO_Void_TogPin(LED_BLU_PIN); break;
	case LED_GRN: M_DIO_Void_TogPin(LED_GRN_PIN); break;
	case LED_RED: M_DIO_Void_TogPin(LED_RED_PIN); break;
	default:                                      break;
	}
}
