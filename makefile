CXX = g++
CXXFLAGS = -Wall -ggdb -std=c++11

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o -lcurl

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o

# a.exe: hw04.o exceptions.o AVLTree.o
# 	$(CXX) $(CXXFLAGS) -o a.exe hw04.o exceptions.o AVLTree.o