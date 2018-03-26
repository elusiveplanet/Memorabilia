#include <Adafruit_NeoPixel.h>

//pinouts for lanes
#define LANE_ONE     3  //F1
#define LANE_TWO     5  //F2
#define LANE_THREE   6  //CNT

#define LANE_FOUR    9  //BOT
#define LANE_FIVE    10 //B1
#define LANE_SIX     11 //B2

#define PIXEL_COUNT        15 //for temp obj

#define PIXEL_COUNT_ONE    18
#define PIXEL_COUNT_TWO    18
#define PIXEL_COUNT_THREE  30

#define PIXEL_COUNT_FOUR   30
#define PIXEL_COUNT_FIVE   14
#define PIXEL_COUNT_SIX    15

Adafruit_NeoPixel Lane1 = Adafruit_NeoPixel(PIXEL_COUNT_ONE, LANE_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane2 = Adafruit_NeoPixel(PIXEL_COUNT_TWO, LANE_TWO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane3 = Adafruit_NeoPixel(PIXEL_COUNT_THREE, LANE_THREE, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel Lane4 = Adafruit_NeoPixel(PIXEL_COUNT_FOUR, LANE_FOUR, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane5 = Adafruit_NeoPixel(PIXEL_COUNT_FIVE, LANE_FIVE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane6 = Adafruit_NeoPixel(PIXEL_COUNT_SIX, LANE_SIX, NEO_GRB + NEO_KHZ800);

bool checkInit = true;
byte val;

/*
 * Possible new ideas to test on strips
 * 
 * Breathing/Blood(lines):
 * Strips light up from the center of back and spread out through the strips in a U shape
 * Derivatives: Rainbow blood, Blue blood, Alliance specific blood
 * 
 */

void setup() {
  Serial.begin(9600);
  Lane1.begin(); Lane2.begin(); Lane3.begin();
  Lane4.begin(); Lane5.begin(); Lane6.begin();
  Lane1.show();  Lane2.show();  Lane3.show();
  Lane4.show();  Lane5.show();  Lane6.show();
  Serial.println("Initialized!");
}

void loop() {
  if (Serial.available() > 0) 
  {
  interpret(Serial.read());
  Serial.println("Interpreting");
  }
}

void interpret(char x)
{
  switch(x)
  {
    case 'I':
    initToColorFade(Lane1.Color(0, 0, 255), 10);
    Serial.println("Initializing");
      break;
    case 'P':
    bleedBlue(Lane1.Color(0, 0, 255), 20 , false);
    Serial.println("Painting a heartbeat");
      break;
    case 'O':
    bleedBlue(Lane1.Color(0, 0, 255), 10 , true);
    Serial.println("Painting an infinite (sorta) heartbeat");
      break;
    case 'B':
    ColorAll(Lane1.Color(0, 0, 255));
    Serial.println("Painting the strips Phthalo Blue");
      break;
    case 'W':
    ColorAll(Lane1.Color(255, 255, 255));
    Serial.println("Painting the strips Jersey White");
      break;
    case 'R':
    Serial.println("Painting a pretty rainbow");
    for (int x = 0;  x < 255; x++)
    {
      ColorAllWithWait(Wheel(x), 5);
      if (Serial.available() > 0){
      break;
      }
    }
      break;
  }
}

// Initialises all strip lanes to pixel color using the fade methods
// Used when bot is turned on.
void initToColorFade(uint32_t c, uint8_t wait) { //C is color for all strips, wait is, well, wait time in ms for all strips.
  laneOneColorWipe(c, wait); laneTwoColorWipe(c, wait); laneThreeColorWipe(c, wait);
  laneFourColorWipe(c, wait); laneFiveColorWipe(c, wait); laneSixColorWipe(c, wait);
}

//Self-explanatory, does not use fade methods
void ColorAll(uint32_t c) { //C is color for all strips
  laneOneColor(c); laneTwoColor(c); laneThreeColor(c);
  laneFourColor(c); laneFiveColor(c); laneSixColor(c);
}

//Colors all strips with added wait to supply rainbow or rainbow-esque method
void ColorAllWithWait(uint32_t c, uint8_t t) { //C is color for all strips, t is time
  laneOneColor(c); laneTwoColor(c); laneThreeColor(c);
  laneFourColor(c); laneFiveColor(c); laneSixColor(c);
  delay(t);
}

//Lane One Color Uniform
void laneOneColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane1.numPixels(); i++) {Lane1.setPixelColor(i, c); Lane1.show();}}

//Lane Two Color Uniform
void laneTwoColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane2.numPixels(); i++) {Lane2.setPixelColor(i, c); Lane2.show();}}

//Lane Three Color Uniform
void laneThreeColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane3.numPixels(); i++) {Lane3.setPixelColor(i, c); Lane3.show();}}

