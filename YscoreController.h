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

#include "TinyScreenExt.h"
#include "YscoreModel.h"

#ifndef YScoreController_h
#define YScoreController_h

// // Screen dimensions and locations
// #define SCREEN_MENU_MARGIN_Y 10

// #define SCREEN_BATTERY_X 82

// #define SCREEN_BUTTON_LEFT_MARGIN_X 7
// #define SCREEN_BUTTON_TOP_Y 13
// #define SCREEN_BUTTON_BOTTOM_Y 48

// #define SCREEN_BUTTON_RIGHT_MARGIN_X 88

// #define SCREEN_MIDDLE_LINE_Y 37

// #define SCREEN_GAMES_LINE_X 42
// #define SCREEN_POINTS_LINE_X 59

// #define SCREEN_SERVE_X 14
// #define SCREEN_SERVE_Y 26

// #define SCREEN_PLAYER_LEFT_X 10
// #define SCREEN_PLAYER_RIGHT_X 27
// #define SCREEN_PLAYER_TOP_Y 13
// #define SCREEN_PLAYER_BOTTOM_Y 48

// #define SCREEN_STATS_PLAYER_LEFT_X 9
// #define SCREEN_STATS_PLAYER_RIGHT_X 23
// #define SCREEN_STATS_PLAYER_TOP_Y 13
// #define SCREEN_STATS_PLAYER_BOTTOM_Y 31

// #define SCREEN_STATS_SCORE_LEFT_X 40
// #define SCREEN_STATS_SCORE_TOP_Y 15
// #define SCREEN_STATS_SCORE_BOTTOM_Y 33

// #define SCREEN_STATS_MIDDLE_LINE_Y 28
// #define SCREEN_STATS_BOTTOM_LINE_Y 46

// #define SCREEN_STATS_POINTS_LINE1_X 37
// #define SCREEN_STATS_POINTS_LINE2_X 54
// #define SCREEN_STATS_POINTS_LINE3_X 71

// #define SCREEN_TIME_X 10
// #define SCREEN_TIME_Y 15

// // offset from screen margins
// #define SCREEN_MARGIN_OFFSET_X 4
// #define SCREEN_MARGIN_OFFSET_Y 6

// // button state
// #define BUTTON_MODE TSButtonUpperLeft
// #define BUTTON_US TSButtonUpperRight
// #define BUTTON_THEM TSButtonLowerRight
// #define BUTTON_BACK TSButtonLowerLeft

// // The application states
// #define APP_STATE_UNDEF 0
// #define APP_STATE_STARTING 1
// #define APP_STATE_SET_SERVE 2
// #define APP_STATE_PLAYING 3
// #define APP_STATE_WINNING 4
// #define APP_STATE_PAUSING 5
// #define APP_STATE_PAUSING_TIME 6
// #define APP_STATE_STATS 7
// #define APP_STATE_STATS_TIME 8
// #define APP_STATE_CONFIG_DOUBLES 9

// // The button states
// // pressed are odd values so that
// // testing the LSB indicates that
// // the button was pressed
// #define BUT_STATE_UNPRESSED 0
// #define BUT_STATE_PRESSED 1

// // The number of milliseconds for a long press
// #define LONG_PRESS_TIME 500

// // define the labels used in the application
// #define LBL_TITLE "iScore"
// #define LBL_COPYRIGHT "1.0 (c) J. Hewitt"
// //  Battery: 100%
// #define LBL_TO_START_PRESS "Press to start"
// #define LBL_BATTERY "Bat: "

// #define LBL_WHOSERVES "Who serves?"
// #define LBL_RESTART " Restart "

// #define LBL_SEPARATOR ":"
// #define LBL_SPACE " "
// #define LBL_ZERO "0"
// #define LBL_PERCENT "%"

// // define the modifyable labels
// #define LBL_US " US  "
// #define LBL_THEM " THEM"
// #define LBL_NONE " NONE"

// #define LBL_YOU "YOU "
// #define LBL_PLAYING_TIME "Time Played"

