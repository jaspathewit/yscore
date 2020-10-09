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

/* 

Copyright (C) 2004 by Matthew Welch

Permission is hereby granted, free of charge, to any person obtaining a copy of
this font software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

/* 
**  Font data for Tiny 4pt
*/

/* Character bitmaps for Tiny 4pt */
static const unsigned char PROGMEM tiny_4ptBitmaps[] =
	{
		/* @0 ' ' (4 pixels wide) */
		//
		//
		//
		//
		0x00,
		0x00,
		0x00,
		0x00,

		/* @4 '!' (1 pixels wide) */
		//  # #
		0x00,
		0x80,
		0x00,
		0x80,

		/* @8 '"' (3 pixels wide) */
		//    #
		//
		//    #
		0x00,
		0x00,
		0x00,
		0xA0,

		/* @12 '#' (4 pixels wide) */
		//  # #
		// ####
		// ####
		//  # #
		0x60,
		0xF0,
		0x60,
		0xF0,

		/* @16 '$' (3 pixels wide) */
		//  # #
		// ####
		//  # #
		0x40,
		0xE0,
		0x40,
		0xE0,

		/* @20 '%' (3 pixels wide) */
		//  # #
		//   #
		//  # #
		0x00,
		0xA0,
		0x40,
		0xA0,

		/* @24 '&' (3 pixels wide) */
		//   #
		//  # #
		//  ###
		0x00,
		0x60,
		0xA0,
		0x60,

		/* @28 ''' (1 pixels wide) */
		//    #
		0x00,
		0x00,
		0x00,
		0x80,

		/* @32 '(' (2 pixels wide) */
		//  ###
		// #  #
		0x40,
		0x80,
		0x80,
		0xC0,

		/* @36 ')' (2 pixels wide) */
		// #  #
		//  ###
		0x80,
		0x40,
		0x40,
		0xC0,

		/* @40 '*' (3 pixels wide) */
		//   ##
		//    #
		//   ##
		0x00,
		0x00,
		0xA0,
		0xE0,

		/* @44 '+' (3 pixels wide) */
		//   #
		//  ###
		//   #
		0x00,
		0x40,
		0xE0,
		0x40,

		/* @48 ',' (1 pixels wide) */
		// ##
		0x80,
		0x80,
		0x00,
		0x00,

		/* @52 '-' (3 pixels wide) */
		//   #
		//   #
		//   #
		0x00,
		0x00,
		0xE0,
		0x00,

		/* @56 '.' (1 pixels wide) */
		//  #
		0x00,
		0x80,
		0x00,
		0x00,

		/* @60 '/' (3 pixels wide) */
		//  #
		//   #
		//    #
		0x00,
		0x80,
		0x40,
		0x20,

		/* @64 '0' (3 pixels wide) */
		//   ##
		//  # #
		//   ##
		0x00,
		0x40,
		0xA0,
		0xE0,

		/* @68 '1' (3 pixels wide) */
		//  # #
		//  ###
		//  #
		0x00,
		0xE0,
		0x40,
		0xC0,

		/* @72 '2' (3 pixels wide) */
		//  ###
		//  # #
		//  # #
		0x00,
		0xE0,
		0x80,
		0xE0,

		/* @76 '3' (3 pixels wide) */
		//  # #
		//  # #
		//   ##
		0x00,
		0xC0,
		0x20,
		0xE0,

		/* @80 '4' (3 pixels wide) */
		//   ##
		//   #
		//  ###
		0x00,
		0x20,
		0xE0,
		0xA0,

		/* @84 '5' (3 pixels wide) */
		//  # #
		//  # #
		//   ##
		0x00,
		0xC0,
		0x20,
		0xE0,

		/* @88 '6' (3 pixels wide) */
		//  ###
		//  ###
		//  ###
		0x00,
		0xE0,
		0xE0,
		0xE0,

		/* @92 '7' (3 pixels wide) */
		//  # #
		//   ##
		//    #
		0x00,
		0x80,
		0x40,
		0xE0,

		/* @96 '8' (3 pixels wide) */
		//   ##
		//  # #
		//   ##
		0x00,
		0x40,
		0xA0,
		0xE0,

		/* @100 '9' (3 pixels wide) */
		//   ##
		//   ##
		//  ###
		0x00,
		0x20,
		0xE0,
		0xE0,

		/* @104 ':' (1 pixels wide) */
		//  # #
		0x00,
		0x80,
		0x00,
		0x80,

		/* @108 ';' (1 pixels wide) */
		// ## #
		0x80,
		0x80,
		0x00,
		0x80,

		/* @112 '<' (3 pixels wide) */
		//   #
		//  # #
		// #  #
		0x20,
		0x40,
		0x80,
		0x60,

		/* @116 '=' (3 pixels wide) */
		//  # #
		//  # #
		//  # #
		0x00,
		0xE0,
		0x00,
		0xE0,

		/* @120 '>' (3 pixels wide) */
		// #  #
		//  # #
		//   #
		0x80,
		0x40,
		0x20,
		0xC0,

		/* @124 '?' (3 pixels wide) */
		//    #
		//  # #
		//    #
		0x00,
		0x40,
		0x00,
		0xE0,

		/* @128 '@' (3 pixels wide) */
		//   ##
		//  # #
		//  # #
		0x00,
		0x60,
		0x80,
		0xE0,

		/* @132 'A' (3 pixels wide) */
		//  ###
		//   ##
		//  ###
		0x00,
		0xA0,
		0xE0,
		0xE0,

		/* @136 'B' (3 pixels wide) */
		//  ###
		//  # #
		//   ##
		0x00,
		0xC0,
		0xA0,
		0xE0,

		/* @140 'C' (3 pixels wide) */
		//   ##
		//  # #
		//  # #
		0x00,
		0x60,
		0x80,
		0xE0,

		/* @144 'D' (3 pixels wide) */
		//  ###
		//  # #
		//   ##
		0x00,
		0xC0,
		0xA0,
		0xE0,

		/* @148 'E' (3 pixels wide) */
		//  ###
		//  # #
		//  # #
		0x00,
		0xE0,
		0x80,
		0xE0,

		/* @152 'F' (3 pixels wide) */
		//  ###
		//   ##
		//    #
		0x00,
		0x80,
		0xC0,
		0xE0,

		/* @156 'G' (3 pixels wide) */
		//   ##
		//  # #
		//  ###
		0x00,
		0x60,
		0xA0,
		0xE0,

		/* @160 'H' (3 pixels wide) */
		//  ###
		//   #
		//  ###
		0x00,
		0xA0,
		0xE0,
		0xA0,

		/* @164 'I' (3 pixels wide) */
		//  # #
		//  ###
		//  # #
		0x00,
		0xE0,
		0x40,
		0xE0,

		/* @168 'J' (3 pixels wide) */
		//   #
		//  #
		//   ##
		0x00,
		0x40,
		0xA0,
		0x20,

		/* @172 'K' (3 pixels wide) */
		//  ###
		//   #
		//  ###
		0x00,
		0xA0,
		0xE0,
		0xA0,

		/* @176 'L' (3 pixels wide) */
		//  ###
		//  #
		//  #
		0x00,
		0xE0,
		0x80,
		0x80,

		/* @180 'M' (4 pixels wide) */
		//  ###
		//    #
		//   ##
		//  ###
		0x00,
		0x90,
		0xB0,
		0xF0,

		/* @184 'N' (3 pixels wide) */
		//  ###
		//    #
		//  ###
		0x00,
		0xA0,
		0xA0,
		0xE0,

		/* @188 'O' (3 pixels wide) */
		//   ##
		//  # #
		//  ###
		0x00,
		0x60,
		0xA0,
		0xE0,

		/* @192 'P' (3 pixels wide) */
		//  ###
		//   ##
		//    #
		0x00,
		0x80,
		0xC0,
		0xE0,

		/* @196 'Q' (3 pixels wide) */
		//   ##
		//  # #
		// ####
		0x20,
		0x60,
		0xA0,
		0xE0,

		/* @200 'R' (3 pixels wide) */
		//  ###
		//   ##
		//  # #
		0x00,
		0xA0,
		0xC0,
		0xE0,

		/* @204 'S' (3 pixels wide) */
		//  # #
		//  # #
		//   ##
		0x00,
		0xC0,
		0x20,
		0xE0,

		/* @208 'T' (3 pixels wide) */
		//    #
		//  ###
		//    #
		0x00,
		0x40,
		0x40,
		0xE0,

		/* @212 'U' (3 pixels wide) */
		//   ##
		//  #
		//  ###
		0x00,
		0x60,
		0xA0,
		0xA0,

		/* @216 'V' (4 pixels wide) */
		//    #
		//   #
		//  ##
		//    #
		0x00,
		0x20,
		0x60,
		0x90,

		/* @220 'W' (4 pixels wide) */
		//   ##
		//  #
		//  ###
		//   ##
		0x00,
		0x60,
		0xB0,
		0xB0,

		/* @224 'X' (3 pixels wide) */
		//  ###
		//    #
		//  ###
		0x00,
		0xA0,
		0xA0,
		0xE0,

		/* @228 'Y' (4 pixels wide) */
		//    #
		//    #
		//  ###
		//    #
		0x00,
		0x20,
		0x20,
		0xF0,

		/* @232 'Z' (3 pixels wide) */
		//  # #
		//  ###
		//  # #
		0x00,
		0xE0,
		0x40,
		0xE0,

		/* @236 '[' (2 pixels wide) */
		// ####
		// #  #
		0xC0,
		0x80,
		0x80,
		0xC0,

		/* @240 '\' (3 pixels wide) */
		//    #
		//    #
		//  ##
		0x00,
		0x20,
		0x20,
		0xC0,

		/* @244 ']' (2 pixels wide) */
		// #  #
		// ####
		0xC0,
		0x40,
		0x40,
		0xC0,

		/* @248 '^' (3 pixels wide) */
		//    #
		//    #
		//    #
		0x00,
		0x00,
		0x00,
		0xE0,

		/* @252 '_' (3 pixels wide) */
		// #
		// #
		// #
		0xE0,
		0x00,
		0x00,
		0x00,

		/* @256 '`' (2 pixels wide) */
		//    #
		//    #
		0x00,
		0x00,
		0x00,
		0xC0,

		/* @260 'a' (3 pixels wide) */
		//   #
		//  # #
		//  ###
		0x00,
		0x60,
		0xA0,
		0x60,

		/* @264 'b' (3 pixels wide) */
		//  ###
		//  # #
		//   #
		0x00,
		0xC0,
		0xA0,
		0xC0,

		/* @268 'c' (3 pixels wide) */
		//   #
		//  # #
		//  # #
		0x00,
		0x60,
		0x80,
		0x60,

		/* @272 'd' (3 pixels wide) */
		//   #
		//  # #
		//  ###
		0x00,
		0x60,
		0xA0,
		0x60,

		/* @276 'e' (3 pixels wide) */
		//   #
		//  ###
		//  # #
		0x00,
		0x60,
		0xC0,
		0x60,

		/* @280 'f' (2 pixels wide) */
		//  ###
		//   ##
		0x00,
		0x80,
		0xC0,
		0xC0,

		/* @284 'g' (2 pixels wide) */
		// # ##
		// ####
		0xC0,
		0x40,
		0xC0,
		0xC0,

		/* @288 'h' (3 pixels wide) */
		//  ###
		//    #
		//  ##
		0x00,
		0xA0,
		0xA0,
		0xC0,

		/* @292 'i' (1 pixels wide) */
		//  ###
		0x00,
		0x80,
		0x80,
		0x80,

		/* @296 'j' (1 pixels wide) */
		// ####
		0x80,
		0x80,
		0x80,
		0x80,

		/* @300 'k' (3 pixels wide) */
		//  ###
		//   #
		//  # #
		0x00,
		0xA0,
		0xC0,
		0xA0,

		/* @304 'l' (1 pixels wide) */
		//  ###
		0x00,
		0x80,
		0x80,
		0x80,

		/* @308 'm' (4 pixels wide) */
		//  ###
		//    #
		//  ###
		//  ##
		0x00,
		0xB0,
		0xB0,
		0xE0,

		/* @312 'n' (3 pixels wide) */
		//  ###
		//    #
		//  ##
		0x00,
		0xA0,
		0xA0,
		0xC0,

		/* @316 'o' (3 pixels wide) */
		//   #
		//  # #
		//   #
		0x00,
		0x40,
		0xA0,
		0x40,

		/* @320 'p' (3 pixels wide) */
		// ####
		//  # #
		//   #
		0x80,
		0xC0,
		0xA0,
		0xC0,

		/* @324 'q' (3 pixels wide) */
		//   #
		//  # #
		// ####
		0x20,
		0x60,
		0xA0,
		0x60,

		/* @328 'r' (2 pixels wide) */
		//  ###
		//    #
		0x00,
		0x80,
		0x80,
		0xC0,

		/* @332 's' (3 pixels wide) */
		//  #
		//  ###
		//    #
		0x00,
		0xC0,
		0x40,
		0x60,

		/* @336 't' (3 pixels wide) */
		//    #
		//  ###
		//    #
		0x00,
		0x40,
		0x40,
		0xE0,

		/* @340 'u' (3 pixels wide) */
		//   ##
		//  #
		//  ###
		0x00,
		0x60,
		0xA0,
		0xA0,

		/* @344 'v' (3 pixels wide) */
		//   ##
		//  #
		//   ##
		0x00,
		0x40,
		0xA0,
		0xA0,

		/* @348 'w' (4 pixels wide) */
		//   ##
		//  #
		//  ##
		//   ##
		0x00,
		0x60,
		0xB0,
		0x90,

		/* @352 'x' (3 pixels wide) */
		//  # #
		//   #
		//  # #
		0x00,
		0xA0,
		0x40,
		0xA0,

		/* @356 'y' (3 pixels wide) */
		// # ##
		// # #
		//  ###
		0xC0,
		0x20,
		0xE0,
		0xA0,

		/* @360 'z' (3 pixels wide) */
		//  # #
		//  ###
		//  # #
		0x00,
		0xE0,
		0x40,
		0xE0,

		/* @364 '{' (3 pixels wide) */
		//   #
		// ####
		// #  #
		0x60,
		0x40,
		0xC0,
		0x60,

		/* @368 '|' (1 pixels wide) */
		// ####
		0x80,
		0x80,
		0x80,
		0x80,

		/* @372 '}' (3 pixels wide) */
		// #  #
		// ####
		//   #
		0xC0,
		0x40,
		0x60,
		0xC0,

		/* @376 '~' (3 pixels wide) */
		//    #
		//    #
		//    #
		0x00,
		0x00,
		0x00,
		0xE0,
};

