#include "computer.h"

Computer::Computer(): Player() {}
Computer::Computer(string n, int w, int l, int t, char p) : Player (n, w, l, t, p) {}
Computer::Computer(const Computer& rhs) : Player (rhs){}

int Computer::makeMove(Board& board) {
    int col; 

    do {
        col = rand() % 8;
        if (board.isValidMove(col)) {
            return col;
        }
    } while (board.isValidMove(col) == false);
}