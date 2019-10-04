//
// Created by Massimo Biancalani on 03/10/2019.
//
#include <iostream>

using namespace std;
class Rectangle {
protected:
    unsigned int width, height;
public:
    virtual void display() {
        cout << width << " " << height << endl;
    };
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        cin >> width >> height;
    }
    void display() {
        cout << width * height << endl;
    };
};