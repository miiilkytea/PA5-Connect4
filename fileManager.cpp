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

// void leaderboard(Human* p){
//     const int MAX = 10;
//     int win[MAX];
//     string nams[MAX];
//     int count = 0;

//     ifstream fin("leaderboard.csv");
//     if(!fin){
//         cout << "Cannot read file." << endl;
//         return;
//     }
//     ofstream tempOut("temp.csv");
//     if(!tempOut){
//         cout << "Can't read file." << endl;
//         return;
//     }

//     string read;

//     while(getline(fin, read) && count <= MAX){ // <= 10 because of the first line not being part of the leaderboard, just labels
//         int commaIndex = -1;

//         for(int i = 0; i < read.length(); i++){
//             if(read[i] == ','){
//                 commaIndex = i;
//                 break;
//             }
//         }

//         if(commaIndex != -1){
//             getline[]
//         }

//         if(read.substr(nam.length()) < ww){
//             tempOut << profile << endl;
//             count++;
//             cout << "Congratulations! You made it on the leaderboard! You are rank " << count+1 << "!" << endl;
//             if(count < 10){
//                 tempOut << read << endl;
//             }

//         }
//         else{
//             tempOut << read << endl;
//         }
//         count++;
//     }

//     fin.close();
//     tempOut.close();

//     remove("leaderboard.csv");
//     rename("temp.csv", "leaderboard.csv");
// }

void leaderboard(Human* p) {
    const int MAX = 10;
    string names[MAX];
    int wins[MAX];
    int count = 0;

    // Load existing leaderboard
    ifstream fin("leaderboard.csv");
    if (fin) {
        string line;
        while (getline(fin, line) && count < MAX) {

            // Find comma manually (no size_t)
            int commaIndex = -1;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ',') {
                    commaIndex = i;
                    break;
                }
            }

            if (commaIndex != -1) {
                names[count] = line.substr(0, commaIndex);
                wins[count] = stoi(line.substr(commaIndex + 1));
                count++;
            }
        }
    }
    fin.close();

    // New entry
    string newName = p->getName();
    int newWins = p->getWins();

    // Find insertion position
    int pos = count; // default: append at end
    for (int i = 0; i < count; i++) {
        if (newWins > wins[i]) {
            pos = i;
            break;
        }
    }

    // Shift entries down to make room
    if (pos < MAX) {
        int limit = (count < MAX) ? count : MAX - 1;

        for (int i = limit; i > pos; i--) {
            names[i] = names[i - 1];
            wins[i] = wins[i - 1];
        }

        // Insert new entry
        names[pos] = newName;
        wins[pos] = newWins;

        if (count < MAX) count++;
    }

    // Write updated leaderboard
    ofstream fout("leaderboard.csv");
    for (int i = 0; i < count; i++) {
        fout << names[i] << "," << wins[i] << endl;
    }
    fout.close();

    // Print rank if player made it
    if (pos < MAX) {
        cout << "Congratulations! You made the leaderboard! Rank: " << pos + 1 << endl;
    }
}
