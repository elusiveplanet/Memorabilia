#include <Servo.h>
#include <AFMotor.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      8

Servo servo1;
Servo servo2;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;

void setup()
{
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  pixels.begin();
  pixels.show();
}

void loop()
{
  byte val;
  if (Serial.available())
  {
    val = Serial.read();
    Serial.println(int(val));
    motorMove(int(val));
  }
}

void motorMove(int x)
{
  if (x == 83) //Stop
  {
    servo1.write(90);
    servo2.write(90);
  }

  if (x == 66) //Move front
  {
    servo1.write(180);

    servo2.write(170);
  }

  if (x == 70) //Move back
  {
    servo1.write(0);
    servo2.write(0);
  }

  if (x == 76) //left
  {
    servo1.write(180);
    servo2.write(0);
  }

  if (x == 82) //right
  {
    servo1.write(0);
    servo2.write(180);
  }

  if (x == 119 || x == 87) //white led
  {
    for(int i=0;i<NUMPIXELS;i++)
    {
    pixels.setPixelColor(i, pixels.Color(255,255,255));
    }
  }
}
