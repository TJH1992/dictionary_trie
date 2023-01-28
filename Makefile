# Terrance Hutchinson
# RedID: 822021623
# CS 480
# Professor Ben Shen
# Created by Terrance Hutchinson on 1/19/23.

# CXX Make variable for compiler
CXX=g++
# -std=c++11  C/C++ variant to use, e.g. C++ 2011
# -Wall       show the necessary warning files
# -g3         include information for symbolic debugger e.g. gdb
CXXFLAGS=-std=c++11 -Wall -g3 -c

# object files
OBJS = main.o dictionary.o countprefix.o

# Program name
PROGRAM = countprefix

$(PROGRAM) : $(OBJS) $(VOCABULARY_FILE) $(TEST_FILE)
	$(CXX) -o $(PROGRAM) $^ $(VOCABULARY_FILE) $(TEST_FILE) > output.txt

dictionary.o : dictionary.h dictionary.cpp
	$(CXX) $(CXXFLAGS) dictionary.cpp

countprefix.o : dictionary.h countprefix.cpp
	$(CXX) $(CXXFLAGS) countprefix.cpp

clean :
	rm -f *.o $(PROGRAM)