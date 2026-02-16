#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    vector<vector<char>> win (n);
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        for (int j = 0; j < inp.size(); j++) {
            win[i].push_back(inp[j]);
            if (i != j) {
                if (inp[j] == 'W') {
                    win[j].push_back('L');
                } else if (inp[j] == 'L') {
                    win[j].push_back('W');
                } else {
                    win[j].push_back('D');
                }
            }
        }
    }


    for (int i = 0; i < m; i++) {
        
        int curL; int curR;
        cin >> curL >> curR;
        int total = 0;

        int winning = 0;
        for (int i = 0; i < n; i++) {
            if (win[i][curL - 1] == 'W' && win[i][curR - 1] == 'W') {
                winning++;
            }
        }
        
        for (int l = 1; l <= n; l++) {

            if (win[l - 1][curL - 1] == 'W' && win[l - 1][curR - 1] == 'W') {
                total += n;
            } else {
                total += winning;
            }
        }

        cout << total << endl;
    }
}