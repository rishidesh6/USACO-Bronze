#include <bits/stdc++.h>
using namespace std;

ifstream fin("balancing.in"); 
ofstream fout("balancing.out");

int main() {
    int n, b;
    fin >> n >> b;

    vector<int> xCoords;
    vector<int> yCoords;

    set<int> vertFence;
    set<int> horFence;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        xCoords.push_back(x);
        yCoords.push_back(y);

        //fences can only be odd numbers so these are the relevant fence positions as opposed to just making them anything
        vertFence.insert(x + 1); horFence.insert(y + 1);
    }

    int ans = INT_MAX;

    for (int v: vertFence) {
        for (int h: horFence) {

            int region1 = 0; int region2 = 0; int region3 = 0; int region4 = 0;
            int m = 0;

            //for every x coordinate, y coordinate, check which region its in and add to that region
            for (int i = 0; i < n; i++) {
                
                int xCoord = xCoords[i];
                int yCoord = yCoords[i];
                
                if (xCoord < v && yCoord < h) {
                    region1++;
                } else if (xCoord > v && yCoord < h) {
                    region2++;
                } else if (xCoord < v && yCoord > h) {
                    region3++;
                } else {
                    region4++;
                }

            }
            //max of all four regions for every fence position x and y 
            m = max({region1, region2, region3, region4});
            //minimum of it which is what the answer requires
            ans = min(ans, m);
        }
    }

    fout << ans;
}