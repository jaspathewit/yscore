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

// The number of times that the actionPerfocmed is called before
// the device goes to sleep (10 minutes)
#define SLEEP_THRESHHOLD 6000

#define BUTTONS_STATE_NO_CHANGE 0
#define BUTTONS_STATE_CHANGED 1

// Class provides the controler functionality.
class YscoreController
{
public:
  YscoreController(TinyScreenExt &display);

  // sets the model from which values can be
  // retrieved for the view
  void setModel(YscoreModel *model);

  // initilise the controller
  void initilise();

  // Perform the action
  void performAction();

private:
  // initilise the buttons
  void initButtons();
  // update the button states
  uint8_t updateButtonStates();
  // update the button states
  void updateButtonStatesSequence();
  // print the button states for debugging
  void printButtonStates();
  // print an individual button state
  void printButtonState(uint8_t buttonState);
  // update the button state for a single button
  uint8_t readButtonState(bool prevState, bool currState);
  // function resets all button states to BUT_STATE_UNPRESSED
  void resetButtonState();
  // perform the default action for all app states
  void performActionDefault();

  // deform the action for the App_Starting state
  // must set modelChanged if the model is changed by this action
  void performActionStarting();
  // peform the action for the app setting serve state
  void performActionSettingServe();
  // perform the action for the app playing state
  void performActionPlaying();
  // return true if neither the us and them buttons were pressed or
  // both were pressed
  bool checkDoNothing();

  void performActionWinning();
  void performActionStats();
  void performActionStatsTime();
  void performActionPausing();
  void performActionPausingTime();
  void performActionSettingTypeOfMatch();
  void performActionSettingBrightness();
  void performActionSettingLanguage();
  void performActionSettingHandedness();
  void performActionAbout();
  void performActionAck();
  void performActionUpdate();

  TinyScreenExt &_display;
  YscoreModel *_model = NULL;

  // the definition of the buttons
  uint8_t _TSButtonMode;
  uint8_t _TSButtonBack;
  uint8_t _TSButtonThem;
  uint8_t _TSButtonUs;

  // the button states
  uint8_t _buttonStateMode = BUT_STATE_UNPRESSED;
  uint8_t _buttonStateBack = BUT_STATE_UNPRESSED;
  uint8_t _buttonStateUs = BUT_STATE_UNPRESSED;
  uint8_t _buttonStateThem = BUT_STATE_UNPRESSED;

  // define the button previous states
  uint8_t _prevStateMode = false;
  uint8_t _prevStateBack = false;
  uint8_t _prevStateThem = false;
  uint8_t _prevStateUs = false;

  uint16_t _performActionCount = 0;
};

#endif