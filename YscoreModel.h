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

#ifndef YScoreModel_h
#define YScoreModel_h

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

// button state
#define BUTTON_MODE TSButtonUpperLeft
#define BUTTON_US TSButtonUpperRight
#define BUTTON_THEM TSButtonLowerRight
#define BUTTON_BACK TSButtonLowerLeft

// The application states
#define APP_STATE_UNDEF 0
#define APP_STATE_STARTING 1
#define APP_STATE_SET_SERVE 2
#define APP_STATE_PLAYING 3
#define APP_STATE_WINNING 4
#define APP_STATE_PAUSING 5
#define APP_STATE_PAUSING_TIME 6
#define APP_STATE_STATS 7
#define APP_STATE_STATS_TIME 8
#define APP_STATE_CONFIG_DOUBLES 9

// The button states
// pressed are odd values so that
// testing the LSB indicates that
// the button was pressed
#define BUT_STATE_UNPRESSED 0
#define BUT_STATE_PRESSED 1

// The number of milliseconds for a long press
#define LONG_PRESS_TIME 500

// define the labels used in the application
#define LBL_TITLE "iScore"
#define LBL_COPYRIGHT "1.0 (c) J. Hewitt"
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

static const tImage *IMG_STATS_PLAYER[][4] = {{&img_Happy_blue, &img_Happy_green, &img_Happy_red, &img_Happy_yellow},
                                              {&img_Happy_blue, &img_Happy_green, &img_Sad_red, &img_Sad_yellow},
                                              {&img_Sad_blue, &img_Sad_green, &img_Happy_red, &img_Happy_yellow}};

// static const char* LBL_SERVE[][2] = {{">", "<"}, {"<", ">"}};

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

// #define VBATPIN A9

// Using software SPI (the default case) for driving the display:
// #define OLED_MOSI   5
// #define OLED_CLK   10
// #define OLED_DC    11
// #define OLED_CS    12
// #define OLED_RESET 13

// create the display
// Adafruit_SSD1306 Display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//Get the display to be used
//Library must be passed the board type
//TinyScreenDefault for TinyScreen shields
//TinyScreenAlternate for alternate address TinyScreen shields
//TinyScreenPlus for TinyScreen+
TinyScreenExt display = TinyScreenExt(TinyScreenPlus);

// Labels for the buttons
#define LBL_BUT_MODE "MODE"
#define LBL_BUT_BACK "BACK"
#define LBL_BUT_THEM "THEM"
#define LBL_BUT_US "US"

// create the labels for the
#define LBL_MENU_PLAY "Play"
#define LBL_MENU_STATS "Stats"
#define LBL_MENU_RESTART "Restart"

// map the TSButtons (for the display flip)
uint8_t TSButtonMode = TSButtonUpperLeft;
uint8_t TSButtonBack = TSButtonLowerLeft;
uint8_t TSButtonThem = TSButtonUpperRight;
uint8_t TSButtonUs = TSButtonLowerRight;

// define the button previous states
bool prevStateMode = false;
bool prevStateBack = false;
bool prevStateThem = false;
bool prevStateUs = false;

// start in an unknown state application states
uint8_t appState = APP_STATE_UNDEF;

// indicates when the model has changed
bool modelChanged = false;

// the button states
uint8_t buttonStateMode = BUT_STATE_UNPRESSED;
uint8_t buttonStateBack = BUT_STATE_UNPRESSED;
uint8_t buttonStateUs = BUT_STATE_UNPRESSED;
uint8_t buttonStateThem = BUT_STATE_UNPRESSED;

// current battery state
uint8_t batteryState = 0;

// the score pad
uint8_t scorepad[SCOREPAD_MAX_SIZE][3];

// the current index into the scorepad
uint8_t scorepadIdx = 0;

// the indexes into the scorepad of where games where won
uint8_t summarypad[SUMMARYPAD_MAX_SIZE];

// playing time
unsigned long startTime;
unsigned long playingTime;

// who won the match
uint8_t winner = NONE;

// Class provides the model functionality.
class YscoreModel
{
public:
  YscoreModel(TinyScreenExt display);

  void setView(YscoreView view);

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
  YscoreView _view = 0;
};

///////////////////////
// manage the score pad
///////////////////////

// resets all the values in the scorepad to zero
// TODO check if it is suficient to just set the
// first row to 00
void resetScorepad()
{
  // reset the scorepad
  // for (int i = 0; i < SCOREPAD_MAX_SIZE ; i++) {
  //   scorepad[i][US] = 0;
  //   scorepad[i][THEM] = 0;
  // }

  scorepad[0][US] = 0;
  scorepad[0][THEM] = 0;

  winner = NONE;
  scorepadIdx = 0;
}

