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

#include "images/images.h"

#include "fonts/TinyFont.h"

#include "fonts/SansSerif_8pt.h"
#include "fonts/SansSerif_10pt.h"
#include "fonts/SansSerif_12pt.h"

#include "fonts/DigitsLarge.h"
#include "fonts/DigitsSmall.h"

#include "fonts/MarVoSym_8pt.h"
#include "fonts/MarVoSym_10pt.h"
#include "fonts/MarVoSym_12pt.h"

#include "YscoreModel.h"
#include "YscoreViewInterface.h"

#ifndef YScoreResourceProvider_h
#define YScoreResourceProvider_h

// define the labels used in the application
// copyright
#define LBL_COPYRIGHT "1.0 � J. Hewitt"
// #define LBL_APP_NAME "yScore"

// About
#define LBL_EN_FIND_US_AT "Find us @"
#define LBL_NL_FIND_US_AT "Vind ons @"
#define LBL_FR_FIND_US_AT "Trouve nous @"
#define LBL_DE_FIND_US_AT "Finde uns @"

static const char *LBL_FIND_US_AT[] = {LBL_EN_FIND_US_AT,
                                       LBL_NL_FIND_US_AT,
                                       LBL_FR_FIND_US_AT,
                                       LBL_DE_FIND_US_AT};

#define LBL_WEB_ADDRESS "www.yscore.be"

// Acknowledgement
#define LBL_ACK_LINE1 "3rd party software"
#define LBL_ACK_LINE2 "Tiny Matthew Welch"
#define LBL_ACK_LINE3 "www.squaregear.net"
#define LBL_ACK_LINE4 " "
#define LBL_ACK_LINE5 "FlashStorage"
#define LBL_ACK_LINE6 "Cristian. Maglie"
#define LBL_ACK_LINE7 "www.github.com"
#define LBL_ACK_LINE8 "/cmaglie/FlashStorage"

//  start
#define LBL_EN_PRESS_A_BUTTON "Press a button"
#define LBL_NL_PRESS_A_BUTTON "Druk een knop"
#define LBL_FR_PRESS_A_BUTTON "Appuyer un bouton"
#define LBL_DE_PRESS_A_BUTTON "Dr�cke einen Knopf"

static const char *LBL_PRESS_A_BUTTON[] = {LBL_EN_PRESS_A_BUTTON,
                                           LBL_NL_PRESS_A_BUTTON,
                                           LBL_FR_PRESS_A_BUTTON,
                                           LBL_DE_PRESS_A_BUTTON};

#define LBL_WHOSERVES "Who serves?"
#define LBL_RESTART " Restart "

// #define LBL_SEPARATOR ":"
// #define LBL_SPACE " "
// #define LBL_ZERO "0"
// #define LBL_PERCENT "%"

// define the modifyable labels
#define LBL_US " US  "
#define LBL_THEM " THEM"
#define LBL_NONE " NONE"

#define LBL_YOU "YOU "
#define LBL_PLAYING_TIME "Time Played"

// "text" when it is in MarVoSym font are the
// Up Down left and right arrows
#define LBL_UP_ARROW "C"
#define LBL_DOWN_ARROW "D"
#define LBL_LEFT_ARROW "A"
#define LBL_RIGHT_ARROW "B"

#define LBL_UPDOWN_ARROW "CD"

// Player Names
static char *
    LBL_PLAYER[] = {LBL_THEM, LBL_US, LBL_NONE};

static const tImage *IMG_SERVE[][2] = {{&img_Serve_BR, &img_Serve_BL},
                                       {&img_Serve_TL, &img_Serve_TR}};

static const tImage *IMG_PLAYER_DOUBLES[][4] = {{&img_Happy_blue, &img_Happy_green, &img_Sad_red, &img_Sad_yellow},
                                                {&img_Sad_blue, &img_Sad_green, &img_Happy_red, &img_Happy_yellow},
                                                {&img_Happy_blue, &img_Happy_green, &img_Sad_yellow, &img_Sad_red},
                                                {&img_Sad_blue, &img_Sad_green, &img_Happy_yellow, &img_Happy_red},
                                                {&img_Happy_green, &img_Happy_blue, &img_Sad_red, &img_Sad_yellow},
                                                {&img_Sad_green, &img_Sad_blue, &img_Happy_red, &img_Happy_yellow},
                                                {&img_Happy_green, &img_Happy_blue, &img_Sad_yellow, &img_Sad_red},
                                                {&img_Sad_green, &img_Sad_blue, &img_Happy_yellow, &img_Happy_red}};

static const tImage *IMG_WINNING_PLAYER[][2] = {{&img_Happy_blue, &img_Happy_green},
                                                {&img_Happy_red, &img_Happy_yellow}};

