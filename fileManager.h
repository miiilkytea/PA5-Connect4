#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <cstdio>
#include "game.h"

void saveProfile(Player&);
Player* loadProfile(string);
bool overwriteProfile(Player&);
// void leaderboard(Player&);

#endif