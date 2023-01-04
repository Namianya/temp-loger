#include <Wire.h>
#include "DS3231.h"

DS3231 Clock;

// type in current info here to set-up the clock properly

byte YT_SetYear = 20;
byte YT_SetMonth = 12;
byte YT_SetDate = 18;
byte YT_SetHour = 10;
byte YT_SetMinute = 42;
byte YT_SetSecond = 00;

void setup () {

    Wire.begin();
    Clock.setYear(YT_SetYear);
    Clock.setMonth(YT_SetMonth);
    Clock.setDate(YT_SetDate);
    Clock.setHour(YT_SetHour);
    Clock.setMinute(YT_SetMinute);
    Clock.setSecond(YT_SetSecond);
//    Clock.setDoW(4);

    Serial.begin(57600);
}

void loop () {  

}

