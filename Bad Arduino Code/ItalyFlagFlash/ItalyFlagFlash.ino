/*
Alexis Renderos Italy Flag Color Flash Program
3/1/2015
This program makes 3 leds flash on pins 2, 3, and 4. They go off in sequence {2__, _3_, __4, 234, ___, 234, ___ LOOP} with some delay inbetween 234 bursts.
Underscores are the pins currently not enabled.
*/

const int RED_PIN = 2;
const int WHI_PIN = 3;
const int GRE_PIN = 4;

int DISPLAY_TIME = 100;


void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(WHI_PIN, OUTPUT);
  pinMode(GRE_PIN, OUTPUT);
}


void loop()
{
  mainColors();
}

void mainColors()
{
  //green led
  digitalWrite(RED_PIN, LOW);
  digitalWrite(WHI_PIN, LOW);
  digitalWrite(GRE_PIN, HIGH);

  delay(1000);
  
  //white led
  digitalWrite(RED_PIN, LOW);
  digitalWrite(WHI_PIN, HIGH);
  digitalWrite(GRE_PIN, LOW);

  delay(1000);
  
  //red led
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(WHI_PIN, LOW);
  digitalWrite(GRE_PIN, LOW);
  
  delay(1000);
  
  //DISP all then flash 2x
  
  //off
 digitalWrite(RED_PIN, LOW);
 digitalWrite(WHI_PIN, LOW);
 digitalWrite(GRE_PIN, LOW);
 
 delay(250);
 
 //on
 digitalWrite(RED_PIN, HIGH);
 digitalWrite(WHI_PIN, HIGH);
 digitalWrite(GRE_PIN, HIGH);
 
 delay(1000);
 
 //off
 digitalWrite(RED_PIN, LOW);
 digitalWrite(WHI_PIN, LOW);
 digitalWrite(GRE_PIN, LOW);
 
 delay(250);
 
 //on
 digitalWrite(RED_PIN, HIGH);
 digitalWrite(WHI_PIN, HIGH);
 digitalWrite(GRE_PIN, HIGH);
 
 delay(1000);
 
  //off
 digitalWrite(RED_PIN, LOW);
 digitalWrite(WHI_PIN, LOW);
 digitalWrite(GRE_PIN, LOW);
 
 delay(250);
 
}
