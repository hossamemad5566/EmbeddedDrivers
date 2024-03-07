/******************************************************************
 * @name : Hossam Emad 
 * @date : 27/11/2023
 * @SWC  : DIO 
 * @vesrion: V1.0
 * ****************************************************************/
/*library layer*/
#include "STD_TYPES.h"
#include"BIT_MATH.h"

/* MCAL layer */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
void DIO_voidInit(void)
{
    DIO_DDRB_REG = CONC(DIO_u8_PB7_DIRECTION,DIO_u8_PB6_DIRECTION,DIO_u8_PB5_DIRECTION,DIO_u8_PB4_DIRECTION
    				   ,DIO_u8_PB3_DIRECTION,DIO_u8_PB2_DIRECTION,DIO_u8_PB1_DIRECTION,DIO_u8_PB0_DIRECTION);
    DIO_DDRC_REG = CONC(DIO_u8_PC7_DIRECTION,DIO_u8_PC6_DIRECTION,DIO_u8_PC5_DIRECTION,DIO_u8_PC4_DIRECTION
                       ,DIO_u8_PC3_DIRECTION,DIO_u8_PC2_DIRECTION,DIO_u8_PC1_DIRECTION,DIO_u8_PC0_DIRECTION);
    DIO_DDRD_REG = CONC(DIO_u8_PD7_DIRECTION,DIO_u8_PD6_DIRECTION,DIO_u8_PD5_DIRECTION,DIO_u8_PD4_DIRECTION
                       ,DIO_u8_PD3_DIRECTION,DIO_u8_PD2_DIRECTION,DIO_u8_PD1_DIRECTION,DIO_u8_PD0_DIRECTION);
    /*INITIAL VALUES FOR PINS*/                
     DIO_PORTB_REG = CONC(DIO_u8_PB7_VALUE,DIO_u8_PB6_VALUE,DIO_u8_PB5_VALUE,DIO_u8_PB4_VALUE
                         ,DIO_u8_PB3_VALUE,DIO_u8_PB2_VALUE,DIO_u8_PB1_VALUE,DIO_u8_PB0_VALUE);
     DIO_PORTC_REG = CONC(DIO_u8_PC7_VALUE,DIO_u8_PC6_VALUE,DIO_u8_PC5_VALUE,DIO_u8_PC4_VALUE
                         ,DIO_u8_PC3_VALUE,DIO_u8_PC2_VALUE,DIO_u8_PC1_VALUE,DIO_u8_PC0_VALUE);
     DIO_PORTD_REG = CONC(DIO_u8_PD7_VALUE,DIO_u8_PD6_VALUE,DIO_u8_PD5_VALUE,DIO_u8_PD4_VALUE
                         ,DIO_u8_PD3_VALUE,DIO_u8_PD2_VALUE,DIO_u8_PD1_VALUE,DIO_u8_PD0_VALUE);
}
                        
u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId, u8 Copy_u8PinId,u8 Copy_u8PinDirection)
{
    u8 Local_u8ReturnState = STD_TYPE_OK ;
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && ((Copy_u8PinDirection == DIO_u8_INPUT)||(Copy_u8PinDirection == DIO_u8_OUTPUT)) )
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTB : 
            switch (Copy_u8PinDirection)
            {
                case DIO_u8_OUTPUT : SET_BIT(DIO_DDRB_REG,Copy_u8PinId)  ; break;
                case DIO_u8_INPUT  : CLR_BIT(DIO_DDRB_REG,Copy_u8PinId)  ; break;
            }    
            break;
        case DIO_u8_PORTC : 
            switch (Copy_u8PinDirection)
            {
                case DIO_u8_OUTPUT : SET_BIT(DIO_DDRC_REG,Copy_u8PinId)  ; break;
                case DIO_u8_INPUT  : CLR_BIT(DIO_DDRC_REG,Copy_u8PinId)  ; break;  
            } 
            break;
        case DIO_u8_PORTD : 
            switch (Copy_u8PinDirection)
            {
                case DIO_u8_OUTPUT : SET_BIT(DIO_DDRD_REG,Copy_u8PinId)  ; break;
                case DIO_u8_INPUT  : CLR_BIT(DIO_DDRD_REG,Copy_u8PinId)  ; break;  
            } 
        }
    }
    else 
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState;
}

