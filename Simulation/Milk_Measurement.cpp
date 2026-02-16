#include <bits/stdc++.h>
using namespace std;

ifstream fin("measurement.in"); 
ofstream fout("measurement.out");

int n;

int main() {
    fin >> n;
    
    map<int, int> m;
    map<int, int> b;
    map<int, int> e;

    int day; string name;
    char sign;
    int num;

    int bessie = 7;
    int elsie = 7;
    int mildred = 7;

    int maxDay = 0;

    for (int i = 0; i < n; i++) {
        fin >> day >> name >> sign >> num;
        maxDay = max(maxDay, day);

        if (name == "Mildred") {
            m[day] = num;
            if (sign == '-') m[day] *= -1;
        } else if (name == "Elsie") {
            e[day] = num;
            if (sign == '-') e[day] *= -1;
        } else {
            b[day] = num;
            if (sign == '-') b[day] *= -1;
        }
    }

    string display = "";
    int displayChanges = 0;

    for (int i = 1; i <= maxDay; i++) {
        
        string prevDisplay = display;
        string newDisplay = "";

        if (!m.count(i) && !e.count(i) && !b.count(i)) continue;

        if (m.count(i)) {
            mildred += m[i];
        } else if (b.count(i)) {
            bessie += b[i];
        } else {
            elsie += e[i];
        }

        int maxi = max({elsie, bessie, mildred});
        if (elsie == maxi) {
            newDisplay += 'E';
        }
        if (bessie == maxi) {
            newDisplay += 'B';
        } 
        if (mildred == maxi) {
            newDisplay += 'M';
        }

        if (newDisplay != prevDisplay) displayChanges++;
        display = newDisplay;
    }

    fout << displayChanges;
}

