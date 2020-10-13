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

    this->_tinyScreenVarient = TINYSCREEN_REV_3;

    // Set the pin to digital output, set it to 1, set it to ADC input, capture value.
    // Set the pin to digital output, set it to 0, set it to ADC input, capture value.
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
    const int VBATTpin = A4;

    // read the value and discard
    float battVoltageReading = analogRead(VBATTpin);
    battVoltageReading = analogRead(VBATTpin);
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
        result = 2;
    }

    return result;
}

// Get the battery voltage as a scaled value
// between 0 to 10 for revision 4 tinyscreens
uint8_t TinyScreenBattery::getStateRev4()
{
    uint8_t result = 10;
    return result;
}
