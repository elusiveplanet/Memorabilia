

#include <AFMotor.h>

AF_DCMotor DriveM(4); 
AF_DCMotor TurnM(3);
AF_DCMotor DriveMB(1);

void setup() {
  
}

void loop() {
  DriveM.run(BACKWARD);
  DriveM.setSpeed(255);
  DriveMB.run(BACKWARD);
  DriveMB.setSpeed(255);
  delay(500);
  DriveM.run(BACKWARD);
  DriveM.setSpeed(255);
  DriveMB.run(BACKWARD);
  DriveMB.setSpeed(255);
  delay(500);
  /*
      DriveM.run(FORWARD);
      DriveM.setSpeed(255);
      delay(1000);
  */

}
