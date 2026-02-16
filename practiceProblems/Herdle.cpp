#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> answer;
    map<char, int> guess;

    vector<vector<char>> a(3, vector<char> (3, ' '));
    char g[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char A;
            cin >> A;
            a[i][j] = A;
            answer[A]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char A;
            cin >> A;
            g[i][j] = A;
            guess[A]++;
        }
    }

    int green = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == g[i][j]) {
                green++;
                answer[a[i][j]]--;
                guess[g[i][j]]--;
            }
        }
    }

    int yellow = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (answer[g[i][j]] >= 1 && a[i][j] != g[i][j]) {
                yellow++;
                answer[g[i][j]]--;
            }
        }
    }

    cout << green << endl << yellow;

}