/* Character descriptors for Tiny 4pt */
/* { [Char width in bits], [Offset into tiny_4ptCharBitmaps in bytes] } */
static const FONT_CHAR_INFO PROGMEM tiny_4ptDescriptors[] =
	{
		{4, 0},	  /*   */
		{1, 4},	  /* ! */
		{3, 8},	  /* " */
		{4, 12},  /* # */
		{3, 16},  /* $ */
		{3, 20},  /* % */
		{3, 24},  /* & */
		{1, 28},  /* ' */
		{2, 32},  /* ( */
		{2, 36},  /* ) */
		{3, 40},  /* * */
		{3, 44},  /* + */
		{1, 48},  /* , */
		{3, 52},  /* - */
		{1, 56},  /* . */
		{3, 60},  /* / */
		{3, 64},  /* 0 */
		{3, 68},  /* 1 */
		{3, 72},  /* 2 */
		{3, 76},  /* 3 */
		{3, 80},  /* 4 */
		{3, 84},  /* 5 */
		{3, 88},  /* 6 */
		{3, 92},  /* 7 */
		{3, 96},  /* 8 */
		{3, 100}, /* 9 */
		{1, 104}, /* : */
		{1, 108}, /* ; */
		{3, 112}, /* < */
		{3, 116}, /* = */
		{3, 120}, /* > */
		{3, 124}, /* ? */
		{3, 128}, /* @ */
		{3, 132}, /* A */
		{3, 136}, /* B */
		{3, 140}, /* C */
		{3, 144}, /* D */
		{3, 148}, /* E */
		{3, 152}, /* F */
		{3, 156}, /* G */
		{3, 160}, /* H */
		{3, 164}, /* I */
		{3, 168}, /* J */
		{3, 172}, /* K */
		{3, 176}, /* L */
		{4, 180}, /* M */
		{3, 184}, /* N */
		{3, 188}, /* O */
		{3, 192}, /* P */
		{3, 196}, /* Q */
		{3, 200}, /* R */
		{3, 204}, /* S */
		{3, 208}, /* T */
		{3, 212}, /* U */
		{4, 216}, /* V */
		{4, 220}, /* W */
		{3, 224}, /* X */
		{4, 228}, /* Y */
		{3, 232}, /* Z */
		{2, 236}, /* [ */
		{3, 240}, /* \ */
		{2, 244}, /* ] */
		{3, 248}, /* ^ */
		{3, 252}, /* _ */
		{2, 256}, /* ` */
		{3, 260}, /* a */
		{3, 264}, /* b */
		{3, 268}, /* c */
		{3, 272}, /* d */
		{3, 276}, /* e */
		{2, 280}, /* f */
		{2, 284}, /* g */
		{3, 288}, /* h */
		{1, 292}, /* i */
		{1, 296}, /* j */
		{3, 300}, /* k */
		{1, 304}, /* l */
		{4, 308}, /* m */
		{3, 312}, /* n */
		{3, 316}, /* o */
		{3, 320}, /* p */
		{3, 324}, /* q */
		{2, 328}, /* r */
		{3, 332}, /* s */
		{3, 336}, /* t */
		{3, 340}, /* u */
		{3, 344}, /* v */
		{4, 348}, /* w */
		{3, 352}, /* x */
		{3, 356}, /* y */
		{3, 360}, /* z */
		{3, 364}, /* { */
		{1, 368}, /* | */
		{3, 372}, /* } */
		{3, 376}, /* ~ */
};

