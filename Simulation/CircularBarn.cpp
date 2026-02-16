#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cbarn.in"); 
    ofstream fout("cbarn.out");

    int n;
    fin >> n;
    vector<int> rooms;
    int sumCows = 0;

    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        sumCows += x;
        rooms.push_back(x);
    }

    
    int minD = INT_MAX;

    for (int i = 0; i < n; i++) {
        int total = 0;
        int cowsRemaining = sumCows - rooms[i];;
        for (int j = i + 1; j < n + i; j++) {
            int cur = j;
            if (j >= n) {
                cur -= n;
            }
            total += cowsRemaining;
            cowsRemaining -= rooms[cur];
        }
        minD = min(minD, total);
    }

    fout << minD;
}