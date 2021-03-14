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
#define LBL_COPYRIGHT "1.0 © J. Hewitt"
// #define LBL_APP_NAME "yScore"

// About
static const char *LBL_FIND_US_AT[] = {"Find us",     // EN
                                       "Vind ons",    // NL
                                       "Trouve nous", // FR
                                       "Finde uns"};  // DE

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
static const char *LBL_PLAY[] = {" Play",
                                 " Speel",
                                 " Jouer",
                                 " Spielen"};

static const char *LBL_SETTINGS[] = {" Settings",
                                     " Instellingen",
                                     " Réglages",
                                     " Einstellungen"};

// #define LBL_RESTART " Restart "

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

#define LBL_ALL_ARROW "CDAB"

#define LBL_UPDOWN_ARROW "CD"
#define LBL_LEFTRIGHT_ARROW "AB"

// Player Names
// static char *
//     LBL_PLAYER[] = {LBL_THEM, LBL_US, LBL_NONE};

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

static const tImage *IMG_PLAYER_SINGLES[][4] = {{&img_Happy_green, &img_Blank_player, &img_Blank_player, &img_Sad_yellow},
                                                {&img_Sad_green, &img_Blank_player, &img_Blank_player, &img_Happy_yellow},
                                                {&img_Happy_green, &img_Blank_player, &img_Blank_player, &img_Sad_yellow},
                                                {&img_Blank_player, &img_Sad_green, &img_Happy_yellow, &img_Blank_player},
                                                {&img_Blank_player, &img_Happy_green, &img_Sad_yellow, &img_Blank_player},
                                                {&img_Sad_green, &img_Blank_player, &img_Blank_player, &img_Happy_yellow},
                                                {&img_Blank_player, &img_Happy_green, &img_Sad_yellow, &img_Blank_player},
                                                {&img_Blank_player, &img_Sad_green, &img_Happy_yellow, &img_Blank_player}};

static const tImage *IMG_WINNING_PLAYER_DOUBLES[][2] = {{&img_Happy_blue, &img_Happy_green},
                                                        {&img_Happy_red, &img_Happy_yellow}};

static const tImage *IMG_STATS_PLAYER_DOUBLES[][4] = {{&img_Happy_blue, &img_Happy_green, &img_Sad_red, &img_Sad_yellow},
                                                      {&img_Sad_blue, &img_Sad_green, &img_Happy_red, &img_Happy_yellow},
                                                      {&img_Happy_blue, &img_Happy_green, &img_Happy_red, &img_Happy_yellow}};

// static const char* LBL_SERVE[][2] = {{">", "<"}, {"<", ">"}};

// Titles
static const char *LBL_TITLE_PLAYING[] = {"Playing",
                                          "Spelen",
                                          "En jouant",
                                          "Spielen"};

static const char *LBL_TITLE_WINNING[] = {"Winner!",
                                          "Winnaar!",
                                          "Gagnant!",
                                          "Gewinner!"};

static const char *LBL_TITLE_MATCH_SCORE[] = {"Game score",
                                              "Spel score",
                                              "Score du jeu",
                                              "Spielstand"};

static const char *LBL_TITLE_MATCH_TIME[] = {"Game time",
                                             "Spel tijd",
                                             "Jeu temps",
                                             "Spielzeit"};

static const char *LBL_TITLE_ABOUT[] = {"About",
                                        "Over",
                                        "À propos",
                                        "Über"};

static const char *LBL_TITLE_ACKNOWLEDGEMENT[] = {"Acknowledgement",
                                                  "Erkenning",
                                                  "Reconnaissance",
                                                  "Anerkennung"};

static const char *LBL_TITLE_UPDATE[] = {"Update",
                                         "Bijwerken",
                                         "Metter",
                                         "Aktualisieren"};

static const char *LBL_EN_PLAYER_SINGLES[] = {"Them", "Me"};
static const char *LBL_NL_PLAYER_SINGLES[] = {"Hen", "Mij"};
static const char *LBL_FR_PLAYER_SINGLES[] = {"Eux", "Moi"};
static const char *LBL_DE_PLAYER_SINGLES[] = {"Sie", "Mich"};
static const char **LBL_PLAYER_SINGLES[] = {LBL_EN_PLAYER_SINGLES,
                                            LBL_NL_PLAYER_SINGLES,
                                            LBL_FR_PLAYER_SINGLES,
                                            LBL_DE_PLAYER_SINGLES};

static const char *LBL_EN_PLAYER_DOUBLES[] = {"Them", "Us"};
static const char *LBL_NL_PLAYER_DOUBLES[] = {"Hen", "Wij"};
static const char *LBL_FR_PLAYER_DOUBLES[] = {"Eux", "Nous"};
static const char *LBL_DE_PLAYER_DOUBLES[] = {"Sie", "Wir"};
static const char **LBL_PLAYER_DOUBLES[] = {LBL_EN_PLAYER_DOUBLES,
                                            LBL_NL_PLAYER_DOUBLES,
                                            LBL_FR_PLAYER_DOUBLES,
                                            LBL_DE_PLAYER_DOUBLES};

static const char *LBL_RESTART[] = {" Restart ",
                                    " Herstarten ",
                                    " Redémarrer ",
                                    " Neu starten "};

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

