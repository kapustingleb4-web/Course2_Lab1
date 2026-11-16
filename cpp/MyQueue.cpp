#include "MyQueue.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

MyQueue::MyQueue() : head(nullptr), tail(nullptr), size(0) {}

MyQueue::MyQueue(const MyQueue& other) : head(nullptr), tail(nullptr), size(0) {
    for (Node* cur = other.head; cur; cur = cur->next) push(cur->val);
}

MyQueue& MyQueue::operator=(const MyQueue& other) {
    if (this != &other) {
        clear();
        for (Node* cur = other.head; cur; cur = cur->next) push(cur->val);
    }
    return *this;
}

MyQueue::~MyQueue() { clear(); }

void MyQueue::push(const string& val) {
    Node* n = new Node(val);
    if (tail) tail->next = n;
    else head = n;
    tail = n;
    size++;
}

string MyQueue::pop() {
    if (!head) throw runtime_error("Queue is empty");
    Node* n = head;
    string v = n->val;
    head = head->next;
    if (!head) tail = nullptr;
    delete n;
    size--;
    return v;
}

int MyQueue::length() const { return size; }

vector<string> MyQueue::getData() const {
    vector<string> v;
    for (Node* cur = head; cur; cur = cur->next) v.push_back(cur->val);
    return v;
}

void MyQueue::clear() {
    while (head) {
        Node* n = head;
        head = head->next;
        delete n;
    }
    tail = nullptr;
    size = 0;
}

void MyQueue::print() const {
    for (Node* cur = head; cur; cur = cur->next) cout << cur->val << " ";
}
