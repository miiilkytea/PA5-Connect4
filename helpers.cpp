#include "helpers.h"

int displayMenu() {
    int selection;

    cout << "*----------------MENU----------------*";
    cout << "1. START NEW GAME" << endl;
    cout << "2. SHOW PLAYER LEADERBOARD" <<endl;
    cout << "3. EXIT" << endl;
    cout << "Please select a menu option: ";

    do {
        cin >> selection;
        if (validateInput<int>(1,3, selection)) {
            return selection;
        } else {
            cout << "Invalid input. Please input a menu selection between 1-3: ";
        }
    } while (validateInput<int>(1,3, selection) == false);
}

void displayLeaderboard() {
    ifstream fin("leaderboard.csv", ios::out);
    string name, junk;
    int wins;

    if (!fout) {
        cout << "Could not open leaderboard.csv"<<endl;
    }

    getline(fin, junk);
    if (fin.is_open()) {
        while(fin) {
            getline(fin, junk);
        }
    }


}

template <typename T>
bool validateInput(T in1, T in2, T uInput) {
    if (uInput >= in1 && uInput <= in2) {
        return true;
    } else {
        return false;
    }
}