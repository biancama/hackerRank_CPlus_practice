//
// Created by Massimo Biancalani on 24/09/2019.
//
#include <iostream>
using namespace std;

class Box {
private:
    unsigned int l, b, h;
public:
    Box() :l(0), b(0), h(0) {};
    Box(unsigned int l, unsigned int b, unsigned int h): l(l), b(b), h(h) {};
    Box(const Box& box) {
        this->b = box.b;
        this->l = box.l;
        this->h = box.h;
    }
    unsigned int getLength() const {
        return l;
    }
    unsigned int getBreadth() const {
        return b;
    }
    unsigned int getHeight() const {
        return h;
    }

    long long CalculateVolume() const {
        long long result = 1;
        result *= (long long) b * (long long) h * (long long)l;
        return result;
    }

    bool operator <(Box& b) {
        if (this->l < b.l || (this->b < b.b && this->l == b.l) || (this->h < b.h && this->b == b.b && this->l == b.l)) {
            return true;
        } else {
            return false;
        }
    }

    friend  ostream& operator<<(ostream& out, const Box& B) {
        cout << B.l << " " << B.b << " " << B.h;
        return cout;
    }
};