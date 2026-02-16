#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, u;

int symmetries(int n, int x, int y, vector<vector<char>>& matrix) {

    vector<pair<int, int>> points = {{x, y}, {x, n - y - 1}, {n - x - 1, y}, {n - x - 1, n - y - 1}};
    int countA = 0;
    int countB = 0;

    for (int i = 0; i < 4; i++) {
        if (matrix[points[i].first][points[i].second] == '.') {
            countA++;
        } else {
            countB++;
        }
    }

    return min(countA, countB);
}


int main() {

    cin >> n >> u;
    vector<vector<char>> matrix(n, vector<char>(n));


    char x;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cin >> x;
            matrix[i][j] = x;
        }

    }
    

    int count = 0;

    for (int i = 0; i < n/2; i++) {
        for (int j = n/2; j < n; j++) {
            count += symmetries(n, i, j, matrix);
        }
    }

    cout << count << endl;

    for (int i = u; i > 0; i--) {
        int x, y;
        cin >> x >> y;
        
        x--; y--;

        count -= symmetries(n, x, y, matrix);
        if (matrix[x][y] == '.') {
            matrix[x][y] = '#';
        } else {
            matrix[x][y] = '.';
        }
        count += symmetries(n, x, y, matrix);
        cout << count << endl;
    }
}