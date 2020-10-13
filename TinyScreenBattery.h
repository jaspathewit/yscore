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

#ifndef TinyScreenBattery_h
#define TinyScreenBattery_h

#define TINYSCREEN_REV_UNKNOWN 0
#define TINYSCREEN_REV_3 1
#define TINYSCREEN_REV_4 2

#define VCC_UPPER 3.15
#define VCC_LOWER 3.1

// Class provides an abstraction to the TinyScreen Battery.
class TinyScreenBattery
{
public:
     TinyScreenBattery(void);

     // get the state of the battery scaled between 10 and 1
     uint8_t getState();
     float getVCC();

private:
     void _init();

     // get the scaled voltage for the revision 3 or 4 Tinyscreen
     uint8_t getStateRev3();
     uint8_t getStateRev4();

     // get the current battery voltage
     float getVoltage();
     // get the current reference voltage
     // float getVCC();
     uint8_t _tinyScreenVarient = TINYSCREEN_REV_UNKNOWN;
     uint8_t _isFlat;
};

#endif