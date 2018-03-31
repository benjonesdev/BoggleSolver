all: Boggle

Boggle: bin/main.o
	g++ -o bin/Boggle bin/main.o

bin/main.o: src/main.cpp
	g++ -g -Wall -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

clean:
	rm -f bin/*