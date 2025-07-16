#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../../Service/reg.h"
#include "Timer_int.h"
#include <avr/interrupt.h>
#include <util/delay.h>

static Timer0_CmpFunc_t g_Timer0CmpCallback = NULL;

void TIMER0_Init(void) {
    // Clear TCCR0
    TIMER0_TCCR0_REG = 0;
    // CTC mode: WGM01 = 1
    SET_BIT(TIMER0_TCCR0_REG, TIMER0_TCCR0_WGM01);
    // Set compare value
    TIMER0_OCR0_REG = 250;
    // Enable OCIE0 interrupt
    SET_BIT(TIMER0_TIMSK_REG, TIMER0_TIMSK_OCIE0);
    SET_BIT(SREG_REG, GIE_BIT);
}

void TIMER0_SetCompareMatchCallback(Timer0_CmpFunc_t callback) {
    g_Timer0CmpCallback = callback;
}

void TIMER0_Start(void) {
	 SET_BIT(TIMER0_TCCR0_REG, 2);
	 SET_BIT(TIMER0_TCCR0_REG, 0);
}

void TIMER0_Stop(void) {
    // Clear prescaler bits
    TIMER0_TCCR0_REG &= 0xF8;
}

// ISR for Timer0 Compare Match
void __vector_10(void) __attribute__((signal));
void __vector_10(void) {
    if (g_Timer0CmpCallback) {
        g_Timer0CmpCallback();
    }
}

static volatile u32 g_timer0Ticks = 0;

u32 TIMER0_GetTicks(void) {
    return g_timer0Ticks;
}
