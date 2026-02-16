#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowsignal.in"); 
ofstream fout("cowsignal.out");

int m, n, k;

int main() {

    fin >> m >> n >> k;

    char matrix[m][n];
    char x;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> x;
            matrix[i][j] = x;
        }
    }



    for (int i = 0; i < m; i++) {

        vector<char> curString;

        for (int j = 0; j < n; j++) {
            
            char cur = matrix[i][j];
            for (int y = 0; y < k; y++) {
                curString.push_back(cur);
            }
        }
        for (int times = 0; times < k; times++) {
            for (char character: curString) {
                fout << character;
            }
            fout << endl;
        }

    }
}