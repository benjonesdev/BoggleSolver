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
       // int score = currentWord.length() - 1;
        //validWords[currentWord] = score;
        std::string newWords = getValidWords();
        if(newWords == currentWord)
        {
            if(.length() < 2)
            {
                points += 0;
            }
            else if(newWords.length() <= 4)
            {
                points += 1;
            }
            else if(newWords.length() <= 5)
            {
                points += 2;
            }
            else if(newWords.length() <= 6)
            {
                points += 3;
            }
            else if(newWords.length() <= 7)
            {
                points += 5;
            }
            else
            {
                points += 11;
            }
        }

    }

    dictFile.close(); // close file

}

// Getter
std::unordered_map<std::string, int> DictionaryParser::getValidWords() {
    return validWords;
}


