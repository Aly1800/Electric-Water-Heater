#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "UART_int.h"
#include <avr/io.h>

void UART_voidInit(void) {
    // Baud Rate: 9600 (for 8MHz)
    UBRRH = 0;
    UCSRB = (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
    UBRRL = 51;

}

void UART_voidTransmit(u8 data) {
    while (!( UCSRA & (1 << UDRE)));
    UDR = data;
}

void UART_voidTransmitString(const char* str) {
    while (*str) {
        UART_voidTransmit(*str++);
    }
}

void UART_voidSendData(u8 data) {
    while (GET_BIT(UCSRA, UDRE) == 0);

    UDR = data;
}

void UART_voidTransmitNumber(u16 num) {
    char buffer[6];
    itoa(num, buffer, 10);
    UART_voidTransmitString(buffer);
}

void UART_voidSendString(const char* str) {
	while(*str) {
		UART_voidSendData(*str++);
	}
}

