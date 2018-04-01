/************************************************
 * Dictionary Reader Class Implementation File *
*************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Board.hpp"
#include "DictionaryParser.hpp"

void Board::foundWords()
{
    char response;
    std::cout << "Do you wanna play boggle game?\n";
    response = validationChar();
    std::cout <<"Please select start point of a word, enter two integer numbes from 0 to 3: \n";
    r = validation(0, 3);
    c = validation(0, 3);
    std::string guessWords;
    guessWords = board[r][c];
    for(int i = 0; i < 16; i++)
    {
        onCorner(c, r);
        EdgeMiddle(c, r);
        guessWords += board[r][c];
    }
    std::cout << guessWords << std::endl;
    //are we going to compare the guessWords with hash table of valid words???
    //do we need a list of guess words?
    guessWordsCollection.push_back(guessWords);
}

Board::Board(std::unordered_map<std::string, int> dict) : MAX_ROWS(4), MAX_COLS(4) {
	// seed srand, is the right place to do this?
	srand(time(NULL));
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
	dictionary = dict;
//TODO: read dictionary txt file into dictionary var
// dictionary = DictionaryParser.GetValidWords()
}

Board::~Board() {
//TODO: memory leak? or is destructor unnecessary?
}

//////////////////////
/* PUBLIC FUNCTIONS */
//////////////////////

void Board::printBoard() {
	std::cout << "Board: \n";
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

void Board::printValidWords() {
	std::cout << "Valid Words Found:\n";
	for (auto it = validWords.begin(); it != validWords.end(); ++it) {
		std::cout << "Word: " << it->first << " Points: " << it->second << "\n";
	}
}

// Randomizes the characters on the board
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

// Calls dfs on every starting square on the board
// After returning, validWords should contain every valid word on the board
void Board::solveBoard() {
	for (int row = 0; row < MAX_ROWS; row++) {
		for (int col = 0; col < MAX_COLS; col++) {
			dfs(row, col, "");
		}
	}
}

//////////////////////
/* PRIVATE FUNCTIONS */
//////////////////////

void Board::dfs(int row, int col, std::string str) {
	// If current coords are out of bounds or already visited, return
	if (outOfBounds(row, col) || visited[row][col]) {
		return;
	}
	// Add letter of current square into string
	str += board[row][col];
	// Mark the square as visited
	visited[row][col] = true;
	
// Check if valid
	if (dictionary.find(str) != dictionary.end() && dictionary[str] > 0)	{
		validWords[str] = dictionary[str];
	}

	// Recursively move to adjacent squares +/- 1 in both directions
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j <= col + 1; j++) {
			dfs(i, j, str);
		}
	}

	// Undo the current move so the algorithm can backtrack
	str = str.substr(0, str.size() - 1);
	visited[row][col] = false;
}

bool Board::outOfBounds(int row, int col) {
	// out of bounds
	if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) {
		return true;
	}
	// in bounds
	return false;
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

void Board::onCorner(int x, int y)
{
    int nextMove;
    if(x == 0 && y == 0)
    {
        //next move can be
        nextMove = rand() % 3;
        switch (nextMove)
        {
            case 0:
                x += 1;
                break;
            case 1: y += 1;
                break;
            case 2:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 3 && y == 0)
    {
        nextMove = rand() % 3;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                y += 1;
            case 2:
                x -= 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 0 && y== 3)
    {
        nextMove = rand() % 3;
        switch(nextMove)
        {
            case 0:
                y -= 1;
                break;
            case 1:
                x += 1;
                break;
            case 2:
                y -= 1;
                x += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 3 && y == 3)
    {
        nextMove = rand() % 3;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                y -= 1;
                break;
            case 2:
                x -= 1;
                y -= 1;
                break;
            default:
                break;
        }
    }
    r = y;
    c = x;
}


//if current letter is on edge or in the middle
//next move can be
void Board::EdgeMiddle(int x, int y)
{
    int nextMove;
    if(y == 0)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x += 1;
                break;
            case 1:
                x -= 1;
                break;
            case 2:
                y += 1;
                break;
            case 3:
                x -= 1;
                y += 1;
                break;
            case 4:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 0)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x += 1;
                break;
            case 1:
                y += 1;
                break;
            case 2:
                y -= 1;
                break;
            case 3:
                x += 1;
                y -= 1;
                break;
            case 4:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if( y == 3)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                x += 1;
                break;
            case 2:
                y -= 1;
                break;
            case 3:
                x -= 1;
                y -= 1;
                break;
            case 4:
                x += 1;
                y -= 1;
                break;
            default:
                break;
        }
    }
    else if(x == 3)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                y -= 1;
                break;
            case 2:
                y += 1;
                break;
            case 3:
                x -= 1;
                y += 1;
                break;
            case 4:
                x -= 1;
                y -= 1;
                break;
            default:
                break;
        }
    }
    else
    {
        nextMove = rand() % 8;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                x += 1;
                break;
            case 2:
                y -= 1;
                break;
            case 3:
                y += 1;
                break;
            case 4:
                x -= 1;
                y -= 1;
                break;
            case 5:
                x -= 1;
                y += 1;
                break;
            case 6:
                x += 1;
                y -= 1;
                break;
            case 7:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    r = y;
    c = x;
}

