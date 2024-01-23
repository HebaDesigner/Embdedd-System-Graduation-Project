/*
 *      Timer_Program.c
 *      Created on: Jun 15, 2023
 *      Author: Heba Atef Ahmed
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "Timer_register.h"
#include "Timer_interface.h"

void (*TIMERS_pvCallBack_Func[8])(void) = {NULL};

void TIM0_voidInitialize(void){
	/*waveform mode*/
#if 	TIM0_WAVEFORM_MODE== NORMAL_MODE
	CLR_BIT(TCCR0_Register,WGM01);
	CLR_BIT(TCCR0_Register,WGM00);
#elif	TIM0_WAVEFORM_MODE== PWM_FASECORRECT_MODE
	CLR_BIT(TCCR0_Register,WGM01);
	SET_BIT(TCCR0_Register,WGM00);
#elif 	TIM0_WAVEFORM_MODE== CTC_MODE
	SET_BIT(TCCR0_Register,WGM01);
	CLR_BIT(TCCR0_Register,WGM00);
#elif	 TIM0_WAVEFORM_MODE== FASTPWM_MODE
	SET_BIT(TCCR0_Register,WGM01);
	SET_BIT(TCCR0_Register,WGM00);
#else
#endif
		//PRESCALER Selection
	/*Clock Select (Prescaler) to be used by the Timer/Counter*/
	TCCR0_Register = ((TCCR0_Register &= 0b11111000) | TIM0_CLOCK_SELECT);

		/*COMPARE MODE Selection on pin OC0*/
#if 	TIM0_COMPARE_MODE == OC0_DISCONNECTED			//In all modes
	CLR_BIT(TCCR0_Register,COM01);
	CLR_BIT(TCCR0_Register,COM00);
#elif 	TIM0_COMPARE_MODE == OC0_TOGGLE					//Only on non PWM mode
	CLR_BIT(TCCR0_Register,COM01);
	SET_BIT(TCCR0_Register,COM00);
#elif 	TIM0_COMPARE_MODE == OC0_CLEAR_NON_INVERTED		//CLEAR BIT IN NON PWM AND NON INVERTED IN PWM PHASECORRECT OR FAST PWM
	SET_BIT(TCCR0_Register,COM01);
	CLR_BIT(TCCR0_Register,COM00);
#elif 	TIM0_COMPARE_MODE == OC0_SET_INVERTED			//SET BIT IN NON PWM AND INVERTED IN PWM PHASECORRECT OR FAST PWM
	SET_BIT(TCCR0_Register,COM01);
	SET_BIT(TCCR0_Register,COM00);
#else
#endif
}

/*Timer0 Disable*/
void TIM0_voidDisable(void){
	TCCR0_Register=((TCCR0_Register&0b11111000)|(0));
}

/*Preoload Value Set*/
void TIM0_voidSetTimerReg(u8 Copy_u8Value){
	TCNT0_Register=Copy_u8Value;
}

/*Preoload Value Read*/
u16 Timer0_u16ReadTimerValue(void)
{
	return TCNT0_Register ;
}

/*Compare Match Value Set*/
void TIM0_voidSetCompareVal(u8 Copy_u8Value){
	OCR0_Register=Copy_u8Value;
}

/*Auto Generating OCR0 value by Duty cycle percentage */
void TIM0_VoidDutyCyclePercentage(u8 Copy_u8PersantageValue)
{
	if(((TIM0_WAVEFORM_MODE== FASTPWM_MODE) || (TIM0_WAVEFORM_MODE== PWM_FASECORRECT_MODE)) && (TIM0_COMPARE_MODE == OC0_CLEAR_NON_INVERTED))
	{
		OCR0_Register = 256 * (Copy_u8PersantageValue/100);
	}
	else if(((TIM0_WAVEFORM_MODE== FASTPWM_MODE) || (TIM0_WAVEFORM_MODE== PWM_FASECORRECT_MODE)) && (TIM0_COMPARE_MODE == OC0_SET_INVERTED))
	{
		OCR0_Register = 256 * (1-(Copy_u8PersantageValue/100));
	}
	else{ };
}


/*************************************************************TIMER1**************************************************************/

