#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << "YES" << endl;
            continue;
        }

        string nums = "";
        int segments = 0;
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            nums += x;
            if (i == 0) {
                segments++;
            } else {
                if (nums[i - 1] != x) {
                    segments++;
                }
            }
        }

        if (segments <= k) {
            cout << "YES" << endl;
            continue;
        }

        int midpoint = n/2;
        string firstHalf = nums.substr(0, midpoint);
        string secondHalf = nums.substr(midpoint);

        if (k == 2) {
            if (firstHalf == secondHalf) {
                cout << "YES" << endl;
                continue;
            } else {
                cout << "NO" << endl;
                continue;
            }
        } else if (k == 3) {
            if (firstHalf == secondHalf) {
                cout << "YES" << endl;
                continue;
            }
        }
        bool solved = false;
        bool neverStarted1 = true;
        bool neverStarted2 = true;
        
        for (int i = 0; i < n; i++) {
            int mid1 = i / 2;
            string h1 = nums.substr(0, mid1);
            string h2 = nums.substr(mid1, mid1);
        
            string h3 = nums.substr(i, (n - i) / 2);
            string h4 = nums.substr(i + (n - i) / 2);
        
            bool same = false;
            bool same2 = false;
        
            if (h1 == h2 && i + 1 < n) {
                same = true;
                for (int j = i + 2; j < n; j++) {
                    neverStarted1 = false;
                    if (nums[j] != nums[j - 1]) {
                        same = false;
                        break;
                    }
                }
            }
            if (h3 == h4 && i - 1 >= 0) {
                same2 = true;
                for (int j = i - 2; j >= 0; j--) {
                    neverStarted2 = false;
                    if (nums[j] != nums[j + 1]) {
                        same2 = false;
                        break;
                    }
                }
            }
        
            if ((same && !neverStarted1) || (same2 && !neverStarted2)) {
                cout << "YES" << endl;
                solved = true;
                break;
            }
        }
        
        if (!solved) {
            cout << "NO" << endl;
        }

    }
}