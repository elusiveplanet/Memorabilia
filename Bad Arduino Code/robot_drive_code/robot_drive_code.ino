// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor DriveM(3); 'ON BELL WIRE
AF_DCMotor TurnM(4); 'ON PURPLE AND GREY WIRE

void setup() {
}

void loop() {
  uint8_t i
  TurnM.run(FORWARD);
  TurnM.setSpeed(200);
  delay(5000);
  TurnM.run(BACKWARD);
  TurnM.setSpeed(200);
  delay(5000);
  /*
      DriveM.run(FORWARD);
      DriveM.setSpeed(255);
      delay(1000);
  */
}
