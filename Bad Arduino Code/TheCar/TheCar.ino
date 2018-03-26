/**
 ***  Arduino Code Created By Alexis Renderos of FRC Team 2358
 ***  Additions and revisions made by: Jessie Houghton
 ***  Purpose is to drive six different "lanes" of LED strips individually on our competition robot.
 ***  This allows for easier creation of patterns using the addressable functions built into the LED strips.
 ***  Code is written for 3 pin 5050 chipset "Neo-Pixel" style LEDs.
**/

/*
   Possible new ideas to test on strips

   Breathing/Blood(lines):
   Strips light up from the center of back and spread out through the strips in a U shape
   Derivatives: Rainbow blood, Blue blood, Alliance specific blood

   COMMMANDS FOR SERIAL
   ALL VALUES ARE CHAR

   B-COLORS ALL STRIPS BLUE
   E-CREATES A RANDOM BLUE PATTERN - LIKE FIRE
   F-CREATES A RANDOM RED PATTERN  - LIKE FIRE
   I-INITIALIZES ALL STRIPS TO BLUE WITH A FADE
   J-INITIALIZES ALL STRIPS TO BLUE WITH A LONGER FADE
   K-INITIALIZES ALL STRIPS TO WHITE WITH A FADE
   L-INITIALIZES ALL STRIPS TO WHITE WITH A LONGER FADE
   M-COLORS ALL STRIPS RED
   N-TURNS ALL STRIPS OFF
   O-CREATES A HEARTBEAT IN BLUE LIGHT - INFINITE BUT CAN BE INTERRUPTED BY NEW SERIAL DATA
   P-CREATES A SINGLE HEARTBEAT IN BLUE LIGHT
   Q-FADES ALL STRIPS TO BE OFF
   R-A PRETTY, INTERRUPTABLE RAINBOW!
   W-COLORS ALL STRIPS WHITE
   Y-RUNS NON-INTERRUPTABLE DEFAULT-DESIGN METHOD 3
   Z-RUNS NON-INTERRUPTABLE DEFAULT-DESIGN METHOD 2
*/
#include <Adafruit_NeoPixel.h>

//pinouts for lanes
#define LANE_ONE     3  //F1
#define LANE_TWO     5  //F2
#define LANE_THREE   6  //CNT

#define LANE_FOUR    9  //BOT
#define LANE_FIVE    10 //B1
#define LANE_SIX     11 //B2

#define PIXEL_COUNT        30 //for temp obj

#define PIXEL_COUNT_ONE    18  //18
#define PIXEL_COUNT_TWO    18  //18
#define PIXEL_COUNT_THREE  30  //30

#define PIXEL_COUNT_FOUR   3
#define PIXEL_COUNT_FIVE   3
#define PIXEL_COUNT_SIX    3  

#define PIXEL_BRIGHTNESS   255 //0-255

