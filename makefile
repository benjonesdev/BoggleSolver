all: Boggle

Boggle: bin/main.o bin/Board.o
	g++ -o bin/Boggle bin/main.o bin/Board.o

bin/main.o: src/main.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

bin/Board.o: src/Board.hpp src/Board.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/Board.o src/Board.cpp

clean:
	rm -f bin/*