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
#include "yScore.h"
#include "YscoreController.h"

/*
  Constructor
*/
YscoreController::YscoreController(TinyScreenExt &display) : _display(display)
{
  //initButtons();
}

// sets the model to be used to retrieve the values
// to be shown in the view
void YscoreController::setModel(YscoreModel *model)
{
  _model = model;
}

// initlise all the buttons for the fliped configuration
//
void YscoreController::initButtons()
{
  // needs to be set so that the button definitions are correct
  _display.setFlip(true);
  _TSButtonMode = TSButtonUpperLeft;
  _TSButtonBack = TSButtonLowerLeft;
  _TSButtonThem = TSButtonUpperRight;
  _TSButtonUs = TSButtonLowerRight;
}

// function resets all button states to BUT_STATE_UNPRESSED
void YscoreController::initilise()
{
  initButtons();
  resetButtonState();
  _model->resetScorepad();
  _model->setAppState(APP_STATE_STARTING);
}

///////////////////////////
// Handle the Button states
///////////////////////////

// update the button states
uint8_t YscoreController::updateButtonStates()
{
  // get the current state of the all buttons
  int8_t buttons = _display.getButtons();

  bool curStateMode = (buttons & _TSButtonMode) > 0;
  bool curStateBack = (buttons & _TSButtonBack) > 0;
  bool curStateThem = (buttons & _TSButtonThem) > 0;
  bool curStateUs = (buttons & _TSButtonUs) > 0;

  // determine what the button states are
  _buttonStateMode = readButtonState(_prevStateMode, curStateMode);
  _buttonStateBack = readButtonState(_prevStateBack, curStateBack);
  _buttonStateUs = readButtonState(_prevStateUs, curStateUs);
  _buttonStateThem = readButtonState(_prevStateThem, curStateThem);

  uint8_t changed = BUTTONS_STATE_NO_CHANGE;
  // update the prev states with the current state
  if (_prevStateMode != curStateMode)
  {
    _prevStateMode = curStateMode;
    changed = BUTTONS_STATE_CHANGED;
  }

  if (_prevStateBack != curStateBack)
  {
    _prevStateBack = curStateBack;
    changed = BUTTONS_STATE_CHANGED;
  }

  if (_prevStateThem != curStateThem)
  {
    _prevStateThem = curStateThem;
    changed = BUTTONS_STATE_CHANGED;
  }

  if (_prevStateUs != curStateUs)
  {
    _prevStateUs = curStateUs;
    changed = BUTTONS_STATE_CHANGED;
  }

  // printButtonStates();
  return changed;
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
  int8_t changed = updateButtonStates();
  if (BUTTONS_STATE_NO_CHANGE == changed)
  {
    // check if no button has been pressed for a while
    _performActionCount++;

    //_display.printDebug(_performActionCount);

    // we need to go to sleep
    if (_performActionCount > SLEEP_THRESHHOLD)
    {
      _performActionCount = 0;
      // turn off the display and go to sleep
      _display.off();
      _display.standByMode();
      // when we are awoken we restart here
      // clear the current button state
      resetButtonState();
      return;
    }
    else
    {
      return;
    }
  }

  // button state has changed
  // reset the performActionCounter
  _performActionCount = 0;

  // get the current app state and perform the action
  uint8_t appState = _model->getAppState();

  switch (appState)
  {
  case APP_STATE_STARTING:
    performActionStarting();
    break;
  case APP_STATE_SETTING_SERVE:
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
  case APP_STATE_SETTING_TYPE_OF_MATCH:
    performActionSettingTypeOfMatch();
    break;
  case APP_STATE_SETTING_BRIGHTNESS:
    performActionSettingBrightness();
    break;
  case APP_STATE_SETTING_LANGUAGE:
    performActionSettingLanguage();
    break;
  case APP_STATE_SETTING_HANDEDNESS:
    performActionSettingHandedness();
    break;
  case APP_STATE_ABOUT:
    performActionAbout();
    break;
  case APP_STATE_ACK:
    performActionAck();
    break;
  case APP_STATE_UPDATE:
    performActionUpdate();
    break;
  }
}

// perform the default action for all app states
void YscoreController::performActionDefault()
{
}

// perform the action for the APP_STATE_STARTING
void YscoreController::performActionStarting()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_TYPE_OF_MATCH);
    return;
  }

  if ((_buttonStateMode == BUT_STATE_PRESSED) || (_buttonStateThem == BUT_STATE_PRESSED) || (_buttonStateUs == BUT_STATE_PRESSED))
  {
    _model->setAppState(APP_STATE_SETTING_SERVE);
    return;
  }
}

// peform the action for the APP_STATE_SETTING_SERVE
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

// perform the action for the APP_STATE_PLAYING
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
    // We want to go back has play started
    if (_model->hasPlayStarted())
    {
      _model->decScorepadIdx();
    }
    else
    {
      // play has not started
      _model->setAppState(APP_STATE_SETTING_SERVE);
      _model->resetScorepad();
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

// perform the action for the APP_STATE_WINNING
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
    _model->setAppState(APP_STATE_SETTING_SERVE);
    _model->resetScorepad();
    return;
  }

  return;
}

// perform the action for the APP_STATE_STATS
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
    _model->setAppState(APP_STATE_SETTING_SERVE);
    _model->resetScorepad();
    return;
  }
}

// perform the action for the APP_STATE_STATS_TIME
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
    _model->setAppState(APP_STATE_SETTING_SERVE);
    _model->resetScorepad();
    return;
  }
}

// perform the action for the APP_STATE_PAUSING
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
    _model->setAppState(APP_STATE_SETTING_SERVE);
    _model->resetScorepad();
    return;
  }
}

// perform the action for the APP_STATE_PAUSING_TIME
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
    _model->setAppState(APP_STATE_SETTING_SERVE);
    _model->resetScorepad();
    return;
  }
}

// perform the action for the APP_STATE_SETTING_TYPE_OF_MATCH
void YscoreController::performActionSettingTypeOfMatch()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_BRIGHTNESS);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_STARTING);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    return;
  }
}

// perform the action for the APP_STATE_SETTING_BRIGHTNESS
void YscoreController::performActionSettingBrightness()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_LANGUAGE);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_TYPE_OF_MATCH);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    return;
  }
}

// perform the action for the APP_STATE_SETTING_LANGUAGE
void YscoreController::performActionSettingLanguage()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_HANDEDNESS);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_BRIGHTNESS);
    return;
  }

  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    return;
  }
}

// perform the action for the App_Stats_setting_language
void YscoreController::performActionSettingHandedness()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_ABOUT);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_LANGUAGE);
    return;
  }

  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    return;
  }
}

// perform the action for the App_setting_about
void YscoreController::performActionAbout()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_ACK);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_SETTING_HANDEDNESS);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    return;
  }
}

// perform the action for the App_setting_about
void YscoreController::performActionAck()
{
  if (_buttonStateBack == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_UPDATE);
    return;
  }

  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_ABOUT);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    return;
  }
}

// perform the action for the App_setting_update
void YscoreController::performActionUpdate()
{
  if (_buttonStateMode == BUT_STATE_PRESSED)
  {
    _model->setAppState(APP_STATE_ACK);
    return;
  }

  // us or them restart
  if (_buttonStateUs == BUT_STATE_PRESSED || _buttonStateThem == BUT_STATE_PRESSED)
  {
    return;
  }
}
