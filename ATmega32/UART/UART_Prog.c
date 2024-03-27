/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : UART
 * @about :
****************************************/


/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"

static void(*UARTPfun)(u8 )=NULL;

void UART_Init(void)
{
	/*set Baud rate :9600*/
	UBRRH_REG =(u8)(UART_BAUD_RATE>>8);
    UBRRL_REG =(u8)UART_BAUD_RATE ;
	/* TO ENABLE RX and TX CIRCUIT */
	UCSRB_REG = (1<<RXEN_BIT)|(1<<TXEN_BIT);
	/*set frame format*/
	UCSRC_REG = (1<<URSEL_BIT)|(UART_STOP_BIT<<USBS_BIT)|(UART_FRAME_SIZE<<UCSZ0_BIT);
}

void UART_SendByte(u8 Data)
{
	u16 Local_u16Counter=0;
	while((!(GET_BIT(UCSRA_REG,UDRE_BIT)))&&(Local_u16Counter<UART_POLLING_TIME) )
	{
		Local_u16Counter++;
	}
	UDR_REG = Data;
}

u8 UART_SendString(u8*Copy_Pu8Arr , u8 Copy_u8size)
{
	u8 local_u8RetuenState = STD_OK;
	if (Copy_Pu8Arr != NULL)
	{
		for(int i =0 ;i<Copy_u8size;i++)
		{
			UART_SendByte(Copy_Pu8Arr[i]);
		}
	}
	else
	{
		local_u8RetuenState = STD_NOK;
	}
	return local_u8RetuenState;
}

u8   UART_ReceiveByteSync(void)
{
	u16 Local_u16Counter =0;
	/* Wait for data to be received */
	while ( !(GET_BIT(UCSRA_REG,RXC_BIT)) && (Local_u16Counter<UART_POLLING_TIME))
	{
		Local_u16Counter++;
	}
	/* Get and return received data from buffer */
	return UDR_REG;
}

u8 UART_ReceiveByteAsyncCallBack(void(*Pfun)(u8 ))
{
	u8 local_u8REturnType =STD_OK;
	if(Pfun!=NULL)
	{
		/*set callback*/
		UARTPfun = Pfun;
		/*enable receive int*/
		SET_BIT(UCSRB_REG,RXCIE_BIT);
	}
	else 
	{
		local_u8REturnType =STD_NOK;
	}
	return local_u8REturnType;
}

void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
    UARTPfun(UDR_REG);
}

