/*********************************************************
 * @name : Hossam Emad
 * @date : 1/12/2023
 * @swc: LCD 16*2
 * @version : V1.0
 * @description :
*********************************************************/
/*lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*MCAL layer*/
#include "DIO_interface.h"
/*HAL layer*/
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void LCD_voidEnable(void)
{
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
    _delay_us(1);
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW); 
}

void LCD_voidWriteCmnd(u8 Copy_u8Cmnd)
{
       /* 1- RS pin =0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
    /* 2- RW pin =0 */
    /*connect to GND in hardware*/
    //DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
    /* 3- send cmd to data pins */
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
    /* 4- latching E  for "Tpw" to pass data from i\o buffer to registers*/
    LCD_voidEnable();
}

void LCD_voidWriteChar(u8 Copy_u8Char)
{
    /* 1- RS pin =1 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
    /* 2- RW pin =0 */
    /*connect to GND in hardware*/
    // DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
    /* 3- send char to data pins */
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
    /* 4- latching E  for "Tpw" to pass Data from i\o buffer to registers*/
    LCD_voidEnable();     
}

void LCD_voidInit(void)
{
     _delay_ms(40);
    /* function set Command */
    LCD_voidWriteCmnd(0b00111000);
    _delay_us(40);
    /* Display on off control */
    LCD_voidWriteCmnd(0b00001110);
    _delay_us(40);
    /*clear display*/
    LCD_voidWriteCmnd(0b00000001);
    _delay_ms(2);
    /*Entry mode set*/
    LCD_voidWriteCmnd(0b00000110);
}

void LCD_voidWriteString(u8 *Copy_Pu8Srting)
{
    u8 Local_u8CharCounter = 0 ;
    while(Copy_Pu8Srting[Local_u8CharCounter] != '\0')
    {
        LCD_voidWriteChar(Copy_Pu8Srting[Local_u8CharCounter]);
        Local_u8CharCounter ++;
    }
}

u8 LCD_u8GoToXY(u8 Copy_u8LineNo ,u8 Copy_u8Location)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    if(Copy_u8Location < 40)
    {
        switch (Copy_u8LineNo)
        {
            case LCD_u8_LINE1 : LCD_voidWriteCmnd(Copy_u8Location + 0x80 );break;           
            case LCD_u8_LINE2 : LCD_voidWriteCmnd(Copy_u8Location + 0xC0 );break;  
            default           : Local_u8ReturnState = STD_TYPE_NOK;        break;
        }
    }
    else
    {
        Local_u8ReturnState = STD_TYPE_NOK; 
    }
    return Local_u8ReturnState;
    /*0x80 is the instruction that make the address counter point to 1st location 
    in line one 
      0xC0 is the instruction that make the address counter point to 1st location 
    in line two  
    ==============================================================================
    IR: 0b1******* the stars* represent the location in DDRAM 
    0x00 : first location in line 1
    0x40 (64) : first location in line 2
    when we represent these nummbers in the stars of IR this will result the 
    instructions above 
    */
}

void LCD_voidShift(u8 Copy_u8ShiftDirection,u8 Copy_u8NumOfTimes)
{
    u8 Local_u8Counter = 0;
    for(Local_u8Counter =0;Local_u8Counter<Copy_u8NumOfTimes;Copy_u8NumOfTimes++)
    {
        switch (Copy_u8ShiftDirection)
        {
        case LCD_Right:LCD_voidWriteCmnd(0b00011100) ;break;
        case LCD_Left :LCD_voidWriteCmnd(0b00011000) ;break;
        _delay_ms(1);
        }
    }
}

void LCD_voidXYString(u8 Copy_u8LineNo ,u8 Copy_u8Location,u8 *Copy_Pu8Srting)
{
    LCD_u8GoToXY(Copy_u8LineNo,Copy_u8Location);
    LCD_voidWriteString(Copy_Pu8Srting);
}

u8 LCD_u8WriteSpecialChar(u8 Copy_u8CharIndex,u8 *Copy_Au8Char)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    u8 Local_u8Conter = 0;
    /*choose the place in CGRAM to write your special character*/
    switch (Copy_u8CharIndex)
    {
    case LCD_u8_SPECHIAL0: LCD_voidWriteCmnd(0b01000000); break;
    case LCD_u8_SPECHIAL1: LCD_voidWriteCmnd(0b01001000); break;
    case LCD_u8_SPECHIAL2: LCD_voidWriteCmnd(0b01010000); break;
    case LCD_u8_SPECHIAL3: LCD_voidWriteCmnd(0b01011000); break;
    case LCD_u8_SPECHIAL4: LCD_voidWriteCmnd(0b01100000); break;
    case LCD_u8_SPECHIAL5: LCD_voidWriteCmnd(0b01101000); break;
    case LCD_u8_SPECHIAL6: LCD_voidWriteCmnd(0b01110000); break;
    case LCD_u8_SPECHIAL7: LCD_voidWriteCmnd(0b01111000); break;
    default:Local_u8ReturnState = STD_TYPE_NOK; break;
    }
    /*write the char represented by array of u8 to CGRAM*/
    for (Local_u8Conter=0;Local_u8Conter<8;Local_u8Conter++)
    {
        LCD_voidWriteChar(Copy_Au8Char[Local_u8Conter]);   
    }
    return Local_u8ReturnState;
}

void Num_u16ToString(u16 Copu_u16Num, u8 *Copu_Au8Str)
{
    sprintf(Copu_Au8Str, "%d", Copu_u16Num);
}

void LCD_voidWriteNumber(u16 Copy_u16Num)
{
    u8 Local_u8Buffer[10];
    Num_u16ToString(Copy_u16Num,Local_u8Buffer);
    LCD_voidWriteString(Local_u8Buffer);
}


