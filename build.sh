#!/bin/sh

g++ -c pingpong.cpp
g++ pingpong.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