// // "text" when it is in MarVoSym font are the
// // Up Down left and right arrows
// #define LBL_UP_ARROW "C"
// #define LBL_DOWN_ARROW "D"
// #define LBL_LEFT_ARROW "A"
// #define LBL_RIGHT_ARROW "B"

// #define LBL_UPDOWN_ARROW "CD"

// // Player Names
// static char *LBL_PLAYER[] = {LBL_THEM, LBL_US, LBL_NONE};

// static const tImage *IMG_SERVE[][2] = {{&img_Serve_BR, &img_Serve_BL},
//                                        {&img_Serve_TL, &img_Serve_TR}};

// static const tImage *IMG_PLAYER_DOUBLES[][4] = {{&img_Happy_blue, &img_Happy_green, &img_Sad_red, &img_Sad_yellow},
//                                                 {&img_Sad_blue, &img_Sad_green, &img_Happy_red, &img_Happy_yellow},
//                                                 {&img_Happy_blue, &img_Happy_green, &img_Sad_yellow, &img_Sad_red},
//                                                 {&img_Sad_blue, &img_Sad_green, &img_Happy_yellow, &img_Happy_red},
//                                                 {&img_Happy_green, &img_Happy_blue, &img_Sad_red, &img_Sad_yellow},
//                                                 {&img_Sad_green, &img_Sad_blue, &img_Happy_red, &img_Happy_yellow},
//                                                 {&img_Happy_green, &img_Happy_blue, &img_Sad_yellow, &img_Sad_red},
//                                                 {&img_Sad_green, &img_Sad_blue, &img_Happy_yellow, &img_Happy_red}};

// static const tImage *IMG_WINNING_PLAYER[][2] = {{&img_Happy_blue, &img_Happy_green},
//                                                 {&img_Happy_red, &img_Happy_yellow}};

// static const tImage *IMG_STATS_PLAYER[][4] = {{&img_Happy_blue, &img_Happy_green, &img_Happy_red, &img_Happy_yellow},
//                                               {&img_Happy_blue, &img_Happy_green, &img_Sad_red, &img_Sad_yellow},
//                                               {&img_Sad_blue, &img_Sad_green, &img_Happy_red, &img_Happy_yellow}};

// // static const char* LBL_SERVE[][2] = {{">", "<"}, {"<", ">"}};

// // The maximum number of scores that need to be stored
// #define SCOREPAD_MAX_SIZE 180
// #define SUMMARYPAD_MAX_SIZE 3
// #define NULL_SCOREPAD_IDX 0xFF
// #define FIRST_GAME 0
// #define SECOND_GAME 1
// #define THIRD_GAME 2

// // define values for updating us, them and none
// // THEM and US are also used as indexes into the
// // scorepad
// #define THEM 0
// #define US 1
// #define NONE 2

// // index into the scorepad for the Player
// // position data
// #define PLAYER 2

// // define the various bit masks to get and set values
// // scorepad contains 3 uint8_t values
// // uint8_t [THEM]
// // 1 bit EndOfGame marker 1 = true (row in scorepad is at the end of a game)
// // 2 bits number of games (maximum of 2)
// // 5 bits points (to a max of 30)

// // uint8_t [US]
// // 2 bits number of games (maximum of 2)
// // 5 bits points to a max of 30

// // uint8_t [PLAYER]
// // 1 bit has serve (of the US uint8_t) (0 = THEY have the serve, 1 US has the serve)
// // 1 bit position of Players THEM (0 = BLUE, GREEN 1 = GREEN, BLUE)
// // 1 bit position of Players US (0 = RED, YELLOW, 1 = YELLOW, RED)

// #define MASK_8TH_BIT_ON B10000000
// #define MASK_8TH_BIT_OFF B01111111
// #define MASK_1ST_BIT_ON B00000001
// #define MASK_1ST_BIT_OFF B11111110
// #define MASK_2ND_BIT_ON B00000010
// #define MASK_2ND_BIT_OFF B11111101
// #define MASK_3RD_BIT_ON B00000100
// #define MASK_3RD_BIT_OFF B11111011

// #define MASK_GAMES B01100000
// #define MASK_POINTS B00011111
// #define MASK_NOT_POINTS B11100000

