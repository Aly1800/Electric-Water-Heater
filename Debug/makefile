################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/EEPROM/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/TempSensor/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/ElementControl/subdir.mk
-include HAL/Buttons/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Electric_Water_Heater.lss \

FLASH_IMAGE += \
Electric_Water_Heater.hex \

EEPROM_IMAGE += \
Electric_Water_Heater.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Electric_Water_Heater.elf secondary-outputs

# Tool invocations
Electric_Water_Heater.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Electric_Water_Heater.map -mmcu=atmega32 -o "Electric_Water_Heater.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Electric_Water_Heater.lss: Electric_Water_Heater.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Electric_Water_Heater.elf  >"Electric_Water_Heater.lss"
	@echo 'Finished building: $@'
	@echo ' '

Electric_Water_Heater.hex: Electric_Water_Heater.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Electric_Water_Heater.elf  "Electric_Water_Heater.hex"
	@echo 'Finished building: $@'
	@echo ' '

Electric_Water_Heater.eep: Electric_Water_Heater.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Electric_Water_Heater.elf  "Electric_Water_Heater.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Electric_Water_Heater.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Electric_Water_Heater.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Electric_Water_Heater.elf
	@echo 'Invoking: AVRDude'
	D:\Coding\SDK_Win_64\SDK_Win_64\SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:Electric_Water_Heater.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Electric_Water_Heater.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
