#include <AFMotor.h>

AF_DCMotor V12(1);
AF_DCMotor Green(2);
AF_DCMotor Red(3);
AF_DCMotor Blue(4);

void setup() {
  V12.setSpeed(200);
  V12.run(RELEASE);
  Green.setSpeed(200);
  Green.run(RELEASE);
  Red.setSpeed(200);
  Red.run(RELEASE);
  Blue.setSpeed(200);
  Blue.run(RELEASE);
}

void loop() {
  /*

  */
  V12.run(FORWARD);
  Green.run(FORWARD);
  Red.run(FORWARD);
  Blue.run(FORWARD);
  V12.setSpeed(255);
  Green.setSpeed(255);
  Red.setSpeed(255);
  Blue.setSpeed(255);

  /*
  uint16_t i;

  for (i = 0; i < 255; i++) {
    Red.setSpeed(i);
    Blue.setSpeed(i);
    Green.setSpeed(i);
    delay(10);
  }

  for (i = 255; i != 0; i--) {
    Red.setSpeed(i);
    Blue.setSpeed(i);
    Green.setSpeed(i);
    delay(10);
  }
  */
    /*
      uint16_t i;

      for (i = 0; i < 255; i++) {
      V12.setSpeed(i);
      delay(10);
      }

      for (i = 255; i != 0; i--) {
      V12.setSpeed(i);
      delay(10);
    */
    }
