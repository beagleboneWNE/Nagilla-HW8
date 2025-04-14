/**
 * @file test_analog.cpp
 * @brief Test application for AnalogIn class.
 * 
 * This script creates an AnalogIn object for AIN0 and reads its ADC value.
 * Usage: ./test_analog
 */

#include "AnalogIn.h"
#include <iostream>
using namespace std;

int main() {
    AnalogIn AIN(0); // AIN0 is connected to pin P9_39
    cout << "Analog pin number: " << AIN.getNumber() << endl;
    cout << "ADC Sample Value: " << AIN.readAdcSample() << endl;
    return 0;
}

