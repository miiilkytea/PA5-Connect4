#include "fileManager.h"

void saveProfile(Human* p){
    ofstream fout("playerData.csv", ios::app);

    if(!fout){
        cout << "Could not open file" << endl;
    }
    else{
        fout << p->getName() << "," << p->getWins() << "," << p->getLosses() << "," << p->getTies() << endl;
    }
    fout.close();
}

Human* loadProfile(string n){
    ifstream fin("playerData.csv");

    if(!fin){
        cout << "Could not open file" << endl;
        return new Human("N/A", 0, 0, 0, 'X');
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
            return new Human(temp,w,l,t, 'X');
        }
        getline(fin, junk);
    }
    return new Human(n,0,0,0, 'X');
}

bool overwriteProfile(Human* p){ //return if a profile got rewritten (true) or not (false)
    bool changed = false;         //if didn't get rewritten, then need to run saveProfile
    string target;
    target = p->getName();
    int www = p->getWins();
    int lll = p->getLosses();
    int ttt = p->getTies();
    string ww = to_string(www);
    string ll = to_string(lll);
    string tt = to_string(ttt);
    string profile = target + "," + ww + "," + ll + "," + tt;

    ifstream fin("playerData.csv");

    if(!fin){
        cout << "Could not read file." << endl;
        return changed;
    }

    ofstream tempOut("temp.csv");
    if(!tempOut){
        cout << "Could not open File." << endl;
        return changed;
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