// #include <Adafruit_SPITFT.h>
// #include <Adafruit_SPITFT_Macros.h>
// #include <gfxfont.h>

/*********************************************************************
Personal Score Board II
*********************************************************************/

// #include <Wire.h>
// #include <SPI.h>
#include <TinyScreen.h>

#include "iScore.h"
#include "fonts/TinyFont.h"
#include "fonts/windings3.h"
#include "images/images.h"

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

// The maximum value when the battery is fully charged
#define MAX_VBAT 4321

// Screen dimensions and locations
#define SCREEN_WIDTH 96
#define SCREEN_WIDTH_HALF SCREEN_WIDTH / 2
#define SCREEN_HEIGHT 64
#define SCREEN_HEIGHT_HALF SCREEN_HEIGHT / 2

#define SCREEN_START_X 0
#define SCREEN_END_X 95
#define SCREEN_START_Y 0
#define SCREEN_END_Y 95

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
// offset between two characters on the same line
#define SCREEN_CHAR_OFFSET 2

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

#define LBL_WHOSERVES "Who serves"
#define LBL_RESTART "Restart "

#define LBL_SEPARATOR ":"
#define LBL_SPACE " "
#define LBL_ZERO "0"
#define LBL_PERCENT "%"

// define the modifyable labels
#define LBL_US "US  "
#define LBL_THEM "THEM"
#define LBL_NONE "NONE"
#define LBL_US_THEM "US    THEM"

#define LBL_YOU "YOU "
#define LBL_WINNER "Winner: "
#define LBL_PLAYING_TIME "Time: "

// "text" when it is in windings3 font are the
// Up Down left and right arrows
#define LBL_UP_ARROW "p"
#define LBL_DOWN_ARROW "q"
#define LBL_LEFT_ARROW "t"
#define LBL_RIGHT_ARROW "u"

#define LBL_ALL_ARROW "tupq"
#define LBL_UPDOWN_ARROW "pq"

// Array of pointers to the digit images
// makes it easier to map between 0-9
// and the corresponding image
static const tImage *IMG_DIGIT[] = {
    &img_Digit_0,
    &img_Digit_1,
    &img_Digit_2,
    &img_Digit_3,
    &img_Digit_4,
    &img_Digit_5,
    &img_Digit_6,
    &img_Digit_7,
    &img_Digit_8,
    &img_Digit_9};

// Array of pointers to the small digit images
// makes it easier to map between 0-9
// and the corresponding image
static const tImage *IMG_SMALL_DIGIT[] = {
    &img_Small_Digit_0,
    &img_Small_Digit_1,
    &img_Small_Digit_2,
    &img_Small_Digit_3,
    &img_Small_Digit_4,
    &img_Small_Digit_5,
    &img_Small_Digit_6,
    &img_Small_Digit_7,
    &img_Small_Digit_8,
    &img_Small_Digit_9};

// Player Names
static char *LBL_PLAYER[] = {LBL_THEM, LBL_US, LBL_NONE};

static const tImage *IMG_SERVE[][2] = {{&img_Serve_BR, &img_Serve_BL},
                                       {&img_Serve_TL, &img_Serve_TR}};

