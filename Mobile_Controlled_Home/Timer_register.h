/*
 *      Timer_Register.h
 *      Created on: Jun 15, 2023
 *      Author: Heba Atef Ahmed
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0_Register  *((volatile u8*)0x53)	/*Timer/counter control register (Timer0)*/
#define WGM01		3							/*Waveform Generation Mode (Timer0)*/
#define WGM00		6							/*Waveform Generation Mode (Timer0)*/

#define COM01		5							/*Compare output mode (Timer0)*/
#define COM00		4							/*Compare output mode (Timer0)*/

#define CS02		2							/*Prescaler Clock select (Timer0)*/
#define CS01		1							/*Prescaler Clock select (Timer0)*/
#define CS00		0							/*Prescaler Clock select (Timer0)*/

#define TCNT0_Register 	*((volatile u8*)0x52)	/*Preload Value (Timer0)*/
#define OCR0_Register  	*((volatile u8*)0x5C)	/*Compare Match Value (Timer0)*/

#define TIMSK_Register  *((volatile u8*)0x59)	/*Interrupt Enable/Desable*/

#define TICIE1		5							/*Input Capture Interrupt Enable		  (Timer1)*/
#define OCIE1A		4							/*Output Compare A Match Interrupt Enable (Timer1)*/
#define OCIE1B		3							/*Output Compare B Match Interrupt Enable (Timer1)*/
#define TOIE1		2							/*Overflow Interrupt Enable				  (Timer1)*/

#define OCIE0		1							/*Output Compare Match Interrupt Enable	  (Timer0)*/
#define TOIE0		0							/*Overflow Interrupt Enable				  (Timer0)*/

#define OCIE2		7							/*Output Compare Match Interrupt Enable	  (Timer2)*/
#define TOIE2		6							/*Overflow Interrupt Enable				  (Timer2)*/


#define TIFR_Register  	*((volatile u8*)0x58)	/*Interrupt Flag*/

#define TCCR1A_Register *((volatile u8*)0x4F)	/*Timer/Counter1 Control Register A*/

#define COM1A1		7							/*Compare Output Mode for Channel A (Timer1)*/
#define COM1A0		6							/*Compare Output Mode for Channel A (Timer1)*/

#define COM1B1		5							/*Compare Output Mode for Channel B (Timer1)*/
#define COM1B0		4							/*Compare Output Mode for Channel B (Timer1)*/

#define WGM11		1							/*Waveform Generation Mode (Timer1)*/
#define WGM10		0							/*Waveform Generation Mode (Timer1)*/

#define TCCR1B_Register *((volatile u8*)0x4E)	/*Timer/Counter1 Control Register B*/

#define ICNC1		7							/*Input Capture Noise Canceler (Timer1)*/
#define ICES1		6							/*Input Capture Edge Select (Timer1)*/

#define WGM13		4							/*Waveform Generation Mode (Timer1)*/
#define WGM12		3							/*Waveform Generation Mode (Timer1)*/

#define CS12		2							/*Prescaler Clock select (Timer1)*/
#define CS11		1							/*Prescaler Clock select (Timer1)*/
#define CS10		0							/*Prescaler Clock select (Timer1)*/

#define TCNT1_Register *((volatile u16*)0x4C)	/*Preload Value (Timer1)*/

#define OCR1A_Register *((volatile u16*)0x4A)	/*Compare Match Value Channel A (Timer1)*/
#define OCR1B_Register *((volatile u16*)0x48)	/*Compare Match Value Channel B (Timer1)*/

#define ICR1_Register  *((volatile u16*)0x46)	/*Input Capture Register (Timer1)*/

#define TCCR2_Register  *((volatile u8*)0x45)	/*Timer/counter control register (Timer2)*/
#define WGM20		6							/*Waveform Generation Mode (Timer2)*/
#define WGM21		3							/*Waveform Generation Mode (Timer2)*/

#define COM20		4							/*Compare output mode (Timer2)*/
#define COM21		5							/*Compare output mode (Timer2)*/

#define CS22		2							/*Prescaler Clock select (Timer2)*/
#define CS21		1							/*Prescaler Clock select (Timer2)*/
#define CS20		0							/*Prescaler Clock select (Timer2)*/

#define TCNT2_Register 	*((volatile u8*)0x44)	/*Preload Value (Timer2)*/
#define OCR2_Register  	*((volatile u8*)0x43)	/*Compare Match Value (Timer2)*/


#endif /* TIMER_REGISTER_H_ */


