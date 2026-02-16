#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<long long> cows;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        cows.push_back(x);
    }

    for (int i = 0; i < m; i++) {

        long long cane;
        cin >> cane;
        long long bottom = 0;
        long long top = cane;

        for (int j = 0; j < n; j++) {
            long long cow = cows[j];
            if (cow > bottom) {
                int minH = min(cane, cow);
                cows[j]+= minH - bottom;
                bottom = minH;
            }
            if (bottom == top) break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cows[i] << endl;
    }

}