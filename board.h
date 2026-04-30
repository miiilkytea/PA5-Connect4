#ifndef BOARD_H
#define BOARD_H
using namespace std;
#include <iostream>

class Board{
    int rows, cols;
    char** grid;

    public:
        Board();
        Board(int, int);
        Board(const Board&);

        int getRows();
        int getCols();
        char** getGrid();

        void setRows(int);
        void setCols(int);

        Board& operator =(const Board&);
        ~Board();

        bool dropPiece(int, char);
        // bool isValidMove(int);
        bool checkWin(char);
        bool checkTie();

        ostream& operator <<(ostream&, Board&);
};

#endif