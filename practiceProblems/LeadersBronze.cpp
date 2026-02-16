#include <iostream>
#include <vector>
using namespace std;

int n;
string str;
vector<int> ranges;
vector<int> leadersG;
vector<int> leadersH;


startG = 0;
endG = 0;
startH = 0;
endH = 0;

int main() {
    cin >> n;
    cin >> str;
    int x;
    while (cin >> x) {
        ranges.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        char cur = str[i];
        if (cur == 'G') {
            if (startG == 0) {
                startG = i;
            }
            endG = i;
        }

        if (cur == 'H') {
            if (startH == 0) {
                startH = i;
            }
            endH = i;
        }
    }

    for (int j = 0; j < n; j++) {
        
    }

}