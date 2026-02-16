#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int n;
vector<int> petals;

int main() {
    cin >> n;
    int x;
    while (cin >> x) {
        petals.push_back(x);
    }

    int amount = 0;

    for (int i = 0; i < n; i++) {
        
        for (int j = i; j < n; j++) {

            int total = 0;
            vector<int> temp;

            for (int y = i; y <= j; y++) {
                temp.push_back(petals[y]);
            }

            total = accumulate(temp.begin(), temp.end(), 0);

            if (total % (j - i + 1) == 0) {
                int average = total / (j - i + 1);

            
                int occurences = count(temp.begin(), temp.end(), average);
                if (occurences > 0) {
                    amount++;
                }
            }
        }
    }

    cout << amount;
}