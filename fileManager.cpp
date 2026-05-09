#include "fileManager.h"

void saveProfile(Player& p){
    ofstream fout("playerData.csv", ios::app);

    if(!fout){
        cout << "Could not open file" << endl;
    }
    else{
        fout << p.getName() << "," << p.getWins() << "," << p.getLosses() << "," << p.getTies() << endl;
    }
    fout.close();
}

Player* loadProfile(string n){
    ifstream fin("playerData.csv");

    if(!fin){
        cout << "Could not open file" << endl;
        return new Human("N/A", 0, 0, 0);
    }
    string temp; //temp string to check names
    string junk; //remainder of line
    int w, l, t;
    string ws, ls, ts;
    while(getline(fin, temp, ',')){
        if(temp == n){
            getline(fin, ws, ',');
            getline(fin, ls, ',');
            getline(fin, ts);
            w = stoi(ws);
            l = stoi(ls);
            t = stoi(ts);
            return new Human(temp,w,l,t);
        }
        getline(fin, junk);
    }
    return new Human(n,0,0,0);
}

bool overwriteProfile(Player& p){ //return if a profile got rewritten (true) or not (false)
    bool changed = false;         //if didn't get rewritten, then need to run saveProfile
    string target;
    target = p.getName();
    string profile = p.getName() + "," + p.getWins() + "," + p.getLosses() + "," + p.getTies();

    ifstream fin("playerData.csv");

    if(!fin){
        cout << "Could not read file." << endl;
        break;
    }

    ofstream tempOut("temp.csv");
    if(!tempOut){
        cout << "Could not open File." << endl;
        break;
    }

    string read;

    while(getline(fin, read)){
        if(read.substr(0, target.length()) == target){
            tempOut << profile << endl;
            changed = true;
        }
        else{
            tempOut << read << endl;
        }
    }

    fin.close();
    tempOut.close();

    remove("playerData.csv");
    rename("temp.csv", "playerData.csv");

    return changed;
}

// void leaderboard(Player& p){

// }