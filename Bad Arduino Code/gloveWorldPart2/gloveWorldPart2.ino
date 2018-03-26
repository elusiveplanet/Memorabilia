
/*
   Possible new ideas to test on strips

   Breathing/Blood(lines):
   Strips light up from the center of back and spread out through the strips in a U shape
   Derivatives: Rainbow blood, Blue blood, Alliance specific blood

 * COMMMANDS FOR SERIAL
 * ALL VALUES ARE CHAR
 *
 * B-COLORS ALL STRIPS BLUE
 * I-INITIALIZES ALL STRIPS TO BLUE WITH A FADE
 * J-INITIALIZES ALL STRIPS TO BLUE WITH A LONGER FADE
 * K-INITIALIZES ALL STRIPS TO WHITE WITH A FADE
 * L-INITIALIZES ALL STRIPS TO WHITE WITH A LONGER FADE
 * M-COLORS ALL STRIPS RED
 * N-TURNS ALL STRIPS OFF
 * Q-FADES ALL STRIPS TO BE OFF
 * R-A PRETTY, INTERRUPTABLE RAINBOW!
 * W-COLORS ALL STRIPS WHITE
 * Z-RUNS NON-INTERRUPTABLE DEFAULT-DESIGN METHOD
 */
#include <Adafruit_NeoPixel.h>

//pinouts for lanes
#define LANE_ONE     3
#define LANE_TWO     9 

#define PIXEL_COUNT        15 //for temp obj

#define PIXEL_COUNT_ONE    12
#define PIXEL_COUNT_TWO    12 

Adafruit_NeoPixel Lane1 = Adafruit_NeoPixel(PIXEL_COUNT_ONE, LANE_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Lane2 = Adafruit_NeoPixel(PIXEL_COUNT_TWO, LANE_TWO, NEO_GRB + NEO_KHZ800);

bool checkInit = true;
bool runDefault = true;
//This ^ will cause for the strips to reject any serial comms and run a premade script if it is set true.
byte val;

void setup() {
  Serial.begin(9600);
  Lane1.begin(); Lane2.begin();
  Lane1.show();  Lane2.show();
  Serial.println("Initialized!");
}

void loop() {
  if (runDefault) {
    Serial.println("Running the default code master! :)");
    defaultDesign();
  }
  else if (Serial.available() > 0) {
    interpret(Serial.read());
    Serial.println("Interpreting");
  }
}

void interpret(char x)
{
  switch (x)
  {
    case 'B':
      ColorAll(Lane1.Color(0, 0, 255));
      Serial.println("Painting the strips Phthalo Blue");
      break;
    case 'I':
      initToColorFade(Lane1.Color(0, 0, 255), 100);
      Serial.println("Initializing to blue");
      break;
    case 'J':
      initToColorFade(Lane1.Color(0, 0, 255), 1000);
      Serial.println("Initializing to blue with a long delay");
      break;
    case 'K':
      initToColorFade(Lane1.Color(255, 255, 255), 100);
      Serial.println("Initializing to white");
      break;
    case 'L':
      initToColorFade(Lane1.Color(255, 255, 255), 1000);
      Serial.println("Initializing to white with a long delay");
      break;
    case 'M':
      ColorAll(Lane1.Color(255, 0, 0));
      Serial.println("Painting the strips Crimson Red");
      break;
    case 'N':
      ColorAll(Lane1.Color(0, 0, 0));
      Serial.println("Painting the strips Black as Night (aka off)");
      break;
    case 'Q':
      initToColorFade(Lane1.Color(0, 0, 0), 100);
      Serial.println("Initializing the strips to Black as Night (aka off)");
      break;
    case 'R':
      Serial.println("Painting a pretty rainbow");
      for (int x = 0;  x < 255; x++)
      {
        ColorAllWithWait(Wheel(x), 25);
        if (Serial.available() > 0) {
          break;
        }
      }
      break;
    case 'W':
      ColorAll(Lane1.Color(255, 255, 255));
      Serial.println("Painting the strips Jersey White");
      break;
    case 'X':
      initToColorFade(Lane1.Color(255, 0, 0), 100);
      Serial.println("Initializing to red");
      break;
    case 'Z':
      defaultDesign();
      Serial.println("Running the default code master! :)");
      break;
  }
}

void defaultDesign() {
  interpret('J'); //long init blue
  delay(100);
  interpret('L'); //long init white
  delay(100);
  interpret('I'); //init blue
  delay(1000);
  interpret('K'); //init white
  delay(1000);
  interpret('Q'); //init to black
  delay(1000);
  interpret('X'); //init to red for rainbow
  delay(1000);
  interpret('R'); //rainbow
  interpret('R'); //rainbow
  delay(100);
  interpret('I'); //init blue
  delay(5000);
  interpret('Q'); //init to black
  delay(250);
}

// Initialises all strip lanes to pixel color using the fade methods
// Used when bot is turned on.
void initToColorFade(uint32_t c, uint8_t wait) { //C is color for all strips, wait is, well, wait time in ms for all strips.
  laneOneColorWipe(c, wait); laneTwoColorWipe(c, wait);
}

//Self-explanatory, does not use fade methods
void ColorAll(uint32_t c) { //C is color for all strips
  laneOneColor(c); laneTwoColor(c);
}

//Colors all strips with added wait to supply rainbow or rainbow-esque method
void ColorAllWithWait(uint32_t c, uint8_t t) { //C is color for all strips, t is time
  laneOneColor(c); laneTwoColor(c); 
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
