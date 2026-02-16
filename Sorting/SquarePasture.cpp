#include <bits/stdc++.h>
using namespace std;

ifstream fin("square.in"); 
ofstream fout("square.out");

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    fin >> x1 >> y1 >> x2 >> y2;
    fin >> x3 >> y3 >> x4 >> y4;

    int minX = min({x1, x2, x3, x4});
    int maxX = max({x1, x2, x3, x4});

    int minY = min({y1, y2, y3, y4});
    int maxY = max({y1, y2, y3, y4});

    fout << pow(max(maxY - minY, maxX - minX), 2);
}