/* Font information for Tiny 4pt */
static const FONT_INFO tiny_4ptFontInfo =
	{
		4,					 /*  Character height */
		' ',				 /*  Start character */
		'~',				 /*  End character */
		tiny_4ptDescriptors, /*  Character descriptor array */
		tiny_4ptBitmaps,	 /*  Character bitmap array */
};

/* Font data for Tiny 4pt */
// extern static const unsigned char PROGMEM tiny_4ptBitmaps[];
// extern static const FONT_INFO tiny_4ptFontInfo;
// extern static const FONT_CHAR_INFO PROGMEM tiny_4ptDescriptors[];

/* 
**  Font data for Tiny 6pt
*/

/* Character bitmaps for Tiny 6pt */
static const unsigned char PROGMEM tiny_6ptBitmaps[] =
	{
		/* @0 ' ' (4 pixels wide) */
		//
		//
		//
		//
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @6 '!' (1 pixels wide) */
		//  #  ##
		0x00,
		0x80,
		0x00,
		0x00,
		0x80,
		0x80,

		/* @12 '"' (4 pixels wide) */
		//     ##
		//
		//
		//     ##
		0x00,
		0x00,
		0x00,
		0x00,
		0x90,
		0x90,

		/* @18 '#' (7 pixels wide) */
		//  #  #
		// ######
		// ######
		//  #  #
		// ######
		//  #  #
		//  #  #
		0x68,
		0xFE,
		0x68,
		0x68,
		0xFE,
		0x68,

		/* @24 '$' (4 pixels wide) */
		//  #  #
		// ######
		// ######
		//  #  #
		0x60,
		0xF0,
		0x60,
		0x60,
		0xF0,
		0x60,

		/* @30 '%' (5 pixels wide) */
		//  #   #
		//   ##
		//   ##
		//     #
		//  #   #
		0x00,
		0x88,
		0x60,
		0x60,
		0x10,
		0x88,

		/* @36 '&' (5 pixels wide) */
		//   ##
		//  #  ##
		//  #  ##
		//  #   #
		//   ##
		0x00,
		0x70,
		0x88,
		0x88,
		0x60,
		0x70,

		/* @42 ''' (1 pixels wide) */
		//     ##
		0x00,
		0x00,
		0x00,
		0x00,
		0x80,
		0x80,

		/* @48 '(' (3 pixels wide) */
		//  ####
		// #    #
		// #    #
		0x60,
		0x80,
		0x80,
		0x80,
		0x80,
		0x60,

		/* @54 ')' (3 pixels wide) */
		// #    #
		//  ####
		//  ####
		0x80,
		0x60,
		0x60,
		0x60,
		0x60,
		0x80,

		/* @60 '*' (4 pixels wide) */
		//   ## #
		//     #
		//     #
		//   ## #
		0x00,
		0x00,
		0x90,
		0x90,
		0x60,
		0x90,

		/* @66 '+' (4 pixels wide) */
		//   ##
		//  ####
		//  ####
		//   ##
		0x00,
		0x60,
		0xF0,
		0xF0,
		0x60,
		0x00,

		/* @72 ',' (1 pixels wide) */
		// ##
		0x80,
		0x80,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @78 '-' (4 pixels wide) */
		//   ##
		//   ##
		//   ##
		//   ##
		0x00,
		0x00,
		0xF0,
		0xF0,
		0x00,
		0x00,

		/* @84 '.' (1 pixels wide) */
		//  #
		0x00,
		0x80,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @90 '/' (5 pixels wide) */
		//  #
		//   ##
		//   ##
		//     #
		//      #
		0x00,
		0x80,
		0x60,
		0x60,
		0x10,
		0x08,

		/* @96 '0' (4 pixels wide) */
		//   ###
		//  #   #
		//  #   #
		//   ###
		0x00,
		0x60,
		0x90,
		0x90,
		0x90,
		0x60,

		/* @102 '1' (4 pixels wide) */
		//  #  #
		//  #####
		//  #####
		//  #
		0x00,
		0xF0,
		0x60,
		0x60,
		0xE0,
		0x60,

		/* @108 '2' (4 pixels wide) */
		//  ### #
		//  #   #
		//  #   #
		//  #  #
		0x00,
		0xF0,
		0x80,
		0x80,
		0x10,
		0xE0,

		/* @114 '3' (4 pixels wide) */
		//  #   #
		//  #  ##
		//  #  ##
		//   ###
		0x00,
		0xE0,
		0x10,
		0x10,
		0x70,
		0xE0,

		/* @120 '4' (4 pixels wide) */
		//   ###
		//   ##
		//   ##
		//  #####
		0x00,
		0x10,
		0xF0,
		0xF0,
		0x90,
		0x10,

		/* @126 '5' (4 pixels wide) */
		//  #  ##
		//  #   #
		//  #   #
		//   ## #
		0x00,
		0xE0,
		0x10,
		0x10,
		0x80,
		0xF0,

		/* @132 '6' (4 pixels wide) */
		//  ####
		//  ### #
		//  ### #
		//  ### #
		0x00,
		0xF0,
		0xF0,
		0xF0,
		0x80,
		0x70,

		/* @138 '7' (4 pixels wide) */
		//  #   #
		//   ## #
		//   ## #
		//     ##
		0x00,
		0x80,
		0x60,
		0x60,
		0x10,
		0xF0,

		/* @144 '8' (4 pixels wide) */
		//   ###
		//  #  ##
		//  #  ##
		//   ###
		0x00,
		0x60,
		0x90,
		0x90,
		0xF0,
		0x60,

		/* @150 '9' (4 pixels wide) */
		//   ###
		//   ## #
		//   ## #
		//  #####
		0x00,
		0x10,
		0xF0,
		0xF0,
		0x90,
		0x70,

		/* @156 ':' (1 pixels wide) */
		//  #  #
		0x00,
		0x80,
		0x00,
		0x00,
		0x80,
		0x00,

		/* @162 ';' (1 pixels wide) */
		// ##  #
		0x80,
		0x80,
		0x00,
		0x00,
		0x80,
		0x00,

		/* @168 '<' (4 pixels wide) */
		//   ##
		//  #  #
		//  #  #
		// #    #
		0x10,
		0x60,
		0x80,
		0x80,
		0x60,
		0x10,

		/* @174 '=' (4 pixels wide) */
		//  #  #
		//  #  #
		//  #  #
		//  #  #
		0x00,
		0xF0,
		0x00,
		0x00,
		0xF0,
		0x00,

		/* @180 '>' (4 pixels wide) */
		// #    #
		//  #  #
		//  #  #
		//   ##
		0x80,
		0x60,
		0x10,
		0x10,
		0x60,
		0x80,

		/* @186 '?' (4 pixels wide) */
		//      #
		//  #   #
		//  #   #
		//     #
		0x00,
		0x60,
		0x00,
		0x00,
		0x10,
		0xE0,

		/* @192 '@' (4 pixels wide) */
		//   ###
		//  #   #
		//  #   #
		//  #  ##
		0x00,
		0x70,
		0x80,
		0x80,
		0x90,
		0x70,

		/* @198 'A' (4 pixels wide) */
		//  ####
		//   ## #
		//   ## #
		//  ####
		0x00,
		0x90,
		0xF0,
		0xF0,
		0x90,
		0x60,

		/* @204 'B' (4 pixels wide) */
		//  #####
		//  #  ##
		//  #  ##
		//   ###
		0x00,
		0xE0,
		0x90,
		0x90,
		0xF0,
		0xE0,

		/* @210 'C' (4 pixels wide) */
		//   ###
		//  #   #
		//  #   #
		//  #   #
		0x00,
		0x70,
		0x80,
		0x80,
		0x80,
		0x70,

		/* @216 'D' (4 pixels wide) */
		//  #####
		//  #   #
		//  #   #
		//   ###
		0x00,
		0xE0,
		0x90,
		0x90,
		0x90,
		0xE0,

		/* @222 'E' (4 pixels wide) */
		//  #####
		//  #  ##
		//  #  ##
		//  #   #
		0x00,
		0xF0,
		0x80,
		0x80,
		0xE0,
		0xF0,

		/* @228 'F' (4 pixels wide) */
		//  #####
		//   ## #
		//   ## #
		//      #
		0x00,
		0x80,
		0xE0,
		0xE0,
		0x80,
		0xF0,

		/* @234 'G' (4 pixels wide) */
		//   ###
		//  #   #
		//  #   #
		//  ### #
		0x00,
		0x70,
		0x90,
		0x90,
		0x80,
		0x70,

		/* @240 'H' (4 pixels wide) */
		//  #####
		//   ##
		//   ##
		//  #####
		0x00,
		0x90,
		0xF0,
		0xF0,
		0x90,
		0x90,

		/* @246 'I' (4 pixels wide) */
		//  #   #
		//  #####
		//  #####
		//  #   #
		0x00,
		0xF0,
		0x60,
		0x60,
		0x60,
		0xF0,

		/* @252 'J' (4 pixels wide) */
		//   ##
		//  #
		//  #
		//   ####
		0x00,
		0x60,
		0x90,
		0x90,
		0x10,
		0x10,

		/* @258 'K' (5 pixels wide) */
		//  #####
		//   ##
		//   ##
		//   ###
		//  #   #
		0x00,
		0x88,
		0xF0,
		0xF0,
		0x90,
		0x88,

		/* @264 'L' (4 pixels wide) */
		//  #####
		//  #
		//  #
		//  #
		0x00,
		0xF0,
		0x80,
		0x80,
		0x80,
		0x80,

		/* @270 'M' (7 pixels wide) */
		//  #####
		//     #
		//     #
		//   ##
		//     #
		//  #####
		//  #####
		0x00,
		0x86,
		0x96,
		0x96,
		0xEE,
		0x86,

		/* @276 'N' (5 pixels wide) */
		//  #####
		//     #
		//     #
		//   ##
		//  #####
		0x00,
		0x88,
		0x98,
		0x98,
		0xE8,
		0x88,

		/* @282 'O' (5 pixels wide) */
		//   ###
		//  #   #
		//  #   #
		//  #   #
		//   ###
		0x00,
		0x70,
		0x88,
		0x88,
		0x88,
		0x70,

		/* @288 'P' (4 pixels wide) */
		//  #####
		//   ## #
		//   ## #
		//     #
		0x00,
		0x80,
		0xE0,
		0xE0,
		0x90,
		0xE0,

		/* @294 'Q' (5 pixels wide) */
		//   ###
		//  #   #
		//  #   #
		// ##   #
		//   ###
		0x10,
		0x70,
		0x88,
		0x88,
		0x88,
		0x70,

		/* @300 'R' (4 pixels wide) */
		//  #####
		//   ## #
		//   ## #
		//  #  #
		0x00,
		0x90,
		0xE0,
		0xE0,
		0x90,
		0xE0,

		/* @306 'S' (4 pixels wide) */
		//  #  #
		//  #   #
		//  #   #
		//   ## #
		0x00,
		0xE0,
		0x10,
		0x10,
		0x80,
		0x70,

		/* @312 'T' (4 pixels wide) */
		//      #
		//  #####
		//  #####
		//      #
		0x00,
		0x60,
		0x60,
		0x60,
		0x60,
		0xF0,

		/* @318 'U' (5 pixels wide) */
		//   ####
		//  #
		//  #
		//  #
		//   ####
		0x00,
		0x70,
		0x88,
		0x88,
		0x88,
		0x88,

		/* @324 'V' (7 pixels wide) */
		//     ##
		//   ##
		//   ##
		//  #
		//   ##
		//     ##
		//     ##
		0x00,
		0x10,
		0x68,
		0x68,
		0x86,
		0x86,

		/* @330 'W' (7 pixels wide) */
		//   ####
		//  #
		//  #
		//   ###
		//  #
		//   ####
		//   ####
		0x00,
		0x68,
		0x96,
		0x96,
		0x96,
		0x86,

		/* @336 'X' (4 pixels wide) */
		//  ### #
		//     #
		//     #
		//  ### #
		0x00,
		0x90,
		0x90,
		0x90,
		0x60,
		0x90,

		/* @342 'Y' (7 pixels wide) */
		//      #
		//     #
		//     #
		//  ###
		//     #
		//      #
		//      #
		0x00,
		0x10,
		0x10,
		0x10,
		0x68,
		0x86,

		/* @348 'Z' (5 pixels wide) */
		//  #   #
		//  ### #
		//  ### #
		//  #  ##
		//  #   #
		0x00,
		0xF8,
		0x60,
		0x60,
		0x10,
		0xF8,

		/* @354 '[' (3 pixels wide) */
		// ######
		// #    #
		// #    #
		0xE0,
		0x80,
		0x80,
		0x80,
		0x80,
		0xE0,

		/* @360 '\' (5 pixels wide) */
		//      #
		//     #
		//     #
		//   ##
		//  #
		0x00,
		0x08,
		0x10,
		0x10,
		0x60,
		0x80,

		/* @366 ']' (3 pixels wide) */
		// #    #
		// ######
		// ######
		0xE0,
		0x60,
		0x60,
		0x60,
		0x60,
		0xE0,

		/* @372 '^' (4 pixels wide) */
		//     #
		//      #
		//      #
		//     #
		0x00,
		0x00,
		0x00,
		0x00,
		0x90,
		0x60,

		/* @378 '_' (4 pixels wide) */
		// #
		// #
		// #
		// #
		0xF0,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @384 '`' (3 pixels wide) */
		//      #
		//     #
		//     #
		0x00,
		0x00,
		0x00,
		0x00,
		0x60,
		0x80,

		/* @390 'a' (4 pixels wide) */
		//   ##
		//  #  #
		//  #  #
		//  ####
		0x00,
		0x70,
		0x90,
		0x90,
		0x70,
		0x00,

		/* @396 'b' (4 pixels wide) */
		//  #####
		//  #  #
		//  #  #
		//   ##
		0x00,
		0xE0,
		0x90,
		0x90,
		0xE0,
		0x80,

		/* @402 'c' (4 pixels wide) */
		//   ##
		//  #  #
		//  #  #
		//  #  #
		0x00,
		0x70,
		0x80,
		0x80,
		0x70,
		0x00,

		/* @408 'd' (4 pixels wide) */
		//   ##
		//  #  #
		//  #  #
		//  #####
		0x00,
		0x70,
		0x90,
		0x90,
		0x70,
		0x10,

		/* @414 'e' (4 pixels wide) */
		//   ##
		//  ####
		//  ####
		//  #  #
		0x00,
		0x70,
		0xE0,
		0xE0,
		0x70,
		0x00,

		/* @420 'f' (3 pixels wide) */
		//  ####
		//   ## #
		//   ## #
		0x00,
		0x80,
		0xE0,
		0xE0,
		0x80,
		0x60,

		/* @426 'g' (3 pixels wide) */
		// # ###
		// #####
		// #####
		0xE0,
		0x60,
		0xE0,
		0xE0,
		0xE0,
		0x00,

		/* @432 'h' (4 pixels wide) */
		//  #####
		//     #
		//     #
		//  ###
		0x00,
		0x90,
		0x90,
		0x90,
		0xE0,
		0x80,

		/* @438 'i' (1 pixels wide) */
		//  ### #
		0x00,
		0x80,
		0x80,
		0x80,
		0x00,
		0x80,

		/* @444 'j' (1 pixels wide) */
		// #### #
		0x80,
		0x80,
		0x80,
		0x80,
		0x00,
		0x80,

		/* @450 'k' (4 pixels wide) */
		//  #####
		//   ##
		//   ##
		//  #  #
		0x00,
		0x90,
		0xE0,
		0xE0,
		0x90,
		0x80,

		/* @456 'l' (1 pixels wide) */
		//  #####
		0x00,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,

		/* @462 'm' (7 pixels wide) */
		//  ####
		//     #
		//     #
		//  ###
		//     #
		//  ###
		//  ###
		0x00,
		0x96,
		0x96,
		0x96,
		0xE8,
		0x00,

		/* @468 'n' (4 pixels wide) */
		//  ####
		//     #
		//     #
		//  ###
		0x00,
		0x90,
		0x90,
		0x90,
		0xE0,
		0x00,

		/* @474 'o' (4 pixels wide) */
		//   ##
		//  #  #
		//  #  #
		//   ##
		0x00,
		0x60,
		0x90,
		0x90,
		0x60,
		0x00,

		/* @480 'p' (4 pixels wide) */
		// #####
		//  #  #
		//  #  #
		//   ##
		0x80,
		0xE0,
		0x90,
		0x90,
		0xE0,
		0x00,

		/* @486 'q' (4 pixels wide) */
		//   ##
		//  #  #
		//  #  #
		// #####
		0x10,
		0x70,
		0x90,
		0x90,
		0x70,
		0x00,

		/* @492 'r' (3 pixels wide) */
		//  ####
		//     #
		//     #
		0x00,
		0x80,
		0x80,
		0x80,
		0xE0,
		0x00,

		/* @498 's' (4 pixels wide) */
		//  #
		//  ####
		//  ####
		//     #
		0x00,
		0xE0,
		0x60,
		0x60,
		0x70,
		0x00,

		/* @504 't' (4 pixels wide) */
		//     #
		//  #####
		//  #####
		//     #
		0x00,
		0x60,
		0x60,
		0x60,
		0xF0,
		0x60,

		/* @510 'u' (4 pixels wide) */
		//   ###
		//  #
		//  #
		//  ####
		0x00,
		0x70,
		0x90,
		0x90,
		0x90,
		0x00,

		/* @516 'v' (4 pixels wide) */
		//   ###
		//  #
		//  #
		//   ###
		0x00,
		0x60,
		0x90,
		0x90,
		0x90,
		0x00,

		/* @522 'w' (7 pixels wide) */
		//   ###
		//  #
		//  #
		//   ##
		//  #
		//   ###
		//   ###
		0x00,
		0x68,
		0x96,
		0x96,
		0x86,
		0x00,

		/* @528 'x' (4 pixels wide) */
		//  #  #
		//   ##
		//   ##
		//  #  #
		0x00,
		0x90,
		0x60,
		0x60,
		0x90,
		0x00,

		/* @534 'y' (4 pixels wide) */
		// # ###
		// # ##
		// # ##
		//  ####
		0xE0,
		0x10,
		0xF0,
		0xF0,
		0x90,
		0x00,

		/* @540 'z' (4 pixels wide) */
		//  #  #
		//  ####
		//  ####
		//  #  #
		0x00,
		0xF0,
		0x60,
		0x60,
		0xF0,
		0x00,

		/* @546 '{' (4 pixels wide) */
		//   ##
		// ######
		// ######
		// #    #
		0x70,
		0x60,
		0xE0,
		0xE0,
		0x60,
		0x70,

		/* @552 '|' (1 pixels wide) */
		// ######
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,

		/* @558 '}' (4 pixels wide) */
		// #    #
		// ######
		// ######
		//   ##
		0xE0,
		0x60,
		0x70,
		0x70,
		0x60,
		0xE0,

		/* @564 '~' (5 pixels wide) */
		//     #
		//      #
		//      #
		//     #
		//      #
		0x00,
		0x00,
		0x00,
		0x00,
		0x90,
		0x68,
};

