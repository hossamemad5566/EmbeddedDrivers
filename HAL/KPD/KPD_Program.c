/*********************************************************
 * @name : Hossam Emad
 * @date : 7/12/2023
 * @swc: KPD
 * @version : V1.0
 * @description :
*********************************************************/
/*Lib Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
/*MCAL*/
#include "DIO_interface.h"

/*HAL*/
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_Au8Rows[4]= {KPD_u8_R0_PIN,KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN};
u8 KPD_Au8Cols[4]= {KPD_u8_C0_PIN,KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN};
u8 KPD_Au8ReturnKey[4][4]=KPD_u8_KEY_VAL;

u8 KPD_u8GetKey(u8 *KPD_Pu8ReturnKey)
{
    u8 Local_u8REturnState  = STD_TYPE_OK;
    u8 Local_u8RowsCounter  = 0 ;
    u8 Local_u8ColsCounter  = 0 ;
    u8 Local_u8ReturnSwitch = 1 ;
    u8 Local_u8BreakFlag    = 0 ;     /* we use it to terminate the two for loops as break inside*/
                                     /* the cols loop will not terminate rows loop*/
    if(NULL != KPD_Pu8ReturnKey)
    {
    	/*Initial value to indicate if no key pressed*/
    	*KPD_Pu8ReturnKey = KPD_u8_KEY_NOT_PRESSED;
        for (Local_u8RowsCounter=0;Local_u8RowsCounter<=3;Local_u8RowsCounter++)
        {
            /*write low on pin*/
            DIO_u8SetPinValue(KPD_u8_ROWPORT,KPD_Au8Rows[Local_u8RowsCounter],DIO_u8_LOW);
            /*read the cols values*/
            for(Local_u8ColsCounter = 0;Local_u8ColsCounter<=3;Local_u8ColsCounter++)
            {
                
                DIO_u8GetPinValue(KPD_u8_COLPORT,KPD_Au8Cols[Local_u8ColsCounter],&Local_u8ReturnSwitch);
                
                if(DIO_u8_LOW == Local_u8ReturnSwitch)
                {
                    _delay_ms(20);   /*debouncing*/
                     /*one press = one output */
                    while(DIO_u8_LOW == Local_u8ReturnSwitch)
                    {
                        DIO_u8GetPinValue(KPD_u8_COLPORT,KPD_Au8Cols[Local_u8ColsCounter],&Local_u8ReturnSwitch);
                    }

                    /*return the value and terminate the function*/
                    *KPD_Pu8ReturnKey =KPD_Au8ReturnKey[Local_u8RowsCounter][Local_u8ColsCounter] ;
                    Local_u8BreakFlag = 1; break; // this to break in the row for loop
                }
                
            }
            /*deactivate the row*/
            DIO_u8SetPinValue(KPD_u8_ROWPORT,KPD_Au8Rows[Local_u8RowsCounter],DIO_u8_HIGH);
            if(Local_u8BreakFlag)
            {
            	break;
            }
        }
    }
    else 
    {
        Local_u8REturnState = STD_TYPE_NOK;
    }

    
    return Local_u8REturnState;
}
