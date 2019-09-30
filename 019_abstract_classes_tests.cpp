//
// Created by Massimo Biancalani on 26/09/2019.
//
#include <new>
using namespace std;
template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;
    Node* prev;
};
template <typename T, typename V>
class Cache {
protected:
    unsigned int number_of_element;
    const unsigned int cp;
    Node<T, V>* head;
    Node<T, V>* tail;
    Cache(int capacity) :cp(capacity) {
        number_of_element = 0;
    };
    virtual void set(const T& k, const V& v);
    virtual T get(const T& elem) const;
};

class LRUCache : public Cache<int, int> {
public:
    LRUCache(int capacity) : Cache(capacity) {};
    void set(const int& k, const int& v) {
        Node<int, int>* currentNode = currentPosition(k);
        if (currentNode != nullptr) {
            if (currentNode->prev != nullptr) {
                currentNode->prev->next = currentNode->next;
            }
            if (currentNode->next != nullptr) {
                currentNode->next->prev = currentNode->prev;
            } else {
                tail = currentNode->prev;
            }
            if (head != nullptr) {
                head->prev = currentNode;
            }
            currentNode->next = head;
            currentNode->prev = nullptr;
            head = currentNode;
        } else {
            number_of_element++;
            currentNode = new Node<int, int>;
            currentNode->key = k; currentNode->value = v;
            currentNode->next = head;
            if (head != nullptr) {
                head->prev = currentNode;
            }
            head = currentNode;

            if (tail == nullptr) {
                tail = currentNode;
            } else {
                if (number_of_element > cp) {
                    Node<int, int>* prevOfTail = tail->prev;
                    if(prevOfTail != nullptr) {
                        prevOfTail->next = nullptr;
                    }
                    delete(tail);
                    tail = prevOfTail;
                }
            }
        }
    }
};