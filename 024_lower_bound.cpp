//
// Created by Massimo Biancalani on 02/10/2019.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int lower_bound_main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned n, q;
    cin >> n;
    vector<int> sorted_array;
    for (int i = 0; i < n; ++i) {
        int elem;
        cin >> elem;
        sorted_array.push_back(elem);
    }
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int elem;
        cin >> elem;
        auto lower_bound_ptr = lower_bound(sorted_array.begin(), sorted_array.end(), elem);
        auto position = lower_bound_ptr - sorted_array.begin();

       if (sorted_array[position] != elem) {
            cout << "No " << position + 1<< endl;
        } else {
            cout << "Yes " << position + 1 << endl;
        }
    }
    return 0;
}
