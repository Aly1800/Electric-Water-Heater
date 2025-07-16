#include "Buttons_int.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../Service/bit_math.h"
#include "../../Service/reg.h"
#include "../../MCAL/Timer/Timer_int.h"

void BUTTON_Init(void) {
	DIO_voidSetPinDirection(ON_OFF_PORT,   ON_OFF_PIN,    DIO_PIN_INPUT);
	    DIO_voidEnablePullUp(ON_OFF_PORT,      ON_OFF_PIN);

	    DIO_voidSetPinDirection(UP_BUTTON_PORT,   UP_BUTTON_PIN,   DIO_PIN_INPUT);
	    DIO_voidEnablePullUp(UP_BUTTON_PORT,     UP_BUTTON_PIN);

	    DIO_voidSetPinDirection(DOWN_BUTTON_PORT, DOWN_BUTTON_PIN, DIO_PIN_INPUT);
	    DIO_voidEnablePullUp(DOWN_BUTTON_PORT,    DOWN_BUTTON_PIN);

}

u8 BUTTON_UP_pressed(void) {
    if (DIO_u8GetPinValue(UP_BUTTON_PORT, UP_BUTTON_PIN) == DIO_PIN_LOW) {
        _delay_ms(DEBOUNCE_INTERVAL_MS);
        if (DIO_u8GetPinValue(UP_BUTTON_PORT, UP_BUTTON_PIN) == DIO_PIN_LOW)
            return BUTTON_PRESSED;
    }
    return BUTTON_NOT_PRESSED;
}

u8 BUTTON_DOWN_pressed(void) {
    if (DIO_u8GetPinValue(DOWN_BUTTON_PORT, DOWN_BUTTON_PIN) == DIO_PIN_LOW) {
        _delay_ms(DEBOUNCE_INTERVAL_MS);
        if (DIO_u8GetPinValue(DOWN_BUTTON_PORT, DOWN_BUTTON_PIN) == DIO_PIN_LOW)
            return BUTTON_PRESSED;
    }
    return BUTTON_NOT_PRESSED;
}
