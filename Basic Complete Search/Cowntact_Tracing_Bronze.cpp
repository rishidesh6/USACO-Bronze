#include <bits/stdc++.h>
using namespace std;

ifstream fin("tracing.in"); 
ofstream fout("tracing.out");


struct triple{
    int t;
    int cowX;
    int cowY;
};

int main() {

    int N, T;

    fin >> N >> T;
    string cows;
    fin >> cows;
    
    vector<triple> inp;
    
    for (int i = 0; i < T; i++) {
        int t, x, y;
        fin >> t >> x >> y;
        inp.push_back({t, x, y});
    }
    
    sort(inp.begin(), inp.end(), [](const triple& a, const triple& b) {
        return a.t < b.t;
    });
    
    set<int> validP0;
    int minK = INT_MAX;
    int maxK = -1;
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= 250; k++) {
            
            bool infected[N] = {false};
            int remainingInfections[N] = {0};
            infected[i] = true;
            remainingInfections[i] = k;
            
            for (const triple& a: inp) {
                int curX = a.cowX;
                int curY = a.cowY;
                
                if (infected[curX - 1] && remainingInfections[curX - 1] > 0 && !infected[curY - 1]) {
                    infected[curY - 1] = true;
                    remainingInfections[curY - 1] = k;
                    remainingInfections[curX - 1] -= 1;
                }
                
                if (infected[curY - 1] && remainingInfections[curY - 1] > 0 && !infected[curX - 1]) {
                    infected[curX - 1] = true;
                    remainingInfections[curX - 1] = k;
                    remainingInfections[curY - 1] -= 1;
                }
            }
            bool match = true;
            for (int j = 0; j < N; j++) {
                if ((infected[j] && cows[j] == '0') || (!infected[j] && cows[j] == '1')) {
                    match = false;
                    break;
                }
            }
            if (match) {
                validP0.insert(i + 1);
                minK = min(minK, k);
                maxK = max(maxK, k);
            }
        }
    }
    
    int x = validP0.size();
    int y = minK;
    
    fout << x << ' ';
    if (y == INT_MAX) {
        fout << '0' << ' ';
    } else {
        fout << y << ' ';
    }
    if (maxK == 250) {
        fout << "Infinity"; 
    } else {
        fout << maxK;
    }
    
}