static const tImage *IMG_PLAYER[][4] = {{&img_Happy_blue, &img_Happy_green, &img_Sad_red, &img_Sad_yellow},
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

//Library must be passed the board type
//TinyScreenDefault for TinyScreen shields
//TinyScreenAlternate for alternate address TinyScreen shields
//TinyScreenPlus for TinyScreen+
TinyScreen display = TinyScreen(TinyScreenPlus);

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

// battery state
uint8_t currentPctBat = 0;

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

//////////////////////////
// Setup the initial state
//////////////////////////

void setup()
{
  // starting state
  appState = APP_STATE_STARTING;

  // setupButtons();
  resetButtonState();
  setupdisplay();
  resetScorepad();
}

void setupdisplay()
{
  display.begin();
  // needs to be set so that the button definitions are correct
  display.setFlip(true);
  //setBrightness(brightness);//sets main current level, valid levels are 0-15
  display.setBrightness(10);
  // set the font to be used
  //display.setFont(liberationSans_8ptFontInfo);
  // set white text on black background
  display.fontColor(TS_8b_White, TS_8b_Black);

  // draw the starting screen
  drawStartScreen();
}

////////////////////////////////////////////////
// Main evaluation loop
// keep this short to improve the responsiveness
////////////////////////////////////////////////
void loop()
{
  // unsigned long time = millis();

  if (appState == APP_STATE_STARTING)
  {
    // updateBatteryState();
  }

  // update the button states
  updateButtonStates();

  // perform the action
  performAction();

  // update the display according to the current state
  // but only if the model has changed
  if (modelChanged)
  {
    updateDisplay();
  }

  delay(50);

  // any changes to the model will have been handled
  modelChanged = false;

  //  Serial.print("Loop Time");
  //  Serial.print(millis() - time);
  //  Serial.println("ms");
}

///////////////////////
// Handle Battery State
///////////////////////

// handle updating the battery state
// void updateBatteryState() {
//   // read the raw value from the pin
//   float fvbat = analogRead(VBATPIN);

//   // convert it to raw volatage ()
//   fvbat = (fvbat * 2 * 3.3); // we divided by 2, so multiply back, Multiply by 3.3V, our reference voltage
//   uint8_t pctBat = ((fvbat / MAX_VBAT) * 100); // calculate the percentage

//   // check if the change in voltage is bigger
//   // than 10 %
//   if(abs(currentPctBat - pctBat) >= 10) {
//     currentPctBat = pctBat;
//     modelChanged = true;
//   }
// }

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

void printButtonStates()
{
  display.setFont(liberationSans_8ptFontInfo);
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
void resetButtonState()
{
  buttonStateMode = BUT_STATE_UNPRESSED;
  buttonStateBack = BUT_STATE_UNPRESSED;
  buttonStateUs = BUT_STATE_UNPRESSED;
  buttonStateThem = BUT_STATE_UNPRESSED;
}

////////////////////////////////////////
// Perform Actions depending on AppState
// and button state
////////////////////////////////////////

// perform action
void performAction()
{

  // check for a long press on the mode
  // button
  // performActionDefault();

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
  display.setFont(tiny_6ptFontInfo);
  tPoint point = printAt(0, 0, LBL_COPYRIGHT);

  // draw the logo
  point = drawImageAt(0, 14, img_BT32x32);

  // draw the name appname
  point = drawImageAt(32, 16, img_AppName63x22);

  // draw the press to start
  display.setFont(liberationSans_8ptFontInfo);
  printAtCentered(50, LBL_TO_START_PRESS);

  drawBatteryIcon(SCREEN_BATTERY_X, SCREEN_START_Y);
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
  display.setFont(liberationSans_8ptFontInfo);
  tPoint pos = printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                       SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y, LBL_WHOSERVES);

  display.setFont(wingdings3_8ptFontInfo);
  uint8_t y = pos.y;
  pos = printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                y, LBL_UP_ARROW);

  display.setFont(liberationSans_8ptFontInfo);
  pos = printAt(pos.x + SCREEN_CHAR_OFFSET,
                y, LBL_THEM);

  display.setFont(wingdings3_8ptFontInfo);
  y = pos.y;
  pos = printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                y, LBL_DOWN_ARROW);

  display.setFont(liberationSans_8ptFontInfo);
  printAt(pos.x + SCREEN_CHAR_OFFSET,
          y, LBL_US);

  //display.setFont(liberationSans_10ptFontInfo);
  // printAtCentered(20, LBL_WHOSERVES);
  // display.println(LBL_WHOSERVES);
  // display.println(F(LBL_US_THEM));
}

// draw the playing screen
void drawPlayingScreen()
{
  drawPlayingFrame();
  drawPlayingGrid();
  drawPlayingServe();
  drawPlayingPlayers();
  drawPlayingScore();

  // display.setTextSize(2);
  // printPlayingLineFor(scorepadIdx, US);
  // printPlayingLineFor(scorepadIdx, THEM);
}

