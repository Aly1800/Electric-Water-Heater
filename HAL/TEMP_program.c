#include "../../MCAL/ADC/ADC_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "../../Service/Std_type.h"
#include "TEMP_int.h"

u8 TEMP_Read(void) {
    u16 adc_value = ADC_u16StartConversion(0);
    u8 temperature = (adc_value * 500UL) / 1024;
    return temperature;
}
