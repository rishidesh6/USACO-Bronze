#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(1000, vector<int>(1000, 0));
    vector<vector<int>> adjacents(1000, vector<int>(1000, 0));

    int comfyCows = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x][y] = 1;

        if (x < 1000 && matrix[x + 1][y] == 1) {
            adjacents[x + 1][y]++;
            adjacents[x][y]++;
            if (adjacents[x + 1][y] == 3) {
                comfyCows++;
            } else if (adjacents[x + 1][y] == 4) {
                comfyCows--;
            }
            
        }
        if (x > 0 && matrix[x - 1][y] == 1) {
            adjacents[x - 1][y]++;
            adjacents[x][y]++;
            if (adjacents[x - 1][y] == 3) {
                comfyCows++;
            } else if (adjacents[x - 1][y] == 4) {
                comfyCows--;
            }

        }
        if (y < 1000 && matrix[x][y + 1] == 1) {
            adjacents[x][y + 1]++;
            adjacents[x][y]++;
            if (adjacents[x][y + 1] == 3) {
                comfyCows++;
            } else if (adjacents[x][y + 1] == 4) {
                comfyCows--;
            }
        }
        if (y > 0 && matrix[x][y - 1] == 1) {
            adjacents[x][y - 1]++;
            adjacents[x][y]++;
            if (adjacents[x][y - 1] == 3) {
                comfyCows++;
            } else if (adjacents[x][y - 1] == 4) {
                comfyCows--;
            }
        }

        if (adjacents[x][y] == 3) {
            comfyCows--;
        }

        cout << comfyCows << endl;
    }


}