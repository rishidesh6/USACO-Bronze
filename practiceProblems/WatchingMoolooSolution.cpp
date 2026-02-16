#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> days(n);
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        days[i] = x;
    }
    
    long long prev = days[0];
    long long total = k + 1;

    for (long long i = 0; i < n; i++) {
        long long gap = days[i] - prev;
        
        if (gap < (k + 1)) {
            total += gap;
        } else {
            total += k + 1;
        }
        
        prev = days[i];
    }
    
    cout << total;

}