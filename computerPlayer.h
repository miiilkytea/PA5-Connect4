#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"

class Computer : public Player {

    public: 
        Computer();
        Computer(strint, int, int, int);
        Computer(const Computer&);

        int makeMove(Board&) override;
};

#endif