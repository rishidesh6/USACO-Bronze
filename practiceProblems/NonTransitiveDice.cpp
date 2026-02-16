#include <bits/stdc++.h>
using namespace std;

int t;

bool wins(const vector<int>& x, const vector<int>& y) {
    int xUp = 0;
    int yUp = 0;
    for (int num: x) {
        for (int num2: y) {
            if (num > num2) {
                xUp++;
            } else if (num2 > num) {
                yUp++;
            }
        }
    }

    if (xUp > yUp) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> t;
    while (t--) {
        vector<int> A;
        vector<int> B;
        
        for (int i = 0; i < 4; i++) {
            int x; 
            cin >> x;
            A.push_back(x);
        }
        for (int i = 0; i < 4; i++) {
            int x;
            cin >> x;
            B.push_back(x);
        }

        bool done = false;

        for (int i = 1; i <= 10 && !done; i++) {
            for (int j = 1; j <= 10 && !done; j++) {
                for (int k = 1; k <= 10 && !done; k++) {
                    for (int l = 1; l <= 10 && !done; l++) {
                        
                        vector<int> C;
                        C.push_back(i); C.push_back(j); C.push_back(k); C.push_back(l);
                        
                        bool AwinsB = wins(A, B);
                        bool BwinsA = wins(B, A);
                        bool AwinsC = wins(A, C);
                        bool CwinsA = wins(C, A);
                        bool BwinsC = wins(B, C);
                        bool CwinsB = wins(C, B);

                        if ((AwinsB && CwinsA && BwinsC) || (BwinsA && CwinsB && AwinsC)) {
                            done = true;
                        }
                    }
                }
            }
        }

        if (!done) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
}