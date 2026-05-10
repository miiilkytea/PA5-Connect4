#include "helpers.h"

int displayMenu() {
    int selection;

    cout << "*----------------MENU----------------*" << endl;
    cout << "1. START NEW GAME" << endl;
    cout << "2. SHOW PLAYER LEADERBOARD" << endl;
    cout << "3. EXIT" << endl;
    cout << "Please select a menu option: ";

    do {
        cin >> selection;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000);
            cout << "Invalid input. Please input a menu selection between 1-3: ";
            continue;
        }

        if (!validateInput<int>(1,3, selection)) {
            cout << "Invalid input. Please input a menu selection between 1-3: ";
        } else {
            break;
        }
    } while (validateInput<int>(1,3, selection) == false);
    return selection;
}

template <typename T>
bool validateInput(T in1, T in2, T uInput) {
    if (uInput >= in1 && uInput <= in2) {
        return true;
    } else {
        return false;
    }
}

void displayLeaderboard(){
    ifstream fin("leaderboard.csv");
    if(!fin){
        cout << "Could not open leaderboard for display" << endl;
        return;
    }

    string header;
    getline(fin, header);

    string nms[10], wns[10];
    for(int i = 0; i < 10; i++){
        getline(fin, nms[i], ',');
        getline(fin, wns[i]);
    }

    cout << endl << endl << "======LEADERBOARD=======" << endl;
    for(int i = 0; i < 10; i++){
        if(nms[i] == "default"){
            break;
        }
        cout << i+1 << ") " << nms[i] << ", Wins: " << wns[i] << endl;
    }
    cout << "========================" << endl << endl;
}