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
void YscoreView::update()
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
    drawScreenStart();
    break;
  case APP_STATE_SETTING_SERVE:
    drawScreenSettingServe();
    break;
  case APP_STATE_PLAYING:
    drawScreenPlaying();
    break;
  case APP_STATE_CURRENT_SCORE:
    // draw the Match score screen with the running
    // points
    drawScreenMatchScore(true);
    break;
  case APP_STATE_CURRENT_TIME:
    drawScreenMatchTime();
    break;
  case APP_STATE_WINNING:
    drawScreenWinning();
    break;
  case APP_STATE_MATCH_SCORE:
    // draw the match score screen without the running
    // points
    drawScreenMatchScore(false);
    break;
  case APP_STATE_MATCH_TIME:
    drawScreenMatchTime();
    break;
  case APP_STATE_SETTING_TYPE_OF_MATCH:
    drawScreenSettingTypeOfMatch();
    break;
  case APP_STATE_SETTING_BRIGHTNESS:
    drawScreenSettingBrightness();
    break;
  case APP_STATE_SETTING_LOCAL:
    drawScreenSettingLocal();
    break;
  case APP_STATE_SETTING_HANDEDNESS:
    drawScreenSettingHandedness();
    break;
  case APP_STATE_ABOUT:
    drawScreenAbout();
    break;
  case APP_STATE_ACK:
    drawScreenAck();
    break;
  case APP_STATE_UPDATE:
    drawScreenUpdate();
    break;
  }

  // always update the battery if the state was updated
  // after that the battery will be updated separatly
  updateBattery();

  // display.display();
}

// update the view of the battery according to the state
void YscoreView::updateBattery()
{
  if (_model == NULL)
  {
    return;
  }
  drawBatteryIcon(SCREEN_BATTERY_X, _display.yMin);
}

// update the view of the time according to the state
void YscoreView::updateTime()
{
  if (_model == NULL)
  {
    return;
  }

  if (_model->getAppState() == APP_STATE_CURRENT_TIME)
  {
    drawScreenMatchTime();
  }
}

///////////////////////////////////////////
// Draw the different screens
//////////////////////////////////////////

// draw the start screen
void YscoreView::drawScreenStart()
{
  _display.setFont(SansSerif_8pt);
  _display.printAt(_display.xMin, _display.yMin, _resource.getLblCopyright(_model->getLocal()));

  // draw the logo
  _display.drawImageAt(_display.xMin, SCREEN_START_IMAGE_Y, &img_BT32x32);

  // draw the name appname
  _display.drawImageAt(SCREEN_START_TEXT_X, 14, &img_AppName63x22);

  _display.setFont(MarVoSym_8pt);
  tPoint pos = _display.printAt(SCREEN_START_TEXT_X, SCREEN_START_TEXT_Y, LBL_RIGHT_ARROW);
  _display.setFont(SansSerif_8pt);
  pos = _display.printAt(pos.x, SCREEN_START_TEXT_Y, _resource.getLblPlay(_model->getLocal()));
  uint8_t y = pos.y + SCREEN_START_TEXT_OFFSET_Y;
  _display.setFont(MarVoSym_8pt);
  pos = _display.printAt(SCREEN_START_TEXT_X, y, LBL_LEFT_ARROW);
  _display.setFont(SansSerif_8pt);
  pos = _display.printAt(pos.x, y, _resource.getLblSettings(_model->getLocal()));

  // take into account the handedness
  if (_model->getHandedness() == HANDEDNESS_RIGHT)
  {
    drawButtonLabelsLeft();
  }
  else
  {
    drawButtonLabelsRight();
  }
}

// draw the playing screen
void YscoreView::drawScreenPlaying()
{
  drawFrame(_resource.getTitlePlaying(_model->getLocal()));
  drawPlayingGrid();
  drawPlayingServe();
  drawPlayingPlayers();
  drawPlayingScore();
}

// draw the winningscreen
void YscoreView::drawScreenWinning()
{
  drawFrame(_resource.getTitleWinning(_model->getLocal()));
  drawWinningPlayers();
  drawRestart();
}

// draw the match score screen
void YscoreView::drawScreenMatchScore(bool runningPoints)
{
  drawFrame(_resource.getTitleMatchScore(_model->getLocal()));
  drawStatsPlayers();
  drawStatsGrid();
  drawStatsGameScoresAt(SCREEN_STATS_SCORE_LEFT_X, SCREEN_STATS_SCORE_TOP_Y, THEM, runningPoints);
  drawStatsGameScoresAt(SCREEN_STATS_SCORE_LEFT_X, SCREEN_STATS_SCORE_BOTTOM_Y, US, runningPoints);

  drawRestart();
}

// draw the match time screen
void YscoreView::drawScreenMatchTime()
{
  drawFrame(_resource.getTitleMatchTime(_model->getLocal()));
  printTime(_model->getPlayingHours(), _model->getPlayingMinutes(), _model->getPlayingSeconds());
  drawRestart();
}

