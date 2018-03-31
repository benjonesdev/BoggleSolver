/************************************************
 * Dictionary Reader Class Implementation File *
*************************************************/

#include <iostream>
#include "Board.hpp"

Board::Board() : MAX_ROWS(4), MAX_COLS(4) {
	// init board
	for (int i = 0; i < MAX_ROWS; i++) {
		board.push_back(std::vector<char>());
		for (int j = 0; j < MAX_COLS; j++) {
			board[i].push_back('A');
		}
	}
	// init visited
	for (int i = 0; i < MAX_ROWS; i++) {
		visited.push_back(std::vector<bool>());
		for (int j = 0; j < MAX_COLS; j++) {
			visited[i].push_back(false);
		}
	}
}

Board::~Board() {
//TODO: memory leak? or is destructor unnecessary?
}

void Board::randomBoard() {
    std::vector<int> spot;
    for (int i = 0; i < MAX_ROWS * MAX_COLS; i++) {
        spot.push_back(i);
    }
    std::random_shuffle(spot.begin(), spot.end());
    for (int j = 0; j < MAX_ROWS; j++) {
    	for (int k = 0; k < MAX_COLS; k++) {
    		int face = rand() % 6;
        	board[j][k] = squareGen(spot[j+k], face);
    	}
    }
}

void Board::printBoard() {
	for (int row = 0; row < MAX_ROWS; row++) {
		for (int col = 0; col < MAX_COLS; col++) {
			if (board[row][col] == 'Q')
				std::cout << "Qu ";
			else 
				std::cout << board[row][col] << "  ";
		}
		std::cout << "\n\n";
	}
}

char Board::squareGen(int die, int face) {
    std::vector<std::string> cubes {
            "RIFOBX",
            "IFEHEY",
            "DENOWS",
            "UTOKND",
            "HMSRAO",
            "LUPETS",
            "ACITOA",
            "YLGKUE",
            "QBMJOA",
            "EHISPN",
            "VETIGN",
            "BALIYT",
            "EZAVND",
            "RALESC",
            "UWILRG",
            "PACEMD"
    };
    return cubes[die][face];
}