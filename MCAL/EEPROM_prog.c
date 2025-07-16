#include "../../Service/Std_type.h"
#include "../../Service/bit_math.h"
#include "../../Service/reg.h"
#include "EEPROM_int.h"
#include <util/delay.h>

#define EEPROM_TEMP_ADDR 0x00
#define WRITE_TIMEOUT 10000

void EEPROM_voidInit(void) {

}

EEPROM_Status_t IN_EEPROM_voidReadDataByte(u16 Copy_u16Address, u8* Copy_pu8Data)
{
    if(Copy_u16Address > EEPROM_MAX_ADDR) return EEPROM_INVALID_ADDRESS;
    if(Copy_pu8Data == NULL) return EEPROM_INVALID_DATA;

    while(GET_BIT(IN_EEPROM_CTRL_REG, IN_EEPROM_CTRL_EEWE));

    IN_EEPROM_EARL_REG = (u8)Copy_u16Address;
    IN_EEPROM_EARH_REG = (u8)(Copy_u16Address >> 8);
    SET_BIT(IN_EEPROM_CTRL_REG, IN_EEPROM_CTRL_EERE);
    *Copy_pu8Data = IN_EEPROM_DATA_REG;

    return EEPROM_OK;
}

EEPROM_Status_t IN_EEPROM_voidWriteDataByte(u16 Copy_u16Address, u8 Copy_u8Data)
{
    if(Copy_u16Address > EEPROM_MAX_ADDR) return EEPROM_INVALID_ADDRESS;

    u8 sreg = SREG_REG;
    CLR_BIT(SREG_REG, GIE_BIT);

    u32 timeout = 0;
    while(GET_BIT(IN_EEPROM_CTRL_REG, IN_EEPROM_CTRL_EEWE)) {
        if(++timeout > WRITE_TIMEOUT) {
            SREG_REG = sreg;
            return EEPROM_WRITE_TIMEOUT;
        }
    }
    IN_EEPROM_EARL_REG = (u8)Copy_u16Address;
    IN_EEPROM_EARH_REG = (u8)(Copy_u16Address >> 8);
    IN_EEPROM_DATA_REG = Copy_u8Data;
    SET_BIT(IN_EEPROM_CTRL_REG, IN_EEPROM_CTRL_EEMWE);
    SET_BIT(IN_EEPROM_CTRL_REG, IN_EEPROM_CTRL_EEWE);

    SREG_REG = sreg;
    return EEPROM_OK;
}

EEPROM_Status_t EEPROM_SaveTemp(u8 temp)
{
    if(temp < 35 || temp > 75) return EEPROM_INVALID_DATA;

    EEPROM_Status_t status = IN_EEPROM_voidWriteDataByte(EEPROM_TEMP_ADDR, temp);

    u8 verify;
    if(status == EEPROM_OK) {
    	_delay_ms(10);
        IN_EEPROM_voidReadDataByte(EEPROM_TEMP_ADDR, &verify);
        if(verify != temp) {
            return EEPROM_WRITE_FAILED;
        }
    }

    return status;
}

EEPROM_Status_t EEPROM_LoadTemp(u8* temp)
{
    if(temp == NULL) return EEPROM_INVALID_DATA;
    return IN_EEPROM_voidReadDataByte(EEPROM_TEMP_ADDR, temp);
}
