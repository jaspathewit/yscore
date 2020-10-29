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

// Class provides the view functionality.
class YscoreView
{
public:
  YscoreView(TinyScreenExt display);

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
};

// handle the display updates etc
// update the display according to the state
void updateDisplay()
{
  // clear the display
  clearDisplay();

  switch (appState)
  {
  case APP_STATE_STARTING:
    drawStartScreen();
    break;
  case APP_STATE_SET_SERVE:
    drawSettingServeScreen();
    break;
  case APP_STATE_PLAYING:
    drawPlayingScreen();
    break;
  case APP_STATE_PAUSING:
    // draw the stats screen with the running
    // points
    drawStatsScreen(true);
    break;
  case APP_STATE_PAUSING_TIME:
    // draw the playing time
    drawPlayingTimeScreen();
    break;
  case APP_STATE_WINNING:
    // draw the winning screen without the running
    // points
    drawWinningScreen();
    break;
  case APP_STATE_STATS:
    // draw the stats screen without the running
    // points
    drawStatsScreen(false);
    break;
  case APP_STATE_STATS_TIME:
    // draw the playing time
    drawPlayingTimeScreen();
    break;
  }

  // display.display();
}

///////////////////////////////////////////
// Draw the different screens
//////////////////////////////////////////

// clear the display
// Sets the cursor to 0,0
void clearDisplay()
{
  display.clearScreen();
  //display.setCursor(0,0);
}

// draw the start screen
void drawStartScreen()
{
  display.setFont(SansSerif_8pt);
  display.printAt(0, 0, LBL_COPYRIGHT);

  // draw the logo
  display.drawImageAt(0, 14, &img_BT32x32);

  // draw the name appname
  display.drawImageAt(32, 16, &img_AppName63x22);

  // draw the press to start
  display.setFont(SansSerif_12pt);
  display.printCenteredAt(50, LBL_TO_START_PRESS);
}

// draw the setting serve screen
void drawSettingServeScreen()
{
  drawPlayingFrame();
  drawWhoServes();
}

// draw the who serves
void drawWhoServes()
{
  display.setFont(SansSerif_10pt);
  tPoint pos = display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                               SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y, LBL_WHOSERVES);

  display.setFont(MarVoSym_10pt);
  uint8_t y = pos.y;
  pos = display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                        y, LBL_UP_ARROW);

  display.setFont(SansSerif_10pt);
  pos = display.printAt(pos.x, y, LBL_THEM);

  display.setFont(MarVoSym_10pt);
  y = pos.y;
  pos = display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                        y, LBL_DOWN_ARROW);

  display.setFont(SansSerif_12pt);
  display.printAt(pos.x, y, LBL_US);
}

// draw the playing screen
void drawPlayingScreen()
{
  drawPlayingFrame();
  drawPlayingGrid();
  drawPlayingServe();
  drawPlayingPlayers();
  drawPlayingScore();
}

// draw the winningscreen
void drawWinningScreen()
{
  drawPlayingFrame();
  drawWinningPlayers();
  drawRestart();
}

// draw the restart
void drawRestart()
{
  display.setFont(MarVoSym_10pt);
  uint8_t y = (display.yMax - 2) - display.getFontHeight();
  tPoint pos = display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                               50, LBL_UPDOWN_ARROW);

  display.setFont(SansSerif_10pt);
  display.printAt(pos.x, 50, LBL_RESTART);
}

// draw the stats screen
void drawStatsScreen(bool runningPoints)
{
  drawStatsFrame();
  drawStatsPlayers();
  drawStatsGrid();
  drawStatsGameScoresAt(SCREEN_STATS_SCORE_LEFT_X, SCREEN_STATS_SCORE_TOP_Y, THEM, runningPoints);
  drawStatsGameScoresAt(SCREEN_STATS_SCORE_LEFT_X, SCREEN_STATS_SCORE_BOTTOM_Y, US, runningPoints);

  drawRestart();
}

// draw the playing time screen
void drawPlayingTimeScreen()
{
  drawTimeFrame();
  printTime(playingTime);
  drawRestart();
}

///////////////////////////////////////////
// Print components and elements of screens
///////////////////////////////////////////

// draw the game scores for the given player
// if the running Points is true the last value
// are the current points in the game
void drawStatsGameScoresAt(uint8_t x, uint8_t y, uint8_t who, bool runningPoints)
{
  char buffer[3];

  uint8_t i;

  tPoint pos;

  pos.x = x;
  pos.y = y;

  display.setFont(Digits_Small);

  for (i = 0; i < SUMMARYPAD_MAX_SIZE; i++)
  {
    uint8_t index = summarypad[i];
    if (index == NULL_SCOREPAD_IDX)
    {
      break;
    }

    uint8_t points = getPoints(index, who);
    pos = display.printAt(pos.x, y, zeroPad(buffer, points));
    pos.x += 3;
  }

  if (runningPoints)
  {
    uint8_t points = getPoints(scorepadIdx, who);

    display.printAt(pos.x, y, zeroPad(buffer, points));
  }
}

