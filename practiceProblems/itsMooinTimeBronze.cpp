#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool isMoo(int a, int b, int c) {
    if (a != b && b == c && a != c) {
        return true;
    }
    return false;
}

bool overlap(const vector<int>& positions, int p) {
    for (int s: positions) {
        if (p >= s && p <= s + 2) {
            return false;
        }
    }

    return true;
}

int n, f;

int main() {

    map<string, int> moos;
    map<string, vector<int>> indexes;
    vector<string> solutions;

    cin >> n >> f;

    string str;

    cin >> str;

    for (int i = 0; i < n - 2; i++) {
        string sub = str.substr(i, 3);
        if (isMoo(sub[0], sub[1], sub[2])) {
            moos[sub]++;
            indexes[sub].push_back(i);
        }
    }

    for (int i = 0; i < n - 2; i++) {

        char cur = str[i];

        for (char j = 'a'; j <= 'z'; j++) {
            string temp = str;
            temp[i] = j;

            if (i >= 2) {

                string moo1 = temp.substr(i - 2, 3);

                if (isMoo(moo1[0], moo1[1], moo1[2])) {
                    int count = 0;
                    for (int p = 0; p < n - 2; p++) {
                        if (temp.substr(p, 3) == moo1) count++;
                    }
                    if (count >= f && find(solutions.begin(), solutions.end(), moo1) == solutions.end()) {
                        solutions.push_back(moo1);
                    }

                }
            }

            string moo2 = temp.substr(i, 3);

            if (isMoo(moo2[0], moo2[1], moo2[2])) {
                int count2 = 0;
                for (int p2 = 0; p2 < n - 2; p2++) {
                    if (temp.substr(p2, 3) == moo2) count2++;
                }
                if (count2 >= f && find(solutions.begin(), solutions.end(), moo2) == solutions.end()) {
                    solutions.push_back(moo2);
                }
            }

            if (i >= 1) {

                string moo3 = temp.substr(i - 1, 3);
                
                if (isMoo(moo3[0], moo3[1], moo3[2])) {
                    int count3 = 0;
                    for (int p3 = 0; p3 < n - 2; p3++) {
                        if (temp.substr(p3, 3) == moo3) count3++;
                    }
                    if (count3 >= f && find(solutions.begin(), solutions.end(), moo3) == solutions.end()) {
                        solutions.push_back(moo3);
                    }
                }
            }

        }
    }

    for (auto& moo: moos) {
        if (moo.second >= f && find(solutions.begin(), solutions.end(), moo.first) == solutions.end()) {
            solutions.push_back(moo.first);
        }
    }

    sort(solutions.begin(), solutions.end());
    cout << solutions.size() << endl;

    for (const auto& solution: solutions) {
        cout << solution << endl;
    }
}