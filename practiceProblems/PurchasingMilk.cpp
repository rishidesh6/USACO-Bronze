#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;
    
    vector<long long> deals;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (i == 0) {
            deals.push_back(a);
        } else {
            if (a < (deals[i - 1] * 2)) {
                deals.push_back(a);
            } else {
                deals.push_back(deals[i - 1] * 2);
            }
        }
    }
    
    while (q--) {
        long long x;
        cin >> x;
        long long minCost = INT_MAX;

        long long remaining = x;
        for (int i = min(n - 1, 30LL); i >= 0; i--) {
            if (remaining < (1LL << i)) continue;
            long long times = remaining/(1LL << i);
            long long price = 0;
            price += (times * deals[i]);
            remaining = remaining % (1LL << i);

            if (remaining == 0) {
                minCost = min(price, minCost);
            } else {
                minCost = min(price + deals[i], minCost);
            }
        }

        cout << minCost << endl;
    }
}