#!/bin/bash

g++ -c AnalogIn.cpp -o AnalogIn.o
g++ -c test_analog.cpp -o test_analog.o
g++ AnalogIn.o test_analog.o -o test_analog

echo "Build complete. Run using: ./test_analog"

