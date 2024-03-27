/*********************************************************
 * @name : Hossam Emad
 * @date : 1/12/2023
 * @swc: LCD 16*2
 * @version : V1.0
 * @description :
*********************************************************/
#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_
/*choices for LCD_u8GoToXY */
#define LCD_u8_LINE1     1
#define LCD_u8_LINE2     2
/*choices for LCD_u8WriteSpecialChar */
#define LCD_u8_SPECHIAL0    0
#define LCD_u8_SPECHIAL1    1
#define LCD_u8_SPECHIAL2    2
#define LCD_u8_SPECHIAL3    3
#define LCD_u8_SPECHIAL4    4
#define LCD_u8_SPECHIAL5    5
#define LCD_u8_SPECHIAL6    6
#define LCD_u8_SPECHIAL7    7
/*LCD_voidShift*/
#define LCD_Right  			0
#define LCD_Left  			1
#define LCD_CLEARTEXT "                                        "


void Num_u16ToString(u16 Copu_u16Num, u8 *Copu_Au16Str);



void LCD_voidInit(void);

void LCD_voidShift(u8 Copy_u8ShiftDirection,u8 Copy_u8NumOfTimes);

void LCD_voidWriteCmnd(u8 Copy_u8Cmnd);

void LCD_voidWriteChar(u8 Copy_u8Cmnd);

void LCD_voidWriteString(u8 *Copy_Pu8Srting);

void LCD_voidWriteNumber(u16 Copy_u16Num);

u8 LCD_u8GoToXY(u8 Copy_u8LineNo ,u8 Copy_u8Location);

u8 LCD_u8WriteSpecialChar(u8 Copy_u8CharIndex,u8 *Copy_Au8Char);

void LCD_voidXYString(u8 Copy_u8LineNo ,u8 Copy_u8Location,u8 *Copy_Pu8Srting);
#endif
