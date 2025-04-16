# HW8
This is a repository for CMSC 313 HW8
AUTHORING: Owen Pennington
PURPOSE OF SOFTWARE: an implementation of a matrix library in both C and C++
FILES: 
    matrix.cpp: C++ code with a simple class implementation for a matrix library includes member functions for setting variables and getting variables aswell as performing operations between matrices
    matrixc.h: header file for c code declares struct Matrix with integers data, rows, and columns. data is a 1D pointer array. also declares many functions used to perform operations on Matrix
    matrix.c: implementations for each operational function declared in matrixc.h
    main.c: file includes main function for matrixc.h and matrix.c that runs a test program and prints result to compare desired results for correctness
    makefile: this makefile has various commands to compile and run the files in the folder
    tester.c: a tester file to thouroughly test function testing both valid and invalid situations
BUILD INSTRUCTIONS: you can just use the makefile but if you really must know 
    C : gcc -Wall -std=c99 -o run_c main.c matrix.c
    C tester: gcc -Wall -std=c99 tester.c matrix.c -o matrix_test
    C++ : G++ -Wall matrix.cpp -o matrixpp
TESTING METHODOLOGY: 
    I made a full tester file for the C functions that can be run through the makefile
