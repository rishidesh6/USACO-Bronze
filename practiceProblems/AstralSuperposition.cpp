#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        int numStars = 0;
        int ans = 0;

        vector<vector<char>> matrix(n, vector<char>(n, ' '));
        vector<vector<bool>> used(n, vector<bool>(n, false));

        bool impossible = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char x;
                cin >> x;
                if (x != 'W') numStars++;
                matrix[i][j] = x;
            }
        }

        if (a == 0 && b == 0) {
            cout << numStars << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (impossible) break;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 'B') continue;
                if (i - b < 0 || j - a < 0)  {
                    impossible = true;
                    break;
                } else if (matrix[i - b][j - a] == 'W') {
                    impossible = true;
                    break;
                }

                used[i - b][j - a] = true;
                ans += 2;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 'G') continue;
                if (used[i][j]) continue;
                if ((i - b >= 0 && j - a >= 0) && (matrix[i - b][j - a] != 'W')) {
                    continue;
                } else {
                    used[i][j] = true;
                    ans++;
                }
            }
        }

        if (!impossible) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}