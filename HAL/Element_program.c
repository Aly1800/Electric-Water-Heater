#include "../../MCAL/DIO/DIO_int.h"
#include "Element_int.h"

void ELEMENT_Init(void){
    // Heater OFF
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN_0, DIO_PIN_LOW);
    // Cooler OFF
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN_1, DIO_PIN_LOW);
    // LED OFF
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN_2, DIO_PIN_LOW);
}

void ELEMENT_SetState(Element_t element, Element_State_t state){
    switch (element){
        case ELEMENT_HEATER:
            DIO_voidSetPinValue(DIO_PORTB, DIO_PIN_0, state);
            break;
        case ELEMENT_PELTIER:
            DIO_voidSetPinValue(DIO_PORTB, DIO_PIN_1, state);
            break;
        case ELEMENT_LED:
            DIO_voidSetPinValue(DIO_PORTB, DIO_PIN_2, state);
            break;
    }
}

void ELEMENT_ToggleState(Element_t element){
    switch (element){
        case ELEMENT_LED:
        	DIO_voidTogPinValue(DIO_PORTB, DIO_PIN_2);
            break;
    }
}
