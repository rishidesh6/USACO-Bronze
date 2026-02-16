#include <bits/stdc++.h>
using namespace std;

ifstream fin("blocks.in"); 
ofstream fout("blocks.out");

int n;
string box1;
string box2;

int main() {

    fin >> n;

    map<char, int> alpha;
    for (char c = 'a'; c <= 'z'; c++) alpha[c] = 0;

    while (fin >> box1 >> box2) {

        map<char, int> f1;
        map<char, int> f2;

        for (int i = 0; i < box1.size(); i++) {
            char cur = box1[i];
            f1[cur]++;
        }

        for (int i = 0; i < box2.size(); i++) {
            char cur = box2[i];
            f2[cur]++;
        }

        //we need to count the max amount of times each letter appears per pair of boxes
        for (char j = 'a'; j <= 'z'; j++) {
            //can loop through a map with keys that don't have to exist, like how a certain letter in the alphabet might not show up;
            alpha[j] += max(f1[j], f2[j]);
        }
    }

    for (auto& pair: alpha) {
        fout << pair.second << endl;
    }
}