// draw the setting serve screen
void YscoreView::drawScreenSettingServe()
{
  uint8_t local = _model->getLocal();
  drawFrame(_resource.getTitleWhoServes(local));
  drawSelectionFrame();
  _display.setFont(SansSerif_12pt);
  drawSelection(_model->getWhoServes(), _resource.getSelectionListWhoServes(local, _model->getTypeOfMatch()));
}

// draw the settings type of match screen
void YscoreView::drawScreenSettingTypeOfMatch()
{
  uint8_t local = _model->getLocal();
  drawFrame(_resource.getTitleTypeOfMatch(local));
  drawSelectionFrame();
  _display.setFont(SansSerif_12pt);
  drawSelection(_model->getTypeOfMatch(), _resource.getSelectionListTypeOfMatch(local));
}

// draw the settings languge
void YscoreView::drawScreenSettingLocal()
{
  uint8_t local = _model->getLocal();
  drawFrame(_resource.getTitleLocal(local));
  drawSelectionFrame();
  _display.setFont(SansSerif_12pt);
  drawSelection(local, _resource.getSelectionListLocal(local));
}

// draw the settings Handedness
void YscoreView::drawScreenSettingHandedness()
{
  uint8_t local = _model->getLocal();
  drawFrame(_resource.getTitleHandedness(local));
  drawSelectionFrame();
  _display.setFont(SansSerif_12pt);
  uint8_t handedness = _model->getHandedness();
  drawSelection(handedness, _resource.getSelectionListHandedness(local));
}

// draw the settings Brightness
void YscoreView::drawScreenSettingBrightness()
{
  uint8_t local = _model->getLocal();
  drawFrame(_resource.getTitleBrightness(local));
  drawSelectionFrame();
  _display.setFont(SansSerif_12pt);
  drawSelection(_model->getBrightness(), _resource.getSelectionListBrightness(local));
}

// draw the about screen
void YscoreView::drawScreenAbout()
{
  drawFrame(_resource.getTitleAbout(_model->getLocal()));

  // draw the logo
  _display.drawImageAt(10, SCREEN_MENU_MARGIN_Y + 2, &img_BT22x22);

  _display.drawImageAt(33, SCREEN_MENU_MARGIN_Y + 4, &img_AppName54x20);

  _display.setFont(SansSerif_12pt);
  tPoint pos = _display.printCenteredAt(36, _resource.getLblFindUsAt(_model->getLocal()));

  _display.setFont(SansSerif_8pt);
  _display.printCenteredAt(pos.y, LBL_WEB_ADDRESS);
}

// draw the ack screen
void YscoreView::drawScreenAck()
{
  drawFrame(_resource.getTitleAcknowledgement(_model->getLocal()));
  _display.setFont(TinyFont);
  uint8_t posx = SCREEN_BUTTON_LEFT_MARGIN_X + 2;
  uint8_t posy = SCREEN_MENU_MARGIN_Y + 2;

  tPoint pos = _display.printAt(posx, posy, LBL_ACK_LINE1);
  pos = _display.printAt(posx, pos.y, LBL_ACK_LINE2);
  pos = _display.printAt(posx, pos.y, LBL_ACK_LINE3);
  pos = _display.printAt(posx, pos.y, LBL_ACK_LINE4);
  pos = _display.printAt(posx, pos.y, LBL_ACK_LINE5);
  pos = _display.printAt(posx, pos.y, LBL_ACK_LINE6);
  pos = _display.printAt(posx, pos.y, LBL_ACK_LINE7);
  pos = _display.printAt(posx, pos.y, LBL_ACK_LINE8);
}

// draw the ack screen
void YscoreView::drawScreenUpdate()
{
  drawFrame(_resource.getTitleUpdate(_model->getLocal()));
  _display.setFont(SansSerif_12pt);
  _display.printCenteredAt(30, _resource.getTitleUpdate(_model->getLocal()));
}

///////////////////////////////////////////
// elements of screens
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
    uint8_t index = _model->getPointsIndex(i);
    if (index == NULL_SCOREPAD_IDX)
    {
      break;
    }

    uint8_t points = _model->getPoints(who, index);

    pos = _display.printAt(pos.x, y, zeroPad(buffer, points));
    pos.x += 3;
  }

  if (runningPoints)
  {
    uint8_t points = _model->getPoints(who);

    _display.printAt(pos.x, y, zeroPad(buffer, points));
  }
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
                   _resource.getLblPlayer(_model->getLocal(), _model->getTypeOfMatch(), winner));
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

// // draw the Time frame
// void YscoreView::drawTimeFrame()
// {
//   drawTimeMenu();
//   drawButtonLabels();
// }

// // draw the time menu labels
// void YscoreView::drawTimeMenu()
// {
//   _display.drawImageAt(_display.xMin, _display.yMin, &img_Time);
//   _display.drawLine(_display.xMin, SCREEN_MENU_MARGIN_Y, _display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
//   _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, _display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, _display.yMax, TS_8b_Gray);
// }

