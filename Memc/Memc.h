/*

   Autor: Luismar Chechelaky
   Fonte: https://github.com/chechelaky/Arduino/blob/master/Memc/Memc.h

   https://www.arduino.cc/en/Reference/HomePage
   1 bytes / uint8_t, byte = (2 ^  8) - 1                 0 to           255
   2 bytes /           int = (2 ^ 15) - 1           -32,768 to        32,767
   2 bytes /  unsigned int = (2 ^ 16) - 1                 0 to        65,535
   4 bytes /          long = (2 ^ 31) - 1    -2,147,483,648 to 2,147,483,647
   4 bytes / unsigned long = (2 ^ 32) - 1                 0 to 4,294,967,295
   4 bytes /         float = ()              -3.4028235E+38 to 3.4028235E+38
   8 bytes /        double =

   Reading and Writing Data Structures to EEPROM
   https://playground.arduino.cc/Code/EEPROMWriteAnything

   byte, uint8
   https://oscarliang.com/arduino-difference-byte-uint8-t-unsigned-cha/

   HOW AND WHY TO USE NAMESPACES
   https://luckyresistor.me/2014/10/31/how-and-why-to-use-namespaces/
*/

#pragma once
#ifndef Memc_h
#define Memc_h

#include <Wire.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


class Memc{
  public:
    Memc(int pin);
    void Position(unsigned int adr);
    void Save(unsigned int adr, uint8_t val);
    void Save(unsigned int adr, int val);
    void Save(unsigned int adr, unsigned int val);
    void Save(unsigned int adr, long val);
    void Save(unsigned int adr, unsigned long val);
    void Save(unsigned int adr, float val);
    void Save(unsigned int adr, double val);
//    void Save(unsigned int adr, String val);

    void Load(unsigned int adr, uint8_t &val);
    void Load(unsigned int adr, int &val);
    void Load(unsigned int adr, unsigned int &val);
    void Load(unsigned int adr, long &val);
    void Load(unsigned int adr, unsigned long &val);
    void Load(unsigned int adr, float &val);
    void Load(unsigned int adr, double &val);
//    void Load(unsigned int adr, String &val, uint8_t len);

  private:
    int _device;
};

#endif

