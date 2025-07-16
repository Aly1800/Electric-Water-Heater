#ifndef UART_INT_H_
#define UART_INT_H_

void UART_voidInit(void);
void UART_voidTransmit(u8 data);
void UART_voidTransmitString(const char* str);
void UART_voidTransmitNumber(u16 num);
void UART_voidSendString(const char* str);
void UART_voidSendData(u8 data);

#endif