static const tImage *IMG_STATS_PLAYER[][4] = {{&img_Happy_blue, &img_Happy_green, &img_Sad_red, &img_Sad_yellow},
                                              {&img_Sad_blue, &img_Sad_green, &img_Happy_red, &img_Happy_yellow},
                                              {&img_Happy_blue, &img_Happy_green, &img_Happy_red, &img_Happy_yellow}};

// static const char* LBL_SERVE[][2] = {{">", "<"}, {"<", ">"}};

// Titles
#define LBL_EN_TITLE_PLAYING "Playing"
#define LBL_NL_TITLE_PLAYING "Spelen"
#define LBL_FR_TITLE_PLAYING "En jouant"
#define LBL_DE_TITLE_PLAYING "Spielen"

static const char *LBL_TITLE_PLAYING[] = {LBL_EN_TITLE_PLAYING,
                                          LBL_NL_TITLE_PLAYING,
                                          LBL_FR_TITLE_PLAYING,
                                          LBL_DE_TITLE_PLAYING};

#define LBL_EN_TITLE_WINNING "Winner!"
#define LBL_NL_TITLE_WINNING "Winnaar!"
#define LBL_FR_TITLE_WINNING "Gagnant!"
#define LBL_DE_TITLE_WINNING "Gewinner!"

static const char *LBL_TITLE_WINNING[] = {LBL_EN_TITLE_WINNING,
                                          LBL_NL_TITLE_WINNING,
                                          LBL_FR_TITLE_WINNING,
                                          LBL_DE_TITLE_WINNING};

// type used to define a selection list
typedef struct
{
  uint8_t length;
  const char **list;
} tSelectionList;

// Settings
// Who serves
#define LBL_EN_TITLE_WHO_SERVES "Who Serves?"
#define LBL_NL_TITLE_WHO_SERVES "Wie serveert?"
#define LBL_FR_TITLE_WHO_SERVES "Qui sert?"
#define LBL_DE_TITLE_WHO_SERVES "Wer dient?"

static const char *LBL_TITLE_WHO_SERVES[] = {LBL_EN_TITLE_WHO_SERVES,
                                             LBL_NL_TITLE_WHO_SERVES,
                                             LBL_FR_TITLE_WHO_SERVES,
                                             LBL_DE_TITLE_WHO_SERVES};

static const char *SETTING_EN_WHO_SERVES[] = {"Them", "Us", "Random"};
static const char *SETTING_NL_WHO_SERVES[] = {"Hen", "Wij", "Willekeurig"};
static const char *SETTING_FR_WHO_SERVES[] = {"Eux", "Nous", "Al�atoire"};
static const char *SETTING_DE_WHO_SERVES[] = {"Sie", "Wir", "Zuf�llig"};

static const char **SETTING_WHO_SERVES[] = {SETTING_EN_WHO_SERVES,
                                            SETTING_NL_WHO_SERVES,
                                            SETTING_FR_WHO_SERVES,
                                            SETTING_DE_WHO_SERVES};

// Type of match
#define LBL_EN_TITLE_TYPE_OF_MATCH "Type of match?"
#define LBL_NL_TITLE_TYPE_OF_MATCH "Soort spel?"
#define LBL_FR_TITLE_TYPE_OF_MATCH "Type de jeu?"
#define LBL_DE_TITLE_TYPE_OF_MATCH "Art der Spiels?"

static const char *LBL_TITLE_TYPE_OF_MATCH[] = {LBL_EN_TITLE_TYPE_OF_MATCH,
                                                LBL_NL_TITLE_TYPE_OF_MATCH,
                                                LBL_FR_TITLE_TYPE_OF_MATCH,
                                                LBL_DE_TITLE_TYPE_OF_MATCH};

static const char *SETTING_EN_TYPE_OF_MATCH[] = {"Doubles", "Singles"};
static const char *SETTING_NL_TYPE_OF_MATCH[] = {"Dubbelspel", "Enklespel"};
static const char *SETTING_FR_TYPE_OF_MATCH[] = {"Doubles", "Simple"};
static const char *SETTING_DE_TYPE_OF_MATCH[] = {"Doppel", "Einzel"};

static const char **SETTING_TYPE_OF_MATCH[] = {SETTING_EN_TYPE_OF_MATCH,
                                               SETTING_NL_TYPE_OF_MATCH,
                                               SETTING_FR_TYPE_OF_MATCH,
                                               SETTING_DE_TYPE_OF_MATCH};

