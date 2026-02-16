#include <bits/stdc++.h>
using namespace std;

ifstream fin("cownomics.in"); 
ofstream fout("cownomics.out");

int main() {
    int n, m;
    fin >> n >> m;

    vector<vector<int>> spotty (m);
    vector<vector<int>> plain (m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            fin >> a;
            spotty[j].push_back(a);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char b;
            fin >> b;
            plain[j].push_back(b);
        }
    }

    int total = 0;

    for (int i = 0; i < m; i++) {
        int matches = 0;
        for (int j = 0; j < plain[i].size(); j++) {

            for (int k = 0; k < spotty[i].size(); k++) {

                if (plain[i][j] == spotty[i][k]) {
                    matches++;
                }

            }
            if (matches > 0) {
                break;
            }
        }
        if (matches == 0) {
            total++;
        }
    }

    fout << total;
}