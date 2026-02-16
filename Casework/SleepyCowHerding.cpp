#include <bits/stdc++.h>
using namespace std;

ifstream fin("herding.in"); 
ofstream fout("herding.out");

int main() {
    int x, y, z;
    fin >> x >> y >> z;

    vector<int> cows = {x, y, z};

    sort(cows.begin(), cows.end());

    int gap1 = cows[1] - cows[0] - 1;
    int gap2 = cows[2] - cows[1] - 1;

    int biggest = max(gap1, gap2);
    int smallest = min(gap1, gap2);

    fout << smallest << endl << biggest;
}