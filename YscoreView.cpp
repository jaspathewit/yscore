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

#include "YscoreView.h"
#include "YscoreModel.h"

/*
  Constructor
*/
YscoreView::YscoreView(TinyScreenExt &display) : _display(display)
{
}

// sets the model to be used to retrieve the values
// to be shown in the view
void YscoreView::setModel(YscoreModel *model)
{
  _model = model;
}

// update the view according to the state
void YscoreView::updateView()
{
  if (_model == NULL)
  {
    return;
  }

  // clear the display
  this->_display.clearScreen();

  switch (_model->getAppState())
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

// update the view of the battery according to the state
void YscoreView::updateViewBattery()
{
  if (_model == NULL)
  {
    return;
  }
  drawBatteryIcon(SCREEN_BATTERY_X, _display.yMin);
}

///////////////////////////////////////////
// Draw the different screens
//////////////////////////////////////////

// draw the start screen
void YscoreView::drawStartScreen()
{
  _display.setFont(SansSerif_8pt);
  _display.printAt(0, 0, LBL_COPYRIGHT);

  // draw the logo
  _display.drawImageAt(0, 14, &img_BT32x32);

  // draw the name appname
  _display.drawImageAt(32, 16, &img_AppName63x22);

  // draw the press to start
  _display.setFont(SansSerif_12pt);
  _display.printCenteredAt(50, LBL_TO_START_PRESS);
}

// draw the setting serve screen
void YscoreView::drawSettingServeScreen()
{
  drawPlayingFrame();
  drawWhoServes();
}

// draw the who serves
void YscoreView::drawWhoServes()
{
  _display.setFont(SansSerif_10pt);
  tPoint pos = _display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                                SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y, LBL_WHOSERVES);

  _display.setFont(MarVoSym_10pt);
  uint8_t y = pos.y;
  pos = _display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                         y, LBL_UP_ARROW);

  _display.setFont(SansSerif_10pt);
  pos = _display.printAt(pos.x, y, LBL_THEM);

  _display.setFont(MarVoSym_10pt);
  y = pos.y;
  pos = _display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                         y, LBL_DOWN_ARROW);

  _display.setFont(SansSerif_12pt);
  _display.printAt(pos.x, y, LBL_US);
}

// draw the playing screen
void YscoreView::drawPlayingScreen()
{
  drawPlayingFrame();
  drawPlayingGrid();
  drawPlayingServe();
  drawPlayingPlayers();
  drawPlayingScore();
}

// draw the winningscreen
void YscoreView::drawWinningScreen()
{
  drawPlayingFrame();
  drawWinningPlayers();
  drawRestart();
}

// draw the restart
void YscoreView::drawRestart()
{
  _display.setFont(MarVoSym_10pt);
  uint8_t y = (_display.yMax - 2) - _display.getFontHeight();
  tPoint pos = _display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                                50, LBL_UPDOWN_ARROW);

  _display.setFont(SansSerif_10pt);
  _display.printAt(pos.x, 50, LBL_RESTART);
}

// draw the stats screen
void YscoreView::drawStatsScreen(bool runningPoints)
{
  drawStatsFrame();
  drawStatsPlayers();
  drawStatsGrid();
  drawStatsGameScoresAt(SCREEN_STATS_SCORE_LEFT_X, SCREEN_STATS_SCORE_TOP_Y, THEM, runningPoints);
  drawStatsGameScoresAt(SCREEN_STATS_SCORE_LEFT_X, SCREEN_STATS_SCORE_BOTTOM_Y, US, runningPoints);

  drawRestart();
}

// draw the playing time screen
void YscoreView::drawPlayingTimeScreen()
{
  drawTimeFrame();
  printTime(_model->getPlayingTime());
  drawRestart();
}

///////////////////////////////////////////
// Print components and elements of screens
///////////////////////////////////////////

// draw the game scores for the given player
// if the running Points is true the last value
// are the current points in the game
void YscoreView::drawStatsGameScoresAt(uint8_t x, uint8_t y, uint8_t who, bool runningPoints)
{
  char buffer[3];

  uint8_t i;

  tPoint pos;

  pos.x = x;
  pos.y = y;

  _display.setFont(Digits_Small);

  for (i = 0; i < SUMMARYPAD_MAX_SIZE; i++)
  {
    uint8_t index = _model->getSummaryPad()[i];
    if (index == NULL_SCOREPAD_IDX)
    {
      break;
    }

    uint8_t points = _model->getPoints(index, who);
    pos = _display.printAt(pos.x, y, zeroPad(buffer, points));
    pos.x += 3;
  }

  if (runningPoints)
  {
    uint8_t points = _model->getPoints(who);

    _display.printAt(pos.x, y, zeroPad(buffer, points));
  }
}