// print a time given in millis
void printTime(unsigned long millis)
{
  char buffer[8];

  display.setFont(SansSerif_10pt);

  tPoint pos = display.printAt(SCREEN_TIME_X, SCREEN_TIME_Y, LBL_PLAYING_TIME);

  unsigned long secs = millis / 1000;

  uint8_t hours = numberOfHours(secs);
  uint8_t minutes = numberOfMinutes(secs);
  uint8_t seconds = numberOfSeconds(secs);

  if (hours != 0)
  {
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hours, minutes, seconds);
  }
  else
  {
    snprintf(buffer, sizeof(buffer), "%02d:%02d", minutes, seconds);
  }

  display.setFont(SansSerif_12pt);
  display.printCenteredAt(pos.y + 4, buffer);
}

// draw the battery icon
void drawBatteryIcon(uint8_t x, uint8_t y)
{
  uint8_t height = 8;
  uint8_t width = 12;

  // Draw the border
  display.drawRect(x, y, width, height, TSRectangleNoFill, TS_8b_White);
  // draw the contact at the end
  display.drawLine(x + width, y + 2, x + width, y + 5, TS_8b_White);

  // change the colour depending on the charge
  uint16_t colour = TS_8b_Green;
  if (batteryState <= 2)
  {
    colour = TS_8b_Red;
  }

  // clear the battery content
  display.drawRect(x + 1, y + 1, 10, height - 2, TSRectangleFilled, TS_8b_Black);

  // draw the content
  display.drawRect(x + 1, y + 1, batteryState, height - 2, TSRectangleFilled, colour);
}

// draw the playing frame
void drawPlayingFrame()
{
  drawPlayingMenu();
  drawButtonLabels();
}

// draw the playing grid
void drawPlayingGrid()
{
  // horizontal middle line
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_MIDDLE_LINE_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_MIDDLE_LINE_Y, TS_8b_Gray);

  // vertical (games)
  display.drawLine(SCREEN_GAMES_LINE_X, SCREEN_MENU_MARGIN_Y, SCREEN_GAMES_LINE_X, display.yMax, TS_8b_Gray);
  // vertical (points)
  display.drawLine(SCREEN_POINTS_LINE_X, SCREEN_MENU_MARGIN_Y, SCREEN_POINTS_LINE_X, display.yMax, TS_8b_Gray);
}

// draw the playing score
void drawPlayingScore()
{
  drawPlayingScoreGames();
  drawPlayingScorePoints();
}

// draw the number of sets for each team
void drawPlayingScoreGames()
{
  display.setFont(Digits_Large);

  char buffer[2];
  uint8_t games = getGames(scorepadIdx, THEM);
  itoa(games, buffer, 10);
  display.printAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
                  SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                  buffer);

  games = getGames(scorepadIdx, US);
  itoa(games, buffer, 10);
  display.printAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
                  SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
                  buffer);
}

// draw the current points for each team
void drawPlayingScorePoints()
{
  char buffer[3];
  display.setFont(Digits_Large);
  uint8_t points = getPoints(scorepadIdx, THEM);
  display.printAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
                  SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                  zeroPad(buffer, points));

  points = getPoints(scorepadIdx, US);
  zeroPad(buffer, points);
  display.printAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
                  SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
                  zeroPad(buffer, points));
}

void drawPlayingServe()
{

  // determine which team is serving and which side
  uint8_t serving = THEM;

  // assume THEM have the serve
  // so we only need to check if that is not true
  if (hasServe(scorepadIdx, US))
  {
    serving = US;
  }

  // get the points of the team playing
  uint8_t points = getPoints(scorepadIdx, serving);

  // char * serve = LBL_SPACE;
  // // get the serve symbol
  // if(hasServe(index, who)) {
  //   serve = LBL_SERVE[who][points % 2];
  // }

  display.drawImageAt(SCREEN_SERVE_X, SCREEN_SERVE_Y, IMG_SERVE[serving][points % 2]);
}

// draw the players playing the game
void drawPlayingPlayers()
{
  // get the Player details
  uint8_t playerImges = scorepad[scorepadIdx][PLAYER];

  display.drawImageAt(SCREEN_PLAYER_LEFT_X,
                      SCREEN_PLAYER_TOP_Y, IMG_PLAYER_DOUBLES[playerImges][0]);

  display.drawImageAt(SCREEN_PLAYER_RIGHT_X,
                      SCREEN_PLAYER_TOP_Y, IMG_PLAYER_DOUBLES[playerImges][1]);

  display.drawImageAt(SCREEN_PLAYER_LEFT_X,
                      SCREEN_PLAYER_BOTTOM_Y, IMG_PLAYER_DOUBLES[playerImges][2]);

  display.drawImageAt(SCREEN_PLAYER_RIGHT_X,
                      SCREEN_PLAYER_BOTTOM_Y, IMG_PLAYER_DOUBLES[playerImges][3]);
}

