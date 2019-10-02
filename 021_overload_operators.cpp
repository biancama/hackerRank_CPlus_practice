//
// Created by Massimo Biancalani on 01/10/2019.
//

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }

    friend ostream &operator<<(ostream &os, const Complex &complex);
};
Complex operator+(const Complex& a, const Complex& b) {
    return { a.a + b.a, a.b + b.b };
}

ostream &operator<<(ostream &os, const Complex &complex) {
    complex.b > 0 ? os << complex.a << "+i" << complex.b : os << complex.a << "-i" << complex.b;
    return os;
}
