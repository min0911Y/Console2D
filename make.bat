@echo off
del *.o
del *.exe
g++ -c CONSOLE2D.cpp
g++ main.cpp CONSOLE2D.o
a