// // the value that needs to be added to a uint8_t to "add" a game
// #define ONE_GAME 0x20

// // #define VBATPIN A9

// // Using software SPI (the default case) for driving the display:
// // #define OLED_MOSI   5
// // #define OLED_CLK   10
// // #define OLED_DC    11
// // #define OLED_CS    12
// // #define OLED_RESET 13

// // create the display
// // Adafruit_SSD1306 Display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// //Get the display to be used
// //Library must be passed the board type
// //TinyScreenDefault for TinyScreen shields
// //TinyScreenAlternate for alternate address TinyScreen shields
// //TinyScreenPlus for TinyScreen+
// TinyScreenExt display = TinyScreenExt(TinyScreenPlus);

// // Labels for the buttons
// #define LBL_BUT_MODE "MODE"
// #define LBL_BUT_BACK "BACK"
// #define LBL_BUT_THEM "THEM"
// #define LBL_BUT_US "US"

// // create the labels for the
// #define LBL_MENU_PLAY "Play"
// #define LBL_MENU_STATS "Stats"
// #define LBL_MENU_RESTART "Restart"

// map the TSButtons (for the display flip)
uint8_t TSButtonMode = TSButtonUpperLeft;
uint8_t TSButtonBack = TSButtonLowerLeft;
uint8_t TSButtonThem = TSButtonUpperRight;
uint8_t TSButtonUs = TSButtonLowerRight;

// Class provides the controler functionality.
class YscoreController
{
public:
  YscoreController(TinyScreenExt display);

  void setModel(YscoreModel model);
  // Perform the action
  void performAction();

  // void begin(void);
  // void setFlip(uint8_t flip);
  // void setBrightness(uint8_t);

  // // hardware Buttons
  // uint8_t getButtons(void);

  // // hardware battery
  // uint8_t getBatteryState();
  // float getVoltage();

  // // Anti aliased Font handeling
  // void setFont(const tFont &);
  // uint8_t getFontHeight(const tFont &);
  // uint8_t getFontHeight(void);
  // uint8_t getPrintWidth(char *);
  // void setCursor(uint8_t, uint8_t);
  // void fontColor(uint16_t, uint16_t);
  // tPoint printAt(uint8_t x, uint8_t y, char *str);
  // tPoint printCenteredAt(uint8_t y, char *str);
  // tPoint printVerticalAt(uint8_t x, uint8_t y, char *str);
  // virtual size_t write(uint8_t);

  // //drawing commands
  // //   void drawLine(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  // void drawLine(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);
  // //   void drawRect(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  // void drawRect(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);
  // //   void clearWindow(uint8_t, uint8_t, uint8_t, uint8_t);
  // tPoint drawImageAt(uint8_t x, uint8_t y, const tImage *image);
  // void clearScreen(void);

  // static const uint8_t xMin = 0;
  // static const uint8_t yMin = 0;
  // static const uint8_t xMax = 95;
  // static const uint8_t yMax = 63;

private:
  void _init(TinyScreenExt display);

  TinyScreenExt _display = 0;

  // the button states
  uint8_t buttonStateMode = BUT_STATE_UNPRESSED;
  uint8_t buttonStateBack = BUT_STATE_UNPRESSED;
  uint8_t buttonStateUs = BUT_STATE_UNPRESSED;
  uint8_t buttonStateThem = BUT_STATE_UNPRESSED;

  // define the button previous states
  bool prevStateMode = false;
  bool prevStateBack = false;
  bool prevStateThem = false;
  bool prevStateUs = false;
};

///////////////////////////
// Handle the Button states
///////////////////////////

// update the button states
void updateButtonStates()
{
  // get the current state of the all buttons
  int8_t buttons = display.getButtons();

  bool curStateMode = (buttons & TSButtonMode) > 0;
  bool curStateBack = (buttons & TSButtonBack) > 0;
  bool curStateThem = (buttons & TSButtonThem) > 0;
  bool curStateUs = (buttons & TSButtonUs) > 0;

  // determine what the button states are
  buttonStateMode = readButtonState(prevStateMode, curStateMode);
  buttonStateBack = readButtonState(prevStateBack, curStateBack);
  buttonStateUs = readButtonState(prevStateUs, curStateUs);
  buttonStateThem = readButtonState(prevStateThem, curStateThem);

  // update the prev states with the current state
  prevStateMode = curStateMode;
  prevStateBack = curStateBack;
  prevStateThem = curStateThem;
  prevStateUs = curStateUs;

  // printButtonStates();
}

