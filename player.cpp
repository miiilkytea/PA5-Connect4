#include "player.h"

Player::Player() {
    name = "NA";
    wins = 0;
    losses = 0;
    ties = 0;
    piece = "O";
}
Player::Player(string n, int w, int l, int t) {
    name = n;
    wins = w;
    losses = l;
    ties = t;
}

Player::Player(const Player& rhs) {
    name = rhs.name;
    wins = rhs.wins;
    losses = rhs.losses;
    ties = rhs.ties;
    piece = rhs.piece;
}

string Player::getName() {
    return name;
}

int Player::getWins() {
    return wins;
}

int Player::getLosses() {
    return losses;
}

int Player::getTies() {
    return ties;
}

char Player::getPiece() {
    return piece;
}

void Player::setName(string n) {
    name = n;
}

void Player::recordWin() {
    wins++;
}
void Player::recordLoss() {
    losses++;
}
void Player::recordTie() {
    ties++;
}

void Player::setPiece(Player& p2) {
    if (p2.getPiece()=="O") {
        piece = "X";
    }
    piece = "O";
}
