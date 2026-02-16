#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lifeguards.in"); 
    ofstream fout("lifeguards.out");

    int n;
    fin >> n;

    vector<int> numLine(1001, 0);
    int minNonOverlap = INT_MAX;
    int totalSpotsTaken = 0;
    
    vector<int> xs;
    vector<int> ys;
    
    vector<int> numCows(1001, 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        xs.push_back(x); ys.push_back(y);
        
        for (int j = x - 1; j < y - 1; j++) {
            if (numLine[j] == 0) {
                totalSpotsTaken++;
                numLine[j] = 1;
                numCows[j]++;
            } else {
                numCows[j]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        
        int nonOverlap = 0;
        int x = xs[i];
        int y = ys[i];
        
        for (int j = x - 1; j < y - 1; j++) {
            if (numCows[j] == 1) {
                nonOverlap++;
            }
        }
        
        minNonOverlap = min(minNonOverlap, nonOverlap);
    }

    fout << totalSpotsTaken - minNonOverlap;
}