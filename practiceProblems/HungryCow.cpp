#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long t;
    cin >> t;

    long long daysFilled = 0;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        long long d, b;
        cin >> d >> b;

        if (min(t, d + b - 1) == daysFilled) {
            continue;
        }else {
            daysFilled = min(t, d + b - 1);
            total += daysFilled - d + 1;
        }
    }

    cout << total;
}