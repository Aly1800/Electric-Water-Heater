#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../../Service/reg.h"
#include "ADC_int.h"

#define ADCL_REG (*(volatile u8*)0x24)
#define ADCH_REG (*(volatile u8*)0x25)

void ADC_voidInit(){
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS0);
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS1);
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS2);
	SET_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS0);
	CLR_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS1);
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN);
}

u16 ADC_u16StartConversion(u8 Copy_u8ChannelID) {
    ADC_ADMUX_REG &= 0b11100000;
    ADC_ADMUX_REG |= (Copy_u8ChannelID & 0x07);

    SET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADSC);

    while (!GET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADIF));
    SET_BIT(ADC_ADCSRA_REG, ADC_ADCSRA_ADIF);

    u16 result = ADC_ADCL_REG;
    result |= (ADC_ADCH_REG << 8);

    return result;
}
