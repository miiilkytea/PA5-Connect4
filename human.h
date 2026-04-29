#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player {

    public: 
        Human();
        Human(strint, int, int, int);
        Huamn(const Human&);

        int makeMove(Board&) override;
};

#endif