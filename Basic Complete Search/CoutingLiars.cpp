#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> dir;
    vector<int> vals;

    for (int i = 0; i < n; i++) {
        char op;
        int val;
        cin >> op >> val;
        dir.push_back(op);
        vals.push_back(val);
    }

    int minLiars = INT_MAX;
    for (int x = 0; x < n; x++) {
        int X = vals[x];
        int liars = 0;
        for (int i = 0; i < n; i++) {
            if (dir[i] == 'G' && X < vals[i]) {
                liars++;
            } else if (dir[i] == 'L' && X > vals[i]) {
                liars++;
            }
        }
        minLiars = min(minLiars, liars);
    }

    cout << minLiars;
}