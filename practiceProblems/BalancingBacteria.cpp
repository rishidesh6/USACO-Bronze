#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    long long ops = 0;
    
    for (int i = 0; i < n; i++) {

        if (a[i] == 0) continue;
        
        long long val = abs(0 - a[i]);
        long long prev = a[i];
        ops += val;
        a[i] = 0;
        
        for (int j = i + 1; j < n; j++) {
            long long mult = j - i + 1;
            if (prev - 0 > 0) {
                a[j] -= (mult * val);
            } else {
                a[j] += (mult * val);
            }
        }
    }

    cout << ops;
}