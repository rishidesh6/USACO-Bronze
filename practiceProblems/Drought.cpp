#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<long long> a;
        long long minY = INT_MAX;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            minY = min(minY, x);
            a.push_back(x);
        }

        long long total = 0;
        bool solved = false;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n - 1; j++) {

                if (a[j] == minY) continue;
                
                long long diff = a[j] - minY;

                a[j] -= diff;
                a[j + 1] -= diff;
                total += 2 * (diff);

                minY = min(minY, a[j + 1]);

                auto it = min_element(a.begin(), a.end());
                auto it2 = max_element(a.begin(), a.end());

                if (*it == *it2) {
                    solved = true;
                }
            }
        }
        
        if (solved && minY >= 0) {
            cout << total << endl;
        } else {
            cout << -1 << endl;
        }
    }
}