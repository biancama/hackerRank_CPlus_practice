//
// Created by Massimo Biancalani on 2019-04-03.
//

#include <iostream>

using namespace std;
int max_of_four(int a, int b, int c, int d) {
    return  max(max(a, b), max(c, d));
}