// print a time given in millis
void YscoreView::printTime(unsigned long millis)
{
  char buffer[8];

  _display.setFont(SansSerif_10pt);

  tPoint pos = _display.printAt(SCREEN_TIME_X, SCREEN_TIME_Y, LBL_PLAYING_TIME);

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

  _display.setFont(SansSerif_12pt);
  _display.printCenteredAt(pos.y + 4, buffer);
}

// draw the battery icon
void YscoreView::drawBatteryIcon(uint8_t x, uint8_t y)
{
  uint8_t height = 8;
  uint8_t width = 12;

  // Draw the border
  _display.drawRect(x, y, width, height, TSRectangleNoFill, TS_8b_White);
  // draw the contact at the end
  _display.drawLine(x + width, y + 2, x + width, y + 5, TS_8b_White);

  // change the colour depending on the charge
  uint8_t batteryState = _model->getBatteryState();
  uint16_t colour = TS_8b_Green;
  if (batteryState <= 2)
  {
    colour = TS_8b_Red;
  }

  // clear the battery content
  _display.drawRect(x + 1, y + 1, 10, height - 2, TSRectangleFilled, TS_8b_Black);

  // draw the content
  _display.drawRect(x + 1, y + 1, batteryState, height - 2, TSRectangleFilled, colour);
}

// draw the playing frame
void YscoreView::drawPlayingFrame()
{
  drawPlayingMenu();
  drawButtonLabels();
}

// draw the playing grid
void YscoreView::drawPlayingGrid()
{
  // horizontal middle line
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_MIDDLE_LINE_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_MIDDLE_LINE_Y, TS_8b_Gray);

  // vertical (games)
  _display.drawLine(SCREEN_GAMES_LINE_X, SCREEN_MENU_MARGIN_Y, SCREEN_GAMES_LINE_X, _display.yMax, TS_8b_Gray);
  // vertical (points)
  _display.drawLine(SCREEN_POINTS_LINE_X, SCREEN_MENU_MARGIN_Y, SCREEN_POINTS_LINE_X, _display.yMax, TS_8b_Gray);
}

// draw the playing score
void YscoreView::drawPlayingScore()
{
  drawPlayingScoreGames();
  drawPlayingScorePoints();
}

// draw the number of sets for each team
void YscoreView::drawPlayingScoreGames()
{
  _display.setFont(Digits_Large);

  char buffer[2];
  uint8_t games = _model->getGames(THEM);
  itoa(games, buffer, 10);
  _display.printAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
                   SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                   buffer);

  games = _model->getGames(US);
  itoa(games, buffer, 10);
  _display.printAt(SCREEN_GAMES_LINE_X + SCREEN_MARGIN_OFFSET_X,
                   SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
                   buffer);
}

// draw the current points for each team
void YscoreView::drawPlayingScorePoints()
{
  char buffer[3];
  _display.setFont(Digits_Large);
  uint8_t points = _model->getPoints(THEM);
  _display.printAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
                   SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                   zeroPad(buffer, points));

  points = _model->getPoints(US);
  zeroPad(buffer, points);
  _display.printAt(SCREEN_POINTS_LINE_X + SCREEN_MARGIN_OFFSET_X,
                   SCREEN_MIDDLE_LINE_Y + SCREEN_MARGIN_OFFSET_Y,
                   zeroPad(buffer, points));
}

void YscoreView::drawPlayingServe()
{

  // determine which team is serving and which side
  uint8_t serving = THEM;

  // assume THEM have the serve
  // so we only need to check if that is not true
  if (_model->hasServe(US))
  {
    serving = US;
  }

  // get the points of the team playing
  uint8_t points = _model->getPoints(serving);
  _display.drawImageAt(SCREEN_SERVE_X, SCREEN_SERVE_Y, IMG_SERVE[serving][points % 2]);
}

// draw the players playing the game
void YscoreView::drawPlayingPlayers()
{
  // get the Player details
  uint8_t playerImges = _model->getPlayerPosition();

  _display.drawImageAt(SCREEN_PLAYER_LEFT_X,
                       SCREEN_PLAYER_TOP_Y, IMG_PLAYER_DOUBLES[playerImges][0]);

  _display.drawImageAt(SCREEN_PLAYER_RIGHT_X,
                       SCREEN_PLAYER_TOP_Y, IMG_PLAYER_DOUBLES[playerImges][1]);

  _display.drawImageAt(SCREEN_PLAYER_LEFT_X,
                       SCREEN_PLAYER_BOTTOM_Y, IMG_PLAYER_DOUBLES[playerImges][2]);

  _display.drawImageAt(SCREEN_PLAYER_RIGHT_X,
                       SCREEN_PLAYER_BOTTOM_Y, IMG_PLAYER_DOUBLES[playerImges][3]);
}

