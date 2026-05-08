#include "computer.h"

Computer(): Player() {}
Computer(string n, int w, int l, int t, char p) : Player (n, w, l, t, p) {}
Computer(const Computer& rhs) : Player (rhs){}

int Computer::makeMove(Board& board) {
    

}