void TIM1_voidInitialize(void){
	/*Waveform Generation Mode*/
#if 	TIM1_WAVEFORM_MODE== TIM1_NORMAL_MODE
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(0));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(0));
#elif	TIM1_WAVEFORM_MODE== PWM_FASECORRECT_8BIT
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(0));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(1));
#elif	TIM1_WAVEFORM_MODE== PWM_FASECORRECT_9BIT
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(0));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(2));
#elif	TIM1_WAVEFORM_MODE== PWM_FASECORRECT_10BIT
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(0));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(3));
#elif	TIM1_WAVEFORM_MODE== CTC_OCR1A
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(8));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(0));
#elif	TIM1_WAVEFORM_MODE== PWM_FAST_8BIT
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(8));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(1));
#elif	TIM1_WAVEFORM_MODE== PWM_FAST_9BIT
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(8));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(2));
#elif	TIM1_WAVEFORM_MODE== PWM_FAST_10BIT
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(8));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(3));
#elif	TIM1_WAVEFORM_MODE== PWM_FASE_FREQUENCY_CORRECT_ICR1
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(16));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(0));
#elif	TIM1_WAVEFORM_MODE== PWM_FASE_FREQUENCY_CORRECT_OCR1A
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(16));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(1));
#elif	TIM1_WAVEFORM_MODE== PWM_FASE_CORRECT_ICR1
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(24));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(2));
#elif	TIM1_WAVEFORM_MODE== PWM_FASE_CORRECT_OCR1A
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(16));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(3));

#elif	TIM1_WAVEFORM_MODE== CTC_ICR1
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(24));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(0));
#elif	TIM1_WAVEFORM_MODE== PWM_FAST_ICR1
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(24));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(2));
#elif	TIM1_WAVEFORM_MODE== PWM_FAST_OCR1A
	TCCR1B_Register=((TCCR1B_Register&0b11100111)|(24));
	TCCR1A_Register=((TCCR1A_Register&0b11111100)|(3));
#else
#endif

	//Clock Select (Prescaler) to be used by the Timer1/Counter (TCCR1B)
	TCCR1B_Register = ((TCCR1B_Register &= 0b11111000) | TIM1_CLOCK_SELECT);

	/*: Compare Output Mode for Channel A on pin OC1A*/
#if 	TIM1A_COMPARE_MODE == OC1A_DISCONNECTED			//In all modes
	TCCR1A_Register=((TCCR1A_Register&0b00111111)|(0));
#elif 	TIM1A_COMPARE_MODE == OC1A_TOGGLE					//Only on non PWM mode TOGGLE ON COMPARE MATCH
	TCCR1A_Register=((TCCR1A_Register&0b00111111)|(64));
#elif 	TIM1A_COMPARE_MODE == OC1A_CLEAR_NON_INVERTED		//CLEAR BIT IN NON PWM AND NON INVERTED IN PWM PHASECORRECT OR FAST PWM
	TCCR1A_Register=((TCCR1A_Register&0b00111111)|(128));
#elif 	TIM1A_COMPARE_MODE == OC1A_SET_INVERTED			//SET BIT IN NON PWM AND INVERTED IN PWM PHASECORRECT OR FAST PWM
	TCCR1A_Register=((TCCR1A_Register&0b00111111)|(192));
#else
#endif
	/*: Compare Output Mode for Channel B on pin OC1B*/
#if 	TIM1B_COMPARE_MODE == OC1B_DISCONNECTED			//In all modes
	TCCR1B_Register=((TCCR1B_Register&0b00111111)|(0));
#elif 	TIM1B_COMPARE_MODE == OC1B_TOGGLE					//Only on non PWM mode TOGGLE ON COMPARE MATCH
	TCCR1B_Register=((TCCR1B_Register&0b00111111)|(64));
#elif 	TIM1B_COMPARE_MODE == OC1B_CLEAR_NON_INVERTED		//CLEAR BIT IN NON PWM AND NON INVERTED IN PWM PHASECORRECT OR FAST PWM
	TCCR1B_Register=((TCCR1B_Register&0b00111111)|(128));
#elif 	TIM1B_COMPARE_MODE == OC1B_SET_INVERTED			//SET BIT IN NON PWM AND INVERTED IN PWM PHASECORRECT OR FAST PWM
	TCCR1B_Register=((TCCR1B_Register&0b00111111)|(192));
