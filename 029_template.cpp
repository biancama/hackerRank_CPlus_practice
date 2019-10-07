//
// Created by Massimo Biancalani on 04/10/2019.
//
#include <string>
using namespace std;
template <class T>
class AddElements {
    T elem;
public:
    AddElements(T e):elem(e){};

    T add(T other) {
        return elem + other;
    }

};
// class template specialization:
template <>
class AddElements <string> {
    string element;
public:
    AddElements (string arg) {element=arg;}
    string concatenate (string arg)
    {
        string s = element+arg;
        return s;
    }
};