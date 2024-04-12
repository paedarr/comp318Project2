CXX = g++
CXXFLAGS = -std=c++11

main: main.o AVLTrees.o
	$(CXX) $(CXXFLAGS) -o main main.o AVLTrees.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

AVLTrees.o: AVLTrees.cpp
	$(CXX) $(CXXFLAGS) -c AVLTrees.cpp

clean:
	rm -f *.o main