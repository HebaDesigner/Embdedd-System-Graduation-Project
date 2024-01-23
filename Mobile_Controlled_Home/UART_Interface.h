/*
 * UART_Interface.h
 * UART driver for the microcontroller ATMega 32
 * Created on: Jun 16, 2023
 * Author: Heba Atef Ahmed
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define F_CPU 8000000UL			/* Define frequency here its 8MHz */

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define  Double_USART_TX_Speed                                 Speed  //Double the USART Transmission Speed
/*Options:
 *               Speed
 *               Double_Speed
 */
#define Speed                                                   0b00000000                 //Speed
#define Double_Speed                                            0b00000010                 //Double_Speed


#define  USART_Receive_Complete_INT                            Disabled
/*Options:
 *               Enabled
 *               Disabled
 */
#define  USART_Transmit_Complete_INT                           Disabled
/*Options:
 *               Enabled
 *               Disabled
 */
#define  USART_Data_Register_Empty_INT                         Enabled
/*Options:
 *               Enabled
 *               Disabled
 */
#define  Receiver_Enable                                       Enabled
/*Options:
 *               Enabled
 *               Disabled
 */
#define  Transmitter_Enable                                    Enabled
/*Options:
 *               Enabled
 *               Disabled
 */
#define  Receive_Data_Bit8                                     Enabled
/*Options:
 *               Enabled
 *               Disabled
 */
#define  Transmit_Data_Bit8                                    Enabled
/*Options:
 *               Enabled
 *               Disabled
 */

#define  Mode_Select                                           Asynchronous                 //USART Mode Select
/*Options:
 *               Asynchronous Operation
 *               Synchronous Operation
 */
#define Asynchronous                                           0b00000000                 //Asynchronous
#define Synchronous                                            0b01000000                 //Synchronous


#define  Mode_Parity                                           Dis_Parity                 //USART Mode Parity
/*Options:
 *               Disabled_Parity
 *               Enabled, Even Parity
 *               Enabled, Odd Parity
 */
#define Dis_Parity                                              0b00000000                 //Disabled_Parity
#define En_Even_Parity                                          0b00100000                 //Enabled, Even Parity
#define En_Odd_Parity                                           0b00110000                 //Enabled, Odd Parity

#define  Stop_Bit_Select                                        bit_1                     //USART Stop Bit Select
/*Options:
 *                1 bit
 *                2 bits
 */
#define bit_1                                                   0b00000000                 //1 bit
#define bits_2                                                  0b00001000                 //2 bits


//#define	UCSRC_URSEL                   0b10000000          	// Register UCSRC Select


#define   Character_Size                                        bit_8
/*Options:  combine UCSZ2 in UCSRB with UCSZ1:0 in UCSRC sets the number of data bits (Character Size) in a frame the Receiver and Transmitter
 *               5-bit (UCSRC)
 *               6-bit (UCSRC)
 *               7-bit (UCSRC)
 *               8-bit (UCSRC)
 *               9-bit (UCSRC)
 */

#define	bit_5	        	                                           0b00000000		//5-bit (UCSRC)
#define	bit_6	        	                                           0b00000010		//6-bit (UCSRC)
#define	bit_7		                                                   0b00000100		//7-bit (UCSRC)
#define	bit_8		                                                   0b00000110		//8-bit (UCSRC)
#define	bit_9   	                                                   0b00000110		//9-bit (UCSRC)

//Clock_Polarity in Synchronous mode case Transmitted Data Changed (Output of TxD Pin)
#define  Clock_Polarity_TX                                        Rising_TX
/*Options:
 *                 Rising XCK Edge
 *                 Falling XCK Edge
 */
#define Rising_TX                                                   0b00000000                 //Rising_TX
#define Falling_TX                                                  0b00000001                 //Falling_TX

//Clock_Polarity in Synchronous mode case Received Data Sampled (Input on RxD Pin)
#define  Clock_Polarity_RX                                        Falling_RX
/*Options:
 *                 Rising XCK Edge
 *                 Falling XCK Edge
 */
#define Rising_RX                                                   0b00000001                 //Rising_RX
#define Falling_RX                                                  0b00000000                //Falling_RX

void UART_Init(void);

void UART_Transmit_string(u8 *str);
void UART_Receive_string(u8 *str);


void USART_Init(void);
u8 USART_voidReceive_char(void);
void USART_voidSend_char(u8 Data);
void UART_vSendstring( char *ptr);
char CompareString(char arr1[10], char arr2[10]);
void USART_voidSendNumber(u32 Cpy_Number);
u8 USART_voidReceive_finish(void);



#endif /* UART_INTERFACE_H_ */
