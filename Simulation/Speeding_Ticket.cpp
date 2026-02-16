#include <bits/stdc++.h>
using namespace std;

ifstream fin("speeding.in"); 
ofstream fout("speeding.out");

int n, m;

vector<int> road;
//vector<int> limits;
vector<int> cow;
//vector<int> speed;


int main() {

    fin >> n >> m;
    int x, y;

    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        for (int j = 0; j < x; j++) {
            road.push_back(y);
        }
    }

    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        for (int j = 0; j < x; j++) {
            cow.push_back(y);
        }
    }

    int maximum = 0;
    for (int i = 0; i < 100; i++) {
        if (cow[i] > road[i]) {
            maximum = max(maximum, (cow[i] - road[i]));
        }
    }

    fout << maximum;
}