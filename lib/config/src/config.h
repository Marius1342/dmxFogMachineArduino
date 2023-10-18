/*
 * Filename: \lib\config\src\config.h
 * Path: \lib\config\src
 * Created Date: Sunday, October 15th 2023, 5:19:43 pm
 * Author: Marius Knies
 *
 * Copyright (c) Marius Knies
 */

// Set this to true, then the oled display is active
#define OLED_SELECT false
#define SELECT_BTN 2
#define DOWN 3
#define UP 4
// The pin for the relay/mosfet
#define mosfetAddress 11

// The start address for the EEPROM
#define EEPROM_ADDRESS 1

// The press delay in ms
#define delayTimeButton 25
// The standard DMX address
#define standardAddress 20
// The minimal time difference between spray -> dont -> spray spray in ms
#define minTimeDiff 1500
// The maximum spray time in ms
#define maxSprayTime 15000
// When no dmx is found in ms
#define DMX_TIMEOUT_WARN 8000
// The minimal spray time for the arduino in ms
#define minSprayTime 700
// Just a constant, all delays use this, for user text and co in ms
#define WAIT_TIME 2000

#if minSprayTime < 700
#pragma warning When the spray time is to short, your fog machine can be damaged
#endif