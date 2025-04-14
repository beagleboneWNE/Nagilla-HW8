/**
 * @file test_all_App.cpp
 * @brief Controls LEDs, reads ADC value, and uses GPIO input/output on BeagleBone.
 * 
 * - Turns on LEDs 1 and 3
 * - Flashes LED 2
 * - Reads and prints temperature ADC value
 * - Checks button on P8_16 (GPIO46)
 * - If pressed, turns on external LED on P9_12 (GPIO60)
 * 
 * Usage: ./test_all_App
 */

#include "derek_LED.h"
#include "AnalogIn.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    // Step a: Turn on user LEDs 1 and 3
    LED led1(1), led3(3);
    led1.turnOn();
    led3.turnOn();

    // Step b: Flash user LED 2
    LED led2(2);
    led2.flash("100");

    // Step c: Read temperature sensor via AIN0
    AnalogIn temp(0);
    int tempValue = temp.readAdcSample();
    cout << "Temperature Sensor ADC Value: " << tempValue << endl;

    // Step d: Read button value on P8_16 (GPIO46)
    ofstream exportGPIO("/sys/class/gpio/export");
    exportGPIO << "46";
    exportGPIO << "60"; // P9_12 LED pin
    exportGPIO.close();

    usleep(100000); // wait for sysfs to register

    ofstream dir46("/sys/class/gpio/gpio46/direction");
    dir46 << "in";
    dir46.close();

    ofstream dir60("/sys/class/gpio/gpio60/direction");
    dir60 << "out";
    dir60.close();

    ifstream button("/sys/class/gpio/gpio46/value");
    string buttonState;
    button >> buttonState;
    button.close();

    cout << "Button (GPIO46) state: " << buttonState << endl;

    // Step e: If button was pushed, turn on LED on P9_12
    if (buttonState == "1") {
        ofstream ledOut("/sys/class/gpio/gpio60/value");
        ledOut << "1";
        ledOut.close();
        cout << "Button pressed! LED on P9_12 turned ON." << endl;
    }

    return 0;
}

