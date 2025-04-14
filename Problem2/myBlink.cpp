/**
 * @file myBlink.cpp
 * @brief Blinks a specified BeagleBone USR LED a given number of times.
 * 
 * This script allows you to blink a specific onboard LED using command-line arguments.
 * Usage: ./myBlink blink <LED_NUMBER> <NUMBER_OF_BLINKS>
 * Example: ./myBlink blink 2 5  // Blinks USR2 LED 5 times
 */

#include "derek_LED.h"
#include <cstdlib>  // for atoi

int main(int argc, char* argv[]) {
    if (argc != 4 || string(argv[1]) != "blink") {
        cout << "Usage: ./myBlink blink <LED_NUMBER> <NUMBER_OF_BLINKS>" << endl;
        cout << "Example: ./myBlink blink 2 5" << endl;
        return 1;
    }

    int ledNum = atoi(argv[2]);     // Convert LED number
    int blinkCount = atoi(argv[3]); // Convert blink count

    // Validate input
    if (ledNum < 0 || ledNum > 3 || blinkCount < 1) {
        cout << "Invalid input: LED number must be 0-3 and blink count must be > 0." << endl;
        return 2;
    }

    LED led(ledNum);           // Create LED object
    led.blink(blinkCount);     // Blink the LED

    return 0;
}

