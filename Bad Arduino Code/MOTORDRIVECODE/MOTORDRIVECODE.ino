// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Servo.h> 

// DC motor on M2
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motorLED(3);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
   
  // turn on motor #2
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motorLED.setSpeed(200);
  motorLED.run(RELEASE);
}

int i;

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motorLED.run(FORWARD);
  for (i=0; i<255; i++) {
    motor1.setSpeed(i);  
    motor2.setSpeed(i);
    motorLED.setSpeed(i);
    delay(25);
 }
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motorLED.run(FORWARD);
  for (i=255; i!=0; i--) {
    motor1.setSpeed(i);  
    motor2.setSpeed(i);
    motorLED.setSpeed(i);
    delay(25);
 }
 
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  for (i=0; i<255; i++) {
    motor1.setSpeed(i);  
    motor2.setSpeed(i);
    motorLED.setSpeed(i);
    delay(25);
 }
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  for (i=255; i!=0; i--) {
    motor1.setSpeed(i);  
    motor2.setSpeed(i);
    motorLED.setSpeed(i);
    delay(25);
 }
}