static const char *SETTING_EN_WHO_SERVES_SINGLES[] = {"Them", "Me", "Random"};
static const char *SETTING_NL_WHO_SERVES_SINGLES[] = {"Hen", "Mij", "Willekeurig"};
static const char *SETTING_FR_WHO_SERVES_SINGLES[] = {"Eux", "Moi", "Aléatoire"};
static const char *SETTING_DE_WHO_SERVES_SINGLES[] = {"Sie", "Mich", "Zufällig"};

static const char **SETTING_WHO_SERVES_SINGLES[] = {SETTING_EN_WHO_SERVES_SINGLES,
                                                    SETTING_NL_WHO_SERVES_SINGLES,
                                                    SETTING_FR_WHO_SERVES_SINGLES,
                                                    SETTING_DE_WHO_SERVES_SINGLES};

static const char *SETTING_EN_WHO_SERVES_DOUBLES[] = {"Them", "Us", "Random"};
static const char *SETTING_NL_WHO_SERVES_DOUBLES[] = {"Hen", "Wij", "Willekeurig"};
static const char *SETTING_FR_WHO_SERVES_DOUBLES[] = {"Eux", "Nous", "Aléatoire"};
static const char *SETTING_DE_WHO_SERVES_DOUBLES[] = {"Sie", "Wir", "Zufällig"};

static const char **SETTING_WHO_SERVES_DOUBLES[] = {SETTING_EN_WHO_SERVES_DOUBLES,
                                                    SETTING_NL_WHO_SERVES_DOUBLES,
                                                    SETTING_FR_WHO_SERVES_DOUBLES,
                                                    SETTING_DE_WHO_SERVES_DOUBLES};

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
#define LBL_FR_TITLE_BRIGHTNESS "Luminosité?"
#define LBL_DE_TITLE_BRIGHTNESS "Helligkeit?"

static const char *LBL_TITLE_BRIGHTNESS[] = {LBL_EN_TITLE_BRIGHTNESS,
                                             LBL_NL_TITLE_BRIGHTNESS,
                                             LBL_FR_TITLE_BRIGHTNESS,
                                             LBL_DE_TITLE_BRIGHTNESS};

static const char *SETTING_EN_BRIGHTNESS[] = {"Very dark", "Dark", "Normal", "Bright", "Very Bright"};
static const char *SETTING_NL_BRIGHTNESS[] = {"Zeer donker", "Donker", "Normaal", "Helder", "Zeer helder"};
static const char *SETTING_FR_BRIGHTNESS[] = {"Très sombre", "Foncé", "Normal", "Clair", "Très clair"};
static const char *SETTING_DE_BRIGHTNESS[] = {"Sehr dunkel", "Dunkel", "Normal", "Hell", "Sehr hell"};
static const char **SETTING_BRIGHTNESS[] = {SETTING_EN_BRIGHTNESS,
                                            SETTING_NL_BRIGHTNESS,
                                            SETTING_FR_BRIGHTNESS,
                                            SETTING_DE_BRIGHTNESS};

// Handedness
#define LBL_EN_TITLE_HANDEDNESS "Handedness"
#define LBL_NL_TITLE_HANDEDNESS "handigheid"
#define LBL_FR_TITLE_HANDEDNESS "Main de préférence"
#define LBL_DE_TITLE_HANDEDNESS "Händigkeit"

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

static const char *SETTING_LOCAL[] = {"English", "Nederlands", "Français", "Deutsch"};

// Class provides the resource provider functionality.
class YscoreResourceProvider
{
public:
  // YscoreResourceProvider();
  const char *getLblCopyright(uint8_t local);
  const char *getLblPlay(uint8_t local);
  const char *getLblSettings(uint8_t local);
  const char *getLblFindUsAt(uint8_t local);
  const char *getLblRestart(uint8_t local);

  const char *getLblPlayer(uint8_t local, uint8_t typeOfMatch, uint8_t winner);

  const char *getTitlePlaying(uint8_t local);
  const char *getTitleWinning(uint8_t local);
  const char *getTitleMatchScore(uint8_t local);
  const char *getTitleMatchTime(uint8_t local);
  const char *getTitleAbout(uint8_t local);
  const char *getTitleAcknowledgement(uint8_t local);
  const char *getTitleUpdate(uint8_t local);

  const char *getTitleWhoServes(uint8_t local);
  const tSelectionList getSelectionListWhoServes(uint8_t local, uint8_t typeOfMatch);
  const char *getTitleTypeOfMatch(uint8_t local);
  const tSelectionList getSelectionListTypeOfMatch(uint8_t local);
  const char *getTitleBrightness(uint8_t local);
  const tSelectionList getSelectionListBrightness(uint8_t local);
  const char *getTitleLocal(uint8_t local);
  const tSelectionList getSelectionListLocal(uint8_t local);
  const char *getTitleHandedness(uint8_t local);
  const tSelectionList getSelectionListHandedness(uint8_t local);

  const tImage *getImgServe(uint8_t who, uint8_t side);
  const tImage **getImgPlayers(uint8_t typeOfMatch, uint8_t position);
  const tImage **getImgStatsPlayers(uint8_t typeOfMatch, uint8_t winnar);
  const tImage **getImgWiningPlayers(uint8_t typeOfMatch, uint8_t winnar);

private:
};

#endif
