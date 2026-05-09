#include "game.h"

Game::Game() {
    player1 = nullptr;
    player2 = nullptr;
    currentPlayer = &player1;
}

Game::Game(Player* p1, Player* p2) {
    player1 = p1;
    player2 = p2;
    currentPlayer = &p1;
}
Game::Game(const Game& rh) {
    player1 = rh.player1;
    player2 = rh.player2;
    
}

Player* Game::getP1() {
    return player1;
}
Player* Game::getP2() {
    return player2;
}
Player** Game::getCurrentPlayer(){
    return currentPlayer;
}
Board* Game::getBoard() {
    return &board;
}

void Game::start() {
    bool endGame = false;
    bool uWin, uTie;
    while (endGame == false) {
        cout << board;
        playTurn();
        switchPlayer();
        uWin = board.checkWin(uCol, uRow,(*currentPlayer)->getPiece());
        uTie = board.checkTie();
        endGame =  uWin || uTie;

        if (uWin == true) {
            (*currentPlayer)->recordWin();
            switchPlayer();
            (*currentPlayer)->recordLoss();
        } else if (uTie == true) {
            for (int i = 0; i < 2; i++) {
                (*currentPlayer)->recordTie();
                switchPlayer();
            }
        }
    }
}
void Game::switchPlayer() {
    if(currentPlayer == &player1) {
        currentPlayer = &player2;
    } else {
        currentPlayer = &player1;
    }
}
void Game::playTurn() {
    char piece;
    do {
        uCol = (*currentPlayer)->makeMove(board);
        piece = (*currentPlayer)->getPiece();
        uRow = board.dropPiece(uCol, piece);
    }while (uRow == 100);
    
}  
