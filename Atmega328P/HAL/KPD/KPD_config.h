/*********************************************************
 * @name : Hossam Emad
 * @date : 7/12/2023
 * @swc: KPD
 * @version : V1.0
 * @description :
*********************************************************/
#ifndef _KPD_CONFIG_H_
#define _KPD_CONFIG_H_
/*the default value for o/p pins is high*/

/*output*/
#define KPD_u8_ROWPORT  DIO_u8_PORTC
#define KPD_u8_R0_PIN   DIO_u8_PIN0
#define KPD_u8_R1_PIN   DIO_u8_PIN1
#define KPD_u8_R2_PIN   DIO_u8_PIN2
#define KPD_u8_R3_PIN   DIO_u8_PIN3
/*input*/
#define KPD_u8_COLPORT  DIO_u8_PORTB
#define KPD_u8_C0_PIN   DIO_u8_PIN2
#define KPD_u8_C1_PIN   DIO_u8_PIN3
#define KPD_u8_C2_PIN   DIO_u8_PIN4
#define KPD_u8_C3_PIN   DIO_u8_PIN5

#define KPD_u8_KEY_VAL {{'7','8','9','/'},\
                        {'4','5','6','*'},\
                        {'1','2','3','-'},\
                        {'%','0','=','+'}}


#endif
