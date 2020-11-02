/*********************************************************************
iScore
*********************************************************************/

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

// #include <Wire.h>
// #include <SPI.h>
#include <stdlib.h>

#include "yScore.h"
#include "YscoreModel.h"
#include "YscoreView.h"
#include "YscoreController.h"
#include "TinyScreenExt.h"

//Get the display to be used
//Library must be passed the board type
//TinyScreenDefault for TinyScreen shields
//TinyScreenAlternate for alternate address TinyScreen shields
//TinyScreenPlus for TinyScreen+
TinyScreenExt display = TinyScreenExt(TinyScreenPlus);
YscoreView view = YscoreView(display);
YscoreModel model = YscoreModel(display);
YscoreController controller = YscoreController(display);

//////////////////////////
// Setup the initial state
//////////////////////////

void setup()
{
  // setup the display
  setupDisplay();
  // wire up the model view and controler
  // model can notify the view
  model.setView(&view);
  // view can read the model
  view.setModel(&model);
  // controller can modify the model
  controller.setModel(&model);

  // initilise the Controller
  controller.initilise();

  // starting state
  // appState = APP_STATE_STARTING;

  // setupButtons();
  // resetButtonState();
  // resetScorepad();
}

void setupDisplay()
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
  // drawStartScreen();
}

////////////////////////////////////////////////
// Main evaluation loop
// keep this short to improve the responsiveness
////////////////////////////////////////////////
void loop()
{
  // perform the action
  controller.performAction();

  // update the battery state of the model
  model.updateBatteryState();

  delay(50);
}
