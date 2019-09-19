//
// Created by Massimo Biancalani on 2019-09-19.
//
#include <iostream>

using namespace std;
void strings() {
    string first, second;
    cin >> first >> second;
    cout << first.size() << " " << second.size() << endl;
    cout << first + second << endl;

    // swap
    char app = first[0];
    first[0] = second[0];
    second[0] = app;
    cout << first << " " << second<< endl;

}