# Compiler
CXX = clang++
# Compiler flags
CXXFLAGS = -std=c++14
# Include directories
INC = -Iinclude

# Targets and dependencies
default: main

# Target rules
main: main.o
	$(CXX) $(CXXFLAGS) $(INC) -o main main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c main.cpp

clean:
	rm -f main main.o
