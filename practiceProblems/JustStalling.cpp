#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;

    vector<int> stalls;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        stalls.push_back(x);
    }

    vector<int> limits;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        limits.push_back(x);
    }

    sort(stalls.begin(), stalls.end());
    sort(limits.begin(), limits.end());

    long long total = 1;
    int numsPassed = 0;

    for (int i = n - 1; i >= 0; i--) {

        int cur = stalls[i];
        auto it = lower_bound(limits.begin(), limits.end(), cur);

        int pos = distance(limits.begin(), it);

        int amt = n - pos;
        total *= (amt - numsPassed);

        numsPassed++;
    }

    cout << total;
}