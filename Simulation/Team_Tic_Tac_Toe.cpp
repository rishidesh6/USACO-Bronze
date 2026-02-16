#include <bits/stdc++.h>
using namespace std;

ifstream fin("tttt.in"); 
ofstream fout("tttt.out");

char matrix[3][3];

int main() {

    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            char x;
            fin >> x;
            matrix[i][j] = x;
        }
    }
    
    set<char> solo;
    set<pair<char, char>> team;

    for (int i = 0; i < 3; i++) {

        map<char, int> rows;
        map<char, int> cols;

        for (int j = 0; j < 3; j++) {
            rows[matrix[i][j]]++;
            cols[matrix[j][i]]++;
        }

        if (rows.size() == 1) {
            solo.insert(rows.begin()->first);
        } else if (rows.size() == 2) {
            auto it = rows.begin();
            char a = it->first;
            it++;
            char b = it->first;
            team.insert({a, b});
        }

        if (cols.size() == 1) {
            solo.insert(cols.begin()->first);
        } else if (cols.size() == 2) {
            auto it2 = cols.begin();
            char c = it2->first;
            it2++;
            char d = it2->first;
            team.insert({c, d});
        }
    }

    map<char, int> diag1;
    map<char, int> diag2;

    diag1[matrix[0][0]]++; diag1[matrix[1][1]]++; diag1[matrix[2][2]]++;

    if (diag1.size() == 2) {
        auto it3 = diag1.begin();
        char a = it3->first;
        it3++;
        char b = it3->first;
        team.insert({a, b});
    };
    if(diag1.size() == 1) solo.insert(diag1.begin()->first);

    diag2[matrix[0][2]]++; diag2[matrix[1][1]]++; diag2[matrix[2][0]]++;

    if (diag2.size() == 2) {
        auto it4 = diag2.begin();
        char c = it4->first;
        it4++;
        char d = it4->first;
        team.insert({c, d});
    }; 
    if(diag2.size() == 1) solo.insert(diag2.begin()->first);

    fout << solo.size() << endl << team.size();
}