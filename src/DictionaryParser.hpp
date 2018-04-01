/****************************************
 * Dictionary Reader Class Header File *
*****************************************/

#ifndef DICTIONARY_PARSER_HPP
#define DICTIONARY_PARSER_HPP

#include <string>
#include <unordered_map>


class DictionaryParser
{
private:
    std::unordered_map<std::string, int> validWords;
public:
    void parseTextFile(std::string); // parse text file
    std::unordered_map<std::string, int> getValidWords(); // returns valid words read from text file as a hash map
};

#endif
