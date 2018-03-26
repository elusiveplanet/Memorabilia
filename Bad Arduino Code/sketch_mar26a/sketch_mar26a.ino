/* ROBOT CODE CREATED BY ALEXIS RENDEROS */
#include <AFMotor.h>
#include <Servo.h> 

AF_DCMotor DriveM(1); /* ON BELL WIRE */
AF_DCMotor TurnM(4); /* ON PURPLE AND GREY WIRE */

Servo servo1;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Sweeperoni");
  
  servo1.attach(9);
}

void loop() {
/*  
DriveM.run(FORWARD);
DriveM.setSpeed(255);
*/
servo1.write(360);


}
