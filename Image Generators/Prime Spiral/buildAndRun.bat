g++ -I ..\..\Libraries\ -c PrimeSpiralDriver.cpp -lquadmath
g++ -lquadmath -Wall -std=c++11 -fexceptions -std=gnu++17 -g -fext-numeric-literals -o PrimeSpiralGenerator.exe PrimeSpiralDriver.o -lquadmath
PrimeSpiralGenerator.exe
pause
