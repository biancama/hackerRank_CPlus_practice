//
// Created by Massimo Biancalani on 02/10/2019.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int sets_main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int q, y, x;
    cin >> q;
    set<int> s;
    for (int i = 0; i < q; ++i) {
        cin >> y >> x;
        switch (y) {
            case 1: {
                s.insert(x);
                break;
            }
            case 2: {
                s.erase(x);
                break;
            }
            case 3: {
                auto elem_ptr = s.find(x);
                if (elem_ptr == s.end()) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