// draw the winningscreen
void drawWinningScreen()
{
  drawPlayingFrame();
  drawWinningPlayers();
  drawRestart();

  // display.setTextSize(2);
  // printPlayingLineFor(scorepadIdx, US);
  // printPlayingLineFor(scorepadIdx, THEM);
}

// draw the restart
void drawRestart()
{

  display.setFont(wingdings3_8ptFontInfo);
  uint8_t y = (SCREEN_END_Y - 2) - display.getFontHeight();
  tPoint pos = printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                       50, LBL_UPDOWN_ARROW);

  display.setFont(liberationSans_8ptFontInfo);
  printAt(pos.x + SCREEN_CHAR_OFFSET,
          50, LBL_RESTART);

  //display.setFont(liberationSans_10ptFontInfo);
  // printAtCentered(20, LBL_WHOSERVES);
  // display.println(LBL_WHOSERVES);
  // display.println(F(LBL_US_THEM));
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

  // display.setTextSize(1);
  // display.print(F(LBL_WINNER));
  // display.println(LBL_PLAYER[winner]);

  // display.print(LBL_PLAYER[US]);
  // printGameScores(US, runningPoints);
  // display.print(LBL_PLAYER[THEM]);
  // printGameScores(THEM, runningPoints);
  // display.print(F(LBL_PLAYING_TIME));
  // printTime(playingTime);
}

// draw the playing time screen
void drawPlayingTimeScreen()
{
  drawTimeFrame();
  printTime(playingTime);
  drawRestart();

  // display.setTextSize(1);
  // display.print(F(LBL_WINNER));
  // display.println(LBL_PLAYER[winner]);

  // display.print(LBL_PLAYER[US]);
  // printGameScores(US, runningPoints);
  // display.print(LBL_PLAYER[THEM]);
  // printGameScores(THEM, runningPoints);
  // display.print(F(LBL_PLAYING_TIME));
  // printTime(playingTime);
}

///////////////////////////////////////////
// Print components and elements of screens
///////////////////////////////////////////

// print the line of the playing screen
void printPlayingLineFor(uint8_t index, uint8_t who)
{
  // uint8_t games = getGames(index, who);
  // uint8_t points = getPoints(index, who);

  // char * serve = LBL_SPACE;
  // // get the serve symbol
  // if(hasServe(index, who)) {
  //   serve = LBL_SERVE[who][points % 2];
  // }

  // display.print(LBL_PLAYER[who]);
  // display.print(serve);
  // print2DigitsZeroPadded(games);
  // display.print(F(LBL_SEPARATOR));
  // print2DigitsZeroPadded(points);
  // display.println();
}

// draw the game scores for the given player
// if the running Points is true the last value
// are the current points in the game
void drawStatsGameScoresAt(uint8_t x, uint8_t y, uint8_t who, bool runningPoints)
{
  uint8_t i;

  tPoint pos;

  pos.x = x;
  pos.y = y;

  for (i = 0; i < SUMMARYPAD_MAX_SIZE; i++)
  {
    uint8_t index = summarypad[i];
    if (index == NULL_SCOREPAD_IDX)
    {
      break;
    }

    uint8_t points = getPoints(index, who);

    pos = draw2DigitsZeroPaddedAt(pos.x, y, points, IMG_SMALL_DIGIT);
    pos.x += 3;
  }

  if (runningPoints)
  {
    uint8_t points = getPoints(scorepadIdx, who);

    draw2DigitsZeroPaddedAt(pos.x, y, points, IMG_SMALL_DIGIT);
  }

  // display.print(F(LBL_SPACE));
  // uint8_t i;
  // for(i = 0; i < SUMMARYPAD_MAX_SIZE; i++ ) {
  //   uint8_t index = summarypad[i];
  //   if (index == NULL_SCOREPAD_IDX) {
  //     break;
  //   }

  //   if(i != 0) {
  //     display.print(F(LBL_SEPARATOR));
  //   }
  //   print2DigitsZeroPadded(getPoints(index,who));
  // }

  // if (runningPoints) {
  //   if(i != 0) {
  //     display.print(F(LBL_SEPARATOR));
  //   }
  //   print2DigitsZeroPadded(getPoints(scorepadIdx,who));
  // }

  // display.println();
}

