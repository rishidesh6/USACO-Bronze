#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> og;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            og.push_back(x);
        }
        vector<long long> a;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            a.push_back(x);
        }
        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            ans.push_back(x);
        }

        vector<long long> temp = sort(og.begin(), og.end());
        bool invalid = false;

        for (int i = 0; i < n; i++) {
            auto& it = find(og.begin(), og.end(), temp[i]);
            int d = distance(og.begin(), it);
            if (ans[d] != temp[i]) {
                invalid = true;
                break;
            }
        }

        if (!invalid) {
            cout << 0 << endl;
            continue;
        }

        for (int day = 1; day <= n; day++) {

            for (int j = 0; j < n; j++) {
                og[j] += a[j];
            }

            vector<int> temp = sort(og.begin(), og.end());
            invalid = false;

            for (int i = 0; i < n; i++) {
                auto& it = find(og.begin(), og.end(), temp[i]);
                int d = distance(og.begin(), it);
                if (ans[d] != temp[i]) {
                    invalid = true;
                    break;
                }
            }

            if (!invalid) {
                cout << day << endl;
                break;
            }

        }
    }
}