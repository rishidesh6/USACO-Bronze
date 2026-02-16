#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int q;
    cin >> q;

    int maxPic = 0;
    vector<vector<int>> cows(n, vector<int>(n, 0));
    vector<vector<int>> sums(n, vector<int>(n, 0));

    while (q--) {
        int r, c, v;
        cin >> r >> c >> v;
        r--; c--;
        int diff = v - cows[r][c];
        cows[r][c] = v;

        for (int i = max(0, r - k + 1); i <= min(r, n - k); i++) {
            for (int j = max(0, c - k + 1); j <= min(c, n - k); j++) {
                sums[i][j] += diff;
                maxPic = max(maxPic, sums[i][j]);
            }
        }

        cout << maxPic << endl;
    }
}