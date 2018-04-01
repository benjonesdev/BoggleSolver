#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Board.hpp"
#include "DictionaryParser.hpp"

using std::cout;
using std::string;

int main() {
    DictionaryParser d;
    d.parseTextFile("../dictionary.txt");
    std::unordered_map<string, int> validWords;
    validWords = d.getValidWords();
    cout << validWords["cool"] << std::endl;
	Board b;
	b.randomBoard();
	b.solveBoard();
	b.printBoard();
	return 0;
}
