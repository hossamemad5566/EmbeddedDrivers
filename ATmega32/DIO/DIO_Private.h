/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : DIO
 * @about :
****************************************/

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define PINA_REG     *(volatile u8*)0x39
#define DDRA_REG     *(volatile u8*)0x3A
#define PORTA_REG    *(volatile u8*)0x3B

#define PINB_REG     *(volatile u8*)0x36
#define DDRB_REG     *(volatile u8*)0x37
#define PORTB_REG    *(volatile u8*)0x38

#define PINC_REG     *(volatile u8*)0x33
#define DDRC_REG     *(volatile u8*)0x34
#define PORTC_REG    *(volatile u8*)0x35

#define PIND_REG     *(volatile u8*)0x30
#define DDRD_REG     *(volatile u8*)0x31
#define PORTD_REG    *(volatile u8*)0x32

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
