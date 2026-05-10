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

void leaderboard(Human* p){
    int newWin = p->getWins();
    string newName = p->getName();

    string nams[10];
    int wns[10];
    int count = 0;

    ifstream fileIn("leaderboard.csv");
    if(!fileIn){
        cout << "Could not open leaderboard file." << endl;
        return;
    }

    ofstream tempOut("temp.csv");
    if(!tempOut){
        cout << "Could not make temporary leaderboard file." << endl;
        return;
    }

    string header;
    getline(fileIn, header);

    while(count < 10){
        string name, winStr;

        if(!getline(fileIn, name, ',')) break;
        if(!getline(fileIn, winStr)) break;

        nams[count] = name;
        wns[count] = stoi(winStr);
        count++;
    }

    fileIn.close();

    for(int i = 0; i < count; i++){
        if(nams[i] == newName){
            nams[i] = "default";
            wns[i] = 0;
        }
    }

    int position = count;
    for(int i = 0; i < count; i++){
        if(newWin > wns[i]){
            position = i;
            break;
        }
    }

    if(position < 10){ //only if the position of the ranking gets updated
        for(int i = 9; i > position; i--){ //moves rankings down
            nams[i] = nams[i-1];
            wns[i] = wns[i-1];
        }
        nams[position] = newName;
        wns[position] = newWin;

        cout << "Congratulations! You made the leaderboard! Rank: " << position+1 << endl;
    }

    tempOut << header << endl;
    for(int i = 0; i < 10; i++){
        tempOut << nams[i] << "," << wns[i] << endl;
    }

    tempOut.close();
    remove("leaderboard.csv");
    rename("temp.csv", "leaderboard.csv");
}