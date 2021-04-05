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

#include "YscoreModel.h"
#include "YscoreResourceProvider.h"

/*
  Constructor
*/
// YscoreResourceProvider::YscoreResourceProvider()
// {
// }

// sets the model to be used to retrieve the values
// to be shown in the view
// void YscoreView::setModel(YscoreModel *model)
// {
//   _model = model;
// }

// get the copyright message
const char *YscoreResourceProvider::getLblCopyright(uint8_t local)
{
  return LBL_COPYRIGHT;
}

// get the play message
const char *YscoreResourceProvider::getLblPlay(uint8_t local)
{
  return LBL_PLAY[local];
}

// get the settings message
const char *YscoreResourceProvider::getLblSettings(uint8_t local)
{
  return LBL_SETTINGS[local];
}

// get the FindUsAt message
const char *YscoreResourceProvider::getLblFindUsAt(uint8_t local)
{
  return LBL_FIND_US_AT[local];
}

// get the Restart message
const char *YscoreResourceProvider::getLblRestart(uint8_t local)
{
  return LBL_RESTART[local];
}

const char *YscoreResourceProvider::getLblPlayer(uint8_t local, uint8_t typeOfMatch, uint8_t winner)
{
  if (typeOfMatch == TYPE_OF_MATCH_DOUBLES)
  {
    return LBL_PLAYER_DOUBLES[local][winner];
  }

  return LBL_PLAYER_SINGLES[local][winner];
}

// get the Playing Title
const char *YscoreResourceProvider::getTitlePlaying(uint8_t local)
{
  return LBL_TITLE_PLAYING[local];
}

// get the Winning Title
const char *YscoreResourceProvider::getTitleWinning(uint8_t local)
{
  return LBL_TITLE_WINNING[local];
}

// get the Match score Title
const char *YscoreResourceProvider::getTitleMatchScore(uint8_t local)
{
  return LBL_TITLE_MATCH_SCORE[local];
}

// get the Match time Title
const char *YscoreResourceProvider::getTitleMatchTime(uint8_t local)
{
  return LBL_TITLE_MATCH_TIME[local];
}

// get the Abount Title
const char *YscoreResourceProvider::getTitleAbout(uint8_t local)
{
  return LBL_TITLE_ABOUT[local];
}

// get the Acknowledgement Title
const char *YscoreResourceProvider::getTitleAcknowledgement(uint8_t local)
{
  return LBL_TITLE_ACKNOWLEDGEMENT[local];
}

// get the Update Title
const char *YscoreResourceProvider::getTitleUpdate(uint8_t local)
{
  return LBL_TITLE_UPDATE[local];
}

// get the WhoServes Title
const char *YscoreResourceProvider::getTitleWhoServes(uint8_t local)
{
  return LBL_TITLE_WHO_SERVES[local];
}

// get the selectionListWhoServes
const tSelectionList YscoreResourceProvider::getSelectionListWhoServes(uint8_t local, uint8_t typeOfMatch)
{
  if (typeOfMatch == TYPE_OF_MATCH_DOUBLES)
  {
    tSelectionList result = {3, SETTING_WHO_SERVES_DOUBLES[local]};
    return result;
  }

  tSelectionList result = {3, SETTING_WHO_SERVES_SINGLES[local]};
  return result;
}

// get the TypeOfMatch Title
const char *YscoreResourceProvider::getTitleTypeOfMatch(uint8_t local)
{
  return LBL_TITLE_TYPE_OF_MATCH[local];
}

// get the selectionListTypeOfMatch
const tSelectionList YscoreResourceProvider::getSelectionListTypeOfMatch(uint8_t local)
{
  tSelectionList result = {2, SETTING_TYPE_OF_MATCH[local]};
  return result;
}

// get the Brightness Title
const char *YscoreResourceProvider::getTitleBrightness(uint8_t local)
{
  return LBL_TITLE_BRIGHTNESS[local];
}

// get the selectionListBrightness
const tSelectionList YscoreResourceProvider::getSelectionListBrightness(uint8_t local)
{
  tSelectionList result = {5,
                           SETTING_BRIGHTNESS[local]};
  return result;
}

// get the Local Title
const char *YscoreResourceProvider::getTitleLocal(uint8_t local)
{
  return LBL_TITLE_LOCAL[local];
}

// get the selectionListLocal
const tSelectionList YscoreResourceProvider::getSelectionListLocal(uint8_t local)
{
  tSelectionList result = {4, SETTING_LOCAL};
  return result;
}

// get the Handedness Title
const char *YscoreResourceProvider::getTitleHandedness(uint8_t local)
{
  return LBL_TITLE_HANDEDNESS[local];
}

// get the selectionListHandedness
const tSelectionList YscoreResourceProvider::getSelectionListHandedness(uint8_t local)
{
  tSelectionList result = {2, SETTING_HANDEDNESS[local]};
  return result;
}

/////////////////////////
// Images
/////////////////////////

// get the image for the direction of serve
// who US THEM
// Side 0 right 1 left
const tImage *YscoreResourceProvider::getImgServe(uint8_t who, uint8_t side)
{
  return IMG_SERVE[who][side];
}

// get the 4 images for the players
// Type of game
// Position
// images are;
// 0 1
// 2 3
const tImage **YscoreResourceProvider::getImgPlayers(uint8_t typeOfMatch, uint8_t position)
{
  if (typeOfMatch == TYPE_OF_MATCH_SINGLES)
  {
    return IMG_PLAYER_SINGLES[position];
  }

  return IMG_PLAYER_DOUBLES[position];
}

// get the 4 images for the stats players
// Type of game
// winner
// images are;
// 0 1
// 2 3
const tImage **YscoreResourceProvider::getImgStatsPlayers(uint8_t typeOfMatch, uint8_t winner)
{
  return IMG_STATS_PLAYER_DOUBLES[winner];
}

// get the 2 images for the winner players
// Type of game
// winner
// images are;
// 0 1
const tImage **YscoreResourceProvider::getImgWiningPlayers(uint8_t typeOfMatch, uint8_t winner)
{
  return IMG_WINNING_PLAYER_DOUBLES[winner];
}
