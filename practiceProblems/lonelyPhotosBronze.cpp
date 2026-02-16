#include <bits/stdc++.h>
using namespace std;

int n;
string cows;

int main() {

    cin >> n >> cows;

    int photos = 0;

    for (int i = 0; i < n; i++) {

        int H = 0; int G = 0; int count = 0;


        for (int j = i; j < n; j++) {
            
            if (cows[j] == 'H') {
                H++;
            } else {
                G++;
            }
            
            int count = j - i + 1;
            if (count >= 3) {
                if ((H == 1 && G >= 2) || (G == 1 && H >= 2)) {
                    photos += 1;
                }
            }
        }
    }
    
    cout << photos;
}