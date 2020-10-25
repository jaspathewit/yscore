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

#include <TinyScreen.h>
#include "TinyScreenBattery.h"

/*
  Constructor
*/
TinyScreenBattery::TinyScreenBattery()
{
    this->_init();
}

/*
  Initialzie the battery
*/
void TinyScreenBattery::_init()
{
    this->_tinyScreenVarient = getRevision();
}

// determins the refvison of the TinyScreen
// by detectiny if A0 is floating
uint8_t TinyScreenBattery::getRevision()
{
    uint32_t max = 0;
    uint32_t min = 0;
    for (uint8_t i = 0; i < 20; i++)
    {
        uint32_t reading = analogRead(A4);
        if (reading > max)
        {
            max = reading;
        }

        if (reading < min)
        {
            max = reading;
        }
    }
    uint32_t delta = max - min;
    if (delta < REVISION_THRESHHOLD)
    {
        return TINYSCREEN_REV_4;
    }

    // assume its a Rev3 (code for the battery will work)
    return TINYSCREEN_REV_3;
}

// Battery
// This function gets the battery VCC internally, you can checkout this link
// if you want to know more about how:
// http://atmel.force.com/support/articles/en_US/FAQ/ADC-example
float TinyScreenBattery::getVCC()
{
    SYSCTRL->VREF.reg |= SYSCTRL_VREF_BGOUTEN;
    while (ADC->STATUS.bit.SYNCBUSY == 1)
        ;
    ADC->SAMPCTRL.bit.SAMPLEN = 0x1;
    while (ADC->STATUS.bit.SYNCBUSY == 1)
        ;
    ADC->INPUTCTRL.bit.MUXPOS = 0x19; // Internal bandgap input
    while (ADC->STATUS.bit.SYNCBUSY == 1)
        ;
    ADC->CTRLA.bit.ENABLE = 0x01; // Enable ADC
    while (ADC->STATUS.bit.SYNCBUSY == 1)
        ;
    ADC->SWTRIG.bit.START = 1;   // Start conversion
    ADC->INTFLAG.bit.RESRDY = 1; // Clear the Data Ready flag
    while (ADC->STATUS.bit.SYNCBUSY == 1)
        ;
    ADC->SWTRIG.bit.START = 1; // Start the conversion again to throw out first value
    while (ADC->INTFLAG.bit.RESRDY == 0)
        ; // Waiting for conversion to complete
    uint32_t valueRead = ADC->RESULT.reg;
    while (ADC->STATUS.bit.SYNCBUSY == 1)
        ;
    ADC->CTRLA.bit.ENABLE = 0x00; // Disable ADC
    while (ADC->STATUS.bit.SYNCBUSY == 1)
        ;
    SYSCTRL->VREF.reg &= ~SYSCTRL_VREF_BGOUTEN;

    float vcc = (1.1 * 1023.0) / valueRead;
    return vcc;
}

// Get the battery voltage
float TinyScreenBattery::getVoltage(void)
{
    // read the value and discard
    float battVoltageReading = analogRead(VBATT_PIN);
    battVoltageReading = analogRead(VBATT_PIN);
    float battVoltage = this->getVCC() * battVoltageReading / 1023.0 / 0.5;

    return battVoltage;
}

// Get the battery voltage as a scaled value
// between 0 to 10
uint8_t TinyScreenBattery::getState()
{
    uint8_t result = 0;
    if (TINYSCREEN_REV_3 == this->_tinyScreenVarient)
    {
        result = this->getStateRev3();
    }

    if (TINYSCREEN_REV_4 == this->_tinyScreenVarient)
    {
        result = this->getStateRev4();
    }

    return result;
}

// Get the battery voltage as a scaled value
// between 0 to 10 for revision 3 tinyscreens
uint8_t TinyScreenBattery::getStateRev3()
{
    uint8_t result = 10;
    float vcc = this->getVCC();
    if (vcc >= VCC_UPPER)
    {
        // we are not flat
        this->_isFlat = false;
        result = 10;
    }

    if (this->_isFlat || (this->getVCC() < VCC_LOWER))
    {
        // make sure that we know that we are flat
        // and that we will stay flat until the Vcc is
        // above VCC_UPPER
        this->_isFlat = true;
        result = BATT_STATUS_02;
    }

    return result;
}

// Get the battery voltage as a scaled value
// between 0 to 10 for revision 4 tinyscreens
uint8_t TinyScreenBattery::getStateRev4()
{
    // get the current value of the battery
    uint32_t reading = analogRead(VBATT_PIN);
    reading = analogRead(VBATT_PIN);

    // check that the new reading differs from the old
    // by at least the threashhold.
    if (abs(this->_currentVoltage - reading) < VBATT_THRESHOLD)
    {
        return this->_currentState;
    }

    // remember the new _currentVoltage
    this->_currentVoltage = reading;

    uint32_t level = VBATT_UPPER;
    // check for full battery
    if (this->_currentVoltage > level)
    {
        this->_currentState = BATT_STATUS_10;
        return this->_currentState;
    }

    level -= VBATT_DIVISOR;
    if (this->_currentVoltage > level)
    {
        this->_currentState = BATT_STATUS_08;
        return this->_currentState;
    }

    level -= VBATT_DIVISOR;
    if (this->_currentVoltage > level)
    {
        this->_currentState = BATT_STATUS_06;
        return this->_currentState;
    }

    level -= VBATT_DIVISOR;
    if (this->_currentVoltage > level)
    {
        this->_currentState = BATT_STATUS_04;
        return this->_currentState;
    }

    this->_currentState = BATT_STATUS_02;
    return this->_currentState;
}
