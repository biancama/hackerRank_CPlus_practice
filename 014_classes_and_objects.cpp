//
// Created by Massimo Biancalani on 24/09/2019.
//
#include <iostream>

using namespace std;
class Student {
private:
    int scores[5];
public:
    int calculateTotalScore() {
        int result = 0;
        for (int i = 0; i < 5; ++i) {
            result += scores[i];
        }
        return result;
    }

    void input() {
        for (int i = 0; i < 5; ++i) {
            cin >> scores[i];
        }
    }
};