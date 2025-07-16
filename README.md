# Electric-Water-Heater
This project is a smart electric water heater system built using an AVR microcontroller. It allows the user to set the desired water temperature using push buttons, with the current and set temperatures displayed on a 2-digit 7-segment display. The system uses an LM35 sensor to monitor the water temperature and stores the user’s preferred temperature in external EEPROM for persistence across power cycles.

The heating and cooling elements are controlled using solid-state relays based on a temperature comparison algorithm with hysteresis (±5°C). A heating LED indicates system status by blinking or remaining steady. The project includes ON/OFF control, temperature averaging, and a timeout-based setting mode. It demonstrates key embedded system concepts such as ADC reading, EEPROM usage, and modular driver design.
![WhatsApp Image 2025-07-16 at 16 51 14 (1)](https://github.com/user-attachments/assets/0a241ff4-3791-47dc-91ee-f8b20a426475)
