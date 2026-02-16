#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string contest;
    cin >> contest;

    vector<int> positions[26];
    for (int i = 0; i < n; i++) {
        positions[contest[i] - 'a'].push_back(i);
    }

    for (int x = 0; x < q; x++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        long long maxVal = -1;

        for (int j = l; j <= r; j++) {
            char middle = contest[j];

            int farLeft = -1;
            if (j > l) {
                if (contest[l] != middle) {
                    farLeft = l;
                } else {
                    for (int i = l + 1; i < j; i++) {
                        if (contest[i] != middle) {
                            farLeft = i;
                            break;
                        }
                    }
                }

            }

            if (farLeft == -1) continue;

            auto& copy = positions[middle - 'a'];

            auto it = lower_bound(copy.begin(), copy.end(), j + 1);

            int rightMost = -1;
            if (it != copy.end() && *it <= r) {
                auto it2 = upper_bound(copy.begin(), copy.end(), r);
                it2--;
                rightMost = *it2;
            }
            if (rightMost == -1) continue;

            long long left = j - farLeft;
            long long right = rightMost - j;
            maxVal = max(maxVal, left * right);
        }

        cout << maxVal << endl;
    }
}