// draw the playing time
void printTime(unsigned long millis)
{

  display.setFont(liberationSans_10ptFontInfo);

  unsigned long secs = millis / 1000;

  uint8_t value = numberOfHours(secs);
  tPoint pos = printAt(SCREEN_TIME_X, SCREEN_TIME_Y, LBL_PLAYING_TIME);
  if (value != 0)
  {
    pos = print2DigitsZeroPaddedAt(pos.x, SCREEN_TIME_Y, value);
    pos = printAt(pos.x, SCREEN_TIME_Y, LBL_SEPARATOR);
  }

  value = numberOfMinutes(secs);
  pos = print2DigitsZeroPaddedAt(pos.x, SCREEN_TIME_Y, value);
  pos = printAt(pos.x, SCREEN_TIME_Y, LBL_SEPARATOR);
  value = numberOfSeconds(secs);

  print2DigitsZeroPaddedAt(pos.x, SCREEN_TIME_Y, value);
}

// draw the battery icon
void drawBatteryIcon(uint8_t x, uint8_t y)
{
  uint8_t height = 8;
  uint8_t width = 13;

  // Draw the border
  display.drawRect(x, y, width, height, TSRectangleNoFill, TS_8b_White);
  // draw the contact at the end
  display.drawLine(x + width, y + 2, x + width, y + 5, TS_8b_White);
  // get the current value of the battery 0 to width - 3 (0 to 100%)
  uint8_t charge = 5;
  // draw the contents
  display.drawRect(x + 1, y + 1, charge, height - 2, TSRectangleFilled, TS_8b_Red);
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
  display.drawLine(SCREEN_GAMES_LINE_X, SCREEN_MENU_MARGIN_Y, SCREEN_GAMES_LINE_X, SCREEN_END_Y, TS_8b_Gray);
  // vertical (points)
  display.drawLine(SCREEN_POINTS_LINE_X, SCREEN_MENU_MARGIN_Y, SCREEN_POINTS_LINE_X, SCREEN_END_Y, TS_8b_Gray);
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
  uint8_t games = getGames(scorepadIdx, THEM);
  drawDigitAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
              SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
              games, IMG_DIGIT);

  games = getGames(scorepadIdx, US);
  drawDigitAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
              SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
              games, IMG_DIGIT);

  // drawImageAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
  //  SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
  // *IMG_DIGIT[0]);

  // drawImageAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
  // SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
  // *IMG_DIGIT[0]);
}

// draw the current points for each team
void drawPlayingScorePoints()
{
  uint8_t points = getPoints(scorepadIdx, THEM);
  draw2DigitsZeroPaddedAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
                          SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                          points, IMG_DIGIT);

  points = getPoints(scorepadIdx, US);
  draw2DigitsZeroPaddedAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
                          SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
                          points, IMG_DIGIT);

  // tPoint pos = drawImageAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
  // SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
  //  *IMG_DIGIT[2]);
  // drawImageAt(pos.x + SCREEN_DIGIT_OFFSET,
  // SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
  // *IMG_DIGIT[1]);

  // pos = drawImageAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
  // SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
  // *IMG_DIGIT[2]);
  // drawImageAt(pos.x + SCREEN_DIGIT_OFFSET,
  // SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
  // *IMG_DIGIT[1]);
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

  drawImageAt(SCREEN_SERVE_X, SCREEN_SERVE_Y, *IMG_SERVE[serving][points % 2]);
}

// draw the players playing the game
void drawPlayingPlayers()
{

  // get the Player details
  uint8_t playerImges = scorepad[scorepadIdx][PLAYER];

  drawImageAt(SCREEN_PLAYER_LEFT_X,
              SCREEN_PLAYER_TOP_Y, *IMG_PLAYER[playerImges][0]);

  drawImageAt(SCREEN_PLAYER_RIGHT_X,
              SCREEN_PLAYER_TOP_Y, *IMG_PLAYER[playerImges][1]);

  drawImageAt(SCREEN_PLAYER_LEFT_X,
              SCREEN_PLAYER_BOTTOM_Y, *IMG_PLAYER[playerImges][2]);

  drawImageAt(SCREEN_PLAYER_RIGHT_X,
              SCREEN_PLAYER_BOTTOM_Y, *IMG_PLAYER[playerImges][3]);
}

