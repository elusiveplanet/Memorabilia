#include <Servo.h> 

Servo servo1;

void setup() {
  Serial.begin(9600);   
  servo1.attach(9);
}

void loop() {
  for (int x = 0; x <= 180; x++)
  {
    servo1.write(x);
    Serial.println(x);
    delay(100);
  }
  for (int y = 179; y >= 0; y--)
  {
    servo1.write(y);
    Serial.println(y);
    delay(100);
  }
}
