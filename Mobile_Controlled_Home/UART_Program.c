/*
 * UART_Program.c
 * UART driver for the microcontroller ATMega 32
 * Created on: Jun 16, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"UART_Private.h"
#include"UART_Interface.h"
#include"avr/delay.h"


void USART_Init(void)
{
	//#define	UCSRC_URSEL                   0b10000000          	// Register UCSRC Select

	u8 Local_u8UCSRCValue = 0;
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);


	//UBRRL = 51;                               //baud Rate 9600
	UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/

	//Double the USART Transmission Speed
#if Double_USART_TX_Speed == Speed
	//TX Speed
	CLR_BIT(UCSRA,UCSRA_U2X);

#elif Double_USART_TX_Speed == Double_Speed
	//TX Double Speed, will reduce the divisor of the baud rate divider from 16 to 8 effectively doubling the transfer rate for async
	SET_BIT(UCSRA,UCSRA_U2X);


#else
#error "Wrong Option"
#endif

	//A USART Receive Complete Interrupt
#if USART_Receive_Complete_INT == Disabled
	//RX Complete Interrupt Enable
	CLR_BIT(UCSRB,UCSRB_RXCIE);

#elif USART_Receive_Complete_INT == Enabled
	//RX Complete Interrupt Disable
	SET_BIT(UCSRB,UCSRB_RXCIE);

#else
#error "Wrong Option"
#endif

	//A USART Transmit Complete Interrupt
#if USART_Transmit_Complete_INT == Disabled
	//TX Complete Interrupt Enable
	CLR_BIT(UCSRB,UCSRB_TXCIE);

#elif USART_Transmit_Complete_INT == Enabled
	//TX Complete Interrupt Disable
	SET_BIT(UCSRB,UCSRB_TXCIE);

#else
#error "Wrong Option"
#endif

	//Data Register Empty Interrupt
#if USART_Data_Register_Empty_INT == Enabled
	//USART Data Register Empty Interrupt Enable
	SET_BIT(UCSRB,UCSRB_UDRIE);

#elif USART_Data_Register_Empty_INT == Disabled
	//USART Data Register Empty Interrupt Disable
	CLR_BIT(UCSRB,UCSRB_UDRIE);

#else
#error "Wrong Option"
#endif

	//USART Receiver
#if Receiver_Enable == Enabled
	//Receiver Enable
	SET_BIT(UCSRB,UCSRB_RXEN);

#elif Receiver_Enable == Disabled
	//Receiver Disable
	CLR_BIT(UCSRB,UCSRB_RXEN);

#else
#error "Wrong Option"
#endif

	//USART Transmitter
#if Transmitter_Enable == Enabled
	//Transmitter Enable
	SET_BIT(UCSRB,UCSRB_TXEN);

#elif Transmitter_Enable == Disabled
	//Transmitter Disable
	CLR_BIT(UCSRB,UCSRB_TXEN);

#else
#error "Wrong Option"
#endif

#if Receive_Data_Bit8 == Disabled
	//Receive_Data_Bit8 Disable
	CLR_BIT(UCSRB,UCSRB_RXB8);
	//RXB8 is the ninth data bit of the received character
#elif Receive_Data_Bit8 == Enabled
	//Receive_Data_Bit8
	SET_BIT(UCSRB,UCSRB_RXB8);



#else
#error "Wrong Option"
#endif

	//TXB8 is the ninth data bit of the received character
#if Transmit_Data_Bit8 == Disabled
	//Transmit_Data_Bit8
	CLR_BIT(UCSRB,UCSRB_TXB8);

#elif Transmit_Data_Bit8 == Enabled
	//Transmit_Data_Bit8 Disable
	SET_BIT(UCSRB,UCSRB_TXB8);

#else
#error "Wrong Option"
#endif

	//USART Mode Select
#if Mode_Select == Asynchronous
	CLR_BIT(UCSRC,UCSRC_UMSEL);

#elif Mode_Select == Synchronous
	SET_BIT(UCSRC,UCSRC_UMSEL);

#else
#error "Wrong USART Mode Select option"
#endif

	//USART Stop Bit Select
#if Stop_Bit_Select == bit_1
	CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);

#elif Stop_Bit_Select == bits_2
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);

#else
#error "Wrong USART Stop_Bit_Select option"
#endif

	//USART Parity Mode
#if Mode_Parity == Dis_Parity                              //Disabled
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
#elif Mode_Parity == En_Even_Parity                             //Enabled, Even Parity
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
#elif Mode_Parity == En_Odd_Parity                             //Enabled, Odd Parity
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
#else
#error "Wrong USART Mode Parity option"
#endif

	//Character_Size
#if Character_Size == bit_5                                      //bit_5
	CLR_BIT(UCSRC,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif Character_Size == bit_6                                    //bit_6
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif Character_Size == bit_7                                    //bit_7
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif Character_Size == bit_8                                    //bit_8
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif Character_Size == bit_9                                    //bit_9
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	SET_BIT(UCSRB,UCSRB_UCSZ2);
#else
#error "Wrong USART Character_Size option"
#endif

	//Clock_Polarity in Synchronous mode case Transmitted Data Changed (Output of TxD Pin)
#if Clock_Polarity_TX == Rising_TX
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCPOL);

#elif Clock_Polarity_TX == Falling_TX
	SET_BIT(UCSRC,UCSRC_UCPOL);

#else
#error "Wrong USART Clock_Polarity TX option"
#endif


	//Clock_Polarity in Synchronous mode case Received Data Sampled (Input on RxD Pin)
#if Clock_Polarity_RX == Rising_RX
	SET_BIT(UCSRC,UCSRC_UCPOL);

#elif Clock_Polarity_RX == Falling_RX
	CLR_BIT(UCSRC,UCSRC_UCPOL);

#else
#error "Wrong USART Clock_Polarity RX option"
#endif

	UCSRC = Local_u8UCSRCValue;
}

u8 USART_voidReceive_char(void){

	while(GET_BIT(UCSRA,UCSRA_RXC) == 0); //RX Complete

	return UDR ;
}

void USART_voidSend_char(u8 Data){

	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0); //check register Empty or not

	UDR = Data;
}

void USART_vSendString(u8 *str){

	u8 i = 0;
	while (str[i] !='\0') {
		USART_voidSend_char(str[i]);
		i++;
	}
	//USART_vSendString('\0');
}

void USART_vReceiveString(u8 *str)
{

	u8 i = 0;
	str[i] = USART_voidReceive_char();

	while (str[i] !='#') {
	//while((str[i]) != '\0'){
		i++;
		str[i] = USART_voidReceive_char();
	}
	str[i] = '\0';
}

char CompareString(char arr1[10], char arr2[10])
{
	u8 i = 0;
	char flag = 0;
	while(arr2[i] != '\0')
	{
		if(arr1[i] == arr2[i])
			flag = 1;
		else
			flag = 0;
		i++;
	}
	return flag;
}

void USART_voidSendNumber(u32 Cpy_Number)
{
	USART_voidSend_char((Cpy_Number/1000)+48);
	USART_voidSend_char(((Cpy_Number%1000)/100)+48);
	USART_voidSend_char(((Cpy_Number%100)/10)+48);
	USART_voidSend_char((Cpy_Number%10)+48);
}

u8 USART_voidReceive_finish(void)
{
	if(GET_BIT(UCSRA,UCSRA_RXC) != 0) //
	{
	return UDR ;
	}
}
