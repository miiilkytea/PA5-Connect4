#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <cstdio>
#include "player.h"

void saveProfile(Player&);
Player& loadProfile(string);
void overwriteProfile(Player&);
// void leaderboard(Player&);

#endif