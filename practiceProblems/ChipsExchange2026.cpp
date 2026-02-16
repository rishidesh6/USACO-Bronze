#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long A, B, cA, cB, fA;
        cin >> A >> B >> cA >> cB >> fA;

        if (A >= fA || ((B/cB) * cA) + A >= fA) {
            cout << 0 << endl;
            continue;
        } else if (A == 0 && B == 0) {
            cout << ((fA + (fA % 2))/cA)*(cB) << endl;
            continue;
        }
        

        for (long long x = 1; x < pow(10, 4); x++) {
            bool works = false;
            for (long long j = 0; j <= x; j++) {
            
                long long a = j;
                long long b = x - a;

                if (B + b > cB) {
                long long value = (B + b)/cB * cA;
                    if (A + a + value >= fA) {
                        works = true;
                    } else {
                        works = false;
                        break;
                    }
                }
            }

            if (works) {
                cout << x << endl;
                break;
            }
        }

    }
}