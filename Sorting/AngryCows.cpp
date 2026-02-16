#include <bits/stdc++.h>
using namespace std;

ifstream fin("angry.in"); 
ofstream fout("angry.out");

int main() {
    int n;
    fin >> n;

    vector<int> a;
    int maxX = 0;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        a.push_back(x);
        maxX = max(maxX, x);
    }

    sort(a.begin(), a.end());
    vector<int> numberLine(maxX, 0);
    for (int i = 0; i < n; i++) {
        numberLine[a[i] - 1] = a[i] - 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        
        int cur = a[i] - 1;
        int p1 = cur;
        int p2 = cur;
        bool p1Done = false;
        bool p2Done = false;

        for (int T = 1; T <= 100; T++) {
            p1 = cur - T;
            p2 = cur + T;
            
            if (p1 < 0) {
                p1Done = true;
            } else if (numberLine[p1] == 0) {
                p1Done = true;
            }
            for (int j = p1; j < cur; j++) {
                if (p1Done) break;
                if (numberLine[j] != 0) {
                    p1 = j;
                    break;
                }
            }
            
            if (p2 >= maxX) {
                p2Done = true;
            } else if (numberLine[p2] == 0) {
                p2Done = true;
            }
            for (int j = p2; j > cur; j--) {
                if (p2Done) break;
                if (numberLine[j] != 0) {
                    p2 = j;
                    break;
                }
            }
            
            if (p1Done && p2Done) break;
        }
        int exploded = 0;
        for (int j = max(p1, 0); j <= min(p2, maxX - 1); j++) {
            if (numberLine[j] != 0) {
                exploded++;
            }
        }
        ans = max(ans, exploded);
    }
    
    fout << ans;
}