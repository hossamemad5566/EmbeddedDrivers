/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : LCD
 * @about :
****************************************/


#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "BitMath.h"
#include "STD.h"
#include "DIO_Interface.h"
#include <util/delay.h>

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define _8_BIT_MODE                   8
#define _4_BIT_MODE                   4
#define LCD_8_BIT_MODE_COMMAND        0x38
#define LCD_DISPLAY_ON_COMMAND        0x0C
#define LCD_RETURN_HOME_COMMAND       0x02
#define LCD_4_BIT_MODE_COMMAND_1      0x33
#define LCD_4_BIT_MODE_COMMAND_2      0x32
#define LCD_4_BIT_MODE_COMMAND_3      0x28
#define LCD_CLEAR                     0x01
#define LCD_R0_COMMAND                0x80
#define LCD_R1_COMMAND                0xC0
#define LCD_R2_COMMAND                0x94
#define LCD_R3_COMMAND                0xD4


/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_Lcd_Void_LCDInit(void);
void H_Lcd_Void_LCDWriteCharacter(u8);
void H_Lcd_Void_LCDWriteCommand(u8);
void H_Lcd_Void_LCDWriteString(u8*);
void H_Lcd_Void_LCDClear(void);
void H_Lcd_Void_LCDWriteNumber(s32);
void H_Lcd_Void_LCDGoTo(u8,u8);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
