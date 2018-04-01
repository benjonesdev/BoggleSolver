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
    string textFile = "dictionary.txt";
    d.parseTextFile(textFile);
    std::unordered_map<string, int> validWords;
    validWords = d.getValidWords();

    // // Iterate and print keys and values of unordered_map
    // for (const auto &n : validWords)
    // {
    //     std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    // }
    
	Board b;
	b.randomBoard();
	b.solveBoard();
	b.printBoard();
	return 0;
}
