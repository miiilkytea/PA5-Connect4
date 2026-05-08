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

        int dropPiece(int, char); //returns row index where dropped, or 100 if it doesn't drop (in case board is not default size)
        bool isValidMove(int);
        bool checkWin(int, int, char);
        bool checkTie();

        friend ostream& operator <<(ostream&, Board&);
};

#endif

/* board displaying

easier logic
5   0 1 2 3 4 5 6
4   0 1 2 3 4 5 6
3   0 1 2 3 4 5 6
2   0 1 2 3 4 5 6
1   0 1 2 3 4 5 6
0   0 1 2 3 4 5 6

*/