#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "DHTesp.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "GfxUi.h"
#include "Button.h"
#include "Buzzer.h"

// Graphic Definition
Adafruit_ILI9341 tft = Adafruit_ILI9341(10, D4);
GfxUi ui = GfxUi(&tft);
XPT2046_Touchscreen ts(D3);
#define BL_LED D8

// Button Definition
RectButton next(&tft, FillType::FILL, 300, 220, 20, 20, ILI9341_WHITE, 0xACF0);
RectButton prev(&tft, FillType::FILL, 0, 220, 20, 20, ILI9341_WHITE, 0x41E7);
Buzzer buzz(D1);

// Touchscreen Calibration
const int TS_MINX = 350;
const int TS_MINY = 354;
const int TS_MAXX = 3963;
const int TS_MAXY = 3877;

Song imperialMarch(120, {{NOTE_A4, DotQuarter}, {NOTE_A4, DotQuarter}, {NOTE_A4, Sixteenth}, {NOTE_A4, Sixteenth}, {NOTE_A4, Sixteenth}, {NOTE_A4, Sixteenth}, {NOTE_F4, Eighth}, {NOTE_REST, Eighth},
                      {NOTE_A4, DotQuarter}, {NOTE_A4, DotQuarter}, {NOTE_A4, Sixteenth}, {NOTE_A4, Sixteenth}, {NOTE_A4, Sixteenth}, {NOTE_A4, Sixteenth}, {NOTE_F4, Eighth}, {NOTE_REST, Eighth},
                      {NOTE_A4, Quarter}, {NOTE_A4, Quarter}, {NOTE_A4, Quarter}, {NOTE_F4, DotEighth}, {NOTE_C5, Sixteenth},
                      {NOTE_A4, Quarter}, {NOTE_F4, DotQuarter}, {NOTE_C5, Sixteenth}, {NOTE_A4, Half},
                      {NOTE_E5, Quarter}, {NOTE_E5, Quarter}, {NOTE_E5, Quarter}, {NOTE_F5, DotEighth}, {NOTE_C5, Sixteenth},
                      {NOTE_A4, Quarter}, {NOTE_F4, DotEighth}, {NOTE_C5, Sixteenth}, {NOTE_A4, Half}});

void setup() {
  // Serial Initialization
  Serial.begin(9600);
  buzz.playSong(imperialMarch);

  // Screen Initialization
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  pinMode(BL_LED,OUTPUT);
  digitalWrite(BL_LED,HIGH);
  
  // Touchscreen Initialization
  ts.begin();

  // Image Initialization
  SPIFFS.begin();
  ui.drawBmp("/top_bit.bmp", 0, 0);

  // Button Initialization
  next.render();
  prev.hide();
}

void loop() {
  if(!ts.touched()){
    delay(100);
    return;
  }
  
  auto pt = ts.getPoint();
  int y = map(pt.y, TS_MINY, TS_MAXY, 0, tft.height());
  int x = map(pt.x, TS_MINX, TS_MAXX, 0, tft.width());

  if(next.isPressed(x, y)){
    buzz.setTone(392, 250);
    ui.drawBmp("/bottom_bit.bmp", 0, 0);
    next.hide();
    prev.render();
  }
  else if(prev.isPressed(x, y)){
    buzz.setTone(392, 250);
    ui.drawBmp("/top_bit.bmp", 0, 0);
    next.render();
    prev.hide();
  }

  yield();
  delay(100);
}