// draw the players stats
void drawStatsPlayers()
{

  drawImageAt(SCREEN_STATS_PLAYER_LEFT_X,
              SCREEN_STATS_PLAYER_TOP_Y, *IMG_STATS_PLAYER[winner][0]);

  drawImageAt(SCREEN_STATS_PLAYER_RIGHT_X,
              SCREEN_STATS_PLAYER_TOP_Y, *IMG_STATS_PLAYER[winner][1]);

  drawImageAt(SCREEN_STATS_PLAYER_LEFT_X,
              SCREEN_STATS_PLAYER_BOTTOM_Y, *IMG_STATS_PLAYER[winner][2]);

  drawImageAt(SCREEN_STATS_PLAYER_RIGHT_X,
              SCREEN_STATS_PLAYER_BOTTOM_Y, *IMG_STATS_PLAYER[winner][3]);
}

// draw the button labels
void drawPlayingMenu()
{
  drawBatteryIcon(SCREEN_BATTERY_X, SCREEN_START_Y);
  drawImageAt(SCREEN_START_X, SCREEN_START_Y, img_Play);
  display.drawLine(SCREEN_START_X, SCREEN_MENU_MARGIN_Y, SCREEN_END_X, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_END_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_END_Y, TS_8b_Gray);
}

// draw the winning players of the match
void drawWinningPlayers()
{

  // draw the trophy
  tPoint trophyPos = drawImageAt(SCREEN_BUTTON_LEFT_MARGIN_X + 12,
                                 SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_X,
                                 img_Trophy);

  // draw the players
  tPoint pos = drawImageAt(trophyPos.x + SCREEN_MARGIN_OFFSET_X,
                           SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                           *IMG_WINNING_PLAYER[winner][0]);

  // draw the players
  pos = drawImageAt(pos.x + SCREEN_MARGIN_OFFSET_X,
                    SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                    *IMG_WINNING_PLAYER[winner][1]);

  display.setFont(liberationSans_8ptFontInfo);
  printAt(trophyPos.x + SCREEN_MARGIN_OFFSET_X,
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
  drawBatteryIcon(SCREEN_BATTERY_X, SCREEN_START_Y);
  drawImageAt(SCREEN_START_X, SCREEN_START_Y, img_Stats);
  display.drawLine(SCREEN_START_X, SCREEN_MENU_MARGIN_Y, SCREEN_END_X, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_END_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_END_Y, TS_8b_Gray);
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
  drawImageAt(SCREEN_START_X, SCREEN_BUTTON_TOP_Y, img_ArrowRight);
  drawImageAt(SCREEN_START_X, SCREEN_BUTTON_BOTTOM_Y, img_ArrowLeft);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_END_Y, TS_8b_Gray);
  drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 3, SCREEN_BUTTON_TOP_Y, img_ArrowUp);
  drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 3, SCREEN_BUTTON_BOTTOM_Y, img_ArrowDown);
  display.drawLine(SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_END_Y, TS_8b_Gray);
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
  drawBatteryIcon(SCREEN_BATTERY_X, SCREEN_START_Y);
  drawImageAt(SCREEN_START_X, SCREEN_START_Y, img_Time);
  display.drawLine(SCREEN_START_X, SCREEN_MENU_MARGIN_Y, SCREEN_END_X, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_END_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_END_Y, TS_8b_Gray);
}

/////////////////////////////////////////////
// Convenience functions for printing numbers
/////////////////////////////////////////////

// print to the display the given value ensuring that
// two digits are printed ie value less than 10 result
// result in 09 being printed
tPoint print2DigitsZeroPaddedAt(uint8_t x, uint8_t y, uint8_t value)
{
  char buffer[2];
  uint8_t tens = value / 10;
  itoa(tens, buffer, 10);
  tPoint pos = printAt(x, y, buffer);
  uint8_t units = value % 10;
  itoa(units, buffer, 10);
  pos = printAt(pos.x, y, buffer);

  // if(value < 100) {
  //   display.print(F(LBL_SPACE));
  // }
  // if(value < 10) {
  //   display.print(F(LBL_SPACE));
  // }
  // display.print(value);
  return pos;
}

