/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : Relay
 * @about :
****************************************/
#include "DIO_Interface.h"
#include "Relay.h"
#include <util/delay.h>

void Relay_voidInit(void)
{
    M_DIO_Void_SetPinDirection(RELAY_PIN,OUTPUT);
    M_DIO_Void_SetPinValue(RELAY_PIN,LOW);
}

void Relay_voidFlash(void)
{
    static u8 local_u8RState = 0;
    local_u8RState = !local_u8RState;
    M_DIO_Void_SetPinValue(RELAY_PIN,local_u8RState);
}

void Relay_voidOff(void)
{
    M_DIO_Void_SetPinValue(RELAY_PIN,LOW);
}