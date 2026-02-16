#include <iostream>
#include <map>
#include <iterator>
using namespace std;

long long n;

int main() {

    cin >> n;
    map<int, int> counts;

    int x;
    long long moos = 0;

    while (cin >> x) {
        if (!(counts.count(x))) {
            counts[x] = 1;
        } else {
            counts[x]++;
        }
    }

    auto it = counts.begin();
    long long pos = 0;
    for (long long i = 0; i < counts.size(); i++) {

        if (it->second >= 2) {
            moos += pos;
        }

        advance(it, 1);
        pos ++;
    }

    cout << moos;
    
}