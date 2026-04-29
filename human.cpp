#include "human.h"

Human():Player() {}
Human(string n, int w, int l, int t): Player(n, w, l, t) {}
Huamn(const Human& rhs) : Player (rhs) {}

int Human::makeMove(Board& board) {
    int col;
    cout << "Choose the column for your next move (EX. 1): ";
    cin >> col;

    do {
        if (board.isValidMove(col)) {
            return col;
        } else {
            cout << "Invalid column input. Please select an open column 1-7: ";
            cin >> col;
        }
    } while (board.isValidMove(col));
}