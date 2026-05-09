#include "helpers.h"

int displayMenu() {
    int selection;

    cout << "*----------------MENU----------------*" << endl;
    cout << "1. START NEW GAME" << endl;
    cout << "2. SHOW PLAYER LEADERBOARD" <<endl;
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

void displayLeaderboard() {
    ifstream fin("leaderboard.csv", ios::out);
    string name, junk, wins;
    int i = 1;

    if (!fin) {
        cout << "Could not open leaderboard.csv"<<endl;
    }

    
    getline(fin, junk);
    cout << "*-----------LEADERBOARD-----------*" << endl;
    if (fin.is_open()) {
        while(!fin.eof()) {
            getline(fin, name, ',');
            getline(fin, wins);

            cout << i << ") " << name << " | " << wins << endl;
            i++;
        }
    }
    fin.close();


}

template <typename T>
bool validateInput(T in1, T in2, T uInput) {
    if (uInput >= in1 && uInput <= in2) {
        return true;
    } else {
        return false;
    }
}