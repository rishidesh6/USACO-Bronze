#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<vector<int>>> scores(n, vector<vector<int>>(n, vector<int>(n, 0)));
    
    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;
        scores[x][min(y, z)][max(y, z)]++;
    }
    
    int maxScore = 0;
    int numBoards = 0;
    
    for (int i = 0; i < (1 << n); i++) {
        int score = 0;
        vector<int> ms; vector<int> os;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                ms.push_back(j);
            } else {
                os.push_back(j);
            }
        }

        for (int m: ms) {
            for (int k = 0; k < os.size(); k++) {
                for (int l = k + 1; l < os.size(); l++) {
                    score += scores[m][os[k]][os[l]];
                }
            }
        }

        if (score > maxScore) {
            maxScore = score;
            numBoards = 1;
        } else if (score == maxScore) {
            numBoards++;
        }
    }
    
    cout << maxScore << ' ' << numBoards;
}