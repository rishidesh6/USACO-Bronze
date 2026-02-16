#include <bits/stdc++.h>
using namespace std;

ifstream fin("cownomics.in"); 
ofstream fout("cownomics.out");

int main() {

    int n, m;
    fin >> n >> m;

    vector<string> spotty (n);
    vector<string> plain (n);

    for (int i = 0; i < n; i++) {
        fin >> spotty[i];
    }

    for (int i = 0; i < n; i++) {
        fin >> plain[i];
    }

    int triples = 0;

    for (int i = 0; i < m; i++) {

        for (int j = i + 1; j < m; j++) {

            for (int k = j + 1; k < m; k++) {

                unordered_set<string> spottyTriples;
                for (int l = 0; l < n; l++) {
                    string t = "";
                    t += spotty[l][i]; t+= spotty[l][j]; t+= spotty[l][k];
                    spottyTriples.insert(t);
                }

                bool valid = true;
                for (int w = 0; w < n; w++) {
                    string t = "";
                    t+= plain[w][i]; t+= plain[w][j]; t+= plain[w][k];
                    if (spottyTriples.count(t)) {
                        valid = false;
                        break;
                    }
                }

                if (valid) triples++;
            }

        }

    }

    fout << triples << endl;

}