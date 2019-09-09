g++ -I ..\..\Libraries\ -c RTEngineCore.cpp -std=c++11
g++ -I ..\..\Libraries\ -c RTEngineBackend.cpp -std=c++11
g++ -lquadmath -Wall -std=c++11 -fexceptions -std=gnu++17 -g -fext-numeric-literals -o RusRaytracingEngine.exe RTEngineCore.o RTEngineBackend.o
CLS
RusRaytracingEngine.exe 
pause