#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  delay(10000);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DELETE);
  delay(100);
  Keyboard.releaseAll();

  delay(2000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('l');
  Keyboard.releaseAll();
  while (true);
}

bool checkPin() {
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
  if (voltage > 100)
  return true;
  else
  return false;
}

