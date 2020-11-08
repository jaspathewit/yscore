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

#ifndef TinyScreenExt_font_h
#define TinyScreenExt_font_h

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

#endif
