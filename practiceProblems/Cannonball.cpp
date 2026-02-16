#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> line;
    vector<int> vals;

    bool used[n] = {false};

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        line.push_back(x);
        vals.push_back(y);
    }

    bool done = false;
    
    int pos = s - 1;
    int power = 1;
    int dir = 1;

    int padsRow = 0;
    int targetsBroke = 0;

    while (!done) {
        
        if (pos < 0 || pos > n) {
            done = true;
            break;
        }

        if (line[pos] == 0) {
            
            if (vals[pos] == 0) {
                padsRow++;
            } else {
                padsRow = 0;
            }

            if (padsRow == 2) {
                done = true;
                break;
            }

            dir *= -1;
            power += vals[pos];

            pos += (power * dir);
            
        } else {
            
            if (power >= vals[pos] && !used[pos]) {
                targetsBroke++;
                used[pos] = true;
            }
            pos += (power * dir);
        }

    }

    cout << targetsBroke << endl;
}