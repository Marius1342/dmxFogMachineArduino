/*
 * Filename: \src\main.cpp
 * Path: \src
 * Created Date: Sunday, October 15th 2023, 5:16:30 pm
 * Author: Marius Knies
 *
 * Copyright (c) 2023 Marius Knies
 */
#define VERSION "0.0.1"

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include <EEPROM.h>

#include "Adafruit_SSD1306.h"

#include "DMXSerial_megaavr.h"
#include "DMXSerial_avr.h"
#include "DMXSerial.h"

#include "screen.h"

#include "config.h"

uint16_t dmxAddress = standardAddress;
uint16_t oldDmx = standardAddress;
uint64_t lastActive = millis();
uint64_t sprayStart = millis();
bool reset = false;
bool onState = false;
Screen *lcd = nullptr;

void printText(const String &Text)
{
  lcd->printText(Text);
}

void handelOLED();

void reloadDmx()
{
  delay(500);

  if (oldDmx == dmxAddress)
  {
    lcd->setTextColor(WHITE);
  }

  if (reset)
  {
    dmxAddress = standardAddress;
    EEPROM.put(EEPROM_ADDRESS, dmxAddress);
    printText("Reset, wait");
    delay(750);
    printText("CH: " + String(dmxAddress));
    reset = false;
    return;
  }
  EEPROM.put(EEPROM_ADDRESS, dmxAddress);
  reset = true;
  printText("Set, wait");
  delay(750);
  printText("CH: " + String(dmxAddress));
}

void downAddress()
{

  reset = false;
  if (dmxAddress == 0)
  {
    dmxAddress = 512;
  }
  else
  {
    dmxAddress--;
  }
  printText("CH: " + String(dmxAddress));

  // Check if dmxAddress is old dmx address
  if (oldDmx == dmxAddress)
  {
    lcd->setTextColor(WHITE);
  }
  else
  {
    lcd->setTextColor(BLACK);
  }
}
void upAddress()
{

  reset = false;
  if (dmxAddress == 512)
  {
    dmxAddress = 0;
  }
  else
  {
    dmxAddress++;
  }
  printText("CH: " + String(dmxAddress));

  // Check if dmxAddress is old dmx address
  if (oldDmx == dmxAddress)
  {
    lcd->setTextColor(WHITE);
  }
  else
  {
    lcd->setTextColor(BLACK);
  }
}

void setup()
{

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(mosfetAddress, OUTPUT);

  lcd = new Screen();

  pinMode(mosfetAddress, OUTPUT);

  if (OLED_SELECT)
  {
    pinMode(SELECT_BTN, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    pinMode(UP, INPUT_PULLUP);
  }

  DMXSerial.init(DMXReceiver);

  lcd->welcome();
  if (OLED_SELECT)
  {
    if (EEPROM.read(EEPROM_ADDRESS + 2) == 22)
    {
      EEPROM.get(EEPROM_ADDRESS, dmxAddress);
    }
    else
    {
      EEPROM.put(EEPROM_ADDRESS, dmxAddress);
      EEPROM.write(EEPROM_ADDRESS + 2, 22);
    }
  }
  oldDmx = dmxAddress;
  lcd->printText("CH: " + String(dmxAddress));
}

void loop()
{
  int value = DMXSerial.read(20);
  if (value > 0 && onState == false)
  {
    onState = true;
    if (lastActive - millis() > minTimeDiff)
    {
      digitalWrite(mosfetAddress, HIGH);
      lastActive = millis();
    }
  }
  else if (value == 0)
  {
    onState = false;
    // Check for min spray time
    if (millis() - lastActive > minSprayTime)
    {
      digitalWrite(mosfetAddress, LOW);
    }
    else
    {
      printText("Min spray time: " + String(minSprayTime) + "ms");
    }
  }

  handelOLED();

  if (DMXSerial.noDataSince() > DMX_TIMEOUT_WARN)
  {
    digitalWrite(mosfetAddress, LOW);
    printText("No DMX");
    delay(2000);
  }
  else
  {
    printText("CH:" + String(dmxAddress));
  }
}

void handelOLED()
{
  if (OLED_SELECT)
  {
    if (digitalRead(SELECT_BTN) == HIGH)
    {
      reloadDmx();
      delay(250);
    }
    else if (digitalRead(DOWN) == HIGH)
    {
      downAddress();
      delay(delayTimeButton);
    }
    else if (digitalRead(UP) == HIGH)
    {
      upAddress();
      delay(delayTimeButton);
    }
  }
}