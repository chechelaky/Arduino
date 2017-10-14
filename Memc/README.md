Memc - MemoryChip

Biblicoteca destinada a ler/gravar dados no módulo RTC & EEPROM DS3231 AT24C32.
![Alt text](https://github.com/chechelaky/Arduino/blob/master/Memc/atc24c32.jpgg "Módulo DS3231 AT24C32")

O Arduino possui memória gravável, através da biblioteca https://www.arduino.cc/en/Reference/EEPROM.

A expectativa de ciclos de uso da memória (tanto para o processo de leitura/gravação) é de cerca de 100,000 ciclos ou menos.
http://forum.arduino.cc/index.php?topic=188319.0
https://forum.arduino.cc/index.php?topic=100390.0

Já a capacidade de retenção do módulo AT24C32 (conforme https://www.elecrow.com/download/24C32.pdf) é de:
High Reliability
– Endurance: 1 Million Write Cycles
– Data Retention: 100 Years

Memória do módulo ATC24c32: 32Kbits ou 4Kbytes.

Informações técnicas: https://www.elecrow.com/rtc-eeprom-module-ds3231-at24c32-p-863.html

Testada e funcional em:
Arduino Mega 2560
