#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
//
// Created by Massimo Biancalani on 26/09/2019.
//
struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    void set_lrp(Node* const current) {
        if (current == head && current ==tail) {
            return;
        }
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        if (current == tail) {
            tail = current->prev;
        }
        current->next = head;
        head->prev = current;
        head = current;
        current->prev = NULL;
    }

public:
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    };

    ~LRUCache()  {
        while (tail != NULL) {
            auto nodeApp = tail;
            tail = tail->prev;
            delete(nodeApp);
        }
    }

    void set(int k, int v) override {
        auto nodeInTheCache = mp.find(k);
        Node* currentNode = NULL;
        if (nodeInTheCache == mp.end()) {
            currentNode = new Node(NULL, head, k, v);
            if (head != NULL) {
                head->prev = currentNode;
            }
            head = currentNode;
            if (tail == NULL) {
                tail = currentNode;
            }
            mp.emplace(k, currentNode);
            if (mp.size() > cp) {
                Node* prevOfTail = tail->prev;
                mp.erase(tail->key);
                delete(tail);
                if (prevOfTail != NULL) {
                    prevOfTail->next = NULL;
                }
                tail = prevOfTail;
            }
        } else {
            currentNode = nodeInTheCache->second;
            currentNode->value = v;
            set_lrp(currentNode);
        }

    }

    int get(int k)  override {
        auto nodeInTheCache = mp.find(k);
        if (nodeInTheCache == mp.end()) {
            return -1;
        } else {
            return nodeInTheCache->second->value;
        }
    }

    string to_string() const {
        Node* currentNode = head;
        string result;
        while(currentNode != NULL) {
            result +=  "(" + std::to_string(currentNode->key) + ", " +  std::to_string(currentNode->value) + ") --> ";
            currentNode = currentNode->next;
        }
        result += "\n";
        currentNode = tail;
        while(currentNode != NULL) {
            result +=  "(" + std::to_string(currentNode->key) + ", " +  std::to_string(currentNode->value) + ") --> ";
            currentNode = currentNode->prev;
        }
        return result;
    }
};