/*
   Autor: Luismar Chechelaky
   Fonte: https://github.com/chechelaky/Arduino/edit/master/Memc/examples/teste.ino

   https://www.arduino.cc/en/Reference/HomePage
   1 bytes / uint8_t, byte = (2 ^  8) - 1                 0 to           255
   2 bytes /           int = (2 ^ 15) - 1           -32,768 to        32,767
   2 bytes /  unsigned int = (2 ^ 16) - 1                 0 to        65,535
   4 bytes /          long = (2 ^ 31) - 1    -2,147,483,648 to 2,147,483,647
   4 bytes / unsigned long = (2 ^ 32) - 1                 0 to 4,294,967,295
   4 bytes /         float = ()              -3.4028235E+38 to 3.4028235E+38
   8 bytes /        double =

*/

#include <Wire.h>
#include <Memc.h>

Memc mem(87);

void setup(){
  Wire.begin();
  Serial.begin(38400);
  Serial.println("Inicio");

  byte n1 = 121;
  mem.Save(30, n1);
  n1 = 0;
  mem.Load(30, n1);
  Serial.println("n1[" + (String) n1 + "]");

  int n2 = 32767;
  mem.Save(31, n2);
  n2 = 0;
  mem.Load(31, n2);
  Serial.println("n2[" + (String) n2 + "]");

  unsigned int n3 = 65535;
  mem.Save(33, n3);
  n3 = 0;
  mem.Load(33, n3);
  Serial.println("n3[" + (String) n3 + "]");

  long n4 = 2147483647;
  mem.Save(35, n4);
  n4 = 0;
  mem.Load(35, n4);
  Serial.println("n4[" + (String) n4 + "]");

  unsigned long n5 = 4294967295;
  mem.Save(38, n5);
  n5 = 0;
  mem.Load(38, n5);
  Serial.println("n5[" + (String) n5 + "]");

  float n6 = 3.141592654;
  mem.Save(42, n6);
  n6 = 0;
  mem.Load(42, n6);
  Serial.println("n6[" + (String) n6 + "]");

  double n7 = 3.141592654;
  mem.Save(46, n7);
  n7 = 0;
  mem.Load(46, n7);
  Serial.println("n7[" + (String) n7 + "]");

//  String n8 = "Curitiba";
//  mem.Save(60, n8);
//  n8 = "";
//  mem.Load(60, n8, 8);
//  Serial.println("n8[" + (String) n8 + "]");



  Serial.println("Fim");
}

void loop(){

}
