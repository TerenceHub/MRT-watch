/* MRT Watch
Parts:
- Arduino Mini Pro
- 1.3" OLED screen
- 2 buttons
- BMP180 Temperture and Pressure sensor
- Tiny RTC (DS1307 chipset)

Features:
 - get time from RTC(real time clock)
 - 3 pages switch : watch, time meter for Xiaobitan to Qizhang MRT, for Qizhang to Xiaobitan 
 - Screen auto/manual sleep and wake up function
 - Temperature and altitude display
 - Only update data when screen on

Author: Terence
Date: March, 2015 version 4.0
Reference:
*/

#include <Time.h>                           // include time library to get the time
#include <U8glib.h>                         // include u8g library for drawing on screen
U8GLIB_SSD1306_132X64 u8g(10, 9, 12, 11, 13);
//                        D0, D1,CS, DC, RST

#include <Wire.h>                           // include I2C library
#include <SFE_BMP180.h>                     // include BMP180 library for temperature and pressure sensor
#include <DS1307RTC.h>                      // include DS1307 RTC library

#include "timeTable_X2Q.h"                  // timetable from Xiaobitan to Qizhang
#include "timeTable_Q2X.h"                  // timetable from Qizhang to Xiaobitan

typedef enum {pageA, pageB, pageC} MyPage;  // using enum to define page number - myPage: pageA = 0, pageB = 1, pageC = 2
MyPage pageNumber = pageA;                  // set initial value of myPage to pageA (=0)

unsigned long oledTime = 0;                 // set initial OLED update timer

boolean sleep = 0;                          // set initial screen satus to screen on (sleep = 0)
unsigned long screenOnTime = 0;             // set screen on time = 0 for initial value
unsigned long screenSaverDuration = 30000;  // set auto screen saver duration to 30s

SFE_BMP180 pressure;                        // create SFE_BMP180 object, called "pressure"


void setup() {
  uint8_t u8g_Begin();
  u8g.setColorIndex(1);
  pressure.begin();                         // initialize BMP180 sensor
  
  pinMode(6, INPUT_PULLUP);                 // set button 1 pin  
  pinMode(7, INPUT_PULLUP);                 // set button 2 pin
  // setTime(12, 52, 30, 4, 2, 15);         // hour, min, sec, date, month, year - set current time without RTC
  
  // set time to RTC when launching first time or change RTC backup bettary   
  /*
  tmElements_t tm;
  tm.Year = 45; // 2015 - 1970 = 45
  tm.Month = 2;
  tm.Day = 6; 
  tm.Hour = 21;
  tm.Minute = 07;
  tm.Second = 30;
  
  //setTime(makeTime(tm));             // set system time in time_t format (seconds from 1970/1/1 00:00:00, UTC)
  RTC.set(makeTime(tm));             // set RTC time in time_t format
  */
  
  // system sync time with RTC
  setSyncProvider(RTC.get);          // sync system time with RTC
}


void clockMeter() {
  // draw clock and sensor reading for first page

  //draw icon
  u8g.setFont (u8g_font_7x13_67_75);
  u8g.setFontPosTop();
  u8g.setPrintPos(8, 0);
  u8g.print(char(244));                     // draw ASCII charactor for icon
  
  //draw Date and Weekday
  u8g.setFont (u8g_font_6x10);
  u8g.setFontPosTop();
  u8g.setPrintPos( 20, 3 );
  u8g.print(day());
  u8g.setPrintPos( 35, 3 );
  drawMonth(month());                       // show month with Jan., Feb., ... Dec.
  u8g.setPrintPos(60, 3);
  u8g.drawStr( 52, 3, ",");                 // draw , between date and weekday
  drawWeekday(weekday());                   // show weekday with Sun, Mon, Tue...
    
  //draw Time
  u8g.setFont (u8g_font_courB24n);
  u8g.setFontPosBaseline();  
  u8g.setPrintPos(18, 44);
  printDigits(hour());  
  u8g.drawStr ( 54, 44, ":");
  u8g.setPrintPos(68, 44);
  printDigits(minute());
  u8g.setFont (u8g_font_6x10);
  u8g.setPrintPos(110, 44);
  printDigits(second());
   
  //draw Temperature and Altitude
  showReading();                             // funcion in Sensor_Reading tab

}


void pageSwitch() {
  // switch pages
  if(pageNumber == 0 && sleep == 0) {
    // first page to show date, clock, temperature and altitude when screen on
    clockMeter();
  }
  else if(pageNumber == 1 && sleep == 0) {
    // second page to show current time, minute countdown for MRT to Qizhang and next MRT time
    showCurrentTime();                       // function in MRT_timer tab
    nextMRT(weekday(), hour(), minute());    // function in MRT_timer tab
  }
  else if(pageNumber == 2 && sleep == 0) {
    // third page to show current time, minute countdown for MRT to Xiaobitab and next MRT time
    showCurrentTime();                       // function in MRT_timer tab
    nextMRT_Q(weekday(), hour(), minute());  // function in MRT_timer tab
  }
}


void sleepOnOff() {
  // switch sleeping mode
  if(sleep == 0) {
    u8g.sleepOff();
  }
  else if(sleep == 1) {
    u8g.sleepOn();
  }
}

void loop() {

  buttonSwitch();                           // button behavior function, page switch and sleep on/off
  sleepOnOff();                             // set screen sleep on/off function
  
  // set OLED update interval
  if (oledTime > millis()) oledTime = millis();
  // update OLED screen every 1 second
  if (millis() - oledTime > 1000) {
    
    // picture loop
    u8g.firstPage();  
    do {      
      pageSwitch();
    } while( u8g.nextPage() );      

    oledTime = millis();                     // reset OLED timer
  }
}
