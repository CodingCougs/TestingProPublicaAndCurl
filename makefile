# Makefile for the sample API call program
# It is necessary to link the curl library through CLI, so its a lot simpler
# to just use this as a template in the future

CXX = g++
CXXFLAGS = -Wall -ggdb -std=c++11

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o -lcurl

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o

a.exe: main.o
	$(CXX) $(CXXFLAGS) -o a.exe main.o