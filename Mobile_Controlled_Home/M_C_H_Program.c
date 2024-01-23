/*
 *  M_C_H_Program.c
 *  Created on: Oct 19, 2023
 *  Author: Heba Atef Ahmed
 */
#include "BIT_CALC.h"
#include "DIO_Interface.h"
#include "ADC_NInterface.h"
#include "SEGMENT7_interface.h"
#include "util/delay.h"
#include "UART_Interface.h"
#include "M_C_H_Interface.h"
#include "Timer_interface.h"


void ID_PASS(void)
{

	DIO_u8_SetPin_value(Group_A,DIO_u8_Pin_6,DIO_u8_Low);

	//Array to Store ID to compare password
	char Arr_u8ID[4];

	//Array to Store Pass to compare with ID if It write or wrong
	char Arr_u8Pass[4], IteratorPass=0;

	//Variable make 3 tries only to Enter password
	u8 Wrong_u8Pass = 3;

	//7Segment Array to display Numbers*
	u8 NUMBERS [10] = {zero, one, two, three, four, five, six, seven, eight, nine};

	//First display on screen welocm for 0.5 seconds
	USART_vSendString("\rWelcome");

	//Ask user to Enter ID
	USART_vSendString("\rEnter ID:");

	while(1)
	{

		USART_vReceiveString(Arr_u8ID);

		USART_vSendString("\rPASS:");
		DIO_u8_SetPin_value(Group_A,DIO_u8_Pin_6,DIO_u8_High);

		Segment7_VidSetDisplay(NUMBERS[Wrong_u8Pass]);

		//new Busy waiting to wait user to enter Right Password
		while(1)
		{
			USART_vReceiveString(Arr_u8Pass);

			if(Arr_u8Pass[3]==Arr_u8ID[0] && Arr_u8Pass[2]==Arr_u8ID[1] && Arr_u8Pass[1]==Arr_u8ID[2] && Arr_u8Pass[0]==Arr_u8ID[3])
			{
				Segment7_VidDisableDisplayOne();

				USART_vSendString("\r\rWELCOME To Your Smart Home...");
				TIM1_voidDisable();

				MainMenu();
			}else
			{
				Wrong_u8Pass--;
				if(Wrong_u8Pass == 0)
				{

					Segment7_VidSetDisplay(NUMBERS[Wrong_u8Pass]);
					USART_vSendString("\rBye bebooo");
					DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_2,DIO_u8_High);
					_delay_ms(500);
					DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_2,DIO_u8_Low);
					_delay_ms(500);
					DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_2,DIO_u8_High);
					_delay_ms(500);
					DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_2,DIO_u8_Low);

					break;
				}

				Segment7_VidSetDisplay(NUMBERS[Wrong_u8Pass]);
				IteratorPass=0;
				USART_vSendString("\rTry Again");

				USART_vSendString("\rPASS:");
			}
		}
		break;
	}
	Segment7_VidDisableDisplayOne();

}

