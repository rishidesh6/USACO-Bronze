#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<char> cows;
    vector<int> segments;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '1') {
            cur++;
        } else {
            if (cur != 0) {
                segments.push_back(cur);
            }
            cur = 0;
        }
        cows.push_back(x);
    }
    
    if (cur != 0) {
        segments.push_back(cur);
    }

    int minVal = INT_MAX;
    bool exits = false;

    for (int window = 1; window <= n; window += 2) {

        long long temp = 0;

        for (int i = 0; i < segments.size(); i++) {

            int block = segments[i];

            if ((i == 0 && cows[0] == '1') || (i == segments.size() - 1 && cows[n - 1] == '1')) {
                if (window > block * 2 - 1) {
                    exits = true;
                }
            } else {
                if (window > block) {
                    exits = true;
                }
            }
            
            if (!exits) {
                temp += (block + window - 1) / window;
            }
        }

        if (exits) break;
        minVal = min(minVal, (int)temp);
    }
    cout << minVal;
}