//
// Created by Massimo Biancalani on 2019-04-03.
//
#include  <vector>
#include <iostream>

using namespace std;
void print_query() {
    int n, q;

    vector<vector<int> > m;
    cin >> n;
    cin >> q;

    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> app(l);
        for (int j = 0; j < l; ++j) {
            cin >> app[j];
        }
        m.push_back(app);
    }

    for (int k = 0; k < q; ++k) {
        int i, j;
        cin >> i >> j;
        cout << m[i][j] << endl;
    }
}