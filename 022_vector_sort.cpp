//
// Created by Massimo Biancalani on 02/10/2019.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int vector_sort_main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> vector_to_be_sorted;
    for(int i =0; i < n;i++ ){
        int elem;
        cin >> elem;
        vector_to_be_sorted.push_back(elem);
    }
    sort(vector_to_be_sorted.begin(), vector_to_be_sorted.end());
    for(int i =0; i < n;i++ ){
        cout << vector_to_be_sorted[i] << " ";
    }
    return 0;
}
