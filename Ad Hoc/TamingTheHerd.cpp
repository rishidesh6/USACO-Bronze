#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream fin("taming.in"); 
    ofstream fout("taming.out");

    int n;
    fin >> n;

    vector<int> nums;
    int breakouts = 0;
    int negatives = 0;

    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        if (i == 0) {
            nums.push_back(0);
            breakouts++;
        } else {
            nums.push_back(x);
            if (nums[i] > 0) {
                for (int j = x; j >= 0; j--) {
                    nums[i - (x - j)] = j;
                    if (j == 0) {
                        breakouts++;
                    }
                }
            } else if (nums[i] == 0) {
                breakouts++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            negatives++;
        }
    }

    fout << breakouts << ' ' << negatives + breakouts;
}