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
#include "TinyScreenBattery.h"

#include "YscoreModel.h"

/*
  Constructor
*/
YscoreModel::YscoreModel(TinyScreenExt &display) : _display(display)
{
}

// set the view that will be called if the model has been changed
void YscoreModel::setView(IYscoreView *view)
{
  _view = view;
}

// call the view to update it
void YscoreModel::updateView()
{
  if (_view == NULL)
  {
    return;
  }
  _view->update();
}

// call the view to update the battery
void YscoreModel::updateViewBattery()
{
  if (_view == NULL)
  {
    return;
  }
  _view->updateBattery();
}

// call the view to update the time
void YscoreModel::updateViewTime()
{
  if (_view == NULL)
  {
    return;
  }
  _view->updateTime();
}

// set the appstate of the model
void YscoreModel::setAppState(uint8_t appState)
{
  if (_appState != appState)
  {
    _appState = appState;
    // update the view
    _view->update();
  }
}

// set the appstate of the model
uint8_t YscoreModel::getAppState()
{
  return _appState;
}

///////////////////////
// Handle Battery State
///////////////////////

// handle updating the battery state
void YscoreModel::updateBatteryState()
{
  uint8_t newState = _display.getBatteryState();

  if (_batteryState != newState)
  {
    _batteryState = newState;
    _view->updateBattery();
  }
}

// handle updating the battery state
uint8_t YscoreModel::getBatteryState()
{
  return _batteryState;
}

// set time play started
void YscoreModel::startPlayingTime()
{
  _display.setDate(1, 1, 20);
  _display.setTime(0, 0, 0);
}

// update the time
void YscoreModel::updateTime()
{
  // only update the playing time if not in
  if (_appState == APP_STATE_WINNING || _appState == APP_STATE_STATS || _appState == APP_STATE_STATS_TIME)
  {
    return;
  }

  uint8_t changed = false;
  uint8_t hours = _display.getHours();
  if (_hours != hours)
  {
    _hours = hours;
    changed = true;
  }

  uint8_t minutes = _display.getMinutes();
  if (_minutes != minutes)
  {
    _minutes = minutes;
    changed = true;
  }

  uint8_t seconds = _display.getSeconds();
  if (_seconds != seconds)
  {
    _seconds = seconds;
    changed = true;
  }

  if (changed)
  {
    _view->updateTime();
  }
}

// get the current playing hours
uint8_t YscoreModel::getPlayingHours()
{
  // if we are in the stats time state
  // return the match playing time
  if (_appState == APP_STATE_STATS_TIME)
  {
    return _hours;
  }
  return _display.getHours();
}

// get the current playing minutes
uint8_t YscoreModel::getPlayingMinutes()
{
  // if we are in the stats time state
  // return the match playing time
  if (_appState == APP_STATE_STATS_TIME)
  {
    return _minutes;
  }
  return _display.getMinutes();
}

// get the current playing seconds
uint8_t YscoreModel::getPlayingSeconds()
{
  // if we are in the stats time state
  // return the match playing time
  if (_appState == APP_STATE_STATS_TIME)
  {
    return _seconds;
  }
  return _display.getSeconds();
}

// gets the current score pad index
uint8_t YscoreModel::getScorepadIdx()
{
  return _scorepadIdx;
}

// resets the scorepad
void YscoreModel::resetScorepad()
{
  _scorepad[0][US] = 0;
  _scorepad[0][THEM] = 0;
  _scorepad[0][PLAYER] = 0;

  _winner = NONE;
  _scorepadIdx = 0;

  // reset the summary pad
  resetSummarypad();
}

// function increments the score pad index
void YscoreModel::incScorepadIdx()
{
  // copy the data of the existing row to the new row
  // and increment the index
  copyScorepadRowTo(_scorepadIdx, _scorepadIdx + 1);
  _scorepadIdx++;
}

