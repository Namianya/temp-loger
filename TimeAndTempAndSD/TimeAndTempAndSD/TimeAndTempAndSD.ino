
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SD.h>


#include <Wire.h>
#include "DS3231.h"

File myFile;

#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

DS3231 Clock;

boolean Century = false;
boolean PM = false;

void setup () {

    Wire.begin();
    Serial.begin(57600);
    Serial.print("Initializing SD card...");
    pinMode(10, OUTPUT);

    if (!SD.begin(10)) {
      Serial.println("initialization failed!");
      return;
    }
    Serial.println("initialization done.");
      sensors.begin();
}


void loop () {

    delay(1000);   

int YT_sec, YT_min, YT_hr, YT_yr, YT_mt, YT_dt;

YT_sec = Clock.getSecond();

if (YT_sec==0) {
YT_min = Clock.getMinute();
YT_hr = Clock.getHour(Century, PM);
YT_yr = Clock.getYear();
YT_mt = Clock.getMonth(Century);
YT_dt = Clock.getDate();
sensors.requestTemperatures();
myFile = SD.open("tempread.txt", FILE_WRITE);
if (myFile) {
  myFile.print(YT_dt); 
  myFile.print('/');
  myFile.print(YT_mt);
  myFile.print('/');
  myFile.print(YT_yr);
  myFile.print(' ');
  myFile.print(YT_hr);
  myFile.print(':');
  myFile.print(YT_min);
  myFile.print(':');
  myFile.print(YT_sec);  
  myFile.print(',');
  myFile.print(sensors.getTempCByIndex(0));
  myFile.print(',');
  myFile.println(sensors.getTempCByIndex(1));
  myFile.close();
  Serial.println("card write successful");
} else {
  Serial.println("error opening tempread.txt");
}

}

}

