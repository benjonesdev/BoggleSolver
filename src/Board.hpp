/****************************************
 * Board Class Header File *
*****************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Board {
public:
	Board();
	~Board();
	void randomBoard();
	void printBoard();
private:
	// constants
	const int MAX_ROWS;
	const int MAX_COLS;
	// variables
	std::vector<std::vector<char>> board;
	std::vector<std::vector<bool>> visited;
	std::vector<std::string> validWords;
	std::unordered_map<std::string, int> dictionary;
	// functions
	char squareGen(int die, int face);
};

#endif