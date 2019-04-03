//
// Created by Massimo Biancalani on 2019-04-03.
//

#include <cstdlib>

void update(int *a, int *b) {
    int sum = *a + *b;
    int dif = abs(*a - *b);

    *a = sum;
    *b = dif;
}