u8 DIO_u8SetPinValue      (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <=DIO_u8_PIN7)&& ((Copy_u8PinValue == DIO_u8_HIGH)||(Copy_u8PinValue == DIO_u8_LOW)))
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTB : 
            switch (Copy_u8PinValue)
            {
                case DIO_u8_HIGH : SET_BIT(DIO_PORTB_REG,Copy_u8PinId)   ; break;
                case DIO_u8_LOW  : CLR_BIT(DIO_PORTB_REG,Copy_u8PinId)   ; break;  
            }    
            break;
        case DIO_u8_PORTC : 
            switch (Copy_u8PinValue)
                {
                    case DIO_u8_HIGH : SET_BIT(DIO_PORTC_REG ,Copy_u8PinId)   ; break;
                    case DIO_u8_LOW  : CLR_BIT(DIO_PORTC_REG ,Copy_u8PinId)   ; break;
                }
            break;
        case DIO_u8_PORTD : 
            switch (Copy_u8PinValue)
                {
                    case DIO_u8_HIGH : SET_BIT(DIO_PORTD_REG,Copy_u8PinId)   ; break;
                    case DIO_u8_LOW  : CLR_BIT(DIO_PORTD_REG,Copy_u8PinId)   ; break; 
                }
            break;        
        }
    }
    else 
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState;
}

u8 DIO_u8TogglePin     (u8 Copy_u8PortId,u8 Copy_u8PinId)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <=DIO_u8_PIN7))
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTB :TOG_BIT(DIO_PORTB_REG,Copy_u8PinId)   ; break;
        case DIO_u8_PORTC :TOG_BIT(DIO_PORTC_REG,Copy_u8PinId)   ; break;
        case DIO_u8_PORTD :TOG_BIT(DIO_PORTD_REG,Copy_u8PinId)   ; break;
        }
    }
    else 
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState;
}

u8 DIO_u8GetPinValue      (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_Pu8PinValue)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    u8 Local_u8PinValue; // variable to read the pin value
    if((Copy_u8PortId <= DIO_u8_PORTD)&&(Copy_u8PinId <= DIO_u8_PIN7)&&(Copy_Pu8PinValue!=NULL))
    {
        switch (Copy_u8PortId)
        {
            case DIO_u8_PORTB :
                Local_u8PinValue = GET_BIT(DIO_PINB_REG,Copy_u8PinId);
                if(DIO_u8_HIGH==Local_u8PinValue)
                	{*Copy_Pu8PinValue = DIO_u8_HIGH;}
                else
                	{*Copy_Pu8PinValue = DIO_u8_LOW ;}
            break;
            case DIO_u8_PORTC :
                Local_u8PinValue = GET_BIT(DIO_PINC_REG,Copy_u8PinId);
                if(DIO_u8_HIGH==Local_u8PinValue)
					{*Copy_Pu8PinValue = DIO_u8_HIGH;}
				else
					{*Copy_Pu8PinValue = DIO_u8_LOW ;}
            break;
            case DIO_u8_PORTD :
                Local_u8PinValue = GET_BIT(DIO_PIND_REG,Copy_u8PinId);
                if(DIO_u8_HIGH==Local_u8PinValue)
					{*Copy_Pu8PinValue = DIO_u8_HIGH;}
				else
					{*Copy_Pu8PinValue = DIO_u8_LOW ;}
            break;

        }
    }
    else
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState;
}

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    if((Copy_u8PortId <= DIO_u8_PORTD)&&((Copy_u8PortDirection == DIO_u8_INPUT)||(Copy_u8PortDirection == DIO_u8_OUTPUT)))
    {
        switch (Copy_u8PortId)
        {
            case DIO_u8_PORTB : 
                switch (Copy_u8PortDirection)
                {
                    case DIO_u8_OUTPUT:  DIO_DDRB_REG =0xff; break;
                    case DIO_u8_INPUT :  DIO_DDRB_REG =0x00; break;
                }
            break;
            case DIO_u8_PORTC : 
                switch (Copy_u8PortDirection)
                {
                    case DIO_u8_OUTPUT:  DIO_DDRC_REG =0xff; break;
                    case DIO_u8_INPUT :  DIO_DDRC_REG =0x00; break;
                }
            break;
            case DIO_u8_PORTD : 
                switch (Copy_u8PortDirection)
                {
                    case DIO_u8_OUTPUT:  DIO_DDRD_REG =0xff; break;
                    case DIO_u8_INPUT :  DIO_DDRD_REG =0x00; break;
                }
            break;
        }
    }
    else 
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState;

}

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    switch (Copy_u8PortId)
    {
        case DIO_u8_PORTB : DIO_PORTB_REG = Copy_u8PortValue; break;
        case DIO_u8_PORTC : DIO_PORTC_REG = Copy_u8PortValue; break;
        case DIO_u8_PORTD : DIO_PORTD_REG = Copy_u8PortValue; break;
        default : Local_u8ReturnState = STD_TYPE_NOK;         break;
    }
    return Local_u8ReturnState;
}

u8 Dio_u8GetPortValue     (u8 Copy_u8PortId,u8 *Copy_Pu8PortValue)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    if((Copy_u8PortId >= DIO_u8_PORTD)&&(Copy_Pu8PortValue!=NULL))
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTB :*Copy_Pu8PortValue = DIO_PINB_REG; break;
        case DIO_u8_PORTC :*Copy_Pu8PortValue = DIO_PINC_REG; break;
        case DIO_u8_PORTD :*Copy_Pu8PortValue = DIO_PIND_REG; break;
        }
    }
    else 
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState;
}

