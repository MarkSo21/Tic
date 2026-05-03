CXX = g++
CXXFLAGS = -Wall -std=c++11

all: tictactoe

tictactoe: main.o tictactoe.o
	$(CXX) $(CXXFLAGS) -o tictactoe main.o tictactoe.o

main.o: main.cpp tictactoe.h
	$(CXX) $(CXXFLAGS) -c main.cpp

tictactoe.o: tictactoe.cpp tictactoe.h
	$(CXX) $(CXXFLAGS) -c tictactoe.cpp

clean:
	rm -f *.o tictactoe highscore.txt