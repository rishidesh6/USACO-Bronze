#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        string moo;
        cin >> moo;

        int ans = INT_MAX;

        if (moo.size() < 3) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i < moo.size() - 1; i++) {
            if (moo[i] != 'O') continue;
            int size = moo.size();
            int cur = 0;
            if (moo[i - 1] != 'M') {
                cur++;
            }
            if (moo[i + 1] != 'O') {
                cur++;
            }
            ans = min(ans, size - 3 + cur);
        }

        if (ans == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}