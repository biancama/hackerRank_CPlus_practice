//
// Created by Massimo Biancalani on 2019-09-19.
//

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
vector<int> parseInts(string str) {
    auto str_stream =  stringstream(str);

    vector<int> result;
    int n;
    char ch;
    str_stream >> n;
    result.push_back(n);
    do {
        str_stream >> ch;
        str_stream >> n;
        result.push_back(n);
    } while (!str_stream.eof());
    return result;
}