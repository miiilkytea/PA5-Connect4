#include "human.h"

Human::Human():Player() {}
Human::Human(string n, int w, int l, int t, char p): Player(n, w, l, t, p) {}
Human::Human(const Human& rhs) : Player (rhs) {}

int Human::makeMove(Board& board) {
    int col;
    cout << "Choose the column for your next move (EX. 1): ";

    do {
        cin >> col;
        if (board.isValidMove(col)) {
            return col;
        } else {
            cout << "Invalid column input. Please select an open column 1-7: ";
        }
    } while (board.isValidMove(col) == false);
}