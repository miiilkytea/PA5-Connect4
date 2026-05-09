// author: Samantha English & Isabelle Schinzing
// version 0.0

#include "helpers.h"
#include "fileManager.h"

int main(){
    string name;
    Human* p1 = new Human("NA", 0, 0, 0, 'X');
    Computer* p2 = new Computer("Computer", 0, 0, 0, 'O');
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
                if (overwriteProfile(p1) == false) {    
                    saveProfile(p1);
                }
                cout << "GOODBYE!" << endl;
                break;
            default:
                cout << "Invalid input. Please select a menu option 1 or 2." << endl;
        }
    } while(menuSelect!=2);
    return 0;
}