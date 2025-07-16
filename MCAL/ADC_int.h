#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#include "../../Service/Std_type.h"

#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7
#define ADC_OK      0
#define ADC_ERROR   1

void ADC_voidInit();
u16 ADC_u16StartConversion(u8 Copy_u8ChannelID);

#endif