// update the button states
void updateButtonStatesSequence()
{
  bool curStateMode = false;
  bool curStateBack = false;
  bool curStateThem = false;
  bool curStateUs = false;

  long button = random(0, 12);

  if (button == 0)
  {
    buttonStateMode = BUT_STATE_PRESSED;
    curStateMode = true;
  }

  if (button == 1)
  {
    buttonStateBack = BUT_STATE_PRESSED;
    curStateBack = true;
  }

  if (button > 2 && button < 7)
  {
    buttonStateUs = BUT_STATE_PRESSED;
    curStateUs = true;
  }

  if (button > 7)
  {
    buttonStateThem = BUT_STATE_PRESSED;
    curStateThem = true;
  }

  // update the prev states with the current state
  prevStateMode = curStateMode;
  prevStateBack = curStateBack;
  prevStateThem = curStateThem;
  prevStateUs = curStateUs;
}

void printButtonStates()
{
  display.setFont(SansSerif_8pt);
  display.setCursor(0, 50);
  display.print("M ");
  printButtonState(buttonStateMode);
  display.print("B ");
  printButtonState(buttonStateBack);
  display.print("T ");
  printButtonState(buttonStateThem);
  display.print("U ");
  printButtonState(buttonStateUs);
}

void printButtonState(uint8_t buttonState)
{
  if (buttonState == BUT_STATE_PRESSED)
  {
    display.print("p ");
  }
  else
  {
    display.print("u ");
  }
}

// update the button state for a single button
uint8_t readButtonState(bool prevState, bool currState)
{
  // if our state changed and we are not pressed now
  // then the button was released (so it had been pressed)
  if (prevState != currState && currState == false)
  {
    return BUT_STATE_PRESSED;
  }
  return BUT_STATE_UNPRESSED;
}

// function resets all button states to BUT_STATE_UNPRESSED
// void resetButtonState()
// {
//   buttonStateMode = BUT_STATE_UNPRESSED;
//   buttonStateBack = BUT_STATE_UNPRESSED;
//   buttonStateUs = BUT_STATE_UNPRESSED;
//   buttonStateThem = BUT_STATE_UNPRESSED;
// }

////////////////////////////////////////
// Perform Actions depending on AppState
// and button state
////////////////////////////////////////

// perform action
void performAction()
{

  switch (appState)
  {
  case APP_STATE_STARTING:
    performActionStarting();
    break;
  case APP_STATE_SET_SERVE:
    performActionSettingServe();
    break;
  case APP_STATE_PLAYING:
    performActionPlaying();
    break;
  case APP_STATE_PAUSING:
    performActionPausing();
    break;
  case APP_STATE_PAUSING_TIME:
    performActionPausingTime();
    break;
  case APP_STATE_WINNING:
    performActionWinning();
    break;
  case APP_STATE_STATS:
    performActionStats();
    break;
  case APP_STATE_STATS_TIME:
    performActionStatsTime();
    break;
  }
}

// perform the default action for all app states
void performActionDefault()
{
}

// deform the action for the App_Starting state
// must set modelChanged if the model is changed by this action
void performActionStarting()
{
  if ((buttonStateMode == BUT_STATE_PRESSED) || (buttonStateBack == BUT_STATE_PRESSED) || (buttonStateThem == BUT_STATE_PRESSED) || (buttonStateUs == BUT_STATE_PRESSED))
  {
    appState = APP_STATE_SET_SERVE;
    modelChanged = true;
    return;
  }
}

