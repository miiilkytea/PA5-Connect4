#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"
using namespace std;


class Player{
    protected:
        string name;
        int wins, losses, ties;

    public:
        Player();
        Player(string, int, int, int);
        Player(const Player&);

        string getName();
        int getWins();
        int getLosses();
        int getTies();

        void setName(string);
        void recordWin();
        void recordLoss();
        void recordTie();

        virtual int makeMove(Board&)=0;
};

#endif