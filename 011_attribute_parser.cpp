//
// Created by Massimo Biancalani on 2019-09-19.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;




void attribute_parser() {
    unsigned int n, q;
    unordered_map<string, string> attributes;
    string key ="", attributeName;

    string input_line;

    cin >> n >> q;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;

        while(getline(ss, word, ' ')) {
            if (word[1] == '/') {
                size_t indexOfDot = key.find(".");
                if (indexOfDot == string::npos) {
                    key = "";
                } else {
                    key = key.substr(0, indexOfDot);
                }
            } else if (word[0] == '<') {
                size_t tagNoAttribute = word.find(">");
                string tagName;
                if (tagNoAttribute == string::npos) {
                    tagName = word.substr(1);
                } else {
                    tagName = word.substr(1, tagNoAttribute - 1);
                }
                if (key != "") {
                    key.append(".");
                }
                key.append(tagName);

            } else if (word[0] == '"') {
                size_t indexOfNextQuote = word.find("\"", 1);
                string value = word.substr(1, indexOfNextQuote - 1);
                attributes.emplace(key + attributeName, value);
            } else if (word[0] != '=') {
                attributeName = "~" + word;
            }
        }
    }

    for (int j = 0; j < q; ++j) {
        getline(cin, input_line);
        auto value = attributes.find(input_line);
        if (value == attributes.end()) {
            cout << "Not Found!" << endl;
        } else {
            cout << value->second << endl;
        }
    }


}




