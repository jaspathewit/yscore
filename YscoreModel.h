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

// #include "IYscoreView.h"
#include "TinyScreenExt.h"
#include "YscoreViewInterface.h"

#ifndef YScoreModel_h
#define YScoreModel_h

// // button state
// #define BUTTON_MODE TSButtonUpperLeft
// #define BUTTON_US TSButtonUpperRight
// #define BUTTON_THEM TSButtonLowerRight
// #define BUTTON_BACK TSButtonLowerLeft

// The application states
#define APP_STATE_UNDEF 0
#define APP_STATE_STARTING 1
#define APP_STATE_SETTING_SERVE 2
#define APP_STATE_PLAYING 3
#define APP_STATE_WINNING 4
#define APP_STATE_PAUSING 5
#define APP_STATE_PAUSING_TIME 6
#define APP_STATE_STATS 7
#define APP_STATE_STATS_TIME 8
#define APP_STATE_SETTING_TYPE_OF_MATCH 9
#define APP_STATE_SETTING_LANGUAGE 10
#define APP_STATE_SETTING_BRIGHTNESS 11
#define APP_STATE_SETTING_HANDEDNESS 12
#define APP_STATE_ABOUT 13
#define APP_STATE_ACK 14
#define APP_STATE_UPDATE 15

// values for settings
#define TYPE_OF_MATCH_DOUBLES 0
#define TYPE_OF_MATCH_SINGLES 1

#define BRIGHTNESS_VERY_DARK 0
#define BRIGHTNESS_DARK 1
#define BRIGHTNESS_NORMAL 2
#define BRIGHTNESS_BRIGHT 3
#define BRIGHTNESS_VERY_BRIGHT 4

// map brightness levels to actual display brightness levels
const uint8_t DISPLAY_BRIGHTNESS[] = {2, 6, 10, 12, 15};

// The button states
// pressed are odd values so that
// testing the LSB indicates that
// the button was pressed
#define BUT_STATE_UNPRESSED 0
#define BUT_STATE_PRESSED 1

// The maximum number of scores that need to be stored
#define SCOREPAD_MAX_SIZE 180
#define SUMMARYPAD_MAX_SIZE 3
#define NULL_SCOREPAD_IDX 0xFF
#define FIRST_GAME 0
#define SECOND_GAME 1
#define THIRD_GAME 2

// define values for updating us, them and none
// THEM and US are also used as indexes into the
// scorepad
#define THEM 0
#define US 1
#define NONE 2

// index into the scorepad for the Player
// position data
#define PLAYER 2

// define the various bit masks to get and set values
// scorepad contains 3 uint8_t values
// uint8_t [THEM]
// 1 bit EndOfGame marker 1 = true (row in scorepad is at the end of a game)
// 2 bits number of games (maximum of 2)
// 5 bits points (to a max of 30)

// uint8_t [US]
// 2 bits number of games (maximum of 2)
// 5 bits points to a max of 30

// uint8_t [PLAYER]
// 1 bit has serve (of the US uint8_t) (0 = THEY have the serve, 1 US has the serve)
// 1 bit position of Players THEM (0 = BLUE, GREEN 1 = GREEN, BLUE)
// 1 bit position of Players US (0 = RED, YELLOW, 1 = YELLOW, RED)

#define MASK_8TH_BIT_ON B10000000
#define MASK_8TH_BIT_OFF B01111111
#define MASK_1ST_BIT_ON B00000001
#define MASK_1ST_BIT_OFF B11111110
#define MASK_2ND_BIT_ON B00000010
#define MASK_2ND_BIT_OFF B11111101
#define MASK_3RD_BIT_ON B00000100
#define MASK_3RD_BIT_OFF B11111011

#define MASK_GAMES B01100000
#define MASK_POINTS B00011111
#define MASK_NOT_POINTS B11100000

// the value that needs to be added to a uint8_t to "add" a game
#define ONE_GAME 0x20

// // map the TSButtons (for the display flip)
// uint8_t TSButtonMode = TSButtonUpperLeft;
// uint8_t TSButtonBack = TSButtonLowerLeft;
// uint8_t TSButtonThem = TSButtonUpperRight;
// uint8_t TSButtonUs = TSButtonLowerRight;

// start in an unknown state application states
// uint8_t appState = APP_STATE_UNDEF;

// indicates when the model has changed
// bool modelChanged = false;

// the button states
// uint8_t buttonStateMode = BUT_STATE_UNPRESSED;
// uint8_t buttonStateBack = BUT_STATE_UNPRESSED;
// uint8_t buttonStateUs = BUT_STATE_UNPRESSED;
// uint8_t buttonStateThem = BUT_STATE_UNPRESSED;

// Class provides the model functionality.
class YscoreModel
{
public:
  YscoreModel(TinyScreenExt &display);

