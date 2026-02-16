#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("guess.in"); 
    ofstream fout("guess.out");

    int n;
    fin >> n;

    vector<vector<string>> animals(n);
    vector<int> characteristics(n, 0);

    for (int i = 0; i < n; i++) {
        string animal; int c;
        fin >> animal >> c;
        characteristics[i] = c;

        for (int j = 0; j < c; j++) {
            string m;
            fin >> m;
            animals[i].push_back(m);
        }
    }

    int maxOverlap = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            int same = 0;
            for (int k = 0; k < characteristics[i]; k++) {
                for (int l = 0; l < characteristics[j]; l++) {
                    
                    string c1 = animals[i][k];
                    string c2 = animals[j][l];
                    
                    if (c1 == c2) {
                        same++;
                    }
                }
            }
            maxOverlap = max(maxOverlap, same);
        }
    }

    fout << maxOverlap + 1;
}