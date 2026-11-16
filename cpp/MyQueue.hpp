#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP
#include <string>
#include <vector>

using namespace std;

class MyQueue {
private:
    struct Node {
        string val;
        Node* next;
        explicit Node(const string& v) : val(v), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    MyQueue();
    MyQueue(const MyQueue& other);
    MyQueue& operator=(const MyQueue& other);
    ~MyQueue();

    void push(const string& val);
    string pop();
    int length() const;
    vector<string> getData() const;
    void clear();
    void print() const;
};
#endif