#else
#endif
}

/*Timer1 Disable*/
void TIM1_voidDisable(void){
	TCCR1B_Register=((TCCR1B_Register&0b11111000)|(0));
}

/*Preoload Value Set*/
void TIM1_voidSetTimerReg(u16 Copy_u16Value){
	TCNT1_Register=Copy_u16Value;
}

/*Preoload Value Read*/
u16 Timer1_u16ReadTimerValue(void)
{
	return TCNT1_Register ;
}

/*Compare Match Value on Channel A Set*/
void TIM1_voidSetCompareValChannel_A(u16 Copy_u16Value){
	OCR1A_Register=Copy_u16Value;
}

/*Compare Match Value on Channel B Set*/
void TIM1_voidSetCompareValChannel_B(u16 Copy_u16Value){
	OCR1B_Register=Copy_u16Value;
}

/*Input Capture Register ICR1 Value Set*/
void TIM1_voidSetInputCapture(u16 Copy_u16Value){
	ICR1_Register=Copy_u16Value;
}


/***************************************************************ICU***************************************************************/
void ICU_voidInit(void)
{
	/*Set trigger source to Rising Edge Initially*/
	SET_BIT(TCCR1B_Register,ICES1);

	/*Enable Input Capture interrupt*/
	SET_BIT(TIMSK_Register,TICIE1);
}

u16 ICU_u16ReadInputCaptuer(void)
{
	return ICR1_Register;
}

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8Edge == ICU_RISING_EDGE )
	{
		SET_BIT(TCCR1B_Register,ICES1);
	}
	else if(Copy_u8Edge == ICU_FALLING_EDGE )
	{
		CLR_BIT(TCCR1B_Register,ICES1);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}


/*********************************************************************************************************************************/

void TIM2_voidInitialize(void){
	/*waveform mode*/
#if 	TIM2_WAVEFORM_MODE== NORMAL_MODE
	CLR_BIT(TCCR2_Register,WGM21);
	CLR_BIT(TCCR2_Register,WGM20);
#elif	TIM2_WAVEFORM_MODE== PWM_FASECORRECT_MODE
	CLR_BIT(TCCR2_Register,WGM21);
	SET_BIT(TCCR2_Register,WGM20);
#elif 	TIM2_WAVEFORM_MODE== CTC_MODE
	SET_BIT(TCCR2_Register,WGM21);
	CLR_BIT(TCCR2_Register,WGM20);
#elif	 TIM2_WAVEFORM_MODE== FASTPWM_MODE
	SET_BIT(TCCR2_Register,WGM21);
	SET_BIT(TCCR2_Register,WGM20);
#else
#endif
		//Clock Select (Prescaler) to be used by the Timer2/Counter (TCCR2)
	TCCR2_Register = ((TCCR2_Register &= 0b11111000) | TIM2_CLOCK_SELECT);

	/*COMPARE MODE Selection on pin OC2*/
#if 	TIM2_COMPARE_MODE == OC2_DISCONNECTED			//In all modes
	CLR_BIT(TCCR2_Register,COM21);
	CLR_BIT(TCCR2_Register,COM20);
#elif 	TIM2_COMPARE_MODE == OC2_TOGGLE					//Only on non PWM mode
	CLR_BIT(TCCR2_Register,COM21);
	SET_BIT(TCCR2_Register,COM20);
#elif 	TIM2_COMPARE_MODE == OC2_CLEAR_NON_INVERTED		//CLEAR BIT IN NON PWM AND NON INVERTED IN PWM PHASECORRECT OR FAST PWM
	SET_BIT(TCCR2_Register,COM21);
	CLR_BIT(TCCR2_Register,COM20);
#elif 	TIM2_COMPARE_MODE == OC2_SET_INVERTED			//SET BIT IN NON PWM AND INVERTED IN PWM PHASECORRECT OR FAST PWM
	SET_BIT(TCCR2_Register,COM21);
	SET_BIT(TCCR2_Register,COM20);
#else
#endif
}

/*Timer2 Disable*/
void TIM2_voidDisable(void){
	TCCR2_Register=((TCCR2_Register&0b11111000)|(0));
}

