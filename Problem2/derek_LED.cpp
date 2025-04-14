#include "derek_LED.h"
#include <unistd.h> // for sleep()

LED::LED(int number) {
    this->number = number;
    ostringstream s;
    s << LED_PATH << number;
    path = string(s.str());
}

void LED::writeLED(string filename, string value) {
    ofstream fs;
    fs.open((path + filename).c_str());
    fs << value;
    fs.close();
}

void LED::removeTrigger() {
    writeLED("/trigger", "none");
}

void LED::turnOn() {
    cout << "Turning LED" << number << " on." << endl;
    removeTrigger();
    writeLED("/brightness", "1");
}

void LED::turnOff() {
    cout << "Turning LED" << number << " off." << endl;
    removeTrigger();
    writeLED("/brightness", "0");
}

void LED::flash(string delayms) {
    cout << "Making LED" << number << " flash." << endl;
    writeLED("/trigger", "timer");
    writeLED("/delay_on", delayms);
    writeLED("/delay_off", delayms);
}

void LED::outputState() {
    ifstream fs;
    fs.open((path + "/trigger").c_str());
    string line;
    while (getline(fs, line)) cout << line << endl;
    fs.close();
}

void LED::blink(int num) {
    for (int i = 0; i < num; i++) {
        cout << "Blink " << (i + 1) << ": LED" << number << " ON" << endl;
        turnOn();
        sleep(1);

        cout << "Blink " << (i + 1) << ": LED" << number << " OFF" << endl;
        turnOff();
        sleep(1);
    }
}

LED::~LED() {
    cout << "destroying the LED with path: " << path << endl;
}

