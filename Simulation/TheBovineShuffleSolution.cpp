#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("shuffle.in"); 
    ofstream fout("shuffle.out");

    int n;
    fin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        a.push_back(x);
    }
    vector<string> cows;
    for (int i = 0; i < n; i++) {
        string id;
        fin >> id;
        cows.push_back(id);
    }
    
    vector<string> newArray(n, "");

    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < n; j++) { 
            int pos = j + 1;
            
            for (int k = 0; k < n; k++) {
                
                if (a[k] == pos) {
                    newArray[k] = cows[j];
                }
            }
        }
        
        cows = newArray;
    }

    for (int i = 0; i < n; i++) {
        fout << cows[i] << endl;
    }
}