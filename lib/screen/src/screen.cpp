/*
 * Filename: \lib\screen\src\screen.cpp
 * Path: \lib\screen\src
 * Created Date: Sunday, October 15th 2023, 5:19:42 pm
 * Author: Marius Knies
 *
 * Copyright (c) 2023 Marius Knies
 */
#include "Screen.h"
#include "config.h"

/*
Init the screen
*/
Screen::Screen()
{
    if (OLED_SELECT == false)
    {
        return;
    }

    //  0x3C for I2C
    Screen::_display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    Screen::_display.clearDisplay();
    Screen::_display.setTextSize(1);
    Screen::_display.setTextColor(WHITE);
}

void Screen::welcome()
{
    if (OLED_SELECT == false)
    {
        return;
    }
    Screen::_display.setCursor(0, 0);
    Screen::_display.print("FROM: Marius Knies");
    Screen::_display.display();
}

void Screen::printText(String text)
{
    if (OLED_SELECT == false)
    {
        return;
    }
    Screen::_display.clearDisplay();
    Screen::_display.setCursor(0, 0);
    Screen::_display.print(text);
    Screen::_display.display();
}

void Screen::setColor(int color)
{
    if (OLED_SELECT == false)
    {
        return;
    }
    Screen::_display.setTextColor(color);
}

void Screen::setTextColor(int color)
{
    if (OLED_SELECT == false)
    {
        return;
    }
    Screen::_display.setTextColor(color);
}

void Screen::clear()
{
    if (OLED_SELECT == false)
    {
        return;
    }
    Screen::_display.clearDisplay();
}

Screen::~Screen()
{
}