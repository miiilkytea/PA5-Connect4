#include "human.h"

Human():Player() {}
Human(string n, int w, int l, int t): Player(n, w, l, t) {}
Huamn(const Human& rhs) : Player (rhs) {}

int Human::makeMove(Board&) {
    //in progress
}