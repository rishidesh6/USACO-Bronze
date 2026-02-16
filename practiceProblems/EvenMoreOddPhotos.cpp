#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    int evens = 0;
    int odds = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            evens++;
        } else {
            odds++;
        }
        numbers.push_back(x);
    }

    bool completed = false;
    string cur = "Even";

    int groups = 0;

    while (!completed) {
        if (cur == "Even") {
            if (evens > 0) {
                evens--;
                groups++;
            } else if (odds >= 2) {
                odds-=2;
                groups++;
            } else {
                completed = true;
            }

            cur = "Odd";
        } else {
            if (odds > 0) {
                odds--;
                groups++;
            } else {
                completed = true;
            }

            cur = "Even";
        }
    }

    if (odds > 0) {
        groups -= odds;
    }

    cout << groups;
}