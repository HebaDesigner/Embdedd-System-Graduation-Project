/*
 *      Timer_interface.h
 *      Created on: Jun 15, 2023
 *      Author: Heba Atef Ahmed
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define		ICU_FALLING_EDGE 						0
#define		ICU_RISING_EDGE			                1

#define     Enable                                  1
#define     Disable                                 0

/*************************************************************TIMER0**************************************************************/

#define 	NORMAL_MODE								0
#define 	PWM_FASECORRECT_MODE					1	//WAVEFORM_MODE_TIM0
#define 	CTC_MODE								2
#define 	FASTPWM_MODE							3

#define 	TIMER0_STOPPED							0
#define 	TIM0_NO_PRESCALER						1
#define 	TIM0_DIVIDED_BY_8						2
#define 	TIM0_DIVIDED_BY_64						3	//CLOCK_SELECT_TIM0
#define 	TIM0_DIVIDED_BY_256						4
#define 	TIM0_DIVIDED_BY_1024					5
#define 	T0_FALLING_EDGE							6
#define 	T0_RISING_EDGE							7

#define 	OC0_DISCONNECTED						0
#define 	OC0_TOGGLE								1	//COMPARE_MODE_TIM0
#define 	OC0_CLEAR_NON_INVERTED					2
#define 	OC0_SET_INVERTED						3

#define 	TIM0_WAVEFORM_MODE	FASTPWM_MODE			//you can select the mode //
/*options:
		NORMAL_MODE
		PWM_FASECORRECT_MODE
		CTC_MODE
		FASTPWM_MODE
*/

#define 	TIM0_CLOCK_SELECT	TIM0_DIVIDED_BY_8		//you can select the mode //
/*options:
		TIMER_STOPPED
		NO_PRESCALER
		DIVIDED_BY_8
		DIVIDED_BY_64
		DIVIDED_BY_256
		DIVIDED_BY_1024
		T0_FALLING_EDGE
		T0_RISING_EDGE
*/

#define 	TIM0_COMPARE_MODE	OC0_CLEAR_NON_INVERTED			//you can select the mode //
/*options:
			OC0_DISCONNECTED
			OC0_TOGGLE
			OC0_CLEAR_NON_INVERTED
			OC0_SET_INVERTED
*/

#define  TIM0_INT_Mask                           TIM0_Comp_INT
/*Options: TIMSK
 *               TIM0_Compare_Match_INT
 *               TIM0_Overflow_INT
 */
#define TIM0_OVF_INT                                 0         //0b00000001     //Timer/Counter0 Overflow Interrupt Enable
#define TIM0_Comp_INT                                1        //0b00000010     //Timer/Counter0 Output Compare Match Interrupt Enable


/*************************************************************TIMER1**************************************************************/

#define 	TIM1_NORMAL_MODE						0
#define 	PWM_FASECORRECT_8BIT					1	//WAVEFORM_MODE_TIM1
#define 	PWM_FASECORRECT_9BIT					2
#define 	PWM_FASECORRECT_10BIT					3
#define 	CTC_OCR1A								4
#define 	PWM_FAST_8BIT							5
#define 	PWM_FAST_9BIT							6
#define 	PWM_FAST_10BIT							7
#define 	PWM_FASE_FREQUENCY_CORRECT_ICR1			8
#define 	PWM_FASE_FREQUENCY_CORRECT_OCR1A		9
#define 	PWM_FASE_CORRECT_ICR1					10
#define 	PWM_FASE_CORRECT_OCR1A					11
#define 	CTC_ICR1								12
#define 	PWM_FAST_ICR1							13
#define 	PWM_FAST_OCR1A							14

#define 	TIM1_STOPPED							0
#define 	TIM1_NO_PRESCALER						1
#define 	TIM1_DIVIDED_BY_8						2
#define 	TIM1_DIVIDED_BY_64						3	//CLOCK_SELECT_TIM1
#define 	TIM1_DIVIDED_BY_256						4
#define 	TIM1_DIVIDED_BY_1024					5

#define 	T1_FALLING_EDGE							6
#define 	T1_RISING_EDGE							7

#define 	OC1A_DISCONNECTED						0
#define 	OC1A_TOGGLE								1	//COMPARE_MODE_CHANNEL_A_TIM1
#define 	OC1A_CLEAR_NON_INVERTED					2
#define 	OC1A_SET_INVERTED						3

