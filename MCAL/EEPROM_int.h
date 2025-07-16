#ifndef MCAL_IN_EEPROM_IN_EEPROM_INT_H_
#define MCAL_IN_EEPROM_IN_EEPROM_INT_H_

#include "../../Service/Std_type.h"

#define EEPROM_MAX_ADDR 1023
#define EEPROM_TEMP_ADDR 0x00

typedef enum {
    EEPROM_OK,
    EEPROM_INVALID_ADDRESS,
    EEPROM_WRITE_TIMEOUT,
    EEPROM_BUSY,
    EEPROM_INVALID_DATA,
    EEPROM_WRITE_FAILED,
    EEPROM_READ_FAILED
} EEPROM_Status_t;


#define EEPROM_MAX_WRITE_CYCLES 100000

EEPROM_Status_t IN_EEPROM_voidReadDataByte(u16 Copy_u16Address, u8* Copy_pu8Data);
EEPROM_Status_t IN_EEPROM_voidWriteDataByte(u16 Copy_u16Address, u8 Copy_u8Data);
EEPROM_Status_t EEPROM_SaveTemp(u8 temp);
EEPROM_Status_t EEPROM_LoadTemp(u8* temp);
void EEPROM_voidInit();


#endif
