#include <Adafruit_NeoPixel.h>

#define FLEX_MIN 512
#define FLEX_MAX 614

//pinouts for lanes
//CHANGE FOR GEMMA
#define LANE_ONE     9
#define LANE_TWO     10

#define PIXEL_COUNT_ONE    15
#define PIXEL_COUNT_TWO    15

Adafruit_NeoPixel Lane1 = Adafruit_NeoPixel(PIXEL_COUNT_ONE, LANE_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane2 = Adafruit_NeoPixel(PIXEL_COUNT_TWO, LANE_TWO, NEO_GRB + NEO_KHZ800);

int flexPin = 2;

void setup() {
  Lane1.begin(); Lane2.begin();
  Lane1.show();  Lane2.show();
}

void loop() {
  int aaronFlex = analogRead(flexPin); 
  //You flex the sensor. The arduino flexes very hard.
  
  int aaronMapFlex1 = map(aaronFlex, FLEX_MIN, FLEX_MAX, 0, Lane1.numPixels());
  int aaronMapFlex2 = map(aaronFlex, FLEX_MIN, FLEX_MAX, 0, Lane2.numPixels());

  laneOneColor(Lane1.Color(0, 0, 255), aaronMapFlex1);
  laneTwoColor(Lane2.Color(0, 0, 255), aaronMapFlex2);
}

void laneOneColor(uint32_t c, int flex) {
  for (uint16_t i = 0; i < flex; i++){
    Lane1.setPixelColor(i, c);
    Lane1.show();
  }
}

void laneTwoColor(uint32_t c, int flex) {
  for (uint16_t i = 0; i < flex; i++) {
    Lane2.setPixelColor(i, c);
    Lane2.show();
  }
}
