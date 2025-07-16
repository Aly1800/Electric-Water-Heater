#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/ElementControl/Element_int.h"
#include "../HAL/SSD/SSD_control.h"
#include "Heat_control.h"
#include "../HAL/ElementControl/Element_int.h"
#include <util/delay.h>

u8 systemState = SYSTEM_OFF;
u8 temp_arr[10] = {0};
u8 avg_temp = 0;
u8 settingModeFlag = 0;
u8 set_temp = 60;

void HEATER_Init(void){
    ELEMENT_Init();
    SSD_Init();
}

void HEATER_Start(void) {
    ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_ON);
    ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
}

void COOLER_Start(void) {
    ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
    ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_ON);
}

void HEATCOOL_Stop(void) {
    ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
    ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
}

void HEATER_HandleOnOffButton(void){
    static u8 lastState = 1;
    u8 currentState = DIO_u8GetPinValue(DIO_PORTD, DIO_PIN_2);

    if (currentState == 0 && lastState == 1){
        if (systemState == SYSTEM_OFF){
            systemState = SYSTEM_ON;
        } else {
            systemState = SYSTEM_OFF;
        }
        _delay_ms(200);
    }
    lastState = currentState;
}

void HandleUpButton(void){
    static u8 lastState = 1;
    u8 currentState = DIO_u8GetPinValue(DIO_PORTD, DIO_PIN_3);

    if (currentState == 0 && lastState == 1){
        if (set_temp < 75){
            set_temp += 5;
        }
        _delay_ms(200);
    }
    lastState = currentState;
}

void HandleDownButton(void){
    static u8 lastState = 1;
    u8 currentState = DIO_u8GetPinValue(DIO_PORTD, DIO_PIN_4);

    if (currentState == 0 && lastState == 1){
        if (set_temp > 35){
            set_temp -= 5;
        }
        _delay_ms(200);
    }
    lastState = currentState;
}

extern u8 set_temp;

void HEATER_Update(void){
    static u16 blink_counter = 0;

    if (systemState == SYSTEM_ON){
        ADC_voidInit();
        u8 sensor_temp = TEMP_Read();
        SSD_Write(set_temp);

        if (sensor_temp < set_temp - 5){
            ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_ON);
            ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);

            // Blink LED every second
            blink_counter++;
            if (blink_counter >= 20){
                ELEMENT_ToggleState(ELEMENT_LED);
                blink_counter = 0;
            }
        }
        else if (sensor_temp > set_temp + 5){
            ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
            ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_ON);
            ELEMENT_SetState(ELEMENT_LED, ELEMENT_ON);
            blink_counter = 0;
        }
        else {
            ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
            ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
            ELEMENT_SetState(ELEMENT_LED, ELEMENT_OFF);
            blink_counter = 0;
        }
    }
    else if (systemState == SYSTEM_SETTING){
        SSD_Write(set_temp);
        ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_LED, ELEMENT_ON);
        blink_counter = 0;
    }
    else {
        ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_LED, ELEMENT_OFF);
        SSD_Disable();
        blink_counter = 0;
    }
}

void system_init(void){
    ELEMENT_Init();
    SSD_Init();

    u8 init_temp = TEMP_Read();
    for (u8 i = 0; i < 10; i++){
        temp_arr[i] = init_temp;
    }
    avg_temp = init_temp;
}

void OFF_state(void){
    ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
    ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
    ELEMENT_SetState(ELEMENT_LED, ELEMENT_OFF);
    SSD_Disable();
}

void ON_state(void){
    static u8 temp_index = 0;
    u8 temp = TEMP_Read();

    temp_arr[temp_index] = temp;
    temp_index = (temp_index + 1) % 10;

    u16 sum = 0;
    for (u8 i = 0; i < 10; i++){
        sum += temp_arr[i];
    }
    avg_temp = sum / 10;

    SSD_Write(avg_temp);
    change_temp();
}

void change_temp(void){
    if (avg_temp >= set_temp - 5 && avg_temp <= set_temp + 5){
        ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_LED, ELEMENT_OFF);
    } else if (avg_temp > set_temp + 5){
        ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_ON);
        ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_LED, ELEMENT_ON);
    } else if (avg_temp < set_temp - 5){
        ELEMENT_SetState(ELEMENT_HEATER, ELEMENT_ON);
        ELEMENT_SetState(ELEMENT_PELTIER, ELEMENT_OFF);
        ELEMENT_SetState(ELEMENT_LED, ELEMENT_ON);
    }
}
