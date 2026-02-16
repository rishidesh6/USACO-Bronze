#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<tuple<int, int>> posts;

    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        posts.push_back({x, y});
    }

    vector<tuple<int, int>> starting;
    vector<tuple<int, int>> ending;

    for (int i = 0; i < n; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        starting.push_back({sx, sy}); ending.push_back({ex, ey});
    }

    for (int i = 0; i < n; i++) {

        tuple<int, int> cur = starting[i];
        tuple<int, int> last = ending[i];
        int distance = 0;
        int curX = get<0> (cur);
        int curY = get<1> (cur);

        for (int j = 0; j < n * 2; j++) {

            tuple<int, int> t = posts[j];

            if (get<0>(t) <= get<0>(last)) {
                distance -= (get<0>(t) - get<0>(last));
                cout << distance << endl;
                break;
            }

            if (get<0>(t) < curX) continue;

            distance += (get<0>(t) - curX + get<1>(t) - curY);
            curX += (get<0>(t) - curX); curY += (get<1>(t) - curY);
        }
    }
}