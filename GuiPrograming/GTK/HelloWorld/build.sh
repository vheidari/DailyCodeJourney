#!/usr/bin/bash

echo "Start Building Gtkmm Project ..."


g++ -std=c++23 main.cpp -o main.out `pkg-config --cflags --libs gtkmm-4.0`
