#include <Servo.h>
#include <AFMotor.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            10
#define NUMPIXELS      8


AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

byte val;
byte hold;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500;

void setup()
{
  Serial.begin(9600);

  pixels.begin();

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  //Flash white light to indicate restart
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
  }
  pixels.show();

  delay(100);

  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
  
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    Serial.println(int(val));
    //motorMove(int(val));
  }
}

void motorMove(int x)
{
  if (x == 83) //Stop
  {
motor1.setSpeed(0);
motor2.setSpeed(0);
  }

  if (x == 66) //Move front
  {
    motor1.run(FORWARD);
    motor1.setSpeed(255);
    motor2.run(FORWARD);
    motor2.setSpeed(255);
  }

  if (x == 70) //Move back
  {
    motor1.run(BACKWARD);
    motor1.setSpeed(255);
    motor2.run(BACKWARD);
    motor2.setSpeed(255);
  }

  if (x == 76) //left
  {
    motor1.run(FORWARD);
    motor1.setSpeed(255);
    motor2.run(BACKWARD);
    motor2.setSpeed(255);
  }

  if (x == 82) //right
  {
    motor1.run(BACKWARD);
    motor1.setSpeed(255);
    motor2.run(FORWARD);
    motor2.setSpeed(255);
  }

  if (x == 85 || x == 117) //LIGHTS

    if (x == 85)
    {
      pixels.setPixelColor(0, pixels.Color(0, 0, 100));
      pixels.setPixelColor(1, pixels.Color(0, 70, 0));

      pixels.setPixelColor(2, pixels.Color(100, 0, 0));
      pixels.setPixelColor(3, pixels.Color(20, 20, 100));

      pixels.setPixelColor(4, pixels.Color(20, 20, 100));
      pixels.setPixelColor(5, pixels.Color(100, 0, 0));

      pixels.setPixelColor(6, pixels.Color(0, 70, 0));
      pixels.setPixelColor(7, pixels.Color(0, 0, 100));
      pixels.show();
    }
    else if (x == 117)
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
    }


  if (x == 87 || x == 119) //LIGHTS PT2

    if (x == 87)
    {
      uint16_t i, j;
      for (j = 0; j < 256 * 5; j++) //FIVE ITERATIONS THEN DONE
      {
        for (i = 0; i < pixels.numPixels(); i++)
        {
          pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
        }
        pixels.show();
        delay(10);
      }
    }
    else if (x == 119)
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
    }
}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
