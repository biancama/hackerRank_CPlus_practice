//
// Created by Massimo Biancalani on 02/10/2019.
//
#include <iostream>
#include <deque>
using namespace std;
void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> dq;
    int i =0;
    for (i = 0; i < k; ++i) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (; i < n; ++i) {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && i - dq.front() >= k ) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << endl;
}