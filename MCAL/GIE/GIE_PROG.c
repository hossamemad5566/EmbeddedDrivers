/*************************************
* @name     : Hossam Emad 
* @date     : 13/12/2023
* @SWC      : GIE
* @version  : 1.0
***************************************/
/*Library*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*MCAL*/
#include "GIE_PRIVATE.h"
#include "GIE_INTERFACE.h"



void GIE_voidEnable(void)
{
    SET_BIT(SREG,7);
}

void GIE_voidDisable(void)
{
    CLR_BIT(SREG,7);
}
