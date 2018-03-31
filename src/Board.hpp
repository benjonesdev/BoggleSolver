#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

class Board {
public:
	Board();
	~Board();
	void randomBoard();
	void printBoard(std::vector<char>);
private:
	std::vector<std::vector<char>> board;
	std::vector<std::vector<bool>> visited;
	std::vector<std::string> validWords;
	std::unordered_map<std::string, int> dictionary;
}


#endif