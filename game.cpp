#include "game.h"

Game::Game() {
    player1 = null;
    player2 = null;
    currentPlayer = player1;
}

Game(Player* p1, Player* p2) {
    player1 = p1;
    player2 = p2;
    currentPlayer = p1;
}
Game::Game(const Game& rh) {
    player1 = rh.p1;
    player2 = rh.p2;
    
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
    return board;
}

void Game::start() {

}
void Game::switchPlayer() {
    if(currentPlayer == player1) {
        currentPlayer = player2;
    } else {
        currentPlayer = player1;
    }
}
void Game::playTurn() {
    int check, selectedCol;
    char piece;
    if (currentPlayer != null) {
        do {
            selectedCol = currentPlayer->makeMove();
            piece = currentPlayer->getPiece();
            check = board.dropPiece(selectedCol, piece);
            if (check != 100) {
                switchPlayer();
            }
        while (check == 100);
        }
    } else {
        cout << "Player 1 not assigned. Please create a player profile to proceed" << endl;
    }
}  
void Game::savePlayerData() {

}
void Game::loadPlayerData() {

}