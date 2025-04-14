#!/bin/bash

echo "Compiling files..."

# Compile implementation and application
g++ -c derek_LED.cpp -o derek_LED.o
g++ -c myBlink.cpp -o myBlink.o

# Link the object files into an executable
g++ derek_LED.o myBlink.o -o myBlink

echo "Build complete. Run using: ./myBlink blink <LED#> <count>"

