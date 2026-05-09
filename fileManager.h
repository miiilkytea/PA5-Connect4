#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <cstdio>
#include "game.h"

void saveProfile(Human*);
Human* loadProfile(string);
bool overwriteProfile(Human*);
void leaderboard(Human*);

#endif