Adafruit_NeoPixel Lane1 = Adafruit_NeoPixel(PIXEL_COUNT_ONE, LANE_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane2 = Adafruit_NeoPixel(PIXEL_COUNT_TWO, LANE_TWO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane3 = Adafruit_NeoPixel(PIXEL_COUNT_THREE, LANE_THREE, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel Lane4 = Adafruit_NeoPixel(PIXEL_COUNT_FOUR, LANE_FOUR, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane5 = Adafruit_NeoPixel(PIXEL_COUNT_FIVE, LANE_FIVE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane6 = Adafruit_NeoPixel(PIXEL_COUNT_SIX, LANE_SIX, NEO_GRB + NEO_KHZ800);

bool runDefault = true;

void setup() {
  Serial.begin(9600);
  Lane1.begin(); Lane2.begin(); Lane3.begin();
  Lane4.begin(); Lane5.begin(); Lane6.begin();
  Lane1.show();  Lane2.show();  Lane3.show();
  Lane4.show();  Lane5.show();  Lane6.show();
  Serial.println("Fully Initialized!");
}

void loop() {
  //Disable code - Takes a time interval and then shuts off the leds if there hasnt been a cereal bowl poured in the last couple of minutes
  /*
    static int timeSince;
    if (millis() + (1000 * 60) <= timeSince)
    {
    interpret('N');
    }
    */
  if (runDefault) {
    Serial.println("Running default code master! :)");
    straightBlueFire();
  }
  else if (Serial.available() > 0) {
    //timeSince = millis();
    interpret(Serial.read());
    Serial.println("Interpreting");
  }
  
  //straightActualFire();
  //straightBlueFire();
}

void interpret(char x) {
  switch (x) {
    case 'B':
      ColorAll(Lane1.Color(0, 0, PIXEL_BRIGHTNESS));
      Serial.println("Painting the strips Phthalo Blue");
      break;
    case 'E':
      straightBlueFire();
      Serial.println("Painting some sick blue beats y0!");
      break;
    case 'F':
      straightActualFire();
      Serial.println("Painting some sick red beats y0!");
      break;
    case 'I':
      initToColorFade(Lane1.Color(0, 0, PIXEL_BRIGHTNESS), 10);
      Serial.println("Initializing to blue");
      break;
    case 'J':
      initToColorFade(Lane1.Color(0, 0, PIXEL_BRIGHTNESS), 100);
      Serial.println("Initializing to blue with a long delay");
      break;
    case 'K':
      initToColorFade(Lane1.Color(PIXEL_BRIGHTNESS, PIXEL_BRIGHTNESS, PIXEL_BRIGHTNESS), 10);
      Serial.println("Initializing to white");
      break;
    case 'L':
      initToColorFade(Lane1.Color(PIXEL_BRIGHTNESS, PIXEL_BRIGHTNESS, PIXEL_BRIGHTNESS), 100);
      Serial.println("Initializing to white with a long delay");
      break;
    case 'M':
      ColorAll(Lane1.Color(PIXEL_BRIGHTNESS, 0, 0));
      Serial.println("Painting the strips Crimson Red");
      break;
    case 'N':
      ColorAll(Lane1.Color(0, 0, 0));
      Serial.println("Painting the strips Black as Night (aka off)");
      break;
    case 'O':
      bleedBlue(Lane1.Color(0, 0, PIXEL_BRIGHTNESS), 25, true);
      Serial.println("Painting an (sorta) infinite blue heartbeat");
      break;
    case 'P':
      bleedBlue(Lane1.Color(0, 0, PIXEL_BRIGHTNESS), 25, false);
      Serial.println("Painting a blue heartbeat");
      break;
    case 'Q':
      initToColorFade(Lane1.Color(0, 0, 0), 100);
      Serial.println("Initializing the strips to Black as Night (aka off)");
      break;
    case 'R':
      Serial.println("Painting a pretty rainbow");
      for (int x = 0;  x < 255; x++) {
        ColorAllWithWait(Wheel(x), 5);
        if (Serial.available() > 0)
          break;
      }
      break;
    case 'S':
      bleedBluePartTwo(Lane1.Color(0, 0, PIXEL_BRIGHTNESS), 20 , false);
      Serial.println("Painting a blue heartbeat with a little rainbow action in the back :]");
      break;
    case 'W':
      ColorAll(Lane1.Color(PIXEL_BRIGHTNESS, PIXEL_BRIGHTNESS, PIXEL_BRIGHTNESS));
      Serial.println("Painting the strips Jersey White");
      break;
    case 'X':
      initToColorFade(Lane1.Color(PIXEL_BRIGHTNESS, 0, 0), 10);
      Serial.println("Initializing to red, like the blood of my enemies");
      break;
    case 'Y':
      defaultDesignFire();
      Serial.println("Running the default code master! :) This seems like it is version 3, the fire one!");
      break;
    case 'Z':
      defaultDesignComp();
      Serial.println("Running the default code master! :) This seems like it is version 2, the comp version!");
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
  for (uint16_t i = 0; i < Lane1.numPixels(); i++) {
    Lane1.setPixelColor(i, c);
    Lane1.show();
  }
}

//Lane Two Color Uniform
void laneTwoColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane2.numPixels(); i++) {
    Lane2.setPixelColor(i, c);
    Lane2.show();
  }
}

//Lane Three Color Uniform
void laneThreeColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane3.numPixels(); i++) {
    Lane3.setPixelColor(i, c);
    Lane3.show();
  }
}

//Lane Four Color Uniform
void laneFourColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane4.numPixels(); i++) {
    Lane4.setPixelColor(i, c);
    Lane4.show();
  }
}

