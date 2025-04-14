#!/bin/bash

echo "Compiling all files..."

g++ -c derek_LED.cpp -o derek_LED.o
g++ -c AnalogIn.cpp -o AnalogIn.o
g++ -c test_all_App.cpp -o test_all_App.o

g++ derek_LED.o AnalogIn.o test_all_App.o -o test_all_App

echo "Build complete. Run using: ./test_all_App"

