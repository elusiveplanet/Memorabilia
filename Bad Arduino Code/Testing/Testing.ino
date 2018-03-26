#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1            10
#define PIN2            11
#define PIN3            12
#define NUMPIXELS       3
#define SENSORPIN       A3
Adafruit_NeoPixel laneOne = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel laneTwo = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel laneThr = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);

int delayval = 500;

void setup() {
  laneOne.begin();
    laneTwo.begin();
      laneThr.begin();
}

void loop() {
    int val = analogRead(SENSORPIN);
  Serial.println(val);
  for(int i=0;i<NUMPIXELS;i++){
    laneOne.setPixelColor(i, laneOne.Color(val,0,0));
    laneOne.show();
  }
  for(int i=0;i<NUMPIXELS;i++){
    laneTwo.setPixelColor(i, laneTwo.Color(0,val,0));
    laneTwo.show();
  }
  for(int i=0;i<NUMPIXELS;i++){
    laneThr.setPixelColor(i, laneThr.Color(0,0,val));
    laneThr.show();
  }
}
