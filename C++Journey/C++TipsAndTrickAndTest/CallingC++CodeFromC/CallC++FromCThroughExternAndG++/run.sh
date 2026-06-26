#!/bin/sh

# -I flage stands for include directory
# use ./CppApp/cppmain.cpp  to bind cppmain.cpp to main.c
g++ -std=c++23 -I ./CppApp main.c ./CppApp/cppmain.cpp -o main