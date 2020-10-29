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

#include "YscoreControler.h"

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

// prints debug info
void printDebug(char *buffer)
{
  display.setFont(SansSerif_8pt);
  display.setCursor(10, 0);
  display.print(buffer);
}

// prints debug info
void printDebug(uint32_t number)
{
  display.setFont(SansSerif_8pt);
  display.setCursor(20, 0);
  display.print(number, 10);
}

// prints debug info
void printDebug(double number)
{
  display.setFont(SansSerif_8pt);
  display.setCursor(20, 0);
  display.print(number, 2);
}
