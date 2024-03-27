/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : UART
 * @about :
****************************************/


#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define UART_POLLING_TIME                           50000



#define UCSRA_REG  (*((volatile u8 *) 0x2B))
#define UCSRB_REG  (*((volatile u8 *) 0x2A))
#define UCSRC_REG  (*((volatile u8 *) 0x40))
#define UDR_REG    (*((volatile u8 *) 0x2C))
#define UBRRL_REG  (*((volatile u8 *) 0x29))
#define UBRRH_REG  (*((volatile u8 *) 0x40))

/* UCSRA_BITS */
#define RXC_BIT              7
#define TXC_BIT              6
#define UDRE_BIT             5

/* UCSRB_BITS */
#define RXCIE_BIT             7
#define TXCIE_BIT             6
#define UDRIE_BIT             5
#define RXEN_BIT              4
#define TXEN_BIT              3



/* UCSRC_BITS */

#define URSEL_BIT            7
#define UMSEL_BIT            6
#define UPM1_BIT             5
#define UPM0_BIT             4
#define USBS_BIT             3
#define UCSZ1_BIT            2
#define UCSZ0_BIT            1

#define PARITY_DISABLE       0
#define PARITY_EVEN          1
#define PARITY_ODD           2

/*STOP BITS*/
#define STOP_1bit            0
#define STOP_2bit            1

/*frame size*/
#define FEAME_5bit          0
#define FEAME_6bit          1
#define FEAME_7bit          8
#define FEAME_8bit          3


/*UART Baud Rate*/
#define UART_SPEED_2400           416
#define UART_SPEED_4800           207
#define UART_SPEED_9600           103
#define UART_SPEED_14400          68
#define UART_SPEED_19200          51
#define UART_SPEED_28800          34
#define UART_SPEED_38400          25
#define UART_SPEED_57600          16
#define UART_SPEED_76800          12
#define UART_SPEED_115200         8
#define UART_SPEED_230400         3
#define UART_SPEED_250000         3
#define UART_SPEED_5000000        1
#define UART_SPEED_10000000       0

#endif 
