#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> arr;
    
    cin >> n;
    int x;
    while (cin >> x) {
        arr.push_back(x);
    }
    
    int amountCows = 0;
    int amountMoney = 0;
    
    
    for (int i = 0; i < n; i++) {

        int aC = 0;
        int aM = 0;
        int curC = arr[i];
        
        for (int j = 0; j < n; j++) {
            
            if (arr[j] >= curC) {
                aC++;
                aM += curC;
            }
            
            if (aM > amountMoney || (aM == amountMoney && aC > amountCows)) {
                amountCows = aC;
                amountMoney = aM;
            }
            
        }
    }
    
    cout << amountMoney << ' ' << amountCows;
    
}