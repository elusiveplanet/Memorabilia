/*
 * WiiChuckDemo -- 
 *
 * 2008 Tod E. Kurt, http://thingm.com/
 *
 */

#include <Wire.h>
#include "nunchuck_funcs.h"

int loop_cnt=0;

byte accx,accy,zbut,cbut,jxpos,jypos;
int ledPin = 13;


void setup()
{
    Serial.begin(19200);
    nunchuck_setpowerpins();
    nunchuck_init(); // send the initilization handshake
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    Serial.print("Wii are ready!\n");
}

void loop()
{
    if( loop_cnt > 10 ) {
        loop_cnt = 0;

        nunchuck_get_data();

        accx  = nunchuck_accelx(); // ranges from approx 70 - 182
        accy  = nunchuck_accely(); // ranges from approx 65 - 173 
        zbut = nunchuck_zbutton();
        cbut = nunchuck_cbutton(); 
        jypos = nunchuck_buf[1];
        jxpos = nunchuck_buf[0];
        if (jypos >= 200)
        {
          digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
        }
        else if (jypos > 135 & jypos < 200)
        {
          digitalWrite(7, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
        }
        else if (jypos >= 125 & jypos <= 135)
        {
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
        }
        else if (jypos > 55 & jypos < 135)
        {
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(3, LOW);
        }
        else if (jypos <= 55)
        {
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          digitalWrite(3, HIGH);
        }
        
        Serial.print("A X: "); Serial.print((byte)accx,DEC);
        Serial.print(" A Y: "); Serial.print((byte)accy,DEC);
        Serial.print(" A Z: "); Serial.print((byte)nunchuck_buf[4],DEC);
        Serial.print("Z: "); Serial.print((byte)zbut,DEC);
        Serial.print(" C: "); Serial.print((byte)cbut,DEC);
        Serial.print("J X: "); Serial.print((byte)nunchuck_buf[0],DEC);
        Serial.print("J Y: "); Serial.print((byte)nunchuck_buf[1],DEC);
        Serial.println("");

        
        //BUTTON CODE
                if (nunchuck_cbutton() == 1) {
          digitalWrite(9, HIGH);
        }
        else if (nunchuck_cbutton() == 0) {
         digitalWrite(9, LOW); 
        }
        /* 
        if (nunchuck_zbutton() == 1) {
          digitalWrite(8, HIGH);
        }
        else if (nunchuck_zbutton() == 0) {
         digitalWrite(8, LOW); 
        }
        */
       
    }
        loop_cnt++;
    delay(1);
}

