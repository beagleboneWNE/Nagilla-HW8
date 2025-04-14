/**
 * @file myApp.cpp
 * @brief Controls BeagleBone onboard LEDs using command-line arguments.
 * 
 * This script allows you to turn all four user LEDs on/off, flash them, or check status.
 * Usage: ./myApp <command>
 * Command options: on, off, flash, status
 * Example: ./myApp flash
 */

#include "derek_LED.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: makeLEDs <command>" << endl;
        cout << "  command is one of: on, off, flash, status" << endl;
        cout << "  e.g. makeLEDs flash" << endl;
        return 2;
    }

    cout << "Starting the makeLEDs program" << endl;
    string cmd(argv[1]);
    LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };

    for (int i = 0; i < 4; i++) {
        if (cmd == "on") leds[i].turnOn();
        else if (cmd == "off") leds[i].turnOff();
        else if (cmd == "flash") leds[i].flash("100");
        else if (cmd == "status") leds[i].outputState();
        else cout << "Invalid command!" << endl;
    }

    cout << "Finished the makeLEDs program" << endl;
    return 0;
}

