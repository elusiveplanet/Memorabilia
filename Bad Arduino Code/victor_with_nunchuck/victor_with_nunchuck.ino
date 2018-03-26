#include <Wire.h>
#include <ArduinoNunchuk.h>
#include <Servo.h>
#define BAUDRATE 19200
Servo servo1;

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup()
{
  Serial.begin(BAUDRATE);
  nunchuk.init(); 
  servo1.attach(9);
}

int rounder(int var){
  if (var < 0)
  {
  return var + abs(var);
  }
  else if (var > 180)
  {
  return 180; 
  }
}

void loop()
{
  int x;
  int y;
  nunchuk.update();
  /*
  Serial.print(nunchuk.analogX);
  Serial.print("   ");
  Serial.print(nunchuk.analogY);
  Serial.print("   ");
  */
  x = rounder(nunchuk.analogX - 37);
  y = rounder(nunchuk.analogY - 30);
  Serial.println(x);
  Serial.println(y);
  servo1.write(y);
}


