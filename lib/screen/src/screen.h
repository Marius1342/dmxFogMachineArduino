/*
 * Filename: \lib\screen\src\screen.h
 * Path: \lib\screen\src
 * Created Date: Sunday, October 15th 2023, 5:19:42 pm
 * Author: Marius Knies
 *
 * Copyright (c) 2023 Marius Knies
 */
#ifndef SCREEN_H
#define SCREEN_H

#include "Adafruit_SSD1306.h"
#include <Arduino.h>

class Screen
{
private:
    Adafruit_SSD1306 _display;

public:
    Screen();
    void welcome();
    void printText(String text);
    void setColor(int color);
    void setTextColor(int color);
    void clear();
    ~Screen();
};

#endif