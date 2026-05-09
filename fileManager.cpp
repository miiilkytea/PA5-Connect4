#include "fileManager.h"

void saveProfile(Player& p){
    ofstream fout("playerData.csv", ios::app);

    if(!fout){
        cout << "Could not open file" << endl;
        break;
    }

    fout << p.getName() << "," << p.getWins() << "," << p.getLosses() << "," << p.getTies() << endl;

    fout.close();
}

Player& loadProfile(string n){
    ifstream fin("playerData.csv", ios::in);

    if(!fout){
        cout << "Could not open file" << endl;
        break;
    }
    
    string temp; //temp string to check names
    string junk; //remainder of line
    int w, l, t;
    while(!fin.eof()){
        getline(fin, temp, ',');
        getline(fin, junk);
        if(temp == n){
            break;
        }
    }
    if(temp == n){
        getline(fin, w, ',');
        getline(fin, l, ',');
        getline(fin, t);
        Player* profile(temp, w, l, t);
    }
    else{
        Player* profile(n, 0, 0, 0);
    }

    return profile;
}

void overwriteProfile(Player& p){

}