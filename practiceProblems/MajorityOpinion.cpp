#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<int> hays;
        map <int, vector<int>> occurences;
        vector<int> validHays;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            hays.push_back(x);
            occurences[x].push_back(i);

            if (occurences[x].size() > 1 && occurences[x][occurences[x].size() - 1] - occurences[x][occurences[x].size() - 2] <= 2) {
                if (!count(validHays.begin(), validHays.end(), x)) {
                    validHays.push_back(x);
                }
            }
        }

        if (validHays.size() == 0) {
            cout << -1 << endl; 
        } else {
            sort(validHays.begin(), validHays.end());
            for (int i = 0; i < validHays.size(); i++) {
                if (i != validHays.size() - 1) {
                    cout << validHays[i] << ' ';
                } else {
                    cout << validHays[i];
                }
            }
            cout << endl;
        }
    }
}