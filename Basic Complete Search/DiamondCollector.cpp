#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("diamond.in"); 
    ofstream fout("diamond.out");

    int n, k;
    fin >> n >> k;

    vector<int> diamonds;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        diamonds.push_back(x);
    }

    int maxTotal = 0;
    
    for (int i = 0; i < n; i++) {
        int total = 0;
        int cur = diamonds[i];
        for (int j = 0; j < n; j++) {
            if ((diamonds[j] - cur) >= 0 && diamonds[j] - cur <= k) {
                total++;
            }
        }
        maxTotal = max(total, maxTotal);
    }

    fout << maxTotal;
    
}