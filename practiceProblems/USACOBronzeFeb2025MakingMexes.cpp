#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {

    const int size = 2 * 100000;

    cin >> n;

    vector<int> arr(size, 0);

    int x;
    while (cin >> x) {
        arr[x]++;
    }

    int total = 0;
    for (int i = 0; i <= n; i++) {
        
        if (arr[i] == 0) {
            cout << total << endl;
            total++;
        } else {
            cout << max(total, arr[i]) << endl;
        }

    }

}