// prints the given text centered on the display
// at the given y. If the given string is too large
// then it is printed at column 0
tPoint printAtCentered(uint8_t y, char *str)
{
  uint8_t width = display.getPrintWidth(str);
  int x = SCREEN_WIDTH_HALF - (width / 2);
  if (x < 0)
  {
    x = 0;
  }

  tPoint result = printAt(x, y, str);
  return result;
}

// prints the given text at the given x, y on the display
tPoint printAt(uint8_t x, uint8_t y, char *str)
{

  display.setCursor(x, y);
  display.print(str);

  uint8_t endx = x + display.getPrintWidth(str);
  uint8_t endy = y + display.getFontHeight();

  tPoint result = {endx, endy};
  return result;
}

// prints the given text vertically on the display
// at the given x, y.
tPoint printAtVertical(uint8_t x, uint8_t y, char *str)
{
  char buffer[2];

  tPoint result = {x, y};
  uint8_t maxWidth = 0;

  for (int i = 0; i < strlen(str); i++)
  {
    buffer[0] = str[i];
    buffer[1] = '\0';

    // print the char and move the next
    // print position to one pixel lower
    tPoint endPoint = printAt(result.x, result.y, buffer);
    result.y = (1 + endPoint.y);

    // check the maximum width of the characters
    // printed so far
    if (endPoint.x > maxWidth)
    {
      maxWidth = endPoint.x;
    }
  }

  result.x = result.x + maxWidth;
  return result;
}

/////////////////////////////////////////////
// Convenience functions for drawing numbers
/////////////////////////////////////////////

// print to the display the given value ensuring that
// two digits are printed ie value less than 10 result
// result in 09 being printed
tPoint draw2DigitsZeroPaddedAt(uint8_t x, uint8_t y, uint8_t value, const tImage **digits)
{
  uint8_t tens = value / 10;
  tPoint pos = drawDigitAt(x, y, tens, digits);
  uint8_t units = value % 10;
  pos = drawDigitAt(pos.x, y, units, digits);

  // if(value < 100) {
  //   display.print(F(LBL_SPACE));
  // }
  // if(value < 10) {
  //   display.print(F(LBL_SPACE));
  // }
  // display.print(value);
  return pos;
}

// print to the display the given value
// at point x,y
// if the value is > 9 then 0 is displayed
tPoint drawDigitAt(uint8_t x, uint8_t y, uint8_t value, const tImage **digits)
{
  if (value > 9)
  {
    value = 0;
  }
  tPoint result = drawImageAt(x, y, *(digits[value]));
  return result;
}

// draw the given image at (x,y)
tPoint drawImageAt(uint8_t x, uint8_t y, tImage image)
{
  //set a background that matches
  //display.drawRect(0,0,96,64,TSRectangleFilled,TS_8b_Blue);
  //let's set up for a bitmap at (40,30) that is 17 pixels wide and 12 pixels tall:
  //setX(x start, x end);//set OLED RAM to x start, wrap around at x end
  uint8_t endx = x + image.width;
  display.setX(x, endx - 1);
  //setY(y start, y end);//set OLED RAM to y start, wrap around at y end
  uint8_t endy = y + image.height;
  display.setY(y, endy - 1);

  //now start a data transfer
  display.startData();
  //writeBuffer(buffer,count);//optimized write of a large buffer of 8 bit data
  display.writeBuffer(image.data, image.width * image.height);
  display.endTransfer();

  tPoint result = {endx, endy};
  return result;
}

// prints debug info
void printDebug(char *buffer)
{

  display.setFont(tiny_6ptFontInfo);
  display.setCursor(10, 0);
  display.print(buffer);
}

// prints debug info
void printDebug(int number)
{

  display.setFont(tiny_6ptFontInfo);
  display.setCursor(10, 0);
  display.print(number);
}
