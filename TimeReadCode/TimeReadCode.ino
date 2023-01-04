#include <Wire.h>
#include "DS3231.h"

DS3231 Clock;

boolean Century = false;
boolean PM = false;

void setup () {

    Wire.begin();
    Serial.begin(57600);
}


void loop () {

    delay(1000);   

int YT_sec, YT_min, YT_hr, YT_yr, YT_mt, YT_dt;

YT_sec = Clock.getSecond();
YT_min = Clock.getMinute();
YT_hr = Clock.getHour(Century, PM);
YT_yr = Clock.getYear();
YT_mt = Clock.getMonth(Century);
YT_dt = Clock.getDate();

Serial.print(YT_dt); 
Serial.print('/');
Serial.print(YT_mt);
Serial.print('/');
Serial.print(YT_yr);
Serial.print(' ');
Serial.print(YT_hr);
Serial.print(':');
Serial.print(YT_min);
Serial.print(':');
Serial.println(YT_sec);    

}

