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

#ifndef IYScoreView_h
#define IYScoreView_h

// Interface to be implemented by Class provides the YscoreView functionality.
class IYscoreView
{
public:
  // method updates the view according to the current model
  virtual void updateView() = 0;
  // method updates the view of the battery
  virtual void updateViewBattery() = 0;
};

#endif
