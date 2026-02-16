#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("balancing.in"); 
    ofstream fout("balancing.out");

    int n;
    fin >> n;

    vector<int> xs;
    vector<int> ys;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        total++;
        xs.push_back(x); ys.push_back(y);
    }

    int minM = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int maxM = 0;
            int curX = xs[i] + 1; int curY = ys[j] + 1;
            int Q1 = 0; int Q2 = 0; int Q3 = 0; int Q4 = 0;

            for (int k = 0; k < n; k++) {
                int curX2 = xs[k]; int curY2 = ys[k];
                if (curX2 < curX && curY2 < curY) {
                    Q1++;
                } else if (curX2 > curX && curY2 < curY) {
                    Q2++;
                } else if (curX2 > curX && curY2 > curY) {
                    Q3++;
                }
            }

            maxM = max({Q1, Q2, Q3, total - Q1 - Q2 - Q3});
            minM = min(minM, maxM);
        }
    }

    fout << minM;
}