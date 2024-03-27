/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : UART
 * @about :
****************************************/


#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_


#include "BitMath.h"
#include "STD.h"


void UART_Init(void);
void UART_SendByte(u8);
u8 UART_SendString(u8*Copy_Pu8Arr , u8 Copy_u8size);
u8   UART_ReceiveByteSync(void);
u8 UART_ReceiveByteAsyncCallBack(void(*Pfun)(u8 ));

#endif
