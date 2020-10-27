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

#define REVISION_THRESHHOLD 25
#define TINYSCREEN_REV_UNKNOWN 0
#define TINYSCREEN_REV_3 1
#define TINYSCREEN_REV_4 2

// the analog pin giving the value of the Battery
#define VBATT_PIN A4
#define VBATT_THRESHOLD 5
#define VBATT_UPPER 600
#define VBATT_LOWER 500
#define VBATT_DIVISOR 15

// value should give about an hours usage
// before dying completly
#define VCC_UPPER 3.25
#define VCC_LOWER 3.2

// Battery is flat
#define BATT_STATUS_10 10
#define BATT_STATUS_08 8
#define BATT_STATUS_06 6
#define BATT_STATUS_04 4
#define BATT_STATUS_02 2

// Class provides an abstraction to the TinyScreen Battery.
class TinyScreenBattery
{
public:
     TinyScreenBattery(void);

     // get the state of the battery scaled between 10 and 1
     uint8_t getState();
     float getVCC();
     // get the current battery voltage
     float getVoltage();

private:
     void _init();

     uint8_t getRevision();

     // get the scaled voltage for the revision 3 or 4 Tinyscreen
     uint8_t getStateRev3();
     uint8_t getStateRev4();

     // get the current battery voltage
     // float getVoltage();
     // get the current reference voltage
     // float getVCC();
     uint8_t _tinyScreenVarient = TINYSCREEN_REV_UNKNOWN;
     uint32_t _currentVoltage = 0;
     uint8_t _currentState;

     uint8_t _isFlat;
};

#endif