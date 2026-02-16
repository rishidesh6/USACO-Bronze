#include <iostream>
#include <utility>
#include <list>
using namespace std;

int n;
long long big = 10000000001;

struct ItemData {
    int x;
    int y;
    int cowNum;
};

struct meet{
    int time;
    int cow1;
    int cow2;
}

list<ItemData> NCows;

list<ItemData> Ecows;

int main() {
    cin >> n;

    char dir;
    int x, y;
 
    for (int i = 0; i < n; i++) {
        cin >> dir >> x >> y;

        if (dir == 'N') {
            NCows.push_back(x, y, i);
        }
        if (dir == 'E') {
            ECows.push_back(x, y, i);
        }
    }

    list<meet> meetTimes;

    for (nCow: NCows) {
        for (eCow: ECows) {

            int xTime = nCow.x - eCow.x;
            int yTime = eCow.y - nCow.y;

            if (xTime == yTime) {
                continue;
            }

            if (xTime > yTime && yTime > 0) {
                meetTimes.push_back(xTime, eCow.cowNum, nCow.cowNum);
            }
            if (yTime > xTime && xTime > 0) {
                meetTimes.push_back(yTime, nCow.cowNum, eCow.cowNum);
            }
        }
    }

    meetTimes.sort();

    int ans[n] = {big};

    for (meetTime: meetTimes) {
        if (ans[meetTime.cow2] == big && ans[meetTime.cow1] == big) {
            ans[meetTime.cow1] = meetTime.time;
        }
    }
}