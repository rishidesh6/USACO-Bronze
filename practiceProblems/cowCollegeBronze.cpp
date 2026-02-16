#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    
    long long amountCows = 0;
    long long amountMoney = 0;
    long long goodTuition = 0;
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++) {

        long long curC = arr[i];
        long long aC = n - i;
        long long aM = aC * curC;
        
            
        if (aM > amountMoney || (aM == amountMoney && aC > amountCows)) {
            amountCows = aC;
            amountMoney = aM;
            goodTuition = curC;
        }
            
    }
    
    cout << amountMoney << ' ' << goodTuition;
    
}