/****************************************
 * Board Class Header File *
*****************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "validation.hpp"

class Board {
public:
	Board(std::unordered_map<std::string, int> dict);
	~Board();
	void printBoard();
	void printValidWords();
	void randomBoard();
	void solveBoard();
    void foundWords();
    void onCorner(int, int);
    void EdgeMiddle(int, int);
private:
	// constants
	const int MAX_ROWS;
	const int MAX_COLS;
    
    int r;
    int c;
	// variables
	std::vector<std::vector<char> > board;
	std::vector<std::vector<bool> > visited;
    //found valid words from board
    std::vector<std::string > guessWordsCollection;
	std::unordered_map<std::string, int> validWords;
	std::unordered_map<std::string, int> dictionary;
	// functions
	void dfs(int row, int col, std::string str);
	bool outOfBounds(int row, int col);
	char squareGen(int die, int face);
};

#endif
