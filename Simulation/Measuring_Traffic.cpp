#include <bits/stdc++.h>
using namespace std;

int n;

ifstream fin("traffic.in"); 
ofstream fout("traffic.out");

int main() {
    fin >> n;
    
    vector<string> t;
    vector<int> l;
    vector<int> h;

    //take in input
    for (int i = 0; i < n; i++) {
        
        string type;
        int low, high;
        
        fin >> type >> low >> high;
        t.push_back(type); l.push_back(low); h.push_back(high);
    }
    
    //set ranges to find the actual range of the highway throughout
    int rangeMin = -1000;
    int rangeMax = 1000;

    //loop backwards for starting flow of traffic, calculating min and max range as we go
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == "none") {
            rangeMin = max(rangeMin, l[i]);
            rangeMax = min(rangeMax, h[i]);
        } else if (t[i] == "on") {
            rangeMin -= h[i];
            rangeMax -= l[i];
        } else if (t[i] == "off") {
            rangeMin += l[i];
            rangeMax += h[i];
        }

    }

    fout << max(rangeMin, 0) << ' ' << rangeMax << endl;

    rangeMin = -1000;
    rangeMax = 1000;

    //reset and loop the other way from i = 0 to i = n - 1 to get ending ranges, same process
    for (int i = 0; i < n; i++) {
        if (t[i] == "none") {
            rangeMin = max(rangeMin, l[i]);
            rangeMax = min(rangeMax, h[i]);
        } else if (t[i] == "off") {
            rangeMin -= h[i];
            rangeMax -= l[i];
        } else if (t[i] == "on") {
            rangeMin += l[i];
            rangeMax += h[i];
        }

    } 

    //range could be less than 0 in the case of subtracting, so this is to make sure it doesn't get lower than 0
    fout << max(rangeMin, 0) << ' ' << rangeMax << endl;
}