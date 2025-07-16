#ifndef ELEMENT_INT_H
#define ELEMENT_INT_H

typedef enum {
    ELEMENT_HEATER,
    ELEMENT_PELTIER,
    ELEMENT_LED
} Element_t;

typedef enum {
    ELEMENT_OFF,
    ELEMENT_ON
} Element_State_t;

void ELEMENT_Init(void);
void ELEMENT_SetState(Element_t element, Element_State_t state);
void ELEMENT_ToggleState(Element_t element);


#endif
