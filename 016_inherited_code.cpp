//
// Created by Massimo Biancalani on 24/09/2019.
//

#include <iostream>
#include <exception>
#include <sstream>
#include <vector>
using namespace std;

class BadLengthException : public exception {
    string m_error;

public:
    BadLengthException(unsigned int n)  {
        stringstream ss;
        ss << n;
        m_error = ss.str();
    }

    virtual const char * what () const throw () {
        return (char*) m_error.c_str();
    }
};