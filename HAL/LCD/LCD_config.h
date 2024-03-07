/*********************************************************
 * @name : Hossam Emad
 * @date : 1/12/2023
 * @swc: LCD 16*2
 * @version : V1.0
 * @description :
*********************************************************/
#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

/* control pins */
#define LCD_u8_CONTROL_PORT        DIO_u8_PORTB
#define LCD_u8_RS_PIN              DIO_u8_PIN0
#define LCD_u8_E_PIN               DIO_u8_PIN1
//#define LCD_u8_RW_PIN            DIO_u8_PIN2
/*RW pin is connected to GND as we just write to LCD*/

/* data port */
#define LCD_u8_DATA_PORT           DIO_u8_PORTD

#endif