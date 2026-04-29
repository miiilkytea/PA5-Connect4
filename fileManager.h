#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "player.h"

void saveProfile(Player&);
Player& loadProfile(string);
void overwriteProfile(Player&);

#endif