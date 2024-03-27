/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : TIMER
 * @about :
****************************************/

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "Timer_Config.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"

/*--------------------------------------------------------------------------------------------*/
/*   GLOBAL VARIABLES   */
/*--------------------------------------------------------------------------------------------*/
void(*Timer_CallBack)(void);
u32 Timer_U32_NumOfOV = 0;
u32 Timer_U32_NumOfCM = 0;
u8  Timer_U8_RemTicks = 0;

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerInit(void)
{
#if   TIMER0_MODE   ==   NORMAL_MODE
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
	/* TO ENABLE TIMER0 OV INTERRUPT */
	SET_BIT(TIMSK_REG,TOIE0_BIT);
#elif TIMER0_MODE   ==   CTC_MODE
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
	/* TO ENABLE TIMER0 CM INTERRUPT */
	SET_BIT(TIMSK_REG,OCIE0_BIT);
#endif
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerSetTime(u32 Copy_U32_DesiredTime)
{
	u32 Local_U32_TickTime   = TIMER0_PRESCALER_DF / F_OSC; /* RESULT WILL BE IN MICRO SECONDS */
	u32 Local_U32_TotalTicks = (Copy_U32_DesiredTime * 1000) / Local_U32_TickTime;

#if   TIMER0_MODE   ==   NORMAL_MODE
	Timer_U32_NumOfOV        = Local_U32_TotalTicks / 256;
	Timer_U8_RemTicks        = Local_U32_TotalTicks % 256;
	if(Timer_U8_RemTicks != 0)
	{
		TCNT0_REG = 256 - Timer_U8_RemTicks;
		Timer_U32_NumOfOV++;
	}
#elif TIMER0_MODE   ==   CTC_MODE
	u8 Local_U8_DivisionValue = 255;
	while(Local_U32_TotalTicks % Local_U8_DivisionValue)
	{
		Local_U8_DivisionValue--;
	}
	OCR0_REG = Local_U8_DivisionValue - 1;
	Timer_U32_NumOfCM = Local_U32_TotalTicks / Local_U8_DivisionValue;
#endif
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerStart(u8 Copy_U8_TimerChannel)
{
	switch(Copy_U8_TimerChannel)
	{
	case TIMER0_CHANNEL:
#if   TIMER0_PRESCALER_DF   ==   1024
	SET_BIT(TCCR0_REG,CS00_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	SET_BIT(TCCR0_REG,CS02_BIT);
#elif TIMER0_PRESCALER_DF   ==   256
	CLR_BIT(TCCR0_REG,CS00_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	SET_BIT(TCCR0_REG,CS02_BIT);
#endif
		break;
	case TIMER1_CHANNEL:
#if   TIMER1_PRESCALER_DF   ==   1024
		SET_BIT(TCCR1B_REG,CS10_BIT);
		CLR_BIT(TCCR1B_REG,CS11_BIT);
		SET_BIT(TCCR1B_REG,CS12_BIT);
#elif TIMER1_PRESCALER_DF   ==   256
		CLR_BIT(TCCR1B_REG,CS10_BIT);
		CLR_BIT(TCCR1B_REG,CS11_BIT);
		SET_BIT(TCCR1B_REG,CS12_BIT);
#endif
		break;
	case TIMER2_CHANNEL:
		break;
	default: break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerStop(u8 Copy_U8_TimerChannel)
{
	switch(Copy_U8_TimerChannel)
	{
	case TIMER0_CHANNEL:
		CLR_BIT(TCCR0_REG,CS00_BIT);
		CLR_BIT(TCCR0_REG,CS01_BIT);
		CLR_BIT(TCCR0_REG,CS02_BIT);
	

		break;
	case TIMER1_CHANNEL:
		CLR_BIT(TCCR1B_REG,CS10_BIT);
		CLR_BIT(TCCR1B_REG,CS11_BIT);
		CLR_BIT(TCCR1B_REG,CS12_BIT);
		break;
	case TIMER2_CHANNEL:
		break;
	default: break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMInit(u8 Copy_U8_TimerChannel)
{
	switch(Copy_U8_TimerChannel)
	{
	case TIMER0_CHANNEL:
		M_DIO_Void_SetPinDirection(PB3_PIN,OUTPUT);
	#if TIMER0_MODE   ==   FAST_PWM_MODE
		SET_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);
	#elif TIMER0_MODE   ==   PHASE_CORRECT_PWM_MODE
		SET_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);
	#endif
	#if   TIMER0_FAST_PWM_MODE   ==   NON_INVERTED
		CLR_BIT(TCCR0_REG,COM00_BIT);
		SET_BIT(TCCR0_REG,COM01_BIT);
	#elif TIMER0_FAST_PWM_MODE   ==   INVERTED
		SET_BIT(TCCR0_REG,COM00_BIT);
		SET_BIT(TCCR0_REG,COM01_BIT);
	#endif
		break;
	case TIMER1_CHANNEL:
		M_DIO_Void_SetPinDirection(PD5_PIN,OUTPUT);
		/* TO SELECT MODE NO. 14 IN TABLE 47 */
		CLR_BIT(TCCR1A_REG,WGM10_BIT);
		SET_BIT(TCCR1A_REG,WGM11_BIT);
		SET_BIT(TCCR1B_REG,WGM12_BIT);
		SET_BIT(TCCR1B_REG,WGM13_BIT);
		/* TO SELECT NON INVERTED MODE */
		CLR_BIT(TCCR1A_REG,COM1A0_BIT);
		SET_BIT(TCCR1A_REG,COM1A1_BIT);
		ICR1_REG = ((F_OSC * 1000000) / TIMER1_PRESCALER_DF) / F_PWM1;
		break;
	case TIMER2_CHANNEL:
		break;
	default: break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMSetDutyCycle(u8 Copy_U8_TimerChannel,f32 Copy_F32_DutyCycle)
{
	switch(Copy_U8_TimerChannel)
	{
	case TIMER0_CHANNEL:
#if TIMER0_MODE   ==   FAST_PWM_MODE
	OCR0_REG = ((Copy_F32_DutyCycle * 256 ) / 100) - 1;
#elif TIMER0_MODE   ==   PHASE_CORRECT_PWM_MODE
	OCR0_REG = ((Copy_F32_DutyCycle * 255 ) / 100);
#endif

		break;
	case TIMER1_CHANNEL:
		OCR1A_REG = ((Copy_F32_DutyCycle * ICR1_REG ) / 100) - 1;
		break;
	case TIMER2_CHANNEL:
		break;
	default: break;
	}
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMStart(u8 Copy_U8_TimerChannel)
{
	M_Timer_Void_TimerStart(Copy_U8_TimerChannel);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMStop(u8 Copy_U8_TimerChannel)
{
	M_Timer_Void_TimerStop(Copy_U8_TimerChannel);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_SetCallBack(void(*Copy_Ptr)(void))
{
	Timer_CallBack = Copy_Ptr;
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
#if   TIMER0_MODE   ==   NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
	static u32 Local_U32_Counter = 0;
	Local_U32_Counter++;
	if(Local_U32_Counter == Timer_U32_NumOfOV)
	{
		Timer_CallBack();
		Local_U32_Counter = 0;
		TCNT0_REG = 256 - Timer_U8_RemTicks;
	}
}
#elif   TIMER0_MODE   ==   CTC_MODE

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
ISR(TIMER0_COMP_vect)
{
	static u32 Local_U32_Counter = 0;
	Local_U32_Counter++;
	if(Local_U32_Counter == Timer_U32_NumOfCM)
	{
		Timer_CallBack();
		Local_U32_Counter = 0;
	}
}
#endif
