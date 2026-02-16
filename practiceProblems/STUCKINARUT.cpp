#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;

    vector<vector<int>> NCows;
    vector<vector<int>> ECows;

    vector<int> xVals(n);
    vector<int> yVals(n);

    for (int i = 0; i < n; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;

        vector<int> arr = {x, y, i};

        if (dir == 'E') {
            ECows.push_back(arr);
        } else {
            NCows.push_back(arr);
        }

        xVals[i] = x;
        yVals[i] = y;
    }

    vector<vector<int>> meet;

    for (auto &nc : NCows) {
        for (auto &ec : ECows) {

            int yT = ec[1] - nc[1];
            int xT = nc[0] - ec[0];

            if (xT == yT) continue;

            if (yT > xT && xT > 0) {
                meet.push_back({yT, nc[2], ec[2], 0});
            } 
            else if (yT < xT && yT > 0) {
                meet.push_back({xT, ec[2], nc[2], 1});
            }
        }
    }

    sort(meet.begin(), meet.end());

    vector<int> ans(n, INT_MAX);

    for (auto &m : meet) {
        if (ans[m[1]] == INT_MAX && ans[m[2]] == INT_MAX) {
            ans[m[1]] = m[0];
            continue;
        }

        if (ans[m[1]] == INT_MAX && ans[m[2]] != INT_MAX) {

            if (m[3]) {
                int start = yVals[m[2]];
                int end = start + ans[m[2]];

                if (yVals[m[1]] >= start && yVals[m[1]] <= end) {
                    ans[m[1]] = m[0];
                }
            } else {
                int start = xVals[m[2]];
                int end = start + ans[m[2]];

                if (xVals[m[1]] >= start && xVals[m[1]] <= end) {
                    ans[m[1]] = m[0];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == INT_MAX) {
            cout << "Infinity\n";
        } else {
            cout << ans[i] << "\n";
        }
    }
}
