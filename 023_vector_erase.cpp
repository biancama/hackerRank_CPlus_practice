//
// Created by Massimo Biancalani on 02/10/2019.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int erasable_vector_main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int n, k;
    cin >> n;
    vector<int> erasable_vector;
    for (int i = 0; i < n; ++i) {
        int elem;
        cin >> elem;
        erasable_vector.push_back(elem);
    }
    cin >> n;
    erasable_vector.erase(erasable_vector.begin()  + n - 1);
    cin >> n >> k;
    erasable_vector.erase(erasable_vector.begin()  + n - 1, erasable_vector.begin()  + k - 1);
    cout << erasable_vector.size() << endl;
    for (const auto &item : erasable_vector) {
        cout << item << " ";
    }
    return 0;
}
