#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ForwardList {
private:
    struct Node {
        string data;
        Node* next;
        Node(const string& val) : data(val), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    ForwardList();
    ~ForwardList();

    // Базовые
    void push_front(const string& val);
    void push_back(const string& val);
    
    // НОВЫЕ: по значению
    void insert_before_value(const string& target, const string& val);
    void insert_after_value(const string& target, const string& val);
    
    void pop_front();
    void pop_back();
    void remove_by_value(const string& val);
    
    // НОВЫЕ: удаление
    void remove_all_by_value(const string& val);
    void remove_before_value(const string& target);
    void remove_after_value(const string& target);
    
    bool find(const string& val) const;
    int getSize() const;
    void print() const;

    vector<string> getData() const;
    void setData(const vector<string>& d);
};
#endif