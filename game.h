#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "computer.h"
#include "human.h"

class Game{
    Board board;
    Player* player1;
    Player* player2;
    Player** currentPlayer;
    int uRow, uCol;

    public:
        Game();
        Game(Player*, Player*);
        Game(const Game&);

        Player* getP1();
        Player* getP2();
        Player** getCurrentPlayer();
        Board* getBoard();

        void start();
        void switchPlayer();
        void playTurn();
};

#endif