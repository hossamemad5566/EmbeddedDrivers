/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : Keypad
 * @about :
****************************************/

/*============================================================================================*/
/*   INCLUDES   */
/*============================================================================================*/
#include "Keypad_Config.h"
#include "Keypad_Interface.h"
#include "Keypad_Private.h"
#define NOT_INT 		0
extern  u8 change_u8Flag ;
/*============================================================================================*/
/*   FUNCTION BODY   */
/*============================================================================================*/
void H_KeyPad_Void_KeyPadInit(void)
{
	M_DIO_Void_SetPinDirection(KEYPAD_R0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R3_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(KEYPAD_R0_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R1_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R2_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R3_PIN,HIGH);

	M_DIO_Void_SetPinPullUpRes(KEYPAD_C0_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C1_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C2_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C3_PIN,ENABLE);

}

/*============================================================================================*/
/*   FUNCTION BODY   */
/*============================================================================================*/
u8   H_KeyPad_U8_KeyPadRead(u8 copy_u8Row)
{
	u8 Local_U8_KeypadRowPins[4] = { KEYPAD_R0_PIN , KEYPAD_R1_PIN , KEYPAD_R2_PIN , KEYPAD_R3_PIN };
	u8 Local_U8_KeypadColPins[4] = { KEYPAD_C0_PIN , KEYPAD_C1_PIN , KEYPAD_C2_PIN , KEYPAD_C3_PIN };
#if   KEYPAD_MODEL   ==   KEYPAD_MODEL_A
	u8 Local_U8_KeypadValue [4][4] = {{ 'S' , 'B' , 'G' , 'I' },
			                          { 'O' , '5' , '6' , '2' },
							          { 'P' , 'D' , 'U' , '3' },
						         	  { '*' , 'L' , 'R' , '4' }};
#elif KEYPAD_MODEL   ==   KEYPAD_MODEL_B
	u8 Local_U8_KeypadValue [4][4] = {{ '7' , '8' , '9' , '+' },
			                          { '4' , '5' , '6' , '-' },
							          { '1' , '2' , '3' , '*' },
							          { 'C' , '0' , '=' , '/' }};
#endif
	u8 Local_U8_Reading    = KEYPAD_RELEASED;
	//u8 Local_U8_RowCounter ;
	u8 Local_U8_ColCounter ;	
		M_DIO_Void_SetPinValue(Local_U8_KeypadRowPins[copy_u8Row],LOW);

		
		for(Local_U8_ColCounter = 0 ; Local_U8_ColCounter <= 3 ; Local_U8_ColCounter++)
		{
			#if(NOT_INT)
			if (copy_u8Row == 0)
			{
				if(((M_DIO_Void_GetPinValue((Local_U8_KeypadColPins[2]))) == KEYPAD_PRESSED))
				{
					if((M_DIO_Void_GetPinValue((Local_U8_KeypadColPins[1]))) == KEYPAD_PRESSED)
					{Local_U8_Reading= 'C';	break;}
				}
			}
			#endif
			if((M_DIO_Void_GetPinValue((Local_U8_KeypadColPins[Local_U8_ColCounter]))) == KEYPAD_PRESSED)
			{
				Local_U8_Reading = Local_U8_KeypadValue[copy_u8Row][Local_U8_ColCounter];
			    break; // this to break in the row for loop
			}
		}
		if (Local_U8_Reading != KEYPAD_RELEASED)
		{
			change_u8Flag=1;
		}
		M_DIO_Void_SetPinValue(Local_U8_KeypadRowPins[copy_u8Row],HIGH);
	
return Local_U8_Reading;
}

