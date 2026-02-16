#include <bits/stdc++.h>
using namespace std;

struct Interactions {
    int time;
    int cow1;
    int cow2;
};

int main() {
    ifstream fin("tracing.in"); 
    ofstream fout("tracing.out");

    int n, T;
    fin >> n >> T;
    string cows;
    fin >> cows;

    vector<Interactions> events;
    for (int i = 0; i < T; i++) {
        int t, x, y;
        fin >> t >> x >> y;

        events.push_back({t, x - 1, y - 1});
    }

    sort(events.begin(), events.end(), [](const Interactions& a, const Interactions& b) {
        return a.time < b.time;
    });

    int minK = INT_MAX; int maxK = -1;
    set<int> potentialCows;
    vector<bool> yes(n, false);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= T; k++) {
            vector<int> infectionsLeft(n, k);
            vector<bool> infected(n, false);
            infected[i] = true;

            for (int j = 0; j < T; j++) {
                int cow1 = events[j].cow1;
                int cow2 = events[j].cow2;
                bool aWasInfected = infected[cow1];
                bool bWasInfected = infected[cow2];

                if (aWasInfected && infectionsLeft[cow1] > 0) {
                    infectionsLeft[cow1]--;
                    if (!infected[cow2]) {
                        infected[cow2] = true;
                    }
                }

                if (bWasInfected && infectionsLeft[cow2] > 0) {
                    infectionsLeft[cow2]--;
                    if (!infected[cow1]) {
                        infected[cow1] = true;
                    }
                }
            }

            string bitStr = "";
            for (int l = 0; l < n; l++) {
                if (infected[l]) {
                    bitStr += "1";
                } else {
                    bitStr += "0";
                }
            }
            if (bitStr == cows) {
                minK = min(minK, k);
                maxK = max(maxK, k);
                potentialCows.insert(i);
            }
        }
    }

    fout << potentialCows.size() << ' ';
    if (minK == INT_MAX) {
        fout << 0 << ' ';
    } else {
        fout << minK << ' ';
    }

    if (maxK == T) {
        fout << "Infinity";
    } else {
        fout << maxK;
    }

}