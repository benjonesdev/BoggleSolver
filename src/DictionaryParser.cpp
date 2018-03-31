/************************************************
 * Dictionary Reader Class Implementation File *
*************************************************/

#include <string>
#include <fstream>
#include "DictionaryParser.hpp"

// Constructor
void DictionaryParser::parseTextFile(std::string textFile) {
    std::ifstream dictFile;
    std::string currentWord;
    dictFile.open(textFile);

    while (dictFile >> currentWord) // iterate through text file
    {
        // basic score of length of word - 1
        int score = currentWord.length() - 1;
        validWords[currentWord] = score;
    }

}

// Getter
std::unordered_map<std::string, int> DictionaryParser::getValidWords() {
    return validWords;
}