#!/bin/bash

g++ -c derek_LED.cpp -o derek_LED.o
g++ -c myApp.cpp -o myApp.o
g++ derek_LED.o myApp.o -o myApp

echo "Build complete. Run using: ./myApp <command>"

