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
    ifstream fin("playerData.csv");

    if(!fout){
        cout << "Could not open file" << endl;
        break;
    }
    
    string temp; //temp string to check names
    string junk; //remainder of line
    int w, l, t;
    while(!fin.eof()){
        getline(fin, temp, ',');
        if(temp == n){
            break;
        }
        getline(fin, junk);
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
    string target;
    target = p.getName();
    string profile = p.getName() + "," + p.getWins() + "," + p.getLosses() + "," + p.getTies();

    ifstream fin("playerData.csv");

    if(!fin){
        cout << "Could not read file." << endl;
        break;
    }

    ofstream tempOut("temp.csv");

    string read;

    while(getline(fin, read)){
        if(read.substr(0, target.length()) == target){
            tempOut << profile << endl;
        }
        else{
            tempOut << read << endl;
        }
    }

    fin.close();
    tempOut.close();

    remove("playerData.csv");
    rename("temp.csv", "playerData.csv");
}

// void leaderboard(Player& p){

// }