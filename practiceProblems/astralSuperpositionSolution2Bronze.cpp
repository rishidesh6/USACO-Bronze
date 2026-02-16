#include <iostream>
#include <string>
#include <vector>
using namespace std;

char matrix[1000][1000];
int t;

int main() {
    cin >> t;
    
    while (t--) {
        
        int n, a, b;
        int stars = 0;
        int count[1000][1000] = {0};
        //a to the right, b down
        cin >> n >> a >> b;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                char x;
                cin >> x;
                if (x == 'B' || x == 'G') {
                    stars++;
                }
                matrix[i][j] = x;
                
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                char cur = matrix[i][j];
                
                int prevX = i - b;
                int prevY = j - a;
                int futureX = i + b;
                int futureY = j + a;
                
                
                if (cur == 'B') {
                    
                    if (prevX < 0 || prevY < 0) {
                        count[i][j] = -1;
                        
                    } else if (matrix[prevX][prevY] == 'W') {
                        count[i][j] = -1;
                        
                    } else {
                        if (count[prevX][prevY] == 0) {
                            count[i][j] = 2;
                        } else {
                            count[i][j] = 1;
                        }
                        //cout << i << ' ' << j << ' ';
                    }
                } else if (cur == 'G') {
                    
                    if (prevX < 0 || prevY < 0) {
                        count[i][j] = 1;
                        //cout << i << ' ' << j << ' ';
                        
                    } else if (matrix[prevX][prevY] == 'W') {
                        count[i][j] = 1;
                        //cout << i << ' ' << j << ' ';

                    } else if (!(futureX > n - 1 || futureY > n - 1) && matrix[futureX][futureY] == 'B'){
                        count[i][j] = 1;
                    } else {
                        count[i][j] = 0;
                    }
                    
                } else {
                    count[i][j] = 0;
                }
                
            }
        }
        int total = 0;
        bool invalid = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            
                //cout << count[i] << ' ';
                
                if (count[i][j] == -1) {
                    invalid = true;
                } else {
                    total += count[i][j];
                }
            
            }
        }
        
        if (a == 0 && b == 0) {
            cout << stars << endl;
        } else if (!invalid) {
            cout << total << endl;
        } else {
            cout << -1 << endl;
        }
        
    }
}