#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {

    cin >> n >> m;
    string dirs;
    cin >> dirs;

    vector<long long> a;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    long long total = accumulate(a.begin(), a.end(), 0LL);
    vector<bool> badL(n);
    vector<bool> badR(n);

    for (int i = 0; i < n; i++) {
        if (dirs[i] == 'R' && dirs[(i + 1) % n] == 'L') {
            badL[i] = true;
            badR[(i + 1) % n] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        long long rn = 0;
        if (badL[i]) {
            int j = (i - 1 + n) % n;
            while (dirs[j] == 'R') {
                rn += a[j];
                j = (j - 1 + n) % n;
            }
        }
        if (badR[i]) {
            int j = (i + 1) % n;
            while (dirs[j] == 'L') {
                rn += a[j];
                j = (j + 1) % n;
            }
        }
        total -= min(rn, m);
    }

    cout << total;
}