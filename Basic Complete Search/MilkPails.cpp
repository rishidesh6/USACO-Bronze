#include <bits/stdc++.h>
using namespace std;

int x, y, m;

ifstream fin("pails.in"); 
ofstream fout("pails.out");

int main() {

    fin >> x >> y >> m;
    int total = 0;
    int minZ = INT_MAX;

    for (int i = 0; i <= (m/x); i++) {
        total += x * i;
        int left = m - total;
        int z = left % y;
        minZ = min(minZ, z);
        total = 0;
    }

    fout << m - minZ;
}