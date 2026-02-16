#include <bits/stdc++.h>
using namespace std;

ifstream fin("circlecross.in"); 
ofstream fout("circlecross.out");

int main() {
    string road;
    fin >> road;

    vector<int> start;
    vector<int> end;

    for (int i = 0; i < 26; i++) {
        start.push_back(-1);
        end.push_back(-1);
    }
    
    for (int i = 0; i < 52; i++) {
        if (start[road[i] - 'A'] == -1) {
            start[road[i] - 'A'] = i;
        } else {
            end[road[i] - 'A'] = i;
        }
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]) {
                ans++;
            }
        }
    }
    fout << ans << endl;
}