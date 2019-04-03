//
// Created by Massimo Biancalani on 2019-04-03.
//
#include <iostream>

using namespace std;
void print_reverse_array() {
    int N;

    cin >> N;
    int arr[N];

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = N -1; i >= 0; --i) {
        cout << arr[i] << " ";
    }
}