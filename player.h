#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"


class Player{
    protected:
        string name;
        int wins, losses, ties;
        char piece;

    public:
        Player();
        Player(string, int, int, int, char);
        Player(const Player&);

        string getName();
        int getWins();
        int getLosses();
        int getTies();
        char getPiece();

        void setName(string);
        void recordWin();
        void recordLoss();
        void recordTie();
        void setPiece(Player&);

        virtual int makeMove(Board&)=0;
};

#endif