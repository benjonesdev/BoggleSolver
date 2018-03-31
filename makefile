all: Boggle

Boggle: main.o
	g++ main.cpp -o Boggle

clean:
	rm *.o