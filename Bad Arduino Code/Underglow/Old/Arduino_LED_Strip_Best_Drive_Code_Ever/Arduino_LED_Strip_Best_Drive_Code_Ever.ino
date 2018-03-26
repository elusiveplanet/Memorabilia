/*
     Arduino Code Created By Alexis Renderos of FRC Team 2358
     Additions and revisions made by: Jessie Houghton
     Purpose is to drive three different "lanes" of LED strips individually on our competition robot
*/

#include <Adafruit_NeoPixel.h>

//pinouts for lanes
#define LANE_ONE     3  //F1
#define LANE_TWO     5  //F2
#define LANE_THREE   6  //CNT

#define LANE_FOUR    9  //BOT
#define LANE_FIVE    10 //B1
#define LANE_SIX     11 //B2

#define PIXEL_COUNT        15 //for temp obj

#define PIXEL_COUNT_ONE    30
#define PIXEL_COUNT_TWO    30
#define PIXEL_COUNT_THREE  30

#define PIXEL_COUNT_FOUR   30
#define PIXEL_COUNT_FIVE   30
#define PIXEL_COUNT_SIX    30

Adafruit_NeoPixel Lane1 = Adafruit_NeoPixel(PIXEL_COUNT_ONE, LANE_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane2 = Adafruit_NeoPixel(PIXEL_COUNT_TWO, LANE_TWO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane3 = Adafruit_NeoPixel(PIXEL_COUNT_THREE, LANE_THREE, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel Lane4 = Adafruit_NeoPixel(PIXEL_COUNT_FOUR, LANE_FOUR, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane5 = Adafruit_NeoPixel(PIXEL_COUNT_FIVE, LANE_FIVE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane6 = Adafruit_NeoPixel(PIXEL_COUNT_SIX, LANE_SIX, NEO_GRB + NEO_KHZ800);


byte val;

void setup() {
  /*Serial.begin(9600);*/
  Lane1.begin(); Lane2.begin(); Lane3.begin();
  Lane4.begin(); Lane5.begin(); Lane6.begin();
  Lane1.show();  Lane2.show();  Lane3.show();
  Lane4.show();  Lane5.show();  Lane6.show();
}

void loop() {
  /*
    if (Serial.available())
    {
    val = Serial.read();
    Serial.println(int(val));
    interpret(int(val));
    }
    for (int x = 0; x < 10; x++)
    {
    laneOneRainbow(10);
    }
  */

  laneOneColor(Lane1.Color(0, 0, 255));
  laneTwoColor(Lane2.Color(0, 0, 255));
  laneThreeColor(Lane3.Color(0, 0, 255));

  laneFourColor(Lane4.Color(0, 0, 255));
  laneFiveColor(Lane5.Color(0, 0, 255));
  laneSixColor(Lane6.Color(0, 0, 255));

  /*
    for (int x = 0; x < 100000; x++)
    {
    if (x % 2 == 0)
    {
      laneOneColor(Lane1.Color(0, 0, 255));
      laneTwoColor(Lane2.Color(0, 255, 0));
      laneThreeColor(Lane3.Color(255, 0, 0));
    }
    if (x % 3 == 0)
    {
      laneOneColor(Lane1.Color(0, 255, 0));
      laneTwoColor(Lane2.Color(255, 0, 0));
      laneThreeColor(Lane3.Color(0, 0, 255));
    }
    if (x % 5 == 0)
    {
      laneOneColor(Lane1.Color(255, 0, 0));
      laneTwoColor(Lane2.Color(0, 0, 255));
      laneThreeColor(Lane3.Color(0, 255, 0));
    }
    }
    delay(10000);
  */
}

//Lane One Color
void laneOneColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane1.numPixels(); i++) {
    Lane1.setPixelColor(i, c);
    Lane1.show();
  }
}

//Lane Two Color
void laneTwoColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane2.numPixels(); i++) {
    Lane2.setPixelColor(i, c);
    Lane2.show();
  }
}

//Lane Three Color
void laneThreeColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane3.numPixels(); i++) {
    Lane3.setPixelColor(i, c);
    Lane3.show();
  }
}

//Lane Four Color
void laneFourColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane4.numPixels(); i++) {
    Lane4.setPixelColor(i, c);
    Lane4.show();
  }
}

