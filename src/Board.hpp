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
	Board(std::unordered_map<std::string, int> dict);
	~Board();
	void printBoard();
	void printValidWords();
	void randomBoard();
	void solveBoard();
private:
	// constants
	const int MAX_ROWS;
	const int MAX_COLS;
	// variables
	std::vector<std::vector<char> > board;
	std::vector<std::vector<bool> > visited;
	std::unordered_map<std::string, int> validWords;
	std::unordered_map<std::string, int> dictionary;
	// functions
	void dfs(int row, int col, std::string str);
	bool outOfBounds(int row, int col);
	char squareGen(int die, int face);
};

#endif
