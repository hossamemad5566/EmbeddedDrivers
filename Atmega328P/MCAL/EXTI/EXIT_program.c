/*************************************
* @name     : Hossam Emad 
* @date     : 13/12/2023
* @SWC      : EXTI external interrupt
* @version  : 1.0
***************************************/
/*Library*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*MCAL*/
#include "EXIT_config.h"
#include "EXIT_interface.h"
#include "EXIT_private.h"

/*array of pointer that take void and return void 
* static to make it global to this file only 
* used to store the call back function then call it 
in the ISR vector function */
static void (*ECTI_APCallBack[2])(void)={NULL,NULL};

u8 EXTI_u8SetCallBack(void(*pf)(void),u8 Copy_u8EXTIIndex)
{
    u8 Local_u8ReturnType = STD_TYPE_OK;
    if((pf != NULL) &&(Copy_u8EXTIIndex <= EXTI_U8_INDX1))
    {
        ECTI_APCallBack[Copy_u8EXTIIndex] = pf;
    }
    else
    {
        Local_u8ReturnType = STD_TYPE_NOK;
    }
    return Local_u8ReturnType ;
}


/* __attribute__ : keyword to prevent the compiler from removing function
 * ((signal))    : to tell the compiler that the function is ISR */

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if(ECTI_APCallBack[EXTI_U8_INDX0] != NULL)
	{
        ECTI_APCallBack[EXTI_U8_INDX0]();
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(ECTI_APCallBack[EXTI_U8_INDX1] != NULL)
	{
        ECTI_APCallBack[EXTI_U8_INDX1]();
    }
}

u8 EXIT_u8EXITEnable ( u8 Copy_u8EXTIIndex, u8 Copy_u8EXTIEdge)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    if((Copy_u8EXTIIndex <= EXTI_U8_INDX1) && (Copy_u8EXTIEdge <= EXTI_U8_CHANGE ))
    {
        switch (Copy_u8EXTIIndex)
        {
        case EXTI_U8_INDX0      :
            switch (Copy_u8EXTIEdge)
            {
                case EXTI_U8_RISING     :   SET_BIT(EXTI_EICRA,0); SET_BIT(EXTI_EICRA,1);   break;
                case EXTI_U8_FALLING    :   CLR_BIT(EXTI_EICRA,0); SET_BIT(EXTI_EICRA,1);   break;
                case EXTI_U8_LOW        :   CLR_BIT(EXTI_EICRA,0); CLR_BIT(EXTI_EICRA,1);   break;
                case EXTI_U8_CHANGE     :   SET_BIT(EXTI_EICRA,0); CLR_BIT(EXTI_EICRA,1);   break;
            }
            SET_BIT(EXTI_EIMSK,0);
        break;
        case EXTI_U8_INDX1      :  
            switch (Copy_u8EXTIEdge)
            {
                case EXTI_U8_RISING     :   SET_BIT(EXTI_EICRA,2); SET_BIT(EXTI_EICRA,3);   break;
                case EXTI_U8_FALLING    :   CLR_BIT(EXTI_EICRA,2); SET_BIT(EXTI_EICRA,3);   break;
                case EXTI_U8_LOW        :   CLR_BIT(EXTI_EICRA,2); CLR_BIT(EXTI_EICRA,3);   break;
                case EXTI_U8_CHANGE     :   SET_BIT(EXTI_EICRA,2); CLR_BIT(EXTI_EICRA,3);   break;
            }
            SET_BIT(EXTI_EIMSK,1);
        break;
        }
    }
    else 
    {
        Local_u8ReturnState = STD_TYPE_NOK;
    }
    return Local_u8ReturnState ;
}

u8 EXIT_u8EXITDisable ( u8 Copy_u8EXTIIndex)
{
    u8 Local_u8ReturnState = STD_TYPE_OK;
    
    switch (Copy_u8EXTIIndex)
    {
        case EXTI_U8_INDX0      : CLR_BIT(EXTI_EIMSK,0); break;
        case EXTI_U8_INDX1      : CLR_BIT(EXTI_EIMSK,1); break;
        default :    Local_u8ReturnState = STD_TYPE_NOK; break;
    }
   
    return Local_u8ReturnState ;
}

