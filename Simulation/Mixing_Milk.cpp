#include <bits/stdc++.h>
using namespace std;

ifstream fin("mixmilk.in"); 
ofstream fout("mixmilk.out");

int c1, amount1, c2, amount2, c3, amount3;
int N = 3;

int main() {

    vector<int> capacity(N);
    vector<int> milk(N);

    for (int i = 0; i < N; i++) {
        fin >> capacity[i] >> milk[i];
    }

    for (int i = 0; i < 100; i++) {
        int first = (i % N);
        int second = (i + 1) % N;

        int amount = min(milk[first], capacity[second] - milk[second]);

        milk[first] -= amount;
        milk[second] += amount;
    }

    for (int amt : milk) fout << amt << endl;
    fin.close();
    fout.close();
}