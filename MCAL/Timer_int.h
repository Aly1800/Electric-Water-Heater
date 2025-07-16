#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../../Service/reg.h"
#include <avr/interrupt.h>

typedef void (*Timer0_CmpFunc_t)(void);
void TIMER0_Init(void);
void TIMER0_SetCompareMatchCallback(Timer0_CmpFunc_t callback);
void TIMER0_Start(void);
void TIMER0_Stop(void);
u32 TIMER0_GetTicks(void);

#endif // TIMER_INT_H_
