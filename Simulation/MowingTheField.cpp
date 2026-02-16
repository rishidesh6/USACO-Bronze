#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("mowing.in"); 
    ofstream fout("mowing.out");

    int n;
    fin >> n;

    vector<vector<int>> matrix(2001, vector<int>(2001, 0));
    vector<vector<int>> lastTimeVisited(2001, vector<int> (2001, 0));

    int curX = 1001;
    int curY = 1001;
    matrix[curX][curY] = 1;
    lastTimeVisited[curX][curY] = 0;

    int minTimeAllowed = INT_MAX;
    int curT = 0;

    for (int i = 0; i < n; i++) {

        char d;
        int s;
        fin >> d >> s;

        for (int j = 0; j < s; j++) {
            curT++;
            if (d == 'N') {
                curY--;
            } else if (d == 'S') {
                curY++;
            } else if (d == 'W') {
                curX--;
            } else {
                curX++;
            }

            if (matrix[curX][curY] == 0) {
                matrix[curX][curY] = 1;
                lastTimeVisited[curX][curY] = curT;
            } else {
                minTimeAllowed = min(minTimeAllowed, curT - lastTimeVisited[curX][curY]);
                lastTimeVisited[curX][curY] = curT;
            }
        }
    }

    if (minTimeAllowed == INT_MAX) {
        fout << -1;
    } else {
        fout << minTimeAllowed;
    }
}