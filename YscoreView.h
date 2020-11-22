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

#ifndef YScoreView_h
#define YScoreView_h

// Screen dimensions and locations
#define SCREEN_MENU_MARGIN_Y 10

#define SCREEN_BATTERY_X 82

#define SCREEN_BUTTON_LEFT_MARGIN_X 7
#define SCREEN_BUTTON_TOP_Y 13
#define SCREEN_BUTTON_BOTTOM_Y 48

#define SCREEN_BUTTON_RIGHT_MARGIN_X 88

#define SCREEN_MIDDLE_LINE_Y 37

#define SCREEN_GAMES_LINE_X 42
#define SCREEN_POINTS_LINE_X 59

#define SCREEN_SERVE_X 14
#define SCREEN_SERVE_Y 26

#define SCREEN_PLAYER_LEFT_X 10
#define SCREEN_PLAYER_RIGHT_X 27
#define SCREEN_PLAYER_TOP_Y 13
#define SCREEN_PLAYER_BOTTOM_Y 48

#define SCREEN_STATS_PLAYER_LEFT_X 9
#define SCREEN_STATS_PLAYER_RIGHT_X 23
#define SCREEN_STATS_PLAYER_TOP_Y 13
#define SCREEN_STATS_PLAYER_BOTTOM_Y 31

#define SCREEN_STATS_SCORE_LEFT_X 40
#define SCREEN_STATS_SCORE_TOP_Y 15
#define SCREEN_STATS_SCORE_BOTTOM_Y 33

#define SCREEN_STATS_MIDDLE_LINE_Y 28
#define SCREEN_STATS_BOTTOM_LINE_Y 46

#define SCREEN_STATS_POINTS_LINE1_X 37
#define SCREEN_STATS_POINTS_LINE2_X 54
#define SCREEN_STATS_POINTS_LINE3_X 71

#define SCREEN_TIME_X 10
#define SCREEN_TIME_Y 15

// offset from screen margins
#define SCREEN_MARGIN_OFFSET_X 4
#define SCREEN_MARGIN_OFFSET_Y 6

// define the labels used in the application
#define LBL_TITLE "iScore"
#define LBL_COPYRIGHT "1.0 © J. Hewitt"
//  Battery: 100%
#define LBL_TO_START_PRESS "Press to start"
#define LBL_BATTERY "Bat: "

#define LBL_WHOSERVES "Who serves?"
#define LBL_RESTART " Restart "

#define LBL_SEPARATOR ":"
#define LBL_SPACE " "
#define LBL_ZERO "0"
#define LBL_PERCENT "%"

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
static char *LBL_PLAYER[] = {LBL_THEM, LBL_US, LBL_NONE};

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

// Labels for the buttons
#define LBL_BUT_MODE "MODE"
#define LBL_BUT_BACK "BACK"
#define LBL_BUT_THEM "THEM"
#define LBL_BUT_US "US"

// create the labels for the
#define LBL_MENU_PLAY "Play"
#define LBL_MENU_STATS "Stats"
#define LBL_MENU_RESTART "Restart"

// Class provides the view functionality.
class YscoreView : public IYscoreView
{
public:
  YscoreView(TinyScreenExt &display);

  // sets the model from which values can be
  // retrieved for the view
  void setModel(YscoreModel *model);

  // method updates the view according to the current model
  void update();
  // method updates the view of the battery
  void updateBattery();
  // method updates the view of the time
  void updateTime();

private:
  // draw the start screen
  void drawScreenStart();
  // drow the setting the serve screen
  void drawScreenSettingsServe();
  // draw the playing screen
  void drawScreenPlaying();
  // draw the winningscreen
  void drawScreenWinning();
  // draw the stats screen
  void drawScreenStats(bool runningPoints);
  // draw the playing time screen
  void drawScreenPlayingTime();
  // draw the settings type of match screen
  void drawScreenSettingTypeOfMatch();
  // draw the settings language
  void drawScreenSettingLanguage();
  // draw the settings brightness
  void drawScreenSettingBrightness();
  // draw the settings handedness
  void drawScreenSettingHandedness();
  // draw the about screen
  void drawScreenAbout();
  // draw the ack Scree
  void drawScreenAck();
  // draw the update Screen
  void drawScreenUpdate();

  ///////////////////////////////////////////
  // Elements of screens
  ///////////////////////////////////////////

  // draw the who serves
  void drawWhoServes();
  // draw the game scores for the given player
  // if the running Points is true the last value
  // are the current points in the game
  void drawStatsGameScoresAt(uint8_t x, uint8_t y, uint8_t who, bool runningPoints);
  // draw the playing grid
  void drawPlayingGrid();
  // draw the playing score
  void drawPlayingScore();
  // draw the number of sets for each team
  void drawPlayingScoreGames();
  // draw the current points for each team
  void drawPlayingScorePoints();
  // draw the arrow indicating serve
  void drawPlayingServe();
  // draw the players playing the game
  void drawPlayingPlayers();
  // draw the players stats
  void drawStatsPlayers();
  // draw the winning players of the match
  void drawWinningPlayers();
  // draw the Stats grid
  void drawStatsGrid();

  ///////////////////////////////////////////////
  // Screen "Widgets"
  ///////////////////////////////////////////////
  // draw the frame (Menu + button labels)
  void drawFrame(const tImage *image);

  // draw a menu
  void drawMenu(const tImage *image);

  // draw the restart
  void drawRestart();

  // draw the button labels
  void drawButtonLabels();

  // draw the battery icon
  void drawBatteryIcon(uint8_t x, uint8_t y);

  // print a time given in millis
  void printTime(uint8_t hours, uint8_t minutes, uint8_t seconds);

  ///////////////////////////////////////////////
  // Convenience functions for handeling numbers
  ///////////////////////////////////////////////

  // put the zero padded value into the provided buffer
  char *zeroPad(char *buffer, uint8_t value);

  TinyScreenExt &_display;
  YscoreModel *_model = NULL;
};

#endif