void MainMenu(void)
{
	//Menu to choose your option
	char Menu_u8Option;

	u16 App_u16ADCReading;

	//LM35_ADCReading
	u16 Local_u16Counter;


	//Initialize ADC & Timer
	ADC_voidInit();
	TIM2_voidInitialize();
	TIM0_voidInitialize();
	TIM1_voidInitialize();

	USART_vSendString("\r");
	USART_vSendString("\rChoose Option From The Menu");
	USART_vSendString("\r");
	USART_vSendString("\r1- Open The Door");
	USART_vSendString("\r2- Close The Door");

	USART_vSendString("\r3- Open Lighting");
	USART_vSendString("\r4- Close Lighting");

	USART_vSendString("\r5- Open Fan");
	USART_vSendString("\r6- Close Fan");

	USART_vSendString("\r7- Adjust Fan Speed");
	USART_vSendString("\r8- Adjust Brightness");

	USART_vSendString("\r9- Exit");
	USART_vSendString("\r");

	USART_vSendString("\rYour Option:");
	do
	{
		Menu_u8Option = USART_voidReceive_char();

		if(Menu_u8Option == '1')
		{
			/*Input Capture Register ICR1 Value Set in mode 14*/
			TIM1_voidSetInputCapture(20000);

			TIM1_voidSetCompareValChannel_A(2500);

			USART_vSendString("\r");
			USART_vSendString("\Door is Opened");
			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");

			USART_vSendString("\r\rYour Option:");

			while(1)
			{
				Menu_u8Option = USART_voidReceive_char();

				if(Menu_u8Option == 'a')
				{
					MainMenu();
				}
				else if(Menu_u8Option == 'b')
				{
					Exit();
				}
			}
		}
		else if(Menu_u8Option == '2')
		{

			TIM1_voidSetCompareValChannel_A(750);


			USART_vSendString("\r");
			USART_vSendString("\Door is Closed");
			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");


			USART_vSendString("\r\rYour Option:");

			Menu_u8Option = USART_voidReceive_char();

			if(Menu_u8Option == 'a')
			{
				MainMenu();
			}
			else if(Menu_u8Option == 'b')
			{
				Exit();
			}
		}
		else if(Menu_u8Option == '3')
		{
			DIO_u8_SetPort_value(Group_C,DIO_u8_Port_High);

			USART_vSendString("\r");
			USART_vSendString("\rLight is Opened");
			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");

			USART_vSendString("\r\rYour Option:");

			while(1)
			{
				Menu_u8Option = USART_voidReceive_char();

				if(Menu_u8Option == 'a')
				{
					MainMenu();
				}
				else if(Menu_u8Option == 'b')
				{
					Exit();
				}
			}
		}
		else if(Menu_u8Option == '4')
		{
			TIM2_voidDisable();

			DIO_u8_SetPort_value(Group_C,DIO_u8_Port_Low);

			USART_vSendString("\r");
			USART_vSendString("\rLight is Closed");
			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");

			USART_vSendString("\r\rYour Option:");

			while(1)
			{
				Menu_u8Option = USART_voidReceive_char();

				if(Menu_u8Option == 'a')
				{
					MainMenu();
				}
				else if(Menu_u8Option == 'b')
				{
					Exit();
				}
			}
		}
		else if(Menu_u8Option == '5')
		{
			TIM0_voidDisable();

			DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_3,DIO_u8_High);

			USART_vSendString("\r");
			USART_vSendString("\rFAN is Opened");
			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");

			USART_vSendString("\r\rYour Option:");

			while(1)
			{
				Menu_u8Option = USART_voidReceive_char();

				if(Menu_u8Option == 'a')
				{
					MainMenu();
				}
				else if(Menu_u8Option == 'b')
				{
					Exit();
				}
			}
		}
		else if(Menu_u8Option == '6')
		{
			TIM0_voidDisable();

			DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_3,DIO_u8_Low);

			USART_vSendString("\r");
			USART_vSendString("\rFAN is Closed");
			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");

			USART_vSendString("\r\rYour Option:");

			while(1)
			{
				Menu_u8Option = USART_voidReceive_char();

				if(Menu_u8Option == 'a')
				{
					MainMenu();
				}
				else if(Menu_u8Option == 'b')
				{
					Exit();
				}
			}
		}
		else if(Menu_u8Option == '7')
		{
			u16 MilliVolt;
			u16 Temp;

			USART_vSendString("\rWrite s To Know The Temp:  ");

			while(1)
			{
				ADC_u16StartConversionSynch(Channel_A0, &Local_u16Counter);
				MilliVolt = (u16) ((Local_u16Counter*5000UL)/1024UL);
				Temp = MilliVolt/10;

				if(Temp > 30)
				{
					DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_3,DIO_u8_High);
				}
				else if(Temp < 30)
				{
					DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_3,DIO_u8_Low);
				}
				Menu_u8Option = USART_voidReceive_finish();
				if(Menu_u8Option == 's')
				{
					break;
				}
			}
			if(Temp>30)
			{
				USART_vSendString("\r");
				USART_vSendString("\rWeather is Hot FAN Opened ");

				USART_vSendString("\rTemp:");
				USART_voidSendNumber(Temp);
				USART_vSendString("c");

			}
			else if(Temp<30)
			{
				USART_vSendString("\r");
				USART_vSendString("\rWeather is Fine FAN Closed ");
				USART_vSendString("\rTemp:");
				USART_voidSendNumber(Temp);
				USART_vSendString("c");
			}

			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");

			USART_vSendString("\r\rYour Option:");

			while(1)
			{
				Menu_u8Option = USART_voidReceive_char();

				if(Menu_u8Option == 'a')
				{
					MainMenu();
				}
				else if(Menu_u8Option == 'b')
				{
					Exit();
				}
			}
		}
		else if(Menu_u8Option == '8')
		{
			USART_vSendString("\rWrite s To Choose Other Option:  ");

			u16 Reading;

			while(1)
			{
				ADC_u16StartConversionSynch(Channel_A1,&App_u16ADCReading);

				Reading = mapping(0, 670, 1, 10, App_u16ADCReading);

				TIM2_voidSetCompareVal(255 - (Reading * 25));

				switch(Reading)
				{
				case 1:
					DIO_u8_SetPort_value(Group_C, 0b11111111);
					break;
				case 2:
					DIO_u8_SetPort_value(Group_C, 0b01111111);
					break;
				case 3:
					DIO_u8_SetPort_value(Group_C, 0b00111111);
					break;
				case 4:
					DIO_u8_SetPort_value(Group_C, 0b00011111);
					break;
				case 5:
					DIO_u8_SetPort_value(Group_C, 0b00001111);
					break;
				case 6:
					DIO_u8_SetPort_value(Group_C, 0b00000111);
					break;
				case 7:
					DIO_u8_SetPort_value(Group_C, 0b00000011);
					break;
				case 8:
					DIO_u8_SetPort_value(Group_C, 0b00000001);
					break;
				default:
					DIO_u8_SetPort_value(Group_C, 0b00000000);
					break;
				}

				Menu_u8Option = USART_voidReceive_finish();

				if(Menu_u8Option == 's')
				{
					break;
				}
			}
			USART_vSendString("\r");

			USART_vSendString("\ra- Main Menu");

			USART_vSendString("\rb- Exit");

			USART_vSendString("\r\rYour Option:");

			while(1)
			{
				Menu_u8Option = USART_voidReceive_char();

				if(Menu_u8Option == 'a')
				{
					MainMenu();
				}
				else if(Menu_u8Option == 'b')
				{
					Exit();
				}
			}
		}
		else if(Menu_u8Option == '9')
		{
			Exit();
		}
	}while(Menu_u8Option != '#');
}

void Exit(void)
{
	DIO_u8_SetPort_value(Group_A,DIO_u8_Low);

	DIO_u8_SetPort_value(Group_B,DIO_u8_Low);

	DIO_u8_SetPort_value(Group_C,DIO_u8_Low);

	DIO_u8_SetPort_value(Group_D,DIO_u8_Low);

	USART_vSendString("\r\rbye bye bebooooooo");
}

