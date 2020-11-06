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

#include <avr/pgmspace.h>
#include <TinyScreen.h>

#include "TinyScreenBattery.h"

#ifndef TinyScreenExt_h
#define TinyScreenExt_h

// macros from DateTime.h
/* Useful Constants */
#define SECS_PER_MIN (60UL)
#define SECS_PER_HOUR (3600UL)
#define SECS_PER_DAY (SECS_PER_HOUR * 24L)

/* Useful Macros for getting elapsed time */
#define numberOfSeconds(_time_) (_time_ % SECS_PER_MIN)
#define numberOfMinutes(_time_) ((_time_ / SECS_PER_MIN) % SECS_PER_MIN)
#define numberOfHours(_time_) ((_time_ % SECS_PER_DAY) / SECS_PER_HOUR)
#define elapsedDays(_time_) (_time_ / SECS_PER_DAY)

// type used by all "drawing" commands to be able to return the x,y coordinates
// after the drawing has completed
typedef struct
{
     uint8_t x;
     uint8_t y;
} tPoint;

// type defining images that can be drawn to the TinyScreen
typedef struct
{
     const uint8_t *data;
     const uint8_t width;
     const uint8_t height;
     const uint8_t dataSize;
} tImage;

// type used to define a char in the font table
typedef struct
{
     long int code;
     const tImage *image;
} tChar;

// type used to define a font
typedef struct
{
     int length;
     const tChar *chars;
} tFont;

// Class provides an extension to the TinyScreen class.
class TinyScreenExt : public Print
{
public:
     TinyScreenExt(uint8_t type);

     void begin(void);
     void setFlip(uint8_t flip);
     void setBrightness(uint8_t);

     // hardware Buttons
     uint8_t getButtons(void);

     // hardware battery
     uint8_t getBatteryState();
     float getVoltage();

     // Anti aliased Font handeling
     void setFont(const tFont &);
     uint8_t getFontHeight(const tFont &);
     uint8_t getFontHeight(void);
     uint8_t getPrintWidth(char *);
     void setCursor(uint8_t, uint8_t);
     void fontColor(uint16_t, uint16_t);
     tPoint printAt(uint8_t x, uint8_t y, char *str);
     tPoint printCenteredAt(uint8_t y, char *str);
     tPoint printVerticalAt(uint8_t x, uint8_t y, char *str);
     virtual size_t write(uint8_t);

     //drawing commands
     //   void drawLine(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
     void drawLine(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);
     //   void drawRect(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
     void drawRect(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);
     //   void clearWindow(uint8_t, uint8_t, uint8_t, uint8_t);
     tPoint drawImageAt(uint8_t x, uint8_t y, const tImage *image);
     void clearScreen(void);

     // Utility debug methods
     void printDebug(char *buffer);
     // prints debug info
     void printDebug(uint32_t number);

     static const uint8_t xMin = 0;
     static const uint8_t yMin = 0;
     static const uint8_t xMax = 95;
     static const uint8_t yMax = 63;

private:
     TinyScreen _display = 0;
     TinyScreenBattery _battery;

     // info about the _display
     uint8_t _cursorX, _cursorY;

     // info about the current font
     uint8_t _fontHeight, _fontFirstCh, _fontLastCh;
     int _fontLength;
     const tChar *_fontChars;
};

#endif