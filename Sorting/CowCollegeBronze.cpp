#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cows[i] = x;
    }

    sort(cows.begin(), cows.end());

    int maxPrice = 0;
    int price = 0;

    for (int i = 0; i < n; i++) {
        
        if (max(maxPrice, cows[i] * (n - i)) == (cows[i] * (n - i))) {
            
            if (price > cows[i] && maxPrice == cows[i] * (n - i)) {
                price = cows[i];
            } else if (!(price > cows[i]) && maxPrice == cows[i] * (n - i)) { 
                maxPrice = max(maxPrice, cows[i] * (n - i));
            } else {
                maxPrice = max(maxPrice, cows[i] * (n - i));
                price = cows[i];
            }

        }
        
    }

    cout << maxPrice << ' ' << price;
}