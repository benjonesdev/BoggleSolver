#include <iostream>
#include <string>
#include <vector>
#include "Board.hpp"

using std::cout;
using std::string;

int main() {
	Board b;
	b.randomBoard();
	b.solveBoard();
	b.printBoard();
	return 0;
}
