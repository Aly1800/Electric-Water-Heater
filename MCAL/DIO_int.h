#include"../../Service/Std_type.h"
#include"../../Service/bit_math.h"

#ifndef DIO_INT_H
 #define DIO_INT_H

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0x00
#define DIO_PORT_HIGH   0xff
#define DIO_PORT_LOW    0x00

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

#define DIGIT_ENABLE_ACTIVE  0  // Active-low
#define DIGIT_ENABLE_INACTIVE 1

#define HEATING_ACTIVE       1  // Active-high
#define HEATING_INACTIVE     0

#define COOLING_ACTIVE       1  // Active-high
#define COOLING_INACTIVE     0

#define STATUS_LED_ON        1  // Active-high (PB2)
#define STATUS_LED_OFF       0

typedef enum {
    DIO_OK,
    DIO_INVALID_PORT,
    DIO_INVALID_PIN,
    DIO_INVALID_DIRECTION,
    DIO_INVALID_VALUE
} DIO_Error_t;

void DIO_voidSetPinDirection(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8direction);
void DIO_voidSetPinValue    (u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value);
u8   DIO_u8GetPinValue      (u8 Copy_u8port, u8 Copy_u8pin);
void DIO_voidSetPortDirection(u8 Copy_u8port,  u8 Copy_u8direction);
void DIO_voidSetPortValue    (u8 Copy_u8port,  u8 Copy_u8value);
u8   DIO_u8GetPortValue      (u8 Copy_u8port);
void DIO_voidEnablePullUp(u8 Copy_u8port, u8 Copy_u8pin);
void DIO_voidTogPinValue    (u8 Copy_u8port, u8 Copy_u8pin);
void DIO_voidInit(void);

 #endif
