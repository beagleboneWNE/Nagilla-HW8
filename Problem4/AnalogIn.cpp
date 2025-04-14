#include "AnalogIn.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

AnalogIn::AnalogIn() {
    this->number = 0;
}

AnalogIn::AnalogIn(unsigned int n) {
    this->number = n;
}

void AnalogIn::setNumber(unsigned int n) {
    this->number = n;
}

int AnalogIn::readAdcSample() {
    stringstream ss;
    ss << ADC_PATH << number << "_raw";
    ifstream fs;
    fs.open(ss.str().c_str());
    int value;
    fs >> value;
    fs.close();
    return value;
}

AnalogIn::~AnalogIn() {
    // no cleanup needed
}

