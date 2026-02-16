#include <bits/stdc++.h>
using namespace std;

string cowphabet;
string heard;

int main() {
    cin >> cowphabet >> heard;

    bool complete = false;
    int runs = 0;

    int idx = 0;

    while (!complete) {
        for (int i = 0; i < 26; i++) {
            if (cowphabet[i] == heard[idx]) {
                idx++;
                if (idx == heard.size()) {
                    complete = true;
                    break;
                }
            }
        }
        runs++;
    }

    cout << runs;
}