/* Character descriptors for Tiny 6pt */
/* { [Char width in bits], [Offset into tiny_6ptCharBitmaps in bytes] } */
static const FONT_CHAR_INFO PROGMEM tiny_6ptDescriptors[] =
	{
		{4, 0},	  /*   */
		{1, 6},	  /* ! */
		{4, 12},  /* " */
		{7, 18},  /* # */
		{4, 24},  /* $ */
		{5, 30},  /* % */
		{5, 36},  /* & */
		{1, 42},  /* ' */
		{3, 48},  /* ( */
		{3, 54},  /* ) */
		{4, 60},  /* * */
		{4, 66},  /* + */
		{1, 72},  /* , */
		{4, 78},  /* - */
		{1, 84},  /* . */
		{5, 90},  /* / */
		{4, 96},  /* 0 */
		{4, 102}, /* 1 */
		{4, 108}, /* 2 */
		{4, 114}, /* 3 */
		{4, 120}, /* 4 */
		{4, 126}, /* 5 */
		{4, 132}, /* 6 */
		{4, 138}, /* 7 */
		{4, 144}, /* 8 */
		{4, 150}, /* 9 */
		{1, 156}, /* : */
		{1, 162}, /* ; */
		{4, 168}, /* < */
		{4, 174}, /* = */
		{4, 180}, /* > */
		{4, 186}, /* ? */
		{4, 192}, /* @ */
		{4, 198}, /* A */
		{4, 204}, /* B */
		{4, 210}, /* C */
		{4, 216}, /* D */
		{4, 222}, /* E */
		{4, 228}, /* F */
		{4, 234}, /* G */
		{4, 240}, /* H */
		{4, 246}, /* I */
		{4, 252}, /* J */
		{5, 258}, /* K */
		{4, 264}, /* L */
		{7, 270}, /* M */
		{5, 276}, /* N */
		{5, 282}, /* O */
		{4, 288}, /* P */
		{5, 294}, /* Q */
		{4, 300}, /* R */
		{4, 306}, /* S */
		{4, 312}, /* T */
		{5, 318}, /* U */
		{7, 324}, /* V */
		{7, 330}, /* W */
		{4, 336}, /* X */
		{7, 342}, /* Y */
		{5, 348}, /* Z */
		{3, 354}, /* [ */
		{5, 360}, /* \ */
		{3, 366}, /* ] */
		{4, 372}, /* ^ */
		{4, 378}, /* _ */
		{3, 384}, /* ` */
		{4, 390}, /* a */
		{4, 396}, /* b */
		{4, 402}, /* c */
		{4, 408}, /* d */
		{4, 414}, /* e */
		{3, 420}, /* f */
		{3, 426}, /* g */
		{4, 432}, /* h */
		{1, 438}, /* i */
		{1, 444}, /* j */
		{4, 450}, /* k */
		{1, 456}, /* l */
		{7, 462}, /* m */
		{4, 468}, /* n */
		{4, 474}, /* o */
		{4, 480}, /* p */
		{4, 486}, /* q */
		{3, 492}, /* r */
		{4, 498}, /* s */
		{4, 504}, /* t */
		{4, 510}, /* u */
		{4, 516}, /* v */
		{7, 522}, /* w */
		{4, 528}, /* x */
		{4, 534}, /* y */
		{4, 540}, /* z */
		{4, 546}, /* { */
		{1, 552}, /* | */
		{4, 558}, /* } */
		{5, 564}, /* ~ */
};

