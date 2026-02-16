#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lostcow.in"); 
    ofstream fout("lostcow.out");

    int x, y;
    fin >> x >> y;

    int num = 1;
    int total = 0;

    for (int i = 0; i < 9; i++) {
        
        if (x + num < x && x + num <= y && y <= x) {
            total += abs(y - x);
            break;
        } else if (x + num > x && x + num >= y && y >= x) {
            total += abs(y - x);
            break;
        }
        
        total += abs(num) + abs(num);
        num *= -2;
    }

    fout << total;
}