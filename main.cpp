// author: Samantha English & Isabelle Schinzing
// version 0.0

#include "helpers.h"
#include "fileManager.h"

main(){
    string name;
    Human* p1;

    cout << "Welcome to Connect 4!" << endl << "Enter your name: ";
    cin >> name;

    p1 = loadProfile(name);

    while(displayMenu()!=3){

    }


    return 0;
}