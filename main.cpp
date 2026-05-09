// author: Samantha English & Isabelle Schinzing
// version 0.0

#include "helpers.h"
#include "fileManager.h"

int main(){
    string name;
    Human* p1;
    Computer* p2 = new Computer("Computer", 0, 0, 0);
    int menuSelect;

    cout << "Welcome to Connect 4!" << endl << "Enter your name: ";
    cin >> name;

    p1 = loadProfile(name);

    do {
        menuSelect = displayMenu();
        switch (menuSelect) {
            case 1:{
                Game newGame(p1, p2);
                newGame.start();
                break;
            }
            case 2:
                displayLeaderboard();
                break;
            case 3:
                if (overwriteProfile(p1) == false) {    
                    saveProfile(p1);
                }
                cout << "GOODBYE!" << endl;
                break;
            default:
                cout << "Invalid input. Please select a menu option 1-3." << endl;
        }
    } while(menuSelect!=3);
    return 0;
}