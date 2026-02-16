#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int T = 0; T < t; T++) {
        int n;
        cin >> n;

        vector<int> nums;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums.push_back(x);
            sum += x;
        }

        for (int hours = 0; hours <= sum; hours++) {
            if (hours != 0 && sum % hours != 0) continue;
        

            bool works = true;
            int cur = 0;
            for (int val: nums) {
                cur += val;
                if (cur > hours) {
                    works = false;
                    break;
                }
                if (cur == hours) {
                    cur = 0;
                }
            }
    
            if (works) {
                if (hours == 0) {
                    cout << 0 << endl;
                } else {
                    cout << n - sum/hours << endl;
                }
                break;
            }
        }
    }
}