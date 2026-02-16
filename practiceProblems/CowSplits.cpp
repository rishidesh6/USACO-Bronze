#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, k;
    cin >> t >> k;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        vector<int> places((n * 3), 0);
        if (n % 2 == 1) {
            cout << -1 << endl;
            continue;
        } else if (s.substr(0, (n * 3)/2) == s.substr((n * 3)/2, (n * 3) - (n * 3)/2)) {
            cout << 1 << endl;
            for (int i = 0; i < (n * 3); i++) {
                if (i == (n * 3)-1) {
                    cout << 1 << endl;
                } else {
                    cout << 1 << ' ';
                }
            }
            continue;
        } else {
            for (int i = 0; i < (n * 3)/2; i += 3) {
                string curString1 = s.substr(i, 3);
                string curString2 = s.substr(i + (n * 3)/2, 3);

                if (curString1 == "COW") {
                    if (curString2 == "OWC") {
                        places[i] = 2; places[i + 1] = 1; places[i + 2] = 1;
                        places[i + (n * 3)/2] = 1; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 2;
                    } else if (curString2 == "WCO") {
                        places[i] = 1; places[i + 1] = 1; places[i + 2] = 2;
                        places[i + (n * 3)/2] = 2; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 1;
                    } else {
                        places[i] = 1; places[i + 1] = 1; places[i + 2] = 1;
                        places[i + (n * 3)/2] = 1; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 1;
                    }
                } else if (curString1 == "OWC") {
                    if (curString2 == "COW") {
                        places[i] = 1; places[i + 1] = 1; places[i + 2] = 2;
                        places[i + (n * 3)/2] = 2; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 1;
                    } else if (curString2 == "WCO") {
                        places[i] = 2; places[i + 1] = 1; places[i + 2] = 1;
                        places[i + (n * 3)/2] = 1; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 2;
                    } else {
                        places[i] = 1; places[i + 1] = 1; places[i + 2] = 1;
                        places[i + (n * 3)/2] = 1; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 1;
                    }
                } else {
                    if (curString2 == "COW") {
                        places[i] = 2; places[i + 1] = 1; places[i + 2] = 1;
                        places[i + (n * 3)/2] = 1; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 2;
                    } else if (curString2 == "OWC") {
                        places[i] = 1; places[i + 1] = 1; places[i + 2] = 2;
                        places[i + (n * 3)/2] = 2; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 1;
                    } else {
                        places[i] = 1; places[i + 1] = 1; places[i + 2] = 1;
                        places[i + (n * 3)/2] = 1; places[i + (n * 3)/2 + 1] = 1; places[i + (n * 3)/2 + 2] = 1;
                    }
                }
            }
            cout << 2 << endl;
            for (int i = 0; i < (n * 3); i++) {
                if (i == (n * 3) - 1) {
                    cout << places[i] << endl;
                } else {
                    cout << places[i] << ' ';
                }
            }
            continue;
        }
    }
}