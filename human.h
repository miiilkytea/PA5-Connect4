#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player {

    public: 
        Human();
        Human(string, int, int, int, char);
        Human(const Human&);

        int makeMove(Board&) override;
};

#endif