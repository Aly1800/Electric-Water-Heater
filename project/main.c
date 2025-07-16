#include "../MCAL/DIO/DIO_int.h"
#include "../APP/Heat_control.h"
#include <util/delay.h>
#include "../MCAL/EEPROM/EEPROM_int.h"

int main(void){
	u8 set_temp = 60;
    DIO_voidInit();
    ADC_voidInit();
    HEATER_Init();
    EEPROM_voidInit();
    IN_EEPROM_voidReadDataByte(EEPROM_SET_TEMP_ADDRESS, &set_temp);

    while(1){
        HEATER_HandleOnOffButton();
        HandleUpButton();
        HandleDownButton();
        HEATER_Update();
    }

    return 0;
}


