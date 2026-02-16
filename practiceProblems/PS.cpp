#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ogOdds = 0;
    vector<char> str;

    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if ((i + 1) % 2 == 1 && x == 'G') {
            ogOdds++;
        }
        str.push_back(x);
    }
    

    int numOdds = 0;
    int numEven = 0;
    vector<int> diffs;
    vector<int> oddsAtJ;

    for (int i = 1; i <= n; i += 2) {
        if (str[i - 1] == 'G') {
            numOdds++;
        }
        if (str[i] == 'G') {
            numEven++;
        }

        int diff = numOdds - numEven;
        diffs.push_back(diff);
        oddsAtJ.push_back(numOdds);
    }

    auto it = max_element(diffs.begin(), diffs.end());
    int d = distance(diffs.begin(), it);

    if (*it <= 0) {
        cout << 0 << endl;
    } else {
        int total = 1;
        cout << total << endl;
    }
}