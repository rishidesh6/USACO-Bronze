#include <bits/stdc++.h>
using namespace std;

ifstream fin("gymnastics.in"); 
ofstream fout("gymnastics.out");


int main() {
    int k, n;

    fin >> k >> n;

    int matrix[k][n];
    int pos[k][n + 1];

    for (int session = 0; session < k; session++) {
        for (int place = 0; place < n; place++) {
            int x;
            fin >> x;
            matrix[session][place] = x;
            pos[session][matrix[session][place]] = place;
        }
    }

    int pairs = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (i == j) continue;

            bool before = true;

            for (int session = 0; session < k; session++) {
                if (pos[session][i] > pos[session][j]) {
                    before = false;
                    break;
                }
            }

            if (before) pairs++;
        }
    }

    fout << pairs;
}