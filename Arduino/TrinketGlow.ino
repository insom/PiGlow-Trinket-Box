#include <TinyWireM.h>

#define WHERE 0x54

#define Wire TinyWireM

bool x;

void setup() {
  Wire.begin();
  pinMode(1, OUTPUT);
  x = 0;

  Wire.beginTransmission(WHERE);
  Wire.write(0x17);
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(WHERE);
  Wire.write(0x0);
  Wire.write(1);
  Wire.endTransmission();
  Wire.beginTransmission(WHERE);
  Wire.write(0x13);
  Wire.write(0x3f);
  Wire.endTransmission();
  Wire.beginTransmission(WHERE);
  Wire.write(0x14);
  Wire.write(0x3f);
  Wire.endTransmission();
  Wire.beginTransmission(WHERE);
  Wire.write(0x15);
  Wire.write(0x3f);
  Wire.endTransmission();

  Wire.beginTransmission(WHERE);
  Wire.write(0x16);
  Wire.write(0x0);
  Wire.endTransmission();

}

void loop() {

  Wire.beginTransmission(WHERE);
  Wire.write(random(1, 0x13));
  Wire.write(random(0xff));
  Wire.endTransmission();
  
  Wire.beginTransmission(WHERE);
  Wire.write(0x16);
  Wire.write(0x0);
  Wire.endTransmission();
  
  delay(10);
  digitalWrite(1, x ? HIGH : LOW);
  x = !x;

}
