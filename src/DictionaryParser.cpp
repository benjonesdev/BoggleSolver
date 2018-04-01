/************************************************
 * Dictionary Reader Class Implementation File *
*************************************************/

#include <string>
#include <fstream>
#include <iostream>
#include "DictionaryParser.hpp"

// Constructor
void DictionaryParser::parseTextFile(std::string textFile) {
    std::ifstream dictFile;
    std::string currentWord;
    dictFile.open(textFile);
    if (dictFile) { // make sure file opened
        while (dictFile >> currentWord) // iterate through text file
        {

            int score;
            if(currentWord.length() <= 2)
            {
                score = 0;
            }
            else if(currentWord.length() <= 4)
            {
                score = 1;
            }
            else if(currentWord.length() <= 5)
            {
                score = 2;
            }
            else if(currentWord.length() <= 6)
            {
                score = 3;
            }
            else if(currentWord.length() <= 7)
            {
                score = 5;
            }
            else
            {
                score = 11;
            }
            validWords[currentWord] = score;
        }
    }

    dictFile.close(); // close file

}

// Getter
std::unordered_map<std::string, int> DictionaryParser::getValidWords() {
    return validWords;
}


