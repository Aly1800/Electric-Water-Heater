#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../../Service/reg.h"
#include "EXTI_int.h"

void (*pfn)(void)=NULL;

void EXTI_voidEnable(u8 Copy_u8Int_ID)
{

	switch(Copy_u8Int_ID)
	{
	case EXTI_INT0 : SET_BIT(EXTI_GICR_REG , EXTI_GICR_INT0);   break;
	case EXTI_INT1 : SET_BIT(EXTI_GICR_REG , EXTI_GICR_INT1);   break;
	case EXTI_INT2 : SET_BIT(EXTI_GICR_REG , EXTI_GICR_INT2);   break;
	default        : /*error*/ break ;

	}
}

void EXTI_voidDisable(u8 Copy_u8Int_ID){

	switch(Copy_u8Int_ID)
	{
	case EXTI_INT0 : CLR_BIT(EXTI_GICR_REG , EXTI_GICR_INT0);   break;
	case EXTI_INT1 : CLR_BIT(EXTI_GICR_REG , EXTI_GICR_INT1);   break;
	case EXTI_INT2 : CLR_BIT(EXTI_GICR_REG , EXTI_GICR_INT2);   break;
	default        : /*error*/ break ;

	}
}

void EXTI_voidInit(void) {
#if EXTI_INT0_INITIAL_VAL == EXTI_ENABLED
    SET_BIT(EXTI_GICR_REG, EXTI_GICR_INT0);
#elif EXTI_INT0_INITIAL_VAL == EXTI_DISABLED
    CLR_BIT(EXTI_GICR_REG, EXTI_GICR_INT0);
#endif

#if EXTI_INT1_INITIAL_VAL == EXTI_ENABLED
    SET_BIT(EXTI_GICR_REG, EXTI_GICR_INT1);
#elif EXTI_INT1_INITIAL_VAL == EXTI_DISABLED
    CLR_BIT(EXTI_GICR_REG, EXTI_GICR_INT1);
#endif

#if EXTI_INT2_INITIAL_VAL == EXTI_ENABLED
    SET_BIT(EXTI_GICR_REG, EXTI_GICR_INT2);
#elif EXTI_INT2_INITIAL_VAL == EXTI_DISABLED
    CLR_BIT(EXTI_GICR_REG, EXTI_GICR_INT2);
#endif
}

void EXTI_voidChangeSenseControl(u8 Copy_u8Int_ID , u8 Copy_u8SenseLevel)
{
	switch(Copy_u8Int_ID)
	{
	case EXTI_INT0 :
		switch (Copy_u8SenseLevel){
		case EXTI_LOW_LEVEL :
			CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
			CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
			break ;
		case EXTI_FALLING_EDGE :
			CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
			SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
			break ;
		case EXTI_RISING_EDGE :
			SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
			SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
			break ;
		case EXTI_ANY_CHANGE:
			SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
			CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
			break ;
		default: /*error */ break ;
		}
		break ;

		case EXTI_INT1 :
			switch (Copy_u8SenseLevel){
			case EXTI_LOW_LEVEL :
				CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
				CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
				break ;
			case EXTI_FALLING_EDGE :
				CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
				SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
				break ;
			case EXTI_RISING_EDGE :
				SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
				SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
				break ;
			case EXTI_ANY_CHANGE:
				SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
				CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
				break ;
			default: /*error */ break ;
			}
			break ;
			case EXTI_INT2 :
				/*0 --> falling */
				/*1 --> Rising */
				if (Copy_u8SenseLevel == EXTI_FALLING_EDGE)
				{

					CLR_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);
				}
				else if (Copy_u8SenseLevel == EXTI_RISING_EDGE)
				{

					SET_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);
				}
				else
				{
					/*error*/
				}
				break ;
	}
}
void EXTI_voidCallBack(void (*fn)(void )){
	if(fn != NULL)
	{
		pfn = fn;
	}else{
		return;
		/*error */
	}
}

void __vector_1 (void) __attribute__ ((signal)) ;
void __vector_1 (void){
	if(pfn != NULL)
	{
		pfn();
	}
}

