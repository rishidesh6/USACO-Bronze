#include <bits/stdc++.h>
using namespace std;

ifstream fin("perimeter.in"); 
ofstream fout("perimeter.out");

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<char>>& matrix, vector<vector<bool>>& visited, int& a, int& p, int n) {
    visited[x][y] = true;
    a++;

    for (int d = 0; d < 4; d++) {
        int newX = x + dx[d];
        int newY = y + dy[d];

        if (newX < 0 || newX > n - 1 || newY < 0 || newY > n - 1) {
            p++;
        } else if (matrix[newX][newY] == '.') {
            p++;
        } else {
            if (!visited[newX][newY]) {
                dfs(newX, newY, matrix, visited, a, p, n);
            }
        }
    }
}

int main() {
    int n;
    fin >> n;

    vector<vector<char>> matrix(n, vector<char>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            fin >> x;
            matrix[i][j] = x;
        }
    }

    int bestArea = 0; int bestPerimeter = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && matrix[i][j] == '#') {
                int a = 0; int p = 0;

                dfs(i, j, matrix, visited, a, p, n);
                if (a > bestArea) {
                    bestArea = a;
                    bestPerimeter = p;
                } else if (a == bestArea) {
                    bestPerimeter = min(p, bestPerimeter);
                }
            }
        }
    }

    fout << bestArea << ' ' << bestPerimeter;
    
}