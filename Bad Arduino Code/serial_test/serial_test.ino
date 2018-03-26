void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  Serial.println("iter!");
  Serial1.println("1");
  delay(1000);
  Serial1.println("0");
  delay(1000);
}