  void setView(IYscoreView *view);
  void updateBatteryState();
  uint8_t getBatteryState();

  void setAppState(uint8_t appState);
  uint8_t getAppState();

  // resets the current playing time
  void startPlayingTime();
  // update the time (Hours, minutes, seconds)
  void updateTime();
  // returns the current playing hours
  uint8_t getPlayingHours();
  // return the current playing minutes
  uint8_t getPlayingMinutes();
  // return the current playing seconds
  uint8_t getPlayingSeconds();

  uint8_t getScorepadIdx();
  // resets all the values in the scorepad to zero
  // TODO check if it is suficient to just set the
  // first row to 000
  void resetScorepad();

  // function increments the score pad index
  void incScorepadIdx();
  // function decrements the score pad index
  // taking into account the EndOfGameMarker
  // if there is one
  void decScorepadIdx();

  // function creates the summary table from the scorepad
  void createSummaryTable();
  // returns the summary pad
  uint8_t getPointsIndex(uint8_t index);

  // returns true if play has started ie one point has been made false if not
  uint8_t hasPlayStarted();

  // adds one to the number of points scorepad row at the given index for the given player
  void incPoints(uint8_t who);

  // gets the current number of games for the given player
  uint8_t getGames(uint8_t who);
  // gets the current points from for the given player
  uint8_t getPoints(uint8_t who);
  // gets the points from the  scorepad row at the given index for the given player
  uint8_t getPoints(uint8_t who, uint8_t index);

  // set the serve for the given player
  void setServe(uint8_t who);
  // gets the serve status for the given player
  bool hasServe(uint8_t who);

  // gets the serve status for the given player
  uint8_t getPlayerPosition();

  // gets the identity of the winner
  uint8_t getWinner();

  // settings
  void incTypeOfMatch();
  void decTypeOfMatch();
  uint8_t getTypeOfMatch();

  void incBrightness();
  void decBrightness();
  uint8_t getBrightness();

private:
  // update the view
  void updateView();
  // update the battery view
  void updateViewBattery();
  // update the time view
  void updateViewTime();

  // check if a game was won
  void checkGameWon();
  // check if a game was won by lhs as compared to rhs
  // if the game was won by the lhs return lhs else
  // return NONE, basically this determines if lhs
  // won a game. It makes no statement about the rhs
  // this must be tested for separatly
  uint8_t checkGameWonBy(uint8_t lhs, uint8_t rhs);
  // check if a match was won
  void checkMatchWon();

  // copy the score pad row reseting the has serve bit and EndOfGame at the same time
  void copyScorepadRowTo(uint8_t from, uint8_t to);
  // copy the score pad row keeping the serve and the games
  void copyScorepadNewGameRowTo(uint8_t from, uint8_t to);

  // resets all the values in the summarypad to NULL_SCOREPAD_IDX
  void resetSummarypad();

  //////////////////////////////////////////////////////////////////
  // manage data extraction and setting of values from the score pad
  //////////////////////////////////////////////////////////////////

  // gets the serve status at the given index for the given player
  inline bool hasServe(uint8_t who, uint8_t index);

  // sets the uint8_t serve bit of the scorepad row at the given index off or on
  // depending on who has the serve
  inline void setServe(uint8_t index, uint8_t who);

  // sets the THEM uint8_t EndOfGame bit of the scorepad row at the given index on
  void endOfGameOn(uint8_t index);
  // gets the THEM uint8_t EndOfGame bit of the scorepad row at the given index on
  bool isEndOfGame(uint8_t index);
  // gets the number of games from the  scorepad row at the given index for the given player
  uint8_t getGames(uint8_t index, uint8_t who);
  // adds one to the number of games given index for the given player
  void incGames(uint8_t index, uint8_t who);

  // adds one to the number of points scorepad row at the given index for the given player
  void incPoints(uint8_t index, uint8_t who);

  uint8_t _appState = APP_STATE_UNDEF;
  // current battery state
  uint8_t _batteryState = 0;

  // the score pad
  uint8_t _scorepad[SCOREPAD_MAX_SIZE][3];

  // the current index into the scorepad
  uint8_t _scorepadIdx = 0;

  // the indexes into the scorepad of where games where won
  uint8_t _summaryPad[SUMMARYPAD_MAX_SIZE];

  // playing time
  uint8_t _hours;
  uint8_t _minutes;
  uint8_t _seconds;

  // who won the match
  uint8_t _winner = NONE;

  // Settings
  // type of match DOUBLES / SINGLES
  uint8_t _typeOfMatch = TYPE_OF_MATCH_DOUBLES;
  // Brightness
  uint8_t _brightness = BRIGHTNESS_NORMAL;

  TinyScreenExt &_display;
  IYscoreView *_view = NULL;
};

#endif
