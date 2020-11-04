/*
Copyright (C) 2020 Jason Hewitt

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/* Class extends the TinyScreen class to provide additional functionality 
missing from the base TinyScreen.
*/

#include "TinyScreenExt.h"
#include "TinyScreenBattery.h"

/*
  Constructor
*/
TinyScreenExt::TinyScreenExt(uint8_t type)
{
    _display = TinyScreen(TinyScreenPlus);
    _battery = TinyScreenBattery();
}

void TinyScreenExt::begin(void)
{
    _display.begin();
}

// Sets if the Screen of the TinyScreen is fliped vertically
void TinyScreenExt::setFlip(uint8_t f)
{
    _display.setFlip(f);
}

//sets main current level, valid levels are 0-15
void TinyScreenExt::setBrightness(uint8_t brightness)
{
    _display.setBrightness(brightness);
}

// Font methods

//set text cursor position to (x,y)
void TinyScreenExt::setCursor(uint8_t x, uint8_t y)
{
    _cursorX = x;
    _cursorY = y;
    _display.setCursor(x, y);
}

//set font data to use
void TinyScreenExt::setFont(const tFont &font)
{
    // get the first char
    tChar c = font.chars[0];
    _fontFirstCh = c.code;

    // get the height
    _fontHeight = c.image->height;

    // get the last char
    c = font.chars[font.length - 1];
    _fontLastCh = c.code;

    // get the chars
    _fontChars = font.chars;
}

// Set the Font color (Will have to do something here to support anti aliasing)
void TinyScreenExt::fontColor(uint16_t f, uint16_t g)
{
    _display.fontColor(f, g);
}

//returns height of font
uint8_t TinyScreenExt::getFontHeight(const tFont &font)
{
    // get the first char
    tChar c = font.chars[0];

    // get the height
    uint8_t result = c.image->height;
    return result;
}

//returns height of the current font
uint8_t TinyScreenExt::getFontHeight()
{
    return _fontHeight;
}

// gets the total printed width
uint8_t TinyScreenExt::getPrintWidth(char *st)
{
    if (!_fontFirstCh)
    {
        return 0;
    }

    uint8_t result = 0;
    uint8_t length = strlen(st);
    for (uint8_t i = 0; i < length; i++)
    {
        tChar c = _fontChars[st[i] - _fontFirstCh];
        result += (c.image->width) + 1;
    }

    return result;
}

// prints the given char * at the given x, y on the display
tPoint TinyScreenExt::printAt(uint8_t x, uint8_t y, char *str)
{
    tPoint result = {x, y};

    setCursor(x, y);
    print(str);

    result.x += getPrintWidth(str);
    result.y += getFontHeight();

    return result;
}

// prints the given text vertically on the display
// at the given x, y.
tPoint TinyScreenExt::printVerticalAt(uint8_t x, uint8_t y, char *str)
{
    char buffer[2];

    tPoint result = {x, y};

    for (int i = 0; i < strlen(str); i++)
    {
        buffer[0] = str[i];
        buffer[1] = '\0';

        // print the char and move the next
        // print position to one pixel lower
        tPoint endPoint = printAt(x, result.y, buffer);
        result.y = (1 + endPoint.y);

        // check the maximum width of the characters
        // printed so far
        if (endPoint.x > result.x)
        {
            result.x = endPoint.x;
        }
    }

    return result;
}

// prints the given text centered on the display
// at the given y. If the given string is too large
// then it is printed at column 0
tPoint TinyScreenExt::printCenteredAt(uint8_t y, char *str)
{
    uint8_t width = getPrintWidth(str);
    int x = (xMax - width) / 2;
    if (x < 0)
    {
        x = 0;
    }

    tPoint result = printAt(x, y, str);
    return result;
}

// perform the write of a given character
size_t TinyScreenExt::write(uint8_t ch)
{
    // check that a font has been set
    if (!_fontFirstCh)
    {
        return 1;
    }

    if (ch == '\n')
    {
        _cursorY += _fontHeight;
        return 1;
    }

    if (ch == '\r')
    {
        _cursorX = 0;
        return 1;
    }

    // check that the char to be written is in the range
    if (ch < _fontFirstCh || ch > _fontLastCh)
    {
        return 1;
    }

    // check if we are drawing off the screen
    if (_cursorX > _display.xMax || _cursorY > _display.yMax)
    {
        return 1;
    }

    // get the image to be drawn
    const tImage *image = _fontChars[ch - _fontFirstCh].image;

    // draw the image for the character
    tPoint pos = drawImageAt(_cursorX, _cursorY, image);
    _cursorX += (image->width + 1);
    return 1;
}

// hardware (buttons battery, etc.)

// get the state of all the buttons
uint8_t TinyScreenExt::getButtons(void)
{
    return _display.getButtons();
}

// Get the battery voltage as a scaled value
// between 0 to 10
uint8_t TinyScreenExt::getBatteryState()
{
    return _battery.getState();
}

// Get the battery voltage
float TinyScreenExt::getVoltage(void)
{
    return _battery.getVoltage();
}

// drawing methods
void TinyScreenExt::clearScreen()
{
    _display.clearScreen();
}

//sets specified OLED controller memory to an 8/16 bit color, fill is a boolean
void TinyScreenExt::drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t f, uint16_t color)
{
    _display.drawRect(x, y, w, h, f, color);
}

//draw a line from (x1,y1) to (x2,y2) with an 8 bit color
void TinyScreenExt::drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t color)
{
    _display.drawLine(x0, y0, x1, y1, color);
}

// draw the given image at (x,y)
tPoint TinyScreenExt::drawImageAt(uint8_t x, uint8_t y, const tImage *image)
{
    uint8_t endx = x + image->width;
    _display.setX(x, endx - 1);
    uint8_t endy = y + image->height;
    _display.setY(y, endy - 1);

    //now start a data transfer
    _display.startData();
    _display.writeBuffer(image->data, image->width * image->height);
    _display.endTransfer();

    tPoint result = {endx, endy};
    return result;
}