//Lane Five Color Uniform
void laneFiveColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane5.numPixels(); i++) {
    Lane5.setPixelColor(i, c);
    Lane5.show();
  }
}

//Lane Six Color Uniform
void laneSixColor(uint32_t c) { //C is color
  for (uint16_t i = 0; i < Lane6.numPixels(); i++) {
    Lane6.setPixelColor(i, c);
    Lane6.show();
  }
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

//Lane Four Fade Color
void laneFourColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane4.numPixels(); i++) {
    Lane4.setPixelColor(i, c);
    Lane4.show();
    delay(wait);
  }
}

//Lane Five Fade Color
void laneFiveColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane5.numPixels(); i++) {
    Lane5.setPixelColor(i, c);
    Lane5.show();
    delay(wait);
  }
}

//Lane Six Fade Color
void laneSixColorWipe(uint32_t c, uint8_t wait) { //C is color, wait is, well, wait time in ms.
  for (uint16_t i = 0; i < Lane6.numPixels(); i++) {
    Lane6.setPixelColor(i, c);
    Lane6.show();
    delay(wait);
  }
}

// Used for bleedBlue
void laneFourPulse(uint32_t c, uint8_t wait)
{
  int left  = 0;
  int right = 0;
  for (int i = Lane4.numPixels() / 2; i > 0; i--)
  {
    left  = i - 1;
    right = Lane4.numPixels() + (i * -1);
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
    right = Lane3.numPixels() + (i * -1);
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
  laneFourPulse(c, wait);
  delay(wait);
  laneFiveSixPulse(c, wait);
  delay(wait);
  laneThreePulse(c, wait);
  delay(wait);
  laneOneTwoPulse(c, wait);
  delay(wait);
  bleedBlueReverse(Lane1.Color(0, 0, 0), wait);
  if (recursive)
    if (!Serial.available() > 0) {
      delay(5000);
      bleedBlue(c, wait, recursive);
    }
}

void bleedBlueReverse(uint32_t c, uint8_t wait)
{
  laneFourPulse(c, wait);
  delay(wait);
  laneFiveSixPulse(c, wait);
  delay(wait);
  laneThreePulse(c, wait);
  delay(wait);
  laneOneTwoPulse(c, wait);
  delay(wait);
}

void bleedBluePartTwo(uint32_t c, uint8_t wait, bool recursive)
{
  customRainbowLane4(wait);
  laneFourPulse(c, wait);
  delay(wait);
  laneFiveSixPulse(c, wait);
  delay(wait);
  laneThreePulse(c, wait);
  delay(wait);
  laneOneTwoPulse(c, wait);
  delay(wait);
  bleedBlueReverse(Lane1.Color(0, 0, 0), wait);
  if (recursive)
    if (!Serial.available() > 0)
      bleedBlue(c, wait, recursive);
}

void defaultDesignFun() {
  interpret('J'); //long init blue
  delay(10);
  interpret('L'); //long init white
  delay(10);
  interpret('I'); //init blue
  delay(100);
  interpret('K'); //init white
  delay(100);
  interpret('N'); //init to black
  delay(100);
  interpret('X'); //init to red for rainbow
  delay(100);
  interpret('R'); //rainbow
  interpret('R'); //rainbow
  delay(100);
  interpret('I'); //init blue
  delay(500);

  interpret('P');
  interpret('P');
  interpret('P');

  interpret('P');
  interpret('P');
  interpret('P');

  interpret('I'); //init blue
  delay(500);
  interpret('B'); //paint blue
  delay(500);
  interpret('E'); //blue fire
  interpret('N'); //init to black
  delay(250);
}

void defaultDesignComp() {
  interpret('O'); //single pulse P or rainbow with pulse S
  //delay(5000);
}

void defaultDesignFire() {
      if (!Serial.available() > 0)
  interpret('E');                               //Blue fire test
  bleedBlueReverse(Lane1.Color(0, 0, 0), 25); //Clear
      if (!Serial.available() > 0)
  interpret('F');                               //Red fire test
  bleedBlueReverse(Lane1.Color(0, 0, 0), 25); //Clear
}

void straightBlueFire()
{
  //3 Second burst
  for (int iter = 0; iter <= 30; iter++)
  {
    for (int x = 0; x < Lane6.numPixels(); x++)
    {
      int color1 = regulate(random(98, 252) + 255);
      int color2 = regulate(random(98, 252) + 255);
      int color3 = regulate(random(98, 252) + 255);
      Lane4.setPixelColor(x, Wheel(color1));
      Lane5.setPixelColor(x, Wheel(color2));
      Lane6.setPixelColor(x, Wheel(color3));
    }
    Lane1.show();
    Lane2.show();
    Lane3.show();
    Lane4.show();
    Lane5.show();
    Lane6.show();
    delay(150);
  }
}

void straightActualFire()
{
  //3 Second burst
  for (int iter = 0; iter <= 30; iter++)
  {
    for (int x = 0; x < Lane6.numPixels(); x++)
    {
      int color1 = regulate(random(0, 40) + 250);
      int color2 = regulate(random(0, 40) + 250);
      int color3 = regulate(random(0, 40) + 250);
      Serial.println(color1);
      Serial.println(color2);
      Serial.println(color3);
      Lane1.setPixelColor(x, Wheel(color1));
      Lane2.setPixelColor(x, Wheel(color2));
      Lane3.setPixelColor(x, Wheel(color3));
      Lane4.setPixelColor(x, Wheel(color1));
      Lane5.setPixelColor(x, Wheel(color2));
      Lane6.setPixelColor(x, Wheel(color3));
    }
    Lane1.show();
    Lane2.show();
    Lane3.show();
    Lane4.show();
    Lane5.show();
    Lane6.show();
    delay(100);
  }
}

//NEEDS TESTING NEEDS TESTING NEEDS TESTING NEEDS TESTING NEEDS TESTING
void blueLightPulseAll(int wait)
{
  for (int x = 0; x < 255; x++)
    ColorAll(Lane1.Color(0, 0, x));
  delay(wait);
  for (int y = 255; y > 0; y--)
    ColorAll(Lane1.Color(0, 0, y));
}

//NEEDS TESTING NEEDS TESTING NEEDS TESTING NEEDS TESTING NEEDS TESTING
void customRainbowLane4(int iterWait)
{
  int x = Lane6.numPixels();
  int wVal = (255 / x);
  for (int numIter = 0; numIter < x; numIter++)
  {
    for (int pixel = 0; pixel < x; pixel++)
    {
      Lane6.setPixelColor(pixel, Wheel((wVal * pixel) + (wVal * numIter)));
    }
    delay(iterWait);
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

void colorDeep()
{
  ColorAll(Lane1.Color(0, 0, 255));
  delay(100);
  ColorAll(Lane1.Color(0, 255, 0));
  delay(100);
  ColorAll(Lane1.Color(255, 0, 0));
  delay(100);
  ColorAll(Lane1.Color(0, 0, 0));
  delay(100);
  bleedBlue(Lane1.Color(0, 0, 255), 25, false);
  delay(100);
  bleedBlue(Lane1.Color(0, 255, 0), 25, false);
  delay(100);
  bleedBlue(Lane1.Color(255, 0, 0), 25, false);
  delay(100);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition in the sequence: red - green - blue - back to red.
// Requires a pixel number
uint32_t Wheel(byte WheelPos) {
  int LANE_TEMP = 2;
  //temp pixel object to return color from
  Adafruit_NeoPixel LaneTemp = Adafruit_NeoPixel(PIXEL_COUNT, LANE_TEMP, NEO_GRB + NEO_KHZ800);
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)    return LaneTemp.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  if (WheelPos < 170) {
    WheelPos -= 85;       return LaneTemp.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;      return LaneTemp.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
