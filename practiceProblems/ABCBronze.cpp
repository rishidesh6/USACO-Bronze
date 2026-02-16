
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    
    vector<int> numbers;
    
    
    while (cin >> x) {
        numbers.push_back(x);
    }
    
    sort(numbers.begin(), numbers.end());
    
    int a = numbers[0];
    
    int b = numbers[1];
    int big = numbers[6];
    
    int c = big - a - b;
    
    cout << a << ' ' << b << ' ' << c;
    
    
}