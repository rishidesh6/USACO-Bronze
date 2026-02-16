#include <bits/stdc++.h>
using namespace std;

int n, f;

bool isMoo(const string &s, int i) {
    return (s[i] != s[i + 1] && s[i + 1] == s[i + 2]);
}

int main() {

    cin >> n >> f;
    string contest;
    cin >> contest;
    
    map<string, int> curCount;
    map<string, vector<int>> pos;
    
    for (int i = 0; i + 2 < n; i++) {
        
        if (isMoo(contest, i)) {
            string t = contest.substr(i, 3);
            curCount[t]++;
            pos[t].push_back(i);
        }
        
    }
    
    set<string> result;
    
    for (auto &x : curCount) {
        if (x.second >= f) {
            result.insert(x.first);
        }
    }
    
    for (int i = 0; i + 2 < n; i++) {
        
        string temp = contest.substr(i, 3);
        
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                
                if (a == b) continue;
                string m = {a, b, b};
                
                int diffs = 0;
                if (temp[0] != m[0]) diffs++;
                if (temp[1] != m[1]) diffs++;
                if (temp[2] != m[2]) diffs++;
                if (diffs != 1) continue;
                
                
                int current_count = curCount[m];
                if (current_count != f - 1) continue;
                
                bool mooBreaks = false;
                
                string modified = contest;
                
                for (int k = 0; k < 3; k++) {
                    if (temp[k] != m[k]) {
                        modified[i + k] = m[k];
                        break;
                    }
                }
                
                for (int j = max(0, i - 2); j <= min(n - 3, i + 2); j++) {
                    bool was = isMoo(contest, j);
                    bool now = isMoo(modified, j);
                    
                    if (was && !now) {
                        mooBreaks = true;
                        break;
                    }
                }
                
                if (!mooBreaks) {
                    result.insert(m);
                }
                
            }
        }
        
    }
    
    
    cout << result.size() << endl;
    for (auto &str: result) {
        cout << str << endl;
    }
}