//Lane Four Color Uniform
void laneFourColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane4.numPixels(); i++) {Lane4.setPixelColor(i, c); Lane4.show();}}

//Lane Five Color Uniform
void laneFiveColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane5.numPixels(); i++) {Lane5.setPixelColor(i, c); Lane5.show();}}

//Lane Six Color Uniform
void laneSixColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane6.numPixels(); i++) {Lane6.setPixelColor(i, c); Lane6.show();}}



//Lane One Fade Color
void laneOneColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane1.numPixels(); i++) {Lane1.setPixelColor(i, c); Lane1.show(); delay(wait);}}

//Lane Two Fade Color
void laneTwoColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane2.numPixels(); i++) {Lane2.setPixelColor(i, c); Lane2.show(); delay(wait);}}

//Lane Three Fade Color
void laneThreeColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane3.numPixels(); i++) {Lane3.setPixelColor(i, c); Lane3.show(); delay(wait);}}

//Lane Four Fade Color
void laneFourColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane4.numPixels(); i++) {Lane4.setPixelColor(i, c); Lane4.show(); delay(wait);}}

//Lane Five Fade Color
void laneFiveColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane5.numPixels(); i++) {Lane5.setPixelColor(i, c); Lane5.show(); delay(wait);}}

//Lane Six Fade Color
void laneSixColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane6.numPixels(); i++) {Lane6.setPixelColor(i, c); Lane6.show(); delay(wait);}}

// Used for bleedBlue
void laneFourPulse(uint32_t c, uint8_t wait)
{
  int left  = 0;
  int right = 0;
  for (int i = Lane4.numPixels() / 2; i > 0; i--)
  {
    left  = i - 1;
    right = Lane4.numPixels() + (i *-1);
    Lane4.setPixelColor(left,  c);
    Lane4.setPixelColor(right, c);
    Lane4.show();
    delay(wait);
  }
}

// Used for bleedBlue
void laneFiveSixPulse(uint32_t c, uint8_t wait)
{
  for (uint16_t i = 0; i < Lane6.numPixels(); i++) 
  {
   Lane5.setPixelColor(i, c); Lane6.setPixelColor(i, c);
   Lane5.show();              Lane6.show(); 
   delay(wait);
  }
}

// Used for bleedBlue
void laneThreePulse(uint32_t c, uint8_t wait)
{
  int left  = 0;
  int right = 0;
  for (int i = Lane3.numPixels() / 2; i > 0; i--)
  {
    left  = i - 1;
    right = Lane3.numPixels() + (i *-1);
    Lane3.setPixelColor(left,  c);
    Lane3.setPixelColor(right, c);
    Lane3.show();
    delay(wait);
  }
}

// Used for bleedBlue
void laneOneTwoPulse(uint32_t c, uint8_t wait)
{
  for (uint16_t i = 0; i < Lane1.numPixels(); i++) 
  {
   Lane1.setPixelColor(i, c); Lane2.setPixelColor(i, c);
   Lane1.show();              Lane2.show(); 
   delay(wait);
  }
}

//Strips light up from the center of back and spread out through the strips in a U shape
void bleedBlue(uint32_t c, uint8_t wait, bool recursive)
{
  laneFourPulse(c,wait);
  delay(wait);
  laneFiveSixPulse(c,wait);
  delay(wait);
  laneThreePulse(c,wait);
  delay(wait);
  laneOneTwoPulse(c,wait);
  delay(wait);
  ColorAll(Lane1.Color(0,0,0));
  if (recursive){
  if (!Serial.available() > 0)
  {
  bleedBlue(c,wait,recursive);
  }
  }  
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition in the sequence: red - green - blue - back to red.
// Requires a pixel number
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