// peform the action for the app setting state
// must set modelChanged if the model in changed by this action
void performActionSettingServe()
{

  // check for go back
  if (buttonStateBack == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_STARTING;
    modelChanged = true;
    return;
  }

  // check for do nothing
  bool doNothing = checkDoNothing();
  if (doNothing)
  {
    return;
  }

  uint8_t whoToUpdate = NONE;

  if (buttonStateUs == BUT_STATE_PRESSED)
  {
    whoToUpdate = US;
  }

  if (buttonStateThem == BUT_STATE_PRESSED)
  {
    whoToUpdate = THEM;
  }

  setServe(scorepadIdx, whoToUpdate);
  startTime = millis();
  // JHW Temp
  appState = APP_STATE_PLAYING;
  // appState = APP_STATE_WINNING;
  // winner = THEM;
  modelChanged = true;
}

// perform the action for the app playing state
// must set modelChanged if the model in changed by this action
void performActionPlaying()
{
  //printDebug(scorepadIdx);

  if (buttonStateMode == BUT_STATE_PRESSED)
  {
    createSummaryTable();
    playingTime = millis() - startTime;
    appState = APP_STATE_PAUSING;
    modelChanged = true;
    return;
  }

  if (buttonStateBack == BUT_STATE_PRESSED)
  {
    // We want to go back and no points have been scored
    if (scorepadIdx == 0)
    {
      appState = APP_STATE_SET_SERVE;
      resetScorepad();
    }
    else
    {
      decScorepadIdx();
    }
    modelChanged = true;
    return;
  }

  // check for do nothing
  bool doNothing = checkDoNothing();
  if (doNothing)
  {
    return;
  }

  uint8_t whoToUpdate = NONE;

  if (buttonStateUs == BUT_STATE_PRESSED)
  {
    whoToUpdate = US;
  }

  if (buttonStateThem == BUT_STATE_PRESSED)
  {
    whoToUpdate = THEM;
  }

  copyScorepadRowTo(scorepadIdx, scorepadIdx + 1);
  incScorepadIdx();
  // update the score and who has the serve
  setServe(scorepadIdx, whoToUpdate);
  incPoints(scorepadIdx, whoToUpdate);
  modelChanged = true;
  checkGameWon();
}

// check if a game was won
void checkGameWon()
{

  // first check if a game was won by US
  uint8_t whoToUpdate = checkGameWonBy(US, THEM);
  if (whoToUpdate == NONE)
  {
    whoToUpdate = checkGameWonBy(THEM, US);
  }

  // uint8_t whoToUpdate = NONE;

  // // get the points
  // uint8_t usPoints = getPoints(scorepadIdx, US);
  // uint8_t themPoints = getPoints(scorepadIdx, THEM);

  // // US got to 21 points before THEM
  // if (usPoints == 21 && themPoints < 20) {
  //   whoToUpdate = US;
  // }

  // if (themPoints == 21 && usPoints < 20) {
  //   whoToUpdate = THEM;
  // }

  // // US got passed 21 and two points in the lead
  // if (usPoints > 21 && (usPoints - themPoints) >=2 ) {
  //   whoToUpdate = US;
  // }

  // if (themPoints > 21 && (themPoints - usPoints) >=2 ) {
  //   whoToUpdate = THEM;
  // }

  // // check for defacto winner at 30 points
  // if (usPoints == 30) {
  //   whoToUpdate = US;
  // }

  // if (themPoints == 30) {
  //   whoToUpdate = THEM;
  // }

  // perform the update
  if (whoToUpdate != NONE)
  {
    // mark this scorepad as an end of game
    endOfGameOn(scorepadIdx);
    copyScorepadNewGameRowTo(scorepadIdx, scorepadIdx + 1);
    incScorepadIdx();
    incGames(scorepadIdx, whoToUpdate);
    modelChanged = true;
    checkMatchWon();
  }
}

