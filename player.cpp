#include "player.h"

Player::Player() {
    name = "NA";
    wins = 0;
    losses = 0;
    ties = 0;
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
}

string Player::getName() {
    return name;
}

int Player::getWins() {
    return wins;
}

int Player::getLosses() {
    
}

int getTies() {

}

void setName(string) {

}
void recordWin();
void recordLoss();
void recordTie();

virtual int makeMove(Board&)=0;