// function decrements the score pad index
// taking into account the EndOfGameMarker
// if there is one
void YscoreModel::decScorepadIdx()
{
  _scorepadIdx--;
  if (isEndOfGame(_scorepadIdx))
  {
    // go back before the end of the game
    _scorepadIdx--;
  }

  // always update the view when playing
  if (_appState == APP_STATE_PLAYING)
  {
    updateView();
  }
}

// get the index into the points table for the
// given summary pad index
uint8_t YscoreModel::getPointsIndex(uint8_t index)
{
  if (index > SUMMARYPAD_MAX_SIZE)
  {
    return NULL_SCOREPAD_IDX;
  }

  return _summaryPad[index];
}

// returns true if play has started
uint8_t YscoreModel::hasPlayStarted()
{
  return _scorepadIdx > 0;
}

// gets the number of games from the  scorepad row at the given index for the given player
uint8_t YscoreModel::getGames(uint8_t who)
{
  uint8_t result = _scorepad[_scorepadIdx][who] & MASK_GAMES;
  return result >> 5;
}

// adds one to the number of points for the given player
void YscoreModel::incPoints(uint8_t who)
{
  _scorepad[_scorepadIdx][who]++;

  checkGameWon();
  // if we are still playing update the view
  // if we are in the Winning state then that will
  // have updated the view.
  if (getAppState() == APP_STATE_PLAYING)
  {
    updateView();
  }
}

// gets the current points for the given player
uint8_t YscoreModel::getPoints(uint8_t who)
{
  uint8_t result = getPoints(who, _scorepadIdx);
  return result;
}

// gets the points from the  scorepad row at the given index for the given player
uint8_t YscoreModel::getPoints(uint8_t who, uint8_t index)
{
  uint8_t result = _scorepad[index][who] & MASK_POINTS;
  return result;
}

// gets the serve status for the given player
bool YscoreModel::hasServe(uint8_t who)
{
  // get if the serve is true or false for the
  // side requested
  bool result = hasServe(who, _scorepadIdx);
  return result;
}

// gets the serve status at the given index for the given player
inline bool YscoreModel::hasServe(uint8_t who, uint8_t index)
{
  // get if the serve is true or false
  bool result = _scorepad[index][PLAYER] & MASK_1ST_BIT_ON;
  return who == US ? result : !result;
}

// sets the uint8_t serve bit of the scorepad row at the given index off or on
// depending on who has the serve
void YscoreModel::setServe(uint8_t who)
{
  if (who == US)
  {
    // record that US now has the serve
    _scorepad[_scorepadIdx][PLAYER] |= MASK_1ST_BIT_ON;
    // if we are not at the start of the match
    if (_scorepadIdx != 0)
    {
      // check if we had the serve on the previous point
      bool hadServe = hasServe(US, _scorepadIdx - 1);
      if (hadServe)
      {
        // toggle the position of the players
        _scorepad[_scorepadIdx][PLAYER] ^= MASK_2ND_BIT_ON;
      }
    }
  }
  else
  {
    _scorepad[_scorepadIdx][PLAYER] &= MASK_1ST_BIT_OFF;
    // if we are not at the start of the match
    if (_scorepadIdx != 0)
    {
      // check if they had the serve on the previous point
      bool hadServe = hasServe(THEM, _scorepadIdx - 1);
      if (hadServe)
      {
        // toggle the position of the players
        _scorepad[_scorepadIdx][PLAYER] ^= MASK_3RD_BIT_ON;
      }
    }
  }
}

// gets the current player positions
uint8_t YscoreModel::getPlayerPosition()
{
  uint8_t result = _scorepad[_scorepadIdx][PLAYER];
  return result;
}

