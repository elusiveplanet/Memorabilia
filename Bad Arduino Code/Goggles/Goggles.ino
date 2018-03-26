// Low power NeoPixel goggles example.  Makes a nice blinky display
// with just a few LEDs on at any time.

#include <Adafruit_NeoPixel.h>
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
#include <avr/power.h>
#endif

#define PIN 3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(32, PIN);

uint8_t  mode   = 0, // Current animation effect
         offset = 0; // Position of spinny eyes
uint32_t color  = 0xFF0000; // Start red
uint32_t prevTime;  

void setup() {
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pixels.setBrightness(10);
  prevTime = millis();
}

void loop() {
  for (int x = 0;  x < 255; x++) {
    ColorAllWithWait(Wheel(x), 5);
  }
    for (int x = 0;  x < 255; x++) {
    ColorAllWithWait(Wheel(x), 5);
  }

  for (uint16_t i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i,pixels.Color(0, 0, 0) );
    pixels.show();
    delay(50);
  }
  delay(350);
  
  straightBlueFire();

  straightBlueFire();

  straightBlueFire();

  for (uint16_t i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i,pixels.Color(0, 0, 0) );
    pixels.show();
    delay(50);
  }
  delay(350);
}

void ColorAllWithWait(uint32_t c, uint8_t t) { //C is color for all strips, t is time
    for (uint16_t i = 0; i < 32; i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
  }
  delay(t);
}

void straightBlueFire()
{
  //3 Second burst
  for (int iter = 0; iter <= 30; iter++)
  {
    for (int x = 0; x < pixels.numPixels(); x++)
    {
      int color1 = regulate(random(128, 212) + 255);
      pixels.setPixelColor(x, Wheel(color1));
    }
    pixels.show();
    delay(100);
  }
}

int regulate(int x)
{
  if (x >= 0 && x <= 255)
    return x;
  else if (x > 255)
    return regulate(x - 255);
  else if (x < 0)
    return regulate(x + 255);
  return x;
}

uint32_t Wheel(byte WheelPos) {
  int LANE_TEMP = 2;
  //temp pixel object to return color from
  Adafruit_NeoPixel LaneTemp = Adafruit_NeoPixel(32, 0, NEO_GRB + NEO_KHZ800);
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)    return LaneTemp.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  if (WheelPos < 170) {
    WheelPos -= 85;       return LaneTemp.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;      return LaneTemp.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
