CXX      := -g++
CXXFLAGS := -g -pedantic -Wall -Wextra

all: main

main: main.cpp NAT.cpp NAT.h
	$(CXX) -o main NAT.cpp main.cpp 
clean:
	rm -rf main
