#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, k;
    cin >> t >> k;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int totalOs = 0;
        vector<bool> flip(n, false);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'O') {
                if (totalOs % 2 == 1) {
                    flip[i] = true;
                } else {
                    totalOs++;
                }
            } else {
                if (totalOs % 2 == 1) {
                    flip[i] = true;
                    totalOs++;
                }
            }
        }

        cout << "YES" << endl;
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                if (flip[i]) {
                    if (s[i] == 'O') {
                        cout << 'M';
                    } else {
                        cout << 'O';
                    }
                } else {
                    cout << s[i];
                }
            }
            cout << endl;
        }
    }


}