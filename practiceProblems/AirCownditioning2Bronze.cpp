#include <bits/stdc++.h>
using namespace std;

struct con {
    int first;
    int second;
    int third; 
    int fourth;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coolage(100, 0);
    vector<bool> used(100, false);

    vector<con> conditioners(m);

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        for (int j = x - 1; j < y - 1; j++) {
            used[j] = true;
            coolage[j] = (-1 * z);
        }
    }

    int money = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        conditioners[i] = {a - 1, b - 1, c, d};
    }
    
    sort(conditioners.begin(), conditioners.end(), [](const con& a, const con& b) {
        return a.fourth < b.fourth;
    });
    
    vector<bool> done(m, false);
    
    for (int i = 0; i < coolage.size(); i++) {
        if (!used[i]) continue;
        bool iComplete = false;
        vector<int> temp = coolage;
        
        for (int j = 0; j < m; j++) {
            if (done[j]) continue;
            if (temp[i] >= 0) {
                iComplete = true;
                break;
            }
            if (!(conditioners[j].first <= i && conditioners[j].second >= i)) continue;
            
            for (int k = conditioners[j].first; k < conditioners[j].second; k++) {
                if (!used[k]) continue;
                temp[k] += conditioners[j].third;
            }
            
            done[j] = true;
            money += conditioners[j].fourth;
        }
        
        coolage = temp;
    }

    cout << money;
}