#define 	OC1B_DISCONNECTED						0
#define 	OC1B_TOGGLE								1	//COMPARE_MODE_CHANNEL_B_TIM1
#define 	OC1B_CLEAR_NON_INVERTED					2
#define 	OC1B_SET_INVERTED						3

#define 	TIM1_WAVEFORM_MODE	PWM_FAST_ICR1				//you can select the mode //
/*options:
		TIM1_NORMAL_MODE
		PWM_FASECORRECT_8BIT
		PWM_FASECORRECT_9BIT
		PWM_FASECORRECT_10BIT
		CTC_OCR1A
		PWM_FAST_8BIT
		PWM_FAST_9BIT
		PWM_FAST_10BIT
		PWM_FASE_FREQUENCY_CORRECT_ICR1
		PWM_FASE_FREQUENCY_CORRECT_OCR1A
		PWM_FASE_CORRECT_ICR1
		PWM_FASE_CORRECT_OCR1A
		CTC_ICR1
		PWM_FAST_ICR1
		PWM_FAST_OCR1A
*/

#define 	TIM1_CLOCK_SELECT	TIM1_DIVIDED_BY_8			//you can select the mode //
/*options:
		TIM1_STOPPED
		TIM1_NO_PRESCALER
		TIM1_DIVIDED_BY_8
		TIM1_DIVIDED_BY_64
		TIM1_DIVIDED_BY_256
		TIM1_DIVIDED_BY_1024
		T1_FALLING_EDGE
		T1_RISING_EDGE
*/

#define 	TIM1A_COMPARE_MODE	OC1A_CLEAR_NON_INVERTED		//you can select the mode //
/*options:
		OC1A_DISCONNECTED
		OC1A_TOGGLE
		OC1A_CLEAR_NON_INVERTED
		OC1A_SET_INVERTED
*/

#define 	TIM1B_COMPARE_MODE	OC1B_CLEAR_NON_INVERTED		//you can select the mode //
/*options:
		OC1B_DISCONNECTED
		OC1B_TOGGLE
		OC1B_CLEAR_NON_INVERTED
		OC1B_SET_INVERTED
*/

#define  TIM1_INT_Mask                           TIM1_Comp_A_INT
/*Options: TIMSK
 *               Input_Capture_Interrupt_Enable
 *               Output Compare A Match Interrupt Enable
 *               Output Compare B Match Interrupt Enable
 *               Overflow Interrupt Enable
 */
#define TIM1_ICU_INT                             2         //0b00100000     //Input_Capture_Interrupt_Enable
#define TIM1_Comp_A_INT                          3       //0b00010000     //Output Compare A Match Interrupt Enable
#define TIM1_Comp_B_INT                          4      //0b00001000     //Output Compare B Match Interrupt Enable
#define TIM1_OVF_INT                             5     //0b00000100     //Overflow_Interrupt_Enable

/*************************************************************TIMER2**************************************************************/

#define 	NORMAL_MODE								0
#define 	PWM_FASECORRECT_MODE					1	//WAVEFORM_MODE_TIM2
#define 	CTC_MODE								2
#define 	FASTPWM_MODE							3

#define 	TIMER2_STOPPED							0
#define 	TIM2_NO_PRESCALER						1
#define 	TIM2_DIVIDED_BY_8						2
#define 	TIM2_DIVIDED_BY_32						3	//CLOCK_SELECT_TIM2
#define 	TIM2_DIVIDED_BY_64						4
#define 	TIM2_DIVIDED_BY_128						5
#define 	TIM2_DIVIDED_BY_256						6
#define 	TIM2_DIVIDED_BY_1024	     			7

#define 	OC2_DISCONNECTED						0
#define 	OC2_TOGGLE								1	//COMPARE_MODE_TIM0
#define 	OC2_CLEAR_NON_INVERTED					2
#define 	OC2_SET_INVERTED						3

#define 	TIM2_WAVEFORM_MODE	FASTPWM_MODE			//you can select the mode //
/*options:
		NORMAL_MODE
		PWM_FASECORRECT_MODE
		CTC_MODE
		FASTPWM_MODE
*/

