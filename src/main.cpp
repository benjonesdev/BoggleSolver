#include <iostream>
#include <string>
#include <vector>
#include "Board.hpp"

using std::cout;
using std::string;

// const int MAX_ROWS = 4;
// const int MAX_COLS = 4;

// // static const string CHARACTER_DICE[16] = {
// //    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
// //    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
// //    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
// //    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
// // };


// char board[4][4] = {
// 	{'r', 'e', 'w', 'n'},
// 	{'l', 'a', 'c', 't'},
// 	{'i', 's', 'a', 'r'},
// 	{'e', 'e', 'n', 'o'}
// };

// bool outOfBounds(int row, int col) {
// 	// out of bounds
// 	if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) {
// 		return true;
// 	}
// 	// in bounds
// 	return false;
// }

// // Recursive DFS function
// void dfsUtil(char board[][4], int row, int col, bool visited[][4], std::vector<std::string> &validWords, std::string str) {
// 	// If current coords are out of bounds or already visited, return
// 	if (outOfBounds(row, col) || visited[row][col]) {
// 		return;
// 	}
// 	// Add letter of current square into string
// 	str += board[row][col];
// 	// Mark the square as visited
// 	visited[row][col] = true;
	
// //NOTE: this prints strings of length 4 to show that the strings generated follow boggle rules
// 	if (str.size() == 4) {
// 		validWords.push_back(str);
// 	}

// /* Here we check if str is a valid word, if so add to a vector of valid words for the board
//  * We'll need to add that vector to the function signature
//  * ex:
//  * if (isInDictionary(str))
//  *		validWordsVector.push(str)
//  */ 

// 	// Recursively move to adjacent squares +/- 1 in both directions
// 	for (int i = row - 1; i <= row + 1; i++) {
// 		for (int j = col - 1; j <= col + 1; j++) {
// 			dfsUtil(board, i, j, visited, validWords, str);
// 		}
// 	}

// 	// Undo the current move so the algorithm can backtrack
// 	str = str.substr(0, str.size() - 1);
// 	visited[row][col] = false;
// }

// // Could probably get rid of this function and initialize visited[][] in main or something
// void dfs(char board[][4], int row, int col, std::vector<std::string> &validWords) {
// 	bool visited[4][4] = {
// 		{false, false, false, false},
// 		{false, false, false, false},
// 		{false, false, false, false},
// 		{false, false, false, false}
// 	};
// 	dfsUtil(board, row, col, visited, validWords, "");
// }

// int main() {
// 	std::vector<std::string> validWords; 

// 	// Prints the board
// 	cout << "Board\n";
// 	for (int i = 0; i < 4; i++) {
// 		for (int j = 0; j < 4; j++) {
// 			cout << board[i][j];
// 			cout << " ";
// 		}
// 		cout << "\n";
// 	}
// 	cout << "\n";

// 	dfs(board, 0, 0, validWords);

// 	// Prints all valid words found of length 4
// 	for(int i = 0; i < validWords.size(); i++) {
// 		cout << validWords[i] << "\n";
// 	}

// 	return 0;
// }

int main() {
	Board b;
	b.randomBoard();
	b.printBoard();
	return 0;
}
