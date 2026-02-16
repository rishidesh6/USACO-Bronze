#include <bits/stdc++.h>
using namespace std;

ifstream fin("billboard.in"); 
ofstream fout("billboard.out");

int areaOverlap(int abx, int aby, int cbx, int cby, int atx, int aty, int ctx, int cty) {
    if (ctx < abx || cty < aby || atx > cby || aty > cby) {
        return 0;
    } else {
        int minCX = INT_MAX; int minCY = INT_MAX;
        minCX = min(cbx, ctx); minCY = min(cby, cty);
        int maxAX = INT_MAX; int maxAY = INT_MAX;
        maxAX = max(abx, atx); maxAY = max(aby, aty);

        int yDiff = minCY - maxAY;
        int xDiff = minCX - maxAX;
        return xDiff * yDiff;
    }
}

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    int xT, yT, xT2, yT2;

    fin >> x1 >> y1 >> x2 >> y2;
    fin >> x3 >> y3 >> x4 >> y4;
    fin >> xT >> yT >> xT2 >> yT2;

    int areaB1 = (y2 - y1) * (x2 - x1);
    int areaB2 = (y4 - y3) * (x4 - x3);

    int overlap1 = areaOverlap(x1, y1, x2, y2, xT, yT, xT2, yT2);
    areaB1 -= overlap1;
    int overlap2 = areaOverlap(x3, y3, x4, y4, xT, yT, xT2, yT2);
    areaB2 -= overlap2;

    fout << areaB1 + areaB2;
}