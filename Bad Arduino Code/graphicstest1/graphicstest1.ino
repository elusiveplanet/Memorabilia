#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8

const int  buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0; 
unsigned long previousMillis = 0; 
const long interval = 50;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

#include <Wire.h>
#include <ArduinoNunchuk.h>

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
  Serial.begin(9600);
  Serial.println("Hello! This is Alexis Renderos saying that he feels nothing. <3");
  tft.initR(INITR_BLACKTAB);
  nunchuk.init();
  tft.fillScreen(ST7735_BLACK);
  Serial.println("Initialized");
  tft.setRotation(1);
}

void loop() {
  nunchuk.update();
  tft.fillScreen(ST7735_BLACK);
  String ret = String(nunchuk.analogX, DEC) + " " + String(nunchuk.analogY, DEC) + "\n" + String(nunchuk.accelX, DEC) + " " + String(nunchuk.accelY, DEC) + " " + String(nunchuk.accelZ, DEC) + "\n" + String(nunchuk.zButton, DEC) + " " + String(nunchuk.cButton, DEC);
  Serial.println(ret);
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    
    testdrawtext(ret, ST7735_WHITE);
  }
}

void testdrawtext(String text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

