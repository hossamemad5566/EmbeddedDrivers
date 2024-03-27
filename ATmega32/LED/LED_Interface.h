/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : LED
 * @about :
****************************************/

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

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
#define LED_YEL    1
#define LED_BLU    2
#define LED_GRN    3
#define LED_RED    4
/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedInit(u8);
void H_LED_Void_LedOn(u8);
void H_LED_Void_LedOff(u8);
void H_LED_Void_LedBlink(u8);
void H_LED_Void_LedTog(u8);

#endif /* HAL_LED_LED_INTERFACE_H_ */
