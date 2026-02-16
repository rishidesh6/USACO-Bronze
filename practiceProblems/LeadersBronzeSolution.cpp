#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<char> breeds;
    int GStart = -1;
    int GEnd = 0;
    int HStart = -1;
    int HEnd = 0;

    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == 'G' && GStart == -1) {
            GStart = i;
        } else if (x == 'G') {
            GEnd = i;
        } else if (x == 'H' && HStart == -1) {
            HStart = i;
        } else {
            HEnd = i;
        }
        breeds.push_back(x);
    }

    vector<int> leaders;
    vector<int> cows;
    vector<bool> isLeader(n, false);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (breeds[i] == 'G') {
            if (i <= GStart && x - 1 >= GEnd) {
                leaders.push_back(i);
                isLeader[i] = true;
            }
        } else {
            if (i <= HStart && x - 1 >= HEnd) {
                leaders.push_back(i);
                isLeader[i] = true;
            }
        }
        cows.push_back(x);
    }

    int pairs = 0;

    for (int i = 0; i < leaders.size(); i++) {
        for (int j = 0; j < leaders[i]; j++) {
            
            if (cows[j] - 1 < leaders[i] && !isLeader[j]) continue;
            pairs++;
        }
    }

    cout << pairs;
}