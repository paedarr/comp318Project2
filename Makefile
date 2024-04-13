CXX = g++
CXXFLAGS = -std=c++11

# Default executable name
EXEC = main

# Target to build the executable
$(EXEC): main.o AVLTrees.o
	$(CXX) $(CXXFLAGS) -o $(EXEC) main.o AVLTrees.o

# Target to compile main.cpp
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Target to compile AVLTrees.cpp
AVLTrees.o: AVLTrees.cpp
	$(CXX) $(CXXFLAGS) -c AVLTrees.cpp

# Target to clean object files and executable
clean:
	rm -f *.o $(EXEC)
