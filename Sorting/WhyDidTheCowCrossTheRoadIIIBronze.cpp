#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowqueue.in"); 
ofstream fout("cowqueue.out");

int n;

int main() {
    fin >> n;
    map<int, int> arrivals;
    vector<int> sortedArrivals(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        arrivals[x] = y;
        sortedArrivals[i] = x;
    }

    sort(sortedArrivals.begin(), sortedArrivals.end());

    int t = 0;
    for (int val: sortedArrivals) {
        t = max(t, val);
        t += arrivals[val];
    }

    fout << t;
}