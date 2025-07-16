#ifndef BUTTONS_INT_H_
#define BUTTONS_INT_H_

#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../Service/reg.h"
#include <avr/interrupt.h>
#include <util/delay.h>

#define BUTTON_PRESSED    1
#define BUTTON_NOT_PRESSED 0

#define DEBOUNCE_INTERVAL_MS 100
#define ON_OFF_PORT   DIO_PORTD
#define ON_OFF_PIN    DIO_PIN_2
#define UP_BUTTON_PORT   DIO_PORTD
#define UP_BUTTON_PIN    DIO_PIN_3
#define DOWN_BUTTON_PORT DIO_PORTD
#define DOWN_BUTTON_PIN  DIO_PIN_4

void BUTTON_Init(void);

u8 BUTTON_UP_pressed(void);
u8 BUTTON_DOWN_pressed(void);

#endif
