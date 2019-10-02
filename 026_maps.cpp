//
// Created by Massimo Biancalani on 02/10/2019.
//

#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int q, type, value;
    string key;
    cin >> q;
    map<string, int> m;
    for (int i = 0; i < q; ++i) {
        cin >> type >> key;
        switch (type) {
            case 1: {
                cin >> value;
                auto elem_ptr = m.find(key);
                if (elem_ptr != m.end()) {
                    value += elem_ptr->second;
                    m.erase(key);
                }
                m.insert(make_pair(key, value));
                break;
            }
            case 2: {
                m.erase(key);
                break;
            }
            case 3: {
                auto elem_ptr = m.find(key);
                if (elem_ptr == m.end()) {
                    cout << "0" << endl;
                } else {
                    cout << elem_ptr->second << endl;
                }
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
