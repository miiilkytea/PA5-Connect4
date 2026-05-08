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
    bool startCheck = false;
    while (startCheck == false) {
        cout << board;
        playTurn();
        switchPlayer();
        startCheck = board.checkWin() || board.checkTie();
    }
    savePlayerData();
}
void Game::switchPlayer() {
    if(currentPlayer == &player1) {
        currentPlayer = &player2;
    } else {
        currentPlayer = &player1;
    }
}
void Game::playTurn() {
    int check, selectedCol;
    char piece;
    do {
        selectedCol = (*currentPlayer)->makeMove(board);
        piece = (*currentPlayer)->getPiece();
        check = board.dropPiece(selectedCol, piece);
    }while (check == 100);
    
}  
void Game::savePlayerData() {
    
}
void Game::loadPlayerData() {

}