/* Font information for Tiny 6pt */
static const FONT_INFO tiny_6ptFontInfo =
	{
		6,					 /*  Character height */
		' ',				 /*  Start character */
		'~',				 /*  End character */
		tiny_6ptDescriptors, /*  Character descriptor array */
		tiny_6ptBitmaps,	 /*  Character bitmap array */
};

/* Font data for Tiny 6pt */
// extern static const unsigned char PROGMEM tiny_6ptBitmaps[];
// extern static const FONT_INFO tiny_6ptFontInfo;
// extern static const FONT_CHAR_INFO PROGMEM tiny_6ptDescriptors[];

/* 
**  Font data for Tiny 8pt
*/

/* Character bitmaps for Tiny 8pt */
static const unsigned char PROGMEM tiny_8ptBitmaps[] =
	{
		/* @0 ' ' (4 pixels wide) */
		//
		//
		//
		//
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @9 '!' (2 pixels wide) */
		//   ##  ###
		//   ##  ###
		0x00,
		0x00,
		0xC0,
		0xC0,
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xC0,

		/* @18 '"' (6 pixels wide) */
		//       ###
		//       ###
		//
		//
		//       ###
		//       ###
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xCC,

		/* @27 '#' (9 pixels wide) */
		//   ##  ##
		//   ##  ##
		// #########
		// #########
		//   ##  ##
		// #########
		// #########
		//   ##  ##
		//   ##  ##
		0x36,
		0x36,
		0xFF,
		0xFF,
		0x36,
		0x36,
		0xFF,
		0xFF,
		0x36,
		0x00,
		0x00,
		0x80,
		0x80,
		0x00,
		0x00,
		0x80,
		0x80,
		0x00,

		/* @45 '$' (6 pixels wide) */
		//   ##  ##
		//   ##  ##
		// #########
		// #########
		//   ##  ##
		//   ##  ##
		0x30,
		0x30,
		0xFC,
		0xFC,
		0x30,
		0x30,
		0xFC,
		0xFC,
		0x30,

		/* @54 '%' (7 pixels wide) */
		//   ##   ##
		//   ##   ##
		//     ##
		//     ##
		//       ##
		//   ##  ###
		//   ##   ##
		0x00,
		0x00,
		0xC6,
		0xC6,
		0x30,
		0x30,
		0x0C,
		0xCE,
		0xC6,

		/* @63 '&' (7 pixels wide) */
		//     ##
		//     ##
		//   ##  ###
		//   ##  ###
		//   ##   ##
		//   #### ##
		//     ##
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xC6,
		0xC6,
		0x30,
		0x3C,
		0x3C,

		/* @72 ''' (2 pixels wide) */
		//       ###
		//       ###
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xC0,

		/* @81 '(' (4 pixels wide) */
		//   ######
		//   ######
		// ##     ##
		// ##     ##
		0x30,
		0x30,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xF0,
		0x30,

		/* @90 ')' (4 pixels wide) */
		// ##     ##
		// ##     ##
		//   ######
		//   ######
		0xC0,
		0xC0,
		0x30,
		0x30,
		0x30,
		0x30,
		0x30,
		0xF0,
		0xC0,

		/* @99 '*' (6 pixels wide) */
		//     ## ##
		//     ## ##
		//       ##
		//       ##
		//     ## ##
		//     ## ##
		0x00,
		0x00,
		0x00,
		0x00,
		0xCC,
		0xCC,
		0x30,
		0xFC,
		0xCC,

		/* @108 '+' (6 pixels wide) */
		//     ##
		//     ##
		//   ######
		//   ######
		//     ##
		//     ##
		0x00,
		0x00,
		0x30,
		0x30,
		0xFC,
		0xFC,
		0x30,
		0x30,
		0x00,

		/* @117 ',' (2 pixels wide) */
		// ####
		// ####
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @126 '-' (6 pixels wide) */
		//     ##
		//     ##
		//     ##
		//     ##
		//     ##
		//     ##
		0x00,
		0x00,
		0x00,
		0x00,
		0xFC,
		0xFC,
		0x00,
		0x00,
		0x00,

		/* @135 '.' (2 pixels wide) */
		//   ##
		//   ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @144 '/' (7 pixels wide) */
		//   ##
		//   ##
		//     ##
		//     ##
		//       ##
		//       ###
		//        ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0x30,
		0x30,
		0x0C,
		0x0E,
		0x06,

		/* @153 '0' (6 pixels wide) */
		//     ####
		//     ####
		//   ##   ##
		//   ##   ##
		//     ####
		//     ####
		0x00,
		0x00,
		0x30,
		0x30,
		0xCC,
		0xCC,
		0xCC,
		0xFC,
		0x30,

		/* @162 '1' (6 pixels wide) */
		//   ##  ##
		//   ##  ##
		//   #######
		//   #######
		//   ##
		//   ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0x30,
		0x30,
		0xF0,
		0xF0,
		0x30,

		/* @171 '2' (6 pixels wide) */
		//   #### ##
		//   #### ##
		//   ##   ##
		//   ##   ##
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0xC0,
		0xC0,
		0x0C,
		0xFC,
		0xF0,

		/* @180 '3' (6 pixels wide) */
		//   ##   ##
		//   ##   ##
		//   ##  ###
		//   ##  ###
		//     ####
		//     ####
		0x00,
		0x00,
		0xF0,
		0xF0,
		0x0C,
		0x0C,
		0x3C,
		0xFC,
		0xF0,

		/* @189 '4' (6 pixels wide) */
		//     ####
		//     ####
		//     ##
		//     ##
		//   #######
		//   #######
		0x00,
		0x00,
		0x0C,
		0x0C,
		0xFC,
		0xFC,
		0xCC,
		0xCC,
		0x0C,

		/* @198 '5' (6 pixels wide) */
		//   ##  ###
		//   ##  ###
		//   ##   ##
		//   ##   ##
		//     ## ##
		//     ## ##
		0x00,
		0x00,
		0xF0,
		0xF0,
		0x0C,
		0x0C,
		0xC0,
		0xFC,
		0xFC,

		/* @207 '6' (6 pixels wide) */
		//   ######
		//   ######
		//   #### ##
		//   #### ##
		//   #### ##
		//   #### ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0xFC,
		0xFC,
		0xC0,
		0xFC,
		0x3C,

		/* @216 '7' (6 pixels wide) */
		//   ##   ##
		//   ##   ##
		//     ## ##
		//     ## ##
		//       ###
		//       ###
		0x00,
		0x00,
		0xC0,
		0xC0,
		0x30,
		0x30,
		0x0C,
		0xFC,
		0xFC,

		/* @225 '8' (6 pixels wide) */
		//     ####
		//     ####
		//   ##  ###
		//   ##  ###
		//     ####
		//     ####
		0x00,
		0x00,
		0x30,
		0x30,
		0xCC,
		0xCC,
		0xFC,
		0xFC,
		0x30,

		/* @234 '9' (6 pixels wide) */
		//     ####
		//     ####
		//     ## ##
		//     ## ##
		//   #######
		//   #######
		0x00,
		0x00,
		0x0C,
		0x0C,
		0xFC,
		0xFC,
		0xCC,
		0xFC,
		0x3C,

		/* @243 ':' (2 pixels wide) */
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0x00,
		0x00,
		0xC0,
		0xC0,
		0x00,

		/* @252 ';' (2 pixels wide) */
		// ####  ##
		// ####  ##
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0x00,
		0x00,
		0xC0,
		0xC0,
		0x00,

		/* @261 '<' (6 pixels wide) */
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		// ##     ##
		// ##     ##
		0x0C,
		0x0C,
		0x30,
		0x30,
		0xC0,
		0xC0,
		0x30,
		0x3C,
		0x0C,

		/* @270 '=' (6 pixels wide) */
		//   ##  ##
		//   ##  ##
		//   ##  ##
		//   ##  ##
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0x00,
		0x00,
		0xFC,
		0xFC,
		0x00,

		/* @279 '>' (6 pixels wide) */
		// ##     ##
		// ##     ##
		//   ##  ##
		//   ##  ##
		//     ##
		//     ##
		0xC0,
		0xC0,
		0x30,
		0x30,
		0x0C,
		0x0C,
		0x30,
		0xF0,
		0xC0,

		/* @288 '?' (6 pixels wide) */
		//        ##
		//        ##
		//   ##   ##
		//   ##   ##
		//       ##
		//       ##
		0x00,
		0x00,
		0x30,
		0x30,
		0x00,
		0x00,
		0x0C,
		0xFC,
		0xF0,

		/* @297 '@' (6 pixels wide) */
		//     ####
		//     ####
		//   ##   ##
		//   ##   ##
		//   ##  ###
		//   ##  ###
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xC0,
		0xC0,
		0xCC,
		0xFC,
		0x3C,

		/* @306 'A' (6 pixels wide) */
		//   ######
		//   ######
		//     ## ##
		//     ## ##
		//   ######
		//   ######
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xFC,
		0xFC,
		0xCC,
		0xFC,
		0x30,

		/* @315 'B' (6 pixels wide) */
		//   #######
		//   #######
		//   ##  ###
		//   ##  ###
		//     ####
		//     ####
		0x00,
		0x00,
		0xF0,
		0xF0,
		0xCC,
		0xCC,
		0xFC,
		0xFC,
		0xF0,

		/* @324 'C' (6 pixels wide) */
		//     ####
		//     ####
		//   ##   ##
		//   ##   ##
		//   ##   ##
		//   ##   ##
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xC0,
		0xC0,
		0xC0,
		0xFC,
		0x3C,

		/* @333 'D' (6 pixels wide) */
		//   #######
		//   #######
		//   ##   ##
		//   ##   ##
		//     ####
		//     ####
		0x00,
		0x00,
		0xF0,
		0xF0,
		0xCC,
		0xCC,
		0xCC,
		0xFC,
		0xF0,

		/* @342 'E' (6 pixels wide) */
		//   #######
		//   #######
		//   ##  ###
		//   ##  ###
		//   ##   ##
		//   ##   ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0xC0,
		0xC0,
		0xF0,
		0xFC,
		0xFC,

		/* @351 'F' (6 pixels wide) */
		//   #######
		//   #######
		//     ## ##
		//     ## ##
		//        ##
		//        ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xF0,
		0xF0,
		0xC0,
		0xFC,
		0xFC,

		/* @360 'G' (6 pixels wide) */
		//     ####
		//     ####
		//   ##   ##
		//   ##   ##
		//   #### ##
		//   #### ##
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xCC,
		0xCC,
		0xC0,
		0xFC,
		0x3C,

		/* @369 'H' (6 pixels wide) */
		//   #######
		//   #######
		//     ##
		//     ##
		//   #######
		//   #######
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xFC,
		0xFC,
		0xCC,
		0xCC,
		0xCC,

		/* @378 'I' (6 pixels wide) */
		//   ##   ##
		//   ##   ##
		//   #######
		//   #######
		//   ##   ##
		//   ##   ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0x30,
		0x30,
		0x30,
		0xFC,
		0xFC,

		/* @387 'J' (6 pixels wide) */
		//     ##
		//     ##
		//   ##
		//   ##
		//     #####
		//     #####
		0x00,
		0x00,
		0x30,
		0x30,
		0xCC,
		0xCC,
		0x0C,
		0x0C,
		0x0C,

		/* @396 'K' (7 pixels wide) */
		//   #######
		//   #######
		//     ##
		//     ##
		//     ####
		//   #######
		//   ##   ##
		0x00,
		0x00,
		0xC6,
		0xC6,
		0xFC,
		0xFC,
		0xCC,
		0xCE,
		0xC6,

		/* @405 'L' (6 pixels wide) */
		//   #######
		//   #######
		//   ##
		//   ##
		//   ##
		//   ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,

		/* @414 'M' (9 pixels wide) */
		//   #######
		//   #######
		//       ##
		//       ##
		//     ##
		//     ####
		//       ##
		//   #######
		//   #######
		0x00,
		0x00,
		0xC1,
		0xC1,
		0xCD,
		0xCD,
		0xF7,
		0xF7,
		0xC1,
		0x00,
		0x00,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,

		/* @432 'N' (7 pixels wide) */
		//   #######
		//   #######
		//       ##
		//       ##
		//     ##
		//   #######
		//   #######
		0x00,
		0x00,
		0xC6,
		0xC6,
		0xCE,
		0xCE,
		0xF6,
		0xF6,
		0xC6,

		/* @441 'O' (7 pixels wide) */
		//     ####
		//     ####
		//   ##   ##
		//   ##   ##
		//   ##   ##
		//   #######
		//     ####
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xC6,
		0xC6,
		0xC6,
		0xFE,
		0x3C,

		/* @450 'P' (6 pixels wide) */
		//   #######
		//   #######
		//     ## ##
		//     ## ##
		//       ##
		//       ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xF0,
		0xF0,
		0xCC,
		0xFC,
		0xF0,

		/* @459 'Q' (7 pixels wide) */
		//     ####
		//     ####
		//   ##   ##
		//   ##   ##
		// ####   ##
		// #########
		//     ####
		0x0C,
		0x0C,
		0x3C,
		0x3C,
		0xC6,
		0xC6,
		0xC6,
		0xFE,
		0x3C,

		/* @468 'R' (6 pixels wide) */
		//   #######
		//   #######
		//     ## ##
		//     ## ##
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xF0,
		0xF0,
		0xCC,
		0xFC,
		0xF0,

		/* @477 'S' (6 pixels wide) */
		//   ##  ##
		//   ##  ##
		//   ##   ##
		//   ##   ##
		//     ## ##
		//     ## ##
		0x00,
		0x00,
		0xF0,
		0xF0,
		0x0C,
		0x0C,
		0xC0,
		0xFC,
		0x3C,

		/* @486 'T' (6 pixels wide) */
		//        ##
		//        ##
		//   #######
		//   #######
		//        ##
		//        ##
		0x00,
		0x00,
		0x30,
		0x30,
		0x30,
		0x30,
		0x30,
		0xFC,
		0xFC,

		/* @495 'U' (7 pixels wide) */
		//     #####
		//     #####
		//   ##
		//   ##
		//   ##
		//   #######
		//     #####
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xC6,
		0xC6,
		0xC6,
		0xC6,
		0xC6,

		/* @504 'V' (9 pixels wide) */
		//       ###
		//       ###
		//     ##
		//     ##
		//   ##
		//   ####
		//     ##
		//       ###
		//       ###
		0x00,
		0x00,
		0x0C,
		0x0C,
		0x36,
		0x36,
		0xC1,
		0xC1,
		0xC1,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x80,
		0x80,
		0x80,

		/* @522 'W' (9 pixels wide) */
		//     #####
		//     #####
		//   ##
		//   ##
		//     ####
		//   ######
		//   ##
		//     #####
		//     #####
		0x00,
		0x00,
		0x36,
		0x36,
		0xCD,
		0xCD,
		0xCD,
		0xCD,
		0xC1,
		0x00,
		0x00,
		0x00,
		0x00,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,

		/* @540 'X' (6 pixels wide) */
		//   #### ##
		//   #### ##
		//       ##
		//       ##
		//   #### ##
		//   #### ##
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xCC,
		0xCC,
		0x30,
		0xFC,
		0xCC,

		/* @549 'Y' (9 pixels wide) */
		//        ##
		//        ##
		//       ##
		//       ##
		//   ####
		//   ######
		//       ##
		//        ##
		//        ##
		0x00,
		0x00,
		0x0C,
		0x0C,
		0x0C,
		0x0C,
		0x36,
		0xF7,
		0xC1,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x80,
		0x80,

		/* @567 'Z' (7 pixels wide) */
		//   ##   ##
		//   ##   ##
		//   #### ##
		//   #### ##
		//   ##  ###
		//   ##  ###
		//   ##   ##
		0x00,
		0x00,
		0xFE,
		0xFE,
		0x30,
		0x30,
		0x0C,
		0xFE,
		0xFE,

		/* @576 '[' (4 pixels wide) */
		// #########
		// #########
		// ##     ##
		// ##     ##
		0xF0,
		0xF0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xF0,
		0xF0,

		/* @585 '\' (7 pixels wide) */
		//        ##
		//        ##
		//       ##
		//       ##
		//     ##
		//   ####
		//   ##
		0x00,
		0x00,
		0x06,
		0x06,
		0x0C,
		0x0C,
		0x30,
		0xF0,
		0xC0,

		/* @594 ']' (4 pixels wide) */
		// ##     ##
		// ##     ##
		// #########
		// #########
		0xF0,
		0xF0,
		0x30,
		0x30,
		0x30,
		0x30,
		0x30,
		0xF0,
		0xF0,

		/* @603 '^' (6 pixels wide) */
		//       ##
		//       ##
		//        ##
		//        ##
		//       ##
		//       ##
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0xCC,
		0xFC,
		0x30,

		/* @612 '_' (6 pixels wide) */
		// ##
		// ##
		// ##
		// ##
		// ##
		// ##
		0xFC,
		0xFC,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,

		/* @621 '`' (4 pixels wide) */
		//        ##
		//        ##
		//       ##
		//       ##
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x30,
		0xF0,
		0xC0,

		/* @630 'a' (6 pixels wide) */
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		//   ######
		//   ######
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xCC,
		0xCC,
		0x3C,
		0x3C,
		0x00,

		/* @639 'b' (6 pixels wide) */
		//   #######
		//   #######
		//   ##  ##
		//   ##  ##
		//     ##
		//     ##
		0x00,
		0x00,
		0xF0,
		0xF0,
		0xCC,
		0xCC,
		0xF0,
		0xF0,
		0xC0,

		/* @648 'c' (6 pixels wide) */
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xC0,
		0xC0,
		0x3C,
		0x3C,
		0x00,

		/* @657 'd' (6 pixels wide) */
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		//   #######
		//   #######
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xCC,
		0xCC,
		0x3C,
		0x3C,
		0x0C,

		/* @666 'e' (6 pixels wide) */
		//     ##
		//     ##
		//   ######
		//   ######
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xF0,
		0xF0,
		0x3C,
		0x3C,
		0x00,

		/* @675 'f' (4 pixels wide) */
		//   ######
		//   ######
		//     ## ##
		//     ## ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xF0,
		0xF0,
		0xC0,
		0xF0,
		0x30,

		/* @684 'g' (4 pixels wide) */
		// ##  ####
		// ##  ####
		// ########
		// ########
		0xF0,
		0xF0,
		0x30,
		0x30,
		0xF0,
		0xF0,
		0xF0,
		0xF0,
		0x00,

		/* @693 'h' (6 pixels wide) */
		//   #######
		//   #######
		//       ##
		//       ##
		//   ####
		//   ####
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xCC,
		0xCC,
		0xF0,
		0xF0,
		0xC0,

		/* @702 'i' (2 pixels wide) */
		//   #### ##
		//   #### ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0x00,
		0xC0,
		0xC0,

		/* @711 'j' (2 pixels wide) */
		// ###### ##
		// ###### ##
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0x00,
		0xC0,
		0xC0,

		/* @720 'k' (6 pixels wide) */
		//   #######
		//   #######
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xF0,
		0xF0,
		0xCC,
		0xCC,
		0xC0,

		/* @729 'l' (2 pixels wide) */
		//   #######
		//   #######
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,

		/* @738 'm' (9 pixels wide) */
		//   ######
		//   ######
		//       ##
		//       ##
		//   ####
		//   ######
		//       ##
		//   ####
		//   ####
		0x00,
		0x00,
		0xCD,
		0xCD,
		0xCD,
		0xCD,
		0xF6,
		0xF6,
		0x00,
		0x00,
		0x00,
		0x80,
		0x80,
		0x80,
		0x80,
		0x00,
		0x00,
		0x00,

		/* @756 'n' (6 pixels wide) */
		//   ######
		//   ######
		//       ##
		//       ##
		//   ####
		//   ####
		0x00,
		0x00,
		0xCC,
		0xCC,
		0xCC,
		0xCC,
		0xF0,
		0xF0,
		0x00,

		/* @765 'o' (6 pixels wide) */
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		//     ##
		//     ##
		0x00,
		0x00,
		0x30,
		0x30,
		0xCC,
		0xCC,
		0x30,
		0x30,
		0x00,

		/* @774 'p' (6 pixels wide) */
		// ########
		// ########
		//   ##  ##
		//   ##  ##
		//     ##
		//     ##
		0xC0,
		0xC0,
		0xF0,
		0xF0,
		0xCC,
		0xCC,
		0xF0,
		0xF0,
		0x00,

		/* @783 'q' (6 pixels wide) */
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		// ########
		// ########
		0x0C,
		0x0C,
		0x3C,
		0x3C,
		0xCC,
		0xCC,
		0x3C,
		0x3C,
		0x00,

		/* @792 'r' (4 pixels wide) */
		//   ######
		//   ######
		//       ##
		//       ##
		0x00,
		0x00,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xF0,
		0xF0,
		0x00,

		/* @801 's' (6 pixels wide) */
		//   ##
		//   ##
		//   ######
		//   ######
		//       ##
		//       ##
		0x00,
		0x00,
		0xF0,
		0xF0,
		0x30,
		0x30,
		0x3C,
		0x3C,
		0x00,

		/* @810 't' (6 pixels wide) */
		//       ##
		//       ##
		//   #######
		//   #######
		//       ##
		//       ##
		0x00,
		0x00,
		0x30,
		0x30,
		0x30,
		0x30,
		0xFC,
		0xFC,
		0x30,

		/* @819 'u' (6 pixels wide) */
		//     ####
		//     ####
		//   ##
		//   ##
		//   ######
		//   ######
		0x00,
		0x00,
		0x3C,
		0x3C,
		0xCC,
		0xCC,
		0xCC,
		0xCC,
		0x00,

		/* @828 'v' (6 pixels wide) */
		//     ####
		//     ####
		//   ##
		//   ##
		//     ####
		//     ####
		0x00,
		0x00,
		0x30,
		0x30,
		0xCC,
		0xCC,
		0xCC,
		0xCC,
		0x00,

		/* @837 'w' (9 pixels wide) */
		//     ####
		//     ####
		//   ##
		//   ##
		//     ##
		//   ####
		//   ##
		//     ####
		//     ####
		0x00,
		0x00,
		0x36,
		0x36,
		0xCD,
		0xCD,
		0xC1,
		0xC1,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x80,
		0x80,
		0x80,
		0x80,
		0x00,

		/* @855 'x' (6 pixels wide) */
		//   ##  ##
		//   ##  ##
		//     ##
		//     ##
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0xCC,
		0xCC,
		0x30,
		0x30,
		0xCC,
		0xCC,
		0x00,

		/* @864 'y' (6 pixels wide) */
		// ##  ####
		// ##  ####
		// ##  ##
		// ##  ##
		//   ######
		//   ######
		0xF0,
		0xF0,
		0x0C,
		0x0C,
		0xFC,
		0xFC,
		0xCC,
		0xCC,
		0x00,

		/* @873 'z' (6 pixels wide) */
		//   ##  ##
		//   ##  ##
		//   ######
		//   ######
		//   ##  ##
		//   ##  ##
		0x00,
		0x00,
		0xFC,
		0xFC,
		0x30,
		0x30,
		0xFC,
		0xFC,
		0x00,

		/* @882 '{' (6 pixels wide) */
		//     ##
		//     ##
		// #########
		// #########
		// ##     ##
		// ##     ##
		0x3C,
		0x3C,
		0x30,
		0x30,
		0xF0,
		0xF0,
		0x30,
		0x3C,
		0x3C,

		/* @891 '|' (2 pixels wide) */
		// #########
		// #########
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,
		0xC0,

		/* @900 '}' (6 pixels wide) */
		// ##     ##
		// ##     ##
		// #########
		// #########
		//     ##
		//     ##
		0xF0,
		0xF0,
		0x30,
		0x30,
		0x3C,
		0x3C,
		0x30,
		0xF0,
		0xF0,

		/* @909 '~' (7 pixels wide) */
		//       ##
		//       ##
		//        ##
		//        ##
		//       ##
		//       ###
		//        ##
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0xCC,
		0xFE,
		0x36,
};