// check if a game was won by lhs as compared to rhs
// if the game was won by the lhs return lhs else
// return NONE, basically this determines if lhs
// won a game. It makes no statement about the rhs
// this must be tested for separatly
uint8_t checkGameWonBy(uint8_t lhs, uint8_t rhs)
{
  uint8_t result = NONE;

  // get the points
  uint8_t lhsPoints = getPoints(scorepadIdx, lhs);
  uint8_t rhsPoints = getPoints(scorepadIdx, rhs);

  // lhs got to 21 points before rhs
  if (lhsPoints == 21 && rhsPoints < 20)
  {
    result = lhs;
  }

  // lhs got passed 21 and is two points in the lead
  if (lhsPoints > 21 && (lhsPoints - rhsPoints) >= 2)
  {
    result = lhs;
  }

  // check for defacto winner at 30 points
  if (lhsPoints == 30)
  {
    result = lhs;
  }

  return result;
}

// check if a match was won
void checkMatchWon()
{
  uint8_t whoToUpdate = NONE;
  // get the games
  uint8_t usGames = getGames(scorepadIdx, US);
  uint8_t themGames = getGames(scorepadIdx, THEM);

  // US got to 2 games before THEM
  if (usGames == 2)
  {
    whoToUpdate = US;
  }

  if (themGames == 2)
  {
    whoToUpdate = THEM;
  }

  // perform the update
  if (whoToUpdate != NONE)
  {
    // mark this scorepad as an end of game
    // endOfGameOn(scorepadIdx);
    // incScorepadIdx();
    // record the winner
    winner = whoToUpdate;
    createSummaryTable();
    playingTime = millis() - startTime;
    appState = APP_STATE_WINNING;
    modelChanged = true;
  }
}

// return true if neither the us and them buttons were pressed or
// both were pressed
bool checkDoNothing()
{
  // either both buttons were pressed or neither button was pressed
  return buttonStateUs == buttonStateThem;
}

// perform the action for the App_Winning state
// must set modelChanged if the model in changed by this action
void performActionWinning()
{
  // show the stats
  if (buttonStateMode == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_STATS;
    modelChanged = true;
    return;
  }

  // We have not won yet
  if (buttonStateBack == BUT_STATE_PRESSED)
  {
    decScorepadIdx();
    appState = APP_STATE_PLAYING;
    modelChanged = true;
    return;
  }

  // us or them restart
  if (buttonStateUs == BUT_STATE_PRESSED || buttonStateThem == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_SET_SERVE;
    resetScorepad();
    modelChanged = true;
    return;
  }

  return;
}

// perform the action for the App_Stats state
// must set modelChanged if the model is changed by this action
void performActionStats()
{
  if (buttonStateBack == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_WINNING;
    modelChanged = true;
    return;
  }

  if (buttonStateMode == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_STATS_TIME;
    modelChanged = true;
    return;
  }

  // us or them restart
  if (buttonStateUs == BUT_STATE_PRESSED || buttonStateThem == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_SET_SERVE;
    resetScorepad();
    modelChanged = true;
    return;
  }
}

// perform the action for the App_Stats_time state
// must set modelChanged if the model is changed by this action
void performActionStatsTime()
{
  if (buttonStateBack == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_STATS;
    modelChanged = true;
    return;
  }

  // us or them restart
  if (buttonStateUs == BUT_STATE_PRESSED || buttonStateThem == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_SET_SERVE;
    resetScorepad();
    modelChanged = true;
    return;
  }
}

// perform the action for the App_Pausing state
// must set modelChanged if the model in changed by this action
void performActionPausing()
{
  if (buttonStateBack == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_PLAYING;
    modelChanged = true;
    return;
  }

  if (buttonStateMode == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_PAUSING_TIME;
    modelChanged = true;
    return;
  }

  // us or them restart
  if (buttonStateUs == BUT_STATE_PRESSED || buttonStateThem == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_SET_SERVE;
    resetScorepad();
    modelChanged = true;
    return;
  }
}

// perform the action for the App_Pausing_Time state
// must set modelChanged if the model in changed by this action
void performActionPausingTime()
{
  if (buttonStateBack == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_PAUSING;
    modelChanged = true;
    return;
  }

  // us or them restart
  if (buttonStateUs == BUT_STATE_PRESSED || buttonStateThem == BUT_STATE_PRESSED)
  {
    appState = APP_STATE_SET_SERVE;
    resetScorepad();
    modelChanged = true;
    return;
  }
}

#endif