#include <bits/stdc++.h>
using namespace std;

int n;

int main() {

    int direction; int x; int y;

    vector<int> dirs;
    vector<int> xs;
    vector<int> ys;
    
    
    int stops[n];

    for (int i = 0; i < n; i++) {

        cin >> direction >> x >> y;

        dirs.push_back(direction);
        xs.push_back(x);
        ys.push_back(y);

    }

    for (int i = 0; i < n; i++) {
        char dir1 = dirs[i];
        
        for (int j = 0; j < n; j++) {

            if (j == i) continue;
            char dir2 = dirs[j];

            if (dir1 == 'N' && dir2 == 'N' && (xs[i] == xs[j])) {
                int stop = max(ys[i], ys[j]) - min(ys[i], ys[i]);

                if (ys[i] == max(ys[i], ys[j]) && stop <= stops[i]) {
                    stops[i] = stop;
                } else if (stop <= stops[j]) {
                    stops[j] = stop;
                }

            } else if (dir1 == dir2 && (ys[i] == ys[j])) {
                int stop2 = max(xs[i], xs[j]) - min(xs[i], xs[j]);

                if (xs[i] == max(xs[i], xs[j]) && stop2 <= stops[i]) {
                    stops[i] = stop2;
                } else if (stop2 <= stops[j]) {
                    stops[j] = stop2;
                }
                
            } else {

                if (dir1 == 'N' && dir2 == 'E') {
                    int stop3 = 0;
                    if (ys[j] < ys[i] && (ys[i] - ys[j] < xs[j] - xs[i])) {

                        stop3 = ys[i] - ys[j];

                        if (stop3 <= stops[j]) {
                            stops[j] = stop3;
                        }

                    } else if (xs[j] < xs[i] && (xs[i] - xs[j] < ys[j] - ys[i])) {

                        stop3 = xs[i] - xs[j];

                        if (stop3 <= stops[i]) {
                            stops[i] = stop3;
                        }

                    }
                } else {
                    int stop3 = 0;
                    if (ys[i] < ys[j] && (ys[j] - ys[i] < xs[i] - xs[j])) {

                        stop3 = ys[j] - ys[i];

                        if (stop3 <= stops[i]) {
                            stops[i] = stop3;
                        }

                    } else if (xs[i] < xs[j] && (xs[j] - xs[i] < ys[i] - ys[j])) {

                        stop3 = xs[j] - xs[i];

                        if (stop3 <= stops[j]) {
                            stops[j] = stop3;
                        }

                    }                    
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (stops[i] == 0) {
            cout << "Infinity" << endl;
        } else {
            cout << stops[i] << endl;
        }
    }
}