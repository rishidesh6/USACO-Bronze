#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> T;
vector<int> P;
vector<int> diffs;

long long total = 0;

int main() {
    cin >> n;
    
    int p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        P.push_back(p);
    }
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        T.push_back(t);
    }
    
    for (int i = 0; i < n; i++) {
       diffs.push_back(P[i] - T[i]); 
    }

    total += abs(diffs[0]);


    for (int i = 1; i < n; i++) {
        int currentDif = diffs[i] - diffs[i - 1];

        if (currentDif > 0) {
            total += currentDif;
        }
    }

    cout << total;
}