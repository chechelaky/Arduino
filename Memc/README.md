# RTC & EEPROM DS3231 AT24C32
Características:
* [relógio](http://www.elecrow.com/download/AT24C32_TEST.zip)
* termometro digital
* chip de memória de 32Kbits para leitura/gravação de dados
* [Informações técnicas](https://www.elecrow.com/rtc-eeprom-module-ds3231-at24c32-p-863.html)

![Alt text](https://github.com/chechelaky/Arduino/blob/master/Memc/atc24c32.jpg "Módulo DS3231 AT24C32")

O uso como relógio é amplamente debatido na internet.
Como termometro, um arquivo de exemplo está contido na biblioteca do relógio.
Pouco é falado sobre a capacidade de leitura/gravação de dados.

# Memc - MemoryChip
Biblicoteca destinada a ler/gravar dados no módulo RTC & EEPROM DS3231 AT24C32.

O Arduino possui memória utilizável (leitura/gravação), através da biblioteca [EEPROM](https://www.arduino.cc/en/Reference/EEPROM).

A expectativa de ciclos de uso da memória no Arduino (tanto para o processo de leitura/gravação) é de cerca de 100,000 ciclos ou menos.
* http://forum.arduino.cc/index.php?topic=188319.0
* https://forum.arduino.cc/index.php?topic=100390.0

Já a capacidade de retenção do módulo AT24C32 (conforme https://www.elecrow.com/download/24C32.pdf) é de:
* High Reliability
* Endurance: 1 Million Write Cycles
* Data Retention: 100 Years

Memória do módulo ATC24c32: 32Kbits ou 4Kbytes.

Testado em:
* Arduino Mega 2560, funcionamento OK.
