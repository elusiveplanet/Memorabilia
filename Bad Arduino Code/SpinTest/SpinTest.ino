#include <Servo.h>
Servo servo1;

void setup()
{
  Serial.begin(9600);
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

void loop() {
  Serial.println(rounder(map(analogRead(A0), 0, 1023, 0, 180)));
  servo1.write(rounder(map(analogRead(A0), 0, 1023, 0, 180)));
}

