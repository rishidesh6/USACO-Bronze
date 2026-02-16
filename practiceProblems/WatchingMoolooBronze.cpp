#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<int> numbers;
    
    long long x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        numbers.push_back(x);
    }

    
    sort(numbers.begin(), numbers.end());
    
    if (numbers.size() >= (numbers[n - 1] - numbers[0] + 1) / 2) {
        cout << (numbers.size() + 1) + k;
    } else {
        cout << (k + 1) * numbers.size();
    }
}