///////////////////////////////////////////////
// Screen "widgits"
///////////////////////////////////////////////
// draw a frame
void YscoreView::drawFrame(const char *title)
{
  drawMenu(title);
  drawButtonLabels();
}

// draw a menu
void YscoreView::drawMenu(const char *title)
{
  _display.setFont(SansSerif_8pt);
  _display.printAt(0, 0, title);
  _display.drawLine(_display.xMin, SCREEN_MENU_MARGIN_Y, _display.xMax, SCREEN_MENU_MARGIN_Y, TS_8b_Gray);
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, _display.yMax, SCREEN_BUTTON_RIGHT_MARGIN_X, _display.yMax, TS_8b_Gray);
  _display.drawLine(SCREEN_BUTTON_LEFT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_LEFT_MARGIN_X, _display.yMax, TS_8b_Gray);
  _display.drawLine(SCREEN_BUTTON_RIGHT_MARGIN_X, SCREEN_MENU_MARGIN_Y, SCREEN_BUTTON_RIGHT_MARGIN_X, _display.yMax, TS_8b_Gray);
}

// draw the settings list
void YscoreView::drawSelection(uint8_t index, const tSelectionList list)
{
  _display.printCenteredAt(SCREEN_SELECTION_MIDDLE_Y, list.list[index]);

  if (index - 1 > -1)
  {
    _display.printCenteredAt(SCREEN_SELECTION_TOP_Y, list.list[index - 1]);
  }

  if (index + 1 < list.length)
  {
    _display.printCenteredAt(SCREEN_SELECTION_BOTTOM_Y, list.list[index + 1]);
  }
}

// draw the selection frame
void YscoreView::drawSelectionFrame()
{
  // draw a box round the selected text
  _display.drawRect(SCREEN_SELECTION_TL_X, SCREEN_SELECTION_TL_Y,
                    SCREEN_SELECTION_WIDTH, SCREEN_SELECTION_HEGHT, 0, TS_8b_Gray);
}

// draw the restart
void YscoreView::drawRestart()
{
  _display.setFont(MarVoSym_10pt);
  uint8_t y = (_display.yMax - 2) - _display.getFontHeight();
  tPoint pos = _display.printAt(SCREEN_BUTTON_LEFT_MARGIN_X + SCREEN_MARGIN_OFFSET_X,
                                50, LBL_UPDOWN_ARROW);

  _display.setFont(SansSerif_10pt);
  _display.printAt(pos.x, 50, _resource.getLblRestart(_model->getLocal()));
}

// draw the button labels
void YscoreView::drawButtonLabels()
{
  drawButtonLabelsLeft();
  drawButtonLabelsRight();
}

// draw the button labels
void YscoreView::drawButtonLabelsLeft()
{
  if (_model->getHandedness() == HANDEDNESS_RIGHT)
  {
    _display.drawImageAt(_display.xMin, SCREEN_BUTTON_TOP_Y, &img_ArrowRight);
    _display.drawImageAt(_display.xMin, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowLeft);
  }
  else
  {
    _display.drawImageAt(_display.xMin, SCREEN_BUTTON_TOP_Y, &img_ArrowUp);
    _display.drawImageAt(_display.xMin, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowDown);
  }
}

// draw the button labels
void YscoreView::drawButtonLabelsRight()
{
  if (_model->getHandedness() == HANDEDNESS_RIGHT)
  {
    _display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 2, SCREEN_BUTTON_TOP_Y, &img_ArrowUp);
    _display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 2, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowDown);
  }
  else
  {
    _display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 2, SCREEN_BUTTON_TOP_Y, &img_ArrowRight);
    _display.drawImageAt(SCREEN_BUTTON_RIGHT_MARGIN_X + 2, SCREEN_BUTTON_BOTTOM_Y, &img_ArrowLeft);
  }
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
  uint8_t colour = TS_8b_Green;
  if (batteryState <= 2)
  {
    colour = TS_8b_Red;
  }

  // clear the battery content
  _display.drawRect(x + 1, y + 1, 10, height - 2, TSRectangleFilled, TS_8b_Black);

  // draw the content
  _display.drawRect(x + 1, y + 1, batteryState, height - 2, TSRectangleFilled, colour);
}

// print a time given in millis
void YscoreView::printTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
  char buffer[12];

  _display.setFont(SansSerif_10pt);

  tPoint pos = _display.printAt(SCREEN_TIME_X, SCREEN_TIME_Y, LBL_PLAYING_TIME);

  uint8_t days = _display.getDay() - 1;

  // temp for measuring standby time
  //if (days != 0) {
  snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d:%02d", days, hours, minutes, seconds);
  //}

  // if (hours != 0)
  // {
  //   snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hours, minutes, seconds);
  // }
  // else
  // {
  //   snprintf(buffer, sizeof(buffer), "%02d:%02d", minutes, seconds);
  // }

  _display.setFont(SansSerif_12pt);
  _display.printCenteredAt(pos.y + 4, buffer);
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
