#include <iostream>
#include <string>
using namespace std;

char matrix[1000][1000];
char p1[1000][1000];
char p2[1000][1000];

int t;

int main() {

    cin >> t;
    while (t--) {

        int n, a, b;
        cin >> n >> a >> b;
        string row;
        int count = 0;
        int stars = 0;
        int grays = 0;
        bool covered[1000][1000] = {};

        for (int i = 0; i < n; i++) {

            cin >> row;
            for (int j = 0; j < n; j++) {
                matrix[i][j] = row[j];

                if (row[j] == 'W') {
                    p1[i][j] = '.';
                    p2[i][j] = '.';
                    covered[i][j] = true;
                }

                if (row[j] == 'B') {
                    p1[i][j] = '*';
                    count++;
                    stars++;
                    p2[i][j] = '.';
                }

                if (row[j] == 'G') {
                    p1[i][j] = '?';
                    p2[i][j] = '?';
                    grays++;
                    stars++;
                }

            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] != 'G') {
                    continue;
                }

                if (i - b < 0 || j - a < 0) {
                    p1[i][j] = '*';
                    count++;
                } else {
                    if (!(i + b > n - 1) && !(j + a > n - 1) && (matrix[i + b][j + a] == 'B' || matrix[i + b][j + a] == 'G')) {
                        p1[i][j] = '*';
                        count++;
                    } else {
                        if (matrix[i - b][j - a] == 'W') {
                            p1[i][j] = '*';
                            count++;
                        }
                    }
                }

            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (p1[i][j] != '*') continue;

                int newPosX = i + b;
                int newPosY = j + a;

                if (newPosX > n - 1 || newPosY > n - 1) {
                    covered[i][j] = true;
                }

                if (p2[newPosX][newPosY] == '*') {
                    covered[newPosX][newPosY] = true;
                    continue;
                }

                if (p2[newPosX][newPosY] == '?' || p2[newPosX][newPosY] == '.') {
                    p2[newPosX][newPosX] = '*';
                    covered[newPosX][newPosY] = true;
                }

            }
        }

        bool valid = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (covered[i][j] == false && !(matrix[i][j] == 'G')) {
                
                    valid = false;
                } 
            }
        }

        if (a == 0 && b == 0) {
            cout << stars << endl;
        } else if (valid == false) {
            cout << -1 << endl;
        } else {
            cout << count << endl;
        }

    }
}