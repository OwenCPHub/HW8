CC = gcc
CXX = g++
CFLAGS = -Wall -std=c99
CXXFLAGS = -Wall

c: matrix.c main.c matrixc.h
	$(CC) $(CFLAGS) matrix.c main.c -o matrixc

c++: matrix.cpp
	$(CXX) $(CXXFLAGS) matrix.cpp -o matrixcpp

clean:
	rm -f *.o
	rm -f matrixc matrixcpp
	rm -f *~

run_c++:
	./matrixcpp

run_c:
	./matrixc