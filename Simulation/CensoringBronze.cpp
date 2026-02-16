#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("censor.in"); 
    ofstream fout("censor.out");

    string s;
    fin >> s;
    string t;
    fin >> t;

    for (int i = 0; i < s.size(); i++) {
        if (i < t.size() - 1) {
            continue;
        }
        string word = "";
        for (int j = i - t.size() + 1; j <= i; j++) {
            word += s[j];
        }
        if (word == t) {
            s.erase(i - t.size() + 1, t.size());
            i = max(-1, i - (int)t.size());
        }
    }

    fout << s;

}