#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("shell.in"); 
    ofstream fout("shell.out");

    int n;
    fin >> n;

    
    int shellPlace = 0;

    vector<int> swap1;
    vector<int> swap2;
    vector<int> guess;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        fin >> x >> y >> z;
        swap1.push_back(x); swap2.push_back(y); guess.push_back(z);
    }

    int ans = 0;

    for (int i = 0; i < 3; i++) {
        
        shellPlace = i;
        int points = 0;
        
        for (int j = 0; j < n; j++) {
            if (swap1[j] - 1 == shellPlace) {
                shellPlace = swap2[j] - 1;
            } else if (swap2[j] - 1 == shellPlace) {
                shellPlace = swap1[j] - 1;
            }
            
            if (guess[j] - 1 == shellPlace) {
                points++;
            }
        }

        ans = max(ans, points);
    }

    fout << ans;
}