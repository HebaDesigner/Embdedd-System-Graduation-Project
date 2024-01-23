/*
 *  main.c
 *  Created on: Oct 19, 2023
 *  Author: Heba Atef Ahmed
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "ADC_NInterface.h"
#include "SEGMENT7_interface.h"
#include "util/delay.h"
#include "UART_Interface.h"
#include "M_C_H_Interface.h"
#include "Timer_interface.h"

void main(void)
{
	USART_Init();
	Segment7_VoidInit();

	//ADC signal Input channel 0
	DIO_u8_SetPin_Dir(Group_A,DIO_u8_Pin_0,DIO_u8_Input);
	DIO_u8_SetPin_value(Group_A,DIO_u8_Pin_0,DIO_u8_Low);

	//ADC signal Input channel 1
	DIO_u8_SetPin_Dir(Group_A,DIO_u8_Pin_1,DIO_u8_Input);
	DIO_u8_SetPin_value(Group_A,DIO_u8_Pin_1,DIO_u8_Low);

	//ADC signal Output Light Leds
	DIO_u8_SetPort_Dir(Group_C,DIO_u8_PORT_Output);

	//Connect Ground to Leds
	DIO_u8_SetPin_Dir(Group_D,DIO_u8_Pin_7,DIO_u8_Output);

	//7Segment
	DIO_u8_SetPort_Dir(Group_B, DIO_u8_PORT_Output);

	//7Segment Com
	DIO_u8_SetPin_Dir(Group_A, DIO_u8_Pin_6, DIO_u8_Output);

	// Leds
	DIO_u8_SetPort_Dir(Group_C, DIO_u8_PORT_Output);

	//Door, fan , light, Alarm
	DIO_u8_SetPort_Dir(Group_D, DIO_u8_PORT_Output);

	ID_PASS();
	while(1)
	{

	}
}

