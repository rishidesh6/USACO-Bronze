#include <bits/stdc++.h>
using namespace std;

ifstream fin("shuffle.in"); 
ofstream fout("shuffle.out");

int n;

int main() {
    fin >> n;

    int a;
    vector<int> spot;

    for (int i = 0; i < n; i++) {
        fin >> a;
        spot.push_back(a);
    }

    int x;
    map<int, int> ids;
    int names[n];

    for (int i = 0; i < n; i++) {
        fin >> x;
        ids[x] = i;
        names[i] = x;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            ids[names[j]] = spot[j] - 1;
        }
    }

    for (const auto& pair: ids) {
        names[pair.second] = pair.first; 
    }
    for (int i = 0; i < n; i++) {
        fout << names[i] << endl;
    }
}