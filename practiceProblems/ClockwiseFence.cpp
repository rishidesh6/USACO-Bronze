#include <bits/stdc++.h>
using namespace std;

int n;

bool fenceRight(int x, int y, char dir, vector<vector<int>>& a) {

    if (x < 0 || x >= 200 || y < 0 || y >= 200) return false;

    if (dir == 'N') {
        if (y + 1 >= 200) return false;
        if (a[x][y + 1] == 1) return true;
        return fenceRight(x - 1, y, dir, a);
    }
    else if (dir == 'S') {
        if (y - 1 < 0) return false;
        if (a[x][y - 1] == 1) return true;
        return fenceRight(x + 1, y, dir, a);
    }
    else if (dir == 'E') {
        if (x + 1 >= 200) return false;
        if (a[x + 1][y] == 1) return true;
        return fenceRight(x, y + 1, dir, a);
    }
    else {
        if (x - 1 < 0) return false;
        if (a[x - 1][y] == 1) return true;
        return fenceRight(x, y - 1, dir, a);
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {

        vector<vector<int>> matrix(200, vector<int>(200, 0));

        string path;
        cin >> path;

        int posX = 100;
        int posY = 100;

        matrix[posX][posY] = 1;

        for (int j = 0; j < (int)path.size(); j++) {
            if (path[j] == 'W') posY--;
            else if (path[j] == 'E') posY++;
            else if (path[j] == 'N') posX--;
            else posX++;

            matrix[posX][posY] = 1;
        }

        bool cc = false;
        
        posX = 100; 
        posY = 100;

        for (int j = 0; j < (int)path.size(); j++) {

            bool answer = fenceRight(posX, posY, path[j], matrix);
            if (!answer) {
                cc = true;
                break;
            }

            if (path[j] == 'W') posY--;
            else if (path[j] == 'E') posY++;
            else if (path[j] == 'N') posX--;
            else posX++;
        }

        if (cc) cout << "CCW" << endl;
        else cout << "CW" << endl;
    }
}
