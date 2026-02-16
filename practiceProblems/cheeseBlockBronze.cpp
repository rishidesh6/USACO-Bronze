#include <iostream>
#include <vector>
using namespace std;

int n, q;

int main() {
    cin >> n >> q;

    vector<vector<int>> xy(n, vector<int> (n));
    vector<vector<int>> xz(n, vector<int> (n));
    vector<vector<int>> yz(n, vector<int> (n));

    int total = 0;

    for (int i = q; i > 0; i--) {

        int x, y, z;
        cin >> x >> y >> z;

        xy[x][y] += 1;
        if (xy[x][y] == n) {
            total += 1;
        }
        xz[x][z] += 1;
        if (xz[x][z] == n) {
            total += 1;
        }
        yz[y][z] += 1;
        if (yz[y][z] == n) {
            total += 1;
        }

        cout << total << endl;
    }

}