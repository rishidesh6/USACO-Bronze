#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, cA, cB, fA;
        cin >> a >> b >> cA >> cB >> fA;

        long long newA = b/cB * cA;
        newA += a;
        long long cashIns = ((fA - newA)/cA);
        b -= (b/cB) * cB;

        if (newA >= fA) {
            cout << 0 << endl;
            continue;
        }

        long long total = 0;
        if (cB < cA) {
            total += (cB - b - 1);
            total += (fA - newA);
            cout << total << endl;
            continue;
        } else {
            total += cA - 1;
            total += (cashIns * cB);
            cout << total << endl;
            continue;
        }
    }
}