// copy the score pad row reseting the has serve bit and EndOfGame at the same time
void copyScorepadRowTo(uint8_t from, uint8_t to)
{
  // copy the score pad row mask out the end of game bit
  scorepad[to][THEM] = scorepad[from][THEM] & MASK_8TH_BIT_OFF;
  // copy the US score pad row
  scorepad[to][US] = scorepad[from][US];
  // copy the PLAYER score pad row
  scorepad[to][PLAYER] = scorepad[from][PLAYER];
}

// copy the score pad row keeping the serve and the games
void copyScorepadNewGameRowTo(uint8_t from, uint8_t to)
{
  // keep the number of games
  scorepad[to][THEM] = scorepad[from][THEM] & MASK_GAMES;
  // keep the number of games and the serve bit
  scorepad[to][US] = scorepad[from][US] & MASK_GAMES;
  // keep the number of games and the serve bit
  scorepad[to][PLAYER] = scorepad[from][PLAYER];
}

// function increments the score pad index
inline void incScorepadIdx()
{
  scorepadIdx++;
}

// function decrements the score pad index
// taking into account the EndOfGameMarker
// if there is one
inline void decScorepadIdx()
{
  scorepadIdx--;
  if (isEndOfGame(scorepadIdx))
  {
    // go back before the end of the game
    scorepadIdx--;
  }
}

// resets all the values in the summarypad to NULL_SCOREPAD_IDX
void resetSummarypad()
{
  for (int i = 0; i < SUMMARYPAD_MAX_SIZE; i++)
  {
    summarypad[i] = NULL_SCOREPAD_IDX;
  }
}

// function creates the summary table from the scorepad
void createSummaryTable()
{
  resetSummarypad();
  uint8_t summaryIdx = 0;
  for (int i = 0; i < scorepadIdx; i++)
  {
    // if this was the score at the end of the game
    if (isEndOfGame(i))
    {
      summarypad[summaryIdx] = i;
      summaryIdx++;
    }
  }
}

//////////////////////////////////////////////////////////////////
// manage data extraction and setting of values from the score pad
//////////////////////////////////////////////////////////////////

// sets the uint8_t serve bit of the scorepad row at the given index off or on
// depending on who has the serve
inline void setServe(uint8_t index, uint8_t who)
{
  if (who == US)
  {
    // record that US now has the serve
    scorepad[index][PLAYER] |= MASK_1ST_BIT_ON;
    // if we are not at the start of the match
    if (index != 0)
    {
      // check if we had the serve on the previous point
      bool hadServe = hasServe(index - 1, US);
      if (hadServe)
      {
        // toggle the position of the players
        scorepad[index][PLAYER] ^= MASK_2ND_BIT_ON;
      }
    }
  }
  else
  {
    scorepad[index][PLAYER] &= MASK_1ST_BIT_OFF;
    // if we are not at the start of the match
    if (index != 0)
    {
      // check if they had the serve on the previous point
      bool hadServe = hasServe(index - 1, THEM);
      if (hadServe)
      {
        // toggle the position of the players
        scorepad[index][PLAYER] ^= MASK_3RD_BIT_ON;
      }
    }
  }
}

// sets the THEM uint8_t EndOfGame bit of the scorepad row at the given index on
void endOfGameOn(uint8_t index)
{
  scorepad[index][THEM] |= MASK_8TH_BIT_ON;
}

// gets the THEM uint8_t EndOfGame bit of the scorepad row at the given index on
bool isEndOfGame(uint8_t index)
{
  return scorepad[index][THEM] & MASK_8TH_BIT_ON;
}

// gets the number of games from the  scorepad row at the given index for the given player
uint8_t getGames(uint8_t index, uint8_t who)
{
  uint8_t result = scorepad[index][who] & MASK_GAMES;
  return result >> 5;
}

// adds one to the number of games given index for the given player
void incGames(uint8_t index, uint8_t who)
{
  scorepad[index][who] += ONE_GAME;
}

// gets the points from the  scorepad row at the given index for the given player
uint8_t getPoints(uint8_t index, uint8_t who)
{
  uint8_t result = scorepad[index][who] & MASK_POINTS;
  return result;
}

// adds one to the number of points scorepad row at the given index for the given player
void incPoints(uint8_t index, uint8_t who)
{
  scorepad[index][who]++;
}

// gets the serve status from the scorepad row at the given index for the given player
inline bool hasServe(uint8_t index, uint8_t who)
{
  // get if the serve is true or false
  bool result = scorepad[index][PLAYER] & MASK_1ST_BIT_ON;
  return who == US ? result : !result;
}

#endif
