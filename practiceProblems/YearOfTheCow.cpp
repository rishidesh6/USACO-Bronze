#include <bits/stdc++.h>
using namespace std;

int n;

int main() {

    map<string, int> zodiacs = {
        {"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, 
        {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, 
        {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}
    };

    map<string, int> cows;
    cows["Bessie"] = 0;
    map<string, string> cowZodiacs;
    cowZodiacs["Bessie"] = "Ox";
    cin >> n;

    for (int i = 0;  i < n; i++) {

        string w1, w2, w3, w4, w5, w6, w7, w8;
        cin >> w1 >> w2 >> w3 >> w4 >> w5 >> w6 >> w7 >> w8;

        string nameOne = w1;
        string order = w4;
        string zodiac = w5;
        string nameTwo = w8;

        int diff = 0;

        if (order == "next") {
            if (zodiacs[zodiac] - zodiacs[cowZodiacs[nameTwo]] > 0) {
                diff = zodiacs[zodiac] - zodiacs[cowZodiacs[nameTwo]];
            } else {
                diff = zodiacs[zodiac] - zodiacs[cowZodiacs[nameTwo]] + 12;
            }

            cows[nameOne] = diff + cows[nameTwo];
        } else {
            if (zodiacs[cowZodiacs[nameTwo]] - zodiacs[zodiac] > 0) {
                diff = zodiacs[cowZodiacs[nameTwo]] - zodiacs[zodiac];
            } else {
                diff = zodiacs[cowZodiacs[nameTwo]] - zodiacs[zodiac] + 12;
            }

            cows[nameOne] = cows[nameTwo] - diff;
        }

        cowZodiacs[nameOne] = zodiac;
    }

    cout << abs(cows["Elsie"]);
}