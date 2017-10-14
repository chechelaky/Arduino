/*
   Autor: Luismar Chechelaky
   Fonte: https://github.com/chechelaky/Arduino/edit/master/Memc/Memc.cpp

   https://www.arduino.cc/en/Reference/HomePage
   1 bytes / uint8_t, byte = (2 ^  8) - 1                 0 to           255
   2 bytes /           int = (2 ^ 15) - 1           -32,768 to        32,767
   2 bytes /  unsigned int = (2 ^ 16) - 1                 0 to        65,535
   4 bytes /          long = (2 ^ 31) - 1    -2,147,483,648 to 2,147,483,647
   4 bytes / unsigned long = (2 ^ 32) - 1                 0 to 4,294,967,295
   4 bytes /         float = ()              -3.4028235E+38 to 3.4028235E+38
   8 bytes /        double =

   Character Strings as Arrays
   http://www-ee.eng.hawaii.edu/~tep/EE160/Book/chap7/subsection2.1.1.2.html
*/

#include "Memc.h"

Memc::Memc(int device){
//  Serial.println("Memc::Memc( device=" + (String) device + " )");
  _device = device;
}

void Memc::Position(unsigned int adr){
  Wire.beginTransmission(_device);
  Wire.write((int)(adr >> 8));
  Wire.write((int)(adr & 0xFF));
};

void Memc::Save(unsigned int adr, uint8_t val){
//  Serial.println("Memc::Save( adr=" + (String) adr + ", uint8_t val=" + (String) val + " )");
  Memc::Position(adr);
  Wire.write(val);
  Wire.endTransmission();
  delay(5);
};

void Memc::Save(unsigned int adr, int val){
//  Serial.println("Memc::Save( adr=" + (String) adr + ", int val=" + (String) val + " )");
  union{
    int v;
    byte b[2];
  }n;
  n.v = val;
  for(byte i = 0 ; i < 2 ; i++){
    Memc::Save(adr+i, n.b[i]);
  }
};

void Memc::Save(unsigned int adr, unsigned int val){
//  Serial.println("Memc::Save( adr=" + (String) adr + ", unsigned val=" + (String) val + " )");
  union{
    unsigned int v;
    byte b[2];
  }n;
  n.v = val;
  for(byte i = 0 ; i < 2 ; i++){
    Memc::Save(adr+i, n.b[i]);
  }
};

void Memc::Save(unsigned int adr, long val){
//  Serial.println("Memc::Save( adr=" + (String) adr + ", long val=" + (String) val + " )");
  union{
    long int v;
    byte b[4];
  }n;
  n.v = val;
  for(byte i = 0 ; i < 4 ; i++){
    Memc::Save(adr+i, n.b[i]);
  }
};

void Memc::Save(unsigned int adr, unsigned long val){
//  Serial.println("Memc::Save( adr=" + (String) adr + ", unsigned long val=" + (String) val + " )");
  union{
    unsigned long v;
    byte b[4];
  }n;
  n.v = val;
  for(byte i = 0 ; i < 4 ; i++){
    Memc::Save(adr+i, n.b[i]);
  }
};

void Memc::Save(unsigned int adr, float val){
//  Serial.println("Memc::Save( adr=" + (String) adr + ", float val=" + (String) val + " )");
  union{
    float v;
    byte b[4];
  }n;
  n.v = val;
  for(byte i = 0 ; i < 4 ; i++){
    Memc::Save(adr+i, n.b[i]);
  }
};

void Memc::Save(unsigned int adr, double val){
//  Serial.println("Memc::Save( adr=" + (String) adr + ", double val=" + (String) val + " )");
  union{
    double v;
    byte b[8];
  }n;
  n.v = val;
  for(byte i = 0 ; i < 8 ; i++){
    Memc::Save(adr+i, n.b[i]);
  }
};

//void Memc::Save(unsigned int adr, String val){
//  val.concat('\0');
//  int len = val.length();
//  if(len < 30){
//    char arr[len];
//    val.toCharArray(arr, len);
//    for(byte i = 0 ; i < len-1 ; i++){
//      Memc::Save(adr+i, (byte)arr[i]);
//    }
//  }
//};

void Memc::Load(unsigned int adr, uint8_t &val){
  Memc::Position(adr);
  Wire.endTransmission();
  Wire.requestFrom(_device, 1);
  byte num;
  if(Wire.available()){
    num = Wire.read();
  }
  Wire.endTransmission();
  val = num;
//  Serial.println("Memc::Load( adr=" + (String) adr + ", uint8_t val=" + (String) val + " )");
};

void Memc::Load(unsigned int adr, int &val){
  union{
    int v;
    byte b[2];
  }n;
  for(byte i = 0 ; i < 2 ; i++){
    Memc::Load(adr+i, n.b[i]);
  }
  val = n.v;
//  Serial.println("Memc::Load( adr=" + (String) adr + ", int val=" + (String) val + " )");
};

void Memc::Load(unsigned int adr, unsigned int &val){
  union{
    unsigned int v;
    byte b[2];
  }n;
  for(byte i = 0 ; i < 2 ; i++){
    Memc::Load(adr+i, n.b[i]);
  }
  val = n.v;
//  Serial.println("Memc::Load( adr=" + (String) adr + ", unsigned int val=" + (String) val + " )");
};

void Memc::Load(unsigned int adr, long &val){
  union{
    long v;
    byte b[4];
  }n;
  for(byte i = 0 ; i < 4 ; i++){
    Memc::Load(adr+i, n.b[i]);
  }
  val = n.v;
//  Serial.println("Memc::Load( adr=" + (String) adr + ", long val=" + (String) val + " )");
};

void Memc::Load(unsigned int adr, unsigned long &val){
  union{
    unsigned long v;
    byte b[4];
  }n;
  for(byte i = 0 ; i < 4 ; i++){
    Memc::Load(adr+i, n.b[i]);
  }
  val = n.v;
//  Serial.println("Memc::Load( adr=" + (String) adr + ", unsigned long val=" + (String) val + " )");
};

void Memc::Load(unsigned int adr, float &val){
  union{
    float v;
    byte b[4];
  }n;
  for(byte i = 0 ; i < 4 ; i++){
    Memc::Load(adr+i, n.b[i]);
  }
  val = n.v;
//  Serial.println("Memc::Load( adr=" + (String) adr + ", float val=" + (String) val + " )");
};

void Memc::Load(unsigned int adr, double &val){
  union{
    double v;
    byte b[8];
  }n;
  for(byte i = 0 ; i < 8 ; i++){
    Memc::Load(adr+i, n.b[i]);
  }
  val = n.v;
//  Serial.println("Memc::Load( adr=" + (String) adr + ", double val=" + (String) val + " )");
};

//void Memc::Load(unsigned int adr, String &val, uint8_t len){
//  char arr[len];
//  byte tmp;
//  String ret;
//  for(byte i = 0 ; i < len ; i++){
//    Memc::Load(adr+i, tmp);
//    ret.concat(char(tmp));
//  }
//  val = ret;
//};
