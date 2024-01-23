/*
 *  UART_Private.h
 *  UART driver for the microcontroller ATMega 32
 *  Created on: Jun 16, 2023
 *  Author: Heba Atef Ahmed
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR                                               *((volatile u8*)0x2c)           //USART I/O Data Register –UDR(RXB, TXB)

#define UCSRA                                             *((volatile u8*)0x2B)           //USART Control and Status Register A – UCSRA
#define UCSRA_RXC                                         7                               //USART Receive Complete
#define UCSRA_TXC                                         6                               //USART Transmit Complete
#define UCSRA_UDRE                                        5                               //USART Data Register Empty
#define UCSRA_FE                                          4                               //Frame Error
#define UCSRA_DOR                                         3                               //Data OverRun
#define UCSRA_PE                                          2                               // Parity Error
#define UCSRA_U2X                                         1                               // Double the USART Transmission Speed
#define UCSRA_MPCM                                        0                               // Multi-processor Communication Mode


#define UCSRB                                             *((volatile u8*)0x2A)           //USART Control and Status Register B – UCSRB
#define UCSRB_RXCIE                                       7                               //RX Complete Interrupt Enable
#define UCSRB_TXCIE                                       6                               //TX Complete Interrupt Enable
#define UCSRB_UDRIE                                       5                               //USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN                                        4                               //Receiver Enable
#define UCSRB_TXEN                                        3                               //Transmitter Enable
#define UCSRB_UCSZ2                                       2                               //Character Size
#define UCSRB_RXB8                                        1                               //Receive Data Bit 8
#define UCSRB_TXB8                                        0                               //Transmit Data Bit 8

#define UCSRC                                             *((volatile u8*)0x40)           //USART Control and Status Register C – UCSRC
#define UCSRC_URSEL                                       7                               //Register Select between UCSRC or UBRRH Register
                                                                                          //one ------> UCSRC // Zero ------> UBRRH
#define UCSRC_UMSEL                                       6                               //USART Mode Select Asynchronous or synchronous
#define UCSRC_UPM1                                        5                               //Parity Mode bit1
#define UCSRC_UPM0                                        4                               //Parity Mode bit0
#define UCSRC_USBS                                        3                               //Stop Bit Select
#define UCSRC_UCSZ1                                       2                               //Character Size bit1
#define UCSRC_UCSZ0                                       1                               //Character Size bit0
#define UCSRC_UCPOL                                       0                               //Clock Polarity

                                     //USART Baud Rate Registers – UBRRL and UBRRH
#define UBRRH                                             *((volatile u8*)0x40)
#define UBRRH_URSEL                                       15                              //Register Select between UCSRC or UBRRH Register
                                  // UBRR11:8: UBRH Baud Rate Register
                                  // UBRR7:0: UBRL Baud Rate Register
#define UBRRL                                             *((volatile u8*)0x29)

#endif /* UART_PRIVATE_H_ */
