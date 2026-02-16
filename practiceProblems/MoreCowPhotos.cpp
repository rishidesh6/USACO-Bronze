#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        map<int, int> occurences;
        int m = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m = max(m, x);
            occurences[x]++;
        }

        int total = n;
        total -= (occurences[m] - 1);

        for (auto& pair: occurences) {
            int num = pair.first;
            if (num == m) continue;

            if (pair.second > 2) {
                total -= (pair.second - 2);
            } else if (pair.second == 1) {
                total -= 1;
            }
        }

        cout << total << endl;
    }
}