/*Preoload Value Set*/
void TIM2_voidSetTimerReg(u8 Copy_u8Value){
	TCNT2_Register=Copy_u8Value;
}


u16 Timer2_u16ReadTimerValue(void)
{
	return TCCR2_Register ;
}

/*Compare Match Value Set*/
void TIM2_voidSetCompareVal(u8 Copy_u8Value){
	OCR2_Register=Copy_u8Value;
}

/*Auto Generating OCR0 value by Duty cycle percentage */
void TIM2_VoidDutyCyclePercentage(u8 Copy_u8PersantageValue)
{
	if(((TIM2_WAVEFORM_MODE== FASTPWM_MODE) || (TIM2_WAVEFORM_MODE== PWM_FASECORRECT_MODE)) && (TIM2_COMPARE_MODE == OC2_CLEAR_NON_INVERTED))
	{
		OCR2_Register = 256 * (Copy_u8PersantageValue/100);
	}
	else if(((TIM2_WAVEFORM_MODE== FASTPWM_MODE) || (TIM2_WAVEFORM_MODE== PWM_FASECORRECT_MODE)) && (TIM2_COMPARE_MODE == OC2_SET_INVERTED))
	{
		OCR2_Register = 256 * (1-(Copy_u8PersantageValue/100));
	}
	else{ };
}


/*************************************************************ALL TIMERS***********************************************************/

void Timers_voidEn_Dis_Interrupt(u16 Copy_TIM_INT_Mask, u8 Copy_En_Dis)
{
	u8 	Local_u8ErrorState = OK;

	switch(Copy_TIM_INT_Mask)
	{
	//TIMER0 Overflow_Interrupt_Enable
	case TIM0_OVF_INT:
	{
		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,TOIE0);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,TOIE0);
		}
		break;
	}
	//TIMER0 Compare Match Interrupt Enable
	case TIM0_Comp_INT:
	{
		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,OCIE0);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,OCIE0);
		}
		break;
	}
	//Input_Capture_Interrupt_Enable
	case TIM1_ICU_INT:
	{
		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,TICIE1);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,TICIE1);
		}
		break;
	}
	//TIMER1 Compare A Match Interrupt Enable
	case TIM1_Comp_A_INT:
	{
		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,OCIE1A);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,OCIE1A);
		}
		break;
	}
	//TIMER1 Compare B Match Interrupt Enable
	case TIM1_Comp_B_INT:
	{

		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,OCIE1B);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,OCIE1B);
		}
		break;
	}
	//TIMER1 Overflow_Interrupt_Enable
	case TIM1_OVF_INT:
	{
		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,TOIE1);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,TOIE1);
		}
		break;
	}
	//TIMER2 Overflow_Interrupt_Enable
	case TIM2_OVF_INT:
	{
		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,TOIE2);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,TOIE2);
		}
		break;
	}
	//TIMER2 Compare Match Interrupt Enable
	case TIM2_Comp_INT:
	{
		if(Copy_En_Dis == Enable)
		{
			SET_BIT(TIMSK_Register,OCIE2);
		}
		else if(Copy_En_Dis == Disable)
		{
			CLR_BIT(TIMSK_Register,OCIE2);
		}
		break;
	}
	default:
	{
		Local_u8ErrorState = NOK;
		break;
	}

	}
}

u8 TIMERS_u8SetCallBack(void (*Copy_pvCallBackFunc[8])(void), u16 INT_Name)
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_pvCallBackFunc[INT_Name] != NULL)
	{
		TIMERS_pvCallBack_Func[INT_Name] = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}


//TIMER2 COMP
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM2_Comp_INT]();
}

//TIMER2 Over flow
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM2_OVF_INT]();
}

//TIMER1 ICU_Capt
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM1_ICU_INT]();
}


//TIMER1 COMPA
void __vector_7 (void)__attribute__((signal));
void __vector_7 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM1_Comp_A_INT]();
}

//TIMER1 COMPB
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM1_Comp_B_INT]();
}

//TIMER1 Over flow
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM1_OVF_INT]();
}

//TIMER0 COMP
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM0_Comp_INT]();
}

//TIMER0 Overflow
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(TIMERS_pvCallBack_Func!= NULL)
		TIMERS_pvCallBack_Func[TIM0_OVF_INT]();
}