// Brightness
#define LBL_EN_TITLE_BRIGHTNESS "Brightness?"
#define LBL_NL_TITLE_BRIGHTNESS "Helderheid?"
#define LBL_FR_TITLE_BRIGHTNESS "Luminosit�?"
#define LBL_DE_TITLE_BRIGHTNESS "Helligkeit?"

static const char *LBL_TITLE_BRIGHTNESS[] = {LBL_EN_TITLE_BRIGHTNESS,
                                             LBL_NL_TITLE_BRIGHTNESS,
                                             LBL_FR_TITLE_BRIGHTNESS,
                                             LBL_DE_TITLE_BRIGHTNESS};

static const char *SETTING_EN_BRIGHTNESS[] = {"Very dark", "Dark", "Normal", "Bright", "Very Bright"};
static const char *SETTING_NL_BRIGHTNESS[] = {"Zeer donker", "Donker", "Normaal", "Helder", "Zeer helder"};
static const char *SETTING_FR_BRIGHTNESS[] = {"Tr�s sombre", "Fonc�", "Normal", "Clair", "Tr�s clair"};
static const char *SETTING_DE_BRIGHTNESS[] = {"Sehr dunkel", "Dunkel", "Normal", "Hell", "Sehr hell"};
static const char **SETTING_BRIGHTNESS[] = {SETTING_EN_BRIGHTNESS,
                                            SETTING_NL_BRIGHTNESS,
                                            SETTING_FR_BRIGHTNESS,
                                            SETTING_DE_BRIGHTNESS};

// Handedness
#define LBL_EN_TITLE_HANDEDNESS "Handedness"
#define LBL_NL_TITLE_HANDEDNESS "handigheid"
#define LBL_FR_TITLE_HANDEDNESS "Main de pr�f�rence"
#define LBL_DE_TITLE_HANDEDNESS "H�ndigkeit"

static const char *LBL_TITLE_HANDEDNESS[] = {LBL_EN_TITLE_HANDEDNESS,
                                             LBL_NL_TITLE_HANDEDNESS,
                                             LBL_FR_TITLE_HANDEDNESS,
                                             LBL_DE_TITLE_HANDEDNESS};

static const char *SETTING_EN_HANDEDNESS[] = {"Right", "Left"};
static const char *SETTING_NL_HANDEDNESS[] = {"Rechts", "Links"};
static const char *SETTING_FR_HANDEDNESS[] = {"Droit", "Gauch"};
static const char *SETTING_DE_HANDEDNESS[] = {"Rechts", "Links"};
static const char **SETTING_HANDEDNESS[] = {SETTING_EN_HANDEDNESS,
                                            SETTING_NL_HANDEDNESS,
                                            SETTING_FR_HANDEDNESS,
                                            SETTING_DE_HANDEDNESS};

// Local
#define LBL_EN_TITLE_LOCAL "Language?"
#define LBL_NL_TITLE_LOCAL "Taal?"
#define LBL_FR_TITLE_LOCAL "Langue?"
#define LBL_DE_TITLE_LOCAL "Sprache?"

static const char *LBL_TITLE_LOCAL[] = {LBL_EN_TITLE_LOCAL,
                                        LBL_NL_TITLE_LOCAL,
                                        LBL_FR_TITLE_LOCAL,
                                        LBL_DE_TITLE_LOCAL};

static const char *SETTING_LOCAL[] = {"English", "Nederlands", "Fran�ais", "Deutsch"};

// Labels for the buttons
// #define LBL_BUT_MODE "MODE"
// #define LBL_BUT_BACK "BACK"
// #define LBL_BUT_THEM "THEM"
// #define LBL_BUT_US "US"

// create the labels for the
// #define LBL_MENU_PLAY "Play"
// #define LBL_MENU_STATS "Stats"
// #define LBL_MENU_RESTART "Restart"

// Class provides the resource provider functionality.
class YscoreResourceProvider
{
public:
  // YscoreResourceProvider();
  const char *getCopyright(uint8_t local);
  const char *getPressAButton(uint8_t local);
  const char *getFindUsAt(uint8_t local);

  const char *getTitlePlaying(uint8_t local);
  const char *getTitleWinning(uint8_t local);

  const char *getTitleWhoServes(uint8_t local);
  const tSelectionList getSelectionListWhoServes(uint8_t local);
  const char *getTitleTypeOfMatch(uint8_t local);
  const tSelectionList getSelectionListTypeOfMatch(uint8_t local);
  const char *getTitleBrightness(uint8_t local);
  const tSelectionList getSelectionListBrightness(uint8_t local);
  const char *getTitleLocal(uint8_t local);
  const tSelectionList getSelectionListLocal(uint8_t local);
  const char *getTitleHandedness(uint8_t local);
  const tSelectionList getSelectionListHandedness(uint8_t local);

private:
};

#endif