#define 	TIM2_CLOCK_SELECT	TIM2_DIVIDED_BY_8		//you can select the mode //
/*options:
		TIMER_STOPPED
		NO_PRESCALER
		DIVIDED_BY_8
		DIVIDED_BY_32
		DIVIDED_BY_64
		DIVIDED_BY_128
		DIVIDED_BY_256
		DIVIDED_BY_1024
*/

#define 	TIM2_COMPARE_MODE	OC2_CLEAR_NON_INVERTED			//you can select the mode //
/*options:
			OC2_DISCONNECTED
			OC2_TOGGLE
			OC2_CLEAR_NON_INVERTED
			OC2_SET_INVERTED
*/

#define  TIM2_INT_Mask                           TIM2_Comp_INT
/*Options: TIMSK
 *               TIM0_Compare_Match_INT
 *               TIM0_Overflow_INT
 */
#define TIM2_OVF_INT                                 6         //0b00000001     //Timer/Counter0 Overflow Interrupt Enable
#define TIM2_Comp_INT                                7        //0b00000010     //Timer/Counter0 Output Compare Match Interrupt Enable


/*********************************************************************************************************************************/

void TIM0_voidDisable(void);

void TIM0_voidInitialize(void);

void TIM0_voidSetTimerReg(u8 Copy_u8Value);
void TIM0_voidSetCompareVal(u8 Copy_u8Value);

void TIM0_voidEnableOVINT(void);
void TIM0_voidDisableOVINT(void);

void TIM0_voidEnableCTCINT(void);
void TIM0_voidDisableCTCINT(void);

void TIM0_VoidDutyCyclePercentage(u8 Copy_u8PersantageValue);

u8 TIM0_u8GETCounter(void);

void TIM0_voidSetOVCallback( void (*callback_Copy_ptr) (void) );
void TIM0_voidSetCTCCallback( void (*callback_Copy_ptr) (void) );

/*********************************************************************************************************************************/

void TIM1_voidDisable(void);
void TIM1_voidInitialize(void);

void TIM1_voidSetTimerReg(u16 Copy_u16Value);
void TIM1_voidSetCompareValChannel_A(u16 Copy_u16Value);
void TIM1_voidSetCompareValChannel_B(u16 Copy_u16Value);
void TIM1_voidSetInputCapture(u16 Copy_u16Value);

void TIM1_voidEnableCTCAINT(void);
void TIM1_voidDisableCTCAINT(void);

void TIM1_voidEnableCTCBINT(void);
void TIM1_voidDisableCTCBINT(void);

void TIM1_voidEnableICUINT(void);
void TIM1_voidDisableICUINT(void);

void TIM1_voidEnableOVINT(void);
void TIM1_voidDisableOVINT(void);

void TIM1_voidSetTimerReg(u16 Copy_u16Value);

void TIM1_A_voidSetCompareVal(u16 Copy_u16Value);
void TIM1_B_voidSetCompareVal(u16 Copy_u16Value);

void TIM1_voidEnableOVINT(void);
void TIM1_voidDisableOVINT(void);

void TIM1_voidEnableCTCINT(void);
void TIM1_voidDisableCTCINT(void);

u16 TIM1_u16GETCounter(void);
u16 TIM1_u16GETICUValue(void);

void TIM1_voidSetICUEdge(u16 Copy_u8edge);

void TIM1_voidSetOVCallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidSetCTCACallback( void (*callback_Copy_ptr) (void) );
void TIM1_voidSetCTCBCallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidSetICUCallback( void (*callback_Copy_ptr) (void) );

/*********************************************************************************************************************************/
void TIM2_voidDisable(void);

void TIM2_voidInitialize(void);

void TIM2_voidSetTimerReg(u8 Copy_u8Value);
void TIM2_voidSetCompareVal(u8 Copy_u8Value);

void TIM2_voidEnableOVINT(void);
void TIM2_voidDisableOVINT(void);

void TIM2_voidEnableCTCINT(void);
void TIM2_voidDisableCTCINT(void);

void TIM2_VoidDutyCyclePercentage(u8 Copy_u8PersantageValue);

u8 TIM2_u8GETCounter(void);

void TIM2_voidSetOVCallback( void (*callback_Copy_ptr) (void) );
void TIM2_voidSetCTCCallback( void (*callback_Copy_ptr) (void) );


#endif /* TIMER_INTERFACE_H_ */
