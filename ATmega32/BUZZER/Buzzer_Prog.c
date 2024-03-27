/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : Buzzer
 * @about :
****************************************/

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "STD.h"
#include "DIO_Interface.h"

#include <util/delay.h>

#include "Buzzer_Config.h"
#include "Buzzer_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerInit(void)
{
	M_DIO_Void_SetPinDirection(BUZZER_PIN,OUTPUT);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerOn(void)
{
	M_DIO_Void_SetPinValue(BUZZER_PIN,HIGH);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerOff(void)
{
	M_DIO_Void_SetPinValue(BUZZER_PIN,LOW);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerTog(void)
{
	M_DIO_Void_TogPin(BUZZER_PIN);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerOnce(void)
{
	M_DIO_Void_SetPinValue(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_ON_TIME);
	M_DIO_Void_SetPinValue(BUZZER_PIN,LOW);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerTwice(void)
{
	M_DIO_Void_SetPinValue(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_ON_TIME);
	M_DIO_Void_SetPinValue(BUZZER_PIN,LOW);
	_delay_ms(BUZZER_OFF_TIME);
	M_DIO_Void_SetPinValue(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_ON_TIME);
	M_DIO_Void_SetPinValue(BUZZER_PIN,LOW);
}
