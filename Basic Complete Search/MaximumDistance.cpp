#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        y.push_back(b);
    }

    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int distance = pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2);
            maxVal = max(distance, maxVal);
        }
    }

    cout << maxVal;
}