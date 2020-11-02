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
#include "fonts/SansSerif_8pt.h"

#include "YscoreController.h"

/*
  Constructor
*/
YscoreController::YscoreController(TinyScreenExt &display) : _display(display)
{
}

// sets the model to be used to retrieve the values
// to be shown in the view
void YscoreController::setModel(YscoreModel *model)
{
  _model = model;
}

// function resets all button states to BUT_STATE_UNPRESSED
void YscoreController::initilise()
{
  resetButtonState();
  _model->resetScorepad();
  _model->setAppState(APP_STATE_STARTING);
}

///////////////////////////
// Handle the Button states
///////////////////////////

// update the button states
void YscoreController::updateButtonStates()
{
  // get the current state of the all buttons
  int8_t buttons = _display.getButtons();

  bool curStateMode = (buttons & TSButtonMode) > 0;
  bool curStateBack = (buttons & TSButtonBack) > 0;
  bool curStateThem = (buttons & TSButtonThem) > 0;
  bool curStateUs = (buttons & TSButtonUs) > 0;

  // determine what the button states are
  _buttonStateMode = readButtonState(_prevStateMode, curStateMode);
  _buttonStateBack = readButtonState(_prevStateBack, curStateBack);
  _buttonStateUs = readButtonState(_prevStateUs, curStateUs);
  _buttonStateThem = readButtonState(_prevStateThem, curStateThem);

  // update the prev states with the current state
  _prevStateMode = curStateMode;
  _prevStateBack = curStateBack;
  _prevStateThem = curStateThem;
  _prevStateUs = curStateUs;

  // printButtonStates();
}

// update the button states
void YscoreController::updateButtonStatesSequence()
{
  bool curStateMode = false;
  bool curStateBack = false;
  bool curStateThem = false;
  bool curStateUs = false;

  long button = random(0, 12);

  if (button == 0)
  {
    _buttonStateMode = BUT_STATE_PRESSED;
    curStateMode = true;
  }

  if (button == 1)
  {
    _buttonStateBack = BUT_STATE_PRESSED;
    curStateBack = true;
  }

  if (button > 2 && button < 7)
  {
    _buttonStateUs = BUT_STATE_PRESSED;
    curStateUs = true;
  }

  if (button > 7)
  {
    _buttonStateThem = BUT_STATE_PRESSED;
    curStateThem = true;
  }

  // update the prev states with the current state
  _prevStateMode = curStateMode;
  _prevStateBack = curStateBack;
  _prevStateThem = curStateThem;
  _prevStateUs = curStateUs;
}

void YscoreController::printButtonStates()
{
  _display.setFont(SansSerif_8pt);
  _display.setCursor(0, 50);
  _display.print("M ");
  printButtonState(_buttonStateMode);
  _display.print("B ");
  printButtonState(_buttonStateBack);
  _display.print("T ");
  printButtonState(_buttonStateThem);
  _display.print("U ");
  printButtonState(_buttonStateUs);
}

void YscoreController::printButtonState(uint8_t _buttonState)
{
  if (_buttonState == BUT_STATE_PRESSED)
  {
    _display.print("p ");
  }
  else
  {
    _display.print("u ");
  }
}

// update the button state for a single button
uint8_t YscoreController::readButtonState(bool prevState, bool currState)
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
void YscoreController::resetButtonState()
{
  _buttonStateMode = BUT_STATE_UNPRESSED;
  _buttonStateBack = BUT_STATE_UNPRESSED;
  _buttonStateUs = BUT_STATE_UNPRESSED;
  _buttonStateThem = BUT_STATE_UNPRESSED;
}

////////////////////////////////////////
// Perform Actions depending on AppState
// and button state
////////////////////////////////////////

// perform action
void YscoreController::performAction()
{
  if (_model == NULL)
  {
    return;
  }

  // update the current state of the buttons
  updateButtonStates();

  // get the current app state and perform the action
  uint8_t appState = _model->getAppState();
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
void YscoreController::performActionDefault()
{
}

// deform the action for the App_Starting state
// must set modelChanged if the model is changed by this action
void YscoreController::performActionStarting()
{
  if ((_buttonStateMode == BUT_STATE_PRESSED) || (_buttonStateBack == BUT_STATE_PRESSED) || (_buttonStateThem == BUT_STATE_PRESSED) || (_buttonStateUs == BUT_STATE_PRESSED))
  {
    _model->setAppState(APP_STATE_SET_SERVE);
    return;
  }
}

// peform the action for the app setting state
// must set modelChanged if the model in changed by this action
void YscoreController::performActionSettingServe()
{
  // check for go back
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_STARTING);
    return;
  }

  // check for do nothing
  bool doNothing = checkDoNothing();
  if (doNothing)
  {
    return;
  }

  uint8_t whoToUpdate = NONE;

  if (_buttonStateUs == BUT_STATE_PRESSED)
  {
    whoToUpdate = US;
  }

  if (_buttonStateThem == BUT_STATE_PRESSED)
  {
    whoToUpdate = THEM;
  }

  _model->setServe(whoToUpdate);
  _model->startPlayingTime();
  _model->setAppState(APP_STATE_PLAYING);
}

// perform the action for the app playing state
// must set modelChanged if the model in changed by this action
void YscoreController::performActionPlaying()
{
  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->createSummaryTable();
    _model->setAppState(APP_STATE_PAUSING);
    return;
  }

  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    // We want to go back and no points have been scored
    if (_model->hasPlayStarted())
    {
      _model->setAppState(APP_STATE_SET_SERVE);
      _model->resetScorepad();
    }
    else
    {
      _model->decScorepadIdx();
    }
    return;
  }

  // check for do nothing
  bool doNothing = checkDoNothing();
  if (doNothing)
  {
    return;
  }

  uint8_t whoToUpdate = NONE;

  if (_buttonStateUs == BUT_STATE_PRESSED)
  {
    whoToUpdate = US;
  }

  if (_buttonStateThem == BUT_STATE_PRESSED)
  {
    whoToUpdate = THEM;
  }

  _model->incScorepadIdx();
  // update the score and who has the serve
  _model->setServe(whoToUpdate);
  _model->incPoints(whoToUpdate);
  // checkGameWon();
}

// return true if neither the us and them buttons were pressed or
// both were pressed
bool YscoreController::checkDoNothing()
{
  // either both buttons were pressed or neither button was pressed
  return _buttonStateUs == _buttonStateThem;
}

// perform the action for the App_Winning state
// must set modelChanged if the model in changed by this action
void YscoreController::performActionWinning()
{
  // show the stats
  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_STATS);
    return;
  }

  // We have not won yet
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->decScorepadIdx();
    // ensure that we are playing again
    _model->setAppState(APP_STATE_PLAYING);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SET_SERVE);
    _model->resetScorepad();
    return;
  }

  return;
}

// perform the action for the App_Stats state
void YscoreController::performActionStats()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_WINNING);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_STATS_TIME);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SET_SERVE);
    _model->resetScorepad();
    return;
  }
}

// perform the action for the App_Stats_time state
void YscoreController::performActionStatsTime()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_STATS);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SET_SERVE);
    _model->resetScorepad();
    return;
  }
}

// perform the action for the App_Pausing state
void YscoreController::performActionPausing()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_PLAYING);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_PAUSING_TIME);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SET_SERVE);
    _model->resetScorepad();
    return;
  }
}

// perform the action for the App_Pausing_Time state
void YscoreController::performActionPausingTime()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_PAUSING);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SET_SERVE);
    _model->resetScorepad();
    return;
  }
}
