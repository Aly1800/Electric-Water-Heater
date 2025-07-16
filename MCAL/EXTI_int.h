
#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#define EXTI_INT0    0
#define EXTI_INT1    1
#define EXTI_INT2    2

#define EXTI_LOW_LEVEL     0
#define EXTI_ANY_CHANGE    1
#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3

#define EXTI_ENABLED        1
#define EXTI_DISABLED       0

#define EXTI_INT0_INITIAL_VAL    EXTI_DISABLED
#define EXTI_INT1_INITIAL_VAL    EXTI_DISABLED
#define EXTI_INT2_INITIAL_VAL    EXTI_DISABLED

#define EXTI_INT0_SENSE_MODE    EXTI_LOW_LEVEL
#define EXTI_INT1_SENSE_MODE    EXTI_LOW_LEVEL

#define EXTI_INT2_SENSE_MODE    EXTI_RISING_EDGE

void EXTI_voidEnable(u8 Copy_u8Int_ID);
void EXTI_voidDisable(u8 Copy_u8Int_ID);
void EXTI_voidInit(void);
void EXTI_voidChangeSenseControl(u8 Copy_u8Int_ID , u8 Copy_u8SenseLevel);
void EXTI_voidCallBack(void (*fn)(void ));

#endif
