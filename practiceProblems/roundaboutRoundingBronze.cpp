#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;
    long long x;
    while (cin >> x) {
        long long curFour = 45;
        long long curFive = 5;
        long long total = 0;

        for (int i = 0; i < 15; i++) {

            if (x < curFour) {
                break;
            } else if (x - (curFour + curFive) < 0) {
                total += (x - (curFour + curFive) + 1);
                total += curFive;
                break;
            }
            total += curFive;

            curFive = (curFive * 10) + 5;
            curFour = (curFour * 10) - 5;
        }

        cout << total << endl;
    }
}