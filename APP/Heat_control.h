#ifndef HEAT_CONTROL_H
#define HEAT_CONTROL_H

#define SYSTEM_OFF 0
#define SYSTEM_ON  1

#define SYSTEM_OFF 0
#define SYSTEM_ON 1
#define SYSTEM_SETTING 2

#define EEPROM_SET_TEMP_ADDRESS  0x00

extern u8 systemState;
extern u8 desired_temp;
extern u8 temp_arr[10];
extern u8 avg_temp;

extern u8 systemState;

void HEATER_Init(void);
void HEATER_HandleOnOffButton(void);
void HEATER_Update(void);
void system_init(void);
void OFF_state(void);
void HEATER_Start(void);
void COOLER_Start(void);
void HEATCOOL_Stop(void);

#endif
