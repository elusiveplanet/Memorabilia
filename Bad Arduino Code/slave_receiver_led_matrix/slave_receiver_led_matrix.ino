// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

//defining constants
enum i2c_cmd {
  CMD_COLOR_WIPE = 66,
  CMD_
};

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}
//400 khz

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}


void interpret(int x)
{
  //Switch over if
    if (x == 66) //Init --- FWD
    {
    laneOneColorWipe(Wheel(100), 250);
    }
    else if (x == 76) //BLUE --- LEFT
    {
    laneOneColor(Lane1.Color(0, 0, 255));
    }
    else if (x == 82) //White --- RIGHT
    {
    laneOneColor(Lane1.Color(255, 255, 255));
    }
    else if (x == 70) //Rainbow --- BACK
    {
    laneOneColor(Lane1.Color(255, 255, 255));
    }
}
