//
// Created by Massimo Biancalani on 08/10/2019.
//
#include <vector>
using namespace std;
class Matrix {
public:
    vector<vector<int>> a;

    const Matrix operator +(const Matrix& b) const {
        Matrix result;
        if (a.size() == 0) {
            return result;
        }
        for (unsigned int i = 0; i < a.size(); i++) {
            result.a.push_back(vector<int>());
            for (unsigned int j = 0; j < b.a[i].size(); j++) {
                result.a[i].push_back(a[i][j] + b.a[i][j]);
            }
        }
        return result;
    }
};