//Lane Five Color
void laneFiveColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane5.numPixels(); i++) {
    Lane5.setPixelColor(i, c);
    Lane5.show();
  }
}

//Lane Six Color
void laneSixColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane6.numPixels(); i++) {
    Lane6.setPixelColor(i, c);
    Lane6.show();
  }
}

void laneOneLaMigra(uint8_t wait) {
  uint16_t i, j;
  bool rb = true;
  for (i = 0; i < Lane1.numPixels(); i++) {
    if (rb) {
      Lane1.setPixelColor(i, Lane1.Color(0, 0, 100));
      rb = false;
    }
    else    {
      Lane1.setPixelColor(i, Lane1.Color(100, 0, 0));
      rb = true;
    }
  }
  Lane1.show();
  rb = true;
  delay(100);
  for (j = 0; j < Lane1.numPixels(); j++) {
    if (rb) {
      Lane1.setPixelColor(j, Lane1.Color(100, 0, 0));
      rb = false;
    }
    else    {
      Lane1.setPixelColor(j, Lane1.Color(0, 0, 100));
      rb = true;
    }
  }
  Lane1.show();
  delay(100);
}

void interpret(int x)
{
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

//Initialises all strip lanes to pre-def pixel color using the fade methods
void initToColorFade(uint32_t c, uint8_t wait) { //C is color for all strips, wait is, well, wait time in ms for all strips.
  laneOneColorWipe(c, wait); laneTwoColorWipe(c, wait); laneThreeColorWipe(c, wait);
}

//Lane One Fade Color
void laneOneColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane1.numPixels(); i++) {
    Lane1.setPixelColor(i, c);
    Lane1.show();
    delay(wait);
  }
}

//Lane Two Fade Color
void laneTwoColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane2.numPixels(); i++) {
    Lane2.setPixelColor(i, c);
    Lane2.show();
    delay(wait);
  }
}

//Lane Three Fade Color
void laneThreeColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane3.numPixels(); i++) {
    Lane3.setPixelColor(i, c);
    Lane3.show();
    delay(wait);
  }
}

//Not Pretty Rainbows
void laneOneRainbow(uint8_t wait) {
  uint16_t i, j;
  for (j = 0; j < 256; j++) {
    for (i = 0; i < Lane1.numPixels(); i++) {
      Lane1.setPixelColor(i, Wheel((i + j) & 255));
    }
    Lane1.show();
    delay(wait);
  }
}

void laneTwoRainbow(uint8_t wait) {
  uint16_t i, j;
  for (j = 0; j < 256; j++) {
    for (i = 0; i < Lane2.numPixels(); i++) {
      Lane2.setPixelColor(i, Wheel((i + j) & 255));
    }
    Lane2.show();
    delay(wait);
  }
}

void laneThreeRainbow(uint8_t wait) {
  uint16_t i, j;
  for (j = 0; j < 256; j++) {
    for (i = 0; i < Lane3.numPixels(); i++) {
      Lane3.setPixelColor(i, Wheel((i + j) & 255));
    }
    Lane3.show();
    delay(wait);
  }
}

//The best single rainbows, all the way
//NOT COMPLETE
void laneOneCoolRainbow(uint8_t wait) {
  uint16_t i, j;
  for (j = 100; j < 200; j++) {
    for (i = 0; i < Lane1.numPixels(); i++) {
      Lane1.setPixelColor(i, Wheel((i + j) & 255));
    }
    Lane1.show();
    delay(wait);
  }
  for (j = 200; j < 100; j--) {
    for (i = 0; i < Lane1.numPixels(); i++) {
      Lane1.setPixelColor(i, Wheel((i + j) & 255));
    }
    Lane1.show();
    delay(wait);
  }
}



// Input a value 0 to 255 to get a color value.
// The colours are a transition in the sequence: red - green - blue - back to red.
uint32_t Wheel(byte WheelPos) {
  int LANE_TEMP = 2;

  //temp pixel object to return color from
  Adafruit_NeoPixel LaneTemp = Adafruit_NeoPixel(PIXEL_COUNT, LANE_TEMP, NEO_GRB + NEO_KHZ800);

  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return LaneTemp.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return LaneTemp.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return LaneTemp.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

/*CompBot Underglow
  BackBar=30*3
  FrontBar=17 + 22



*/

