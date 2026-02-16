#include <bits/stdc++.h>
using namespace std;

ifstream fin("bcs.in"); 
ofstream fout("bcs.out");

int main() {
    int n, k;
    fin >> n >> k;

    vector<vector<char>> matrix(n, vector<char>(n));
    vector<vector<vector<char>>> kMat(k, vector<vector<char>>(n, vector<char>(n)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> matrix[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int c = 0; c < n; c++) {
                fin >> kMat[i][j][c];
            }
        }
    }

    for (int p1 = 0; p1 < k; p1++) {
        for (int p2 = p1 + 1; p2 < k; p2++) {

            vector<vector<char>> piece1 = kMat[p1];
            vector<vector<char>> piece2 = kMat[p2];

            for (int x1 = -n + 1; x1 < n; x1++) {
                for (int y1 = -n + 1; y1 < n; y1++) {

                    bool ok1 = true;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (piece1[i][j] == '#') {
                                if (i + x1 < 0 || i + x1 >= n ||
                                    j + y1 < 0 || j + y1 >= n) {
                                    ok1 = false;
                                }
                            }
                        }
                    }
                    if (!ok1) continue;

                    for (int x2 = -n + 1; x2 < n; x2++) {
                        for (int y2 = -n + 1; y2 < n; y2++) {

                            bool ok2 = true;
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < n; j++) {
                                    if (piece2[i][j] == '#') {
                                        if (i + x2 < 0 || i + x2 >= n ||
                                            j + y2 < 0 || j + y2 >= n) {
                                            ok2 = false;
                                        }
                                    }
                                }
                            }
                            if (!ok2) continue;

                            vector<vector<char>> combined(n, vector<char>(n, '.'));
                            bool valid = true;

                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < n; j++) {
                                    if (piece1[i][j] == '#') {
                                        combined[i + x1][j + y1] = '#';
                                    }
                                }
                            }

                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < n; j++) {
                                    if (piece2[i][j] == '#') {
                                        if (combined[i + x2][j + y2] == '#') {
                                            valid = false;
                                        }
                                        combined[i + x2][j + y2] = '#';
                                    }
                                }
                            }

                            if (!valid) continue;

                            if (combined == matrix) {
                                fout << p1 + 1 << " " << p2 + 1 << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
