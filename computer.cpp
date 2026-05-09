#include "computer.h"

Computer::Computer(): Player() {}
Computer::Computer(string n, int w, int l, int t, char p) : Player (n, w, l, t, p) {}
Computer::Computer(const Computer& rhs) : Player (rhs){}

int Computer::makeMove(Board& board) {
    int col; 

    do {
        col = rand() % (board.getCols() + 1); //randomly selects from 0 to 1 less than the number of columns, which allows for indexing of the board
        if (board.isValidMove(col)) {
            break;
        }
    } while (board.isValidMove(col) == false);
    return col;
}