// check if a game was won
void YscoreModel::checkGameWon()
{

  // first check if a game was won by US
  uint8_t whoToUpdate = checkGameWonBy(US, THEM);
  if (whoToUpdate == NONE)
  {
    whoToUpdate = checkGameWonBy(THEM, US);
  }

  // perform the update
  if (whoToUpdate != NONE)
  {
    // mark the current scorepad as an end of game
    endOfGameOn(_scorepadIdx);
    // create a new scorepad entry for the start of the game
    copyScorepadNewGameRowTo(_scorepadIdx, _scorepadIdx + 1);
    // increment the number of games in the new row
    incGames(_scorepadIdx + 1, whoToUpdate);
    // move to the new score pad entry
    _scorepadIdx++;

    checkMatchWon();
  }
}

// check if a game was won by lhs as compared to rhs
// if the game was won by the lhs return lhs else
// return NONE, basically this determines if lhs
// won a game. It makes no statement about the rhs
// this must be tested for separatly
uint8_t YscoreModel::checkGameWonBy(uint8_t lhs, uint8_t rhs)
{
  uint8_t result = NONE;

  // get the points
  uint8_t lhsPoints = getPoints(lhs);
  uint8_t rhsPoints = getPoints(rhs);

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
void YscoreModel::checkMatchWon()
{
  uint8_t whoToUpdate = NONE;
  // get the games
  uint8_t usGames = getGames(US);
  uint8_t themGames = getGames(THEM);

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
    // record the winner
    _winner = whoToUpdate;
    createSummaryTable();
    setAppState(APP_STATE_WINNING);
  }
}

// gets the identity of the winner
uint8_t YscoreModel::getWinner()
{
  return _winner;
}

// copy the score pad row reseting the has serve bit and EndOfGame at the same time
void YscoreModel::copyScorepadRowTo(uint8_t from, uint8_t to)
{
  // copy the score pad row mask out the end of game bit
  _scorepad[to][THEM] = _scorepad[from][THEM] & MASK_8TH_BIT_OFF;
  // copy the US score pad row
  _scorepad[to][US] = _scorepad[from][US];
  // copy the PLAYER score pad row
  _scorepad[to][PLAYER] = _scorepad[from][PLAYER];
}

// copy the score pad row keeping the serve and the games
void YscoreModel::copyScorepadNewGameRowTo(uint8_t from, uint8_t to)
{
  // keep the number of games
  _scorepad[to][THEM] = _scorepad[from][THEM] & MASK_GAMES;
  // keep the number of games and the serve bit
  _scorepad[to][US] = _scorepad[from][US] & MASK_GAMES;
  // keep the number of games and the serve position
  _scorepad[to][PLAYER] = _scorepad[from][PLAYER];
}

// resets all the values in the summarypad to NULL_SCOREPAD_IDX
void YscoreModel::resetSummarypad()
{
  for (int i = 0; i < SUMMARYPAD_MAX_SIZE; i++)
  {
    _summaryPad[i] = NULL_SCOREPAD_IDX;
  }
}

// function creates the summary table from the scorepad
void YscoreModel::createSummaryTable()
{
  resetSummarypad();
  uint8_t summaryIdx = 0;
  for (int i = 0; i < _scorepadIdx; i++)
  {
    // if this was the score at the end of the game
    if (isEndOfGame(i))
    {
      _summaryPad[summaryIdx] = i;
      summaryIdx++;
    }
  }
}

//////////////////////////////////////////////////////////////////
// manage data extraction and setting of values from the score pad
//////////////////////////////////////////////////////////////////

// sets the THEM uint8_t EndOfGame bit of the scorepad row at the given index on
void YscoreModel::endOfGameOn(uint8_t index)
{
  _scorepad[index][THEM] |= MASK_8TH_BIT_ON;
}

// gets the THEM uint8_t EndOfGame bit of the scorepad row at the given index on
bool YscoreModel::isEndOfGame(uint8_t index)
{
  return _scorepad[index][THEM] & MASK_8TH_BIT_ON;
}

// adds one to the number of games given index for the given player
void YscoreModel::incGames(uint8_t index, uint8_t who)
{
  _scorepad[index][who] += ONE_GAME;
}
