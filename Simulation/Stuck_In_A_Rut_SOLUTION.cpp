#include <bits/stdc++.h>
using namespace std;

struct Event {
    long long time;
    int blocked;
    int blocker;
    
};

int main() {
    int n;
    cin >> n;
    
    vector<char> dir(n);
    vector<long long> x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> x[i] >> y[i];
    }

    vector<long long> stops(n, INT_MAX);
    
    vector<Event> events;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (dir[i] == 'N' && dir[j] == 'E') {
                
                long long ix = x[i];
                long long iy = y[j];
                
                if (ix < x[j] || iy < y[i]) continue;
                
                long long tN = iy - y[i];
                long long tE = ix - x[j];
                
                
                //if east time is less that means that the north cow will be blocked(i) and vice versa
                if (tN < tE) {
                    events.push_back({tE, j, i});
                } else if (tE < tN) {
                    events.push_back({tN, i, j});
                }
                
                
            }
            
            
        }
    }
     
    sort(events.begin(), events.end(), [](const Event&a, const Event&b) {
        return a.time < b.time;
    });
    
    for (auto & event: events) {
        int blocked = event.blocked;
        int blocker = event.blocker;
        long long t = event.time;
        
        // if blocker is still alive then the time needs to be greater and thats the only way it works
        if (stops[blocker] > t) {
            stops[blocked] = t;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (stops[i] == INT_MAX) {
            cout << "Infinity" << endl;
        } else {
            cout << stops[i] << endl;
        }
    }
}

//UNSOLVED