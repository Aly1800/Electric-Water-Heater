#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_control.h"
#include <util/delay.h>

void SSD_Init(void){
    // Segments (PORTC) as outputs
    DIO_voidSetPortDirection(DIO_PORTC, DIO_PORT_OUTPUT);

    // Digit enables (PD5, PD6) as outputs
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN_5, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN_6, DIO_PIN_OUTPUT);

    SSD_Disable(); // Disable display at startup
}

void SSD_Disable(void){
    // Disable both digits (active LOW logic)
    DIO_voidSetPinValue(DIO_PORTD, DIO_PIN_5, DIO_PIN_HIGH);
    DIO_voidSetPinValue(DIO_PORTD, DIO_PIN_6, DIO_PIN_HIGH);
}

void SSD_Enable(u8 digit){
    if (digit == 1){
        DIO_voidSetPinValue(DIO_PORTD, DIO_PIN_5, DIO_PIN_LOW);  // Enable digit 1
        DIO_voidSetPinValue(DIO_PORTD, DIO_PIN_6, DIO_PIN_HIGH); // Disable digit 2
    } else if (digit == 2){
        DIO_voidSetPinValue(DIO_PORTD, DIO_PIN_5, DIO_PIN_HIGH); // Disable digit 1
        DIO_voidSetPinValue(DIO_PORTD, DIO_PIN_6, DIO_PIN_LOW);  // Enable digit 2
    }
}
void SSD_Write(u8 number){
	u8 tens = number / 10;
	    u8 units = number % 10;

	    SSD_SendPattern(tens);
	    SSD_Enable(1);
	    _delay_ms(5);
	    SSD_Disable();

	    SSD_SendPattern(units);
	    SSD_Enable(2);
	    _delay_ms(5);
	    SSD_Disable();
}



void SSD_SendPattern(u8 digit){
    // Assuming common cathode and direct segment mapping 0-9
    u8 numbers[10] = {0x3F, //0
                      0x06, //1
                      0x5B, //2
                      0x4F, //3
                      0x66, //4
                      0x6D, //5
                      0x7D, //6
                      0x07, //7
                      0x7F, //8
                      0x6F  //9
                     };

    if (digit <= 9){
        DIO_voidSetPortValue(DIO_PORTC, numbers[digit]);
    } else {
        DIO_voidSetPortValue(DIO_PORTC, 0x00); // Blank if out of range
    }
}

void SSD_Refresh(u8 number){
    static u8 digitFlag = 0;
    u8 digit = (digitFlag == 0) ? (number / 10) : (number % 10);

    SSD_SendPattern(digit);

    if (digitFlag == 0){
        SSD_Enable(1);
    } else {
        SSD_Enable(2);
    }

    digitFlag ^= 1; // Toggle digit
}

