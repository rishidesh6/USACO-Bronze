#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    int x;
    
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
    }
    
    int y; 
    for (int i = 0; i < n; i++) {
        cin >> y;
        b[i] = y;
    }
    
    int before = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) before++;
    }
    
    vector<int> answer(n + 1, 0);
    
    auto sol = [&](int l, int r) {
        int base = before;
        
        while (l >= 0 && r < n) {
            
            if (a[l] == b[l]) {
                base--;
            }
            if (a[r] == b[r]) {
                base--;
            }
            
            if (a[l] == b[r]) {
                base++;
            }
            if (a[r] == b[l]) {
                base++;
            }
            
            answer[base]++;

            l--;
            r++;
        }
    };
    
    for (int i = 0; i < n; i++) {
        sol(i, i);
    }
    for (int i = 0; i < n - 1; i++) {
        sol(i, i + 1);
    }
    
    for (int i = 0; i <= n; i++) {
        cout << answer[i] << endl;
    }
}