#include "helpers.h"

int displayMenu() {
    int selection;

    cout << "*----------------MENU----------------*";
    cout << "1. START NEW GAME" << endl;
    cout << "2. SHOW PLAYER STATISTICS" <<endl;
    cout << "3. EXIT" << endl;
    cout << "Please select a menu option: ";

    do {
        cin >> selection;
        if (validateInput<int>(1,3, selection)) {
            return selection;
        } else {
            cout << "Invalid input. Please input a menu selection between 1-3: ";
        }
    } while (validateInput<int>(1,3, selection) = false);
}

template <typename T>
bool validateInput(T in1, T in2, T uInput) {
    if (uInput >= in1 && uInput <= in2) {
        return true;
    } else {
        return false;
    }
}