// draw the players stats
void drawStatsPlayers()
{
  display.drawImageAt(SCREEN_STATS_PLAYER_LEFT_X,
                      SCREEN_STATS_PLAYER_TOP_Y, IMG_STATS_PLAYER[winner][0]);

  display.drawImageAt(SCREEN_STATS_PLAYER_RIGHT_X,
                      SCREEN_STATS_PLAYER_TOP_Y, IMG_STATS_PLAYER[winner][1]);

  display.drawImageAt(SCREEN_STATS_PLAYER_LEFT_X,
                      SCREEN_STATS_PLAYER_BOTTOM_Y, IMG_STATS_PLAYER[winner][2]);

  display.drawImageAt(SCREEN_STATS_PLAYER_RIGHT_X,
                      SCREEN_STATS_PLAYER_BOTTOM_Y, IMG_STATS_PLAYER[winner][3]);
}

// draw the button labels
void drawPlayingMenu()
{
  display.drawImageAt(display.xMin, display.yMin, &img_Play);
  display.drawLine(display.xMin, SCREEN_MENU_MARGIN_Y, display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, display.yMax, TS_8b_Gray);
}

// draw the winning players of the match
void drawWinningPlayers()
{

  // draw the trophy
  tPoint trophyPos = display.drawImageAt(SCREEN_BUTTON_LEFT_MARGIN_X + 12,
                                         SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_X,
                                         &img_Trophy);

  // draw the players
  tPoint pos = display.drawImageAt(trophyPos.x + SCREEN_MARGIN_OFFSET_X,
                                   SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                                   IMG_WINNING_PLAYER[winner][0]);

  // draw the players
  pos = display.drawImageAt(pos.x + SCREEN_MARGIN_OFFSET_X,
                            SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                            IMG_WINNING_PLAYER[winner][1]);

  display.setFont(SansSerif_12pt);
  display.printAt(trophyPos.x + SCREEN_MARGIN_OFFSET_X,
                  pos.y + SCREEN_MARGIN_OFFSET_Y,
                  LBL_PLAYER[winner]);
}

// draw the Stats frame
void drawStatsFrame()
{
  drawStatsMenu();
  drawButtonLabels();
}

// draw the button labels
void drawStatsMenu()
{
  display.drawImageAt(display.xMin, display.yMin, &img_Stats);
  display.drawLine(display.xMin, SCREEN_MENU_MARGIN_Y, display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, display.yMax, TS_8b_Gray);
}

// draw the Stats grid
void drawStatsGrid()
{
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_STATS_MIDDLE_LINE_Y,
                   SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_STATS_MIDDLE_LINE_Y, TS_8b_Gray);

  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_STATS_BOTTOM_LINE_Y,
                   SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);

  display.drawLine(SCREEN_STATS_POINTS_LINE1_X, SCREEN_MENU_MARGIN_Y,
                   SCREEN_STATS_POINTS_LINE1_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);

  display.drawLine(SCREEN_STATS_POINTS_LINE2_X, SCREEN_MENU_MARGIN_Y,
                   SCREEN_STATS_POINTS_LINE2_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);

  display.drawLine(SCREEN_STATS_POINTS_LINE3_X, SCREEN_MENU_MARGIN_Y,
                   SCREEN_STATS_POINTS_LINE3_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);
}

// draw the button labels
void drawButtonLabels()
{
  display.drawImageAt(display.xMin, SCREEN_BUTTON_TOP_Y, &img_ArrowRight);
  display.drawImageAt(display.xMin, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowLeft);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_LEFT_MARGIN_X, display.yMax, TS_8b_Gray);
  display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 3, SCREEN_BUTTON_TOP_Y, &img_ArrowUp);
  display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 3, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowDown);
  display.drawLine(SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, display.yMax, TS_8b_Gray);
}

// draw the Time frame
void drawTimeFrame()
{
  drawTimeMenu();
  drawButtonLabels();
}

// draw the button labels
void drawTimeMenu()
{
  display.drawImageAt(display.xMin, display.yMin, &img_Time);
  display.drawLine(display.xMin, SCREEN_MENU_MARGIN_Y, display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, display.yMax, TS_8b_Gray);
}

///////////////////////////////////////////////
// Convenience functions for handeling numbers
///////////////////////////////////////////////

// put the zero padded value into the provided buffer
char *zeroPad(char *buffer, uint8_t value)
{
  snprintf(buffer, sizeof(buffer), "%02d", value);
  return buffer;
}

#endif