/* Character descriptors for Tiny 8pt */
/* { [Char width in bits], [Offset into tiny_8ptCharBitmaps in bytes] } */
static const FONT_CHAR_INFO PROGMEM tiny_8ptDescriptors[] =
	{
		{4, 0},	  /*   */
		{2, 9},	  /* ! */
		{6, 18},  /* " */
		{9, 27},  /* # */
		{6, 45},  /* $ */
		{7, 54},  /* % */
		{7, 63},  /* & */
		{2, 72},  /* ' */
		{4, 81},  /* ( */
		{4, 90},  /* ) */
		{6, 99},  /* * */
		{6, 108}, /* + */
		{2, 117}, /* , */
		{6, 126}, /* - */
		{2, 135}, /* . */
		{7, 144}, /* / */
		{6, 153}, /* 0 */
		{6, 162}, /* 1 */
		{6, 171}, /* 2 */
		{6, 180}, /* 3 */
		{6, 189}, /* 4 */
		{6, 198}, /* 5 */
		{6, 207}, /* 6 */
		{6, 216}, /* 7 */
		{6, 225}, /* 8 */
		{6, 234}, /* 9 */
		{2, 243}, /* : */
		{2, 252}, /* ; */
		{6, 261}, /* < */
		{6, 270}, /* = */
		{6, 279}, /* > */
		{6, 288}, /* ? */
		{6, 297}, /* @ */
		{6, 306}, /* A */
		{6, 315}, /* B */
		{6, 324}, /* C */
		{6, 333}, /* D */
		{6, 342}, /* E */
		{6, 351}, /* F */
		{6, 360}, /* G */
		{6, 369}, /* H */
		{6, 378}, /* I */
		{6, 387}, /* J */
		{7, 396}, /* K */
		{6, 405}, /* L */
		{9, 414}, /* M */
		{7, 432}, /* N */
		{7, 441}, /* O */
		{6, 450}, /* P */
		{7, 459}, /* Q */
		{6, 468}, /* R */
		{6, 477}, /* S */
		{6, 486}, /* T */
		{7, 495}, /* U */
		{9, 504}, /* V */
		{9, 522}, /* W */
		{6, 540}, /* X */
		{9, 549}, /* Y */
		{7, 567}, /* Z */
		{4, 576}, /* [ */
		{7, 585}, /* \ */
		{4, 594}, /* ] */
		{6, 603}, /* ^ */
		{6, 612}, /* _ */
		{4, 621}, /* ` */
		{6, 630}, /* a */
		{6, 639}, /* b */
		{6, 648}, /* c */
		{6, 657}, /* d */
		{6, 666}, /* e */
		{4, 675}, /* f */
		{4, 684}, /* g */
		{6, 693}, /* h */
		{2, 702}, /* i */
		{2, 711}, /* j */
		{6, 720}, /* k */
		{2, 729}, /* l */
		{9, 738}, /* m */
		{6, 756}, /* n */
		{6, 765}, /* o */
		{6, 774}, /* p */
		{6, 783}, /* q */
		{4, 792}, /* r */
		{6, 801}, /* s */
		{6, 810}, /* t */
		{6, 819}, /* u */
		{6, 828}, /* v */
		{9, 837}, /* w */
		{6, 855}, /* x */
		{6, 864}, /* y */
		{6, 873}, /* z */
		{6, 882}, /* { */
		{2, 891}, /* | */
		{6, 900}, /* } */
		{7, 909}, /* ~ */
};

/* Font information for Tiny 8pt */
static const FONT_INFO tiny_8ptFontInfo =
	{
		9,					 /*  Character height */
		' ',				 /*  Start character */
		'~',				 /*  End character */
		tiny_8ptDescriptors, /*  Character descriptor array */
		tiny_8ptBitmaps,	 /*  Character bitmap array */
};

/* Font data for Tiny 8pt */
// extern static const unsigned char PROGMEM tiny_8ptBitmaps[];
// extern static const FONT_INFO tiny_8ptFontInfo;
// extern static const FONT_CHAR_INFO PROGMEM tiny_8ptDescriptors[];
