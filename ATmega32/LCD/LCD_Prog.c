/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : LCD
 * @about :
****************************************/


/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "BitMath.h"
#include "STD.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDInit(void)
{
#if LCD_MODE   ==   _8_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_D0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D3_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);

	H_Lcd_Void_LCDWriteCommand(LCD_8_BIT_MODE_COMMAND);
	H_Lcd_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
	H_Lcd_Void_LCDWriteCommand(LCD_RETURN_HOME_COMMAND);
#elif LCD_MODE   ==   _4_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PIN,OUTPUT);

	H_Lcd_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_Lcd_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_Lcd_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_3);
	H_Lcd_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
	H_Lcd_Void_LCDWriteCommand(LCD_RETURN_HOME_COMMAND);
	H_Lcd_Void_LCDWriteCommand(LCD_CLEAR);


#endif
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDWriteCharacter(u8 Copy_U8_Character)
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,HIGH);
#if   LCD_MODE   ==   _8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D0_PIN,GET_BIT(Copy_U8_Character,0));
	M_DIO_Void_SetPinValue(LCD_D1_PIN,GET_BIT(Copy_U8_Character,1));
	M_DIO_Void_SetPinValue(LCD_D2_PIN,GET_BIT(Copy_U8_Character,2));
	M_DIO_Void_SetPinValue(LCD_D3_PIN,GET_BIT(Copy_U8_Character,3));
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Character,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Character,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Character,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Character,7));

	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Character,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Character,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Character,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Character,7));
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Character,0));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Character,1));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Character,2));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Character,3));
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(5);
#endif
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDWriteCommand(u8 Copy_U8_Command)
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,LOW);
#if   LCD_MODE   ==   _8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D0_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D1_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D2_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D3_PIN,GET_BIT(Copy_U8_Command,3));
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));

	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Command,3));
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(5);
#endif
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDWriteString(u8*Copy_U8_Ptr)
{
	u8 Local_U8_Counter = 0;
	while(Copy_U8_Ptr[Local_U8_Counter] != NULL)
	{
		H_Lcd_Void_LCDWriteCharacter(Copy_U8_Ptr[Local_U8_Counter]);
		Local_U8_Counter++;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDClear()
{
	H_Lcd_Void_LCDWriteCommand(LCD_CLEAR);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDWriteNumber(s32 Copy_S32_Number)
{
	s8 Local_S8_Counter = 0;
	u8 Local_U8_Arr[10] = {0};
	if(Copy_S32_Number < 0)
	{
		Copy_S32_Number = Copy_S32_Number * -1;
		H_Lcd_Void_LCDWriteCharacter('-');
	}

	do
	{
		Local_U8_Arr[Local_S8_Counter] = Copy_S32_Number % 10;
		Copy_S32_Number                = Copy_S32_Number / 10;
		Local_S8_Counter++;
	}while(Copy_S32_Number != 0);

	while(Local_S8_Counter > 0)
	{
		H_Lcd_Void_LCDWriteCharacter(Local_U8_Arr[--Local_S8_Counter] + 48);
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDGoTo(u8 Copy_U8_Row,u8 Copy_U8_Col)
{
	u8 Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
	H_Lcd_Void_LCDWriteCommand(Local_U8_Arr[Copy_U8_Row] + Copy_U8_Col);
}
