#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[i] = x;
    }

    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;

        c[i] = c[i] - y;
    }

    sort(c.begin(), c.end(), greater<int>());
    for (int i = 0; i < q; i++) {
        int v, s;
        cin >> v >> s;

        if (c[v - 1] > s) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}