#include "game.h"

Game::Game() {

}

Game(Player* p1, Player* p2) {
    player1 = p1;
    player2 = p2;
}
Game::Game(const Game& rh) {
    player1 = rh.p1;
    player2 = rh.p2;
}

Player* Game::getP1() {

}
Player* Game::getP2() {

}
Player** Game::getCurrentPlayer(){

}
Board* Game::getBoard() {

}

void Game::start() {

}
void Game::switchPlayer() {

}
void Game::playTurn() {

}
void Game::savePlayerData() {

}
void Game::loadPlayerData() {

}