// draw the players stats
void YscoreView::drawStatsPlayers()
{
  uint8_t winner = _model->getWinner();

  _display.drawImageAt(SCREEN_STATS_PLAYER_LEFT_X,
                       SCREEN_STATS_PLAYER_TOP_Y, IMG_STATS_PLAYER[winner][0]);

  _display.drawImageAt(SCREEN_STATS_PLAYER_RIGHT_X,
                       SCREEN_STATS_PLAYER_TOP_Y, IMG_STATS_PLAYER[winner][1]);

  _display.drawImageAt(SCREEN_STATS_PLAYER_LEFT_X,
                       SCREEN_STATS_PLAYER_BOTTOM_Y, IMG_STATS_PLAYER[winner][2]);

  _display.drawImageAt(SCREEN_STATS_PLAYER_RIGHT_X,
                       SCREEN_STATS_PLAYER_BOTTOM_Y, IMG_STATS_PLAYER[winner][3]);
}

// draw the playing menu
void YscoreView::drawPlayingMenu()
{
  _display.drawImageAt(_display.xMin, _display.yMin, &img_Play);
  _display.drawLine(_display.xMin, SCREEN_MENU_MARGIN_Y, _display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, _display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, _display.yMax, TS_8b_Gray);
}

// draw the winning players of the match
void YscoreView::drawWinningPlayers()
{

  // draw the trophy
  tPoint trophyPos = _display.drawImageAt(SCREEN_BUTTON_LEFT_MARGIN_X + 12,
                                          SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_X,
                                          &img_Trophy);

  uint8_t winner = _model->getWinner();
  // draw the players
  tPoint pos = _display.drawImageAt(trophyPos.x + SCREEN_MARGIN_OFFSET_X,
                                    SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                                    IMG_WINNING_PLAYER[winner][0]);

  // draw the players
  pos = _display.drawImageAt(pos.x + SCREEN_MARGIN_OFFSET_X,
                             SCREEN_MENU_MARGIN_Y + SCREEN_MARGIN_OFFSET_Y,
                             IMG_WINNING_PLAYER[winner][1]);

  _display.setFont(SansSerif_12pt);
  _display.printAt(trophyPos.x + SCREEN_MARGIN_OFFSET_X,
                   pos.y + SCREEN_MARGIN_OFFSET_Y,
                   LBL_PLAYER[winner]);
}

// draw the Stats frame
void YscoreView::drawStatsFrame()
{
  drawStatsMenu();
  drawButtonLabels();
}

// draw the button labels
void YscoreView::drawStatsMenu()
{
  _display.drawImageAt(_display.xMin, _display.yMin, &img_Stats);
  _display.drawLine(_display.xMin, SCREEN_MENU_MARGIN_Y, _display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, _display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, _display.yMax, TS_8b_Gray);
}

// draw the Stats grid
void YscoreView::drawStatsGrid()
{
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_STATS_MIDDLE_LINE_Y,
                    SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_STATS_MIDDLE_LINE_Y, TS_8b_Gray);

  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_STATS_BOTTOM_LINE_Y,
                    SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);

  _display.drawLine(SCREEN_STATS_POINTS_LINE1_X, SCREEN_MENU_MARGIN_Y,
                    SCREEN_STATS_POINTS_LINE1_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);

  _display.drawLine(SCREEN_STATS_POINTS_LINE2_X, SCREEN_MENU_MARGIN_Y,
                    SCREEN_STATS_POINTS_LINE2_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);

  _display.drawLine(SCREEN_STATS_POINTS_LINE3_X, SCREEN_MENU_MARGIN_Y,
                    SCREEN_STATS_POINTS_LINE3_X, SCREEN_STATS_BOTTOM_LINE_Y, TS_8b_Gray);
}

// draw the button labels
void YscoreView::drawButtonLabels()
{
  _display.drawImageAt(_display.xMin, SCREEN_BUTTON_TOP_Y, &img_ArrowRight);
  _display.drawImageAt(_display.xMin, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowLeft);
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_LEFT_MARGIN_X, _display.yMax, TS_8b_Gray);
  _display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 3, SCREEN_BUTTON_TOP_Y, &img_ArrowUp);
  _display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 3, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowDown);
  _display.drawLine(SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, _display.yMax, TS_8b_Gray);
}

// draw the Time frame
void YscoreView::drawTimeFrame()
{
  drawTimeMenu();
  drawButtonLabels();
}

// draw the time menu labels
void YscoreView::drawTimeMenu()
{
  _display.drawImageAt(_display.xMin, _display.yMin, &img_Time);
  _display.drawLine(_display.xMin, SCREEN_MENU_MARGIN_Y, _display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, _display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, _display.yMax, TS_8b_Gray);
}

///////////////////////////////////////////////
// Convenience functions for handeling numbers
///////////////////////////////////////////////

// put the zero padded value into the provided buffer
char *YscoreView::zeroPad(char *buffer, uint8_t value)
{
  snprintf(buffer, sizeof(buffer), "%02d", value);
  return buffer;
}
