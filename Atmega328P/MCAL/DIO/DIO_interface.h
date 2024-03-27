/******************************************************************
 * @name : Hossam Emad 
 * @date : 27/11/2023
 * @SWC  : DIO 
 * @vesrion: V1.0
 * ****************************************************************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
/*Macros for port ID */
#define DIO_u8_PORTB  0
#define DIO_u8_PORTC  1
#define DIO_u8_PORTD  2

/*Macros for pin ID */
#define DIO_u8_PIN0   0
#define DIO_u8_PIN1   1
#define DIO_u8_PIN2   2
#define DIO_u8_PIN3   3
#define DIO_u8_PIN4   4
#define DIO_u8_PIN5   5
#define DIO_u8_PIN6   6
#define DIO_u8_PIN7   7

/*Macros for pin Direction */
#define DIO_u8_INPUT   0
#define DIO_u8_OUTPUT  1

/*Macros for pin Value */
#define DIO_u8_HIGH    1
#define DIO_u8_LOW     0


                        /* Prototypes of DIO APIs */
void DIO_voidInit(void);
                        
u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId, u8 Copy_u8PinId,u8 Copy_u8PinDirection);

u8 DIO_u8SetPinValue      (u8 Copy_u8PortId,u8 Copu_u8PinId,u8 Copyu8Pinvalue);

u8 DIO_u8TogglePin     (u8 Copy_u8PortId,u8 Copy_u8PinId);

u8 DIO_u8GetPinValue      (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_Pu8PinValue);

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId, u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId, u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue     (u8 Copy_u8PortId,u8 *Copy_Pu8PortValue);

#endif
