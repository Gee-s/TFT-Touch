/***************************************************
* This example code is to support the project at https://youtu.be/T4WPC79vNA8
* project by Forrai Lehel @ Gee's
* https://www.youtube.com/channel/UCovS14bgyQZHr6i_6iNDQNA

*Based on code developed by Limor Fried/Ladyada for Adafruit Industries.
 ****************************************************/

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <XPT2046_Touchscreen.h>

#define TFT_DC 9
#define TFT_CS 7
#define CS_PIN  6
#define TIRQ_PIN  2

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);
void setup(void)
{
 tft.begin();
  ts.begin();
 tft.fillScreen(ILI9341_BLACK);
 tft.setTextColor(ILI9341_WHITE);  
 tft.setTextSize(2);
}

void loop(void)
{
 if (ts.tirqTouched()) {
    if (ts.touched()) {
      TS_Point p = ts.getPoint();
      tft.setCursor(0, 0);
      tft.print("Pressure = ");
      tft.print(p.z);
      tft.println();
      tft.print("x = ");
      tft.print(p.x);
      tft.println();
      tft.print("y = ");
      tft.print(p.y);
      delay(1500);
      tft.fillScreen(ILI9341_BLACK);
    }
  }  
}
